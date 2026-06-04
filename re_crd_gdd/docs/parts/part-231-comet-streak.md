# Part 231 — Comet Streak

## Identity

| Field | Value |
|-------|-------|
| Part Type | `231` |
| Category | Scenery |
| Description | Tiny wood strip (24x12) |
| ANM File | `PART231.ANM` → `build/phase-4/anm/PART231.json` |
| BMP Resource | `PART231.BMP` → `build/phase-3/bitmaps/PART231_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 24 | bitmap frame width |
| `bitmap_h` | 12 | bitmap frame height |

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
| 0 | 24×12 | `build/phase-3/bitmaps/PART231_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART231.json` |
| Sprite PNGs | `godot/assets/sprites/PART231_*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |

---

*Generated from `build/phase-4/anm/PART231.json` + `build/phase-5/yaml/`*
