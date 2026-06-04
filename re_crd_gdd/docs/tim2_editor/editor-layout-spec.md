# TIM2 Editor — Layout & Interaction Spec

## Window

| Property | Value |
|----------|-------|
| Width | 1280 px |
| Height | 720 px |
| FPS | 60 |
| Title | "TIM2 Level Editor" |

## Viewport

The game viewport shows the level area with zoom/scroll support.

| Property | Value |
|----------|-------|
| X | 10 px |
| Y | 60 px |
| Width | 560 px |
| Height | 377 px |

These match the TIM2 standard 560×377 playfield. The viewport is positioned with
a 10px left margin and 60px top margin (room for future toolbar at top).

### Coordinate System

- **Level coords**: integer 1:1 pixel coordinates of the original game (0,0 = top-left).
- **Screen coords**: pixel position on the 1280×720 window.
- **Conversion**: see `screen_to_level()` / `level_to_screen()` in `main.py`.

### Zoom & Scroll

| Property | Default | Range |
|----------|---------|-------|
| `zoom` | 1.0 | 0.25 – 4.0 |
| `scroll_x` | 0 | — |
| `scroll_y` | 0 | — |

Controls:
- **Mouse wheel** (viewport): zoom in/out (×1.25 factor).
- **Middle mouse drag**: pan.
- **Z**: reset zoom to 1.0.
- **0**: reset scroll to (0,0).
- **+/=**: zoom in.
- **-**: zoom out.

## Catalog Panel

| Property | Value |
|----------|-------|
| X | 580 px (10 + 560 + 10) |
| Y | 60 px |
| Width | 200 px |
| Height | 377 px |

The catalog panel sits to the right of the viewport. It lists parts organized
by category with thumbnail icons and names.

### Interacting with the Catalog

- **Click** a part entry → switches to PLACE mode with that part type.
- **Mouse wheel** on catalog → scroll the list up/down.
- **Highlighted entry** = current tool_place_type in PLACE mode.

### Mode Indicator

A single-line status bar at the top of the catalog panel shows the current mode:
- `SELECT`, `PLACE [N] Name`, `DELETE`, `CONNECT`, `PREVIEW`, `LEVEL INFO`

## Mode States

| # | Name | Key | Description |
|---|------|-----|-------------|
| 0 | SELECT | S | Click to select, drag to move, handles to resize |
| 1 | PLACE | P | Click in viewport to place the selected part type |
| 2 | DELETE | D | Click a part to remove it |
| 3 | PREVIEW | Space | Run simulation; click to stop |
| 4 | CONNECT | C | Click source part, then target part to create a rope/belt connection |
| 5 | LEVEL INFO | I | Opens the level info editing dialog |

## Grid

Snap grid is 16×16 pixels (`SNAP_GRID`). Grid lines are drawn when visible in the
viewport at the current zoom level. Grid color: `COLORS["grid"] = (60, 100, 160)`.

## Context

All layout constants are defined in `tim2_editor/editor/config.py`.
