extends RefCounted
class_name PhysicsSolver

const MAX_TICKS: int = 10000

var world_state: WorldState
var tick_counter: int = 0

const FLOOR_BUFFER: int = 32
const BOUNCE_VELOCITY_THRESHOLD: int = 0x800
const PROXIMITY_RANGE: int = 50
const CONSTRAINT_ITERATIONS: int = 3
const ROPE_PART_TYPES: Array = [7, 10, 76]

var collision_matrix: Dictionary = {
	"STATIC": ["DYNAMIC", "EXPLOSIVE", "TOOL", "ROPE"],
	"DYNAMIC": ["STATIC", "DYNAMIC", "EXPLOSIVE", "TOOL", "ROPE"],
	"EXPLOSIVE": ["STATIC", "DYNAMIC", "EXPLOSIVE", "TOOL", "ROPE", "SCENERY", "CREATED"],
	"TOOL": ["STATIC", "DYNAMIC", "EXPLOSIVE", "TOOL"],
	"ROPE": ["ROPE"],
	"SCENERY": [],
	"CREATED": ["STATIC"],
}

var electrical_consumer_states: Dictionary = {
	24: [1, 2],    # Fan: off → on
	50: [1, 4],    # Electric Motor: off → running
	51: [9, 10],   # Vacuum: off → on
	67: [1, 3],    # Can Opener: closed → opened
	81: [1, 8],    # Toaster: off → toasting
	107: [2, 1],   # Mixer: off → on
}

func _init(state: WorldState):
	world_state = state

func step() -> void:
	if tick_counter >= MAX_TICKS:
		return
	tick_counter += 1
	world_state.tick_count = tick_counter

	var parts = world_state.parts
	var vp = world_state.viewport

	# Pass 0: State counters
	for part in parts:
		if part.is_moving:
			part.advance_state()

	# Pass 1: Gravity
	for part in parts:
		if part.is_moving:
			part.tick()

	# Pass 2: Behaviors (inlined common handlers)
	_handle_behaviors(parts)

	# Pass 3: Viewport bounds
	_apply_viewport_bounds(parts, vp)

	# Pass 4: Collisions
	for i in range(len(parts)):
		var a = parts[i]
		if not a.is_moving:
			continue
		var cat_a = a.collision_cat
		for j in range(i + 1, len(parts)):
			var b = parts[j]
			var cat_b = b.collision_cat
			if not _should_collide(cat_a, cat_b):
				continue
			if a.connected_1 == j or a.connected_2 == j or b.connected_1 == i or b.connected_2 == i:
				continue
			if _detect_collision(a, b):
				_resolve_collision(a, b)

	# Pass 5: Proximity + Electrical
	_check_proximity_behaviors(parts)
	_propagate_electrical(parts)

	# Pass 6: Constraints
	for _iter in range(CONSTRAINT_ITERATIONS):
		for part in parts:
			if part.part_type not in ROPE_PART_TYPES:
				continue
			if 0 <= part.connected_1 and part.connected_1 < len(parts):
				_enforce_rope_constraint(part, parts[part.connected_1])

	# Post-step: state change callbacks
	if world_state.on_state_change.is_valid():
		for part in parts:
			if part.state_counter != part.state_prev:
				part.state_prev = part.state_counter
				world_state.on_state_change.call(part)

func _handle_behaviors(parts: Array):
	for part in parts:
		match part.part_type:
			5: # Conveyor belt
				part.vel_x += 16 if part.appearance & PartData.FLAG_FLIP else -16
			6: # Gear
				part.angular_velocity = 4
			7, 10, 76: # Ropes/pulley
				pass
			8: # Belt sync
				if part.belt_connected_part_1 >= 0 and part.belt_connected_part_1 < len(parts):
					var other = parts[part.belt_connected_part_1]
					part.angular_velocity = (part.angular_velocity + other.angular_velocity) / 2
			18: # Cannon
				part.facing = 1 if part.appearance & PartData.FLAG_FLIP == 0 else -1
			21, 22, 25, 27, 28: # Electrical tools
				pass
			35, 36: # Rocket
				if part.state_counter >= 2:
					part.vel_y -= 64
			37: # Hedge trimmers
				pass
			42: # Newton's mouse
				pass
			55, 56: # Magnifying glass
				pass
			57, 58: # Mel's house
				pass
			59: # Springboard
				pass
			69: # Boxing glove
				part.vel_x = 512 * part.facing
			_:
				pass

func _apply_viewport_bounds(parts: Array, vp: Array):
	var vx = vp[0]; var vy = vp[1]; var vw = vp[2]; var vh = vp[3]
	var floor_y = vy + vh - FLOOR_BUFFER
	var right_wall = vx + vw

	for part in parts:
		if not part.is_moving:
			continue
		var cor = part.cor_q8

		var bottom = part.y + part.height_1
		if bottom >= floor_y:
			part.y -= bottom - floor_y
			part.pos_y = part.y
			var new_vel = -(part.vel_y * cor) >> 8
			if abs(new_vel) < BOUNCE_VELOCITY_THRESHOLD:
				part.vel_y = 0
			else:
				part.vel_y = new_vel

		if part.y < vy:
			part.y = vy
			part.pos_y = part.y
			var new_vel = (part.vel_y * cor) >> 8
			if abs(new_vel) < BOUNCE_VELOCITY_THRESHOLD:
				part.vel_y = 0
			else:
				part.vel_y = new_vel

		if part.x < vx:
			part.x = vx
			part.pos_x = part.x
			var new_vel = -(part.vel_x * cor) >> 8
			if abs(new_vel) < BOUNCE_VELOCITY_THRESHOLD:
				part.vel_x = 0
			else:
				part.vel_x = new_vel

		if part.x + part.width_1 > right_wall:
			part.x = right_wall - part.width_1
			part.pos_x = part.x
			var new_vel = -(part.vel_x * cor) >> 8
			if abs(new_vel) < BOUNCE_VELOCITY_THRESHOLD:
				part.vel_x = 0
			else:
				part.vel_x = new_vel

func _should_collide(cat_a: String, cat_b: String) -> bool:
	var targets = collision_matrix.get(cat_a, [])
	return cat_b in targets

func _detect_collision(a: PartData, b: PartData) -> bool:
	var a_is_circle = a.collision_radius > 0
	var b_is_circle = b.collision_radius > 0
	if a_is_circle and b_is_circle:
		return _circle_overlap(a, b)
	if a_is_circle:
		return _circle_aabb_overlap(a, b)
	if b_is_circle:
		return _circle_aabb_overlap(b, a)
	return a.aabb_overlap(b)

func _circle_overlap(a: PartData, b: PartData) -> bool:
	var ca = a.get_circle()
	var cb = b.get_circle()
	var dx = ca[0] - cb[0]
	var dy = ca[1] - cb[1]
	var r_sum = ca[2] + cb[2]
	return dx * dx + dy * dy < r_sum * r_sum

func _circle_aabb_overlap(circle: PartData, aabb: PartData) -> bool:
	var c = circle.get_circle()
	var box = aabb.get_collision_box()
	var closest_x = max(box[0], min(c[0], box[2]))
	var closest_y = max(box[1], min(c[1], box[3]))
	var dx = c[0] - closest_x
	var dy = c[1] - closest_y
	return dx * dx + dy * dy < c[2] * c[2]

func _resolve_collision(a: PartData, b: PartData):
	var cor = a.cor_q8
	var no_bounce = b.part_type == 5

	if a.collision_radius > 0:
		_resolve_circle_collision(a, b, cor, no_bounce)
		return

	var l1 = a.x; var t1 = a.y
	var r1 = a.x + (a.collision_w if a.collision_w > 0 else a.width_1)
	var b1 = a.y + (a.collision_h if a.collision_h > 0 else a.height_1)
	var l2 = b.x; var t2 = b.y
	var r2 = b.x + (b.collision_w if b.collision_w > 0 else b.width_1)
	var b2 = b.y + (b.collision_h if b.collision_h > 0 else b.height_1)

	var overlap_x = min(r1, r2) - max(l1, l2)
	var overlap_y = min(b1, b2) - max(t1, t2)

	if overlap_x < overlap_y:
		if a.vel_x >= 0:
			a.x = b.x - (r1 - l1)
		else:
			a.x = b.x + (r2 - l2)
		a.pos_x = a.x
		if not no_bounce:
			a.vel_x = (-a.vel_x * cor) >> 8
			var fric = a.friction_q8 >> 1
			if fric > 0:
				a.vel_x = int(a.vel_x * (256 - fric) / 256)
	else:
		if a.vel_y >= 0:
			a.y = b.y - (b1 - t1)
		else:
			a.y = b.y + (b2 - t2)
		a.pos_y = a.y
		if not no_bounce:
			a.vel_y = (-a.vel_y * cor) >> 8
			var fric = a.friction_q8 >> 1
			if fric > 0:
				a.vel_x = int(a.vel_x * (256 - fric) / 256)

	_apply_solve_collision(a, b)
	if world_state.on_collision.is_valid():
		world_state.on_collision.call(a, b)

func _resolve_circle_collision(a: PartData, b: PartData, cor: int, no_bounce: bool):
	var ca = a.get_circle()
	var ax = ca[0]; var ay = ca[1]; var ar = ca[2]

	if b.collision_radius > 0:
		var cb = b.get_circle()
		var dx = ax - cb[0]
		var dy = ay - cb[1]
		var dist = sqrt(dx * dx + dy * dy)
		if dist == 0: dist = 1
		var overlap = (ar + cb[2]) - dist
		var nx = dx / dist
		var ny = dy / dist
		a.x += int(nx * overlap)
		a.y += int(ny * overlap)
		a.pos_x = a.x; a.pos_y = a.y
		var vn = a.vel_x * nx + a.vel_y * ny
		if vn < 0 and not no_bounce:
			var cf = 256 + cor
			a.vel_x -= int(vn * cf * nx) >> 8
			a.vel_y -= int(vn * cf * ny) >> 8
	else:
		var box = b.get_collision_box()
		var closest_x = max(box[0], min(ax, box[2]))
		var closest_y = max(box[1], min(ay, box[3]))
		var dx = ax - closest_x
		var dy = ay - closest_y
		var dist = sqrt(dx * dx + dy * dy)
		if dist == 0: dist = 1
		var overlap = ar - dist
		var nx = dx / dist
		var ny = dy / dist
		a.x += int(nx * overlap)
		a.y += int(ny * overlap)
		a.pos_x = a.x; a.pos_y = a.y
		var vn = a.vel_x * nx + a.vel_y * ny
		if vn < 0 and not no_bounce:
			var cf = 256 + cor
			a.vel_x -= int(vn * cf * nx) >> 8
			a.vel_y -= int(vn * cf * ny) >> 8

	_apply_solve_collision(a, b)
	if world_state.on_collision.is_valid():
		world_state.on_collision.call(a, b)

func _apply_solve_collision(a: PartData, b: PartData):
	a.on_collision(b)
	b.on_collision(a)

func _check_proximity_behaviors(parts: Array):
	for i in range(len(parts)):
		var a = parts[i]
		var a_beh = BehaviorRegistry.get_behavior(a.part_type)
		var rules = a_beh.get("rules", {})
		for rule_key in rules:
			var rule = rules[rule_key]
			if rule.get("response") != "state_transition":
				continue
			var trigger_cats = rule.get("ignites_categories", rule.get("trigger_if_other_in_category", []))
			if trigger_cats.is_empty():
				continue
			for j in range(len(parts)):
				if i == j or not parts[j].is_moving:
					continue
				var b = parts[j]
				var b_cat = BehaviorRegistry.get_category(b.part_type)
				if b_cat in trigger_cats:
					var dx = abs(a.x - b.x)
					var dy = abs(a.y - b.y)
					if dx < PROXIMITY_RANGE and dy < PROXIMITY_RANGE:
						a.state_counter = a.state_limit_upper - 1
						a.current_state = a.state_counter

func _is_source_active(part: PartData) -> bool:
	var pt = part.part_type
	if pt == 120: return true
	if pt == 21: return part.state_counter >= 8
	if pt == 26: return part.state_counter >= 2
	if pt == 38: return part.state_counter == 2
	if pt == 25: return part.state_counter == 2
	if pt == 96: return part.state_counter >= 2
	return false

func _propagate_electrical(parts: Array):
	for source in parts:
		if not (source.flags_3 & 0x2):
			continue
		var powered = _is_source_active(source)
		for idx in [source.outlet_plugged_1, source.outlet_plugged_2]:
			if idx < 0 or idx >= len(parts):
				continue
			var consumer = parts[idx]
			var states = electrical_consumer_states.get(consumer.part_type)
			if states == null:
				continue
			var off_state = states[0]
			var on_state = states[1]
			if powered and consumer.state_counter != on_state:
				consumer.state_counter = on_state
				consumer.current_state = on_state
			elif not powered and consumer.state_counter == on_state:
				consumer.state_counter = off_state
				consumer.current_state = off_state

func _enforce_rope_constraint(part: PartData, target: PartData):
	var dx = (target.x + target.width_1 / 2.0) - (part.x + part.width_1 / 2.0)
	var dy = (target.y + target.height_1 / 2.0) - (part.y + part.height_1 / 2.0)
	var dist = sqrt(dx * dx + dy * dy)
	var max_len = part.rope_segment_length
	if dist > max_len and dist > 0:
		var correction = (dist - max_len) / 2.0
		var nx = dx / dist
		var ny = dy / dist
		part.x += int(nx * correction); part.pos_x = part.x
		part.y += int(ny * correction); part.pos_y = part.y
		target.x -= int(nx * correction); target.pos_x = target.x
		target.y -= int(ny * correction); target.pos_y = target.y
