# Part 228 — Anchor

## Identity

| Field | Value |
|-------|-------|
| Part Type | `228` |
| Category | Scenery |
| Description | Medium wood block (48x42) |
| ANM File | `PART228.ANM` → `build/phase-4/anm/PART228.json` |
| BMP Resource | `PART228.BMP` → `build/phase-3/bitmaps/PART228_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 48 | bitmap frame width |
| `bitmap_h` | 42 | bitmap frame height |

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
| 0 | 48×42 | `build/phase-3/bitmaps/PART228_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART228.json` |
| Sprite PNGs | `godot/assets/sprites/PART228_*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |

---

*Generated from `build/phase-4/anm/PART228.json` + `build/phase-5/yaml/`*
