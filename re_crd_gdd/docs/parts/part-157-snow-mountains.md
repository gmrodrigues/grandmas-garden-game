# Part 157 — Snow Mountains

## Identity

| Field | Value |
|-------|-------|
| Part Type | `157` |
| Category | Scenery |
| Description | Snow-topped ice formation (120x32) |
| ANM File | `PART157.ANM` → `build/phase-4/anm/PART157.json` |
| BMP Resource | `PART157.BMP` → `build/phase-3/bitmaps/PART157_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 120 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

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
| 0 | 120×32 | `build/phase-3/bitmaps/PART157_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART157.json` |
| Sprite PNGs | `godot/assets/sprites/PART157_*.png` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/RLEV26.yaml` |
| Level YAML | `godot/assets/levels/RLEV4.yaml` |

---

*Generated from `build/phase-4/anm/PART157.json` + `build/phase-5/yaml/`*
