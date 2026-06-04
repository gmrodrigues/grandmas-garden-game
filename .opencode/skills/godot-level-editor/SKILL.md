---
name: godot-level-editor
description: Godot 4.6 level editor with mode-based input, pan/zoom viewport, ANM sprite rendering, and physics preview. Use when building EditorController.gd, dialogs, game controllers, or any Godot 2D editor UI. Trigger keywords: Godot, editor, mode machine, viewport, zoom, pan, _draw(), Sprite2D, FileDialog, level editor, preview simulation.
---

# Godot 4.6 Level Editor Pattern

Implements the editor from `editor/EditorController.gd`, `editor/LevelInfoDialog.gd`, `editor/ProgrammablePartDialog.gd`, `editor/SolutionRectTool.gd`, and `game/` scenes. Use when building Godot 2D editors, game UI, or viewport-based tools.

## Architecture

**Core files:**
- `godot_level_editor/scenes/Main.tscn` — main scene (Control root)
- `godot_level_editor/editor/EditorController.gd` — mode machine + input + _draw
- `godot_level_editor/editor/LevelInfoDialog.gd` — Window for level metadata
- `godot_level_editor/editor/ProgrammablePartDialog.gd` — Window for physics props
- `godot_level_editor/editor/SolutionRectTool.gd` — solution rect click-drag
- `godot_level_editor/game/GameController.gd` — game mode state machine
- `godot_level_editor/game/GoalBar.gd` — goal text label
- `godot_level_editor/game/SolveOverlay.gd` — "LEVEL SOLVED!" overlay

## Mode Machine Pattern

Editor has 6 exclusive modes (`EditorController.gd:4`):

```gdscript
enum ToolMode {
    MODE_SELECT,   # Click to select, drag to move, handles visible
    MODE_PLACE,    # Click catalog → click canvas → place part
    MODE_DELETE,   # Click part → delete
    MODE_CONNECT,  # Click source → click target → set connected_1
    MODE_PREVIEW,  # Run physics + SolutionChecker
    MODE_LEVEL_INFO  # Show LevelInfoDialog
}
```

Mode changes via keyboard shortcuts: S/P/D/C/Space/I

## Viewport Pan & Zoom

**Zoom** (scroll wheel):
```gdscript
zoom *= 1.25  # scroll up = zoom in
zoom = clamp(zoom, 0.25, 4.0)
# Recompute offset to zoom toward cursor:
offset = mouse_pos - (mouse_pos - offset) * (new_zoom / old_zoom)
```

**Pan** (middle mouse drag):
```gdscript
offset += event.position - _middle_mouse_start_pos
_middle_mouse_start_pos = event.position
```

**Coordinate transforms** (used everywhere):
```gdscript
_level_x = (screen_x / zoom) + offset.x  # screen → level coords
_level_y = (screen_y / zoom) + offset.y
_grid_snapped = int(_level_x / 16) * 16  # snap to 16px grid
```

## _draw() Overlay Pattern

All overlay graphics (grid, selection handles, connection lines) drawn in `_draw()`:

```gdscript
func _draw():
    # Grid lines
    for x in range(start_x, end_x, 16):
        draw_line(to_screen(Vector2(x, 0)), to_screen(Vector2(x, level_h)), Color(0.2, 0.2, 0.2))

    # Selection outline (amber)
    if selected_part_idx >= 0:
        var r = Rect2(part.x, part.y, part.width, part.height)
        draw_rect(r, Color(1, 0.78, 0), false, 2.0)

        # 8 resize handles (corners + midpoints)
        for pos in _get_handle_positions(part):
            draw_rect(Rect2(pos, Vector2(8/zoom, 8/zoom)), Color(1, 0.78, 0))

    # Connection preview line
    if current_mode == MODE_CONNECT and connect_source_idx >= 0:
        draw_line(connect_src_screen, mouse_screen, Color(1, 0.78, 0), 1.0, true)
```

Handle positions computed from part rect, scaled by zoom.

## Sprite Rendering in Editor

Parts rendered as `Sprite2D` nodes under a `Node2D` canvas:

```gdscript
func _spawn_part_node(part_data: PartData) -> Sprite2D:
    var s = Sprite2D.new()
    s.centered = false
    canvas.add_child(s)
    _update_sprite(s, part_data)
    return s

func _update_sprite(s: Sprite2D, part_data: PartData):
    var anm_name = PartDatabase.get_part_anm_name(part_data.part_type)
    var img = AnmRenderer.render_frame(anm_name, part_data.current_state,
                                       part_data.state_counter,
                                       part_data.width, part_data.height)
    if img:
        s.texture = ImageTexture.create_from_image(img)
    else:
        # Fallback: colored rect
        s.modulate = Color(0.5, 0.5, 1.0)
```

In preview mode, `_sync_part_nodes()` updates sprite positions each tick.

## FileDialog Save/Load

```gdscript
func _save_dialog():
    var fd = FileDialog.new()
    fd.file_mode = FileDialog.FILE_MODE_SAVE_FILE
    fd.add_filter("*.yaml", "TIM2 Level")
    add_child(fd)
    fd.file_selected.connect(_do_save)
    fd.file_selected.connect(fd.queue_free)   # prevent leak
    fd.canceled.connect(fd.queue_free)         # prevent leak
    fd.popup_centered(Vector2i(500, 400))
```

Always connect `queue_free` to both `file_selected` and `canceled` to avoid orphaned dialogs.

## Command-Line Arg Injection

Both controllers support `--level <path>` to auto-load a level on startup, enabling headless testing without UI interaction:

```bash
./Godot --path <project>/ --headless --level res://build/ELEV10.yaml
```

**EditorController.gd** (`EditorController.gd:68`):
```gdscript
func _ready():
    ...
    var args = OS.get_cmdline_args()
    var level_idx = args.find("--level")
    if level_idx >= 0 and level_idx + 1 < args.size():
        _do_load(args[level_idx + 1])
```

**GameController.gd** (`GameController.gd:22`):
```gdscript
func _ready():
    ...
    var args = OS.get_cmdline_args()
    var level_idx = args.find("--level")
    if level_idx >= 0 and level_idx + 1 < args.size():
        load_level(args[level_idx + 1])
```

The `_do_load`/`load_level` methods are the same ones used by the FileDialog — no separate code paths needed.

## Preview Simulation (MODE_PREVIEW)

```gdscript
func _start_preview():
    _snapshot = _serialize_all_parts()
    world.reset()
    solver.reset(world)
    preview_running = true

func _process(delta):
    if preview_running:
        solver.step(world)  # one physics tick
        _sync_part_nodes()
        if SolutionChecker.check_solution(world, solution_conditions):
            _show_solved_overlay()
        if world.ticks > 10000:
            _stop_preview()
```

## Dialog Pattern

```gdscript
# LevelInfoDialog.gd
class_name LevelInfoDialog
extends Window

signal dialog_closed(accepted: bool, data: Dictionary)

func _ready():
    $OKButton.pressed.connect(func(): dialog_closed.emit(true, _get_data()))
    $CancelButton.pressed.connect(func(): dialog_closed.emit(false, {}))

# Usage:
var dlg = LevelInfoDialog.new()
add_child(dlg)
dlg.dialog_closed.connect(func(accepted, data):
    if accepted:
        _apply_level_info(data)
    dlg.queue_free()
)
```

## Game Mode (GameController.gd)

3-state machine: `SELECT_LEVEL → PLAYING → SOLVED`

```gdscript
enum GameState { SELECT_LEVEL, PLAYING, SOLVED }

func _physics_process(delta):
    if state == PLAYING:
        sim_loop.tick()
        if solution_checker.check_solution(world, conditions):
            state = SOLVED
            _show_overlay()
```

## Key Reference

- `editor/EditorController.gd:4` — ToolMode enum
- `editor/EditorController.gd:68` — `--level` arg injection in `_ready()`
- `editor/EditorController.gd:_input()` — input router
- `editor/EditorController.gd:_handle_key()` — keyboard shortcuts
- `editor/EditorController.gd:_handle_mouse_click()` — click mode dispatch
- `editor/EditorController.gd:326` — zoom logic
- `editor/EditorController.gd:_draw()` — grid + handles + connection line
- `editor/EditorController.gd:482-490` — FileDialog save with `queue_free`
- `editor/EditorController.gd:521-529` — FileDialog load with `queue_free`
- `editor/EditorController.gd:538-551` — `_do_load()` with hex flag quote stripping
- `editor/EditorController.gd:602` — `_start_preview()`
- `editor/EditorController.gd:618` — `_stop_preview()`
- `game/GameController.gd:22` — `--level` arg injection in `_ready()`
- `game/GameController.gd` — game mode state machine
