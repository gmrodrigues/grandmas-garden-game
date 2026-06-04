# Part 151 — Cave Opening

## Identity

| Field | Value |
|-------|-------|
| Part Type | `151` |
| Category | Scenery |
| Description | Ice cave wall rough (88x47) |
| ANM File | `PART151.ANM` → `build/phase-4/anm/PART151.json` |
| BMP Resource | `PART151.BMP` → `build/phase-3/bitmaps/PART151_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**6 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 88 | bitmap frame width |
| `bitmap_h` | 47 | bitmap frame height |

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
| 0 | 88×47 | `build/phase-3/bitmaps/PART151_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART151.json` |
| Sprite PNGs | `godot/assets/sprites/PART151_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/MLEV13.yaml` |
| Level YAML | `godot/assets/levels/MLEV27.yaml` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |
| ... | +1 more levels |

---

*Generated from `build/phase-4/anm/PART151.json` + `build/phase-5/yaml/`*
