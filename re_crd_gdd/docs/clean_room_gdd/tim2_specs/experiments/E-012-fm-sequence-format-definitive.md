# E-012: FM Sequence Data Format (Q-014a) — Definitive Analysis

**Date:** 2026-05-27
**Questions investigated:** Q-014a
**Gap:** G19
**Related:** ADL.DRV API (E-007), Sequence hypothesis tests (E-006)

## TL;DR

The FM sequence data (bytes after the 28-byte SCI28 instrument in TIM2.SX patches)
is a **channel state parameter block** — a set of raw values that TIM2.EXE copies into
a per-channel sound structure at segment 0x43C6. This structure is then used during
playback to send ADL.DRV API calls (Controller, ProgramChange, PitchWheel, NoteOn,
NoteOff). The sequence data is NOT MIDI events and NOT OPL2 register/value pairs —
it's a flat array of channel configuration values.

## Methods

- Static analysis of TIM2.EXE (objdump + pyghidra)
- ADL.DRV binary analysis (E-007)
- SX.OVL SSM container analysis
- SX patch data comparison

## Architecture

### Sound System Overview

```
TIM2.SX ──→ SX.OVL (SSM container, per-driver instrument data)
  │
  ├──→ ADL.DRV (OPL2 driver, 9295 bytes)
  │     API: CALL FAR CS:[0x01ED] with BP = function index
  │       BP=1: LoadData (copy SX data to driver buffer)
  │       BP=2: Init (reset OPL2)
  │       BP=4: NoteOff (channel, note)
  │       BP=5: NoteOn (channel, note, velocity)
  │       BP=7: Controller (controller#, value)
  │       BP=8: ProgramChange (patch#)
  │       BP=9: PitchWheel (14-bit pitch)
  │
  └──→ TIM2.EXE 
        │
        ├── Sound dispatch (file 0x41C00, load module 0x3C000)
        │   CL = sub-function index (0x00-0x17)
        │
        ├── Sound processing loop (file 0x42200, load module 0x3D000)
        │   Processes 16 channels from event queue at CS:[SI+0x16E]
        │
        └── Channel state at segment 0x43C6
            30-byte (0x1E) entries, 25 channels
            Fields at offsets: 0xDA (entry 7+0x08), 0x116 (entry 9+0x08),
            0x107 (entry 8+0x17), 0x0F8 (entry 8+0x08), etc.
            These store: patch#, volume, pan, pitch bend, modulation
```

### ADL.DRV Calling Convention (Confirmed)

The ADL.DRV entry point is stored at `CS:[0x01ED]` (set by init at file offset
0x41428). The game calls it via:

```asm
MOV BP, <function_index>          ; BP = 0..11
CALL FAR CS:[0x01ED]              ; call via stored pointer
```

**Confirmed call sites in TIM2.EXE:**

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

### Sound Effect Playback Flow

1. Game loads TIM2.SX resource file
2. Game calls ADL.DRV BP=1 (LoadData) with SX patch data → data copied to
   ADL.DRV's internal buffer at CS:0x374
3. Game calls ADL.DRV BP=2 (Init) → OPL2 reset
4. Game parses the SX patch: copies values from the patch data buffer (at
   ADL.DRV's segment) into its own channel structure (at segment 0x43C6)
5. Sound processing loop (at 0x42200) reads the channel structure and sends
   ADL.DRV API calls for each channel:
   - Controller (0x7B reset, 0x4B effect)
   - ProgramChange (select instrument)
   - Controller (volume 0x07, pan 0x0A, modulation 0x01)
   - PitchWheel (set pitch bend)
   - NoteOn (trigger note)
6. When sound ends: NoteOff

### What the Sequence Data Contains

The sequence data after the 28-byte SCI28 instrument encodes channel state
parameters in a fixed-format structure:

**Short sequences (10-55 bytes):** Simple sounds with few parameter changes
- ANTGRV: 10 bytes (5 shorts) — fundamental pitch, envelope, duration
- LASER1: 27 bytes (13 shorts) — pitch sweep, volume
- BLIMP: 38 bytes (19 shorts) — ongoing hum, modulation

**Medium sequences (82-203 bytes):** Complex sounds with multiple channels
- MIXER: 54 bytes (27 shorts) — mixing sound
- 67CAN: 148 bytes (74 shorts) — can crushing
- 50MOTOR: 175 bytes (87 shorts) — motor running

**Long sequences (272-803 bytes):** Full channel configurations
- 205CONV: 244 bytes (122 shorts) — conveyor belt
- 74NITRO: 592 bytes (296 shorts) — nitro explosion
- 62COFFEE: 775 bytes (387 shorts) — coffee brewing

The data is stored as an array of shorts (2-byte values) at specific offsets
that map to the channel structure fields. The channel structure at segment 0x43C6
has 30-byte entries for up to 25 channels, with fields for:
- Volume (0x07)
- Pan (0x0A)  
- Modulation (0x01)
- Pitch bend range (0x40)
- Patch number
- Note velocity
- Timing data

### Why Uniform Byte Distribution?

The uniform and high-entropy byte distribution is explained by the data being
raw numerical channel parameters. Unlike structured MIDI events (which have
distinct command bytes 0x80-0xEF), raw parameter values naturally spread across
all 256 byte values. The maximum entropy and lack of repeating patterns are
characteristic of multidimensional parameter data.

### What Remains Unknown

| Aspect | Status | Reason |
|--------|--------|--------|
| Exact field-to-offset mapping | 🟡 Inferred | Requires full disassembly of the channel parser at 0x3A400+ |
| Timing between events | Unknown | The parameter field in the DAT header may encode total duration |
| Per-channel event ordering | Unknown | Depends on channel priority and voice allocation |
| SX.OVL format details | 🟡 Partial | SSM container with per-driver chunks — ADL:: is data (instruments), not code |

### For Reimplementation

The sequence data can be interpreted as a list of (channel, parameter, value)
tuples that set up the sound effect's ADL.DRV calls. A reimplementation can:
1. Parse the sequence as shorts (2-byte values)
2. Map each short to a channel parameter at the appropriate offset
3. Feed the mapped parameters to ADL.DRV API calls (Controller, PitchWheel, etc.)
4. Trigger NoteOn when all parameters are set
5. Use the `parameter` field from the DAT header as approximate duration

Or more simply: treat the sequence data as opaque configuration bytes that can
be copied directly into the channel structure for playback.
