# Part 61 — Alligator

## Identity

| Field | Value |
|-------|-------|
| Part Type | `61` |
| Category | Characters |
| Description | Meet Edison Alligator. He'll chow down Mel Schlemming or Newton Mouse if they get too close. He also flips things into the air with his snout. |
| ANM File | `PART61.ANM` → `build/phase-4/anm/PART61.json` |
| BMP Resource | `PART61.BMP` → `build/phase-3/bitmaps/PART61_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**14 level(s)** use this part type:

- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH5.yaml` → `godot/assets/levels/HH5.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV12.yaml` → `godot/assets/levels/RLEV12.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/TLEV39.yaml` → `godot/assets/levels/TLEV39.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2400 | mass/density (relative scale) |
| `unk_2` | 40 | category-specific property |
| `property_q8` | 192 | Q8.8 = 0.750 |
| `unk_6` | 48 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 94 | bitmap frame width |
| `bitmap_h` | 16 | bitmap frame height |

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
| Hasn't Eaten | `1→5` | 1 | No |
| Has Eaten | `5→-1` | 5 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 47 |
| Total States | 11 |
| Animated (Section A) | Yes |
| Section A Durations | 86 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 100×16 | 0 |
| `7` | 1 | 1–10 (10 frames) | 95×18 | 19 |
| `8` | 11 | 11–20 (10 frames) | 100×26 | 209 |
| `4` | 21 | 21–23 (3 frames) | 96×16 | 403 |
| `12` | 24 | 24–25 (2 frames) | 96×17 | 460 |
| `5` | 26 | 26–64 (39 frames) | 96×17 | 498 |
| `6` | 65 | 65–66 (2 frames) | 0×0 | 0 |
| `9` | 67 | 67–76 (10 frames) | 0×0 | 0 |
| `10` | 77 | 77–81 (5 frames) | 0×0 | 0 |
| `11` | 82 | 82–83 (2 frames) | 0×0 | 0 |
| `13` | 84 | 84 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001`, `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 1 | `0001_0001`, `0001_0008`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 2 | `0001_0001`, `0001_0009`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 3 | `0001_0001`, `0001_0010`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 4 | `0001_0001`, `0001_0012`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 5 | `0001_0001`, `0001_0013`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 6 | `0001_0001`, `0001_0008`, `0001_0003` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f003.png :material-check:` |
| 7 | `0001_0001`, `0001_0009`, `0001_0004` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f004.png :material-check:` |
| 8 | `0001_0001`, `0001_0010`, `0001_0005` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f005.png :material-check:` |
| 9 | `0001_0001`, `0001_0012`, `0001_0006` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f006.png :material-check:` |
| 10 | `0001_0001`, `0001_0013`, `0001_0007` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f007.png :material-check:` |
| 11 | `0001_0001`, `0001_0014`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 12 | `0001_0001`, `0001_0014`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 13 | `0001_0001`, `0001_0015`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 14 | `0001_0001`, `0001_0014`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 15 | `0001_0001`, `0001_0015`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 16 | `0001_0001`, `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 17 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 18 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 19 | `0001_0001`, `0001_0017`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 20 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 21 | `0001_0001`, `0001_0017`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 22 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 23 | `0001_0001`, `0001_0017`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 24 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 25 | `0001_0001`, `0001_0017`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 26 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 27 | `0001_0001`, `0001_0017`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 28 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 29 | `0001_0001`, `0001_0017`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 30 | `0001_0001`, `0001_0016`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f016.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 31 | `0001_0001`, `0001_0017`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f017.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 32 | `0001_0001`, `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 33 | `0001_0001`, `0001_0008`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 34 | `0001_0001`, `0001_0009`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 35 | `0001_0001`, `0001_0010`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 36 | `0001_0001`, `0001_0012`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 37 | `0001_0001`, `0001_0013`, `0001_0000` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f000.png :material-check:` |
| 38 | `0001_0001`, `0001_0008`, `0001_0003` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f003.png :material-check:` |
| 39 | `0001_0001`, `0001_0009`, `0001_0004` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f004.png :material-check:` |
| 40 | `0001_0001`, `0001_0010`, `0001_0005` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f005.png :material-check:` |
| 41 | `0001_0001`, `0001_0012`, `0001_0006` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f006.png :material-check:` |
| 42 | `0001_0001`, `0001_0013`, `0001_0007` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f013.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f007.png :material-check:` |
| 43 | `0001_0001`, `0001_0014`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 44 | `0001_0001`, `0001_0015`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 45 | `0001_0001`, `0001_0014`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f014.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |
| 46 | `0001_0001`, `0001_0015`, `0001_0002` | `build/phase-3/bitmaps/PART61_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f015.png :material-check:`<br>`build/phase-3/bitmaps/PART61_f002.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 11 | `3061` | 0 | `build/phase-6/raw-wav/SX_3061_11025.wav` |
| 17 | `3261` | 0 | `build/phase-6/raw-wav/SX_3261_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 141 |
| `END_FRAME` | 47 |
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

**Alligator** has 2 semantic states: Hasn't Eaten, Has Eaten. Transitions are triggered by: collision, proximity.

Terminal state(s): Has Eaten (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART61.json` |
| Sprite PNGs | `godot/assets/sprites/PART61_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH37.yaml` |
| Level YAML | `godot/assets/levels/HH43.yaml` |
| ... | +9 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART61.json` + `build/phase-5/yaml/`*
