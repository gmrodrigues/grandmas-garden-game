# TIM2.EXE Code Reference

This document provides a structured reference to the TIM2.EXE codebase, organized by
subsystem. For each function, the original file offset, Ghidra address, decompiled C
code location, and key details are provided.

## Database Files

- `build/phase-12/symbol-database.json` — All known symbols (functions, data, structs)
- `build/phase-12/decompile-index.json` — Cross-references between symbols and experiments
- `build/phase-12/decompiled/` — 1,476 decompiled C files organized by subsystem

---

## 1. Physics Engine

### 1.1 Gravity Integration

**File:** `0x05361E` | **Ghidra:** `0x4E41E` | **Name:** `FUN_4bdc_2636`  
**Documented in:** E-009 | **Decompiled:** `build/phase-12/decompiled/physics/FUN_4bdc_2636.c`

Applies gravity to a single part each physics tick (60 Hz VBL-synchronized).

```
velocity_y += gravity_y  (32-bit, CWD + ADC for carry)
velocity_x += gravity_x  (32-bit, usually 0 for normal gravity)
```

**Key fields:**
- `ES:[BX+0x3A]` — gravity_y (loaded from part's physics struct)
- `ES:[BX+0x1A:0x1C]` — velocity_y (32-bit signed, lo:hi)
- `ES:[BX+0x1E:0x20]` — velocity_x (32-bit signed, lo:hi)

**Base gravity selection** (at `0x02794B`, `FUN_1a9e_7325`):

| Part Category | Base | gravity_y = base/4 | Effective (>>9) |
|-------------|------|-------------------|-----------------|
| CX < 2 | 0x1C00 (7168) | 1792 | ~3.5 px/tick² |
| CX < 6 | 0x1A00 (6656) | 1664 | ~3.25 px/tick² |
| CX < 10 | 0x1800 (6144) | 1536 | ~3.0 px/tick² |
| CX < 21 | 0x1600 (5632) | 1408 | ~2.75 px/tick² |
| CX < 121 | 0x1400 (5120) | 1280 | ~2.5 px/tick² |
| CX < 151 | 0x1200 (4608) | 1152 | ~2.25 px/tick² |
| CX >= 151 | 0x1000 (4096) | 1024 | ~2.0 px/tick² |

### 1.2 AABB Collision Detection

**File:** `0x054459` | **Ghidra:** `0x4F259` | **Name:** `FUN_4bdc_3427`  
**Documented in:** E-010 | **Decompiled:** `build/phase-12/decompiled/physics/FUN_4bdc_3427.c`

1. Reads connected part pointer from `ES:[BX+0x98:0x9A]`
2. If connected, follows the chain
3. Computes AABB extents for both parts (via `FUN_4bdc_32a7` at `0x5428B`)
4. Performs overlap test using global variables:
   - `[0x63E0] vs [0x63D0]` — part1 vs part2 X-min
   - `[0x63E2] vs [0x63DC]` — part1 vs part2 X-max
   - `[0x63E4] vs [0x63D4]` — part1 vs part2 Y-min
   - `[0x63E6] vs [0x63DE]` — part1 vs part2 Y-max
5. Overlap test: `if (x1 >= x2 OR y1 >= y2 OR t1 >= t2 OR b1 <= b2) → NO COLLISION`
6. On collision: calls `FUN_4bdc_368d` (shape test), applies position correction

### 1.3 Collision Resolution

**File:** `0x057250` area | **Documented in:** E-010

Calculates overlap between two colliding parts:
```
overlap = (pos1 - pos2) / 2 (IDIV 4)
pos_y -= overlap
velocity_y += overlap
```

Velocity clamping at threshold 0x64 (100): if velocity exceeds this, it's capped.

### 1.4 Per-Part Physics Step

**File:** `0x055353` | **Ghidra:** `0x50153` | **Name:** `FUN_31f7_13f1`  
**Documented in:** E-010 | **Decompiled:** `build/phase-12/decompiled/physics/FUN_31f7_13f1.c`

For each moving part each tick:
1. Set physics-active flags at `ES:[BX+0x0A]` (bit 6 = 0x40)
2. Skip if disabled (`ES:[BX+0x0D]` bit 5 = 0x20) or frozen (`ES:[BX+0x0F]` bit 6 = 0x40)
3. Call gravity integration at `0x5361E`
4. Call collision detection at `0x54459`
5. If collision: re-integrate gravity with new position, re-check collision

### 1.5 Main Frame Update

**File:** `0x054EAB` | **Ghidra:** `0x4FCAB` | **Name:** `FUN_4bdc_3d8c`  
**Documented in:** E-010 | **Decompiled:** `build/phase-12/decompiled/physics/FUN_4bdc_3d8c.c`

7-pass frame update, called once per VBL (60 Hz):

| Pass | EXE Offset | Action |
|------|-----------|--------|
| 0 | 0x55048 | Clear flags, terminal velocity clamp |
| 1 | 0x55090 | Per-part gravity + collision (calls 0x55353) |
| 2 | 0x550DC | Rope init (type 0x11/0x6C) |
| 3 | 0x5514A | Rope constraint solver + per-part physics |
| 4 | 0x551A4 | Alternative rope update |
| 5 | 0x551FE | Disabled/frozen cleanup |
| 6 | 0x55235 | Special parts (0x5B-0x5F) |

After all passes: `INCW [0x6873]` (tick counter)

### 1.6 Rope/Belt Constraints

**Documented in:** E-011 | **Decompiled:** `build/phase-12/decompiled/physics/FUN_4fd6_0143.c`, `FUN_406b_1e72.c`

Single-pass constraint solver called from pass 3:
```
LCALL $0x30, $0x54F2    ; rope constraint solver
```

Rope parts use `behavior` field for segment length. Connected parts via pointers at
`ES:[BX+0x98:0x9A]`. The solver enforces a distance constraint (Euclidean distance
between anchor points) in one iteration per frame.

---

## 2. Sound System

### 2.1 ADL.DRV API

**File:** `build/phase-6/adl_drv/ADL.DRV` (9,295 bytes)  
**Disassembly:** `build/phase-6/adl_drv/ADL.DRV.disasm`  
**Documented in:** E-007, E-012

**Entry point:** `0x1945` (within ADL.DRV binary)
```
MOV BP, CS:[0x1921+BP]  ; load function pointer from jump table
CALL [BP]                ; call internal function
RETF                     ; far return to game
```

**Jump table** (at ADL.DRV offset `0x1921`):

| BP | Offset | Function |
|----|--------|----------|
| 0 | 0x2446 | VersionInfo (returns AH=1, AL=3) |
| 1 | 0x2414 | LoadData (copy SX data to CS:0x374) |
| 2 | 0x1AD0 | Init (reset OPL2 + load instruments) |
| 3 | 0x1951 | NOP |
| 4 | 0x1952 | NoteOff |
| 5 | 0x1988 | NoteOn (AL=note, CH=patch, CL=velocity) |
| 6 | 0x1951 | NOP |
| 7 | 0x19CF | Controller (CH=ctrl#, CL=value) |
| 8 | 0x1A1B | ProgramChange (AL=patch#) |
| 9 | 0x1A29 | PitchWheel (CX=14-bit pitch) |

**OPL2 write function** (at ADL.DRV offset `0x208E`):
```
BX = register, CX = value
OUT 0x388 → register address (with IN AL,DX delay)
OUT 0x389 → register value (with 33× loop delay)
```

**Port configuration** (data at ADL.DRV offset `0x37`):
- `CS:[0x37]` = 0x0388 (address port)
- `CS:[0x39]` = 0x0388 (read port)
- `CS:[0x3B]` = 0x0389 (data port)

### 2.2 ADL.DRV Calling Convention in TIM2.EXE

**Entry point stored at:** `CS:[0x01ED]` (in TIM2.EXE)  
**Set by:** init function at file `0x41428`

```
MOV BP, <function_index>   ; BP = 0-11
CALL FAR CS:[0x01ED]       ; call through stored pointer
```

**Call sites confirmed at:**

| Function | BP | File Offset |
|----------|----|-------------|
| VersionInfo | 0 | 0x41431 |
| LoadData | 1 | 0x41461 |
| Init | 2 | 0x41495 |
| NoteOff | 4 | 0x41AB8 |
| NoteOn | 5 | 0x41B09 |
| Controller | 7 | 0x41BEA |
| ProgramChange | 8 | 0x41BDE |
| PitchWheel | 9 | 0x42F2A |

### 2.3 Sound Dispatch Function

**File:** `0x041C00` | **Documented in:** E-012

Sub-functions selected by CL (0x00-0x17):

| CL | Action | Description |
|----|--------|-------------|
| 0x00 | Init driver | Store entry point, call VersionInfo |
| 0x01 | Load SX data | Call ADL.DRV LoadData |
| 0x02 | Init call | Call ADL.DRV Init |
| 0x13 | NoteOff | Call ADL.DRV NoteOff |
| 0x14 | NoteOn | Call ADL.DRV NoteOn |
| 0x15 | Controller | Call ADL.DRV Controller |
| 0x16 | ProgramChange | Call ADL.DRV ProgramChange |
| 0x17 | PitchWheel | Call ADL.DRV PitchWheel |

### 2.4 Sound Processing Loop

**File:** `0x042200` | **Documented in:** E-012 | **Decompiled:** `build/phase-12/decompiled/sound/FUN_31f7_b045.c`

Processes 16 MIDI channels using event queue at `CS:[SI+0x16E]`.

Event structure:
```
[SI+0x16E] = event byte (MIDI command)
[SI+0x14E] = data byte 1 (controller number or note)
[SI+0x15E] = data byte 2 (value or velocity)
[SI+0x13E] = channel state (active/inactive)
```

For each active event, the loop calls ADL.DRV functions in sequence:
1. Controller (0x7B reset, 0x4B effect)
2. ProgramChange (select instrument)
3. Controller (volume 0x07, pan 0x0A, modulation 0x01)
4. Controller (pitch bend range 0x40)
5. PitchWheel (14-bit value)
6. NoteOn (trigger)

### 2.5 SX Patch Data Format

**File:** `build/phase-1/extracted/TIM2.SX` (194,734 bytes)  
**Documented in:** E-005, E-006, E-012

**Container:** Sierra SND/INF/DAT/TAG chunked format
- 38 patches: 14 FM (type=7) + 24 waveform (type=9)

**12-byte DAT header:**
```
[0-1] sound_id: UINT16LE
[2] type: UINT8 (7=FM, 9=waveform)
[3] mode: UINT8 (2 for FM)
[4] unknown: UINT8 (always 3)
[5-6] parameter: UINT16LE (sequence duration?)
[7-8] zero: UINT16LE (always 0)
[9-11] init: 3 bytes [0x10, 0xC6, 0x46] (ignored padding)
```

**28-byte SCI28 instrument** (FM patches):
```
op0 (13 bytes): KSL, MULT, FB, AR, SL, EGS, DR, RR, TL, AM, VIB, KSR, ALG
op1 (13 bytes): same layout
[26-27] wave_form: WF0, WF1
```

**Sequence data:** Channel state parameters (after 28-byte instrument).
- Short sequences (10-55 bytes): simple sounds with few parameters
- Long sequences (272-775 bytes): full channel configurations

### 2.6 SX.OVL Overlay

**File:** `build/phase-1/extracted/SX.OVL` (44,116 bytes)  
**Documented in:** E-012

SSM container with per-driver instrument data:

| Chunk | Size | Driver |
|-------|------|--------|
| GMD:: | 1217B | General MIDI |
| SBP:: | 3330B | Sound Blaster Pro |
| M32:: | 1208B | MT-32 |
| ADL:: | 3030B | AdLib/OPL2 instrument data |
| PRO:: | 3510B | Pro Audio Spectrum |
| PS1:: | 2716B | IBM PS/1 |
| STD:: | 1626B | PC Speaker |
| 001:: | 11749B | Code/data (largest) |

---

## 3. Level Format

### 3.1 Part Entry (48 bytes, variable)

**Documented in:** ModdingWiki, knt47/timgres, GDD section 3.4

Layout: `[40 bytes common] + [0/4/6/8 extra, belt/rope/pulley] + [8 bytes tail]`

**Entry sizes:**
- Default: 48 bytes
- Belt (type 8): 52 bytes (40 + 4 + 8)
- Rope (type 10), Steel cable (type 76): 54 bytes (40 + 6 + 8)
- Pulley (type 7): 56 bytes (40 + 8 + 8)
- Programmable ball (type 87): 60 bytes

### 3.2 Physics Struct Fields (internal)

| Offset | Name | Description |
|--------|------|-------------|
| 0x14 | pos_x | X position |
| 0x16 | pos_y | Y position |
| 0x1A | velocity_y (32-bit) | Y-velocity (lo at 0x1A, hi at 0x1C) |
| 0x1E | velocity_x (32-bit) | X-velocity (lo at 0x1E, hi at 0x20) |
| 0x22 | pos_y_fixed | Position from fixed-point conversion |
| 0x3A | gravity_y | Y-acceleration (per tick) |
| 0x3C | gravity_x | X-acceleration (per tick) |
| 0x3E | part_category | Category for gravity lookup |

### 3.3 Magic Numbers

| Magic | Format | Levels |
|-------|--------|--------|
| EF AC 13 01 | TIM2 production | 200 levels |
| EF AC 12 01 | TIM2 intermediate | 3 levels |
| EF AC 11 01 | Special format | 3 levels (HH3, HH5, HH9) |

### 3.4 Environment Block

```
INT16LE pressure        (default 67)
INT16LE gravity         (default 272, used as gravity table selector)
UINT16LE unknown_4      (always 0)
UINT16LE unknown_6      (always 0)
UINT16LE music_track    (1000-1023)
UINT16LE num_fixed      (fixed part count)
UINT16LE num_moving     (moving part count)
UINT16LE unknown_14     (always 0)
```

---

## 4. Key Data Addresses

| Address | Name | Description |
|---------|------|-------------|
| CS:[0x01ED] | adl_drv_entry_ptr | ADL.DRV entry point (segment:offset) |
| CS:[0x0010] | sx_patch_table | SX patch far pointer table (16 × 4B) |
| CS:[0x16E] | sound_event_queue | MIDI event queue per channel |
| segment 0x43C6 | channel_state | Sound channel struct (30B × 25) |
| [0x49AA] | part_count | Moving part count for physics loops |
| [0x6873] | tick_counter | Frame counter (60 Hz) |
| 0x63E0-0x63E6 | aabb_extent_part1 | Part 1 AABB extents for collision |
| 0x63D0-0x63DE | aabb_extent_part2 | Part 2 AABB extents for collision |

---

## 5. Flag Bit Definitions

**Documented in:** `scripts/lib/flags_dictionary.py`

### flags_1 (part behavior)
| Bit | Meaning |
|-----|---------|
| 0x0020 | Unknown (~5%, interactive/consumable parts) |
| 0x0040 | Meaning unclear (~3%, moving parts) |
| 0x0200 | Can flip vertically |
| 0x0400 | Can flip horizontally |
| 0x0800 | Initially in parts bin |
| 0x1000 | Moving, gravity-affected |
| 0x2000/0x4000 | Static, gravity-immune |

### flags_2 (connectors/rendering)
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

### flags_3 (electrical/fire/scenery)
| Bit | Meaning |
|-----|---------|
| 0x0001 | Has electrical plug |
| 0x0002 | Generator/outlet |
| 0x0004 | Combustible/fuse |
| 0x0008 | Unknown (~50%, common structural) |
| 0x0040 | Locked in editor |
| 0x0080 | Sizable scenery |
| 0x0100 | Unknown (~4%, mechanical parts) |
| 0x0400 | Program icon |
| 0x1000 | Scenery part |
| 0x2000 | Wall block |
| 0x8000 | Solution component |

---

## 6. Experiment Cross-Reference

| Doc | Title | Covered Functions | Covered Gaps |
|-----|-------|------------------|--------------|
| E-005 | OPL2 Register Decode | ADL.DRV API | G19 (Q-014, Q-014b) |
| E-006 | FM Sequence Hypothesis | SX loading | G19 (Q-014a) |
| E-007 | ADL.DRV Found | ADL.DRV | G19 |
| E-009 | Physics Gravity | gravity_integration, gravity_select | G11 |
| E-010 | Collision Algorithm | collision_detect, per_part_step, frame_update | G12 |
| E-011 | Rope/Belt Constraints | rope_init_pass, rope_physics_pass | G13 |
| E-012 | FM Sequence Definitive | sound_dispatch, sound_processing, adl_drv_calls | G19 (Q-014a) |

---

## 7. Decompiled Code Inventory

Total: **1,476 decompiled C files** (6.9 MB) in `build/phase-12/decompiled/`

| Subsystem | Count | Size | Example Functions |
|-----------|-------|------|-------------------|
| physics | 97 | 396K | gravity integration, collision, per-part step |
| sound | 142 | 616K | sound dispatch, ADL.DRV wrappers |
| level | 115 | 508K | level loading, part parsing |
| gfx | 28 | 112K | rendering, VBL wait |
| utility | 349 | 1.4M | timer, memory, string functions |
| misc | 745 | 3.9M | uncategorized helper functions |

*Last updated: 2026-05-27*

## 8. Flag Bit Code Evidence

Flag bit test patterns found in TIM2.EXE via static analysis:

| Bit | EXE Offset | Test Instruction | Code Context | Meaning |
|-----|-----------|-----------------|-------------|---------|
| flags_1 0x0020 | 0x53923 | `TESTB $0x20, ES:[BX+0x0A]` | If set: abs() + 0x20; if clear: abs() + 0x02 | **Physics bias toggle** (collision tolerance) |
| flags_1 0x0040 | 0x5542F | `TESTB $0x40, ES:[BX+0x0A]` | If set: skip constraint processing | **Constraint skip flag** (rope/belt init) |
| flags_3 0x0008 | 0x535C9 | `TESTB $0x08, ES:[BX+0x0F]` | If set: SUB gravity_x; if clear: ADD gravity_x | **gravity_x direction** (wind) |
| flags_3 0x0100 | Not found | No test pattern in EXE | — | Read-only metadata (mechanical marker) |
| flags_2 0x0040 | Not found | No test pattern | — | Confirmed unused |

## 9. UI Elements (G15-G18)

### 9.1 BUTTONS.json (49 frames)

| Position | Size | Frames | Type | Likely Function |
|----------|------|--------|------|----------------|
| (259,148) | 32×28 | 1-3 (3 frames) | Cycle toggle | Flip/mirror tool |
| (259,180) | 32×27 | 4-6 (3 frames) | Cycle toggle | Scale/resize tool |
| (317,151) | 48×49 | 7-9 (3 frames) | Cycle toggle | **Play/Stop/Pause** (largest, center) |
| (469,270) | 32×32 | 11-12 (2 frames) | On/off toggle | Solver toggle |
| (472,232) | 24×24 | 21-22 (2 frames) | On/off toggle | Grid snap toggle |
| (6,16)-(150,218) | 72×202 | 31-32 | Side panels | **Parts bin category tabs** (left) |
| (157,20) | 32×20 | 33 | Static | Active tool indicator |
| (590,17) | 24×15 | 34-35 | Toggle | **Show/hide parts bin** (top-right) |
| (233,28) | 64×53 | 36-38 | Cycle | File/load menu |
| (242,89) | 56×50 | 39-41 | Cycle | Level info/goal editor |

### 9.2 HANDLES.json (108 frames)

| Size | Count | Type | Likely Function |
|------|-------|------|----------------|
| 16×18-24 | 8 | Corner handles | **Drag/resize corners** |
| 24×15 | 12 | Edge handles | **Edge stretch/resize** |
| 24×24 | 14 | Corner handles | **Select box corners** |
| 32×26 | 9 | Rotation handles | **Rotate part** |
| 32×27 | 6 | Incline handle | **Incline edge adjustment** |

### 9.3 Gap Status

| Gap | Status | Basis |
|-----|--------|-------|
| G15 | ✅ | BUTTONS frame positions → function groups |
| G16 | 🟡 | No separate cursor ANM file found |
| G17 | ✅ | HANDLES frame sizes → handle types |
| G18 | ✅ | Button groups at toolbar positions |
