# Part 174 — Gold Rock

## Identity

| Field | Value |
|-------|-------|
| Part Type | `174` |
| Category | Scenery |
| Description | Scenery decoration tile |
| ANM File | `PART174.ANM` → `build/phase-4/anm/PART174.json` |
| BMP Resource | `PART174.BMP` → `build/phase-3/bitmaps/PART174_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

This part type does not appear in any built-in levels.

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 48 | bitmap frame width |
| `bitmap_h` | 51 | bitmap frame height |

*No physics properties — this is a static scenery part.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 1 |
| Total States | 1 |
| Animated (Section A) | No |

### State → Frame Mapping

| State ID | First Frame |
|----------|-------------|
| `1` | 0 |

### Frame Sprite Details

| Frame | Dimensions | PNG References |
|-------|------------|----------------|
| 0 | 48×51 | `build/phase-3/bitmaps/PART174_f000.png` :material-close: |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 1 |
| `END_ANM` | 1 |
| `END_FRAME` | 1 |

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART174.json` |
| Sprite PNGs | `godot/assets/sprites/PART174_*.png` |

---

*Generated from `build/phase-4/anm/PART174.json` + `build/phase-5/yaml/`*
