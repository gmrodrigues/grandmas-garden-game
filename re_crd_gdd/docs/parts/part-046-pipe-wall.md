# Part 46 — Pipe Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `46` |
| Category | Walls / Floors |
| Description | This is a pipe wall or floor. Stretch it vertically or horizontally to any length you need. It has a slippery surface. Explosions won't affect it. |
| ANM File | `PART46.ANM` → `build/phase-4/anm/PART46.json` |
| BMP Resource | `PART46.BMP` → `build/phase-3/bitmaps/PART46_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**27 level(s)** use this part type:

- `build/phase-5/yaml/ELEV1.yaml` → `godot/assets/levels/ELEV1.yaml`
- `build/phase-5/yaml/ELEV22.yaml` → `godot/assets/levels/ELEV22.yaml`
- `build/phase-5/yaml/HH11.yaml` → `godot/assets/levels/HH11.yaml`
- `build/phase-5/yaml/HH26.yaml` → `godot/assets/levels/HH26.yaml`
- `build/phase-5/yaml/HLEV1.yaml` → `godot/assets/levels/HLEV1.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV25.yaml` → `godot/assets/levels/HLEV25.yaml`
- `build/phase-5/yaml/HLEV27.yaml` → `godot/assets/levels/HLEV27.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV31.yaml` → `godot/assets/levels/HLEV31.yaml`
- `build/phase-5/yaml/MLEV14.yaml` → `godot/assets/levels/MLEV14.yaml`
- `build/phase-5/yaml/MLEV2.yaml` → `godot/assets/levels/MLEV2.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV3.yaml` → `godot/assets/levels/MLEV3.yaml`
- `build/phase-5/yaml/MLEV4.yaml` → `godot/assets/levels/MLEV4.yaml`
- `build/phase-5/yaml/MLEV5.yaml` → `godot/assets/levels/MLEV5.yaml`
- `build/phase-5/yaml/MLEV6.yaml` → `godot/assets/levels/MLEV6.yaml`
- `build/phase-5/yaml/RLEV2.yaml` → `godot/assets/levels/RLEV2.yaml`
- `build/phase-5/yaml/RLEV20.yaml` → `godot/assets/levels/RLEV20.yaml`
- `build/phase-5/yaml/RLEV26.yaml` → `godot/assets/levels/RLEV26.yaml`
- `build/phase-5/yaml/RLEV27.yaml` → `godot/assets/levels/RLEV27.yaml`
- `build/phase-5/yaml/TLEV10.yaml` → `godot/assets/levels/TLEV10.yaml`
- `build/phase-5/yaml/TLEV2.yaml` → `godot/assets/levels/TLEV2.yaml`
- `build/phase-5/yaml/TLEV21.yaml` → `godot/assets/levels/TLEV21.yaml`
- `build/phase-5/yaml/TLEV3.yaml` → `godot/assets/levels/TLEV3.yaml`
- `build/phase-5/yaml/TLEV34.yaml` → `godot/assets/levels/TLEV34.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 1024 | friction = 4.000 |
| `unk_6` | 16 | category-specific property |
| `tile_w` | 32 | base width in tile units |
| `tile_h` | 32 | base height in tile units |
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
| `1` | 8 | 8–19 (12 frames) | 32×25 | 56 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART46_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART46_f001.png :material-check:` |
| 2 | `0001_0001` | `build/phase-3/bitmaps/PART46_f001.png :material-check:` |
| 3 | `0001_0002` | `build/phase-3/bitmaps/PART46_f002.png :material-check:` |
| 4 | `0001_0003` | `build/phase-3/bitmaps/PART46_f003.png :material-check:` |
| 5 | `0001_0004` | `build/phase-3/bitmaps/PART46_f004.png :material-check:` |
| 6 | `0001_0004` | `build/phase-3/bitmaps/PART46_f004.png :material-check:` |
| 7 | `0001_0005` | `build/phase-3/bitmaps/PART46_f005.png :material-check:` |
| 8 | `0001_0006` | `build/phase-3/bitmaps/PART46_f006.png :material-check:` |
| 9 | `0001_0007` | `build/phase-3/bitmaps/PART46_f007.png :material-check:` |
| 10 | `0001_0008` | `build/phase-3/bitmaps/PART46_f008.png :material-check:` |
| 11 | `0001_0009` | `build/phase-3/bitmaps/PART46_f009.png :material-check:` |
| 12 | `0001_0010` | `build/phase-3/bitmaps/PART46_f010.png :material-check:` |
| 13 | `0001_0011` | `build/phase-3/bitmaps/PART46_f011.png :material-check:` |
| 14 | `0001_0012` | `build/phase-3/bitmaps/PART46_f012.png :material-check:` |
| 15 | `0001_0013` | `build/phase-3/bitmaps/PART46_f013.png :material-check:` |
| 16 | `0001_0014` | `build/phase-3/bitmaps/PART46_f014.png :material-check:` |
| 17 | `0001_0015` | `build/phase-3/bitmaps/PART46_f015.png :material-check:` |
| 18 | `0001_0016` | `build/phase-3/bitmaps/PART46_f016.png :material-check:` |
| 19 | `0001_0017` | `build/phase-3/bitmaps/PART46_f017.png :material-check:` |

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

**Pipe Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART46.json` |
| Sprite PNGs | `godot/assets/sprites/PART46_f*.png` |
| Level YAML | `godot/assets/levels/ELEV1.yaml` |
| Level YAML | `godot/assets/levels/ELEV22.yaml` |
| Level YAML | `godot/assets/levels/HH11.yaml` |
| Level YAML | `godot/assets/levels/HH26.yaml` |
| Level YAML | `godot/assets/levels/HLEV1.yaml` |
| ... | +22 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART46.json` + `build/phase-5/yaml/`*
