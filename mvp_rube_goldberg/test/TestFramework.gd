class_name TestFramework
extends Node

signal test_started(name: String)
signal test_passed(name: String)
signal test_failed(name: String, reason: String)
signal suite_finished(passed: int, failed: int, total: int)

var _tests: Array = []
var _passed: int = 0
var _failed: int = 0
var _assertion_count: int = 0
var _current_failed: bool = false
var _current_error: String = ""

func add_test(test_func: Callable, name: String) -> void:
	_tests.append({"func": test_func, "name": name})

func run_all(headless: bool = false) -> void:
	_passed = 0
	_failed = 0
	_assertion_count = 0
	var total = _tests.size()
	print("\n=== Running %d test(s) ===\n" % total)
	for test in _tests:
		_run_single(test, headless)
	suite_finished.emit(_passed, _failed, total)
	if headless:
		_print_summary()

func _run_single(test: Dictionary, headless: bool = false) -> void:
	test_started.emit(test.name)
	_current_failed = false
	_current_error = ""
	print("  TEST: ", test.name)
	test.func.call()
	if _current_failed:
		_failed += 1
		test_failed.emit(test.name, _current_error)
		print("    FAIL: ", _current_error)
	else:
		_passed += 1
		test_passed.emit(test.name)
		print("    PASS")

func assert_eq(got, expected, msg: String = "") -> bool:
	_assertion_count += 1
	if got != expected:
		_current_failed = true
		_current_error = "expected %s, got %s" % [str(expected), str(got)]
		if msg != "":
			_current_error += " — " + msg
		return false
	return true

func assert_ne(got, not_expected, msg: String = "") -> bool:
	_assertion_count += 1
	if got == not_expected:
		_current_failed = true
		_current_error = "got unexpected %s" % [str(got)]
		if msg != "":
			_current_error += " — " + msg
		return false
	return true

func assert_true(val, msg: String = "") -> bool:
	return assert_eq(val, true, msg)

func assert_false(val, msg: String = "") -> bool:
	return assert_eq(val, false, msg)

func assert_in_range(val, lo, hi, msg: String = "") -> bool:
	_assertion_count += 1
	if val < lo or val > hi:
		_current_failed = true
		_current_error = "%s outside [%s, %s]" % [str(val), str(lo), str(hi)]
		if msg != "":
			_current_error += " — " + msg
		return false
	return true

func assert_not_null(val, msg: String = "") -> bool:
	return assert_ne(val, null, msg)

func fail(msg: String) -> void:
	_current_failed = true
	_current_error = msg

func _print_summary() -> void:
	print("\n================================")
	print("  Tests: %d total, %d passed, %d failed" % [_tests.size(), _passed, _failed])
	print("  Assertions: %d" % [_assertion_count])
	print("================================")
	if _failed == 0:
		print("  ALL TESTS PASSED")
	else:
		print("  %d TEST(S) FAILED" % _failed)

func get_passed() -> int:
	return _passed

func get_failed() -> int:
	return _failed

func get_total() -> int:
	return _tests.size()