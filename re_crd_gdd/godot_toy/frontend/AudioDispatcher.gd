extends Node
class_name AudioDispatcher

# Autoload to handle sound dispatching without blocking the physics thread.
# Uses a pool of AudioStreamPlayer nodes to allow concurrent sounds.

const POOL_SIZE = 16
var audio_pool: Array[AudioStreamPlayer] = []
var sound_cache: Dictionary = {}

func _ready() -> void:
	for i in range(POOL_SIZE):
		var player = AudioStreamPlayer.new()
		add_child(player)
		audio_pool.append(player)

func play_sound(sound_id: int) -> void:
	var stream = _get_or_load_stream(sound_id)
	if not stream:
		return
		
	var player = _get_available_player()
	if player:
		player.stream = stream
		player.play()

func _get_or_load_stream(sound_id: int) -> AudioStream:
	if sound_cache.has(sound_id):
		return sound_cache[sound_id]
		
	var path = "res://data/audio/SX_" + str(sound_id) + "_11025.wav"
	if ResourceLoader.exists(path):
		var stream = ResourceLoader.load(path)
		sound_cache[sound_id] = stream
		return stream
		
	return null

func _get_available_player() -> AudioStreamPlayer:
	for player in audio_pool:
		if not player.playing:
			return player
			
	# If all playing, override the oldest one (simplified)
	return audio_pool[0]
