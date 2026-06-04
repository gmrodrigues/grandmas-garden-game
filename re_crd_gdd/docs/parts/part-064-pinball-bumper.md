# Part 64 — Pinball Bumper

## Identity

| Field | Value |
|-------|-------|
| Part Type | `64` |
| Category | Special Mechanics |
| Description | This pinball bumper can be placed so that moving objects will bounce off in any direction. |
| ANM File | `PART64.ANM` → `build/phase-4/anm/PART64.json` |
| BMP Resource | `PART64.BMP` → `build/phase-3/bitmaps/PART64_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**20 level(s)** use this part type:

- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/ELEV8.yaml` → `godot/assets/levels/ELEV8.yaml`
- `build/phase-5/yaml/HH12.yaml` → `godot/assets/levels/HH12.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH47.yaml` → `godot/assets/levels/HH47.yaml`
- `build/phase-5/yaml/HH5.yaml` → `godot/assets/levels/HH5.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV3.yaml` → `godot/assets/levels/HLEV3.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- `build/phase-5/yaml/RLEV8.yaml` → `godot/assets/levels/RLEV8.yaml`
- `build/phase-5/yaml/TLEV17.yaml` → `godot/assets/levels/TLEV17.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2400 | mass/density (relative scale) |
| `unk_2` | 40 | category-specific property |
| `property_q8` | 256 | Q8.8 = 1.000 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 41 | bitmap frame width |
| `bitmap_h` | 41 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `electrical`, `proximity` |
| Destructible | No |
| Spawns | `custom` |
| Category Part Count | 15 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 3 |
| Total States | 2 |
| Animated (Section A) | Yes |
| Section A Durations | 5 entries |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `4` | 0 | 0 | 48×41 | 0 |
| `3` | 1 | 1–2 (2 frames) | 48×41 | 7 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001` | `build/phase-3/bitmaps/PART64_f001.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART64_f000.png :material-check:` |
| 2 | `0001_0000` | `build/phase-3/bitmaps/PART64_f000.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `3064` | 0 | `build/phase-6/raw-wav/SX_3064_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 3 |
| `END_FRAME` | 3 |
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

**Pinball Bumper** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part has custom spawn behavior defined in SOLVE.RES.

This part has timed frame-by-frame animation (Section A durations control playback speed at 60 Hz).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART64.json` |
| Sprite PNGs | `godot/assets/sprites/PART64_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/ELEV8.yaml` |
| Level YAML | `godot/assets/levels/HH12.yaml` |
| Level YAML | `godot/assets/levels/HH2.yaml` |
| ... | +15 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART64.json` + `build/phase-5/yaml/`*
