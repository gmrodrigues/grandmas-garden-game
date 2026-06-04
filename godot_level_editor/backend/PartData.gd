extends RefCounted
class_name PartData

const FLAG_MOVING: int = 0x1000
const FLAG_FLIP: int = 0x8000

enum CollShape { CIRCLE, AABB }

var part_type: int = 0
var name: String = "Unknown"

var x: int = 0
var y: int = 0
var width_1: int = 32
var height_1: int = 32
var width_2: int = 32
var height_2: int = 32

var pos_x: int = 0
var pos_y: int = 0
var vel_x: int = 0
var vel_y: int = 0

var flags_1: int = 0
var flags_2: int = 0
var flags_3: int = 0
var appearance: int = 0
var behavior: int = 0

var belt_anchor_x: int = 0
var belt_anchor_y: int = 0
var belt_line_distance: int = 0
var rope_1_anchor_x: int = 0
var rope_1_anchor_y: int = 0
var rope_2_anchor_x: int = 0
var rope_2_anchor_y: int = 0
var connected_1: int = -256
var connected_2: int = -1
var outlet_plugged_1: int = -1
var outlet_plugged_2: int = -1

var rope_segment_length: int = 200

var mass: int = 2832
var cor_q8: int = 128
var friction_q8: int = 0
var collision_radius: int = 0
var collision_w: int = 0
var collision_h: int = 0
var gravity_category: int = 7
var max_gravity: int = 0x2600
var wind_force: int = 0

var current_state: int = 0
var is_moving: bool = false
var is_solved: bool = false

var state_counter: int = 0
var state_prev: int = 0
var sub_counter: int = 0
var state_limit_lower: int = 0
var state_limit_upper: int = 8
var state_limit_reset: int = 0
var state_limit_sub_a: int = 5
var state_limit_sub_b: int = 5

var anm_frame: int = 0
var anm_frame_timer: int = 0
var anm_name: String = ""

var motor_connected: bool = false
var angular_velocity: int = 0
var rotation_angle: int = 0
var facing: int = 1

var pulley_rope_1_connect_x: int = 0
var pulley_rope_1_connect_y: int = 0
var pulley_rope_2_connect_x: int = 0
var pulley_rope_2_connect_y: int = 0
var rope_index: int = -1

var belt_connected_part_1: int = -1
var belt_connected_part_2: int = -1

var _rng_state: int = 1
var _countdown: int = -1
var explosion_timer: float = 0
var explosion_radius: int = 0

var density: int = 3000
var elasticity: int = 128
var friction_extra: int = 16
var gravity_buoyancy: int = 0

var collision_cat: String = "DYNAMIC"

func _init(_type: int = 0, _x: int = 0, _y: int = 0):
	part_type = _type
	x = _x
	y = _y
	pos_x = _x
	pos_y = _y
	is_moving = bool(flags_1 & FLAG_MOVING)

func sync_pos():
	pos_x = x
	pos_y = y

func get_coll_shape() -> int:
	return CollShape.CIRCLE if collision_radius > 0 else CollShape.AABB

func get_gravity_base() -> int:
	var cat = gravity_category
	if cat < 2:   return 0x1C00
	if cat < 6:   return 0x1A00
	if cat < 10:  return 0x1800
	if cat < 21:  return 0x1600
	if cat < 121: return 0x1400
	if cat < 151: return 0x1200
	return 0x1000

func get_gravity_y() -> int:
	return get_gravity_base() / 4

func _clamp_gravity(val: int) -> int:
	if val > max_gravity: return max_gravity
	if val < -max_gravity: return -max_gravity
	return val

func _compute_gravity_x() -> int:
	var wf = wind_force
	if wf == 0: return 0
	if flags_3 & 0x08:
		return -_clamp_gravity(wf)
	return _clamp_gravity(wf)

func tick():
	var gy = _clamp_gravity(get_gravity_y())
	var gx = _compute_gravity_x()
	vel_y += gy
	vel_x += gx
	if gravity_buoyancy != 0:
		vel_y += gravity_buoyancy
	pos_y += vel_y >> 9
	pos_x += vel_x >> 9
	x = pos_x
	y = pos_y

func advance_state() -> bool:
	state_prev = state_counter
	if sub_counter == 0:
		if state_counter != 0:
			if state_counter < state_limit_lower:
				state_counter = state_limit_lower - 1
			state_counter += 1
			if state_counter >= state_limit_upper:
				state_counter = state_limit_reset
		else:
			if _rng_state & 1:
				if _countdown < 0:
					_countdown = _randint(40, 239)
				_countdown -= 1
				if _countdown < 0:
					state_counter += 1
					_countdown = _randint(40, 239)
			else:
				state_counter += 1
	else:
		sub_counter -= 1
		if sub_counter == 0:
			state_counter = state_limit_reset
		else:
			state_counter += 1
			if state_counter >= state_limit_sub_a:
				state_counter = state_limit_sub_b
	return state_counter != state_prev

func _randint(lo: int, hi: int) -> int:
	_rng_state = (_rng_state * 0x343FD + 0x269EC3) & 0xFFFFFFFF
	return lo + (_rng_state % (hi - lo + 1))

func on_collision(other: PartData) -> bool:
	var changed = false
	if state_counter < state_limit_upper:
		state_counter += 1
		changed = true
	current_state = state_counter
	return changed

func get_collision_box() -> Array:
	var w = collision_w if collision_w > 0 else width_1
	var h = collision_h if collision_h > 0 else height_1
	return [x, y, x + w, y + h]

func get_circle() -> Array:
	var r = collision_radius
	var cx = x + width_1 / 2
	var cy = y + height_1 / 2
	return [cx, cy, r]

func aabb_overlap(other: PartData) -> bool:
	var l1 = x; var t1 = y
	var r1 = x + (collision_w if collision_w > 0 else width_1)
	var b1 = y + (collision_h if collision_h > 0 else height_1)
	var l2 = other.x; var t2 = other.y
	var r2 = other.x + (other.collision_w if other.collision_w > 0 else other.width_1)
	var b2 = other.y + (other.collision_h if other.collision_h > 0 else other.height_1)
	return l1 < r2 and r1 > l2 and t1 < b2 and b1 > t2

func distance_to(other: PartData) -> float:
	var cx1 = x + width_1 / 2.0
	var cy1 = y + height_1 / 2.0
	var cx2 = other.x + other.width_2 / 2.0
	var cy2 = other.y + other.height_2 / 2.0
	var dx = cx1 - cx2
	var dy = cy1 - cy2
	return sqrt(dx * dx + dy * dy)
