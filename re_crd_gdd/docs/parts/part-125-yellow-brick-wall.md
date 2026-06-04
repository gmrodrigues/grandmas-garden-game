# Part 125 — Yellow Brick Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `125` |
| Category | Walls / Floors |
| Description | This is a yellow brick wall or floor. Stretch it vertically or horizontally to any length you need. Its surface is pretty slippery. Explosions will blow holes through it. |
| ANM File | `PART125.ANM` → `build/phase-4/anm/PART125.json` |
| BMP Resource | `PART125.BMP` → `build/phase-3/bitmaps/PART125_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**32 level(s)** use this part type:

- `build/phase-5/yaml/ELEV17.yaml` → `godot/assets/levels/ELEV17.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH29.yaml` → `godot/assets/levels/HH29.yaml`
- `build/phase-5/yaml/HH33.yaml` → `godot/assets/levels/HH33.yaml`
- `build/phase-5/yaml/HH41.yaml` → `godot/assets/levels/HH41.yaml`
- `build/phase-5/yaml/HH50.yaml` → `godot/assets/levels/HH50.yaml`
- `build/phase-5/yaml/HLEV10.yaml` → `godot/assets/levels/HLEV10.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV21.yaml` → `godot/assets/levels/MLEV21.yaml`
- `build/phase-5/yaml/MLEV28.yaml` → `godot/assets/levels/MLEV28.yaml`
- `build/phase-5/yaml/MLEV3.yaml` → `godot/assets/levels/MLEV3.yaml`
- `build/phase-5/yaml/MLEV7.yaml` → `godot/assets/levels/MLEV7.yaml`
- `build/phase-5/yaml/RLEV14.yaml` → `godot/assets/levels/RLEV14.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV20.yaml` → `godot/assets/levels/RLEV20.yaml`
- `build/phase-5/yaml/RLEV23.yaml` → `godot/assets/levels/RLEV23.yaml`
- `build/phase-5/yaml/RLEV27.yaml` → `godot/assets/levels/RLEV27.yaml`
- `build/phase-5/yaml/RLEV28.yaml` → `godot/assets/levels/RLEV28.yaml`
- `build/phase-5/yaml/RLEV3.yaml` → `godot/assets/levels/RLEV3.yaml`
- `build/phase-5/yaml/RLEV7.yaml` → `godot/assets/levels/RLEV7.yaml`
- `build/phase-5/yaml/TLEV10.yaml` → `godot/assets/levels/TLEV10.yaml`
- `build/phase-5/yaml/TLEV16.yaml` → `godot/assets/levels/TLEV16.yaml`
- `build/phase-5/yaml/TLEV18.yaml` → `godot/assets/levels/TLEV18.yaml`
- `build/phase-5/yaml/TLEV2.yaml` → `godot/assets/levels/TLEV2.yaml`
- `build/phase-5/yaml/TLEV24.yaml` → `godot/assets/levels/TLEV24.yaml`
- ... and 2 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4153 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `friction_q8` | 1024 | friction = 4.000 |
| `unk_6` | 20 | category-specific property |
| `tile_w` | 16 | base width in tile units |
| `tile_h` | 16 | base height in tile units |
| `collision_w` | 576 | AABB collision width |
| `collision_h` | 416 | AABB collision height |
| `bitmap_w` | 16 | bitmap frame width |
| `bitmap_h` | 16 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | Yes |
| Spawns | *(none)* |
| Category Part Count | 15 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 20 |
| Total States | 2 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 4 | 4–7 (4 frames) | 16×16 | 28 |
| `1` | 8 | 8–19 (12 frames) | 40×16 | 56 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART125_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART125_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART125_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART125_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART125_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART125_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART125_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART125_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART125_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART125_f009.png :material-check:` |
| 10 | `0001_0008` | `build/phase-3/bitmaps/PART125_f008.png :material-check:` |
| 11 | `0001_0009` | `build/phase-3/bitmaps/PART125_f009.png :material-check:` |
| 12 | `0001_0008` | `build/phase-3/bitmaps/PART125_f008.png :material-check:` |
| 13 | `0001_0009` | `build/phase-3/bitmaps/PART125_f009.png :material-check:` |
| 14 | `0001_0010` | `build/phase-3/bitmaps/PART125_f010.png :material-check:` |
| 15 | `0001_0010` | `build/phase-3/bitmaps/PART125_f010.png :material-check:` |
| 16 | `0001_0010` | `build/phase-3/bitmaps/PART125_f010.png :material-check:` |
| 17 | `0001_0011` | `build/phase-3/bitmaps/PART125_f011.png :material-check:` |
| 18 | `0001_0011` | `build/phase-3/bitmaps/PART125_f011.png :material-check:` |
| 19 | `0001_0011` | `build/phase-3/bitmaps/PART125_f011.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 20 |
| `END_FRAME` | 20 |
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

**Yellow Brick Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART125.json` |
| Sprite PNGs | `godot/assets/sprites/PART125_f*.png` |
| Level YAML | `godot/assets/levels/ELEV17.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| Level YAML | `godot/assets/levels/HH2.yaml` |
| ... | +27 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART125.json` + `build/phase-5/yaml/`*
