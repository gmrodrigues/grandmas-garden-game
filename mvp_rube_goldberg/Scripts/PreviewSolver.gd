class_name PreviewSolver
extends RefCounted

const _Part = preload("res://Scripts/Part.gd")
const _PartFactory = preload("res://Scripts/PartFactory.gd")
const _SolutionCondition = preload("res://Scripts/SolutionCondition.gd")

var parts: Array = []
var solution: RefCounted = null
var tick_count: int = 0
var max_ticks: int = 2000
var is_running: bool = false

var _physics: RefCounted = null
var _board_proxy = null

signal tick_complete(tick: int)
signal solution_achieved(tick: int)
signal preview_timeout(tick: int)

func _init():
	parts = []

func setup_from_world_state(world_state) -> void:
	parts.clear()
	tick_count = 0
	is_running = false
	var level_data = world_state.to_level_data()
	var part_data_list = level_data.get("parts", [])
	for pd in part_data_list:
		var p = _PartFactory.create_part(parts.size(), pd)
		parts.append(p)
	var sol_data = level_data.get("solution", {})
	if not sol_data.is_empty():
		solution = _SolutionCondition.new(sol_data, parts)
	_board_proxy = _BoardProxy.new(self)

func step() -> void:
	if not is_running or tick_count >= max_ticks:
		return
	tick_count += 1
	for p in parts:
		if p.is_moving:
			p.advance_state()
	for p in parts:
		if p.is_moving:
			p.tick()
	_apply_wall_constraints()
	_detect_collisions()
	if solution != null:
		if solution.check():
			solution_achieved.emit(tick_count)
			is_running = false
	tick_complete.emit(tick_count)

func run_ticks(count: int) -> void:
	for i in range(count):
		if not is_running:
			break
		step()

func start() -> void:
	is_running = true

func stop() -> void:
	is_running = false

func reset() -> void:
	for p in parts:
		p.state_counter = 0
		p.current_state = 0
		p._rng_state = 1
		p._countdown = -1
		p.vel_x = 0
		p.vel_y = 0
		p.pos_x = p.x
		p.pos_y = p.y
	tick_count = 0
	is_running = false

func sync_to_world_state(world_state) -> void:
	var idx = 0
	for p in parts:
		if idx < world_state.parts_data.size():
			var pd = world_state.parts_data[idx]
			pd.x = p.x
			pd.y = p.y
			pd.state_counter = p.state_counter
			pd.current_state = p.current_state
			pd.is_powered = p.is_powered
		idx += 1

func _apply_wall_constraints() -> void:
	var floor_y = 480 - 10
	var right_wall = 640
	for p in parts:
		if not p.is_moving:
			continue
		var bottom = p.y + p.height_1
		if bottom >= floor_y:
			p.y = floor_y - p.height_1
			p.pos_y = p.y
			p.vel_y = -(p.vel_y * p.cor_q8) >> 8
		if p.y < 0:
			p.y = 0; p.pos_y = p.y; p.vel_y = 0
		if p.x < 0:
			p.x = 0; p.pos_x = p.x; p.vel_x = -(p.vel_x * p.cor_q8) >> 8
		if p.x + p.width_1 > right_wall:
			p.x = right_wall - p.width_1; p.pos_x = p.x
			p.vel_x = -(p.vel_x * p.cor_q8) >> 8

func _detect_collisions() -> void:
	for i in range(parts.size()):
		var a = parts[i]
		for j in range(i + 1, parts.size()):
			var b = parts[j]
			if not a.is_moving and not b.is_moving:
				continue
			if not _aabb_overlap(a, b):
				continue
			_resolve_collision(a, b)

func _aabb_overlap(a, b) -> bool:
	var l1 = a.x; var t1 = a.y
	var r1 = a.x + a.width_1; var b1 = a.y + a.height_1
	var l2 = b.x; var t2 = b.y
	var r2 = b.x + b.width_1; var b2 = b.y + b.height_1
	return l1 < r2 and r1 > l2 and t1 < b2 and b1 > t2

func _resolve_collision(a, b) -> void:
	var l1 = a.x; var t1 = a.y
	var r1 = a.x + a.width_1; var b1 = a.y + a.height_1
	var l2 = b.x; var t2 = b.y
	var r2 = b.x + b.width_1; var b2 = b.y + b.height_1
	var overlap_x = min(r1, r2) - max(l1, l2)
	var overlap_y = min(b1, b2) - max(t1, t2)
	if overlap_x < 0 or overlap_y < 0:
		return
	if overlap_x < overlap_y:
		var push = overlap_x >> 1
		if a.is_moving:
			a.x -= push; a.pos_x = a.x
			a.vel_x = (-a.vel_x * a.cor_q8) >> 8
		if b.is_moving:
			b.x += push; b.pos_x = b.x
			b.vel_x = (-b.vel_x * b.cor_q8) >> 8
	else:
		var push = overlap_y >> 1
		if a.is_moving:
			a.y -= push; a.pos_y = a.y
			a.vel_y = (-a.vel_y * a.cor_q8) >> 8
		if b.is_moving:
			b.y += push; b.pos_y = b.y
			b.vel_y = (-b.vel_y * b.cor_q8) >> 8
	if a.triggers.has("collision") and a.state_counter < a.state_limit_upper:
		a.state_counter += 1
	if b.triggers.has("collision") and b.state_counter < b.state_limit_upper:
		b.state_counter += 1

class _BoardProxy:
	var _solver
	func _init(solver):
		_solver = solver
	func get_parts():
		return _solver.parts
	var parts = []