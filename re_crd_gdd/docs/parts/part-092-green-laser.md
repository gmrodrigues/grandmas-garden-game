# Part 92 — Green Laser

## Identity

| Field | Value |
|-------|-------|
| Part Type | `92` |
| Category | Lasers / Optics |
| Description | When this green laser gun is plugged into an outlet (and the switch is on) it will fire a green laser beam. When the beam strikes a green Laser-Activated Plug, it will generate energy that can be used to power anything hooked up to that outlet. Laser beams can be bounced and directed by using angled mirrors. They may also be fired into Laser Mixers, which will blend the colors of the beams. If an object passes through a laser beam, it will temporarily cut off the energy flow. Use laser beams to light fuses and candles, or to pop balloons. |
| ANM File | `PART92.ANM` → `build/phase-4/anm/PART92.json` |
| BMP Resource | `PART92.BMP` → `build/phase-3/bitmaps/PART92_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**23 level(s)** use this part type:

- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/TLEV26.yaml` → `godot/assets/levels/TLEV26.yaml`
- `build/phase-5/yaml/TLEV27.yaml` → `godot/assets/levels/TLEV27.yaml`
- `build/phase-5/yaml/TLEV28.yaml` → `godot/assets/levels/TLEV28.yaml`
- `build/phase-5/yaml/TLEV29.yaml` → `godot/assets/levels/TLEV29.yaml`
- `build/phase-5/yaml/TLEV30.yaml` → `godot/assets/levels/TLEV30.yaml`
- `build/phase-5/yaml/TLEV5.yaml` → `godot/assets/levels/TLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4153 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 24 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 51 | bitmap frame width |
| `bitmap_h` | 51 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `proximity`, `collision` |
| Destructible | No |
| Spawns | `laser_beam` |
| Category Part Count | 8 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Operating | `1→6`, `6→7`, `7→8`, `8→9` | 8 | No |
| Operating | `9→4`, `4→3`, `3→2`, `2→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 20 |
| Total States | 8 |
| Animated (Section A) | Yes |
| Section A Durations | 52 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 48×18 | 0 |
| `6` | 1 | 1 | 24×42 | 13 |
| `7` | 2 | 2 | 48×18 | 26 |
| `8` | 3 | 3 | 24×42 | 39 |
| `9` | 4 | 4–15 (12 frames) | 48×18 | 52 |
| `4` | 16 | 16–27 (12 frames) | 24×42 | 228 |
| `3` | 28 | 28–39 (12 frames) | 0×0 | 0 |
| `2` | 40 | 40 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f001.png :material-check:` |
| 1 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:` |
| 2 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f001.png :material-check:` |
| 3 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:` |
| 4 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f001.png :material-check:` |
| 5 | `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f000.png :material-check:` |
| 6 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f001.png :material-check:` |
| 7 | `0002_0000`, `0001_0002` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f002.png :material-check:` |
| 8 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:` |
| 9 | `0002_0001`, `0001_0005` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f005.png :material-check:` |
| 10 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:` |
| 11 | `0002_0001`, `0001_0003` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f003.png :material-check:` |
| 12 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f001.png :material-check:` |
| 13 | `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f000.png :material-check:` |
| 14 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f001.png :material-check:` |
| 15 | `0002_0000`, `0001_0002` | `build/phase-3/bitmaps/LASER_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f002.png :material-check:` |
| 16 | `0002_0001` | `build/phase-3/bitmaps/LASER_f001.png :material-check:` |
| 17 | `0002_0001`, `0001_0005`, `0001_0004` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:` |
| 18 | `0002_0001`, `0001_0004`, `0001_0004` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:` |
| 19 | `0002_0001`, `0001_0003`, `0001_0004` | `build/phase-3/bitmaps/LASER_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART92_f004.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 4 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 5 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 6 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 7 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 9 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 10 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 11 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 13 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 14 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 15 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 16 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 42 |
| `END_FRAME` | 20 |
| `PLAY_SFX` | 11 |
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

**Green Laser** has 2 semantic states: Not Operating, Operating. Transitions are triggered by: electrical, proximity, collision.

Terminal state(s): Operating (part is removed from simulation).

This part emits a **laser beam**. The beam interacts with mirrors, mixers, and laser-activated plugs.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART92.json` |
| Sprite PNGs | `godot/assets/sprites/PART92_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/HH21.yaml` |
| Level YAML | `godot/assets/levels/HH30.yaml` |
| Level YAML | `godot/assets/levels/HH42.yaml` |
| Level YAML | `godot/assets/levels/HLEV26.yaml` |
| Level YAML | `godot/assets/levels/HLEV27.yaml` |
| ... | +18 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART92.json` + `build/phase-5/yaml/`*
