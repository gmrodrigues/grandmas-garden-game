# Part 19 — Dynamite

## Identity

| Field | Value |
|-------|-------|
| Part Type | `19` |
| Category | Explosives / Projectiles |
| Description | Light the fuse of this dynamite with a laser, a flaming part (like a candle or rocket), or by using a magnifying glass and light source. It will blow up all kinds of things, including some walls. |
| ANM File | `PART19.ANM` → `build/phase-4/anm/PART19.json` |
| BMP Resource | `PART19.BMP` → `build/phase-3/bitmaps/PART19_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**28 level(s)** use this part type:

- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HH7.yaml` → `godot/assets/levels/HH7.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV21.yaml` → `godot/assets/levels/MLEV21.yaml`
- `build/phase-5/yaml/MLEV3.yaml` → `godot/assets/levels/MLEV3.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV4.yaml` → `godot/assets/levels/RLEV4.yaml`
- `build/phase-5/yaml/RLEV9.yaml` → `godot/assets/levels/RLEV9.yaml`
- `build/phase-5/yaml/TLEV9.yaml` → `godot/assets/levels/TLEV9.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1132 | mass/density (relative scale) |
| `unk_2` | 90 | category-specific property |
| `property_q8` | 64 | Q8.8 = 0.250 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 53 | bitmap frame width |
| `bitmap_h` | 15 | bitmap frame height |

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
| Not Blown up | `2→3` | — | No |
| Blown up | `3→-1` | 3 | Yes :material-bomb: |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 18 |
| Total States | 3 |
| Animated (Section A) | Yes |
| Section A Durations | 23 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 53×15 | 0 |
| `3` | 1 | 1–16 (16 frames) | 92×45 | 13 |
| `4` | 17 | 17 | 40×15 | 319 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f001.png :material-check:` |
| 1 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 2 | `0001_0000`, `0001_0001`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 3 | `0001_0000`, `0001_0001`, `0001_0007` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f007.png :material-check:` |
| 4 | `0001_0000`, `0001_0002`, `0001_0008` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f008.png :material-check:` |
| 5 | `0001_0000`, `0001_0002`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 6 | `0001_0000`, `0001_0002`, `0001_0007` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f007.png :material-check:` |
| 7 | `0001_0000`, `0001_0002`, `0001_0008` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f008.png :material-check:` |
| 8 | `0001_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 9 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f007.png :material-check:` |
| 10 | `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 11 | `0001_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 12 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f007.png :material-check:` |
| 13 | `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 14 | `0001_0000`, `0001_0003`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 15 | `0001_0000`, `0001_0004`, `0001_0004`, `0001_0007` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f007.png :material-check:` |
| 16 | `0001_0000`, `0001_0006` | `build/phase-3/bitmaps/PART19_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART19_f006.png :material-check:` |
| 17 | `0001_0000` | `build/phase-3/bitmaps/PART19_f000.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 51 |
| `END_FRAME` | 18 |
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

**Dynamite** has 2 semantic states: Not Blown up, Blown up. Transitions are triggered by: collision, proximity, timer.

State(s) Blown up are explosive — reaching these destroys the part.

Terminal state(s): Blown up (part is removed from simulation).

This part can be destroyed by explosives.

This part spawns a **projectile** (cannonball, rocket, missile) when triggered. The projectile is a separate part instance.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART19.json` |
| Sprite PNGs | `godot/assets/sprites/PART19_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| Level YAML | `godot/assets/levels/HH33.yaml` |
| ... | +23 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART19.json` + `build/phase-5/yaml/`*
