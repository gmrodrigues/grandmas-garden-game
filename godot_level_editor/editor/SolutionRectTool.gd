extends RefCounted
class_name SolutionRectTool

var start_pos: Vector2 = Vector2.ZERO
var end_pos: Vector2 = Vector2.ZERO
var dragging: bool = false

func begin(pos: Vector2):
	start_pos = pos
	end_pos = pos
	dragging = true

func update(pos: Vector2):
	if dragging:
		end_pos = pos

func finish() -> Rect2:
	dragging = false
	var r = Rect2(start_pos, end_pos - start_pos)
	if r.size.x < 0: r.position.x = end_pos.x; r.size.x = -r.size.x
	if r.size.y < 0: r.position.y = end_pos.y; r.size.y = -r.size.y
	return r

func get_rect() -> Rect2:
	return Rect2(start_pos, end_pos - start_pos)

func cancel():
	dragging = false
