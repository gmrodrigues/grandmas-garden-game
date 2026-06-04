# 5. State Machine

Every part in the game is governed by a state machine that drives its behavior, animations, and sound effects.

## 5.1 State Storage

- Stored as `INT16` at runtime struct offset `0x18` (file offset).
- There are **89 unique state IDs** across all 149 part types.
- State 1 is Idle/Default. State 2 is Active/Running. State 3 is typically Touched/Triggered.

## 5.2 State Execution Engine (Pass 0)

Executed every tick for each moving part. Translates to the following logic:

```gdscript
var state_prev = state_counter

if sub_counter == 0:
    # Main state processing
    if state_counter != 0:
        if state_counter < LIMIT_LOWER:
            state_counter = LIMIT_LOWER - 1
        state_counter += 1
        if state_counter >= LIMIT_UPPER:
            state_counter = LIMIT_RESET
    else:
        # Zero state: random delay (60 Hz timer)
        if rng_check():
            countdown -= 1
            if countdown < 0:
                state_counter += 1
                countdown = random_range(40, 240)
else:
    # Sub-state countdown
    sub_counter -= 1
    if sub_counter == 0:
        # Sub-state expired — reverse direction or reset
        velocity_x = 1 if (flags_1 & 0x10) else -1
        state_counter = LIMIT_RESET
    else:
        state_counter += 1

# If state changed, trigger behavior and audio
if state_counter != state_prev:
    execute_state_behavior(part)
    play_sound_for_state(part, state_counter)
```

## 5.3 State Limits

Limits are initialized at runtime based on the part type, not compile-time constants:
- `LIMIT_LOWER`: State lower bound (typically ~0-1)
- `LIMIT_UPPER`: State upper bound (resets here, typically ~4-20)
- `LIMIT_RESET`: Value to reset to on upper bound
- `SUB_LIMIT_A`: Sub-state cycle limit

## 5.4 State Transitions

Transitions are triggered by:
1. **Timer**: The execution engine naturally advancing the state counter.
2. **Collision**: `on_collision()` directly increments `state_counter` (capped at `LIMIT_UPPER`).
3. **Activation**: Linked/connected parts propagate signals (e.g., Switch → Outlet → Appliance).
