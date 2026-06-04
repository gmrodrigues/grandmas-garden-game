# 4. Physics Engine

The deterministic physics engine operates at a fixed 60Hz loop. Floating-point math is strictly forbidden.

## 4.1 Physics Pass Loop

The tick loop executes in the following order:
1. **Pass 0**: Advance State Machines (State Counters)
2. **Pass 1**: Apply Gravity (Update Velocities & Positions)
3. **Pass 2-3**: Detect Collisions (AABB Overlap & Response)
4. **Pass 4-6**: Enforce Constraints (Rope/Belt Distances)

## 4.2 Gravity (Pass 1)

Applied each tick to parts with `flags_1 & 0x1000` (moving).

```gdscript
velocity_y += gravity_y    # 32-bit addition with CWD sign-extension
velocity_x += gravity_x    # gravity_x is typically 0, negative if flags_3 bit 3 set
position.y += velocity_y >> 9 # fixed-point to pixel conversion (SAR 9)
position.x += velocity_x >> 9
```

Base gravity is selected by part category (field 0x3E in properties):
| Category | Base Gravity | gravity_y (base/4) | Effective px/tick² |
|----------|--------------|--------------------|--------------------|
| < 2 | 0x1C00 (7168) | 1792 | ~3.5 px/tick² |
| < 6 | 0x1A00 (6656) | 1664 | ~3.25 px/tick² |
| < 10 | 0x1800 (6144) | 1536 | ~3.0 px/tick² |
| >= 151 | 0x1000 (4096) | 1024 | ~2.0 px/tick² |

*Environment gravity (field 272 in level header) acts as the global multiplier index.*

## 4.3 Collision Detection & Response (Pass 2-3)

**Detection** is O(N²) AABB testing over moving parts.
`if (x1 >= x2 OR y1 >= y2 OR t1 >= t2 OR b1 <= b2) → no collision`

**Response** (Push-out & Bouncing):
```gdscript
overlap_x = min(r1, r2) - max(l1, l2)
overlap_y = min(b1, b2) - max(t1, t2)
# Push apart along axis of least overlap
correction = overlap / 2  # each part moves by half
```
Velocities are reflected and damped by the part's Coefficient of Restitution (COR), found in `PART{N}.PAR`.

## 4.4 Constraint Solver (Pass 4-6)

Single-pass distance constraint. Applied to Ropes (type 10), Belts (type 8), Steel Cables (type 76).

```gdscript
dx = target.x - part.x
dy = target.y - part.y
dist = integer_sqrt(dx*dx + dy*dy)
if dist > behavior_field:  # behavior = segment length in pixels
    correction = (dist - behavior_field) / 2
    normal_x = dx / dist
    normal_y = dy / dist
    part.x   += normal_x * correction
    part.y   += normal_y * correction
    target.x -= normal_x * correction
    target.y -= normal_y * correction
```
