# Part 186 — Metropolis

## Identity

| Field | Value |
|-------|-------|
| Part Type | `186` |
| Category | Scenery |
| Description | Ice floor tile (72x44) |
| ANM File | `PART186.ANM` → `build/phase-4/anm/PART186.json` |
| BMP Resource | `PART186.BMP` → `build/phase-3/bitmaps/PART186_*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**2 level(s)** use this part type:

- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `bitmap_w` | 72 | bitmap frame width |
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
| 0 | 72×44 | `build/phase-3/bitmaps/PART186_f000.png` :material-close: |

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
| ANM JSON | `build/phase-4/anm/PART186.json` |
| Sprite PNGs | `godot/assets/sprites/PART186_*.png` |
| Level YAML | `godot/assets/levels/HLEV31.yaml` |
| Level YAML | `godot/assets/levels/MLEV26.yaml` |

---

*Generated from `build/phase-4/anm/PART186.json` + `build/phase-5/yaml/`*
