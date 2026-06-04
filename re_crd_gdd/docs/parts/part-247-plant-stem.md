# Part 247 — Plant Stem

## Identity

| Field | Value |
|-------|-------|
| Part Type | `247` |
| Category | Scenery |
| Description | Narrow wood strip (16x46) |
| ANM File | `PART247.ANM` → `build/phase-4/anm/PART247.json` |
| BMP Resource | `PART247.BMP` → `build/phase-3/bitmaps/PART247_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 16 | bitmap frame width |
| `bitmap_h` | 46 | bitmap frame height |

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
| 0 | 16×46 | `build/phase-3/bitmaps/PART247_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART247.json` |
| Sprite PNGs | `godot/assets/sprites/PART247_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/MLEV20.yaml` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |

---

*Generated from `build/phase-4/anm/PART247.json` + `build/phase-5/yaml/`*
