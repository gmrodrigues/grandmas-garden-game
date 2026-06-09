class_name SimulationRunner
extends Node2D

enum State { IDLE, RUNNING, PAUSED, SUCCESS, FAIL }

signal state_changed(state: int)
signal tick_updated(tick: int, max_ticks: int)
signal simulation_finished(success: bool, tick_count: int, events: Array)
signal objective_updated(primary_achieved: bool, secondary_achieved: bool)

const _Board = preload("res://Scripts/Board.gd")
const _PhysicsEngine = preload("res://Scripts/PhysicsEngine.gd")
const _ChainManager = preload("res://Scripts/ChainManager.gd")
const _Part = preload("res://Scripts/Part.gd")
const _PartFactory = preload("res://Scripts/PartFactory.gd")
const _SolutionCondition = preload("res://Scripts/SolutionCondition.gd")

var current_state: int = State.IDLE
var tick_count: int = 0
var max_ticks: int = 2000
var sim_speed_q8: int = 256

var board
var physics
var chain

var tick_accum_usec: int = 0
var last_time_usec: int = 0
var running: bool = false

var level_data: Dictionary = {}
var events: Array = []

var primary_achieved: bool = false
var secondary_achieved: bool = false

func _init():
	board = _Board.new()
	board.set_process(false)
	board.name = "Board"
	add_child(board)

	physics = _PhysicsEngine.new(board)
	chain = _ChainManager.new(board, physics)

	chain.chain_completed.connect(_on_chain_completed)

func init(data: Dictionary) -> void:
	level_data = data
	_reset_simulation()

func _reset_simulation() -> void:
	tick_count = 0
	tick_accum_usec = 0
	last_time_usec = Time.get_ticks_usec()
	events.clear()
	primary_achieved = false
	secondary_achieved = false

	chain.reset()
	physics.reset()
	board.clear_level()
	board.level_data = level_data

	var part_data = level_data.get("parts", [])
	for pd in part_data:
		var p = _PartFactory.create_part(board.parts.size(), pd)
		board.add_part(p)

	board.spawn_sprites()
	var sol_data = level_data.get("solution", {})
	if not sol_data.is_empty():
		board.solution = _SolutionCondition.new(sol_data, board.parts)
	chain.load_from_level(board.level_data)

	_set_state(State.IDLE)

func play() -> void:
	if current_state == State.SUCCESS or current_state == State.FAIL:
		_reset_simulation()
	last_time_usec = Time.get_ticks_usec()
	board.set_process(true)
	running = true
	_set_state(State.RUNNING)

func pause() -> void:
	running = false
	board.set_process(false)
	_set_state(State.PAUSED)

func resume() -> void:
	if current_state == State.PAUSED:
		last_time_usec = Time.get_ticks_usec()
		running = true
		board.set_process(true)
		_set_state(State.RUNNING)

func stop() -> void:
	running = false
	board.set_process(false)
	_set_state(State.IDLE)

func reset() -> void:
	_reset_simulation()
	play()

func set_speed(speed: float) -> void:
	sim_speed_q8 = int(clampf(speed, 0.0, 4.0) * 256.0)

func _set_state(state: int) -> void:
	current_state = state
	state_changed.emit(state)

func _process(_delta):
	if not running:
		return
	var current_time_usec = Time.get_ticks_usec()
	var elapsed_usec = current_time_usec - last_time_usec
	last_time_usec = current_time_usec
	if elapsed_usec > 100000:
		elapsed_usec = 100000
	var scaled = (elapsed_usec * sim_speed_q8) >> 8
	tick_accum_usec += scaled
	const TICK_INTERVAL_USEC: int = 16667
	while tick_accum_usec >= TICK_INTERVAL_USEC:
		tick_accum_usec -= TICK_INTERVAL_USEC
		tick_count += 1
		chain.tick_count = tick_count
		chain.evaluate_chain()
		physics.step(tick_count)
		board.sync_sprites()
	tick_updated.emit(tick_count, max_ticks)
	_check_objectives()
	if tick_count >= max_ticks:
		_on_timeout()

func _check_objectives() -> void:
	var solution = board.solution
	if solution and solution.check() and not primary_achieved:
		primary_achieved = true
		objective_updated.emit(primary_achieved, secondary_achieved)
		_On_success()

func _on_chain_completed(final_tick: int) -> void:
	_On_success()

func _On_success() -> void:
	running = false
	board.set_process(false)
	events = chain.event_log.duplicate()
	_set_state(State.SUCCESS)
	simulation_finished.emit(true, tick_count, events)

func _on_timeout() -> void:
	running = false
	board.set_process(false)
	events = chain.event_log.duplicate()
	_set_state(State.FAIL)
	simulation_finished.emit(false, tick_count, events)

func get_deterministic_snapshot() -> Dictionary:
	return chain.get_deterministic_snapshot()

func run_ticks(max_ticks_limit: int) -> void:
	while running and tick_count < max_ticks_limit:
		chain.tick_count = tick_count
		chain.evaluate_chain()
		physics.step(tick_count)
		if chain.deterministic_run:
			chain.deterministic_log.append(get_deterministic_snapshot())
		tick_count += 1

func run_deterministic_test(runs: int, data: Dictionary) -> bool:
	print("\n=== Determinism Test: %d runs @ 4x speed ===" % runs)
	var saved_speed_q8 = sim_speed_q8
	sim_speed_q8 = 1024
	var all_logs: Array = []
	for r in range(runs):
		init(data)
		chain.deterministic_run = true
		chain.deterministic_log.clear()
		running = true
		tick_count = 0
		run_ticks(max_ticks)
		chain.deterministic_run = false
		all_logs.append(chain.deterministic_log.duplicate(true))
		print("  Run %d: %d ticks, %d events" % [r + 1, tick_count, chain.event_log.size()])
		if tick_count >= max_ticks:
			push_warning("Run %d hit max_ticks limit" % (r + 1))
	var reference = all_logs[0]
	for r in range(1, runs):
		if all_logs[r].size() != reference.size():
			print("  MISMATCH: Run %d has %d ticks, run 0 has %d" % [r + 1, all_logs[r].size(), reference.size()])
			sim_speed_q8 = saved_speed_q8
			return false
		for i in range(reference.size()):
			var a = reference[i]
			var b = all_logs[r][i]
			if a["tick"] != b["tick"]:
				print("  MISMATCH at tick %d: run 0 has tick=%d, run %d has tick=%d" % [i, a["tick"], r, b["tick"]])
				return false
			if a["ball_x"] != b["ball_x"] or a["ball_y"] != b["ball_y"] or a["ball_vel_y"] != b["ball_vel_y"]:
				print("  MISMATCH at tick %d: Ball differs (run 0: (%d,%d,vel=%d), run %d: (%d,%d,vel=%d))" % [i, a["ball_x"], a["ball_y"], a["ball_vel_y"], r, b["ball_x"], b["ball_y"], b["ball_vel_y"]])
				return false
			if a["balloon_x"] != b["balloon_x"] or a["balloon_y"] != b["balloon_y"]:
				print("  MISMATCH at tick %d: Balloon differs" % i)
				return false
			if a["laser_powered"] != b["laser_powered"]:
				print("  MISMATCH at tick %d: Laser powered differs" % i)
				return false
			if a["gate_y"] != b["gate_y"]:
				print("  MISMATCH at tick %d: Gate y differs" % i)
				return false
	print("  PASS: All %d runs produced identical state logs" % runs)
	sim_speed_q8 = saved_speed_q8
	return true