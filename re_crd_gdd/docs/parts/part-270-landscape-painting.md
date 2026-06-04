# Part 270 — Landscape Painting

## Identity

| Field | Value |
|-------|-------|
| Part Type | `270` |
| Category | Scenery |
| Description | Large ice block (104x76) |
| ANM File | `PART270.ANM` → `build/phase-4/anm/PART270.json` |
| BMP Resource | `PART270.BMP` → `build/phase-3/bitmaps/PART270_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/RLEV2.yaml` → `godot/assets/levels/RLEV2.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 104 | bitmap frame width |
| `bitmap_h` | 76 | bitmap frame height |

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
| 0 | 104×76 | `build/phase-3/bitmaps/PART270_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART270.json` |
| Sprite PNGs | `godot/assets/sprites/PART270_*.png` |
| Level YAML | `godot/assets/levels/RLEV2.yaml` |

---

*Generated from `build/phase-4/anm/PART270.json` + `build/phase-5/yaml/`*
