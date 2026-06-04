extends Window
class_name LevelInfoDialog

signal confirmed(data: Dictionary)
signal cancelled()

var fields: Dictionary = {}
var focus_idx: int = 0
var field_keys: Array = []

func _init():
	title = "Level Info"
	min_size = Vector2i(460, 340)
	size = Vector2i(460, 340)
	exclusive = true

func setup(title_str: String, goal: String, bg_color: int, pressure: int, gravity: int, music_track: int):
	var vbox = VBoxContainer.new()
	add_child(vbox)

	var grid = GridContainer.new()
	grid.columns = 2
	grid.add_theme_constant_override("h_separation", 10)
	grid.add_theme_constant_override("v_separation", 6)
	vbox.add_child(grid)

	var entries = {
		"title": title_str,
		"goal": goal,
		"bg_color": str(bg_color),
		"pressure": str(pressure),
		"gravity": str(gravity),
		"music_track": str(music_track),
	}
	field_keys = ["title", "goal", "bg_color", "pressure", "gravity", "music_track"]

	for key in field_keys:
		var label = Label.new()
		label.text = key.capitalize() + ":"
		grid.add_child(label)
		var line = LineEdit.new()
		line.text = entries[key]
		grid.add_child(line)
		fields[key] = line
		if key in ["bg_color", "pressure", "gravity", "music_track"]:
			line.text_changed.connect(func(t): _validate_int(line))

	var hbox = HBoxContainer.new()
	hbox.alignment = BoxContainer.ALIGNMENT_END
	vbox.add_child(hbox)

	var ok_btn = Button.new()
	ok_btn.text = "OK"
	ok_btn.pressed.connect(_on_ok)
	hbox.add_child(ok_btn)

	var cancel_btn = Button.new()
	cancel_btn.text = "Cancel"
	cancel_btn.pressed.connect(_on_cancel)
	hbox.add_child(cancel_btn)

func _validate_int(line: LineEdit):
	var t = line.text.strip_edges()
	if t.is_empty(): return
	if not t.is_valid_int():
		var filtered = ""
		for c in t:
			if c in "-0123456789":
				filtered += c
		line.text = filtered

func _on_ok():
	var data = {}
	for key in field_keys:
		var val = fields[key].text.strip_edges()
		if key in ["bg_color", "pressure", "gravity", "music_track"]:
			data[key] = int(val) if val.is_valid_int() else 0
		else:
			data[key] = val
	confirmed.emit(data)
	queue_free()

func _on_cancel():
	cancelled.emit()
	queue_free()
