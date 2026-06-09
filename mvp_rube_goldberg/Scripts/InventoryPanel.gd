class_name InventoryPanel
extends PanelContainer

signal part_spawned(part_type: int, x: int, y: int)
signal inventory_updated(counts: Dictionary)

const _PartData = preload("res://Scripts/PartData.gd")

var _counts: Dictionary = {}
var _catalog: Array = []
var _part_buttons: Array = []
var _grid: GridContainer

var _drag_part_type: int = -1
var _drag_label: Label = null

func _ready() -> void:
	_grid = GridContainer.new()
	_grid.columns = 4
	_grid.add_theme_constant_override("h_separation", 4)
	_grid.add_theme_constant_override("v_separation", 4)
	var scroll = ScrollContainer.new()
	scroll.set_deferred("scroll_horizontal_custom_minimum_size", 200)
	var vbox = VBoxContainer.new()
	scroll.add_child(vbox)
	vbox.add_child(_grid)
	var label = Label.new()
	label.text = "INVENTORY"
	label.horizontal_alignment = 1
	vbox.add_child(label)
	add_child(scroll)
	_catalog = _load_catalog()
	_build_inventory_ui()

func _load_catalog() -> Array:
	var path = "res://data/part-name-catalog.json"
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		return []
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed is Array:
		return parsed
	return []

func setup(inventory: Array, counts: Dictionary) -> void:
	_counts = counts.duplicate()
	_build_inventory_ui()
	inventory_updated.emit(_counts)

func update_counts(counts: Dictionary) -> void:
	_counts = counts.duplicate()
	_refresh_buttons()

func _build_inventory_ui() -> void:
	for child in _grid.get_children():
		_grid.remove_child(child)
		child.queue_free()
	_part_buttons.clear()

	for pt in _counts.keys():
		var count = _counts[pt]
		if count <= 0:
			continue
		var entry = _get_catalog_entry(pt)
		var name = entry.get("name", "Type" + str(pt))
		var btn = _create_inventory_button(pt, name, count)
		_grid.add_child(btn)
		_part_buttons.append({"button": btn, "part_type": pt})

func _create_inventory_button(part_type: int, name: String, count: int) -> Button:
	var btn = Button.new()
	btn.custom_minimum_size = Vector2(80, 60)
	var lbl = Label.new()
	lbl.text = name.substr(0, 6) + "\n[x%d]" % count
	lbl.horizontal_alignment = 1
	lbl.vertical_alignment = 1
	lbl.autowrap_mode = TextServer.AUTOWRAP_WORD
	btn.add_child(lbl)
	lbl.set_anchors_and_offsets_preset(Control.PRESET_FULL_RECT)
	lbl.set("theme_override_font_sizes/font_size", 9)
	btn.pressed.connect(_on_inventory_button_pressed.bind(part_type))

	var drag = InputEventMouseButton.new()
	drag.button_index = MOUSE_BUTTON_LEFT
	btn.gui_input.connect(_on_inventory_button_drag.bind(part_type, btn))
	return btn

var _dragging_pt: int = -1
var _drag_preview: Control = null

func _on_inventory_button_pressed(part_type: int) -> void:
	pass

func _on_inventory_button_drag(event: InputEvent, part_type: int, btn: Button) -> void:
	if event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_LEFT and event.pressed:
			_dragging_pt = part_type
			_create_drag_preview(btn)
		elif event.button_index == MOUSE_BUTTON_LEFT and not event.pressed:
			if _drag_preview != null:
				var pos = get_viewport().get_mouse_position()
				part_spawned.emit(_dragging_pt, int(pos.x), int(pos.y))
				_dragging_pt = -1
				_free_drag_preview()

func _create_drag_preview(src: Control) -> void:
	_drag_preview = PanelContainer.new()
	var lbl = Label.new()
	lbl.text = "P%d" % _dragging_pt
	_drag_preview.add_child(lbl)
	_drag_preview.custom_minimum_size = Vector2(32, 32)
	get_tree().get_root().add_child(_drag_preview)
	_update_drag_preview_position(get_viewport().get_mouse_position())

func _update_drag_preview_position(pos: Vector2) -> void:
	if _drag_preview:
		_drag_preview.global_position = pos - Vector2(16, 16)

func _free_drag_preview() -> void:
	if _drag_preview:
		_drag_preview.queue_free()
		_drag_preview = null

func _process(_delta: float) -> void:
	if _dragging_pt >= 0 and _drag_preview:
		_update_drag_preview_position(get_viewport().get_mouse_position())

func _refresh_buttons() -> void:
	for entry in _part_buttons:
		var btn = entry["button"]
		var pt = entry["part_type"]
		var count = _counts.get(pt, 0)
		var lbl = btn.get_child(0) as Label
		if lbl:
			var catalog_entry = _get_catalog_entry(pt)
			var name = catalog_entry.get("name", "T%d" % pt)
			lbl.text = name.substr(0, 6) + "\n[x%d]" % count

func _get_catalog_entry(part_type: int) -> Dictionary:
	for entry in _catalog:
		if int(entry.get("part_type", -1)) == part_type:
			return entry
	return {}