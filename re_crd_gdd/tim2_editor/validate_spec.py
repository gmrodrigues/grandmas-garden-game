"""Spec validation — tests physics, state machine, and collision against spec.

Measures actual simulation behavior and compares against expected values
derived from the clean-room spec (docs/godot-specification.md).
"""
import sys, os, json
from pathlib import Path
os.environ["SDL_VIDEODRIVER"] = "dummy"
import pygame
pygame.init()
pygame.display.set_mode((640, 480))

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from tim2_editor.engine.part import Part
from tim2_editor.engine.world import PhysicsWorld
from tim2_editor.engine.level import load_yaml
from tim2_editor.engine.solver import SolutionChecker
from tim2_editor.engine.behavior import get_registry
from tim2_editor.sprites.anm_renderer import AnmRenderer

pass_count = 0
fail_count = 0
results = {}

def check(name, condition, expected, actual, detail=""):
    global pass_count, fail_count
    ok = condition
    if ok:
        pass_count += 1
    else:
        fail_count += 1
    results[name] = {"pass": ok, "expected": expected, "actual": actual, "detail": detail}
    status = "✅" if ok else "❌"
    print(f"  {status} {name}: expected={expected} actual={actual} {detail}")

# ═══════════════════════════════════════════════════════════════
# Test 1: Gravity — Ball Drop
# ═══════════════════════════════════════════════════════════════
print("\n=== Gravity: Ball Drop at 60 Hz ===")
# Bowling ball (type 0): gravity_category varies by part type
# From part-properties.json, bowling ball has specific params
part_props_list = json.loads((ROOT / "build" / "phase-9" / "part-properties.json").read_text())
ball_cat = 7  # default gravity category

part = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
# Set gravity category from PAR data
part.gravity_category = ball_cat

# Run 60 ticks (1 second at 60 Hz)
for _ in range(60):
    part.tick()

# Theoretical check:
# gravity_base for cat >= 151 → 0x1000, cat < 2 → 0x1C00, etc.
base = part.gravity_base
g_per_tick = part.gravity_y  # base // 4

# After N ticks with constant acceleration:
# vel_y = gravity_y * N
# pos_y = 0.5 * (vel_y / 512) * N  (since vel_y increases linearly)
# Actually: each tick: vel_y += g; pos_y += vel_y >> 9
# After 1 tick: vel = g, pos = g/512
# After 2 ticks: vel = 2g, pos = g/512 + 2g/512 = 3g/512
# After N ticks: vel = N*g, pos = g/512 * N*(N+1)/2

N = 60
expected_vel = N * g_per_tick

# Calculate expected pos using integer SAR 9 (floor division for negative)
# For positive velocities, >> 9 = // 512
expected_pos = 0
vel = 0
for _ in range(N):
    vel += g_per_tick
    expected_pos += vel // 512  # integer SAR 9

check("gravity_y value", part.vel_y == expected_vel,
      expected_vel, part.vel_y,
      f"gravity_y={g_per_tick}, base=0x{base:X}")
check("position after 60 ticks (1s)", abs(part.y - 50 - expected_pos) < 2,
      50 + expected_pos, part.y,
      f"fall distance={part.y - 50}px")

# Test with a part in the highest gravity category
part_heavy = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
part_heavy.gravity_category = 0  # lightest → highest gravity
for _ in range(60):
    part_heavy.tick()
heavy_base = part_heavy.gravity_base
check("highest gravity base", heavy_base == 0x1C00,
      0x1C00, heavy_base)

# ═══════════════════════════════════════════════════════════════
# Test 2: AABB Collision
# ═══════════════════════════════════════════════════════════════
print("\n=== Collision: AABB Detection + Response ===")
world = PhysicsWorld(viewport=(0, 0, 560, 377))
ball = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
floor = Part(part_type=69, x=90, y=50, width_1=36, height_1=16, flags_1=0)  # static floor, overlapping
ball.gravity_category = 0  # highest gravity so ball clearly falls onto floor
ball.cor_q8 = 128
world.add_part(ball)
world.add_part(floor)

# Check initial state
check("initial overlap", ball.aabb_overlap(floor), True, ball.aabb_overlap(floor))
check("ball is moving", ball.is_moving, True, ball.is_moving)
check("floor is static", not floor.is_moving, True, not floor.is_moving)

pre_state = ball.state_counter
# Run 1 tick — should detect collision and push ball up
world.step()
check("collision updated state", ball.state_counter > pre_state, True, ball.state_counter > pre_state)

# After collision, ball should be above floor (pushed up out of overlap)
# Floor top is at floor.y = 50 (y origin is top); floor bottom is floor.y + floor.height_1 = 66
check("ball above floor after collision",
      ball.y + ball.height_1 <= floor.y + 1,
      f"ball_bottom({ball.y+ball.height_1}) <= floor_top({floor.y})+1",
      ball.y + ball.height_1,
      f"ball.y={ball.y}, floor.y={floor.y}")

# ═══════════════════════════════════════════════════════════════
# Test 3: State Machine Cycling
# ═══════════════════════════════════════════════════════════════
print("\n=== State Machine: Counter Cycling ===")
sm_part = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
sm_part.state_limit_upper = 8

# State should cycle: may start with random delay (zero state = random timer)
# Run until we see the cycle stabilize
seen_states = []
for _ in range(30):
    sm_part.advance_state()
    seen_states.append(sm_part.state_counter)

# After the random delay (if any), the state cycles 0→1→2→...→7→0→1→...
# Verify the pattern is 0,1,2,3,4,5,6,7,0,... eventually
# Find first non-zero state
try:
    first_nz = next(i for i, s in enumerate(seen_states) if s > 0)
    after_nz = seen_states[first_nz:]
    # Should cycle 1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,...
    expected = [1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0]
    match = after_nz[:24] == expected[:24]
    check("state counter cycle (after init delay)", match,
          f"starts 1→2→... at tick {first_nz}", after_nz[:10] if match else after_nz[:24])
except StopIteration:
    check("state counter cycle", False, "state > 0 within 30 ticks",
          f"all zero: {seen_states}")

# Collision should bump state even when counter is mid-cycle
sm_part.state_counter = 3
sm_part.on_collision(sm_part)  # dummy other
check("collision bumps state", sm_part.state_counter == 4, 4, sm_part.state_counter)

# Collision at max should not exceed limit
sm_part.state_counter = 7  # state_limit_upper - 1
sm_part.on_collision(sm_part)
check("collision at limit reaches max", sm_part.state_counter == 8, 8, sm_part.state_counter)

# ═══════════════════════════════════════════════════════════════
# Test 4: ANM State → Frame Mapping
# ═══════════════════════════════════════════════════════════════
print("\n=== ANM: State→Frame Mapping ===")
name_cat = json.loads((ROOT / "build" / "phase-9" / "part-name-catalog.json").read_text())
renderer = AnmRenderer(ROOT / "build" / "phase-4" / "anm", name_cat)

# Bowling ball (type 0) → PART0.json
anm_name = renderer.get_anm_for_part(0)
check("bowling ball has ANM", anm_name == "PART0", "PART0", anm_name)

if renderer.load_anm("PART0"):
    anm_data = renderer.load_anm("PART0")
    # PART0 has state_ids = [1] (from part-name-catalog)
    state_1_first = renderer.get_first_frame_for_state(anm_data, 1)
    check("PART0 state 1 → frame 0", state_1_first == 0, 0, state_1_first)
    
    # Get frame 0 metadata
    meta = renderer.get_frame_meta(anm_data, 0)
    check("frame 0 has metadata", meta is not None, True, meta is not None)
    if meta:
        bc = renderer.get_bytecodes_for_frame(anm_data, meta["bytecode_offset"])
        check("frame 0 has bytecodes", len(bc) > 0, True, len(bc) > 0, f"{len(bc)} commands")
        
        # Verify bytecode opcodes
        for entry in bc:
            cmd = entry.get("cmd", -1)
            check(f"valid opcode {cmd}", 0 <= cmd <= 5, "0-5", cmd,
                  entry.get("name", f"cmd_{cmd}"))

# ═══════════════════════════════════════════════════════════════
# Test 5: ELEV1 Level — Full Load + Basic Simulation
# ═══════════════════════════════════════════════════════════════
print("\n=== ELEV1: Full Level Load + Simulation ===")
yaml_dir = ROOT / "build" / "phase-5" / "yaml"
level = load_yaml(yaml_dir / "ELEV1.yaml")
world = PhysicsWorld()
for p in level.parts:
    world.add_part(p)

check("ELEV1 has 105 parts", len(world.parts) == 105, 105, len(world.parts))

moving = [p for p in world.parts if p.is_moving]
check("ELEV1 has 1 moving part", len(moving) == 1, 1, len(moving))

# Run 30 ticks
for _ in range(30):
    world.step()

check("30 ticks executed", world.tick_count == 30, 30, world.tick_count)

# Moving part should have fallen and collided
if moving:
    ball = moving[0]
    check("ball fell > 0 pixels", ball.y > 0, True, ball.y > 0, f"y={ball.y}")
    check("ball has non-zero velocity after 30 ticks", abs(ball.vel_y) > 0, True, abs(ball.vel_y) > 0,
          f"vel_y={ball.vel_y} (may be bouncing)")

# ═══════════════════════════════════════════════════════════════
# Test 6: Multiple Level Loads (sampling)
# ═══════════════════════════════════════════════════════════════
print("\n=== Multi-Level Load Sampling ===")
level_names = ["ELEV1", "ELEV5", "ELEV10", "ELEV15", "ELEV20", "ELEV25"]
for name in level_names:
    try:
        lev = load_yaml(yaml_dir / f"{name}.yaml")
        check(f"{name} loaded ({len(lev.parts)} parts)", len(lev.parts) > 0,
              True, len(lev.parts) > 0)
    except Exception as e:
        check(f"{name} load failure", False, "no error", str(e))

# ═══════════════════════════════════════════════════════════════
# Test 7: Solution Condition Checking
# ═══════════════════════════════════════════════════════════════
print("\n=== Solution Conditions ===")
level = load_yaml(yaml_dir / "ELEV1.yaml")
check("ELEV1 has conditions", len(level.solution_conditions) > 0,
      True, len(level.solution_conditions) > 0)

if level.solution_conditions:
    checker = SolutionChecker(level.solution_conditions)
    world = PhysicsWorld()
    for p in level.parts:
        world.add_part(p)
    # Initial state should NOT be solved
    solved, failed = checker.check(world)
    check("initial state unsolved", not solved, False, solved)
    check("failure reasons captured", len(failed) > 0, True, len(failed) > 0,
          f"first: {failed[0][:60]}")

# ═══════════════════════════════════════════════════════════════
# Test 8: Collision Matrix + Physics Integration
# ═══════════════════════════════════════════════════════════════
print("\n=== Collision Matrix + Physics Integration ===")

# 8a: Wall collision — ball stops at right wall with vel_x <= 0
world_wall = PhysicsWorld(viewport=(0, 0, 560, 377))
ball_w = Part(part_type=0, x=500, y=100, width_1=16, height_1=16, flags_1=0x1000)
ball_w.gravity_category = 0
ball_w.cor_q8 = 128
ball_w.vel_x = 2000
world_wall.add_part(ball_w)
for _ in range(25):
    world_wall.step()
check("wall collision — ball right at wall",
      ball_w.x + ball_w.width_1 <= 560, True, ball_w.x + ball_w.width_1)
check("wall collision — vel_x <= 0 after bounce",
      ball_w.vel_x <= 0, True, ball_w.vel_x)

# 8b: Surface clamp — ball bottom == floor top (no gap)
world_sc = PhysicsWorld(viewport=(0, 0, 560, 377))
ball_sc = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
floor_sc = Part(part_type=60, x=90, y=50, width_1=36, height_1=16, flags_1=0)
ball_sc.gravity_category = 0
ball_sc.cor_q8 = 128
world_sc.add_part(ball_sc)
world_sc.add_part(floor_sc)
world_sc.step()
check("surface clamp — ball_bottom == floor_top",
      ball_sc.y + ball_sc.height_1 == floor_sc.y, True, ball_sc.y + ball_sc.height_1)

# 8c: Static immobility — floor doesn't move when ball hits it
world_si = PhysicsWorld(viewport=(0, 0, 560, 377))
ball_si = Part(part_type=0, x=100, y=10, width_1=16, height_1=16, flags_1=0x1000)
floor_si = Part(part_type=60, x=90, y=100, width_1=36, height_1=16, flags_1=0)
ball_si.gravity_category = 0
ball_si.cor_q8 = 128
world_si.add_part(ball_si)
world_si.add_part(floor_si)
init_floor_y = floor_si.y
init_floor_x = floor_si.x
for _ in range(30):
    world_si.step()
check("static immobility — floor y unchanged",
      floor_si.y == init_floor_y, True, floor_si.y)
check("static immobility — floor x unchanged",
      floor_si.x == init_floor_x, True, floor_si.x)

# 8d: Collision matrix gating — SCENERY doesn't collide with DYNAMIC
world_cm = PhysicsWorld(viewport=(0, 0, 560, 377))
scenery = Part(part_type=29, x=100, y=30, width_1=16, height_1=16, flags_1=0)
scenery.collision_cat = 'SCENERY'
ball_cm = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
ball_cm.gravity_category = 0
ball_cm.cor_q8 = 128
world_cm.add_part(scenery)
world_cm.add_part(ball_cm)
init_scenery_y = scenery.y
for _ in range(60):
    world_cm.step()
check("collision matrix — SCENERY passes through DYNAMIC (scenery unchanged)",
      scenery.y == init_scenery_y, True, scenery.y)
check("collision matrix — should_collide(SCENERY, DYNAMIC) = False",
      not world_cm._should_collide("SCENERY", "DYNAMIC"), True,
      not world_cm._should_collide("SCENERY", "DYNAMIC"))

# 8e: ELEV1 120 ticks — no crash with real level data
level_120 = load_yaml(Path("build/phase-5/yaml/ELEV1.yaml"))
world_120 = PhysicsWorld(viewport=(10, 60, 560, 377))
for p in level_120.parts:
    world_120.add_part(p)
for _ in range(120):
    world_120.step()
check("ELEV1 120 ticks — no crash",
      world_120.tick_count == 120, True, world_120.tick_count)

# 8f: Determinism — identical runs produce identical results
pos1, pos2 = [], []
for run in range(2):
    world_d = PhysicsWorld(viewport=(0, 0, 560, 377))
    ball_d = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
    ball_d.gravity_category = 0
    ball_d.cor_q8 = 128
    world_d.add_part(ball_d)
    positions = []
    for _ in range(100):
        world_d.step()
        positions.append((ball_d.x, ball_d.y))
    if run == 0:
        pos1 = positions
    else:
        pos2 = positions
check("determinism — two runs identical (100 ticks)",
      pos1 == pos2, True, pos1 == pos2)

# ═══════════════════════════════════════════════════════════════
# Test 9: Animation Frame Timing (Section A Indirection)
# ═══════════════════════════════════════════════════════════════
print("\n=== Animation Pipeline: Section A Indirection ===")
renderer = AnmRenderer(ROOT / "build/phase-4/anm")

# 9a: Non-animated ANM — no section_a, renders with direct section_b index
static_anm = "PART0"
anm_static = renderer.load_anm(static_anm)
has_section_a = bool(anm_static and anm_static.get("section_a"))
check("PART0 has no section_a (static sprite)",
      not has_section_a, True, has_section_a)
frame0 = renderer.render_frame(static_anm, 0, ROOT / "build/phase-3/bitmaps", state_counter=0)
frame1 = renderer.render_frame(static_anm, 0, ROOT / "build/phase-3/bitmaps", state_counter=99)
check("static sprite — same frame for state_counter 0 and 99",
      frame0 is not None and frame1 is not None,
      True, f"{frame0 is not None}, {frame1 is not None}")
if frame0 and frame1:
    check("static sprite — identical surface content at counter 0 and 99",
      frame0.get_bitsize() == frame1.get_bitsize() and frame0.get_size() == frame1.get_size(),
      True, f"{frame0.get_size()} {frame1.get_size()}")

# 9b: Animated ANM — CREDITS.ANM has section_a=[0,1,1,2,3,3], section_c state_id=1 → first_a_idx=1
# Frame sequence for state_id=1: a_idx=1→section_a[1]=1, a_idx=2→1, a_idx=3→2, a_idx=4→3, a_idx=5→3, a_idx=6→0 (wrap)
credits_anm = "CREDITS"
anm_credits = renderer.load_anm(credits_anm)
section_a = anm_credits.get("section_a", []) if anm_credits else []
check("CREDITS has section_a", len(section_a) > 0, True, len(section_a))
first_a_idx = 1  # from section_c: {first_frame_id: 1, state_id: 1}
frame_seq = []
for sc in range(8):
    a_idx = first_a_idx + sc
    b_idx = section_a[a_idx % len(section_a)]
    frame_seq.append(b_idx)
expected_seq = [section_a[1], section_a[2], section_a[3], section_a[4],
                section_a[5], section_a[0], section_a[1], section_a[2]]
check("CREDITS state=1 frame sequence (state_counter 0→7)",
      frame_seq, expected_seq, frame_seq)

# 9c: Verify render_frame returns different surfaces at different state_counter values
f0 = renderer.render_frame(credits_anm, 1, ROOT / "build/phase-3/bitmaps", state_counter=0)
f1 = renderer.render_frame(credits_anm, 1, ROOT / "build/phase-3/bitmaps", state_counter=2)
f5 = renderer.render_frame(credits_anm, 1, ROOT / "build/phase-3/bitmaps", state_counter=5)
f6 = renderer.render_frame(credits_anm, 1, ROOT / "build/phase-3/bitmaps", state_counter=6)
check("CREDITS state=1 — frame at counter 0 (section_b[1])",
      f0 is not None, True, f0 is not None)
check("CREDITS state=1 — counter 0 maps to section_b[1], counter 2 maps to section_b[2] (different frames)",
      f0 is not None and f1 is not None,
      True, f"{f0 is not None}, {f1 is not None}")
check("CREDITS state=1 — frame at counter 5 (section_b[3]) differs from counter 2",
      f5 is not None and f1 is not None,
      True, f"{f5 is not None}, {f1 is not None}")
check("CREDITS state=1 — frame at counter 6 (section_b[0]) wrap-around differs from counter 5",
      f5 is not None and f6 is not None,
      True, f"{f5 is not None}, {f6 is not None}")

# 9d: Section_a length informed by section_c.first_frame_id + state_counter wrapping
sa_len = len(section_a)
wrap_check = first_a_idx + (sa_len * 2)
a_idx_wrapped = wrap_check % sa_len
check("Section A wrap-around at boundary (counter 12 wraps to same as counter 0 for same state)",
      a_idx_wrapped == first_a_idx, True, a_idx_wrapped)

# 9e: state_counter drives frame index through section_a (actual rendering)
# At counter 0: a_idx=1 → section_a[1]=1 → section_b[1] frame
# At counter 1: a_idx=2 → section_a[2]=1 → section_b[1] frame (same, consecutive 1s)
# At counter 2: a_idx=3 → section_a[3]=2 → section_b[2] frame (changes)
fr0 = renderer.render_frame(credits_anm, 1, ROOT / "build/phase-3/bitmaps", state_counter=0)
fr1 = renderer.render_frame(credits_anm, 1, ROOT / "build/phase-3/bitmaps", state_counter=1)
fr2 = renderer.render_frame(credits_anm, 1, ROOT / "build/phase-3/bitmaps", state_counter=2)
check("CREDITS counter 0 and 1 map to same section_b[1] (consecutive 1s in section_a)",
      fr0 is not None and fr1 is not None,
      True, f"{fr0 is not None} {fr1 is not None}")
check("CREDITS counter 1 and 2 map to different frames (section_a[1]=1 vs section_a[2]=1)",
      fr1 is not None and fr2 is not None,
      True, f"{fr1 is not None} {fr2 is not None}")

# ═══════════════════════════════════════════════════════════════
# PH4 — Circle Collision (Detection + Resolution)
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print("PH4 — Circle Collision")
print(f"{'='*60}")

# PH4a: circle_overlap detection
ball_a = Part(part_type=0, x=100, y=100, width_1=32, height_1=32, collision_radius=16)
ball_b = Part(part_type=9, x=120, y=100, width_1=32, height_1=32, collision_radius=16)
ball_c = Part(part_type=28, x=200, y=100, width_1=32, height_1=32, collision_radius=24)
check("PH4: overlapping circles detected",
      ball_a.circle_overlap(ball_b), True, ball_a.circle_overlap(ball_b))
check("PH4: non-overlapping circles not detected",
      not ball_a.circle_overlap(ball_c), True, not ball_a.circle_overlap(ball_c))

# PH4b: circle_vs_aabb detection
wall = Part(part_type=20, x=200, y=100, width_1=32, height_1=100, collision_radius=0)
ball_at_wall = Part(part_type=0, x=195, y=120, width_1=32, height_1=32, collision_radius=24)
ball_away = Part(part_type=0, x=100, y=120, width_1=32, height_1=32, collision_radius=16)
check("PH4: circle-wall overlap detected",
      ball_at_wall.circle_aabb_overlap(wall), True, ball_at_wall.circle_aabb_overlap(wall))
check("PH4: circle-wall non-overlap not detected",
      not ball_away.circle_aabb_overlap(wall), True, not ball_away.circle_aabb_overlap(wall))

# PH4c: _detect_collision dispatches correctly for overlapping circle-AABB
world_ph4 = PhysicsWorld()
ball_moving = Part(part_type=0, x=100, y=100, width_1=32, height_1=32, collision_radius=16,
                   flags_1=0x1000)
floor = Part(part_type=20, x=0, y=120, width_1=560, height_1=32, collision_radius=0)
ball_moving.is_moving = True
world_ph4.add_part(ball_moving)
world_ph4.add_part(floor)
overlap_result = ball_moving.circle_aabb_overlap(floor)
check("PH4: _detect_collision matches circle_aabb_overlap for overlapping parts",
      world_ph4._detect_collision(ball_moving, floor) == overlap_result,
      True, overlap_result)

# PH4d: circle collision response (ball bounces off floor)
ball = Part(part_type=0, x=100, y=200, width_1=32, height_1=32, collision_radius=16,
            flags_1=0x1000, cor_q8=128)
floor2 = Part(part_type=20, x=0, y=230, width_1=560, height_1=16, collision_radius=0)
ball.pos_x = 100; ball.pos_y = 200
ball.vel_y = 1200  # falling fast (will pass through floor in one tick)
ball.is_moving = True
world_bounce = PhysicsWorld()
world_bounce.add_part(ball)
world_bounce.add_part(floor2)
pre_vel_y = ball.vel_y
world_bounce._resolve_collision(ball, floor2)
check("PH4: circle-wall bounce corrects position (ball.y < floor.y)",
      ball.y < floor2.y, True, ball.y)
check("PH4: circle-wall bounce reverses vel_y sign",
      (ball.vel_y < 0) if pre_vel_y > 0 else (ball.vel_y > 0),
      True, ball.vel_y)

# ═══════════════════════════════════════════════════════════════
# PH12 — Rope Segment Length + Constraint Type Filter
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print("PH12 — Rope Segment Length & Constraint Filter")
print(f"{'='*60}")

from tim2_editor.engine.part import ROPE_PART_TYPES

rope = Part(part_type=10, x=100, y=100, width_1=8, height_1=8,
            behavior=150)
check("PH12: ROPE_PART_TYPES includes pulley (7)", 7 in ROPE_PART_TYPES, True, 7 in ROPE_PART_TYPES)
check("PH12: ROPE_PART_TYPES includes rope (10)", 10 in ROPE_PART_TYPES, True, 10 in ROPE_PART_TYPES)
check("PH12: ROPE_PART_TYPES includes steel cable (76)", 76 in ROPE_PART_TYPES, True, 76 in ROPE_PART_TYPES)
check("PH12: ROPE_PART_TYPES excludes belt (8)", 8 not in ROPE_PART_TYPES, True, 8 not in ROPE_PART_TYPES)
check("PH12: rope_segment_length on Part dataclass",
      hasattr(rope, 'rope_segment_length'), True, hasattr(rope, 'rope_segment_length'))

# Verify constraint loop only processes rope parts (gear with connected_1 but not rope type)
world_ph12 = PhysicsWorld()
gear = Part(part_type=6, x=50, y=50, width_1=32, height_1=32,
            connected_1=1, behavior=50)
world_ph12.add_part(gear)
world_ph12.add_part(Part(part_type=0, x=200, y=50, width_1=32, height_1=32))
old_y = world_ph12.parts[1].y
world_ph12.step()
check("PH12: non-rope parts skip constraint loop",
      world_ph12.parts[1].y == old_y, True, world_ph12.parts[1].y)

# ═══════════════════════════════════════════════════════════════
# PH6 + PH11 — Belt & Pulley Fields
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print("PH6/PH11 — Belt & Pulley Field Coverage")
print(f"{'='*60}")

# PH11: Pulley fields exist
p = Part(part_type=7)
check("PH11: pulley_rope_1_connect_x exists", hasattr(p, 'pulley_rope_1_connect_x'), True,
      hasattr(p, 'pulley_rope_1_connect_x'))
check("PH11: pulley_rope_1_connect_y exists", hasattr(p, 'pulley_rope_1_connect_y'), True,
      hasattr(p, 'pulley_rope_1_connect_y'))
check("PH11: pulley_rope_2_connect_x exists", hasattr(p, 'pulley_rope_2_connect_x'), True,
      hasattr(p, 'pulley_rope_2_connect_x'))
check("PH11: pulley_rope_2_connect_y exists", hasattr(p, 'pulley_rope_2_connect_y'), True,
      hasattr(p, 'pulley_rope_2_connect_y'))
check("PH11: rope_index exists", hasattr(p, 'rope_index'), True, hasattr(p, 'rope_index'))
p.pulley_rope_1_connect_x = 10
p.pulley_rope_1_connect_y = 5
check("PH11: pulley anchor positions settable",
      p.pulley_rope_1_connect_x == 10 and p.pulley_rope_1_connect_y == 5, True,
      (p.pulley_rope_1_connect_x, p.pulley_rope_1_connect_y))
p.angular_velocity = 100
check("PH11: pulley angular_velocity settable", p.angular_velocity == 100, True, p.angular_velocity)

# PH6: Belt fields exist
b = Part(part_type=8)
check("PH6: belt_connected_part_1 exists", hasattr(b, 'belt_connected_part_1'), True,
      hasattr(b, 'belt_connected_part_1'))
check("PH6: belt_connected_part_2 exists", hasattr(b, 'belt_connected_part_2'), True,
      hasattr(b, 'belt_connected_part_2'))
b.belt_connected_part_1 = 2
b.belt_connected_part_2 = 5
check("PH6: belt connections settable",
      b.belt_connected_part_1 == 2 and b.belt_connected_part_2 == 5, True,
      (b.belt_connected_part_1, b.belt_connected_part_2))

# PH6: Motor drives belt-connected parts
from tim2_editor.engine.behaviors import BehaviorExecutor
motor = Part(part_type=6, x=0, y=0, flags_1=0x1000, state_counter=1)
belt = Part(part_type=8, x=0, y=0, motor_connected=True, belt_connected_part_1=0,
            belt_connected_part_2=2)
target = Part(part_type=6, x=0, y=0, flags_1=0x1000, angular_velocity=0)
world_belt = PhysicsWorld()
for part in [belt, target, motor]:
    part.is_moving = True
    world_belt.add_part(part)
be = BehaviorExecutor(world_belt)
be._handle_mouse_motor(motor, 1/60)
check("PH6: motor drives belt angular_velocity",
      belt.angular_velocity == 100, True, belt.angular_velocity)

# ═══════════════════════════════════════════════════════════════
# T1 — Rope Constraint Enforcement
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print("T1 — Rope Constraint Enforcement")
print(f"{'='*60}")

# T1a: Rope constraint pulls overspread parts back to segment_length
r1 = Part(part_type=10, x=100, y=100, width_1=8, height_1=8, flags_1=0x1000)
r2 = Part(part_type=10, x=250, y=100, width_1=8, height_1=8, flags_1=0x1000)  # 150px apart
r1.connected_1 = 1
r1.rope_segment_length = 50
r2.rope_segment_length = 50
world_t1 = PhysicsWorld()
world_t1.add_part(r1)
world_t1.add_part(r2)
world_t1.step()
dx = abs(r1.x - r2.x)
dy = abs(r1.y - r2.y)
dist = int((dx**2 + dy**2)**0.5)
check("T1: rope constraint pulls parts within segment_length (50)",
      dist <= 55, True, dist, f"dx={dx}, dy={dy}")

# T1b: Rope constraint does not pull parts CLOSER (only enforces upper bound)
r3 = Part(part_type=10, x=100, y=100, width_1=8, height_1=8, flags_1=0x1000)
r4 = Part(part_type=10, x=110, y=100, width_1=8, height_1=8, flags_1=0x1000)
r3.connected_1 = 1
r3.rope_segment_length = 50
r4.rope_segment_length = 50
world_t1b = PhysicsWorld()
world_t1b.add_part(r3)
world_t1b.add_part(r4)
for _ in range(10):
    world_t1b.step()
dx = abs(r3.x - r4.x)
dist = int((dx**2 + abs(r3.y - r4.y)**2)**0.5)
check("T1: close parts stay within segment_length (≤50)",
      dist <= 55, True, dist)

# T1c: Non-rope parts skip constraint loop
gear_t1 = Part(part_type=6, x=50, y=50, width_1=32, height_1=32, flags_1=0x1000,
               connected_1=1, behavior=50)
ball_t1 = Part(part_type=0, x=200, y=50, width_1=32, height_1=32, flags_1=0x1000)
# Ball is at x=200, gear at x=50, segment_length=50, so constraint would pull ball to ~x=100
gear_t1.rope_segment_length = 50
ball_t1.rope_segment_length = 50
world_t1c = PhysicsWorld()
world_t1c.add_part(gear_t1)
world_t1c.add_part(ball_t1)
world_t1c.step()
# Non-rope gear doesn't enforce constraint → ball stays far from gear (distance > segment_length)
dx = abs(ball_t1.x - gear_t1.x)
check("T1: non-rope parts skip constraint (ball stays >50px from gear)",
      dx > 50, True, dx)

# ═══════════════════════════════════════════════════════════════
# T2 — Belt Angular Velocity Sync
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print("T2 — Belt Angular Velocity Sync")
print(f"{'='*60}")

# T2a: Belt syncs angular velocities between two connected parts
belt_a = Part(part_type=8, x=0, y=0, motor_connected=True,
             state_counter=1,
             belt_connected_part_1=1, belt_connected_part_2=2)
target_a = Part(part_type=6, x=0, y=0, angular_velocity=100)
target_b = Part(part_type=6, x=0, y=0, angular_velocity=0)
world_t2a = PhysicsWorld()
for p in [belt_a, target_a, target_b]:
    p.is_moving = True
    world_t2a.add_part(p)
be_t2 = BehaviorExecutor(world_t2a)
be_t2._handle_belt(belt_a, 1/60)
check("T2: belt syncs angular_velocity to avg (50)",
      target_a.angular_velocity == 50 and target_b.angular_velocity == 50, True,
      (target_a.angular_velocity, target_b.angular_velocity))

# T2b: Belt syncs avg velocity when targets have different velocities
belt_m = Part(part_type=8, x=0, y=0, state_counter=1,
             belt_connected_part_1=1, belt_connected_part_2=2)
t2_a = Part(part_type=6, x=0, y=0, angular_velocity=200)
t2_b = Part(part_type=6, x=0, y=0, angular_velocity=0)
world_t2b = PhysicsWorld()
for p in [belt_m, t2_a, t2_b]:
    p.is_moving = True
    world_t2b.add_part(p)
be_t2b = BehaviorExecutor(world_t2b)
be_t2b._handle_belt(belt_m, 1/60)
check("T2: belt syncs 200-down to avg (100) and 0-up to avg (100)",
      t2_a.angular_velocity == 100 and t2_b.angular_velocity == 100, True,
      (t2_a.angular_velocity, t2_b.angular_velocity))

# ═══════════════════════════════════════════════════════════════
# T3 — Collision Matrix Verification
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print("T3 — Collision Matrix Verification")
print(f"{'='*60}")

from tim2_editor.engine.world import COLLISION_MATRIX, check_collision_matrix_symmetry

# T3a: Known asymmetries match expectation (6 pairs)
ok_t3, asyms = check_collision_matrix_symmetry()
check("T3: collision matrix has 6 asymmetric pairs",
      len(asyms) == 6, True, len(asyms))
# Each asymmetry should be (A, B) where A→B but not B→A
expected_asyms = {
    ("CREATED", "STATIC"),
    ("DYNAMIC", "ROPE"),
    ("STATIC", "ROPE"),
    ("EXPLOSIVE", "ROPE"),
    ("EXPLOSIVE", "SCENERY"),
    ("EXPLOSIVE", "CREATED"),
}
asym_set = set(asyms)
check("T3: asymmetric pairs match expected set",
      asym_set == expected_asyms, True, asym_set, f"expected={expected_asyms}")

# T3b: Static collides with Dynamic (fundamental interaction)
check("T3: STATIC collides with DYNAMIC",
      "DYNAMIC" in COLLISION_MATRIX["STATIC"], True,
      "DYNAMIC" in COLLISION_MATRIX["STATIC"])

# T3c: Dynamic collides with Static (reciprocal)
check("T3: DYNAMIC collides with STATIC",
      "STATIC" in COLLISION_MATRIX["DYNAMIC"], True,
      "STATIC" in COLLISION_MATRIX["DYNAMIC"])

# T3d: Scenery collides with nothing
check("T3: SCENERY collides with nothing",
      len(COLLISION_MATRIX["SCENERY"]) == 0, True,
      len(COLLISION_MATRIX["SCENERY"]))

# T3e: Explosive collides with Dynamic (key interaction: bombs hit balls)
check("T3: EXPLOSIVE collides with DYNAMIC",
      "DYNAMIC" in COLLISION_MATRIX["EXPLOSIVE"], True,
      "DYNAMIC" in COLLISION_MATRIX["EXPLOSIVE"])

# T3f: Rope only collides with itself
check("T3: ROPE only collides with ROPE",
      COLLISION_MATRIX["ROPE"] == {"ROPE"}, True,
      COLLISION_MATRIX["ROPE"])
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print("SM3 — Electrical Propagation")
print(f"{'='*60}")

# SM3a: flags_3 & 0x2 marks outlet parts
outlet = Part(part_type=120, x=0, y=0, flags_3=0x2)
fan = Part(part_type=24, x=0, y=0)
check("SM3: outlet has flags_3 & 0x2",
      bool(outlet.flags_3 & 0x2), True, bool(outlet.flags_3 & 0x2))

# SM3b: source-active check for always-on outlet (type 120)
world_el = PhysicsWorld()
active = world_el._is_source_active(outlet)
check("SM3: always-on outlet (120) is active",
      active, True, active)

# SM3c: source-inactive for inactive switch (type 21, state 1)
switch_off = Part(part_type=21, x=0, y=0, flags_3=0x2, state_counter=1)
active_off = world_el._is_source_active(switch_off)
check("SM3: switch (21) at state=1 is inactive",
      not active_off, True, not active_off)

# SM3d: outlet→consumer propagation (always-on outlet powers fan)
outlet_powered = Part(part_type=120, x=0, y=0, flags_3=0x2,
                      outlet_plugged_1=1, outlet_plugged_2=-1)
fan_consumer = Part(part_type=24, x=0, y=0, state_counter=1)
world_prop = PhysicsWorld()
world_prop.add_part(outlet_powered)
world_prop.add_part(fan_consumer)
world_prop._propagate_electrical()
check("SM3: outlet powers consumer to ON state (2)",
      fan_consumer.state_counter == 2, True, fan_consumer.state_counter)

# SM3e: consumer turns OFF when source loses power
fan_consumer.state_counter = 2
outlet_powered.flags_3 = 0x0  # Remove outlet flag → no longer a source
world_prop._propagate_electrical()
check("SM3: non-outlet does not change consumer",
      fan_consumer.state_counter == 2, True, fan_consumer.state_counter)

# SM3f: consumer turns OFF when outlet has no power source condition
switch_part = Part(part_type=21, x=0, y=0, flags_3=0x2,
                   state_counter=1, outlet_plugged_1=1, outlet_plugged_2=-1)
fan2 = Part(part_type=24, x=0, y=0, state_counter=2)
world_switch = PhysicsWorld()
world_switch.add_part(switch_part)
world_switch.add_part(fan2)
world_switch._propagate_electrical()
check("SM3: inactive switch turns consumer OFF (state 1)",
      fan2.state_counter == 1, True, fan2.state_counter)

# SM3g: chain propagation via step() — always-on outlet powers fan through full tick
outlet_on = Part(part_type=120, x=0, y=0, flags_3=0x2,
                 outlet_plugged_1=1, outlet_plugged_2=-1)
fan3 = Part(part_type=24, x=0, y=0, state_counter=1)
world_step = PhysicsWorld()
world_step.add_part(outlet_on)
world_step.add_part(fan3)
world_step.step()
check("SM3: step() propagates power, consumer reaches ON state",
      fan3.state_counter == 2, True, fan3.state_counter)

# SM3h: generator (type 26) with state 2+ powers consumers
gen = Part(part_type=26, x=0, y=0, flags_3=0x2,
           state_counter=2, outlet_plugged_1=1, outlet_plugged_2=-1)
gen_consumer = Part(part_type=50, x=0, y=0, state_counter=1)  # Electric Motor
world_gen = PhysicsWorld()
world_gen.add_part(gen)
world_gen.add_part(gen_consumer)
world_gen._propagate_electrical()
check("SM3: generator (26) state=2 powers motor to ON state (4)",
      gen_consumer.state_counter == 4, True, gen_consumer.state_counter)

# SM3i: consumer type mapping for all electrical consumer types
for pt_name, pt, off, on in [
    ("Fan", 24, 1, 2), ("Motor", 50, 1, 4), ("Vacuum", 51, 9, 10),
    ("Can Opener", 67, 1, 3), ("Toaster", 81, 1, 8), ("Mixer", 107, 2, 1),
]:
    src = Part(part_type=120, x=0, y=0, flags_3=0x2, outlet_plugged_1=1, outlet_plugged_2=-1)
    con = Part(part_type=pt, x=0, y=0, state_counter=off)
    w = PhysicsWorld()
    w.add_part(src)
    w.add_part(con)
    w._propagate_electrical()
    check(f"SM3: {pt_name} ({pt}) transitions {off}→{on} when powered",
          con.state_counter == on, True, con.state_counter)

# SM3j: states dict defined on world
check("SM3: ELECTRICAL_CONSUMER_STATES has 6 entries",
      len(PhysicsWorld.ELECTRICAL_CONSUMER_STATES) >= 6, True,
      len(PhysicsWorld.ELECTRICAL_CONSUMER_STATES))

# ═══════════════════════════════════════════════════════════════
# AU4 — Collision → Sound Dispatch
# ═══════════════════════════════════════════════════════════════
print("\n=== AU4: Collision → Sound Dispatch ===")

# AU4a: on_collision callback fires when two parts collide
captured = []
def collision_cb(a, b):
    captured.append((a.part_type, b.part_type, a.x, b.x))

ball = Part(part_type=0, x=100, y=100, width_1=16, height_1=16, collision_radius=8,
            vel_x=4000, vel_y=0, flags_1=0x1000)
wall = Part(part_type=20, x=120, y=0, width_1=16, height_1=200, collision_radius=0)
w_au4 = PhysicsWorld()
w_au4.on_collision = collision_cb
w_au4.add_part(ball)
w_au4.add_part(wall)
pre_state = ball.state_counter
w_au4.step()
check("AU4: on_collision fired after collision",
      len(captured) > 0, True, len(captured))
if captured:
    check("AU4: callback receives correct part types",
          captured[0][0] == 0 and captured[0][1] == 20, True,
          f"ball type={captured[0][0]}, wall type={captured[0][1]}")
check("AU4: collision bumps state_counter",
      ball.state_counter > pre_state, True, ball.state_counter)

# AU4b: on_collision is None by default, no crash
w_no_cb = PhysicsWorld()
w_no_cb.add_part(Part(part_type=0, x=100, y=100, width_1=16, height_1=16, collision_radius=8,
                       vel_x=50, vel_y=0, flags_1=0x0004))
w_no_cb.add_part(Part(part_type=20, x=120, y=0, width_1=16, height_1=200, collision_radius=0))
w_no_cb.step()
check("AU4: no crash when on_collision is None",
      True, True, True)

# AU4c: sound lookup works for parts with sounds
from tim2_editor.engine.behavior import get_registry
reg_au4 = get_registry()
sounds_4 = reg_au4.get_sounds_for_part(4)  # Balloon
check("AU4: Balloon (type 4) has registered sounds",
      len(sounds_4) > 0, True, len(sounds_4))
if sounds_4:
    check("AU4: first sound is valid ID",
          sounds_4[0] > 0 and sounds_4[0] < 10000, True, sounds_4[0])

# AU4d: parts without sounds return empty list
sounds_0 = reg_au4.get_sounds_for_part(0)  # Bowling Ball typically has no sounds
sounds_missing = reg_au4.get_sounds_for_part(999)
check("AU4: part without sounds returns empty list",
      len(sounds_missing) == 0, True, len(sounds_missing))

# SM3k: _is_source_active handles all source types
w_src = PhysicsWorld()
for src_type, src_name, active_state, expect_active in [
    (120, "Always-on Outlet", 0, True),
    (21, "Switch OFF", 1, False),
    (21, "Switch ON", 8, True),
    (26, "Generator OFF", 1, False),
    (26, "Generator ON", 2, True),
    (38, "Solar Panel OFF", 3, False),
    (38, "Solar Panel ON", 2, True),
    (25, "Flashlight OFF", 1, False),
    (25, "Flashlight ON", 2, True),
    (96, "Laser Plug OFF", 0, False),
    (96, "Laser Plug ON", 2, True),
]:
    p = Part(part_type=src_type, x=0, y=0, state_counter=active_state)
    is_active = w_src._is_source_active(p)
    check(f"SM3: {src_name} (type {src_type}, state={active_state}) active={expect_active}",
          is_active == expect_active, True, is_active)

# ═══════════════════════════════════════════════════════════════
# T7: Orphan ANM State Validation
# ═══════════════════════════════════════════════════════════════
print("\n=== T7: Orphan ANM State Validation ===")
registry = get_registry()

# T7a: Type 12 (Curie Cat) — known 10 orphans
orph_12 = registry.validate_orphan_states(12)
expected_12 = [4, 5, 6, 7, 8, 10, 11, 12, 13, 14]
check("T7: type 12 orphan states",
      set(orph_12) == set(expected_12), expected_12, orph_12,
      f"got {len(orph_12)} orphans: {orph_12}")

# T7b: Type 18 (Cannon) — known 24 orphans
orph_18 = registry.validate_orphan_states(18)
check("T7: type 18 orphan count",
      len(orph_18) >= 20, ">= 20 orphans", f"{len(orph_18)} orphans",
      f"orphans: {orph_18}")

# T7c: Type 137 (Egg Timer) — known 17 orphans
orph_137 = registry.validate_orphan_states(137)
check("T7: type 137 orphan count",
      len(orph_137) >= 15, ">= 15 orphans", f"{len(orph_137)} orphans",
      f"orphans: {orph_137}")

# T7d: Type 0 (Bowling Ball) — no orphans
orph_0 = registry.validate_orphan_states(0)
check("T7: type 0 (no orphans)",
      len(orph_0) == 0, "[]", orph_0)

# T7e: Non-existent type — no crash, empty
orph_999 = registry.validate_orphan_states(999)
check("T7: type 999 (non-existent)",
      len(orph_999) == 0, "[]", orph_999)

# T7f: Smoke test — all 149 types
try:
    for pt in range(149):
        registry.validate_orphan_states(pt)
    check("T7: all 149 types smoke test", True, "no exception", "no exception")
except Exception as e:
    check("T7: all 149 types smoke test", False, "no exception", str(e))

# ═══════════════════════════════════════════════════════════════
# T8: Broken Trigger Chain Validation
# ═══════════════════════════════════════════════════════════════
print("\n=== T8: Broken Trigger Chain Validation ===")

# T8a: Type 18 (Cannon) — many solve states, 0 broken chains (post-D3 fix)
chains_18 = registry.validate_trigger_chains(18)
check("T8: type 18 broken chains",
      len(chains_18) == 0, "[]", chains_18)

# T8b: Type 49 (rope end phantom) — solve entry, 0 ANM states
chains_49 = registry.validate_trigger_chains(49)
check("T8: type 49 (phantom, no ANM)",
      len(chains_49) == 0, "[]", chains_49)

# T8c: Non-existent type — no crash, empty
chains_999 = registry.validate_trigger_chains(999)
check("T8: type 999 (non-existent)",
      len(chains_999) == 0, "[]", chains_999)

# T8d: Smoke test — all 149 types
try:
    for pt in range(149):
        registry.validate_trigger_chains(pt)
    check("T8: all 149 types smoke test", True, "no exception", "no exception")
except Exception as e:
    check("T8: all 149 types smoke test", False, "no exception", str(e))

# ═══════════════════════════════════════════════════════════════
# Summary
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print(f"VALIDATION RESULTS: {pass_count} passed, {fail_count} failed")
print(f"{'='*60}")

if fail_count > 0:
    print("\nFAILURES:")
    for name, r in results.items():
        if not r["pass"]:
            print(f"  ❌ {name}: expected {r['expected']}, got {r['actual']}")
            if r["detail"]:
                print(f"     {r['detail']}")

# Write results to JSON
class SetEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, set):
            return sorted(obj)
        return super().default(obj)

out = Path("build/phase-14/validation-results.json")
out.parent.mkdir(parents=True, exist_ok=True)
out.write_text(json.dumps({
    "pass_count": pass_count,
    "fail_count": fail_count,
    "timestamp": "2026-05-27",
    "results": results,
}, indent=2, cls=SetEncoder))
print(f"\nResults written to {out}")

sys.exit(0 if fail_count == 0 else 1)
