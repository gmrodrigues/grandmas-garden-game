# Part 192 — Satellite Tower

## Identity

| Field | Value |
|-------|-------|
| Part Type | `192` |
| Category | Scenery |
| Description | Tall ice spire/formation (72x103) |
| ANM File | `PART192.ANM` → `build/phase-4/anm/PART192.json` |
| BMP Resource | `PART192.BMP` → `build/phase-3/bitmaps/PART192_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/MLEV24.yaml` → `godot/assets/levels/MLEV24.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 72 | bitmap frame width |
| `bitmap_h` | 103 | bitmap frame height |

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
| 0 | 72×103 | `build/phase-3/bitmaps/PART192_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART192.json` |
| Sprite PNGs | `godot/assets/sprites/PART192_*.png` |
| Level YAML | `godot/assets/levels/MLEV24.yaml` |
| Level YAML | `godot/assets/levels/RLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART192.json` + `build/phase-5/yaml/`*
