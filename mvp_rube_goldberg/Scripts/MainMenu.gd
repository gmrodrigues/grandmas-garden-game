extends Control

signal start_game_requested
signal level_select_requested
signal settings_requested
signal quit_requested

var _menu_buttons: Array = []
var _selected_index: int = 0

@onready var vbox: VBoxContainer = $MenuVBox
@onready var title_label: Label = $MenuVBox/TitleLabel
@onready var buttons_container: VBoxContainer = $MenuVBox/ButtonsContainer

func _ready() -> void:
	_build_menu()
	_update_selection()

func _build_menu() -> void:
	var menu_items = [
		{"label": "START GAME", "action": "start_game"},
		{"label": "LEVEL SELECT", "action": "level_select"},
		{"label": "SETTINGS", "action": "settings"},
		{"label": "QUIT", "action": "quit"},
	]
	for item in menu_items:
		var btn = Button.new()
		btn.text = item["label"]
		btn.custom_minimum_size = Vector2(300, 48)
		btn.pressed.connect(_on_menu_button.bind(item["action"]))
		btn.focus_mode = Control.FOCUS_ALL
		buttons_container.add_child(btn)
		_menu_buttons.append(btn)

func _on_menu_button(action: String) -> void:
	match action:
		"start_game":
			start_game_requested.emit()
		"level_select":
			level_select_requested.emit()
		"settings":
			settings_requested.emit()
		"quit":
			get_tree().quit()

func _input(event: InputEvent) -> void:
	if event is InputEventKey and event.pressed:
		match event.keycode:
			KEY_UP:
				_selected_index = (_selected_index - 1 + _menu_buttons.size()) % _menu_buttons.size()
				_update_selection()
			KEY_DOWN:
				_selected_index = (_selected_index + 1) % _menu_buttons.size()
				_update_selection()
			KEY_ENTER, KEY_SPACE:
				if _menu_buttons.size() > _selected_index:
					_menu_buttons[_selected_index].pressed.emit()

func _update_selection() -> void:
	for i in range(_menu_buttons.size()):
		var btn = _menu_buttons[i]
		if i == _selected_index:
			btn.add_theme_color_override("font_color", Color(1, 0.8, 0.2))
			btn.add_theme_color_override("font_hover_color", Color(1, 1, 0.4))
		else:
			btn.add_theme_color_override("font_color", Color(0.7, 0.7, 0.7))
			btn.add_theme_color_override("font_hover_color", Color(0.9, 0.9, 0.9))