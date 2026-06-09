# Part 49 — rope end (phantom)

## Identity

| Field | Value |
|-------|-------|
| Part Type | `49` |
| Category | Created / Phantom |
| Description | phantom part |
| ANM File | `None.ANM` → `build/phase-4/anm/None.json` |
| BMP Resource | `None.BMP` → `build/phase-3/bitmaps/None_f*.png` |
| Created Part | Yes |
| Interactive | No |

## Levels Using This Part

*This part is not used in any built-in level (may be created dynamically at runtime).*

## Physics Properties

| Property | Raw Value | Interpretation |
|----------|-----------|----------------|
| `mass` | 1600 | mass/density (relative scale) |
| `unk_2` | 1000 | category-specific property |
| `property_q8` | 0 | Q8.8 = 0.000 |
| `unk_6` | 0 | category-specific property |
| `dim_w1` | 240 | dimension 1 width |
| `dim_h1` | 240 | dimension 1 height |
| `dim_w2` | 0 | dimension 2 width |
| `dim_h2` | 0 | dimension 2 height |
| `bitmap_w` | 0 | bitmap frame width |
| `bitmap_h` | 0 | bitmap frame height |

## Category Rules

| Rule | Value |
|------|-------|
| Triggers | *(none)* |
| Destructible | No |
| Spawns | *(none)* |
| Category Part Count | 1 |

## State Machine

*No SOLVE.RES state data — this part has no programmatic state transitions.*

## ANM Animation

| Property | Value |
|----------|-------|
| Total Frames | 0 |
| Total States | 0 |
| Animated (Section A) | No |
| Section A Durations | *(empty)* |

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

**rope end (phantom)** is a dynamically created (phantom) part. It is not placed by the player but spawned at runtime by another part's behavior (e.g., explosion debris, laser beam, rope end phantom).

**rope end (phantom)** is a static part with no programmatic state transitions. Its visual appearance is determined by the ANM state selected at placement time (via the `appearance` field in the level file).

## Godot Data Sources

| Asset Type | Path |
|------------|------|
| Behavior JSON | `godot/assets/data/behaviors.json` |
| Category JSON | `godot/assets/data/categories.json` |
| Properties JSON | `godot/assets/data/part-properties.json` |
| Catalog JSON | `godot/assets/data/part-name-catalog.json` |
| ANM JSON | `build/phase-4/anm/None.json` |
| Sprite PNGs | `godot/assets/sprites/None_f*.png` |

---

*Generated from `build/phase-16/godot/behaviors.json` + `build/phase-9/part-properties.json` + `build/phase-4/anm/None.json` + `build/phase-5/yaml/`*
