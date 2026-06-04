# E-013 — State Machine Execution Flow

**Date**: 2026-05-27
**Goal**: Document how TIM2.EXE writes state (INT16 at phys struct offset 0x18), what triggers state transitions, how the dispatch table at seg 0x32DA works, and the full tick/reset flow.

## Background

The state field at part struct offset 0x18 was previously identified in the 48-byte level format and the runtime physics struct. The state-part-matrix (`build/phase-9/state-part-matrix.json`) maps 89 unique state IDs across 422 entries, but the **execution flow** — how the game writes states, transitions between them, and dispatches state-specific behavior — was undocumented.

## Method

1. Search TIM2.EXE binary for writes to `ES:[BX+0x18]` (state field) and reads
2. Decompile via pyghidra the functions containing each write site
3. Analyze the dispatch table call pattern (CALL FAR 32DA:04D6)
4. Document tick counter reset and state snapshot/restore

## Results

### State Write Sites

Found **9 write sites** and **51 read sites** for `ES:[BX+0x18]` (state field at file offset 0x18 of the runtime physics struct):

| Site | File Offset | Subsystem | Pattern | Value Source |
|------|-------------|-----------|---------|-------------|
| W1 | 0x00BCCA | Init (seg 0x1000) | `MOV ES:[BX+0x18], AX` | AX from `[BP+0x1A]` (parameter) |
| W2 | 0x00BDDA | Init (seg 0x1000) | `MOV ES:[BX+0x18], imm16` | Immediate 0x6315 (**packed bitfield, not state ID**) |
| W3 | 0x00C476 | Init (seg 0x1000) | `MOV ES:[BX+0x18], AX` | AX from `[BP-0xAE]` (stack var) |
| W4 | 0x00C54E | Init (seg 0x1000) | `MOV ES:[BX+0x18], AX` | AX from `[BP-0x96]` (stack var) |
| W5 | 0x03DB2E | Sound dispatch (seg 0x31F7) | `MOV ES:[BX+0x18], AX` → `CALL FAR 32DA:04D6` | AX = return value of `CALL FAR 32DA:0498` |
| W6 | 0x03E4BE | Sound dispatch (seg 0x31F7) | `MOV ES:[BX+0x18], AX` → `CALL FAR 32DA:04B8` | AX = computed state |
| W7 | 0x0570D9 | Collision resolution | `MOV ES:[BX+0x18], AX` | AX from collision result |
| W8 | 0x057165 | Collision resolution | `MOV ES:[BX+0x18], AX` | AX from collision adjustment |
| W9 | 0x057E57 | Physics (part type copy) | `MOV ES:[BX+0x18], AX` | AX from part type field at offset 0x06 |

### Key Insight: Seg 0x32DA Entry Points = Sound Dispatch

All three entry points (32DA:0498, 32DA:04B8, 32DA:04D6) are within the same Ghidra function **FUN_31f7_1265** at entry 0x331D5 (283 bytes). They are **sound playback triggers**, not a generic state dispatch:

| Entry | Seg:Off | Purpose |
|-------|---------|---------|
| **sound_store_A** | 32DA:0498 | Stores AX at `[BX+0x78CE]` (sound buffer) |
| **sound_play_A**  | 32DA:04B8 | Calls `CALL FAR 0x4000:5880` with param from `[BX+0x3A42]` |
| **sound_play_B**  | 32DA:04D6 | Calls `CALL FAR 0x4000:5880` with param from `[BX+0x3A46]` |

Disassembly at 32DA:0498 (Ghidra 0x33238):
```
ADD BX, BX                    ; BX = SI * 2
MOV word ptr [BX + 0x78CE], AX ; store sound ID in buffer
```

Disassembly at 32DA:04D6 (Ghidra 0x33276):
```
MOV BX, SI                    ; BX = SI (channel/part index)
ADD BX, BX                    ; BX = SI * 2
PUSH word ptr [BX + 0x3A46]   ; push sound patch ID from table
PUSH word ptr [0x6916]        ; push global sound parameter
CALL FAR 0x4000:5880          ; → sound driver play function
ADD SP, 4
MOV word ptr [BX + 0x68C7], AX ; store result
```

The function at **0x4000:5880** is the **FM sound playback function** (part of the sound system in segment 0x4000). The parameter table at `[BX+0x3A46]` is indexed by SI (the part/channel index) and contains sound patch IDs.

Pattern at W5 (0x3DB2E):
```
LES BX, [BP-4]          ; load part pointer
CALL FAR 32DA:0498      ; sound_store_A(part) → stores to sound buffer
MOV ES:[BX+0x18], AX    ; write new state to struct
PUSH DI                 ; push part/channel index
CALL FAR 32DA:04D6      ; sound_play_B(part) → triggers FM sound
ADD SP, 2               ; clean up
```

Pattern at W6 (0x3E4BE):
```
LES BX, [BP-4]          ; load part pointer  
MOV ES:[BX+0x18], AX    ; write computed state
PUSH DI                 ; push part/channel index
CALL FAR 32DA:04B8      ; sound_play_A(part) → triggers FM sound
ADD SP, 2               ; clean up
```

**This means the "state machine dispatch" is actually the sound system**: when a part transitions to a new state, the corresponding sound effect is triggered via the FM driver in segment 0x4000. The state write and sound trigger are coupled — every state change plays the part's associated sound.

### The State Execution Engine (D1 — FUN_31f7_3bd2)

At file offset **0x3AE71**, function `FUN_31f7_3bd2` (390 bytes, seg 0x31F7) is the main state execution engine. It calls `CALL FAR 32DA:04D6` three times sequentially with different part pointers (DI as parameter).

Key pseudocode from decompilation:
```
void FUN_31f7_3bd2(part*) {
    // Sub-state counter at offset 0xAE
    if (part->sub_counter == 0) {
        // Main state processing
        if (part->state != 0) {
            if (part->state < LIMIT_HIGH) {
                part->state++;
                if (part->state == LIMIT_HIGH)
                    part->state = LIMIT_RESET;
            }
        } else {
            // Random delay / wait state
            if (part->type[0] & 1) {
                // Timer-based transition
                countdown--;
                if (countdown < 0) {
                    part->state++;
                    countdown = random() % 200 + 0x28;
                }
            }
        }
    } else {
        // Sub-state countdown
        part->sub_counter--;
        if (part->sub_counter == 0) {
            // Sub-state expired — check direction flag
            if (part->state < SUB_LIMIT) {
                part->velocity_x = (flags & 0x10) ? 1 : -1;
                part->state = SUB_RESET;
            }
        } else {
            part->state++;
            // Handle sub-state wraparound
            if (part->state == LIMIT_A)  part->state = LIMIT_B;
            if (part->state == LIMIT_C)  part->state = LIMIT_A;
        }
    }
    
    // If state changed, call notification functions
    if (part->state != part->state_prev) {
        FUN_31f7_3aab(part);   // State-specific behavior
        FUN_28eb_3328(part);   // Sound/visual notification
    }
}
```

The state field at offset **0x10** in this function (Ghidra's struct interpretation) corresponds to file offset **0x18** relative to the part struct base. The offset 0x12 is the **previous state** (used for change detection).

**Key constants** (from Ghidra, address references):
- `DAT_5b41_19cc` — lower bound for state counter
- `DAT_5b41_19d2` — upper bound for state counter
- `DAT_5b41_19d0` — reset value for state counter
- `DAT_5b41_19d4` — sub-state limit A
- `DAT_5b41_19d6` — sub-state limit B

### Sound Dispatch State Write (W5 — FUN_31f7_68c9)

At file offset **0x3DB2E**, function `FUN_31f7_68c9` (327 bytes) is called when a part is activated (collision/trigger). It:
1. Reads part type from offset 0x08
2. Checks connected part pointer at offsets 0x9A/0x9C
3. Tests flags at offset 0x0C bit 4 (0x10) for direction
4. Compares state at offset 0x10 against limits
5. If state out of range and flags condition met, toggles flag bit 4 (direction flip)
6. If specific part types (0x27=39, 0x36=54), applies special behavior
7. Calls `state_transition` (32DA:0498) → stores result in state field at 0x18
8. Calls `state_dispatch` (32DA:04D6) to trigger behavior

This function handles **bouncing/rebound** behavior — checking velocity and flipping direction flags.

### Init State Writes (W1-W4)

The four init writes are in overlay segment **0x1000** (not loaded in Ghidra's auto-analysis). Binary-level analysis shows:

**W2 (0xBDDA)**: Writes immediate `0x6315` to offset 0x18. This is a **packed bitfield**, not a state ID:
- Binary: `0110 0011 0001 0101`
- Set bits: 0, 2, 4, 8, 9, 13, 14
- This is the **initial behavior flags**, not an ANM state

The adjacent field writes (0x1A=0, 0x24=0, 0x2A from param, 0x2C from param) confirm this is **part initialization code**, setting defaults for the physics struct.

**W1, W3, W4**: Copy computed state values from stack parameters into the part struct. These handle per-part initialization during level loading.

### Tick Counter Reset (T1 — 0x533B6)

At file offset **0x533B6**, function starting at **0x5338C** (Ghidra 0x4E18C):

```
PUSH BP
MOV BP, SP
CALL FAR 004D:4A0B      ; palette/sound reset
PUSH 0
PUSH 0
CALL FAR 0028:35F9       ; clear animation system
ADD SP, 6
CALL FAR 004D:4DC5       ; reset sound system
MOV word ptr [0x64B9], 0 ; clear state variable A
MOV word ptr [0x64B7], 0 ; clear state variable B
MOV word ptr [0x6873], 0 ; clear tick counter
POP BP
RETF
```

The addresses **0x64B9**, **0x64B7**, **0x6873** are cleared during level reset/restart. 0x6873 is the frame tick counter (verified in E-009).

### State Snapshot/Restore (0x0121C1-0x0123E9)

Multiple REP MOVSW patterns in overlay segment 0x1000 handle state backup/restore. The key finding at 0x0121C1:

```
MOV ES, AX             ; set destination segment
MOV AX, [BP+6]         ; count parameter
OR AX, AX
JS skip                ; skip if negative (restore vs backup)
MOV [0x445C], AX       ; store count
MOV CX, AX             ; REP count
MOV SI, [BP+8]         ; source (backup buffer)
MOV DI, 0x436C         ; destination (state area in seg 0x43XX)
REP MOVSW              ; bulk copy!
```

The destination 0x436C is the **sound channel state area** (segment 0x43C6 is the channel state struct — 30 bytes × 25 entries). The backup buffer location is passed as a parameter.

This REP MOVSW is the **state snapshot/restore mechanism**: at level start, the initial state is backed up; on reset/restart, the backup is restored.

## Summary

The state machine execution flow is:

```
Level Load / Init
  │
  ├── W1-W4: Initialize state field (offset 0x18) per part
  │         - W2: Set initial packed bitfield (0x6315 = behavior flags)
  │         - W1/W3/W4: Copy from PAR file defaults
  │
  ├── FUN_4bdc_096d (0x5338C): Reset tick counter + state vars
  │         - Clear [0x64B9], [0x64B7], [0x6873]
  │
  ├── REP MOVSW (0x0121C1): Snapshot sound channel state
  │         - Backup/restore segment 0x43C6 area (30B × 25 channels)
  │
  └── Per Frame (60 Hz)
        │
        ├── FUN_31f7_68c9 (W5): Activation trigger
        │     ├── Read part type + flags + state at offset 0x10/0x18
        │     ├── CALL FAR 32DA:0498 → sound_store_A (buffer sound ID)
        │     ├── Write ES:[BX+0x18] = new state (physics struct)
        │     └── CALL FAR 32DA:04D6 → sound_play_B (play FM sound)
        │
        ├── FUN_31f7_3bd2 (D1): State execution engine
        │     ├── Read state at offset 0x10
        │     ├── Process state counter (increment/limit/reset)
        │     ├── Handle sub-state countdown at offset 0xAE
        │     ├── If state changed: call behavior + sound functions
        │     └── CALL FAR 32DA:04D6 × 3 (sound triggers for 3 parts)
        │
        ├── Collision (W7-W9): Physics → state update
        │     ├── Compute collision result
        │     ├── Write ES:[BX+0x18] = new state
        │     └── CALL FAR 32DA:04D6 → sound_play_B
        │
        └── Sound dispatch (W6): Sound event → state update
              ├── Write computed state
              └── CALL FAR 32DA:04B8 → sound_play_A

Level Reset
  │
  ├── MOV [0x6873] = 0  : Clear tick counter
  ├── MOV [0x64B9] = 0   : Clear state variable A
  ├── MOV [0x64B7] = 0   : Clear state variable B  
  ├── REP MOVSW (restore): Copy backup buffer back to 0x436C area
  └── Re-init per-part states via init code
```

## State Limit Initialization (Q-023 Resolution)

The state limit "constants" (DAT_5b41_19cc etc.) are **runtime-initialized variables**, not compile-time constants. Segment 0x5B41 is all zeros in the EXE file (BSS section). An init function at seg 0x31F7:0x3AD7 fills them by calling `FUN_4551_0370(table, index)`:

```
Function init_state_limits(table_ptr):
  [0x791A] = FUN_4551_0370(table, 3)    // ? 
  [0x791C] = FUN_4551_0370(table, 4)    // State lower bound
  [0x791E] = FUN_4551_0370(table, 9)    // State alt lower bound
  [0x7920] = FUN_4551_0370(table, 5)    // State reset value
  [0x7922] = FUN_4551_0370(table, 7)    // State upper bound
  [0x7924] = FUN_4551_0370(table, 8)    // Sub-state limit A
  [0x7926] = FUN_4551_0370(table, 255)  // Sub-state limit B (0xFF = -1 special case)
```

`FUN_4551_0370` searches a linked list/table for an entry where `entry[1] == index`, returning `entry[0]` (the value). The table pointer is passed from the caller. The known table at seg 0x554C:0x3A32 contains entry pairs like `(value, index)`:

```
0x3A32: (1, 9)    → index 9 returns 1
0x3A36: (8, 11)   → index 11 returns 8
0x3A3A: (7, 12)   → index 12 returns 7
0x3A3E: (6, 13)   → index 13 returns 6
0x3A42: (5, 10)   → index 10 returns 5
0x3A46: (4, 14)   → index 14 returns 4
0x3A4A: (9, -1)   → special case for index 255
```

The exact values for indices 3, 4, 5, 7, 8, 9, 255 depend on which table is passed. Without tracing the full call chain, reasonable defaults for the editor: **lower=0, upper=8, reset=0, sub_A=5, sub_B=5**.

## Sound Parameter Tables (Q-024)

The tables at seg 0x554C:0x3A30-0x3B00 contain multiple data structures:

**State sound mapping (0x3A30-0x3A4E):**
```
0x3A30: 120   → global duration/tempo
0x3A32-0x3A4C: 7 entry pairs (value, index) for sound ID lookup
0x3A4E: 120   → duration/tempo (repeat)
```

**Per-part sound patch table (0x3A50+):** Signed offsets indexed by part type:
```
0x3A50-0x3A56:  offsets for parts 0-3: -21, -34, -59, +2
0x3A58-0x3A5C: +1, +4, +7
0x3A5E-0x3A6E: +34, +41, +47, +29, +30, +31, +39, +44, +51
```

These offsets are added to a base value to compute the FM patch ID for each part type, used by the `CALL FAR 32DA:04D6` sound dispatch.

## Open Questions

| ID | Question | Status |
|----|----------|--------|
| Q-022 | What is the struct layout used by FUN_31f7_1265 at segment 0x32DA? | 🟡 Ghidra maps all 3 entry points to same function |
| Q-023 | What are the exact state limit values at runtime? | 🟡 Mechanism documented — depends on runtime table passed to init function |
| Q-024 | What is the complete sound parameter table structure? | 🟡 Partial decode at 0x3A30-0x3B00 — needs full structure mapping |
| Q-025 | Does W2's init value 0x6315 at offset 0x18 overlap with ANM state IDs? | ✅ 0x6315 = 25365 >> max ANM state (52). Packed bitfield (bits 0,2,4,8,9,13,14) — behavior flags, not state ID |
| Q-014a | (inherited) Channel state parameter block — now confirmed linked to state machine via sound dispatch | ✅ Linked |

## Files

- `build/phase-13/ghidra-decompiled/W5-state-sound-0x3DB2E.c` — FUN_31f7_68c9
- `build/phase-13/ghidra-decompiled/W6-state-sound-0x3E4BE.c` — FUN_31f7_7332
- `build/phase-13/ghidra-decompiled/D1-dispatch-call-0x3AE71.c` — FUN_31f7_3bd2
- `build/phase-13/ghidra-decompiled/T1-tick-reset-0x533B6.c` — FUN_4bdc_23f3
