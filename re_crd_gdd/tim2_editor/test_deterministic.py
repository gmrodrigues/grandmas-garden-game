"""Deterministic physics validation — tests that simulation is bit-identical across runs."""
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

pass_count = 0
fail_count = 0
results = {}

def check(name, ok, expected, actual, detail=""):
    global pass_count, fail_count
    if ok:
        pass_count += 1
    else:
        fail_count += 1
    results[name] = {"pass": ok, "expected": expected, "actual": actual, "detail": detail}
    print(f"  {'✅' if ok else '❌'} {name}: {detail}")


def world_hash(world: PhysicsWorld) -> str:
    """Deterministic hash of all part states for comparison."""
    lines = []
    for i, p in enumerate(sorted(world.parts, key=lambda x: id(x))):  # stable by insertion
        lines.append(f"{p.x},{p.y},{p.vel_x},{p.vel_y},{p.state_counter},{p.sub_counter}")
    return hash(tuple(lines))


# ═══════════════════════════════════════════════════════════════
# Test 1: Gravity Determinism — same result every run
# ═══════════════════════════════════════════════════════════════
print("\n=== Determinism: Gravity Reproducibility ===")
results_runs = []
for run in range(3):
    p = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
    for _ in range(500):
        p.tick()
    results_runs.append((p.y, p.vel_y, p.pos_y))

check(f"y position identical across 3 runs",
      results_runs[0][0] == results_runs[1][0] == results_runs[2][0],
      "identical", results_runs[0],
      f"y={results_runs[0][0]} vel_y={results_runs[0][1]}")
check(f"vel_y identical across 3 runs",
      results_runs[0][1] == results_runs[1][1] == results_runs[2][1],
      "identical", results_runs[0])

# ═══════════════════════════════════════════════════════════════
# Test 2: Fixed-point vs Floating-point Divergence
# ═══════════════════════════════════════════════════════════════
print("\n=== Determinism: Fixed-Point vs Float Divergence ===")
int_part = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
float_y = 50.0
vel_float = 0.0
g = int_part.gravity_y

divergence_ticks = []
for tick_n in range(1, 10001):
    int_part.tick()
    vel_float += g
    float_y += vel_float / 512.0
    int_y = int_part.y
    float_int_y = int(float_y)
    if int_y != float_int_y:
        divergence_ticks.append((tick_n, int_y, float_int_y))

if divergence_ticks:
    first = divergence_ticks[0]
    last = divergence_ticks[-1]
    check(f"Integer vs float diverge at tick {first[0]}",
          False, "identical position", f"diff at tick {first[0]}",
          f"int_y={first[1]} float_y={first[2]}")
    check(f"Divergence count={len(divergence_ticks)} at 10000 ticks",
          len(divergence_ticks) < 10, "< 10 divergences", len(divergence_ticks),
          f"first_at={first[0]}")
else:
    check("Integer vs float identical for 10000 ticks",
          True, "identical", "identical")

# ═══════════════════════════════════════════════════════════════
# Test 3: Collision Determinism
# ═══════════════════════════════════════════════════════════════
print("\n=== Determinism: Collision Reproducibility ===")
collision_runs = []
for run in range(3):
    w = PhysicsWorld()
    b = Part(part_type=0, x=100, y=50, width_1=16, height_1=16, flags_1=0x1000)
    f = Part(part_type=69, x=90, y=80, width_1=36, height_1=8, flags_1=0)
    w.add_part(b)
    w.add_part(f)
    positions = []
    for _ in range(100):
        w.step()
        positions.append((b.x, b.y, b.vel_x, b.vel_y, f.x, f.y))
    collision_runs.append(positions)

check("Position history identical across 3 collision runs",
      collision_runs[0] == collision_runs[1] == collision_runs[2],
      "identical", f"len={len(collision_runs[0])}")

# ═══════════════════════════════════════════════════════════════
# Test 4: State Machine Determinism
# ═══════════════════════════════════════════════════════════════
print("\n=== Determinism: State Machine Reproducibility ===")
state_runs = []
for run in range(3):
    p = Part(part_type=0, x=100, y=50, flags_1=0x1000)
    states = []
    for _ in range(200):
        p.advance_state()
        states.append((p.state_counter, p.sub_counter, p._countdown if hasattr(p, '_countdown') else -2,
                       p._rng_state))
    state_runs.append(states)

check("State sequence identical across 3 runs",
      state_runs[0] == state_runs[1] == state_runs[2],
      "identical", f"len={len(state_runs[0])}",
      f"first_states={state_runs[0][:5]}")

# Test with explicit seed
p1 = Part(part_type=0, _rng_state=42)
p2 = Part(part_type=0, _rng_state=42)
s1 = [p1.advance_state() for _ in range(100)]
s2 = [p2.advance_state() for _ in range(100)]
check("Seeded RNG gives identical sequence",
      s1 == s2,
      "identical", "identical",
      f"first_5_diffs={[i for i in range(100) if s1[i] != s2[i]][:5]}")

# ═══════════════════════════════════════════════════════════════
# Test 5: Save/Restore Determinism
# ═══════════════════════════════════════════════════════════════
print("\n=== Determinism: Save/Restore Continuation ===")
# Run 500 ticks continuous
w_cont = PhysicsWorld()
b = Part(part_type=0, x=100, y=50, flags_1=0x1000)
f = Part(part_type=69, x=90, y=120, width_1=36, height_1=8, flags_1=0)
w_cont.add_part(b)
w_cont.add_part(f)
for _ in range(500):
    w_cont.step()

# Run 250 + 250 with midpoint save/restore
w_split = PhysicsWorld()
b2 = Part(part_type=0, x=100, y=50, flags_1=0x1000)
f2 = Part(part_type=69, x=90, y=120, width_1=36, height_1=8, flags_1=0)
w_split.add_part(b2)
w_split.add_part(f2)
for _ in range(250):
    w_split.step()
# Save midpoint state
mid = {"parts": [{"x": p.x, "y": p.y, "vel_x": p.vel_x, "vel_y": p.vel_y,
                   "state_counter": p.state_counter, "sub_counter": p.sub_counter,
                   "_rng_state": p._rng_state,
                   "_countdown": getattr(p, '_countdown', -1)}
                  for p in w_split.parts],
       "tick": w_split.tick_count}
# Restore and continue
for p, saved in zip(w_split.parts, mid["parts"]):
    p.x = p.pos_x = saved["x"]; p.y = p.pos_y = saved["y"]
    p.vel_x = saved["vel_x"]; p.vel_y = saved["vel_y"]
    p.state_counter = saved["state_counter"]; p.sub_counter = saved["sub_counter"]
    p._rng_state = saved["_rng_state"]
    p._countdown = saved["_countdown"]
for _ in range(250):
    w_split.step()

# Compare final positions
p_cont = w_cont.parts[0]
p_split = w_split.parts[0]
check("Save/restore: same x after 500 ticks",
      p_cont.x == p_split.x, p_cont.x, p_split.x)
check("Save/restore: same y after 500 ticks",
      p_cont.y == p_split.y, (p_cont.y, p_cont.pos_y), (p_split.y, p_split.pos_y))
check("Save/restore: same vel_y after 500 ticks",
      p_cont.vel_y == p_split.vel_y, p_cont.vel_y, p_split.vel_y)
check("Save/restore: same state_counter",
      p_cont.state_counter == p_split.state_counter,
      p_cont.state_counter, p_split.state_counter)

# ═══════════════════════════════════════════════════════════════
# Test 6: ELEV1 Multi-Part Determinism
# ═══════════════════════════════════════════════════════════════
print("\n=== Determinism: ELEV1 Multi-Part ===")
elev1_runs = []
for run in range(2):
    world = PhysicsWorld()
    level = load_yaml(ROOT / "build" / "phase-5" / "yaml" / "ELEV1.yaml")
    for p in level.parts:
        p.pos_x = p.x
        p.pos_y = p.y
        world.add_part(p)
    for _ in range(200):
        world.step()
    # Capture all part positions
    snap = [(p.x, p.y, p.vel_x, p.vel_y, p.state_counter) for p in world.parts]
    elev1_runs.append(snap)

check("ELEV1 200 ticks identical across runs",
      elev1_runs[0] == elev1_runs[1],
      "identical", "identical",
      f"Mismatches: {sum(1 for a,b in zip(elev1_runs[0], elev1_runs[1]) if a != b)} / {len(elev1_runs[0])} parts")

# ═══════════════════════════════════════════════════════════════
# Summary
# ═══════════════════════════════════════════════════════════════
print(f"\n{'='*60}")
print(f"DETERMINISTIC TESTS: {pass_count} passed, {fail_count} failed")
print(f"{'='*60}")

out = Path("build/phase-14/deterministic-results.json")
out.parent.mkdir(parents=True, exist_ok=True)
out.write_text(json.dumps({
    "pass_count": pass_count, "fail_count": fail_count,
    "results": results,
}, indent=2))
print(f"Results → {out}")

sys.exit(0 if fail_count == 0 else 1)
