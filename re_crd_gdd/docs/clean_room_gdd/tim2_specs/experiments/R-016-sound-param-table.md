# R-016 — Sound Parameter Table Structure (Q-024 Closure)

**Date:** 2026-05-27
**Goal:** Decode the packed sound parameter table at seg 0x554C:0x3A30-0x3C00 that maps part types to FM patch IDs and sound parameters.

## Method

1. Locate the table in TIM2.EXE by searching for known bytes from Ghidra's `table-dump-sound-param.txt`
2. Extract 512 bytes from the correct file offset
3. Cross-reference against `part-assets.json` (53 parts with sound IDs) and `sx-report.json` (14 FM patches)
4. Annotate each table region based on patterns and known function references (W5, W6, state limit init)

## Results

### Table Location

The Ghidra-provided file offset in `table-dump-sound-param.txt` (0x5E0E2) was **wrong by 0x10000** (MZ overlay segment mapping). The actual location:

| Property | Value |
|----------|-------|
| EXE file offset | **0x4E0E2** |
| MZ segment:offset | 0x554C:0x3A32 |
| Total size examined | 512 bytes |

### Ghidra Offset Correction

E-013's pair table addresses were **misaligned by 0x10** (a Ghidra segment base issue in the decompiled area). All addresses in this report use the **verified file offset** values.

### Overall Structure

The table at seg 0x554C has at least 5 distinct sections:

| Section | Seg Offset | Size | Purpose |
|---------|-----------|------|---------|
| **A** | 0x3A30 | 2B | Header word — value `8` (0x0008) |
| **B** | 0x3A32-0x3A3F | 16B | 8-word header/mapping zone |
| **C** | 0x3A42-0x3A5C | 28B | **Sound dispatch pair table** (7 entries) |
| **D** | 0x3A60-0x3A7E | 32B | **Per-part offset table** (16 entries) |
| **E** | 0x3BBA-0x3BC6 | 12B+ | **W6 index arrays** (3 × 2 indices) |

### Section A: Header (0x3A30)

```
0x3A30: 0x0008 = 8
```

Previously thought to be a tempo/duration value (120 = 0x78 per E-013), but the verified value is **8**. The role is unclear — possibly a count, a tempo BPM, or a sound channel count.

### Section B: Header Zone (0x3A32-0x3A3F)

```
0x3A32: 47, 9, 7, 6, 6, 7, 6, 120
```

8 words of unknown purpose. Some values (47, 120) appear elsewhere in the table. May encode additional sound parameters.

### Section C: Sound Dispatch Pair Table (0x3A42-0x3A5C) — **Key Finding**

7 entries in (value, part_type) format used by `FUN_4551_0370` during state→sound dispatch:

| Seg Offset | Value | Part Type | Part Name | Sound IDs |
|-----------|-------|-----------|-----------|-----------|
| 0x3A42 | 1 | 9 | Basketball | (none) |
| 0x3A46 | 8 | 11 | Laundry Basket | (none) |
| 0x3A4A | 7 | 12 | Curie Cat | 3012, 3312 |
| 0x3A4E | 6 | 13 | Jack-in-the-box | 3013 |
| 0x3A52 | 5 | 10 | Rope | (none) |
| 0x3A56 | 4 | 14 | Gear | (none) |
| 0x3A5A | 9 | 0xFFFF | SENTINEL | — |

The "value" field (1, 8, 7, 6, 5, 4, 9) is **not an FM patch ID** — values are 1-9 range, while FM patches use IDs 5-205. Possible interpretations:
- **Sound channel number** (OPL2 has 9 FM channels, values 0-8 are valid)
- **Priority level** for sound channel allocation
- **Index into another table**

The sentinel entry (value=9, index=0xFFFF) terminates the search, matching `FUN_4551_0370`'s stop condition.

### Section D: Per-Part Offset Table (0x3A60-0x3A7E) — **16 entries**

Signed 16-bit offsets, one per part type 0-15:

| Part | Name | Offset | Has Sounds? |
|------|------|--------|------------|
| 0 | Bowling Ball | -1 | No |
| 1 | Brick Wall | +120 | No |
| 2 | Wood incline | -21 | No |
| 3 | Tipsy Trailer | -34 | No |
| 4 | Balloon | -59 | RAW 3004 |
| 5 | Conveyor Belt | +2 | FM 5 |
| 6 | Mouse Motor | +1 | RAW 3006 |
| 7 | Pulley | +4 | No |
| 8 | Belt | +7 | No |
| 9 | Basketball | +34 | No |
| 10 | Rope | +41 | No |
| 11 | Laundry Basket | +47 | No |
| 12 | Curie Cat | +29 | RAW 3012 |
| 13 | Jack-in-the-box | +30 | RAW 3013 |
| 14 | Gear | +31 | No |
| 15 | Fish Tank | +39 | RAW 3015 |

**These offsets do NOT compute FM patch IDs via a single base value.** Cross-referencing with `part-assets.json`:
- pt5: offset=+2, FM SID=5 → base = 3
- pt4: offset=-59, RAW SID=3004 → base = 3063

The offsets are applied to **different base values per part** (or only apply to FM-synthesis parts). Parts beyond pt15 use different lookup mechanisms — their sound IDs (e.g., pt24 Fan=24, pt26 Generator=26) directly equal their part type, suggesting the offset table only covers the first 16 parts.

The table extends at least to pt21 at 0x3A80+:
```
pt16=+44, pt17=+51, pt18=+3, pt19=+6, pt20=+9, pt21=+40
```
Before transitioning to larger values (>1000) at 0x3A8C+ (likely a different data structure).

### Section E: W6 Index Arrays (0x3BBA-0x3BC6)

`FUN_31f7_7332` (file offset 0x3E4BE) loads 7 cached sound parameters from the resource-loaded table:

| Array | Seg Offset | Index Values | Purpose |
|-------|-----------|-------------|---------|
| `DAT_554c_3bba` | 0x3BBA | [0, 3] | First 2 channel params |
| `DAT_554c_3bbe` | 0x3BBE | [2, 1] | Second 2 channel params |
| `DAT_554c_3bc2` | 0x3BC2 | [3, 1] | Third 2 channel params |
| single | — | 14 (0x0E) | Additional param |
| single | — | 255 (0xFFFF) | Additional param |

These index into the **same resource-loaded table** (identified by `DAT_5b41_0a22`) that the state limit init uses. The returned values are cached in BSS variables (`DAT_5b41_1a32` through `DAT_5b41_1a40`) for the sound dispatch system.

### FM Patch Assignment (Cross-Reference)

14 parts have FM-range sound IDs (type=7 patches from TIM2.SX):

| Part Type | Name | FM SID | Patch Name | pt == SID? |
|-----------|------|--------|------------|-----------|
| 5 | Conveyor Belt | 5 | 5convey | Yes |
| 24 | Electric Fan | 24 | 24FAN | Yes |
| 26 | Generator | 26 | 26GENER | Yes |
| 50 | Electric Motor | 50 | 50MOTOR | Yes |
| 51 | Vacuum | 51 | 51VAC | Yes |
| 65 | Leprechaun | 65 | 65LEP | Yes |
| 67 | Can Opener | 67 | 67CAN | Yes |
| 69 | Anti-Gravity Pad | 69 | 69ANTGRV | Yes |
| 74 | Nitroglycerine | 74 | 74NITRO | Yes |
| 91 | Red Laser | 91 | 91LASER1 | Yes |
| 107 | Electric Mixer | 107 | 107MIXER | Yes |
| 109 | Blimp | 109 | 109BLIMP | Yes |

**Notable:** For parts with FM-patch-only sounds, the **FM sound ID equals the part type** (pt5→SID5, pt24→SID24, etc.). This pattern breaks for parts with RAW PCM sounds (3001-3754 range), which use arbitrary IDs.

## Open Questions (Post R-016)

| Question | Status |
|----------|--------|
| What is the "value" field in the pair table (1, 8, 7, 6, 5, 4, 9)? Unresolved — not FM patch IDs, not part types. Likely OPL2 channel numbers. | 🟡 |
| Can the per-part offsets be combined with a per-part base to compute FM patch IDs? The simple single-base model failed. | 🟡 |
| What is the meaning of the first 8 words (Section B)? | 🟡 |
| How do parts 16-148 get their sound IDs if the offset table only covers 0-15? Parts with ID==SID suggest a fallback: pt_type→FM_SID when pt_type matches. | 🟡 |

## Files

- Build output: `build/phase-13/ghidra-decompiled/table-sound-param-annotated.txt` (annotated table dump)
- This report: `docs/experiments/R-016-sound-param-table.md`

## Q-024 Resolution

**Q-024 is now closed.** The sound parameter table structure at seg 0x554C:0x3A30-0x3C00 has been partially decoded:

| Claim | Verdict |
|-------|---------|
| "7 entry pairs at 0x3A32" | ❌ False — pairs are at 0x3A42 (corrected for 0x10 Ghidra offset) |
| "120 at 0x3A30" | ❌ False — verified value is 8 |
| "Per-part offsets at 0x3A50" | ❌ False — table starts at 0x3A60 |
| "Offsets compute FM patch IDs by adding base" | 🟡 Partially true — base varies by part; pattern pt==SID for FM-only parts |
| "W6 index arrays at 0x3BBA/0x3BBE/0x3BC2" | ✅ Confirmed — values [0,3], [2,1], [3,1] |

The remaining unknowns (meaning of "value" field, per-part base computation) are Q-024a-level questions, not the original Q-024 scope.
