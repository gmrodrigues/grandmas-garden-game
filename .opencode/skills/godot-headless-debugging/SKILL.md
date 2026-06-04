---
name: godot-headless-debugging
description: Godot 4 headless debugging workflow — parse errors, runtime errors, log inspection, command-line arg injection, and common Godot 3→4 migration issues. Trigger keywords: godot headless, parse error, script error, godot.log, mini/maxi, hex_to_int, VK_KHR_surface, autoload class_name, YAML parser, FileDialog leak, cmdline, arg injection, --level.
---

# Godot 4 Headless Debugging

Use `--headless --path <project>` to run without a display. Pipeline: compile → parse → runtime → test.

## Running Headless

```bash
./Godot_v4.6.3-stable_linux.x86_64 --path <project_dir>/ --headless [2>&1]
```

Flags: `--headless` (no window), `--path` (project root), `--editor` (open editor), `--script <file>` (run script — no autoloads available).

## Command-Line Arg Injection

Godot leaves unknown flags in `OS.get_cmdline_args()`. This enables injecting paths/values without modifying the launch command structure.

### Pattern: `--level` to auto-load a file

**Invocation:**
```bash
./Godot --path <project>/ --headless --level res://build/ELEV10.yaml
```

**Receiver (`_ready()` in any autoload or main scene):**
```gdscript
func _ready():
    var args = OS.get_cmdline_args()
    var idx = args.find("--level")
    if idx >= 0 and idx + 1 < args.size():
        _do_load(args[idx + 1])
```

### Pattern: environment variables (no `--` needed)

```bash
GODOT_LEVEL=res://build/ELEV10.yaml ./Godot --path <project>/ --headless
```

```gdscript
var path = OS.get_environment("GODOT_LEVEL")
```

### Pattern: inject via `--` separator

```bash
./Godot --path <project>/ --headless -- --level ELEV10.yaml
```

Everything after `--` is passed through as args.

### Pattern: skip UI entirely (direct method call)

For headless tests, bypass FileDialog:
```gdscript
editor._do_load("res://build/ELEV10.yaml")
# or
LevelSerializer.load_yaml("res://build/ELEV10.yaml")
```

## Log Locations

```bash
~/.local/share/godot/app_userdata/<project>/logs/godot*.log
```

Check after every run. Vulkan errors (`VK_KHR_surface not found`) mean missing GPU driver — not a code bug. Scrolling past them is safe (Godot falls back to OpenGL).

## Godot 3→4 Migration Errors

| Pattern | Fix | Why |
|---------|-----|-----|
| `mini(a,b)` / `maxi(a,b)` | `min(a,b)` / `max(a,b)` | Removed in Godot 4 |
| `minf(a,b)` / `maxf(a,b)` | `min(a,b)` / `max(a,b)` | Removed in Godot 4 |
| `int("0x..", 16)` | `"0x...".hex_to_int()` | `int()` no longer accepts base param |
| `KEY_EQUALS` | `KEY_EQUAL` | Renamed in Godot 4 |
| `var f = func():` then `f()` | `f.call()` | Parser can't resolve `var` lambdas as callables at parse time |
| `class_name` on autoload | Remove it | Class type shadows the singleton instance |

## Autoload `class_name` Conflict

Autoload singletons in `project.godot` must NOT have `class_name` in the script.

**Check:** `project.godot` has `Name="*res://..."` AND the script has `class_name Name`
**Fix:** Delete `class_name Name` — the autoload already provides global access.

## YAML Parser Indent Tracking

The most common YAML parser bug: `strip_edges(true, false)` destroys leading whitespace, making every `key:` line reset `current_section`. **Preserve indent:**

```gdscript
var stripped = line_raw.lstrip(" ")
var indent = line_raw.length() - stripped.length()
var content = stripped.strip_edges(false, true)

if indent == 0 and content.ends_with(":") and not content.contains("-"):
    current_section = content.trim_suffix(":")
```

## Hex String Sanitization

YAML hex values with quotes like `'0x6000'` will crash `hex_to_int()`. Always trim:

```gdscript
s.trim_prefix("'").trim_suffix("'").hex_to_int()
```

## FileDialog Memory Leak

Every `FileDialog.new()` + `add_child()` leaks if not freed. Connect `queue_free` to both `file_selected` and `canceled`:

```gdscript
fd.file_selected.connect(_handler)
fd.file_selected.connect(fd.queue_free)
fd.canceled.connect(fd.queue_free)
```

## Diagnostic Workflow

1. Run headless, capture all output
2. Fix parse errors first (syntax → indent → missing identifiers)
3. Fix script/compile errors (removed APIs → migration fixes)
4. Fix runtime errors (file loading, hex parsing)
5. Check `godot.log` for Vulkan/GL errors
6. Test with a level file via `--level` arg injection
7. Re-run until zero errors

## Key References

- `LevelSerializer.gd:199-225` — indent tracking fix
- `EditorController.gd:62-68` — arg injection in `_ready()`
- `EditorController.gd:539-551` — hex flag values with quote stripping
- `EditorController.gd:482-536` — FileDialog with `queue_free` cleanup
- `autoload/*.gd` — `class_name` removed from all 4 singletons
- `PhysicsSolver.gd:225-226,278-279` — `mini/maxi` → `min/max`
- `BehaviorRegistry.gd:66-68,79,205,258` — lambda `.call()` workaround
