# Part 198 — Volcano

## Identity

| Field | Value |
|-------|-------|
| Part Type | `198` |
| Category | Scenery |
| Description | Wood frame/arch (80x57) |
| ANM File | `PART198.ANM` → `build/phase-4/anm/PART198.json` |
| BMP Resource | `PART198.BMP` → `build/phase-3/bitmaps/PART198_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 80 | bitmap frame width |
| `bitmap_h` | 57 | bitmap frame height |

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
| 0 | 80×57 | `build/phase-3/bitmaps/PART198_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART198.json` |
| Sprite PNGs | `godot/assets/sprites/PART198_*.png` |
| Level YAML | `godot/assets/levels/HLEV22.yaml` |
| Level YAML | `godot/assets/levels/MLEV28.yaml` |

---

*Generated from `build/phase-4/anm/PART198.json` + `build/phase-5/yaml/`*
