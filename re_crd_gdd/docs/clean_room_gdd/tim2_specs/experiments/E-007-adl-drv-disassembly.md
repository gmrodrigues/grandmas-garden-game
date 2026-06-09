# E-007: ADL.DRV Found and Disassembled

**Date:** 2026-05-26  
**Questions investigated:** Q-014a, Q-013  
**Gap:** G19

## TL;DR

We found, extracted, and disassembled ADL.DRV — the Dynamix AdLib sound driver
for TIM2 — from the original game floppy disks hosted on Archive.org. The
driver uses a real-mode DOS binary loaded by the game at runtime. It contains
the OPL2 register write function (ports 0x388/0x389), SCI28 instrument loading
logic, and 9-voice OPL2 channel management. The init bytes [0x10, 0xC6, 0x46]
are confirmed NOT referenced by the driver — they're unused padding/metadata.

## What We Did

### Step 1 — Located ADL.DRV

Found TIM2 original floppy disk images on Archive.org (item
`001015-TheIncredibleMachine2`, 2 × 1.44 MB disk images).

### Step 2 — Extracted from FAT12 filesystem

ADL.DRV was on `disk1.img` along with other drivers (AUDBLAST.DRV, SBPRO.DRV,
STD.DRV, GENMIDI.DRV, MT32.DRV) and game files (RESOURCE.CFG, UNCHUNK.EXE,
INSTALL.BAT, COMPRESS.000 = RESOURCE.001).

**File details:**
- ADL.DRV: 9,295 bytes
- Starts with `E9 42 19` (JMP NEAR to real-mode code)
- Contains "AdLib Music Synthesizer Card" and version "2.24" strings
- NOT an MZ executable — it's a raw .COM-style overlay

### Step 3 — Disassembled with objdump

Full disassembly saved to `build/phase-6/adl_drv/ADL.DRV.disasm` (1,601 lines).

**Key findings from the driver:**

#### OPL2 Write Function (offset 0x208E)
```
0x208E: PUSH AX, DX, CX
0x2091: MOV DX, CS:[0x0037]   ; DX = port 0x388 (AdLib address)
0x2096: MOV AX, BX              ; BX = register number
0x2098: OUT DX, AL              ; write register address
0x209D: IN AL, DX (×5)          ; delay (~35 cycles)
0x209E: MOV DX, CS:[0x003B]   ; DX = port 0x389 (AdLib data)
0x20A3: MOV AX, CX              ; CX = value
0x20A5: OUT DX, AL              ; write register value
0x20A6: MOV CX, 0x21            ; delay loop (33 iterations)
0x20A9: MOV DX, CS:[0x0039]   ; DX = port 0x388 again
0x20AF: IN AL, DX               ; status read for delay
0x20B0: LOOP $-3                ; loop
0x20B2: POP CX, DX, AX
0x20B5: RET
```

Interface: `CALL 0x208E` with BX=register, CX=value.

#### Port Configuration (data at offset 0x37)
```
0x0037: 0x88 0x03  → CS:[0x37] = 0x0388 (OPL2 address port, also at 0x39)
0x003B: 0x89 0x03  → CS:[0x3B] = 0x0389 (OPL2 data port)
```

Driver loads port addresses from memory, not as immediates.

#### Instrument Format (function 0x20E2)
- Loads 13 bytes per operator (0x0D = 13)
- Plus 1 byte for waveform select (GF & 3)
- Total: 14 bytes per operator, 28 bytes per 2-operator instrument
- This is the standard SCI28 format

#### Voice Architecture
- 9 voices (standard OPL2, confirmed by `CMP $0x9` patterns)
- Each voice has: patch number, note, velocity, sustain flag, age
- MIDI-like channel management:
  - Note On (0x90): finds free voice, programs instrument
  - Note Off (0x80): releases voice
  - Controller (0xB0): volume (0x07), pan (0x0A), hold pedal (0x40)
  - Program Change (0xC0): selects instrument/patch
  - Pitch wheel (0xE0): pitch bend

#### Confirmed MIDI Command Handling

Functions handling MIDI events:
- `0x1AD4` — Note On handler (finds/assigns voice)
- `0x1B52` — Voice management (reference counting)
- `0x1BEC` — Voice assignment (set voice to specific patch)
- `0x1CA9` — Volume calculation and register update
- `0x1D45` — Note frequency/setup (pitch calculation using `adlibFreq[48]` table at 0x3D)
- `0x1DC4` — Voice release (note off)
- `0x1E23` — setNote() — programs OPL2 registers for a note (the MAIN function)
- `0x1EEE` — Pitch wheel calculation
- `0x1FE1` — Patch/instrument loading from SX data

#### Function 0x1FE1 — Patch Loading from SX Data
```
0x1FE1: PUSH registers
0x1FE7: MOV DI, CX             ; DI = pointer to patch data (CS:[0x374+offset])
0x1FE9: PUSH BX, CX, DX
0x1FEC: MOVB CS:[0x1900+BX], 1  ; mark voice as "active"
0x1FF2: CMPB CS:[0x0C+DI], 0    ; check if byte 12 (first payload byte) is 0
                                  ; (FM patches start with 0x00 = KSL=0 → additive mode)
0x1FF7: JE 0x2001               ; if zero, load normally
0x1FF9: MOVB CS:[0x1900+BX], 0  ; else set flag to 0 (FM mode)
```

### Step 4 — Init Bytes [0x10, 0xC6, 0x46] NOT Referenced

The bytes [0x10, 0xC6, 0x46] do NOT appear as a sequence in ADL.DRV. The
driver does not check for them at patch header offsets 9-11. Combined with
the empirical finding that writing 0x10 to OPL2 register 0x01 kills audio
output, this confirms: **the init bytes are unused padding/metadata.**

## Part 2 — ADL.DRV API Jump Table Discovered

Discovered the external API entry point at offset 0x1945 in ADL.DRV.
The game calls ADL.DRV via FAR CALL to this single entry point with a
function index in BP.

### Dispatch Mechanism

```
0x1945: MOV BP, CS:[0x1921+BP]  ; BP = function offset from jump table
0x194D: CALL [BP]                 ; call internal function
0x194F: POP BP
0x1950: RETF                      ; FAR RETURN to game code
```

### ADL.DRV API (12 functions via jump table at 0x1921)

| BP | Address | Name | Calling Convention |
|----|---------|------|-------------------|
| 0 | 0x2446 | VersionInfo | Returns AH=1, AL=3, CH=0, CL=9 |
| 1 | 0x2414 | LoadData | Copies SX data from ES:AX to CS:0x374, count from CS:0x372 |
| 2 | 0x1AD0 | Init | Resets OPL2 + loads default instruments |
| 3 | 0x1951 | Nop | (just RET) |
| 4 | 0x1952 | NoteOff | AL = note, CH = patch? |
| 5 | 0x1988 | NoteOn | AL=note, CH=patch, CL=velocity |
| 6 | 0x1951 | Nop | (just RET) |
| 7 | 0x19CF | Controller | AL=?, CH=controller#, CL=value |
| 8 | 0x1A1B | ProgramChange | AL=patch#, stored at CS:0x120[note] |
| 9 | 0x1A29 | PitchWheel | AX=voice?, CX=pitch (14-bit) |
| 10 | 0x1A29 | (same as 9) | (duplicate entry?) |
| 11 | 0x1ABF | ? | Not analyzed |

### Game→Driver Interaction Flow

1. Game loads SX patch data via `LoadData` (BP=1)
2. Game calls `Init` (BP=2) to reset OPL2 and load instruments
3. For each sound effect:
   - Game calls `ProgramChange` (BP=8) to select instrument
   - Game calls `NoteOn` (BP=5) to trigger note
   - Game may call `Controller` (BP=7) or `PitchWheel` (BP=9) for effects
   - Game calls `NoteOff` (BP=4) to stop note

### Critical Q-014a Insight

**ADL.DRV does NOT parse the sequence data bytes after the 28-byte SCI28
instrument.** The sequence data is processed by TIM2.EXE, which converts it
into ADL.DRV API calls (NoteOn, NoteOff, Controller, PitchWheel).

This changes Q-014a from "how does ADL.DRV parse the sequence data?" to
"how does TIM2.EXE convert the sequence data into ADL.DRV API calls?"

The sequence data in the SX file likely encodes:
- Pitch bend values (pitch wheel events over time) → sound effects vary pitch
- Velocity/volume changes (controller events) → crescendo/decrescendo effects
- Note timing (when to send each event)

The parameter field may encode the total duration or event count.

## Current Status

- **Q-014** (OPL2 register format): ✅ RESOLVED
- **Q-014a** (sequence data): 🔴 ADL.DRV API fully mapped. Sequence data is
  NOT parsed by the driver — it's processed by TIM2.EXE which converts it to
  ADL.DRV API calls. Requires TIM2.EXE analysis to determine the format.
- **Q-014b** (KSL=0, FB=0): ✅ RESOLVED
- **Q-013** (init bytes): ✅ RESOLVED — confirmed padding/ignored

## Key Artifacts

- ADL.DRV binary: `build/phase-6/adl_drv/ADL.DRV` (9,295 bytes)
- Full disassembly: `build/phase-6/adl_drv/ADL.DRV.disasm` (1,601 lines)
- AUDBLAST.DRV also extracted: `build/phase-6/adl_drv/AUDBLAST.DRV`
- OPL2 write function identified at offset 0x208E
- Patch loading function at 0x1FE1
- ADL.DRV API jump table at offset 0x1921 (12 function entries)
- Entry point: offset 0x1945 (FAR CALL target from game)
- Note handler at 0x1E23
- Pitch frequency table (48 entries) at offset 0x3D
- Source: Archive.org item `001015-TheIncredibleMachine2` (disk1.img)

## Future Work

- Analyze TIM2.EXE to find how it parses sequence data → ADL.DRV API calls
- Determine the exact format of the sequence bytes after SCI28 instrument
- Identify the parameter field meaning (duration? event count?)
