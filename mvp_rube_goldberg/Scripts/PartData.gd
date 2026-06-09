class_name PartData
extends RefCounted

signal changed(part_data: PartData, field: String)
signal selection_changed(part_data: PartData)
signal connection_request(from_part: PartData, to_part: PartData, connection_type: int)
signal deleted(part_data: PartData)

const MAX_PARTS: int = 32
const GRID_SIZE: int = 16

enum ConnectionType { ROPE, BELT, ELECTRICAL }

const HANDLE_UL: int = 0
const HANDLE_U: int = 1
const HANDLE_UR: int = 2
const HANDLE_R: int = 3
const HANDLE_BR: int = 4
const HANDLE_B: int = 5
const HANDLE_BL: int = 6
const HANDLE_L: int = 7

const HANDLE_SIZE: int = 6

const ARCH_STATIC: int = 0
const ARCH_KINETIC: int = 1
const ARCH_DRIVER: int = 2
const ARCH_LINK: int = 3
const ARCH_EMITTER: int = 4
const ARCH_CONSUMER: int = 5

var id: int = -1
var name: String = ""
var part_type: int = 0
var archetype: int = ARCH_STATIC
var category: String = ""

var x: int = 0
var y: int = 0
var width_1: int = 32
var height_1: int = 32
var width_2: int = 32
var height_2: int = 32

var appearance: int = 0
var facing: int = 1

var is_moving: bool = false
var is_powered: bool = false
var is_locked: bool = false
var is_flip_h: bool = false

var state_counter: int = 0
var current_state: int = 0
var state_limit_upper: int = 8
var state_limit_lower: int = 0
var state_limit_reset: int = 0
var state_limit_sub_a: int = 5
var state_limit_sub_b: int = 5

var mass: int = 2832
var cor_q8: int = 128
var friction_q8: int = 0
var damping: int = 200
var collision_radius: int = 0
var gravity_category: int = 7
var gravity_buoyancy: int = 0

var rope_segment_length: int = 200
var connected_1: int = -1
var connected_2: int = -1
var angular_velocity: int = 0

var pressure_max_vel: int = 512
var triggers: Array = []
var destructible: bool = false
var spawns: Array = []

var anm_name: String = ""
var anm_states: Array = []
var anm_num_states: int = 1
var anm_num_frames: int = 1
var anm_is_animated: bool = false

var solve_name: String = ""
var description: String = ""

var selected_handle: int = -1
var is_selected: bool = false
var gizmo_color: Color = Color(0.3, 0.8, 1.0, 0.9)

var _undo_stack: Array = []
var _redo_stack: Array = []

func _init(id_val: int = -1, type_val: int = 0, x_val: int = 0, y_val: int = 0):
	id = id_val
	part_type = type_val
	x = x_val
	y = y_val

func copy_from(other: PartData) -> void:
	for prop in _get_field_names():
		if prop in ["id", "_undo_stack", "_redo_stack"]:
			continue
		if other.has(prop):
			set(prop, other.get(prop))

func clone() -> PartData:
	var c = PartData.new(id, part_type, x, y)
	c.copy_from(self)
	return c

func get_rect() -> Rect2i:
	return Rect2i(x, y, width_1, height_1)

func set_position(new_x: int, new_y: int) -> void:
	if x != new_x or y != new_y:
		_push_undo("position", {"x": x, "y": y})
		x = new_x
		y = new_y
		changed.emit(self, "position")

func set_size(new_w: int, new_h: int) -> void:
	if width_1 != new_w or height_1 != new_h:
		_push_undo("size", {"width_1": width_1, "height_1": height_1})
		width_1 = new_w
		height_1 = new_h
		changed.emit(self, "size")

func set_field(field: String, value) -> void:
	_push_undo(field, get(field))
	set(field, value)
	changed.emit(self, field)

func flip_horizontal() -> void:
	is_flip_h = !is_flip_h
	facing = -facing if facing != 0 else 1
	appearance ^= 0x8000
	changed.emit(self, "flip")

func toggle_lock() -> void:
	is_locked = !is_locked
	changed.emit(self, "lock")

func get_handle_position(handle_idx: int) -> Vector2i:
	match handle_idx:
		HANDLE_UL: return Vector2i(x, y)
		HANDLE_U:  return Vector2i(x + width_1 / 2, y)
		HANDLE_UR: return Vector2i(x + width_1, y)
		HANDLE_R:  return Vector2i(x + width_1, y + height_1 / 2)
		HANDLE_BR: return Vector2i(x + width_1, y + height_1)
		HANDLE_B:  return Vector2i(x + width_1 / 2, y + height_1)
		HANDLE_BL: return Vector2i(x, y + height_1)
		HANDLE_L:  return Vector2i(x, y + height_1 / 2)
	return Vector2i(x, y)

func hit_test(px: int, py: int) -> bool:
	return px >= x and px < x + width_1 and py >= y and py < y + height_1

func hit_test_handle(px: int, py: int) -> int:
	for i in range(8):
		var hp = get_handle_position(i)
		if abs(px - hp.x) <= HANDLE_SIZE and abs(py - hp.y) <= HANDLE_SIZE:
			return i
	return -1

func snap_to_grid(val: int) -> int:
	return (val / GRID_SIZE) * GRID_SIZE

func snap_position() -> void:
	x = snap_to_grid(x)
	y = snap_to_grid(y)

func to_dict() -> Dictionary:
	return {
		"id": id,
		"part_type": part_type,
		"name": name,
		"pos_x": x,
		"pos_y": y,
		"width": width_1,
		"height": height_1,
		"width_2": width_2,
		"height_2": height_2,
		"appearance": appearance,
		"facing": facing,
		"is_moving": is_moving,
		"is_powered": is_powered,
		"state_counter": state_counter,
		"state_limit_upper": state_limit_upper,
		"state_limit_lower": state_limit_lower,
		"state_limit_reset": state_limit_reset,
		"state_limit_sub_a": state_limit_sub_a,
		"state_limit_sub_b": state_limit_sub_b,
		"mass": mass,
		"cor_q8": cor_q8,
		"friction_q8": friction_q8,
		"damping": damping,
		"collision_radius": collision_radius,
		"gravity_category": gravity_category,
		"gravity_buoyancy": gravity_buoyancy,
		"rope_segment_length": rope_segment_length,
		"connected_1": connected_1,
		"connected_2": connected_2,
		"pressure_max_vel": pressure_max_vel,
		"triggers": triggers.duplicate(),
		"destructible": destructible,
		"spawns": spawns.duplicate(),
		"anm_name": anm_name,
		"anm_states": anm_states.duplicate(),
		"anm_num_states": anm_num_states,
		"anm_num_frames": anm_num_frames,
		"anm_is_animated": anm_is_animated,
		"solve_name": solve_name,
		"description": description,
		"is_locked": is_locked,
		"angular_velocity": angular_velocity,
	}

func from_dict(d: Dictionary) -> void:
	part_type = d.get("part_type", 0)
	name = d.get("name", "")
	x = d.get("pos_x", 0)
	y = d.get("pos_y", 0)
	width_1 = d.get("width", 32)
	height_1 = d.get("height", 32)
	width_2 = d.get("width_2", width_1)
	height_2 = d.get("height_2", height_1)
	appearance = d.get("appearance", 0)
	facing = d.get("facing", 1)
	is_moving = d.get("is_moving", false)
	is_powered = d.get("is_powered", false)
	state_counter = d.get("state_counter", 0)
	state_limit_upper = d.get("state_limit_upper", 8)
	state_limit_lower = d.get("state_limit_lower", 0)
	state_limit_reset = d.get("state_limit_reset", 0)
	state_limit_sub_a = d.get("state_limit_sub_a", 5)
	state_limit_sub_b = d.get("state_limit_sub_b", 5)
	mass = d.get("mass", 2832)
	cor_q8 = d.get("cor_q8", 128)
	friction_q8 = d.get("friction_q8", 0)
	damping = d.get("damping", 200)
	collision_radius = d.get("collision_radius", 0)
	gravity_category = d.get("gravity_category", 7)
	gravity_buoyancy = d.get("gravity_buoyancy", 0)
	rope_segment_length = d.get("rope_segment_length", 200)
	connected_1 = d.get("connected_1", -1)
	connected_2 = d.get("connected_2", -1)
	pressure_max_vel = d.get("pressure_max_vel", 512)
	if d.has("triggers"):
		triggers = d["triggers"].duplicate()
	destructible = d.get("destructible", false)
	if d.has("spawns"):
		spawns = d["spawns"].duplicate()
	anm_name = d.get("anm_name", "")
	anm_states = d.get("anm_states", [])
	anm_num_states = d.get("anm_num_states", 1)
	anm_num_frames = d.get("anm_num_frames", 1)
	anm_is_animated = d.get("anm_is_animated", false)
	solve_name = d.get("solve_name", "")
	description = d.get("description", "")
	is_locked = d.get("is_locked", false)
	angular_velocity = d.get("angular_velocity", 0)

func undo() -> void:
	if _undo_stack.is_empty():
		return
	var action = _undo_stack.pop_back()
	_push_redo(action.field, get(action.field))
	set(action.field, action.old_value)
	changed.emit(self, action.field)

func redo() -> void:
	if _redo_stack.is_empty():
		return
	var action = _redo_stack.pop_back()
	_push_undo(action.field, get(action.field))
	set(action.field, action.new_value)
	changed.emit(self, action.field)

func clear_history() -> void:
	_undo_stack.clear()
	_redo_stack.clear()

func _push_undo(field: String, old_value) -> void:
	_undo_stack.push_back({"field": field, "old_value": old_value})
	_redo_stack.clear()
	if _undo_stack.size() > 50:
		_undo_stack.pop_front()

func _push_redo(field: String, new_value) -> void:
	_redo_stack.push_back({"field": field, "new_value": new_value})

func _get_field_names() -> Array:
	return ["id", "name", "part_type", "archetype", "category", "x", "y", "width_1", "height_1",
		"width_2", "height_2", "appearance", "facing", "is_moving", "is_powered", "is_locked",
		"state_counter", "current_state", "state_limit_upper", "state_limit_lower",
		"state_limit_reset", "state_limit_sub_a", "state_limit_sub_b", "mass", "cor_q8",
		"friction_q8", "damping", "collision_radius", "gravity_category", "gravity_buoyancy",
		"rope_segment_length", "connected_1", "connected_2", "angular_velocity",
		"pressure_max_vel", "triggers", "destructible", "anm_name", "solve_name", "description"]

func resolve_collision(other: PartData) -> bool:
	if triggers.has("collision"):
		if state_counter < state_limit_upper:
			state_counter += 1
			current_state = state_counter
			return true
	return false

func resolve_proximity(other: PartData) -> bool:
	if triggers.has("proximity"):
		return resolve_collision(other)
	return false