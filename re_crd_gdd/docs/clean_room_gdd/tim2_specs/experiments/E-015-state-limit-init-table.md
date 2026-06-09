# E-014 — State Limit Init Table Decode

**Date:** 2026-05-27
**Questions investigated:** Q-023
**Gap:** M10

## TL;DR

Extract and decode the per-part state limit init table from TIM2.EXE to determine exact `limit_lower`, `limit_upper`, `limit_reset`, `sub_limit_a`, `sub_limit_b` values. Verify against known ANM state counts for 17 complex parts.

## Goals

1. Decompile `init_state_limits` function to identify the init table structure
2. Extract all table entries from the EXE binary
3. Decode the 5+ state limit values per entry
4. Validate against known part behavior (Cannon=37, LaserMixer=32, etc.)
5. If per-part: update `PartBehaviorRegistry` in editor

## Pre-session state

The state execution engine (`FUN_31f7_3bd2`, D1) uses 6 global symbols:
- `DAT_5b41_19cc` — limit_lower (clamp: if state < limit_lower → limit_lower-1)
- `DAT_5b41_19ce` — some other bound (used in intermediate calculation)
- `DAT_5b41_19d0` — limit_reset (after hitting limit_upper)
- `DAT_5b41_19d2` — limit_upper (if state == limit_upper → reset)
- `DAT_5b41_19d4` — sub_limit_a (sub-state wraparound targets)
- `DAT_5b41_19d6` — sub_limit_b

These are runtime-initialized by `init_state_limits` at seg 0x31F7:0x3AD7 via `FUN_4551_0370(table, index)`. Segment 0x5B41 is BSS (zeros in EXE).

E-013 found a table at seg 0x554C:0x3A32 with (value, index) pairs for sound parameters, but init_state_limits uses indices 3,4,5,7,8,9,255 — which don't all match that table.

## Hypothesis

The state limit init function reads a different table (possibly at seg 0x554C or elsewhere) that contains per-part or global (value, index) pairs. The values for the 6 state limits will be decoded by finding the correct table and computing `FUN_4551_0370` for each index.

## Session log

### Step 1 — Decompile init_state_limits at seg 0x31F7:0x3AD7

Found the function — it's actually `FUN_31f7_3aab` at Ghidra 0x35A1B (file 0x3AC1B), which is the state-specific behavior handler called from D1. It LAZILY initializes limits on first call:

```c
if (DAT_5b41_19ca == 0) {
    DAT_5b41_19ca = FUN_4551_0370(DAT_5b41_09ec, 3);
    DAT_5b41_19cc = FUN_4551_0370(DAT_5b41_09ec, 4);  // limit_lower
    DAT_5b41_19ce = FUN_4551_0370(DAT_5b41_09ec, 9);
    DAT_5b41_19d0 = FUN_4551_0370(DAT_5b41_09ec, 5);  // limit_reset
    DAT_5b41_19d2 = FUN_4551_0370(DAT_5b41_09ec, 7);  // limit_upper
    DAT_5b41_19d4 = FUN_4551_0370(DAT_5b41_09ec, 8);  // sub_limit_a
    DAT_5b41_19d6 = FUN_4551_0370(DAT_5b41_09ec, 0xffff);  // sub_limit_b
}
```

**Key constants:**
| Index | Symbol | Role |
|-------|--------|------|
| 3 | DAT_5b41_19ca | Unknown guard value |
| 4 | DAT_5b41_19cc | limit_lower |
| 9 | DAT_5b41_19ce | Alt lower bound |
| 5 | DAT_5b41_19d0 | limit_reset |
| 7 | DAT_5b41_19d2 | limit_upper |
| 8 | DAT_5b41_19d4 | sub_limit_a |
| 255 | DAT_5b41_19d6 | sub_limit_b |

### Step 2 — Decompile FUN_4551_0370 (table lookup)

At Ghidra 0x45880. It calls `FUN_4551_06cf(param_1)` to get a cached/loaded resource pointer, then walks (value, index) word pairs from offset +8/+10 of the returned structure. If `param_2 == -1`, returns the value at offset +0xc instead. Returns 0 if resource not found.

### Step 3 — Decompile FUN_4551_06cf (resource cache/loader)

At Ghidra 0x45BDF. This function:
1. Checks if resource `param_1` is already cached via `FUN_3f2b_07a3()`
2. If not cached, loads the resource via `FUN_3f2b_0718()`
3. The loaded resource is expected to be "TB" format (ANM bytecode)
4. Parses the TB header (5 words), allocates memory, reads entries
5. Stores the cached pointer via `FUN_3f2b_08e1()`

The resource loader loads data into segment **0x554C** (where the known sound param table lives).

### Step 4 — Finding the table data

**`DAT_5b41_09ec` is at Ghidra 0x5BDFC (seg 0x5B41:0x09EC), value = 0x0000 (BSS).**

The `DAT_5b41_09ec` is the **resource ID** passed to `FUN_4551_0370`. It's a 16-bit resource handle stored in the BSS segment (0x5B41). Since it's 0, the init function tries to load resource 0 — which fails because no resource has ID 0.

**No write cross-references found** to `DAT_5b41_09ec` (Ghidra only finds READ references). Binary search (1,700+ patterns) found zero instances of `MOV [0x09EC], ...` or similar patterns.

**The state limit table is loaded from a resource file at runtime**, not hardcoded in the EXE. The resource ID must be set by initialization code that Ghidra cannot find through its reference analysis (possibly indirect writes via the caching layer or self-modifying relocation).

### Step 5 — Understanding the caching mechanism

`FUN_3f2b_08e1(param_1, cached_ptr)` stores the parsed resource in a cache indexed by `param_1` (resource ID). Subsequent calls to `FUN_4551_06cf(same_id)` return the cached pointer directly.

The guard pattern in `FUN_31f7_3aab` (`if (DAT_5b41_19ca == 0)`) is a **retry loop**: on every state-change call, it tries to init. Once the resource is loaded (by external code setting `DAT_5b41_09ec` to the correct ID), the init succeeds and the guard prevents re-initialization.

The missing piece: what code sets `DAT_5b41_09ec` to a valid resource ID? This must happen in overlay segment 0x1000 (initialization code not fully analyzed by Ghidra), or via a relocation fixup that Ghidra didn't capture.

### Step 6 — Alternative: looking for the table in RESOURCE.MAP

The game's RESOURCE.MAP/001 archive contains ALL game assets. The state limit table is likely resource #some_id loaded from there. Without knowing which ID, we'd need to scan all resources for "TB" files with the right structure.

**Result: PARTIAL — mechanism documented, exact runtime values depend on dynamic resource loading that we can't statically extract from the EXE alone.**

## Takeaway

The state limits are **global constants** (not per-part), loaded at runtime from a game resource file. We can't extract exact values from the EXE binary alone. The current editor approach (using ANM state count as proxy) is the best available approximation.

The D1 code shows that ALL parts share the same global limits:
- `limit_lower` (DAT_5b41_19cc)
- `limit_upper` (DAT_5b41_19d2) — must be >= Cannon's 37 states
- `limit_reset` (DAT_5b41_19d0)

## New questions raised

- Q-026: What resource ID maps to the state limit table? Can we find it by scanning RESOURCE.MAP?
- Q-027: Can we set a breakpoint in DOSBox to capture the runtime values of DAT_5b41_19ca-19d6?

## Artifacts

- Decompiled C: `build/phase-13/ghidra-decompiled/I0-init-limits-0x3AC1B.c`
- Decompiled C: `build/phase-13/ghidra-decompiled/I1-table-lookup-0x4AA80.c`
