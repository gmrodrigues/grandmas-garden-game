# Part 206 — Ocean Wave

## Identity

| Field | Value |
|-------|-------|
| Part Type | `206` |
| Category | Scenery |
| Description | Ice strip horizontal (112x32) |
| ANM File | `PART206.ANM` → `build/phase-4/anm/PART206.json` |
| BMP Resource | `PART206.BMP` → `build/phase-3/bitmaps/PART206_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 112 | bitmap frame width |
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
| `2` | 0 |

### Frame Sprite Details

| Frame | Dimensions | PNG References |
|-------|------------|----------------|
| 0 | 112×32 | `build/phase-3/bitmaps/PART206_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART206.json` |
| Sprite PNGs | `godot/assets/sprites/PART206_*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/HLEV10.yaml` |
| Level YAML | `godot/assets/levels/MLEV28.yaml` |

---

*Generated from `build/phase-4/anm/PART206.json` + `build/phase-5/yaml/`*
