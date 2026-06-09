extends Node

signal sfx_played(sound_id: int, sound_type: String)
signal music_started(track_id: int)
signal music_stopped

const FM_SOUND_ID_MIN: int = 5
const FM_SOUND_ID_MAX: int = 205
const PCM_SOUND_ID_MIN: int = 3001
const PCM_SOUND_ID_MAX: int = 3754

enum SoundType { FM, PCM, UNKNOWN }

var _sfx_players: Array = []
var _music_player: AudioStreamPlayer = null
var _loaded_samples: Dictionary = {}
var _sound_names: Dictionary = {}
var _volume_sfx: float = 1.0
var _volume_music: float = 0.7
var _muted: bool = false

func _ready() -> void:
	_load_sound_names()
	print("AudioManager ready: ", _sound_names.size(), " named sounds")

func _load_sound_names() -> void:
	var path = "res://data/audio-sound-names.json"
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		return
	var text = f.get_as_text()
	f.close()
	var parsed = JSON.parse_string(text)
	if parsed is Dictionary:
		_sound_names = parsed

func play_sfx(sound_id: int, volume: float = 1.0) -> void:
	if _muted:
		return
	var sound_type = _get_sound_type(sound_id)
	match sound_type:
		SoundType.FM:
			_play_fm_sound(sound_id, volume)
		SoundType.PCM:
			_play_pcm_sound(sound_id, volume)
		_:
			push_warning("AudioManager: Unknown sound ID %d" % sound_id)
	sfx_played.emit(sound_id, _sound_type_name(sound_type))

func _get_sound_type(sound_id: int) -> int:
	if sound_id >= PCM_SOUND_ID_MIN and sound_id <= PCM_SOUND_ID_MAX:
		return SoundType.PCM
	if sound_id >= FM_SOUND_ID_MIN and sound_id <= FM_SOUND_ID_MAX:
		return SoundType.FM
	return SoundType.UNKNOWN

func _sound_type_name(t: int) -> String:
	match t:
		SoundType.FM: return "FM"
		SoundType.PCM: return "PCM"
	return "UNKNOWN"

func _play_fm_sound(sound_id: int, volume: float) -> void:
	var name = _sound_names.get(str(sound_id), "sfx_%d" % sound_id)
	print("AudioManager: Play FM sound %d (%s) at volume %.2f" % [sound_id, name, volume])

func _play_pcm_sound(sound_id: int, volume: float) -> void:
	var raw_path = _get_raw_file_path(sound_id)
	if raw_path == "":
		push_warning("AudioManager: RAW file not found for sound %d" % sound_id)
		return
	if not _loaded_samples.has(sound_id):
		var sample = _load_raw_sample(raw_path)
		if sample != null:
			_loaded_samples[sound_id] = sample
	var sample_data = _loaded_samples.get(sound_id)
	if sample_data == null:
		return
	var player = _get_available_player()
	if player != null:
		player.volume_db = linear_to_db(volume * _volume_sfx)
		player.play()

func _get_raw_file_path(sound_id: int) -> String:
	var base_dirs = [
		"res://data/audio/",
		"res://sfx/",
	]
	for base in base_dirs:
		var path = base + "SX_%d.RAW" % sound_id
		if FileAccess.file_exists(path):
			return path
	return ""

func _load_raw_sample(path: String) -> AudioStreamWAV:
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		return null
	var bytes = f.get_buffer(f.get_length())
	f.close()
	var stream = AudioStreamWAV.new()
	stream.format = 0
	stream.mix_rate = 11025
	stream.data = bytes
	return stream

func _get_available_player() -> AudioStreamPlayer:
	for p in _sfx_players:
		if not p.playing:
			return p
	if _sfx_players.size() < 8:
		var new_player = AudioStreamPlayer.new()
		new_player.bus = "Master"
		add_child(new_player)
		_sfx_players.append(new_player)
		return new_player
	return null

func play_music(track_id: int, loop: bool = true) -> void:
	if _muted:
		return
	print("AudioManager: Play music track %d, loop=%s" % [track_id, loop])
	music_started.emit(track_id)

func stop_music() -> void:
	if _music_player != null:
		_music_player.stop()
	music_stopped.emit()

func set_sfx_volume(vol: float) -> void:
	_volume_sfx = clamp(vol, 0.0, 1.0)

func set_music_volume(vol: float) -> void:
	_volume_music = clamp(vol, 0.0, 1.0)

func set_muted(mute: bool) -> void:
	_muted = mute

func is_playing() -> bool:
	for p in _sfx_players:
		if p.playing:
			return true
	return false

func stop_all() -> void:
	for p in _sfx_players:
		p.stop()
	if _music_player:
		_music_player.stop()

func get_sound_name(sound_id: int) -> String:
	return _sound_names.get(str(sound_id), "")

func has_sound(sound_id: int) -> bool:
	if _get_sound_type(sound_id) != SoundType.UNKNOWN:
		return true
	return _get_raw_file_path(sound_id) != ""