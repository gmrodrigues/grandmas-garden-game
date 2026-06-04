# E-001: hash-crack

**Date:** 2025-05-20
**Questions investigated:** Q-001, Q-002, Q-003, Q-004
**Gap:** G2 (hash function)

## TL;DR

Reversed the TIM2 resource filename hash function from TIM2.EXE. Initial attempts using standard hash algorithms all failed. Disassembly revealed a custom weighted-sum + ROL8 + signed IMUL algorithm with a weight table derived from the string "RichRayl@JTP". Verified 1467/1467 entries against RESOURCE.MAP.

## Goals

1. ✅ Determine the hash algorithm used in RESOURCE.MAP entries
2. ✅ Verify the algorithm produces correct hashes for all 1467 entries
3. ✅ Identify the weight table and index table from the EXE
4. ✅ Understand why the EXE default hash indices [0,1,6,7] differ from the MAP header [0,1,4,7]

## Pre-session state

- RESOURCE.MAP parsed with 1467 entries, each 8 bytes (type + hash + offset_low16)
- Entries confirmed in volume order
- Standard hash algorithms (CRC, Adler, FNV, DJB2, SDBM) all failed
- The hash function was unknown

## Hypothesis

The hash is a custom weighted-sum + rotation algorithm using a 16-byte weight table stored in the EXE, with a 4-byte index table overriding the default indices at runtime.

## Session log

### Step 1 — Verify EXE bytes at DGROUP:0x01AA

Read the EXE binary at the offset corresponding to `DGROUP:0x01AA` (the hash index table) and `DGROUP:0x01AE` (the weight table).

Result: Index table = `[0,1,6,7]` (EXE default), Weight table = `"RichRayl@JTP\0RES"` (16 bytes).

**Decision point:** Should we use the EXE's `[0,1,6,7]` or the MAP header's `[0,1,4,7]`?
→ Try MAP values first, since they override at runtime. This was correct.

### Attempt 1 — Reimplement from memory (FAILED)

**Result:** FAILED (200/1467 matches)
**Reason:** Used unsigned `MUL` instead of signed `IMUL`. The x86 `IMUL` instruction with `CWD` extension causes high-word propagation when product >= 0x8000 — this is invisible from the algorithm structure alone. Only the 305 mismatches (where `prod >= 0x8000`) revealed the signed semantics.

### Attempt 2 — Hash index mismatch (PARTIAL, 1462/1467)

**Result:** PARTIAL (5 mismatches)
**Reason:** The 5 mismatches were all resources with subtypes (e.g. `VM.OVL\0RES\01\0`). The test harness was reading the full prefix instead of just the bare filename. The hash uses only the name, not the subtype or version.

**False hypothesis:** "The hash must include the subtype string." → Disproven by re-reading disassembly — `strncpy` copies exactly the filename argument.

### Attempt 3 — CWD signedness subtlety (SUCCESS after fix)

The `IMUL` instruction computes a full 32-bit signed product, stores low word in AX, high word in DX. Then `CWD` recomputes DX from AX only (DX = 0 if AX < 0x8000, DX = 0xFFFF if AX >= 0x8000).

The key insight: the assembly discards the IMUL high word and uses CWD instead. This means `prod_hi = 0xFFFF if low_word >= 0x8000 else 0`.

### Attempt 4 — ROL32 boundary condition

The ROL32 helper at CS:0x199B uses a thunk pattern (POP/PUSH/RETF, not CALL). Tracing required understanding the non-standard calling convention. The `NEG cl` / `ADD cl, 16` pattern requires 8-bit modular arithmetic in Python: `((-cl) & 0xFF)`.

### Attempt 5 — 13-byte buffer length

Short filenames like `"PAL"` produced wrong hashes. The strncpy copies to a 13-byte buffer, NUL-padding the remainder. The hash reads characters at positions `[0,1,4,7]` from this padded buffer.

## Breakthrough

The critical CWD-after-IMUL insight explained the pattern where hash entries came in pairs differing by exactly 1 in the high word. When `wsum * xorsum >= 0x8000`, the `CWD` instruction forces DX=0xFFFF, which propagates into the upper 16 bits of the final hash.

## Validation

```
$ python3 build/phase-2/test_hash.py
Hash verification: 1467/1467 correct (100.0%)
PASSED
```

## New questions raised

- None remaining — the hash function is fully decoded.

## Artifacts

- Script: `scripts/phase-2/01-identify-hash.py`
- Script: `scripts/phase-2/tim2_hash.py`
- Script: `scripts/phase-2/test_hash.py`
- Output: `build/phase-2/hash-function.json`
- Output: `build/phase-2/resource-lookup.json`