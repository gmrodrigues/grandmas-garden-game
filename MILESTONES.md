# Milestones

## M1: Core Gameplay Foundation (completed)
- **Phase 1 — Sprites:** Fixed ANM lookup (PartDatabase→AnmDatabase), cached AnmRenderer, removed dead `_load_anm_catalog()`, wired GameController textures
- **Phase 2 — Undo/Redo:** Full world-snapshot undo/redo (50-deep), wired into 9 mutation sites
- **Phase 3 — Solutions:** Connected on_collision/on_state_change callbacks, parsed solution_conditions from YAML, real conditions in preview
- **Phase 4 — Cleanup:** FLAG_MOVING constant, MAX_TICKS consolidation, emoji→text timeout
- **Phase 5 — Verify:** Zero errors, --level injection, run.sh, Vulkan confirmed

## M2: Editor Polish & Physics Quality (completed)
- **Phase 1 — Resize Handles:** 8 handles on selected part now draggable with MIN_PART_SIZE=8
- **Phase 2 — Condition UI:** "Conditions" toolbar button opens editor dialog for add/remove conditions
- **Phase 3 — Snapshots:** Preview saves/restores sub_counter, _countdown, connections, facing, angular_velocity
- **Phase 4 — Cleanup:** FLAG_FLIP constant across 5 files, missing PNG warning in AnmRenderer
- **Phase 5 — Verify:** Zero errors

## M3: Remaining Work (unstarted)
### High Impact
- **O(N²) collision broadphase** — No spatial grid. Fine for 50 parts, slow at 200+.
- **SolutionRectTool never wired** — Rect-based POSITION conditions have no visual rect selector.
- **Resize handles don't update collision_w/h** — `_resize_part` only changes width_1/height_1.

### Medium Impact
- **`_new_level()` leaks solver/checker** — RefCounted so eventually freed, but not explicit.
- **`is_moving` derived from flags_1 but also set directly** — _lock_selected toggles both but add_part overwrites from flags_1.
- **No error handling for missing YAML fields** — _do_load silently sets defaults.

### Low Impact
- **`orphan_states`/`categories_data`** in BehaviorRegistry loaded but unused externally.
- **`0x8000` in PhysicsSolver conveyor logic** — uses same bit as FLAG_FLIP but for direction. Bit collision risk.
