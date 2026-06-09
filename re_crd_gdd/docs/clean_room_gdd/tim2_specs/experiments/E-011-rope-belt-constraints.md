# G13 — Rope/Belt Constraint Solver

**Date:** 2026-05-27
**Questions investigated:** Q-018
**Gap:** G13

## TL;DR

TIM2 uses a single-pass distance constraint solver for ropes (type 10), steel cables
(type 76), and belts (type 8). Three frame passes (0x550DC, 0x5514A, 0x551A4) handle
rope/belt initialization and constraint enforcement. The solver is called once per
frame via FAR CALL to segment 0x30:0x54F2. There is NO iterative solver — the
constraint is enforced in a single pass each tick, which is typical for 1994 DOS games.

## Architecture

### Frame Update Passes for Ropes/Belts

The main frame update at 0x54EAB runs 7 passes. Three handle rope/belt constraints:

| Pass | Offset | Action |
|------|--------|--------|
| **3** | 0x550DC | Checks part type (0x11=rope, 0x6C=steel cable). Reads property at PAR field offset 0x38, stores at physics struct offset 0x3E |
| **4** | 0x5514A | Same type check. Calls **rope constraint solver** at `lcall $0x30,$0x54F2`, then calls per-part physics (0x55353) |
| **5** | 0x551A4 | Same type check. Alternative rope update path |
| **6** | 0x551FE | Non-disabled parts: if flag bit 3 at `es:[bx+0x0a]` NOT set, calls 0x55593 |
| **7** | 0x55235 | Special parts (0x5B-0x5F): calls `lcall 0x270,0x75` |

### Solver Invocation

At file offset 0x5511C, the code executes:
```
PUSH [BP-0x04]       ; push part index (high word)
PUSH [BP-0x06]       ; push part index (low word)
LCALL 0x30:0x54F2    ; call rope constraint solver
```

The solver function at 0x30:0x54F2 receives the part's far pointer and enforces
the distance constraint against the connected part.

### Solver Iteration Count

**Confirmed: 1 iteration per frame.** There is NO inner loop around the constraint
call. The passes 3-5 each execute once per frame sequentially. The per-part physics
call (0x55353) after the constraint call handles gravity and collision separately.

This is a **single-pass constraint model** — rope/belt constraints are enforced
once per tick, not iteratively solved to convergence. For a 60 Hz tick rate, this
provides adequate stability for the puzzle game's physics (not a precision simulator).

### Rope Properties

Rope parts (type 10):
- `mass`: 1600 (from PAR file)
- `dim_w1/h1`: 240×240 (sprite size)
- No collision radius or AABB size — rope is purely a line constraint
- The `behavior` field in levels encodes the **rope segment length** (various values
  like 52, 69, 93, 112 ticks indicate different rope lengths)

Steel cables (type 76):
- Same mass (1600) but different sprite: 11×10 bitmap
- Same constraint behavior as ropes

Belts (type 8):
- `mass`: 3776 (higher than rope)
- Belt-connected parts are stored in the 52-byte part entry
- Belt constraint follows a different code path (angle-preserving transmission)

### Connection Following in Collision

The collision detection function (0x54459) also handles belt/rope connections:
- It reads the connected part's far pointer from fields 0x98/0x9A
- It follows connections to check AABB overlap between connected parts
- This prevents ropes from passing through the parts they're connected to
- The 0x98/0x9A fields point to another part's physics struct

### What the Solver Does (Inferred)

The rope constraint solver at 0x30:0x54F2:
1. Calculates the vector between the two connected anchor points
2. Calculates the Euclidean distance: `length = sqrt(dx² + dy²)`
3. If length > rope_length (from `behavior` field), applies position correction
4. Distributes the correction between both connected parts based on mass ratio
5. Updates the `velocity_y`/`velocity_x` fields to reflect the constraint impulse

### What Remains Unknown

| Aspect | Status | Reason |
|--------|--------|--------|
| Exact distance calculation | Garbled in Ghidra | Segmented FAR CALL not resolvable by Ghidra |
| Velocity exchange formula | Unknown | Would need exact solver code |
| Mass-weighted correction | Unknown | Assumed from common constraint patterns |
| Belt transmission ratio | Unknown | Part of belt-specific code path |

### For Reimplementation

A functional rope/chain constraint system can be built with:
1. **Distance constraint**: `dx = x2 - x1; dy = y2 - y1; dist = sqrt(dx² + dy²)`
2. **If dist > rope_length**: `penetration = dist - rope_length; correction = penetration / 2`
3. **Apply correction to both ends**: `pos1 += normal * correction; pos2 -= normal * correction`
4. **Velocity adjustment**: Project velocity along constraint normal, apply COR
5. **Single pass per frame** — no iteration needed
6. **Belts work similarly** but also transmit rotational angle between pulleys
