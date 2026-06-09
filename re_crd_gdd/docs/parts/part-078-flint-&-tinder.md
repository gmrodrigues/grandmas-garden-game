# Part 78 — Flint & Tinder

## Identity

| Field | Value |
|-------|-------|
| Part Type | `78` |
| Category | Light / Flame Sources |
| Description | Bump these flint rocks to start a fire, which can be used to light fuses, pop blimps and balloons, and heat up coffee pots. |
| ANM File | `PART78.ANM` → `build/phase-4/anm/PART78.json` |
| BMP Resource | `PART78.BMP` → `build/phase-3/bitmaps/PART78_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**44 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV19.yaml` → `godot/assets/levels/ELEV19.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH13.yaml` → `godot/assets/levels/HH13.yaml`
- `build/phase-5/yaml/HH15.yaml` → `godot/assets/levels/HH15.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH38.yaml` → `godot/assets/levels/HH38.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH48.yaml` → `godot/assets/levels/HH48.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV11.yaml` → `godot/assets/levels/HLEV11.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- ... and 14 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4000 | mass/density (relative scale) |
| `unk_2` | 140 | category-specific property |
| `property_q8` | 96 | Q8.8 = 0.375 |
| `unk_6` | 18 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 46 | bitmap frame width |
| `bitmap_h` | 34 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `proximity`, `electrical` |
| Destructible | No |
| Spawns | `fire` |
| Category Part Count | 5 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unlit | `1→2` | 1 | No |
| Lit | `2→-1` | 7 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 32 |
| Total States | 4 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 48×34 | 0 |
| `2` | 1 | 1–11 (11 frames) | 48×34 | 19 |
| `5` | 12 | 12–26 (15 frames) | 48×41 | 350 |
| `7` | 27 | 27–31 (5 frames) | 48×36 | 749 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 1 | `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 2 | `0001_0000`, `0001_0000`, `0003_0004`, `0003_0000`, `0003_0001` | `build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f001.png :material-check:` |
| 3 | `0001_0000`, `0001_0000`, `0003_0004`, `0003_0000`, `0003_0001` | `build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f001.png :material-check:` |
| 4 | `0001_0001`, `0001_0001`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f001.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 5 | `0001_0002`, `0001_0002`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f002.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 6 | `0001_0003`, `0001_0003`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f003.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f003.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 7 | `0001_0004`, `0001_0004`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f004.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 8 | `0001_0005`, `0001_0005`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f005.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 9 | `0001_0006`, `0001_0006`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f006.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f006.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 10 | `0001_0000`, `0001_0000`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 11 | `0001_0001`, `0001_0001`, `0003_0004`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/SPARKS_f001.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f001.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 12 | `0003_0004`, `0001_0000`, `0001_0000`, `0002_0005`, `0003_0002`, `0003_0003` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:` |
| 13 | `0001_0000`, `0001_0000`, `0003_0004`, `0003_0002`, `0003_0003`, `0002_0006` | `build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/SPARKS_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:` |
| 14 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0007` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:` |
| 15 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0008` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:` |
| 16 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0009` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:` |
| 17 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0005` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f005.png :material-check:` |
| 18 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0006` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:` |
| 19 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0007` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:` |
| 20 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0008` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:` |
| 21 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0009` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:` |
| 22 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0005` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f005.png :material-check:` |
| 23 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0006` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f006.png :material-check:` |
| 24 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0007` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f007.png :material-check:` |
| 25 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0008` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f008.png :material-check:` |
| 26 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0009` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f009.png :material-check:` |
| 27 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0000` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f000.png :material-check:` |
| 28 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0001` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f001.png :material-check:` |
| 29 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0002` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f002.png :material-check:` |
| 30 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0003` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f003.png :material-check:` |
| 31 | `0003_0004`, `0003_0002`, `0003_0003`, `0002_0004` | `build/phase-3/bitmaps/PART78_f004.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f002.png :material-check:`<br>`build/phase-3/bitmaps/PART78_f003.png :material-check:`<br>`build/phase-3/bitmaps/FLAMES_f004.png :material-check:` |

### Sound Effects

| Frame | Sound ID | Bytecode Offset | WAV Reference |
|-------|----------|-----------------|---------------|
| 2 | `3078` | 0 | `build/phase-6/raw-wav/SX_3078_11025.wav` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 140 |
| `END_FRAME` | 32 |
| `PLAY_SFX` | 1 |
| `END_ANM` | 1 |

## Connections & Capabilities

| Capability | Supported |
|------------|-----------|
| Electrical | Yes |
| Belt Connection | No |
| Rope Connection | No |
| Fire/Flame | Yes |
| Laser | No |
| Projectile | No |

## Behavior Notes

**Flint & Tinder** has 2 semantic states: Unlit, Lit. Transitions are triggered by: proximity, electrical.

Terminal state(s): Lit (part is removed from simulation).

This part can ignite nearby combustible parts (balloons, explosives). Uses proximity trigger.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART78.json` |
| Sprite PNGs | `godot/assets/sprites/PART78_f*.png` |
| Sound WAVs | `godot/assets/sounds/SX_{id}_11025.wav` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV19.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| Level YAML | `godot/assets/levels/HH13.yaml` |
| ... | +39 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART78.json` + `build/phase-5/yaml/`*
