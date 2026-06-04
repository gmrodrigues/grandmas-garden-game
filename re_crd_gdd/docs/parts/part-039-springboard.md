# Part 39 — Springboard

## Identity

| Field | Value |
|-------|-------|
| Part Type | `39` |
| Category | Springs / Pneumatics |
| Description | Anything you drop on this springboard will go higher with each bounce. |
| ANM File | `PART39.ANM` → `build/phase-4/anm/PART39.json` |
| BMP Resource | `PART39.BMP` → `build/phase-3/bitmaps/PART39_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**54 level(s)** use this part type:

- `build/phase-5/yaml/ELEV10.yaml` → `godot/assets/levels/ELEV10.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH12.yaml` → `godot/assets/levels/HH12.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH24.yaml` → `godot/assets/levels/HH24.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH31.yaml` → `godot/assets/levels/HH31.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH38.yaml` → `godot/assets/levels/HH38.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH47.yaml` → `godot/assets/levels/HH47.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH5.yaml` → `godot/assets/levels/HH5.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- ... and 24 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 49 | bitmap frame width |
| `bitmap_h` | 27 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 7 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 9 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–1 (2 frames) | 56×27 | 0 |
| `5` | 2 | 2–7 (6 frames) | 56×43 | 26 |
| `4` | 8 | 8 | 56×27 | 106 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0005`, `0001_0000` | `build/phase-3/bitmaps/PART39_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f000.png :material-check:` |
| 1 | `0001_0003`, `0001_0000` | `build/phase-3/bitmaps/PART39_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f000.png :material-check:` |
| 2 | `0001_0004`, `0001_0002` | `build/phase-3/bitmaps/PART39_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f002.png :material-check:` |
| 3 | `0001_0004`, `0001_0000` | `build/phase-3/bitmaps/PART39_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f000.png :material-check:` |
| 4 | `0001_0004`, `0001_0001` | `build/phase-3/bitmaps/PART39_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f001.png :material-check:` |
| 5 | `0001_0006`, `0001_0001` | `build/phase-3/bitmaps/PART39_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f001.png :material-check:` |
| 6 | `0001_0003`, `0001_0001` | `build/phase-3/bitmaps/PART39_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f001.png :material-check:` |
| 7 | `0001_0006`, `0001_0002` | `build/phase-3/bitmaps/PART39_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f002.png :material-check:` |
| 8 | `0001_0005`, `0001_0000` | `build/phase-3/bitmaps/PART39_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART39_f000.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 2 | `3039` | 0 | `build/phase-6/raw-wav/SX_3039_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 18 |
| `END_FRAME` | 9 |
| `PLAY_SFX` | 1 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Springboard** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART39.json` |
| Sprite PNGs | `godot/assets/sprites/PART39_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/HH1.yaml` |
| ... | +49 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART39.json` + `build/phase-5/yaml/`*
