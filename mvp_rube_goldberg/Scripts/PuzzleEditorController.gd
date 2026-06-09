class_name PuzzleEditorController
extends Node2D

enum PuzzleTool { SELECT, ROTATE, FLIP }

signal status_update(msg: String)
signal parts_changed
signal inventory_changed
signal puzzle_solved(tick: int)

const _PartData = preload("res://Scripts/PartData.gd")
const _WorldState = preload("res://Scripts/WorldState.gd")
const _PreviewSolver = preload("res://Scripts/PreviewSolver.gd")

var world_state: WorldState
var current_tool: int = PuzzleTool.SELECT

var viewport_offset_x: int = 0
var viewport_offset_y: int = 0
var zoom_level: float = 1.0
const ZOOM_MIN: float = 0.25
const ZOOM_MAX: float = 4.0
const ZOOM_STEP: float = 0.25

var _inventory: Array = []
var _inventory_counts: Dictionary = {}
var _placed_parts: Array = []
var _drag_state: Dictionary = {}

var _preview_simulation: bool = false
var _preview_solver: RefCounted = null
var _preview_accum_ms: float = 0.0
var _preview_last_time_ms: int = 0

var _inventory_ui: Control = null
var _puzzle_toolbar: Control = null

func _init():
	world_state = _WorldState.new()
	world_state.selection_changed.connect(_on_selection_changed)
	world_state.part_added.connect(_on_part_added)
	world_state.part_removed.connect(_on_part_removed)

func setup(inventory: Array, level_data: Dictionary) -> void:
	_inventory = inventory.duplicate(true)
	_inventory_counts.clear()
	for item in _inventory:
		var pt = int(item.get("part_type", 0))
		var cnt = int(item.get("count", 0))
		_inventory_counts[pt] = cnt
	if level_data.has("parts"):
		for pd in level_data["parts"]:
			var p = _PartData.new(-1, pd.get("part_type", 0), pd.get("x", 0), pd.get("y", 0))
			p.from_dict(pd)
			p.is_locked = true
			world_state.add_part(p)
			_placed_parts.append(p)

func get_inventory_counts() -> Dictionary:
	return _inventory_counts.duplicate()

func get_placed_parts() -> Array:
	return _placed_parts.duplicate()

func _ready():
	_update_status("PUZZLE — drag parts from inventory, R=rotate, F=flip")
	_preview_last_time_ms = Time.get_ticks_msec()

func set_tool(mode: int) -> void:
	current_tool = mode
	match mode:
		PuzzleTool.SELECT:
			_update_status("SELECT — click to select, drag to move")
		PuzzleTool.ROTATE:
			_update_status("ROTATE — click part to rotate 90°")
		PuzzleTool.FLIP:
			_update_status("FLIP — click part to flip")
	parts_changed.emit()

func _input(event: InputEvent) -> void:
	if event is InputEventKey:
		_handle_key_event(event)
		return
	if event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_WHEEL_UP:
			_zoom_in()
			return
		if event.button_index == MOUSE_BUTTON_WHEEL_DOWN:
			_zoom_out()
			return
		if event.button_index == MOUSE_BUTTON_MIDDLE and event.pressed:
			_is_panning = true
			_pan_start_x = int(event.position.x)
			_pan_start_y = int(event.position.y)
			_pan_viewport_start_x = viewport_offset_x
			_pan_viewport_start_y = viewport_offset_y
			return
		if event.button_index == MOUSE_BUTTON_MIDDLE and not event.pressed:
			_is_panning = false
			return
		_handle_mouse_button_event(event)
		return
	if event is InputEventMouseMotion:
		_handle_mouse_motion_event(event)

var _is_panning: bool = false
var _pan_start_x: int = 0
var _pan_start_y: int = 0
var _pan_viewport_start_x: int = 0
var _pan_viewport_start_y: int = 0

func _handle_key_event(event: InputEventKey) -> void:
	if not event.pressed:
		return
	match event.keycode:
		KEY_ESCAPE:
			_cancel_current_operation()
			set_tool(PuzzleTool.SELECT)
		KEY_R:
			if world_state.has_selection():
				for p in world_state.get_selected():
					p.state_counter = (p.state_counter + 1) % maxi(p.state_limit_upper, 1)
					p.current_state = p.state_counter
				parts_changed.emit()
		KEY_F:
			if world_state.has_selection():
				for p in world_state.get_selected():
					p.flip_horizontal()
				parts_changed.emit()
		KEY_S:
			if event.ctrl_pressed:
				_save_puzzle_state()
		KEY_PLUS, KEY_EQUAL, KEY_KP_ADD:
			_zoom_in()
		KEY_MINUS, KEY_KP_SUBTRACT:
			_zoom_out()
		KEY_1: set_tool(PuzzleTool.SELECT)
		KEY_2: set_tool(PuzzleTool.ROTATE)
		KEY_3: set_tool(PuzzleTool.FLIP)
		KEY_5:
			if _preview_simulation:
				_stop_preview()
			else:
				_start_preview()

func _handle_mouse_button_event(event: InputEventMouseButton) -> void:
	if not event.pressed:
		_handle_mouse_up(event)
		return
	var mx = int(event.position.x / zoom_level) + viewport_offset_x
	var my = int(event.position.y / zoom_level) + viewport_offset_y
	match current_tool:
		PuzzleTool.SELECT:
			_handle_select_mouse_down(mx, my, event)
		PuzzleTool.ROTATE:
			_handle_rotate_mouse_down(mx, my)
		PuzzleTool.FLIP:
			_handle_flip_mouse_down(mx, my)

func _handle_select_mouse_down(mx: int, my: int, event: InputEventMouseButton) -> void:
	var part = world_state.find_part_at(mx, my)
	if part != null:
		if not part.is_selected:
			world_state.select_part(part, false)
		_start_part_drag(mx, my)
	else:
		if not event.shift_pressed:
			world_state.deselect_all()
		_drag_state["pan_start_x"] = mx
		_drag_state["pan_start_y"] = my

func _handle_rotate_mouse_down(mx: int, my: int) -> void:
	var part = world_state.find_part_at(mx, my)
	if part != null and not part.is_locked:
		part.state_counter = (part.state_counter + 1) % maxi(part.state_limit_upper, 1)
		part.current_state = part.state_counter
		parts_changed.emit()

func _handle_flip_mouse_down(mx: int, my: int) -> void:
	var part = world_state.find_part_at(mx, my)
	if part != null and not part.is_locked:
		part.flip_horizontal()
		parts_changed.emit()

func _handle_mouse_motion_event(event: InputEventMouseMotion) -> void:
	if _is_panning:
		var dx = int(event.position.x) - _pan_start_x
		var dy = int(event.position.y) - _pan_start_y
		viewport_offset_x = _pan_viewport_start_x - int(dx / zoom_level)
		viewport_offset_y = _pan_viewport_start_y - int(dy / zoom_level)
		parts_changed.emit()
		return
	var mx = int(event.position.x / zoom_level) + viewport_offset_x
	var my = int(event.position.y / zoom_level) + viewport_offset_y
	if current_tool == PuzzleTool.SELECT:
		if _drag_state.has("active") and _drag_state["active"]:
			_handle_select_drag(mx, my)

func _start_part_drag(mx: int, my: int) -> void:
	_drag_state["active"] = true
	_drag_state["start_x"] = mx
	_drag_state["start_y"] = my
	_drag_state["parts_start_positions"] = {}
	for p in world_state.get_selected():
		_drag_state["parts_start_positions"][p.id] = {"x": p.x, "y": p.y}

func _handle_select_drag(mx: int, my: int) -> void:
	var dx = mx - _drag_state.get("start_x", mx)
	var dy = my - _drag_state.get("start_y", my)
	var snap = _PartData.GRID_SIZE
	for p in world_state.get_selected():
		if p.is_locked:
			continue
		var start_pos = _drag_state["parts_start_positions"].get(p.id, {"x": p.x, "y": p.y})
		var new_x = (start_pos["x"] + dx) / snap * snap
		var new_y = (start_pos["y"] + dy) / snap * snap
		if new_x != p.x or new_y != p.y:
			p.x = new_x
			p.y = new_y
			p.changed.emit(p, "position")
	parts_changed.emit()

func _handle_mouse_up(event: InputEventMouseButton) -> void:
	_end_drag()

func _end_drag() -> void:
	_drag_state.clear()

func _cancel_current_operation() -> void:
	_end_drag()

func _zoom_in() -> void:
	zoom_level = mini(zoom_level + ZOOM_STEP, ZOOM_MAX)
	parts_changed.emit()

func _zoom_out() -> void:
	zoom_level = maxi(zoom_level - ZOOM_STEP, ZOOM_MIN)
	parts_changed.emit()

func _update_status(msg: String) -> void:
	status_update.emit(msg)

func _on_selection_changed(selected: Array) -> void:
	parts_changed.emit()

func _on_part_added(part_data: PartData) -> void:
	parts_changed.emit()

func _on_part_removed(part_data: PartData) -> void:
	parts_changed.emit()

func _start_preview() -> void:
	_preview_solver = _PreviewSolver.new()
	_preview_solver.setup_from_world_state(world_state)
	_preview_solver.tick_complete.connect(_on_preview_tick)
	_preview_solver.solution_achieved.connect(_on_preview_solution)
	_preview_solver.start()
	_preview_last_time_ms = Time.get_ticks_msec()
	_preview_accum_ms = 0.0
	_preview_simulation = true
	_update_status("PREVIEW running — press ESC or 5 to stop")

func _stop_preview() -> void:
	if _preview_solver != null:
		_preview_solver.stop()
		_preview_solver = null
	_preview_simulation = false
	parts_changed.emit()
	_update_status("PREVIEW stopped")

func _on_preview_tick(tick: int) -> void:
	parts_changed.emit()

func _on_preview_solution(tick: int) -> void:
	_update_status("SOLVED! Tick " + str(tick))
	_preview_simulation = false
	puzzle_solved.emit(tick)

func _process(_delta: float) -> void:
	queue_redraw()
	if not _preview_simulation or _preview_solver == null or not _preview_solver.is_running:
		return
	var current_time_ms = Time.get_ticks_msec()
	var elapsed_ms = current_time_ms - _preview_last_time_ms
	_preview_last_time_ms = current_time_ms
	if elapsed_ms > 100:
		elapsed_ms = 100
	_preview_accum_ms += elapsed_ms
	var ms_per_tick = 1000.0 / 60.0
	while _preview_accum_ms >= ms_per_tick:
		_preview_solver.tick()
		_preview_accum_ms -= ms_per_tick

func _save_puzzle_state() -> void:
	_update_status("Puzzle state saved")

func get_level_data() -> Dictionary:
	var parts_list = []
	for p in world_state.parts_data:
		parts_list.append(p.to_dict())
	return {
		"parts": parts_list,
		"inventory": _inventory.duplicate(true)
	}

func spawn_from_inventory(part_type: int, x: int, y: int) -> bool:
	var available = _inventory_counts.get(part_type, 0)
	if available <= 0:
		return false
	var snap = _PartData.GRID_SIZE
	x = (x / snap) * snap
	y = (y / snap) * snap
	var p = _PartData.new(-1, part_type, x, y)
	p.is_locked = false
	p.is_moving = true
	var arch = _get_archetype(part_type)
	p.archetype = arch
	world_state.add_part(p)
	_placed_parts.append(p)
	_inventory_counts[part_type] = available - 1
	inventory_changed.emit()
	parts_changed.emit()
	return true

func return_to_inventory(part_data: PartData) -> bool:
	if not _placed_parts.has(part_data):
		return false
	var idx = world_state.parts_data.find(part_data)
	if idx >= 0:
		world_state.parts_data.remove_at(idx)
	_placed_parts.erase(part_data)
	var pt = part_data.part_type
	_inventory_counts[pt] = _inventory_counts.get(pt, 0) + 1
	inventory_changed.emit()
	parts_changed.emit()
	return true

func _get_archetype(part_type: int) -> int:
	var cat = _get_category_for_type(part_type)
	if cat.begins_with("Walls") or cat.begins_with("Scenery"):
		return _PartData.ARCH_STATIC
	if cat == "Balls" or cat == "Balloons / Airships" or cat == "Characters":
		return _PartData.ARCH_KINETIC
	if cat == "Rotating Power Sources":
		return _PartData.ARCH_DRIVER
	if cat == "Ropes / Belts / Pulleys":
		return _PartData.ARCH_LINK
	if cat == "Electrical" or cat == "Light / Flame Sources":
		return _PartData.ARCH_EMITTER
	if cat == "Explosives / Projectiles" or cat == "Springs / Pneumatics" or cat == "Containers":
		return _PartData.ARCH_CONSUMER
	return _PartData.ARCH_STATIC

func _get_category_for_type(part_type: int) -> String:
	var catalog = _load_catalog()
	for entry in catalog:
		if int(entry.get("part_type", -1)) == part_type:
			return entry.get("category", "")
	return ""

func _load_catalog() -> Array:
	var path = "res://data/part-name-catalog.json"
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		return []
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed is Array:
		return parsed
	return []

func _draw() -> void:
	var grid_color = Color(0.2, 0.2, 0.2, 0.5)
	var w = 640; var h = 480
	var off_x = -viewport_offset_x; var off_y = -viewport_offset_y
	for gx in range(0, w + 1, 16):
		var screen_x = (gx + off_x) * zoom_level
		draw_line(Vector2(screen_x, 0), Vector2(screen_x, h * zoom_level), grid_color)
	for gy in range(0, h + 1, 16):
		var screen_y = (gy + off_y) * zoom_level
		draw_line(Vector2(0, screen_y), Vector2(w * zoom_level, screen_y), grid_color)
	for p in world_state.parts_data:
		var sx = (p.x + off_x) * zoom_level
		var sy = (p.y + off_y) * zoom_level
		var sw = p.width_1 * zoom_level
		var sh = p.height_1 * zoom_level
		var col = Color(0.6, 0.6, 0.8, 0.8) if not p.is_locked else Color(0.4, 0.4, 0.4, 0.8)
		if p.is_selected:
			col = Color(0.3, 0.8, 1.0, 0.9)
		draw_rect(Rect2(sx, sy, sw, sh), col, false, 2.0)
		var label = "%d" % p.part_type
		draw_string(ThemeDB.fallback_font, Vector2(sx + 2, sy + 12), label, HORIZONTAL_ALIGNMENT_LEFT, -1, 10, Color(1, 1, 1, 0.8))