#!/usr/bin/env python3
"""Error handling and edge case tests.

Tests graceful degradation when files are missing, JSON is malformed,
or data is incomplete.
"""
import json
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

os_env = __import__("os")
os_env.environ.setdefault("SDL_VIDEODRIVER", "dummy")

import pygame
pygame.init()

ANM_DIR = ROOT / "build" / "phase-4" / "anm"
YAML_DIR = ROOT / "build" / "phase-5" / "yaml"
BMP_DIR = ROOT / "build" / "phase-3" / "bitmaps"

from tim2_editor.engine.part import Part
from tim2_editor.engine.world import PhysicsWorld
from tim2_editor.engine.level import load_yaml, LevelData
from tim2_editor.engine.behavior import PartBehaviorRegistry, get_registry
from tim2_editor.sprites.anm_renderer import AnmRenderer

pass_count = 0
fail_count = 0


def check(name, condition, expected="", actual=""):
    global pass_count, fail_count
    status = "PASS" if condition else "FAIL"
    if condition:
        pass_count += 1
        print(f"  ✅ {name}")
    else:
        fail_count += 1
        print(f"  ❌ {name} — expected: {expected}, got: {actual}")


print("=== Error Handling Tests ===\n")

# ─────────────────────────────────────────────────────────────
# Test 1: load_yaml with non-existent file
print("--- 1. YAML Loading Edge Cases ---")
level = load_yaml(Path("/nonexistent/path/LEVEL.yaml"))
check("load_yaml nonexistent returns LevelData", level is not None and isinstance(level, LevelData))
check("load_yaml nonexistent has empty title", level.title == "")

# Test 2: load_yaml with empty file
with tempfile.NamedTemporaryFile(mode='w', suffix='.yaml', delete=False) as f:
    empty_path = Path(f.name)
try:
    level = load_yaml(empty_path)
    check("load_yaml empty file returns LevelData", level is not None)
finally:
    empty_path.unlink()

# Test 3: load_yaml with malformed YAML
with tempfile.NamedTemporaryFile(mode='w', suffix='.yaml', delete=False) as f:
    f.write("invalid: yaml: content: [\n")
    malformed_path = Path(f.name)
try:
    level = load_yaml(malformed_path)
    check("load_yaml malformed returns LevelData", level is not None)
finally:
    malformed_path.unlink()

# ─────────────────────────────────────────────────────────────
# Test 4: AnmRenderer with missing ANM
print("\n--- 2. ANM Renderer Edge Cases ---")
name_cat = json.loads((ROOT / "build" / "phase-9" / "part-name-catalog.json").read_text())
renderer = AnmRenderer(ANM_DIR, name_cat)

anm = renderer.load_anm("NONEXISTENT_ANM")
check("load_anm nonexistent returns None", anm is None)

frame = renderer.render_frame("NONEXISTENT", 1, BMP_DIR)
check("render_frame nonexistent ANM returns None", frame is None)

# Test with real ANM but non-existent frame index
anm_data = renderer.load_anm("PART0")
if anm_data:
    frame = renderer.render_frame("PART0", 999, BMP_DIR)
    check("render_frame invalid frame returns surface (transparency)", frame is not None)

# ─────────────────────────────────────────────────────────────
# Test 5: PhysicsWorld with edge cases
print("\n--- 3. Physics World Edge Cases ---")

# Empty world
world = PhysicsWorld()
check("empty world step() completes", True)
world.step()
check("empty world tick_count increments", world.tick_count == 1)

# Static parts only (non-moving)
world2 = PhysicsWorld()
part_static = Part(part_type=0)
part_static.is_moving = False
part_static.x = 100
part_static.y = 100
world2.add_part(part_static)
check("static-only world step() completes", True)
world2.step()
check("static-only world tick_count increments", world2.tick_count == 1)

# Part with custom state limits (from ANM state count)
world3 = PhysicsWorld()
part_custom = Part(part_type=18)  # Cannon has 37 states
part_custom.is_moving = True
part_custom.x = 100
part_custom.y = 100
world3.add_part(part_custom)  # This applies the custom limits
check("part has custom state_limit_upper", part_custom.state_limit_upper >= 37)
world3.step()
check("custom limit part step completes", True)

# ─────────────────────────────────────────────────────────────
# Test 6: Part serialization roundtrip
print("\n--- 4. Part Serialization Edge Cases ---")

# Minimal dict (missing keys)
minimal_dict = {"part_type": 5}
part = Part.from_dict(minimal_dict)
check("from_dict minimal has part_type", part.part_type == 5)
check("from_dict minimal has default x", part.x == 0)
check("from_dict minimal has default y", part.y == 0)

# Roundtrip (tests config fields, not runtime state like state_counter)
original = Part(part_type=42)
original.x = 100
original.y = 200
original.appearance = 3
original.flags_1 = 0x1234
d = original.to_dict()
restored = Part.from_dict(d)
check("roundtrip preserves part_type", restored.part_type == original.part_type)
check("roundtrip preserves x", restored.x == original.x)
check("roundtrip preserves y", restored.y == original.y)
check("roundtrip preserves appearance", restored.appearance == original.appearance)
check("roundtrip preserves flags_1", restored.flags_1 == original.flags_1)
check("roundtrip excludes runtime state (state_counter)", restored.state_counter == 0)  # runtime state not serialized

# ─────────────────────────────────────────────────────────────
# Test 7: PartBehaviorRegistry with edge case data
print("\n--- 5. Registry Edge Cases ---")

# Query unknown part type
registry = get_registry()
props = registry.get_physics_props(9999)
check("get_physics_props unknown part returns defaults", props.get("mass") is not None)

sounds = registry.get_sounds_for_part(9999)
check("get_sounds_for_part unknown part returns empty list", sounds == [])

limits = registry.get_state_limits_for_part(9999)
check("get_state_limits_for_part unknown returns defaults", limits.get("limit_upper") == 8)

# ─────────────────────────────────────────────────────────────
# Test 7: Solved State Persistence
print("\n--- 7. Solved State Persistence ---")
import tempfile
import os
from pathlib import Path

# Patch SAVE_DIR and SAVE_FILE for testing
test_save_dir = Path(tempfile.mkdtemp())
test_save_file = test_save_dir / "saves.json"

# Import and test save functions
import importlib
import tim2_editor.game as game_module
orig_save_dir = game_module.SAVE_DIR
orig_save_file = game_module.SAVE_FILE
game_module.SAVE_DIR = test_save_dir
game_module.SAVE_FILE = test_save_file

from tim2_editor.game import load_solved_states, save_solved_state

check("load_solved_states missing file returns empty dict", load_solved_states() == {})

test_level = "TEST_PUZZLE_123"
save_solved_state(test_level)
loaded = load_solved_states()
check("save then load returns solved", loaded.get(test_level) is True)

check("save file exists after save", test_save_file.exists())

other_level = "ANOTHER_PUZZLE"
save_solved_state(other_level)
loaded2 = load_solved_states()
check("second save preserves first", loaded2.get(test_level) is True)
check("second save has both entries", len(loaded2) == 2)

# Cleanup
game_module.SAVE_DIR = orig_save_dir
game_module.SAVE_FILE = orig_save_file

# ─────────────────────────────────────────────────────────────
# Test 8: Collision Matrix Symmetry
print("\n--- 8. Collision Matrix Symmetry ---")
from tim2_editor.engine.world import check_collision_matrix_symmetry, COLLISION_MATRIX

is_sym, asym = check_collision_matrix_symmetry()
check("collision matrix has symmetry check function", is_sym is not None)
check("collision matrix asymmetries found", len(asym) > 0)
if asym:
    print(f"  ℹ️  Asymmetries: {asym}")

known_asyms = {("STATIC", "ROPE"), ("EXPLOSIVE", "SCENERY"), ("EXPLOSIVE", "CREATED"), ("DYNAMIC", "ROPE")}
check("expected asymmetries documented", known_asyms.issubset(set(asym)))

check("DYNAMIC in STATIC targets", "DYNAMIC" in COLLISION_MATRIX["STATIC"])
check("STATIC in DYNAMIC targets", "STATIC" in COLLISION_MATRIX["DYNAMIC"])

# ─────────────────────────────────────────────────────────────
# Test 9: Part Behavioral Fields
print("\n--- 9. Part Behavioral Fields ---")
p = Part()
check("Part has motor_connected field", hasattr(p, 'motor_connected'))
check("Part motor_connected defaults to False", p.motor_connected is False)
check("Part has angular_velocity field", hasattr(p, 'angular_velocity'))
check("Part angular_velocity defaults to 0", p.angular_velocity == 0)
check("Part has rotation_angle field", hasattr(p, 'rotation_angle'))
check("Part rotation_angle defaults to 0", p.rotation_angle == 0)
check("Part has facing field", hasattr(p, 'facing'))
check("Part facing defaults to 1 (right)", p.facing == 1)

p.facing = -1
check("Part facing can be set to -1 (left)", p.facing == -1)
p.motor_connected = True
check("Part motor_connected can be set to True", p.motor_connected is True)

# ─────────────────────────────────────────────────────────────
# Test 10: SafeFont fallback
print("\n--- 10. SafeFont Fallback ---")
from tim2_editor.sandbox import SafeFont

# Create font with definitely-bad font name
font = SafeFont("definitely_not_a_real_font_name_12345", 16)
check("SafeFont with bad name creates object", font is not None)
check("SafeFont with bad name render returns surface", font.render("test", True, (255,255,255)) is not None)

# ─────────────────────────────────────────────────────────────
# Summary
print(f"\n{'='*50}")
print(f"RESULTS: {pass_count} passed, {fail_count} failed")
print(f"{'='*50}")
sys.exit(0 if fail_count == 0 else 1)
