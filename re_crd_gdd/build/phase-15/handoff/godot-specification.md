# The Incredible Machine 2 — Godot Implementation Specification

**Clean-room specification.** No original game code was referenced in the creation of this document.
This spec is derived from reproducible binary analysis experiments documented in `docs/experiments/`.

## 1. Game Loop & Timing

The game runs at **60 Hz**, synchronized to the VGA vertical blank (port 0x3DA).

```
while game_running:
    handle_input()
    update_state_machines()     # Pass 0: advance state counters
    apply_gravity()             # Pass 1: velocity += gravity
    detect_collisions()         # Pass 2-3: AABB overlap + response
    enforce_constraints()       # Pass 4-6: rope/belt distance constraints
    render()                    # ANM-driven sprite rendering
    wait_for_vblank()           # 60 Hz timing
    tick_count++
```

A `tick` = 1/60 second ≈ 16.67 ms. All physics quantities are per-tick.

## 2. Part System

### 2.1 Part Struct (48 bytes in file, ~64+ bytes at runtime)

```
INT16LE part_type        // 0x00: Part type number (0-261)
UINT16LE flags_1         // 0x02: Orientation/gravity flags
UINT16LE flags_2         // 0x04: Belt/rope/scale connector flags  
UINT16LE flags_3         // 0x06: Electrical/fire/scenery flags
UINT16LE appearance      // 0x08: ANM sprite resource ID
INT16LE pad_0a           // 0x0A: Always 0
INT16LE width_1, height_1 // 0x0C-0x0E: Primary dimensions
INT16LE width_2, height_2 // 0x10-0x12: Flipped/alternate dimensions
INT16LE pos_x, pos_y     // 0x14-0x16: Position in level coordinates
INT16LE behavior         // 0x18: Rope segment length / behavior modifier
UINT16LE velocity_y_file // 0x1A: Part of velocity (runtime)
UINT16LE belt_connect    // 0x1C: Packed belt anchor (LO=cx, HI=cy)
UINT16LE belt_distance   // 0x1E: Distance between belt lines
UINT16LE pad_20          // 0x20: Always 0
UINT16LE rope_1_connect  // 0x22: Packed rope1 anchor (LO=x, HI=y)
UINT16LE pad_24          // 0x24: Always 0
UINT16LE rope_2_connect  // 0x26: Packed rope2 anchor (LO=x, HI=y)
--- variable extra (belt=52, rope=54, pulley=56, prog_ball=60 total bytes) ---
INT16LE connected_1      // -8: Index of connected part 1
INT16LE connected_2      // -6: Index of connected part 2  
INT16LE outlet_plugged_1 // -4: Index of plugged outlet part
INT16LE outlet_plugged_2 // -2: Index of plugged outlet part
```

### 2.2 Flag Semantics

**flags_1:**
| Bit | Meaning |
|-----|---------|
| 0x0020 | Physics bias toggle (2 vs 32 units on collision tolerance) |
| 0x0040 | Constraint-processing skip flag (rope/belt init) |
| 0x0200 | Can flip vertically |
| 0x0400 | Can flip horizontally |
| 0x0800 | Initially in parts bin |
| 0x1000 | Moving, gravity-affected |
| 0x2000/0x4000 | Static, gravity-immune |

**flags_2:**
| Bit | Meaning |
|-----|---------|
| 0x0001 | Belt can connect |
| 0x0002 | Belt is connected |
| 0x0004 | Rope can connect |
| 0x0008 | Second rope can connect |
| 0x0010 | Horizontally flipped |
| 0x0020 | Vertically flipped |
| 0x0080 | 1D scalable |
| 0x0100 | 2D freely scalable |

**flags_3:**
| Bit | Meaning |
|-----|---------|
| 0x0001 | Has electrical plug |
| 0x0002 | Generator/outlet |
| 0x0004 | Combustible/fuse |
| 0x0008 | gravity_x direction (wind) |
| 0x0040 | Locked in editor |
| 0x0080 | Sizable scenery |
| 0x0100 | Read-only mechanical part marker (not evaluated at runtime) |
| 0x0400 | Program icon |
| 0x1000 | Scenery part |
| 0x2000 | Wall block |
| 0x8000 | Solution component |

## 3. Physics Engine

### 3.1 Gravity

Applied each tick to parts with `flags_1 & 0x1000` (moving).

```
velocity_y += gravity_y    // 32-bit addition with CWD sign-extension
velocity_x += gravity_x    // gravity_x is typically 0, negative if flags_3 bit 3 set
position  += velocity >> 9 // fixed-point to pixel conversion (SAR 9)
```

Base gravity selected by part category:
| Category (field 0x3E) | Base | gravity_y = base/4 | Effective (>>9) |
|-----------------------|------|-------------------|-----------------|
| < 2 | 0x1C00 (7168) | 1792 | ~3.5 px/tick² |
| < 6 | 0x1A00 (6656) | 1664 | ~3.25 px/tick² |
| < 10 | 0x1800 (6144) | 1536 | ~3.0 px/tick² |
| < 21 | 0x1600 (5632) | 1408 | ~2.75 px/tick² |
| < 121 | 0x1400 (5120) | 1280 | ~2.5 px/tick² |
| < 151 | 0x1200 (4608) | 1152 | ~2.25 px/tick² |
| >= 151 | 0x1000 (4096) | 1024 | ~2.0 px/tick² |

Environment gravity (field 272 in level header) selects the category table row.

Terminal velocity clamping is applied per frame to prevent unstable speeds.

### 3.2 Collision Detection (AABB)

**Detection** (each tick, O(N²) over moving parts):
1. Compute bounding box from part position + collision dimensions
2. Four-edge AABB overlap test: `if (x1 >= x2 OR y1 >= y2 OR t1 >= t2 OR b1 <= b2) → no collision`
3. Connected parts follow linked list via fields at offsets 0x98/0x9A

**Response** (on overlap):
```
overlap_x = min(r1, r2) - max(l1, l2)
overlap_y = min(b1, b2) - max(t1, t2)
// Push apart along axis of least overlap
correction = overlap / 2  // each part moves by half
velocity is adjusted: reflected, damped by COR (coefficient of restitution)
```

Collision shape: AABB for rectangles, circle for parts with `collision_radius > 0`.

### 3.3 Constraint Solver (Rope/Belt)

Single-pass distance constraint, 3 frame passes:

```
Pass 0 (0x550DC): Initialize rope data for types 0x11 (rope) / 0x6C (cable)
Pass 1 (0x5514A): Enforce constraint + apply per-part physics
Pass 2 (0x551A4): Alternative rope update
```

Per constraint:
```
dx = target.x - part.x
dy = target.y - part.y
dist = sqrt(dx² + dy²)
if dist > behavior_field:  // behavior = segment length in pixels
    correction = (dist - behavior_field) / 2
    normal_x = dx / dist
    normal_y = dy / dist
    part.x   += normal_x * correction
    part.y   += normal_y * correction
    target.x -= normal_x * correction
    target.y -= normal_y * correction
```

Belt (type 8) and Steel Cable (type 76) share the same architecture.

## 4. State Machine

### 4.1 State Storage

State is stored as `INT16` at runtime struct offset 0x18 (file offset). There are **89 unique state IDs** across all 149 part types (see `build/phase-9/state-part-matrix.json`).

### 4.2 State Execution Engine

Executed every tick for each moving part (function at EXE 0x3AE71):

```
state_prev = state_counter

if sub_counter == 0:
    # Main state processing
    if state_counter != 0:
        if state_counter < LIMIT_LOWER:
            state_counter = LIMIT_LOWER - 1
        state_counter++
        if state_counter >= LIMIT_UPPER:
            state_counter = LIMIT_RESET
    else:
        # Zero state: random delay (60 Hz timer)
        if RNG & 1:
            countdown--
            if countdown < 0:
                state_counter++
                countdown = random() % 200 + 40
else:
    # Sub-state countdown
    sub_counter--
    if sub_counter == 0:
        # Sub-state expired — reverse direction
        vel_x = (flags & 0x10) ? 1 : -1
        state_counter = LIMIT_RESET
    else:
        state_counter++
        # Handle sub-state wraparound

# If state changed from previous, trigger behavior + sound
if state_counter != state_prev:
    execute_state_behavior(part)
    play_sound_for_state(part, state_counter)
```

**State limits** (initialized at runtime, not compile-time constants):
| Limit | Description | Typical Value |
|-------|-------------|---------------|
| LIMIT_LOWER | State lower bound | ~0-1 |
| LIMIT_UPPER | State upper bound (resets here) | ~4-20 |
| LIMIT_RESET | Value to reset to on upper bound | 0 |
| SUB_LIMIT_A | Sub-state cycle limit | ~5-8 |
| SUB_LIMIT_B | Sub-state alternate cycle | ~5-8 |

### 4.3 State Transitions

Triggered by:
1. **Collision** — `on_collision()` increments `state_counter` (capped at LIMIT_UPPER)
2. **Timer** — State execution engine advances state counter each tick
3. **Activation** — Connected parts propagate state changes (e.g., electrical → generator)

On each state change, the sound system is notified via `CALL FAR 0x4000:5880` (FM sound driver).

## 5. ANM Animation System

### 5.1 ANM File Format

```
ANM: chunked container:
  magic "ANM:" (4 bytes)
  size UINT32LE
  inner "TB" format:
    magic "TB" (2 bytes)
    version UINT16LE (1000 or 1001)
    section_sizes[4] UINT16LE  // A, B, C, D sizes
    width, height (UINT16LE each)
    Section A: UINT16LE[nFrames] tick durations
    Section B: 10-byte entries {x, y, w, h, bytecode_offset}
    Section C: 4-byte entries {first_frame_id, state_id}
    Section D: bytecode stream
```

### 5.2 State → Frame Mapping (Section C)

```
for each entry in Section C:
    if entry.state_id == current_state:
        first_frame_id = entry.first_frame_id
        break
```

### 5.3 Frame Metadata (Section B)

```
frame[x, y, width, height, bytecode_offset]
```

Position (x, y) is relative to the part's level position.

### 5.4 Bytecode (Section D)

Six opcodes, all UINT16LE:

| Cmd | Opcode | Parameters | Description |
|-----|--------|------------|-------------|
| 0 | END_FRAME | — | End current frame bytecode |
| 1 | END_ANM | — | End entire animation |
| 2 | DRAW_BMP | resource_id, sub_image, x, y, flags | Draw BMP sub-resource |
| 3 | DRAW_RECT | x, y, width, height, color, flags | Fill rectangle |
| 4 | DRAW_LINE | x1, y1, x2, y2, flags | Draw line |
| 5 | PLAY_SFX | sound_id | Play sound effect |

**DRAW_BMP flags:** bit 0 = hflip, bit 1 = vflip.
**DRAW_RECT flags:** bit 15 = absolute coordinates, bits 0-3 = draw mode.

### 5.5 Frame Timing

Section A provides tick durations per frame. The state engine's 60 Hz tick counter drives frame advancement. Each frame displays for its Section A duration (in ticks) before the next frame starts.

## 6. Audio System

### 6.1 Sound Architecture

FM synthesis via OPL2 (AdLib/YM3812). Driver: ADL.DRV (9,295 bytes) with 12-function API:

| BP | Function | Description |
|----|----------|-------------|
| 0 | VersionInfo | Returns driver version |
| 1 | LoadData | Copies SX patch data into driver buffer |
| 2 | Init | OPL2 reset + instrument initialization |
| 4 | NoteOff | Stop note on channel |
| 5 | NoteOn | Start note (AL=note, CH=patch, CL=velocity) |
| 7 | Controller | MIDI controller (CH=controller#, CL=value) |
| 8 | ProgramChange | Program change (AL=patch#) |
| 9 | PitchWheel | Pitch bend (CX=14-bit pitch value) |

OPL2 write: `OUT 0x388 = reg; OUT 0x389 = val` with appropriate delays.

### 6.2 FM Instrument Format

SCI28 (Sierra Creative Interpreter 28-byte format):
- Bytes 0-12: Operator 0 (KSL, MULT, AR, DR, SL, RR, TL, AM, VIB, KSR)
- Bytes 13-25: Operator 1 (same layout)
- Byte 26: ALG/feedback/conection
- Byte 27: Unused/volume

### 6.3 RAW Audio

Unsigned 8-bit PCM, 11025 Hz, mono, center = 128.
No header. 113 sound IDs (3001-3754).

## 7. Solution Checking

Each level has solution conditions:
```
part_index: INT16LE
part_state_1: UINT16LE  // base state
part_state_2: UINT16LE  // sub-state qualifier
part_count: UINT16LE    // not used
rect: { x, y, width, height }  // target position rectangle
```

A condition is met when:
- **Position check**: part's bounding box overlaps the target rectangle
- **Off-screen**: rect = (-1, -1, -1, -1) → part is outside viewport
- **Off-top**: rect = (-500, -2000, 1640, 2000) → part is above screen
- **Off-bottom**: rect = (-500, 400, 1640, 3000) → part is below screen

All conditions must be met simultaneously for the solution to be valid.

## 8. Level File Format

EF AC 13 01 header (or EF AC 11 01 for old format):
```
UINT32LE magic_number    // EF AC 13 01 or EF AC 11 01
UINT16LE num_parts
UINT16LE unknown_6       // always 0
UINT16LE bg_color
UINT16LE pressure
UINT16LE gravity         // 272 = standard
UINT16LE unknown_14      // always 0
UINT32LE music_track
UINT16LE num_hints
[num_hints × hint_entry]
UINT16LE num_fixed
[num_fixed × part_entry]
UINT16LE num_moving
[num_moving × part_entry]
[solution_block]
```

## Appendix A: Part Type Catalog

149 part types. Full catalog: `build/phase-9/part-name-catalog.json`.
Complete state matrix: `build/phase-9/state-part-matrix.json`.
Mass/COR/friction: `build/phase-9/part-properties.json`.
ANM cross-reference: `build/phase-9/part-anm-catalog.json`.

## Appendix B: Symbol Database

23 functions, 11 data addresses, 3 structs, 12 ADL.DRV symbols:
`build/phase-12/symbol-database.json`

Key entry points:
- Gravity integration: file 0x5361E
- Collision detection: file 0x54459
- Collision response: file 0x57250
- State execution: file 0x3AE71
- Sound dispatch: file 0x3DB2E
- OPL2 write: ADL.DRV offset 0x208E

## Appendix C: Data Sources

All experimental results are documented in `docs/experiments/`:
- E-001/R-001: Hash function
- E-002/R-002: ANM format
- E-003/R-003: SX audio container
- E-005/E-006: OPL2 / FM instrument decode
- E-007: ADL.DRV disassembly
- E-008: Flag bit analysis
- E-009: Physics gravity
- E-010: Collision algorithm
- E-011: Rope/belt constraint solver
- E-012: FM sequence format
- E-013: State machine execution
- E-014: Animation pipeline
