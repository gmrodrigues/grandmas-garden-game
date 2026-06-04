# Part 96 — Laser-Activated Plug

## Identity

| Field | Value |
|-------|-------|
| Part Type | `96` |
| Category | Lasers / Optics |
| Description | When a laser beam of the right color strikes this laser-activated plug, it will provide electrical power to any part plugged into the outlet. It can be programmed to accept laser beams of any color. But if the plug is blue, for instance, it will only accept a blue laser beam. |
| ANM File | `PART96.ANM` → `build/phase-4/anm/PART96.json` |
| BMP Resource | `PART96.BMP` → `build/phase-3/bitmaps/PART96_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**25 level(s)** use this part type:

- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/HLEV9.yaml` → `godot/assets/levels/HLEV9.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/TLEV27.yaml` → `godot/assets/levels/TLEV27.yaml`
- `build/phase-5/yaml/TLEV28.yaml` → `godot/assets/levels/TLEV28.yaml`
- `build/phase-5/yaml/TLEV29.yaml` → `godot/assets/levels/TLEV29.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 0 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 32 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `proximity`, `collision` |
| Destructible | No |
| Spawns | `laser_beam` |
| Category Part Count | 8 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 28 |
| Total States | 10 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 32×32 | 0 |
| `3` | 1 | 1 | 32×32 | 7 |
| `4` | 2 | 2 | 32×32 | 14 |
| `5` | 3 | 3 | 32×32 | 21 |
| `6` | 4 | 4 | 32×32 | 28 |
| `7` | 5 | 5 | 32×32 | 35 |
| `8` | 6 | 6 | 32×32 | 42 |
| `10` | 7 | 7–13 (7 frames) | 32×32 | 49 |
| `11` | 14 | 14–20 (7 frames) | 32×32 | 140 |
| `12` | 21 | 21–27 (7 frames) | 32×32 | 231 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART96_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART96_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART96_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART96_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART96_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART96_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART96_f006.png :material-check:` |
| 7 | `0001_0000`, `0001_0007` | `build/phase-3/bitmaps/PART96_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 8 | `0001_0001`, `0001_0007` | `build/phase-3/bitmaps/PART96_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 9 | `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART96_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 10 | `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART96_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 11 | `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART96_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 12 | `0001_0005`, `0001_0007` | `build/phase-3/bitmaps/PART96_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 13 | `0001_0006`, `0001_0007` | `build/phase-3/bitmaps/PART96_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 14 | `0001_0000`, `0001_0007` | `build/phase-3/bitmaps/PART96_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 15 | `0001_0001`, `0001_0007` | `build/phase-3/bitmaps/PART96_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 16 | `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART96_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 17 | `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART96_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 18 | `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART96_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 19 | `0001_0005`, `0001_0007` | `build/phase-3/bitmaps/PART96_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 20 | `0001_0006`, `0001_0007` | `build/phase-3/bitmaps/PART96_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 21 | `0001_0000`, `0001_0007`, `0001_0007` | `build/phase-3/bitmaps/PART96_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 22 | `0001_0001`, `0001_0007`, `0001_0007` | `build/phase-3/bitmaps/PART96_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 23 | `0001_0002`, `0001_0007`, `0001_0007` | `build/phase-3/bitmaps/PART96_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 24 | `0001_0003`, `0001_0007`, `0001_0007` | `build/phase-3/bitmaps/PART96_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 25 | `0001_0004`, `0001_0007`, `0001_0007` | `build/phase-3/bitmaps/PART96_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 26 | `0001_0005`, `0001_0007`, `0001_0007` | `build/phase-3/bitmaps/PART96_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |
| 27 | `0001_0006`, `0001_0007`, `0001_0007` | `build/phase-3/bitmaps/PART96_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART96_f007.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 56 |
| `END_FRAME` | 28 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | Yes |
| Projectile | No |

## Behavior Notes

**Laser-Activated Plug** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part emits a **laser beam**. The beam interacts with mirrors, mixers, and laser-activated plugs.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART96.json` |
| Sprite PNGs | `godot/assets/sprites/PART96_f*.png` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/HH13.yaml` |
| Level YAML | `godot/assets/levels/HH21.yaml` |
| Level YAML | `godot/assets/levels/HLEV20.yaml` |
| Level YAML | `godot/assets/levels/HLEV23.yaml` |
| ... | +20 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART96.json` + `build/phase-5/yaml/`*
