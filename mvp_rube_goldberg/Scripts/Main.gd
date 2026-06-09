extends Node2D
class_name Main

enum Mode { EDITOR, PUZZLE, SIMULATION }

const _Part = preload("res://Scripts/Part.gd")
const _SimulationRunner = preload("res://Scripts/SimulationRunner.gd")
const _EditorController = preload("res://Scripts/EditorController.gd")
const _LevelSerializer = preload("res://Scripts/LevelSerializer.gd")

var current_mode: int = Mode.EDITOR
var level_path: String = "res://data/levels/mvp_chain.json"

var status_label: Label
var pass_label: Label
var sim_runner
var editor_ctrl: Node2D
var editor_toolbar: CanvasLayer
var puzzle_ctrl: Node2D
var puzzle_toolbar: CanvasLayer
var inventory_panel: Control
var level_serializer: RefCounted

@onready var sim_ui: CanvasLayer = $SimUI
@onready var sim_overlay: CanvasLayer = $SimulationOverlay
@onready var parts_layer: Node2D = $PartsLayer
@onready var editor_controller: Node2D = $EditorController
@onready var editor_toolbar_layer: CanvasLayer = $EditorToolbar

func _ready():
	level_serializer = _LevelSerializer.new()

	sim_runner = _SimulationRunner.new()
	sim_runner.name = "SimulationRunner"
	add_child(sim_runner)

	editor_ctrl = editor_controller
	editor_toolbar = editor_toolbar_layer

	_setup_puzzle_mode()

	AnmRenderer.load_palette()
	_load_level(level_path)

	sim_ui.speed_changed.connect(_on_speed_changed)
	sim_ui.reset_requested.connect(_on_reset)
	sim_ui.stop_requested.connect(_on_stop)
	sim_ui.play_requested.connect(_on_play_pressed)

	sim_overlay.simulation_stopped.connect(_on_simulation_stopped)

	if editor_toolbar:
		editor_toolbar.tool_selected.connect(_on_editor_tool_selected)
		editor_toolbar.zoom_changed.connect(_on_zoom_changed)
		editor_toolbar.save_requested.connect(_on_save_requested)
		editor_toolbar.load_requested.connect(_on_load_requested)
		editor_toolbar.new_level_requested.connect(_on_new_level_requested)
		editor_toolbar.play_requested.connect(_on_play_pressed)
		editor_toolbar.set_mode_editor()
		editor_toolbar.set_status("SELECT mode — click to select, drag to move")

	if editor_ctrl:
		editor_ctrl.status_update.connect(_on_editor_status_update)
		editor_ctrl.parts_changed.connect(_on_editor_parts_changed)

	var is_headless = OS.has_feature("headless") or DisplayServer.get_name() == "headless"
	var cmd_args = OS.get_cmdline_args()
	if cmd_args.has("--determinism-test"):
		var runs = 50
		for i in range(cmd_args.size()):
			if cmd_args[i] == "--determinism-test" and i + 1 < cmd_args.size():
				runs = cmd_args[i + 1].to_int()
		_run_deterministic_test(runs)
		get_tree().quit()
		return
	_update_status("Editor mode — press Play to run simulation, P for puzzle mode")

func _input(event: InputEvent) -> void:
	if event is InputEventKey and event.pressed:
		if event.keycode == KEY_P and current_mode == Mode.EDITOR:
			_enter_puzzle_mode()
		elif event.keycode == KEY_ESCAPE and current_mode == Mode.PUZZLE:
			_enter_editor_mode()

func _load_level(path: String) -> void:
	var board = _get_or_create_board()
	if board == null:
		return
	board.load_level(path)
	if editor_ctrl:
		var level_data = board.level_data
		if level_data.has("parts") and not level_data["parts"].is_empty():
			editor_ctrl.load_level_data(level_data)

func _get_or_create_board() -> Node:
	var existing = parts_layer.get_node_or_null("Board")
	if existing:
		return existing
	var board = preload("res://Scripts/Board.gd").new()
	board.name = "Board"
	parts_layer.add_child(board)
	return board

func _setup_puzzle_mode() -> void:
	var PuzzleEditorController = load("res://Scripts/PuzzleEditorController.gd")
	var PuzzleToolbar = load("res://Scenes/PuzzleToolbar.tscn")

	puzzle_ctrl = PuzzleEditorController.new()
	puzzle_ctrl.name = "PuzzleEditorController"
	puzzle_ctrl.visible = false
	add_child(puzzle_ctrl)

	var toolbar_scene = PuzzleToolbar.instantiate()
	toolbar_scene.name = "PuzzleToolbar"
	toolbar_scene.visible = false
	add_child(toolbar_scene)
	puzzle_toolbar = toolbar_scene

	var InvPanel = load("res://Scripts/InventoryPanel.gd")
	inventory_panel = InvPanel.new()
	inventory_panel.name = "InventoryPanel"
	inventory_panel.visible = false
	inventory_panel.custom_minimum_size = Vector2(200, 300)
	var vp = get_viewport()
	if vp:
		var size = vp.get_visible_rect().size
		inventory_panel.position = Vector2(size.x - 220, 60)
	add_child(inventory_panel)

	if puzzle_toolbar:
		puzzle_toolbar.tool_selected.connect(_on_puzzle_tool_selected)
		puzzle_toolbar.zoom_changed.connect(_on_puzzle_zoom_changed)
		puzzle_toolbar.play_requested.connect(_on_puzzle_play)
		puzzle_toolbar.reset_requested.connect(_on_puzzle_reset)

	if puzzle_ctrl:
		puzzle_ctrl.status_update.connect(_on_puzzle_status_update)
		puzzle_ctrl.inventory_changed.connect(_on_puzzle_inventory_changed)
		puzzle_ctrl.puzzle_solved.connect(_on_puzzle_solved)

	if inventory_panel:
		inventory_panel.part_spawned.connect(_on_inventory_part_spawned)

	puzzle_ctrl.visible = false
	puzzle_toolbar.visible = false
	inventory_panel.visible = false

func _on_play_pressed() -> void:
	match current_mode:
		Mode.EDITOR:
			_enter_simulation_mode()
		Mode.PUZZLE:
			_enter_puzzle_simulation_mode()
		Mode.SIMULATION:
			if puzzle_ctrl != null:
				_enter_puzzle_mode()
			else:
				_enter_editor_mode()

func _on_speed_changed(speed_mult: float) -> void:
	sim_overlay.set_speed(speed_mult)

func _on_stop() -> void:
	_enter_editor_mode()

func _on_reset() -> void:
	if current_mode == Mode.EDITOR:
		_load_level(level_path)
		_update_status("Level reloaded")
	else:
		sim_runner.reset()

func _on_simulation_stopped() -> void:
	_enter_editor_mode()

func _enter_simulation_mode() -> void:
	current_mode = Mode.SIMULATION
	var board = _get_or_create_board()
	var level_data = board.level_data.duplicate(true)
	if editor_ctrl:
		var editor_data = editor_ctrl.get_level_data()
		if not editor_data.get("parts", []).is_empty():
			level_data["parts"] = editor_data["parts"].duplicate(true)
			level_data["connections"] = editor_data.get("connections", [])
			var ed_phys = editor_data.get("physics", {})
			if not ed_phys.is_empty():
				level_data["physics"] = ed_phys.duplicate(true)
	sim_overlay.init(level_data)
	parts_layer.hide()
	sim_ui.hide()
	editor_toolbar.hide()
	if puzzle_toolbar:
		puzzle_toolbar.hide()
	if inventory_panel:
		inventory_panel.hide()
	sim_overlay.show()
	if editor_toolbar:
		editor_toolbar.set_mode_simulation()
	_update_status("Simulation running...")

func _enter_editor_mode() -> void:
	current_mode = Mode.EDITOR
	sim_overlay.hide()
	sim_ui.show()
	parts_layer.show()
	if editor_toolbar:
		editor_toolbar.show()
		editor_toolbar.set_mode_editor()
	if puzzle_toolbar:
		puzzle_toolbar.hide()
	if inventory_panel:
		inventory_panel.hide()
	_update_status("Editor mode")

func _enter_puzzle_mode() -> void:
	current_mode = Mode.PUZZLE
	sim_overlay.hide()
	sim_ui.hide()
	parts_layer.hide()
	if editor_toolbar:
		editor_toolbar.hide()
	if puzzle_toolbar:
		puzzle_toolbar.show()
		puzzle_toolbar.set_mode_editor()
		puzzle_toolbar.set_status("PUZZLE mode — drag from inventory")
	if inventory_panel:
		inventory_panel.show()
	var board = _get_or_create_board()
	var level_data = board.level_data
	var inventory = level_data.get("inventory", [])
	var counts = {}
	for item in inventory:
		var pt = int(item.get("part_type", 0))
		var cnt = int(item.get("count", 0))
		counts[pt] = cnt
	if puzzle_ctrl:
		puzzle_ctrl.setup(inventory, level_data)
	_update_status("Puzzle mode — position inventory parts to solve")

func _enter_puzzle_simulation_mode() -> void:
	if puzzle_ctrl:
		puzzle_ctrl._start_preview()
		puzzle_toolbar.set_mode_preview()
		_update_status("Puzzle preview running...")

func _on_puzzle_tool_selected(tool: int) -> void:
	if puzzle_ctrl:
		puzzle_ctrl.set_tool(tool)

func _on_puzzle_zoom_changed(level: float) -> void:
	if puzzle_ctrl:
		puzzle_ctrl.zoom_level = level

func _on_puzzle_play() -> void:
	if puzzle_ctrl:
		if puzzle_ctrl._preview_simulation:
			puzzle_ctrl._stop_preview()
			puzzle_toolbar.set_mode_editor()
		else:
			puzzle_ctrl._start_preview()
			puzzle_toolbar.set_mode_preview()

func _on_puzzle_reset() -> void:
	if puzzle_ctrl:
		puzzle_ctrl._stop_preview()
		puzzle_toolbar.set_mode_editor()
		var board = _get_or_create_board()
		var level_data = board.level_data
		var inventory = level_data.get("inventory", [])
		puzzle_ctrl.setup(inventory, level_data)
	_update_status("Puzzle reset")

func _on_puzzle_status_update(msg: String) -> void:
	_update_status(msg)

func _on_puzzle_inventory_changed() -> void:
	if puzzle_ctrl and inventory_panel:
		inventory_panel.update_counts(puzzle_ctrl.get_inventory_counts())

func _on_puzzle_solved(tick: int) -> void:
	_update_status("PUZZLE SOLVED at tick %d!" % tick)

func _on_inventory_part_spawned(part_type: int, x: int, y: int) -> void:
	if puzzle_ctrl:
		puzzle_ctrl.spawn_from_inventory(part_type, x, y)
		if inventory_panel:
			inventory_panel.update_counts(puzzle_ctrl.get_inventory_counts())

func _update_status(msg: String):
	if status_label:
		status_label.text = msg
	if editor_toolbar:
		editor_toolbar.set_status(msg)

func _on_editor_tool_selected(tool: int) -> void:
	if editor_ctrl:
		editor_ctrl.set_tool(tool)

func _on_zoom_changed(level: float) -> void:
	if current_mode == Mode.PUZZLE and puzzle_ctrl:
		puzzle_ctrl.zoom_level = level
	elif editor_ctrl:
		editor_ctrl.zoom_level = level

func _on_editor_status_update(msg: String) -> void:
	_update_status(msg)

func _on_editor_parts_changed() -> void:
	pass

func _on_save_requested() -> void:
	if editor_ctrl:
		var data = editor_ctrl.get_level_data()
		var path = "user://levels/editor_level.json"
		level_serializer.save_json(path, data)
		_update_status("Saved to " + path)

func _on_load_requested() -> void:
	var path = "user://levels/editor_level.json"
	var data = level_serializer.load_json(path)
	if not data.is_empty() and editor_ctrl:
		editor_ctrl.load_level_data(data)
		_update_status("Loaded from " + path)

func _on_new_level_requested() -> void:
	if editor_ctrl:
		editor_ctrl.new_level()
	_update_status("New level — empty workspace")

func _run_deterministic_test(runs: int = 10) -> bool:
	var board = _get_or_create_board()
	if sim_runner.run_deterministic_test(runs, board.level_data):
		return true
	return false

func get_editor_controller() -> Node:
	return editor_ctrl

func get_sim_runner() -> Node:
	return sim_runner