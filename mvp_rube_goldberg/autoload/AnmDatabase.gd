extends Node

var anm_cache: Dictionary = {}
var part_to_anm: Dictionary = {}
var sprite_cache: Dictionary = {}
var palette_cache: Dictionary = {}

func _ready() -> void:
	_load_anm_catalog()
	print("AnmDatabase: ", anm_cache.size(), " cached, ", part_to_anm.size(), " part→ANM mappings")

func _load_anm_catalog() -> void:
	var cat_file = FileAccess.open("res://data/part-name-catalog.json", FileAccess.READ)
	var catalog_entries = []
	if cat_file:
		var json_string = cat_file.get_as_text()
		cat_file.close()
		var json = JSON.new()
		if json.parse(json_string) == OK:
			var data = json.get_data()
			if data is Array:
				catalog_entries = data
				for entry in data:
					var pt = entry.get("part_type")
					var anm = entry.get("anm_name", "")
					if pt != null and anm != "":
						part_to_anm[int(pt)] = anm

	var loaded_count = 0
	var generated_count = 0
	var dir = DirAccess.open("res://data/anm")
	if dir:
		dir.list_dir_begin()
		var file_name = dir.get_next()
		while file_name != "":
			if file_name.ends_with(".json"):
				load_anm(file_name.trim_suffix(".json"))
				loaded_count += 1
			file_name = dir.get_next()

	for entry in catalog_entries:
		var anm = entry.get("anm_name", "")
		if anm != "" and not anm_cache.has(anm):
			_generate_placeholder_anm(anm)
			generated_count += 1

	print("AnmDatabase: %d loaded from disk, %d generated from catalog (%d total)" % [loaded_count, generated_count, anm_cache.size()])

func load_anm(anm_name: String) -> Dictionary:
	if anm_name in anm_cache:
		return anm_cache[anm_name]
	var name = anm_name if anm_name.ends_with(".json") else anm_name + ".json"
	var file = FileAccess.open("res://data/anm/" + name, FileAccess.READ)
	if not file:
		return {}
	var json_string = file.get_as_text()
	file.close()
	var json = JSON.new()
	if json.parse(json_string) == OK:
		anm_cache[anm_name] = json.get_data()
		return anm_cache[anm_name]
	push_warning("Failed to parse ANM: " + name)
	return {}

func _generate_placeholder_anm(anm_name: String) -> Dictionary:
	var placeholder = {
		"version": 1001,
		"width": 32,
		"height": 32,
		"section_sizes": {"a": 0, "b": 1, "c": 1, "d": 14},
		"section_a": [],
		"section_b": [{"x": 0, "y": 0, "width": 32, "height": 32, "bytecode_offset": 0}],
		"section_c": [{"first_frame_id": 0, "state_id": 1}],
		"section_d": [
			{"offset": 0, "cmd": 2, "name": "DRAW_BMP", "resource_id": 0, "sub_image": 0, "x": 0, "y": 0, "flags": 0},
			{"offset": 12, "cmd": 0, "name": "END_FRAME"},
			{"offset": 14, "cmd": 1, "name": "END_ANM"}
		]
	}
	anm_cache[anm_name] = placeholder
	return placeholder

func get_anm_for_part(part_type: int) -> String:
	return part_to_anm.get(part_type, "")

func get_default_state_id(anm_name: String) -> int:
	var anm_data = load_anm(anm_name)
	if anm_data.is_empty():
		return 1
	var section_c = anm_data.get("section_c", [])
	if section_c.is_empty():
		return 1
	var min_frame_id = 999999
	var min_state = 1
	for entry in section_c:
		var fid = entry.get("first_frame_id", 0)
		if fid < min_frame_id:
			min_frame_id = fid
			min_state = entry.get("state_id", 1)
	return min_state

func get_first_frame_for_state(anm_data: Dictionary, state_id: int) -> int:
	for entry in anm_data.get("section_c", []):
		if entry.get("state_id") == state_id:
			return entry.get("first_frame_id", 0)
	return 0

func get_frame_meta(anm_data: Dictionary, frame_idx: int) -> Dictionary:
	var frames = anm_data.get("section_b", [])
	if frame_idx >= 0 and frame_idx < frames.size():
		return frames[frame_idx]
	return {}

func get_bytecodes_for_frame(anm_data: Dictionary, bytecode_offset: int) -> Array:
	var bytecodes = anm_data.get("section_d", [])
	var start_idx = -1
	for i in range(bytecodes.size()):
		if bytecodes[i].get("offset") == bytecode_offset:
			start_idx = i
			break
	if start_idx < 0:
		return []
	var result: Array = []
	for i in range(start_idx, bytecodes.size()):
		var entry = bytecodes[i]
		result.append(entry)
		var cmd = entry.get("cmd", -1)
		if cmd == 0 or cmd == 1:
			break
	return result

func get_state_count(anm_data: Dictionary) -> int:
	return anm_data.get("section_c", []).size()

func get_frame_count(anm_data: Dictionary) -> int:
	return anm_data.get("section_b", []).size()
