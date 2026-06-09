extends Control

signal settings_closed

var _sfx_slider: HSlider
var _music_slider: HSlider
var _mute_checkbox: CheckBox

func _ready() -> void:
	_build_settings_ui()

func _build_settings_ui() -> void:
	var vbox = VBoxContainer.new()
	vbox.alignment = BoxContainer.ALIGNMENT_CENTER
	add_child(vbox)
	vbox.layout_mode = 1
	vbox.anchors_preset = 8
	vbox.anchor_left = 0.5
	vbox.anchor_top = 0.5
	vbox.anchor_right = 0.5
	vbox.anchor_bottom = 0.5
	vbox.offset_left = -200.0
	vbox.offset_top = -150.0
	vbox.offset_right = 200.0
	vbox.offset_bottom = 150.0
	vbox.grow_horizontal = 2
	vbox.grow_vertical = 2

	var title = Label.new()
	title.text = "SETTINGS"
	title.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	vbox.add_child(title)

	var sfx_row = HBoxContainer.new()
	var sfx_label = Label.new()
	sfx_label.text = "SFX Volume:"
	sfx_row.add_child(sfx_label)
	_sfx_slider = HSlider.new()
	_sfx_slider.min_value = 0.0
	_sfx_slider.max_value = 1.0
	_sfx_slider.step = 0.1
	_sfx_slider.value = 1.0
	_sfx_slider.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	_sfx_slider.value_changed.connect(_on_sfx_volume_changed)
	sfx_row.add_child(_sfx_slider)
	vbox.add_child(sfx_row)

	var music_row = HBoxContainer.new()
	var music_label = Label.new()
	music_label.text = "Music Volume:"
	music_row.add_child(music_label)
	_music_slider = HSlider.new()
	_music_slider.min_value = 0.0
	_music_slider.max_value = 1.0
	_music_slider.step = 0.1
	_music_slider.value = 0.7
	_music_slider.size_flags_horizontal = Control.SIZE_EXPAND_FILL
	_music_slider.value_changed.connect(_on_music_volume_changed)
	music_row.add_child(_music_slider)
	vbox.add_child(music_row)

	var mute_row = HBoxContainer.new()
	_mute_checkbox = CheckBox.new()
	_mute_checkbox.text = "Mute All Audio"
	_mute_checkbox.toggled.connect(_on_mute_toggled)
	mute_row.add_child(_mute_checkbox)
	vbox.add_child(mute_row)

	var back_btn = Button.new()
	back_btn.text = "BACK"
	back_btn.pressed.connect(_on_back_pressed)
	vbox.add_child(back_btn)

	var audio = get_node_or_null("/root/AudioManager")
	if audio != null:
		_sfx_slider.value = audio._volume_sfx
		_music_slider.value = audio._volume_music
		_mute_checkbox.button_pressed = audio._muted

func _on_sfx_volume_changed(value: float) -> void:
	var audio = get_node_or_null("/root/AudioManager")
	if audio != null:
		audio.set_sfx_volume(value)

func _on_music_volume_changed(value: float) -> void:
	var audio = get_node_or_null("/root/AudioManager")
	if audio != null:
		audio.set_music_volume(value)

func _on_mute_toggled(pressed: bool) -> void:
	var audio = get_node_or_null("/root/AudioManager")
	if audio != null:
		audio.set_muted(pressed)

func _on_back_pressed() -> void:
	settings_closed.emit()