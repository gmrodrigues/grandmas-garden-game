# Part 154 — Rocky Mountain

## Identity

| Field | Value |
|-------|-------|
| Part Type | `154` |
| Category | Scenery |
| Description | Dark floor tile (80x34) |
| ANM File | `PART154.ANM` → `build/phase-4/anm/PART154.json` |
| BMP Resource | `PART154.BMP` → `build/phase-3/bitmaps/PART154_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 80 | bitmap frame width |
| `bitmap_h` | 34 | bitmap frame height |

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
| 0 | 80×34 | `build/phase-3/bitmaps/PART154_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART154.json` |
| Sprite PNGs | `godot/assets/sprites/PART154_*.png` |
| Level YAML | `godot/assets/levels/MLEV5.yaml` |
| Level YAML | `godot/assets/levels/RLEV24.yaml` |

---

*Generated from `build/phase-4/anm/PART154.json` + `build/phase-5/yaml/`*
