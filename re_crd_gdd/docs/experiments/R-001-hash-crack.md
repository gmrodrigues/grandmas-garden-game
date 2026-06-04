# R-001: hash-crack

**Date:** 2025-05-20
**Experiments:** E-001
**Questions closed:** Q-001, Q-002, Q-003, Q-004

## TL;DR

The TIM2 resource filename hash is a custom algorithm: weighted-sum (using weight table `"RichRayl@JTP\0RES"`) + XOR checksum, followed by ROL8 rotation over buffer positions [0,1,4,7], then combined with a signed IMUL+CWD product. The MAP header overrides the EXE default index table from [0,1,6,7] to [0,1,4,7]. Verified 1467/1467 entries.

## Goals

1. ✅ Determine the hash algorithm used in RESOURCE.MAP entries
2. ✅ Verify the algorithm produces correct hashes for all 1467 entries
3. ✅ Identify the weight table and index table from the EXE
4. ✅ Understand the EXE vs MAP index table override

## Background

Gap G2 (Appearance→ANM mapping) depends on being able to look up resources by name. The RESOURCE.MAP index uses 32-bit hashes instead of filenames, with a custom hash algorithm. Without understanding the hash, no resource can be addressed by name.

Before this investigation, we had confirmed the 8-byte MAP entry format (type + hash + offset_low16) and verified all 1467 entries are in volume order, but the hash function itself was unknown.

## Method

1. Located the hash function in TIM2.EXE at CS:0x05F4 (file offset 0x57F4) via disassembly
2. Extracted the weight table at `DGROUP:0x01AE` (16 bytes: `"RichRayl@JTP\0RES"`)
3. Extracted the index table at `DGROUP:0x01AA` (4 bytes: `[0,1,6,7]`)
4. Discovered the MAP header overrides the index table to `[0,1,4,7]`
5. Implemented the algorithm in Python (`tim2_hash.py`)
6. Wrote a self-test (`test_hash.py`) verifying all 1467 entries

## Discovery

### Algorithm (4 phases)

**Phase 1 — Weighted sum + XOR checksum:**
```
for each char c at position i:
    wsum += c × WEIGHT[i % 16]   (signed IMUL16)
    xorsum ^= c
    if c in (0x5C, 0x3A): reset wsum=0, xorsum=0
```

**Phase 2 — Pad to 13-byte buffer with NULs**

**Phase 3 — 32-bit ROL8 over positions [0,1,4,7]:**
```
for each idx in hash_idx:
    rotate DX:AX left 8 bits → add char at buf[idx] with carry
```

**Phase 4 — Final combine:**
```
prod = (wsum × xorsum) & 0xFFFF  (signed IMUL16)
prod_hi = 0xFFFF if prod >= 0x8000 else 0  (CWD sign-extension)
result = (rot_hi + prod_hi + carry) : (rot_lo + prod)
```

### Key insight

The CWD after IMUL is critical — when the product has bit 15 set, DX=0xFFFF which propagates into the upper 16 bits of the final hash. This explains the observed pattern where hash entries come in `ft`/`ft-1` pairs.

**Source:** TIM2.EXE CS:0x05F4 (file offset 0x57F4), ROL32 helper at CS:0x199B

## False starts

### Attempt 1 — MUL vs IMUL (200/1467 matches)
Used unsigned MUL instead of signed IMUL. The high-word behavior differs for products >= 0x8000.

### Attempt 2 — Subtype in hash string (1462/1467)
Assumed the hash included the full volume prefix (name+subtype+version). In fact only the bare filename is hashed — the test harness was reading the wrong field.

### Attempt 3 — Using IMUL high word directly
Tried using the DX result from IMUL. But the assembly follows IMUL with CWD, which recomputes DX from AX only, discarding the IMUL high word.

### Attempt 4 — Python integer overflow in ROL32
The `NEG cl` / `ADD cl, 16` in 8-bit mode requires `((-cl) & 0xFF)` in Python, not `-cl`, because Python integers are unbounded.

### Attempt 5 — Short filenames wrong
`strncpy` copies to a 13-byte buffer and NUL-pads. Short names like `"PAL"` need the padding for correct hash computation.

## Validation

```bash
$ python3 build/phase-2/test_hash.py
Hash verification: 1467/1467 correct (100.0%)
PASSED
```

## Questions closed

- Q-001: What algorithm does RESOURCE.MAP use to hash filenames? → Weighted-sum + XOR + ROL8 + IMUL/CWD, with weight table "RichRayl@JTP\0RES"
- Q-002: Where is the hash function located in TIM2.EXE? → CS:0x05F4, ROL32 helper at CS:0x199B
- Q-003: Why do some hashes differ by 1 in the high word? → CWD sign-extension: when IMUL product >= 0x8000, DX becomes 0xFFFF
- Q-004: Do the MAP header indices override the EXE defaults? → Yes: MAP [0,1,4,7] overrides EXE [0,1,6,7]

## Cold takeaways

1. **IMUL+CWD is not IMUL alone.** When reversing x86 arithmetic, trace every instruction in order. CWD recomputes DX from AX — it discards the IMUL high word.
2. **8-bit x86 arithmetic is modular.** Python integers are unbounded. Always mask to 0xFF after NEG, ADD, SUB on 8-bit values.
3. **Group failures by pattern first.** The ft/ft-1 pairing in hash values immediately revealed the signed-multiply issue, saving hours of blind tweaking.
4. **Test all entries, not just the first 10.** The 305 edge cases (prod >= 0x8000) would have been missed with a small sample.
5. **Verify the test harness first.** The 5 subtype mismatches were a test harness bug, not an algorithm bug.
6. **Isolate subroutines.** The ROL32 thunk at CS:0x199B uses POP/PUSH/RETF instead of CALL — a separate disassembly pass was needed.

## References

- Source: TIM2.EXE CS:0x05F4 (file offset 0x57F4), DGROUP:0x01AA (index table), DGROUP:0x01AE (weight table)
- Script: `scripts/phase-2/01-identify-hash.py`
- Script: `build/phase-2/tim2_hash.py` (verified hash function)
- Script: `build/phase-2/test_hash.py` (1467/1467 self-test)
- Output: `build/phase-2/hash-function.json` (algorithm parameters)
- Output: `build/phase-2/resource-lookup.json` (name→hash→offset cross-reference)