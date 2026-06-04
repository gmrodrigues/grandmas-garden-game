"""Physics world — manages all parts, runs gravity + collision + constraints + behaviors."""
import logging
from typing import List, Optional, Tuple, Callable, Dict
from .part import Part, ROPE_PART_TYPES
from .behavior import get_registry
from .behaviors import BehaviorExecutor

logger = logging.getLogger(__name__)

COLLISION_CATEGORY_MAP = {
    "Balls": "DYNAMIC",
    "Walls / Floors": "STATIC",
    "Inclines": "STATIC",
    "Containers": "DYNAMIC",
    "Pool Table": "DYNAMIC",
    "Characters": "DYNAMIC",
    "Balloons / Airships": "DYNAMIC",
    "Explosives / Projectiles": "EXPLOSIVE",
    "Cutting / Popping": "TOOL",
    "Springs / Pneumatics": "TOOL",
    "Rotating Power Sources": "TOOL",
    "Electrical": "TOOL",
    "Special Mechanics": "TOOL",
    "Lasers / Optics": "TOOL",
    "Pipe Systems": "DYNAMIC",
    "Light / Flame Sources": "SCENERY",
    "Scenery": "SCENERY",
    "Created / Phantom": "CREATED",
    "Ropes / Belts / Pulleys": "ROPE",
}

# TODO: Review collision matrix asymmetries (see check_collision_matrix_symmetry)
# Current: ROPE only collides with ROPE (STATIC/DYNAMIC can hit ROPE but not vice versa)
#         EXPLOSIVE hits SCENERY/CREATED but those don't reciprocate
COLLISION_MATRIX = {
    "STATIC": {"DYNAMIC", "EXPLOSIVE", "TOOL", "ROPE"},
    "DYNAMIC": {"STATIC", "DYNAMIC", "EXPLOSIVE", "TOOL", "ROPE"},
    "EXPLOSIVE": {"STATIC", "DYNAMIC", "EXPLOSIVE", "TOOL", "ROPE", "SCENERY", "CREATED"},
    "TOOL": {"STATIC", "DYNAMIC", "EXPLOSIVE", "TOOL"},
    "ROPE": {"ROPE"},
    "SCENERY": set(),
    "CREATED": {"STATIC"},
}

FLOOR_BUFFER = 32                   # px — floor boundary below viewport
BOUNCE_VELOCITY_THRESHOLD = 0x800   # internal units — below this, kill bounce
PROXIMITY_RANGE = 50                # px — fire→balloon proximity trigger
CONSTRAINT_ITERATIONS = 3           # rope constraint solver passes (E-011)
DEFAULT_PRESSURE = 67               # global puzzle air pressure (0-128)


def check_collision_matrix_symmetry() -> Tuple[bool, List[Tuple[str, str]]]:
    """Check if collision matrix is symmetric.

    Returns (is_symmetric, asymmetries) where asymmetries is a list of
    (category_a, category_b) pairs where A collides with B but not vice versa.

    Note: Current matrix is intentionally directional (active→passive) rather than
    fully symmetric. This function documents any asymmetries for review.
    """
    asymmetries = []
    categories = set(COLLISION_MATRIX.keys())
    for cat_a in categories:
        for cat_b in categories:
            a_hits_b = cat_b in COLLISION_MATRIX.get(cat_a, set())
            b_hits_a = cat_a in COLLISION_MATRIX.get(cat_b, set())
            if a_hits_b and not b_hits_a:
                asymmetries.append((cat_a, cat_b))
    return len(asymmetries) == 0, asymmetries


class PhysicsWorld:
    """Simulates TIM2 physics at 60 Hz."""
    
    def __init__(self, viewport: Tuple[int, int, int, int] = (0, 0, 560, 377)):
        self.parts: List[Part] = []
        self.tick_count = 0
        self.viewport = viewport
        self.on_collision: Optional[Callable] = None
        self.on_state_change: Optional[Callable[[Part], None]] = None
        # PH7: Global puzzle pressure field (0-128, default 67)
        # Affects gravity_buoyancy for programmable ball (type 87, extra data).
        # No documented effect on other parts (balloons, air drag, etc.).
        self.pressure: int = DEFAULT_PRESSURE
    
    def add_part(self, part: Part):
        """Add a part to the simulation."""
        registry = get_registry()
        game_cat = registry.behaviors.get(part.part_type, {}).get('category', '')
        col_cat = COLLISION_CATEGORY_MAP.get(game_cat, "DYNAMIC")
        part.collision_cat = col_cat

        limits = registry.get_state_limits_for_part(part.part_type)
        part.state_limit_lower = limits["limit_lower"]
        part.state_limit_upper = limits["limit_upper"]
        part.state_limit_reset = limits["limit_reset"]
        part.state_limit_sub_a = limits["limit_sub_a"]
        part.state_limit_sub_b = limits["limit_sub_b"]

        self.parts.append(part)
    
    def remove_part(self, index: int):
        """Remove part by index."""
        if 0 <= index < len(self.parts):
            del self.parts[index]
    
    def get_part_by_index(self, index: int) -> Optional[Part]:
        """Get part by its current list index."""
        if 0 <= index < len(self.parts):
            return self.parts[index]
        return None
    
    def step(self):
        """Advance one tick (1/60 second)."""
        self.tick_count += 1
        self._parts_to_destroy = []

        # Pass 0: Advance state counters (per E-013)
        for part in self.parts:
            if part.is_moving:
                part.advance_state()

        # Pass 1: Apply gravity to moving parts
        for part in self.parts:
            if part.is_moving:
                part.tick()

        # Pass 1b: Execute behavior side effects BEFORE collision (conveyor, motor, explosive, etc.)
        self._execute_behaviors(1/60)

        # Pass 1c: Viewport boundary clamping (floor + walls)
        self._apply_viewport_bounds()

        # Pass 2-3: Collision detection + response (gated by collision matrix)
        # PH4: Collision dispatch by shape type (circle vs AABB)
        for i, a in enumerate(self.parts):
            if not a.is_moving:
                continue
            cat_a = getattr(a, 'collision_cat', 'DYNAMIC')
            for j, b in enumerate(self.parts):
                if i == j:
                    continue
                # PH8: Skip collision between connected parts (belt/rope chain)
                if a.connected_1 == j or a.connected_2 == j or b.connected_1 == i or b.connected_2 == i:
                    continue
                cat_b = getattr(b, 'collision_cat', 'DYNAMIC')
                if not self._should_collide(cat_a, cat_b):
                    continue
                if self._detect_collision(a, b):
                    self._resolve_collision(a, b)

        # Pass 4-5: Proximity interactions (fire→balloon)
        self._check_proximity_behaviors()

        # Pass 4b: SM3 — Electrical propagation (outlet→consumer)
        self._propagate_electrical()

        # Pass 6-7: Constraint enforcement (3 passes per E-011)
        # PH12: Only apply to rope/pulley parts. Belts use different fields.
        for _ in range(CONSTRAINT_ITERATIONS):
            for part in self.parts:
                if part.part_type not in ROPE_PART_TYPES:
                    continue
                if 0 <= part.connected_1 < len(self.parts):
                    self._enforce_rope_constraint(part, part.connected_1)

        # Post-step: fire on_state_change for any part with a changed state_counter
        if self.on_state_change:
            for part in self.parts:
                if part.state_counter != part.state_prev:
                    part.state_prev = part.state_counter
                    self.on_state_change(part)
    
    def _execute_behaviors(self, dt: float):
        """Execute per-tick behavior side effects."""
        if not hasattr(self, '_behavior_executor'):
            self._behavior_executor = BehaviorExecutor(self)
        self._behavior_executor.execute_tick(dt)

        for part in self._parts_to_destroy:
            if part in self.parts:
                self.parts.remove(part)

    def _apply_viewport_bounds(self):
        """Clamp parts to viewport, bounce off floor/walls with COR."""
        vx, vy, vw, vh = self.viewport
        floor_y = vy + vh - FLOOR_BUFFER
        right_wall = vx + vw
        # Ceiling at vy — bounce with COR (mirrors floor but velocity inverts sign)
        bounce_threshold = BOUNCE_VELOCITY_THRESHOLD

        for part in self.parts:
            if not part.is_moving:
                continue

            # Floor
            bottom = part.y + part.height_1
            if bottom >= floor_y:
                correction = bottom - floor_y
                part.y -= correction
                part.pos_y = part.y
                cor = part.cor_q8
                # Reflect Y velocity scaled by COR (Q8.8 → divide by 256)
                new_vel = -(part.vel_y * cor) >> 8
                if abs(new_vel) < bounce_threshold:
                    part.vel_y = 0
                else:
                    part.vel_y = new_vel

            # Ceiling — bounce downward, same COR as floor
            if part.y < vy:
                part.y = vy
                part.pos_y = part.y
                cor = part.cor_q8
                new_vel = (part.vel_y * cor) >> 8  # positive = downward
                if abs(new_vel) < bounce_threshold:
                    part.vel_y = 0
                else:
                    part.vel_y = new_vel

            # Left wall
            if part.x < vx:
                part.x = vx
                part.pos_x = part.x
                cor = part.cor_q8
                new_vel = -(part.vel_x * cor) >> 8
                if abs(new_vel) < bounce_threshold:
                    part.vel_x = 0
                else:
                    part.vel_x = new_vel

            # Right wall — clamp so ball.x + width = right_wall
            if part.x + part.width_1 > right_wall:
                part.x = right_wall - part.width_1
                part.pos_x = part.x
                cor = part.cor_q8
                new_vel = -(part.vel_x * cor) >> 8
                if abs(new_vel) < bounce_threshold:
                    part.vel_x = 0
                else:
                    part.vel_x = new_vel

    def _should_collide(self, cat_a: str, cat_b: str) -> bool:
        """Check collision matrix for category pair. Returns True if they should interact."""
        targets = COLLISION_MATRIX.get(cat_a, set())
        return cat_b in targets

    def _detect_collision(self, a: Part, b: Part) -> bool:
        """Shape-aware collision detection. PH4: dispatches circle/AABB."""
        a_circle = a.coll_shape == "circle"
        b_circle = b.coll_shape == "circle"
        if a_circle and b_circle:
            return a.circle_overlap(b)
        if a_circle:
            return a.circle_aabb_overlap(b)
        if b_circle:
            return b.circle_aabb_overlap(a)
        return a.aabb_overlap(b)

    def _resolve_collision(self, a: Part, b: Part):
        """Collision response with shape-aware resolution.

        Only the moving part (a) gets position correction + bounce.
        Static part (b) is never moved — it's a fixed obstacle.

        For AABB: surface clamping (per collision-spec).
        For circle: push along normal from closest point on B to A's center.
        PH4: Circle-vs-AABB and circle-vs-circle resolution added.
        
        Special case: conveyor belts (part_type 5) don't bounce - they slide.
        """
        cor = a.cor_q8
        no_bounce = b.part_type == 5

        if a.coll_shape == "circle":
            self._resolve_circle_collision(a, b, cor, no_bounce)
        else:
            l1, t1, r1, b1 = a.get_collision_box()
            l2, t2, r2, b2 = b.get_collision_box()
            overlap_x = min(r1, r2) - max(l1, l2)
            overlap_y = min(b1, b2) - max(t1, t2)

            if overlap_x < overlap_y:
                if a.vel_x >= 0:
                    a.x = b.x - (r1 - l1)
                else:
                    a.x = b.x + (r2 - l2)
                a.pos_x = a.x
                if not no_bounce:
                    a.vel_x = (-a.vel_x * cor) >> 8
                    fric = a.friction_q8 >> 1
                    if fric > 0:
                        a.vel_x = int(a.vel_x * (256 - fric) / 256)
            else:
                if a.vel_y >= 0:
                    a.y = b.y - (b1 - t1)
                else:
                    a.y = b.y + (b2 - t2)
                a.pos_y = a.y
                if not no_bounce:
                    a.vel_y = (-a.vel_y * cor) >> 8
                    fric = a.friction_q8 >> 1
                    if fric > 0:
                        a.vel_x = int(a.vel_x * (256 - fric) / 256)

        self._apply_behavior_collision(a, b)
        if self.on_collision:
            self.on_collision(a, b)

    def _resolve_circle_collision(self, a: Part, b: Part, cor: int, no_bounce: bool):
        """Circle collision response: push along normal, reflect velocity. PH4.
        
        Uses reflection formula: v' = v - (1 + cor/256) * (v·n) * n
        cor is Q8.8 fixed-point (128 = 0.5). cor_factor = 256 + cor = (1 + cor/256) in Q8.8.
        vn = v · n (component toward surface, negative = moving into surface)
        """
        ax, ay, ar = a.get_circle()
        if b.coll_shape == "circle":
            bx, by, br = b.get_circle()
            dx = ax - bx
            dy = ay - by
            dist = (dx*dx + dy*dy)**0.5
            if dist == 0:
                dist = 1
            overlap = (ar + br) - dist
            nx = dx / dist
            ny = dy / dist
            a.x += int(nx * overlap)
            a.y += int(ny * overlap)
            a.pos_x, a.pos_y = a.x, a.y
            vn = a.vel_x * nx + a.vel_y * ny
            if vn < 0 and not no_bounce:
                cor_factor = 256 + cor
                a.vel_x -= int(vn * cor_factor * nx) >> 8
                a.vel_y -= int(vn * cor_factor * ny) >> 8
        else:
            l, t, r_b, b_box = b.get_collision_box()
            closest_x = max(l, min(ax, r_b))
            closest_y = max(t, min(ay, b_box))
            dx = ax - closest_x
            dy = ay - closest_y
            dist = (dx*dx + dy*dy)**0.5
            if dist == 0:
                dist = 1
            overlap = ar - dist
            nx = dx / dist
            ny = dy / dist
            a.x += int(nx * overlap)
            a.y += int(ny * overlap)
            a.pos_x, a.pos_y = a.x, a.y
            vn = a.vel_x * nx + a.vel_y * ny
            if vn < 0 and not no_bounce:
                cor_factor = 256 + cor
                a.vel_x -= int(vn * cor_factor * nx) >> 8
                a.vel_y -= int(vn * cor_factor * ny) >> 8
    
    def _enforce_rope_constraint(self, part: Part, target_idx: int):
        """Single-pass distance constraint: keep connected parts within rope length.
        
        Uses rope_segment_length (field at offset 0x18 in rope level entries,
        mapped from YAML behavior). Only called for ROPE_PART_TYPES (7, 10, 76).
        PH12: Uses dedicated rope_segment_length field instead of generic behavior.
        """
        target = self.parts[target_idx]
        dx = (target.x + target.width_1/2) - (part.x + part.width_1/2)
        dy = (target.y + target.height_1/2) - (part.y + part.height_1/2)
        dist = (dx*dx + dy*dy)**0.5
        
        max_len = part.rope_segment_length
        if dist > max_len and dist > 0:
            correction = (dist - max_len) / 2
            nx = dx / dist
            ny = dy / dist
            part.x += int(nx * correction); part.pos_x = part.x
            part.y += int(ny * correction); part.pos_y = part.y
            target.x -= int(nx * correction); target.pos_x = target.x
            target.y -= int(ny * correction); target.pos_y = target.y
    
    def _apply_pressure_effects(self):
        """PH7: apply global pressure field to all parts (stub).
        
        Based on timgres research:
        - Pressure field (0-128, default 67) is a global puzzle property.
        - Only documented effect is on programmable ball (type 87) via
          gravity_buoyancy field in its extra data (applied in Part.tick()).
        - No documented effect on other parts (balloons, air drag, etc.).
        - This stub exists for future physics investigation.
        """
        pass

    def reset(self):
        """Reset all parts to initial positions."""
        for part in self.parts:
            part.vel_x = 0
            part.vel_y = 0
            part.current_state = 0
            part.state_counter = 0
            part.sub_counter = 0
            part._countdown = -1
        self.tick_count = 0
    
    def _apply_behavior_collision(self, a: Part, b: Part):
        """Apply SOLVE.RES state transitions on collision between a and b."""
        registry = get_registry()
        
        # Basic state bump (per E-013 W7/W8)
        a_changed = a.on_collision(b)
        b_changed = b.on_collision(a)
        
        # Try SOLVE.RES rule matching
        # For each part, check if the collision matches a SOLVE.RES trigger
        a_behavior = registry.get_behavior(a.part_type)
        b_behavior = registry.get_behavior(b.part_type)
        
        # Look for matching triggers: other part's state triggers our transition
        for part, other, behavior in [(a, b, a_behavior), (b, a, b_behavior)]:
            if not behavior["solve_states"]:
                continue
            trigger = {"self": part.state_counter, "other": other.state_counter}
            matched = registry.resolve_solve_state(part.part_type, trigger)
            if matched:
                part.state_counter = matched.get("anm_state") or part.state_counter
                part.current_state = part.state_counter
                if matched.get("explosive"):
                    self._destroy_part(part)
    
    def _check_proximity_behaviors(self):
        """Check proximity-based interactions (fire→balloon, electrical→device).
        
        Scans pairs of parts where one's category can trigger another's.
        Uses category_rules from behavior registry.
        """
        registry = get_registry()
        
        for i, a in enumerate(self.parts):
            a_behavior = registry.get_behavior(a.part_type)
            for rule_name, rule in a_behavior.get("rules", {}).items():
                if rule_name != "proximity" or rule.get("response") != "state_transition":
                    continue
                trigger_cats = rule.get("ignites_categories", 
                                        rule.get("trigger_if_other_in_category", []))
                if not trigger_cats:
                    continue
                
                for j, b in enumerate(self.parts):
                    if i == j or not b.is_moving:
                        continue
                    b_behavior = registry.get_behavior(b.part_type)
                    if b_behavior.get("category") in trigger_cats:
                        # Proximity check: within 50px
                        dx = abs(a.x - b.x)
                        dy = abs(a.y - b.y)
                        if dx < 50 and dy < 50:
                            target_state_name = rule.get("state_name", "")
                            for state in a_behavior.get("solve_states", []):
                                if state["name"] == target_state_name:
                                    a.state_counter = state.get("anm_state") or a.state_counter
                                    a.current_state = a.state_counter
                                    if state.get("explosive"):
                                        self._destroy_part(a)
                                    break
    
    # SM3: Electrical consumer part types → (off_state, on_state)
    ELECTRICAL_CONSUMER_STATES = {
        24: (1, 2),    # Fan: off → on
        50: (1, 4),    # Electric Motor: off → running
        51: (9, 10),   # Vacuum: off → on
        67: (1, 3),    # Can Opener: closed → opened
        81: (1, 8),    # Toaster: off → toasting
        107: (2, 1),   # Mixer: off → on
    }

    def _is_source_active(self, part: 'Part') -> bool:
        """Check if an electrical source is producing power. SM3."""
        pt = part.part_type
        if pt == 120:  # Always-on Outlet
            return True
        if pt == 21:   # Switch & Outlet — ON when state >= 8 (switch flipped)
            return part.state_counter >= 8
        if pt == 26:   # Generator — active when spinning (state >= 2)
            return part.state_counter >= 2
        if pt == 38:   # Solar Panel — active when lit (state == 2)
            return part.state_counter == 2
        if pt == 25:   # Flashlight — active when ON (state == 2)
            return part.state_counter == 2
        if pt == 96:   # Laser-Activated Plug — active when triggered (state >= 2)
            return part.state_counter >= 2
        return False

    def _propagate_electrical(self):
        """SM3: Propagate power from active sources to connected consumers.
        
        Iterates outlet parts (flags_3 & 0x2), checks if source is active,
        and sets state_counter on plugged-in consumers via outlet_plugged_1/2.
        Supports chain: source → outlet → consumer via outlet_plugged fields.
        """
        for source in self.parts:
            if not (source.flags_3 & 0x2):
                continue
            powered = self._is_source_active(source)
            for idx in (source.outlet_plugged_1, source.outlet_plugged_2):
                if not (0 <= idx < len(self.parts)):
                    continue
                consumer = self.parts[idx]
                states = self.ELECTRICAL_CONSUMER_STATES.get(consumer.part_type)
                if states is None:
                    continue
                off_state, on_state = states
                if powered and consumer.state_counter != on_state:
                    consumer.state_counter = on_state
                    consumer.current_state = on_state
                elif not powered and consumer.state_counter == on_state:
                    consumer.state_counter = off_state
                    consumer.current_state = off_state

    def _destroy_part(self, part: Part):
        """Remove a part from the simulation (explosive destruction)."""
        if part in self.parts:
            self.parts.remove(part)
    
    def get_state(self) -> dict:
        """Get current simulation state for solution checking."""
        return {
            "tick_count": self.tick_count,
            "parts": [
                {
                    "index": i,
                    "x": p.x,
                    "y": p.y,
                    "state": p.current_state,
                    "in_viewport": self._in_viewport(p),
                }
                for i, p in enumerate(self.parts)
            ]
        }
    
    def _in_viewport(self, p: Part) -> bool:
        vx, vy, vw, vh = self.viewport
        return (vx <= p.x <= vx + vw and vy <= p.y <= vy + vh)


# Module-level collision matrix diagnostic: run once at import time
_is_sym, _asymmetries = check_collision_matrix_symmetry()
if not _is_sym:
    logger.warning(
        "Collision matrix asymmetries (%d pairs): %s",
        len(_asymmetries), _asymmetries
    )
