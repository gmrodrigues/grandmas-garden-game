extends ColorRect
class_name SolveOverlay

var label: Label
var timer: float = 3.0

func _ready():
	color = Color(0, 0, 0, 0.6)
	mouse_filter = Control.MOUSE_FILTER_STOP
	label = Label.new()
	label.text = "LEVEL SOLVED!"
	label.add_theme_font_size_override("font_size", 48)
	label.add_theme_color_override("font_color", Color(0.2, 1.0, 0.2))
	label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	label.vertical_alignment = VERTICAL_ALIGNMENT_CENTER
	label.anchors_preset = Control.PRESET_FULL_RECT
	add_child(label)
	hide()

func show_win():
	show()
	set_process(true)

func _process(delta):
	timer -= delta
	if timer <= 0:
		hide()
		set_process(false)
