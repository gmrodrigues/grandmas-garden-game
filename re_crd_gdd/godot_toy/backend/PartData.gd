extends RefCounted
class_name PartData

# 48-byte struct representation from spec
var part_type: int = 0
var flags_1: int = 0
var flags_2: int = 0
var flags_3: int = 0
var appearance: int = 0

var width_1: int = 32
var height_1: int = 32
var pos_x: int = 0
var pos_y: int = 0

var behavior: int = 0

# Physics state
var velocity_x: int = 0
var velocity_y: int = 0

# State machine
var current_state: int = 1
var state_counter: int = 0
var sub_counter: int = 0

func _init(_type: int, _x: int, _y: int):
	part_type = _type
	pos_x = _x
	pos_y = _y
