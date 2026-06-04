"""TIM2 physics — Part class with position, velocity, collision shape."""
from dataclasses import dataclass
from typing import Optional, Tuple
import json
from pathlib import Path

ROPE_PART_TYPES = {7, 10, 76}  # pulley, rope, steel cable

DEFAULT_MAX_GRAVITY = 0x2600   # 9728 — most parts
PAR20_43_MAX_GRAVITY = 0x3000  # 12288 — parts 20 (Phazer) and 43 (Pinball)


@dataclass
class Part:
    """A single puzzle part with physics properties."""
    part_type: int = 0
    name: str = "Unknown"
    
    # Position and dimensions
    x: int = 0
    y: int = 0
    width_1: int = 32
    height_1: int = 32
    width_2: int = 32
    height_2: int = 32
    
    # Physics state (internal, updated each tick) — fixed-point integers
    pos_x: int = 0            # sub-pixel position, >>9 for pixel coords
    pos_y: int = 0
    vel_x: int = 0            # in internal fixed-point units (>>9 to convert)
    vel_y: int = 0
    
    # Flags
    flags_1: int = 0
    flags_2: int = 0
    flags_3: int = 0
    appearance: int = 0
    behavior: int = 0
    
    # Connections
    belt_anchor_x: int = 0
    belt_anchor_y: int = 0
    belt_line_distance: int = 0
    rope_1_anchor_x: int = 0
    rope_1_anchor_y: int = 0
    rope_2_anchor_x: int = 0
    rope_2_anchor_y: int = 0
    connected_1: int = -256
    connected_2: int = -1
    outlet_plugged_1: int = -1
    outlet_plugged_2: int = -1

    # Rope-specific (types 10, 76) — same byte as behavior in level entry,
    # but semantically rope_segment_length. fformat.txt offset 0x18.
    rope_segment_length: int = 200
    
    # Physics properties (from PAR)
    mass: int = 2832
    cor_q8: int = 128         # coefficient of restitution, Q8.8 (128 = 0.5)
    friction_q8: int = 0      # friction, Q8.8
    collision_radius: int = 0 # for circle collision (balls)
    collision_w: int = 0      # for AABB collision (walls)
    collision_h: int = 0
    
    # Base gravity category (from EXE 0x2794B)
    gravity_category: int = 7 # default to heaviest
    
    # Gravity field clamp (PER-part, from EXE 0x53535 + table init at 0x534B2)
    # Clamps gravity_y (0x3A) and gravity_x (0x3C) to ±max_gravity
    max_gravity: int = DEFAULT_MAX_GRAVITY
    
    # Wind force category (from EXE table[part_type] + 0x3E)
    # Used in tick() when flags_3 & 0x08 is set (PH2)
    wind_force: int = 0        # 0 = no wind effect; default set from gravity_base
    
    # State tracking
    current_state: int = 0    # ANM state ID for solution checking
    is_moving: bool = False
    is_solved: bool = False
    
    # State machine (from E-013: FUN_31f7_3bd2)
    state_counter: int = 0    # int16 at file offset 0x10/0x18
    state_prev: int = 0       # previous state (offset 0x12, for change detection)
    sub_counter: int = 0      # sub-state countdown at offset 0xAE
    state_limit_lower: int = 0   # DAT_5b41_19cc
    state_limit_upper: int = 8   # DAT_5b41_19d2
    state_limit_reset: int = 0   # DAT_5b41_19d0
    state_limit_sub_a: int = 5   # DAT_5b41_19d4
    state_limit_sub_b: int = 5   # DAT_5b41_19d6
    
    # Animation frame tracking
    anm_frame: int = 0        # current ANM frame index
    anm_frame_timer: int = 0  # ticks remaining on current frame
    anm_name: str = ""        # ANM file name (from appearance)

    # Behavioral state (motor, pulley, cannon facing)
    motor_connected: bool = False
    angular_velocity: int = 0
    rotation_angle: int = 0
    facing: int = 1           # 1 = right, -1 = left (for cannon direction)

    # Pulley-specific fields (type 7, from timgres fformat.txt offsets 34-54)
    pulley_rope_1_connect_x: int = 0
    pulley_rope_1_connect_y: int = 0
    pulley_rope_2_connect_x: int = 0
    pulley_rope_2_connect_y: int = 0
    rope_index: int = -1      # TIM2 only — index of rope part in this pulley chain

    # Belt-specific fields (type 8, from timgres nt_part_extra_belt)
    belt_connected_part_1: int = -1
    belt_connected_part_2: int = -1

    # Deterministic RNG state (LCG, matches EXE random())
    _rng_state: int = 1
    
    # Explosive countdown (Q6 — moved from dynamic hasattr in behaviors.py)
    explosion_timer: float = 0

    # Programmable ball extra data (type 87, from timgres nt_part_extra_2_prog_ball)
    density: int = 3000       # programmable density (default from fformat.txt)
    elasticity: int = 128     # programmable elasticity
    friction_extra: int = 16  # programmable friction (renamed to avoid collision friction_q8)
    gravity_buoyancy: int = 0 # precomputed lift/fall; negative = rises, positive = falls
    # Note: gravity_buoyancy depends on density, mass, gravity & pressure.
    # Timgres fformat.txt: "If its value is negative, the ball will rise due
    # to the buoyant force rather than fall."
    
    def __post_init__(self):
        self.pos_x = self.x
        self.pos_y = self.y
        self.is_moving = bool(self.flags_1 & 0x1000)
        # wind_force defaults to gravity_base // 4 (same as gravity_y),
        # matching EXE table[part_type]+0x3E which stores per-part wind magnitude.
        # Set to 0 during level loading or explicit assignment to disable wind.
        if self.wind_force == 0:
            self.wind_force = self.gravity_y
        # For rope parts, behavior field IS rope_segment_length (same byte offset 0x18)
        if self.part_type in ROPE_PART_TYPES and self.behavior > 0:
            self.rope_segment_length = self.behavior
    
    def __setattr__(self, name, value):
        super().__setattr__(name, value)
        if name == 'x':
            super().__setattr__('pos_x', value)
        elif name == 'y':
            super().__setattr__('pos_y', value)
    
    def randint(self, lo: int, hi: int) -> int:
        """Deterministic LCG: AX = AX * 0x343FD + 0x269EC3 (EXE random())."""
        self._rng_state = (self._rng_state * 0x343FD + 0x269EC3) & 0xFFFFFFFF
        return lo + (self._rng_state % (hi - lo + 1))
    
    def sync_pos(self):
        """Sync pos_x/pos_y with x/y after manual position changes."""
        self.pos_x = self.x
        self.pos_y = self.y
    
    @property
    def coll_shape(self) -> str:
        """'circle' if has radius, else 'aabb'."""
        return "circle" if self.collision_radius > 0 else "aabb"
    
    @property
    def gravity_base(self) -> int:
        """Base gravity value from EXE 0x2794B lookup table."""
        cat = self.gravity_category
        if cat < 2:    return 0x1C00
        if cat < 6:    return 0x1A00
        if cat < 10:   return 0x1800
        if cat < 21:   return 0x1600
        if cat < 121:  return 0x1400
        if cat < 151:  return 0x1200
        return 0x1000
    
    @property
    def gravity_y(self) -> int:
        """gravity_y = base / 4 (per EXE 0x274F6)."""
        return self.gravity_base // 4
    
    def _clamp_gravity(self, val: int) -> int:
        """Clamp gravity component to ±max_gravity (EXE 0x53535)."""
        if val > self.max_gravity:
            return self.max_gravity
        if val < -self.max_gravity:
            return -self.max_gravity
        return val
    
    def tick(self):
        """Apply velocity integration for one 60 Hz tick using fixed-point integer math.
        
        Per EXE pass 0 at 0x5359F + clamp at 0x53535:
        1. Compute gravity_x from wind direction (flags_3 bit 3)
        2. Clamp both gravity_x and gravity_y to ±max_gravity
        3. Apply to velocity: vel_y += gravity_y; vel_x += gravity_x
        3b. For programmable ball (type 87), apply gravity_buoyancy (PH7)
        4. Update position: pos += vel >> 9
        """
        gy = self._clamp_gravity(self.gravity_y)
        gx = self._compute_gravity_x()
        self.vel_y += gy
        self.vel_x += gx
        # PH7: buoyancy force for programmable ball (type 87)
        if self.gravity_buoyancy != 0:
            self.vel_y += self.gravity_buoyancy
        self.pos_y += self.vel_y >> 9
        self.pos_x += self.vel_x >> 9
        self.x = self.pos_x
        self.y = self.pos_y
    
    def _compute_gravity_x(self) -> int:
        """Wind/gravity_x from flags_3 bit 3 (PH2, EXE 0x535C9).
        
        EXE flow at 0x535C9-0x535D9:
          if flags_3 & 0x08: gravity_x -= category (wind from left)
          else:              gravity_x += category (wind from right)
        
        The category (wind_force) is a per-part value from the property table
        at [DI+0x3E]. Each tick the wind accumulates until clamped to max_gravity.
        """
        wf = self.wind_force
        if wf == 0:
            return 0
        if self.flags_3 & 0x08:
            return -self._clamp_gravity(wf)
        return self._clamp_gravity(wf)
    
    def advance_state(self):
        """Advance state counter like FUN_31f7_3bd2 (E-013). Uses deterministic LCG."""
        self.state_prev = self.state_counter
        
        if self.sub_counter == 0:
            if self.state_counter != 0:
                if self.state_counter < self.state_limit_lower:
                    self.state_counter = self.state_limit_lower - 1
                self.state_counter += 1
                if self.state_counter >= self.state_limit_upper:
                    self.state_counter = self.state_limit_reset
            else:
                # Zero state — random delay (deterministic LCG)
                if self._rng_state & 1:
                    if not hasattr(self, '_countdown') or self._countdown < 0:
                        self._countdown = self.randint(40, 239)
                    self._countdown -= 1
                    if self._countdown < 0:
                        self.state_counter += 1
                        self._countdown = self.randint(40, 239)
                else:
                    self.state_counter += 1
        else:
            # Sub-state countdown
            self.sub_counter -= 1
            if self.sub_counter == 0:
                # Sub-state expired — reverse direction based on flags
                direction = -1 if (self.flags_1 & 0x10) else 1
                self.state_counter = self.state_limit_reset
            else:
                self.state_counter += 1
                if self.state_counter >= self.state_limit_sub_a:
                    self.state_counter = self.state_limit_sub_b
        
        return self.state_counter != self.state_prev
    
    def on_collision(self, other: 'Part'):
        """Called when this part collides with another (from W5/W7).
        Updates state and returns True if state changed."""
        state_changed = False
        if self.state_counter < self.state_limit_upper:
            self.state_counter += 1
            state_changed = True
        self.current_state = self.state_counter
        return state_changed
    
    def get_collision_box(self) -> Tuple[int, int, int, int]:
        """Get AABB: (left, top, right, bottom).
        
        Uses collision dimensions if set, else part dimensions.
        """
        w = self.collision_w if self.collision_w > 0 else self.width_1
        h = self.collision_h if self.collision_h > 0 else self.height_1
        return (self.x, self.y, self.x + w, self.y + h)
    
    def get_circle(self) -> Tuple[int, int, int]:
        """Get circle: (cx, cy, radius)."""
        r = self.collision_radius
        cx = self.x + self.width_1 // 2
        cy = self.y + self.height_1 // 2
        return (cx, cy, r)
    
    def aabb_overlap(self, other: 'Part') -> bool:
        """Check AABB overlap with another part."""
        l1, t1, r1, b1 = self.get_collision_box()
        l2, t2, r2, b2 = other.get_collision_box()
        return l1 < r2 and r1 > l2 and t1 < b2 and b1 > t2

    def circle_overlap(self, other: 'Part') -> bool:
        """Circle-vs-circle overlap: distance < sum of radii. PH4."""
        cx1, cy1, r1 = self.get_circle()
        cx2, cy2, r2 = other.get_circle()
        dx = cx1 - cx2
        dy = cy1 - cy2
        return dx*dx + dy*dy < (r1 + r2) * (r1 + r2)

    def circle_aabb_overlap(self, other: 'Part') -> bool:
        """Circle-vs-AABB overlap: closest point on AABB to circle center < radius. PH4."""
        cx, cy, r = self.get_circle()
        l, t, r_b, b = other.get_collision_box()
        closest_x = max(l, min(cx, r_b))
        closest_y = max(t, min(cy, b))
        dx = cx - closest_x
        dy = cy - closest_y
        return dx*dx + dy*dy < r * r
    
    def distance_to(self, other: 'Part') -> float:
        """Euclidean distance between centers."""
        cx1 = self.x + self.width_1 / 2
        cy1 = self.y + self.height_1 / 2
        cx2 = other.x + other.width_2 / 2
        cy2 = other.y + other.height_2 / 2
        return ((cx1 - cx2)**2 + (cy1 - cy2)**2) ** 0.5
    
    def to_dict(self) -> dict:
        """Serialize to dict for YAML output."""
        phys = {
            "behavior": int(self.behavior),
            "belt_anchor": {"x": int(self.belt_anchor_x), "y": int(self.belt_anchor_y)},
            "belt_line_distance": int(self.belt_line_distance),
            "rope_1_anchor": {"x": int(self.rope_1_anchor_x), "y": int(self.rope_1_anchor_y)},
            "rope_2_anchor": {"x": int(self.rope_2_anchor_x), "y": int(self.rope_2_anchor_y)},
            "connected_1": int(self.connected_1),
            "connected_2": int(self.connected_2),
            "outlet_plugged_1": int(self.outlet_plugged_1),
            "outlet_plugged_2": int(self.outlet_plugged_2),
        }
        if self.part_type in ROPE_PART_TYPES:
            phys["rope_segment_length"] = int(self.rope_segment_length)
        if self.part_type == 7:
            phys["pulley"] = {
                "rope_1_connect_x": int(self.pulley_rope_1_connect_x),
                "rope_1_connect_y": int(self.pulley_rope_1_connect_y),
                "rope_2_connect_x": int(self.pulley_rope_2_connect_x),
                "rope_2_connect_y": int(self.pulley_rope_2_connect_y),
                "rope_index": int(self.rope_index),
            }
        if self.part_type == 8:
            phys["belt"] = {
                "connected_part_1": int(self.belt_connected_part_1),
                "connected_part_2": int(self.belt_connected_part_2),
            }
        if self.part_type == 87:
            phys["programmable"] = {
                "density": int(self.density),
                "elasticity": int(self.elasticity),
                "friction": int(self.friction_extra),
                "gravity_buoyancy": int(self.gravity_buoyancy),
            }
        return {
            "part_type": self.part_type,
            "x": int(self.x), "y": int(self.y),
            "appearance": int(self.appearance),
            "flags": {
                "flag_1": f"0x{self.flags_1:04x}",
                "flag_2": f"0x{self.flags_2:04x}",
                "flag_3": f"0x{self.flags_3:04x}",
            },
            "dimensions": {
                "width_1": int(self.width_1),
                "height_1": int(self.height_1),
                "width_2": int(self.width_2),
                "height_2": int(self.height_2),
            },
            "physics": phys,
        }
    
    @classmethod
    def from_dict(cls, d: dict) -> 'Part':
        p = cls(part_type=d.get("part_type", 0))
        p.x = d.get("x", 0)
        p.y = d.get("y", 0)
        p.appearance = d.get("appearance", 0)
        
        # Parse hex flags
        flags = d.get("flags", {})
        p.flags_1 = int(flags.get("flag_1", "0x0000"), 16)
        p.flags_2 = int(flags.get("flag_2", "0x0000"), 16)
        p.flags_3 = int(flags.get("flag_3", "0x0000"), 16)
        
        dims = d.get("dimensions", {})
        p.width_1 = dims.get("width_1", 32)
        p.height_1 = dims.get("height_1", 32)
        p.width_2 = dims.get("width_2", 32)
        p.height_2 = dims.get("height_2", 32)
        
        phys = d.get("physics", {})
        p.behavior = phys.get("behavior", 0)
        ba = phys.get("belt_anchor", {})
        p.belt_anchor_x = ba.get("x", 0)
        p.belt_anchor_y = ba.get("y", 0)
        p.belt_line_distance = phys.get("belt_line_distance", 0)
        ra1 = phys.get("rope_1_anchor", {})
        p.rope_1_anchor_x = ra1.get("x", 0)
        p.rope_1_anchor_y = ra1.get("y", 0)
        ra2 = phys.get("rope_2_anchor", {})
        p.rope_2_anchor_x = ra2.get("x", 0)
        p.rope_2_anchor_y = ra2.get("y", 0)
        p.connected_1 = phys.get("connected_1", -256)
        p.connected_2 = phys.get("connected_2", -1)
        p.outlet_plugged_1 = phys.get("outlet_plugged_1", -1)
        p.outlet_plugged_2 = phys.get("outlet_plugged_2", -1)

        # PH12: rope_segment_length (same byte as behavior for rope types)
        if p.part_type in ROPE_PART_TYPES and p.behavior > 0:
            p.rope_segment_length = p.behavior

        prog = phys.get("programmable", {})
        if prog:
            p.density = prog.get("density", 3000)
            p.elasticity = prog.get("elasticity", 128)
            p.friction_extra = prog.get("friction", 16)
            p.gravity_buoyancy = prog.get("gravity_buoyancy", 0)
        
        p.is_moving = bool(p.flags_1 & 0x1000)
        return p
    

