#!/usr/bin/env python3
"""T4: Bulk-load all 206 levels, verify load + simulate for N ticks.

Phases:
  A — load_yaml() each file, verify LevelData integrity
  B — create PhysicsWorld, add parts, run 10 ticks
Reports per-level results to build/phase-14/load-all-levels-results.json
"""
import sys, os, json, traceback, logging
from pathlib import Path

logging.basicConfig(level=logging.WARNING)
logging.getLogger("tim2_editor.engine.behavior").setLevel(logging.ERROR)
logging.getLogger("tim2_editor.engine.level").setLevel(logging.ERROR)
import pygame
pygame.init()

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from tim2_editor.engine.level import load_yaml
from tim2_editor.engine.world import PhysicsWorld
from tim2_editor.engine.behavior import get_registry
from tim2_editor.sprites.anm_renderer import AnmRenderer

YAML_DIR = ROOT / "build" / "phase-5" / "yaml"
ANM_DIR = ROOT / "build" / "phase-4" / "anm"
RESULTS_DIR = ROOT / "build" / "phase-14"
NAME_CATALOG_PATH = ROOT / "build" / "phase-9" / "part-name-catalog.json"

RESULTS_DIR.mkdir(parents=True, exist_ok=True)
name_catalog = json.loads(NAME_CATALOG_PATH.read_text())
renderer = AnmRenderer(ANM_DIR, name_catalog)

sim_ticks = 10

# ── Run ──
files = sorted(YAML_DIR.iterdir())
total = len(files)

results = {}
load_pass = 0
load_fail = 0
sim_pass = 0
sim_fail = 0
sim_skip = 0

for f in files:
    key = f.stem
    entry = {"file": f.name}

    # Phase A: Load
    try:
        level = load_yaml(f)
    except Exception as e:
        entry["load"] = "FAIL"
        entry["load_error"] = traceback.format_exc()
        load_fail += 1
        results[key] = entry
        continue

    if level is None:
        entry["load"] = "FAIL"
        entry["load_error"] = "load_yaml returned None"
        load_fail += 1
        results[key] = entry
        continue

    level_ok = True
    reasons = []
    if not level.title:
        reasons.append("empty title")
        level_ok = False
    if not level.parts or len(level.parts) == 0:
        reasons.append("no parts")
        level_ok = False
    if not level_ok:
        entry["load"] = "WARN"
        entry["load_warnings"] = reasons
    else:
        entry["load"] = "PASS"
        load_pass += 1

    entry["part_count"] = len(level.parts)
    entry["title"] = level.title
    entry["pressure"] = level.pressure
    entry["gravity"] = level.gravity
    entry["music_track"] = level.music_track
    entry["part_types"] = sorted(set(p.part_type for p in level.parts))

    # Phase B: Simulate
    try:
        world = PhysicsWorld()
        world.pressure = level.pressure
        registry = get_registry()
        for p in level.parts:
            anm_name = renderer.get_anm_for_part(p.part_type)
            if anm_name:
                p.anm_name = anm_name
            phys = registry.get_physics_props(p.part_type)
            p.mass = phys["mass"]
            p.cor_q8 = phys["cor_q8"]
            p.friction_q8 = phys["friction_q8"]
            p.collision_radius = phys["collision_radius"]
            if phys["collision_w"] > 0:
                p.collision_w = phys["collision_w"]
            if phys["collision_h"] > 0:
                p.collision_h = phys["collision_h"]
            world.add_part(p)
        for _ in range(sim_ticks):
            world.step()
        entry["sim"] = "PASS"
        entry["sim_ticks"] = world.tick_count
        sim_pass += 1
    except Exception as e:
        entry["sim"] = "FAIL"
        entry["sim_error"] = traceback.format_exc()
        sim_fail += 1

    results[key] = entry

# ── Summary ──
part_type_usage = {}
for key, entry in results.items():
    if "part_types" not in entry:
        continue
    for pt in entry.get("part_types", []):
        part_type_usage[pt] = part_type_usage.get(pt, 0) + 1

summary = {
    "total_files": total,
    "load_pass": load_pass,
    "load_fail": load_fail,
    "sim_pass": sim_pass,
    "sim_fail": sim_fail,
    "sim_skip": sim_skip,
    "ticks_per_level": sim_ticks,
    "part_type_usage": {str(k): v for k, v in sorted(part_type_usage.items())},
}

with open(RESULTS_DIR / "load-all-levels-results.json", "w") as f:
    json.dump({"summary": summary, "results": results}, f, indent=2)

# ── Print ──
print(f"{'='*60}")
print(f"T4: Bulk Level Load Test ({total} files)")
print(f"{'='*60}")
print(f"  Phase A (Load):  {load_pass} passed, {load_fail} failed")
print(f"  Phase B (Sim):   {sim_pass} passed, {sim_fail} failed, {sim_skip} skipped")
loading_subset_not_loaded = load_fail > 0
if load_fail > 0:
    print(f"\n  ❌ Load failures:")
    for key, entry in sorted(results.items()):
        if entry.get("load") == "FAIL":
            err = entry.get("load_error", "unknown")
            print(f"    {key}: {err[:120]}")

if sim_fail > 0:
    print(f"\n  ❌ Sim failures:")
    for key, entry in sorted(results.items()):
        if entry.get("sim") == "FAIL":
            err = entry.get("sim_error", "unknown")
            print(f"    {key}: {err[:120]}")

print(f"\n  Results saved to {RESULTS_DIR / 'load-all-levels-results.json'}")
print(f"\n{'='*60}")

exit_code = 1 if load_fail > 0 or sim_fail > 0 else 0
sys.exit(exit_code)
