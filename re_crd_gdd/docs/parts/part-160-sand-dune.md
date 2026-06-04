# Part 160 — Sand Dune

## Identity

| Field | Value |
|-------|-------|
| Part Type | `160` |
| Category | Scenery |
| Description | Wood plank horizontal (112x21) |
| ANM File | `PART160.ANM` → `build/phase-4/anm/PART160.json` |
| BMP Resource | `PART160.BMP` → `build/phase-3/bitmaps/PART160_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV6.yaml` → `godot/assets/levels/HLEV6.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 112 | bitmap frame width |
| `bitmap_h` | 21 | bitmap frame height |

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
| 0 | 112×21 | `build/phase-3/bitmaps/PART160_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART160.json` |
| Sprite PNGs | `godot/assets/sprites/PART160_*.png` |
| Level YAML | `godot/assets/levels/HLEV26.yaml` |
| Level YAML | `godot/assets/levels/HLEV6.yaml` |

---

*Generated from `build/phase-4/anm/PART160.json` + `build/phase-5/yaml/`*
