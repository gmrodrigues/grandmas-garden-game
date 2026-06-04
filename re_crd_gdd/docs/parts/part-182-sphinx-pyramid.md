# Part 182 — Sphinx Pyramid

## Identity

| Field | Value |
|-------|-------|
| Part Type | `182` |
| Category | Scenery |
| Description | Log cabin wall section (88x44) |
| ANM File | `PART182.ANM` → `build/phase-4/anm/PART182.json` |
| BMP Resource | `PART182.BMP` → `build/phase-3/bitmaps/PART182_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 88 | bitmap frame width |
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
| 0 | 88×44 | `build/phase-3/bitmaps/PART182_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART182.json` |
| Sprite PNGs | `godot/assets/sprites/PART182_*.png` |
| Level YAML | `godot/assets/levels/ELEV5.yaml` |
| Level YAML | `godot/assets/levels/HLEV31.yaml` |
| Level YAML | `godot/assets/levels/RLEV5.yaml` |

---

*Generated from `build/phase-4/anm/PART182.json` + `build/phase-5/yaml/`*
