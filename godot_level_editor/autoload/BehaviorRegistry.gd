extends Node

var solve_data: Dictionary = {}
var behaviors: Dictionary = {}
var physics_props: Dictionary = {}
var part_sounds: Dictionary = {}
var godot_behaviors: Dictionary = {}
var category_rules: Dictionary = {}
var orphan_states: Dictionary = {}
var categories_data: Dictionary = {}
var part_to_category: Dictionary = {}

func _ready() -> void:
	_load_json_files()
	_build_category_rules()
	_compile_behaviors()
	_build_physics_props()
	_load_part_sounds()
	print("BehaviorRegistry: ", behaviors.size(), " behaviors, ", physics_props.size(), " physics props")

func _load_json_files() -> void:
	var load_json = func(path: String) -> Dictionary:
		var file = FileAccess.open(path, FileAccess.READ)
		if not file:
			return {}
		var text = file.get_as_text()
		file.close()
		var json = JSON.new()
		if json.parse(text) == OK:
			var data = json.get_data()
			if data is Dictionary:
				return data
			if data is Array:
				var result: Dictionary = {}
				for item in data:
					if item is Dictionary and item.has("part_type"):
						result[item["part_type"]] = item
				return result
		return {}

	var load_array = func(path: String) -> Array:
		var file = FileAccess.open(path, FileAccess.READ)
		if not file:
			return []
		var text = file.get_as_text()
		file.close()
		var json = JSON.new()
		if json.parse(text) == OK:
			if json.get_data() is Array:
				return json.get_data()
		return []

	var load_string_keyed = func(path: String) -> Dictionary:
		var file = FileAccess.open(path, FileAccess.READ)
		if not file:
			return {}
		var text = file.get_as_text()
		file.close()
		var json = JSON.new()
		if json.parse(text) == OK:
			var data = json.get_data()
			if data is Dictionary:
				return data
		return {}

	solve_data = load_string_keyed.call("res://data/solve-decoded.json")
	godot_behaviors = load_string_keyed.call("res://data/behaviors.json")
	categories_data = load_string_keyed.call("res://data/categories.json")

	var orph_file = FileAccess.open("res://data/state-machine-report.json", FileAccess.READ)
	if orph_file:
		var orph_json = JSON.new()
		if orph_json.parse(orph_file.get_as_text()) == OK:
			var orph_data = orph_json.get_data()
			if orph_data is Dictionary:
				orphan_states = orph_data.get("orphan_anm_states", {}).get("by_part", {})
		orph_file.close()

	var part_assets_raw = load_array.call("res://data/part-assets.json")
	for item in part_assets_raw:
		if item is Dictionary and item.has("part_type"):
			var pt = item["part_type"]
			part_to_category[pt] = item.get("category", "Unknown")

func _build_category_rules() -> void:
	category_rules = {
		"Balls": {
			"triggers": ["collision", "trap"],
			"rules": {"collision": {"response": "state_advance", "activate_others": true, "sound_on_hit": true}},
			"destructible": false, "spawns": null
		},
		"Balloons / Airships": {
			"triggers": ["collision", "proximity"],
			"rules": {
				"proximity": {"response": "state_transition", "trigger_if_other_in_category": ["Explosives", "Light / Flame Sources"]},
				"collision": {"response": "state_transition", "trigger_if_other_in_category": ["Cutting / Popping"]}
			},
			"destructible": true, "spawns": null
		},
		"Rotating Power Sources": {
			"triggers": ["collision", "electrical", "rope"],
			"rules": {"electrical": {"response": "toggle_on_off"}, "collision": {"response": "activate"}, "rope": {"response": "transmit_force"}},
			"destructible": false, "spawns": null
		},
		"Characters": {
			"triggers": ["collision", "proximity"],
			"rules": {"collision": {"response": "eat_or_activate"}, "proximity": {"response": "sleep_or_flee"}},
			"destructible": false, "spawns": null
		},
		"Explosives / Projectiles": {
			"triggers": ["collision", "proximity", "timer"],
			"rules": {"collision": {"response": "explode_chain"}, "proximity": {"response": "explode_if_fire"}, "timer": {"response": "launch_or_explode"}},
			"destructible": true, "spawns": "projectile"
		},
		"Electrical": {
			"triggers": ["electrical", "collision"],
			"rules": {"electrical": {"response": "power_on_off"}, "collision": {"response": "toggle"}},
			"destructible": false, "spawns": null
		},
		"Lasers / Optics": {
			"triggers": ["electrical", "proximity", "collision"],
			"rules": {"electrical": {"response": "activate"}, "proximity": {"response": "detect_beam"}, "collision": {"response": "bounce_mirror"}},
			"destructible": false, "spawns": "laser_beam"
		},
		"Light / Flame Sources": {
			"triggers": ["proximity", "electrical"],
			"rules": {"proximity": {"response": "ignite", "ignites_categories": ["Balloons / Airships", "Explosives / Projectiles"]}, "electrical": {"response": "toggle_on_off"}},
			"destructible": false, "spawns": "fire"
		},
		"Pipe Systems": {
			"triggers": ["collision", "electrical"],
			"rules": {"collision": {"response": "transport"}, "electrical": {"response": "activate"}},
			"destructible": false, "spawns": null
		},
		"Springs / Pneumatics": {
			"triggers": ["collision", "electrical"],
			"rules": {"collision": {"response": "spring_or_pump"}, "electrical": {"response": "activate"}},
			"destructible": false, "spawns": null
		},
		"Containers": {
			"triggers": ["collision"],
			"rules": {"collision": {"response": "fill_or_collect"}},
			"destructible": false, "spawns": null
		},
		"Cutting / Popping": {
			"triggers": ["collision"],
			"rules": {"collision": {"response": "pop_on_contact"}},
			"destructible": false, "spawns": null
		},
		"Pool Table": {
			"triggers": ["collision"],
			"rules": {"collision": {"response": "pocket_ball"}},
			"destructible": false, "spawns": null
		},
		"Special Mechanics": {
			"triggers": ["collision", "electrical", "proximity"],
			"rules": {"collision": {"response": "custom_solve"}, "electrical": {"response": "custom_solve"}, "proximity": {"response": "custom_solve"}},
			"destructible": false, "spawns": "custom"
		},
		"Walls / Floors": {"triggers": [], "rules": {}, "destructible": true, "spawns": null},
		"Inclines": {"triggers": [], "rules": {}, "destructible": false, "spawns": null},
		"Scenery": {"triggers": [], "rules": {}, "destructible": true, "spawns": null},
		"Ropes / Belts / Pulleys": {"triggers": [], "rules": {}, "destructible": false, "spawns": null},
		"Created / Phantom": {"triggers": [], "rules": {}, "destructible": false, "spawns": null},
	}

func _compile_behaviors() -> void:
	for pt_str in solve_data:
		var pt = int(pt_str)
		var solve_entry = solve_data[pt_str]
		var cat_name = solve_entry.get("category", part_to_category.get(pt, "Unknown"))
		var cat_rules = category_rules.get(cat_name, {})
		behaviors[pt] = {
			"part_type": pt,
			"category": cat_name,
			"name": solve_entry.get("solve_name", "Part" + str(pt)),
			"triggers": cat_rules.get("triggers", []).duplicate(),
			"rules": cat_rules.get("rules", {}).duplicate(),
			"destructible": cat_rules.get("destructible", false),
			"spawns": cat_rules.get("spawns"),
			"solve_states": solve_entry.get("states", []),
			"explosive": _has_explosive(solve_entry),
		}

func _has_explosive(solve_entry: Dictionary) -> bool:
	for state in solve_entry.get("states", []):
		if state.get("explosive", false):
			return true
	return false

func _build_physics_props() -> void:
	var load_props = func() -> Array:
		var file = FileAccess.open("res://data/part-properties.json", FileAccess.READ)
		if not file:
			return []
		var text = file.get_as_text()
		file.close()
		var json = JSON.new()
		if json.parse(text) == OK:
			if json.get_data() is Array:
				return json.get_data()
		return []

	var defaults = {"mass": 2832, "cor_q8": 128, "friction_q8": 0, "collision_radius": 0, "collision_w": 0, "collision_h": 0}
	for entry in load_props.call():
		if not entry is Dictionary or not entry.has("part_type"):
			continue
		var pt = entry["part_type"]
		var fields: Dictionary = {}
		for f in entry.get("fields", []):
			if f is Dictionary:
				fields[f.get("name", "")] = f.get("raw", 0)
		var fmt = entry.get("format_id", "")
		var mass = defaults.mass
		var cor = defaults.cor_q8
		var friction = defaults.friction_q8
		var radius = defaults.collision_radius
		var cw = defaults.collision_w
		var ch = defaults.collision_h

		if fmt == "par_80b_40w":
			mass = fields.get("mass", mass)
			cor = fields.get("cor_q8", cor)
			friction = fields.get("damping", friction)
			radius = fields.get("radius", radius)
			cw = fields.get("sprite_w", cw)
			ch = fields.get("sprite_h", ch)
		elif fmt == "par_56b_28w":
			mass = fields.get("mass", mass)
			cor = fields.get("property_q8", cor)
			friction = fields.get("friction_q8", friction)
			cw = fields.get("collision_w", cw)
			ch = fields.get("collision_h", ch)
			radius = 0
		else:
			mass = fields.get("unk_2", mass)
			cor = fields.get("property_q8", cor)
			friction = fields.get("damping", fields.get("field_18", friction))
			cw = fields.get("dim_w1", cw)
			ch = fields.get("dim_h1", ch)
			radius = 0

		physics_props[pt] = {"mass": mass, "cor_q8": cor, "friction_q8": friction, "collision_radius": radius, "collision_w": cw, "collision_h": ch}

func _load_part_sounds() -> void:
	var load_array = func(path: String) -> Array:
		var file = FileAccess.open(path, FileAccess.READ)
		if not file:
			return []
		var text = file.get_as_text()
		file.close()
		var json = JSON.new()
		if json.parse(text) == OK:
			if json.get_data() is Array:
				return json.get_data()
		return []

	for item in load_array.call("res://data/part-assets.json"):
		if item is Dictionary and item.has("part_type"):
			var pt = item["part_type"]
			var sounds: Array = []
			for state in item.get("states", []):
				var sid = state.get("sfx_sound_id", 0)
				if sid > 0:
					sounds.append(sid)
			if not sounds.is_empty():
				part_sounds[pt] = sounds

func get_state_limits(part_type: int) -> Dictionary:
	var gb_str = str(part_type)
	if godot_behaviors.has(gb_str):
		return {
			"limit_lower": godot_behaviors[gb_str].get("limit_lower", 0),
			"limit_upper": godot_behaviors[gb_str].get("limit_upper", 8),
			"limit_reset": godot_behaviors[gb_str].get("limit_reset", 0),
			"limit_sub_a": godot_behaviors[gb_str].get("limit_sub_a", 5),
			"limit_sub_b": godot_behaviors[gb_str].get("limit_sub_b", 5),
		}
	return {"limit_lower": 0, "limit_upper": 8, "limit_reset": 0, "limit_sub_a": 5, "limit_sub_b": 5}

func get_solve_transitions(part_type: int) -> Array:
	var pt_str = str(part_type)
	if solve_data.has(pt_str):
		return solve_data[pt_str].get("states", [])
	return []

func get_behavior(part_type: int) -> Dictionary:
	return behaviors.get(part_type, {})

func get_category(part_type: int) -> String:
	if behaviors.has(part_type):
		return behaviors[part_type].get("category", "Unknown")
	return part_to_category.get(part_type, "Unknown")

func get_physics_props(part_type: int) -> Dictionary:
	return physics_props.get(part_type, {"mass": 2832, "cor_q8": 128, "friction_q8": 0, "collision_radius": 0, "collision_w": 0, "collision_h": 0})

func get_sounds_for_part(part_type: int) -> Array:
	return part_sounds.get(part_type, [])

func validate_orphan_states(part_type: int) -> Array:
	var pt_str = str(part_type)
	if orphan_states.has(pt_str):
		return orphan_states[pt_str]
	return []

func validate_trigger_chains(part_type: int) -> Array:
	var broken: Array = []
	var transitions = get_solve_transitions(part_type)
	if transitions.is_empty():
		return broken
	for state in transitions:
		var triggers = state.get("triggers", [])
		for trigger in triggers:
			var other = trigger.get("other", -1)
			if other >= 0 and other > 104:
				broken.append("Part " + str(part_type) + " trigger has unknown other state " + str(other))
	return broken
