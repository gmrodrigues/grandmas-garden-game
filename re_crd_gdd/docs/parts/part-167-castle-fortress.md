# Part 167 — Castle Fortress

## Identity

| Field | Value |
|-------|-------|
| Part Type | `167` |
| Category | Scenery |
| Description | Building/wall section tall (96x124) |
| ANM File | `PART167.ANM` → `build/phase-4/anm/PART167.json` |
| BMP Resource | `PART167.BMP` → `build/phase-3/bitmaps/PART167_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 96 | bitmap frame width |
| `bitmap_h` | 124 | bitmap frame height |

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
| 0 | 96×124 | `build/phase-3/bitmaps/PART167_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART167.json` |
| Sprite PNGs | `godot/assets/sprites/PART167_*.png` |
| Level YAML | `godot/assets/levels/MLEV25.yaml` |
| Level YAML | `godot/assets/levels/RLEV24.yaml` |
| Level YAML | `godot/assets/levels/RLEV4.yaml` |

---

*Generated from `build/phase-4/anm/PART167.json` + `build/phase-5/yaml/`*
