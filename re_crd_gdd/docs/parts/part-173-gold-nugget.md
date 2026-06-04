# Part 173 — Gold Nugget

## Identity

| Field | Value |
|-------|-------|
| Part Type | `173` |
| Category | Scenery |
| Description | Scenery decoration tile |
| ANM File | `PART173.ANM` → `build/phase-4/anm/PART173.json` |
| BMP Resource | `PART173.BMP` → `build/phase-3/bitmaps/PART173_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

This part type does not appear in any built-in levels.

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 72 | bitmap frame width |
| `bitmap_h` | 83 | bitmap frame height |

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
| 0 | 72×83 | `build/phase-3/bitmaps/PART173_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART173.json` |
| Sprite PNGs | `godot/assets/sprites/PART173_*.png` |

---

*Generated from `build/phase-4/anm/PART173.json` + `build/phase-5/yaml/`*
