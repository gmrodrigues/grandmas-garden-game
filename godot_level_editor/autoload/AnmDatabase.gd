extends Node

var anm_cache: Dictionary = {}
var part_to_anm: Dictionary = {}
var sprite_cache: Dictionary = {}
var palette_cache: Dictionary = {}

func _ready() -> void:
	_load_anm_catalog()
	print("AnmDatabase ready: ", anm_cache.size(), " ANM files cached, ", part_to_anm.size(), " part mappings")

func _load_anm_catalog() -> void:
	var dir = DirAccess.open("res://data/anm")
	if not dir:
		push_warning("res://data/anm/ not found")
		return
	dir.list_dir_begin()
	var file_name = dir.get_next()
	while file_name != "":
		if file_name.ends_with(".json"):
			load_anm(file_name.trim_suffix(".json"))
		file_name = dir.get_next()

	var cat_file = FileAccess.open("res://data/part-name-catalog.json", FileAccess.READ)
	if cat_file:
		var json_string = cat_file.get_as_text()
		cat_file.close()
		var json = JSON.new()
		if json.parse(json_string) == OK:
			var data = json.get_data()
			if data is Array:
				for entry in data:
					var pt = entry.get("part_type")
					var anm = entry.get("anm_name", "")
					if pt != null and anm != "":
						part_to_anm[int(pt)] = anm

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
