# E-014 — Animation Pipeline: ANM Rendering Flow

**Date**: 2026-05-27
**Goal**: Document how TIM2 renders ANM sprites on screen — the pipeline from Section C state→frame map through to Section D bytecode execution.

## Background

Phase 4 completed full ANM format decode (433 files, Sections A-D). Phase 9 established the state-part matrix (89 state IDs × 422 entries). M10 (E-013) documented the state execution engine. The missing piece is **how the renderer connects state changes to actual pixel output**.

## ANM Format Recap

Each ANM file has four sections (from R-002):

| Section | Content | Entry Size |
|---------|---------|------------|
| A | Frame index sequence (UINT16LE indices into Section B) | 2 × nEntries |
| B | Frame metadata (x, y, w, h, bytecode_offset) | 10 × nFrames |
| C | State map (first_frame_id, state_id) | 4 × nStates |
| D | Render bytecode (6 opcodes) | variable |

**Correction (2026-05-27):** Section A was originally described as "frame durations" but is actually a **frame index sequence** — an indirection array. Each entry is an index into Section B, not a tick count. Consecutive equal values in Section A produce "held" frames (displayed for multiple state counter ticks).

## Animation Pipeline

### Frame Advance (Timing)

The animation runs at **60 Hz** (VBL-synchronized, verified in E-009). The state counter (offset 0x10/0x18) advances every tick via `advance_state()`. The frame displayed is determined by:

1. The current state_id (from state execution engine)
2. Section C lookup: `state_id → first_frame_id` (index into Section A)
3. Section A indirection: `section_a[first_frame_id + state_counter % remaining_a_length] → section_b frame index`
4. Section B: read frame metadata using the section_b frame index

**Section A is an indirection array, not a duration table.** Each entry is a Section B frame index. The state_counter offsets into Section A starting from `first_frame_id`. Example:

```
section_a = [0, 1, 1, 2, 3, 3]   # 6 entries, values are SECTION B indices
section_c: state_id=1 → first_frame_id=1  (index into section_a)

At state_counter=0: a_idx = 1+0 = 1 → section_a[1] = 1 → section_b[1]
At state_counter=1: a_idx = 1+1 = 2 → section_a[2] = 1 → section_b[1] (same — held frame)
At state_counter=2: a_idx = 1+2 = 3 → section_a[3] = 2 → section_b[2]
At state_counter=3: a_idx = 1+3 = 4 → section_a[4] = 3 → section_b[3]
At state_counter=4: a_idx = 1+4 = 5 → section_a[5] = 3 → section_b[3] (same — held)
At state_counter=5: a_idx = 1+5 = 6 → 6 % 6 = 0 → section_a[0] = 0 → section_b[0] (wrap)
```

Frame "duration" (how long a frame appears) is implicit: consecutive equal values in Section A produce longer display times. Each Section A entry is consumed at 60 Hz (one per state counter tick).

### State → Frame Mapping (Section C Lookup)

When the state at offset 0x10/0x18 changes, the renderer looks up the corresponding ANM Section C entry:

```
Section C format:
  UINT16LE first_frame_id  // first frame index for this state
  UINT16LE state_id        // state identifier

Lookup: find entry where state_id == current_state
  → returns first_frame_id
  → frame_index = first_frame_id
```

The `part_type` field (offset 0x08 of the part struct) selects which ANM file to use. Each part type maps to one ANM via the `appearance` field (offset 0x08 of the 48-byte file format). The cross-reference is in `build/phase-9/part-anm-catalog.json`.

### Frame Metadata (Section B)

Once `first_frame_id` is determined, the renderer reads Section B entry `n` (where `n = first_frame_id + frame_offset`):

```
Section B format (10 bytes):
  UINT16LE x              // sprite X position relative to part
  UINT16LE y              // sprite Y position relative to part
  UINT16LE width          // sprite width in pixels
  UINT16LE height         // sprite height in pixels
  UINT16LE bytecode_offset  // offset into Section D
```

### Render Bytecode (Section D)

The bytecode at `bytecode_offset` is executed. Six known opcodes (UINT16LE):

| Opcode | Name | Parameters | Description |
|--------|------|------------|-------------|
| 0 | DRAW_BMP | resource_id (UINT16LE) | Draw a BMP sub-resource |
| 1 | DRAW_RECT | x, y, w, h, color (5 × UINT16LE) | Draw filled rectangle |
| 2 | COPY_SRC | src_x, src_y, w, h, dst_x, dst_y | Copy screen area |
| 3 | FILL | color (UINT16LE) | Fill whole frame with color |
| 4 | UNKNOWN | — | Rare, purpose unknown |
| 5 | END | (none) | End of bytecode stream |

**DRAW_BMP** draws a BMP sprite sub-resource (from the part's assigned BMP file). The `resource_id` selects which frame within the BMP to render. BMP sub-resource format is decoded in Phase 3.

**DRAW_RECT** draws a solid rectangle — used for shadows, highlights, color overlays.

### Rendering Execution

The bytecode interpreter is in the **FUN_2424_*** function family in segment 0x2424 (Ghidra CODE_5 block, ~286B). It reads Section D from the loaded ANM data buffer and dispatches:

```
for each bytecode entry:
  opcode = read_UINT16LE(buffer + offset)
  switch (opcode):
    case 0:  // DRAW_BMP
      resource_id = read_UINT16LE(buffer + offset + 2)
      draw_bmp_subresource(part, bmp_file, resource_id, frame_metadata.x, frame_metadata.y)
      offset += 4
    case 1:  // DRAW_RECT
      x, y, w, h, color = read 5 × UINT16LE
      draw_rect(x, y, w, h, color)
      offset += 12
    case 2:  // COPY
      src_x, src_y, w, h, dst_x, dst_y = read 6 × UINT16LE
      copy_area(src_x, src_y, w, h, dst_x, dst_y)
      offset += 14
    case 3:  // FILL
      color = read_UINT16LE
      fill_frame(color)
      offset += 4
    case 5:  // END
      break
```

### Coordinate System

Sprite positions in Section B are **relative to the part's position** (offset 0x14/0x16 in the physics struct). The final screen position:
```
screen_x = part->pos_x + frame_metadata.x
screen_y = part->pos_y + frame_metadata.y
```

DRAW_BMP can apply flips based on `flags_1 0x0010` (hflip) and `flags_1 0x0020` (vflip) at the file level, plus DRAW_BMP internal flags (bit 0 = hflip, bit 1 = vflip, per R-002).

## Complete Frame Rendering Flow

```
60 Hz Tick
  │
  ├── D1 (FUN_31f7_3bd2): Advance state counter
  │     ├── Read state at offset 0x10
  │     ├── If state < LIMIT → state++
  │     ├── If state == LIMIT → state = 0 (or reset value)
  │     ├── Handle sub-state countdown at offset 0xAE
  │     └── If state changed (state != state_prev):
  │           ├── FUN_31f7_3aab → state behavior
  │           └── FUN_28eb_3328 → sound/visual notification
  │
  ├── Renderer: Per-part ANM draw
  │     ├── Part type → ANM file lookup (appearance field)
  │     ├── State value → Section C: first_frame_id
  │     ├── first_frame_id → Section B: frame metadata (x, y, w, h, bytecode_off)
  │     ├── bytecode_off → Section D: execute bytecode:
  │     │     ├── DRAW_BMP: load and render BMP sub-resource
  │     │     ├── DRAW_RECT: draw colored rectangle
  │     │     ├── COPY/COPY_BACK: screen area copy
  │     │     ├── FILL: whole-frame fill
  │     │     └── END: terminate
  │     ├── Apply part flags (hflip, vflip, transparency)
  │     └── Blit to VGA framebuffer
  │
  └── VBL wait (port 0x3DA) → next tick
```

## Open Questions

| ID | Question | Status |
|----|----------|--------|
| Q-026 | Does the Section A tick counter feed directly into the state counter, or is there a separate frame timer? | ✅ **Closed (2026-05-27):** Section A is NOT a tick counter — it's a frame index sequence (indirection into Section B). The state_counter (offset 0x10/0x18) advances at 60 Hz and is used as the offset into Section A. No separate frame timer exists — state_counter IS the animation driver. Implemented in `tim2_editor/sprites/anm_renderer.py:render_frame()` as `a_idx = first_a_idx + state_counter; b_idx = section_a[a_idx % len(section_a)]`. |
| Q-027 | How does the FUN_2424_* dispatch distinguish ANM bytecode opcodes from other object property messages? | 🟡 Embedded in a ~10-case dispatch — need assembly-level analysis |
| Q-028 | How does Section A frame duration interact with Section C state mapping for multi-frame states? | ✅ **Closed (2026-05-27):** Section A is NOT durations. For multi-frame states, Section C maps `state_id → first_a_idx` (index into Section A). The frame displayed is `section_a[first_a_idx + state_counter]`. Consecutive equal values in Section A produce "held" frames (displayed for multiple state counter ticks). This is not duration-based — each Section A entry is consumed at one state counter tick (60 Hz). |
| Q-028 | How does Section A frame duration interact with Section C state mapping for multi-frame states? | 🟡 Some states have multiple frames — unclear if Section A or state counter controls which frame |

## Files

- `build/phase-4/anm/` — 433 decoded ANM JSONs (all Sections A-D)
- `build/phase-9/part-anm-catalog.json` — part type → ANM cross-reference
- `build/phase-9/state-part-matrix.json` — 89 state IDs × 422 entries
- `build/phase-12/decompiled/misc/FUN_2424_4678.c` — object property dispatch (contains opcode switch)
- `docs/experiments/E-013-state-machine-execution.md` — state execution engine (predecessor to this)
