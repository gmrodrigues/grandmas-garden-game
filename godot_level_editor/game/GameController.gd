extends Node2D
class_name GameController

enum GameState { SELECT_LEVEL, PLAYING, SOLVED }

var game_state: GameState = GameState.SELECT_LEVEL
var world: WorldState
var solver: PhysicsSolver
var checker: SolutionChecker
var loop: SimulationLoop
var current_level_path: String = ""
var overlay: Control
var anm_renderer: AnmRenderer

func _ready():
	world = WorldState.new()
	solver = PhysicsSolver.new(world)
	loop = SimulationLoop.new(world)
	overlay = Control.new()
	add_child(overlay)
	overlay.hide()
	anm_renderer = AnmRenderer.new()
	var args = OS.get_cmdline_args()
	var level_idx = args.find("--level")
	if level_idx >= 0 and level_idx + 1 < args.size():
		load_level(args[level_idx + 1])

func load_level(path: String):
	current_level_path = path
	var data = LevelSerializer.load_yaml(path)
	world = WorldState.new()
	solver = PhysicsSolver.new(world)
	loop = SimulationLoop.new(world)
	checker = SolutionChecker.new([])
	for d in data.get("parts", []):
		var dims = d.get("dimensions", {})
		var phys = d.get("physics", {})
		var pd = PartData.new(d.get("part_type", 0), d.get("x", 0), d.get("y", 0))
		pd.width_1 = dims.get("width_1", d.get("width_1", 32))
		pd.height_1 = dims.get("height_1", d.get("height_1", 32))
		pd.width_2 = dims.get("width_2", d.get("width_2", 32))
		pd.height_2 = dims.get("height_2", d.get("height_2", 32))
		pd.appearance = d.get("appearance", 0)
		var flags = d.get("flags", {})
		pd.flags_1 = flags.get("flag_1", "0x0000").trim_prefix("'").trim_suffix("'").hex_to_int() if flags.has("flag_1") else d.get("flags_1", 0)
		pd.flags_2 = flags.get("flag_2", "0x0000").trim_prefix("'").trim_suffix("'").hex_to_int() if flags.has("flag_2") else d.get("flags_2", 0)
		pd.flags_3 = flags.get("flag_3", "0x0000").trim_prefix("'").trim_suffix("'").hex_to_int() if flags.has("flag_3") else d.get("flags_3", 0)
		pd.connected_1 = phys.get("connected_1", d.get("connected_1", -256))
		pd.connected_2 = phys.get("connected_2", d.get("connected_2", -1))
		pd.outlet_plugged_1 = phys.get("outlet_plugged_1", d.get("outlet_plugged_1", -1))
		pd.outlet_plugged_2 = phys.get("outlet_plugged_2", d.get("outlet_plugged_2", -1))
		world.add_part(pd)
	_spawn_sprites()
	game_state = GameState.PLAYING

func _spawn_sprites():
	for child in get_children():
		if child is Sprite2D:
			child.queue_free()
	for i in range(world.parts.size()):
		var p = world.parts[i]
		var s = Sprite2D.new()
		s.set_meta("last_state", p.state_counter)
		s.set_meta("off_x", 0)
		s.set_meta("off_y", 0)
		add_child(s)
		_update_sprite(s, p)
		s.position = Vector2(p.x + s.get_meta("off_x", 0), p.y + s.get_meta("off_y", 0))

func _update_sprite(s: Sprite2D, p: PartData):
	var tex = null
	var anm = AnmDatabase.get_anm_for_part(p.part_type)
	var off_x = 0
	var off_y = 0
	if anm != "":
		var anm_data = AnmDatabase.load_anm(anm)
		var img = null
		if not anm_data.is_empty() and anm_data.get("section_a", []).is_empty() and anm_data.get("section_c", []).size() == 2:
			img = anm_renderer.render_wall(anm, p.width_1, p.height_1)
		if img == null:
			var anm_state_id = BehaviorRegistry.get_anm_state_for_counter(p.part_type, p.state_counter)
			var meta = anm_renderer.get_frame_meta(anm, anm_state_id, p.state_counter, p.width_1, p.height_1)
			off_x = meta.get("x", 0)
			off_y = meta.get("y", 0)
			img = anm_renderer.render_frame(anm, anm_state_id, p.state_counter, p.width_1, p.height_1)
		if img:
			tex = ImageTexture.create_from_image(img)
	s.set_meta("off_x", off_x)
	s.set_meta("off_y", off_y)
	if tex:
		s.texture = tex
		s.centered = false
		s.scale = Vector2.ONE
		s.flip_h = bool(p.appearance & PartData.FLAG_FLIP)
	else:
		var img = Image.create(max(p.width_1, 1), max(p.height_1, 1), false, Image.FORMAT_RGBA8)
		img.fill(Color(0.5, 0.5, 0.6, 0.7))
		tex = ImageTexture.create_from_image(img)
		s.texture = tex
		s.centered = false
		s.flip_h = bool(p.appearance & PartData.FLAG_FLIP)

func _physics_process(_delta):
	if game_state != GameState.PLAYING:
		return
	loop.tick()
	var parts = world.parts
	for i in range(parts.size()):
		var child = get_child(i)
		if child is Sprite2D:
			child.position = Vector2(parts[i].x + child.get_meta("off_x", 0), parts[i].y + child.get_meta("off_y", 0))
			var last_state = child.get_meta("last_state", -1)
			if parts[i].state_counter != last_state:
				_update_sprite(child, parts[i])
				child.set_meta("last_state", parts[i].state_counter)
	if checker:
		var result = checker.check(world)
		if result[0]:
			_on_solved()

func _on_solved():
	game_state = GameState.SOLVED
	overlay.show()
	var label = Label.new()
	label.text = "LEVEL SOLVED!"
	label.add_theme_font_size_override("font_size", 48)
	label.add_theme_color_override("font_color", Color(0.2, 1.0, 0.2))
	label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	label.anchors_preset = Control.PRESET_CENTER
	overlay.add_child(label)
