# Part 159 — Snow Peaks

## Identity

| Field | Value |
|-------|-------|
| Part Type | `159` |
| Category | Scenery |
| Description | Ice spire/pillar (80x31) |
| ANM File | `PART159.ANM` → `build/phase-4/anm/PART159.json` |
| BMP Resource | `PART159.BMP` → `build/phase-3/bitmaps/PART159_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**3 level(s)** use this part type:

- `build/phase-5/yaml/ELEV13.yaml` → `godot/assets/levels/ELEV13.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 80 | bitmap frame width |
| `bitmap_h` | 31 | bitmap frame height |

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
| 0 | 80×31 | `build/phase-3/bitmaps/PART159_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART159.json` |
| Sprite PNGs | `godot/assets/sprites/PART159_*.png` |
| Level YAML | `godot/assets/levels/ELEV13.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/RLEV26.yaml` |

---

*Generated from `build/phase-4/anm/PART159.json` + `build/phase-5/yaml/`*
