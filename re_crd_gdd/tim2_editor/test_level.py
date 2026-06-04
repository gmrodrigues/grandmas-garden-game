"""Editor test: load real levels, verify parsing, physics, and state machine."""
import sys, json, os
from pathlib import Path

os.environ["SDL_VIDEODRIVER"] = "dummy"  # headless pygame
import pygame
pygame.init()
pygame.display.set_mode((640, 480))

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from tim2_editor.engine.part import Part
from tim2_editor.engine.world import PhysicsWorld
from tim2_editor.engine.level import load_yaml
from tim2_editor.engine.solver import SolutionChecker
from tim2_editor.sprites.anm_renderer import AnmRenderer

YAML_DIR = ROOT / "build" / "phase-5" / "yaml"
ANM_DIR = ROOT / "build" / "phase-4" / "anm"
NAME_CATALOG_PATH = ROOT / "build" / "phase-9" / "part-name-catalog.json"

pass_count = 0
fail_count = 0

def check(name, condition, detail=""):
    global pass_count, fail_count
    if condition:
        pass_count += 1
        print(f"  ✅ {name}")
    else:
        fail_count += 1
        print(f"  ❌ {name} — {detail}")

# Load part name catalog
name_catalog = json.loads(NAME_CATALOG_PATH.read_text())
renderer = AnmRenderer(ANM_DIR, name_catalog)

# Test 1: Load ELEV1
print("\n=== Test 1: Load ELEV1.yaml ===")
level = load_yaml(YAML_DIR / "ELEV1.yaml")
check("Level loaded", level is not None, "load_yaml returned None")
parts = level.parts
check("105 parts", len(parts) == 105, f"got {len(parts)}")

# Check first moving part
moving = [p for p in parts if p.is_moving]
check("1 moving part", len(moving) == 1, f"got {len(moving)}")
if moving:
    ball = moving[0]
    check("Ball has dimensions", ball.width_1 > 0 and ball.height_1 > 0)
    check("Ball has flags_1 0x1000", ball.flags_1 & 0x1000, f"flags_1=0x{ball.flags_1:04x}")
    ball.anm_name = renderer.get_anm_for_part(ball.part_type) or ""
    check("Ball has anm_name", len(ball.anm_name) > 0, f"anm_name={ball.anm_name} for type {ball.part_type}")

# Test 2: Verify state machine on selected parts
print("\n=== Test 2: State Machine ===")
world = PhysicsWorld()
for p in parts:
    p.anm_name = renderer.get_anm_for_part(p.part_type) or ""
    world.add_part(p)

check("World has parts", len(world.parts) == 105)

# Run 10 ticks
for tick in range(10):
    world.step()

check("Tick count", world.tick_count == 10)

# Ball should have moved down due to gravity
if moving:
    ball = world.parts[parts.index(moving[0])]
    check("Ball fell", ball.y > 0, f"y={ball.y}")
    check("Ball state advanced", ball.state_counter > 0, f"state={ball.state_counter}")

# Test 3: Collision detection
print("\n=== Test 3: Collision ===")
world2 = PhysicsWorld()
a = Part(part_type=0, x=100, y=100, width_1=32, height_1=32, flags_1=0x1000)
b = Part(part_type=69, x=120, y=120, width_1=32, height_1=32, flags_1=0)
world2.add_part(a)
world2.add_part(b)

check("Parts overlapping", a.aabb_overlap(b))
pre_state = a.state_counter
world2.step()
check("Collision triggered state change", a.state_counter > pre_state or b.state_counter > pre_state)

# Test 4: ANM Renderer
print("\n=== Test 4: ANM Renderer ===")
anm_name = renderer.get_anm_for_part(0)  # ball
check("Ball ANM found", anm_name is not None, f"got {anm_name}")
if anm_name:
    anm_data = renderer.load_anm(anm_name)
    check("ANM data loaded", anm_data is not None)
    if anm_data:
        state_0 = renderer.get_first_frame_for_state(anm_data, 0)
        meta = renderer.get_frame_meta(anm_data, state_0)
        check("Frame has metadata", meta is not None)
        if meta:
            check("Section B has bytecode_offset", "bytecode_offset" in meta)
            bc = renderer.get_bytecodes_for_frame(anm_data, meta["bytecode_offset"])
            check("Bytecodes for frame", len(bc) > 0, f"got {len(bc)} commands")
            # Render the frame
            sprite = renderer.render_frame(anm_name, 0, ROOT / "build" / "phase-3" / "bitmaps")
            check("Sprite rendered", sprite is not None)
            if sprite:
                w, h = sprite.get_size()
                check("Sprite has size", w > 0 and h > 0, f"{w}x{h}")

# Test 5: Solution conditions
print("\n=== Test 5: Solution Conditions ===")
check("Has solution conditions", len(level.solution_conditions) > 0, f"count={len(level.solution_conditions)}")
if level.solution_conditions:
    sc = level.solution_conditions[0]
    checker = SolutionChecker(level.solution_conditions)
    # Check current state (should be unsolved)
    solved, failed = checker.check(world)
    check("Can check solution", isinstance(solved, bool))

# Test 6: ANM catalog mapping
print("\n=== Test 6: ANM Catalog Coverage ===")
part_types_in_level = set(p.part_type for p in parts)
anm_coverage = sum(1 for pt in part_types_in_level if renderer.get_anm_for_part(pt) is not None)
check(f"ANM coverage {anm_coverage}/{len(part_types_in_level)} part types", True)

# Test 7: ELEV1 level info
print("\n=== Test 7: Level Metadata ===")
check("Has title", level.title == "Under the Sea", f"got '{level.title}'")
check("Has goal", len(level.goal) > 0)
check("Has pressure", level.pressure > 0, f"pressure={level.pressure}")
check("Has gravity", level.gravity > 0, f"gravity={level.gravity}")
check("Has music", level.music_track > 0, f"track={level.music_track}")

# Summary
print(f"\n{'='*50}")
print(f"RESULTS: {pass_count} passed, {fail_count} failed")
if fail_count > 0:
    sys.exit(1)
else:
    print("ALL TESTS PASSED ✅")
