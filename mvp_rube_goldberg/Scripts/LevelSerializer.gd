class_name LevelSerializer
extends RefCounted

const _LevelLoader = preload("res://Scripts/LevelLoader.gd")

signal load_complete(data: Dictionary)
signal save_complete(path: String)
signal load_error(msg: String)

var _last_loaded_path: String = ""

func load_yaml(path: String) -> Dictionary:
	var data = _LevelLoader.load_file(path)
	if data.is_empty():
		load_error.emit("Failed to load level from " + path)
		return {}
	_last_loaded_path = path
	_normalize_level_data(data)
	load_complete.emit(data)
	return data

func load_json(path: String) -> Dictionary:
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		load_error.emit("Failed to open JSON: " + str(FileAccess.get_open_error()))
		return {}
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed == null or typeof(parsed) != TYPE_DICTIONARY:
		load_error.emit("Failed to parse JSON from " + path)
		return {}
	_last_loaded_path = path
	_normalize_level_data(parsed)
	load_complete.emit(parsed)
	return parsed

func save_yaml(path: String, data: Dictionary) -> bool:
	var text = _dict_to_yaml(data, 0)
	var f = FileAccess.open(path, FileAccess.WRITE)
	if f == null:
		load_error.emit("Failed to save YAML: " + str(FileAccess.get_open_error()))
		return false
	f.store_string(text)
	f.close()
	_last_loaded_path = path
	save_complete.emit(path)
	return true

func save_json(path: String, data: Dictionary) -> bool:
	var text = JSON.stringify(data, "\t")
	var f = FileAccess.open(path, FileAccess.WRITE)
	if f == null:
		load_error.emit("Failed to save JSON: " + str(FileAccess.get_open_error()))
		return false
	f.store_string(text)
	f.close()
	_last_loaded_path = path
	save_complete.emit(path)
	return true

func new_level() -> Dictionary:
	return {
		"meta": {
			"title": "Untitled Level",
			"objective": "",
			"description": "",
			"hints": [],
			"music": "default",
			"author": "",
			"version": 1
		},
		"physics": {
			"gravity_x": 0,
			"gravity_y": 0x1400,
			"air_pressure": 0
		},
		"viewport": {
			"width": 640,
			"height": 480
		},
		"parts": [],
		"connections": [],
		"chain_script": [],
		"solution": {
			"type": "AABB_overlap",
			"target_part": "",
			"zone": {"x": 0, "y": 0, "width": 640, "height": 480}
		},
		"inventory": []
	}

func editor_data_to_simulation(editor_data: Dictionary) -> Dictionary:
	var sim_data = editor_data.duplicate(true)
	var parts = sim_data.get("parts", [])
	for i in range(parts.size()):
		var p = parts[i]
		if p.has("pos_x") and not p.has("x"):
			p["x"] = p["pos_x"]
		if p.has("pos_y") and not p.has("y"):
			p["y"] = p["pos_y"]
		if p.has("width") and not p.has("width_1"):
			p["width_1"] = p["width"]
		if p.has("height") and not p.has("height_1"):
			p["height_1"] = p["height"]
		if p.has("appearance"):
			var flags = p["appearance"]
			if flags & 0x1000:
				p["is_moving"] = true
	return sim_data

func _normalize_level_data(data: Dictionary) -> void:
	var meta = data.get("meta", {})
	if meta.is_empty():
		data["meta"] = {
			"title": data.get("title", "Untitled"),
			"objective": data.get("objective", ""),
			"description": data.get("description", ""),
			"hints": data.get("hints", []),
			"music": data.get("music", "default")
		}
	var physics = data.get("physics", {})
	if physics.is_empty():
		data["physics"] = {
			"gravity_x": 0,
			"gravity_y": 0x1400,
			"air_pressure": 0
		}
	var viewport = data.get("viewport", {})
	if viewport.is_empty():
		data["viewport"] = {"width": 640, "height": 480}
	if not data.has("connections"):
		data["connections"] = []
	if not data.has("inventory"):
		data["inventory"] = []

func _dict_to_yaml(d: Dictionary, indent: int) -> String:
	var result = ""
	var indent_str = " ".repeat(indent * 2)
	for key in d.keys():
		var val = d[key]
		if val == null:
			result += indent_str + key + ": null\n"
		elif val is bool:
			result += indent_str + key + ": " + ("true" if val else "false") + "\n"
		elif val is int:
			if val < 0:
				result += indent_str + key + ": " + str(val) + "\n"
			else:
				result += indent_str + key + ": " + str(val) + "\n"
		elif val is float:
			result += indent_str + key + ": " + str(val) + "\n"
		elif val is String:
			if _needs_quoting(val):
				result += indent_str + key + ": \"" + val + "\"\n"
			else:
				result += indent_str + key + ": " + val + "\n"
		elif val is Array:
			result += indent_str + key + ":\n"
			for item in val:
				if item is Dictionary:
					var sub = _dict_to_yaml(item, indent + 1)
					for line in sub.split("\n"):
						result += indent_str + "  - " + line + "\n"
				elif item is String:
					result += indent_str + "  - \"" + item + "\"\n"
				else:
					result += indent_str + "  - " + str(item) + "\n"
		elif val is Dictionary:
			result += indent_str + key + ":\n"
			result += _dict_to_yaml(val, indent + 1)
	return result

func _needs_quoting(s: String) -> bool:
	if s.is_empty():
		return true
	if s.begins_with(" ") or s.ends_with(" "):
		return true
	if s.contains(":") or s.contains("#") or s.contains("\""):
		return true
	var lower = s.to_lower()
	if lower == "true" or lower == "false" or lower == "null" or lower == "yes" or lower == "no":
		return true
	return false

func get_last_loaded_path() -> String:
	return _last_loaded_path

func probe_format(path: String) -> String:
	if path.ends_with(".yaml") or path.ends_with(".yml"):
		return "yaml"
	if path.ends_with(".json"):
		return "json"
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		return "unknown"
	var first_line = f.get_line()
	f.close()
	if first_line.strip_edges().begins_with("meta:") or first_line.strip_edges().begins_with("parts:"):
		return "yaml"
	return "json"