# Part 85 — Log Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `85` |
| Category | Walls / Floors |
| Description | This is a log wall or floor. Stretch it vertically or horizontally to any length you need. Its surface isn't very slippery. Explosions will blow holes through it. |
| ANM File | `PART85.ANM` → `build/phase-4/anm/PART85.json` |
| BMP Resource | `PART85.BMP` → `build/phase-3/bitmaps/PART85_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**18 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV18.yaml` → `godot/assets/levels/ELEV18.yaml`
- `build/phase-5/yaml/ELEV20.yaml` → `godot/assets/levels/ELEV20.yaml`
- `build/phase-5/yaml/HH27.yaml` → `godot/assets/levels/HH27.yaml`
- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH45.yaml` → `godot/assets/levels/HH45.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/HLEV9.yaml` → `godot/assets/levels/HLEV9.yaml`
- `build/phase-5/yaml/MLEV1.yaml` → `godot/assets/levels/MLEV1.yaml`
- `build/phase-5/yaml/MLEV3.yaml` → `godot/assets/levels/MLEV3.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV22.yaml` → `godot/assets/levels/RLEV22.yaml`
- `build/phase-5/yaml/RLEV9.yaml` → `godot/assets/levels/RLEV9.yaml`
- `build/phase-5/yaml/TLEV2.yaml` → `godot/assets/levels/TLEV2.yaml`
- `build/phase-5/yaml/TLEV35.yaml` → `godot/assets/levels/TLEV35.yaml`
- `build/phase-5/yaml/TLEV6.yaml` → `godot/assets/levels/TLEV6.yaml`
- `build/phase-5/yaml/TLEV9.yaml` → `godot/assets/levels/TLEV9.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4153 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 96 | friction = 0.375 |
| `unk_6` | 96 | category-specific property |
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
| Total Frames | 35 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–12 (13 frames) | 16×16 | 0 |
| `2` | 13 | 13–22 (10 frames) | 16×16 | 91 |
| `3` | 23 | 23–34 (12 frames) | 24×27 | 161 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART85_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART85_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART85_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART85_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART85_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART85_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART85_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART85_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART85_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART85_f009.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART85_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART85_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART85_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART85_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART85_f014.png :material-check:` |
| 15 | `0001_0015` | `build/phase-3/bitmaps/PART85_f015.png :material-check:` |
| 16 | `0001_0016` | `build/phase-3/bitmaps/PART85_f016.png :material-check:` |
| 17 | `0001_0017` | `build/phase-3/bitmaps/PART85_f017.png :material-check:` |
| 18 | `0001_0018` | `build/phase-3/bitmaps/PART85_f018.png :material-check:` |
| 19 | `0001_0019` | `build/phase-3/bitmaps/PART85_f019.png :material-check:` |
| 20 | `0001_0020` | `build/phase-3/bitmaps/PART85_f020.png :material-check:` |
| 21 | `0001_0021` | `build/phase-3/bitmaps/PART85_f021.png :material-check:` |
| 22 | `0001_0022` | `build/phase-3/bitmaps/PART85_f022.png :material-check:` |
| 23 | `0001_0023` | `build/phase-3/bitmaps/PART85_f023.png :material-check:` |
| 24 | `0001_0024` | `build/phase-3/bitmaps/PART85_f024.png :material-check:` |
| 25 | `0001_0025` | `build/phase-3/bitmaps/PART85_f025.png :material-check:` |
| 26 | `0001_0026` | `build/phase-3/bitmaps/PART85_f026.png :material-check:` |
| 27 | `0001_0027` | `build/phase-3/bitmaps/PART85_f027.png :material-check:` |
| 28 | `0001_0028` | `build/phase-3/bitmaps/PART85_f028.png :material-check:` |
| 29 | `0001_0029` | `build/phase-3/bitmaps/PART85_f029.png :material-check:` |
| 30 | `0001_0030` | `build/phase-3/bitmaps/PART85_f030.png :material-check:` |
| 31 | `0001_0031` | `build/phase-3/bitmaps/PART85_f031.png :material-check:` |
| 32 | `0001_0032` | `build/phase-3/bitmaps/PART85_f032.png :material-check:` |
| 33 | `0001_0033` | `build/phase-3/bitmaps/PART85_f033.png :material-check:` |
| 34 | `0001_0034` | `build/phase-3/bitmaps/PART85_f034.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 35 |
| `END_FRAME` | 35 |
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

**Log Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART85.json` |
| Sprite PNGs | `godot/assets/sprites/PART85_f*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV18.yaml` |
| Level YAML | `godot/assets/levels/ELEV20.yaml` |
| Level YAML | `godot/assets/levels/HH27.yaml` |
| Level YAML | `godot/assets/levels/HH37.yaml` |
| ... | +13 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART85.json` + `build/phase-5/yaml/`*
