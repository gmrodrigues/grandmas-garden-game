# Part 112 — Cactus

## Identity

| Field | Value |
|-------|-------|
| Part Type | `112` |
| Category | Scenery |
| Description | scenery part |
| ANM File | `PART112.ANM` → `build/phase-4/anm/PART112.json` |
| BMP Resource | `PART112.BMP` → `build/phase-3/bitmaps/PART112_f*.png` |
| Created Part | No |
| Interactive | No |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `unk_2` | 900 | scenery property (900 for trees, 1100-1200 for clouds/sun) |
| `bitmap_w` | 47 | bitmap frame width |
| `bitmap_h` | 98 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | Yes |
| Spawns | *(none)* |
| Category Part Count | 26 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 1 |
| Total States | 0 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

### Frame Sprite Details

| Frame | Sprites | PNG References |
|-------|---------|----------------|
| 0 | `0001_0000` | `build/phase-3/bitmaps/PART112.png :material-check:` |

### Bytecode Opcodes

| Opcode | Count |
|--------|-------|
| `DRAW_BMP` | 1 |
| `END_FRAME` | 1 |
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

**Cactus** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

This part can be destroyed by explosives.

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/PART112.json` |
| Sprite PNGs | `godot/assets/sprites/PART112_f*.png` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/PART112.json` + `build/phase-5/yaml/`*
