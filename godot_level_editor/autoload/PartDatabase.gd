extends Node

var part_catalog: Dictionary = {}
var part_name_map: Dictionary = {}
var part_category_map: Dictionary = {}

func _ready() -> void:
	_load_catalog()
	print("PartDatabase loaded: ", part_catalog.size(), " parts")

func _load_catalog() -> void:
	var file = FileAccess.open("res://data/part-name-catalog.json", FileAccess.READ)
	if not file:
		push_warning("part-name-catalog.json not found")
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
					var pt = item["part_type"]
					part_catalog[pt] = item
					part_name_map[pt] = item.get("name", "Part " + str(pt))
					part_category_map[pt] = item.get("category", "Unknown")

func get_part_data(part_type: int) -> Dictionary:
	return part_catalog.get(part_type, {})

func get_part_name(part_type: int) -> String:
	return part_name_map.get(part_type, "Unknown Part " + str(part_type))

func get_part_category(part_type: int) -> String:
	return part_category_map.get(part_type, "Unknown")

func get_categories() -> Array:
	var cats = {}
	for pt in part_catalog:
		var cat = part_catalog[pt].get("category", "Uncategorized")
		cats[cat] = true
	return cats.keys()
