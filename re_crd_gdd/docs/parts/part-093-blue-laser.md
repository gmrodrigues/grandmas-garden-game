# Part 93 — Blue Laser

## Identity

| Field | Value |
|-------|-------|
| Part Type | `93` |
| Category | Lasers / Optics |
| Description | When this blue laser gun is plugged into an outlet (and the switch is on) it will fire a blue laser beam. When the beam strikes a blue Laser-Activated Plug, it will generate energy that can be used to power anything hooked up to that outlet. Laser beams can be bounced and directed by using angled mirrors. They may also be fired into Laser Mixers, which will blend the colors of the beams. If an object passes through a laser beam, it will temporarily cut off the energy flow. Use laser beams to light fuses and candles, or to pop balloons. |
| ANM File | `PART93.ANM` → `build/phase-4/anm/PART93.json` |
| BMP Resource | `PART93.BMP` → `build/phase-3/bitmaps/PART93_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**32 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/TLEV26.yaml` → `godot/assets/levels/TLEV26.yaml`
- `build/phase-5/yaml/TLEV27.yaml` → `godot/assets/levels/TLEV27.yaml`
- `build/phase-5/yaml/TLEV28.yaml` → `godot/assets/levels/TLEV28.yaml`
- `build/phase-5/yaml/TLEV29.yaml` → `godot/assets/levels/TLEV29.yaml`
- ... and 2 more levels

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
| Not Operating | `1→5`, `5→6`, `6→7`, `7→9` | 7 | No |
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
| `5` | 1 | 1 | 24×42 | 13 |
| `6` | 2 | 2 | 48×18 | 26 |
| `7` | 3 | 3 | 24×42 | 39 |
| `9` | 4 | 4–15 (12 frames) | 48×18 | 52 |
| `4` | 16 | 16–27 (12 frames) | 24×42 | 228 |
| `3` | 28 | 28–39 (12 frames) | 0×0 | 0 |
| `2` | 40 | 40 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f001.png :material-check:` |
| 1 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f004.png :material-check:` |
| 2 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f001.png :material-check:` |
| 3 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f004.png :material-check:` |
| 4 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f001.png :material-check:` |
| 5 | `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f000.png :material-check:` |
| 6 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f001.png :material-check:` |
| 7 | `0002_0000`, `0001_0002` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f002.png :material-check:` |
| 8 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f004.png :material-check:` |
| 9 | `0002_0001`, `0001_0005` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f005.png :material-check:` |
| 10 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f004.png :material-check:` |
| 11 | `0002_0001`, `0001_0003` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f003.png :material-check:` |
| 12 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f001.png :material-check:` |
| 13 | `0002_0000`, `0001_0000` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f000.png :material-check:` |
| 14 | `0002_0000`, `0001_0001` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f001.png :material-check:` |
| 15 | `0002_0000`, `0001_0002` | `build/phase-3/bitmaps/PART93_2_f000.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f002.png :material-check:` |
| 16 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f004.png :material-check:` |
| 17 | `0002_0001`, `0001_0005` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f005.png :material-check:` |
| 18 | `0002_0001`, `0001_0004` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f004.png :material-check:` |
| 19 | `0002_0001`, `0001_0003` | `build/phase-3/bitmaps/PART93_2_f001.png :material-alert-outline: (not found)`<br>`build/phase-3/bitmaps/PART93_f003.png :material-check:` |

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
| 17 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 18 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |
| 19 | `91` | 0 | `build/phase-6/raw-wav/SX_91_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 40 |
| `END_FRAME` | 20 |
| `PLAY_SFX` | 13 |
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

**Blue Laser** has 2 semantic states: Not Operating, Operating. Transitions are triggered by: electrical, proximity, collision.

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
| ANM JSON | `build/phase-4/anm/PART93.json` |
| Sprite PNGs | `godot/assets/sprites/PART93_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH21.yaml` |
| Level YAML | `godot/assets/levels/HH27.yaml` |
| Level YAML | `godot/assets/levels/HH30.yaml` |
| ... | +27 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART93.json` + `build/phase-5/yaml/`*
