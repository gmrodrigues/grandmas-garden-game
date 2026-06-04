extends Node

# PartDatabase Autoload
# Responsible for loading part parameters and hitboxes from JSON.

var part_catalog: Dictionary = {}

func _ready() -> void:
	_load_catalog()

func _load_catalog() -> void:
	# Assume build/phase-9/part-name-catalog.json is located in res://data/part-name-catalog.json
	var file = FileAccess.open("res://data/part-name-catalog.json", FileAccess.READ)
	if not file:
		push_warning("part-name-catalog.json not found, parts database will be empty.")
		return
		
	var json_string = file.get_as_text()
	file.close()
	
	var json = JSON.new()
	var err = json.parse(json_string)
	if err == OK:
		var data = json.get_data()
		if data is Array:
			for item in data:
				if item is Dictionary and item.has("part_type"):
					part_catalog[item["part_type"]] = item
	else:
		push_error("Failed to parse part-name-catalog.json: " + json.get_error_message())

func get_part_data(part_type: int) -> Dictionary:
	return part_catalog.get(part_type, {})

func get_part_name(part_type: int) -> String:
	var data = get_part_data(part_type)
	return data.get("name", "Unknown Part " + str(part_type))
