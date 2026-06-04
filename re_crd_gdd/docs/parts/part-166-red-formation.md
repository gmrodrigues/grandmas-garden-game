# Part 166 — Red Formation

## Identity

| Field | Value |
|-------|-------|
| Part Type | `166` |
| Category | Scenery |
| Description | Red wood strip narrow (56x26) |
| ANM File | `PART166.ANM` → `build/phase-4/anm/PART166.json` |
| BMP Resource | `PART166.BMP` → `build/phase-3/bitmaps/PART166_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 56 | bitmap frame width |
| `bitmap_h` | 26 | bitmap frame height |

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
| 0 | 56×26 | `build/phase-3/bitmaps/PART166_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART166.json` |
| Sprite PNGs | `godot/assets/sprites/PART166_*.png` |
| Level YAML | `godot/assets/levels/HLEV22.yaml` |
| Level YAML | `godot/assets/levels/MLEV25.yaml` |

---

*Generated from `build/phase-4/anm/PART166.json` + `build/phase-5/yaml/`*
