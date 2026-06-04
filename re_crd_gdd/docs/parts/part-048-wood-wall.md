# Part 48 — Wood Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `48` |
| Category | Walls / Floors |
| Description | This is a wooden wall or floor. Stretch it vertically or horizontally to any length you need. Its surface isn't very slippery. Explosions will blast holes through it. |
| ANM File | `PART48.ANM` → `build/phase-4/anm/PART48.json` |
| BMP Resource | `PART48.BMP` → `build/phase-3/bitmaps/PART48_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**39 level(s)** use this part type:

- `build/phase-5/yaml/ELEV11.yaml` → `godot/assets/levels/ELEV11.yaml`
- `build/phase-5/yaml/ELEV2.yaml` → `godot/assets/levels/ELEV2.yaml`
- `build/phase-5/yaml/ELEV22.yaml` → `godot/assets/levels/ELEV22.yaml`
- `build/phase-5/yaml/ELEV23.yaml` → `godot/assets/levels/ELEV23.yaml`
- `build/phase-5/yaml/ELEV25.yaml` → `godot/assets/levels/ELEV25.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/ELEV9.yaml` → `godot/assets/levels/ELEV9.yaml`
- `build/phase-5/yaml/HH20.yaml` → `godot/assets/levels/HH20.yaml`
- `build/phase-5/yaml/HH21.yaml` → `godot/assets/levels/HH21.yaml`
- `build/phase-5/yaml/HH30.yaml` → `godot/assets/levels/HH30.yaml`
- `build/phase-5/yaml/HH44.yaml` → `godot/assets/levels/HH44.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV18.yaml` → `godot/assets/levels/HLEV18.yaml`
- `build/phase-5/yaml/HLEV19.yaml` → `godot/assets/levels/HLEV19.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV23.yaml` → `godot/assets/levels/HLEV23.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV28.yaml` → `godot/assets/levels/HLEV28.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/HLEV3.yaml` → `godot/assets/levels/HLEV3.yaml`
- `build/phase-5/yaml/HLEV8.yaml` → `godot/assets/levels/HLEV8.yaml`
- `build/phase-5/yaml/MLEV10.yaml` → `godot/assets/levels/MLEV10.yaml`
- `build/phase-5/yaml/MLEV12.yaml` → `godot/assets/levels/MLEV12.yaml`
- `build/phase-5/yaml/MLEV19.yaml` → `godot/assets/levels/MLEV19.yaml`
- `build/phase-5/yaml/MLEV23.yaml` → `godot/assets/levels/MLEV23.yaml`
- `build/phase-5/yaml/MLEV25.yaml` → `godot/assets/levels/MLEV25.yaml`
- `build/phase-5/yaml/MLEV30.yaml` → `godot/assets/levels/MLEV30.yaml`
- `build/phase-5/yaml/RLEV11.yaml` → `godot/assets/levels/RLEV11.yaml`
- `build/phase-5/yaml/RLEV13.yaml` → `godot/assets/levels/RLEV13.yaml`
- `build/phase-5/yaml/RLEV16.yaml` → `godot/assets/levels/RLEV16.yaml`
- ... and 9 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 7552 | mass/density (relative scale) |
| `unk_2` | 0 | category-specific property |
| `friction_q8` | 1024 | friction = 4.000 |
| `unk_6` | 12 | category-specific property |
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
| Total Frames | 38 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `2` | 0 | 0–12 (13 frames) | 16×16 | 0 |
| `3` | 13 | 13–25 (13 frames) | 16×16 | 91 |
| `4` | 26 | 26–37 (12 frames) | 16×16 | 182 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART48_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART48_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART48_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART48_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART48_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART48_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART48_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART48_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART48_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART48_f009.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART48_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART48_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART48_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART48_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART48_f014.png :material-check:` |
| 15 | `0001_0015` | `build/phase-3/bitmaps/PART48_f015.png :material-check:` |
| 16 | `0001_0016` | `build/phase-3/bitmaps/PART48_f016.png :material-check:` |
| 17 | `0001_0017` | `build/phase-3/bitmaps/PART48_f017.png :material-check:` |
| 18 | `0001_0018` | `build/phase-3/bitmaps/PART48_f018.png :material-check:` |
| 19 | `0001_0019` | `build/phase-3/bitmaps/PART48_f019.png :material-check:` |
| 20 | `0001_0020` | `build/phase-3/bitmaps/PART48_f020.png :material-check:` |
| 21 | `0001_0021` | `build/phase-3/bitmaps/PART48_f021.png :material-check:` |
| 22 | `0001_0022` | `build/phase-3/bitmaps/PART48_f022.png :material-check:` |
| 23 | `0001_0023` | `build/phase-3/bitmaps/PART48_f023.png :material-check:` |
| 24 | `0001_0024` | `build/phase-3/bitmaps/PART48_f024.png :material-check:` |
| 25 | `0001_0025` | `build/phase-3/bitmaps/PART48_f025.png :material-check:` |
| 26 | `0001_0026` | `build/phase-3/bitmaps/PART48_f026.png :material-check:` |
| 27 | `0001_0027` | `build/phase-3/bitmaps/PART48_f027.png :material-check:` |
| 28 | `0001_0028` | `build/phase-3/bitmaps/PART48_f028.png :material-check:` |
| 29 | `0001_0029` | `build/phase-3/bitmaps/PART48_f029.png :material-check:` |
| 30 | `0001_0030` | `build/phase-3/bitmaps/PART48_f030.png :material-check:` |
| 31 | `0001_0031` | `build/phase-3/bitmaps/PART48_f031.png :material-check:` |
| 32 | `0001_0032` | `build/phase-3/bitmaps/PART48_f032.png :material-check:` |
| 33 | `0001_0033` | `build/phase-3/bitmaps/PART48_f033.png :material-check:` |
| 34 | `0001_0034` | `build/phase-3/bitmaps/PART48_f034.png :material-check:` |
| 35 | `0001_0035` | `build/phase-3/bitmaps/PART48_f035.png :material-check:` |
| 36 | `0001_0036` | `build/phase-3/bitmaps/PART48_f036.png :material-check:` |
| 37 | `0001_0037` | `build/phase-3/bitmaps/PART48_f037.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 38 |
| `END_FRAME` | 38 |
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

**Wood Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART48.json` |
| Sprite PNGs | `godot/assets/sprites/PART48_f*.png` |
| Level YAML | `godot/assets/levels/ELEV11.yaml` |
| Level YAML | `godot/assets/levels/ELEV2.yaml` |
| Level YAML | `godot/assets/levels/ELEV22.yaml` |
| Level YAML | `godot/assets/levels/ELEV23.yaml` |
| Level YAML | `godot/assets/levels/ELEV25.yaml` |
| ... | +34 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART48.json` + `build/phase-5/yaml/`*
