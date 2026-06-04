# Part 230 — Ship Logo

## Identity

| Field | Value |
|-------|-------|
| Part Type | `230` |
| Category | Scenery |
| Description | Background strip (40x16) |
| ANM File | `PART230.ANM` → `build/phase-4/anm/PART230.json` |
| BMP Resource | `PART230.BMP` → `build/phase-3/bitmaps/PART230_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 40 | bitmap frame width |
| `bitmap_h` | 16 | bitmap frame height |

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
| 0 | 40×16 | `build/phase-3/bitmaps/PART230_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART230.json` |
| Sprite PNGs | `godot/assets/sprites/PART230_*.png` |
| Level YAML | `godot/assets/levels/HLEV27.yaml` |
| Level YAML | `godot/assets/levels/MLEV20.yaml` |
| Level YAML | `godot/assets/levels/RLEV1.yaml` |

---

*Generated from `build/phase-4/anm/PART230.json` + `build/phase-5/yaml/`*
