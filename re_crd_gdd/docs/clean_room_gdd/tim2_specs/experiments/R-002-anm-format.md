# R-002: anm-format

**Date:** 2025-05-22
**Experiments:** E-002
**Questions closed:** Q-005, Q-006, Q-007, Q-008

## TL;DR

The TIM2 .ANM format is a Sierra `ANM:` chunked container wrapping a `"TB"` (version 1000/1001) inner format with four sections: frame index sequence (A), frame metadata (B), state map (C), and render bytecode (D). The bytecode has exactly 6 opcodes. DRAW_BMP flags: bit 0 = hflip, bit 1 = vflip. DRAW_RECT flags: bit 15 = absolute coords, bits 0-3 = draw mode. Validated across all 433 files.

**Correction (2026-05-27):** Section A is NOT "frame durations" — it is a **frame index sequence** (indirection array). Each entry is a UINT16LE index into Section B, not a tick count. See E-014 animation pipeline for the full frame timing mechanism.

## Goals

1. ✅ Determine container format — `ANM:` wrapper + `TB` inner
2. ✅ Parse TB header and all four sections
3. ✅ Decode Section D bytecode (6 opcodes)
4. ✅ Determine field layouts for all commands
5. ✅ Validate against all 433 files with zero errors
6. ✅ Determine DRAW_BMP flag semantics
7. ✅ Determine DRAW_RECT flag semantics

## Background

The ANM parser is the bridge between the BMP sprite decoder (Phase 3) and the physics engine. Without understanding the animation format, we cannot render any part's visual states. The plan described a "TB" format with sections A-D but was uncertain about Sierra wrapper and exact field layouts.

## Method

1. Inspected `BINSOLVE.ANM` binary to identify container structure
2. Validated container pattern across all 433 files
3. Parsed TB header (16 bytes: magic + version + 4 section sizes + width + height)
4. Parsed Section A (UINT16LE frame indices into Section B), Section B (10-byte frame metadata), Section C (4-byte state entries)
5. Decoded Section D bytecode by testing multiple format hypotheses against cross-file patterns
6. Validated DRAW_BMP and DRAW_RECT flag semantics by frequency analysis across all operations
7. Ran full validation: all offsets in-range, all state entries valid, zero unknown opcodes

## Discovery

### Container format

All 433 files use a Sierra `ANM:` chunk wrapper (4-byte tag + 4-byte size) before the `"TB"` inner data. The `ANM:` wrapper must be stripped before parsing.

### TB header (16 bytes)

| Offset | Size | Field |
|--------|------|-------|
| 0 | 2 | Magic (`0x4254` = `"TB"`) |
| 2 | 2 | Version (1000 or 1001) |
| 4 | 2 | Section A count (frame indices) |
| 6 | 2 | Section B count (frames) |
| 8 | 2 | Section C count (states) |
| 10 | 2 | Section D byte count (bytecode) |
| 12 | 2 | Animation width |
| 14 | 2 | Animation height |

### Section D bytecode (6 opcodes)

| Opcode | Name | Size | Fields |
|--------|------|------|--------|
| 0 | END_FRAME | 2 bytes | (none) |
| 1 | END_ANM | 2 bytes | (none) |
| 2 | DRAW_BMP | 12 bytes | resource_id(2) sub_image(2) x(2) y(2) flags(2) |
| 3 | DRAW_RECT | 14 bytes | x(2) y(2) w(2) h(2) color(2) flags(2) |
| 4 | DRAW_LINE | 12 bytes | x1(2) y1(2) x2(2) y2(2) flags(2) |
| 5 | PLAY_SFX | 4 bytes | sound_id(2) |

### Flag semantics

**DRAW_BMP** (18,366 ops across 433 files): bit 0 = horizontal flip, bit 1 = vertical flip. Only values 0, 1, 2, 3 observed.

**DRAW_RECT** (2,031 ops): bit 15 = absolute coordinates, bits 0-3 = draw mode.

**Source:** `scripts/phase-4/01-parse-anm.py` → `build/phase-4/anm/` (433 JSON files)

## False starts

### Attempt 1 — DRAW_BMP "hash" field (4 bytes)
The plan described a 4-byte "hash" parameter for DRAW_BMP. Testing against BUTTONS.ANM revealed these were actually two UINT16LE fields: `resource_id` and `sub_image`. The "hash" interpretation produced values that never matched RESOURCE.MAP entries.

### Attempt 2 — Unsigned position offsets
Initially assumed all Section B offsets were unsigned. On inspection, `x` and `y` in Section B can be negative (off-screen sprites) — confirmed as INT16LE (signed).

## Validation

| Metric | Value |
|--------|-------|
| Total ANM files | 433 |
| Parsed successfully | 433 (100%) |
| Errors | 0 |
| Total bytecode commands | 28,100 |
| Unique opcodes | 6 (no unknown commands) |

```bash
bash scripts/phase-4-animations.sh
# All 433 files parsed, zero errors
```

## Questions closed

- Q-005: Do .ANM files have a Sierra container wrapper? → Yes, all 433 use `ANM:` wrapper with `TB` inner
- Q-006: How is the TB header structured? → 16 bytes: magic + version + 4 section sizes + width + height
- Q-007: How many Section D opcodes exist? → Exactly 6 (0-5), no unknown opcodes in any file
- Q-008: What are the DRAW_BMP/DRAW_RECT flag semantics? → BMP: bit 0=hflip, bit 1=vflip. RECT: bit 15=absolute, bits 0-3=mode

## Cold takeaways

1. **Don't trust the plan's field sizes.** The "4-byte hash" in the plan was actually two 2-byte fields. Always validate structural hypotheses against real data.
2. **Pattern matching across many files beats single-file analysis.** The incrementing sub_image values across BUTTONS.ANM frames revealed the true field layout.
3. **Validate "universal" claims with coverage checks.** "6 opcodes" was only credible because ALL 433 files and ALL 28,100 commands were checked — no unknown opcodes found.
4. **The Sierra wrapper pattern is consistent.** BMP, PAL, and ANM all use the same `TAG:` + UINT32LE size container format. Expect it everywhere in Sierra/Dynamix files.
5. **Signed vs unsigned matters.** Animation offsets (x, y) can be negative for off-screen sprites. Always check the range of values before choosing INT16 vs UINT16.

## References

- Source: `build/phase-1/extracted/*.ANM` (433 files)
- Script: `scripts/phase-4/01-parse-anm.py`
- Output: `build/phase-4/anm/` (433 JSON files)
- Prior art: Sierra SCI ANM format documentation (similar but non-identical container)