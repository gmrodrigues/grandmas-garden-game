# Part 27 — Captain Z Super Phazer

## Identity

| Field | Value |
|-------|-------|
| Part Type | `27` |
| Category | Explosives / Projectiles |
| Description | This spiffy toy phazer shoots pulses of energy. Tie one end of a rope to the trigger and run it through a pulley (placed behind the phazer), then tie the other end to a balloon or something heavy. You can program the number of energy pulses you want to fire, but the gun will only shoot as long as the rope is pulling on the trigger. Use phazer pulses to bump things, pop balloons and blimps, light candles and fuses, and blow up explosives. |
| ANM File | `PART27.ANM` → `build/phase-4/anm/PART27.json` |
| BMP Resource | `PART27.BMP` → `build/phase-3/bitmaps/PART27_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**22 level(s)** use this part type:

- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH23.yaml` → `godot/assets/levels/HH23.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV24.yaml` → `godot/assets/levels/MLEV24.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 192 | Q8.8 = 0.750 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 65 | bitmap frame width |
| `bitmap_h` | 44 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity`, `timer` |
| Destructible | Yes |
| Spawns | `projectile` |
| Category Part Count | 10 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Fired | `1→6` | — | No |
| Fired | `6→-1` | 6 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 10 |
| Total States | 4 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 70×44 | 0 |
| `6` | 1 | 1–7 (7 frames) | 70×44 | 19 |
| `5` | 8 | 8 | 70×44 | 196 |
| `4` | 9 | 9 | 70×44 | 221 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001`, `0001_0020`, `0001_0000` | `build/phase-3/bitmaps/PART27_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:` |
| 1 | `0001_0020`, `0001_0000`, `0001_0002`, `0001_0011` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f011.png :material-check:` |
| 2 | `0001_0020`, `0001_0000`, `0001_0003`, `0001_0012` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f012.png :material-check:` |
| 3 | `0001_0020`, `0001_0000`, `0001_0004`, `0001_0013` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f013.png :material-check:` |
| 4 | `0001_0020`, `0001_0000`, `0001_0005`, `0001_0014` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f014.png :material-check:` |
| 5 | `0001_0020`, `0001_0000`, `0001_0006`, `0001_0015` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f015.png :material-check:` |
| 6 | `0001_0020`, `0001_0000`, `0001_0007`, `0001_0016` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f016.png :material-check:` |
| 7 | `0001_0020`, `0001_0000`, `0001_0008`, `0001_0016` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f016.png :material-check:` |
| 8 | `0001_0020`, `0001_0000`, `0001_0009`, `0001_0018` | `build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f018.png :material-check:` |
| 9 | `0001_0001`, `0001_0020`, `0001_0000`, `0001_0000` | `build/phase-3/bitmaps/PART27_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f020.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART27_f000.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3027` | 0 | `build/phase-6/raw-wav/SX_3027_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 39 |
| `END_FRAME` | 10 |
| `PLAY_SFX` | 1 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | No |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | No |
| Laser | No |
| Projectile | Yes |

## Behavior Notes

**Captain Z Super Phazer** has 2 semantic states: Not Fired, Fired. Transitions are triggered by: collision, proximity, timer.

Terminal state(s): Fired (part is removed from simulation).

This part can be destroyed by explosives.

This part spawns a **projectile** (cannonball, rocket, missile) when triggered. The projectile is a separate part instance.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART27.json` |
| Sprite PNGs | `godot/assets/sprites/PART27_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH20.yaml` |
| Level YAML | `godot/assets/levels/HH23.yaml` |
| Level YAML | `godot/assets/levels/HH26.yaml` |
| Level YAML | `godot/assets/levels/HH27.yaml` |
| ... | +17 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART27.json` + `build/phase-5/yaml/`*
