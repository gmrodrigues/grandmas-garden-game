# Part 185 — Cityscape

## Identity

| Field | Value |
|-------|-------|
| Part Type | `185` |
| Category | Scenery |
| Description | Wood tile (56x40) |
| ANM File | `PART185.ANM` → `build/phase-4/anm/PART185.json` |
| BMP Resource | `PART185.BMP` → `build/phase-3/bitmaps/PART185_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 56 | bitmap frame width |
| `bitmap_h` | 40 | bitmap frame height |

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
| 0 | 56×40 | `build/phase-3/bitmaps/PART185_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART185.json` |
| Sprite PNGs | `godot/assets/sprites/PART185_*.png` |
| Level YAML | `godot/assets/levels/HLEV31.yaml` |
| Level YAML | `godot/assets/levels/MLEV26.yaml` |
| Level YAML | `godot/assets/levels/RLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART185.json` + `build/phase-5/yaml/`*
