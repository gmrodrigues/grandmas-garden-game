extends Node

const POOL_SIZE = 16
var audio_pool: Array[AudioStreamPlayer] = []
var sound_cache: Dictionary = {}
var next_player: int = 0

func _ready() -> void:
	for i in range(POOL_SIZE):
		var player = AudioStreamPlayer.new()
		add_child(player)
		audio_pool.append(player)
	print("AudioManager ready: ", POOL_SIZE, " players")

func play_sfx(sound_id: int) -> void:
	var stream = _get_or_load_stream(sound_id)
	if not stream:
		return
	var player = _get_available_player()
	if player:
		player.stream = stream
		player.play()

func play_sfx_path(wav_path: String) -> void:
	if not ResourceLoader.exists(wav_path):
		return
	var stream = ResourceLoader.load(wav_path) as AudioStream
	if not stream:
		return
	var player = _get_available_player()
	if player:
		player.stream = stream
		player.play()

func _get_or_load_stream(sound_id: int) -> AudioStream:
	if sound_cache.has(sound_id):
		return sound_cache[sound_id]

	var variants = ["_11025.wav", "_22050.wav", "_8000.wav"]
	for suffix in variants:
		var path = "res://data/wav/SX_" + str(sound_id) + suffix
		if ResourceLoader.exists(path):
			var stream = ResourceLoader.load(path) as AudioStream
			if stream:
				sound_cache[sound_id] = stream
				return stream
	return null

func _get_available_player() -> AudioStreamPlayer:
	for player in audio_pool:
		if not player.playing:
			return player
	var p = audio_pool[next_player]
	next_player = (next_player + 1) % POOL_SIZE
	p.stop()
	return p

func stop_all() -> void:
	for player in audio_pool:
		player.stop()
