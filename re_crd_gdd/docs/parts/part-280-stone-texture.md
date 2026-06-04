# Part 280 — Stone Texture

## Identity

| Field | Value |
|-------|-------|
| Part Type | `280` |
| Category | Scenery |
| Description | Wood panel backdrop (72x64) |
| ANM File | `PART280.ANM` → `build/phase-4/anm/PART280.json` |
| BMP Resource | `PART280.BMP` → `build/phase-3/bitmaps/PART280_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**4 level(s)** use this part type:

- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 72 | bitmap frame width |
| `bitmap_h` | 64 | bitmap frame height |

*No physics properties — this is a static scenery part.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 1 |
| Total States | 0 |
| Animated (Section A) | No |

### Frame Sprite Details

| Frame | Dimensions | PNG References |
|-------|------------|----------------|
| 0 | 72×64 | `build/phase-3/bitmaps/PART280_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART280.json` |
| Sprite PNGs | `godot/assets/sprites/PART280_*.png` |
| Level YAML | `godot/assets/levels/HLEV29.yaml` |
| Level YAML | `godot/assets/levels/HLEV30.yaml` |
| Level YAML | `godot/assets/levels/RLEV18.yaml` |
| Level YAML | `godot/assets/levels/RLEV24.yaml` |

---

*Generated from `build/phase-4/anm/PART280.json` + `build/phase-5/yaml/`*
