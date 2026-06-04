extends RefCounted
class_name SolutionCondition

enum CheckType {
	POSITION,
	OFF_SCREEN,
	OFF_TOP,
	OFF_BOTTOM,
	STATE_ONLY,
}

var part_index: int = -1
var type: CheckType
var target_rect: Rect2
var target_state: int = -1
var ticks_to_wait: int = 0
var satisfied_ticks: int = 0

func _init(_type: CheckType = CheckType.STATE_ONLY, p_index: int = -1):
	type = _type
	part_index = p_index

func check(world_state: WorldState) -> bool:
	if part_index < 0 or part_index >= world_state.parts.size():
		return false
	var part = world_state.parts[part_index]
	var condition_met = false

	match type:
		CheckType.POSITION:
			var pr = Rect2(part.x, part.y, part.width_1, part.height_1)
			condition_met = pr.intersects(target_rect)
		CheckType.OFF_SCREEN:
			condition_met = part.x < -100 or part.x > 700 or part.y < -100 or part.y > 500
		CheckType.OFF_TOP:
			condition_met = part.y < -500
		CheckType.OFF_BOTTOM:
			condition_met = part.y > 1000
		CheckType.STATE_ONLY:
			condition_met = part.current_state == target_state

	if condition_met:
		satisfied_ticks += 1
		if satisfied_ticks >= ticks_to_wait:
			return true
	else:
		satisfied_ticks = 0
	return false

func reset():
	satisfied_ticks = 0

func to_dict() -> Dictionary:
	var rect_arr = [int(target_rect.position.x), int(target_rect.position.y), int(target_rect.size.x), int(target_rect.size.y)]
	return {
		"part_index": part_index,
		"type": type,
		"rect": rect_arr,
		"target_state": target_state,
		"ticks_to_wait": ticks_to_wait,
	}

func from_dict(d: Dictionary):
	part_index = d.get("part_index", -1)
	type = d.get("type", CheckType.STATE_ONLY) as int
	var r = d.get("rect", [0, 0, 0, 0])
	if r is Array and r.size() >= 4:
		target_rect = Rect2(r[0], r[1], r[2], r[3])
	target_state = d.get("target_state", -1)
	ticks_to_wait = d.get("ticks_to_wait", 0)
