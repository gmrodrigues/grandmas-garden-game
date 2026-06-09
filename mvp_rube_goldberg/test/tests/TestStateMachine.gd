extends "res://test/TestFramework.gd"

const _Part = preload("res://Scripts/Part.gd")

func _init():
	pass

func add_sm_tests() -> void:
	add_test(_test_sm_wrap_at_limit.bind(), "State counter wraps at LIMIT_UPPER")
	add_test(_test_sm_reset_value.bind(), "State counter wraps to LIMIT_RESET")
	add_test(_test_sm_lcg_deterministic.bind(), "LCG RNG produces deterministic sequence")
	add_test(_test_sm_sub_counter_reaches_zero.bind(), "Sub-counter reaching zero sets state to LIMIT_RESET")
	add_test(_test_sm_freeze_when_not_moving.bind(), "State counter freezes when not moving")
	add_test(_test_sm_lcg_range.bind(), "LCG RNG produces values within expected range")

func _test_sm_wrap_at_limit() -> void:
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.state_counter = 7
	p.state_limit_upper = 8
	p.state_limit_reset = 0
	p.sub_counter = 0
	p.is_moving = true
	p.advance_state()
	assert_eq(p.state_counter, 0, "state_counter should wrap to LIMIT_RESET when reaching LIMIT_UPPER")

func _test_sm_reset_value() -> void:
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.state_counter = 7
	p.state_limit_upper = 8
	p.state_limit_reset = 3
	p.sub_counter = 0
	p.is_moving = true
	p.advance_state()
	assert_eq(p.state_counter, 3, "state_counter should wrap to LIMIT_RESET=3")

func _test_sm_lcg_deterministic() -> void:
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p._rng_state = 1
	var seq1 = []
	for i in range(10):
		seq1.append(p._randint(0, 1000))
	p._rng_state = 1
	var seq2 = []
	for i in range(10):
		seq2.append(p._randint(0, 1000))
	assert_eq(seq1, seq2, "LCG RNG should produce identical sequences from same seed")

func _test_sm_sub_counter_reaches_zero() -> void:
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.state_counter = 1
	p.state_limit_upper = 10
	p.state_limit_reset = 5
	p.state_limit_sub_a = 5
	p.state_limit_sub_b = 5
	p.sub_counter = 1
	p.is_moving = true
	p.advance_state()
	assert_eq(p.sub_counter, 0, "sub_counter should reach 0")
	assert_eq(p.state_counter, 5, "state_counter should be set to LIMIT_RESET when sub_counter reaches 0")

func _test_sm_freeze_when_not_moving() -> void:
	var p = _Part.new(0, 0, _Part.ARCH_STATIC, 100, 100)
	p.state_counter = 1
	p.state_limit_upper = 8
	p.state_limit_reset = 0
	p.sub_counter = 0
	p.is_moving = false
	var before = p.state_counter
	var phys = preload("res://Scripts/PhysicsEngine.gd").new(null)
	var parts = [p]
	phys._advance_parts(parts)
	assert_eq(p.state_counter, before, "state_counter should NOT advance for non-moving parts")

func _test_sm_lcg_range() -> void:
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p._rng_state = 1
	p._countdown = -1
	var min_val = 999
	var max_val = 0
	for i in range(1000):
		var r = p._randint(40, 239)
		if r < min_val: min_val = r
		if r > max_val: max_val = r
	assert_in_range(min_val, 40, 239, "LCG min should be >= 40")
	assert_in_range(max_val, 40, 239, "LCG max should be <= 239")
	assert_eq(min_val, 40, "LCG should reach exact lower bound 40")
	assert_eq(max_val, 239, "LCG should reach exact upper bound 239")

func assert_gt(a, b, msg: String = "") -> void:
	if not (a > b):
		fail("%s <= %s %s" % [str(a), str(b), msg])