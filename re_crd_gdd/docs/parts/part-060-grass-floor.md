# Part 60 — Grass Floor

## Identity

| Field | Value |
|-------|-------|
| Part Type | `60` |
| Category | Walls / Floors |
| Description | This is a grass floor or vine wall. Stretch it vertically or horizontally to any length you need. It's not very slippery. Explosions will blast holes through it. |
| ANM File | `PART60.ANM` → `build/phase-4/anm/PART60.json` |
| BMP Resource | `PART60.BMP` → `build/phase-3/bitmaps/PART60_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**10 level(s)** use this part type:

- `build/phase-5/yaml/HH37.yaml` → `godot/assets/levels/HH37.yaml`
- `build/phase-5/yaml/HH43.yaml` → `godot/assets/levels/HH43.yaml`
- `build/phase-5/yaml/HH5.yaml` → `godot/assets/levels/HH5.yaml`
- `build/phase-5/yaml/HLEV6.yaml` → `godot/assets/levels/HLEV6.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV17.yaml` → `godot/assets/levels/RLEV17.yaml`
- `build/phase-5/yaml/RLEV28.yaml` → `godot/assets/levels/RLEV28.yaml`
- `build/phase-5/yaml/RLEV29.yaml` → `godot/assets/levels/RLEV29.yaml`
- `build/phase-5/yaml/TLEV2.yaml` → `godot/assets/levels/TLEV2.yaml`
- `build/phase-5/yaml/TLEV39.yaml` → `godot/assets/levels/TLEV39.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 128 | friction = 0.500 |
| `unk_6` | 128 | category-specific property |
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
| Total Frames | 30 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–7 (8 frames) | 16×16 | 0 |
| `2` | 8 | 8–17 (10 frames) | 16×16 | 56 |
| `3` | 18 | 18–29 (12 frames) | 40×20 | 126 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART60_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART60_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART60_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART60_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART60_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART60_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART60_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART60_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART60_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART60_f009.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART60_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART60_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART60_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART60_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART60_f014.png :material-check:` |
| 15 | `0001_0015` | `build/phase-3/bitmaps/PART60_f015.png :material-check:` |
| 16 | `0001_0016` | `build/phase-3/bitmaps/PART60_f016.png :material-check:` |
| 17 | `0001_0017` | `build/phase-3/bitmaps/PART60_f017.png :material-check:` |
| 18 | `0001_0018` | `build/phase-3/bitmaps/PART60_f018.png :material-check:` |
| 19 | `0001_0019` | `build/phase-3/bitmaps/PART60_f019.png :material-check:` |
| 20 | `0001_0020` | `build/phase-3/bitmaps/PART60_f020.png :material-check:` |
| 21 | `0001_0021` | `build/phase-3/bitmaps/PART60_f021.png :material-check:` |
| 22 | `0001_0022` | `build/phase-3/bitmaps/PART60_f022.png :material-check:` |
| 23 | `0001_0023` | `build/phase-3/bitmaps/PART60_f023.png :material-check:` |
| 24 | `0001_0024` | `build/phase-3/bitmaps/PART60_f024.png :material-check:` |
| 25 | `0001_0025` | `build/phase-3/bitmaps/PART60_f025.png :material-check:` |
| 26 | `0001_0026` | `build/phase-3/bitmaps/PART60_f026.png :material-check:` |
| 27 | `0001_0027` | `build/phase-3/bitmaps/PART60_f027.png :material-check:` |
| 28 | `0001_0028` | `build/phase-3/bitmaps/PART60_f028.png :material-check:` |
| 29 | `0001_0029` | `build/phase-3/bitmaps/PART60_f029.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 30 |
| `END_FRAME` | 30 |
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

**Grass Floor** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART60.json` |
| Sprite PNGs | `godot/assets/sprites/PART60_f*.png` |
| Level YAML | `godot/assets/levels/HH37.yaml` |
| Level YAML | `godot/assets/levels/HH43.yaml` |
| Level YAML | `godot/assets/levels/HH5.yaml` |
| Level YAML | `godot/assets/levels/HLEV6.yaml` |
| Level YAML | `godot/assets/levels/MLEV30.yaml` |
| ... | +5 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART60.json` + `build/phase-5/yaml/`*
