# TIM2 Editor — ANM Sprite Rendering Pipeline

## Overview

The editor renders parts using decoded ANM animations when available, falling back
to colored rectangles for part types without sprite data.

## Rendering Pipeline

```
draw_part(part, is_selected)
  │
  ├─ anm_renderer.render_frame(anm_name, state, bmp_dir, state_counter)
  │     │
  │     ├─ Section C: state_id → first_frame_id   (get_first_frame_for_state)
  │     ├─ Section A: first_a_idx + counter → section_b_idx
  │     ├─ Section B: section_b_idx → {width, height, bytecode_offset}
  │     └─ Section D: bytecode execution (DRAW_BMP, DRAW_RECT, DRAW_LINE, PLAY_SFX)
  │
  ├─ sprite exists? → scale by self.zoom → blit
  └─ sprite missing? → fill + outline rectangle using part.width_1/height_1
```

### State Resolution

- If `part.current_state > 0`, use it as the ANM state ID.
- Otherwise default to state 1 (idle).
- `state_counter` is driven by the global `editor_tick`, which increments each frame.
  Section A wraps the counter: `section_a[(first_a_idx + counter) % len(section_a)]`.

### Zoom Scaling

Sprites are scaled uniformly: `int(sprite.get_width() * self.zoom)` preserves aspect
ratio. Fallback rectangles use `part.width_1 * self.zoom`.

### Animation Source

- BPG PNGs: `build/phase-3/bitmaps/` (3,056 files, decoded from original BMPs)
- ANM JSON: `build/phase-4/anm/` (433 files, decoded from original ANM bytecode)
- Palette: `build/phase-3/palettes/PARTTEMP.json` (256-color VGA palette)
- Part→ANM mapping: `build/phase-9/part-name-catalog.json`

## Catalog Thumbnails

`_render_icon_thumbnail(part_type)` renders a cached 32×32 icon:

```
render_frame(anm_name, state=1, bmp_dir, state_counter=0)
  → scale to fit 32×32 box (maintaining aspect)
  → cache in self.thumbnail_cache[part_type]
```

Thumbnails are generated on demand and invalidated on level load/new.

## Fallback Rendering

When no ANM is available for a part type, the editor draws:

```python
pygame.draw.rect(self.screen, fill, rect)
pygame.draw.rect(self.screen, outline, rect, max(1, int(self.zoom)))
```

- Fill: `COLORS["part_fill"]` or `(180, 140, 0, 80)` when selected
- Outline: `COLORS["part_outline"]` or `COLORS["selected"]` when selected
