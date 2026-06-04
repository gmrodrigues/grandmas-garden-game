# 5. Design de Fases (Level Design)

A integridade do jogo como produto final está em apresentar os desafios lógicos de maneira equilibrada. A conversão limpa resgatou todos os **206 níveis originais**, que já contêm curva de dificuldade aprovada.

## Progressão e Estrutura de Dificuldade

A organização de fases foi extraída da taxonomia do `game.py`.

1. **Tutoriais:** Micro-cenários onde apenas uma categoria é explorada de cada vez (ex: gravidade com esferas, como ligar polias).
2. **Easy:** Cenários lineares com soluções de um único caminho claro.
3. **Medium:** Níveis em que o jogador tem *red herrings* (peças disponíveis no inventário que não são necessárias para completar a fase) para induzir falso raciocínio.
4. **Hard e Really Hard:** Fases com peças que operam fora da tela ou que dependem do limite de cordas complexas e física interdependente fina de múltiplos alvos.
5. **Head-to-Head (Multiplayer):** Níveis balanceados que suportam competição entre dois jogadores de forma assimétrica.

## O Formato de Fase (A Abstração YAML)

O projeto base descartou trabalhar o motor em cima dos dados binários crus (`.LEV`) como padrão e consolidou as fases num repositório YAML (`build/phase-5/yaml/`).

O Level Loader (`LevelLoader.gd` na arquitetura final) deve processar e carregar dados dessa forma:

- **Metadados:** Título da fase, Texto do Objetivo, Música a tocar, Dicas (*Hints*) ocultas.
- **Física da Fase:** `gravity` global e `pressure`.
- **`fixed_parts`:** Arrays contendo tipo da peça (`part_type`), posição (X/Y no plano pixel) e flags de orientação espacial. Elas são a base fixa onde a jogabilidade acontece. A simulação da colisão não pode empurrá-las.
- **`moving_parts`:** Array idêntico de peças que respondem à gravidade e física ou podem ser manipuladas livremente em modo *sandbox*.

## O Avaliador de Vitória (Solution Condition)

Ao contrário dos quebra-cabeças modernos limitados ao toque em uma "bandeira final", o mecanismo avaliador reversado mapeia vitória por *Estados Disparadores*.
O sistema opera através do `SolutionCondition` (referenciado em `docs/godot_game_spec/03_data_structures.md`).

Tipos de validação de vitória:
1. **Pelo Estado de Peça (`state_match`):** Condição clássica "Acenda a vela". A verificação valida se o objeto da ID Específica (Vela) passou do seu estado de ID 0 para seu estado ID 1.
2. **Overlap Posicional (`AABB overlap`):** Condição clássica "Faça a bola cair no cesto". Um retângulo virtual invisível (Retângulo Alvo) é instanciado na fase, atuando como um *trigger volume* moderno. O motor checa continuamente se o centro do `part_type` (ex: bola de basquete) se encontra na bounding box especificada.
3. **Condições Múltiplas:** Certos níveis Hard exigem que os estados acima sejam todos atingidos simultaneamente para acionar a janela de vitória.
