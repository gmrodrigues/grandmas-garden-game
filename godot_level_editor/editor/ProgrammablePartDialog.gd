extends Window
class_name ProgrammablePartDialog

signal confirmed(data: Dictionary)
signal cancelled()

var fields: Dictionary = {}

func _init():
	title = "Programmable Ball Properties"
	min_size = Vector2i(320, 260)
	size = Vector2i(320, 260)
	exclusive = true

func setup(density: int, elasticity: int, friction: int, buoyancy: int):
	var vbox = VBoxContainer.new()
	add_child(vbox)

	var grid = GridContainer.new()
	grid.columns = 2
	grid.add_theme_constant_override("h_separation", 8)
	grid.add_theme_constant_override("v_separation", 6)
	vbox.add_child(grid)

	var entries = {
		"density": str(density),
		"elasticity": str(elasticity),
		"friction": str(friction),
		"gravity_buoyancy": str(buoyancy),
	}
	for key in entries:
		var label = Label.new()
		label.text = key.capitalize() + ":"
		grid.add_child(label)
		var line = LineEdit.new()
		line.text = entries[key]
		grid.add_child(line)
		fields[key] = line

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

func _on_ok():
	var data = {}
	for key in fields:
		var t = fields[key].text.strip_edges()
		data[key] = int(t) if t.is_valid_int() else 0
	confirmed.emit(data)
	queue_free()

func _on_cancel():
	cancelled.emit()
	queue_free()
