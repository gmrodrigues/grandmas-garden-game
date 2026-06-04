# Part 203 — Dark Space

## Identity

| Field | Value |
|-------|-------|
| Part Type | `203` |
| Category | Scenery |
| Description | Solid dark filler (72x72) |
| ANM File | `PART203.ANM` → `build/phase-4/anm/PART203.json` |
| BMP Resource | `PART203.BMP` → `build/phase-3/bitmaps/PART203_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**6 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 72 | bitmap frame width |
| `bitmap_h` | 72 | bitmap frame height |

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
| 0 | 72×72 | `build/phase-3/bitmaps/PART203_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART203.json` |
| Sprite PNGs | `godot/assets/sprites/PART203_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/HLEV20.yaml` |
| Level YAML | `godot/assets/levels/HLEV25.yaml` |
| ... | +1 more levels |

---

*Generated from `build/phase-4/anm/PART203.json` + `build/phase-5/yaml/`*
