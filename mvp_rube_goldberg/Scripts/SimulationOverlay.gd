class_name SimulationOverlay
extends CanvasLayer

signal play_requested
signal pause_requested
signal resume_requested
signal stop_requested
signal reset_requested
signal speed_changed(speed: float)
signal simulation_stopped

@onready var play_btn: Button = $ControlPanel/VBox/ButtonsRow/PlayBtn
@onready var pause_btn: Button = $ControlPanel/VBox/ButtonsRow/PauseBtn
@onready var stop_btn: Button = $ControlPanel/VBox/ButtonsRow/StopBtn
@onready var reset_btn: Button = $ControlPanel/VBox/ButtonsRow/ResetBtn
@onready var speed_slider: HSlider = $ControlPanel/VBox/SpeedRow/SpeedSlider
@onready var speed_label: Label = $ControlPanel/VBox/SpeedRow/SpeedLabel
@onready var state_label: Label = $ControlPanel/VBox/StateRow/StateLabel
@onready var tick_label: Label = $ControlPanel/VBox/StateRow/TickLabel
@onready var primary_check: CheckBox = $ControlPanel/VBox/ObjectivesRow/PrimaryCheck
@onready var secondary_check: CheckBox = $ControlPanel/VBox/ObjectivesRow/SecondaryCheck
@onready var result_label: Label = $ResultLabel
@onready var sim_runner: Node = $SimViewportContainer/SimulationViewport/SimulationRunner

var current_state: int = 0
var speed: float = 1.0

func _ready() -> void:
	play_btn.pressed.connect(_on_play)
	pause_btn.pressed.connect(_on_pause)
	stop_btn.pressed.connect(_on_stop)
	reset_btn.pressed.connect(_on_reset)
	speed_slider.value_changed.connect(_on_speed_changed)
	result_label.hide()

	sim_runner.state_changed.connect(_on_runner_state_changed)
	sim_runner.tick_updated.connect(_on_runner_tick_updated)
	sim_runner.objective_updated.connect(_on_runner_objectives_updated)
	sim_runner.simulation_finished.connect(_on_runner_finished)

func init(level_data: Dictionary) -> void:
	primary_check.button_pressed = false
	secondary_check.button_pressed = false
	result_label.hide()
	sim_runner.init(level_data)

func set_speed(speed: float) -> void:
	speed_slider.value = speed
	sim_runner.set_speed(speed)

func update_state(state: int) -> void:
	current_state = state
	match state:
		0: # IDLE
			state_label.text = "Estado: idle"
			play_btn.disabled = false
			pause_btn.disabled = true
			stop_btn.disabled = true
			result_label.hide()
		1: # RUNNING
			state_label.text = "Estado: running"
			play_btn.disabled = true
			pause_btn.disabled = false
			stop_btn.disabled = false
			result_label.hide()
		2: # PAUSED
			state_label.text = "Estado: paused"
			play_btn.disabled = false
			pause_btn.disabled = true
			stop_btn.disabled = false
		3: # SUCCESS
			state_label.text = "Estado: success"
			play_btn.disabled = true
			pause_btn.disabled = true
			stop_btn.disabled = false
			result_label.text = "VITÓRIA!"
			result_label.modulate = Color(0.2, 1.0, 0.2)
			result_label.show()
		4: # FAIL
			state_label.text = "Estado: fail"
			play_btn.disabled = true
			pause_btn.disabled = true
			stop_btn.disabled = false
			result_label.text = "FALHOU!"
			result_label.modulate = Color(1.0, 0.2, 0.2)
			result_label.show()

func update_tick(tick: int, max_ticks: int) -> void:
	tick_label.text = "Tick: %d/%d" % [tick, max_ticks]

func update_objectives(primary: bool, secondary: bool) -> void:
	primary_check.button_pressed = primary
	secondary_check.button_pressed = secondary

func _on_speed_changed(value: float) -> void:
	speed = value
	var label = "1x"
	if speed < 1.0:
		label = "%.1fx" % speed
	elif speed > 1.0:
		label = "%dx" % int(speed)
	speed_label.text = label
	sim_runner.set_speed(speed)

func _on_play() -> void:
	sim_runner.play()

func _on_pause() -> void:
	sim_runner.pause()

func _on_stop() -> void:
	sim_runner.stop()
	simulation_stopped.emit()

func _on_reset() -> void:
	sim_runner.reset()

func _on_runner_state_changed(state: int) -> void:
	update_state(state)

func _on_runner_tick_updated(tick: int, max_ticks: int) -> void:
	update_tick(tick, max_ticks)

func _on_runner_objectives_updated(primary: bool, secondary: bool) -> void:
	update_objectives(primary, secondary)

func _on_runner_finished(success: bool, tick_count: int, events: Array) -> void:
	pass