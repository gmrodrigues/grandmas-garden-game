class_name EditorController
extends Node2D

enum ToolMode { SELECT, PLACE, DELETE, CONNECT, PREVIEW, LEVEL_INFO }
enum PlacementCategory { ALL, BALLS, WALLS, MECHANICS, BALLOONS, DRIVERS, ROPES, ELECTRICAL, EXPLOSIVES }

signal tool_changed(mode: int)
signal status_update(msg: String)
signal parts_changed
signal zoom_changed(level: float)
signal part_selected(part_data: PartData)
signal connection_preview(from_id: int, to_id: int, conn_type: int)

const _PartData = preload("res://Scripts/PartData.gd")
const _WorldState = preload("res://Scripts/WorldState.gd")
const _PreviewSolver = preload("res://Scripts/PreviewSolver.gd")

var world_state: WorldState
var current_tool: int = ToolMode.SELECT
var placement_category: int = PlacementCategory.ALL
var selected_part_type: int = 0

var viewport_offset_x: int = 0
var viewport_offset_y: int = 0
var zoom_level: float = 1.0
const ZOOM_MIN: float = 0.25
const ZOOM_MAX: float = 4.0
const ZOOM_STEP: float = 0.25

var _drag_state: Dictionary = {}
var _placement_preview: Dictionary = {}
var _connection_preview: Dictionary = {}
var _category_buttons: Array = []
var _part_catalog: Array = []

var _preview_simulation: bool = false
var _preview_solver: RefCounted = null
var _preview_accum_ms: float = 0.0
var _preview_last_time_ms: int = 0

@onready var catalog_panel: Control = null
@onready var status_label: Label = null

func _init():
	world_state = _WorldState.new()
	world_state.selection_changed.connect(_on_selection_changed)
	world_state.part_added.connect(_on_part_added)
	world_state.part_removed.connect(_on_part_removed)
	world_state.connections_changed.connect(_on_connections_changed)

func _ready():
	_load_part_catalog()
	_update_status("SELECT mode — click to select, drag to move")
	_preview_last_time_ms = Time.get_ticks_msec()

func _load_part_catalog() -> void:
	var path = "res://data/part-name-catalog.json"
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		push_warning("EditorController: Could not load part catalog from " + path)
		return
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed is Array:
		_part_catalog = parsed

func get_catalog_entry(part_type: int) -> Dictionary:
	for entry in _part_catalog:
		if entry.get("part_type") == part_type:
			return entry
	return {}

func get_archetype_for_type(part_type: int) -> int:
	var entry = get_catalog_entry(part_type)
	var solve_name = entry.get("solve_name", "")
	var category = entry.get("category", "")
	if category.begins_with("Walls") or category.begins_with("Scenery") or category.begins_with("Inclines"):
		return _PartData.ARCH_STATIC
	if category == "Balls" or category == "Balloons / Airships" or category == "Characters":
		return _PartData.ARCH_KINETIC
	if category == "Rotating Power Sources":
		return _PartData.ARCH_DRIVER
	if category == "Ropes / Belts / Pulleys":
		return _PartData.ARCH_LINK
	if category == "Electrical" or category == "Light / Flame Sources":
		return _PartData.ARCH_EMITTER
	if category == "Explosives / Projectiles" or category == "Springs / Pneumatics" or category == "Containers":
		return _PartData.ARCH_CONSUMER
	return _PartData.ARCH_STATIC

func get_parts_in_category(category_filter: int) -> Array:
	var category_map = {
		PlacementCategory.BALLS: "Balls",
		PlacementCategory.WALLS: "Walls / Floors",
		PlacementCategory.MECHANICS: "Special Mechanics",
		PlacementCategory.BALLOONS: "Balloons / Airships",
		PlacementCategory.DRIVERS: "Rotating Power Sources",
		PlacementCategory.ROPES: "Ropes / Belts / Pulleys",
		PlacementCategory.ELECTRICAL: "Electrical",
		PlacementCategory.EXPLOSIVES: "Explosives / Projectiles",
	}
	if category_filter == PlacementCategory.ALL:
		return _part_catalog
	var cat_name = category_map.get(category_filter, "")
	if cat_name == "":
		return []
	var result = []
	for entry in _part_catalog:
		if entry.get("category") == cat_name:
			result.append(entry)
	return result

func set_tool(mode: int) -> void:
	if current_tool == mode:
		return
	_cancel_current_operation()
	current_tool = mode
	tool_changed.emit(mode)
	match mode:
		ToolMode.SELECT:
			_update_status("SELECT — click to select, drag to move, F=flip, L=lock, Del=delete")
		ToolMode.PLACE:
			_update_status("PLACE — click catalog then viewport to place part")
		ToolMode.DELETE:
			_update_status("DELETE — click part to remove")
		ToolMode.CONNECT:
			_update_status("CONNECT — click source, then click target (R=rope, B=belt, E=electrical)")
		ToolMode.PREVIEW:
			_start_preview()
		ToolMode.LEVEL_INFO:
			_update_status("LEVEL INFO — edit metadata")
	parts_changed.emit()

func set_placement_category(cat: int) -> void:
	placement_category = cat

func set_placement_part_type(type_val: int) -> void:
	selected_part_type = type_val
	var entry = get_catalog_entry(type_val)
	var name = entry.get("name", "Type " + str(type_val))
	_update_status("PLACE: " + name + " (type " + str(type_val) + ") — click viewport to place")

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
		if event.button_index == MOUSE_BUTTON_RIGHT and event.pressed:
			if current_tool == ToolMode.SELECT and world_state.has_selection():
				_show_context_menu(event.position)
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
			if current_tool == ToolMode.PREVIEW:
				_stop_preview()
			set_tool(ToolMode.SELECT)
		KEY_F:
			if current_tool == ToolMode.SELECT and world_state.has_selection():
				for p in world_state.get_selected():
					p.flip_horizontal()
				parts_changed.emit()
		KEY_L:
			if current_tool == ToolMode.SELECT and world_state.has_selection():
				for p in world_state.get_selected():
					p.toggle_lock()
				parts_changed.emit()
		KEY_DELETE, KEY_BACKSPACE:
			if current_tool == ToolMode.SELECT and world_state.has_selection():
				_delete_selected()
		KEY_R:
			if current_tool == ToolMode.CONNECT:
				_connection_preview["type"] = _PartData.ConnectionType.ROPE
				_update_status("CONNECT (rope) — click source, then target")
			else:
				set_tool(ToolMode.CONNECT)
		KEY_B:
			if current_tool == ToolMode.CONNECT:
				_connection_preview["type"] = _PartData.ConnectionType.BELT
				_update_status("CONNECT (belt) — click source, then target")
		KEY_E:
			if current_tool == ToolMode.CONNECT:
				_connection_preview["type"] = _PartData.ConnectionType.ELECTRICAL
				_update_status("CONNECT (electrical) — click source, then target")
		KEY_Z:
			if event.ctrl_pressed:
				if event.shift_pressed:
					_redo_all()
				else:
					_undo_all()
		KEY_Y:
			if event.ctrl_pressed:
				_redo_all()
		KEY_S:
			if event.ctrl_pressed:
				_save_level()
		KEY_O:
			if event.ctrl_pressed:
				_load_level_dialog()
		KEY_PLUS, KEY_EQUAL, KEY_KP_ADD:
			_zoom_in()
		KEY_MINUS, KEY_KP_SUBTRACT:
			_zoom_out()
		KEY_1: set_tool(ToolMode.SELECT)
		KEY_2: set_tool(ToolMode.PLACE)
		KEY_3: set_tool(ToolMode.DELETE)
		KEY_4: set_tool(ToolMode.CONNECT)
		KEY_5:
			if current_tool == ToolMode.PREVIEW:
				_stop_preview()
			else:
				set_tool(ToolMode.PREVIEW)
		KEY_6: set_tool(ToolMode.LEVEL_INFO)

func _handle_mouse_button_event(event: InputEventMouseButton) -> void:
	if not event.pressed:
		_handle_mouse_up(event)
		return
	var mx = int(event.position.x / zoom_level) + viewport_offset_x
	var my = int(event.position.y / zoom_level) + viewport_offset_y
	match current_tool:
		ToolMode.SELECT:
			_handle_select_mouse_down(mx, my, event)
		ToolMode.PLACE:
			_handle_place_mouse_down(mx, my, event)
		ToolMode.DELETE:
			_handle_delete_mouse_down(mx, my, event)
		ToolMode.CONNECT:
			_handle_connect_mouse_down(mx, my, event)

func _handle_mouse_up(event: InputEventMouseButton) -> void:
	match current_tool:
		ToolMode.SELECT:
			_handle_select_mouse_up(event)
		ToolMode.CONNECT:
			_handle_connect_mouse_up(event)

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
	match current_tool:
		ToolMode.SELECT:
			if _drag_state.has("active") and _drag_state["active"]:
				_handle_select_drag(mx, my)
		ToolMode.PLACE:
			_placement_preview["mx"] = mx
			_placement_preview["my"] = my
		ToolMode.CONNECT:
			_connection_preview["mx"] = mx
			_connection_preview["my"] = my

func _handle_select_mouse_down(mx: int, my: int, event: InputEventMouseButton) -> void:
	var handle_info = world_state.find_handle_at(mx, my)
	if handle_info.size() > 0:
		_start_handle_drag(handle_info["part"], handle_info["handle"], mx, my)
		return
	var part = world_state.find_part_at(mx, my)
	if part != null:
		if event.shift_pressed:
			if part.is_selected:
				world_state.deselect_part(part)
			else:
				world_state.select_part(part, true)
		else:
			if not part.is_selected:
				world_state.select_part(part, false)
		_start_part_drag(mx, my)
	else:
		if not event.shift_pressed:
			world_state.deselect_all()
		_drag_state["pan_start_x"] = mx
		_drag_state["pan_start_y"] = my

func _handle_select_mouse_up(event: InputEventMouseButton) -> void:
	_end_drag()
	_end_handle_drag()

func _start_part_drag(mx: int, my: int) -> void:
	_drag_state["active"] = true
	_drag_state["start_x"] = mx
	_drag_state["start_y"] = my
	_drag_state["parts_start_positions"] = {}
	for p in world_state.get_selected():
		_drag_state["parts_start_positions"][p.id] = {"x": p.x, "y": p.y}

func _start_handle_drag(part: PartData, handle: int, mx: int, my: int) -> void:
	_drag_state["handle_active"] = true
	_drag_state["handle"] = handle
	_drag_state["part"] = part
	_drag_state["start_x"] = mx
	_drag_state["start_y"] = my
	_drag_state["orig_w"] = part.width_1
	_drag_state["orig_h"] = part.height_1
	_drag_state["orig_x"] = part.x
	_drag_state["orig_y"] = part.y

func _handle_select_drag(mx: int, my: int) -> void:
	if _drag_state.has("handle_active") and _drag_state["handle_active"]:
		_resize_handle_drag(mx, my)
		return
	var dx = mx - _drag_state.get("start_x", mx)
	var dy = my - _drag_state.get("start_y", my)
	var snap = _PartData.GRID_SIZE
	for p in world_state.get_selected():
		var start_pos = _drag_state["parts_start_positions"].get(p.id, {"x": p.x, "y": p.y})
		var new_x = _PartData.new().snap_to_grid(start_pos["x"] + dx)
		var new_y = _PartData.new().snap_to_grid(start_pos["y"] + dy)
		if new_x != p.x or new_y != p.y:
			p.x = new_x
			p.y = new_y
			p.changed.emit(p, "position")
	parts_changed.emit()

func _resize_handle_drag(mx: int, my: int) -> void:
	var handle = _drag_state.get("handle", -1)
	var part = _drag_state.get("part")
	if part == null or handle < 0:
		return
	var dx = mx - _drag_state.get("start_x", mx)
	var dy = my - _drag_state.get("start_y", my)
	var snap = _PartData.GRID_SIZE
	match handle:
		_PartData.HANDLE_UL:
			var new_w = clampi(_drag_state["orig_w"] - dx, 16, 1024)
			var new_h = clampi(_drag_state["orig_h"] - dy, 16, 1024)
			part.x = _drag_state["orig_x"] + _drag_state["orig_w"] - new_w
			part.y = _drag_state["orig_y"] + _drag_state["orig_h"] - new_h
			part.width_1 = (new_w / snap) * snap
			part.height_1 = (new_h / snap) * snap
		_PartData.HANDLE_UR:
			var new_w = clampi(_drag_state["orig_w"] + dx, 16, 1024)
			var new_h = clampi(_drag_state["orig_h"] - dy, 16, 1024)
			part.y = _drag_state["orig_y"] + _drag_state["orig_h"] - new_h
			part.width_1 = (new_w / snap) * snap
			part.height_1 = (new_h / snap) * snap
		_PartData.HANDLE_BR:
			var new_w = clampi(_drag_state["orig_w"] + dx, 16, 1024)
			var new_h = clampi(_drag_state["orig_h"] + dy, 16, 1024)
			part.width_1 = (new_w / snap) * snap
			part.height_1 = (new_h / snap) * snap
		_PartData.HANDLE_BL:
			var new_w = clampi(_drag_state["orig_w"] - dx, 16, 1024)
			var new_h = clampi(_drag_state["orig_h"] + dy, 16, 1024)
			part.x = _drag_state["orig_x"] + _drag_state["orig_w"] - new_w
			part.width_1 = (new_w / snap) * snap
			part.height_1 = (new_h / snap) * snap
		_PartData.HANDLE_U:
			var new_h = clampi(_drag_state["orig_h"] - dy, 16, 1024)
			part.y = _drag_state["orig_y"] + _drag_state["orig_h"] - new_h
			part.height_1 = (new_h / snap) * snap
		_PartData.HANDLE_B:
			var new_h = clampi(_drag_state["orig_h"] + dy, 16, 1024)
			part.height_1 = (new_h / snap) * snap
		_PartData.HANDLE_L:
			var new_w = clampi(_drag_state["orig_w"] - dx, 16, 1024)
			part.x = _drag_state["orig_x"] + _drag_state["orig_w"] - new_w
			part.width_1 = (new_w / snap) * snap
		_PartData.HANDLE_R:
			var new_w = clampi(_drag_state["orig_w"] + dx, 16, 1024)
			part.width_1 = (new_w / snap) * snap
	part.changed.emit(part, "size")
	parts_changed.emit()

func _end_drag() -> void:
	_drag_state.clear()

func _end_handle_drag() -> void:
	_drag_state.erase("handle_active")

func _handle_place_mouse_down(mx: int, my: int, _event: InputEventMouseButton) -> void:
	var snap = _PartData.GRID_SIZE
	mx = (mx / snap) * snap
	my = (my / snap) * snap
	var arch = get_archetype_for_type(selected_part_type)
	var new_part = PartData.new(-1, selected_part_type, mx, my)
	new_part.archetype = arch
	new_part.is_moving = (arch == _PartData.ARCH_KINETIC)
	var entry = get_catalog_entry(selected_part_type)
	if not entry.is_empty():
		new_part.anm_name = entry.get("anm_name", "")
		new_part.solve_name = entry.get("solve_name", "")
		new_part.category = entry.get("category", "")
		new_part.state_limit_upper = entry.get("anm_num_states", 8)
	var id = world_state.add_part(new_part)
	if id >= 0:
		parts_changed.emit()
		_update_status("Placed " + new_part.solve_name + " at (" + str(mx) + ", " + str(my) + ")")

func _handle_delete_mouse_down(mx: int, my: int, _event: InputEventMouseButton) -> void:
	var part = world_state.find_part_at(mx, my)
	if part != null:
		world_state.remove_part(part)
		parts_changed.emit()
		_update_status("Deleted " + part.solve_name)

func _handle_connect_mouse_down(mx: int, my: int, _event: InputEventMouseButton) -> void:
	var part = world_state.find_part_at(mx, my)
	if part == null:
		return
	if not _connection_preview.has("source"):
		_connection_preview["source"] = part
		_connection_preview["mx"] = mx
		_connection_preview["my"] = my
		_update_status("CONNECT: source=" + part.solve_name + " — click target")
	else:
		var source = _connection_preview["source"]
		var conn_type = _connection_preview.get("type", _PartData.ConnectionType.ROPE)
		if part.id != source.id:
			_connect_parts(source, part, conn_type)
			_connection_preview.clear()
			parts_changed.emit()

func _handle_connect_mouse_up(_event: InputEventMouseButton) -> void:
	pass

func _connect_parts(from_part: PartData, to_part: PartData, conn_type: int) -> void:
	world_state.add_connection(from_part.id, to_part.id, conn_type)
	var type_names = ["rope", "belt", "electrical"]
	_update_status("Connected " + from_part.solve_name + " → " + to_part.solve_name + " (" + type_names[conn_type] + ")")

func _delete_selected() -> void:
	var selected = world_state.get_selected()
	for p in selected:
		world_state.remove_part(p)
	parts_changed.emit()
	_update_status("Deleted " + str(selected.size()) + " part(s)")

func _cancel_current_operation() -> void:
	_connection_preview.clear()
	_placement_preview.clear()
	_end_drag()
	_end_handle_drag()

func _on_selection_changed(selected: Array) -> void:
	parts_changed.emit()

func _on_part_added(part_data: PartData) -> void:
	parts_changed.emit()

func _on_part_removed(part_data: PartData) -> void:
	parts_changed.emit()

func _on_connections_changed() -> void:
	parts_changed.emit()

func _undo_all() -> void:
	for p in world_state.parts_data:
		p.undo()

func _redo_all() -> void:
	for p in world_state.parts_data:
		p.redo()

func _zoom_in() -> void:
	zoom_level = mini(zoom_level + ZOOM_STEP, ZOOM_MAX)
	zoom_changed.emit(zoom_level)
	_update_status("Zoom: " + str(zoom_level) + "x")

func _zoom_out() -> void:
	zoom_level = maxi(zoom_level - ZOOM_STEP, ZOOM_MIN)
	zoom_changed.emit(zoom_level)
	_update_status("Zoom: " + str(zoom_level) + "x")

func _show_context_menu(pos: Vector2) -> void:
	_update_status("Context menu at (" + str(int(pos.x)) + ", " + str(int(pos.y)) + ") — use Del to delete, F to flip, L to lock")

func _save_level() -> void:
	_update_status("Save: implement FileDialog")

func _load_level_dialog() -> void:
	_update_status("Load: implement FileDialog")

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
		_preview_solver.sync_to_world_state(world_state)
		_preview_solver = null
	_preview_simulation = false
	parts_changed.emit()
	_update_status("PREVIEW stopped — returned to editor")

func _on_preview_tick(tick: int) -> void:
	parts_changed.emit()

func _on_preview_solution(tick: int) -> void:
	_update_status("PREVIEW: Solution achieved at tick " + str(tick) + "! Press ESC to return to editor")
	_preview_simulation = false

func _process(_delta: float) -> void:
	if current_tool != ToolMode.PREVIEW or not _preview_simulation:
		return
	if _preview_solver == null or not _preview_solver.is_running:
		return
	var current_time_ms = Time.get_ticks_msec()
	var elapsed_ms = current_time_ms - _preview_last_time_ms
	_preview_last_time_ms = current_time_ms
	if elapsed_ms > 100:
		elapsed_ms = 100
	_preview_accum_ms += elapsed_ms
	var ms_per_tick = 1000.0 / 60.0
	while _preview_accum_ms >= ms_per_tick:
		_preview_accum_ms -= ms_per_tick
		_preview_solver.step()
		if not _preview_solver.is_running:
			break
	parts_changed.emit()

func _update_status(msg: String) -> void:
	status_update.emit(msg)

func _draw() -> void:
	var vp_w = int(get_viewport_rect().size.x)
	var vp_h = int(get_viewport_rect().size.y)
	for i in range(0, vp_w, _PartData.GRID_SIZE):
		var start = Vector2(i - viewport_offset_x, 0) * zoom_level
		var end = Vector2(i - viewport_offset_x, vp_h) * zoom_level
		var alpha = 0.15 if (i / _PartData.GRID_SIZE) % 4 == 0 else 0.07
		var c = Color(0.5, 0.5, 0.5, alpha)
		draw_line(start, end, c, 1.0)
	for j in range(0, vp_h, _PartData.GRID_SIZE):
		var start = Vector2(0, j - viewport_offset_y) * zoom_level
		var end = Vector2(vp_w, j - viewport_offset_y) * zoom_level
		var alpha = 0.15 if (j / _PartData.GRID_SIZE) % 4 == 0 else 0.07
		var c = Color(0.5, 0.5, 0.5, alpha)
		draw_line(start, end, c, 1.0)
	for p in world_state.parts_data:
		_draw_part(p)
	if _placement_preview.has("mx"):
		var mx = _placement_preview["mx"]
		var my = _placement_preview["my"]
		var snap = _PartData.GRID_SIZE
		mx = (mx / snap) * snap
		my = (my / snap) * snap
		var entry = get_catalog_entry(selected_part_type)
		var arch = get_archetype_for_type(selected_part_type)
		var color = _get_arch_color(arch)
		var r = Rect2(Vector2((mx - viewport_offset_x) * zoom_level, (my - viewport_offset_y) * zoom_level), Vector2(32 * zoom_level, 32 * zoom_level))
		draw_rect(r, Color(color.r, color.g, color.b, 0.4))
	if _connection_preview.has("source"):
		var src = _connection_preview["source"]
		var mx = _connection_preview.get("mx", 0)
		var my = _connection_preview.get("my", 0)
		var start_pos = Vector2((src.x + src.width_1 / 2 - viewport_offset_x) * zoom_level,
		                       (src.y + src.height_1 / 2 - viewport_offset_y) * zoom_level)
		var end_pos = Vector2((mx - viewport_offset_x) * zoom_level, (my - viewport_offset_y) * zoom_level)
		var conn_type = _connection_preview.get("type", _PartData.ConnectionType.ROPE)
		var line_color = Color(1, 0.8, 0.2) if conn_type == 0 else Color(0.8, 0.8, 0.2) if conn_type == 1 else Color(0.2, 0.8, 1)
		draw_line(start_pos, end_pos, line_color, 2.0)

func _draw_part(p: PartData) -> void:
	var color = _get_arch_color(p.archetype)
	var rect = Rect2(Vector2((p.x - viewport_offset_x) * zoom_level, (p.y - viewport_offset_y) * zoom_level),
	                 Vector2(p.width_1 * zoom_level, p.height_1 * zoom_level))
	draw_rect(rect, Color(color.r, color.g, color.b, 0.2))
	draw_rect(rect, color, false, 1.0)
	if p.is_selected:
		_draw_selection_box(p)
		_draw_handles(p)

func _draw_selection_box(p: PartData) -> void:
	var rect = Rect2(Vector2((p.x - viewport_offset_x) * zoom_level, (p.y - viewport_offset_y) * zoom_level),
	                 Vector2(p.width_1 * zoom_level, p.height_1 * zoom_level))
	var sel_color = Color(0.3, 0.8, 1.0, 0.9)
	var inner = rect.grow(-2)
	draw_rect(inner, sel_color, false, 1.5)
	if p.name != "":
		var label_pos = Vector2(rect.position.x, rect.position.y - 12 * zoom_level)
		var txt = p.name if p.solve_name == "" else p.solve_name
		draw_string(ThemeDB.fallback_font, label_pos, txt, HORIZONTAL_ALIGNMENT_LEFT, -1, 10 * zoom_level, Color(1, 1, 0.8))

func _draw_handles(p: PartData) -> void:
	for i in range(8):
		var hp = p.get_handle_position(i)
		var screen_pos = Vector2((hp.x - viewport_offset_x) * zoom_level, (hp.y - viewport_offset_y) * zoom_level)
		var handle_rect = Rect2(screen_pos - Vector2(_PartData.HANDLE_SIZE * zoom_level / 2, _PartData.HANDLE_SIZE * zoom_level / 2),
		                        Vector2(_PartData.HANDLE_SIZE * zoom_level, _PartData.HANDLE_SIZE * zoom_level))
		draw_rect(handle_rect, Color(1, 1, 0.2), true)
		draw_rect(handle_rect, Color(0.8, 0.8, 0), false, 1.0)

func _get_arch_color(arch: int) -> Color:
	match arch:
		_PartData.ARCH_STATIC:    return Color(0.4, 0.4, 0.4)
		_PartData.ARCH_KINETIC:   return Color(0.3, 0.3, 0.8)
		_PartData.ARCH_DRIVER:    return Color(0.6, 0.6, 0.6)
		_PartData.ARCH_LINK:      return Color(0.5, 0.3, 0.1)
		_PartData.ARCH_EMITTER:   return Color(0.9, 0.2, 0.2)
		_PartData.ARCH_CONSUMER:  return Color(0.3, 0.8, 0.8)
	return Color(0.5, 0.5, 0.5)

func get_level_data() -> Dictionary:
	return world_state.to_level_data()

func load_level_data(data: Dictionary) -> void:
	world_state.from_level_data(data)
	parts_changed.emit()

func new_level() -> void:
	world_state.clear()
	parts_changed.emit()
	_update_status("New level — empty workspace")