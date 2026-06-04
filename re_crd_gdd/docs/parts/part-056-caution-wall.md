# Part 56 — Caution Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `56` |
| Category | Walls / Floors |
| Description | This is a caution wall or floor. Stretch it vertically or horizontally to any length you need. It's very slippery, and isn't affected by explosives. |
| ANM File | `PART56.ANM` → `build/phase-4/anm/PART56.json` |
| BMP Resource | `PART56.BMP` → `build/phase-3/bitmaps/PART56_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

**48 level(s)** use this part type:

- `build/phase-5/yaml/ELEV10.yaml` → `godot/assets/levels/ELEV10.yaml`
- `build/phase-5/yaml/ELEV19.yaml` → `godot/assets/levels/ELEV19.yaml`
- `build/phase-5/yaml/ELEV21.yaml` → `godot/assets/levels/ELEV21.yaml`
- `build/phase-5/yaml/ELEV3.yaml` → `godot/assets/levels/ELEV3.yaml`
- `build/phase-5/yaml/ELEV4.yaml` → `godot/assets/levels/ELEV4.yaml`
- `build/phase-5/yaml/ELEV5.yaml` → `godot/assets/levels/ELEV5.yaml`
- `build/phase-5/yaml/HH1.yaml` → `godot/assets/levels/HH1.yaml`
- `build/phase-5/yaml/HH12.yaml` → `godot/assets/levels/HH12.yaml`
- `build/phase-5/yaml/HH39.yaml` → `godot/assets/levels/HH39.yaml`
- `build/phase-5/yaml/HH47.yaml` → `godot/assets/levels/HH47.yaml`
- `build/phase-5/yaml/HH8.yaml` → `godot/assets/levels/HH8.yaml`
- `build/phase-5/yaml/HH9.yaml` → `godot/assets/levels/HH9.yaml`
- `build/phase-5/yaml/HLEV12.yaml` → `godot/assets/levels/HLEV12.yaml`
- `build/phase-5/yaml/HLEV13.yaml` → `godot/assets/levels/HLEV13.yaml`
- `build/phase-5/yaml/HLEV15.yaml` → `godot/assets/levels/HLEV15.yaml`
- `build/phase-5/yaml/HLEV17.yaml` → `godot/assets/levels/HLEV17.yaml`
- `build/phase-5/yaml/HLEV2.yaml` → `godot/assets/levels/HLEV2.yaml`
- `build/phase-5/yaml/HLEV22.yaml` → `godot/assets/levels/HLEV22.yaml`
- `build/phase-5/yaml/HLEV26.yaml` → `godot/assets/levels/HLEV26.yaml`
- `build/phase-5/yaml/HLEV29.yaml` → `godot/assets/levels/HLEV29.yaml`
- `build/phase-5/yaml/MLEV16.yaml` → `godot/assets/levels/MLEV16.yaml`
- `build/phase-5/yaml/MLEV17.yaml` → `godot/assets/levels/MLEV17.yaml`
- `build/phase-5/yaml/MLEV18.yaml` → `godot/assets/levels/MLEV18.yaml`
- `build/phase-5/yaml/MLEV19.yaml` → `godot/assets/levels/MLEV19.yaml`
- `build/phase-5/yaml/MLEV20.yaml` → `godot/assets/levels/MLEV20.yaml`
- `build/phase-5/yaml/MLEV21.yaml` → `godot/assets/levels/MLEV21.yaml`
- `build/phase-5/yaml/MLEV22.yaml` → `godot/assets/levels/MLEV22.yaml`
- `build/phase-5/yaml/MLEV23.yaml` → `godot/assets/levels/MLEV23.yaml`
- `build/phase-5/yaml/MLEV29.yaml` → `godot/assets/levels/MLEV29.yaml`
- `build/phase-5/yaml/MLEV9.yaml` → `godot/assets/levels/MLEV9.yaml`
- ... and 18 more levels

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 100 | mass/density (relative scale) |
| `unk_2` | 140 | category-specific property |
| `friction_q8` | 512 | friction = 2.000 |
| `unk_6` | 32 | category-specific property |
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
| Total Frames | 18 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–2 (3 frames) | 16×16 | 0 |
| `2` | 3 | 3–5 (3 frames) | 16×16 | 21 |
| `3` | 6 | 6–17 (12 frames) | 24×9 | 42 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART56_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART56_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART56_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART56_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART56_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART56_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART56_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART56_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART56_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART56_f009.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART56_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART56_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART56_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART56_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART56_f014.png :material-check:` |
| 15 | `0001_0011` | `build/phase-3/bitmaps/PART56_f011.png :material-check:` |
| 16 | `0001_0015` | `build/phase-3/bitmaps/PART56_f015.png :material-check:` |
| 17 | `0001_0016` | `build/phase-3/bitmaps/PART56_f016.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 18 |
| `END_FRAME` | 18 |
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

**Caution Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART56.json` |
| Sprite PNGs | `godot/assets/sprites/PART56_f*.png` |
| Level YAML | `godot/assets/levels/ELEV10.yaml` |
| Level YAML | `godot/assets/levels/ELEV19.yaml` |
| Level YAML | `godot/assets/levels/ELEV21.yaml` |
| Level YAML | `godot/assets/levels/ELEV3.yaml` |
| Level YAML | `godot/assets/levels/ELEV4.yaml` |
| ... | +43 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART56.json` + `build/phase-5/yaml/`*
