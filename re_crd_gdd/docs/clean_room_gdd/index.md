# Game Design Document: Clean Room Remake (TIM2)

Este Game Design Document (GDD) foi elaborado com base no processo de engenharia reversa "Clean Room" do jogo *The Incredible Machine 2* (1994). Toda a documentação aqui contida deriva exclusivamente das especificações do motor físico e regras de negócio extraídas dos dados originais (`.LEV`, `.PAR`, `.ANM`, `SOLVE.RES`), sem o uso de código-fonte original.

## Sumário

1. [Visão Geral (Pitch & Vision)](01_pitch_and_vision.md)
   - 1.1 High Concept
   - 1.2 Pilares de Design (3 pillars: Física Determinística, Nostalgia vs. Modernidade, Criatividade Sem Limites)
   - 1.3 Estratégia Legal (Clean Room)
   - 1.4 Público-Alvo e Plataformas

2. [Mecânicas Principais (Core Mechanics)](02_core_mechanics.md)
   - 2.1 O Core Loop (4 steps: Analyze → Build → Test → Evaluate)
   - 2.2 A Física Determinística (60Hz fixed-point, variáveis globais de nível)
   - 2.3 O Loop de Simulação (7 passes em ordem estrita)
   - 2.4 Sistemas de Restrição (Constraints: rope/pulley, belt/gear)

3. [Catálogo de Peças](03_part_catalog.md)
   - 3.1 As 15 Categorias de Peças
   - 3.2 Sistema de Máquina de Estados e Interação (SOLVE.RES)
   - 3.3 O Papel do Design Limpo (Clean Room)

4. [UI/UX e Controles](04_ui_ux_and_controls.md)
   - 4.1 HUD do Modo Puzzle (catalog panel, simulation bar, level info)
   - 4.2 Mapeamento de Controles Modernizados (Mouse & Keyboard)
   - 4.3 Gamepad (Consoles e Steam Deck)
   - 4.4 Touch/Mobile
   - 4.5 Fluxo de "Jornada do Usuário"

5. [Design de Fases (Level Design)](05_level_design.md)
   - 5.1 Progressão e Estrutura de Dificuldade (Tutorial, Easy, Medium, Hard, HH)
   - 5.2 O Formato de Fase (Abstração YAML)
   - 5.3 O Avaliador de Vitória (state_match, AABB_overlap, multi_condition)

6. [Direção de Arte e Áudio](06_art_and_audio.md)
   - 6.1 Art Bible e Arte Clean Room (ScummVM Port vs. Remake HD)
   - 6.2 Audio Design Determinístico (Reactive Dispatcher, FM/ PCM)

7. [Recursos Modernos e Online](07_modern_features.md)
   - 7.1 Sistema de Compartilhamento (Workshop)
   - 7.2 Quality of Life (Undo/Redo, Magnetic Grid, Hint System)
   - 7.3 Multiplayer e Co-op (Head-to-Head, Sandbox Co-op)

8. [Catálogo Detalhado de Peças](08_detailed_parts_catalog.md)
   - 8.1 Balls, Inclines, Containers
   - 8.2 Mechanical & Connectors, Energy & Electrical
   - 8.3 Weapons & Explosives, Animals & AI
   - 8.4 Spheres & Projectiles, Walls & Platforms
   - 8.5 Fire Sources, Air/Wind Sources
   - 8.6 Containers & Pipes, Optics & Lasers
   - 8.7 Anti-Gravity & Space, Balloons & Pressure
   - 8.8 Triggers, Base Structures

9. [Catálogo Detalhado de Fases](09_detailed_level_catalog.md)
   - 9.1 Tutorial Levels (TLEV)
   - 9.2 Easy Levels (ELEV)
   - 9.3 Medium Levels (MLEV)
   - 9.4 Hard Levels (RLEV)
   - 9.5 Head-to-Head Levels (HH)

10. [Catálogo de User Journeys (Fluxos de UX)](10_user_journeys.md)
    - 10.1 J01 — Sign-In Window
    - 10.2 J02 — Main Menu
    - 10.3 J03 — Puzzle Select
    - 10.4 J04 — Parts Bin — Browse & Place
    - 10.5 J05 — Part Handles — Flip/Stretch/Program/Delete
    - 10.6 J06 — Connections — Rope/Belt/Electrical
    - 10.7 J07 — Programmable Parts
    - 10.8 J08 — Simulation — Start/Observe/Pause/Reset
    - 10.9 J09 — Simulation — Solve Conditions
    - 10.10 J10 — Save & Load
    - 10.11 J11 — Player Preferences
    - 10.12 J12 — Music & Sound
    - 10.13 J13 — Hints & Info Dialogs
    - 10.14 J14 — Head-to-Head

11. [Especificação do Editor Godot (Standalone)](11_godot_editor_specification.md)
    - 11.1 Visão Geral do Layout
    - 11.2 Estrutura da Árvore de Nós (Scene Tree)
    - 11.3 Máquina de Estados da Ferramenta (Tool Modes)
    - 11.4 Fluxos e Jornadas Restritas de Edição
    - 11.5 QoL e Mapeamento de Casos de Uso
    - 11.6 Roadmap Ágil de Implementação

12. [Guia de Produção de Assets (Arte e Áudio)](12_asset_production_guide.md)
    - 12.1 A Regra de Ouro: A Arte Serve à Física
    - 12.2 Guia de Estilo (Pixel Art Moderna)
    - 12.3 Guia de Animação (Frame Sync)
    - 12.4 Guia de Engenharia de Áudio (SFX e Música)
    - 12.5 Diretrizes do Design de Níveis (UGC e YAML)

13. [Especificações Técnicas e Formatos de Dados](13_technical_specifications.md)
    - 13.1 Máquinas de Estado (State Machines)
    - 13.2 Formatos de Arquivo (.LEV, .ANM, .PAR)
    - 13.3 Detalhes Técnicos e Limitações (Determinismo, Z-Indexing, Clean Room)

14. [Comportamento das Peças: Edição, Simulação e Gizmos](14_part_editor_behaviors.md)
    - 14.1 Modos de Vida da Peça (Edit Mode vs. Simulation Mode)
    - 14.2 Comportamento de Posicionamento (Snap-to-Grid, Overlap Validation)
    - 14.3 Arquétipos de Gizmos (Stretch, Flip, Anchor, Program, Goal Regions)

15. [Especificação Comportamental (BDD)](15_behavioral_specification.md)
    - 15.1 Physics Simulation Loop (14 scenarios)
    - 15.2 Constraint Systems (7 scenarios)
    - 15.3 State Machine Execution (8 scenarios)
    - 15.4 Solution Conditions (4 scenarios)
    - 15.5 Editor Tool Modes (12 scenarios)
    - 15.6 Simulation Controls (4 scenarios)
    - 15.7 Level Persistence (5 scenarios)

16. [BDD Part Catalog](16_part_bdd_catalog.md)
