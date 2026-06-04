# Part 66 — Mouse Hole

## Identity

| Field | Value |
|-------|-------|
| Part Type | `66` |
| Category | Special Mechanics |
| Description | Newton Mouse likes to hide in this mouse hole when he's chased by Curie Cat. Or you can lure him inside by placing some cheese on the far side of the hole. |
| ANM File | `PART66.ANM` → `build/phase-4/anm/PART66.json` |
| BMP Resource | `PART66.BMP` → `build/phase-3/bitmaps/PART66_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**6 level(s)** use this part type:

- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV22.yaml` → `godot/assets/levels/ELEV22.yaml`
- `build/phase-5/yaml/HH15.yaml` → `godot/assets/levels/HH15.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/RLEV8.yaml` → `godot/assets/levels/RLEV8.yaml`
- `build/phase-5/yaml/TLEV36.yaml` → `godot/assets/levels/TLEV36.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 0 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 19 | bitmap frame width |
| `bitmap_h` | 21 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical`, `proximity` |
| Destructible | No |
| Spawns | `custom` |
| Category Part Count | 15 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Vacant | `1→3` | 1 | No |
| Occupied | `3→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 7 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 24×21 | 0 |
| `3` | 1 | 1–5 (5 frames) | 24×21 | 7 |
| `2` | 6 | 6 | 24×21 | 74 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0004` | `build/phase-3/bitmaps/PART66_f004.png :material-check:` |
| 1 | `0001_0004`, `0001_0000` | `build/phase-3/bitmaps/PART66_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART66_f000.png :material-check:` |
| 2 | `0001_0004`, `0001_0000` | `build/phase-3/bitmaps/PART66_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART66_f000.png :material-check:` |
| 3 | `0001_0004`, `0001_0001` | `build/phase-3/bitmaps/PART66_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART66_f001.png :material-check:` |
| 4 | `0001_0004`, `0001_0002` | `build/phase-3/bitmaps/PART66_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART66_f002.png :material-check:` |
| 5 | `0001_0004`, `0001_0003` | `build/phase-3/bitmaps/PART66_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART66_f003.png :material-check:` |
| 6 | `0001_0004`, `0001_0003` | `build/phase-3/bitmaps/PART66_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART66_f003.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3066` | 0 | `build/phase-6/raw-wav/SX_3066_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 13 |
| `END_FRAME` | 7 |
| `PLAY_SFX` | 1 |
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

**Mouse Hole** has 2 semantic states: Vacant, Occupied. Transitions are triggered by: collision, electrical, proximity.

Terminal state(s): Occupied (part is removed from simulation).

This part has custom spawn behavior defined in SOLVE.RES.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART66.json` |
| Sprite PNGs | `godot/assets/sprites/PART66_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV22.yaml` |
| Level YAML | `godot/assets/levels/HH15.yaml` |
| Level YAML | `godot/assets/levels/HH18.yaml` |
| Level YAML | `godot/assets/levels/RLEV8.yaml` |
| ... | +1 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART66.json` + `build/phase-5/yaml/`*
