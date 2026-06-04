extends Control
class_name EditorController

enum ToolMode {
	MODE_SELECT,
	MODE_PLACE,
	MODE_CONNECT,
	MODE_PREVIEW
}

var current_mode: ToolMode = ToolMode.MODE_SELECT
var selected_part_type: int = -1
var selected_part_node: Node2D = null

@onready var game_space = $GameSpace/LevelViewport/PartContainer
@onready var physics_solver = null
@onready var is_dirty: bool = false

func _ready() -> void:
	pass

func _unhandled_input(event: InputEvent) -> void:
	if event is InputEventKey and event.pressed:
		match event.keycode:
			KEY_P:
				_set_mode(ToolMode.MODE_PLACE)
			KEY_S:
				_set_mode(ToolMode.MODE_SELECT)
			KEY_C:
				_set_mode(ToolMode.MODE_CONNECT)
			KEY_SPACE:
				_toggle_preview()
				
	if current_mode == ToolMode.MODE_PLACE:
		if event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT and event.pressed:
			_place_part(get_global_mouse_position())
			get_viewport().set_input_as_handled()
	elif current_mode == ToolMode.MODE_CONNECT:
		# Draw logic for connections
		pass
	elif current_mode == ToolMode.MODE_SELECT:
		# Selection and handles logic
		pass

func _set_mode(mode: ToolMode) -> void:
	current_mode = mode
	print("Switched to mode: ", mode)

func _place_part(pos: Vector2) -> void:
	if selected_part_type < 0:
		return
		
	# Snap to 16x16 grid
	var snapped_x = floor(pos.x / 16) * 16
	var snapped_y = floor(pos.y / 16) * 16
	
	# Instantiate part (Assuming PartNode scene exists)
	var part_scene = preload("res://frontend/PartNode.tscn")
	var new_part = part_scene.instantiate()
	new_part.position = Vector2(snapped_x, snapped_y)
	new_part.setup(selected_part_type)
	game_space.add_child(new_part)
	is_dirty = true
	print("Placed part ", selected_part_type, " at ", snapped_x, ", ", snapped_y)

func _toggle_preview() -> void:
	if current_mode == ToolMode.MODE_PREVIEW:
		# Stop simulation, restore state
		_set_mode(ToolMode.MODE_SELECT)
		print("Simulation Stopped. Restoring state.")
		# Load from temp_state.yaml
	else:
		# Save state, start simulation
		_set_mode(ToolMode.MODE_PREVIEW)
		print("Simulation Started. Saving state.")
		# Save to temp_state.yaml
		
func serialize_level() -> Dictionary:
	# Convert current scene tree to Dictionary for LevelSerializer
	return {}
