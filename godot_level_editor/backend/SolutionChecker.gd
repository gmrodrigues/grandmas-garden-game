extends RefCounted
class_name SolutionChecker

var conditions: Array[SolutionCondition] = []

func _init(conds: Array[SolutionCondition] = []):
	conditions = conds

func check(world_state: WorldState) -> Array:
	var all_met = true
	var failed: Array = []
	for i in range(conditions.size()):
		var met = conditions[i].check(world_state)
		if not met:
			all_met = false
			failed.append("condition_" + str(i))
	return [all_met, failed]

func reset():
	for c in conditions:
		c.reset()
