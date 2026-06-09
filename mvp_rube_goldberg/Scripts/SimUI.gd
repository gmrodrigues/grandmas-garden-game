class_name SimUI
extends CanvasLayer

signal speed_changed(speed_mult: float)
signal reset_requested
signal stop_requested
signal play_requested

@onready var play_btn: Button = $VBox/HBoxBtns/PlayBtn
@onready var stop_btn: Button = $VBox/HBoxBtns/StopBtn
@onready var reset_btn: Button = $VBox/HBoxBtns/ResetBtn
@onready var speed_slider: HSlider = $VBox/SpeedRow/SpeedSlider
@onready var speed_label: Label = $VBox/SpeedRow/SpeedLabel
@onready var goal_label: Label = $VBox/GoalLabel
@onready var tick_label: Label = $VBox/TickLabel

var speed_mult: float = 1.0
var running: bool = false

func _ready() -> void:
	_play_state(false)
	_update_speed_label()
	goal_label.text = ""
	play_btn.pressed.connect(_on_play_pressed)
	stop_btn.pressed.connect(_on_stop_pressed)
	reset_btn.pressed.connect(_on_reset_pressed)
	speed_slider.value_changed.connect(_on_speed_slider_value_changed)

func _on_play_pressed() -> void:
	_play_state(true)
	play_requested.emit()

func _on_stop_pressed() -> void:
	stop_requested.emit()

func _on_reset_pressed() -> void:
	reset_requested.emit()

func _play_state(is_running: bool) -> void:
	running = is_running
	play_btn.disabled = is_running
	stop_btn.disabled = not is_running

func set_running(is_running: bool) -> void:
	_play_state(is_running)

func _on_speed_slider_value_changed(value: float) -> void:
	speed_mult = value
	_update_speed_label()
	speed_changed.emit(speed_mult)

func _update_speed_label() -> void:
	var label = "1x"
	if speed_mult < 1.0:
		label = "%.1fx" % speed_mult
	elif speed_mult > 1.0:
		label = "%dx" % int(speed_mult)
	speed_label.text = label

func update_tick(tick: int) -> void:
	tick_label.text = "Tick: %d" % tick

func set_goal(text: String) -> void:
	goal_label.text = text