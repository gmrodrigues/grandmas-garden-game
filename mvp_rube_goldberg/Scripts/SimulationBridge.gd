class_name SimulationBridge
extends Node

signal simulation_started
signal simulation_paused
signal simulation_stopped
signal simulation_result(success: bool, tick_count: int)
signal tick_update(tick: int, max_ticks: int)

const _SimulationRunner = preload("res://Scripts/SimulationRunner.gd")
const _LevelSerializer = preload("res://Scripts/LevelSerializer.gd")
const _Board = preload("res://Scripts/Board.gd")
const _PhysicsEngine = preload("res://Scripts/PhysicsEngine.gd")
const _ChainManager = preload("res://Scripts/ChainManager.gd")
const _SolutionCondition = preload("res://Scripts/SolutionCondition.gd")

var _sim_runner: Node = null
var _serializer: LevelSerializer = null
var _editor_world_state = null

var _pending_result_callback: Callable = Callable()
var _headless_mode: bool = false

func _init():
	_serializer = LevelSerializer.new()

func initialize(editor_world_state) -> void:
	_editor_world_state = editor_world_state
	if _sim_runner == null:
		var tree = Engine.get_main_loop()
		if tree and tree.root:
			_sim_runner = _create_simulation_runner()
			_sim_runner.name = "SimulationRunner"
			tree.root.add_child(_sim_runner)

func _create_simulation_runner() -> Node:
	var runner = _SimulationRunner.new()
	runner.state_changed.connect(_on_sim_state_changed)
	runner.tick_updated.connect(_on_tick_updated)
	runner.simulation_finished.connect(_on_sim_finished)
	return runner

func load_level_from_editor() -> bool:
	if _editor_world_state == null:
		return false
	var level_data = _editor_world_state.to_level_data()
	var normalized = _serializer.editor_data_to_simulation(level_data)
	_sim_runner.init(normalized)
	return true

func load_level_from_file(path: String) -> bool:
	var fmt = _serializer.probe_format(path)
	var data
	if fmt == "yaml":
		data = _serializer.load_yaml(path)
	elif fmt == "json":
		data = _serializer.load_json(path)
	else:
		push_error("SimulationBridge: Unknown format for " + path)
		return false
	if data.is_empty():
		return false
	_sim_runner.init(data)
	return true

func play() -> void:
	if _sim_runner == null:
		return
	_sim_runner.play()
	simulation_started.emit()

func pause() -> void:
	if _sim_runner == null:
		return
	_sim_runner.pause()
	simulation_paused.emit()

func stop() -> void:
	if _sim_runner == null:
		return
	_sim_runner.stop()
	simulation_stopped.emit()

func reset() -> void:
	if _sim_runner == null:
		return
	_sim_runner.reset()

func set_speed(speed: float) -> void:
	if _sim_runner == null:
		return
	_sim_runner.set_speed(speed)

func run_headless(runs: int, data: Dictionary) -> bool:
	if _sim_runner == null:
		return false
	_headless_mode = true
	return _sim_runner.run_deterministic_test(runs, data)

func get_current_state() -> int:
	if _sim_runner == null:
		return _SimulationRunner.State.IDLE
	return _sim_runner.current_state

func get_tick_count() -> int:
	if _sim_runner == null:
		return 0
	return _sim_runner.tick_count

func is_running() -> bool:
	if _sim_runner == null:
		return false
	return _sim_runner.running

func _on_sim_state_changed(state: int) -> void:
	pass

func _on_tick_updated(tick: int, max_ticks: int) -> void:
	tick_update.emit(tick, max_ticks)

func _on_sim_finished(success: bool, tick_count: int, events: Array) -> void:
	simulation_result.emit(success, tick_count)
	simulation_stopped.emit()
	_headless_mode = false

func get_sim_runner() -> Node:
	return _sim_runner

func get_serializer() -> LevelSerializer:
	return _serializer

func shutdown() -> void:
	if _sim_runner != null:
		_sim_runner.stop()
		if _sim_runner.get_parent():
			_sim_runner.get_parent().remove_child(_sim_runner)
		_sim_runner.free()
		_sim_runner = null