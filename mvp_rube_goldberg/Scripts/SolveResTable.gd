class_name SolveResTable
extends RefCounted

enum CollisionResult { NONE, STATE_INC, DESTROY, BOUNCE, TRIGGER, EXPLODE }

var _table: Dictionary = {}
var _default_behavior: Dictionary = {}

func _init():
	_build_default_behavior()
	_load_table()

func _build_default_behavior() -> void:
	_default_behavior = {
		"result": CollisionResult.STATE_INC,
		"target_state_inc": 1,
		"other_state_inc": 0,
		"requires_trigger": false,
		"probability": 1.0,
	}

func _load_table() -> void:
	var path = "res://data/solve_res_table.json"
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		push_warning("SolveResTable: Could not load " + path + ", using defaults")
		_build_fallback_table()
		return
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed is Dictionary:
		_table = parsed
	else:
		_build_fallback_table()

func _build_fallback_table() -> void:
	_table = {
		"collision_rules": [
			{
				"source_category": "Balls",
				"target_category": "Walls / Floors",
				"result": CollisionResult.BOUNCE,
				"cor_override": 128,
			},
			{
				"source_category": "Balls",
				"target_category": "Balls",
				"result": CollisionResult.STATE_INC,
				"target_state_inc": 1,
			},
			{
				"source_category": "Balls",
				"target_category": "Balloons / Airships",
				"result": CollisionResult.EXPLODE,
				"target_destroy": true,
			},
			{
				"source_category": "Explosives / Projectiles",
				"target_category": "Walls / Floors",
				"result": CollisionResult.EXPLODE,
				"explosion_radius": 80,
			},
			{
				"source_category": "Balloons / Airships",
				"target_category": "Special Mechanics",
				"result": CollisionResult.TRIGGER,
				"trigger_name": "proximity",
			},
			{
				"source_category": "Rotating Power Sources",
				"target_category": "Balloons / Airships",
				"result": CollisionResult.EXPLODE,
				"target_destroy": true,
			},
			{
				"source_category": "Light / Flame Sources",
				"target_category": "Explosives / Projectiles",
				"result": CollisionResult.EXPLODE,
				"ignition": true,
			},
			{
				"source_category": "Electrical",
				"target_category": "Characters",
				"result": CollisionResult.TRIGGER,
				"trigger_name": "collision",
			},
			{
				"source_category": "Springs / Pneumatics",
				"target_category": "Balls",
				"result": CollisionResult.BOUNCE,
				"vel_boost": 512,
			},
			{
				"source_category": "Ropes / Belts / Pulleys",
				"target_category": "Balls",
				"result": CollisionResult.NONE,
			},
		]
	}

func resolve(source: Part, target: Part, world_state) -> Dictionary:
	var src_cat = _get_category(source.part_type)
	var tgt_cat = _get_category(target.part_type)
	var rule = _find_rule(src_cat, tgt_cat)
	if rule.is_empty():
		return _get_default_result(source, target)
	return _apply_rule(source, target, rule, world_state)

func _find_rule(src_cat: String, tgt_cat: String) -> Dictionary:
	var rules = _table.get("collision_rules", [])
	for r in rules:
		if _category_matches(r.get("source_category", ""), src_cat) and _category_matches(r.get("target_category", ""), tgt_cat):
			return r
	return {}

func _category_matches(pattern: String, actual: String) -> bool:
	if pattern.is_empty() or pattern == "*":
		return true
	if pattern == actual:
		return true
	var patterns = pattern.split(",", false)
	for p in patterns:
		if p.strip_edges() == actual:
			return true
	return false

func _apply_rule(source: Part, target: Part, rule: Dictionary, world_state) -> Dictionary:
	var result_type = rule.get("result", CollisionResult.STATE_INC)
	var outcome = {"action": result_type, "source_effect": {}, "target_effect": {}}

	match result_type:
		CollisionResult.NONE:
			outcome["action"] = CollisionResult.NONE
		CollisionResult.STATE_INC:
			var src_inc = rule.get("target_state_inc", 1)
			var tgt_inc = rule.get("other_state_inc", 0)
			if src_inc > 0 and source.state_counter < source.state_limit_upper:
				source.state_counter += src_inc
			if tgt_inc > 0 and target.state_counter < target.state_limit_upper:
				target.state_counter += tgt_inc
		CollisionResult.BOUNCE:
			var cor = rule.get("cor_override", -1)
			if cor > 0:
				source.cor_q8 = cor
				target.cor_q8 = cor
		CollisionResult.DESTROY:
			if rule.get("target_destroy", false):
				target.destroyed = true
			if rule.get("source_destroy", false):
				source.destroyed = true
		CollisionResult.EXPLODE:
			var radius = rule.get("explosion_radius", 64)
			var src_destroy = rule.get("source_destroy", true)
			var tgt_destroy = rule.get("target_destroy", true)
			if src_destroy:
				source.destroyed = true
			if tgt_destroy:
				target.destroyed = true
			_propagate_explosion(source, target, radius, world_state)
		CollisionResult.TRIGGER:
			var trig_name = rule.get("trigger_name", "collision")
			if source.triggers.has(trig_name):
				if source.state_counter < source.state_limit_upper:
					source.state_counter += 1
			if target.triggers.has(trig_name):
				if target.state_counter < target.state_limit_upper:
					target.state_counter += 1
	return outcome

func _get_default_result(source: Part, target: Part) -> Dictionary:
	if source.triggers.has("collision"):
		if source.state_counter < source.state_limit_upper:
			source.state_counter += 1
	if target.triggers.has("collision"):
		if target.state_counter < target.state_limit_upper:
			target.state_counter += 1
	return {"action": CollisionResult.STATE_INC}

func _propagate_explosion(source: Part, target: Part, radius: int, world_state) -> void:
	var cx = (source.x + target.x) / 2
	var cy = (source.y + target.y) / 2
	for p in world_state.parts_data:
		if p.id == source.id or p.id == target.id:
			continue
		var pcx = p.x + p.width_1 / 2
		var pcy = p.y + p.height_1 / 2
		var dx = pcx - cx
		var dy = pcy - cy
		var dist = maxi(abs(dx), abs(dy))
		if dist < radius:
			var flammable = ["Explosives / Projectiles", "Balloons / Airships"]
			if flammable.has(_get_category(p.part_type)):
				p.destroyed = true

func _get_category(part_type: int) -> String:
	var reg = _get_behavior_registry()
	if reg:
		return reg.get_category(part_type)
	return _fallback_category(part_type)

func _fallback_category(pt: int) -> String:
	var map = {
		0: "Balls", 9: "Balls", 28: "Balls", 43: "Balls", 44: "Balls",
		1: "Walls / Floors", 46: "Walls / Floors",
		4: "Balloons / Airships", 79: "Balloons / Airships", 109: "Balloons / Airships",
		6: "Rotating Power Sources", 5: "Rotating Power Sources", 14: "Rotating Power Sources",
		10: "Ropes / Belts / Pulleys", 8: "Ropes / Belts / Pulleys",
		18: "Explosives / Projectiles", 19: "Explosives / Projectiles",
		24: "Electrical", 26: "Electrical",
		29: "Light / Flame Sources", 45: "Light / Flame Sources",
		13: "Springs / Pneumatics", 16: "Springs / Pneumatics",
	}
	return map.get(pt, "Unknown")

func _get_behavior_registry() -> Node:
	var tree = Engine.get_main_loop()
	if tree and tree.root:
		return tree.root.get_node_or_null("/root/BehaviorRegistry")
	return null

func add_rule(rule: Dictionary) -> void:
	if not _table.has("collision_rules"):
		_table["collision_rules"] = []
	_table["collision_rules"].append(rule)

func get_rule_count() -> int:
	return _table.get("collision_rules", []).size()

func clear_rules() -> void:
	_table["collision_rules"] = []

func to_dict() -> Dictionary:
	return _table.duplicate(true)

func from_dict(d: Dictionary) -> void:
	_table = d.duplicate(true)