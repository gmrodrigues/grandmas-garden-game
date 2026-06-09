const _Part = preload("res://Scripts/Part.gd")

const ARCH_STATIC: int = 0
const ARCH_KINETIC: int = 1
const ARCH_DRIVER: int = 2
const ARCH_LINK: int = 3
const ARCH_EMITTER: int = 4
const ARCH_CONSUMER: int = 5

const FLAG_MOVING: int = 0x1000

static var _behavior_registry = null

static func _get_registry():
	if _behavior_registry == null:
		_behavior_registry = load("res://Scripts/BehaviorRegistry.gd").new()
	return _behavior_registry

static func create_part(id: int, data: Dictionary):
	var part_type = data.get("part_type", 0)
	var archetype = _get_archetype(part_type)
	var px = data.get("pos_x", 0)
	var py = data.get("pos_y", 0)
	var p = _Part.new(id, part_type, archetype, px, py)

	p.name = data.get("name", "")
	p.width_1 = data.get("width", 32)
	p.height_1 = data.get("height", 32)
	p.width_2 = data.get("width_2", p.width_1)
	p.height_2 = data.get("height_2", p.height_1)
	p.facing = data.get("facing", 1)
	p.appearance = data.get("appearance", 0)
	p.rope_segment_length = data.get("rope_segment_length", 200)
	p.connected_1 = data.get("connected_1", -1)
	p.connected_2 = data.get("connected_2", -1)
	p.pressure_max_vel = data.get("pressure_max_vel", 512)
	p.state_limit_upper = data.get("state_limit_upper", 8)
	p.state_limit_lower = data.get("state_limit_lower", 0)
	p.state_limit_reset = data.get("state_limit_reset", 0)
	p.state_limit_sub_a = data.get("state_limit_sub_a", 5)
	p.state_limit_sub_b = data.get("state_limit_sub_b", 5)

	var mass_override = data.get("mass", -1)
	var cor_override = data.get("cor_q8", -1)
	var damping_override = data.get("damping", -1)
	var grav_cat_override = data.get("gravity_category", -1)
	var buoy_override = data.get("gravity_buoyancy", -1)
	var triggers_override = data.get("triggers")
	var destructible_override = data.get("destructible", null)

	if mass_override < 0 or cor_override < 0 or damping_override < 0 or grav_cat_override < 0:
		var reg = _get_registry()
		if reg:
			var props = reg.get_physics_props(part_type)
			var limits = reg.get_state_limits(part_type)
			if mass_override < 0:
				p.mass = props.get("mass", 2832)
			if cor_override < 0:
				p.cor_q8 = props.get("cor_q8", 128)
			if damping_override < 0:
				p.damping = props.get("damping", 200)
			if grav_cat_override < 0:
				p.gravity_category = props.get("gravity_category", 7)
				p.gravity_buoyancy = props.get("gravity_buoyancy", 0)
			if triggers_override == null:
				p.triggers = props.get("triggers", [])
			if destructible_override == null:
				p.destructible = props.get("destructible", false)
			if data.get("state_limit_upper", -1) < 0:
				p.state_limit_upper = limits.get("upper", 8)
				p.state_limit_lower = limits.get("lower", 0)
				p.state_limit_reset = limits.get("reset", 0)
				p.state_limit_sub_a = limits.get("sub_a", 5)
				p.state_limit_sub_b = limits.get("sub_b", 5)
		else:
			if mass_override < 0: p.mass = 2832
			if cor_override < 0: p.cor_q8 = 128
			if damping_override < 0: p.damping = 200
			if grav_cat_override < 0: p.gravity_category = 7
	else:
		p.mass = mass_override
		p.cor_q8 = cor_override
		p.damping = damping_override
		p.gravity_category = grav_cat_override
		if buoy_override != -1:
			p.gravity_buoyancy = buoy_override

	if triggers_override is Array:
		p.triggers = triggers_override
	if destructible_override != null:
		p.destructible = destructible_override

	p.friction_q8 = data.get("friction_q8", 0)
	p.collision_radius = data.get("collision_radius", 0)

	if data.get("is_moving", false):
		p.flags_1 |= FLAG_MOVING
		p.is_moving = true

	return p

static func create_part_minimal(id: int, part_type: int, x: int, y: int, w: int = 32, h: int = 32) -> _Part:
	var archetype = _get_archetype(part_type)
	var p = _Part.new(id, part_type, archetype, x, y)
	p.width_1 = w
	p.height_1 = h
	var reg = _get_registry()
	if reg:
		var props = reg.get_physics_props(part_type)
		var limits = reg.get_state_limits(part_type)
		p.mass = props.get("mass", 2832)
		p.cor_q8 = props.get("cor_q8", 128)
		p.damping = props.get("damping", 200)
		p.gravity_category = props.get("gravity_category", 7)
		p.gravity_buoyancy = props.get("gravity_buoyancy", 0)
		p.triggers = props.get("triggers", [])
		p.destructible = props.get("destructible", false)
		p.state_limit_upper = limits.get("upper", 8)
		p.state_limit_lower = limits.get("lower", 0)
		p.state_limit_reset = limits.get("reset", 0)
		p.is_moving = props.get("is_moving", false)
	return p

static func _get_archetype(part_type: int) -> int:
	var reg = _get_registry()
	if reg:
		return reg.get_archetype(part_type)
	return _fallback_archetype(part_type)

static func _fallback_archetype(part_type: int) -> int:
	if part_type == 1 or part_type == 71 or (part_type >= 82 and part_type <= 85) or (part_type >= 103 and part_type <= 106) or part_type == 110 or part_type == 111:
		return ARCH_STATIC
	if part_type == 0 or part_type == 4 or part_type == 9 or part_type == 28 or part_type == 43 or part_type == 44:
		return ARCH_KINETIC
	if part_type == 6 or part_type == 5 or part_type == 14 or part_type == 31 or part_type == 40 or part_type == 50 or part_type == 86:
		return ARCH_DRIVER
	if part_type == 10 or part_type == 7 or part_type == 8 or part_type == 76:
		return ARCH_LINK
	if part_type == 26 or part_type == 21 or part_type == 25 or part_type == 38:
		return ARCH_EMITTER
	if part_type == 24 or part_type == 13 or part_type == 16 or part_type == 35:
		return ARCH_CONSUMER
	return ARCH_STATIC