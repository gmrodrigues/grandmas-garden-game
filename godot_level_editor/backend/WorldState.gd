extends RefCounted
class_name WorldState

var parts: Array[PartData] = []
var gravity: int = 272
var pressure: int = 67
var tick_count: int = 0
var viewport: Array = [0, 0, 560, 377]

var on_collision: Callable = Callable()
var on_state_change: Callable = Callable()

func add_part(part: PartData):
	part.sync_pos()
	var cat = BehaviorRegistry.get_category(part.part_type)
	part.collision_cat = _col_cat_for_game_cat(cat)
	var limits = BehaviorRegistry.get_state_limits(part.part_type)
	part.state_limit_lower = limits.limit_lower
	part.state_limit_upper = limits.limit_upper
	part.state_limit_reset = limits.limit_reset
	part.state_limit_sub_a = limits.limit_sub_a
	part.state_limit_sub_b = limits.limit_sub_b
	var props = BehaviorRegistry.get_physics_props(part.part_type)
	part.mass = props.get("mass", 2832)
	part.cor_q8 = props.get("cor_q8", 128)
	part.friction_q8 = props.get("friction_q8", 0)
	part.collision_radius = props.get("collision_radius", 0)
	part.collision_w = props.get("collision_w", 0)
	part.collision_h = props.get("collision_h", 0)
	part.is_moving = bool(part.flags_1 & PartData.FLAG_MOVING)
	parts.append(part)

func remove_part(index: int):
	if 0 <= index and index < len(parts):
		parts.remove_at(index)

func get_part_by_index(index: int) -> PartData:
	if 0 <= index and index < len(parts):
		return parts[index]
	return null

func reset():
	for part in parts:
		part.vel_x = 0
		part.vel_y = 0
		part.current_state = 0
		part.state_counter = 0
		part.sub_counter = 0
		part._countdown = -1
	tick_count = 0

func _col_cat_for_game_cat(game_cat: String) -> String:
	match game_cat:
		"Walls / Floors", "Inclines": return "STATIC"
		"Balls", "Containers", "Characters", "Pipe Systems", "Pool Table": return "DYNAMIC"
		"Explosives / Projectiles": return "EXPLOSIVE"
		"Cutting / Popping", "Springs / Pneumatics", "Rotating Power Sources", "Electrical", "Lasers / Optics", "Special Mechanics": return "TOOL"
		"Ropes / Belts / Pulleys": return "ROPE"
		"Light / Flame Sources", "Scenery": return "SCENERY"
		"Created / Phantom": return "CREATED"
	return "DYNAMIC"
