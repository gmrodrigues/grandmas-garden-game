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
	for d in data.get("parts", []):
		var pd = PartData.new(d.get("part_type", 0), d.get("x", 0), d.get("y", 0))
		pd.width_1 = d.get("width_1", 32)
		pd.height_1 = d.get("height_1", 32)
		pd.width_2 = d.get("width_2", 32)
		pd.height_2 = d.get("height_2", 32)
		pd.appearance = d.get("appearance", 0)
		world.add_part(pd)
	_spawn_sprites()
	game_state = GameState.PLAYING

func _spawn_sprites():
	for child in get_children():
		if child is Sprite2D:
			child.queue_free()
	for p in world.parts:
		var s = Sprite2D.new()
		s.position = Vector2(p.x, p.y)
		add_child(s)
		_update_sprite(s, p)

func _update_sprite(s: Sprite2D, p: PartData):
	var tex = null
	var anm = AnmDatabase.get_anm_for_part(p.part_type)
	if anm != "":
		var img = anm_renderer.render_frame(anm, AnmDatabase.get_default_state_id(anm), p.state_counter, p.width_1, p.height_1)
		if img:
			if p.appearance & 0x8000: img.flip_x()
			tex = ImageTexture.create_from_image(img)
	if tex:
		s.texture = tex
		s.centered = false
		s.scale = Vector2.ONE
	else:
		var img = Image.create(max(p.width_1, 1), max(p.height_1, 1), false, Image.FORMAT_RGBA8)
		img.fill(Color(0.5, 0.5, 0.6, 0.7))
		tex = ImageTexture.create_from_image(img)
		s.texture = tex
		s.centered = false

func _physics_process(_delta):
	if game_state != GameState.PLAYING:
		return
	loop.tick()
	for i in range(world.parts.size()):
		var child = get_child(i)
		if child is Sprite2D:
			child.position = Vector2(world.parts[i].x, world.parts[i].y)
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
