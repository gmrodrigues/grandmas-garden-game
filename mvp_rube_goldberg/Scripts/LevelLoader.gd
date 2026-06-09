class_name LevelLoader
extends RefCounted

const INDENT_SIZE: int = 2

static func load_file(path: String) -> Dictionary:
	var f = FileAccess.open(path, FileAccess.READ)
	if f == null:
		push_error("LevelLoader: Failed to open %s: %s" % [path, FileAccess.get_open_error()])
		return {}
	var text = f.get_as_text()
	f.close()
	return parse(text)

static func parse(text: String) -> Dictionary:
	var lines = text.strip_edges().split("\n")
	var root = {}
	var stack = [{"node": root, "indent": -1}]
	var i = 0
	while i < lines.size():
		var line = lines[i]
		if line.strip_edges() == "" or line.strip_edges().begins_with("#"):
			i += 1
			continue
		var raw_indent = 0
		while raw_indent < line.length() and line[raw_indent] == " ":
			raw_indent += 1
		var indent = raw_indent / INDENT_SIZE
		var content = line.strip_edges()
		if content.begins_with("- "):
			var key = ""
			var val: Variant = _parse_value(content.substr(2))
			if val is Dictionary:
				key = val.keys()[0] if not val.is_empty() else ""
				var arr = _ensure_array(stack[-1]["node"], _get_current_key(stack))
				if key != "" and val.has(key):
					arr.append(val[key])
				else:
					arr.append(val)
			else:
				var arr = _ensure_array(stack[-1]["node"], _get_current_key(stack))
				arr.append(val)
		else:
			var colon_i = content.find(": ")
			if colon_i == -1:
				colon_i = content.find(":")
			if colon_i != -1:
				var key = content.substr(0, colon_i).strip_edges()
				var rest = content.substr(colon_i + 1).strip_edges()
				var val: Variant = _parse_value(rest) if rest != "" else ""
				_pop_to_indent(stack, indent)
				var node = stack[-1]["node"]
				if val is Dictionary:
					node[key] = val
				else:
					node[key] = val
				if val is Dictionary:
					stack.append({"node": val, "indent": indent})
		i += 1
	return root

static func _parse_value(s: String) -> Variant:
	s = s.strip_edges()
	if s == "":
		return ""
	if s == "true":
		return true
	if s == "false":
		return false
	if s == "null":
		return null
	if s.begins_with('"') and s.ends_with('"'):
		return s.substr(1, s.length() - 2)
	if s.begins_with("'"):  # single-quoted fallback
		return s.substr(1, s.length() - 2)
	if s.begins_with("[") and s.ends_with("]"):
		var inner = s.substr(1, s.length() - 2).strip_edges()
		if inner == "":
			return []
		var items = inner.split(",")
		var arr: Array = []
		for item in items:
			arr.append(_parse_value(item.strip_edges()))
		return arr
	if s.begins_with("{") and s.ends_with("}"):
		return _parse_inline_dict(s)
	if s.is_valid_int():
		return s.to_int()
	if s.begins_with("0x"):
		return s.trim_prefix("0x").hex_to_int()
	if s.is_valid_float():
		return s.to_float()
	return s

static func _parse_inline_dict(s: String) -> Dictionary:
	var inner = s.substr(1, s.length() - 2).strip_edges()
	var result = {}
	if inner == "":
		return result
	var pairs = inner.split(",")
	for pair in pairs:
		var kv = pair.split(":")
		if kv.size() == 2:
			var k = kv[0].strip_edges()
			var v = _parse_value(kv[1].strip_edges())
			result[k] = v
	return result

static func _ensure_array(node: Dictionary, key: String) -> Array:
	if not node.has(key) or not (node[key] is Array):
		node[key] = []
	return node[key]

static func _get_current_key(stack: Array) -> String:
	var node = stack[-1]["node"]
	if node is Array:
		return ""
	return ""

static func _pop_to_indent(stack: Array, target_indent: int) -> void:
	while stack.size() > 1 and stack[-1]["indent"] >= target_indent:
		stack.pop_back()