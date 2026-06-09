extends "res://test/TestFramework.gd"

const _Part = preload("res://Scripts/Part.gd")
const _Board = preload("res://Scripts/Board.gd")
const _PhysicsEngine = preload("res://Scripts/PhysicsEngine.gd")
const _PartFactory = preload("res://Scripts/PartFactory.gd")
const _ChainManager = preload("res://Scripts/ChainManager.gd")

var _board
var _physics
var _chain

func _init():
	pass

func setup():
	_board = _Board.new()
	_physics = _PhysicsEngine.new(_board)
	_chain = _ChainManager.new(_board, _physics)

func teardown():
	_board = null
	_physics = null
	_chain = null

func _build_level(data: Dictionary) -> void:
	_board.clear_level()
	var parts_data = data.get("parts", [])
	for pd in parts_data:
		var p = _PartFactory.create_part(_board.parts.size(), pd)
		_board.add_part(p)
	_board.spawn_sprites()
	_physics.reset()
	_chain.reset()

func add_physics_tests() -> void:
	add_test(_test_state_counter_advances.bind(), "State counter advances each tick")
	add_test(_test_zero_state_random_delay.bind(), "Zero-state parts apply random delay [40,239]")
	add_test(_test_sub_counter_countdown.bind(), "Sub-state countdown before state advance")
	add_test(_test_gravity_applies.bind(), "Gravity integration applies to moving parts")
	add_test(_test_aabb_collision_detection.bind(), "AABB collision detection")
	add_test(_test_collision_cor_impulse.bind(), "Collision response applies COR impulse")
	add_test(_test_wall_constraint_bounce.bind(), "Wall constraint bounces with COR")
	add_test(_test_gravity_buoyancy.bind(), "Gravity buoyancy lifts balloon parts")
	add_test(_test_spatial_grid_builds.bind(), "Spatial grid builds correctly")
	add_test(_test_remove_destroyed.bind(), "Destroyed parts are removed from array")

func _test_state_counter_advances() -> void:
	setup()
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.state_counter = 1; p.state_limit_upper = 8; p.state_limit_reset = 0
	p.is_moving = true; p.sub_counter = 0
	_board.add_part(p)
	var initial = p.state_counter
	p.advance_state()
	assert_eq(p.state_counter, initial + 1, "state_counter should increment by 1")
	teardown()

func _test_zero_state_random_delay() -> void:
	setup()
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.state_counter = 0; p.state_limit_upper = 8; p.is_moving = true; p.sub_counter = 0; p._rng_state = 1
	_board.add_part(p)
	p.advance_state()
	assert_eq(p.state_counter, 0, "state_counter should NOT advance on first call from zero")
	var advanced = false
	for i in range(300):
		var prev = p.state_counter
		p.advance_state()
		if p.state_counter != prev:
			advanced = true
			assert_in_range(p.state_counter, 1, p.state_limit_upper, "state should advance within limits")
			break
	assert_true(advanced, "state_counter should eventually advance from zero within 300 ticks")
	teardown()

func _test_sub_counter_countdown() -> void:
	setup()
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.state_counter = 1; p.state_limit_upper = 10; p.state_limit_reset = 0
	p.state_limit_sub_a = 5; p.state_limit_sub_b = 5; p.sub_counter = 3; p.is_moving = true
	_board.add_part(p)
	p.advance_state()
	assert_eq(p.sub_counter, 2, "sub_counter should decrement by 1")
	teardown()

func _test_gravity_applies() -> void:
	setup()
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.mass = 2832; p.damping = 200; p.vel_y = 0; p.is_moving = true; p.gravity_category = 7
	_board.add_part(p)
	var initial_vy = p.vel_y
	p.tick()
	assert_gt(p.vel_y, initial_vy, "gravity should increase vel_y")
	teardown()

func _test_aabb_collision_detection() -> void:
	setup()
	var a = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	a.width_1 = 32; a.height_1 = 32; a.is_moving = true
	var b = _Part.new(1, 0, _Part.ARCH_KINETIC, 110, 100)
	b.width_1 = 32; b.height_1 = 32; b.is_moving = true
	_board.add_part(a)
	_board.add_part(b)
	assert_true(a.aabb_overlap(b), "overlapping AABBs should detect collision")
	teardown()

func _test_collision_cor_impulse() -> void:
	setup()
	var a = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	a.width_1 = 32; a.height_1 = 32; a.is_moving = true; a.vel_x = 500; a.cor_q8 = 128
	var b = _Part.new(1, 1, _Part.ARCH_STATIC, 120, 100)
	b.width_1 = 32; b.height_1 = 32; b.is_moving = false
	_board.add_part(a)
	_board.add_part(b)
	assert_true(a.aabb_overlap(b), "A and B should overlap")
	_physics._detect_and_resolve_collisions(_board.parts, 0)
	assert_ne(a.vel_x, 500, "collision should change velocity")
	teardown()

func _test_wall_constraint_bounce() -> void:
	setup()
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 500)
	p.width_1 = 32; p.height_1 = 32; p.vel_y = 1000; p.is_moving = true; p.cor_q8 = 128
	_board.add_part(p)
	_physics._apply_wall_constraints(_board.parts)
	assert_le(p.y, 480 - 10, "part should be clamped above floor")
	teardown()

func _test_gravity_buoyancy() -> void:
	setup()
	var p = _Part.new(0, 0, _Part.ARCH_KINETIC, 100, 100)
	p.vel_y = 0; p.is_moving = true; p.gravity_buoyancy = -0x600; p.gravity_category = 151; p.damping = 0
	_board.add_part(p)
	p.tick()
	assert_lt(p.vel_y, 0, "negative buoyancy should make part float upward")
	teardown()

func _test_spatial_grid_builds() -> void:
	setup()
	for i in range(5):
		var p = _Part.new(i, 0, _Part.ARCH_KINETIC, i * 100, 100)
		p.width_1 = 32; p.height_1 = 32
		_board.add_part(p)
	var grid = _physics._build_spatial_grid(_board.parts)
	assert_gt(grid.size(), 0, "spatial grid should have at least one cell")
	teardown()

func _test_remove_destroyed() -> void:
	setup()
	for i in range(3):
		var p = _Part.new(i, 0, _Part.ARCH_KINETIC, i * 100, 100)
		p.width_1 = 32; p.height_1 = 32; p.is_moving = true
		_board.add_part(p)
	_board.parts[1].destroyed = true
	var before = _board.parts.size()
	_physics._remove_destroyed_parts(_board.parts)
	assert_eq(_board.parts.size(), before - 1, "destroyed part should be removed")
	teardown()

func assert_gt(a, b, msg: String = "") -> void:
	if not (a > b):
		fail("%s <= %s %s" % [str(a), str(b), msg])

func assert_lt(a, b, msg: String = "") -> void:
	if not (a < b):
		fail("%s >= %s %s" % [str(a), str(b), msg])

func assert_le(a, b, msg: String = "") -> void:
	if not (a <= b):
		fail("%s > %s %s" % [str(a), str(b), msg])