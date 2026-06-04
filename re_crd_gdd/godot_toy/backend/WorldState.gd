extends RefCounted
class_name WorldState

var parts: Array[PartData] = []
var gravity: int = 272
var pressure: int = 67
var tick_count: int = 0

func add_part(part: PartData):
	parts.append(part)
