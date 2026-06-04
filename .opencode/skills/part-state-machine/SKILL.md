---
name: part-state-machine
description: Per-part state machine with SOLVE.RES triggers, deterministic RNG, and configurable limits. Use when editing PartData.gd, BehaviorRegistry.gd, state transitions, or SOLVE.RES logic. Trigger keywords: PartData, state_counter, sub_counter, advance_state, SOLVE.RES, LIMIT_UPPER, state machine, trigger chain.
---

# Part State Machine & SOLVE.RES System

Implements per-part state machines from `backend/PartData.gd` and `autoload/BehaviorRegistry.gd`. Use when adding new states, modifying transition logic, or debugging state not advancing.

## Core Files

- `backend/PartData.gd` — PartData class with all state fields + `advance_state()`
- `autoload/BehaviorRegistry.gd` — loads `solve-decoded.json`, `behaviors.json`, `state-machine-report.json`
- `backend/PhysicsSolver.gd:pass 0` — calls `advance_state()` each tick

## State Fields (in PartData)

```gdscript
state_counter: int      # current state index (0..state_limit_upper-1)
state_prev: int         # previous tick's state (for change detection)
sub_counter: int        # delay ticks before transition (0 = no delay)
state_limit_lower: int  # lower bound
state_limit_upper: int  # upper bound (also LIMIT_UPPER)
state_limit_reset: int  # reset target when reaching LIMIT_UPPER
state_limit_sub_a: int  # sub-range lower bound
state_limit_sub_b: int  # sub-range upper bound
current_state: int      # mirrors state_counter, synced after transitions
_rng_state: int         # LCG RNG seed for deterministic randomness
```

## advance_state() Logic (PartData.gd:146)

```
if sub_counter == 0:
    if state_counter != 0:
        # Normal state advancement
        if state_counter < state_limit_lower:
            state_counter = state_limit_lower - 1
        state_counter += 1
        if state_counter >= state_limit_upper:
            state_counter = state_limit_reset  # wraps to reset value
    else:
        # State 0: deterministic RNG delay
        if _rng_state & 1:
            countdown = _randint(40, 239)
            countdown -= 1
            if countdown < 0:
                state_counter += 1  # transition out of state 0
else:
    # Sub-counter delay active
    sub_counter -= 1
    if sub_counter == 0:
        state_counter = state_limit_reset
    else:
        state_counter += 1  # capped at state_limit_sub_a → state_limit_sub_b
```

## Deterministic RNG (PartData.gd:175)

```gdscript
_rng_state = (_rng_state * 0x343FD + 0x269EC3) & 0xFFFFFFFF
return lo + (_rng_state % (hi - lo + 1))
```

This LCG is seeded per-part and produces the same sequence every run — critical for determinism.

## SOLVE.RES Trigger Chains

Loaded from `build/phase-16/solve-decoded.json` by `BehaviorRegistry`.

**Structure per part type:**
```json
{
  "part_type": 5,
  "states": [
    {
      "state_id": 0,
      "triggers": [
        { "type": "OTHER", "other": 1 },
        { "type": "OTHER", "other": 2 }
      ]
    }
  ]
}
```

**Trigger resolution** happens in `PhysicsSolver._handle_behaviors()` when a collision occurs on a part:
1. Look up `part_type` in `BehaviorRegistry`
2. Find current `state_counter` in `solve-decoded`
3. For each trigger `other` value: if `other <= 104`, set `target_part.state_counter = other`
4. This creates chain reactions across connected parts

**Validation**: `BehaviorRegistry.validate_trigger_chains()` (line 170) checks that all `other` references are ≤ 104.

## State Limits from behaviors.json

`BehaviorRegistry._load_behaviors()` reads `state_limit_lower`, `state_limit_upper`, `state_limit_reset`, `state_limit_sub_a`, `state_limit_sub_b` from `behaviors.json` and assigns them to `PartData` at creation time.

## Adding a New Part Type with Custom States

1. Add part type ID and state limits to `build/phase-9/part-properties.json`
2. If SOLVE.RES triggers exist, add entry to `build/phase-16/solve-decoded.json`
3. If custom behavior, add handler in `PhysicsSolver._handle_behaviors()`

## Collision Callback → State Change

`PartData.on_collision(other_part_idx) -> bool` (line 179):
```gdscript
if state_counter < state_limit_upper:
    state_counter += 1
    current_state = state_counter
    return true  # changed
return false
```

Called from `PhysicsSolver._resolve_collision()` after velocity resolution.

## Key Reference

- `backend/PartData.gd:134` — `tick()` gravity
- `backend/PartData.gd:146` — `advance_state()` full logic
- `backend/PartData.gd:175` — `_randint()` deterministic RNG
- `backend/PartData.gd:179` — `on_collision()` state increment
- `autoload/BehaviorRegistry.gd:56` — `_load_solve_decoded()`
- `autoload/BehaviorRegistry.gd:170` — `validate_trigger_chains()`
- `autoload/BehaviorRegistry.gd:147` — `get_solve_transitions()`
