class_name ChainManager
extends RefCounted

const _Board = preload("res://Scripts/Board.gd")
const _PhysicsEngine = preload("res://Scripts/PhysicsEngine.gd")
const _Part = preload("res://Scripts/Part.gd")

var board
var physics

var chain_script: Array = []
var _fired: Array = []
var _flags: Dictionary = {}

var _flag_dependents: Dictionary = {}
var _part_dependents: Dictionary = {}
var _dirty_flags: Array = []
var _dirty_parts: Array = []
var _rule_needs_reeval: Array = []

var event_log: Array = []
var deterministic_log: Array = []
var deterministic_run: bool = false

var tick_count: int = 0
var max_ticks: int = 2000

signal chain_completed(tick: int)
signal event_logged(msg: String)

func _init(b, p):
	board = b
	physics = p

func load_from_level(data: Dictionary):
	chain_script = data.get("chain_script", [])
	_fired.clear()
	_flags.clear()
	_build_rule_cache()

func _build_rule_cache() -> void:
	_flag_dependents.clear()
	_part_dependents.clear()
	_rule_needs_reeval.clear()
	for i in range(chain_script.size()):
		_rule_needs_reeval.append(true)
		var when = chain_script[i].get("when", {})
		_index_condition_dependencies(when, i)

func _index_condition_dependencies(when: Dictionary, rule_idx: int) -> void:
	var type = when.get("type", "")
	match type:
		"tick":
			pass
		"flag":
			var fname = when.get("name", "")
			if not _flag_dependents.has(fname):
				_flag_dependents[fname] = []
			_flag_dependents[fname].append(rule_idx)
		"and":
			for c in when.get("conditions", []):
				_index_condition_dependencies(c, rule_idx)
		"prop_ge", "prop_eq", "prop_gt_ref":
			var pname = when.get("part", "")
			if pname != "":
				if not _part_dependents.has(pname):
					_part_dependents[pname] = []
				_part_dependents[pname].append(rule_idx)
		"overlap":
			var an = when.get("a", "")
			var bn = when.get("b", "")
			if an != "":
				if not _part_dependents.has(an):
					_part_dependents[an] = []
				_part_dependents[an].append(rule_idx)
			if bn != "":
				if not _part_dependents.has(bn):
					_part_dependents[bn] = []
				_part_dependents[bn].append(rule_idx)

func _mark_flag_dirty(name: String) -> void:
	if not _dirty_flags.has(name):
		_dirty_flags.append(name)
	if _flag_dependents.has(name):
		for ri in _flag_dependents[name]:
			_rule_needs_reeval[ri] = true

func _mark_part_dirty(name: String) -> void:
	if not _dirty_parts.has(name):
		_dirty_parts.append(name)
	if _part_dependents.has(name):
		for ri in _part_dependents[name]:
			_rule_needs_reeval[ri] = true

func reset():
	_fired.clear()
	_flags.clear()
	event_log.clear()
	deterministic_log.clear()
	deterministic_run = false
	tick_count = 0
	_dirty_flags.clear()
	_dirty_parts.clear()
	for i in range(_rule_needs_reeval.size()):
		_rule_needs_reeval[i] = true

func evaluate_chain():
	var has_dirty_state = not _dirty_flags.is_empty() or not _dirty_parts.is_empty()
	for i in range(chain_script.size()):
		var rule = chain_script[i]
		var mode = rule.get("mode", "once")
		if mode == "once" and _fired.has(i):
			continue
		var when = rule.get("when", {})
		if not _should_evaluate_condition(when, has_dirty_state, i):
			continue
		if _check_condition(when):
			_execute_actions(rule.get("actions", []))
			if mode == "once":
				_fired.append(i)
	_dirty_flags.clear()
	_dirty_parts.clear()

func _should_evaluate_condition(when: Dictionary, has_dirty_state: bool, rule_idx: int) -> bool:
	if not has_dirty_state:
		return true
	var type = when.get("type", "")
	if type == "tick":
		return true
	if not _rule_needs_reeval[rule_idx]:
		return false
	if type == "flag":
		return _dirty_flags.has(when.get("name", ""))
	if type == "prop_ge" or type == "prop_eq" or type == "prop_gt_ref":
		return _dirty_parts.has(when.get("part", ""))
	if type == "overlap":
		return _dirty_parts.has(when.get("a", "")) or _dirty_parts.has(when.get("b", ""))
	if type == "and":
		for c in when.get("conditions", []):
			if _should_evaluate_condition(c, has_dirty_state, rule_idx):
				return true
		return false
	return true

func _check_condition(when: Dictionary) -> bool:
	var type = when.get("type", "")
	match type:
		"tick":
			return true
		"flag":
			return _flags.get(when.get("name", ""), false) == when.get("value", true)
		"and":
			var conds = when.get("conditions", [])
			for c in conds:
				if not _check_condition(c):
					return false
			return true
		"prop_ge":
			var p = _find_part(when.get("part", ""))
			if p == null or not when.get("prop", "") in p:
				return false
			return p[when.get("prop", "")] >= when.get("value", 0)
		"prop_eq":
			var p = _find_part(when.get("part", ""))
			if p == null or not when.get("prop", "") in p:
				return false
			return p[when.get("prop", "")] == when.get("value", null)
		"prop_gt_ref":
			var p = _find_part(when.get("part", ""))
			var ref = _find_part(when.get("ref_part", ""))
			if p == null or ref == null:
				return false
			var prop = when.get("prop", "")
			var ref_prop = when.get("ref_prop", "")
			if not prop in p or not ref_prop in ref:
				return false
			return p[prop] > ref[ref_prop] + when.get("offset", 0)
		"overlap":
			var a = _find_part(when.get("a", ""))
			var b = _find_part(when.get("b", ""))
			if a == null or b == null:
				return false
			return a.aabb_overlap(b)
		"solution":
			return board.solution != null and board.solution.check()
	return false

func _execute_actions(actions: Array):
	for action in actions:
		var type = action.get("type", "")
		match type:
			"set_flag":
				var flag_name = action.get("name", "")
				_flags[flag_name] = action.get("value", true)
				_mark_flag_dirty(flag_name)
			"inc":
				var p = _find_part(action.get("part", ""))
				if p:
					var prop = action.get("prop", "")
					if prop in p:
						p[prop] = p[prop] + action.get("value", 1)
						if prop == "x" or prop == "y" or prop == "pos_x" or prop == "pos_y":
							_mark_part_dirty(p.name)
			"set":
				var p = _find_part(action.get("part", ""))
				if p:
					var prop = action.get("prop", "")
					if prop in p:
						p[prop] = action.get("value", null)
						if prop == "x" or prop == "y" or prop == "pos_x" or prop == "pos_y":
							_mark_part_dirty(p.name)
			"delta":
				var p = _find_part(action.get("part", ""))
				if p:
					var prop = action.get("prop", "")
					if prop in p:
						var val = p[prop] + action.get("value", 0)
						p[prop] = val
						if prop == "x":
							if "pos_x" in p:
								p["pos_x"] = val
							_mark_part_dirty(p.name)
						elif prop == "y":
							if "pos_y" in p:
								p["pos_y"] = val
							_mark_part_dirty(p.name)
			"log":
				var msg = action.get("msg", "")
				if msg.find("%") >= 0:
					msg = msg % [tick_count / 60.0]
				_log(msg)
			"win":
				_log(action.get("msg", "Chain completed!"))
				chain_completed.emit(tick_count)

func _find_part(name: String):
	for p in board.parts:
		if p.name == name:
			return p
	return null

func _log(msg: String):
	event_log.append("[Tick %d] %s" % [tick_count, msg])
	print("[Tick %d] %s" % [tick_count, msg])
	event_logged.emit(msg)

func print_results():
	print("\n=== MVP Chain Results ===")
	print("Total ticks: ", tick_count)
	print("Events: ", event_log.size())
	for e in event_log:
		print("  ", e)
	print("Final positions:")
	for i in range(board.parts.size()):
		var p = board.parts[i]
		print("  Part ", i, " (", p.name, "): pos=(", p.x, ",", p.y, ") vel=(", p.vel_x, ",", p.vel_y, ") state=", p.state_counter, " moving=", p.is_moving)

func get_deterministic_snapshot() -> Dictionary:
	var snap = {
		"tick": tick_count,
		"ball_x": 0, "ball_y": 0, "ball_vel_y": 0,
		"balloon_x": 0, "balloon_y": 0,
		"laser_powered": false,
		"gate_y": 0,
		"tick_accum_ms": 0.0
	}
	for p in board.parts:
		if p.name == "Ball":
			snap["ball_x"] = p.x
			snap["ball_y"] = p.y
			snap["ball_vel_y"] = p.vel_y
		elif p.name == "Balloon":
			snap["balloon_x"] = p.x
			snap["balloon_y"] = p.y
		elif p.name == "Laser":
			snap["laser_powered"] = p.is_powered
		elif p.name == "Gate":
			snap["gate_y"] = p.y
	return snap