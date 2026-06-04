# Part 214 — Coral Formation

## Identity

| Field | Value |
|-------|-------|
| Part Type | `214` |
| Category | Scenery |
| Description | Short wood railing (56x28) |
| ANM File | `PART214.ANM` → `build/phase-4/anm/PART214.json` |
| BMP Resource | `PART214.BMP` → `build/phase-3/bitmaps/PART214_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 56 | bitmap frame width |
| `bitmap_h` | 28 | bitmap frame height |

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
| 0 | 56×28 | `build/phase-3/bitmaps/PART214_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART214.json` |
| Sprite PNGs | `godot/assets/sprites/PART214_*.png` |
| Level YAML | `godot/assets/levels/HLEV29.yaml` |

---

*Generated from `build/phase-4/anm/PART214.json` + `build/phase-5/yaml/`*
