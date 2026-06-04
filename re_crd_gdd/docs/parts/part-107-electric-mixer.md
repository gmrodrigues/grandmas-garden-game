# Part 107 — Electric Mixer

## Identity

| Field | Value |
|-------|-------|
| Part Type | `107` |
| Category | Electrical |
| Description | Plug this electric mixer into an outlet to make it run. |
| ANM File | `PART107.ANM` → `build/phase-4/anm/PART107.json` |
| BMP Resource | `PART107.BMP` → `build/phase-3/bitmaps/PART107_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**10 level(s)** use this part type:

- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/MLEV14.yaml` → `godot/assets/levels/MLEV14.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV21.yaml` → `godot/assets/levels/RLEV21.yaml`
- `build/phase-5/yaml/TLEV19.yaml` → `godot/assets/levels/TLEV19.yaml`
- `build/phase-5/yaml/TLEV27.yaml` → `godot/assets/levels/TLEV27.yaml`
- `build/phase-5/yaml/TLEV29.yaml` → `godot/assets/levels/TLEV29.yaml`
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
| `bitmap_w` | 49 | bitmap frame width |
| `bitmap_h` | 55 | bitmap frame height |

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
| Not Mixing | `2→1` | 2 | No |
| Mixing | `1→-1` | 1 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 5 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0 | 56×55 | 0 |
| `1` | 1 | 1–4 (4 frames) | 56×59 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART107_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART107_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART107_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART107_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART107_f004.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `107` | 0 | `build/phase-6/raw-wav/SX_107_11025.wav` |
| 2 | `107` | 0 | `build/phase-6/raw-wav/SX_107_11025.wav` |
| 3 | `107` | 0 | `build/phase-6/raw-wav/SX_107_11025.wav` |
| 4 | `107` | 0 | `build/phase-6/raw-wav/SX_107_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 5 |
| `END_FRAME` | 5 |
| `PLAY_SFX` | 4 |
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

**Electric Mixer** has 2 semantic states: Not Mixing, Mixing. Transitions are triggered by: electrical, collision.

Terminal state(s): Mixing (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART107.json` |
| Sprite PNGs | `godot/assets/sprites/PART107_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| Level YAML | `godot/assets/levels/HH32.yaml` |
| Level YAML | `godot/assets/levels/MLEV14.yaml` |
| Level YAML | `godot/assets/levels/RLEV16.yaml` |
| ... | +5 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART107.json` + `build/phase-5/yaml/`*
