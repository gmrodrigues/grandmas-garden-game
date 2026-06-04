# Part 188 — Ice Castle

## Identity

| Field | Value |
|-------|-------|
| Part Type | `188` |
| Category | Scenery |
| Description | Background insert (64x33) |
| ANM File | `PART188.ANM` → `build/phase-4/anm/PART188.json` |
| BMP Resource | `PART188.BMP` → `build/phase-3/bitmaps/PART188_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 64 | bitmap frame width |
| `bitmap_h` | 33 | bitmap frame height |

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
| 0 | 64×33 | `build/phase-3/bitmaps/PART188_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART188.json` |
| Sprite PNGs | `godot/assets/sprites/PART188_*.png` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/MLEV26.yaml` |

---

*Generated from `build/phase-4/anm/PART188.json` + `build/phase-5/yaml/`*
