extends Control

signal level_selected(level_path: String)
signal back_requested

var _level_buttons: Array = []
var _level_data: Array = []

func _ready() -> void:
	_load_levels()
	_build_level_select_ui()

func _load_levels() -> void:
	var levels_dir = "res://data/levels/"
	var dir = DirAccess.open(levels_dir)
	if dir == null:
		push_warning("LevelSelect: Could not open " + levels_dir)
		return
	dir.list_dir_begin()
	var file_name = dir.get_next()
	while file_name != "":
		if file_name.ends_with(".json") or file_name.ends_with(".yaml"):
			_level_data.append({"name": file_name.trim_suffix(".json").trim_suffix(".yaml"), "path": levels_dir + file_name})
		file_name = dir.get_next()

func _build_level_select_ui() -> void:
	var scroll = ScrollContainer.new()
	scroll.set_fit_content_horizontal(true)
	scroll.set_fit_content_vertical(true)
	add_child(scroll)
	scroll.layout_mode = 1
	scroll.anchors_preset = 15
	scroll.anchor_right = 1.0
	scroll.anchor_bottom = 1.0
	scroll.grow_horizontal = 2
	scroll.grow_vertical = 2

	var vbox = VBoxContainer.new()
	vbox.alignment = BoxContainer.ALIGNMENT_CENTER
	scroll.add_child(vbox)

	var title = Label.new()
	title.text = "SELECT LEVEL"
	title.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	vbox.add_child(title)

	var grid = GridContainer.new()
	grid.columns = 4
	vbox.add_child(grid)

	for level in _level_data:
		var btn = Button.new()
		btn.text = level["name"]
		btn.custom_minimum_size = Vector2(150, 60)
		btn.pressed.connect(_on_level_button.bind(level["path"]))
		grid.add_child(btn)
		_level_buttons.append(btn)

	var back_btn = Button.new()
	back_btn.text = "BACK"
	back_btn.pressed.connect(_on_back_pressed)
	vbox.add_child(back_btn)

func _on_level_button(path: String) -> void:
	level_selected.emit(path)

func _on_back_pressed() -> void:
	back_requested.emit()