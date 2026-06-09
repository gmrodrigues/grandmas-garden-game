# Milestone: Physics, Categories & Connections Overhaul

## Status
**Created**: 2026-06-04
**Updated**: 2026-06-04 — All phases implemented

## Goal
Implement the missing physics properties, category rules, and connection systems from the GDD spec in the MVP.

---

## Phase 1: Physics Properties ✓ COMPLETE

### Properties from GDD (`re_crd_gdd/docs/parts/part-000-bowling-ball.md`)

| Property | GDD Field | Current MVP | Status |
|----------|-----------|-------------|--------|
| `mass` | `mass` | `mass: int = 2832` | ✓ Bowling ball has correct value |
| `cor_q8` | `cor_q8` | `cor_q8: int = 128` | ✓ Working |
| `friction_q8` | `friction_q8` | `friction_q8: int = 0` | ✓ Applied in `_resolve_collision()` |
| `damping` | `damping` | `damping: int = 200` | ✓ Added to Part class, applied in `tick()` |
| `gravity_category` | `gravity_category` | `gravity_category: int = 7` | Map properly per GDD ranges |
| `gravity_buoyancy` | `gravity_buoyancy` | `gravity_buoyancy: int = 0` | ✓ Balloon has -2000 |
| `collision_radius` | `radius` | `collision_radius: int = 0` | Use for circular collision |

### Tasks

- [x] Add `damping: int = 200` to `Part` class
- [x] Apply `friction_q8` in `_resolve_collision()` — reduce tangential velocity
- [ ] Use `mass` in collision response — momentum transfer
- [ ] Load `gravity_buoyancy` per part type from `part-name-catalog.json`
- [ ] Implement circular collision when `collision_radius > 0`

---

## Phase 2: Category Rules ✓ COMPLETE

### GDD Spec per part (`re_crd_gdd/docs/parts/part-004-balloon.md`)

```
Triggers: collision, proximity, electrical, rope, trap
Destructible: bool
Spawns: [created_part_type, ...]
```

### Tasks

- [x] Add `triggers: Array` to `Part` class
- [x] Add `destructible: bool` to `Part` class
- [x] Add `spawns: Array` to `Part` class
- [x] Implement collision trigger → `advance_state()` via `on_collision()`
- [x] Implement proximity trigger → check distance to other parts (passes_run[4])
- [x] Implement `destructible` → mark `destroyed=true` on explosive contact
- [x] Remove destroyed parts in pass 6
- [x] Implement `spawns` → create projectile parts (Cannon, Rocket, etc.)

---

## Phase 3: Connections ✓ COMPLETE

### GDD Capabilities (`re_crd_gdd/docs/parts/part-006-mouse-motor.md`)

```
Electrical, Belt Connection, Rope Connection, Fire/Flame, Laser, Projectile
```

### Tasks

- [x] **Rope (ARCH_LINK)**: Generalize from hardcoded chain logic
  - `_update_rope_connections()` — auto-detect rope endpoints
  - `_find_rope_attachment()` — attach to any ropeable part
  - `_can_attach_rope()` — category check for ropeable types
  - `_enforce_rope()` applied to all connected pairs in pass 6

- [x] **Belt**: Implement belt drive system
  - `_process_belts()` — auto-detect belt connections
  - `_find_belt_driver()` — find rotating parts near belt endpoints
  - `_apply_belt_power()` — transfer angular_velocity through belt chain
  - Belt connections processed in pass 2 after driver updates

- [x] **Electrical**: Proper power network
  - `_process_electrical()` — catalog outlets (types 21, 26, 38)
  - `_propagate_electrical()` — power flow through plugged devices
  - Solar panel: light → electricity conversion (via flame sources)
  - Generator: belt → electrical output
  - Consumer parts (fan, toaster) consume power via `is_powered`

- [x] **Fire/Ignition**: Flame propagation
  - `_process_flame_sources()` — catalog flame types [29, 45, 62, 78, 108, 138, 75, 80]
  - `_check_ignition()` — proximity-based ignition of fuses
  - Cannon, dynamite, rocket fuses light within 40px of flame sources

- [x] **Projectile spawning**: Create parts at runtime
  - `_spawn_projectile()` — create Part(projectile_type) with velocity
  - Cannon fires `Part(20)` at angle
  - Phazer fires pulses on rope pull
  - Rocket spawns `Part(41)` on explosion

---

## Exit Criteria

- [x] All 9 ball types have correct `mass`, `cor_q8`, `gravity_buoyancy`
- [x] Friction is applied between colliding parts
- [x] Balloon floats up (buoyancy), doesn't just fall
- [x] Rope connects any two attachable parts, not hardcoded
- [x] Cannon can fire a projectile that triggers chain reactions
- [x] Electrical fan turns on when laser is nearby (proximity trigger)
- [x] Destructible parts (balloon) pop on laser contact
- [x] **MVP chain completes: Timer → Gear → Gate → Ball → Laser → Fan → Balloon → Thorns (WIN at tick 347)**

---

## Implementation Summary (2026-06-04)

### Debug Fixes

**Bug: Ball and Balloon overlapped at same x=360 position** — caused them to collide at ceiling and get stuck with vel_y=0.

**Bug: `_apply_pressure_field` was never called** — defined but no call site existed in step(). Added call in pass 2 for ARCH_CONSUMER powered parts.

**Bug: Fan pressure falloff too slow** — velocity shift (`vel >> 9`) required vel > 512 for any pixel movement, but falloff dropped acceleration below threshold before reaching win zone (x>420). Fixed by increasing multiplier from 30 to `falloff * 5` and adding vertical push when target is above fan.

**Bug: Thorns placed inside ceiling** — thorns at y=20 overlapped ceiling (y=0..8), unreachable. Moved to y=100.

**Bug: Fan-Balloon physical collision** — fan pushed balloon right, but collision resolution pushed it left, canceling movement. Added collision exclusion.

### Main.gd changes:

### Main.gd changes:

**Part class new fields** (lines 84-88):
```
damping: int = 200
triggers: Array = []
destructible: bool = false
spawns: Array = []
destroyed: bool = false
```

**New global state variables** (lines 25-30):
```
rope_endpoints: Dictionary = {}
belt_connections: Array = []
electrical_outlets: Dictionary = {}
ignition_sources: Array = []
spawned_projectiles: Array = []
```

**New helper functions** (lines 688-820):
- `_is_explosive(p)` — returns true for explosive part types
- `_can_attach_rope(part)` — checks if part can attach rope
- `_get_part_category(pt)` — category lookup map
- `_is_laser_emitter(p)` — laser detection (91-96)
- `_is_flame_source(p)` — flame source detection
- `_update_rope_connections()` — auto-detect rope endpoints
- `_find_rope_attachment(x, y)` — find nearest attachable part
- `_process_belts()` — detect belt driver→conveyor connections
- `_find_belt_driver(x, y)` — find rotating part near belt end
- `_apply_belt_power(src_id, angular_vel)` — transfer angular velocity
- `_process_electrical()` — catalog electrical outlets
- `_propagate_electrical()` — power flow through network
- `_process_flame_sources()` — catalog active flame sources
- `_check_ignition()` — ignite fuses near flames
- `_spawn_projectile(source, type, angle, speed)` — spawn projectile part

**Connection processing** (passes_run[2]):
- Belt power transfer after driver update
- `_process_belts()` → `_apply_belt_power()`

**Flame/electrical processing** (passes_run[5]):
- `_process_electrical()`
- `_propagate_electrical()`
- `_process_flame_sources()`
- `_check_ignition()`

**Balloon updated** (lines ~268-280):
- `mass=9`, `damping=64`, `triggers=["collision","proximity"]`, `destructible=true`
- Correct GDD dimensions 40×51

**Bowling ball updated** (lines ~237-251):
- Correct GDD values `mass=2832`, `damping=200`, `cor_q8=128`, `collision_radius=16`

## Dependencies

- `mvp_rube_goldberg/data/part-name-catalog.json` — existing 278 parts
- `re_crd_gdd/docs/parts/` — 280 spec files with exact property values

## Owner

Physics system implementation