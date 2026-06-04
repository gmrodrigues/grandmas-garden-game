extends Control
class_name EditorController

enum ToolMode {
	MODE_SELECT,
	MODE_PLACE,
	MODE_DELETE,
	MODE_CONNECT,
	MODE_PREVIEW,
	MODE_LEVEL_INFO,
}

var current_mode: ToolMode = ToolMode.MODE_SELECT
var selected_part_type: int = 0
var selected_part_idx: int = -1
var world: WorldState
var solver: PhysicsSolver
var checker: SolutionChecker
var preview_snapshot: Dictionary = {}
var preview_running: bool = false
var preview_solved: bool = false
var preview_ticks: int = 0
var connect_source_idx: int = -1
var connect_preview_line: PackedVector2Array = []
var dragging: bool = false
var drag_start: Vector2 = Vector2.ZERO
var drag_part_start: Vector2 = Vector2.ZERO
var panning: bool = false
var pan_start: Vector2 = Vector2.ZERO
var dragging_handle: bool = false
var handle_drag_start: Vector2 = Vector2.ZERO
var handle_drag_part_size: Vector2 = Vector2.ZERO
var handle_drag_idx: int = -1
var scroll: Vector2 = Vector2.ZERO
var zoom: float = 1.0
var zoom_min: float = 0.25
var zoom_max: float = 4.0
var is_dirty: bool = false
var level_title: String = "Untitled"
var level_goal: String = ""
var level_bg_color: int = 0
var level_pressure: int = 67
var level_gravity: int = 272
var level_music_track: int = 1000

const VIEWPORT_X: int = 10
const VIEWPORT_Y: int = 50
const VIEWPORT_W: int = 560
const VIEWPORT_H: int = 377
const CATALOG_W: int = 200
const CATALOG_X: int = VIEWPORT_X + VIEWPORT_W
const SNAP_GRID: int = 16
const MIN_PART_SIZE: int = 8

var canvas: Node2D
var selection_handles_root: Node2D
var part_nodes: Dictionary = {}
var status_label: Label
var mode_label: Label
var zoom_label: Label
var catalog_vbox: VBoxContainer
var dialog_active: bool = false
var anm_renderer: AnmRenderer
var solution_conditions_store: Array[SolutionCondition] = []
var undo_stack: Array = []
var redo_stack: Array = []
const UNDO_LIMIT: int = 50

func _ready():
	world = WorldState.new()
	solver = PhysicsSolver.new(world)
	anm_renderer = AnmRenderer.new()
	_build_ui()
	_new_level()
	print("Editor ready — ", PartDatabase.part_catalog.size(), " parts available")
	var args = OS.get_cmdline_args()
	var level_idx = args.find("--level")
	if level_idx >= 0 and level_idx + 1 < args.size():
		_do_load(args[level_idx + 1])

func _process(_delta):
	if preview_running and not preview_solved:
		solver.step()
		preview_ticks = solver.tick_counter
		_sync_part_nodes()
		queue_redraw()
		if checker:
			var result = checker.check(world)
			if result[0]:
				preview_solved = true
				status_label.text = "LEVEL SOLVED!"
		if preview_ticks >= PhysicsSolver.MAX_TICKS:
			status_label.text = "TIMEOUT"
			_stop_preview()

func _build_ui():
	var vbox = VBoxContainer.new()
	vbox.anchors_preset = Control.PRESET_FULL_RECT
	add_child(vbox)

	var toolbar = HBoxContainer.new()
	toolbar.custom_minimum_size.y = 32
	vbox.add_child(toolbar)

	var main = HSplitContainer.new()
	main.size_flags_vertical = Control.SIZE_EXPAND_FILL
	vbox.add_child(main)

	var viewport_bg = ColorRect.new()
	viewport_bg.color = Color(0.16, 0.18, 0.22)
	viewport_bg.anchors_preset = Control.PRESET_FULL_RECT
	var vp_container = Control.new()
	vp_container.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	vp_container.size_flags_vertical = Control.SIZE_EXPAND_FILL
	vp_container.add_child(viewport_bg)

	canvas = Node2D.new()
	canvas.position = Vector2(VIEWPORT_X, VIEWPORT_Y)
	vp_container.add_child(canvas)

	selection_handles_root = Node2D.new()
	selection_handles_root.name = "Handles"
	canvas.add_child(selection_handles_root)

	main.add_child(vp_container)

	var catalog_container = Control.new()
	catalog_container.custom_minimum_size.x = CATALOG_W
	main.add_child(catalog_container)
	_build_catalog(catalog_container)

	_build_toolbar(toolbar)

	var status_bar = HBoxContainer.new()
	status_bar.custom_minimum_size.y = 22
	vbox.add_child(status_bar)

	mode_label = Label.new()
	mode_label.add_theme_color_override("font_color", Color(0.9, 0.85, 0.2))
	status_bar.add_child(mode_label)
	status_label = Label.new()
	status_label.add_theme_color_override("font_color", Color(0.7, 0.7, 0.7))
	status_bar.add_child(status_label)
	zoom_label = Label.new()
	zoom_label.add_theme_color_override("font_color", Color(0.6, 0.8, 1.0))
	status_bar.add_child(zoom_label)
	_set_mode_label()

func _build_toolbar(toolbar: HBoxContainer):
	var buttons = {
		"New": _new_level, "Save": _save_dialog, "Load": _load_dialog,
		"Select": func(): _set_mode(ToolMode.MODE_SELECT),
		"Place": func(): _set_mode(ToolMode.MODE_PLACE),
		"Delete": func(): _set_mode(ToolMode.MODE_DELETE),
		"Connect": func(): _set_mode(ToolMode.MODE_CONNECT),
		"Preview": _toggle_preview,
		"Info": func(): _set_mode(ToolMode.MODE_LEVEL_INFO),
		"Conditions": _open_condition_editor,
	}
	for text in buttons:
		var b = Button.new()
		b.text = text
		b.pressed.connect(buttons[text])
		toolbar.add_child(b)

func _build_catalog(container: Control):
	var label = Label.new()
	label.text = "  Parts"
	label.add_theme_color_override("font_color", Color(0.9, 0.9, 0.5))
	label.add_theme_font_size_override("font_size", 14)
	container.add_child(label)

	var scroll = ScrollContainer.new()
	scroll.anchors_preset = Control.PRESET_FULL_RECT
	scroll.anchor_top = 0.06
	container.add_child(scroll)

	catalog_vbox = VBoxContainer.new()
	catalog_vbox.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	scroll.add_child(catalog_vbox)
	_populate_catalog()

func _populate_catalog():
	var by_cat: Dictionary = {}
	for pt in PartDatabase.part_catalog:
		var item = PartDatabase.part_catalog[pt]
		var cat = item.get("category", "Uncategorized")
		if not by_cat.has(cat):
			by_cat[cat] = []
		by_cat[cat].append(item)

	for cat in by_cat.keys():
		var items = by_cat[cat]
		var hdr = Label.new()
		hdr.text = cat
		hdr.add_theme_color_override("font_color", Color(0.8, 0.8, 0.4))
		hdr.add_theme_font_size_override("font_size", 12)
		catalog_vbox.add_child(hdr)
		for item in items:
			var pt = item["part_type"]
			var name = item.get("name", "Part " + str(pt))
			var hb = HBoxContainer.new()
			var tx = TextureRect.new()
			tx.custom_minimum_size = Vector2(28, 28)
			tx.expand_mode = TextureRect.EXPAND_FIT_WIDTH_PROPORTIONAL
			hb.add_child(tx)
			var lbl = Label.new()
			lbl.text = name
			hb.add_child(lbl)
			catalog_vbox.add_child(hb)

			var anm = AnmDatabase.get_anm_for_part(pt)
			if anm != "":
				var img = anm_renderer.render_frame(anm, AnmDatabase.get_default_state_id(anm))
				if img:
					var tex = ImageTexture.create_from_image(img)
					var w = min(28, tex.get_width())
					var h = min(28, tex.get_height())
					tx.texture = tex
					tx.custom_minimum_size = Vector2(w, h)
			tx.gui_input.connect(_on_icon_input.bind(pt))

func _on_icon_input(event: InputEvent, pt: int):
	if event is InputEventMouseButton and event.pressed and event.button_index == MOUSE_BUTTON_LEFT:
		selected_part_type = pt
		_set_mode(ToolMode.MODE_PLACE)

func _set_mode(mode: ToolMode):
	current_mode = mode
	connect_source_idx = -1
	connect_preview_line.clear()
	_set_mode_label()

func _set_mode_label():
	var names = ["SELECT", "PLACE", "DELETE", "CONNECT", "PREVIEW", "LEVEL INFO"]
	var text = names[current_mode]
	if current_mode == ToolMode.MODE_PLACE:
		var nm = PartDatabase.get_part_name(selected_part_type)
		text += " [" + str(selected_part_type) + "] " + nm
	mode_label.text = text

func _input(event: InputEvent):
	if dialog_active:
		return
	if event is InputEventKey and event.pressed and not event.echo:
		_handle_key(event)
	if event is InputEventMouseButton:
		_handle_mouse_click(event)
	if event is InputEventMouseMotion:
		_handle_mouse_move(event)

func _handle_key(event: InputEventKey):
	var ctrl = event.ctrl_pressed
	match event.keycode:
		KEY_S: if not ctrl: _set_mode(ToolMode.MODE_SELECT)
		KEY_P: if not ctrl: _set_mode(ToolMode.MODE_PLACE)
		KEY_D: if not ctrl: _set_mode(ToolMode.MODE_DELETE)
		KEY_C: if not ctrl: _set_mode(ToolMode.MODE_CONNECT)
		KEY_SPACE: _toggle_preview()
		KEY_I: if not ctrl: _set_mode(ToolMode.MODE_LEVEL_INFO)
		KEY_F: _flip_selected()
		KEY_L: _lock_selected()
		KEY_DELETE, KEY_BACKSPACE: _delete_selected()
		KEY_N: if not ctrl: _new_level()
		KEY_Z:
			if ctrl: _undo()
			else: zoom = 1.0
		KEY_Y: if ctrl: _redo()
		KEY_EQUAL, KEY_PLUS: zoom = min(zoom * 1.25, zoom_max)
		KEY_MINUS: zoom = max(zoom / 1.25, zoom_min)
		KEY_0: scroll = Vector2.ZERO
	if ctrl:
		match event.keycode:
			KEY_S: _save_dialog()
			KEY_L: _load_dialog()

func _handle_mouse_click(event: InputEventMouseButton):
	var mx = event.position.x
	var my = event.position.y

	if event.button_index == MOUSE_BUTTON_WHEEL_UP:
		if mx >= CATALOG_X:
			return
		zoom = min(zoom * 1.25, zoom_max)
		return
	if event.button_index == MOUSE_BUTTON_WHEEL_DOWN:
		if mx >= CATALOG_X:
			return
		zoom = max(zoom / 1.25, zoom_min)
		return
	if event.button_index == MOUSE_BUTTON_MIDDLE:
		panning = event.pressed
		pan_start = event.position
		return
	if not event.pressed:
		dragging = false
		dragging_handle = false
		handle_drag_idx = -1
		panning = false
		return

	if _is_in_viewport(mx, my):
		var lx = _to_level_x(mx)
		var ly = _to_level_y(my)

		match current_mode:
			ToolMode.MODE_SELECT:
				var handle_idx = _hit_test_handle(mx, my)
				if handle_idx >= 0:
					_push_undo()
					dragging_handle = true
					handle_drag_idx = handle_idx
					handle_drag_start = Vector2(mx, my)
					handle_drag_part_size = Vector2(world.parts[selected_part_idx].width_1, world.parts[selected_part_idx].height_1)
				else:
					var idx = _hit_test(lx, ly)
					selected_part_idx = idx
					if idx >= 0:
						_push_undo()
						dragging = true
						drag_start = Vector2(mx, my)
						var p = world.parts[idx]
						drag_part_start = Vector2(p.x, p.y)
			ToolMode.MODE_PLACE:
				_push_undo()
				_place_part(lx, ly)
			ToolMode.MODE_DELETE:
				var idx = _hit_test(lx, ly)
				if idx >= 0:
					_push_undo()
					_delete_part(idx)
			ToolMode.MODE_CONNECT:
				var idx = _hit_test(lx, ly)
				if idx >= 0:
					if connect_source_idx < 0:
						connect_source_idx = idx
					else:
						_push_undo()
						var s = world.parts[connect_source_idx]
						if s: s.connected_1 = idx
						connect_source_idx = -1
						connect_preview_line.clear()

	queue_redraw()

func _handle_mouse_move(event: InputEventMouseMotion):
	var mx = event.position.x
	var my = event.position.y

	if panning:
		scroll -= (event.relative / zoom)
		queue_redraw()
		return

	if dragging and selected_part_idx >= 0:
		var p = world.parts[selected_part_idx]
		if p:
			var dx = event.relative.x / zoom
			var dy = event.relative.y / zoom
			p.x = _snap(drag_part_start.x + dx)
			p.y = _snap(drag_part_start.y + dy)
			p.sync_pos()
			_update_part_node(selected_part_idx)
			queue_redraw()
		return

	if dragging_handle and selected_part_idx >= 0:
		var p = world.parts[selected_part_idx]
		if p:
			var dx = event.relative.x / zoom
			var dy = event.relative.y / zoom
			var dw = handle_drag_part_size.x
			var dh = handle_drag_part_size.y
			var min_s = MIN_PART_SIZE
			if handle_drag_idx == 0 or handle_drag_idx == 6 or handle_drag_idx == 2:
				p.x = _snap(min(p.x + dx, p.x + dw - min_s))
				dw = max(min_s, dw - dx)
			if handle_drag_idx == 1 or handle_drag_idx == 7 or handle_drag_idx == 3:
				dw = max(min_s, dw + dx)
			if handle_drag_idx == 0 or handle_drag_idx == 4 or handle_drag_idx == 1:
				p.y = _snap(min(p.y + dy, p.y + dh - min_s))
				dh = max(min_s, dh - dy)
			if handle_drag_idx == 2 or handle_drag_idx == 5 or handle_drag_idx == 3:
				dh = max(min_s, dh + dy)
			p.width_1 = _snap(dw)
			p.height_1 = _snap(dh)
			p.sync_pos()
			_update_part_node(selected_part_idx)
			queue_redraw()
		return

	if connect_source_idx >= 0 and current_mode == ToolMode.MODE_CONNECT:
		var p = world.parts[connect_source_idx]
		if p:
			var sx = _to_screen_x(p.x + p.width_1 / 2.0)
			var sy = _to_screen_y(p.y + p.height_1 / 2.0)
			connect_preview_line = PackedVector2Array([Vector2(sx, sy), event.position])
			queue_redraw()

func _is_in_viewport(mx: float, my: float) -> bool:
	return mx >= VIEWPORT_X and mx <= VIEWPORT_X + VIEWPORT_W and my >= VIEWPORT_Y and my <= VIEWPORT_Y + VIEWPORT_H

func _to_level_x(sx: float) -> float:
	return (sx - VIEWPORT_X) / zoom + scroll.x

func _to_level_y(sy: float) -> float:
	return (sy - VIEWPORT_Y) / zoom + scroll.y

func _to_screen_x(lx: float) -> float:
	return (lx - scroll.x) * zoom + VIEWPORT_X

func _to_screen_y(ly: float) -> float:
	return (ly - scroll.y) * zoom + VIEWPORT_Y

func _snap(v: float) -> int:
	return int(floor(v / SNAP_GRID)) * SNAP_GRID

func _get_handle_positions(p: PartData) -> Array:
	var sx = _to_screen_x(p.x)
	var sy = _to_screen_y(p.y)
	var sw = p.width_1 * zoom
	var sh = p.height_1 * zoom
	var hs = max(4, int(6 * zoom))
	var half = hs / 2.0
	return [
		Rect2(sx - half, sy - half, hs, hs),                    # 0: top-left
		Rect2(sx + sw - half, sy - half, hs, hs),               # 1: top-right
		Rect2(sx - half, sy + sh - half, hs, hs),               # 2: bottom-left
		Rect2(sx + sw - half, sy + sh - half, hs, hs),          # 3: bottom-right
		Rect2(sx + sw / 2 - half, sy - half, hs, hs),           # 4: top-center
		Rect2(sx + sw / 2 - half, sy + sh - half, hs, hs),      # 5: bottom-center
		Rect2(sx - half, sy + sh / 2 - half, hs, hs),           # 6: left-center
		Rect2(sx + sw - half, sy + sh / 2 - half, hs, hs),      # 7: right-center
	]

func _hit_test_handle(mx: float, my: float) -> int:
	if selected_part_idx < 0 or selected_part_idx >= world.parts.size():
		return -1
	var p = world.parts[selected_part_idx]
	if not p:
		return -1
	var handles = _get_handle_positions(p)
	var mpos = Vector2(mx, my)
	for i in range(handles.size()):
		if handles[i].has_point(mpos):
			return i
	return -1

func _hit_test(lx: float, ly: float) -> int:
	for i in range(world.parts.size() - 1, -1, -1):
		var p = world.parts[i]
		if lx >= p.x and lx <= p.x + p.width_1 and ly >= p.y and ly <= p.y + p.height_1:
			return i
	return -1

func _place_part(lx: float, ly: float):
	var sx = _snap(lx)
	var sy = _snap(ly)
	var pd = PartData.new(selected_part_type, sx, sy)
	pd.flags_1 |= PartData.FLAG_MOVING
	world.add_part(pd)
	_spawn_part_node(pd)
	selected_part_idx = world.parts.size() - 1
	is_dirty = true

func _delete_part(idx: int):
	if idx < 0 or idx >= world.parts.size(): return
	world.remove_part(idx)
	if part_nodes.has(idx):
		part_nodes[idx].queue_free()
		part_nodes.erase(idx)
	_reindex()
	if selected_part_idx == idx: selected_part_idx = -1
	elif selected_part_idx > idx: selected_part_idx -= 1
	queue_redraw()

func _delete_selected():
	if selected_part_idx >= 0 and not preview_running:
		_delete_part(selected_part_idx)

func _flip_selected():
	var p = _get_part(selected_part_idx)
	if p:
		_push_undo()
		p.appearance ^= PartData.FLAG_FLIP
		_update_part_node(selected_part_idx)
		queue_redraw()

func _lock_selected():
	var p = _get_part(selected_part_idx)
	if p:
		_push_undo()
		p.is_moving = not p.is_moving
		if p.is_moving: p.flags_1 |= PartData.FLAG_MOVING
		else: p.flags_1 &= ~PartData.FLAG_MOVING

func _get_part(idx: int) -> PartData:
	if idx >= 0 and idx < world.parts.size(): return world.parts[idx]
	return null

func _spawn_part_node(pd: PartData):
	var idx = world.parts.size() - 1
	var s = Sprite2D.new()
	s.name = "P" + str(idx)
	s.set_meta("pdx", idx)
	canvas.add_child(s)
	part_nodes[idx] = s
	_update_sprite(s, pd)

func _update_part_node(idx: int):
	var s = part_nodes.get(idx)
	var p = _get_part(idx)
	if s and p:
		s.position = Vector2(p.x, p.y)
		_update_sprite(s, p)

func _update_sprite(s: Sprite2D, p: PartData):
	var tex = null
	var anm = AnmDatabase.get_anm_for_part(p.part_type)
	if anm != "":
		var img = anm_renderer.render_frame(anm, AnmDatabase.get_default_state_id(anm), p.state_counter, p.width_1, p.height_1)
		if img:
			if p.appearance & PartData.FLAG_FLIP: img.flip_x()
			tex = ImageTexture.create_from_image(img)
	if tex:
		s.texture = tex
		s.centered = false
		s.scale = Vector2.ONE
	else:
		var img = Image.create(max(p.width_1, 1), max(p.height_1, 1), false, Image.FORMAT_RGBA8)
		img.fill(Color(0.5, 0.5, 0.6, 0.7))
		tex = ImageTexture.create_from_image(img)
		s.texture = tex
		s.centered = false

func _sync_part_nodes():
	for i in range(world.parts.size()):
		var s = part_nodes.get(i)
		var p = world.parts[i]
		if s and p:
			s.position = Vector2(p.x, p.y)

func _reindex():
	var new_nodes: Dictionary = {}
	for i in range(world.parts.size()):
		var s = part_nodes.get(i)
		if s:
			s.name = "P" + str(i)
			s.set_meta("pdx", i)
			new_nodes[i] = s
	part_nodes = new_nodes
	queue_redraw()

func _setup_world_callbacks():
	world.on_collision = _on_world_collision
	world.on_state_change = _on_world_state_change

func _on_world_collision(a: PartData, b: PartData):
	pass

func _on_world_state_change(part: PartData):
	pass

func _new_level():
	_push_undo()
	world = WorldState.new()
	solver = PhysicsSolver.new(world)
	_setup_world_callbacks()
	checker = null
	selected_part_idx = -1
	preview_running = false
	solution_conditions_store.clear()
	for c in canvas.get_children():
		if c.name != "Handles":
			c.queue_free()
	part_nodes.clear()
	level_title = "Untitled"
	status_label.text = "New level"
	queue_redraw()

func _save_dialog():
	var fd = FileDialog.new()
	fd.file_mode = FileDialog.FILE_MODE_SAVE_FILE
	fd.add_filter("*.yaml", "TIM2 Level")
	add_child(fd)
	fd.file_selected.connect(_do_save)
	fd.file_selected.connect(fd.queue_free)
	fd.canceled.connect(fd.queue_free)
	fd.popup_centered(Vector2i(500, 400))

func _do_save(path: String):
	var parts: Array = []
	for i in range(world.parts.size()):
		var p = world.parts[i]
		parts.append({
			"part_type": p.part_type, "x": p.x, "y": p.y,
			"appearance": p.appearance,
			"width_1": p.width_1, "height_1": p.height_1,
			"width_2": p.width_2, "height_2": p.height_2,
			"flags_1": p.flags_1, "flags_2": p.flags_2, "flags_3": p.flags_3,
			"behavior": p.behavior,
			"belt_anchor_x": p.belt_anchor_x, "belt_anchor_y": p.belt_anchor_y,
			"belt_line_distance": p.belt_line_distance,
			"rope_1_anchor_x": p.rope_1_anchor_x, "rope_1_anchor_y": p.rope_1_anchor_y,
			"rope_2_anchor_x": p.rope_2_anchor_x, "rope_2_anchor_y": p.rope_2_anchor_y,
			"connected_1": p.connected_1, "connected_2": p.connected_2,
			"outlet_plugged_1": p.outlet_plugged_1, "outlet_plugged_2": p.outlet_plugged_2,
			"rope_segment_length": p.rope_segment_length,
			"density": p.density, "elasticity": p.elasticity,
			"friction_extra": p.friction_extra, "gravity_buoyancy": p.gravity_buoyancy,
		})
	var data = {
		"title": level_title, "goal": level_goal, "bg_color": level_bg_color,
		"pressure": level_pressure, "gravity": level_gravity, "music_track": level_music_track,
		"parts": parts, "solution_conditions": [], "solution_delay": 0,
	}
	LevelSerializer.save_yaml(path, data)
	status_label.text = "Saved: " + path.get_file()

func _load_dialog():
	var fd = FileDialog.new()
	fd.file_mode = FileDialog.FILE_MODE_OPEN_FILE
	fd.add_filter("*.yaml", "TIM2 Level")
	add_child(fd)
	fd.file_selected.connect(_do_load)
	fd.file_selected.connect(fd.queue_free)
	fd.canceled.connect(fd.queue_free)
	fd.popup_centered(Vector2i(500, 400))

func _do_load(path: String):
	var data = LevelSerializer.load_yaml(path)
	_new_level()
	for d in data.get("parts", []):
		var pd = PartData.new(d.get("part_type", 0), d.get("x", 0), d.get("y", 0))
		pd.width_1 = d.get("width_1", 32)
		pd.height_1 = d.get("height_1", 32)
		pd.width_2 = d.get("width_2", 32)
		pd.height_2 = d.get("height_2", 32)
		pd.appearance = d.get("appearance", 0)
		var flags = d.get("flags", {})
		pd.flags_1 = flags.get("flag_1", "0x0000").trim_prefix("'").trim_suffix("'").hex_to_int() if flags.has("flag_1") else d.get("flags_1", 0)
		pd.flags_2 = flags.get("flag_2", "0x0000").trim_prefix("'").trim_suffix("'").hex_to_int() if flags.has("flag_2") else d.get("flags_2", 0)
		pd.flags_3 = flags.get("flag_3", "0x0000").trim_prefix("'").trim_suffix("'").hex_to_int() if flags.has("flag_3") else d.get("flags_3", 0)
		world.add_part(pd)
		_spawn_part_node(pd)
	level_title = data.get("title", level_title)
	level_goal = data.get("goal", level_goal)
	status_label.text = "Loaded: " + path.get_file()
	solution_conditions_store.clear()
	for d in data.get("solution_conditions", []):
		var sc = SolutionCondition.new()
		sc.from_dict(d)
		solution_conditions_store.append(sc)
	queue_redraw()

func _draw():
	_draw_grid()
	_draw_selection()
	_draw_connection_line()

func _draw_grid():
	var grid_color = Color(0.25, 0.3, 0.35, 0.5)
	var step = SNAP_GRID
	var start_x = floor(scroll.x / step) * step
	var start_y = floor(scroll.y / step) * step
	var end_x = scroll.x + (VIEWPORT_W / zoom)
	var end_y = scroll.y + (VIEWPORT_H / zoom)
	var gx = start_x
	while gx <= end_x:
		var sx = _to_screen_x(gx)
		if sx >= VIEWPORT_X and sx <= VIEWPORT_X + VIEWPORT_W:
			draw_line(Vector2(sx, VIEWPORT_Y), Vector2(sx, VIEWPORT_Y + VIEWPORT_H), grid_color, 1.0 / zoom)
		gx += step
	var gy = start_y
	while gy <= end_y:
		var sy = _to_screen_y(gy)
		if sy >= VIEWPORT_Y and sy <= VIEWPORT_Y + VIEWPORT_H:
			draw_line(Vector2(VIEWPORT_X, sy), Vector2(VIEWPORT_X + VIEWPORT_W, sy), grid_color, 1.0 / zoom)
		gy += step

func _draw_selection():
	if selected_part_idx < 0 or selected_part_idx >= world.parts.size():
		return
	var p = world.parts[selected_part_idx]
	if not p: return
	var sx = _to_screen_x(p.x)
	var sy = _to_screen_y(p.y)
	var sw = p.width_1 * zoom
	var sh = p.height_1 * zoom
	draw_rect(Rect2(sx, sy, sw, sh), Color(1, 0.78, 0, 0.6), false, max(1, int(zoom)))

	for h in _get_handle_positions(p):
		draw_rect(h, Color(1, 0.78, 0, 0.9), true)

func _draw_connection_line():
	if connect_preview_line.size() == 2:
		draw_line(connect_preview_line[0], connect_preview_line[1], Color(1, 0.78, 0, 0.8), 2.0 / zoom)

func _open_condition_editor():
	_push_undo()
	var DialogClass = load("res://editor/ConditionEditorDialog.gd")
	var dlg = DialogClass.new()
	add_child(dlg)
	dlg.setup()
	dlg.confirmed.connect(func(conds):
		solution_conditions_store = conds
		is_dirty = true
		status_label.text = "Conditions updated (" + str(conds.size()) + ")"
	)
	dlg.popup_centered()

func _toggle_preview():
	if preview_running:
		_stop_preview()
	else:
		_start_preview()

func _start_preview():
	preview_snapshot.clear()
	for i in range(world.parts.size()):
		var p = world.parts[i]
		preview_snapshot[i] = {
			"x": p.x, "y": p.y,
			"vel_x": p.vel_x, "vel_y": p.vel_y,
			"state_counter": p.state_counter, "current_state": p.current_state,
			"sub_counter": p.sub_counter, "_countdown": p._countdown,
			"connected_1": p.connected_1, "connected_2": p.connected_2,
			"facing": p.facing, "angular_velocity": p.angular_velocity,
		}
	world.reset()
	preview_running = true
	preview_solved = false
	preview_ticks = 0
	checker = SolutionChecker.new(solution_conditions_store)
	status_label.text = "▶ PREVIEW RUNNING..."

func _stop_preview():
	preview_running = false
	checker = null
	for i in range(world.parts.size()):
		if preview_snapshot.has(i):
			var sn = preview_snapshot[i]
			var p = world.parts[i]
			p.x = sn.x; p.y = sn.y
			p.vel_x = sn.vel_x; p.vel_y = sn.vel_y
			p.state_counter = sn.state_counter; p.current_state = sn.current_state
			p.sub_counter = sn.get("sub_counter", 0); p._countdown = sn.get("_countdown", -1)
			p.connected_1 = sn.get("connected_1", -1); p.connected_2 = sn.get("connected_2", -1)
			p.facing = sn.get("facing", 1); p.angular_velocity = sn.get("angular_velocity", 0)
			p.sync_pos()
			_update_part_node(i)
	status_label.text = "Preview stopped"

func _snapshot_world() -> Dictionary:
	var parts: Array = []
	for p in world.parts:
		parts.append({
			"part_type": p.part_type, "x": p.x, "y": p.y,
			"vel_x": p.vel_x, "vel_y": p.vel_y,
			"width_1": p.width_1, "height_1": p.height_1,
			"width_2": p.width_2, "height_2": p.height_2,
			"appearance": p.appearance,
			"flags_1": p.flags_1, "flags_2": p.flags_2, "flags_3": p.flags_3,
			"state_counter": p.state_counter, "current_state": p.current_state,
			"connected_1": p.connected_1, "connected_2": p.connected_2,
			"outlet_plugged_1": p.outlet_plugged_1, "outlet_plugged_2": p.outlet_plugged_2,
			"rope_segment_length": p.rope_segment_length,
			"behavior": p.behavior,
		})
	return {
		"parts": parts,
		"level_title": level_title, "level_goal": level_goal,
		"level_bg_color": level_bg_color, "level_pressure": level_pressure,
		"level_gravity": level_gravity, "level_music_track": level_music_track,
	}

func _restore_world(snapshot: Dictionary):
	for c in canvas.get_children():
		if c.name != "Handles":
			c.queue_free()
	part_nodes.clear()
	world.parts.clear()
	for d in snapshot.get("parts", []):
		var pd = PartData.new(d.get("part_type", 0), d.get("x", 0), d.get("y", 0))
		pd.vel_x = d.get("vel_x", 0); pd.vel_y = d.get("vel_y", 0)
		pd.width_1 = d.get("width_1", 32); pd.height_1 = d.get("height_1", 32)
		pd.width_2 = d.get("width_2", 32); pd.height_2 = d.get("height_2", 32)
		pd.appearance = d.get("appearance", 0)
		pd.flags_1 = d.get("flags_1", 0); pd.flags_2 = d.get("flags_2", 0); pd.flags_3 = d.get("flags_3", 0)
		pd.state_counter = d.get("state_counter", 0); pd.current_state = d.get("current_state", 0)
		pd.connected_1 = d.get("connected_1", -1); pd.connected_2 = d.get("connected_2", -1)
		pd.outlet_plugged_1 = d.get("outlet_plugged_1", -1); pd.outlet_plugged_2 = d.get("outlet_plugged_2", -1)
		pd.rope_segment_length = d.get("rope_segment_length", 200)
		pd.behavior = d.get("behavior", 0)
		world.add_part(pd)
		_spawn_part_node(pd)
	level_title = snapshot.get("level_title", "Untitled")
	level_goal = snapshot.get("level_goal", "")
	level_bg_color = snapshot.get("level_bg_color", 0)
	level_pressure = snapshot.get("level_pressure", 67)
	level_gravity = snapshot.get("level_gravity", 272)
	level_music_track = snapshot.get("level_music_track", 1000)
	_reindex()
	queue_redraw()

func _push_undo():
	undo_stack.append(_snapshot_world())
	if undo_stack.size() > UNDO_LIMIT:
		undo_stack.pop_front()
	redo_stack.clear()

func _undo():
	if undo_stack.is_empty():
		return
	redo_stack.append(_snapshot_world())
	_restore_world(undo_stack.pop_back())

func _redo():
	if redo_stack.is_empty():
		return
	undo_stack.append(_snapshot_world())
	_restore_world(redo_stack.pop_back())
