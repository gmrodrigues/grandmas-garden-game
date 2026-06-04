# Part 119 — Pool Table Pocket

## Identity

| Field | Value |
|-------|-------|
| Part Type | `119` |
| Category | Pool Table |
| Description | These pool table pockets can be rotated to eight different angles. Use them with sections of pool table wall to build your own billiards game. Anything that drops into one of these pockets will disappear. |
| ANM File | `PART119.ANM` → `build/phase-4/anm/PART119.json` |
| BMP Resource | `PART119.BMP` → `build/phase-3/bitmaps/PART119_f*.png` |
| Created Part | No |
| Interactive | Yes |

## Levels Using This Part

**7 level(s)** use this part type:

- `build/phase-5/yaml/HH12.yaml` → `godot/assets/levels/HH12.yaml`
- `build/phase-5/yaml/HH2.yaml` → `godot/assets/levels/HH2.yaml`
- `build/phase-5/yaml/HH4.yaml` → `godot/assets/levels/HH4.yaml`
- `build/phase-5/yaml/HLEV24.yaml` → `godot/assets/levels/HLEV24.yaml`
- `build/phase-5/yaml/RLEV25.yaml` → `godot/assets/levels/RLEV25.yaml`
- `build/phase-5/yaml/RLEV6.yaml` → `godot/assets/levels/RLEV6.yaml`
- `build/phase-5/yaml/TLEV24.yaml` → `godot/assets/levels/TLEV24.yaml`

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1000 | mass/density (relative scale) |
| `unk_2` | 200 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 28 | category-specific property |
| `dim_w1` | 0 | dimension 1 width |
| `dim_h1` | 0 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 64 | bitmap frame width |
| `bitmap_h` | 64 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 2 |

## State Machine

### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Hole Empty | `1→3`, `3→4`, `4→5`, `5→6`, `6→7`, `7→8`, `8→9`, `9→11` | — | No |
| Hole Full | `11→12`, `12→13`, `13→14`, `14→15`, `15→16`, `16→17`, `17→18`, `18→-1` | — | No |

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 16 |
| Total States | 16 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0 | 64×64 | 0 |
| `3` | 1 | 1 | 32×48 | 7 |
| `4` | 2 | 2 | 64×64 | 14 |
| `5` | 3 | 3 | 48×32 | 21 |
| `6` | 4 | 4 | 64×64 | 28 |
| `7` | 5 | 5 | 32×48 | 35 |
| `8` | 6 | 6 | 64×64 | 42 |
| `9` | 7 | 7 | 48×32 | 49 |
| `11` | 8 | 8 | 64×64 | 56 |
| `12` | 9 | 9 | 32×48 | 63 |
| `13` | 10 | 10 | 64×64 | 70 |
| `14` | 11 | 11 | 48×32 | 77 |
| `15` | 12 | 12 | 64×64 | 84 |
| `16` | 13 | 13 | 32×48 | 91 |
| `17` | 14 | 14 | 64×64 | 98 |
| `18` | 15 | 15 | 48×32 | 105 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART119_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART119_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART119_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART119_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART119_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART119_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART119_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART119_f007.png :material-check:` |
| 8 | `0001_0000` | `build/phase-3/bitmaps/PART119_f000.png :material-check:` |
| 9 | `0001_0001` | `build/phase-3/bitmaps/PART119_f001.png :material-check:` |
| 10 | `0001_0002` | `build/phase-3/bitmaps/PART119_f002.png :material-check:` |
| 11 | `0001_0003` | `build/phase-3/bitmaps/PART119_f003.png :material-check:` |
| 12 | `0001_0004` | `build/phase-3/bitmaps/PART119_f004.png :material-check:` |
| 13 | `0001_0005` | `build/phase-3/bitmaps/PART119_f005.png :material-check:` |
| 14 | `0001_0006` | `build/phase-3/bitmaps/PART119_f006.png :material-check:` |
| 15 | `0001_0007` | `build/phase-3/bitmaps/PART119_f007.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 16 |
| `END_FRAME` | 16 |
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

**Pool Table Pocket** has 2 semantic states: Hole Empty, Hole Full. Transitions are triggered by: collision.

Terminal state(s): Hole Full (part is removed from simulation).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART119.json` |
| Sprite PNGs | `godot/assets/sprites/PART119_f*.png` |
| Level YAML | `godot/assets/levels/HH12.yaml` |
| Level YAML | `godot/assets/levels/HH2.yaml` |
| Level YAML | `godot/assets/levels/HH4.yaml` |
| Level YAML | `godot/assets/levels/HLEV24.yaml` |
| Level YAML | `godot/assets/levels/RLEV25.yaml` |
| ... | +2 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART119.json` + `build/phase-5/yaml/`*
