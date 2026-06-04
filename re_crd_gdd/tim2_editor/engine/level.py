"""Level loader/saver — reads YAML files, creates physics world."""
import logging
from typing import List, Optional, Tuple, Dict, Any
from pathlib import Path
import yaml

from .part import Part, ROPE_PART_TYPES
from .world import PhysicsWorld, DEFAULT_PRESSURE
from .behavior import get_registry

logger = logging.getLogger(__name__)


class SolutionCondition:
    """A single solution condition from a level."""
    def __init__(self, part_index: int = -1, state_1: int = 0, state_2: int = 0,
                 count: int = 0, rect: Tuple[int, int, int, int] = (0, 0, 0, 0)):
        self.part_index = part_index
        self.state_1 = state_1
        self.state_2 = state_2
        self.count = count
        self.rect = rect  # (x, y, w, h)
    
    @property
    def is_off_screen(self) -> bool:
        return self.rect == (-1, -1, -1, -1)
    
    @property
    def is_off_top(self) -> bool:
        return self.rect == (-500, -2000, 1640, 2000)
    
    @property
    def is_off_bottom(self) -> bool:
        return self.rect == (-500, 400, 1640, 3000)
    
    @property
    def has_position(self) -> bool:
        return self.rect != (0, 0, 0, 0)
    
    def check(self, world: PhysicsWorld) -> bool:
        """Check if this condition is met."""
        part = world.get_part_by_index(self.part_index)
        if part is None:
            return False
        
        if self.has_position:
            if self.is_off_screen:
                return not world._in_viewport(part)
            if self.is_off_top:
                return part.y + part.height_1 < 0
            rx, ry, rw, rh = self.rect
            return (rx <= part.x <= rx + rw and ry <= part.y <= ry + rh)
        else:
            return part.current_state == self.state_1


class LevelData:
    """Holds all data for a level."""
    def __init__(self):
        self.title: str = ""
        self.goal: str = ""
        self.magic: str = "EF AC 13 01"
        self.bg_color: int = 0
        self.pressure: int = DEFAULT_PRESSURE
        self.gravity: int = 272
        self.music_track: int = 1000
        self.hints: List[dict] = []
        self.parts: List[Part] = []
        self.solution_conditions: List[SolutionCondition] = []
        self.solution_delay: int = 0


def _parse_flags(val: Any) -> int:
    """Parse a YAML flag value to int. Supports hex strings like '0x6000' and bare ints."""
    if isinstance(val, int):
        return val
    if isinstance(val, str):
        return int(val.strip(), 16) if val.startswith('0x') else int(val)
    return 0


def load_yaml(path: Path) -> LevelData:
    """Load a level from a YAML file using PyYAML."""
    level = LevelData()
    try:
        text = path.read_text()
    except FileNotFoundError:
        return level
    except IOError:
        return level
    try:
        data = yaml.safe_load(text)
    except (yaml.YAMLError, ValueError):
        return level
    if data is None:
        return level

    info = data.get("level_info", {})
    level.title = info.get("title", "")
    level.goal = info.get("goal_description", "")
    level.bg_color = info.get("background_color", 0)
    level.magic = info.get("magic_number", "EF AC 13 01")

    env = data.get("environment", {})
    level.pressure = env.get("pressure", DEFAULT_PRESSURE)
    level.gravity = env.get("gravity", 272)
    level.music_track = env.get("music_track", 1000)

    hints = data.get("hints", {})
    for entry in hints.get("entries", []):
        level.hints.append({
            "id": entry.get("hint_id", 0),
            "x": entry.get("x", 0),
            "y": entry.get("y", 0),
            "text": entry.get("text", ""),
        })

    parts = data.get("parts", {})
    validated_types: set = set()
    for group in ("fixed", "moving"):
        for pd in parts.get(group, []):
            part = Part(part_type=pd.get("part_type", 0))
            pt = part.part_type
            if pt not in validated_types:
                validated_types.add(pt)
                registry = get_registry()
                orphans = registry.validate_orphan_states(pt)
                if orphans:
                    logger.warning(
                        "SM4: Part %d has %d orphan ANM states (no SOLVE.RES path): %s",
                        pt, len(orphans), orphans)
                broken = registry.validate_trigger_chains(pt)
                for warn in broken:
                    logger.warning("SM5: %s", warn)
            part.x = pd.get("x", 0)
            part.y = pd.get("y", 0)
            part.appearance = pd.get("appearance", 0)

            flags = pd.get("flags", {})
            part.flags_1 = _parse_flags(flags.get("flag_1", 0))
            part.flags_2 = _parse_flags(flags.get("flag_2", 0))
            part.flags_3 = _parse_flags(flags.get("flag_3", 0))

            dims = pd.get("dimensions", {})
            part.width_1 = dims.get("width_1", 32)
            part.height_1 = dims.get("height_1", 32)
            part.width_2 = dims.get("width_2", 32)
            part.height_2 = dims.get("height_2", 32)

            phys = pd.get("physics", {})
            part.behavior = phys.get("behavior", 0)
            ba = phys.get("belt_anchor", {})
            part.belt_anchor_x = ba.get("x", 0)
            part.belt_anchor_y = ba.get("y", 0)
            part.belt_line_distance = phys.get("belt_line_distance", 0)
            ra1 = phys.get("rope_1_anchor", {})
            part.rope_1_anchor_x = ra1.get("x", 0)
            part.rope_1_anchor_y = ra1.get("y", 0)
            ra2 = phys.get("rope_2_anchor", {})
            part.rope_2_anchor_x = ra2.get("x", 0)
            part.rope_2_anchor_y = ra2.get("y", 0)
            part.connected_1 = phys.get("connected_1", -256)
            part.connected_2 = phys.get("connected_2", -1)
            part.outlet_plugged_1 = phys.get("outlet_plugged_1", -1)
            part.outlet_plugged_2 = phys.get("outlet_plugged_2", -1)

            # PH12: rope_segment_length (stored as behavior in YAML for rope types)
            if part.part_type in ROPE_PART_TYPES and part.behavior > 0:
                part.rope_segment_length = part.behavior

            # PH7: Programmable ball extra data (type 87)
            prog = phys.get("programmable", {})
            if prog:
                part.density = prog.get("density", 3000)
                part.elasticity = prog.get("elasticity", 128)
                part.friction_extra = prog.get("friction", 16)
                part.gravity_buoyancy = prog.get("gravity_buoyancy", 0)

            part.is_moving = bool(part.flags_1 & 0x1000)
            level.parts.append(part)

    sol = data.get("solution", {})
    if sol:
        level.solution_delay = sol.get("delay", 0)
        for cd in sol.get("conditions", []):
            r = cd.get("rect", {})
            sc = SolutionCondition(
                part_index=cd.get("part_index", -1),
                state_1=cd.get("part_state_1", 0),
                state_2=cd.get("part_state_2", 0),
                count=cd.get("part_count", 0),
                rect=(r.get("x", 0), r.get("y", 0), r.get("width", 0), r.get("height", 0)),
            )
            level.solution_conditions.append(sc)

    return level


def save_yaml(path: Path, level: LevelData):
    """Save level to YAML file."""
    lines = []
    lines.append("level_info:")
    lines.append(f"  magic_number: {level.magic}")
    if level.bg_color:
        lines.append(f"  background_color: {level.bg_color}")
    lines.append(f"  title: {level.title}")
    lines.append(f"  goal_description: {level.goal}")
    
    lines.append("environment:")
    lines.append(f"  pressure: {level.pressure}")
    lines.append(f"  gravity: {level.gravity}")
    lines.append(f"  music_track: {level.music_track}")
    
    # Hints
    lines.append("hints:")
    lines.append(f"  active_hints_count: {len(level.hints)}")
    lines.append("  entries:")
    for h in level.hints:
        lines.append(f"  - hint_id: {h['id']}")
        lines.append(f"    x: {h['x']}")
        lines.append(f"    y: {h['y']}")
        lines.append(f"    icon_flip: 0")
        lines.append(f"    text: {h['text']}")
    
    # Parts
    fixed = [p for p in level.parts if not p.is_moving]
    moving = [p for p in level.parts if p.is_moving]
    lines.append("parts:")
    lines.append(f"  fixed_count: {len(fixed)}")
    lines.append(f"  moving_count: {len(moving)}")
    
    for label, plist in [("fixed", fixed), ("moving", moving)]:
        lines.append(f"  {label}:")
        for p in plist:
            lines.append(f"  - part_type: {p.part_type}")
            lines.append(f"    x: {p.x}")
            lines.append(f"    y: {p.y}")
            lines.append(f"    appearance: {p.appearance}")
            lines.append(f"    flags:")
            lines.append(f"      flag_1: '0x{p.flags_1:04x}'")
            lines.append(f"      flag_2: '0x{p.flags_2:04x}'")
            lines.append(f"      flag_3: '0x{p.flags_3:04x}'")
            lines.append(f"    dimensions:")
            lines.append(f"      width_1: {p.width_1}")
            lines.append(f"      height_1: {p.height_1}")
            lines.append(f"      width_2: {p.width_2}")
            lines.append(f"      height_2: {p.height_2}")
            lines.append(f"    physics:")
            lines.append(f"      behavior: {p.behavior}")
            lines.append(f"      belt_anchor:")
            lines.append(f"        x: {p.belt_anchor_x}")
            lines.append(f"        y: {p.belt_anchor_y}")
            lines.append(f"      belt_line_distance: {p.belt_line_distance}")
            lines.append(f"      rope_1_anchor:")
            lines.append(f"        x: {p.rope_1_anchor_x}")
            lines.append(f"        y: {p.rope_1_anchor_y}")
            lines.append(f"      rope_2_anchor:")
            lines.append(f"        x: {p.rope_2_anchor_x}")
            lines.append(f"        y: {p.rope_2_anchor_y}")
            lines.append(f"      connected_1: {p.connected_1}")
            lines.append(f"      connected_2: {p.connected_2}")
            lines.append(f"      outlet_plugged_1: {p.outlet_plugged_1}")
            lines.append(f"      outlet_plugged_2: {p.outlet_plugged_2}")
            # PH12: Write rope_segment_length as behavior for rope types
            if p.part_type in (10, 76) and p.rope_segment_length != 200:
                lines.append(f"      rope_segment_length: {p.rope_segment_length}")
            if p.part_type == 87:
                lines.append(f"      programmable:")
                lines.append(f"        density: {p.density}")
                lines.append(f"        elasticity: {p.elasticity}")
                lines.append(f"        friction: {p.friction_extra}")
                lines.append(f"        gravity_buoyancy: {p.gravity_buoyancy}")
    
    # Solution
    if level.solution_conditions:
        lines.append("solution:")
        lines.append(f"  conditions_count: {len(level.solution_conditions)}")
        lines.append(f"  delay: {level.solution_delay}")
        lines.append("  conditions:")
        for sc in level.solution_conditions:
            lines.append(f"  - part_index: {sc.part_index}")
            lines.append(f"    part_state_1: {sc.state_1}")
            lines.append(f"    part_state_2: {sc.state_2}")
            lines.append(f"    part_count: {sc.count}")
            lines.append(f"    rect:")
            lines.append(f"      x: {sc.rect[0]}")
            lines.append(f"      y: {sc.rect[1]}")
            lines.append(f"      width: {sc.rect[2]}")
            lines.append(f"      height: {sc.rect[3]}")
    
    path.write_text('\n'.join(lines))
