# Part 67 — Can Opener

## Identity

| Field | Value |
|-------|-------|
| Part Type | `67` |
| Category | Electrical |
| Description | Plug this can opener into an electrical outlet to make it open the can. When the sauce spills out of the can, Curie Cat will come lap it up if she's within range. |
| ANM File | `PART67.ANM` → `build/phase-4/anm/PART67.json` |
| BMP Resource | `PART67.BMP` → `build/phase-3/bitmaps/PART67_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**11 level(s)** use this part type:

- `build/phase-5/yaml/ELEV16.yaml` → `godot/assets/levels/ELEV16.yaml`
- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/TLEV19.yaml` → `godot/assets/levels/TLEV19.yaml`
- `build/phase-5/yaml/TLEV28.yaml` → `godot/assets/levels/TLEV28.yaml`
- `build/phase-5/yaml/TLEV5.yaml` → `godot/assets/levels/TLEV5.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 37 | bitmap frame width |
| `bitmap_h` | 51 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `electrical`, `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 9 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unopened | `1→3` | 1 | No |
| Opened | `2→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 20 |
| Total States | 3 |
| Animated (Section A) | Yes |
| Section A Durations | 36 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 43×51 | 0 |
| `3` | 1 | 1–24 (24 frames) | 43×49 | 31 |
| `2` | 25 | 25 | 0×0 | 0 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0004`, `0001_0002` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:` |
| 1 | `0001_0001`, `0001_0001`, `0001_0000`, `0001_0005`, `0001_0003` | `build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 2 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0006`, `0001_0003` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 3 | `0001_0001`, `0001_0001`, `0001_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f007.png :material-check:` |
| 4 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f008.png :material-check:` |
| 5 | `0001_0001`, `0001_0001`, `0001_0000`, `0001_0009`, `0001_0003` | `build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 6 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0004`, `0001_0003` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 7 | `0001_0001`, `0001_0001`, `0001_0000`, `0001_0005`, `0001_0003` | `build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 8 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0006`, `0001_0003` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 9 | `0001_0001`, `0001_0001`, `0001_0000`, `0001_0003`, `0001_0007` | `build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f007.png :material-check:` |
| 10 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0003`, `0001_0008` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f008.png :material-check:` |
| 11 | `0001_0001`, `0001_0001`, `0001_0000`, `0001_0009`, `0001_0003` | `build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 12 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0004`, `0001_0003` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f003.png :material-check:` |
| 13 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0002`, `0001_0010` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f010.png :material-check:` |
| 14 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0002`, `0001_0011` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f011.png :material-check:` |
| 15 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0002`, `0001_0012`, `0001_0015` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f015.png :material-check:` |
| 16 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0002`, `0001_0012`, `0001_0015` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f015.png :material-check:` |
| 17 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0002`, `0001_0012`, `0001_0016` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f016.png :material-check:` |
| 18 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0002`, `0001_0012`, `0001_0017` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f017.png :material-check:` |
| 19 | `0001_0000`, `0001_0001`, `0001_0001`, `0001_0002`, `0001_0012`, `0001_0018` | `build/phase-3/bitmaps/PART67_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f012.png :material-check:`<br>`build/phase-3/bitmaps/PART67_f018.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 2 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 3 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 4 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 5 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 6 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 7 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 8 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 9 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 10 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 11 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 12 | `67` | 0 | `build/phase-6/raw-wav/SX_67_11025.wav` |
| 15 | `3067` | 0 | `build/phase-6/raw-wav/SX_3067_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 105 |
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
| Laser | No |
| Projectile | No |

## Behavior Notes

**Can Opener** has 2 semantic states: Unopened, Opened. Transitions are triggered by: electrical, collision.

Terminal state(s): Opened (part is removed from simulation).

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART67.json` |
| Sprite PNGs | `godot/assets/sprites/PART67_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV16.yaml` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| Level YAML | `godot/assets/levels/HLEV11.yaml` |
| Level YAML | `godot/assets/levels/HLEV18.yaml` |
| ... | +6 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART67.json` + `build/phase-5/yaml/`*
