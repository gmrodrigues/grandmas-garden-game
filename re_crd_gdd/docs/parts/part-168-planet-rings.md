# Part 168 — Planet Rings

## Identity

| Field | Value |
|-------|-------|
| Part Type | `168` |
| Category | Scenery |
| Description | Large background decor (160x92) |
| ANM File | `PART168.ANM` → `build/phase-4/anm/PART168.json` |
| BMP Resource | `PART168.BMP` → `build/phase-3/bitmaps/PART168_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 160 | bitmap frame width |
| `bitmap_h` | 92 | bitmap frame height |

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
| 0 | 160×92 | `build/phase-3/bitmaps/PART168_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART168.json` |
| Sprite PNGs | `godot/assets/sprites/PART168_*.png` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |

---

*Generated from `build/phase-4/anm/PART168.json` + `build/phase-5/yaml/`*
