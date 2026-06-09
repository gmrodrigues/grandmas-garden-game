# Part 109 — Blimp

## Identity

| Field | Value |
|-------|-------|
| Part Type | `109` |
| Category | Balloons / Airships |
| Description | This blimp will fly in a straight line until it bumps into something and reverses direction. It will pop if it bumps into a moving gear, a tack, or certain other sharp objects, and it will blow up if it touches a flame or explosion. |
| ANM File | `PART109.ANM` → `build/phase-4/anm/PART109.json` |
| BMP Resource | `PART109.BMP` → `build/phase-3/bitmaps/PART109_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**47 level(s)** use this part type:

- `build/phase-5/yaml/ELEV12.yaml` → `godot/assets/levels/ELEV12.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/ELEV8.yaml` → `godot/assets/levels/ELEV8.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH23.yaml` → `godot/assets/levels/HH23.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH38.yaml` → `godot/assets/levels/HH38.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HH6.yaml` → `godot/assets/levels/HH6.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV2.yaml` → `godot/assets/levels/HLEV2.yaml`
- ... and 17 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 9 | mass/density (relative scale) |
| `unk_2` | 28000 | category-specific property |
| `property_q8` | 64 | Q8.8 = 0.250 |
| `unk_6` | 32 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 53 | bitmap frame width |
| `bitmap_h` | 36 | bitmap frame height |

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
| Normal | `1→2` | 1 | No |
| Popped | `2→5` | 7 | No |
| Blown Up | `5→-1` | 6 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 24 |
| Total States | 7 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–4 (5 frames) | 56×36 | 0 |
| `3` | 5 | 5–7 (3 frames) | 48×41 | 73 |
| `4` | 8 | 8–10 (3 frames) | 48×41 | 100 |
| `2` | 11 | 11–15 (5 frames) | 56×35 | 127 |
| `7` | 16 | 16 | 32×68 | 170 |
| `5` | 17 | 17–21 (5 frames) | 56×35 | 177 |
| `6` | 22 | 22–23 (2 frames) | 32×68 | 316 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART109_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART109_f001.png :material-check:` |
| 1 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART109_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART109_f002.png :material-check:` |
| 2 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART109_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART109_f003.png :material-check:` |
| 3 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART109_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART109_f004.png :material-check:` |
| 4 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART109_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART109_f005.png :material-check:` |
| 5 | `0001_0006` | `build/phase-3/bitmaps/PART109_f006.png :material-check:` |
| 6 | `0001_0007` | `build/phase-3/bitmaps/PART109_f007.png :material-check:` |
| 7 | `0001_0006` | `build/phase-3/bitmaps/PART109_f006.png :material-check:` |
| 8 | `0001_0006` | `build/phase-3/bitmaps/PART109_f006.png :material-check:` |
| 9 | `0001_0007` | `build/phase-3/bitmaps/PART109_f007.png :material-check:` |
| 10 | `0001_0006` | `build/phase-3/bitmaps/PART109_f006.png :material-check:` |
| 11 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART109_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART109_f005.png :material-check:` |
| 12 | `0001_0008` | `build/phase-3/bitmaps/PART109_f008.png :material-check:` |
| 13 | `0001_0008` | `build/phase-3/bitmaps/PART109_f008.png :material-check:` |
| 14 | `0001_0009` | `build/phase-3/bitmaps/PART109_f009.png :material-check:` |
| 15 | `0001_0010` | `build/phase-3/bitmaps/PART109_f010.png :material-check:` |
| 16 | `0001_0011` | `build/phase-3/bitmaps/PART109_f011.png :material-check:` |
| 17 | `0001_0000`, `0001_0005` | `build/phase-3/bitmaps/PART109_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART109_f005.png :material-check:` |
| 18 | `0001_0008`, `0002_0006`, `0002_0007`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART109_f008.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f000.png :material-check:` |
| 19 | `0001_0008`, `0002_0006`, `0002_0007`, `0002_0009`, `0002_0000` | `build/phase-3/bitmaps/PART109_f008.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f000.png :material-check:` |
| 20 | `0001_0009`, `0002_0007`, `0002_0006`, `0002_0001`, `0002_0008` | `build/phase-3/bitmaps/PART109_f009.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f001.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:` |
| 21 | `0001_0010`, `0002_0002`, `0002_0009`, `0002_0008`, `0002_0007` | `build/phase-3/bitmaps/PART109_f010.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f002.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:` |
| 22 | `0001_0011`, `0002_0003`, `0002_0005`, `0002_0008`, `0002_0009`, `0002_0006` | `build/phase-3/bitmaps/PART109_f011.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f005.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:` |
| 23 | `0001_0011`, `0002_0004`, `0002_0009`, `0002_0006`, `0002_0005` | `build/phase-3/bitmaps/PART109_f011.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f004.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f005.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 1 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 2 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 3 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 4 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 5 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 6 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 7 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 8 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 9 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 10 | `109` | 0 | `build/phase-6/raw-wav/SX_109_11025.wav` |
| 12 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |
| 18 | `3019` | 0 | `build/phase-6/raw-wav/SX_3019_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 56 |
| `END_FRAME` | 24 |
| `PLAY_SFX` | 12 |
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

**Blimp** has 3 semantic states: Normal, Popped, Blown Up. Transitions are triggered by: collision, proximity.

Terminal state(s): Blown Up (part is removed from simulation).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART109.json` |
| Sprite PNGs | `godot/assets/sprites/PART109_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV12.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| Level YAML | `godot/assets/levels/ELEV8.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| ... | +42 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART109.json` + `build/phase-5/yaml/`*
