extends Control
class_name GoalBar

var goal_text: String = ""
var label: Label

func _ready():
	label = Label.new()
	label.add_theme_font_size_override("font_size", 14)
	label.add_theme_color_override("font_color", Color(1, 1, 0.8))
	label.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	label.anchors_preset = Control.PRESET_HCENTER_WIDE
	add_child(label)
	hide()

func show_goal(text: String):
	goal_text = text
	label.text = text
	show()
