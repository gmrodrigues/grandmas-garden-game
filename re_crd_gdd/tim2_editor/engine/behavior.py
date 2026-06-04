"""Part behavior system — category-level rules + SOLVE.RES state transitions.

Architecture:
  PartBehaviorRegistry holds rules for all 19 categories.
  Each rule is a dict of {behavior_type: handler_function}.
  Per-part customization comes from SOLVE.RES decoded data.
  
  Behavior types:
    "on_collision"    — triggered when part collides with another
    "on_electrical"   — power/electrical signal received
    "on_proximity"    — near-field interaction (fire heats balloon)
    "on_timer"        — time-based state change
    "on_activate"     — generic activation (button/switch)
    "on_create"       — part instantiated (creates sub-parts)
    "on_destroy"      — part destroyed (explosive chain reaction)
    "can_destroy"     — is this part destructible? (bool)
    "explosive"       — explodes on trigger (bool)
"""

import json
from pathlib import Path
from typing import Dict, List, Optional, Any


PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent


def _load_json(path: Path) -> Any:
    if path.exists():
        return json.loads(path.read_text())
    return {}


class PartBehaviorRegistry:
    """Registry of behavior rules per part type.

    Loads SOLVE.RES decoded data and maps category-level rules.
    """

    def __init__(self, solve_data: Optional[dict] = None):
        self.solve_data = solve_data or _load_json(
            PROJECT_ROOT / "build" / "phase-16" / "solve-decoded.json"
        )

        # Part catalog for name/category lookup
        self.name_catalog_raw = _load_json(PROJECT_ROOT / "build" / "phase-9" / "part-name-catalog.json")
        self.name_catalog = {e["part_type"]: e for e in self.name_catalog_raw}

        # Property catalog (PAR file data) for physics properties
        self.prop_catalog = {e["part_type"]: e for e in
            _load_json(PROJECT_ROOT / "build" / "phase-9" / "part-properties.json")}

        # ANM state data (for state limit calculation)
        self.godot_behaviors = _load_json(
            PROJECT_ROOT / "build" / "phase-16" / "godot" / "behaviors.json")
        self._godot_behaviors_by_pt = {int(k): v for k, v in self.godot_behaviors.items()}

        # Category-level rule definitions
        self.category_rules = self._build_category_rules()

        # Per-part compiled behaviors
        self.behaviors: Dict[int, dict] = {}
        self._compile_behaviors()

        # Per-part sound mappings
        self._part_sounds: Dict[int, List[int]] = {}
        self._load_part_sounds()

        # Physics properties lookup (built from prop_catalog)
        self._physics_props: Dict[int, dict] = {}
        self._build_physics_props()

        # SM4: pre-computed orphan ANM states from state-machine analysis
        self._state_machine_report = _load_json(
            PROJECT_ROOT / "build" / "phase-19" / "state-machine-report.json")
        self._orphan_states: Dict[str, list] = self._state_machine_report.get(
            "orphan_anm_states", {}).get("by_part", {})

        # SM5: state-part matrix for ANM state coverage validation
        self._state_part_matrix = _load_json(
            PROJECT_ROOT / "build" / "phase-9" / "state-part-matrix.json")
        # Build reverse: ANM name → set of valid state IDs
        self._anm_states_by_part: Dict[int, set] = {}
        anm_to_states = self._state_part_matrix.get("state_to_parts", {})
        for state_id_str, anms in anm_to_states.items():
            sid = int(state_id_str)
            for anm in anms:
                if anm.startswith("PART") and anm[4:].isdigit():
                    pt = int(anm[4:])
                    self._anm_states_by_part.setdefault(pt, set()).add(sid)
    
    def _build_category_rules(self) -> dict:
        """Define category-level interaction patterns.
        
        Each category maps to a behavior profile with:
          triggers: list of trigger types this category responds to
          rules: {trigger_type: handler_info}
        """
        return {
            "Balls": {
                "triggers": ["collision", "trap"],
                "rules": {
                    "collision": {
                        "response": "state_advance",
                        "activate_others": True,
                        "sound_on_hit": True,
                    }
                },
                "destructible": False,
                "spawns": None,
            },
            "Balloons / Airships": {
                "triggers": ["collision", "proximity"],
                "rules": {
                    "proximity": {
                        "response": "state_transition",
                        "trigger_if_other_in_category": ["Explosives", "Light / Flame Sources"],
                        "state_name": "Popped",
                    },
                    "collision": {
                        "response": "state_transition",
                        "trigger_if_other_in_category": ["Cutting / Popping"],
                        "state_name": "Popped",
                    },
                },
                "destructible": True,
                "spawns": None,
            },
            "Rotating Power Sources": {
                "triggers": ["collision", "electrical", "rope"],
                "rules": {
                    "electrical": {"response": "toggle_on_off"},
                    "collision": {"response": "activate"},
                    "rope": {"response": "transmit_force"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Characters": {
                "triggers": ["collision", "proximity"],
                "rules": {
                    "collision": {"response": "eat_or_activate"},
                    "proximity": {"response": "sleep_or_flee"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Explosives / Projectiles": {
                "triggers": ["collision", "proximity", "timer"],
                "rules": {
                    "collision": {"response": "explode_chain"},
                    "proximity": {"response": "explode_if_fire"},
                    "timer": {"response": "launch_or_explode"},
                },
                "destructible": True,
                "spawns": "projectile",  # cannonball, bullet, rocket
            },
            "Electrical": {
                "triggers": ["electrical", "collision"],
                "rules": {
                    "electrical": {"response": "power_on_off"},
                    "collision": {"response": "toggle"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Lasers / Optics": {
                "triggers": ["electrical", "proximity", "collision"],
                "rules": {
                    "electrical": {"response": "activate"},
                    "proximity": {"response": "detect_beam"},
                    "collision": {"response": "bounce_mirror"},
                },
                "destructible": False,
                "spawns": "laser_beam",
            },
            "Light / Flame Sources": {
                "triggers": ["proximity", "electrical"],
                "rules": {
                    "proximity": {
                        "response": "ignite",
                        "ignites_categories": [
                            "Balloons / Airships",
                            "Explosives / Projectiles",
                        ],
                    },
                    "electrical": {"response": "toggle_on_off"},
                },
                "destructible": False,
                "spawns": "fire",
            },
            "Pipe Systems": {
                "triggers": ["collision", "electrical"],
                "rules": {
                    "collision": {"response": "transport"},
                    "electrical": {"response": "activate"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Springs / Pneumatics": {
                "triggers": ["collision", "electrical"],
                "rules": {
                    "collision": {"response": "spring_or_pump"},
                    "electrical": {"response": "activate"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Containers": {
                "triggers": ["collision"],
                "rules": {
                    "collision": {"response": "fill_or_collect"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Cutting / Popping": {
                "triggers": ["collision"],
                "rules": {
                    "collision": {"response": "pop_on_contact"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Pool Table": {
                "triggers": ["collision"],
                "rules": {
                    "collision": {"response": "pocket_ball"},
                },
                "destructible": False,
                "spawns": None,
            },
            "Special Mechanics": {
                "triggers": ["collision", "electrical", "proximity"],
                "rules": {
                    "collision": {"response": "custom_solve"},
                    "electrical": {"response": "custom_solve"},
                    "proximity": {"response": "custom_solve"},
                },
                "destructible": False,
                "spawns": "custom",
            },
            # Static categories — no behavior
            "Walls / Floors": {"triggers": [], "rules": {}, "destructible": True},
            "Inclines": {"triggers": [], "rules": {}, "destructible": False},
            "Scenery": {"triggers": [], "rules": {}, "destructible": True},
            "Ropes / Belts / Pulleys": {"triggers": [], "rules": {}, "destructible": False},
            "Created / Phantom": {"triggers": [], "rules": {}, "destructible": False},
        }
    
    def _compile_behaviors(self):
        """Compile per-part behaviors from SOLVE.RES + category rules."""
        for pt_str, solve_entry in self.solve_data.items():
            pt = int(pt_str)
            cat_name = solve_entry.get("category", "Unknown")
            cat_rules = self.category_rules.get(cat_name, {})

            behavior = {
                "part_type": pt,
                "category": cat_name,
                "name": solve_entry.get("solve_name", f"Part{pt}"),
                "triggers": list(cat_rules.get("triggers", [])),
                "rules": dict(cat_rules.get("rules", {})),
                "destructible": cat_rules.get("destructible", False),
                "spawns": cat_rules.get("spawns"),
                "solve_states": solve_entry.get("states", []),
                "explosive": self._has_explosive(solve_entry),
            }
            self.behaviors[pt] = behavior

    def _build_physics_props(self):
        """Build physics property lookup from PAR file data.
        
        PAR files use 3 different formats depending on format_id.
        Maps: part_type → {mass, cor_q8, friction_q8, collision_radius, collision_w, collision_h}
        """
        defaults = {"mass": 2832, "cor_q8": 128, "friction_q8": 0,
                    "collision_radius": 0, "collision_w": 0, "collision_h": 0}

        for entry in self.prop_catalog.values():
            pt = entry["part_type"]
            fields = {f["name"]: f["raw"] for f in entry["fields"]}
            fmt = entry.get("format_id", "")

            if fmt == "par_80b_40w":
                # Oldest format: has mass, damping, cor_q8, radius
                mass = fields.get("mass", 2832)
                cor = fields.get("cor_q8", 128)
                friction = fields.get("damping", 0)  # damping doubles as friction
                radius = fields.get("radius", 0)
                cw = fields.get("sprite_w", 0)
                ch = fields.get("sprite_h", 0)
            elif fmt == "par_56b_28w":
                # Mid format: has mass, property_q8, dim_w1/h1, collision_w/h, friction_q8
                mass = fields.get("mass", 2832)
                cor = fields.get("property_q8", 128)  # property_q8 used as COR
                friction = fields.get("friction_q8", 0)
                cw = fields.get("collision_w", 0)
                ch = fields.get("collision_h", 0)
                radius = 0
            else:
                # Newest format (par_236b_118w or unknown): has property_q8, dim_w1/h1
                mass = fields.get("unk_2", 1000)  # unk_2 appears to be mass-like
                cor = fields.get("property_q8", 128)
                friction = fields.get("damping", fields.get("field_18", 0))
                cw = fields.get("dim_w1", 0)
                ch = fields.get("dim_h1", 0)
                radius = 0

            self._physics_props[pt] = {
                "mass": mass,
                "cor_q8": cor,
                "friction_q8": friction,
                "collision_radius": radius,
                "collision_w": cw,
                "collision_h": ch,
            }

        # Fill gaps with defaults
        for pt in range(300):
            if pt not in self._physics_props:
                self._physics_props[pt] = dict(defaults)

    def get_physics_props(self, part_type: int) -> dict:
        """Return physics properties for a part type."""
        return self._physics_props.get(part_type, {
            "mass": 2832, "cor_q8": 128, "friction_q8": 0,
            "collision_radius": 0, "collision_w": 0, "collision_h": 0,
        })
    
    def _load_part_sounds(self):
        """Load per-part sound ID mappings from part-assets.json."""
        assets = _load_json(PROJECT_ROOT / "build" / "phase-16" / "part-assets.json")
        for entry in assets:
            pt = entry.get("part_type")
            sounds = entry.get("sounds", [])
            if pt is not None and sounds:
                self._part_sounds[pt] = sounds

    def get_sounds_for_part(self, part_type: int) -> List[int]:
        """Return sound IDs associated with a part type. Empty list if none."""
        return self._part_sounds.get(part_type, [])

    def get_state_limits_for_part(self, part_type: int) -> dict:
        """Return state machine limits for a part type.

        Uses ANM state count from godot/behaviors.json as limit_upper.
        Returns: {limit_lower, limit_upper, limit_reset, limit_sub_a, limit_sub_b}
        """
        godot_be = self._godot_behaviors_by_pt.get(part_type, {})
        n_states = len(godot_be.get("states", []))
        limit_upper = max(n_states, 1) if n_states > 0 else 8
        return {
            "limit_lower": 0,
            "limit_upper": limit_upper,
            "limit_reset": 0,
            "limit_sub_a": 5,
            "limit_sub_b": 5,
        }

    def _has_explosive(self, solve_entry: dict) -> bool:
        """Check if any state has explosive flag."""
        for s in solve_entry.get("states", []):
            if s.get("explosive"):
                return True
        return False
    
    def get_behavior(self, part_type: int) -> dict:
        """Get compiled behavior for a part type."""
        return self.behaviors.get(part_type, {
            "part_type": part_type,
            "category": "Unknown",
            "name": f"Part{part_type}",
            "triggers": [],
            "rules": {},
            "destructible": False,
            "spawns": None,
            "solve_states": [],
            "explosive": False,
        })
    
    def resolve_solve_state(self, part_type: int, trigger: dict) -> Optional[dict]:
        """Given a trigger (self_state, other_state), find the matching state transition.
        
        Returns the target state entry from SOLVE.RES, or None.
        """
        behavior = self.get_behavior(part_type)
        states = behavior.get("solve_states", [])
        
        for state in states:
            for t in state.get("triggers", []):
                if t["self"] == trigger.get("self") and t["other"] == trigger.get("other"):
                    return state
        
        return None
    
    def validate_orphan_states(self, part_type: int) -> List[int]:
        """SM4: Check for orphan ANM states (defined in ANM but no SOLVE.RES path).

        Returns list of orphan state IDs for this part type.
        WARNING: these states are defined in the ANM file but unreachable
        through any SOLVE.RES trigger path during normal gameplay.
        """
        return list(self._orphan_states.get(str(part_type), []))

    def validate_trigger_chains(self, part_type: int) -> List[str]:
        """SM5: Check SOLVE.RES trigger chains for broken references.

        For each SOLVE.RES state's anm_state, verify the target ANM state
        actually exists in the part's ANM file. Returns list of warning
        strings describing broken chains.
        """
        behavior = self.get_behavior(part_type)
        states = behavior.get("solve_states", [])
        valid_states = self._anm_states_by_part.get(part_type, set())
        warnings = []
        for state in states:
            target = state.get("anm_state")
            if target is not None and target not in valid_states:
                warnings.append(
                    f"Part {part_type}: SOLVE.RES state '{state.get('name')}' "
                    f"targets ANM state {target} which does not exist in ANM "
                    f"(valid ANM states: {sorted(valid_states)})"
                )
        return warnings

    def get_part_info(self, part_type: int) -> dict:
        """Get catalog info for a part type."""
        return self.name_catalog.get(part_type, {})


# Singleton
_registry: Optional[PartBehaviorRegistry] = None

def get_registry() -> PartBehaviorRegistry:
    global _registry
    if _registry is None:
        _registry = PartBehaviorRegistry()
    return _registry
