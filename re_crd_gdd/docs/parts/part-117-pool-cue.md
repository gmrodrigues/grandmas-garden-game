# Part 117 — Pool Cue

## Identity

| Field | Value |
|-------|-------|
| Part Type | `117` |
| Category | Springs / Pneumatics |
| Description | This pool cue is spring- loaded and ready to shoot anytime something bumps the button on the back end. It can be rotated to shoot from eight different angles. Use it to hit pool balls and other things. |
| ANM File | `PART117.ANM` → `build/phase-4/anm/PART117.json` |
| BMP Resource | `PART117.BMP` → `build/phase-3/bitmaps/PART117_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**29 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/HH12.yaml` → `godot/assets/levels/HH12.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH24.yaml` → `godot/assets/levels/HH24.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV24.yaml` → `godot/assets/levels/HLEV24.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/HLEV7.yaml` → `godot/assets/levels/HLEV7.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV16.yaml` → `godot/assets/levels/MLEV16.yaml`
- `build/phase-5/yaml/MLEV19.yaml` → `godot/assets/levels/MLEV19.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/RLEV10.yaml` → `godot/assets/levels/RLEV10.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV25.yaml` → `godot/assets/levels/RLEV25.yaml`
- `build/phase-5/yaml/RLEV6.yaml` → `godot/assets/levels/RLEV6.yaml`
- `build/phase-5/yaml/TLEV24.yaml` → `godot/assets/levels/TLEV24.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1500 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 28 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 78 | bitmap frame width |
| `bitmap_h` | 78 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 7 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Hit | `3→4`, `12→13`, `15→17`, `19→20`, `22→23`, `25→26`, `28→29`, `31→32` | 31 | No |
| Hit | `4→12`, `13→15`, `17→19`, `20→22`, `23→25`, `26→28`, `29→31`, `32→-1` | 33 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 56 |
| Total States | 24 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `3` | 0 | 0 | 48×9 | 0 |
| `4` | 1 | 1–5 (5 frames) | 32×9 | 7 |
| `9` | 6 | 6 | 48×9 | 44 |
| `12` | 7 | 7 | 40×33 | 51 |
| `13` | 8 | 8–12 (5 frames) | 32×26 | 58 |
| `14` | 13 | 13 | 40×33 | 95 |
| `15` | 14 | 14 | 16×43 | 102 |
| `17` | 15 | 15–19 (5 frames) | 16×32 | 109 |
| `18` | 20 | 20 | 16×43 | 146 |
| `19` | 21 | 21 | 40×33 | 153 |
| `20` | 22 | 22–26 (5 frames) | 32×26 | 160 |
| `21` | 27 | 27 | 40×33 | 197 |
| `22` | 28 | 28 | 48×9 | 204 |
| `23` | 29 | 29–33 (5 frames) | 32×9 | 211 |
| `24` | 34 | 34 | 48×9 | 248 |
| `25` | 35 | 35 | 40×33 | 255 |
| `26` | 36 | 36–40 (5 frames) | 32×26 | 262 |
| `27` | 41 | 41 | 40×33 | 299 |
| `28` | 42 | 42 | 16×43 | 306 |
| `29` | 43 | 43–47 (5 frames) | 16×32 | 313 |
| `30` | 48 | 48 | 16×43 | 350 |
| `31` | 49 | 49 | 40×33 | 357 |
| `32` | 50 | 50–54 (5 frames) | 32×26 | 364 |
| `33` | 55 | 55 | 40×33 | 401 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART117_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART117_f001.png :material-check:` |
| 2 | `0001_0001` | `build/phase-3/bitmaps/PART117_f001.png :material-check:` |
| 3 | `0001_0002` | `build/phase-3/bitmaps/PART117_f002.png :material-check:` |
| 4 | `0001_0003` | `build/phase-3/bitmaps/PART117_f003.png :material-check:` |
| 5 | `0001_0004` | `build/phase-3/bitmaps/PART117_f004.png :material-check:` |
| 6 | `0001_0000` | `build/phase-3/bitmaps/PART117_f000.png :material-check:` |
| 7 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |
| 8 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 9 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 10 | `0001_0012` | `build/phase-3/bitmaps/PART117_f012.png :material-check:` |
| 11 | `0001_0013` | `build/phase-3/bitmaps/PART117_f013.png :material-check:` |
| 12 | `0001_0014` | `build/phase-3/bitmaps/PART117_f014.png :material-check:` |
| 13 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |
| 14 | `0001_0005` | `build/phase-3/bitmaps/PART117_f005.png :material-check:` |
| 15 | `0001_0006` | `build/phase-3/bitmaps/PART117_f006.png :material-check:` |
| 16 | `0001_0006` | `build/phase-3/bitmaps/PART117_f006.png :material-check:` |
| 17 | `0001_0007` | `build/phase-3/bitmaps/PART117_f007.png :material-check:` |
| 18 | `0001_0008` | `build/phase-3/bitmaps/PART117_f008.png :material-check:` |
| 19 | `0001_0009` | `build/phase-3/bitmaps/PART117_f009.png :material-check:` |
| 20 | `0001_0005` | `build/phase-3/bitmaps/PART117_f005.png :material-check:` |
| 21 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |
| 22 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 23 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 24 | `0001_0012` | `build/phase-3/bitmaps/PART117_f012.png :material-check:` |
| 25 | `0001_0013` | `build/phase-3/bitmaps/PART117_f013.png :material-check:` |
| 26 | `0001_0014` | `build/phase-3/bitmaps/PART117_f014.png :material-check:` |
| 27 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |
| 28 | `0001_0000` | `build/phase-3/bitmaps/PART117_f000.png :material-check:` |
| 29 | `0001_0001` | `build/phase-3/bitmaps/PART117_f001.png :material-check:` |
| 30 | `0001_0001` | `build/phase-3/bitmaps/PART117_f001.png :material-check:` |
| 31 | `0001_0002` | `build/phase-3/bitmaps/PART117_f002.png :material-check:` |
| 32 | `0001_0003` | `build/phase-3/bitmaps/PART117_f003.png :material-check:` |
| 33 | `0001_0004` | `build/phase-3/bitmaps/PART117_f004.png :material-check:` |
| 34 | `0001_0000` | `build/phase-3/bitmaps/PART117_f000.png :material-check:` |
| 35 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |
| 36 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 37 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 38 | `0001_0012` | `build/phase-3/bitmaps/PART117_f012.png :material-check:` |
| 39 | `0001_0013` | `build/phase-3/bitmaps/PART117_f013.png :material-check:` |
| 40 | `0001_0014` | `build/phase-3/bitmaps/PART117_f014.png :material-check:` |
| 41 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |
| 42 | `0001_0005` | `build/phase-3/bitmaps/PART117_f005.png :material-check:` |
| 43 | `0001_0006` | `build/phase-3/bitmaps/PART117_f006.png :material-check:` |
| 44 | `0001_0006` | `build/phase-3/bitmaps/PART117_f006.png :material-check:` |
| 45 | `0001_0007` | `build/phase-3/bitmaps/PART117_f007.png :material-check:` |
| 46 | `0001_0008` | `build/phase-3/bitmaps/PART117_f008.png :material-check:` |
| 47 | `0001_0009` | `build/phase-3/bitmaps/PART117_f009.png :material-check:` |
| 48 | `0001_0005` | `build/phase-3/bitmaps/PART117_f005.png :material-check:` |
| 49 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |
| 50 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 51 | `0001_0011` | `build/phase-3/bitmaps/PART117_f011.png :material-check:` |
| 52 | `0001_0012` | `build/phase-3/bitmaps/PART117_f012.png :material-check:` |
| 53 | `0001_0013` | `build/phase-3/bitmaps/PART117_f013.png :material-check:` |
| 54 | `0001_0014` | `build/phase-3/bitmaps/PART117_f014.png :material-check:` |
| 55 | `0001_0010` | `build/phase-3/bitmaps/PART117_f010.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |
| 8 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |
| 15 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |
| 22 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |
| 29 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |
| 36 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |
| 43 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |
| 50 | `3117` | 0 | `build/phase-6/raw-wav/SX_3117_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 56 |
| `END_FRAME` | 56 |
| `PLAY_SFX` | 8 |
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

**Pool Cue** has 2 semantic states: Not Hit, Hit. Transitions are triggered by: collision, electrical.

Terminal state(s): Hit (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART117.json` |
| Sprite PNGs | `godot/assets/sprites/PART117_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| Level YAML | `godot/assets/levels/HH12.yaml` |
| ... | +24 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART117.json` + `build/phase-5/yaml/`*
