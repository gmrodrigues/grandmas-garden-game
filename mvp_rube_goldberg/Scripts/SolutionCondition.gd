class_name SolutionCondition
extends RefCounted

signal solved

var solution_type: String = ""
var target_part_name: String = ""
var zone: Dictionary = {}
var required_state: int = -1
var parts_ref: Array = []
var is_primary: bool = true

var _sub_conditions: Array = []
var _multi_mode: String = "single"

func _init(data: Dictionary = {}, parts: Array = []):
	if not data.is_empty():
		_parse(data)
	if not parts.is_empty():
		parts_ref = parts

func _parse(data: Dictionary) -> void:
	solution_type = data.get("type", "")
	target_part_name = data.get("target_part", "")
	zone = data.get("zone", {})
	required_state = data.get("required_state", -1)
	is_primary = data.get("primary", true)

	if solution_type == "multi_condition":
		_multi_mode = data.get("mode", "and")
		var conds = data.get("conditions", [])
		_sub_conditions.clear()
		for c in conds:
			var sub = SolutionCondition.new(c, parts_ref)
			_sub_conditions.append(sub)
		return

func bind_parts(parts: Array) -> void:
	parts_ref = parts
	for sub in _sub_conditions:
		sub.bind_parts(parts)

func check() -> bool:
	if solution_type == "":
		return false
	if solution_type == "multi_condition":
		return _check_multi()
	if solution_type == "AABB_overlap":
		return _check_aabb_overlap()
	if solution_type == "state_match":
		return _check_state_match()
	return false

func _check_multi() -> bool:
	if _sub_conditions.is_empty():
		return false
	if _multi_mode == "and":
		for sub in _sub_conditions:
			if not sub.check():
				return false
		return true
	elif _multi_mode == "or":
		for sub in _sub_conditions:
			if sub.check():
				return true
		return false
	return false

func _check_aabb_overlap() -> bool:
	var target = _find_part(target_part_name)
	if target == null:
		return false
	var cx = target.pos_x + (target.width_1 >> 1)
	var cy = target.pos_y + (target.height_1 >> 1)
	var zx = zone.get("x", 0)
	var zy = zone.get("y", 0)
	var zw = zone.get("width", 640)
	var zh = zone.get("height", 480)
	return cx >= zx and cx <= zx + zw and cy >= zy and cy <= zy + zh

func _check_state_match() -> bool:
	var target = _find_part(target_part_name)
	if target == null:
		return false
	return target.state_counter >= required_state

func get_conditions() -> Array:
	return _sub_conditions

func get_multi_mode() -> String:
	return _multi_mode

func _find_part(name: String):
	for p in parts_ref:
		if p.name == name:
			return p
	return null