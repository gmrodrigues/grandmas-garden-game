# R-015 — State Limit Initialization Mechanism

**Date:** 2026-05-27
**Experiments:** E-015
**Questions closed:** Q-023

## TL;DR

The 6 state limit constants (`DAT_5b41_19cc`/`19ce`/`19d0`/`19d2`/`19d4`/`19d6`) are **runtime-initialized global variables** in the BSS segment 0x5B41, loaded from a game resource file at startup. They cannot be statically extracted from the EXE binary because the initial values depend on dynamic resource loading. The current editor approach (ANM state count proxy) is the best available approximation.

## Goals

1. ✅ Decompile `init_state_limits` — found it's `FUN_31f7_3aab` (state behavior handler) with lazy initialization
2. ✅ Decompile `FUN_4551_0370` — table lookup with resource caching via `FUN_4551_06cf`
3. ✅ Decompile `FUN_4551_06cf` — resource cache/loader for TB-format files
4. ✅ Verify BSS segment — confirmed all-zero in Ghidra
5. ❌ Extract table values — cannot; resource ID at `DAT_5b41_09ec` is BSS (0x0000)

## Background

Q-023 from E-013 identified 6 state limit constants used by the D1 state execution engine (`FUN_31f7_3bd2`). The intent was to extract exact values from the EXE to replace the ANM-count proxy used by the editor.

## Method

1. Decompile `FUN_31f7_3aab` (the function containing the init calls) via pyghidra
2. Decompile `FUN_4551_0370` (table lookup) and `FUN_4551_06cf` (resource loader)
3. Search for write references to `DAT_5b41_09ec` (the table pointer)
4. Verify BSS segment contents

## Discovery

### Function Chain

```
FUN_31f7_3aab (state behavior handler, called on every state change)
  └── if DAT_5b41_19ca == 0 (not yet initialized):
        ├── DAT_5b41_19ca = FUN_4551_0370(DAT_5b41_09ec, 3)
        ├── DAT_5b41_19cc = FUN_4551_0370(DAT_5b41_09ec, 4)     // limit_lower
        ├── DAT_5b41_19ce = FUN_4551_0370(DAT_5b41_09ec, 9)     // alt bound
        ├── DAT_5b41_19d0 = FUN_4551_0370(DAT_5b41_09ec, 5)     // limit_reset
        ├── DAT_5b41_19d2 = FUN_4551_0370(DAT_5b41_09ec, 7)     // limit_upper
        ├── DAT_5b41_19d4 = FUN_4551_0370(DAT_5b41_09ec, 8)     // sub_limit_a
        └── DAT_5b41_19d6 = FUN_4551_0370(DAT_5b41_09ec, 0xFFFF) // sub_limit_b
```

```
FUN_4551_0370(param_1: resource_id, param_2: index)
  └── ptr = FUN_4551_06cf(param_1)    // get cached or load resource
  └── if ptr == null: return 0
  └── if param_2 == -1: return ptr[12]    // field at +0xc
  └── else: walk ptr[8..10] as far pointer to (value, index) word pairs
        walk until index == 0 or index == param_2, return value
```

```
FUN_4551_06cf(param_1: resource_id)
  ├── FUN_3f2b_07a3(param_1)         // check cache for this ID
  └── if not cached:
        ├── FUN_3f2b_0718(param_1)   // load resource from RESOURCE.MAP/001
        │     ├── scan cache for resource entry
        │     ├── open resource file via FUN_460e_06a6(0x5fc3, ...)
        │     ├── load into segment 0x554C
        │     └── return pointer to loaded data
        ├── parse TB header (5 words), validate 'TB' magic
        ├── allocate memory
        ├── parse entries (value pairs, triples, etc.)
        └── FUN_3f2b_08e1(param_1, ptr)  // store in cache
  └── return (cached) pointer to parsed table
```

### BSS Verification

All 7 state limit variables in segment 0x5B41 read as 0x0000 from Ghidra's memory:

| Symbol | Ghidra Address | Value |
|--------|---------------|-------|
| DAT_5b41_19ca | 0x5CDDA | 0x0000 |
| DAT_5b41_19cc | 0x5CDDC | 0x0000 |
| DAT_5b41_19ce | 0x5CDDE | 0x0000 |
| DAT_5b41_19d0 | 0x5CDE0 | 0x0000 |
| DAT_5b41_19d2 | 0x5CDE2 | 0x0000 |
| DAT_5b41_19d4 | 0x5CDE4 | 0x0000 |
| DAT_5b41_19d6 | 0x5CDE6 | 0x0000 |

### Table Pointer Analysis

`DAT_5b41_09ec` at Ghidra 0x5BDFC (seg 0x5B41:0x09EC) is 0x0000. No write cross-references exist (Ghidra found 7 READ references from `FUN_31f7_3aab` only). Binary search for `MOV [0x09EC]` and similar patterns found zero matches in the EXE.

### Memory Block Mapping

Ghidra's MZ overlay loader creates blocks at different Ghidra addresses but maps them from various file offsets. The BSS segment (CODE_77, 0x5B410-0x5DF9F) is all zeros — its file data is either absent (pure BSS) or loaded from an overlay that Ghidra didn't capture.

## False Starts

1. **Static extraction from EXE**: Attempted to read table values directly from file offsets calculated via `Ghidra = file_offset - 0x5200`. Failed because Ghidra's MZ overlay loader maps segments non-linearly (each segment has its own file offset from the overlay table).

2. **Write xref search**: Searched for `MOV [0x09EC], ...` pattern in the entire EXE binary. Found no matches — the write to `DAT_5b41_09ec` either happens through indirect addressing or in a code path Ghidra couldn't analyze.

3. **Seg 0x5B41 file data**: Checked raw EXE bytes at the calculated file offsets for segment 0x5B41. The segment maps to a zero-initialized BSS region — no data in the EXE file.

## Validation

- The lazy-init guard (`DAT_5b41_19ca == 0`) creates a retry loop — the function tries to init on every state change until the resource is available.
- Since the resource is loaded asynchronously (or by external init code), the limits being 0 means the first few state changes use default/zeroed limits, then proper limits are loaded on a later call.
- The mechanism IS documented and the decompiled C code confirms the table format.

## Questions closed

- **Q-023: What are the state limit constants (DAT_5b41_19cc etc.) in FUN_31f7_3bd2?**
  - **Answer:** The constants are runtime-initialized global variables loaded from a game resource file (TB format, like ANM bytecode). They cannot be extracted statically from the EXE because the resource ID (`DAT_5b41_09ec`) is stored in BSS and initialized at runtime. The table lookup function `FUN_4551_0370` reads (value, index) word pairs from a parsed resource structure. The 7 constants are: DAT_5b41_19ca (idx 3), 19cc (idx 4, limit_lower), 19ce (idx 9, alt bound), 19d0 (idx 5, limit_reset), 19d2 (idx 7, limit_upper), 19d4 (idx 8, sub_limit_a), 19d6 (idx 0xFFFF, sub_limit_b).

## Cold takeaways

1. **BSS variables can't be statically extracted.** If a DOS MZ variable lives in the BSS segment and is initialized at runtime by resource loading, the binary alone won't reveal the value.
2. **Ghidra's overlay mapping is non-linear.** For MZ executables with overlays, the simple `Ghidra = file_offset - header_size` formula only works for the first segment. Each overlay segment has its own file offset.
3. **Resource loading chains can mask data origins.** The `FUN_4551_06cf` pattern (cache → resource load → parse → cache) makes extracting static values from the EXE infeasible without also extracting the game's RESOURCE.001 archive.

## References

- Decompiled C: `build/phase-13/ghidra-decompiled/I0-init-limits-0x3AC1B.c`
- Decompiled C: `build/phase-13/ghidra-decompiled/I1-table-lookup-0x4AA80.c`
- Binary: `TIM2.EXE` at root
- Resource format: `build/phase-16/godot/behaviors.json` (ANM state counts used as proxy)
