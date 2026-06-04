# Part 84 — Greco-Roman Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `84` |
| Category | Walls / Floors |
| Description | This is a Greco-Roman wall or floor. Stretch it vertically or horizontally to any length you need. It has a pretty slippery surface. Explosions won't affect it. |
| ANM File | `PART84.ANM` → `build/phase-4/anm/PART84.json` |
| BMP Resource | `PART84.BMP` → `build/phase-3/bitmaps/PART84_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**42 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV12.yaml` → `godot/assets/levels/ELEV12.yaml`
- `build/phase-5/yaml/ELEV15.yaml` → `godot/assets/levels/ELEV15.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/ELEV7.yaml` → `godot/assets/levels/ELEV7.yaml`
- `build/phase-5/yaml/HH10.yaml` → `godot/assets/levels/HH10.yaml`
- `build/phase-5/yaml/HH15.yaml` → `godot/assets/levels/HH15.yaml`
- `build/phase-5/yaml/HH17.yaml` → `godot/assets/levels/HH17.yaml`
- `build/phase-5/yaml/HH18.yaml` → `godot/assets/levels/HH18.yaml`
- `build/phase-5/yaml/HH19.yaml` → `godot/assets/levels/HH19.yaml`
- `build/phase-5/yaml/HH22.yaml` → `godot/assets/levels/HH22.yaml`
- `build/phase-5/yaml/HH25.yaml` → `godot/assets/levels/HH25.yaml`
- `build/phase-5/yaml/HH34.yaml` → `godot/assets/levels/HH34.yaml`
- `build/phase-5/yaml/HH40.yaml` → `godot/assets/levels/HH40.yaml`
- `build/phase-5/yaml/HH46.yaml` → `godot/assets/levels/HH46.yaml`
- `build/phase-5/yaml/HH49.yaml` → `godot/assets/levels/HH49.yaml`
- `build/phase-5/yaml/HLEV14.yaml` → `godot/assets/levels/HLEV14.yaml`
- `build/phase-5/yaml/HLEV20.yaml` → `godot/assets/levels/HLEV20.yaml`
- `build/phase-5/yaml/HLEV21.yaml` → `godot/assets/levels/HLEV21.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV30.yaml` → `godot/assets/levels/HLEV30.yaml`
- `build/phase-5/yaml/HLEV4.yaml` → `godot/assets/levels/HLEV4.yaml`
- `build/phase-5/yaml/HLEV5.yaml` → `godot/assets/levels/HLEV5.yaml`
- `build/phase-5/yaml/MLEV15.yaml` → `godot/assets/levels/MLEV15.yaml`
- `build/phase-5/yaml/MLEV26.yaml` → `godot/assets/levels/MLEV26.yaml`
- `build/phase-5/yaml/MLEV8.yaml` → `godot/assets/levels/MLEV8.yaml`
- `build/phase-5/yaml/RLEV1.yaml` → `godot/assets/levels/RLEV1.yaml`
- ... and 12 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 4153 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 1024 | friction = 4.000 |
| `unk_6` | 16 | category-specific property |
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
| Total Frames | 25 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–3 (4 frames) | 16×16 | 0 |
| `3` | 4 | 4–12 (9 frames) | 16×16 | 28 |
| `2` | 13 | 13–24 (12 frames) | 24×32 | 91 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART84_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART84_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART84_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART84_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART84_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART84_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART84_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART84_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART84_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART84_f009.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART84_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART84_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART84_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART84_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART84_f014.png :material-check:` |
| 15 | `0001_0015` | `build/phase-3/bitmaps/PART84_f015.png :material-check:` |
| 16 | `0001_0016` | `build/phase-3/bitmaps/PART84_f016.png :material-check:` |
| 17 | `0001_0017` | `build/phase-3/bitmaps/PART84_f017.png :material-check:` |
| 18 | `0001_0018` | `build/phase-3/bitmaps/PART84_f018.png :material-check:` |
| 19 | `0001_0019` | `build/phase-3/bitmaps/PART84_f019.png :material-check:` |
| 20 | `0001_0020` | `build/phase-3/bitmaps/PART84_f020.png :material-check:` |
| 21 | `0001_0021` | `build/phase-3/bitmaps/PART84_f021.png :material-check:` |
| 22 | `0001_0022` | `build/phase-3/bitmaps/PART84_f022.png :material-check:` |
| 23 | `0001_0023` | `build/phase-3/bitmaps/PART84_f023.png :material-check:` |
| 24 | `0001_0024` | `build/phase-3/bitmaps/PART84_f024.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 25 |
| `END_FRAME` | 25 |
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

**Greco-Roman Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART84.json` |
| Sprite PNGs | `godot/assets/sprites/PART84_f*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV12.yaml` |
| Level YAML | `godot/assets/levels/ELEV15.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| ... | +37 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART84.json` + `build/phase-5/yaml/`*
