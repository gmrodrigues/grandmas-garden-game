# Part 245 — Seaweed Vine

## Identity

| Field | Value |
|-------|-------|
| Part Type | `245` |
| Category | Scenery |
| Description | Tall thin wood divider (16x81) |
| ANM File | `PART245.ANM` → `build/phase-4/anm/PART245.json` |
| BMP Resource | `PART245.BMP` → `build/phase-3/bitmaps/PART245_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**5 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 16 | bitmap frame width |
| `bitmap_h` | 81 | bitmap frame height |

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
| 0 | 16×81 | `build/phase-3/bitmaps/PART245_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART245.json` |
| Sprite PNGs | `godot/assets/sprites/PART245_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |
| Level YAML | `godot/assets/levels/RLEV1.yaml` |
| Level YAML | `godot/assets/levels/RLEV21.yaml` |

---

*Generated from `build/phase-4/anm/PART245.json` + `build/phase-5/yaml/`*
