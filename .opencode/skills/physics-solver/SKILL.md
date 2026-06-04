---
name: physics-solver
description: Deterministic 6-pass physics engine for Godot 2D games. Use when implementing or debugging PhysicsSolver.gd, WorldState.gd, SimulationLoop.gd, or rope/collision/constraint physics. Trigger keywords: PhysicsSolver, physics step, rope constraint, collision detection, gravity, deterministic physics, 60Hz.
---

# Deterministic 6-Pass Physics Solver

Implements the physics engine from `backend/PhysicsSolver.gd`. Use when modifying the physics pipeline, adding new behavior handlers, or debugging physics behavior.

## Architecture

**Core files:**
- `godot_level_editor/backend/PhysicsSolver.gd` — main solver (RefCounted)
- `godot_level_editor/backend/WorldState.gd` — holds all parts + collision callbacks
- `godot_level_editor/backend/PartData.gd` — per-part state (position, velocity, flags, connections)
- `godot_level_editor/backend/SimulationLoop.gd` — 60Hz driver calling `solver.step()`

**Entry point:** `solver.step(world)` — called once per physics tick (60Hz, independent of render)

## 6-Pass Pipeline

| Pass | Name | What it does |
|------|------|-------------|
| 0 | State counters | Calls `advance_state()` per moving part — handles `state_counter`, `sub_counter`, `LIMIT_UPPER`, deterministic RNG |
| 1 | Gravity | `part.tick()` — `vel_y += gravity`, wind via `flags_3 & 0x08`, max_gravity clamp |
| 2 | Behaviors | Inline match on `part_type` — conveyor/gear/rocket/belt/gear behaviors |
| 3 | Viewport bounds | Floor bounce with COR, ceiling bounce, left/right wall clamp |
| 4 | Collisions | O(n²) AABB + circle overlap, collision matrix gating, `on_collision()` → SOLVE.RES trigger, connected parts skip |
| 5 | Proximity + Electrical | Proximity check (fire→balloon), electrical propagation (source→outlet→consumer) |
| 6 | Constraints | 3 iterations rope constraint, belt angular velocity sync |

## Key Patterns

### Adding a new behavior handler (Pass 2)

In `PhysicsSolver._handle_behaviors()` (`_physics_step` section), add an `elif part_type == N:` branch:

```gdscript
elif part_type == N:  # N = part type ID
    # inline logic for this part type
    pass  # e.g., set vel_x for conveyor
```

Keep it inline — no function call overhead per part per tick.

### Collision matrix modification

The `collision_matrix` Dictionary maps `category → allowed_target_categories`. Edit `PhysicsSolver._init_collision_matrix()` to change rules. Example:

```gdscript
DYNAMIC: [STATIC, DYNAMIC, EXPLOSIVE, TOOL]
```

### Rope constraint solver

Located in `PhysicsSolver._enforce_rope_constraint()` (line 359). Runs 3 iterations per tick. Modify `max_rope_iterations` to change accuracy vs. performance.

### Collision detection

`_detect_collision(a: PartData, b: PartData) -> bool` (line 182) handles:
- Circle vs Circle: distance < r1+r2
- Circle vs AABB: closest point on rect to circle center
- AABB vs AABB: overlap on both axes

`_resolve_collision(a, b)` (line 210): positional correction + velocity reflection with COR.

## Determinism Guarantees

1. **Fixed timestep**: `SimulationLoop` calls `solver.step()` at exactly 60Hz via `_physics_process`
2. **Order deterministic**: parts iterated in array index order — NEVER use `shuffle()` or non-deterministic order
3. **Integer math for positions**: `vel_y >> 9` instead of `vel_y / 512.0`
4. **LCG RNG**: seeded per `PartData._rng_state`, same formula each tick
5. **No `randf()` / `Time.get_ticks_msec()`** in physics code

## Debugging Physics

```gdscript
# In PhysicsSolver.step() after pass N:
if Engine.get_physics_frames() % 60 == 0:
    print("Pass %d: part %d pos=(%d,%d) vel=(%d,%d)" % [pass, i, part.x, part.y, part.vel_x, part.vel_y])
```

## Reference

- `backend/PartData.gd:134` — `tick()` gravity/wind
- `backend/PartData.gd:146` — `advance_state()` state machine
- `backend/PhysicsSolver.gd:36` — `step()` entry
- `backend/PhysicsSolver.gd:182` — `_detect_collision()`
- `backend/PhysicsSolver.gd:210` — `_resolve_collision()`
- `backend/PhysicsSolver.gd:359` — `_enforce_rope_constraint()`
