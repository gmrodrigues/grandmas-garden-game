extends RefCounted
class_name LevelSerializer

static func save_yaml(path: String, level: Dictionary) -> void:
	var file = FileAccess.open(path, FileAccess.WRITE)
	if not file:
		push_error("Failed to save: " + path)
		return
	var parts: Array = level.get("parts", [])

	file.store_line("level_info:")
	file.store_line("  magic_number: " + level.get("magic", "EF AC 13 01"))
	var bg = level.get("bg_color", 0)
	if bg != 0:
		file.store_line("  background_color: " + str(bg))
	file.store_line("  title: " + level.get("title", "Untitled"))
	file.store_line("  goal_description: " + level.get("goal", ""))
	file.store_line("")

	file.store_line("environment:")
	file.store_line("  pressure: " + str(level.get("pressure", 67)))
	file.store_line("  gravity: " + str(level.get("gravity", 272)))
	file.store_line("  music_track: " + str(level.get("music_track", 1000)))
	file.store_line("")

	var hints: Array = level.get("hints", [])
	file.store_line("hints:")
	file.store_line("  active_hints_count: " + str(hints.size()))
	file.store_line("  entries:")
	for h in hints:
		file.store_line("  - hint_id: " + str(h.get("id", 0)))
		file.store_line("    x: " + str(h.get("x", 0)))
		file.store_line("    y: " + str(h.get("y", 0)))
		file.store_line("    icon_flip: 0")
		file.store_line("    text: " + str(h.get("text", "")))
	file.store_line("")

	var fixed: Array = []
	var moving: Array = []
	for p in parts:
		if p is Dictionary:
			var flags = p.get("flags", {})
			var flag_1_str = flags.get("flag_1", "0x0000")
			var flag_1_val = flag_1_str if flag_1_str is String else "0x0000"
			var is_moving = (flag_1_val.hex_to_int() & PartData.FLAG_MOVING) != 0 if flag_1_val.begins_with("0x") else false
			if is_moving:
				moving.append(p)
			else:
				fixed.append(p)
		elif p.has_method("get_part_type"):
			if p.is_moving:
				moving.append(p)
			else:
				fixed.append(p)

	file.store_line("parts:")
	file.store_line("  fixed_count: " + str(fixed.size()))
	file.store_line("  moving_count: " + str(moving.size()))

	_write_part_group(file, "fixed", fixed)
	_write_part_group(file, "moving", moving)
	file.store_line("")

	var solution_conditions: Array = level.get("solution_conditions", [])
	if not solution_conditions.is_empty():
		file.store_line("solution:")
		file.store_line("  conditions_count: " + str(solution_conditions.size()))
		file.store_line("  delay: " + str(level.get("solution_delay", 0)))
		file.store_line("  conditions:")
		for sc in solution_conditions:
			var sc_dict = sc if sc is Dictionary else sc.to_dict()
			file.store_line("  - part_index: " + str(sc_dict.get("part_index", -1)))
			file.store_line("    part_state_1: " + str(sc_dict.get("part_state_1", 0)))
			file.store_line("    part_state_2: " + str(sc_dict.get("part_state_2", 0)))
			file.store_line("    part_count: " + str(sc_dict.get("count", 0)))
			var rect = sc_dict.get("rect", [0, 0, 0, 0])
			file.store_line("    rect:")
			file.store_line("      x: " + str(rect[0] if rect is Array else rect.x))
			file.store_line("      y: " + str(rect[1] if rect is Array else rect.y))
			file.store_line("      width: " + str(rect[2] if rect is Array else rect.size.x))
			file.store_line("      height: " + str(rect[3] if rect is Array else rect.size.y))

	file.close()

static func _write_part_group(file: FileAccess, label: String, plist: Array):
	file.store_line("  " + label + ":")
	for p in plist:
		file.store_line("  - part_type: " + str(_get_part_field(p, "part_type")))
		file.store_line("    x: " + str(_get_part_field(p, "x")))
		file.store_line("    y: " + str(_get_part_field(p, "y")))
		file.store_line("    appearance: " + str(_get_part_field(p, "appearance")))
		file.store_line("    flags:")
		file.store_line("      flag_1: '0x" + _hex16(_get_part_field(p, "flags_1")) + "'")
		file.store_line("      flag_2: '0x" + _hex16(_get_part_field(p, "flags_2")) + "'")
		file.store_line("      flag_3: '0x" + _hex16(_get_part_field(p, "flags_3")) + "'")
		file.store_line("    dimensions:")
		file.store_line("      width_1: " + str(_get_part_field(p, "width_1")))
		file.store_line("      height_1: " + str(_get_part_field(p, "height_1")))
		file.store_line("      width_2: " + str(_get_part_field(p, "width_2")))
		file.store_line("      height_2: " + str(_get_part_field(p, "height_2")))
		file.store_line("    physics:")
		file.store_line("      behavior: " + str(_get_part_field(p, "behavior")))
		file.store_line("      belt_anchor:")
		file.store_line("        x: " + str(_get_part_field(p, "belt_anchor_x")))
		file.store_line("        y: " + str(_get_part_field(p, "belt_anchor_y")))
		file.store_line("      belt_line_distance: " + str(_get_part_field(p, "belt_line_distance")))
		file.store_line("      rope_1_anchor:")
		file.store_line("        x: " + str(_get_part_field(p, "rope_1_anchor_x")))
		file.store_line("        y: " + str(_get_part_field(p, "rope_1_anchor_y")))
		file.store_line("      rope_2_anchor:")
		file.store_line("        x: " + str(_get_part_field(p, "rope_2_anchor_x")))
		file.store_line("        y: " + str(_get_part_field(p, "rope_2_anchor_y")))
		file.store_line("      connected_1: " + str(_get_part_field(p, "connected_1")))
		file.store_line("      connected_2: " + str(_get_part_field(p, "connected_2")))
		file.store_line("      outlet_plugged_1: " + str(_get_part_field(p, "outlet_plugged_1")))
		file.store_line("      outlet_plugged_2: " + str(_get_part_field(p, "outlet_plugged_2")))

		var pt = _get_part_field(p, "part_type")
		var rs = _get_part_field(p, "rope_segment_length")
		if pt in [10, 76] and rs != 200:
			file.store_line("      rope_segment_length: " + str(rs))
		if pt == 87:
			file.store_line("      programmable:")
			file.store_line("        density: " + str(_get_part_field(p, "density")))
			file.store_line("        elasticity: " + str(_get_part_field(p, "elasticity")))
			file.store_line("        friction: " + str(_get_part_field(p, "friction_extra")))
			file.store_line("        gravity_buoyancy: " + str(_get_part_field(p, "gravity_buoyancy")))

static func _get_part_field(p, field: String):
	if p is Dictionary:
		if field in ["flags_1", "flags_2", "flags_3"]:
			var flags = p.get("flags", {})
			var fl = {"flag_1": "flags_1", "flag_2": "flags_2", "flag_3": "flags_3"}
			var fname = fl.get(field, field)
			var val = flags.get(field, flags.get(fname, 0))
			if val is String:
				if val.begins_with("0x"):
					return val.hex_to_int()
				return int(val)
			return val
		if field == "part_type":
			return p.get("part_type", 0)
		if field in ["x", "y", "appearance", "behavior"]:
			return p.get(field, 0)
		if field in ["width_1", "height_1", "width_2", "height_2"]:
			var dims = p.get("dimensions", {})
			return dims.get(field, 32)
		if field in ["belt_anchor_x", "belt_anchor_y"]:
			var phys = p.get("physics", {})
			var ba = phys.get("belt_anchor", {})
			if field == "belt_anchor_x": return ba.get("x", 0)
			else: return ba.get("y", 0)
		var phys = p.get("physics", {})
		return phys.get(field, 0 if field != "rope_segment_length" else 200)
	else:
		return p.get(field) if p.has_method("get") else 0

static func _hex16(val) -> String:
	if val is String:
		return val.right(4) if val.length() >= 4 else val
	return "%04x" % [int(val)]

static func _parse_key_value(line: String, data: Dictionary) -> void:
	var parts = line.split(":", true, 1)
	if parts.size() == 2:
		var key = parts[0].strip_edges()
		var val = parts[1].strip_edges()
		if val.begins_with("\"") and val.ends_with("\""):
			data[key] = val.substr(1, val.length() - 2)
		elif val.is_valid_int():
			data[key] = val.to_int()

static func _parse_flags(val) -> int:
	if val is int:
		return val
	if val is String:
		val = val.strip_edges()
		if val.begins_with("0x"):
			return val.hex_to_int()
		if val.is_valid_int():
			return val.to_int()
	return 0

static func load_yaml(path: String) -> Dictionary:
	var level_data = {
		"title": "", "goal": "", "bg_color": 0, "magic": "EF AC 13 01",
		"pressure": 67, "gravity": 272, "music_track": 1000,
		"hints": [], "parts": [], "solution_conditions": [], "solution_delay": 0,
	}

	var file = FileAccess.open(path, FileAccess.READ)
	if not file:
		push_error("Failed to load: " + path)
		return level_data

	var raw = file.get_as_text()
	file.close()

	var lines = raw.split("\n")
	var current_section = ""
	var current_part: Dictionary = {}
	var in_flags = false
	var in_dimensions = false
	var in_physics = false
	var in_belt_anchor = false
	var in_rope_1_anchor = false
	var in_rope_2_anchor = false
	var in_programmable = false
	var in_hint_entry = false
	var current_hint: Dictionary = {}
	var current_solution: Dictionary = {}

	for line_raw in lines:
		if line_raw.strip_edges().is_empty() or line_raw.strip_edges().begins_with("#"):
			continue

		var stripped = line_raw.lstrip(" ")
		var indent = line_raw.length() - stripped.length()
		var content = stripped.strip_edges(false, true)

		if indent == 0 and content.ends_with(":") and not content.contains("-"):
			current_section = content.trim_suffix(":")
			continue

		match current_section:
			"level_info", "environment":
				var parts = content.split(":", true, 1)
				if parts.size() == 2:
					var key = parts[0].strip_edges()
					var val = parts[1].strip_edges()
					if val.is_valid_int():
						level_data[key] = val.to_int()
					else:
						level_data[key] = val

			"parts":
				if content.begins_with("- part_type:"):
					if current_part:
						level_data["parts"].append(current_part)
					current_part = {"flags": {}, "dimensions": {}, "physics": {}}
					in_flags = false
					in_dimensions = false
					in_physics = false
					in_belt_anchor = false
					in_rope_1_anchor = false
					in_rope_2_anchor = false
					in_programmable = false
					var val = int(content.split(":")[1].strip_edges())
					current_part["part_type"] = val
				elif content == "flags:":
					in_flags = true; in_dimensions = false; in_physics = false; in_belt_anchor = false; in_rope_1_anchor = false; in_rope_2_anchor = false; in_programmable = false
				elif content == "dimensions:":
					in_dimensions = true; in_flags = false; in_physics = false; in_belt_anchor = false; in_programmable = false
				elif content == "physics:":
					in_physics = true; in_flags = false; in_dimensions = false; in_belt_anchor = false; in_programmable = false
				elif content == "belt_anchor:":
					in_belt_anchor = true; in_physics = false; in_rope_1_anchor = false; in_rope_2_anchor = false; in_programmable = false
				elif content == "rope_1_anchor:":
					in_rope_1_anchor = true; in_belt_anchor = false; in_rope_2_anchor = false
				elif content == "rope_2_anchor:":
					in_rope_2_anchor = true; in_rope_1_anchor = false
				elif content == "programmable:":
					in_programmable = true; in_physics = false; in_belt_anchor = false; in_rope_1_anchor = false; in_rope_2_anchor = false
				elif in_flags:
					var fp = content.split(":")
					if fp.size() == 2:
						current_part["flags"][fp[0].strip_edges()] = fp[1].strip_edges()
				elif in_dimensions:
					var fp = content.split(":")
					if fp.size() == 2:
						current_part["dimensions"][fp[0].strip_edges()] = int(fp[1].strip_edges())
				elif in_physics and not in_belt_anchor and not in_rope_1_anchor and not in_rope_2_anchor and not in_programmable:
					var fp = content.split(":")
					if fp.size() == 2:
						current_part["physics"][fp[0].strip_edges()] = int(fp[1].strip_edges())
				elif in_belt_anchor:
					var fp = content.split(":")
					if fp.size() == 2:
						current_part["physics"]["belt_anchor_" + fp[0].strip_edges()] = int(fp[1].strip_edges())
				elif in_rope_1_anchor:
					var fp = content.split(":")
					if fp.size() == 2:
						current_part["physics"]["rope_1_anchor_" + fp[0].strip_edges()] = int(fp[1].strip_edges())
				elif in_rope_2_anchor:
					var fp = content.split(":")
					if fp.size() == 2:
						current_part["physics"]["rope_2_anchor_" + fp[0].strip_edges()] = int(fp[1].strip_edges())
				elif in_programmable:
					var fp = content.split(":")
					if fp.size() == 2:
						current_part["physics"]["programmable_" + fp[0].strip_edges()] = int(fp[1].strip_edges())

			"hints":
				in_hint_entry = content.begins_with("- hint_id:")
				if in_hint_entry:
					if current_hint:
						level_data["hints"].append(current_hint)
					current_hint = {"id": 0, "x": 0, "y": 0, "text": ""}
					current_hint["id"] = int(content.split(":")[1].strip_edges())
				elif current_hint:
					var hp = content.split(":")
					if hp.size() == 2:
						var key = hp[0].strip_edges()
						var val = hp[1].strip_edges()
						if key == "x" or key == "y":
							current_hint[key] = int(val)
						else:
							current_hint["text"] = val.lstrip("\"").rstrip("\"")

			"solution":
				if content.begins_with("- part_index:"):
					if current_solution:
						level_data["solution_conditions"].append(current_solution)
					current_solution = {"part_index": -1, "part_state_1": 0, "part_state_2": 0, "count": 0, "rect": [0, 0, 0, 0]}
					current_solution["part_index"] = int(content.split(":")[1].strip_edges())
				elif content == "rect:":
					pass
				elif content.begins_with("part_state_"):
					var sp = content.split(":")
					if sp.size() == 2:
						var key = sp[0].strip_edges()
						var val = int(sp[1].strip_edges())
						if key.contains("state_1"): current_solution["part_state_1"] = val
						elif key.contains("state_2"): current_solution["part_state_2"] = val
				elif content.begins_with("part_count"):
					current_solution["count"] = int(content.split(":")[1].strip_edges())
				elif content.begins_with("delay"):
					level_data["solution_delay"] = int(content.split(":")[1].strip_edges())
				elif content.begins_with("x:") or content.begins_with("x:"):
					current_solution["rect"][0] = int(content.split(":")[1].strip_edges())
				elif content.begins_with("y:") or content.begins_with("y:"):
					current_solution["rect"][1] = int(content.split(":")[1].strip_edges())
				elif content.begins_with("width"):
					current_solution["rect"][2] = int(content.split(":")[1].strip_edges())
				elif content.begins_with("height"):
					current_solution["rect"][3] = int(content.split(":")[1].strip_edges())

	if current_part:
		level_data["parts"].append(current_part)
	if current_hint:
		level_data["hints"].append(current_hint)
	if current_solution:
		level_data["solution_conditions"].append(current_solution)

	for p in level_data["parts"]:
		if p is Dictionary and not p.has("x"):
			p["x"] = 0
		if p is Dictionary and not p.has("y"):
			p["y"] = 0

	return level_data
