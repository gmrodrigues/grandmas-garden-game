# R-003: sx-audio

**Date:** 2026-05-26
**Experiments:** E-003
**Questions closed:** Q-009, Q-010, Q-011, Q-012

## TL;DR

TIM2.SX is a Sierra SND chunked container with 38 instrument patches indexed by an INF table. 14 are OPL2 FM (sound effects, IDs 5–205), 24 are digital waveform (background music, IDs 1000–1023). A TAG chunk provides human-readable names. 113 separate RAW files are unsigned 8-bit PCM with no header. OPL2 register programming format and RAW sample rate remain open.

## Goals

1. ✅ Determine the overall container format of TIM2.SX — Sierra SND/INF/DAT/TAG chunked container
2. ✅ Parse the INF index — 5-byte header + 38 × 6-byte entries (sound_id + file_offset)
3. ✅ Decode the DAT patch header — 12 common bytes (sound_id, type, mode, unknown, parameter, zero, init)
4. ✅ Catalogue all instruments — 14 FM + 24 waveform with names from TAG
5. ✅ Determine the RAW audio encoding — unsigned 8-bit PCM, center=128, no header
6. 🟡 Identify OPL2 register programming format — still open (Q-014)
7. 🟡 Determine RAW sample rate — still open (Q-015)

## Background

Gap G19 (SX chunk format) and G20 (RAW sample format) were listed as open in the GDD. The only prior analysis was `build/phase-6/sx-report.json` which reported "SND: chunk detected, format TBD". Sound IDs < 300 reference TIM2.SX patches, while IDs >= 3000 reference RAW files. Understanding both formats is required for audio playback in a reimplementation.

## Method

1. Hex dumped TIM2.SX first 128 bytes, identified SND: header and INF: chunk
2. Parsed INF as 5-byte header + N × 6-byte entries, found perfect fit (5 + 38 × 6 = 233)
3. Cross-referenced INF offsets with DAT chunk positions — all 38 match
4. Analyzed DAT patch headers: 12-byte common prefix with type byte distinguishing FM (7) from waveform (9)
5. Parsed TAG name index: count + pairs of (sound_id, NUL-terminated string)
6. Analyzed 113 RAW files for encoding patterns (byte range, center value, unique values)
7. Wrote `scripts/phase-6/01-analyse-sx.py` with idempotent output to `build/phase-6/sx-report.json`

## Discovery

### TIM2.SX container format

| Chunk | Purpose | Structure |
|-------|---------|-----------|
| `SND:` | File header | 4-byte preamble (`A6 F8 02 80`) — meaning TBD |
| `INF:` | Instrument index | `version(UINT16LE)=2` + `count(UINT16LE)=38` + `type(UINT8)=3` + `count × {UINT16LE sound_id, UINT32LE offset}` |
| `DAT:` | Per-patch data | `UINT16LE sound_id` + `UINT8 type` + `UINT8 mode` + `UINT8 unknown` + `UINT16LE parameter` + `UINT16LE zero` + `UINT8[3] init` + instrument data |
| `TAG:` | Name index | `count(UINT16LE)` + `count × {UINT16LE sound_id, NUL-terminated ASCII name}` |

### DAT patch types

| Type | Mode | Count | ID range | Typical size | Content |
|------|------|-------|----------|-------------|---------|
| 7 | 2 (FM) | 14 | 5–205 | 62–843 | OPL2 register programming |
| 9 | 3 (waveform) | 24 | 1000–1023 | 1,012–17,362 | Digital audio samples |

The 3 init bytes (`10 C6 46`) are consistent across all 38 patches — likely OPL2 register writes for base frequency/timbre.

### RAW files

113 files, IDs 3001–3754, unsigned 8-bit PCM, no header, center value 128 (0x80). Short files (~2,304 bytes) show 4–6 unique values (looped tones); longer files show natural audio distribution.

**Source:** `scripts/phase-6/01-analyse-sx.py` → `build/phase-6/sx-report.json`

## False starts

### Attempt 1 — SND: as a chunk with UINT32LE size
The SND: "size" field read as 0x8002F8A6, which is too large for the file. SND: is actually a file-level header with a special 4-byte preamble, not a standard Sierra chunk. The real chunks start at offset 8 (INF:).

### Attempt 2 — INF entries as UINT16+UINT32 with 4-byte header
Initially tried a 4-byte header (2 bytes version + 2 bytes count). The remaining 229 bytes don't divide evenly by 38. A 5-byte header (version + count + type_byte) gives exactly 228 = 38 × 6 bytes. The type_byte (0x03) was the missing piece.

## Validation

```
[INFO]  Found 40 top-level chunks (SND + INF + 38 DATs + TAG)
[INFO]  INF: version=2, count=38, type_byte=3
[INFO]  Parsed 38 DAT patches (14 FM + 24 waveform)
[INFO]  Parsed 38 TAG name entries
[INFO]  Remaining bytes after last chunk: 0
[INFO]  Found 113 RAW sample files
[OK]    sx-report written
```

Zero remaining bytes confirms the container is fully parsed.

## Questions closed

- Q-009: What is the overall container format of TIM2.SX? → Sierra SND/INF/DAT/TAG chunked container with 4-chunk types
- Q-010: How are instruments indexed in TIM2.SX? → INF chunk with 5-byte header + 38 × 6-byte entries (sound_id + file_offset)
- Q-011: What are the DAT patch header fields? → 12 common bytes: sound_id, type, mode, unknown, parameter, zero, init[3]; type=7 for FM, type=9 for waveform
- Q-012: What encoding are the RAW sound files? → Unsigned 8-bit PCM, no header, center=128, 113 files with IDs 3001–3754

## Cold takeaways

1. **When a "chunk header" gives an impossible size, it's a file-level preamble, not a chunk.** The SND: bytes aren't a standard Sierra chunk — they're a file header. Real chunks start after it.
2. **Test header sizes by division.** When you know the entry count (38) and the total data size, try different header sizes until `(total - header) % count == 0`. The 5-byte header was found this way.
3. **Cross-reference indexes against data offsets.** The INF offsets pointing exactly to DAT: tag starts was the confirmation that the entry format was correct.
4. **TAG chunks are gold mines.** The NUL-terminated ASCII names in TAG eliminated any ambiguity about which sound ID maps to which instrument.
5. **Byte-value statistics reveal encoding.** Center ≈ 128 with range 5–234 in RAW files is the signature of unsigned 8-bit PCM.

## References

- Source: `build/phase-1/extracted/TIM2.SX` (194,734 bytes)
- Source: `build/phase-1/extracted/SX_*.RAW` (113 files)
- Script: `scripts/phase-6/01-analyse-sx.py`
- Output: `build/phase-6/sx-report.json`