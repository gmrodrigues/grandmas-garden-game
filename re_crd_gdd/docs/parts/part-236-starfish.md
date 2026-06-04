# Part 236 — Starfish

## Identity

| Field | Value |
|-------|-------|
| Part Type | `236` |
| Category | Scenery |
| Description | Wood filler joint (24x19) |
| ANM File | `PART236.ANM` → `build/phase-4/anm/PART236.json` |
| BMP Resource | `PART236.BMP` → `build/phase-3/bitmaps/PART236_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 24 | bitmap frame width |
| `bitmap_h` | 19 | bitmap frame height |

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
| 0 | 24×19 | `build/phase-3/bitmaps/PART236_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART236.json` |
| Sprite PNGs | `godot/assets/sprites/PART236_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/MLEV20.yaml` |

---

*Generated from `build/phase-4/anm/PART236.json` + `build/phase-5/yaml/`*
