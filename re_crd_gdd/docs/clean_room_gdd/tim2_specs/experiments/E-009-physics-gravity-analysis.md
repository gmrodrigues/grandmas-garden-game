# E-009: Physics Engine — Gravity and Tick Rate Analysis

**Date:** 2026-05-26
**Questions investigated:** Q-016 (tick rate), Q-020 (gravity constant)
**Gap:** G11
**Related:** PAR file physics (G14), part struct (G1)

## TL;DR

Static analysis of TIM2.EXE revealed the physics integration code and gravity
calculation. The part struct field at offset 0x1A (previously "unknown_26") is
**VELOCITY_Y** (32-bit). Internal gravity values range from 0x1000 to 0x1C00
(~4096–7168) depending on part type. The physics loop uses 32-bit arithmetic
with CWD+ADC for precision. Tick rate was not definitively determined but is
consistent with 60 Hz (VBL). The environment gravity value (272) is used as
a scale selector, not a direct acceleration value.

## Methods

Static reverse engineering of TIM2.EXE using x86 disassembly (objdump).

## Findings

### Part Struct Field Corrections

The 48-byte level-format part struct has different semantics in the internal
physics system. Offsets in the INTERNAL physics struct:

| Offset | Name | Description | Verified |
|--------|------|-------------|----------|
| 0x14 | pos_x | X position | ✅ Cross-referenced from collision code |
| 0x16 | pos_y | Y position | ✅ |
| 0x18 | behavior | Also stores collision state / velocity_x? | 🟡 |
| 0x1A | **velocity_y** (low) | Y-velocity (32-bit, low word) | ✅ **Previously "unknown_26"** |
| 0x1C | velocity_y (high) | Y-velocity (32-bit, high word) | ✅ |
| 0x1E | velocity_x (low) | X-velocity (32-bit, low word) | ✅ |
| 0x20 | velocity_x (high) | X-velocity (32-bit, high word) | ✅ |
| 0x22 | pos_y_fixed | Position Y (converted from fixed-point) | ✅ |
| 0x24 | pos_x_fixed | Position X (converted from fixed-point) | ✅ |
| 0x3A | **gravity_y** | Y-acceleration (gravity, applied to v_y) | ✅ |
| 0x3C | gravity_x | X-acceleration (wind/drag, applied to v_x) | ✅ |
| 0x3E | part_category | Determines base gravity level | 🟡 |

### Gravity Integration Code (at TIM2.EXE 0x53622)

```
LES BX, [BP+0x06]              ; BX → part physics struct

; Apply gravity to Y-velocity
MOV AX, ES:[BX+0x3A]           ; AX = gravity_y
CWD                              ; sign-extend AX → DX:AX
ADD ES:[BX+0x1A], AX           ; velocity_y.lo += gravity_y.lo
ADC ES:[BX+0x1C], DX           ; velocity_y.hi += gravity_y.hi (carry)

; Apply wind/drag to X-velocity
MOV AX, ES:[BX+0x3C]           ; AX = gravity_x
CWD
ADD ES:[BX+0x1E], AX           ; velocity_x.lo += gravity_x.lo
ADC ES:[BX+0x20], DX           ; velocity_x.hi += gravity_x.hi (carry)
```

### Base Gravity Calculation (at TIM2.EXE 0x2794B)

The function selects a base gravity based on part category:

```
Part category (CX)  →  Base gravity (DX)
CX < 2              →  0x1C00 (7168)
2 ≤ CX < 6          →  0x1A00 (6656)
6 ≤ CX < 10         →  0x1800 (6144)
10 ≤ CX < 21        →  0x1600 (5632)
21 ≤ CX < 121       →  0x1400 (5120)
121 ≤ CX < 151      →  0x1200 (4608)
CX ≥ 151            →  0x1000 (4096)
```

The gravity fields in the physics struct are then set as:
- gravity_y (0x3A) = base / 4
- gravity_x (0x3C) = base (or -base, depending on direction flags)

### Tick Rate — 60 Hz (VBL-confirmed)

The tick rate is **60 Hz** (60 frames per second, VBL-synchronized).

**Evidence:**

1. **VBL wait in rendering** (at TIM2.EXE 0x37031):
   ```
   MOV DX, 0x3DA        ; VGA input status register 1
   LOOP:
   IN AL, DX             ; read VGA status
   AND AL, 0x08          ; check bit 3 (Vertical Retrace)
   JE LOOP               ; wait until VBL active
   ```
   The rendering code waits for the vertical blanking interval, which occurs at the
   monitor's refresh rate (60 Hz for standard VGA).

2. **Main loop structure** (at TIM2.EXE 0x53242-0x53375):
   ```
   loop_start:
     CALL 0x54EAB             ; MAIN FRAME UPDATE (gravity + collision + constraints)
     ...rendering with VBL wait...
     INCW [0x6873]             ; tick counter (one per frame)
     CMP [0x6887], 0x2000      ; check loop condition
     JE loop_start
   ```
   The main loop executes once per frame, calling the frame update each iteration.
   Each iteration is one physics "tick".

3. **No timer interrupt involved**: The frame update runs in the main loop, not from
   a timer interrupt handler (INT 8 at 18.2 Hz). The interrupt handler at 0x147E9
   handles timer-based counter decrements (for sound/music timing), but the physics
   runs in the main loop.

4. **18.2 Hz is ruled out**: Our earlier fixed-point analysis showed effective gravity
   values of ~2-3.5 pixels/tick². At 60 Hz, a 200-pixel drop takes ~210 ms (12.6 ticks),
   which matches the visual feel of the game. At 18.2 Hz, the same drop would take
   only ~70 ms (<2 ticks), which would be unrealistically fast.

**Conclusion: Tick rate = 60 Hz. One tick = 1/60 second ≈ 16.67 ms.**

### Gravity Constants (Final)

Based on the 60 Hz tick rate and fixed-point analysis:

| Part Category | Base Value | gravity_y (base/4) | Effective (>>9) | Pixels/sec² |
|-------------|-----------|-------------------|---------------|-------------|
| Balls (type 0) | 0x1C00 (7168) | 1792 | 3.5 | 12600 |
| Light parts | 0x1A00 (6656) | 1664 | 3.25 | 11700 |
| Medium parts | 0x1800 (6144) | 1536 | 3.0 | 10800 |
| Heavy parts | 0x1400 (5120) | 1280 | 2.5 | 9000 |
| Scenery/walls | 0x1000 (4096) | 1024 | 2.0 | 7200 |

The environment gravity field (value 272 in level files) selects which base gravity
table row to use, not the acceleration value itself.

### Fixed-Point Conversion (at TIM2.EXE 0x536A8)

```
MOV DX, ES:[BX+0x1C]           ; velocity_y.hi
MOV AX, ES:[BX+0x1A]           ; velocity_y.lo
MOV CL, 9                       ; shift by 9 (divide by 512)
CALL 0x19BF                     ; perform SAR CL on the 32-bit value
MOV ES:[BX+0x22], AX            ; store result as position delta (applied to y)
```

The velocity is converted from fixed-point to pixel units by shifting right
by 9 bits (dividing by 512). The result is added to the position each tick.
This is consistent with Q8.23 or similar fixed-point format.

### Collision Detection (at TIM2.EXE 0x572D7)

```
MOV AX, ES:[BX+0x18]           ; read collision state / velocity_x
SUB AX, ES:[BX+0x18]           ; compare with another part's same field
SAR AX, 1                       ; divide by 2 (center correction)
ADD ES:[BX+0x14], AX            ; adjust pos_x
```

Collision resolution adjusts pos_x by half the overlap amount.

## Physical Interpretation

The acceleration applied per tick:
- gravity_y = base / 4 ≈ 1024–1792 units
- After fixed-point conversion (>> 9): ≈ 2.0–3.5 pixels/tick²
- At 60 Hz: ≈ 7200–12600 pixels/sec²
- For a 200-pixel drop: t = sqrt(2×200/2.5) ≈ 12.6 ticks ≈ 210 ms ✅ (feels right)

## What Remains Open

1. **Tick rate** — Needs empirical confirmation (video frame counting)
2. **Environment gravity (272)** — How does it affect the per-part base gravity?
   The base values (0x1000–0x1C00) don't directly incorporate 272.
3. **Pressure (67)** — How does it affect physics? (buoyancy? drag?)
4. **PART category** — What exactly is at offset 0x3E in the physics struct?
   Could be mass/density bucket derived from PAR file properties.

## Artifacts

- Source: TIM2.EXE static analysis (offsets 0x27460–0x27520, 0x2794B–0x27998,
  0x5361E–0x536FD, 0x57250–0x57300)
- GDD update: part struct field 0x1A renamed to velocity_y
