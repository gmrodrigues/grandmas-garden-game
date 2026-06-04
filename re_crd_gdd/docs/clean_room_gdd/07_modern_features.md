# 7. Recursos Modernos e Online

Embora a espinha dorsal de simulação permaneça idêntica ao design de 1994, o remake de The Incredible Machine 2 adota padrões contemporâneos para garantir a retenção de público no ecossistema atual de PC e Consoles.

## Sistema de Compartilhamento (Workshop)

O valor principal do jogo reside na expressão mecânica infinita e desafios da comunidade.

- **Fases Definidas pelo Usuário (UGC):** Graças à abstração de serialização (descrita no motor de fase `YAML` em `level.py`), uma fase de usuário gerada no "Editor de Nível Livre" exporta um arquivo `.yaml` limpo contendo as peças soltas, condições de vitória customizadas e física padrão.
- **Integração com Plataformas:** Conexão nativa com **Steam Workshop**. Jogadores podem dar *Upload* dos seus quebra-cabeças. O cliente de jogo embutido tem a seção *Community Browser* com filtros de "Melhor Avaliados", "Mais Desafiadores", "Engenhocas Cômicas".

## Quality of Life (Melhorias de Interface)

A recriação introduz melhorias essenciais para evitar fadiga cognitiva:
* **Undo / Redo (Desfazer / Refazer):** Pilha de histórico rastreando as manipulações de array no Node Tree, garantindo que o acidental esbarrão que apagou um conector complexo não seja um *game-over* manual.
* **Magnetic Grid Dinâmico:** Ao arrastar conectores de polias (ropes/belts), o motor cria assistência (snap-in) com destaque colorido em torno da extremidade correta (verde para conectar, vermelho para impossibilitado), sanando o problema opaco da década de 90.
* **Dicas Progressivas (Hint System):** Integrado às flags do YAML (`hints:` array). O jogador apertando no botão de lâmpada revela as dicas em camadas textuais sucessivas, auxiliando progressão sem usar *walkthroughs* de sites externos.

## Multiplayer e Co-op

O formato possui o histórico modo **Head-to-Head**.

- **Modo Competitivo Paralelo:** Dois jogadores recebem a mesma fase exata. No modelo clássico local, a tela é dividida e um timer dita quem resolve mais rápido usando recursos mais escassos. A modernização trará este conceito para o *Online Matchmaking*.
- **Sandbox Co-op (Brainstorm):** Uma adição puramente moderna, permitindo a dois jogadores manipularem o cenário online via conexão P2P no modo *Freeplay*, colaborando para montar superestruturas de rube goldberg numa lousa gigantesca em sincronia com o motor determinístico validando ambos simultaneamente.
