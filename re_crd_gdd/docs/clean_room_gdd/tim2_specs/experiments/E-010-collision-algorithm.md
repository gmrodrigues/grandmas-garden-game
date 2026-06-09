# E-010: Collision Detection Algorithm (G12)

**Date:** 2026-05-26
**Questions investigated:** Q-017
**Gap:** G12
**Related:** G11 (gravity/ticks), G13 (rope/belt constraints)

## TL;DR

Reverse-engineered from TIM2.EXE using static analysis. The game uses Axis-Aligned
Bounding Box (AABB) collision detection for all parts. The physics loop iterates
over each moving part one-by-one in the main frame update (0x54EAB). For each
part, it applies gravity, then checks AABB overlap against other parts. If a
collision is detected, it adjusts positions and may exchange velocity.

## Methods

Static analysis of TIM2.EXE via objdump, guided by the task agent's structural
analysis of the main game loop and per-part physics step.

## Key Findings

### Physics Loop Architecture

The main frame update at 0x54EAB executes multiple passes over the part list
each frame (once per tick):

| Pass | EXE Offset | Purpose |
|------|-----------|---------|
| Clear state | 0x55048 | Clears flags, calls terminal velocity clamp |
| **Physics** | 0x55090 | **Per-part gravity + collision** (calls 0x55353) |
| Rope init | 0x550DC | Initializes rope parameters |
| Rope update | 0x5514A | Updates rope constraints |
| Rope pass 2 | 0x551A4 | Alternative rope update |
| State check | 0x551FE | Disabled/frozen part cleanup |
| Special parts | 0x55235 | Type 0x5B-0x5F updates |

### Per-Part Physics Step (0x55353)

For each moving part:
1. Set physics-active flag (bit 6 at 0x0A)
2. Skip if disabled (bit 5 at 0x0D) or frozen (bit 6 at 0x0F)
3. **Call 0x5361E — Apply gravity** (velocity += gravity, 32-bit)
4. **Call 0x54459 — Collision detection → response** (AABB test against all other parts)
5. If collision: adjust position, re-apply gravity, re-check collision

### AABB Collision Detection (0x54459)

The collision detection function at 0x54459:

1. Stores the part's far pointer at global variables [0x63EE]:[0x63F0]
2. Checks if part has a connected part (field 0x98 ≠ 0)
3. Loads the connected part's pointer from fields 0x9A/0x9C
4. Calls function 0x5428B to compute AABB extents for both parts
5. Performs AABB overlap test using global variables:
   - [0x63E0] vs [0x63D0] : part1.extent_x1 vs part2.extent_x1
   - [0x63E2] vs [0x63DC] : part1.extent_x2 vs part2.extent_x2
   - [0x63E4] vs [0x63D4] : part1.extent_y1 vs part2.extent_y1
   - [0x63E6] vs [0x63DE] : part1.extent_y2 vs part2.extent_y2

   Check: if (x1 ≥ x2) OR (y1 ≥ y2) OR (top1 ≥ top2) OR (bottom1 ≤ bottom2) → NO COLLISION
   Otherwise: COLLISION DETECTED

6. On collision:
   - Calls function 0x54760 for collision type test (shape-specific check)
   - If shape test passes, sets SI=1 (collision flag)
   - Calls 0x543BB (collision response — velocity/position adjustment)

7. **Connection following**: For belt/rope connected parts, the function follows
   the linked part list (via 0x98/0x9A fields) and tests ALL connected parts
   for AABB overlap (this is the loop at 0x54636 that compares edges)

### AABB Extents Computation (0x5428B)

The function at 0x5428B computes the bounding box extents for a part based on:
- Position from fields 0x22/0x24 (fixed-point converted position)
- Size from collision dimensions (width_1/height_1 from the 48-byte struct)

The results are stored in global variables:
- [0x63E0]/[0x63E2] — part1 min/max X
- [0x63E4]/[0x63E6] — part1 min/max Y
- [0x63D0]/[0x63DC] — part2 min/max X
- [0x63D4]/[0x63DE] — part2 min/max Y

### Collision Response (0x57250 area)

From earlier analysis at 0x57250-0x57300:
1. Calculate overlap amount: `overlap = part1.extent - part2.extent`
2. Divide overlap between both parts: `correction = overlap / 2`
3. Adjust positions: `pos_x += correction`
4. The collision also affects velocity (denoted at 0x57295):
   `velocity_y += overlap` (impulse)
5. Uses boundary check (0x5725C): velocity is clamped when overlap exceeds
   a threshold (0x64 = 100 internal units)

### Collision Types

From the code at 0x54760 (called from collision detection), the game supports
multiple collision types:
- **AABB-AABB** (rect vs rect) — the main check
- **Circle-AABB** (ball vs wall) — uses radius field from PAR data
- **AABB overlapping with belt/rope connections** — follows constraint chain

The PAR file shapes determine which collision test is used:
- Parts with `radius` field → circle collision (balls)
- Parts with `collision_w`/`collision_h` → AABB collision (walls/inclines)

### Confirmed Part Struct Field Updates

| Offset | Previous Name | Corrected Name | Source |
|--------|--------------|----------------|--------|
| 0x0A | flags_3 | Active flags (bit 6 = physics active) | 0x55353 |
| 0x0D | (part of background color) | Disabled flag (bit 5) | 0x55353 |
| 0x0F | (byte) | Frozen flag (bit 6) | 0x55353 |
| 0x14 | pos_x | Position X | Multi. |
| 0x16 | pos_y | Position Y | Multi. |
| 0x18 | behavior | Also: collision state / velocity_x | 0x572D7 |
| 0x1A | unknown_26 | velocity_y (32-bit, lo word) | 0x53622 |
| 0x98 | part of editor data | Connected part pointer (seg:off) | 0x54471 |
| 0x9A | part of editor data | Connected part pointer | 0x54492 |

### What's Missing

1. **Tick rate** still needs empirical confirmation
2. **COR implementation** — how is the restitution coefficient applied?
   The `cor_q8` field (128=0.5) from PAR files should affect bounce velocity
3. **Friction implementation** — how does `friction_q8` work?
4. **Exact AABB size source** — does the game use `width_1`/`height_1` from the
   48-byte struct or the PAR file's `collision_w`/`collision_h`?
5. **Detail of velocity exchange** during collision (mass-weighted momentum transfer)

### For Reimplementation

This is sufficient to build a working physics engine:
- AABB collision detection between all part pairs
- Position correction after overlap detection
- Gravity integration (velocity += gravity, position += velocity >> 9)
- Single-pass iteration (not requiring multiple solver iterations for default physics)
- Belt/rope constraints via connection following
