# Part 227 — Clown Fish

## Identity

| Field | Value |
|-------|-------|
| Part Type | `227` |
| Category | Scenery |
| Description | Wood patch/tile (64x25) |
| ANM File | `PART227.ANM` → `build/phase-4/anm/PART227.json` |
| BMP Resource | `PART227.BMP` → `build/phase-3/bitmaps/PART227_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 64 | bitmap frame width |
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
| 0 | 64×25 | `build/phase-3/bitmaps/PART227_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART227.json` |
| Sprite PNGs | `godot/assets/sprites/PART227_*.png` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |

---

*Generated from `build/phase-4/anm/PART227.json` + `build/phase-5/yaml/`*
