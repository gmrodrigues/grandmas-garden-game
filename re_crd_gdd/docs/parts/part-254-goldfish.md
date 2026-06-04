# Part 254 — Goldfish

## Identity

| Field | Value |
|-------|-------|
| Part Type | `254` |
| Category | Scenery |
| Description | Small wood strip (32x14) |
| ANM File | `PART254.ANM` → `build/phase-4/anm/PART254.json` |
| BMP Resource | `PART254.BMP` → `build/phase-3/bitmaps/PART254_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 32 | bitmap frame width |
| `bitmap_h` | 14 | bitmap frame height |

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
| 0 | 32×14 | `build/phase-3/bitmaps/PART254_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART254.json` |
| Sprite PNGs | `godot/assets/sprites/PART254_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/HLEV29.yaml` |
| Level YAML | `godot/assets/levels/RLEV1.yaml` |

---

*Generated from `build/phase-4/anm/PART254.json` + `build/phase-5/yaml/`*
