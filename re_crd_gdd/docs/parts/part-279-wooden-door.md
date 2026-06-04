# Part 279 — Wooden Door

## Identity

| Field | Value |
|-------|-------|
| Part Type | `279` |
| Category | Scenery |
| Description | Tree canopy/foliage (64x80) |
| ANM File | `PART279.ANM` → `build/phase-4/anm/PART279.json` |
| BMP Resource | `PART279.BMP` → `build/phase-3/bitmaps/PART279_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 64 | bitmap frame width |
| `bitmap_h` | 80 | bitmap frame height |

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
| 0 | 64×80 | `build/phase-3/bitmaps/PART279_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART279.json` |
| Sprite PNGs | `godot/assets/sprites/PART279_*.png` |
| Level YAML | `godot/assets/levels/HLEV30.yaml` |
| Level YAML | `godot/assets/levels/RLEV18.yaml` |
| Level YAML | `godot/assets/levels/RLEV24.yaml` |

---

*Generated from `build/phase-4/anm/PART279.json` + `build/phase-5/yaml/`*
