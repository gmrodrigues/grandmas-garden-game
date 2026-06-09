class_name WorldState
extends RefCounted

signal part_added(part_data: PartData)
signal part_removed(part_data: PartData)
signal part_changed(part_data: PartData, field: String)
signal selection_changed(selected: Array)
signal connection_added(from_id: int, to_id: int, conn_type: int)
signal connections_changed

const MAX_PARTS: int = 32
const _UndoSystem = preload("res://Scripts/UndoSystem.gd")

var parts_data: Array = []
var gravity_x: int = 0
var gravity_y: int = 0x1400
var air_pressure: int = 0
var viewport_width: int = 640
var viewport_height: int = 480

var _undo_system: RefCounted = null
var _selected_parts: Array = []
var _connections: Array = []
var _next_id: int = 0
var _is_recording: bool = true

func _init():
	parts_data = []
	_connections = []
	_undo_system = _UndoSystem.new()

func get_undo_system() -> RefCounted:
	return _undo_system

func set_recording(recording: bool) -> void:
	_is_recording = recording

func add_part(p: PartData) -> int:
	if parts_data.size() >= MAX_PARTS:
		return -1
	p.id = _next_id
	_next_id += 1
	parts_data.append(p)
	p.changed.connect(_on_part_changed)
	if _is_recording and _undo_system:
		_undo_system.record_part_added(p.id, p.to_dict())
	part_added.emit(p)
	return p.id

func remove_part(part_data: PartData) -> void:
	var idx = parts_data.find(part_data)
	if idx < 0:
		return
	var part_dict = part_data.to_dict()
	parts_data.remove_at(idx)
	deselect_part(part_data)
	_remove_connections_for(part_data.id)
	if _is_recording and _undo_system:
		_undo_system.record_part_removed(part_dict, idx)
	part_removed.emit(part_data)

func get_part(id: int) -> PartData:
	for p in parts_data:
		if p.id == id:
			return p
	return null

func find_part_at(x: int, y: int) -> PartData:
	for i in range(parts_data.size() - 1, -1, -1):
		if parts_data[i].hit_test(x, y):
			return parts_data[i]
	return null

func find_handle_at(x: int, y: int) -> Dictionary:
	for p in parts_data:
		if p.is_selected:
			var h = p.hit_test_handle(x, y)
			if h >= 0:
				return {"part": p, "handle": h}
	return {}

func get_selected() -> Array:
	return _selected_parts.duplicate()

func select_part(part_data: PartData, add_to_selection: bool = false) -> void:
	if not add_to_selection:
		deselect_all()
	if not _selected_parts.has(part_data):
		_selected_parts.append(part_data)
		part_data.is_selected = true
		selection_changed.emit(_selected_parts)

func deselect_part(part_data: PartData) -> void:
	_selected_parts.erase(part_data)
	part_data.is_selected = false
	selection_changed.emit(_selected_parts)

func deselect_all() -> void:
	for p in _selected_parts:
		p.is_selected = false
	_selected_parts.clear()
	selection_changed.emit(_selected_parts)

func has_selection() -> bool:
	return not _selected_parts.is_empty()

func get_part_count() -> int:
	return parts_data.size()

func add_connection(from_id: int, to_id: int, conn_type: int) -> void:
	if from_id == to_id:
		return
	for c in _connections:
		if c[0] == from_id and c[1] == to_id and c[2] == conn_type:
			return
	_connections.append([from_id, to_id, conn_type])
	if _is_recording and _undo_system:
		_undo_system.record_connection_added(from_id, to_id, conn_type)
	connections_changed.emit()
	connection_added.emit(from_id, to_id, conn_type)

func remove_connection(from_id: int, to_id: int, conn_type: int) -> void:
	for i in range(_connections.size() - 1, -1, -1):
		var c = _connections[i]
		if c[0] == from_id and c[1] == to_id and c[2] == conn_type:
			if _is_recording and _undo_system:
				_undo_system.record_connection_removed(from_id, to_id, conn_type)
			_connections.remove_at(i)
	connections_changed.emit()

func get_connections() -> Array:
	return _connections.duplicate()

func has_connection(from_id: int, to_id: int, conn_type: int = -1) -> bool:
	for c in _connections:
		if c[0] == from_id and c[1] == to_id:
			if conn_type < 0 or c[2] == conn_type:
				return true
	return false

func get_outgoing_connections(from_id: int) -> Array:
	var result = []
	for c in _connections:
		if c[0] == from_id:
			result.append(c)
	return result

func get_incoming_connections_list(to_id: int) -> Array:
	var result = []
	for c in _connections:
		if c[1] == to_id:
			result.append(c)
	return result

func clear() -> void:
	for p in parts_data:
		p.changed.disconnect(_on_part_changed)
	parts_data.clear()
	_selected_parts.clear()
	_connections.clear()
	_next_id = 0

func to_level_data() -> Dictionary:
	var parts_list = []
	for p in parts_data:
		parts_list.append(p.to_dict())
	return {
		"parts": parts_list,
		"connections": _connections.duplicate(),
		"physics": {
			"gravity_x": gravity_x,
			"gravity_y": gravity_y,
			"air_pressure": air_pressure
		},
		"viewport": {
			"width": viewport_width,
			"height": viewport_height
		}
	}

func from_level_data(data: Dictionary) -> void:
	clear()
	var physics = data.get("physics", {})
	gravity_x = physics.get("gravity_x", 0)
	gravity_y = physics.get("gravity_y", 0x1400)
	air_pressure = physics.get("air_pressure", 0)
	var vp = data.get("viewport", {})
	viewport_width = vp.get("width", 640)
	viewport_height = vp.get("height", 480)
	var parts_list = data.get("parts", [])
	for pd in parts_list:
		var part_data = PartData.new()
		part_data.from_dict(pd)
		add_part(part_data)
	var conns = data.get("connections", [])
	for c in conns:
		if c.size() >= 3:
			add_connection(c[0], c[1], c[2])

func _on_part_changed(part_data: PartData, field: String) -> void:
	part_changed.emit(part_data, field)

func _remove_connections_for(part_id: int) -> void:
	for i in range(_connections.size() - 1, -1, -1):
		var c = _connections[i]
		if c[0] == part_id or c[1] == part_id:
			_connections.remove_at(i)
	connections_changed.emit()

func create_part_at(type_val: int, x_val: int, y_val: int) -> PartData:
	var p = PartData.new(_next_id, type_val, x_val, y_val)
	_next_id += 1
	parts_data.append(p)
	p.changed.connect(_on_part_changed)
	if _is_recording and _undo_system:
		_undo_system.record_part_added(p.id, p.to_dict())
	part_added.emit(p)
	return p

func record_part_moved(part_id: int, old_x: int, old_y: int, new_x: int, new_y: int) -> void:
	if _is_recording and _undo_system:
		_undo_system.record_part_moved(part_id, old_x, old_y, new_x, new_y)

func record_part_resized(part_id: int, old_x: int, old_y: int, old_w: int, old_h: int, new_x: int, new_y: int, new_w: int, new_h: int) -> void:
	if _is_recording and _undo_system:
		_undo_system.record_part_resized(part_id, old_x, old_y, old_w, old_h, new_x, new_y, new_w, new_h)

func record_property_change(part_id: int, property: String, old_value, new_value) -> void:
	if _is_recording and _undo_system:
		_undo_system.record_property_change(part_id, property, old_value, new_value)

func undo() -> bool:
	if _undo_system == null:
		return false
	return _undo_system.undo()

func redo() -> bool:
	if _undo_system == null:
		return false
	return _undo_system.redo()

func can_undo() -> bool:
	if _undo_system == null:
		return false
	return _undo_system.can_undo()

func can_redo() -> bool:
	if _undo_system == null:
		return false
	return _undo_system.can_redo()