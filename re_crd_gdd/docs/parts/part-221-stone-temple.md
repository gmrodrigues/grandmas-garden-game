# Part 221 — Stone Temple

## Identity

| Field | Value |
|-------|-------|
| Part Type | `221` |
| Category | Scenery |
| Description | Tall wood block (88x58) |
| ANM File | `PART221.ANM` → `build/phase-4/anm/PART221.json` |
| BMP Resource | `PART221.BMP` → `build/phase-3/bitmaps/PART221_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 88 | bitmap frame width |
| `bitmap_h` | 58 | bitmap frame height |

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
| 0 | 88×58 | `build/phase-3/bitmaps/PART221_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART221.json` |
| Sprite PNGs | `godot/assets/sprites/PART221_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/HLEV10.yaml` |

---

*Generated from `build/phase-4/anm/PART221.json` + `build/phase-5/yaml/`*
