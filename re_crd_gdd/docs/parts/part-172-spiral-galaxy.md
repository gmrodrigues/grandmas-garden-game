# Part 172 — Spiral Galaxy

## Identity

| Field | Value |
|-------|-------|
| Part Type | `172` |
| Category | Scenery |
| Description | Ice ruin/arch structure (80x84) |
| ANM File | `PART172.ANM` → `build/phase-4/anm/PART172.json` |
| BMP Resource | `PART172.BMP` → `build/phase-3/bitmaps/PART172_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**1 level(s)** use this part type:

- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 80 | bitmap frame width |
| `bitmap_h` | 84 | bitmap frame height |

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
| 0 | 80×84 | `build/phase-3/bitmaps/PART172_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART172.json` |
| Sprite PNGs | `godot/assets/sprites/PART172_*.png` |
| Level YAML | `godot/assets/levels/HLEV20.yaml` |

---

*Generated from `build/phase-4/anm/PART172.json` + `build/phase-5/yaml/`*
