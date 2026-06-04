# Part 256 — Shark

## Identity

| Field | Value |
|-------|-------|
| Part Type | `256` |
| Category | Scenery |
| Description | Background ledge (48x15) |
| ANM File | `PART256.ANM` → `build/phase-4/anm/PART256.json` |
| BMP Resource | `PART256.BMP` → `build/phase-3/bitmaps/PART256_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 48 | bitmap frame width |
| `bitmap_h` | 15 | bitmap frame height |

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
| 0 | 48×15 | `build/phase-3/bitmaps/PART256_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART256.json` |
| Sprite PNGs | `godot/assets/sprites/PART256_*.png` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/HLEV29.yaml` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |
| Level YAML | `godot/assets/levels/RLEV23.yaml` |

---

*Generated from `build/phase-4/anm/PART256.json` + `build/phase-5/yaml/`*
