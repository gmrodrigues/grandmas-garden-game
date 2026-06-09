# The Incredible Machine 2 — Clean Room Implementation Kit

**Spec complete. Physics deterministic. Ready for Godot.**

## What This Is

A clean-room specification for reimplementing The Incredible Machine 2 (1994, Sierra/Dynamix). The spec was derived from reproducible binary analysis experiments (`docs/experiments/`). No original game source code was referenced.

## Files

| Path | Description |
|------|-------------|
| `godot-specification.md` | **Main spec** — standalone, RE-independent. Godot developer starts here. |
| `data/` | All reference data for implementation |
| ─ `part-name-catalog.json` | 149 part types: names, descriptions, ANM mapping, categories |
| ─ `part-properties.json` | Mass, COR, friction, dimensions for all 149 parts |
| ─ `part-anm-catalog.json` | 433 ANM files with state→frame mappings per ANM |
| ─ `state-part-matrix.json` | 89 state IDs × 422 entries: which states each part type has |
| ─ `part-state-summary.md` | Human-readable per-part state reference |
| ─ `flags_dictionary.py` | Flag bit meanings in machine-readable format |
| ─ `solve-decoded.json` | 52 interactive parts with SOLVE.RES state transition rules |
| ─ `part-assets.json` | Per-part asset catalog: sprites, sounds, durations, states |
| ─ `behaviors.json` | Godot-ready behavior rules per part (trigger types, transitions) |
| ─ `categories.json` | 19 categories with trigger profiles and destructibility |
| ─ `anm/*.json` | 433 decoded ANM animation files (Section A-D) |
| ─ `yaml/*.yaml` | 206 decoded levels (all built-in puzzles) |
| ─ `bitmaps/*.png` | 3,054 decoded sprite frames from 467 BMP files |
| ─ `palettes/*.png` | 27 decoded colour palettes |
| ─ `sx-report.json` | Audio format reference (FM patches, RAW samples) |
| `editor/` | Python validation editor (optional — use to verify spec) |
| ─ `engine/` | Physics, state machine, solver — reference implementation |
| ─ `sprites/` | ANM sprite renderer |
| ─ `test_level.py` | 28 tests: level loading, state machine, ANM rendering |
| ─ `validate_spec.py` | 31 tests: gravity, collision, state, ANM, solutions |
| ─ `test_deterministic.py` | 10+ tests: deterministic physics, save/restore, multi-level |

## Quick Start (Godot Implementation)

1. Read `godot-specification.md` (sections 1-8 cover all engine systems)
2. Implement the physics engine first (Section 3):
   - Gravity at 60 Hz, 7-tier lookup table
   - AABB collision with overlap/2 correction
   - Single-pass distance constraint solver
3. Implement the state machine (Section 4):
   - 89 state IDs, counter cycling with limits
   - Seeded LCG RNG (`AX = AX * 0x343FD + 0x269EC3`)
   - Sub-state countdown at struct offset 0xAE
4. Implement the ANM animation system (Section 5):
   - Section C: state_id → first_frame_id lookup
   - Section B: frame metadata (position, size, bytecode offset)
   - Section D: 6-opcode bytecode interpreter
5. Implement part behaviors using `data/behaviors.json`:
   - 52 interactive parts with SOLVE.RES state transitions
   - 11 interactive categories (Balls, Electrical, Characters, etc.)
   - Per-part triggers: collision, electrical, proximity, timer
   - Explosive/destruction chain reactions
6. Load levels from `data/yaml/` or `.TIM` files (Section 8 format)

## Validation

Run the Python editor tests to verify your implementation matches the spec:

```bash
cd editor/
pipenv run python3 test_level.py       # 28 tests
pipenv run python3 validate_spec.py     # 31 tests  
pipenv run python3 test_deterministic.py  # 10+ tests
```

## Physics Constants

- **Tick rate**: 60 Hz (VBL-synchronized)
- **Gravity**: base/4 per tick, base from 7-tier category table (0x1000-0x1C00)
- **Collision**: AABB, overlap/2 correction
- **Constraints**: Single-pass distance solver, `behavior` = segment length
- **State machine**: 89 states, LCG RNG, sub-state countdown
- **ANM bytecode**: 6 opcodes (END_FRAME, END_ANM, DRAW_BMP, DRAW_RECT, DRAW_LINE, PLAY_SFX)
- **Audio FM**: ADL.DRV driver, SCI28 instrument format, 12-function API

## Tagged Release

`v1.0-spec-complete` — spec and all data are frozen.

## License

Clean-room specification. No original game code or assets are included.
All files are derived from reproducible binary analysis experiments.
