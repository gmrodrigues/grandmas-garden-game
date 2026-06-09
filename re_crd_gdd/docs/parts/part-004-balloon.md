# Part 4 — Balloon

## Identity

| Field | Value |
|-------|-------|
| Part Type | `4` |
| Category | Balloons / Airships |
| Description | This balloon can be programmed to have four different appearances, which all act exactly the same. It will float up into the air unless it's tied down with a rope or held back by another object. Use it to lift the low end of the teeter-totter, shoot the phazer, trigger the boxing glove, push the bellows, or bump various objects. Balloons will pop if they touch moving gears, hedge trimmers, tin snips, any flame, laser beams or tacks. |
| ANM File | `PART4.ANM` → `build/phase-4/anm/PART4.json` |
| BMP Resource | `PART4.BMP` → `build/phase-3/bitmaps/PART4_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**68 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV15.yaml` → `godot/assets/levels/ELEV15.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV7.yaml` → `godot/assets/levels/ELEV7.yaml`
- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH23.yaml` → `godot/assets/levels/HH23.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH31.yaml` → `godot/assets/levels/HH31.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- ... and 38 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 9 | mass/density (relative scale) |
| `unk_2` | 1 | category-specific property |
| `property_q8` | 64 | Q8.8 = 0.250 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 32 | bitmap frame width |
| `bitmap_h` | 48 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity` |
| Destructible | Yes |
| Spawns | *(none)* |
| Category Part Count | 3 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Popped | `3→7`, `2→6`, `4→8`, `5→9` | — | No |
| Popped | `7→2`, `6→4`, `8→5`, `9→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 23 |
| Total States | 8 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `3` | 0 | 0 | 40×51 | 0 |
| `7` | 1 | 1–5 (5 frames) | 40×51 | 7 |
| `2` | 6 | 6 | 48×51 | 44 |
| `6` | 7 | 7–12 (6 frames) | 48×51 | 51 |
| `4` | 13 | 13 | 56×51 | 95 |
| `8` | 14 | 14–17 (4 frames) | 56×51 | 102 |
| `5` | 18 | 18 | 40×42 | 132 |
| `9` | 19 | 19–22 (4 frames) | 40×42 | 139 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0010` | `build/phase-3/bitmaps/PART4_f010.png :material-check:` |
| 1 | `0001_0010` | `build/phase-3/bitmaps/PART4_f010.png :material-check:` |
| 2 | `0001_0011` | `build/phase-3/bitmaps/PART4_f011.png :material-check:` |
| 3 | `0001_0012` | `build/phase-3/bitmaps/PART4_f012.png :material-check:` |
| 4 | `0001_0013` | `build/phase-3/bitmaps/PART4_f013.png :material-check:` |
| 5 | `0001_0014` | `build/phase-3/bitmaps/PART4_f014.png :material-check:` |
| 6 | `0001_0000` | `build/phase-3/bitmaps/PART4_f000.png :material-check:` |
| 7 | `0001_0000` | `build/phase-3/bitmaps/PART4_f000.png :material-check:` |
| 8 | `0001_0001` | `build/phase-3/bitmaps/PART4_f001.png :material-check:` |
| 9 | `0001_0002` | `build/phase-3/bitmaps/PART4_f002.png :material-check:` |
| 10 | `0001_0003` | `build/phase-3/bitmaps/PART4_f003.png :material-check:` |
| 11 | `0001_0004` | `build/phase-3/bitmaps/PART4_f004.png :material-check:` |
| 12 | `0001_0005` | `build/phase-3/bitmaps/PART4_f005.png :material-check:` |
| 13 | `0003_0000` | `build/phase-3/bitmaps/PART4C_f000.png :material-check:` |
| 14 | `0003_0000` | `build/phase-3/bitmaps/PART4C_f000.png :material-check:` |
| 15 | `0003_0001` | `build/phase-3/bitmaps/PART4C_f001.png :material-check:` |
| 16 | `0003_0002` | `build/phase-3/bitmaps/PART4C_f002.png :material-check:` |
| 17 | `0003_0003` | `build/phase-3/bitmaps/PART4C_f003.png :material-check:` |
| 18 | `0004_0000` | `build/phase-3/bitmaps/PART4D_f000.png :material-check:` |
| 19 | `0004_0000` | `build/phase-3/bitmaps/PART4D_f000.png :material-check:` |
| 20 | `0004_0001` | `build/phase-3/bitmaps/PART4D_f001.png :material-check:` |
| 21 | `0004_0002` | `build/phase-3/bitmaps/PART4D_f002.png :material-check:` |
| 22 | `0004_0003` | `build/phase-3/bitmaps/PART4D_f003.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 2 | `3004` | 0 | `build/phase-6/raw-wav/SX_3004_11025.wav` |
| 8 | `3004` | 0 | `build/phase-6/raw-wav/SX_3004_11025.wav` |
| 15 | `3004` | 0 | `build/phase-6/raw-wav/SX_3004_11025.wav` |
| 20 | `3004` | 0 | `build/phase-6/raw-wav/SX_3004_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 23 |
| `END_FRAME` | 23 |
| `PLAY_SFX` | 4 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | No |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Balloon** has 2 semantic states: Not Popped, Popped. Transitions are triggered by: collision, proximity.

Terminal state(s): Popped (part is removed from simulation).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART4.json` |
| Sprite PNGs | `godot/assets/sprites/PART4_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV15.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| ... | +63 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART4.json` + `build/phase-5/yaml/`*
