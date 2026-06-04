"""Behavior execution system — runs per-tick side effects for special parts.

This module provides behavior handlers for parts that have special game mechanics:
- Conveyor Belt: moves objects on top
- Mouse Motor: drives connected pulleys
- Cannon: fires projectiles
- Explosives: chain reaction explosions
- Electrical: power transmission
- Anti-Gravity: applies upward force
- Rope: constraint physics

Each handler is a function that receives (world, part, dt) and can modify the world.
"""
from typing import TYPE_CHECKING, Tuple
from collections import deque

if TYPE_CHECKING:
    from .world import PhysicsWorld
    from .part import Part

from .behavior import get_registry


# Pipe part types
PIPE_TYPES = {57, 88, 97, 98}

# Portal map: (part_type, appearance) → (entrance_edge, exit_edge)
# entrance_edge = edge of collision box where ball enters the pipe
# exit_edge = edge where ball emerges
# Derived from spatial adjacency analysis of MLEV4, MLEV29, ELEV22
PIPE_PORTALS = {
    (57, 0): ('left', 'bottom'),    # curve: entrance left, exit bottom
    (57, 1): ('bottom', 'right'),   # curve: entrance bottom, exit right
    (57, 2): ('left', 'top'),       # curve: entrance left, exit top
    (57, 3): ('top', 'right'),      # curve: entrance top, exit right
    (97, 0): ('left', 'right'),     # straight horizontal
    (97, 1): ('right', 'left'),     # straight horizontal (reversed)
    (88, 0): ('top', 'bottom'),     # accelerator vertical
    (88, 5): ('left', 'right'),     # accelerator horizontal
    (98, 0): ('bottom', 'top'),     # T-connector: entrance bottom, exit top
}

PORTAL_HALF_WIDTH = 6  # half-size of portal detection box, in pixels

# ── Physics/Speed/Range Constants ──
CONVEYOR_SPEED = 60            # pixels per second
MOTOR_TORQUE = 100             # angular velocity units
CANNONBALL_SIZE = 16           # width/height in pixels
CANNONBALL_SPEED_X = 200       # horizontal launch velocity
CANNONBALL_SPEED_Y = -50       # vertical launch velocity (upward)
EXPLOSION_DELAY = 2.0          # seconds before detonation
EXPLOSION_RADIUS = 100         # pixels
EXPLOSION_DAMAGE = 500         # force magnitude
FLASHLIGHT_RANGE = 150         # pixels
ANTI_GRAVITY_FORCE = -150      # upward force
MOUSE_EAT_DISTANCE = 5         # pixels — threshold for "reached cheese"
MOUSE_SPEED = 30               # pixels per second toward cheese
MOUSE_EATEN_STATE = 10         # state after eating
LASER_BEAM_LENGTH = 200        # pixels
BALLOON_IDLE_STATE = 1         # before pop
BALLOON_POP_STATE = 8          # after pop
MAGNIFIER_BEAM_LENGTH = 200    # pixels
IGNITABLE_IDLE_STATE = 1       # before ignition
IGNITED_STATE = 8              # after ignition
PIPE_EXIT_SPEED = 100          # pixels per second

# ── State IDs ──
CONVEYOR_RUNNING_STATE = 1
MOTOR_RUNNING_STATE = 1
BELT_RUNNING_STATE = 1
CANNON_IDLE_STATE = 1          # pre-fire state
EXPLOSIVE_TRIGGERED_STATE = 1
FLASHLIGHT_ON_STATE = 2
ANTI_GRAVITY_ON_STATE = 2
MOUSE_HUNGRY_STATE = 1
LASER_ON_STATE = 2
MAGNIFIER_ON_STATE = 2
ELECTRICAL_OFF_STATE = 1
ELECTRICAL_ON_STATE = 2


class BehaviorExecutor:
    """Executes per-tick behaviors for special parts."""

    def __init__(self, world: 'PhysicsWorld'):
        self.world = world
        self.registry = get_registry()

    def execute_tick(self, dt: float):
        """Run all behavior handlers for the current tick."""
        for part in list(self.world.parts):
            self._execute_part_behavior(part, dt)

    def _execute_part_behavior(self, part: 'Part', dt: float):
        """Execute behavior for a single part based on its type and state."""
        pt = part.part_type
        state = part.state_counter

        if pt == 5:  # Conveyor Belt
            self._handle_conveyor_belt(part, dt)
        elif pt == 6:  # Mouse Motor
            self._handle_mouse_motor(part, dt)
        elif pt == 7:  # Pulley
            self._handle_pulley(part, dt)
        elif pt == 8:  # Belt
            self._handle_belt(part, dt)
        elif pt == 18:  # Cannon
            self._handle_cannon(part, dt)
        elif pt in (19, 22, 27, 36, 55, 70, 74, 80):  # Explosives / Projectiles
            self._handle_explosive(part, dt)
        elif pt == 25:  # Flashlight
            self._handle_flashlight(part, dt)
        elif pt == 69:  # Anti-Gravity Pad
            self._handle_anti_gravity(part, dt)
        elif pt == 42:  # Newton Mouse
            self._handle_newton_mouse(part, dt)
        elif pt in (91, 92, 93):  # Laser (Red, Green, Blue)
            self._handle_laser(part, dt)
        elif pt == 30:  # Magnifying Glass
            self._handle_magnifying_glass(part, dt)
        elif pt in PIPE_TYPES:  # Pipe System
            self._handle_pipe(part, dt)

    def _handle_conveyor_belt(self, part: 'Part', dt: float):
        """Conveyor belt moves objects on top."""
        if part.state_counter != CONVEYOR_RUNNING_STATE:
            return

        belt_speed = CONVEYOR_SPEED

        for other in self.world.parts:
            if other is part:
                continue
            if not other.is_moving:
                continue

            l1, t1, r1, b1 = part.get_collision_box()
            l2, t2, r2, b2 = other.get_collision_box()

            if not (r1 <= l2 or r2 <= l1 or b1 <= t2 or b2 <= t1):
                other.x += belt_speed * dt

    def _handle_mouse_motor(self, part: 'Part', dt: float):
        """Mouse motor drives connected pulleys and belt-connected parts. PH6."""
        if part.state_counter != MOTOR_RUNNING_STATE:
            return

        motor_torque = MOTOR_TORQUE

        for other in self.world.parts:
            if other.part_type in (7, 8):  # Pulley or Belt
                if other.motor_connected:
                    other.angular_velocity = motor_torque

    def _handle_pulley(self, part: 'Part', dt: float):
        """Pulley rotates based on motor and enforces rope anchor constraints. PH11.
        
        Two rope segments connect at pulley_rope_1/2_connect positions.
        The pulley acts as a frictionless redirect: rope segments entering the
        pulley are constrained to their anchor points on the pulley body.
        """
        if part.angular_velocity != 0:
            part.rotation_angle = (part.rotation_angle + part.angular_velocity * dt) % 360

        rope_1_anchor = (part.x + part.pulley_rope_1_connect_x,
                         part.y + part.pulley_rope_1_connect_y)
        rope_2_anchor = (part.x + part.pulley_rope_2_connect_x,
                         part.y + part.pulley_rope_2_connect_y)

        # Constrain connected rope segments to pulley anchor points
        for idx in (part.connected_1, part.connected_2):
            if 0 <= idx < len(self.world.parts):
                rope_part = self.world.parts[idx]
                if rope_part.part_type in (10, 76):
                    rope_part.rope_1_anchor_x = rope_1_anchor[0]
                    rope_part.rope_1_anchor_y = rope_1_anchor[1]
                    rope_part.rope_2_anchor_x = rope_2_anchor[0]
                    rope_part.rope_2_anchor_y = rope_2_anchor[1]

    def _handle_belt(self, part: 'Part', dt: float):
        """Belt couples angular velocity between two rotating parts. PH6.
        
        belt_connected_part_1/2 (from fformat.txt offsets 32-35) are indices
        of the two rotating parts (motors, gears) that this belt connects.
        When one rotates, the belt transfers angular velocity to the other.
        """
        if part.state_counter != BELT_RUNNING_STATE:
            return

        parts = self.world.parts
        target1 = parts[part.belt_connected_part_1] if 0 <= part.belt_connected_part_1 < len(parts) else None
        target2 = parts[part.belt_connected_part_2] if 0 <= part.belt_connected_part_2 < len(parts) else None

        if target1 and target2:
            avg = (target1.angular_velocity + target2.angular_velocity) // 2
            if avg != 0:
                target1.angular_velocity = avg
                target2.angular_velocity = avg

    def _handle_cannon(self, part: 'Part', dt: float):
        """Cannon fires projectile when fired."""
        if part.state_counter == CANNON_IDLE_STATE:
            direction = part.facing
            self._spawn_projectile(part, direction)
            part.state_counter = 2  # Mark as fired

    def _spawn_projectile(self, cannon: 'Part', direction: int):
        """Spawn a cannonball projectile."""
        from .part import Part
        projectile = Part()
        projectile.part_type = 0  # Use bowling ball as projectile
        projectile.x = cannon.x + cannon.width_1 // 2
        projectile.y = cannon.y + cannon.height_1 // 2
        projectile.width_1 = CANNONBALL_SIZE
        projectile.height_1 = CANNONBALL_SIZE
        projectile.vel_x = CANNONBALL_SPEED_X * direction
        projectile.vel_y = CANNONBALL_SPEED_Y
        projectile.is_moving = True
        self.world.add_part(projectile)

    def _handle_explosive(self, part: 'Part', dt: float):
        """Explosive - if triggered, explode and damage nearby parts."""
        if part.state_counter != EXPLOSIVE_TRIGGERED_STATE:
            return

        part.explosion_timer = EXPLOSION_DELAY if part.explosion_timer == 0 else part.explosion_timer
        part.explosion_timer -= dt
        if part.explosion_timer <= 0:
            self._create_explosion(part)

    def _create_explosion(self, part: 'Part'):
        """Create explosion effect and damage nearby parts."""
        explosion_radius = EXPLOSION_RADIUS
        explosion_damage = EXPLOSION_DAMAGE

        cx = part.x + part.width_1 // 2
        cy = part.y + part.height_1 // 2

        for other in self.world.parts:
            if other is part:
                continue

            ocx = other.x + other.width_1 // 2
            ocy = other.y + other.height_1 // 2

            dx = ocx - cx
            dy = ocy - cy
            dist = (dx * dx + dy * dy) ** 0.5

            if dist < explosion_radius:
                if dist > 0:
                    force = explosion_damage * (1 - dist / explosion_radius)
                    other.vel_x += int((dx / dist) * force)
                    other.vel_y += int((dy / dist) * force)

                other_behavior = self.registry.get_behavior(other.part_type)
                if other_behavior.get('destructible'):
                    if other not in self.world._parts_to_destroy:
                        self.world._parts_to_destroy.append(other)

        if part not in self.world._parts_to_destroy:
            self.world._parts_to_destroy.append(part)

    def _handle_flashlight(self, part: 'Part', dt: float):
        """Flashlight provides power to connected electrical devices."""
        if part.state_counter != FLASHLIGHT_ON_STATE:
            return

        light_range = FLASHLIGHT_RANGE
        cx = part.x + part.width_1 // 2
        cy = part.y + part.height_1 // 2

        for other in self.world.parts:
            if other is part or other.part_type == 25:
                continue

            ocx = other.x + other.width_1 // 2
            ocy = other.y + other.height_1 // 2

            dx = ocx - cx
            dy = ocy - cy
            dist = (dx * dx + dy * dy) ** 0.5

            if dist < light_range:
                other_behavior = self.registry.get_behavior(other.part_type)
                if other_behavior.get('category') == 'Electrical':
                    if other.state_counter == ELECTRICAL_OFF_STATE:
                        other.state_counter = ELECTRICAL_ON_STATE

    def _handle_anti_gravity(self, part: 'Part', dt: float):
        """Anti-gravity pad floats objects above it."""
        if part.state_counter != ANTI_GRAVITY_ON_STATE:
            return

        gravity_override = ANTI_GRAVITY_FORCE

        for other in self.world.parts:
            if other is part or not other.is_moving:
                continue

            l1, t1, r1, b1 = part.get_collision_box()
            l2, t2, r2, b2 = other.get_collision_box()

            if not (r1 <= l2 or r2 <= l1 or b1 <= t2 or b2 <= t1):
                other.vel_y += gravity_override
                other.y -= 1  # Keep above pad

    def _handle_newton_mouse(self, part: 'Part', dt: float):
        """Newton mouse eats cheese and moves."""
        if part.state_counter != MOUSE_HUNGRY_STATE:
            return

        target = self._find_nearest_cheese(part)
        if target:
            dx = target.x - part.x
            dy = target.y - part.y
            dist = (dx * dx + dy * dy) ** 0.5
            if dist > MOUSE_EAT_DISTANCE:
                speed = MOUSE_SPEED
                part.x += (dx / dist) * speed * dt
                part.y += (dy / dist) * speed * dt
            else:
                part.state_counter = MOUSE_EATEN_STATE

    def _find_nearest_cheese(self, part: 'Part'):
        """Find nearest cheese for mouse."""
        min_dist = float('inf')
        nearest = None

        for other in self.world.parts:
            if other.part_type == 43:  # Cheese
                dx = other.x - part.x
                dy = other.y - part.y
                dist = (dx * dx + dy * dy) ** 0.5
                if dist < min_dist:
                    min_dist = dist
                    nearest = other

        return nearest

    def _handle_laser(self, part: 'Part', dt: float):
        """Laser emits light beam."""
        if part.state_counter != LASER_ON_STATE:
            return

        beam_length = LASER_BEAM_LENGTH

        end_x = part.x + part.width_1 // 2 + beam_length

        for other in self.world.parts:
            if other is part:
                continue

            ol, ot, or_, ob = other.get_collision_box()

            if ol < end_x and or_ > part.x:
                other_behavior = self.registry.get_behavior(other.part_type)
                if other_behavior.get('category') == 'Balloons / Airships':
                    if other.state_counter == BALLOON_IDLE_STATE:
                        other.state_counter = BALLOON_POP_STATE

    def _handle_magnifying_glass(self, part: 'Part', dt: float):
        """Magnifying glass focuses light to start fire — ignites flammable objects in beam path."""
        if part.state_counter != MAGNIFIER_ON_STATE:
            return

        beam_length = MAGNIFIER_BEAM_LENGTH
        origin_x = part.x + part.width_1 // 2
        end_x = origin_x + beam_length

        for other in self.world.parts:
            if other is part:
                continue

            ol, ot, or_, ob = other.get_collision_box()
            if not (ol < end_x and or_ > part.x):
                continue

            other_behavior = self.registry.get_behavior(other.part_type)
            cat = other_behavior.get('category', '')
            if cat in ('Explosives / Projectiles', 'Balloons / Airships'):
                if other.state_counter == IGNITABLE_IDLE_STATE:
                    other.state_counter = IGNITED_STATE

    def _get_portal_rect(self, part: 'Part', edge: str) -> Tuple[int, int, int, int]:
        """Get small detection rectangle at the center of the given collision-box edge."""
        w = part.collision_w if part.collision_w > 0 else part.width_1
        h = part.collision_h if part.collision_h > 0 else part.height_1
        hw = PORTAL_HALF_WIDTH
        if edge == 'left':
            return (part.x, part.y + h // 2 - hw, hw * 2, hw * 2)
        if edge == 'right':
            return (part.x + w - hw * 2, part.y + h // 2 - hw, hw * 2, hw * 2)
        if edge == 'top':
            return (part.x + w // 2 - hw, part.y, hw * 2, hw * 2)
        if edge == 'bottom':
            return (part.x + w // 2 - hw, part.y + h - hw * 2, hw * 2, hw * 2)
        return (part.x, part.y, hw * 2, hw * 2)

    def _moving_part_overlaps_portal(self, portal_rect: Tuple[int, int, int, int],
                                      part: 'Part') -> bool:
        """Check if a moving part's center falls within the portal rect."""
        px, py, pw, ph = portal_rect
        cx = part.x + part.width_1 // 2
        cy = part.y + part.height_1 // 2
        return (px <= cx <= px + pw) and (py <= cy <= py + ph)

    def _trace_pipe_network(self, part: 'Part', entry_edge: str) -> Tuple['Part', str]:
        """BFS through connected pipes to find the ultimate exit.

        Returns (final_pipe, exit_edge) — the pipe and edge where the ball
        should emerge, or (part, entry_edge) if the ball just entered and
        immediately exits through the entrance edge (no routing needed).
        """
        portals = PIPE_PORTALS.get((part.part_type, part.appearance))
        if portals is None:
            return (part, entry_edge)

        port_entry, port_exit = portals
        exit_rect = self._get_portal_rect(part, port_exit)
        visited = {id(part)}

        # BFS: chain through connected pipes
        queue = deque()
        queue.append((part, port_exit, exit_rect))

        last_part = part
        last_exit_edge = port_exit

        while queue:
            current, out_edge, e_rect = queue.popleft()

            # Try to find another pipe whose entrance overlaps our exit
            found = False
            for other in self.world.parts:
                if id(other) in visited or other.part_type not in PIPE_TYPES:
                    continue
                other_portals = PIPE_PORTALS.get((other.part_type, other.appearance))
                if other_portals is None:
                    continue
                other_entry_edge = other_portals[0]
                other_entry_rect = self._get_portal_rect(other, other_entry_edge)
                if self._rects_overlap(e_rect, other_entry_rect):
                    visited.add(id(other))
                    other_exit_edge = other_portals[1]
                    other_exit_rect = self._get_portal_rect(other, other_exit_edge)
                    queue.append((other, other_exit_edge, other_exit_rect))
                    found = True
                    break

            if not found:
                # Dead end — this pipe's exit is the ball's emergence point
                last_part = current
                last_exit_edge = out_edge
                break

        return (last_part, last_exit_edge)

    def _rects_overlap(self, a: Tuple[int, int, int, int],
                        b: Tuple[int, int, int, int]) -> bool:
        """Check if two axis-aligned rectangles overlap."""
        ax, ay, aw, ah = a
        bx, by, bw, bh = b
        return ax < bx + bw and ax + aw > bx and ay < by + bh and ay + ah > by

    def _handle_pipe(self, part: 'Part', dt: float):
        """Pipe system — ball enters one end, BFS-traces network, teleports to exit."""
        portals = PIPE_PORTALS.get((part.part_type, part.appearance))
        if portals is None:
            return

        entry_edge = portals[0]
        entry_rect = self._get_portal_rect(part, entry_edge)

        for other in self.world.parts:
            if other is part or not other.is_moving:
                continue
            if not self._moving_part_overlaps_portal(entry_rect, other):
                continue

            # BFS through pipe network
            exit_part, exit_edge = self._trace_pipe_network(part, entry_edge)
            exit_rect = self._get_portal_rect(exit_part, exit_edge)

            # Teleport ball to exit portal center
            ex, ey, ew, eh = exit_rect
            other.x = ex + ew // 2 - other.width_1 // 2
            other.y = ey + eh // 2 - other.height_1 // 2
            other.pos_x = other.x
            other.pos_y = other.y

            # Apply exit velocity: direction matches exit_edge
            speed = PIPE_EXIT_SPEED
            if exit_edge == 'right':
                other.vel_x = speed
                other.vel_y = 0
            elif exit_edge == 'left':
                other.vel_x = -speed
                other.vel_y = 0
            elif exit_edge == 'top':
                other.vel_x = 0
                other.vel_y = -speed
            elif exit_edge == 'bottom':
                other.vel_x = 0
                other.vel_y = speed
