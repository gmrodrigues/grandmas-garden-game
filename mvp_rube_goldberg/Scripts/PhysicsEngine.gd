class_name PhysicsEngine
extends RefCounted

const _Part = preload("res://Scripts/Part.gd")
const _SolveResTable = preload("res://Scripts/SolveResTable.gd")

const FLOOR_BUFFER: int = 10
const BOUNCE_VELOCITY_THRESHOLD: int = 0x800
const CONSTRAINT_ITERATIONS: int = 3
const CELL_SIZE: int = 64
const CELL_NEIGHBORS: Array = [[0,0],[-1,-1],[0,-1],[1,-1],[-1,0],[1,0],[-1,1],[0,1],[1,1]]

var _board
var _solve_res_table: RefCounted = null

var rope_endpoints: Dictionary = {}
var belt_connections: Array = []
var electrical_outlets: Dictionary = {}
var ignition_sources: Array = []
var spawned_projectiles: Array = []

func _init(board):
	_board = board
	_solve_res_table = _SolveResTable.new()

func reset():
	rope_endpoints.clear()
	belt_connections.clear()
	electrical_outlets.clear()
	ignition_sources.clear()
	spawned_projectiles.clear()

func step(tick_count: int):
	var parts = _board.parts
	_advance_parts(parts)
	_apply_driver_and_link_forces(parts)
	_process_belts(parts)
	_apply_pressure_fields(parts)
	_apply_wall_constraints(parts)
	_detect_and_resolve_collisions(parts, tick_count)
	_handle_proximity_triggers(parts)
	_handle_emitters_and_consumers(parts)
	_process_electrical()
	_propagate_electrical()
	_process_flame_sources()
	_check_ignition()
	_remove_destroyed_parts(parts)
	_enforce_rope_constraints(parts)
	_update_rope_connections(parts)

func _advance_parts(parts: Array):
	for p in parts:
		if p.is_moving:
			p.advance_state()

	for p in parts:
		if p.is_moving:
			p.tick()

func _apply_driver_and_link_forces(parts: Array):
	for p in parts:
		match p.archetype:
			_Part.ARCH_DRIVER:
				p.angular_velocity = 8
			_Part.ARCH_LINK:
				if p.connected_1 >= 0 and p.connected_1 < parts.size():
					var target = parts[p.connected_1]
					var dx = (target.x + target.width_1 / 2) - (p.x + p.width_1 / 2)
					var dy = (target.y + target.height_1 / 2) - (p.y + p.height_1 / 2)
					var dist = maxi(abs(dx), abs(dy))
					if dist > p.rope_segment_length and dist > 0:
						p.rope_pull_x = dx * (dist - p.rope_segment_length) / dist
						p.rope_pull_y = dy * (dist - p.rope_segment_length) / dist
						target.x += p.rope_pull_x >> 1
						target.y += p.rope_pull_y >> 1
			_Part.ARCH_CONSUMER:
				if p.is_powered:
					p.state_counter = 1

func _process_belts(parts: Array):
	belt_connections.clear()
	for p in parts:
		if p.part_type == 8:
			var src = _find_belt_driver(p.x, p.y, parts)
			var dst = _find_belt_driver(p.x + p.width_1, p.y + p.height_1, parts)
			if src >= 0 and dst >= 0:
				belt_connections.append([src, dst])

	for conn in belt_connections:
		if conn[0] < parts.size() and conn[1] < parts.size():
			var src = parts[conn[0]]
			var dst = parts[conn[1]]
			if src and dst and src.angular_velocity > 0:
				dst.angular_velocity = src.angular_velocity
				dst.is_moving = true

func _find_belt_driver(x: int, y: int, parts: Array) -> int:
	var best_dist = 100
	var best_id = -1
	var driver_types = [5, 6, 14, 31, 40, 50, 86]
	for p in parts:
		if p.archetype != _Part.ARCH_DRIVER:
			continue
		if driver_types.has(p.part_type):
			var cx = p.x + p.width_1 / 2
			var cy = p.y + p.height_1 / 2
			var dist = maxi(abs(x - cx), abs(y - cy))
			if dist < best_dist:
				best_dist = dist
				best_id = p.id
	return best_id

func _apply_pressure_fields(parts: Array):
	for p in parts:
		if p.archetype == _Part.ARCH_CONSUMER and p.is_powered:
			for other in parts:
				if other.id != p.id and other.is_moving:
					_apply_pressure_field(p, other)

func _apply_pressure_field(source, target):
	var sx = source.x + source.width_1 / 2
	var sy = source.y + source.height_1 / 2
	var tx = target.x + target.width_1 / 2
	var ty = target.y + target.height_1 / 2
	var dx = tx - sx
	var dy = ty - sy
	var dist = maxi(abs(dx), abs(dy))
	if dist <= 0 or dist > 200:
		return
	if dx * source.facing <= 0:
		return
	var falloff = 200 - dist
	if falloff <= 0:
		return
	var accel = (falloff * 5) >> 3
	var vel_add_x = (accel * source.facing)
	target.vel_x += vel_add_x
	if abs(target.vel_x) > source.pressure_max_vel:
		target.vel_x = clampi(target.vel_x, -source.pressure_max_vel, source.pressure_max_vel)
	if dy < 0:
		target.vel_y -= accel
		if target.vel_y < -source.pressure_max_vel:
			target.vel_y = -source.pressure_max_vel

func _apply_wall_constraints(parts: Array):
	var vp_x = 0; var vp_y = 0; var vp_w = 640; var vp_h = 480
	var floor_y = vp_y + vp_h - FLOOR_BUFFER
	var right_wall = vp_x + vp_w
	for p in parts:
		if not p.is_moving:
			continue
		var cor = p.cor_q8
		var bottom = p.y + p.height_1
		if bottom >= floor_y:
			p.y -= bottom - floor_y
			p.pos_y = p.y
			var new_vel = -(p.vel_y * cor) >> 8
			if abs(new_vel) < BOUNCE_VELOCITY_THRESHOLD:
				p.vel_y = 0
			else:
				p.vel_y = new_vel
		if p.y < vp_y:
			p.y = vp_y; p.pos_y = p.y; p.vel_y = 0
		if p.x < vp_x:
			p.x = vp_x; p.pos_x = p.x
			var new_vel = -(p.vel_x * cor) >> 8
			if abs(new_vel) < BOUNCE_VELOCITY_THRESHOLD:
				p.vel_x = 0
			else:
				p.vel_x = new_vel
		if p.x + p.width_1 > right_wall:
			p.x = right_wall - p.width_1
			p.pos_x = p.x
			var new_vel = -(p.vel_x * cor) >> 8
			if abs(new_vel) < BOUNCE_VELOCITY_THRESHOLD:
				p.vel_x = 0
			else:
				p.vel_x = new_vel

func _detect_and_resolve_collisions(parts: Array, tick_count: int):
	var grid = _build_spatial_grid(parts)
	var checked: Dictionary = {}
	for cell_key in grid:
		var cell_parts = grid[cell_key]
		var parts_list = cell_parts[0]
		var cx = cell_parts[1]
		var cy = cell_parts[2]
		for i in range(parts_list.size()):
			var ai = parts_list[i]
			var a = parts[ai]
			for ni in CELL_NEIGHBORS:
				var nk = str(cx + ni[0]) + "," + str(cy + ni[1])
				if not grid.has(nk):
					continue
				var neighbor = grid[nk][0]
				for j in range(neighbor.size()):
					var bj = neighbor[j]
					if bj == ai:
						continue
					var b = parts[bj]
					if b.is_moving and bj < ai:
						continue
					if a.id == 5 or b.id == 5 or a.id == 12 or b.id == 12 or \
					   (a.id == 6 and b.id == 7) or (a.id == 7 and b.id == 6) or \
					   (a.id == 7 and b.id == 8) or (a.id == 8 and b.id == 7):
						continue
					var pair_key = str(ai) + "," + str(bj)
					if checked.has(pair_key):
						continue
					checked[pair_key] = true
					if _detect_collision(a, b):
						_resolve_collision(a, b)

func _build_spatial_grid(parts: Array) -> Dictionary:
	var grid: Dictionary = {}
	for i in range(parts.size()):
		var p = parts[i]
		var cx = int(floor(float(p.x + p.width_1 / 2) / CELL_SIZE))
		var cy = int(floor(float(p.y + p.height_1 / 2) / CELL_SIZE))
		var key = str(cx) + "," + str(cy)
		if not grid.has(key):
			grid[key] = [[], cx, cy]
		grid[key][0].append(i)
	return grid

func _detect_collision(a, b) -> bool:
	return a.aabb_overlap(b)

func _resolve_collision(a, b):
	var l1 = a.x; var t1 = a.y
	var r1 = a.x + a.width_1; var b1 = a.y + a.height_1
	var l2 = b.x; var t2 = b.y
	var r2 = b.x + b.width_1; var b2 = b.y + b.height_1
	var overlap_x = min(r1, r2) - max(l1, l2)
	var overlap_y = min(b1, b2) - max(t1, t2)
	if overlap_x < 0 or overlap_y < 0:
		return
	var outcome = null
	if _solve_res_table:
		outcome = _solve_res_table.resolve(a, b, _board)
	if outcome == null or outcome.get("action") == _SolveResTable.CollisionResult.NONE:
		return
	if outcome.get("action") != _SolveResTable.CollisionResult.EXPLODE:
		_apply_physical_resolution(a, b, overlap_x, overlap_y)
	a.on_collision(b)
	b.on_collision(a)

func _apply_physical_resolution(a, b, overlap_x: int, overlap_y: int) -> void:
	var cor_a = a.cor_q8
	var cor_b = b.cor_q8
	if overlap_x < overlap_y:
		var push = overlap_x >> 1
		if a.is_moving:
			a.x -= push if a.vel_x >= 0 else -push
			a.pos_x = a.x
			var normal_vel = (-a.vel_x * cor_a) >> 8
			var friction = (a.friction_q8 * abs(a.vel_y)) >> 8
			a.vel_x = normal_vel
			a.vel_y = (a.vel_y * (256 - friction)) >> 8 if friction > 0 else a.vel_y
		if b.is_moving:
			b.x += push if b.vel_x >= 0 else -push
			b.pos_x = b.x
			var normal_vel = (-b.vel_x * cor_b) >> 8
			var friction = (b.friction_q8 * abs(b.vel_y)) >> 8
			b.vel_x = normal_vel
			b.vel_y = (b.vel_y * (256 - friction)) >> 8 if friction > 0 else b.vel_y
	else:
		var push = overlap_y >> 1
		if a.is_moving:
			a.y -= push if a.vel_y >= 0 else -push
			a.pos_y = a.y
			var normal_vel = (-a.vel_y * cor_a) >> 8
			var friction = (a.friction_q8 * abs(a.vel_x)) >> 8
			a.vel_y = normal_vel
			a.vel_x = (a.vel_x * (256 - friction)) >> 8 if friction > 0 else a.vel_x
		if b.is_moving:
			b.y += push if b.vel_y >= 0 else -push
			b.pos_y = b.y
			var normal_vel = (-b.vel_y * cor_b) >> 8
			var friction = (b.friction_q8 * abs(b.vel_x)) >> 8
			b.vel_y = normal_vel
			b.vel_x = (b.vel_x * (256 - friction)) >> 8 if friction > 0 else b.vel_x

func _handle_proximity_triggers(parts: Array):
	for i in range(parts.size()):
		var p = parts[i]
		if p.triggers.has("proximity"):
			for j in range(parts.size()):
				if i == j:
					continue
				var other = parts[j]
				var dx = abs(p.x + p.width_1 / 2 - (other.x + other.width_1 / 2))
				var dy = abs(p.y + p.height_1 / 2 - (other.y + other.height_1 / 2))
				if dx < 80 and dy < 80:
					p.on_collision(other)

func _handle_emitters_and_consumers(parts: Array):
	for i in range(parts.size()):
		var a = parts[i]
		if a.archetype == _Part.ARCH_EMITTER:
			if a.state_counter >= 2:
				a.is_powered = true
				for j in range(parts.size()):
					var c = parts[j]
					if c.archetype == _Part.ARCH_CONSUMER:
						var dx = abs(a.x - c.x)
						var dy = abs(a.y - c.y)
						if dx < 200 and dy < 200:
							c.is_powered = true

func _process_electrical():
	electrical_outlets.clear()
	for p in _board.parts:
		if p.part_type == 21 or p.part_type == 26 or p.part_type == 38:
			electrical_outlets[p.id] = {"powered": false, "plugged": []}

func _propagate_electrical():
	for oid in electrical_outlets:
		var outlet = electrical_outlets[oid]
		if not outlet.powered:
			for other in _board.parts:
				if other.part_type == 50:
					if abs(other.x - _board.parts[oid].x) < 50 and abs(other.y - _board.parts[oid].y) < 50:
						outlet.powered = true
						break
		if outlet.powered:
			for pid in outlet.plugged:
				var p = _board.parts[pid]
				if p and p.archetype == _Part.ARCH_CONSUMER:
					p.is_powered = true

func _process_flame_sources():
	ignition_sources.clear()
	for p in _board.parts:
		if _is_flame_source(p) and p.state_counter >= 1:
			ignition_sources.append(p)

func _check_ignition():
	var flammable = [18, 19, 36, 70]
	for flame in ignition_sources:
		for p in _board.parts:
			if flammable.has(p.part_type):
				var dx = abs(flame.x + flame.width_1/2 - (p.x + p.width_1/2))
				var dy = abs(flame.y + flame.height_1/2 - (p.y + p.height_1/2))
				if dx < 40 and dy < 40:
					if p.state_counter < p.state_limit_upper:
						p.state_counter = 2
						p.advance_state()

func _remove_destroyed_parts(parts: Array):
	var to_remove = []
	for p in parts:
		if p.destroyed:
			to_remove.append(p.id)
	for rid in to_remove:
		for i in range(parts.size()):
			if parts[i].id == rid:
				parts[i] = null
				break
	while parts.has(null):
		parts.erase(null)

func _enforce_rope_constraints(parts: Array):
	for _iter in range(CONSTRAINT_ITERATIONS):
		for p in parts:
			if p.archetype != _Part.ARCH_LINK:
				continue
			if p.connected_1 >= 0 and p.connected_1 < parts.size():
				_enforce_rope(p, parts[p.connected_1])

func _enforce_rope(part, target):
	var dx = (target.x + target.width_1 / 2) - (part.x + part.width_1 / 2)
	var dy = (target.y + target.height_1 / 2) - (part.y + part.height_1 / 2)
	var dist = maxi(abs(dx), abs(dy))
	if dist > part.rope_segment_length and dist > 0:
		var over = dist - part.rope_segment_length
		var corr = over >> 1
		if dx != 0:
			var nx = dx / dist
			part.x += (nx * corr) >> 8
			part.pos_x = part.x
			target.x -= (nx * corr) >> 8
			target.pos_x = target.x
		if dy != 0:
			var ny = dy / dist
			part.y += (ny * corr) >> 8
			part.pos_y = part.y
			target.y -= (ny * corr) >> 8
			target.pos_y = target.y

func _update_rope_connections(parts: Array):
	rope_endpoints.clear()
	for p in parts:
		if p.archetype == _Part.ARCH_LINK:
			var ep_a = _find_rope_attachment(p.x, p.y, parts)
			var ep_b = _find_rope_attachment(p.x + p.width_1, p.y + p.height_1, parts)
			if ep_a >= 0:
				rope_endpoints[p.id] = [ep_a, -1]
			if ep_b >= 0:
				if rope_endpoints.has(p.id):
					rope_endpoints[p.id][1] = ep_b
				else:
					rope_endpoints[p.id] = [-1, ep_b]

func _find_rope_attachment(x: int, y: int, parts: Array) -> int:
	var best_dist = 100
	var best_id = -1
	for p in parts:
		if p.id < 0 or p.id >= parts.size():
			continue
		if not _can_attach_rope(p):
			continue
		var cx = p.x + p.width_1 / 2
		var cy = p.y + p.height_1 / 2
		var dist = maxi(abs(x - cx), abs(y - cy))
		if dist < best_dist:
			best_dist = dist
			best_id = p.id
	return best_id

func _can_attach_rope(part) -> bool:
	var ropeable_categories = ["Special Mechanics", "Springs / Pneumatics", "Containers", "Balloons / Airships", "Characters", "Electrical", "Explosives / Projectiles", "Ropes / Belts / Pulleys"]
	return ropeable_categories.has(_get_part_category(part.part_type))

func _get_part_category(pt: int) -> String:
	var cat_map = {
		0: "Balls", 9: "Balls", 28: "Balls", 43: "Balls", 44: "Balls",
		59: "Balls", 63: "Balls", 68: "Balls", 87: "Balls",
		1: "Walls / Floors", 48: "Walls / Floors", 56: "Walls / Floors",
		2: "Inclines", 99: "Inclines", 100: "Inclines", 101: "Inclines", 102: "Inclines", 126: "Inclines",
		3: "Special Mechanics", 17: "Special Mechanics", 22: "Special Mechanics", 23: "Special Mechanics",
		52: "Special Mechanics", 58: "Special Mechanics", 66: "Special Mechanics",
		69: "Special Mechanics", 73: "Special Mechanics", 139: "Special Mechanics",
		4: "Balloons / Airships", 79: "Balloons / Airships", 109: "Balloons / Airships",
		5: "Rotating Power Sources", 6: "Rotating Power Sources", 14: "Rotating Power Sources",
		31: "Rotating Power Sources", 40: "Rotating Power Sources", 50: "Rotating Power Sources",
		86: "Rotating Power Sources",
		7: "Ropes / Belts / Pulleys", 8: "Ropes / Belts / Pulleys", 10: "Ropes / Belts / Pulleys",
		76: "Ropes / Belts / Pulleys",
		11: "Containers", 15: "Containers", 71: "Containers",
		12: "Characters", 32: "Characters", 33: "Characters", 34: "Characters",
		42: "Characters", 54: "Characters", 61: "Characters", 65: "Characters",
		13: "Springs / Pneumatics", 16: "Springs / Pneumatics", 35: "Springs / Pneumatics",
		39: "Springs / Pneumatics", 75: "Springs / Pneumatics", 89: "Springs / Pneumatics",
		97: "Springs / Pneumatics", 98: "Springs / Pneumatics", 107: "Springs / Pneumatics",
		18: "Explosives / Projectiles", 19: "Explosives / Projectiles", 20: "Explosives / Projectiles",
		27: "Explosives / Projectiles", 36: "Explosives / Projectiles",
		41: "Explosives / Projectiles", 55: "Explosives / Projectiles", 70: "Explosives / Projectiles",
		74: "Explosives / Projectiles", 80: "Explosives / Projectiles",
		21: "Electrical", 24: "Electrical", 25: "Electrical", 26: "Electrical",
		38: "Electrical", 51: "Electrical", 67: "Electrical", 81: "Electrical", 120: "Electrical",
		29: "Light / Flame Sources", 78: "Light / Flame Sources", 108: "Light / Flame Sources",
		136: "Light / Flame Sources", 138: "Light / Flame Sources",
		30: "Lasers / Optics", 91: "Lasers / Optics", 92: "Lasers / Optics", 93: "Lasers / Optics",
		94: "Lasers / Optics", 95: "Lasers / Optics", 96: "Lasers / Optics", 148: "Lasers / Optics"
	}
	return cat_map.get(pt, "Unknown")

func _is_explosive(p) -> bool:
	var explosive_types = [18, 19, 22, 27, 36, 41, 55, 70, 74, 75, 80]
	return explosive_types.has(p.part_type)

func _is_laser_emitter(p) -> bool:
	return p.part_type >= 91 and p.part_type <= 96

func _is_flame_source(p) -> bool:
	var flame_types = [29, 45, 62, 78, 108, 138, 75, 80]
	return flame_types.has(p.part_type)

func spawn_projectile(source, projectile_type: int, angle: float, speed: int):
	if _board.parts.size() >= _board.MAX_PARTS:
		return null
	var px = source.x + source.width_1 / 2
	var py = source.y + source.height_1 / 2
	var vx = int(cos(angle) * speed)
	var vy = int(sin(angle) * speed)
	const _Part = preload("res://Scripts/Part.gd")
	var proj = _Part.new(_board.parts.size(), projectile_type, _Part.ARCH_KINETIC, px - 8, py - 8)
	proj.vel_x = vx
	proj.vel_y = vy
	proj.mass = 500
	proj.cor_q8 = 64
	proj.damping = 10
	proj.is_moving = true
	spawned_projectiles.append(_board.add_part(proj))
	return proj