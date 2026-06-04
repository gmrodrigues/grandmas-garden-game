# E-002: anm-format

**Date:** 2025-05-22
**Questions investigated:** Q-005, Q-006, Q-007, Q-008
**Gap:** G9 (DRAW_BMP flags), G10 (DRAW_RECT flags)

## TL;DR

Decoded the TIM2 .ANM animation format from raw binary to structured JSON. Discovered that all 433 files wrap a "TB" inner format inside a Sierra "ANM:" container. Identified a 6-opcode render bytecode (END_FRAME, END_ANM, DRAW_BMP, DRAW_RECT, DRAW_LINE, PLAY_SFX) and verified it against all 28,100 commands across all files with zero unknown opcodes.

## Goals

1. ✅ Determine whether .ANM files have a Sierra container wrapper or stand-alone format
2. ✅ Parse the TB header and identify all four sections
3. ✅ Decode the Section D bytecode command set
4. ✅ Determine field layouts for all commands (DRAW_BMP, DRAW_RECT, DRAW_LINE, PLAY_SFX)
5. ✅ Validate parsing against all 433 files with zero errors
6. ✅ Determine DRAW_BMP flag semantics (G9)
7. ✅ Determine DRAW_RECT flag semantics (G10)

## Pre-session state

- Phase 1 extraction complete: 433 .ANM files extracted to `build/phase-1/extracted/`
- The plan document described a "TB" magic and four sections (A/B/C/D) but was uncertain about container wrappers
- Section D opcodes were hypothesized but not verified
- No validation had been run against the full file set

## Hypothesis

The .ANM files use a Sierra chunked container (like BMP and PAL) wrapping a "TB" inner format with four sections: frame durations (A), frame metadata (B), state map (C), and render bytecode (D). The bytecode has exactly 6 commands, all using UINT16LE parameters. DRAW_BMP flags are bit fields for sprite transformations.

## Session log

### Step 1 — Sample a file and identify container format

Inspected `BINSOLVE.ANM` first 16 bytes: found `"ANM:"` Sierra chunk wrapper (4+4 bytes), followed by `"TB"` magic. This confirmed the double-wrapper pattern seen in BMP/PAL.

### Step 2 — Validate across all 433 files

All files have `"ANM:"` wrapper. 424 use version 1001, 9 use version 1000. Pattern is universal.

### Step 3 — Parse TB header and sections A/B/C

Identified header layout:
- Magic (`0x4254` = "TB"), version (1000 or 1001)
- Section sizes: `sa`, `sb`, `sc`, `sd` (all UINT16LE)
- Width, height (UINT16LE)

Section A: UINT16LE array of frame indices into Section B (not tick counts). Each entry selects which Section B sprite to display for a given state + counter offset. Section B: 10-byte entries (x, y, width, height, bytecode_offset). Section C: 4-byte entries (first_frame_id, state_id).

**Correction (2026-05-27):** The original description "tick counts" was wrong. Section A is an indirection array: `section_a[first_a_idx + state_counter] → section_b frame index`. See E-014 and R-002 for the corrected animation pipeline understanding.

### Step 4 — Attempt #1: Determine DRAW_BMP field layout

Initially tried parsing DRAW_BMP as "hash(4) + x(2) + y(2)" based on the plan. This produced implausible values — the "hash" field was never a valid RESOURCE.MAP hash.

**Breakthrough:** Re-read the first DRAW_BMP in BUTTONS.ANM: `(1, 0, 0, 0, 0)`. Fields 1 and 2 increment together across frames. This pattern means: `resource_id(2)` referencing a sub-image in the BMP, `sub_image(2)` as the frame index, `x(2)` and `y(2)` as position, `flags(2)` for transformations.

### Step 5 — Validate DRAW_BMP and DRAW_RECT flags

Cross-referenced 18,366 DRAW_BMP operations across all 433 ANMs. Found only 4 distinct flag values: 0, 1, 2, 3. Pattern: bit 0 = horizontal flip, bit 1 = vertical flip. Confirmed G9.

Cross-referenced 2,031 DRAW_RECT operations. Found bit 15 = absolute coordinates, bits 0-3 = draw mode. Confirmed G10.

### Step 6 — Full validation run

Parsed all 433 files. Zero errors. All bytecode offsets valid, all section C indices valid, every file has exactly 1 END_ANM terminator.

## Breakthrough

The key insight was that the "hash" field in the plan (4 bytes) was actually two separate UINT16LE fields: `resource_id` (referencing a BMP sub-resource) and `sub_image` (the frame index within that BMP). This was confirmed by the incrementing pattern across BUTTONS.ANM frames.

## Validation

```bash
$ bash scripts/phase-4-animations.sh
# All 433 ANM files parsed, 0 errors
# Total commands: 28,100
# Unique opcodes: 6 (no unknown commands)
```

## New questions raised

- How do Section C state IDs map to physics engine states? (Led to Q-008 / G8, resolved separately)

## Artifacts

- Script: `scripts/phase-4/01-parse-anm.py`
- Output: `build/phase-4/anm/` — 433 JSON files