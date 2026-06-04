# Part 239 — Coral Branch

## Identity

| Field | Value |
|-------|-------|
| Part Type | `239` |
| Category | Scenery |
| Description | Square wood tile (32x25) |
| ANM File | `PART239.ANM` → `build/phase-4/anm/PART239.json` |
| BMP Resource | `PART239.BMP` → `build/phase-3/bitmaps/PART239_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 32 | bitmap frame width |
| `bitmap_h` | 25 | bitmap frame height |

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
| 0 | 32×25 | `build/phase-3/bitmaps/PART239_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART239.json` |
| Sprite PNGs | `godot/assets/sprites/PART239_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/RLEV1.yaml` |

---

*Generated from `build/phase-4/anm/PART239.json` + `build/phase-5/yaml/`*
