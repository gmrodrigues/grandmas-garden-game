# Part 42 — Newton Mouse

## Identity

| Field | Value |
|-------|-------|
| Part Type | `42` |
| Category | Characters |
| Description | This is Newton Mouse. He'll go after any cheese he can see. He'll also run away if Curie Cat comes after him. He'll run inside a mouse hole if you place a hunk of cheese on the other side of it, or if Curie chases him toward one. Newton also has to watch out for alligators. |
| ANM File | `PART42.ANM` → `build/phase-4/anm/PART42.json` |
| BMP Resource | `PART42.BMP` → `build/phase-3/bitmaps/PART42_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**37 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV14.yaml` → `godot/assets/levels/ELEV14.yaml`
- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV22.yaml` → `godot/assets/levels/ELEV22.yaml`
- `build/phase-5/yaml/HH15.yaml` → `godot/assets/levels/HH15.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV3.yaml` → `godot/assets/levels/HLEV3.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/HLEV9.yaml` → `godot/assets/levels/HLEV9.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV6.yaml` → `godot/assets/levels/MLEV6.yaml`
- `build/phase-5/yaml/RLEV15.yaml` → `godot/assets/levels/RLEV15.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV19.yaml` → `godot/assets/levels/RLEV19.yaml`
- ... and 7 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2000 | mass/density (relative scale) |
| `unk_2` | 1 | category-specific property |
| `property_q8` | 0 | Q8.8 = 0.000 |
| `unk_6` | 256 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 20 | bitmap frame width |
| `bitmap_h` | 20 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 8 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Hasn't Eaten | `1→10` | 1 | No |
| Has Eaten | `10→-1` | 10 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 54 |
| Total States | 9 |
| Animated (Section A) | Yes |
| Section A Durations | 80 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 24×20 | 0 |
| `9` | 1 | 1–22 (22 frames) | 32×26 | 7 |
| `7` | 23 | 23–26 (4 frames) | 32×24 | 163 |
| `8` | 27 | 27–29 (3 frames) | 32×24 | 191 |
| `10` | 30 | 30–49 (20 frames) | 32×23 | 214 |
| `11` | 50 | 50 | 48×14 | 354 |
| `14` | 51 | 51–72 (22 frames) | 32×13 | 361 |
| `12` | 73 | 73–76 (4 frames) | 0×0 | 0 |
| `13` | 77 | 77 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART42_f000.png :material-check:` |
| 1 | `0001_0007` | `build/phase-3/bitmaps/PART42_f007.png :material-check:` |
| 2 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 3 | `0001_0009` | `build/phase-3/bitmaps/PART42_f009.png :material-check:` |
| 4 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 5 | `0001_0009` | `build/phase-3/bitmaps/PART42_f009.png :material-check:` |
| 6 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 7 | `0001_0009` | `build/phase-3/bitmaps/PART42_f009.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 9 | `0001_0007` | `build/phase-3/bitmaps/PART42_f007.png :material-check:` |
| 10 | `0001_0001` | `build/phase-3/bitmaps/PART42_f001.png :material-check:` |
| 11 | `0001_0002` | `build/phase-3/bitmaps/PART42_f002.png :material-check:` |
| 12 | `0001_0003` | `build/phase-3/bitmaps/PART42_f003.png :material-check:` |
| 13 | `0001_0005` | `build/phase-3/bitmaps/PART42_f005.png :material-check:` |
| 14 | `0001_0002` | `build/phase-3/bitmaps/PART42_f002.png :material-check:` |
| 15 | `0001_0003` | `build/phase-3/bitmaps/PART42_f003.png :material-check:` |
| 16 | `0001_0005` | `build/phase-3/bitmaps/PART42_f005.png :material-check:` |
| 17 | `0001_0010` | `build/phase-3/bitmaps/PART42_f010.png :material-check:` |
| 18 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 19 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 20 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 21 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 22 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 23 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 24 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 25 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 26 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 27 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 28 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 29 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 30 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 31 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 32 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 33 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 34 | `0001_0011` | `build/phase-3/bitmaps/PART42_f011.png :material-check:` |
| 35 | `0001_0012` | `build/phase-3/bitmaps/PART42_f012.png :material-check:` |
| 36 | `0001_0010` | `build/phase-3/bitmaps/PART42_f010.png :material-check:` |
| 37 | `0001_0000` | `build/phase-3/bitmaps/PART42_f000.png :material-check:` |
| 38 | `0001_0007` | `build/phase-3/bitmaps/PART42_f007.png :material-check:` |
| 39 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 40 | `0001_0009` | `build/phase-3/bitmaps/PART42_f009.png :material-check:` |
| 41 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 42 | `0001_0009` | `build/phase-3/bitmaps/PART42_f009.png :material-check:` |
| 43 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 44 | `0001_0009` | `build/phase-3/bitmaps/PART42_f009.png :material-check:` |
| 45 | `0001_0008` | `build/phase-3/bitmaps/PART42_f008.png :material-check:` |
| 46 | `0001_0007` | `build/phase-3/bitmaps/PART42_f007.png :material-check:` |
| 47 | `0001_0001` | `build/phase-3/bitmaps/PART42_f001.png :material-check:` |
| 48 | `0001_0002` | `build/phase-3/bitmaps/PART42_f002.png :material-check:` |
| 49 | `0001_0003` | `build/phase-3/bitmaps/PART42_f003.png :material-check:` |
| 50 | `0001_0005` | `build/phase-3/bitmaps/PART42_f005.png :material-check:` |
| 51 | `0001_0002` | `build/phase-3/bitmaps/PART42_f002.png :material-check:` |
| 52 | `0001_0003` | `build/phase-3/bitmaps/PART42_f003.png :material-check:` |
| 53 | `0001_0005` | `build/phase-3/bitmaps/PART42_f005.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 17 | `3042` | 0 | `build/phase-6/raw-wav/SX_3042_11025.wav` |
| 27 | `3042` | 0 | `build/phase-6/raw-wav/SX_3042_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 54 |
| `END_FRAME` | 54 |
| `PLAY_SFX` | 2 |
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

**Newton Mouse** has 2 semantic states: Hasn't Eaten, Has Eaten. Transitions are triggered by: collision, proximity.

Terminal state(s): Has Eaten (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART42.json` |
| Sprite PNGs | `godot/assets/sprites/PART42_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV14.yaml` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| ... | +32 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART42.json` + `build/phase-5/yaml/`*
