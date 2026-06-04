# Part 118 — Pool Table Wall

## Identity

| Field | Value |
|-------|-------|
| Part Type | `118` |
| Category | Pool Table |
| Description | You can build your own virtual pool table with these felt-covered walls. Balls will bounce off them. Add pockets wherever you want them. Flip these walls if necessary. |
| ANM File | `PART118.ANM` → `build/phase-4/anm/PART118.json` |
| BMP Resource | `PART118.BMP` → `build/phase-3/bitmaps/PART118_f*.png` |
| Created Part | No |
| Interactive | No |

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
| `mass` | 4153 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 1024 | Q8.8 = 4.000 |
| `unk_6` | 12 | category-specific property |
| `dim_w1` | 32 | dimension 1 width |
| `dim_h1` | 32 | dimension 1 height |
| `dim_w2` | 576 | dimension 2 width |
| `dim_h2` | 416 | dimension 2 height |
| `bitmap_w` | 32 | bitmap frame width |
| `bitmap_h` | 32 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | `collision` |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 2 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 23 |
| Total States | 3 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### State → Frame Mapping

| State ID | First Frame | Frame Range | Dimensions | Bytecode Offset |
|----------|-------------|-------------|------------|-----------------|
| `1` | 0 | 0–10 (11 frames) | 16×32 | 0 |
| `2` | 11 | 11–21 (11 frames) | 32×16 | 77 |
| `3` | 22 | 22 | 32×32 | 154 |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART118_f000.png :material-check:` |
| 1 | `0001_0001` | `build/phase-3/bitmaps/PART118_f001.png :material-check:` |
| 2 | `0001_0002` | `build/phase-3/bitmaps/PART118_f002.png :material-check:` |
| 3 | `0001_0003` | `build/phase-3/bitmaps/PART118_f003.png :material-check:` |
| 4 | `0001_0004` | `build/phase-3/bitmaps/PART118_f004.png :material-check:` |
| 5 | `0001_0005` | `build/phase-3/bitmaps/PART118_f005.png :material-check:` |
| 6 | `0001_0006` | `build/phase-3/bitmaps/PART118_f006.png :material-check:` |
| 7 | `0001_0007` | `build/phase-3/bitmaps/PART118_f007.png :material-check:` |
| 8 | `0001_0008` | `build/phase-3/bitmaps/PART118_f008.png :material-check:` |
| 9 | `0001_0009` | `build/phase-3/bitmaps/PART118_f009.png :material-check:` |
| 10 | `0001_0010` | `build/phase-3/bitmaps/PART118_f010.png :material-check:` |
| 11 | `0001_0011` | `build/phase-3/bitmaps/PART118_f011.png :material-check:` |
| 12 | `0001_0012` | `build/phase-3/bitmaps/PART118_f012.png :material-check:` |
| 13 | `0001_0013` | `build/phase-3/bitmaps/PART118_f013.png :material-check:` |
| 14 | `0001_0014` | `build/phase-3/bitmaps/PART118_f014.png :material-check:` |
| 15 | `0001_0015` | `build/phase-3/bitmaps/PART118_f015.png :material-check:` |
| 16 | `0001_0016` | `build/phase-3/bitmaps/PART118_f016.png :material-check:` |
| 17 | `0001_0017` | `build/phase-3/bitmaps/PART118_f017.png :material-check:` |
| 18 | `0001_0018` | `build/phase-3/bitmaps/PART118_f018.png :material-check:` |
| 19 | `0001_0019` | `build/phase-3/bitmaps/PART118_f019.png :material-check:` |
| 20 | `0001_0020` | `build/phase-3/bitmaps/PART118_f020.png :material-check:` |
| 21 | `0001_0021` | `build/phase-3/bitmaps/PART118_f021.png :material-check:` |
| 22 | `0001_0022` | `build/phase-3/bitmaps/PART118_f022.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 23 |
| `END_FRAME` | 23 |
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

**Pool Table Wall** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART118.json` |
| Sprite PNGs | `godot/assets/sprites/PART118_f*.png` |
| Level YAML | `godot/assets/levels/HH12.yaml` |
| Level YAML | `godot/assets/levels/HH2.yaml` |
| Level YAML | `godot/assets/levels/HH4.yaml` |
| Level YAML | `godot/assets/levels/HLEV24.yaml` |
| Level YAML | `godot/assets/levels/RLEV25.yaml` |
| ... | +2 more levels |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART118.json` + `build/phase-5/yaml/`*
