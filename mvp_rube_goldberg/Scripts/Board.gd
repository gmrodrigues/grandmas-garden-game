class_name Board
extends Node2D

const _Part = preload("res://Scripts/Part.gd")
const _PartFactory = preload("res://Scripts/PartFactory.gd")
const _SolutionCondition = preload("res://Scripts/SolutionCondition.gd")

const MAX_PARTS: int = 32

var parts: Array = []
var part_sprites: Array = []
var sprite_cache: Dictionary = {}

var level_data: Dictionary = {}
var solution

signal parts_changed

func _init():
	parts = []
	part_sprites = []
	level_data = {}

func add_part(p) -> int:
	var idx = parts.size()
	if idx >= MAX_PARTS:
		return -1
	p.id = idx
	if p.archetype == _Part.ARCH_KINETIC:
		p.is_moving = true
	parts.append(p)
	return idx

func find_part_named(name: String):
	for p in parts:
		if p.name == name:
			return p
	return null

func clear_level():
	parts.clear()
	for child in get_children():
		if child.name.begins_with("PartSprite_"):
			remove_child(child)
			child.free()
	part_sprites.clear()
	sprite_cache.clear()

func load_level(path: String) -> bool:
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		push_error("Board: Level load failed for " + path)
		return false
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed == null or typeof(parsed) != TYPE_DICTIONARY:
		push_error("Board: Failed to parse level JSON from " + path)
		return false
	level_data = parsed
	var meta = level_data.get("meta", {})
	var sol_data = level_data.get("solution", {})
	var part_data = level_data.get("parts", [])
	parts.clear()
	if not meta.is_empty():
		pass
	for pd in part_data:
		var p = _PartFactory.create_part(pd.get("id", parts.size()), pd)
		add_part(p)
	solution = _SolutionCondition.new(sol_data, parts)
	spawn_sprites()
	return true

func spawn_sprites():
	for child in get_children():
		if child.name.begins_with("PartSprite_"):
			remove_child(child)
			child.free()
	part_sprites.clear()
	for i in range(parts.size()):
		var s = Sprite2D.new()
		s.name = "PartSprite_" + str(i)
		s.centered = false
		add_child(s)
		part_sprites.append(s)
		update_sprite(i)

func spawn_sprite_for_part(p) -> void:
	var idx = p.id
	while part_sprites.size() <= idx:
		var s = Sprite2D.new()
		s.name = "PartSprite_" + str(part_sprites.size())
		s.centered = false
		add_child(s)
		part_sprites.append(s)
	update_sprite(idx)

func get_arch_color(arch: int) -> Color:
	match arch:
		_Part.ARCH_STATIC:   return Color(0.4, 0.4, 0.4)
		_Part.ARCH_KINETIC:  return Color(0.3, 0.3, 0.8)
		_Part.ARCH_DRIVER:   return Color(0.6, 0.6, 0.6)
		_Part.ARCH_LINK:     return Color(0.5, 0.3, 0.1)
		_Part.ARCH_EMITTER:  return Color(0.9, 0.2, 0.2)
		_Part.ARCH_CONSUMER: return Color(0.3, 0.8, 0.8)
	return Color(0.5, 0.5, 0.5)

func update_sprite(idx: int):
	if idx >= part_sprites.size() or idx >= parts.size():
		return
	var s = part_sprites[idx]
	var p = parts[idx]
	var tex = null
	var anm_name = AnmDatabase.get_anm_for_part(p.part_type)
	if anm_name != "":
		var anm_data = AnmDatabase.load_anm(anm_name)
		if anm_data and not anm_data.is_empty():
			var img = null
			var sc = anm_data.get("section_c", [])
			if sc.size() == 2 and p.archetype == _Part.ARCH_STATIC and (p.width_1 % 16 == 0 or p.height_1 % 16 == 0):
				img = AnmRenderer.render_wall(anm_name, p.width_1, p.height_1)
			if img == null:
				var state_id = _get_state_id(anm_data, p.state_counter)
				img = AnmRenderer.render_frame(anm_name, state_id, p.state_counter, p.width_1, p.height_1)
			if img:
				if p.is_powered:
					img = _brighten_image(img)
				tex = ImageTexture.create_from_image(img)
	if tex == null:
		var color = get_arch_color(p.archetype)
		if p.is_powered:
			color = Color(min(color.r + 0.4, 1.0), min(color.g + 0.4, 1.0), min(color.b + 0.4, 1.0))
		var w = maxi(p.width_1, 1)
		var h = maxi(p.height_1, 1)
		var img = Image.create(w, h, false, Image.FORMAT_RGBA8)
		img.fill(color)
		for py in range(h):
			for px in range(w):
				if px == 0 or px == w - 1 or py == 0 or py == h - 1:
					img.set_pixel(px, py, Color(0, 0, 0, 1))
				if p.state_counter > 0 and py < 4:
					img.set_pixel(px, py, Color(1, 0.5, 0, 1))
		tex = ImageTexture.create_from_image(img)
	s.texture = tex
	s.centered = false
	s.flip_h = bool(p.appearance & _Part.FLAG_FLIP)

func _get_state_id(anm_data: Dictionary, state_counter: int) -> int:
	var sc = anm_data.get("section_c", [])
	if sc.is_empty():
		return 1
	var idx = state_counter % sc.size()
	return sc[idx].get("state_id", 1)

func _brighten_image(img: Image) -> Image:
	for y in range(img.get_height()):
		for x in range(img.get_width()):
			var c = img.get_pixel(x, y)
			if c.a > 0:
				img.set_pixel(x, y, Color(min(c.r + 0.3, 1), min(c.g + 0.3, 1), min(c.b + 0.3, 1), c.a))
	return img

func sync_sprites():
	for i in range(parts.size()):
		if i >= part_sprites.size():
			continue
		var s = part_sprites[i]
		var p = parts[i]
		var last_st = s.get_meta("last_state", -1)
		if p.state_counter != last_st:
			update_sprite(i)
			s.set_meta("last_state", p.state_counter)
		s.position = Vector2(p.x, p.y)