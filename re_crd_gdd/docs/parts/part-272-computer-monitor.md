# Part 272 — Computer Monitor

## Identity

| Field | Value |
|-------|-------|
| Part Type | `272` |
| Category | Scenery |
| Description | Dark background tile (80x62) |
| ANM File | `PART272.ANM` → `build/phase-4/anm/PART272.json` |
| BMP Resource | `PART272.BMP` → `build/phase-3/bitmaps/PART272_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/MLEV6.yaml` → `godot/assets/levels/MLEV6.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 80 | bitmap frame width |
| `bitmap_h` | 62 | bitmap frame height |

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
| 0 | 80×62 | `build/phase-3/bitmaps/PART272_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART272.json` |
| Sprite PNGs | `godot/assets/sprites/PART272_*.png` |
| Level YAML | `godot/assets/levels/MLEV6.yaml` |

---

*Generated from `build/phase-4/anm/PART272.json` + `build/phase-5/yaml/`*
