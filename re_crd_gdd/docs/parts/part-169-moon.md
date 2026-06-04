# Part 169 — Moon

## Identity

| Field | Value |
|-------|-------|
| Part Type | `169` |
| Category | Scenery |
| Description | Ice background panel (64x61) |
| ANM File | `PART169.ANM` → `build/phase-4/anm/PART169.json` |
| BMP Resource | `PART169.BMP` → `build/phase-3/bitmaps/PART169_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**11 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV24.yaml` → `godot/assets/levels/MLEV24.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/RLEV12.yaml` → `godot/assets/levels/RLEV12.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 64 | bitmap frame width |
| `bitmap_h` | 61 | bitmap frame height |

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
| 0 | 64×61 | `build/phase-3/bitmaps/PART169_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART169.json` |
| Sprite PNGs | `godot/assets/sprites/PART169_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/ELEV5.yaml` |
| Level YAML | `godot/assets/levels/HLEV20.yaml` |
| ... | +6 more levels |

---

*Generated from `build/phase-4/anm/PART169.json` + `build/phase-5/yaml/`*
