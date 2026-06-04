extends RefCounted
class_name SolutionCondition

enum CheckType {
	POSITION,
	OFF_SCREEN,
	OFF_TOP,
	OFF_BOTTOM,
	STATE_ONLY
}

var part_index: int = -1
var type: CheckType
var target_rect: Rect2
var target_state: int = -1
var ticks_to_wait: int = 0
var satisfied_ticks: int = 0

func _init(_type: CheckType, p_index: int):
	type = _type
	part_index = p_index

func check(world_state: WorldState) -> bool:
	if part_index < 0 or part_index >= world_state.parts.size():
		return false
		
	var part = world_state.parts[part_index]
	var condition_met = false
	
	match type:
		CheckType.POSITION:
			var part_rect = Rect2(part.pos_x, part.pos_y, part.width_1, part.height_1)
			condition_met = part_rect.intersects(target_rect)
		CheckType.OFF_SCREEN:
			condition_met = part.pos_x < 0 or part.pos_x > 640 or part.pos_y < 0 or part.pos_y > 480
		CheckType.OFF_TOP:
			condition_met = part.pos_y < -500
		CheckType.OFF_BOTTOM:
			condition_met = part.pos_y > 1000
		CheckType.STATE_ONLY:
			condition_met = part.current_state == target_state
			
	if condition_met:
		satisfied_ticks += 1
		if satisfied_ticks >= ticks_to_wait:
			return true
	else:
		satisfied_ticks = 0
		
	return false
