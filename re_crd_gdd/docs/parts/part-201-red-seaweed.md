# Part 201 — Red Seaweed

## Identity

| Field | Value |
|-------|-------|
| Part Type | `201` |
| Category | Scenery |
| Description | Wide red decorative trim (128x24) |
| ANM File | `PART201.ANM` → `build/phase-4/anm/PART201.json` |
| BMP Resource | `PART201.BMP` → `build/phase-3/bitmaps/PART201_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 128 | bitmap frame width |
| `bitmap_h` | 24 | bitmap frame height |

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
| 0 | 128×24 | `build/phase-3/bitmaps/PART201_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART201.json` |
| Sprite PNGs | `godot/assets/sprites/PART201_*.png` |
| Level YAML | `godot/assets/levels/HLEV22.yaml` |
| Level YAML | `godot/assets/levels/MLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART201.json` + `build/phase-5/yaml/`*
