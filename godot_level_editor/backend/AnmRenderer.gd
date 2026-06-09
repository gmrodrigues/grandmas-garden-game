extends RefCounted
class_name AnmRenderer

var bmp_cache: Dictionary = {}
var palette: Array = []
var palette_loaded: bool = false

func _init():
	pass

func load_palette(path: String = "res://data/palettes/PARTTEMP.json") -> Array:
	if palette_loaded:
		return palette
	var file = FileAccess.open(path, FileAccess.READ)
	if not file:
		_load_fallback_palette()
		return palette
	var json = JSON.new()
	if json.parse(file.get_as_text()) == OK:
		var data = json.get_data()
		var colors = data.get("colors", [])
		for c in colors:
			palette.append(Color8(c.get("r", 0), c.get("g", 0), c.get("b", 0), 255))
		while palette.size() < 256:
			palette.append(Color8(0, 0, 0, 255))
		palette_loaded = true
	else:
		_load_fallback_palette()
	file.close()
	return palette

func _load_fallback_palette():
	palette = [
		Color8(0,0,0), Color8(0,0,168), Color8(0,168,0), Color8(0,168,168),
		Color8(168,0,0), Color8(168,0,168), Color8(168,84,0), Color8(168,168,168),
		Color8(84,84,84), Color8(84,84,252), Color8(84,252,84), Color8(84,252,252),
		Color8(252,84,84), Color8(252,84,252), Color8(252,252,84), Color8(252,252,252),
	]
	while palette.size() < 256:
		palette.append(Color8(0, 0, 0, 255))
	palette_loaded = true

func decode_color(color_val: int) -> Color:
	if color_val >= 0 and color_val < palette.size():
		return palette[color_val]
	return Color8(color_val & 0xFF, (color_val >> 8) & 0xFF, (color_val >> 16) & 0xFF, 255)

func load_bmp(bmp_name: String, sub_image: int = -1) -> Image:
	var cache_key = bmp_name + "_" + str(sub_image)
	if bmp_cache.has(cache_key):
		return bmp_cache[cache_key]

	var dir = "res://data/sprites/"
	var candidates = []
	if sub_image >= 0:
		candidates.append(dir + bmp_name + "_f" + "%03d" % sub_image + ".png")
	candidates.append(dir + bmp_name + ".png")

	for path in candidates:
		if ResourceLoader.exists(path):
			var img = ResourceLoader.load(path) as Texture2D
			if img:
				var image = img.get_image()
				if image:
					if image.get_format() != Image.FORMAT_RGBA8:
						image.convert(Image.FORMAT_RGBA8)
					bmp_cache[cache_key] = image
					return image
	push_warning("AnmRenderer: missing sprite: " + bmp_name)
	return null

func get_frame_meta(anm_name: String, state_id: int, state_counter: int = 0,
					part_width: int = 0, part_height: int = 0) -> Dictionary:
	var anm_data = AnmDatabase.load_anm(anm_name)
	if anm_data.is_empty():
		return {}
	var first_a_idx = AnmDatabase.get_first_frame_for_state(anm_data, state_id)
	var section_a = anm_data.get("section_a", [])
	var section_b_idx: int
	if not section_a.is_empty():
		section_b_idx = section_a[(first_a_idx + state_counter) % section_a.size()]
	else:
		section_b_idx = first_a_idx
	if part_width > 0 or part_height > 0:
		var section_b = anm_data.get("section_b", [])
		for i in range(section_b.size()):
			var f = section_b[i]
			if f.get("width", 0) == part_width and f.get("height", 0) == part_height:
				section_b_idx = i
				break
	return AnmDatabase.get_frame_meta(anm_data, section_b_idx)

func render_frame(anm_name: String, state_id: int, state_counter: int = 0,
				  part_width: int = 0, part_height: int = 0) -> Image:
	var anm_data = AnmDatabase.load_anm(anm_name)
	if anm_data.is_empty():
		return null

	var first_a_idx = AnmDatabase.get_first_frame_for_state(anm_data, state_id)
	var section_a = anm_data.get("section_a", [])
	var section_b_idx: int

	if not section_a.is_empty():
		section_b_idx = section_a[(first_a_idx + state_counter) % section_a.size()]
	else:
		section_b_idx = first_a_idx

	if part_width > 0 or part_height > 0:
		var section_b = anm_data.get("section_b", [])
		for i in range(section_b.size()):
			var f = section_b[i]
			if f.get("width", 0) == part_width and f.get("height", 0) == part_height:
				section_b_idx = i
				break

	return _render_section_b_frame(anm_data, section_b_idx, anm_name)

func render_wall(anm_name: String, width: int, height: int) -> Image:
	var anm_data = AnmDatabase.load_anm(anm_name)
	if anm_data.is_empty() or not anm_data.get("section_a", []).is_empty():
		return null

	var section_c = anm_data.get("section_c", [])
	if section_c.size() != 2:
		return null

	var num_h = section_c[-2].get("first_frame_id", 0)
	var num_v = section_c[-1].get("first_frame_id", 0) - num_h
	if num_h <= 0 or num_v <= 0:
		return null

	var tile_size = 16
	var is_horizontal = height == tile_size and width > tile_size
	var is_vertical = width == tile_size and height > tile_size
	if not is_horizontal and not is_vertical:
		return null

	var wall_len: int
	var first_sub_img: int
	var num_tiles: int
	var surf_w: int
	var surf_h: int

	if is_horizontal:
		wall_len = width / tile_size
		first_sub_img = 0
		num_tiles = num_h
		surf_w = width; surf_h = tile_size
	else:
		wall_len = height / tile_size
		first_sub_img = num_h
		num_tiles = num_v
		surf_w = tile_size; surf_h = height

	var surface = Image.create(surf_w, surf_h, false, Image.FORMAT_RGBA8)
	surface.fill(Color(0, 0, 0, 0))

	for i in range(wall_len):
		var sub_idx: int
		if i == 0:
			sub_idx = first_sub_img
		elif i == wall_len - 1:
			sub_idx = first_sub_img + num_tiles - 1
		else:
			var center_idx = (i - 1) % (num_tiles - 2)
			sub_idx = first_sub_img + 1 + center_idx

		var sprite = load_bmp(anm_name, sub_idx)
		if sprite:
			if sprite.get_format() != surface.get_format():
				sprite.convert(surface.get_format())
			var pos_x = i * tile_size if is_horizontal else 0
			var pos_y = 0 if is_horizontal else i * tile_size
			surface.blit_rect(sprite, Rect2(0, 0, sprite.get_width(), sprite.get_height()), Vector2(pos_x, pos_y))

	return surface

func _render_section_b_frame(anm_data: Dictionary, section_b_idx: int, anm_name: String) -> Image:
	var meta = AnmDatabase.get_frame_meta(anm_data, section_b_idx)
	if meta.is_empty():
		return null

	var w = meta.get("width", 0)
	var h = meta.get("height", 0)
	if w <= 0 or h <= 0:
		return null

	var surface = Image.create(w, h, false, Image.FORMAT_RGBA8)
	surface.fill(Color(0, 0, 0, 0))

	var bytecodes = AnmDatabase.get_bytecodes_for_frame(anm_data, meta.get("bytecode_offset", 0))
	for entry in bytecodes:
		_execute_bytecode(surface, entry, anm_name)

	return surface

func _execute_bytecode(image: Image, entry: Dictionary, anm_name: String):
	var cmd = int(entry.get("cmd", -1))
	match cmd:
		2: _draw_bmp(image, entry, anm_name)
		3: _draw_rect(image, entry)
		4: _draw_line(image, entry)
		5:
			var sound_id = entry.get("sound_id", 0)
			AudioManager.play_sfx(sound_id)

func _draw_bmp(image: Image, entry: Dictionary, anm_name: String):
	var resource_id = int(entry.get("resource_id", 1))
	var sub_image = int(entry.get("sub_image", 0))
	var bx = int(entry.get("x", 0))
	var by = int(entry.get("y", 0))
	var flags = int(entry.get("flags", 0))

	var bmp_name = _resolve_resource_name(anm_name, resource_id)
	var sprite = load_bmp(bmp_name, sub_image)
	if sprite == null:
		return

	if sprite.get_format() != image.get_format():
		sprite.convert(image.get_format())
	if flags & 1:
		sprite.flip_x()
	if flags & 2:
		sprite.flip_y()

	image.blit_rect(sprite, Rect2(0, 0, sprite.get_width(), sprite.get_height()), Vector2(bx, by))

func _resolve_resource_name(anm_name: String, resource_id: int) -> String:
	if resource_id == 1:
		return anm_name
	return anm_name + "_" + str(resource_id)

func _draw_rect(image: Image, entry: Dictionary):
	var rx = int(entry.get("x", 0))
	var ry = int(entry.get("y", 0))
	var rw = int(entry.get("width", 0))
	var rh = int(entry.get("height", 0))
	var color_val = int(entry.get("color", 0))
	var color = decode_color(color_val)

	for y in range(ry, min(ry + rh, image.get_height())):
		for x in range(rx, min(rx + rw, image.get_width())):
			image.set_pixel(x, y, color)

func _draw_line(image: Image, entry: Dictionary):
	var x1 = int(entry.get("x1", 0))
	var y1 = int(entry.get("y1", 0))
	var x2 = int(entry.get("x2", 0))
	var y2 = int(entry.get("y2", 0))
	var color_val = int(entry.get("color", int(entry.get("flags", 0)) & 0xFF))
	var color = decode_color(color_val)

	var dx = abs(x2 - x1)
	var dy = abs(y2 - y1)
	var sx = 1 if x1 < x2 else -1
	var sy = 1 if y1 < y2 else -1
	var err = dx - dy
	var cx = x1
	var cy = y1

	while true:
		if cx >= 0 and cx < image.get_width() and cy >= 0 and cy < image.get_height():
			image.set_pixel(cx, cy, color)
		if cx == x2 and cy == y2:
			break
		var e2 = 2 * err
		if e2 > -dy:
			err -= dy
			cx += sx
		if e2 < dx:
			err += dx
			cy += sy
