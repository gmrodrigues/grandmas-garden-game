# Part 37 — Hedge Trimmers

## Identity

| Field | Value |
|-------|-------|
| Part Type | `37` |
| Category | Cutting / Popping |
| Description | You can cut ropes with these hedge trimmers by bumping the handles with another object. Balloons and blimps pop against the tips. |
| ANM File | `PART37.ANM` → `build/phase-4/anm/PART37.json` |
| BMP Resource | `PART37.BMP` → `build/phase-3/bitmaps/PART37_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**51 level(s)** use this part type:

- `build/phase-5/yaml/ELEV14.yaml` → `godot/assets/levels/ELEV14.yaml`
- `build/phase-5/yaml/ELEV26.yaml` → `godot/assets/levels/ELEV26.yaml`
- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH23.yaml` → `godot/assets/levels/HH23.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HH7.yaml` → `godot/assets/levels/HH7.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- ... and 21 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 128 | Q8.8 = 0.500 |
| `unk_6` | 16 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 55 | bitmap frame width |
| `bitmap_h` | 36 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 3 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Open | `7→11` | 7 | No |
| Closed | `3→-1` | 4 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 10 |
| Total States | 6 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `7` | 0 | 0 | 61×36 | 0 |
| `8` | 1 | 1–3 (3 frames) | 61×36 | 13 |
| `11` | 4 | 4 | 32×8 | 70 |
| `3` | 5 | 5 | 65×36 | 77 |
| `4` | 6 | 6 | 64×17 | 122 |
| `9` | 7 | 7–9 (3 frames) | 70×17 | 129 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART37_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART37_f001.png :material-check:` |
| 1 | `0001_0000`, `0001_0001`, `0002_0000` | `build/phase-3/bitmaps/PART37_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART37_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART37_2_f000.png :material-alert-outline: (not found)` |
| 2 | `0001_0000`, `0001_0001`, `0002_0001` | `build/phase-3/bitmaps/PART37_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART37_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART37_2_f001.png :material-alert-outline: (not found)` |
| 3 | `0001_0000`, `0001_0001`, `0002_0002` | `build/phase-3/bitmaps/PART37_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART37_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART37_2_f002.png :material-alert-outline: (not found)` |
| 4 | `0001_0001` | `build/phase-3/bitmaps/PART37_f001.png :material-check:` |
| 5 | `0001_0002` | `build/phase-3/bitmaps/PART37_f002.png :material-check:` |
| 6 | `0001_0002` | `build/phase-3/bitmaps/PART37_f002.png :material-check:` |
| 7 | `0001_0002`, `0002_0000` | `build/phase-3/bitmaps/PART37_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART37_2_f000.png :material-alert-outline: (not found)` |
| 8 | `0001_0002`, `0002_0001` | `build/phase-3/bitmaps/PART37_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART37_2_f001.png :material-alert-outline: (not found)` |
| 9 | `0001_0002`, `0002_0002` | `build/phase-3/bitmaps/PART37_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART37_2_f002.png :material-alert-outline: (not found)` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 5 | `3037` | 0 | `build/phase-6/raw-wav/SX_3037_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 20 |
| `END_FRAME` | 10 |
| `DRAW_LINE` | 6 |
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
| Projectile | No |

## Behavior Notes

**Hedge Trimmers** has 2 semantic states: Open, Closed. Transitions are triggered by: collision.

Terminal state(s): Closed (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART37.json` |
| Sprite PNGs | `godot/assets/sprites/PART37_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV14.yaml` |
| Level YAML | `godot/assets/levels/ELEV26.yaml` |
| Level YAML | `godot/assets/levels/ELEV9.yaml` |
| Level YAML | `godot/assets/levels/HH18.yaml` |
| Level YAML | `godot/assets/levels/HH19.yaml` |
| ... | +46 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART37.json` + `build/phase-5/yaml/`*
