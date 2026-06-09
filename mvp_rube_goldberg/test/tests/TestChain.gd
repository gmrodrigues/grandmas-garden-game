extends "res://test/TestFramework.gd"

const _Part = preload("res://Scripts/Part.gd")
const _Board = preload("res://Scripts/Board.gd")
const _PhysicsEngine = preload("res://Scripts/PhysicsEngine.gd")
const _ChainManager = preload("res://Scripts/ChainManager.gd")
const _PartFactory = preload("res://Scripts/PartFactory.gd")

var _board
var _physics
var _chain

func _init():
	pass

func setup():
	_board = _Board.new()
	_physics = _PhysicsEngine.new(_board)
	_chain = _ChainManager.new(_board, _physics)
	_board.level_data = {}

func teardown():
	_board = null
	_physics = null
	_chain = null

func add_chain_tests() -> void:
	add_test(_test_tick_condition_fires.bind(), "Tick condition fires every tick")
	add_test(_test_once_mode_fires_only_once.bind(), "Once mode fires only once")
	add_test(_test_flag_condition.bind(), "Flag condition checks _flags dictionary")
	add_test(_test_set_flag_action.bind(), "Set flag action modifies _flags")
	add_test(_test_win_action_emits.bind(), "Win action emits chain_completed")
	add_test(_test_prop_ge_condition.bind(), "Prop_ge condition checks part property")
	add_test(_test_and_condition.bind(), "And condition requires all sub-conditions")
	add_test(_test_log_action.bind(), "Log action records event")

func _test_tick_condition_fires() -> void:
	setup()
	var fired = [0]
	_chain.chain_completed.connect(func(t): fired[0] += 1)
	_chain.load_from_level({
		"chain_script": [{"when": {"type": "tick"}, "mode": "repeat", "actions": [{"type": "win", "msg": "tick!"}]}]
	})
	_chain.tick_count = 0
	_chain.evaluate_chain()
	assert_eq(fired[0], 1, "tick condition should fire on first evaluation")
	_chain.tick_count = 1
	_chain.evaluate_chain()
	assert_eq(fired[0], 2, "tick condition should fire again (repeat mode)")
	teardown()

func _test_once_mode_fires_only_once() -> void:
	setup()
	var fired = [0]
	_chain.chain_completed.connect(func(t): fired[0] += 1)
	_chain.load_from_level({
		"chain_script": [{"when": {"type": "tick"}, "mode": "once", "actions": [{"type": "win"}]}]
	})
	_chain.evaluate_chain()
	assert_eq(fired[0], 1, "once mode should fire")
	_chain.evaluate_chain()
	assert_eq(fired[0], 1, "once mode should NOT fire again")
	teardown()

func _test_flag_condition() -> void:
	setup()
	var fired = [false]
	_chain.chain_completed.connect(func(t): fired[0] = true)
	_chain.load_from_level({
		"chain_script": [
			{"when": {"type": "flag", "name": "ready", "value": true}, "mode": "once", "actions": [{"type": "win"}]}
		]
	})
	_chain.evaluate_chain()
	assert_false(fired[0], "flag condition should not fire before flag is set")
	_chain._flags["ready"] = true
	_chain.evaluate_chain()
	assert_true(fired[0], "flag condition should fire after flag is set")
	teardown()

func _test_set_flag_action() -> void:
	setup()
	_chain.load_from_level({
		"chain_script": [
			{"when": {"type": "tick"}, "mode": "once", "actions": [{"type": "set_flag", "name": "activated", "value": true}]}
		]
	})
	_chain.evaluate_chain()
	assert_true(_chain._flags.get("activated", false), "set_flag should set _flags['activated'] to true")
	teardown()

func _test_win_action_emits() -> void:
	setup()
	var emitted = [false]
	var emitted_tick = [-1]
	_chain.chain_completed.connect(func(t): emitted[0] = true; emitted_tick[0] = t)
	_chain.load_from_level({
		"chain_script": [{"when": {"type": "tick"}, "mode": "once", "actions": [{"type": "win"}]}]
	})
	_chain.tick_count = 42
	_chain.evaluate_chain()
	assert_true(emitted[0], "win action should emit chain_completed signal")
	assert_eq(emitted_tick[0], 42, "chain_completed should carry the tick count")
	teardown()

func _test_prop_ge_condition() -> void:
	setup()
	var p = _PartFactory.create_part(0, {"part_type": 0, "name": "Ball", "pos_x": 100, "pos_y": 100})
	p.state_counter = 5
	_board.add_part(p)
	_chain.load_from_level({
		"chain_script": [
			{"when": {"type": "prop_ge", "part": "Ball", "prop": "state_counter", "value": 5}, "mode": "once", "actions": [{"type": "log", "msg": "state >= 5"}]}
		]
	})
	_chain.evaluate_chain()
	assert_gt(_chain.event_log.size(), 0, "prop_ge should fire when state_counter >= 5")
	teardown()

func _test_and_condition() -> void:
	setup()
	_chain.load_from_level({
		"chain_script": [
			{"when": {"type": "and", "conditions": [
				{"type": "tick"},
				{"type": "flag", "name": "ready", "value": true}
			]}, "mode": "once", "actions": [{"type": "set_flag", "name": "result", "value": true}]}
		]
	})
	_chain.evaluate_chain()
	assert_false(_chain._flags.get("result", false), "and should NOT fire when one condition is false")
	_chain._flags["ready"] = true
	_chain.evaluate_chain()
	assert_true(_chain._flags.get("result", false), "and SHOULD fire when all conditions are true")
	teardown()

func _test_log_action() -> void:
	setup()
	_chain.load_from_level({
		"chain_script": [{"when": {"type": "tick"}, "mode": "once", "actions": [{"type": "log", "msg": "Hello, world!"}]}]
	})
	_chain.evaluate_chain()
	assert_gt(_chain.event_log.size(), 0, "log action should add to event_log")
	if _chain.event_log.size() > 0:
		assert_ne(_chain.event_log[0].find("Hello"), -1, "log message should contain custom text")
	teardown()

func assert_gt(a, b, msg: String = "") -> void:
	if not (a > b):
		fail("%s <= %s %s" % [str(a), str(b), msg])