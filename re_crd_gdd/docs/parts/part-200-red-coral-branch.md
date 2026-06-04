# Part 200 — Red Coral Branch

## Identity

| Field | Value |
|-------|-------|
| Part Type | `200` |
| Category | Scenery |
| Description | Red decorative trim (112x11) |
| ANM File | `PART200.ANM` → `build/phase-4/anm/PART200.json` |
| BMP Resource | `PART200.BMP` → `build/phase-3/bitmaps/PART200_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 112 | bitmap frame width |
| `bitmap_h` | 11 | bitmap frame height |

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
| 0 | 112×11 | `build/phase-3/bitmaps/PART200_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART200.json` |
| Sprite PNGs | `godot/assets/sprites/PART200_*.png` |
| Level YAML | `godot/assets/levels/HLEV21.yaml` |
| Level YAML | `godot/assets/levels/HLEV22.yaml` |
| Level YAML | `godot/assets/levels/MLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART200.json` + `build/phase-5/yaml/`*
