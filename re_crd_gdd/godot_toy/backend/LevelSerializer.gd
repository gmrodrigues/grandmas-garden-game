extends RefCounted
class_name LevelSerializer

# Simplified YAML parsing tailored for the TIM2 level spec
# Supports level_info, environment, hints, parts, and solution sections.

static func save_level(path: String, level_data: Dictionary) -> void:
	var file = FileAccess.open(path, FileAccess.WRITE)
	if not file:
		push_error("Failed to open file for saving: " + path)
		return
		
	# Write level info
	file.store_line("level_info:")
	file.store_line("  title: \"" + str(level_data.get("title", "Untitled")) + "\"")
	file.store_line("  goal: \"" + str(level_data.get("goal", "")) + "\"")
	file.store_line("  bg_color: " + str(level_data.get("bg_color", 0)))
	file.store_line("")
	
	# Write environment
	file.store_line("environment:")
	file.store_line("  pressure: " + str(level_data.get("pressure", 67)))
	file.store_line("  gravity: " + str(level_data.get("gravity", 272)))
	file.store_line("  music_track: " + str(level_data.get("music_track", 1000)))
	file.store_line("")
	
	# Write parts
	file.store_line("parts:")
	var parts = level_data.get("parts", [])
	for p in parts:
		file.store_line("  - part_type: " + str(p.part_type))
		file.store_line("    pos_x: " + str(p.pos_x))
		file.store_line("    pos_y: " + str(p.pos_y))
		file.store_line("    flags_1: " + str(p.flags_1))
		file.store_line("    flags_2: " + str(p.flags_2))
		file.store_line("    flags_3: " + str(p.flags_3))
		file.store_line("    appearance: " + str(p.appearance))
	file.store_line("")
	
	file.close()

static func load_level(path: String) -> Dictionary:
	var file = FileAccess.open(path, FileAccess.READ)
	if not file:
		push_error("Failed to load file: " + path)
		return {}
		
	var level_data = {
		"title": "",
		"goal": "",
		"bg_color": 0,
		"pressure": 67,
		"gravity": 272,
		"music_track": 1000,
		"parts": []
	}
	
	var current_section = ""
	var current_part = null
	
	while not file.eof_reached():
		var line = file.get_line().strip_edges(false, true)
		if line.is_empty() or line.begins_with("#"):
			continue
			
		if line.ends_with(":"):
			current_section = line.substr(0, line.length() - 1).strip_edges()
			continue
			
		if current_section == "level_info":
			_parse_key_value(line, level_data)
		elif current_section == "environment":
			_parse_key_value(line, level_data)
		elif current_section == "parts":
			if line.begins_with("- part_type:"):
				if current_part != null:
					level_data["parts"].append(current_part)
				current_part = PartData.new(int(line.split(":")[1].strip_edges()), 0, 0)
			elif current_part != null:
				var parts = line.split(":")
				if parts.size() == 2:
					var key = parts[0].strip_edges()
					var val = int(parts[1].strip_edges())
					if key in current_part:
						current_part.set(key, val)
						
	if current_part != null:
		level_data["parts"].append(current_part)
		
	file.close()
	return level_data

static func _parse_key_value(line: String, data: Dictionary) -> void:
	var parts = line.split(":", true, 1)
	if parts.size() == 2:
		var key = parts[0].strip_edges()
		var val = parts[1].strip_edges()
		if val.begins_with("\"") and val.ends_with("\""):
			data[key] = val.substr(1, val.length() - 2)
		elif val.is_valid_int():
			data[key] = val.to_int()
