"""Solution checker — validates level completion conditions."""
from typing import List, Tuple
from .world import PhysicsWorld
from .level import SolutionCondition


class SolutionChecker:
    """Checks if all solution conditions are met."""
    
    def __init__(self, conditions: List[SolutionCondition]):
        self.conditions = conditions
    
    def check(self, world: PhysicsWorld) -> Tuple[bool, List[str]]:
        """
        Check all conditions against the current world state.
        Returns (all_met, failed_conditions).
        """
        all_met = True
        failed = []
        
        for i, cond in enumerate(self.conditions):
            met = cond.check(world)
            if not met:
                all_met = False
                failed.append(f"condition_{i}: part_{cond.part_index} "
                              f"state=({cond.state_1},{cond.state_2}) "
                              f"rect={cond.rect}")
        
        return all_met, failed
