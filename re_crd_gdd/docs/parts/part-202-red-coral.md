# Part 202 — Red Coral

## Identity

| Field | Value |
|-------|-------|
| Part Type | `202` |
| Category | Scenery |
| Description | Red decorative beam (168x18) |
| ANM File | `PART202.ANM` → `build/phase-4/anm/PART202.json` |
| BMP Resource | `PART202.BMP` → `build/phase-3/bitmaps/PART202_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 168 | bitmap frame width |
| `bitmap_h` | 18 | bitmap frame height |

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
| 0 | 168×18 | `build/phase-3/bitmaps/PART202_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART202.json` |
| Sprite PNGs | `godot/assets/sprites/PART202_*.png` |
| Level YAML | `godot/assets/levels/HLEV21.yaml` |
| Level YAML | `godot/assets/levels/HLEV22.yaml` |
| Level YAML | `godot/assets/levels/MLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART202.json` + `build/phase-5/yaml/`*
