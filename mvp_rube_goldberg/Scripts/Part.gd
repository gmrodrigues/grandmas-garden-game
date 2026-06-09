class_name Part
extends RefCounted

var id: int = -1
var x: int = 0
var y: int = 0
var pos_x: int = 0
var pos_y: int = 0
var vel_x: int = 0
var vel_y: int = 0
var width_1: int = 32
var height_1: int = 32
var width_2: int = 32
var height_2: int = 32
var mass: int = 2832
var cor_q8: int = 128
var friction_q8: int = 0
var collision_radius: int = 0
var part_type: int = 0
var archetype: int = 0
var appearance: int = 0
var flags_1: int = 0
var is_moving: bool = false
var is_powered: bool = false
var facing: int = 1
var state_counter: int = 0
var state_limit_upper: int = 8
var state_limit_lower: int = 0
var state_limit_reset: int = 0
var current_state: int = 0
var sub_counter: int = 0
var _rng_state: int = 1
var _countdown: int = -1
var connected_1: int = -1
var connected_2: int = -1
var rope_segment_length: int = 200
var rope_pull_x: int = 0
var rope_pull_y: int = 0
var angular_velocity: int = 0
var gravity_category: int = 7
var gravity_buoyancy: int = 0
var name: String = ""
var state_limit_sub_a: int = 5
var state_limit_sub_b: int = 5
var pressure_max_vel: int = 512
var damping: int = 200
var triggers: Array = []
var destructible: bool = false
var spawns: Array = []
var destroyed: bool = false

const FLAG_MOVING: int = 0x1000
const FLAG_FLIP: int = 0x8000

const ARCH_STATIC: int = 0
const ARCH_KINETIC: int = 1
const ARCH_DRIVER: int = 2
const ARCH_LINK: int = 3
const ARCH_EMITTER: int = 4
const ARCH_CONSUMER: int = 5

func _init(_id: int = -1, _type: int = 0, _arch: int = 0, _x: int = 0, _y: int = 0):
	id = _id
	part_type = _type
	archetype = _arch
	x = _x
	y = _y
	pos_x = _x
	pos_y = _y
	is_moving = bool(flags_1 & FLAG_MOVING)

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

func tick():
	var gy = get_gravity_y()
	vel_y += gy
	if gravity_buoyancy != 0:
		vel_y += gravity_buoyancy
	if damping > 0:
		vel_x = (vel_x * (256 - damping)) >> 8
		vel_y = (vel_y * (256 - damping)) >> 8
	pos_y += vel_y >> 9
	pos_x += vel_x >> 9
	x = pos_x
	y = pos_y

func advance_state() -> bool:
	var prev = state_counter
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
	return state_counter != prev

func _randint(lo: int, hi: int) -> int:
	_rng_state = (_rng_state * 0x343FD + 0x269EC3) & 0xFFFFFFFF
	return lo + (_rng_state % (hi - lo + 1))

func aabb_overlap(other: Part) -> bool:
	var l1 = x; var t1 = y
	var r1 = x + width_1; var b1 = y + height_1
	var l2 = other.x; var t2 = other.y
	var r2 = other.x + other.width_1; var b2 = other.y + other.height_1
	return l1 < r2 and r1 > l2 and t1 < b2 and b1 > t2

func get_collision_box() -> Array:
	return [x, y, x + width_1, y + height_1]

func on_collision(other: Part) -> bool:
	if triggers.has("collision"):
		if state_counter < state_limit_upper:
			state_counter += 1
			current_state = state_counter
			return true
	return false