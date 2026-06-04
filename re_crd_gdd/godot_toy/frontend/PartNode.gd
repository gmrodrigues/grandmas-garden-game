extends Area2D
class_name PartNode

@onready var sprite: Sprite2D = $Sprite2D
var part_type: int = -1
var part_data: Dictionary = {}
var current_frame_state: int = 1

func setup(_part_type: int) -> void:
	part_type = _part_type
	# Fetch data from singleton
	if PartDatabase.part_catalog.has(part_type):
		part_data = PartDatabase.part_catalog[part_type]
		_update_visuals()

func _update_visuals() -> void:
	# Use part_data to load the correct Sprite/Texture based on current_frame_state
	# The Z-Index logic from the GDD
	if part_type >= 150:
		z_index = -1 # Scenery
	elif (part_data.get("flags_1", 0) & 0x1000) != 0:
		z_index = 1 # Active/Moving parts
	else:
		z_index = 0 # Fixed structures

func _on_input_event(viewport: Node, event: InputEvent, shape_idx: int) -> void:
	if event is InputEventMouseButton and event.pressed and event.button_index == MOUSE_BUTTON_LEFT:
		# If the editor is in MODE_SELECT, select this part
		var editor = get_tree().get_first_node_in_group("editor_controller")
		if editor and editor.current_mode == 0: # MODE_SELECT
			editor.selected_part_node = self
			print("Selected part: ", part_type)
