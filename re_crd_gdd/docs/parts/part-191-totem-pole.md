# Part 191 — Totem Pole

## Identity

| Field | Value |
|-------|-------|
| Part Type | `191` |
| Category | Scenery |
| Description | Vertical wood post (24x83) |
| ANM File | `PART191.ANM` → `build/phase-4/anm/PART191.json` |
| BMP Resource | `PART191.BMP` → `build/phase-3/bitmaps/PART191_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/MLEV24.yaml` → `godot/assets/levels/MLEV24.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 24 | bitmap frame width |
| `bitmap_h` | 83 | bitmap frame height |

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
| 0 | 24×83 | `build/phase-3/bitmaps/PART191_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART191.json` |
| Sprite PNGs | `godot/assets/sprites/PART191_*.png` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/MLEV24.yaml` |
| Level YAML | `godot/assets/levels/MLEV26.yaml` |
| Level YAML | `godot/assets/levels/RLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART191.json` + `build/phase-5/yaml/`*
