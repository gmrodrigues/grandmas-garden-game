# Part 62 — Coffee Pot

## Identity

| Field | Value |
|-------|-------|
| Part Type | `62` |
| Category | Special Mechanics |
| Description | Make this coffee pot percolate by heating it with a candle, Aladdin's lamp, match-on-a-spring, or flint & tinder. Then use the steam to push things. |
| ANM File | `PART62.ANM` → `build/phase-4/anm/PART62.json` |
| BMP Resource | `PART62.BMP` → `build/phase-3/bitmaps/PART62_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**17 level(s)** use this part type:

- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/MLEV13.yaml` → `godot/assets/levels/MLEV13.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- `build/phase-5/yaml/RLEV2.yaml` → `godot/assets/levels/RLEV2.yaml`
- `build/phase-5/yaml/RLEV27.yaml` → `godot/assets/levels/RLEV27.yaml`
- `build/phase-5/yaml/TLEV25.yaml` → `godot/assets/levels/TLEV25.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 2400 | mass/density (relative scale) |
| `unk_2` | 40 | category-specific property |
| `property_q8` | 64 | Q8.8 = 0.250 |
| `unk_6` | 64 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 38 | bitmap frame width |
| `bitmap_h` | 41 | bitmap frame height |

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
| Off | `1→3` | 1 | No |
| Percolating | `3→-1` | 4 | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 24 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 40×41 | 0 |
| `3` | 1 | 1–17 (17 frames) | 40×41 | 7 |
| `4` | 18 | 18–23 (6 frames) | 73×69 | 332 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART62_f000.png :material-check:` |
| 1 | `0001_0000` | `build/phase-3/bitmaps/PART62_f000.png :material-check:` |
| 2 | `0001_0000` | `build/phase-3/bitmaps/PART62_f000.png :material-check:` |
| 3 | `0001_0000`, `0001_0001` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f001.png :material-check:` |
| 4 | `0001_0000`, `0001_0003` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f003.png :material-check:` |
| 5 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f002.png :material-check:` |
| 6 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f004.png :material-check:` |
| 7 | `0001_0005`, `0001_0008` | `build/phase-3/bitmaps/PART62_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f008.png :material-check:` |
| 8 | `0001_0005`, `0001_0006` | `build/phase-3/bitmaps/PART62_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f006.png :material-check:` |
| 9 | `0001_0000`, `0001_0002` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f002.png :material-check:` |
| 10 | `0001_0010`, `0001_0014` | `build/phase-3/bitmaps/PART62_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f014.png :material-check:` |
| 11 | `0001_0010`, `0001_0012` | `build/phase-3/bitmaps/PART62_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f012.png :material-check:` |
| 12 | `0001_0005`, `0001_0008` | `build/phase-3/bitmaps/PART62_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f008.png :material-check:` |
| 13 | `0001_0000`, `0001_0004` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f004.png :material-check:` |
| 14 | `0001_0005`, `0001_0007` | `build/phase-3/bitmaps/PART62_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f007.png :material-check:` |
| 15 | `0001_0005`, `0001_0009` | `build/phase-3/bitmaps/PART62_f005.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f009.png :material-check:` |
| 16 | `0001_0010`, `0001_0013` | `build/phase-3/bitmaps/PART62_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f013.png :material-check:` |
| 17 | `0001_0010`, `0001_0011` | `build/phase-3/bitmaps/PART62_f010.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f011.png :material-check:` |
| 18 | `0001_0000`, `0001_0015` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f015.png :material-check:` |
| 19 | `0001_0000`, `0001_0016` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f016.png :material-check:` |
| 20 | `0001_0000`, `0001_0017` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f017.png :material-check:` |
| 21 | `0001_0000`, `0001_0015` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f015.png :material-check:` |
| 22 | `0001_0000`, `0001_0016` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f016.png :material-check:` |
| 23 | `0001_0000`, `0001_0017` | `build/phase-3/bitmaps/PART62_f000.png :material-check:`<br>`build/phase-3/bitmaps/PART62_f017.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 45 |
| `END_FRAME` | 24 |
| `DRAW_LINE` | 23 |
| `DRAW_RECT` | 3 |
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

**Coffee Pot** has 2 semantic states: Off, Percolating. Transitions are triggered by: collision, electrical, proximity.

Terminal state(s): Percolating (part is removed from simulation).

This part has custom spawn behavior defined in SOLVE.RES.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART62.json` |
| Sprite PNGs | `godot/assets/sprites/PART62_f*.png` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/HH16.yaml` |
| Level YAML | `godot/assets/levels/HH17.yaml` |
| Level YAML | `godot/assets/levels/HH18.yaml` |
| ... | +12 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART62.json` + `build/phase-5/yaml/`*
