# Part 170 — Moon Crater

## Identity

| Field | Value |
|-------|-------|
| Part Type | `170` |
| Category | Scenery |
| Description | Wood background panel (72x66) |
| ANM File | `PART170.ANM` → `build/phase-4/anm/PART170.json` |
| BMP Resource | `PART170.BMP` → `build/phase-3/bitmaps/PART170_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 72 | bitmap frame width |
| `bitmap_h` | 66 | bitmap frame height |

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
| 0 | 72×66 | `build/phase-3/bitmaps/PART170_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART170.json` |
| Sprite PNGs | `godot/assets/sprites/PART170_*.png` |
| Level YAML | `godot/assets/levels/MLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART170.json` + `build/phase-5/yaml/`*
