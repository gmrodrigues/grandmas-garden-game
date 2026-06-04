---
name: anm-renderer
description: ANM bytecode animation renderer for Godot 2D. Use when working on AnmRenderer.gd, AnmDatabase.gd, animation playback, sprite rendering, or palette/bytecode interpretation. Trigger keywords: ANM, AnmRenderer, animation, bytecode, sprite, palette, DRAW_BMP, Section A/B/C/D.
---

# ANM Animation Bytecode Renderer

Implements the ANM animation system from `backend/AnmRenderer.gd` + `autoload/AnmDatabase.gd`. Use when modifying animation playback, adding new bytecode commands, or debugging missing sprites.

## Architecture

**Core files:**
- `godot_level_editor/autoload/AnmDatabase.gd` — loads/caches 433 ANM JSON files
- `godot_level_editor/backend/AnmRenderer.gd` — renders ANM frames to Image (RefCounted)
- `godot_level_editor/backend/PartData.gd` — `appearance` field drives flip/state
- `godot_level_editor/autoload/AudioManager.gd` — PLAY_SFX bytecode dispatches here

**Data files:**
- `godot_level_editor/data/anm/*.json` — 433 ANM files (Section A/B/C/D structure)
- `godot_level_editor/data/sprites/*.png` — 3054 BMP sprites (`NAME_fNNN.png`)
- `godot_level_editor/data/palettes/*.json` — 24 palette files

## 4-Section ANM Format

| Section | Purpose | Structure |
|---------|---------|----------|
| A | Frame index lookup by state+counter | Array of integers — index into Section B |
| B | Per-frame metadata | Objects with `width`, `height`, `bytecode_offset` |
| C | State → first frame mapping | Array, `state_id → first_frame_index` |
| D | Bytecode commands per frame | Arrays of `[cmd, ...args]` |

**Pipeline:**
```
state_id → Section C[state_id] → first Section A index
Section A[(first_a_idx + state_counter) % section_a.size()] → Section B frame index
Section B[frame].bytecode_offset → Section D[bytecode_offset:] → execute bytecodes
```

## Render Flow

```
AnmRenderer.render_frame(anm_name, state_id, state_counter, width, height) → Image
  1. AnmDatabase.load_anm(anm_name)  — fetch cached ANM JSON
  2. AnmDatabase.get_first_frame_for_state(state_id)  — Section C lookup
  3. Section A[(first_a_idx + state_counter) % section_a.size()]  — frame index
  4. AnmDatabase.get_bytecodes_for_frame(bytecode_offset)  — Section D slice
  5. For each bytecode entry: AnmRenderer._execute_bytecode(image, entry, anm_name)
```

## Bytecode Commands (Section D)

| Cmd ID | Method | Args | Description |
|--------|--------|------|-------------|
| 0 | — | (none) | `END_FRAME` — stop this frame |
| 1 | — | (none) | `END_ANM` — stop entire animation |
| 2 | `_draw_bmp()` | x, y, flip_flags, res_id, unknown, bmp_index | Blit sprite image |
| 3 | `_draw_rect()` | x, y, w, h, color_idx | Filled rectangle |
| 4 | `_draw_line()` | x1, y1, x2, y2, color_idx | Bresenham line |
| 5 | `_play_sfx()` | sound_id | Trigger AudioManager.play_sfx() |

## Palette System

- 24 palettes loaded from `data/palettes/*.json`
- Each palette has 16 VGA color slots
- Index 0 is transparent in most palettes
- Used by `_draw_rect()` and `_draw_line()` — `color_idx` is palette index, not RGB

## BMP Loading

`AnmRenderer._load_bmp(anm_name, resource_id, bmp_index)`:
- Path: `data/sprites/{anm_name}_f{bmp_index:03d}.png`
- Multi-sub-image PNGs: each BMP may have multiple frames as sub-images
- Cached in `AnmRenderer._bmp_cache` Dictionary
- If missing: logs warning, returns `null` → frame renders without this BMP

## Flip Support

`appearance & 0x8000` → triggers `Image.flip_x()`. Applied after all drawing.

## Wall Rendering

`render_wall(anm_name, width, height)` tiles wall segments:
1. Section C end-caps at left/right (or top/bottom for vertical)
2. Section C center tiles tiled across middle
3. Requires `wall_meta` cached per ANM: `[center_count, cap_size, tile_size]`

## Adding a New Bytecode Command

In `AnmRenderer._execute_bytecode()` (line 170), add a new `cmd == N:` branch:

```gdscript
elif cmd == N:
    # parse args from entry[1:]
    # draw to image (Image.set_pixel for pixel ops, or use Image blit)
    pass
```

If the command needs a new sprite type, also update `_load_bmp()`.

## Key Reference

- `backend/AnmRenderer.gd:68` — `render_frame()` entry
- `backend/AnmRenderer.gd:93` — `render_wall()` wall tiling
- `backend/AnmRenderer.gd:151` — `_render_section_b_frame()`
- `backend/AnmRenderer.gd:170` — `_execute_bytecode()` dispatch
- `backend/AnmRenderer.gd:191` — `_draw_bmp()` sprite blit
- `backend/AnmRenderer.gd:230` — `_draw_rect()` filled rect
- `backend/AnmRenderer.gd:254` — `_draw_line()` Bresenham line
- `autoload/AnmDatabase.gd` — ANM JSON loading and caching
