# E-003: sx-audio

**Date:** 2026-05-26
**Questions investigated:** Q-009, Q-010, Q-011, Q-012
**Gap:** G19 (SX chunk format), G20 (RAW sample format)

## TL;DR

Decoded the TIM2.SX container as a Sierra SND chunked format with INF/DAT/TAG sections. Found 38 patches (14 FM type-7, 24 waveform type-9) indexed by a 6-byte-per-entry INF table. Identified 113 RAW files as unsigned 8-bit PCM centered at 128. OPL2 register programming format and RAW sample rate remain open.

## Goals

1. ✅ Determine the overall container format of TIM2.SX
2. ✅ Parse the INF index and identify how instruments are catalogued
3. ✅ Decode the DAT patch header (common fields across FM and waveform types)
4. ✅ Catalogue all instruments (count, types, names)
5. ✅ Determine the RAW audio encoding (signed/unsigned, bit depth)
6. 🟡 Identify the OPL2 register programming format within FM DAT payloads
7. 🟡 Determine the RAW sample rate

## Pre-session state

- Phase 1 extraction complete: TIM2.SX (194,734 bytes) and 113 RAW files extracted
- Existing `sx-report.json` only reported "SND: chunk detected, format TBD"
- The plan mentioned TIM2.SX as an OPL2 FM patch container but the format was unknown

## Hypothesis

TIM2.SX uses the same Sierra chunked container format seen in BMP, PAL, and ANM files (4-char tag + UINT32LE size). The SND: header contains a file-level preamble, followed by an index (INF:), per-patch data (DAT:), and a name table (TAG:). RAW files are unsigned 8-bit PCM with no header.

## Session log

### Step 1 — Scan for chunk tags

Scanned TIM2.SX for all 4-char tags ending with ':'. Found: SND: (1), INF: (1), DAT: (38), TAG: (1). This confirmed the Sierra chunked container pattern.

### Step 2 — Parse INF chunk

INF data is 233 bytes. Tried various entry sizes. `5 + 38 × 6 = 233` — perfect fit. Header: UINT16LE version=2, UINT16LE count=38, UINT8 type=3. Entries: UINT16LE sound_id + UINT32LE file_offset.

Cross-referenced INF entries with DAT chunk offsets — all 38 offsets point precisely to DAT: tag starts. Confirmed.

### Step 3 — Parse DAT patch headers

All 38 patches share a 12-byte common header: UINT16LE sound_id, UINT8 type (7=FM, 9=waveform), UINT8 mode (2=FM, 3=waveform), UINT8 unknown (always 3), UINT16LE parameter, UINT16LE zero, 3 init bytes (10 C6 46).

FM patches (type 7): 14 patches, IDs 5–205, sizes 62–843 bytes. Sound effects like convey, FAN, MOTOR, COFFEE, LASER1.

Waveform patches (type 9): 24 patches, IDs 1000–1023, sizes 1012–17362 bytes. Background music tracks (newtim2, unpluggd, enya, etc.).

### Step 4 — Parse TAG name index

TAG chunk at end of file: UINT16LE count=38, then pairs of UINT16LE sound_id + NUL-terminated ASCII name. Confirmed all 38 names match their sound IDs (e.g., 5=convey, 24=FAN, 1000=newtim2).

### Step 5 — Analyze RAW files

113 RAW files (SX_3001.RAW through SX_3754.RAW). All show:
- No header bytes (data starts immediately with audio samples)
- Byte range approximately 5–234, center value ~128
- Unsigned 8-bit PCM encoding confirmed

Small files (2,304 bytes for SX_3500, SX_3600) show very few unique values (4–6), suggesting short looped samples. Larger files (11,609+ bytes) show more variation, consistent with longer sound effects.

### Attempt 1 — SND header interpretation (PARTIAL)

The 4 bytes after SND: are `A6 F8 02 80`. Two interpretations: UINT16LE pair (63654, 32770) or UINT32LE (0x8002F8A6). Neither produces a clean interpretation. This preamble likely encodes a version/type word and a flag byte, but the exact meaning is open.

## Breakthrough

The INF entry format (`5-byte header + 38 × 6-byte entries = 233 bytes`) was the key. Once it fit perfectly, cross-referencing with DAT offsets confirmed the entire container structure. The TAG chunk at the end of the file provided human-readable names for all 38 patches, removing any ambiguity about which sound ID maps to which instrument.

## Validation

```bash
$ python3 scripts/phase-6/01-analyse-sx.py
[INFO]  TIM2.SX: 194,734 bytes
[INFO]  Found 40 top-level chunks
[INFO]  INF: version=2, count=38, type_byte=3
[INFO]  Parsed 38 DAT patches
[INFO]  Parsed 38 TAG name entries
[INFO]  Remaining bytes after last chunk: 0
[INFO]  Found 113 RAW sample files
[INFO]  FM patches: 14, Waveform patches: 24
[OK]    sx-report written
```

All 38 DAT patches parsed, all TAG names matched, zero remaining bytes after last chunk, 113 RAW files catalogued.

## New questions raised

- Q-013: What do the 4 SND: preamble bytes (A6 F8 02 80) encode?
- Q-014: How are OPL2 registers encoded in FM patch payloads (after the 12-byte header)?
- Q-015: What sample rate are the RAW files? (Likely 11025 Hz but unconfirmed)

## Artifacts

- Script: `scripts/phase-6/01-analyse-sx.py`
- Output: `build/phase-6/sx-report.json`