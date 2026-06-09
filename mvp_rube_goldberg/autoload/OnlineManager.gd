extends Node

signal connection_status_changed(status: String)
signal match_found(opponent_info: Dictionary)
signal session_error(error: String)
signal workshop_item_downloaded(item_id: String, path: String)

enum ConnectionStatus { DISCONNECTED, CONNECTING, CONNECTED, ERROR }

var _status: int = ConnectionStatus.DISCONNECTED
var _player_name: String = "Player"
var _session_id: String = ""
var _workshop_items: Array = []
var _download_progress: float = 0.0

func _ready() -> void:
	print("OnlineManager ready (stub)")

func connect_to_server(endpoint: String = "") -> void:
	_status = ConnectionStatus.CONNECTING
	connection_status_changed.emit("connecting")
	print("OnlineManager: connect_to_server (stub) — endpoint: " + endpoint)
	await get_tree().create_timer(0.5).timeout
	_status = ConnectionStatus.CONNECTED
	connection_status_changed.emit("connected")

func disconnect_from_server() -> void:
	_status = ConnectionStatus.DISCONNECTED
	connection_status_changed.emit("disconnected")
	print("OnlineManager: disconnect_from_server (stub)")

func create_session(is_host: bool = true) -> String:
	_session_id = "session_%d" % (randi() % 10000)
	print("OnlineManager: create_session (stub) — " + _session_id + ", is_host=" + str(is_host))
	return _session_id

func join_session(session_id: String) -> bool:
	print("OnlineManager: join_session (stub) — " + session_id)
	return true

func leave_session() -> void:
	_session_id = ""
	print("OnlineManager: leave_session (stub)")

func find_match() -> void:
	print("OnlineManager: find_match (stub)")
	connection_status_changed.emit("searching")
	await get_tree().create_timer(1.0).timeout
	var opponent = {"name": "CPU_Player", "skill": 1200}
	match_found.emit(opponent)

func cancel_matchmaking() -> void:
	print("OnlineManager: cancel_matchmaking (stub)")
	connection_status_changed.emit("disconnected")

func send_game_event(event_type: String, data: Dictionary) -> void:
	if _status != ConnectionStatus.CONNECTED:
		return
	print("OnlineManager: send_game_event (stub) — type=" + event_type)

func set_player_name(name: String) -> void:
	_player_name = name
	print("OnlineManager: player name set to " + name)

func get_player_name() -> String:
	return _player_name

func get_connection_status() -> int:
	return _status

func get_workshop_items() -> Array:
	return _workshop_items.duplicate()

func download_workshop_item(item_id: String) -> void:
	print("OnlineManager: download_workshop_item (stub) — " + item_id)
	_download_progress = 0.0
	while _download_progress < 1.0:
		await get_tree().create_timer(0.1).timeout
		_download_progress += 0.1
	_download_progress = 1.0
	var path = "user://workshop/" + item_id + "/"
	workshop_item_downloaded.emit(item_id, path)

func cancel_download(item_id: String) -> void:
	print("OnlineManager: cancel_download (stub) — " + item_id)

func upload_level(path: String, metadata: Dictionary) -> bool:
	print("OnlineManager: upload_level (stub) — " + path)
	return true

func get_online_players() -> Array:
	return [{"name": _player_name, "status": "online"}]

func is_online() -> bool:
	return _status == ConnectionStatus.CONNECTED