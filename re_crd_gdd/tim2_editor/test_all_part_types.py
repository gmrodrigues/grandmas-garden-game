#!/usr/bin/env python3
"""T5: Programmatically create + simulate all 149 part types (0-148).

For each part type:
  1. Create Part with default physics properties
  2. Add to a PhysicsWorld
  3. Run 10 ticks
  4. Verify no exception
Reports per-type results to build/phase-14/all-part-types-results.json
"""
import sys, os, json, traceback
from pathlib import Path
os.environ["SDL_VIDEODRIVER"] = "dummy"
import pygame
pygame.init()
pygame.display.set_mode((640, 480))

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from tim2_editor.engine.part import Part, DEFAULT_MAX_GRAVITY, PAR20_43_MAX_GRAVITY
from tim2_editor.engine.world import PhysicsWorld, COLLISION_CATEGORY_MAP
from tim2_editor.engine.behavior import get_registry

PART_TYPE_RANGE = range(0, 149)  # 0 through 148 inclusive
RESULTS_DIR = ROOT / "build" / "phase-14"
SIM_TICKS = 10

RESULTS_DIR.mkdir(parents=True, exist_ok=True)
registry = get_registry()

# Load name catalog for readable names
name_catalog_raw = json.loads((ROOT / "build" / "phase-9" / "part-name-catalog.json").read_text())
name_lookup = {e["part_type"]: e.get("name", "Unknown") for e in name_catalog_raw}

results = {}
pass_count = 0
fail_count = 0

for pt in PART_TYPE_RANGE:
    name = name_lookup.get(pt, f"Type {pt}")
    entry = {"part_type": pt, "name": name, "ticks": 0}

    try:
        part = Part(
            part_type=pt,
            x=160, y=200,
            width_1=32, height_1=32,
            flags_1=0x1000,
        )

        phys = registry.get_physics_props(pt)
        part.mass = phys["mass"]
        part.cor_q8 = phys["cor_q8"]
        part.friction_q8 = phys["friction_q8"]
        part.collision_radius = phys["collision_radius"]
        if phys["collision_w"] > 0:
            part.collision_w = phys["collision_w"]
        if phys["collision_h"] > 0:
            part.collision_h = phys["collision_h"]

        for pt_special, max_g in [(20, PAR20_43_MAX_GRAVITY), (43, PAR20_43_MAX_GRAVITY)]:
            if pt == pt_special:
                part.max_gravity = max_g
                break

        world = PhysicsWorld()
        world.add_part(part)

        for _ in range(SIM_TICKS):
            world.step()

        entry["status"] = "PASS"
        entry["ticks"] = world.tick_count
        pass_count += 1

    except Exception as e:
        entry["status"] = "FAIL"
        entry["error"] = traceback.format_exc()
        fail_count += 1

    results[str(pt)] = entry

# Summary
summary = {
    "total_types": len(PART_TYPE_RANGE),
    "pass": pass_count,
    "fail": fail_count,
    "ticks_per_type": SIM_TICKS,
    "failed_types": [int(k) for k, v in results.items() if v["status"] == "FAIL"],
}

with open(RESULTS_DIR / "all-part-types-results.json", "w") as f:
    json.dump({"summary": summary, "results": results}, f, indent=2)

# Print
print(f"{'='*60}")
print(f"T5: All 149 Part Types Simulate ({SIM_TICKS} ticks each)")
print(f"{'='*60}")
for pt in PART_TYPE_RANGE:
    entry = results[str(pt)]
    glyph = "\u2705" if entry["status"] == "PASS" else "\u274C"
    print(f"  {glyph} Type {pt:>3d} ({entry['name']}): {entry['status']} ({entry['ticks']} ticks)")
    if entry["status"] == "FAIL":
        err = entry.get("error", "unknown")
        first_line = err.split("\n")[0] if err else "unknown"
        print(f"     {first_line}")

print(f"{'-'*60}")
print(f"  Total: {pass_count} passed, {fail_count} failed")
print(f"  Results saved to {RESULTS_DIR / 'all-part-types-results.json'}")
print(f"{'='*60}")

sys.exit(0 if fail_count == 0 else 1)
