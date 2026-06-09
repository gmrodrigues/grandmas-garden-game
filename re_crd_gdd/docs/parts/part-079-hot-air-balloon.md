# Part 79 — Hot Air Balloon

## Identity

| Field | Value |
|-------|-------|
| Part Type | `79` |
| Category | Balloons / Airships |
| Description | Light the candle to create hot air, which will makes this balloon rise into the air. Tie a rope to the eye hook on the bottom and use it to lift things, pull triggers, and so on. |
| ANM File | `PART79.ANM` → `build/phase-4/anm/PART79.json` |
| BMP Resource | `PART79.BMP` → `build/phase-3/bitmaps/PART79_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**30 level(s)** use this part type:

- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV8.yaml` → `godot/assets/levels/ELEV8.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH31.yaml` → `godot/assets/levels/HH31.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV21.yaml` → `godot/assets/levels/MLEV21.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`
- `build/phase-5/yaml/RLEV12.yaml` → `godot/assets/levels/RLEV12.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV24.yaml` → `godot/assets/levels/RLEV24.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`
- `build/phase-5/yaml/TLEV15.yaml` → `godot/assets/levels/TLEV15.yaml`
- `build/phase-5/yaml/TLEV25.yaml` → `godot/assets/levels/TLEV25.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 12 | mass/density (relative scale) |
| `unk_2` | 4000 | category-specific property |
| `property_q8` | 64 | Q8.8 = 0.250 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 34 | bitmap frame width |
| `bitmap_h` | 83 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision`, `proximity` |
| Destructible | Yes |
| Spawns | *(none)* |
| Category Part Count | 3 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Lit | `1→5` | 1 | No |
| Lit | `5→4` | 5 | No |
| Popped | `4→-1` | 2 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 12 |
| Total States | 5 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 40×83 | 0 |
| `5` | 1 | 1–5 (5 frames) | 40×83 | 13 |
| `4` | 6 | 6–7 (2 frames) | 40×83 | 108 |
| `2` | 8 | 8–9 (2 frames) | 80×118 | 136 |
| `3` | 10 | 10–11 (2 frames) | 17×65 | 168 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f000.png :material-check:` |
| 1 | `0001_0001`, `0002_0006`, `0001_0000` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f000.png :material-check:` |
| 2 | `0001_0001`, `0002_0007`, `0001_0000` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f000.png :material-check:` |
| 3 | `0001_0001`, `0002_0008`, `0001_0000` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f000.png :material-check:` |
| 4 | `0001_0001`, `0002_0009`, `0001_0000` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f000.png :material-check:` |
| 5 | `0001_0001`, `0002_0005`, `0001_0000` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f000.png :material-check:` |
| 6 | `0001_0001`, `0001_0000` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f000.png :material-check:` |
| 7 | `0001_0001`, `0001_0003` | `build/phase-3/bitmaps/PART79_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f003.png :material-check:` |
| 8 | `0001_0004`, `0001_0002` | `build/phase-3/bitmaps/PART79_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f002.png :material-check:` |
| 9 | `0001_0005`, `0001_0006`, `0001_0002` | `build/phase-3/bitmaps/PART79_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f002.png :material-check:` |
| 10 | `0001_0007`, `0001_0002` | `build/phase-3/bitmaps/PART79_f007.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f002.png :material-check:` |
| 11 | `0001_0006`, `0001_0002` | `build/phase-3/bitmaps/PART79_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART79_f002.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 7 | `3004` | 0 | `build/phase-6/raw-wav/SX_3004_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 30 |
| `END_FRAME` | 12 |
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

**Hot Air Balloon** has 3 semantic states: Not Lit, Lit, Popped. Transitions are triggered by: collision, proximity.

Terminal state(s): Popped (part is removed from simulation).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART79.json` |
| Sprite PNGs | `godot/assets/sprites/PART79_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV8.yaml` |
| Level YAML | `godot/assets/levels/HH16.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| ... | +25 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART79.json` + `build/phase-5/yaml/`*
