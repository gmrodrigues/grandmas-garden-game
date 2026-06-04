# Part 193 — Radio Tower

## Identity

| Field | Value |
|-------|-------|
| Part Type | `193` |
| Category | Scenery |
| Description | Short ice column section (32x56) |
| ANM File | `PART193.ANM` → `build/phase-4/anm/PART193.json` |
| BMP Resource | `PART193.BMP` → `build/phase-3/bitmaps/PART193_*.png` |
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
| `bitmap_w` | 32 | bitmap frame width |
| `bitmap_h` | 56 | bitmap frame height |

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
| 0 | 32×56 | `build/phase-3/bitmaps/PART193_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART193.json` |
| Sprite PNGs | `godot/assets/sprites/PART193_*.png` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/MLEV24.yaml` |
| Level YAML | `godot/assets/levels/MLEV26.yaml` |
| Level YAML | `godot/assets/levels/RLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART193.json` + `build/phase-5/yaml/`*
