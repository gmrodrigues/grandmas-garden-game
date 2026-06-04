# Part 150 — Pine Forest

## Identity

| Field | Value |
|-------|-------|
| Part Type | `150` |
| Category | Scenery |
| Description | Ice wall panel (104x45) |
| ANM File | `PART150.ANM` → `build/phase-4/anm/PART150.json` |
| BMP Resource | `PART150.BMP` → `build/phase-3/bitmaps/PART150_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**6 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV24.yaml` → `godot/assets/levels/ELEV24.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 104 | bitmap frame width |
| `bitmap_h` | 45 | bitmap frame height |

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
| 0 | 104×45 | `build/phase-3/bitmaps/PART150_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART150.json` |
| Sprite PNGs | `godot/assets/sprites/PART150_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV24.yaml` |
| Level YAML | `godot/assets/levels/MLEV13.yaml` |
| Level YAML | `godot/assets/levels/MLEV27.yaml` |
| ... | +1 more levels |

---

*Generated from `build/phase-4/anm/PART150.json` + `build/phase-5/yaml/`*
