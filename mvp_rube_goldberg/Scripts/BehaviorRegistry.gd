class_name BehaviorRegistry
extends RefCounted

const _Part = preload("res://Scripts/Part.gd")

var _catalog: Array = []
var _type_to_entry: Dictionary = {}
var _archetype_cache: Dictionary = {}
var _state_limits_cache: Dictionary = {}
var _physics_props_cache: Dictionary = {}
var _category_cache: Dictionary = {}

var gravity_table: Array = []
var pressure_table: Array = []

func _init():
	_load_catalog()
	_build_caches()

func _load_catalog() -> void:
	var path = "res://data/part-name-catalog.json"
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		push_error("BehaviorRegistry: Cannot load " + path)
		return
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed is Array:
		_catalog = parsed
		for entry in _catalog:
			var pt = entry.get("part_type", -1)
			if pt >= 0:
				_type_to_entry[pt] = entry

func _build_caches() -> void:
	for entry in _catalog:
		var pt = entry.get("part_type", -1)
		if pt < 0:
			continue
		_category_cache[pt] = entry.get("category", "Unknown")
		_archetype_cache[pt] = _resolve_archetype(entry)
		var anm_states = entry.get("anm_states", [1])
		_state_limits_cache[pt] = {
			"upper": anm_states.size(),
			"lower": 0,
			"reset": 0,
			"sub_a": 5,
			"sub_b": 5,
		}
		_physics_props_cache[pt] = _resolve_physics_props(entry)

	gravity_table = [
		0x1C00, 0x1A00, 0x1800, 0x1600, 0x1400, 0x1200, 0x1000
	]
	pressure_table = [256, 384, 512, 640, 768, 1024]

func _resolve_archetype(entry: Dictionary) -> int:
	var solve_name = entry.get("solve_name", "").to_lower()
	var category = entry.get("category", "")
	if "ball" in solve_name or "bowling" in solve_name or "marble" in solve_name:
		return _Part.ARCH_KINETIC
	if category.begins_with("Walls") or category.begins_with("Scenery") or category.begins_with("Inclines"):
		return _Part.ARCH_STATIC
	if category == "Balls" or category == "Balloons / Airships":
		return _Part.ARCH_KINETIC
	if category == "Characters":
		return _Part.ARCH_KINETIC
	if category == "Rotating Power Sources":
		return _Part.ARCH_DRIVER
	if category == "Ropes / Belts / Pulleys":
		return _Part.ARCH_LINK
	if category == "Electrical" or category == "Light / Flame Sources":
		return _Part.ARCH_EMITTER
	if category == "Explosives / Projectiles" or category == "Springs / Pneumatics" or category == "Containers":
		return _Part.ARCH_CONSUMER
	if category == "Special Mechanics":
		return _Part.ARCH_KINETIC
	return _Part.ARCH_STATIC

func _resolve_physics_props(entry: Dictionary) -> Dictionary:
	var category = entry.get("category", "")
	var solve_name = entry.get("solve_name", "").to_lower()
	var base_mass = 2832
	var base_cor = 128
	var base_damping = 200
	var is_moving = false
	var triggers = []
	var destructible = false
	var gravity_cat = 7
	var buoyancy = 0

	if "ball" in solve_name or "bowling" in solve_name:
		base_mass = 4096
		base_cor = 64
		is_moving = true
		gravity_cat = 1
	elif "balloon" in solve_name:
		base_mass = 512
		is_moving = true
		gravity_cat = 151
		buoyancy = -0x600
	elif "wall" in solve_name or "brick" in solve_name:
		base_mass = 8192
		base_cor = 32
		destructible = true
	elif "rope" in solve_name:
		gravity_cat = 121
	elif "fan" in solve_name:
		gravity_cat = 6
		is_moving = true
	elif "spring" in solve_name or "bellows" in solve_name:
		base_mass = 1024
		is_moving = true
		gravity_cat = 4
	elif "generator" in solve_name or "motor" in solve_name:
		is_moving = true
		gravity_cat = 3
	elif "laser" in solve_name:
		is_moving = false
		gravity_cat = 0
	elif "explosive" in solve_name or "dynamite" in solve_name or "nitro" in solve_name:
		destructible = true
		base_cor = 0
		gravity_cat = 2
		is_moving = false
	elif "cannon" in solve_name or "missile" in solve_name or "rocket" in solve_name:
		is_moving = true
		gravity_cat = 1
		triggers.append("proximity")

	if category == "Electrical" or category == "Light / Flame Sources":
		is_moving = false

	return {
		"mass": base_mass,
		"cor_q8": base_cor,
		"damping": base_damping,
		"is_moving": is_moving,
		"triggers": triggers,
		"destructible": destructible,
		"gravity_category": gravity_cat,
		"gravity_buoyancy": buoyancy,
	}

func get_archetype(part_type: int) -> int:
	return _archetype_cache.get(part_type, _Part.ARCH_STATIC)

func get_state_limits(part_type: int) -> Dictionary:
	return _state_limits_cache.get(part_type, {"upper": 8, "lower": 0, "reset": 0, "sub_a": 5, "sub_b": 5})

func get_physics_props(part_type: int) -> Dictionary:
	return _physics_props_cache.get(part_type, {"mass": 2832, "cor_q8": 128, "damping": 200, "is_moving": false, "triggers": [], "destructible": false, "gravity_category": 7, "gravity_buoyancy": 0})

func get_category(part_type: int) -> String:
	return _category_cache.get(part_type, "Unknown")

func get_entry(part_type: int) -> Dictionary:
	return _type_to_entry.get(part_type, {})

func get_anm_name(part_type: int) -> String:
	var entry = _type_to_entry.get(part_type, {})
	return entry.get("anm_name", "")

func get_all_categories() -> Array:
	var cats = {}
	for pt in _category_cache:
		cats[_category_cache[pt]] = true
	return cats.keys()

func get_parts_in_category(category: String) -> Array:
	var result = []
	for entry in _catalog:
		if entry.get("category") == category:
			result.append(entry)
	return result

func get_gravity_for_category(cat: int) -> int:
	if cat >= 0 and cat < gravity_table.size():
		return gravity_table[cat]
	return 0x1400

func get_pressure_max_vel(pressure_level: int) -> int:
	if pressure_level >= 0 and pressure_level < pressure_table.size():
		return pressure_table[pressure_level]
	return 512

func is_ropeable_category(category: String) -> bool:
	var ropeable = ["Special Mechanics", "Springs / Pneumatics", "Containers",
		"Balloons / Airships", "Characters", "Electrical", "Explosives / Projectiles",
		"Ropes / Belts / Pulleys"]
	return ropeable.has(category)

func get_all_part_types() -> Array:
	return _type_to_entry.keys()

func get_entry_count() -> int:
	return _catalog.size()