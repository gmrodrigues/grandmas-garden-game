# Part 213 — Coral Branch

## Identity

| Field | Value |
|-------|-------|
| Part Type | `213` |
| Category | Scenery |
| Description | Wood railing section (56x44) |
| ANM File | `PART213.ANM` → `build/phase-4/anm/PART213.json` |
| BMP Resource | `PART213.BMP` → `build/phase-3/bitmaps/PART213_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 56 | bitmap frame width |
| `bitmap_h` | 44 | bitmap frame height |

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
| 0 | 56×44 | `build/phase-3/bitmaps/PART213_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART213.json` |
| Sprite PNGs | `godot/assets/sprites/PART213_*.png` |
| Level YAML | `godot/assets/levels/HLEV29.yaml` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |
| Level YAML | `godot/assets/levels/RLEV21.yaml` |
| Level YAML | `godot/assets/levels/RLEV23.yaml` |

---

*Generated from `build/phase-4/anm/PART213.json` + `build/phase-5/yaml/`*
