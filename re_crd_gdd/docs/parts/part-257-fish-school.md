# Part 257 — Fish School

## Identity

| Field | Value |
|-------|-------|
| Part Type | `257` |
| Category | Scenery |
| Description | Nano wood tile (16x9) |
| ANM File | `PART257.ANM` → `build/phase-4/anm/PART257.json` |
| BMP Resource | `PART257.BMP` → `build/phase-3/bitmaps/PART257_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 16 | bitmap frame width |
| `bitmap_h` | 9 | bitmap frame height |

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
| 0 | 16×9 | `build/phase-3/bitmaps/PART257_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART257.json` |
| Sprite PNGs | `godot/assets/sprites/PART257_*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/MLEV20.yaml` |

---

*Generated from `build/phase-4/anm/PART257.json` + `build/phase-5/yaml/`*
