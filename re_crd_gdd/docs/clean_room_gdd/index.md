# Game Design Document: Clean Room Remake (TIM2)

Este Game Design Document (GDD) foi elaborado com base no processo de engenharia reversa "Clean Room" do jogo *The Incredible Machine 2* (1994). Toda a documentação aqui contida deriva exclusivamente das especificações do motor físico e regras de negócio extraídas dos dados originais (`.LEV`, `.PAR`, `.ANM`, `SOLVE.RES`), sem o uso de código-fonte original.

## Sumário

1. [Visão Geral (Pitch & Vision)](01_pitch_and_vision.md)
   - High Concept, Pilares de Design e Plataformas.
2. [Mecânicas Principais (Core Mechanics)](02_core_mechanics.md)
   - Motor físico, ciclo de 60Hz (7 passes) e sistemas de cabos/correias.
3. [Catálogo de Peças](03_part_catalog.md)
   - Visão geral das categorias, regras de negócio e matriz de interação.
4. [UI/UX e Controles](04_ui_ux_and_controls.md)
   - Interface do jogador, layout e adaptações para mouse, gamepad e touch.
5. [Design de Fases (Level Design)](05_level_design.md)
   - Progressão, construtor de fases e sistema de condições de vitória.
6. [Direção de Arte e Áudio](06_art_and_audio.md)
   - Especificações da nova arte (Clean Room) e engenharia de som determinística.
7. [Recursos Modernos e Online](07_modern_features.md)
   - Integração com Steam, Multiplayer Head-to-Head e QoL (Undo/Redo).
8. [Catálogo Detalhado de Peças](08_detailed_parts_catalog.md)
   - Documentação exaustiva das 278 peças (ativas e cenário) com imagens e estados.
9. [Catálogo Detalhado de Fases](09_detailed_level_catalog.md)
   - Documentação completa de todas as 206 fases com setup de inventário e dicas.
10. [Catálogo de User Journeys (Fluxos de UX)](10_user_journeys.md)
    - Especificação visual e arquitetural de todas as 14 jornadas de interface e menus.
11. [Especificação do Editor Godot (Standalone)](11_godot_editor_specification.md)
    - Blueprint arquitetural da UI de edição, hierarquia de nós e máquinas de estado da ferramenta.
12. [Guia de Produção de Assets (Arte e Áudio)](12_asset_production_guide.md)
    - Regras restritas para pixel art moderna (32-bits), sonoplastia (44.1kHz) e conformidade física de animações.
13. [Especificações Técnicas e Formatos de Dados](13_technical_specifications.md)
    - Estrutura de leitura de arquivos legados e mapeamento binário para a nova engine.
