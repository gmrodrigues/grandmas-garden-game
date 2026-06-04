# TIM2 Clean Room: Godot Game Specification

This directory serves as the definitive, standalone Game Design Document and Technical Specification for the Godot 4.6 reimplementation of *The Incredible Machine 2*.

> **Clean Room Principle**: No original game code was referenced in the creation of this document. This spec is derived entirely from reproducible binary analysis experiments documented in `docs/experiments/` and the resulting Python validation prototype.

## Table of Contents

1. [Game Overview](01_game_overview.md)
   - Core Loop, Game Modes, Mechanics, UI/UX Flow
2. [Godot Architecture](02_godot_architecture.md)
   - Backend-First Separation, GDScript Mappings, Scene Tree
3. [Data Structures](03_data_structures.md)
   - Part Structs, Flag Semantics, Level Binary Format, Solution Blocks
4. [Physics Engine](04_physics_engine.md)
   - 60Hz Tick, Gravity, Collision Detection (AABB), Constraint Solvers
5. [State Machine](05_state_machine.md)
   - State Storage, Execution Engine, Transitions
6. [Animation System](06_animation_system.md)
   - ANM Format, Bytecode Opcodes, Godot Rendering Pipeline
7. [Audio System](07_audio_system.md)
   - OPL2 FM Synthesis, RAW PCM, Godot Audio Dispatcher
8. [Part Catalog](08_part_catalog.md)
   - Catalog Index, Categories, Property Files
9. [Project File Database](09_project_file_database.md)
   - Complete annotated index of every file in the project with Godot relevance ratings
10. [Steam Launch Roadmap](10_steam_launch_roadmap.md)
   - How to use the database, clean room legal strategy, phased build plan, Steam milestone gates
