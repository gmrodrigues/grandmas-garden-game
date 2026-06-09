class_name PuzzleToolbar
extends CanvasLayer

signal tool_selected(tool: int)
signal zoom_changed(level: float)
signal play_requested
signal reset_requested

enum PuzzleTools { SELECT, ROTATE, FLIP }

var current_tool: int = PuzzleTools.SELECT

@onready var panel: PanelContainer = $ToolbarPanel
@onready var tools_hbox: HBoxContainer = $ToolbarPanel/VBox/ToolsRow
@onready var zoom_label: Label = $ToolbarPanel/VBox/ZoomRow/ZoomLabel
@onready var status_msg: Label = $ToolbarPanel/VBox/StatusMsg

var _tool_buttons: Array = []
var _zoom_level: float = 1.0

func _ready() -> void:
	_build_toolbar()
	_update_tool_buttons()

func _build_toolbar() -> void:
	var tool_names = ["SELECT (1)", "ROTATE (2)", "FLIP (3)"]
	for i in range(tool_names.size()):
		var btn = Button.new()
		btn.text = tool_names[i]
		btn.custom_minimum_size = Vector2(100, 28)
		btn.pressed.connect(_on_tool_button.bind(i))
		tools_hbox.add_child(btn)
		_tool_buttons.append(btn)

	var zoom_in_btn = Button.new()
	zoom_in_btn.text = "+"
	zoom_in_btn.custom_minimum_size = Vector2(30, 28)
	zoom_in_btn.pressed.connect(_on_zoom_in)
	$ToolbarPanel/VBox/ZoomRow/ZoomInBtn.add_child(zoom_in_btn)

	var zoom_out_btn = Button.new()
	zoom_out_btn.text = "-"
	zoom_out_btn.custom_minimum_size = Vector2(30, 28)
	zoom_out_btn.pressed.connect(_on_zoom_out)
	$ToolbarPanel/VBox/ZoomRow/ZoomOutBtn.add_child(zoom_out_btn)

	$ToolbarPanel/VBox/ActionRow/PlayBtn.pressed.connect(_on_play)
	$ToolbarPanel/VBox/ActionRow/ResetBtn.pressed.connect(_on_reset)

func _on_tool_button(tool: int) -> void:
	current_tool = tool
	_update_tool_buttons()
	tool_selected.emit(tool)

func _update_tool_buttons() -> void:
	for i in range(_tool_buttons.size()):
		_tool_buttons[i].button_pressed = (i == current_tool)

func set_tool(tool: int) -> void:
	current_tool = tool
	_update_tool_buttons()

func set_status(msg: String) -> void:
	status_msg.text = msg

func set_zoom(level: float) -> void:
	_zoom_level = level
	zoom_label.text = "%.2fx" % level

func _on_zoom_in() -> void:
	_zoom_level = mini(_zoom_level + 0.25, 4.0)
	zoom_label.text = "%.2fx" % _zoom_level
	zoom_changed.emit(_zoom_level)

func _on_zoom_out() -> void:
	_zoom_level = maxi(_zoom_level - 0.25, 0.25)
	zoom_label.text = "%.2fx" % _zoom_level
	zoom_changed.emit(_zoom_level)

func _on_play() -> void:
	play_requested.emit()

func _on_reset() -> void:
	reset_requested.emit()

func set_mode_preview() -> void:
	$ToolbarPanel/VBox/ActionRow/PlayBtn.text = "STOP"
	$ToolbarPanel/VBox/ActionRow/PlayBtn.modulate = Color(1.0, 0.3, 0.3)

func set_mode_editor() -> void:
	$ToolbarPanel/VBox/ActionRow/PlayBtn.text = "PLAY"
	$ToolbarPanel/VBox/ActionRow/PlayBtn.modulate = Color(0.3, 1.0, 0.3)