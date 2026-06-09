extends "res://test/TestFramework.gd"

const _PartData = preload("res://Scripts/PartData.gd")
const _WorldState = preload("res://Scripts/WorldState.gd")
const _EditorController = preload("res://Scripts/EditorController.gd")

var _ws: RefCounted
var _ec: Node2D

func _init():
	pass

func setup():
	_ws = _WorldState.new()
	_ec = Node2D.new()
	add_child(_ec)
	_ec.world_state = _ws

func teardown():
	_ec.queue_free()
	_ec = null
	_ws = null

func add_editor_tests() -> void:
	add_test(_test_select_mode_select_part.bind(), "SELECT — click part selects it")
	add_test(_test_select_mode_deselect_on_empty.bind(), "SELECT — click empty deselects")
	add_test(_test_select_mode_drag_moves_part.bind(), "SELECT — drag moves selected part")
	add_test(_test_select_mode_flip_key.bind(), "SELECT — F key flips part horizontally")
	add_test(_test_select_mode_lock_key.bind(), "SELECT — L key toggles lock")
	add_test(_test_select_mode_delete_key.bind(), "SELECT — Delete removes selected")
	add_test(_test_place_mode_snaps_to_grid.bind(), "PLACE — places part snapped to grid")
	add_test(_test_delete_mode_removes_part.bind(), "DELETE — click removes part")
	add_test(_test_connect_mode_rope.bind(), "CONNECT — creates rope connection between two parts")
	add_test(_test_connect_mode_esc_cancels.bind(), "CONNECT — ESC cancels pending connection")
	add_test(_test_preview_mode_starts.bind(), "PREVIEW — enters preview simulation mode")
	add_test(_test_level_info_mode_sets.bind(), "LEVEL_INFO — sets tool mode correctly")

func _make_part(x: int, y: int, pt: int = 0) -> PartData:
	var p = _PartData.new(-1, pt, x, y)
	p.width_1 = 32; p.height_1 = 32
	return p

func _simulate_click(mx: int, my: int, pressed: bool = true) -> void:
	var ev = InputEventMouseButton.new()
	ev.button_index = MOUSE_BUTTON_LEFT
	ev.pressed = pressed
	ev.position = Vector2(mx * _ec.zoom_level, my * _ec.zoom_level)
	_ec._handle_mouse_button_event(ev)

func _simulate_key_press(keycode: int) -> void:
	var ev = InputEventKey.new()
	ev.keycode = keycode
	ev.pressed = true
	_ec._handle_key_event(ev)

func _test_select_mode_select_part() -> void:
	setup()
	var p = _make_part(100, 100)
	_ws.add_part(p)
	_ec.current_tool = _EditorController.ToolMode.SELECT
	_simulate_click(100, 100)
	assert_true(_ws.has_selection(), "clicking part should select it")
	assert_eq(_ws.get_selected()[0], p, "selected part should be the clicked part")
	teardown()

func _test_select_mode_deselect_on_empty() -> void:
	setup()
	var p = _make_part(100, 100)
	_ws.add_part(p)
	_ec.current_tool = _EditorController.ToolMode.SELECT
	_simulate_click(100, 100)
	assert_true(_ws.has_selection(), "part should be selected first")
	_simulate_click(300, 300)
	assert_false(_ws.has_selection(), "clicking empty space should deselect")
	teardown()

func _test_select_mode_drag_moves_part() -> void:
	setup()
	var p = _make_part(100, 100)
	_ws.add_part(p)
	_ec.current_tool = _EditorController.ToolMode.SELECT
	_simulate_click(100, 100)
	var initial_x = p.x
	var drag_ev = InputEventMouseMotion.new()
	drag_ev.position = Vector2(120, 120)
	_ec._handle_mouse_motion_event(drag_ev)
	assert_ne(p.x, initial_x, "part x should change during drag")
	teardown()

func _test_select_mode_flip_key() -> void:
	setup()
	var p = _make_part(100, 100)
	p.facing = 1
	_ws.add_part(p)
	_ws.select_part(p)
	_ec.current_tool = _EditorController.ToolMode.SELECT
	_simulate_key_press(KEY_F)
	assert_eq(p.facing, -1, "F key should flip facing to -1")
	teardown()

func _test_select_mode_lock_key() -> void:
	setup()
	var p = _make_part(100, 100)
	p.is_locked = false
	_ws.add_part(p)
	_ws.select_part(p)
	_ec.current_tool = _EditorController.ToolMode.SELECT
	_simulate_key_press(KEY_L)
	assert_true(p.is_locked, "L key should lock the part")
	_simulate_key_press(KEY_L)
	assert_false(p.is_locked, "L key again should unlock")
	teardown()

func _test_select_mode_delete_key() -> void:
	setup()
	var p = _make_part(100, 100)
	_ws.add_part(p)
	_ws.select_part(p)
	_ec.current_tool = _EditorController.ToolMode.SELECT
	var before = _ws.parts_data.size()
	_simulate_key_press(KEY_DELETE)
	assert_eq(_ws.parts_data.size(), before - 1, "Delete should remove selected part")
	teardown()

func _test_place_mode_snaps_to_grid() -> void:
	setup()
	_ec.current_tool = _EditorController.ToolMode.PLACE
	_ec.selected_part_type = 1
	_simulate_click(101, 105)
	assert_true(_ws.parts_data.size() > 0, "PLACE should add a part")
	var placed = _ws.parts_data[-1]
	assert_eq(placed.x % _PartData.GRID_SIZE, 0, "placed x should snap to grid")
	assert_eq(placed.y % _PartData.GRID_SIZE, 0, "placed y should snap to grid")
	teardown()

func _test_delete_mode_removes_part() -> void:
	setup()
	var p = _make_part(100, 100)
	_ws.add_part(p)
	var before = _ws.parts_data.size()
	_ec.current_tool = _EditorController.ToolMode.DELETE
	_simulate_click(100, 100)
	assert_eq(_ws.parts_data.size(), before - 1, "DELETE mode should remove clicked part")
	teardown()

func _test_connect_mode_rope() -> void:
	setup()
	var a = _make_part(100, 100, 0)
	var b = _make_part(200, 100, 0)
	_ws.add_part(a)
	_ws.add_part(b)
	_ec.current_tool = _EditorController.ToolMode.CONNECT
	_ec._connection_preview["type"] = _PartData.ConnectionType.ROPE
	_simulate_click(100, 100)
	_simulate_click(200, 100)
	assert_true(_ws.has_connection(a.id, b.id), "rope connection should exist between a and b")
	teardown()

func _test_connect_mode_esc_cancels() -> void:
	setup()
	var a = _make_part(100, 100, 0)
	_ws.add_part(a)
	_ec.current_tool = _EditorController.ToolMode.CONNECT
	_simulate_click(100, 100)
	var before = _ws.get_connections().size()
	_simulate_key_press(KEY_ESCAPE)
	assert_eq(_ws.get_connections().size(), before, "ESC should cancel pending connection without adding")
	teardown()

func _test_preview_mode_starts() -> void:
	setup()
	_ec.current_tool = _EditorController.ToolMode.SELECT
	_ec.set_tool(_EditorController.ToolMode.PREVIEW)
	assert_eq(_ec.current_tool, _EditorController.ToolMode.PREVIEW, "PREVIEW tool should be set")
	assert_true(_ec._preview_simulation or _ec._preview_solver != null, "preview should be started")
	teardown()

func _test_level_info_mode_sets() -> void:
	setup()
	_ec.set_tool(_EditorController.ToolMode.LEVEL_INFO)
	assert_eq(_ec.current_tool, _EditorController.ToolMode.LEVEL_INFO, "LEVEL_INFO tool should be set")
	teardown()