# Part 83 — Cinder Block Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `83` |
| Category | Walls / Floors |
| Description | This is a cinder block wall or floor. Stretch it vertically or horizontally to any length you need. Its surface isn't very slippery. Explosions will blow holes through it. |
| ANM File | `PART83.ANM` → `build/phase-4/anm/PART83.json` |
| BMP Resource | `PART83.BMP` → `build/phase-3/bitmaps/PART83_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**32 level(s)** use this part type:

- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV6.yaml` → `godot/assets/levels/ELEV6.yaml`
- `build/phase-5/yaml/ELEV7.yaml` → `godot/assets/levels/ELEV7.yaml`
- `build/phase-5/yaml/ELEV8.yaml` → `godot/assets/levels/ELEV8.yaml`
- `build/phase-5/yaml/HH14.yaml` → `godot/assets/levels/HH14.yaml`
- `build/phase-5/yaml/HH16.yaml` → `godot/assets/levels/HH16.yaml`
- `build/phase-5/yaml/HH28.yaml` → `godot/assets/levels/HH28.yaml`
- `build/phase-5/yaml/HH32.yaml` → `godot/assets/levels/HH32.yaml`
- `build/phase-5/yaml/HH35.yaml` → `godot/assets/levels/HH35.yaml`
- `build/phase-5/yaml/HH36.yaml` → `godot/assets/levels/HH36.yaml`
- `build/phase-5/yaml/HH42.yaml` → `godot/assets/levels/HH42.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV16.yaml` → `godot/assets/levels/HLEV16.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV11.yaml` → `godot/assets/levels/MLEV11.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV24.yaml` → `godot/assets/levels/MLEV24.yaml`
- `build/phase-5/yaml/MLEV27.yaml` → `godot/assets/levels/MLEV27.yaml`
- `build/phase-5/yaml/RLEV18.yaml` → `godot/assets/levels/RLEV18.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV5.yaml` → `godot/assets/levels/RLEV5.yaml`
- `build/phase-5/yaml/RLEV6.yaml` → `godot/assets/levels/RLEV6.yaml`
- `build/phase-5/yaml/TLEV10.yaml` → `godot/assets/levels/TLEV10.yaml`
- `build/phase-5/yaml/TLEV12.yaml` → `godot/assets/levels/TLEV12.yaml`
- ... and 2 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4153 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 1024 | friction = 4.000 |
| `unk_6` | 40 | category-specific property |
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
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `4` | 0 | 0–3 (4 frames) | 16×16 | 0 |
| `1` | 4 | 4–7 (4 frames) | 16×16 | 28 |
| `3` | 8 | 8–19 (12 frames) | 16×16 | 56 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART83_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART83_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART83_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART83_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART83_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART83_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART83_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART83_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART83_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART83_f009.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART83_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART83_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART83_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART83_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART83_f014.png :material-check:` |
| 15 | `0001_0015` | `build/phase-3/bitmaps/PART83_f015.png :material-check:` |
| 16 | `0001_0009` | `build/phase-3/bitmaps/PART83_f009.png :material-check:` |
| 17 | `0001_0016` | `build/phase-3/bitmaps/PART83_f016.png :material-check:` |
| 18 | `0001_0017` | `build/phase-3/bitmaps/PART83_f017.png :material-check:` |
| 19 | `0001_0018` | `build/phase-3/bitmaps/PART83_f018.png :material-check:` |

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

**Cinder Block Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART83.json` |
| Sprite PNGs | `godot/assets/sprites/PART83_f*.png` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV6.yaml` |
| Level YAML | `godot/assets/levels/ELEV7.yaml` |
| Level YAML | `godot/assets/levels/ELEV8.yaml` |
| Level YAML | `godot/assets/levels/HH14.yaml` |
| ... | +27 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART83.json` + `build/phase-5/yaml/`*
