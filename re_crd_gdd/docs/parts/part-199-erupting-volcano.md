# Part 199 — Erupting Volcano

## Identity

| Field | Value |
|-------|-------|
| Part Type | `199` |
| Category | Scenery |
| Description | Large wood panel (128x73) |
| ANM File | `PART199.ANM` → `build/phase-4/anm/PART199.json` |
| BMP Resource | `PART199.BMP` → `build/phase-3/bitmaps/PART199_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 128 | bitmap frame width |
| `bitmap_h` | 73 | bitmap frame height |

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
| 0 | 128×73 | `build/phase-3/bitmaps/PART199_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART199.json` |
| Sprite PNGs | `godot/assets/sprites/PART199_*.png` |
| Level YAML | `godot/assets/levels/HLEV21.yaml` |
| Level YAML | `godot/assets/levels/HLEV22.yaml` |

---

*Generated from `build/phase-4/anm/PART199.json` + `build/phase-5/yaml/`*
