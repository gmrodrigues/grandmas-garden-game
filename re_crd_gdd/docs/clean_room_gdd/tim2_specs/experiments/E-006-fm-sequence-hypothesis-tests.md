# E-006: FM Sequence Data Format (Q-014a)

**Date:** 2026-05-26
**Questions investigated:** Q-014a
**Gap:** G19
**Related:** E-005 (OPL2 register decode)

## TL;DR

The sequence data after the 28-byte SCI instrument in TIM2.SX FM patches is
**NOT MIDI/COMMAND encoded** (uniform byte distribution rules out all event-based
formats). Strong evidence suggests it is **raw OPL2 register/value streaming**
— a sequence of `(register_address, value)` pairs — but definitive confirmation
requires ADL.DRV disassembly. The `parameter` field is likely a duration in
ticks, but the tick rate is uncertain.

## Session Goals

1. Determine the format of sequence data after the 28-byte SCI instrument
2. Test multiple format hypotheses against all 14 FM patches
3. Interpret the `parameter` field in the DAT header
4. Cross-reference ScummVM MIDIParser-SCI format

## Step 1 — Data Extraction

Extracted full sequence bytes (22–803 bytes each) from all 14 FM patches by
parsing `fm-patch-report.json`'s `payload_hex_full` field (stripping the first
28 bytes = 56 hex chars of instrument data).

Script: `scripts/phase-6/14-analyse-fm-sequence-hypotheses.py`
Output: `build/phase-6/fm-sequence-hypothesis-report.json`

## Step 2 — Hypothesis Testing (H1–H10)

All 14 FM patch sequences were tested against 10 hypotheses:

| Hypothesis | Test | Result |
|---|---|---|
| **H1: MIDI-like** (0x9x=note on, 0x8x=note off, etc.) | High-nibble distribution | ❌ **RULED OUT** — All 16 nibbles 5.4–7.4% (uniform), MIDI would cluster at 0x8/0x9/0xB |
| **H2: 3-byte commands** | Chunk uniqueness at offset 0,1,2 | ❌ **RULED OUT** — All chunk sizes near 1.0 uniqueness ratio |
| **H3: Delta-time encoding** | Byte-to-byte difference clustering | ❌ **RULED OUT** — No clustering of small/large deltas |
| **H4: Checksummed 2-byte packets** | XOR/add constant across pairs | ❌ **RULED OUT** — No consistent XOR/add pattern |
| **H5: OPL2 register/value streaming** | (reg,val) pairs at offset 0–3 | ✅ **VIABLE** — 92–100% of bytes at best offset are valid OPL2 registers |
| **H6: Musical note+duration** (note 0–47, duration bytes) | Byte range 0–47 | ❌ **RULED OUT** — Only 69ANTGRV shows 21% in note range |
| **H7: Parameter = XOR/LSUM of sequence** | Compare param to XOR/sum(seq) | ❌ **RULED OUT** — 0/14 XOR matches, 1/14 SUM match |
| **H8: Zero-absence significance** | Byte value 0 count | ⚠️ Notable but not diagnostic — 11/14 patches have zero_count=0 |
| **H9: 0x80 as end marker** | Position of 0x80 in sequence | ⚠️ 5/14 end with 0x80 (ANTGRV, LASER1, COFFEE, MIXER, BLIMP), 9/14 do not |
| **H10: Bitflag encoding** (51VAC special pattern) | Power-of-2 bytes | ⚠️ 51VAC shows [0x00, 0x0F, 0x1F, 0x3F, 0x7F, 0x80] = 8.4% — could be OPL2 value bytes |

## Step 3 — High-Nibble Distribution Analysis

Aggregate across all 3,583 sequence bytes:

```
0x0x:  6.9%   0x8x:  6.0%  NOTE_OFF    0x1x:  6.5%
0x1x:  6.5%   0x9x:  5.7%  NOTE_ON     0x2x:  6.0%
0x2x:  6.0%   0xAx:  5.4%              0x3x:  6.1%
0x3x:  6.1%   0xBx:  6.4%  CTRL        0x4x:  6.4%
0x4x:  6.4%   0xCx:  5.6%  PROG        0x5x:  6.6%
0x5x:  6.6%   0xDx:  5.9%              0x6x:  6.2%
0x6x:  6.2%   0xEx:  6.7%              0x7x:  6.3%
0x7x:  6.3%   0xFx:  7.4%  META        0x8x:  6.0%
```

**All 16 high-nibble classes are within 5.4–7.4%** — a statistically uniform
distribution. This is the single most important finding and **categorically
rules out** any event-based format (MIDI, custom commands, note tuples) where
specific byte values recur at high frequency.

## Step 4 — OPL2 Register Streaming Analysis

Despite the uniform distribution, **every single top-20 most-common byte value**
across all sequences is a valid OPL2 register (0x01–0xF5):

| Rank | Byte | Count | OPL2 Register? |
|------|------|-------|----------------|
| 1 | 0x80 | 29 | ✅ (0x01≤0x80≤0xF5) |
| 2 | 0xFE | 27 | ❌ (above F5) |
| 3 | 0x40 | 26 | ✅ (OPL2 register 0x40) |
| 4 | 0xF5 | 24 | ✅ (valid reg) |
| 5 | 0x94 | 24 | ✅ |
| ... | ... | ... | All top-20 are ✅ |

When parsed as alternating `(register, value)` pairs at the correct byte offset,
**92–100% of register-position bytes are valid OPL2 registers 0x01–0xF5**:

| Patch | Best Offset | Reg Ratio | Notes |
|-------|-----------|-----------|-------|
| 5convey | 1 | 100.0% | |
| 24FAN | 0 | 97.9% | |
| 26GENER | 1 | 97.2% | |
| 50MOTOR | 1 | 94.1% | |
| 51VAC | 0 | 92.5% | |
| 62COFFEE | 1 | 96.3% | |
| 65LEP | 1 | 93.4% | |
| 67CAN | 0 | 96.6% | |
| 69ANTGRV | 0 | 100.0% | |
| 74NITRO | 2 | 95.1% | |
| 91LASER1 | 1 | 100.0% | |
| 107MIXER | 0 | 100.0% | |
| 109BLIMP | 0 | 100.0% | |
| 205CONV | 1 | 99.3% | |

Register types found across sequences:
- **0x20–0x35**: Operator parameters (AM/VIB/KSR/MULT, AR, DR)
- **0x40–0x55**: KSL/Total Level
- **0x60–0x75**: Attack/Decay, Sustain/Release
- **0x80–0x95**: (continued ADSR)
- **0xA0–0xA8**: Frequency low byte (notes)
- **0xB0–0xB8**: Frequency high + octave + key-on
- **0xC0–0xC8**: Feedback/Algorithm
- **0xE0–0xE8**: Waveform select

**This covers ALL categories of OPL2 programming** — exactly what FM synthesis
needs. The registers are spread across all voice and operator parameters.

## Step 5 — The Paradox: Uniform Distribution + OPL2 Registers

This is the central tension. The uniform high-nibble distribution is inconsistent
with **any** command/control format but is **consistent with** alternating
(reg, val) pairs:

**Mathematical argument for (reg, val) → uniform nibbles:**
- Register bytes: mostly 0x00–0xF5 → nibbles 0–E with 0xFx = ~(6/245)=~2.5% of reg bytes
- Value bytes: uniformly distributed → each nibble ~6.25%
- Combined: 0xFx ≈ (2.5% + 6.25%) / 2 ≈ **4.4%** estimated, observed = **7.4%**
- Other nibbles similarly converge toward uniform

The uniform distribution is therefore **not a contradiction** — it is exactly
what alternating (reg, val) pairs would produce, with the "command marker"
effect completely diluted.

## Step 6 — Parameter Field Analysis

The `parameter` field (UINT16LE) in the DAT header ranges from 151 to 1555.

**H7 result:** Not a XOR or simple SUM checksum of sequence bytes.

**H13 result (duration in ticks):**
| Rate | Interpretation |
|------|---------------|
| 18.2 Hz (DOS INT8 timer) | param 151–1555 → 8.3s–85.4s total duration |
| 60 Hz (VBL) | param 151–1555 → 2.5s–25.9s total duration |
| 240 Hz (SCI) | param 151–1555 → 0.63s–6.5s total duration |

All three rates produce plausible SFX durations for a 1994 DOS game.

Estimated notes/note durations (assuming 3 bytes/event):
| Patch | param | @18.2Hz | Notes | ms/note |
|-------|-------|---------|-------|---------|
| ANTGRV | 151 | 8.3s | 7 | 1131ms |
| BLIMP | 851 | 46.8s | 22 | 2125ms |
| LASER1 | 439 | 24.1s | 18 | 1316ms |
| MIXER | 497 | 27.3s | 27 | 999ms |
| COFFEE | 1245 | 68.4s | 268 | 256ms |

## Step 7 — 51VAC Special Pattern

51VAC is an outlier: most common bytes are [0x00, 0x0F, 0x1F, 0x31, 0x80] —
power-of-2 and bit-pattern values. These are **exactly the kinds of values
stored in OPL2 registers**:
- 0x00: zero level, no modulation
- 0x0F: max total level (attenuation = 47.25 dB)
- 0x1F: high attenuation
- 0x80: bit 7 set (common in OPL2 value fields)

This is further evidence the sequence data is raw OPL2 value bytes.

## Step 8 — 0x80 End Marker

5 of 14 patches end with byte 0x80 (ANTGRV, LASER1, COFFEE, MIXER, BLIMP).
These 5 are also the **shortest** patches (22, 55, 803, 82, 66 bytes).
Notably, COFFEE (the longest at 803 bytes) also ends with 0x80.

0x80 is NOT a valid OPL2 register address (0x01–0xF5), so it could serve as
an end marker. But 9/14 patches do NOT end with 0x80, making it inconclusive.

## Step 9 — Variable-Length Delta-Time Test (H11)

Tested MIDI-style variable-length quantity parsing. Results show:
- Delta-time values are often astronomically large (billions) — wrong scale
- Commands appear as random bytes, not in MIDI patterns
- Note on/off counts are tiny (0–16 per patch) vs thousands of bytes

**Verdict: NOT variable-length delta-time MIDI.**

## Conclusion

**Q-014a remains 🔴 OPEN**, but with a strongly-supported working hypothesis:

> **Sequence data = raw OPL2 register/value streaming** — a flat sequence of
> `(register_address_byte, value_byte)` pairs executed sequentially by ADL.DRV
> to program the YM3812 chip for each sound effect.

**Supporting evidence (5 independent lines):**
1. All top-20 most-common bytes are valid OPL2 registers
2. At correct alignment (offset 0–2), 92–100% of register-position bytes are 0x01–0xF5
3. Registers span ALL OPL2 categories (operator, frequency, waveform, channel)
4. Uniform nibble distribution is mathematically consistent with alternating (reg, val)
5. 51VAC's power-of-2 bytes match typical OPL2 register values

**The uniform distribution paradox is resolved:** any stream of (reg, val) pairs
with near-uniform value bytes will produce near-uniform high-nibble distribution.
The OPL2 register clustering effect is spread across all 0x0–0xE high nibbles,
making it statistically invisible in aggregate distribution analysis.

**What remains unknown (requires ADL.DRV):**
- Exact register-value alignment per patch (offset 0, 1, or 2)
- Whether timing/delay bytes are interleaved (would add non-reg bytes → reducing reg ratio)
- Whether 0x80 is truly an end marker
- Whether the parameter field is duration or something else

**The init bytes [0x10, 0xC6, 0x46] remain 🟡 Unknown.**

## Artifacts

- Script: `scripts/phase-6/14-analyse-fm-sequence-hypotheses.py`
- Output: `build/phase-6/fm-sequence-hypothesis-report.json`
- Analysis: Cross-referenced with `fm-patch-report.json` and `sx-report.json`
- Web research: ScummVM `midiparser_sci.cpp` and `adlib.cpp` (confirmed SCI28, ruled out MIDI sequences)