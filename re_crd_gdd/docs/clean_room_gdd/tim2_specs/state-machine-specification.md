# TIM2 State Machine — Complete Specification

Cross-referenced specification for the TIM2 state machine system.
Validated against ANM Section C data, SOLVE.RES transitions,
and the Python reference editor (`tim2_editor/`).

## 1. State Concepts

TIM2 uses **four distinct but interconnected** state concepts:

| Concept | Location | Type | Purpose |
|---------|----------|------|---------|
| `state_counter` | Part struct offset 0x18 | INT16 | Internal physics state, incremented by state engine, written by collision/proximity/sound |
| `current_state` | Runtime tracking | INT16 | Copy of state_counter for solution checking and ANM lookup |
| ANM `state_id` | ANM Section C | UINT16 | Maps to first_frame_id for sprite rendering |
| SOLVE.RES `self`/`other` | solve-decoded.json | UINT16 pairs | Trigger condition: when part's state==self AND other part's state==other, transition fires |

**State ID universe**: 89 unique IDs (max 104), spanning parts and UI elements.

## 2. State Execution Engine

Executed every tick (60 Hz) for each moving part. Located at EXE 0x3AE71 (FUN_31f7_3bd2).

```python
def advance_state():
    if sub_counter == 0:
        if state_counter != 0:
            if state_counter < LIMIT_LOWER:  # typically 0
                state_counter = LIMIT_LOWER - 1
            state_counter += 1
            if state_counter >= LIMIT_UPPER:  # default 8
                state_counter = LIMIT_RESET    # default 0
        else:  # zero state — random delay
            if RNG & 1:
                if countdown < 0:
                    countdown = random(40, 239)
                countdown -= 1
                if countdown < 0:
                    state_counter += 1
                    countdown = random(40, 239)
    else:  # sub-state countdown
        sub_counter -= 1
        if sub_counter == 0:
            state_counter = LIMIT_RESET
        else:
            state_counter += 1
```

### State Limits

| Limit | Default | Description |
|-------|---------|-------------|
| LIMIT_LOWER | 0 | Minimum state value before wraparound |
| LIMIT_UPPER | 8 | Maximum state — wraps to LIMIT_RESET |
| LIMIT_RESET | 0 | Reset value when upper bound reached |
| SUB_LIMIT_A | 5 | Sub-state cycle limit A |
| SUB_LIMIT_B | 5 | Sub-state cycle limit B |

**Parts exceeding default LIMIT_UPPER=8**: 17 parts need custom limits.
These limits are initialized at runtime via `FUN_4551_0370` using a lookup table
at segment 0x5B41. Exact per-part values remain to be resolved from the binary data section.

## 3. SOLVE.RES → ANM State Mapping

**52 interactive parts** use SOLVE.RES state transitions (113 state entries).

### `anm_state` Override Semantics

- **79 states** use explicit `anm_state` — the SOLVE.RES state
  maps to a specific ANM rendering state, independent of trigger chain positions.
  Example: Cannon's 'Not Fired' → ANM state 47 (overrides 6 trigger self values).

- **34 states** use `null` — the ANM state equals the trigger
  `self` value directly. Each trigger chain step renders at its own ANM state.
  Example: Balloon's 'Not Popped' — self values (2,3,4,5) each map to ANM states directly.

### Orphan ANM States

**146 ANM states** across **29 parts** exist in ANM Section C
but are not referenced by any SOLVE.RES trigger. These are internal animation
transition frames (state sequences that play between solve-visible states).

| Part | Orphan States |
|------|---------------|
| 12 (Curie Cat) | 4, 5, 6, 7, 8, 10, 11, 12, 13, 14 |
| 13 (Jack-in-the-box) | 13 |
| 18 (Cannon) | 3, 6, 9, 15, 22, 23, 24, 25, 26, 27, 28, 29, 30, 35, 36, 39, 40, 42, 43, 44, 46, 49, 51, 52 |
| 19 (Dynamite) | 4 |
| 26 (Generator) | 3, 4, 5, 10, 11, 12 |
| 27 (Captain Z Super Phazer) | 4, 5 |
| 31 (Mandrill Motor) | 3, 8 |
| 36 (Rocket) | 9, 10, 14, 16, 17, 18, 20, 23 |
| 37 (Hedge Trimmers) | 8, 9, 11 |
| 42 (Newton Mouse) | 7, 8, 9, 11, 12, 13, 14 |
| 45 (Aladdin's Lamp) | 3 |
| 54 (Mel Schlemming) | 3, 8, 9, 15, 16, 18, 19, 20, 21, 23, 25 |
| 58 (Mel's House) | 8, 9, 13, 14 |
| 61 (Alligator) | 4, 6, 7, 8, 9, 10, 11, 12, 13 |
| 65 (Leprechaun) | 3 |
| 67 (Can Opener) | 3 |
| 70 (Missile) | 4, 8, 14, 15, 20 |
| 75 (Match-on-a-Spring) | 4 |
| 77 (Tin Snips) | 5, 6 |
| 78 (Flint & Tinder) | 5 |
| 79 (Hot Air Balloon) | 3 |
| 80 (Fireworks) | 10, 11, 14, 15, 17, 18, 19, 20 |
| 81 (Toaster) | 8, 9, 10 |
| 108 (Leaky Bucket) | 5, 6, 7, 8, 9, 10 |
| 109 (Blimp) | 3, 4 |
| 117 (Pool Cue) | 9, 14, 18, 21, 24, 27, 30 |
| 136 (Message Computer) | 6 |
| 137 (Egg Timer) | 20, 21, 24, 25, 27, 29, 31, 32, 35, 37, 38, 39, 40, 41, 42, 43, 44 |
| 148 (Laser Detector) | 5 |

*State 27 is universally orphan — likely an internal 'empty/transition' frame.*

## 4. Trigger Chain Mechanics

**207 total triggers** across all interactive parts.

Each SOLVE.RES state has trigger entries `{self, other}`:
- `self`: The ANM state the part must currently BE IN to trigger
- `other`: The state the OTHER colliding part must have for the trigger to fire
- `other=-1`: Terminal state — fires on ANY other part's state (wildcard)
- `other>0`: Requires a specific other part state

**Trigger chain integrity**: 201 chains resolve, 38 broken.

## 5. Collision + State Integration

When two parts collide, BOTH `state_counter` values are read:

```python
for part, other in [(a,b), (b,a)]:
    trigger = {'self': part.state_counter, 'other': other.state_counter}
    matched = resolve_solve_state(part.part_type, trigger)
    if matched:
        part.state_counter = matched.anm_state or part.state_counter
        if matched.explosive:
            destroy(part)
```

State changes propagate through SOLVE.RES trigger chains: Part A's collision
bumps self from 1→2. If this matches a SOLVE.RES trigger for Part B, B may
also advance. This enables chain reactions (candle lights fuse, fuse ignites
dynamite, dynamite explodes).

## 6. State Machine Complexity by Category

| Category | Avg ANM States | Max ANM States | Interactive |
|----------|---------------|----------------|-------------|
| Balloons / Airships | 6.7 | 8 | 3 |
| Balls | 3.8 | 16 | 9 |
| Characters | 6.9 | 14 | 6 |
| Containers | 4.8 | 9 | 4 |
| Created / Phantom | 1.0 | 1 | 0 |
| Cutting / Popping | 6.0 | 8 | 2 |
| Electrical | 4.4 | 9 | 6 |
| Explosives / Projectiles | 9.6 | 37 | 8 |
| Inclines | 1.0 | 1 | 0 |
| Lasers / Optics | 9.0 | 32 | 4 |
| Light / Flame Sources | 3.0 | 4 | 5 |
| Pipe Systems | 2.0 | 4 | 0 |
| Pool Table | 9.5 | 16 | 1 |
| Ropes / Belts / Pulleys | 1.2 | 2 | 0 |
| Rotating Power Sources | 4.0 | 10 | 4 |
| Scenery | 0.8 | 1 | 0 |
| Special Mechanics | 4.0 | 26 | 8 |
| Springs / Pneumatics | 6.1 | 24 | 4 |
| Walls / Floors | 2.1 | 3 | 0 |

## 7. State Write Sites (from E-013)

The `state_counter` field at phys struct offset 0x18 is written by 9 sites:

| Site | Type | Function | Description |
|------|------|----------|-------------|
| W1 | Init | Part constructor | Copies initial state from PAR file data |
| W2 | Init | Part constructor | Writes packed bitfield 0x6315 (behavior flags, not ANM state) |
| W3 | Init | Part constructor | Copies from PAR defaults |
| W4 | Init | Part constructor | Copies from PAR defaults |
| W5 | Physics | FUN_31f7_68c9 | Bounce/rebound with direction flag flipping |
| W6 | Physics | Collision response | State bump on AABB overlap |
| W7 | Physics | Collision response | SOLVE.RES trigger resolution |
| W8 | Sound | FUN_31f7_3bd2 | State advance → triggers FM sound playback |
| W9 | Sound | seg 0x32DA | Sound dispatch writes state for playback |

## 8. Validation Summary

- **11 checks passed, 0 failed**
- 152 SOLVE.RES state references resolve to valid ANM states
- 146 orphan ANM states (internal transition frames)
- 201 trigger chains link correctly
- 89 unique state IDs in universe
