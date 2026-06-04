# Part 219 — Submarine

## Identity

| Field | Value |
|-------|-------|
| Part Type | `219` |
| Category | Scenery |
| Description | Wide wood panel (144x64) |
| ANM File | `PART219.ANM` → `build/phase-4/anm/PART219.json` |
| BMP Resource | `PART219.BMP` → `build/phase-3/bitmaps/PART219_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 144 | bitmap frame width |
| `bitmap_h` | 64 | bitmap frame height |

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
| 0 | 144×64 | `build/phase-3/bitmaps/PART219_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART219.json` |
| Sprite PNGs | `godot/assets/sprites/PART219_*.png` |
| Level YAML | `godot/assets/levels/HLEV10.yaml` |
| Level YAML | `godot/assets/levels/RLEV23.yaml` |

---

*Generated from `build/phase-4/anm/PART219.json` + `build/phase-5/yaml/`*
