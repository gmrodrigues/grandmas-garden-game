class_name UndoSystem
extends RefCounted

signal history_changed(can_undo: bool, can_redo: bool)
signal action_performed(description: String)

const MAX_HISTORY: int = 50

var _undo_stack: Array = []
var _redo_stack: Array = []

enum ActionType { PART_ADDED, PART_REMOVED, PART_MOVED, PART_RESIZED, PART_PROPERTY, CONNECTION_ADDED, CONNECTION_REMOVED, LEVEL_LOADED }

class UndoAction:
	var type: int
	var description: String
	var data: Dictionary
	var timestamp: int

	func _init(t: int, desc: String, d: Dictionary):
		type = t
		description = desc
		data = d
		timestamp = Time.get_ticks_msec()

	func to_dict() -> Dictionary:
		return {
			"type": type,
			"description": description,
			"data": data,
			"timestamp": timestamp
		}

	func from_dict(d: Dictionary) -> void:
		type = d.get("type", 0)
		description = d.get("description", "")
		data = d.get("data", {})
		timestamp = d.get("timestamp", 0)

func _init():
	pass

func push_action(action: UndoAction) -> void:
	_undo_stack.append(action)
	_redo_stack.clear()
	if _undo_stack.size() > MAX_HISTORY:
		_undo_stack.pop_front()
	history_changed.emit(can_undo(), can_redo())
	action_performed.emit(action.description)

func undo() -> bool:
	if _undo_stack.is_empty():
		return false
	var action = _undo_stack.pop_back()
	var reverse = _create_reverse(action)
	_redo_stack.append(action)
	history_changed.emit(can_undo(), can_redo())
	return reverse

func redo() -> bool:
	if _redo_stack.is_empty():
		return false
	var action = _redo_stack.pop_back()
	var reverse = _create_reverse(action)
	_undo_stack.append(action)
	history_changed.emit(can_undo(), can_redo())
	return reverse

func can_undo() -> bool:
	return not _undo_stack.is_empty()

func can_redo() -> bool:
	return not _redo_stack.is_empty()

func clear() -> void:
	_undo_stack.clear()
	_redo_stack.clear()
	history_changed.emit(false, false)

func get_undo_description() -> String:
	if _undo_stack.is_empty():
		return ""
	return _undo_stack.back().description

func get_redo_description() -> String:
	if _redo_stack.is_empty():
		return ""
	return _redo_stack.back().description

func get_history_size() -> int:
	return _undo_stack.size()

func _create_reverse(action: UndoAction) -> UndoAction:
	var reverse_data = {}
	match action.type:
		ActionType.PART_ADDED:
			reverse_data = {"part_id": action.data.get("part_id", -1), "part_data": action.data.get("part_data", {})}
			return UndoAction.new(ActionType.PART_REMOVED, "Undo: " + action.description, reverse_data)
		ActionType.PART_REMOVED:
			reverse_data = {"part_data": action.data.get("part_data", {}), "index": action.data.get("index", 0)}
			return UndoAction.new(ActionType.PART_ADDED, "Undo: " + action.description, reverse_data)
		ActionType.PART_MOVED:
			reverse_data = {"part_id": action.data.get("part_id", -1), "old_x": action.data.get("new_x", 0), "old_y": action.data.get("new_y", 0), "new_x": action.data.get("old_x", 0), "new_y": action.data.get("old_y", 0)}
			return UndoAction.new(ActionType.PART_MOVED, "Undo: " + action.description, reverse_data)
		ActionType.PART_RESIZED:
			reverse_data = {"part_id": action.data.get("part_id", -1), "old_w": action.data.get("new_w", 32), "old_h": action.data.get("new_h", 32), "new_w": action.data.get("old_w", 32), "new_h": action.data.get("old_h", 32), "old_x": action.data.get("new_x", 0), "old_y": action.data.get("new_y", 0), "new_x": action.data.get("old_x", 0), "new_y": action.data.get("old_y", 0)}
			return UndoAction.new(ActionType.PART_RESIZED, "Undo: " + action.description, reverse_data)
		ActionType.PART_PROPERTY:
			reverse_data = {"part_id": action.data.get("part_id", -1), "property": action.data.get("property", ""), "old_value": action.data.get("new_value", null), "new_value": action.data.get("old_value", null)}
			return UndoAction.new(ActionType.PART_PROPERTY, "Undo: " + action.description, reverse_data)
		ActionType.CONNECTION_ADDED:
			reverse_data = {"from_id": action.data.get("from_id", -1), "to_id": action.data.get("to_id", -1), "conn_type": action.data.get("conn_type", 0)}
			return UndoAction.new(ActionType.CONNECTION_REMOVED, "Undo: " + action.description, reverse_data)
		ActionType.CONNECTION_REMOVED:
			reverse_data = {"from_id": action.data.get("from_id", -1), "to_id": action.data.get("to_id", -1), "conn_type": action.data.get("conn_type", 0)}
			return UndoAction.new(ActionType.CONNECTION_ADDED, "Undo: " + action.description, reverse_data)
	return action

func record_part_added(part_id: int, part_data: Dictionary) -> void:
	var data = {"part_id": part_id, "part_data": part_data.duplicate(true)}
	push_action(UndoAction.new(ActionType.PART_ADDED, "Add part", data))

func record_part_removed(part_data: Dictionary, index: int) -> void:
	var data = {"part_data": part_data.duplicate(true), "index": index}
	push_action(UndoAction.new(ActionType.PART_REMOVED, "Remove part", data))

func record_part_moved(part_id: int, old_x: int, old_y: int, new_x: int, new_y: int) -> void:
	var data = {"part_id": part_id, "old_x": old_x, "old_y": old_y, "new_x": new_x, "new_y": new_y}
	push_action(UndoAction.new(ActionType.PART_MOVED, "Move part", data))

func record_part_resized(part_id: int, old_x: int, old_y: int, old_w: int, old_h: int, new_x: int, new_y: int, new_w: int, new_h: int) -> void:
	var data = {"part_id": part_id, "old_x": old_x, "old_y": old_y, "old_w": old_w, "old_h": old_h, "new_x": new_x, "new_y": new_y, "new_w": new_w, "new_h": new_h}
	push_action(UndoAction.new(ActionType.PART_RESIZED, "Resize part", data))

func record_property_change(part_id: int, property: String, old_value, new_value) -> void:
	var data = {"part_id": part_id, "property": property, "old_value": old_value, "new_value": new_value}
	push_action(UndoAction.new(ActionType.PART_PROPERTY, "Change " + property, data))

func record_connection_added(from_id: int, to_id: int, conn_type: int) -> void:
	var data = {"from_id": from_id, "to_id": to_id, "conn_type": conn_type}
	push_action(UndoAction.new(ActionType.CONNECTION_ADDED, "Add connection", data))

func record_connection_removed(from_id: int, to_id: int, conn_type: int) -> void:
	var data = {"from_id": from_id, "to_id": to_id, "conn_type": conn_type}
	push_action(UndoAction.new(ActionType.CONNECTION_REMOVED, "Remove connection", data))

func get_last_action() -> UndoAction:
	if _undo_stack.is_empty():
		return null
	return _undo_stack.back()

func get_undo_stack() -> Array:
	return _undo_stack.duplicate(false)

func get_redo_stack() -> Array:
	return _redo_stack.duplicate(false)