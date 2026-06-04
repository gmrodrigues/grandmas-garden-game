extends RefCounted
class_name SimulationLoop

var world: WorldState
var solver: PhysicsSolver

func _init(_world: WorldState):
	world = _world
	solver = PhysicsSolver.new(world)

func tick():
	if solver.tick_counter >= PhysicsSolver.MAX_TICKS:
		return
	solver.step()
