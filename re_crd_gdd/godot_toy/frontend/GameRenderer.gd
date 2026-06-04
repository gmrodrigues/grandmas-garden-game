extends Node2D
class_name GameRenderer

# The Visual Shell (Frontend)
# Does not contain any physics or gameplay logic. Only reads from backend.

var world: WorldState
var simulation: SimulationLoop
var part_sprites: Dictionary = {}

func _ready():
	# Initialize backend deterministically
	world = WorldState.new()
	simulation = SimulationLoop.new(world)
	
	# Toy data: Add a falling ball
	var ball = PartData.new(0, 100, 50)
	ball.flags_1 |= 0x1000 # Moving flag
	world.add_part(ball)
	
	# Toy data: Add a static floor
	var floor_part = PartData.new(1, 100, 300)
	world.add_part(floor_part)
	
	# Setup rendering nodes
	for part in world.parts:
		var sprite = Sprite2D.new()
		# For the toy project we'll just draw a colored rectangle 
		# instead of loading the ANM JSON + BPG PNGs.
		# In reality, you'd integrate the ANM bytecode interpreter here.
		add_child(sprite)
		part_sprites[part] = sprite

func _physics_process(_delta: float):
	# Godot's _physics_process defaults to 60fps, matching the TIM2 spec.
	# We tick the pure GDScript backend once per physics frame.
	simulation.tick()
	
	# Render the new state
	for part in world.parts:
		var sprite = part_sprites[part] as Sprite2D
		sprite.position = Vector2(part.pos_x, part.pos_y)
		
		# Here we would query the ANM bytecode for `part.current_state`
		# and set the correct `sprite.texture` and `sprite.region_rect`.
