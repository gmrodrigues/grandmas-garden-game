extends Control
class_name ConditionEditorDialog

signal confirmed(conditions: Array)
signal rect_requested(cond_idx: int)

var conditions: Array = []
var condition_vbox: VBoxContainer

func _init(existing: Array = []):
	conditions = existing.duplicate()

func setup():
	var vbox = VBoxContainer.new()
	vbox.anchors_preset = Control.PRESET_FULL_RECT
	add_child(vbox)

	var header = Label.new()
	header.text = "Conditions:"
	vbox.add_child(header)

	var scroll = ScrollContainer.new()
	scroll.size_flags_vertical = Control.SIZE_EXPAND_FILL
	vbox.add_child(scroll)

	condition_vbox = VBoxContainer.new()
	condition_vbox.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	scroll.add_child(condition_vbox)
	_refresh_list()

	var add_hbox = HBoxContainer.new()
	vbox.add_child(add_hbox)

	var type_dropdown = OptionButton.new()
	type_dropdown.add_item("STATE_ONLY", 4)
	type_dropdown.add_item("POSITION", 1)
	type_dropdown.add_item("OFF_SCREEN", 2)
	add_hbox.add_child(type_dropdown)

	var part_input = SpinBox.new()
	part_input.min_value = -1
	part_input.max_value = 999
	part_input.value = -1
	add_hbox.add_child(part_input)

	var add_btn = Button.new()
	add_btn.text = "Add"
	add_btn.pressed.connect(_on_add.bind(type_dropdown, part_input))
	add_hbox.add_child(add_btn)

	var btn_hbox = HBoxContainer.new()
	btn_hbox.alignment = BoxContainer.ALIGNMENT_END
	vbox.add_child(btn_hbox)

	var ok_btn = Button.new()
	ok_btn.text = "OK"
	ok_btn.pressed.connect(_on_ok)
	btn_hbox.add_child(ok_btn)

	var cancel_btn = Button.new()
	cancel_btn.text = "Cancel"
	cancel_btn.pressed.connect(_on_cancel)
	btn_hbox.add_child(cancel_btn)

func set_condition_rect(idx: int, rect: Rect2):
	if idx >= 0 and idx < conditions.size():
		var sc = conditions[idx]
		sc.target_rect = rect
		_refresh_list()

func _refresh_list():
	for c in condition_vbox.get_children():
		c.queue_free()
	for i in range(conditions.size()):
		var sc = conditions[i]
		var hbox = HBoxContainer.new()
		var type_names = ["POSITION", "OFF_SCREEN", "OFF_TOP", "OFF_BOTTOM", "STATE_ONLY"]
		var tname = type_names[sc.type] if sc.type >= 0 and sc.type < type_names.size() else "?"
		var rect_info = ""
		if sc.type == 1:
			rect_info = " rect=(%d,%d %dx%d)" % [sc.target_rect.position.x, sc.target_rect.position.y, sc.target_rect.size.x, sc.target_rect.size.y]
		var label = Label.new()
		label.text = "[%d] %s  part=%d  state=%d%s" % [i, tname, sc.part_index, sc.target_state, rect_info]
		hbox.add_child(label)
		if sc.type == 1:
			var rect_btn = Button.new()
			rect_btn.text = "Rect"
			rect_btn.pressed.connect(func(): rect_requested.emit(i))
			hbox.add_child(rect_btn)
		var del_btn = Button.new()
		del_btn.text = "X"
		var idx = i
		del_btn.pressed.connect(func(): conditions.remove_at(idx); _refresh_list())
		hbox.add_child(del_btn)
		condition_vbox.add_child(hbox)

func _on_add(dropdown: OptionButton, part_input: SpinBox):
	var sc = SolutionCondition.new(dropdown.get_selected_id(), int(part_input.value))
	if sc.type == 1:
		sc.target_rect = Rect2(0, 0, 100, 100)
		conditions.append(sc)
		rect_requested.emit(conditions.size() - 1)
	else:
		conditions.append(sc)
	_refresh_list()

func _on_ok():
	confirmed.emit(conditions)
	queue_free()

func _on_cancel():
	queue_free()
