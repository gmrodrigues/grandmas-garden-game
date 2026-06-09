extends Node2D

const _TestPhysics = preload("res://test/tests/TestPhysics.gd")
const _TestStateMachine = preload("res://test/tests/TestStateMachine.gd")
const _TestChain = preload("res://test/tests/TestChain.gd")
const _TestEditor = preload("res://test/tests/TestEditor.gd")

var _suites: Array = []
var _suite_total: int = 0
var _suite_passed: int = 0
var _suite_failed: int = 0

func _ready() -> void:
	var is_headless = OS.has_feature("headless") or DisplayServer.get_name() == "headless"
	print("=== BDD Test Runner ===")
	print("Headless: ", is_headless)

	var physics = _TestPhysics.new()
	physics.add_physics_tests()
	_suites.append(physics)

	var sm = _TestStateMachine.new()
	sm.add_sm_tests()
	_suites.append(sm)

	var chain = _TestChain.new()
	chain.add_chain_tests()
	_suites.append(chain)

	var editor = _TestEditor.new()
	editor.add_editor_tests()
	_suites.append(editor)

	for suite in _suites:
		suite.suite_finished.connect(_on_suite_finished)
		suite.run_all(is_headless)

	if is_headless:
		_print_final_summary()
		get_tree().quit()

func _on_suite_finished(passed: int, failed: int, total: int) -> void:
	_suite_passed += passed
	_suite_failed += failed
	_suite_total += total

func _print_final_summary() -> void:
	print("\n=================================")
	print("  FINAL SUMMARY")
	print("=================================")
	print("  Tests: %d total, %d passed, %d failed" % [_suite_total, _suite_passed, _suite_failed])
	print("=================================")
	if _suite_failed == 0:
		print("  ALL SUITES PASSED")
	else:
		print("  %d SUITE(S) FAILED" % _suite_failed)