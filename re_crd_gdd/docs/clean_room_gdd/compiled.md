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


# 1. Visão Geral (Pitch & Vision)

## High Concept
Um jogo de puzzle e simulação física no estilo *Rube Goldberg*, onde o jogador constrói engenhocas complexas em cadeia para resolver objetivos simples (como "acender uma vela" ou "colocar a bola na cesta"). Modernizado com uma nova engine robusta (Godot 4) e ferramentas de compartilhamento online, o jogo resgata a essência de resolução criativa de problemas da era 16-bits.

## Pilares de Design

### 1. Física Determinística ("A Regra de Ouro")
O coração do jogo não é um motor de física realista (como Box2D ou Havok), mas sim um simulador **100% determinístico** rodando em taxa fixa de 60Hz. 
* **O que isso significa:** Se o jogador não alterar nenhuma peça e clicar no botão "Play" 100 vezes, o resultado (colisões, reações, momento exato de cada evento) deve ser **matematicamente idêntico** em todas as 100 vezes. 
* **Por que importa:** Sem isso, engenhocas complexas que dependem de precisão milimétrica deixam de funcionar de forma previsível, frustrando o jogador e quebrando o design dos puzzles.

### 2. Nostalgia vs. Modernidade
O jogo deve manter a estética mecânica e o charme cartunesco dos anos 90, porém envelopado em uma UI/UX moderna. Resoluções amplas (4K e Ultrawide), atalhos de teclado ágeis, controles adaptados para gamepads modernos e zoom in/out livre são melhorias fundamentais que atualizam a experiência sem corromper a essência do gameplay original.

### 3. Criatividade Sem Limites
O jogo não julga a solução. Se o objetivo era acender uma fogueira e o jogador usou um rato em uma esteira para acionar um motor, que puxa um balde de tesouras para cortar uma corda, soltando uma bola de boliche em um interruptor de laser que incinera dinamite... a solução é válida. O ambiente sandbox (Freeplay) incentiva a criação das engenhocas mais caóticas possíveis.

## Estratégia Legal (Clean Room)
Para garantir a comercialização legal (ex: via Steam), o desenvolvimento segue a arquitetura **"Clean Room"**. 
* Toda a lógica, física e regras derivam da especificação de formato binário revertida pela equipe, garantindo não haver uso de código-fonte de terceiros.
* Para os *assets* (arte e áudio), o projeto adota inicialmente o **Modelo ScummVM**, onde o jogador deve fornecer os arquivos originais legalmente adquiridos, ou operará com arte 100% nova, evitando qualquer violação de *copyright*.

## Público-Alvo e Plataformas
* **Público:** Fãs de jogos retrô, amantes de puzzle (ex: *Portal*, *Baba Is You*, *Zachtronics games*), crianças com interesse em engenharia/física e entusiastas de sandbox.
* **Plataformas Iniciais:** PC (Steam - Windows, Linux, macOS) e Steam Deck.
* **Plataformas Futuras:** Consoles e Mobile (adaptando o esquema de controles *Drag and Drop* para toque).


# 2. Mecânicas Principais (Core Mechanics)

O funcionamento do jogo divide-se entre dois modos: o **Modo de Edição** (Build Mode) e o **Modo de Simulação** (Play Mode). Durante a simulação, o jogo confia em uma engine física altamente customizada, operando sob regras estritas extraídas do formato original.

## O Core Loop

1. **Analisar Objetivo:** O jogador lê a condição de vitória e analisa o cenário pré-montado (peças fixas que não podem ser movidas).
2. **Construir Engenhoca:** Usando um inventário limitado, o jogador arrasta, posiciona, rotaciona e conecta peças no cenário (ex: ligando cordas de objetos a roldanas).
3. **Testar (Play):** O tempo começa a correr. A gravidade age sobre os itens móveis.
4. **Avaliar Resultado:** 
   - Se o objetivo for cumprido, a fase é vencida.
   - Se algo der errado, o jogador aperta "Stop", a fase reseta ao estado de edição, e ele reajusta as peças.

## A Física Determinística

O motor físico opera isolado dos *frames* visuais do jogador. Ele roda a exatos **60 ticks por segundo (60Hz)** usando matemática de ponto fixo (*fixed-point integer math*, convertida para pixels por `>> 9`). O uso de inteiros em vez de *floats* previne as discrepâncias de arredondamento causadas por diferentes CPUs.

### Variáveis Globais de Nível
Cada fase possui propriedades globais que alteram as leis da física:
- **Gravidade (`gravity_y`):** Pode ser normal, baixa (espaço) ou até invertida. O limite típico é de `±0x2600` ou `±0x3000`.
- **Pressão do Ar (`air_pressure`):** Afeta balões e a física de propagação de chamas/explosões.

### O Loop de Simulação (7 Passes)
O coração da mecânica. Em cada tick de 1/60s, a simulação DEVE executar exatamente os seguintes passes em ordem estrita:

1. **Contadores de Estado:** Atualiza os atrasos de estados das peças (ex: timers de detonação ou transição de animações).
2. **Integração de Gravidade:** Aplica a força gravitacional (tabela de aceleração) em objetos que não estão presos. Exemplo: a `velocity_y` é aumentada e somada à posição `pos_y`.
3. **Comportamentos Especiais (Behaviors):** Motores giram, canhões atiram, gatos correm atrás de ratos. Regras de movimentação exclusivas de cada peça.
4. **Clamping de Viewport:** Impede que peças saiam das bordas ativas da tela, aplicando salto (`bounciness`/COR) quando batem no chão ou no teto.
5. **Colisões (AABB):** Detecção de sobreposição (*overlap*). Objetos são reposicionados e suas velocidades recebem um impulso vetorial. Exceção: peças interconectadas ignoram colisões entre si.
6. **Proximidade & Elétrica:** Condução de eletricidade através de conectores ligados. Lasers, lanternas e interruptores ativam alvos próximos ou na linha de visão.
7. **Constraint Solver (Corda/Correia):** Passo de correção. Roldanas tensionam cordas e esteiras sincronizam suas velocidades angulares de forma idêntica.

## Sistemas de Restrição (Constraints)

A manipulação de transferência mecânica é uma mecânica principal.

* **Cordas e Polias (Ropes & Pulleys):** As cordas possuem comprimento definido (armazenado no campo `behavior` da peça). Um *solver* de passe único corrige a posição dos itens amarrados se eles esticarem a corda além do limite, criando o efeito de "pêndulo" ou balanço em polias.
* **Correias e Engrenagens (Belts & Gears):** Transmitem velocidade angular. O solver soma o torque das peças motrizes (como um motor ligado na tomada) e distribui a mesma velocidade angular padronizada de `±60px/s` para todas as peças escravas conectadas pelo mesmo cinto.


# 3. Catálogo de Peças (Part Catalog)

O coração criativo e lógico do jogo reside nas suas peças. O motor original abriga **149 peças jogáveis** e **116 peças de cenário** (decorativas). 

Devido à magnitude desse catálogo, este documento fornece um guia das categorias e da lógica do sistema. A especificação cirúrgica de cada peça (massa, elasticidade, atrito, estados da animação e raio de colisão extraídos do formato `.PAR`) está catalogada nos 148 documentos individuais localizados na pasta `docs/parts/` e na base de dados `build/phase-9/part-name-catalog.json`.

## As 15 Categorias de Peças

O jogo agrupa as peças em categorias que compartilham regras lógicas de simulação, colisões ou tabelas de gravidade:

1. **Força Motriz (Motores e Manivelas):** Peças que geram força angular. Ex: Moinhos de vento, motores elétricos, macaco na bicicleta, rato na roda.
2. **Mecânicos e Conectores:** Engrenagens, correias, alavancas e tesouras que transmitem movimento.
3. **Geradores de Energia / Elétricos:** Painéis solares, interruptores, tomadas e geradores.
4. **Armas e Explosivos:** Canhões, dinamites, mísseis, fogo de artifício. Respondem primariamente a chamas ou ativação mecânica.
5. **Animais e IA Simples:** Curiosidades físicas como Mel Arnold, o Gato (perseguidor), o Rato (fujão), o Jacaré (comedor).
   - ![Newton Mouse](../../build/phase-3/bitmaps/PART11_f000.png) ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png)
6. **Esferas e Projéteis:** Bolas de boliche, bolas de tênis, bolas de bilhar (variam em peso e elasticidade, "bounciness").
   - ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png)
7. **Paredes e Plataformas (Scenery):** Tipos estáticos que servem de chão ou teto. Peças como trampolins e esteiras entram aqui se ancoradas.
8. **Fontes de Fogo:** Fósforos, velas, tochas e lupas.
9. **Fontes de Ar/Vento:** Ventiladores, secadores de cabelo, aspiradores.
10. **Recipientes e Tubos:** Baldes, cestas e o sistema de encanamentos (que transporta peças via teleporte em grafo BFS).
11. **Óptica e Lasers:** Espelhos, prismas, tomadas de laser, misturadores RGB e balões.
12. **Anti-Gravidade e Espaço:** Almofadas flutuantes e amarras espaciais.
13. **Balões e Itens de Pressão:** Balões de gás, dirigíveis (respondem diferentemente dependendo da pressão do ar da fase).
14. **Gatilhos (Triggers):** Interruptores de chão, alavancas puxáveis.
15. **Estruturas Base:** Blocos construtores.

## Matriz de Interação (SOLVE.RES)

O jogo raramente programa eventos específicos "na unha". A interação ocorre através de uma tabela de decisão baseada em estado (`build/phase-16/solve-decoded.json`), que opera pelo esquema de "Pares de Gatilho":

`{Minha_Peça, Meu_Estado} + {Outra_Peça, Estado_Dela} => {Ação}`

Exemplos clássicos de interação:
* **Fogo vs Explosivo:** Se a Chama (Peça A) encostar na Dinamite (Peça B), Peça B avança para seu estado de ignição. A partir daí, o *timer* interno (*state_counter*) da Dinamite cuida do atraso até a explosão, que então gera uma força radial (*push/destroy*).
* **Laser vs Balão:** O laser projeta o raio. Se a linha de colisão do raio intercepta o balão de festa, aciona o gatilho de *burst* no balão, reproduzindo a animação de destruição.
* **Gato vs Rato:** A peça Gato executa uma rotina de varredura direcional em seu *pass* de *behavior*. Se "ver" a peça Rato no mesmo eixo, altera sua própria velocidade (`vel_x`) para perseguir o rato.

## O Papel do Design Limpo (Clean Room)

Ao implementar cada peça, desenvolvedores da Godot devem consultar **exclusivamente** os dados da pasta `docs/parts/`. 
Nós não portamos código de C para GDScript; nós olhamos os parâmetros de atrito e massa, as dimensões da Hitbox (AABB offset) e programamos a lógica no Node da peça. O número do estado (`state_id`) dita qual quadro de sprite desenhar e qual som emitir (baseado em `R-016-sound-param-table.md`).


# 4. UI/UX e Controles

A interface de usuário de um simulador puzzle-sandbox é o elemento que determina se o jogador se sentirá no controle de uma máquina complexa ou frustrado brigando com caixas.

A implementação da UI em Godot tem o luxo de ser livre de amarras de motor antigo, desde que mantenha a coerência mecânica descrita no `docs/user-journey-specification.md`.

## HUD do Modo Puzzle

A tela deve prover ao jogador visibilidade máxima da "Área do Puzzle" e rápido acesso às peças.

1. **Painel de Catálogo/Inventário:** Localizado nas laterais da tela (usualmente à direita ou inferior).
   - O catálogo de peças apresenta o inventário limitado disponível para aquela fase.
   - Ícones das peças em "caixas" renderizando seu primeiro frame (*idle*).
   - Indicação numérica das peças restantes.
2. **Barra de Controle de Simulação:**
   - **Play (Teste):** Congela o Modo Edição e inicia a simulação física.
   - **Stop/Reset:** Finaliza a simulação e devolve todas as peças para o exato estado em que estavam antes do clique em Play.
   - **Fast Forward:** Um botão *quality-of-life* moderno que acelera os 60Hz originais, útil para aguardar roldanas girarem até o topo de uma tela lenta.
3. **Display de Informações de Fase:**
   - Botão para rever o Objetivo e as Dicas (*Hints*).
   - Elementos de leitura da fase: Indicador global de Gravidade (Normal/Espaço) e Pressão do Ar.

## Mapeamento de Controles Modernizados

### 1. Mouse & Teclado (Core PC)
O fluxo clássico validado em `tim2_editor/main.py`.
- **Drag & Drop:** Clique esquerdo para segurar, arrastar e soltar (Snap na grade opcional, tipicamente de 16px).
- **Conectar (Cabos e Eletricidade):** Modos de clique dedicados para criar amarras ou ligar interruptores em tomadas elétricas. O *feedback* visual (cor da conexão) é fundamental aqui.
- **Atalhos (Hotkeys):** Rotação rápida de peça (Espaço), deletar peça (Del), Pan pela área do puzzle (Middles-click drag).

### 2. Gamepad (Consoles e Steam Deck)
Adaptar a jogabilidade original "point-and-click" exige sistemas modernos:
- **Cursor Magnético / Assistência:** O analógico esquerdo não apenas mimetiza o mouse, mas aplica uma atração gravitacional quando o cursor está perto de um conector de roldana ou um botão de UI.
- **Menus Radiais:** Em vez de mover o cursor cruzando toda a tela até o inventário lateral, apertar `Y` ou `Triângulo` abre um menu radial rápido agrupando peças da fase pelo cursor.
- **Direcionais (D-Pad):** Alterna as opções de conectores de uma engrenagem, por exemplo.

### 3. Touch/Mobile
- **Pinch-to-Zoom:** Essencial para fases imensas que passam o tamanho de uma tela.
- **Tap & Hold:** Exibe informações ("Tooltips") da peça, atributos de massa ou atrito.
- **Arrastar Flutuante:** Para evitar que o dedo tampe a peça ao ser arrastada, o ícone sob posse flutua ligeiramente acima do ponto de toque físico.

## Fluxo de "Jornada do Usuário"
Toda transição de tela deve respeitar os 14 diagramas contidos em `user-journey-specification.md`, da tela de Assinatura inicial (*J01*) à passagem pelo Seletor de Níveis com separação de dificuldade e tela final de Vitória, certificando-se de reproduzir as corretas instâncias do fluxo clássico.


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


# 6. Direção de Arte e Áudio

O projeto tem restrições técnicas vitais advindas de sua estratégia jurídica e histórica ("Clean Room"), forçando o departamento de arte e design de som a operarem em moldes diferentes do desenvolvimento tradicional.

## Art Bible e Arte Clean Room

Existem duas rotas implementáveis na direção de arte. O *Game Design* base deve comportar ambas:

1. **A Abordagem "Port de Engine" (Modelo ScummVM):** O jogo provê **zero arte visual original**. O jogador providencia o recurso legal `RESOURCE.001` do MS-DOS.
   - **Renderizador Opcodes (`ANMPlayer.gd`):** O backend reconstrói os mais de 3.000 *sprites* extraídos por processamento cru, sendo essencial possuir um código que suporte 6 opcodes base (A, B, C, D) ditados por `docs/experiments/R-002-anm-format.md`. Nenhuma textura é modificada, respeitando paletas de 256 cores originais (`PARTTEMP.json`).

2. **A Abordagem "Remake HD" (Propriedade Intelectual Nova):** Caso a rota escolhida seja evitar o requisito de arquivos originais, toda a arte precisa ser recriada.
   - **Restrição de Gameplay:** Apesar de poder re-imaginar um gato, os **hitboxes (raios de colisão) e offset (x/y center)** devem obrigatoriamente manter os tamanhos ditados na base do projeto (`build/phase-9/part-properties.json`) em ponto fixo (`AABB`). Se o raio de colisão da engrenagem nova no remake em HD for maior que a clássica em 1 pixel, **fases antigas vão quebrar**.
   - **Direção de Estilo:** Sugere-se uma arte limpa, vetorial ou 2.5D com shaders cartunescos, mantendo as animações expressivas e exageradas (*slapstick comedy*).

## Audio Design Determinístico

O sistema de áudio difere da física porque a simulação física não pode jamais depender de um frame de áudio terminando.

* **Dispatcher Reativo:** O áudio é tratado exclusivamente como "Side-Effect" (efeito colateral) da mudança de estado e atrito de colisão do backend de mecânicas. Baseando-se no `R-016-sound-param-table.md`, cada peça (seja 14 FM Patches OPL2 ou os 113 sons Waveform de PCM cru 8-bit/11kHz) tem um trigger associado e despacha um som sem bloquear o fio da física.
* **Exemplo de Pipeline Musical:** Se o cenário determina *Laser Firing*, o código avança o state e aciona uma flag global; o *AudioDispatcher* "ouve" a flag no próximo tick visual de renderização de Godot e aciona o áudio local correspondente.
* **Remasterização:** Trilhas de fundo deverão ser repensadas caso se afaste o modelo ScummVM (Option A), recriando temas de synth-jazz adequados para ambientes sem distrair a lógica complexa do player construindo seus cenários.


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


# 8. Catálogo Detalhado de Peças

Este documento lista detalhadamente todas as peças presentes no jogo, gerado automaticamente a partir da documentação original do projeto `docs/parts/`.

## Peça 0 — Bowling Ball

![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 40 fases  
**Quantidade de Estados:** 1 estado(s)  

> This bowling ball is very heavy and doesn't bounce much.

---

## Peça 1 — Brick Wall

![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 37 fases  
**Quantidade de Estados:** 2 estado(s)  

> This brick wall or floor can be stretched vertically or horizontally to any length you need. It's not as slippery as a caution wall. Explosives will blow it up.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 2 — Wood incline

![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png)

**Categoria:** Inclines  
**Fases em que aparece:** 36 fases  
**Quantidade de Estados:** 1 estado(s)  

> You can roll things up or down this wood incline, or use it to direct balloons. It can be stretched or shrunk, which changes the angle. Explosives won't hurt it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 3 — Tipsy Trailer

![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 38 fases  
**Quantidade de Estados:** 1 estado(s)  

> This little trailer acts as a teeter-totter. Drop something heavy on the high end to catapult an object off the low end. Tie a rope to either end and use it to hoist and lower objects, pull the trigger of the phazer, or cause other reactions.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 4 — Balloon

![Balloon](../../build/phase-3/bitmaps/PART4_f000.png)

**Categoria:** Balloons / Airships  
**Fases em que aparece:** 68 fases  
**Quantidade de Estados:** 8 estado(s)  

> This balloon can be programmed to have four different appearances, which all act exactly the same. It will float up into the air unless it's tied down with a rope or held back by another object. Use it to lift the low end of the teeter-totter, shoot the phazer, trigger the boxing glove, push the bellows, or bump various objects. Balloons will pop if they touch moving gears, hedge trimmers, tin snips, any flame, laser beams or tacks.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Popped | `3→7`, `2→6`, `4→8`, `5→9` | — | No |
| Popped | `7→2`, `6→4`, `8→5`, `9→-1` | — | No |

---

## Peça 5 — Conveyor Belt

![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png)

**Categoria:** Rotating Power Sources  
**Fases em que aparece:** 61 fases  
**Quantidade de Estados:** 10 estado(s)  

> Hitch this conveyor belt to a motor by adding a belt. Then use it to move objects. Add a gear to make it change directions.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 6 — Mouse Motor

![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png)

**Categoria:** Rotating Power Sources  
**Fases em que aparece:** 44 fases  
**Quantidade de Estados:** 2 estado(s)  

> This little cage is actually a Mouse Motor.  Bump the cage to make the mouse run around on his wheel. Add a belt and hitch it up to things like the conveyor belt or the Jack-in-the- box to make them work.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Running | `3→6` | — | No |
| Running | `6→-1` | 6 | No |

---

## Peça 7 — Pulley

![Pulley](../../build/phase-3/bitmaps/PART7_f000.png)

**Categoria:** Ropes / Belts / Pulleys  
**Fases em que aparece:** 91 fases  
**Quantidade de Estados:** 2 estado(s)  

> You can place this pulley between any two parts that may be connected by rope or cable. For example: tie one end of a rope to an object (a laundry basket for instance), then run the rope over as many pulleys as necessary (click on each pulley), and tie the other end of the rope to another part, such as the phazer. When you run the puzzle, the laundry basket will fall, pulling the rope, which will pull the trigger and fire the phazer.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 8 — Belt

![Belt](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Ropes / Belts / Pulleys  
**Fases em que aparece:** 83 fases  
**Quantidade de Estados:** 1 estado(s)  

> Use this belt to hitch any two rotating parts together. Click on the first part you wish to connect (the Mandrill Motor, for instance), then stretch the belt over to the second part (such as the pinwheel). When the line turns from red to green the belt is in position. Click again to attach it. Belts can only be stretched a limited distance.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 9 — Basketball

![Basketball](../../build/phase-3/bitmaps/PART9_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 21 fases  
**Quantidade de Estados:** 2 estado(s)  

> This basketball is medium in weight and very bouncy.

---

## Peça 10 — Rope

![Rope](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Ropes / Belts / Pulleys  
**Fases em que aparece:** 117 fases  
**Quantidade de Estados:** 1 estado(s)  

> Use this rope to tie objects together, hang things in the air, or hoist things off the ground with the help of a pulley. It attaches to teeter-totters, boat cleats, laundry baskets, buckets, phazers, balloons, the Mandrill Motor, and several other parts. To use rope: pull it out of the Parts Bin onto the screen. Click on the first object you want tied, then drag the cursor over the second object. When the line turns from red to green the rope is in position. Click again to attach it. You can cut the rope with hedge trimmers or tin snips.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 11 — Laundry Basket

![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png)

**Categoria:** Containers  
**Fases em que aparece:** 12 fases  
**Quantidade de Estados:** 2 estado(s)  

> Use this laundry basket to trap Curie Cat, Newton Mouse, or Mel Schlemming. Tie one end of a rope to the laundry basket, and tie the other end to another part (like a bucket or teeter-totter).

---

## Peça 12 — Curie Cat

![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 21 fases  
**Quantidade de Estados:** 12 estado(s)  

> Curie Cat will head toward Newton Mouse or Bill the Goldfish whenever he can see them. He'll turn around if he's bumped or runs into something. He also likes the goo that comes out of the can when it falls from the can opener.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Hasn't Eaten | `1→9` | 1 | No |
| Has Eaten | `9→-1` | 9 | No |

---

## Peça 13 — Jack-in-the-box

![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png)

**Categoria:** Springs / Pneumatics  
**Fases em que aparece:** 25 fases  
**Quantidade de Estados:** 4 estado(s)  

> You can hitch this Jack-in-the-box to any rotating part by adding a belt. When the wheel turns, it will pop open. And when Jack pops out, anything on top of his box will be shot into the air.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Closed | `3→4` | — | No |
| Popped Out | `5→-1` | 4 | No |

---

## Peça 14 — Gear

![Gear](../../build/phase-3/bitmaps/PART14_f000.png)

**Categoria:** Rotating Power Sources  
**Fases em que aparece:** 32 fases  
**Quantidade de Estados:** 2 estado(s)  

> You can make this belt turn by adding a belt and hitching it to other rotating parts (like Mandrill Motors and generators). Place gears side by side or above/below each other to reach the distance necessary or to change the direction of rotation.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 15 — Fish Tank

![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png)

**Categoria:** Containers  
**Fases em que aparece:** 11 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is Bill the Goldfish. Curie Cat will come after him if she's close enough and they're on the same level of flooring. If his tank breaks, she'll be attracted from a greater distance. Drop just about anything on the tank to break it.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Broken | `15→9` | 15 | No |
| Broken | `9→-1` | 14 | No |

---

## Peça 16 — Bike Pump

![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png)

**Categoria:** Springs / Pneumatics  
**Fases em que aparece:** 27 fases  
**Quantidade de Estados:** 3 estado(s)  

> Drop something on the top handle of this bike pump to make it blow air. It can be used to push away balloons and other objects, or to make pinwheels turn.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Pumped | `2→4` | 2 | No |
| Pumped | `4→-1` | 5 | No |

---

## Peça 17 — Bucket

![Bucket](../../build/phase-3/bitmaps/PART17_f000.png)

**Categoria:** Containers  
**Fases em que aparece:** 48 fases  
**Quantidade de Estados:** 2 estado(s)  

> You can drop things inside this bucket. Tie a rope to it, and tie the other end to a second object. Then drop something heavy into the bucket to lift the other object. You can also lift teeter-totters, pull triggers, and affect other parts that may be attached to a rope.

---

## Peça 18 — Cannon

![Cannon](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 21 fases  
**Quantidade de Estados:** 37 estado(s)  

> Light the fuse of this cannon with a laser, a flaming part (like a candle or rocket), or by using a magnifying glass and light source. It fires cannon balls which can be used to break and bump things. It can be rotated to aim in six different angles.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Fired | `1→23`, `4→25`, `7→27`, `34→35`, `41→42`, `47→48` | 47 | No |
| Fired | `19→4`, `20→7`, `31→34`, `38→41`, `45→47`, `50→-1` | 48 | No |

---

## Peça 19 — Dynamite

![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 28 fases  
**Quantidade de Estados:** 3 estado(s)  

> Light the fuse of this dynamite with a laser, a flaming part (like a candle or rocket), or by using a magnifying glass and light source. It will blow up all kinds of things, including some walls.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Blown up | `2→3` | — | No |
| Blown up | `3→-1` | 3 | Yes :material-bomb: |

---

## Peça 20 — Phazer pulse

![Phazer pulse](../../build/phase-3/bitmaps/PART20_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> [CREATED PART]


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 21 — Electric Switch & Outlet

![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 54 fases  
**Quantidade de Estados:** 8 estado(s)  

> Plug any of the electrical parts (like the toaster, can opener, or fan) into this electric outlet, then drop something on the switch to turn on the power. Or bump up on the switch if it's upside-down.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 22 — Remote Control

![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 57 fases  
**Quantidade de Estados:** 2 estado(s)  

> As soon as you set this remote control down on the screen, a second part made up of explosives appears.  Drag the explosives to the area or object you want to blow up. Drop something on top of the remote control button to set off the explosion. You can also tie one end of a rope to the button and hitch the other end to a teeter-totter, or another object that will allow you to pull the button down.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 23 — Boat Cleat

![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 75 fases  
**Quantidade de Estados:** 2 estado(s)  

> Any object that can be tied with a rope may be hitched to this boat cleat. Use it to hang things from the air, or to keep balloons from floating away.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 24 — Electric Fan

![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 23 fases  
**Quantidade de Estados:** 2 estado(s)  

> Plug this electric fan into an outlet to make it blow air. Flip it to change wind direction. Use it to blow objects away or to turn the pinwheel.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `1→2` | — | No |
| On | `2→-1` | 2 | No |

---

## Peça 25 — Flashlight

![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png)

**Categoria:** Light / Flame Sources  
**Fases em que aparece:** 55 fases  
**Quantidade de Estados:** 3 estado(s)  

> Drop something on the button of this flashlight to turn it on. Use it to power solar panels. Or put a magnifying glass right in front of it and use it to light fuses and candles.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `3→4` | 3 | No |
| On | `4→-1` | 2 | No |

---

## Peça 26 — Generator

![Generator](../../build/phase-3/bitmaps/PART26_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 15 fases  
**Quantidade de Estados:** 8 estado(s)  

> This generator comes with its own outlet. Use it to supply electricity to power parts by connecting the generator's wheel to a rotational motor (like the Mandrill Motor, the Mouse Motor, or the Electric Motor) by adding a belt.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `9→10` | — | No |
| On | `2→3` | — | No |

---

## Peça 27 — Captain Z Super Phazer

![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 22 fases  
**Quantidade de Estados:** 4 estado(s)  

> This spiffy toy phazer shoots pulses of energy. Tie one end of a rope to the trigger and run it through a pulley (placed behind the phazer), then tie the other end to a balloon or something heavy. You can program the number of energy pulses you want to fire, but the gun will only shoot as long as the rope is pulling on the trigger. Use phazer pulses to bump things, pop balloons and blimps, light candles and fuses, and blow up explosives.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Fired | `1→6` | — | No |
| Fired | `6→-1` | 6 | No |

---

## Peça 28 — Baseball

![Baseball](../../build/phase-3/bitmaps/PART28_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 47 fases  
**Quantidade de Estados:** 1 estado(s)  

> This baseball is pretty light and not very bouncy.

---

## Peça 29 — Lava Lamp

![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png)

**Categoria:** Light / Flame Sources  
**Fases em que aparece:** 19 fases  
**Quantidade de Estados:** 3 estado(s)  

> This groovy lava lamp isn't just a cool piece of retro-decor taken from Professor Tim's attic. It's also an excellent light source. Tie a rope to the chain and give it a tug to turn on the lamp. Use it to power up the solar panel, or shine it through a magnifying glass to light fuses and candles.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `1→2` | 1 | No |
| On | `2→-1` | 3 | No |

---

## Peça 30 — Magnifying Glass

![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 52 fases  
**Quantidade de Estados:** 1 estado(s)  

> Place this magnifying glass in front of any light source to ignite fuses or candles. Make sure it's close enough to both the light source and the fuse you're trying to light. Flip it if necessary.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 31 — Mandrill Motor

![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png)

**Categoria:** Rotating Power Sources  
**Fases em que aparece:** 9 fases  
**Quantidade de Estados:** 7 estado(s)  

> To start up this Mandrill Motor, tie a rope to the shade and give it a tug. When Pavlov Mandrill sees the banana he pedals like crazy. Attach a belt to the treadmill to power anything that is driven with a belt.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Sitting | `1→4` | 1 | No |
| Treading | `4→7` | 5 | No |
| Bonked | `7→-1` | 9 | No |

---

## Peça 32 — Boris the Bat

![Boris the Bat](../../build/phase-3/bitmaps/PART32_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 2 estado(s)  

> Happy Halloween! Meet Boris the Bat. He hangs in mid-air until he's bumped. Then he flies around acting batty.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 33 — Cupid

![Cupid](../../build/phase-3/bitmaps/PART33_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 2 estado(s)  

> Well, well, if it isn't Cupid, dropping in for Valentine's Day! Bump him to make him fly around. Any balloons that touch his arrow will pop.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 34 — Santa Claus

![Santa Claus](../../build/phase-3/bitmaps/PART34_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 2 estado(s)  

> Ho, ho, ho! Happy Holidays! This cheesy plastic Santa Claus lamp will only light up when you place it next to an electric socket.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `1→2` | 1 | No |
| On | `2→-1` | 2 | No |
| !Part | *(none)* | — | No |
| Boxing Glove | *(none)* | — | No |
| Cocked | `2→3` | — | No |
| Punched | `3→-1` | — | No |

---

## Peça 35 — Boxing Glove

![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png)

**Categoria:** Springs / Pneumatics  
**Fases em que aparece:** 44 fases  
**Quantidade de Estados:** 3 estado(s)  

> Bump the button on the back of this boxing glove to make it punch things.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 36 — Rocket

![Rocket](../../build/phase-3/bitmaps/PART36_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 24 fases  
**Quantidade de Estados:** 15 estado(s)  

> You can light the fuse of this rocket with a candle (or other flaming part), a laser beam, a phazer, or by using a magnifying glass and light source. It can be flipped to fly straight up, left, or right.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Fired | `2→17`, `12→18`, `25→21` | 25 | No |
| Fired | `8→12`, `15→25`, `24→-1` | 21 | No |

---

## Peça 37 — Hedge Trimmers

![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png)

**Categoria:** Cutting / Popping  
**Fases em que aparece:** 51 fases  
**Quantidade de Estados:** 6 estado(s)  

> You can cut ropes with these hedge trimmers by bumping the handles with another object. Balloons and blimps pop against the tips.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Open | `7→11` | 7 | No |
| Closed | `3→-1` | 4 | No |

---

## Peça 38 — Solar Panel

![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 16 fases  
**Quantidade de Estados:** 2 estado(s)  

> This solar panel comes with its own electrical outlet. Shine a light on the panel, then plug in any electric part you want to operate.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 39 — Springboard

![Springboard](../../build/phase-3/bitmaps/PART39_f000.png)

**Categoria:** Springs / Pneumatics  
**Fases em que aparece:** 54 fases  
**Quantidade de Estados:** 3 estado(s)  

> Anything you drop on this springboard will go higher with each bounce.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 40 — Pinwheel

![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png)

**Categoria:** Rotating Power Sources  
**Fases em que aparece:** 16 fases  
**Quantidade de Estados:** 2 estado(s)  

> You can make this pinwheel spin by blowing air on it (from parts like the fan or the bike pump). Attach a belt and use it to turn other rotating parts.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Spinning | `1→2` | 1 | No |
| Spinning | `2→-1` | 2 | No |

---

## Peça 41 — explosion

![explosion](../../build/phase-3/bitmaps/PART41_f000.png)

**Categoria:** Created / Phantom  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> [CREATED PART]


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 42 — Newton Mouse

![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 37 fases  
**Quantidade de Estados:** 9 estado(s)  

> This is Newton Mouse. He'll go after any cheese he can see. He'll also run away if Curie Cat comes after him. He'll run inside a mouse hole if you place a hunk of cheese on the other side of it, or if Curie chases him toward one. Newton also has to watch out for alligators.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Hasn't Eaten | `1→10` | 1 | No |
| Has Eaten | `10→-1` | 10 | No |

---

## Peça 43 — Pinball

![Pinball](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Balls  
**Fases em que aparece:** 78 fases  
**Quantidade de Estados:** 2 estado(s)  

> This pinball is very hard and heavy, and doesn't bounce much.

---

## Peça 44 — Tennis Ball

![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 44 fases  
**Quantidade de Estados:** 1 estado(s)  

> This tennis ball is very light and bouncy.

---

## Peça 45 — Aladdin's Lamp

![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Light / Flame Sources  
**Fases em que aparece:** 8 fases  
**Quantidade de Estados:** 3 estado(s)  

> Light this oil lamp with a laser, a flaming part (like flint rocks or a match-on-a-spring), or a light source and a magnifying glass. Once it's burning, you can use it to light candles and fuses, heat up coffee pots, or to pop blimps and balloons.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Out | `1→2` | 1 | No |
| Lit | `2→-1` | 2 | No |

---

## Peça 46 — Pipe Wall

![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 27 fases  
**Quantidade de Estados:** 2 estado(s)  

> This is a pipe wall or floor. Stretch it vertically or horizontally to any length you need. It has a slippery surface. Explosions won't affect it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 47 — Curved Pipe Wall

![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 1 estado(s)  

> This curved pipe section can be connected to a pipe wall or floor. Flip it to curve in the direction needed.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 48 — Wood Wall

![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 39 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is a wooden wall or floor. Stretch it vertically or horizontally to any length you need. Its surface isn't very slippery. Explosions will blast holes through it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 50 — Electric Motor

![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png)

**Categoria:** Rotating Power Sources  
**Fases em que aparece:** 32 fases  
**Quantidade de Estados:** 3 estado(s)  

> Plug this electric motor into an outlet and flick on the switch. Then use a belt to attach it to gears, conveyor belts, and other rotating parts. This motor can also be flipped.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `1→4` | — | No |
| Running | `4→-1` | 3 | No |

---

## Peça 51 — Vacuum

![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 2 estado(s)  

> Plug this vacuum into an electrical outlet and use it to suck up any object that's affected by gravity.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `9→10` | — | No |
| Vacuuming | `10→-1` | 10 | No |

---

## Peça 52 — Cheese

![Cheese](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 29 fases  
**Quantidade de Estados:** 1 estado(s)  

> Newton Mouse will come after this cheese whenever he's close enough and on the same level of flooring.

---

## Peça 53 — Thumb Tack

![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png)

**Categoria:** Cutting / Popping  
**Fases em que aparece:** 34 fases  
**Quantidade de Estados:** 8 estado(s)  

> This thumb tack is handy for popping blimps and balloons. It can be flipped so that the point is facing up, down, or either side.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 54 — Mel Schlemming

![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 32 fases  
**Quantidade de Estados:** 14 estado(s)  

> Meet Mel Schlemming. Mel walks mindlessly forward until he bumps into something. Then he turns around and walks mindlessly in the other direction. You can program him to walk, run, or stand still until he's bumped. If he falls too far, he drops to the floor and takes a snooze. He also has to watch out for alligators.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Normal | `1→8` | 1 | No |
| Sleeping | `51→-1` | 11 | No |

---

## Peça 55 — Remote Control Explosives

![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 57 fases  
**Quantidade de Estados:** 2 estado(s)  

> These explosives come with the remote control part. They'll blow up all kinds of things, including most walls. Drop something on top of the remote control button to set them off. You can also tie one end of a rope to the button and hitch the other end to a teeter-totter, or another object that will allow you to pull the button down.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Exploded | `2→5` | — | No |
| Exploded | `5→-1` | — | Yes :material-bomb: |

---

## Peça 56 — Caution Wall

![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 48 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is a caution wall or floor. Stretch it vertically or horizontally to any length you need. It's very slippery, and isn't affected by explosives.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 57 — Large Curved Pipe

![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png)

**Categoria:** Pipe Systems  
**Fases em que aparece:** 43 fases  
**Quantidade de Estados:** 1 estado(s)  

> Drop balls and other objects into this large curved pipe to make them come out the other end. It can be attached to straight sections of large pipe and t-connectors. You can also attach an accelerator tube to speed up or reverse the direction of objects moving through the pipes.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 58 — Mel's House

![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 18 fases  
**Quantidade de Estados:** 8 estado(s)  

> Here's Mel Schlemming's cozy suburban duplex. If he sees it, he'll head home. It can also be programmed to be a rustic log cabin.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Vacant | `5→6`, `4→15` | 4 | No |
| Occupied | `6→4`, `15→-1` | 15 | No |

---

## Peça 59 — Super Ball

![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 3 estado(s)  

> This super ball gains height with each bounce.

---

## Peça 60 — Grass Floor

![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 10 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is a grass floor or vine wall. Stretch it vertically or horizontally to any length you need. It's not very slippery. Explosions will blast holes through it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 61 — Alligator

![Alligator](../../build/phase-3/bitmaps/PART61_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 14 fases  
**Quantidade de Estados:** 11 estado(s)  

> Meet Edison Alligator. He'll chow down Mel Schlemming or Newton Mouse if they get too close. He also flips things into the air with his snout.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Hasn't Eaten | `1→5` | 1 | No |
| Has Eaten | `5→-1` | 5 | No |

---

## Peça 62 — Coffee Pot

![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 17 fases  
**Quantidade de Estados:** 3 estado(s)  

> Make this coffee pot percolate by heating it with a candle, Aladdin's lamp, match-on-a-spring, or flint & tinder. Then use the steam to push things.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `1→3` | 1 | No |
| Percolating | `3→-1` | 4 | No |

---

## Peça 63 — Pool Ball

![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 21 fases  
**Quantidade de Estados:** 16 estado(s)  

> This pool ball won't move until it's hit. The harder it's hit, the farther it will roll. It isn't affected by gravity. You can program it to show any number on its surface.

---

## Peça 64 — Pinball Bumper

![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 20 fases  
**Quantidade de Estados:** 2 estado(s)  

> This pinball bumper can be placed so that moving objects will bounce off in any direction.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 65 — Leprechaun

![Leprechaun](../../build/phase-3/bitmaps/PART65_f000.png)

**Categoria:** Characters  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 3 estado(s)  

> Happy Saint Patrick's Day! Say hi to Blarney O'Reilly, the leprechaun who lives in Professor Tim's garden. Give him a nudge and he'll dance a jig for you.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Resting | `1→2` | — | No |
| Dancing | `2→-1` | — | No |

---

## Peça 66 — Mouse Hole

![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 3 estado(s)  

> Newton Mouse likes to hide in this mouse hole when he's chased by Curie Cat. Or you can lure him inside by placing some cheese on the far side of the hole.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Vacant | `1→3` | 1 | No |
| Occupied | `3→-1` | 2 | No |

---

## Peça 67 — Can Opener

![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 11 fases  
**Quantidade de Estados:** 3 estado(s)  

> Plug this can opener into an electrical outlet to make it open the can. When the sauce spills out of the can, Curie Cat will come lap it up if she's within range.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unopened | `1→3` | 1 | No |
| Opened | `2→-1` | 2 | No |

---

## Peça 68 — Soccer Ball

![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 20 fases  
**Quantidade de Estados:** 1 estado(s)  

> This soccer ball is medium in weight and quite bouncy.

---

## Peça 69 — Anti-Gravity Pad

![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 76 fases  
**Quantidade de Estados:** 2 estado(s)  

> This anti-gravity pad reverses the gravity field for anything on top of it. Without gravity, most things will float up into the air. But balloons will drop.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unactivated | `1→2` | 1 | No |
| Operating | `2→-1` | 2 | No |

---

## Peça 70 — Missile

![Missile](../../build/phase-3/bitmaps/PART70_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 23 fases  
**Quantidade de Estados:** 15 estado(s)  

> This missile is handy for blowing up all sorts of things, including most walls. Light the fuse with a laser, a phazer, a candle (or other flaming part), or by using a magnifying glass and light source. You can flip it to fly straight up, right, or left.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Launched | `2→8`, `13→14`, `18→19` | 18 | No |
| Launched | `3→12`, `16→17`, `21→22` | 19 | No |
| Exploded | `12→13`, `17→18`, `22→-1` | — | Yes :material-bomb: |

---

## Peça 71 — Boxes

![Boxes](../../build/phase-3/bitmaps/PART71_f000.png)

**Categoria:** Containers  
**Fases em que aparece:** 43 fases  
**Quantidade de Estados:** 9 estado(s)  

> This box is really five boxes in one. Program it to be glass, wooden, wicker, metal, or cardboard, which are all different sizes. Drop things inside the box, or use it to catch falling objects.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 72 — Peg

![Peg](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> [CREATED PART]


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 73 — Trap Door

![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 33 fases  
**Quantidade de Estados:** 3 estado(s)  

> This trap door drops open when heavy objects land on top of it.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Up | `2→3` | 2 | No |
| Down | `3→-1` | 4 | No |

---

## Peça 74 — Nitroglycerine

![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 38 fases  
**Quantidade de Estados:** 2 estado(s)  

> This tube of nitroglycerine will explode if it's bumped or dropped with enough force. It blows up all kinds of things, including most walls.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unexploded | `1→3` | 1 | No |
| Exploded | `3→-1` | — | Yes :material-bomb: |

---

## Peça 75 — Match-on-a-Spring

![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png)

**Categoria:** Springs / Pneumatics  
**Fases em que aparece:** 52 fases  
**Quantidade de Estados:** 4 estado(s)  

> Pull the little peg with a rope to make this match pop up lit. Use it to light fuses, pop blimps and balloons, and heat up coffee pots.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unlit | `1→4` | 1 | No |
| Lit | `3→-1` | 2 | No |

---

## Peça 76 — Steel Cable

![Steel Cable](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Ropes / Belts / Pulleys  
**Fases em que aparece:** 14 fases  
**Quantidade de Estados:** 1 estado(s)  

> This steel cable works just like rope, except it's much stronger. It can only be cut with tin snips. To use the steel cable:  pull it out of the Parts Bin onto the screen. Click on the first object you want tied, then drag the cursor over the second object. When the line turns from red to green the cable is in position. Click again to attach it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 77 — Tin Snips

![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png)

**Categoria:** Cutting / Popping  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 4 estado(s)  

> You can use these tin snips to cut through rope or steel cable, or to pop blimps and balloons. To make them cut, just bump the handles with another object. They can also be used to pop blimps and balloons.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Open | `4→5` | — | No |
| Closed | `3→-1` | — | No |

---

## Peça 78 — Flint & Tinder

![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png)

**Categoria:** Light / Flame Sources  
**Fases em que aparece:** 44 fases  
**Quantidade de Estados:** 4 estado(s)  

> Bump these flint rocks to start a fire, which can be used to light fuses, pop blimps and balloons, and heat up coffee pots.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unlit | `1→2` | 1 | No |
| Lit | `2→-1` | 7 | No |

---

## Peça 79 — Hot Air Balloon

![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png)

**Categoria:** Balloons / Airships  
**Fases em que aparece:** 30 fases  
**Quantidade de Estados:** 5 estado(s)  

> Light the candle to create hot air, which will makes this balloon rise into the air. Tie a rope to the eye hook on the bottom and use it to lift things, pull triggers, and so on.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Lit | `1→5` | 1 | No |
| Lit | `5→4` | 5 | No |
| Popped | `4→-1` | 2 | No |

---

## Peça 80 — Fireworks

![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png)

**Categoria:** Explosives / Projectiles  
**Fases em que aparece:** 17 fases  
**Quantidade de Estados:** 15 estado(s)  

> This part lets you choose between three different types of fireworks displays. Program the part to get the celebration of your choice. Light the fuse with a flaming part like a candle, rocket, or an Aladdin's lamp.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Set Off | `9→19`, `12→20`, `16→21` | — | No |
| Set Off | `6→12`, `7→16`, `8→-1` | 21 | No |

---

## Peça 81 — Toaster

![Toaster](../../build/phase-3/bitmaps/PART81_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 12 fases  
**Quantidade de Estados:** 9 estado(s)  

> Plug this toaster into an electrical outlet and push down on the switch to make it work. When the toast is done, it pops into the air. Use it to bump other objects. You can also program it to work as a timer. The darker the toast you choose, the longer the amount of time it takes to pop up.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Toasting | `1→8`, `6→9`, `7→10` | — | No |
| Toasting | `2→6`, `3→7`, `4→-1` | — | No |

---

## Peça 82 — Sand Wall

![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 14 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is a sand wall or floor. Stretch it vertically or horizontally to any length you need. Its surface isn't very slippery. Explosions won't affect it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 83 — Cinder Block Wall

![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 32 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is a cinder block wall or floor. Stretch it vertically or horizontally to any length you need. Its surface isn't very slippery. Explosions will blow holes through it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 84 — Greco-Roman Wall

![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 42 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is a Greco-Roman wall or floor. Stretch it vertically or horizontally to any length you need. It has a pretty slippery surface. Explosions won't affect it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 85 — Log Wall

![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 18 fases  
**Quantidade de Estados:** 3 estado(s)  

> This is a log wall or floor. Stretch it vertically or horizontally to any length you need. Its surface isn't very slippery. Explosions will blow holes through it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 86 — Tiny Gear

![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png)

**Categoria:** Rotating Power Sources  
**Fases em que aparece:** 16 fases  
**Quantidade de Estados:** 2 estado(s)  

> This tiny gear rotates at twice the speed of a big gear when it's placed next to one. These gears must be placed directly beside or above/below other gears.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 87 — Programmable Ball

![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png)

**Categoria:** Balls  
**Fases em que aparece:** 11 fases  
**Quantidade de Estados:** 7 estado(s)  

> This ball can be programmed to vary in appearance, mass, elasticity, density, and friction.

---

## Peça 88 — Accelerator Tube

![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png)

**Categoria:** Pipe Systems  
**Fases em que aparece:** 38 fases  
**Quantidade de Estados:** 4 estado(s)  

> This accelerator tube can be connected to any type of large pipe. It will speed up or change the direction of any object passing through it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 89 — Trans-Roto-Matic

![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 14 fases  
**Quantidade de Estados:** 2 estado(s)  

> This handy gadget turns translational motion (back and forth) into rotational energy (around in circles). Tie a rope to the eye hook, then tug it with another object to make the gear turn. Hitch a belt to the gear and use it to rotate pinwheels, conveyors, and other rotating parts.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 90 — Roto-Trans Converter

![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 15 fases  
**Quantidade de Estados:** 2 estado(s)  

> This nifty contraption turns rotational energy (circular) into translational motion (back and forth movement). Hitch the little wheel to a rotational motor with a belt, then tie a rope to the eye hook and hitch it to something you want to lift or pull (like a teeter-totter, phazer trigger, or laundry basket).


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 91 — Red Laser

![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 30 fases  
**Quantidade de Estados:** 8 estado(s)  

> When this red laser gun is plugged into an outlet (and the switch is on) it will fire a red beam. When the beam strikes a red Laser-Activated Plug, it will generate energy that can be used to power anything hooked up to that outlet. Laser beams can be bounced and directed by using angled mirrors. They may also be fired into Laser Mixers, which will blend the colors of the beams. If an object passes through a laser beam, it will temporarily cut off the energy flow. Use laser beams to light fuses and candles, or to pop balloons.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Operating | `1→6`, `6→7`, `7→8`, `8→9` | 8 | No |
| Operating | `9→4`, `4→3`, `3→2`, `2→-1` | 2 | No |

---

## Peça 92 — Green Laser

![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 23 fases  
**Quantidade de Estados:** 8 estado(s)  

> When this green laser gun is plugged into an outlet (and the switch is on) it will fire a green laser beam. When the beam strikes a green Laser-Activated Plug, it will generate energy that can be used to power anything hooked up to that outlet. Laser beams can be bounced and directed by using angled mirrors. They may also be fired into Laser Mixers, which will blend the colors of the beams. If an object passes through a laser beam, it will temporarily cut off the energy flow. Use laser beams to light fuses and candles, or to pop balloons.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Operating | `1→6`, `6→7`, `7→8`, `8→9` | 8 | No |
| Operating | `9→4`, `4→3`, `3→2`, `2→-1` | 2 | No |

---

## Peça 93 — Blue Laser

![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 32 fases  
**Quantidade de Estados:** 8 estado(s)  

> When this blue laser gun is plugged into an outlet (and the switch is on) it will fire a blue laser beam. When the beam strikes a blue Laser-Activated Plug, it will generate energy that can be used to power anything hooked up to that outlet. Laser beams can be bounced and directed by using angled mirrors. They may also be fired into Laser Mixers, which will blend the colors of the beams. If an object passes through a laser beam, it will temporarily cut off the energy flow. Use laser beams to light fuses and candles, or to pop balloons.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Operating | `1→5`, `5→6`, `6→7`, `7→9` | 7 | No |
| Operating | `9→4`, `4→3`, `3→2`, `2→-1` | 2 | No |

---

## Peça 94 — Angled Mirror

![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 26 fases  
**Quantidade de Estados:** 1 estado(s)  

> This angled mirror can be used to deflect and change the direction of laser beams. It can be positioned in four different angles.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 95 — Laser Mixer

![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 13 fases  
**Quantidade de Estados:** 32 estado(s)  

> This Laser Mixer will blend together the colors of any laser beams passing through it. For instance, a red beam and a blue beam will become violet. The violet beam could then be used to provide energy to a violet Laser-Activated Plug.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 96 — Laser-Activated Plug

![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 25 fases  
**Quantidade de Estados:** 10 estado(s)  

> When a laser beam of the right color strikes this laser-activated plug, it will provide electrical power to any part plugged into the outlet. It can be programmed to accept laser beams of any color. But if the plug is blue, for instance, it will only accept a blue laser beam.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 97 — Large Pipes

![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png)

**Categoria:** Pipe Systems  
**Fases em que aparece:** 16 fases  
**Quantidade de Estados:** 2 estado(s)  

> Connect sections of this large pipe together and drop balls or other things inside. Attach sections of curved pipe and t-connectors to control the direction that objects go. You can also attach an accelerator tube to speed up or reverse the direction of objects moving through the pipes.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 98 — T-Connector

![T-Connector](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Pipe Systems  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Use this T-Connector to hitch sections of large or curved pipe together. Drop balls and other objects into the openings. Attach an accelerator tube to speed up or reverse the direction of objects moving through the pipes.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 99 — Grass Incline

![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png)

**Categoria:** Inclines  
**Fases em que aparece:** 8 fases  
**Quantidade de Estados:** 1 estado(s)  

> Roll balls and other parts up or down this grass incline. Use it to control the direction of balloons and other objects. It can be stretched or shrunk, which changes the angle. It's not affected by explosives.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 100 — Log Incline

![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png)

**Categoria:** Inclines  
**Fases em que aparece:** 15 fases  
**Quantidade de Estados:** 1 estado(s)  

> Roll balls and other parts up or down this log incline. Use it to control the direction of balloons and other objects. It can be stretched or shrunk, which changes the angle. It's not affected by explosives.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 101 — Granite Incline

![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png)

**Categoria:** Inclines  
**Fases em que aparece:** 47 fases  
**Quantidade de Estados:** 1 estado(s)  

> Roll balls and other parts up or down this granite incline. Use it to control the direction of balloons and other objects. It can be stretched or shrunk, which changes the angle. It's not affected by explosives.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 102 — Brick Incline

![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png)

**Categoria:** Inclines  
**Fases em que aparece:** 25 fases  
**Quantidade de Estados:** 1 estado(s)  

> Roll balls and other parts up or down this brick incline. It can be stretched or shrunk, which changes the angle. Use it to control the direction of balloons and other objects. It's not affected by explosives.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 103 — Archway

![Archway](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> This big granite archway can be used to fill spaces so objects can't pass through. You can set things on top of it, or bounce things off it. But you can't blow it up.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 104 — Wooden Barrier

![Wooden Barrier](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> This large wooden barrier can be used to fill spaces so objects can't pass through. You can set things on top of it, or bounce things off it. But you can't blow it up.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 105 — Scaffold Barrier

![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 10 fases  
**Quantidade de Estados:** 1 estado(s)  

> This chunk of metal scaffolding can be used to fill spaces so objects can't pass through. You can set things on top of it, or bounce things off it. But you can't blow it up.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 106 — Lattice Archway

![Lattice Archway](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> This large lattice archway can be used to fill spaces so objects can't pass through. You can set things on top of it, or bounce things off it. But you can't blow it up.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 107 — Electric Mixer

![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 10 fases  
**Quantidade de Estados:** 2 estado(s)  

> Plug this electric mixer into an outlet to make it run.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Mixing | `2→1` | 2 | No |
| Mixing | `1→-1` | 1 | No |

---

## Peça 108 — Leaky Bucket

![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png)

**Categoria:** Containers  
**Fases em que aparece:** 11 fases  
**Quantidade de Estados:** 8 estado(s)  

> There's a hole in the bottom of this bucket. You can program how fast the water leaks out. The faster it drips, the heavier the bucket is when you start the puzzle. As the contents drip out, the bucket gets lighter. Tie a rope to the top and use pulleys to connect it to another object.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Dripping | `1→4` | 1 | No |
| Empty | `4→10` | 4 | No |

---

## Peça 109 — Blimp

![Blimp](../../build/phase-3/bitmaps/PART109_f000.png)

**Categoria:** Balloons / Airships  
**Fases em que aparece:** 47 fases  
**Quantidade de Estados:** 7 estado(s)  

> This blimp will fly in a straight line until it bumps into something and reverses direction. It will pop if it bumps into a moving gear, a tack, or certain other sharp objects, and it will blow up if it touches a flame or explosion.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Normal | `1→2` | 1 | No |
| Popped | `2→5` | 7 | No |
| Blown Up | `5→-1` | 6 | No |

---

## Peça 110 — Elm Tree

![Elm Tree](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 0 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 111 — Spruce Tree

![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 10 fases  
**Quantidade de Estados:** 0 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 112 — Cactus

![Cactus](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 0 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 113 — Sun

![Sun](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 27 fases  
**Quantidade de Estados:** 0 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 114 — Big Cloud

![Big Cloud](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 24 fases  
**Quantidade de Estados:** 0 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 115 — Little Cloud

![Little Cloud](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 116 — Pinball Flipper

![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png)

**Categoria:** Springs / Pneumatics  
**Fases em que aparece:** 29 fases  
**Quantidade de Estados:** 2 estado(s)  

> This pinball flipper will flick any object that drops on top of it. It can be flipped left or right.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 117 — Pool Cue

![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png)

**Categoria:** Springs / Pneumatics  
**Fases em que aparece:** 29 fases  
**Quantidade de Estados:** 24 estado(s)  

> This pool cue is spring- loaded and ready to shoot anytime something bumps the button on the back end. It can be rotated to shoot from eight different angles. Use it to hit pool balls and other things.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Hit | `3→4`, `12→13`, `15→17`, `19→20`, `22→23`, `25→26`, `28→29`, `31→32` | 31 | No |
| Hit | `4→12`, `13→15`, `17→19`, `20→22`, `23→25`, `26→28`, `29→31`, `32→-1` | 33 | No |

---

## Peça 118 — Pool Table Wall

![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png)

**Categoria:** Pool Table  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 3 estado(s)  

> You can build your own virtual pool table with these felt-covered walls. Balls will bounce off them. Add pockets wherever you want them. Flip these walls if necessary.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 119 — Pool Table Pocket

![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png)

**Categoria:** Pool Table  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 16 estado(s)  

> These pool table pockets can be rotated to eight different angles. Use them with sections of pool table wall to build your own billiards game. Anything that drops into one of these pockets will disappear.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Hole Empty | `1→3`, `3→4`, `4→5`, `5→6`, `6→7`, `7→8`, `8→9`, `9→11` | — | No |
| Hole Full | `11→12`, `12→13`, `13→14`, `14→15`, `15→16`, `16→17`, `17→18`, `18→-1` | — | No |

---

## Peça 120 — Electrical Outlet

![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png)

**Categoria:** Electrical  
**Fases em que aparece:** 32 fases  
**Quantidade de Estados:** 4 estado(s)  

> This electrical outlet has juice running to it at all times. Plug in any electrical part and it will work.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 121 — Vine Tile

![Vine Tile](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 122 — tile

![tile](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 123 — tile

![tile](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 124 — tile

![tile](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 125 — Yellow Brick Wall

![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png)

**Categoria:** Walls / Floors  
**Fases em que aparece:** 32 fases  
**Quantidade de Estados:** 2 estado(s)  

> This is a yellow brick wall or floor. Stretch it vertically or horizontally to any length you need. Its surface is pretty slippery. Explosions will blow holes through it.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 126 — Yellow Brick Incline

![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png)

**Categoria:** Inclines  
**Fases em que aparece:** 38 fases  
**Quantidade de Estados:** 1 estado(s)  

> Roll balls and other parts up or down this yellow brick incline. Use it to control the direction of balloons and other objects. It can be stretched or shrunk, which changes the angle. It's not affected by explosives.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 128 — purple mountain

![purple mountain](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 11 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 129 — desert mesa

![desert mesa](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 130 — Glass Building

![Glass Building](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 131 — apartment building

![apartment building](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 132 — office building

![office building](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 133 — car

![car](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 134 — lamp post

![lamp post](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 135 — fire hydrant

![fire hydrant](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 136 — Message Computer

![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 3 estado(s)  

> This little computer is a handy way to relay messages one letter at a time. A letter will appear on the monitor if something bumps the keyboard. The computer may be programmed to display any letter in the alphabet, numbers 0 through 9, and several symbols. Line them up side by side to spell out a whole message.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Off | `4→5` | — | No |
| On | `5→-1` | 5 | No |

---

## Peça 137 — Egg Timer

![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 46 fases  
**Quantidade de Estados:** 26 estado(s)  

> Program this egg timer to a desired amount of time. Then drop something on the top knob to make it start. When the time is up, an arm pops out, bumping anything in its way.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unactivated | `22→37`, `23→38`, `26→39`, `28→40`, `30→41`, `36→42`, `33→43`, `34→44` | — | No |
| Time Out | `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1`, `19→-1` | — | No |

---

## Peça 138 — Candle

![Candle](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Light / Flame Sources  
**Fases em que aparece:** 26 fases  
**Quantidade de Estados:** 2 estado(s)  

> This candle can be lit with a laser beam, a phazer, another flaming part (like a rocket or an oil lamp), or with a magnifying glass and light source. Use it to light fuses, make the coffee pot percolate, or pop blimps and balloons.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Unlit | `1→2` | 1 | No |
| Lit | `2→-1` | 2 | No |

---

## Peça 139 — Teeter-Totter

![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png)

**Categoria:** Special Mechanics  
**Fases em que aparece:** 53 fases  
**Quantidade de Estados:** 1 estado(s)  

> Drop something heavy on the high end of this teeter-totter to catapult an object off the low end. Tie a rope to either end and use it to hoist and lower objects, pull the phazer trigger, or cause other reactions.


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 140 — Small Cactus

![Small Cactus](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 141 — Small Maple Tree

![Small Maple Tree](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 142 — Small Pine Tree

![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 9 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 143 — Small Cloud

![Small Cloud](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 24 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 144 — small mountain

![small mountain](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 10 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 145 — medium mountain

![medium mountain](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 11 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 146 — small mesa

![small mesa](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 147 — medium mesa

![medium mesa](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> scenery part


**Detalhes dos Estados:**
*No SOLVE.RES state data — this part has no programmatic state transitions.*

---

## Peça 148 — Laser Detector

![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png)

**Categoria:** Lasers / Optics  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 4 estado(s)  

> This laser detector can receive laser beams of any color. When a beam strikes the black eye, the green light turns on. If the beam is broken, the red light flashes. If the beam returns, both lights will flash.


**Detalhes dos Estados:**
### SOLVE.RES State Transitions

| State Name | Triggers (self→other) | ANM State | Explosive |
|------------|-----------------------|-----------|-----------|
| Not Activated | `2→3` | — | No |
| Activated | `3→4` | — | No |
| Alarm On | `4→-1` | — | No |

---

## Peça 150 — Pine Forest

![Pine Forest](../../scenery-review/PART150.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice wall panel (104x45)

---

## Peça 151 — Cave Opening

![Cave Opening](../../scenery-review/PART151.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice cave wall rough (88x47)

---

## Peça 152 — Forest Trees

![Forest Trees](../../scenery-review/PART152.png)

**Categoria:** Scenery  
**Fases em que aparece:** 8 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice bank/slope section (72x36)

---

## Peça 153 — Rocky Terrain

![Rocky Terrain](../../scenery-review/PART153.png)

**Categoria:** Scenery  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark scenery section (72x33)

---

## Peça 154 — Rocky Mountain

![Rocky Mountain](../../scenery-review/PART154.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark floor tile (80x34)

---

## Peça 155 — Trees on Rocks

![Trees on Rocks](../../scenery-review/PART155.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark platform ledge (104x26)

---

## Peça 156 — Trees on Terrain

![Trees on Terrain](../../scenery-review/PART156.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark ledge shorter (88x19)

---

## Peça 157 — Snow Mountains

![Snow Mountains](../../scenery-review/PART157.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Snow-topped ice formation (120x32)

---

## Peça 158 — Iceberg

![Iceberg](../../scenery-review/PART158.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Iceberg with white snowcap (72x42)

---

## Peça 159 — Snow Peaks

![Snow Peaks](../../scenery-review/PART159.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice spire/pillar (80x31)

---

## Peça 160 — Sand Dune

![Sand Dune](../../scenery-review/PART160.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood plank horizontal (112x21)

---

## Peça 161 — Desert Dune

![Desert Dune](../../scenery-review/PART161.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Shorter wood plank (88x19)

---

## Peça 162 — Sand Hill

![Sand Hill](../../scenery-review/PART162.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Thin wood beam (72x13)

---

## Peça 163 — Tropical Island

![Tropical Island](../../scenery-review/PART163.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 0 estado(s)  

> Wood platform/top (112x30)

---

## Peça 164 — Red Canyon

![Red Canyon](../../scenery-review/PART164.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Red-painted wood ledge (112x22)

---

## Peça 165 — Red Rock

![Red Rock](../../scenery-review/PART165.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Red-painted wood beam (96x16)

---

## Peça 166 — Red Formation

![Red Formation](../../scenery-review/PART166.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Red wood strip narrow (56x26)

---

## Peça 167 — Castle Fortress

![Castle Fortress](../../scenery-review/PART167.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Building/wall section tall (96x124)

---

## Peça 168 — Planet Rings

![Planet Rings](../../scenery-review/PART168.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Large background decor (160x92)

---

## Peça 169 — Moon

![Moon](../../scenery-review/PART169.png)

**Categoria:** Scenery  
**Fases em que aparece:** 11 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice background panel (64x61)

---

## Peça 170 — Moon Crater

![Moon Crater](../../scenery-review/PART170.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood background panel (72x66)

---

## Peça 171 — Owl

![Owl](../../scenery-review/PART171.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background detail (48x45)

---

## Peça 172 — Spiral Galaxy

![Spiral Galaxy](../../scenery-review/PART172.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice ruin/arch structure (80x84)

---

## Peça 173 — Gold Nugget

![Gold Nugget](../../scenery-review/PART173.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 174 — Gold Rock

![Gold Rock](../../scenery-review/PART174.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 175 — Globe

![Globe](../../scenery-review/PART175.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 176 — Comet

![Comet](../../scenery-review/PART176.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 177 — Star Glow

![Star Glow](../../scenery-review/PART177.png)

**Categoria:** Scenery  
**Fases em que aparece:** 8 fases  
**Quantidade de Estados:** 1 estado(s)  

> Snow block detail (56x57)

---

## Peça 178 — Star Burst

![Star Burst](../../scenery-review/PART178.png)

**Categoria:** Scenery  
**Fases em que aparece:** 10 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small ice connector joint (24x23)

---

## Peça 179 — Star Sparkle

![Star Sparkle](../../scenery-review/PART179.png)

**Categoria:** Scenery  
**Fases em que aparece:** 9 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tiny ice connector joint (24x17)

---

## Peça 180 — Stalactites

![Stalactites](../../scenery-review/PART180.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood roof/canopy (96x54)

---

## Peça 181 — Greenhouse Dome

![Greenhouse Dome](../../scenery-review/PART181.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice cap/ledge section (88x30)

---

## Peça 182 — Sphinx Pyramid

![Sphinx Pyramid](../../scenery-review/PART182.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Log cabin wall section (88x44)

---

## Peça 183 — Futuristic Tower

![Futuristic Tower](../../scenery-review/PART183.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background block (88x57)

---

## Peça 184 — Sci-Fi City

![Sci-Fi City](../../scenery-review/PART184.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice block tile (80x47)

---

## Peça 185 — Cityscape

![Cityscape](../../scenery-review/PART185.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood tile (56x40)

---

## Peça 186 — Metropolis

![Metropolis](../../scenery-review/PART186.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice floor tile (72x44)

---

## Peça 187 — City Buildings

![City Buildings](../../scenery-review/PART187.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background cap piece (88x33)

---

## Peça 188 — Ice Castle

![Ice Castle](../../scenery-review/PART188.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background insert (64x33)

---

## Peça 189 — Crystal Tower

![Crystal Tower](../../scenery-review/PART189.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background detail panel (56x50)

---

## Peça 190 — City Skyline

![City Skyline](../../scenery-review/PART190.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background panel (88x53)

---

## Peça 191 — Totem Pole

![Totem Pole](../../scenery-review/PART191.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Vertical wood post (24x83)

---

## Peça 192 — Satellite Tower

![Satellite Tower](../../scenery-review/PART192.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tall ice spire/formation (72x103)

---

## Peça 193 — Radio Tower

![Radio Tower](../../scenery-review/PART193.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Short ice column section (32x56)

---

## Peça 194 — Dish Antenna

![Dish Antenna](../../scenery-review/PART194.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background post (32x45)

---

## Peça 195 — Glass Dome

![Glass Dome](../../scenery-review/PART195.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Snow bank top (64x30)

---

## Peça 196 — Crystal Formation

![Crystal Formation](../../scenery-review/PART196.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood structure block (72x54)

---

## Peça 197 — Mountain Range

![Mountain Range](../../scenery-review/PART197.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wide wood beam (136x16)

---

## Peça 198 — Volcano

![Volcano](../../scenery-review/PART198.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood frame/arch (80x57)

---

## Peça 199 — Erupting Volcano

![Erupting Volcano](../../scenery-review/PART199.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Large wood panel (128x73)

---

## Peça 200 — Red Coral Branch

![Red Coral Branch](../../scenery-review/PART200.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Red decorative trim (112x11)

---

## Peça 201 — Red Seaweed

![Red Seaweed](../../scenery-review/PART201.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wide red decorative trim (128x24)

---

## Peça 202 — Red Coral

![Red Coral](../../scenery-review/PART202.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Red decorative beam (168x18)

---

## Peça 203 — Dark Space

![Dark Space](../../scenery-review/PART203.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Solid dark filler (72x72)

---

## Peça 204 — Satellite

![Satellite](../../scenery-review/PART204.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 205 — Blue Space

![Blue Space](../../scenery-review/PART205.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Blue ice/water surface (72x72)

---

## Peça 206 — Ocean Wave

![Ocean Wave](../../scenery-review/PART206.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice strip horizontal (112x32)

---

## Peça 207 — Breaking Wave

![Breaking Wave](../../scenery-review/PART207.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice ledge section (112x18)

---

## Peça 208 — Surf Wave

![Surf Wave](../../scenery-review/PART208.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice edge trim (72x14)

---

## Peça 209 — Rising Bubbles

![Rising Bubbles](../../scenery-review/PART209.png)

**Categoria:** Scenery  
**Fases em que aparece:** 8 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tall ice column (16x81)

---

## Peça 210 — Bubble Stream

![Bubble Stream](../../scenery-review/PART210.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice pillar section (16x74)

---

## Peça 211 — Floating Bubbles

![Floating Bubbles](../../scenery-review/PART211.png)

**Categoria:** Scenery  
**Fases em que aparece:** 7 fases  
**Quantidade de Estados:** 1 estado(s)  

> Short ice pillar (16x40)

---

## Peça 212 — Coral Arch

![Coral Arch](../../scenery-review/PART212.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood fence/railing (80x49)

---

## Peça 213 — Coral Branch

![Coral Branch](../../scenery-review/PART213.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood railing section (56x44)

---

## Peça 214 — Coral Formation

![Coral Formation](../../scenery-review/PART214.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Short wood railing (56x28)

---

## Peça 215 — Green Mountain

![Green Mountain](../../scenery-review/PART215.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood cube block (72x54)

---

## Peça 216 — Mossy Rock

![Mossy Rock](../../scenery-review/PART216.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood board/plank (80x36)

---

## Peça 217 — Green Cliff

![Green Cliff](../../scenery-review/PART217.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood slab wide (96x45)

---

## Peça 218 — Shipwreck

![Shipwreck](../../scenery-review/PART218.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Large wood block (112x91)

---

## Peça 219 — Submarine

![Submarine](../../scenery-review/PART219.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wide wood panel (144x64)

---

## Peça 220 — Ancient Ruins

![Ancient Ruins](../../scenery-review/PART220.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood arch/doorway (88x71)

---

## Peça 221 — Stone Temple

![Stone Temple](../../scenery-review/PART221.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tall wood block (88x58)

---

## Peça 222 — Ornate Gate

![Ornate Gate](../../scenery-review/PART222.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 223 — Bamboo Fence

![Bamboo Fence](../../scenery-review/PART223.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small wood tile (24x31)

---

## Peça 224 — Stone Wall

![Stone Wall](../../scenery-review/PART224.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 225 — Stone Block

![Stone Block](../../scenery-review/PART225.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood detail piece (40x35)

---

## Peça 226 — Hot Rod Car

![Hot Rod Car](../../scenery-review/PART226.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood top decoration (136x61)

---

## Peça 227 — Clown Fish

![Clown Fish](../../scenery-review/PART227.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood patch/tile (64x25)

---

## Peça 228 — Anchor

![Anchor](../../scenery-review/PART228.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Medium wood block (48x42)

---

## Peça 229 — Treasure Chest

![Treasure Chest](../../scenery-review/PART229.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood texture tile (56x42)

---

## Peça 230 — Ship Logo

![Ship Logo](../../scenery-review/PART230.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background strip (40x16)

---

## Peça 231 — Comet Streak

![Comet Streak](../../scenery-review/PART231.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tiny wood strip (24x12)

---

## Peça 232 — Golden Shell

![Golden Shell](../../scenery-review/PART232.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 233 — Shell

![Shell](../../scenery-review/PART233.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small wood tile (32x21)

---

## Peça 234 — Shell Spiral

![Shell Spiral](../../scenery-review/PART234.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small wood strip (32x18)

---

## Peça 235 — Red Fan Coral

![Red Fan Coral](../../scenery-review/PART235.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 236 — Starfish

![Starfish](../../scenery-review/PART236.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood filler joint (24x19)

---

## Peça 237 — Metal Gears

![Metal Gears](../../scenery-review/PART237.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tiny wood joint (16x18)

---

## Peça 238 — Orange Coral

![Orange Coral](../../scenery-review/PART238.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small vertical wood (24x35)

---

## Peça 239 — Coral Branch

![Coral Branch](../../scenery-review/PART239.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Square wood tile (32x25)

---

## Peça 240 — Green Coral

![Green Coral](../../scenery-review/PART240.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Vertical wood section (24x35)

---

## Peça 241 — Coral Tree

![Coral Tree](../../scenery-review/PART241.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small square wood (32x25)

---

## Peça 242 — Seaweed Tall

![Seaweed Tall](../../scenery-review/PART242.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tall thin wood (40x52)

---

## Peça 243 — Kelp Forest

![Kelp Forest](../../scenery-review/PART243.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood cluster/clump (32x31)

---

## Peça 244 — Kelp Plant

![Kelp Plant](../../scenery-review/PART244.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tall wood strip (32x68)

---

## Peça 245 — Seaweed Vine

![Seaweed Vine](../../scenery-review/PART245.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tall thin wood divider (16x81)

---

## Peça 246 — Seaweed Long

![Seaweed Long](../../scenery-review/PART246.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood divider strip (16x66)

---

## Peça 247 — Plant Stem

![Plant Stem](../../scenery-review/PART247.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Narrow wood strip (16x46)

---

## Peça 248 — Sea Urchin

![Sea Urchin](../../scenery-review/PART248.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark wood tile (32x21)

---

## Peça 249 — Red Crab

![Red Crab](../../scenery-review/PART249.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark wood detail (32x22)

---

## Peça 250 — Jellyfish

![Jellyfish](../../scenery-review/PART250.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Crystal ice detail (32x27)

---

## Peça 251 — Octopus

![Octopus](../../scenery-review/PART251.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wood texture panel (48x33)

---

## Peça 252 — Striped Fish

![Striped Fish](../../scenery-review/PART252.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Mini wood tile (24x19)

---

## Peça 253 — Angelfish

![Angelfish](../../scenery-review/PART253.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 0 estado(s)  

> Micro wood strip (24x14)

---

## Peça 254 — Goldfish

![Goldfish](../../scenery-review/PART254.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small wood strip (32x14)

---

## Peça 255 — Seahorse

![Seahorse](../../scenery-review/PART255.png)

**Categoria:** Scenery  
**Fases em que aparece:** 5 fases  
**Quantidade de Estados:** 1 estado(s)  

> Mini tall wood (24x35)

---

## Peça 256 — Shark

![Shark](../../scenery-review/PART256.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background ledge (48x15)

---

## Peça 257 — Fish School

![Fish School](../../scenery-review/PART257.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Nano wood tile (16x9)

---

## Peça 258 — Fish Scatter

![Fish Scatter](../../scenery-review/PART258.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Micro flat wood (32x11)

---

## Peça 259 — Fish Group

![Fish Group](../../scenery-review/PART259.png)

**Categoria:** Scenery  
**Fases em que aparece:** 8 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small flat wood (32x21)

---

## Peça 260 — Great White Shark

![Great White Shark](../../scenery-review/PART260.png)

**Categoria:** Scenery  
**Fases em que aparece:** 6 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wide flat ice surface (120x35)

---

## Peça 261 — Dolphin

![Dolphin](../../scenery-review/PART261.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Ice surface tile (104x35)

---

## Peça 262 — Orca Whale

![Orca Whale](../../scenery-review/PART262.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wide background decor (176x91)

---

## Peça 263 — Gray Whale

![Gray Whale](../../scenery-review/PART263.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Wide wood decoration (216x88)

---

## Peça 264 — Lionfish

![Lionfish](../../scenery-review/PART264.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 265 — Stingray

![Stingray](../../scenery-review/PART265.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 266 — White Coral

![White Coral](../../scenery-review/PART266.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 267 — Tree Trunk

![Tree Trunk](../../scenery-review/PART267.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 1 estado(s)  

> Small wood section (32x26)

---

## Peça 268 — Stained Glass

![Stained Glass](../../scenery-review/PART268.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tall pole/flagpole (56x111)

---

## Peça 269 — Abstract Art

![Abstract Art](../../scenery-review/PART269.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Large rock/wood wall (80x101)

---

## Peça 270 — Landscape Painting

![Landscape Painting](../../scenery-review/PART270.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Large ice block (104x76)

---

## Peça 271 — Blue Tiles

![Blue Tiles](../../scenery-review/PART271.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 272 — Computer Monitor

![Computer Monitor](../../scenery-review/PART272.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark background tile (80x62)

---

## Peça 273 — Metal Vent

![Metal Vent](../../scenery-review/PART273.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background vertical strip (40x60)

---

## Peça 274 — Einstein Bust

![Einstein Bust](../../scenery-review/PART274.png)

**Categoria:** Scenery  
**Fases em que aparece:** 2 fases  
**Quantidade de Estados:** 1 estado(s)  

> Background decoration (40x46)

---

## Peça 275 — Workshop Board

![Workshop Board](../../build/phase-3/bitmaps/BLANK.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 0 estado(s)  

> Scenery decoration tile

---

## Peça 276 — Cliff Edge

![Cliff Edge](../../scenery-review/PART276.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 0 estado(s)  

> Large ice end piece (120x100)

---

## Peça 277 — Treasure Map

![Treasure Map](../../scenery-review/PART277.png)

**Categoria:** Scenery  
**Fases em que aparece:** 0 fases  
**Quantidade de Estados:** 1 estado(s)  

> Scenery decoration tile

---

## Peça 278 — Periodic Table

![Periodic Table](../../scenery-review/PART278.png)

**Categoria:** Scenery  
**Fases em que aparece:** 1 fases  
**Quantidade de Estados:** 1 estado(s)  

> Dark background block (112x66)

---

## Peça 279 — Wooden Door

![Wooden Door](../../scenery-review/PART279.png)

**Categoria:** Scenery  
**Fases em que aparece:** 3 fases  
**Quantidade de Estados:** 1 estado(s)  

> Tree canopy/foliage (64x80)

---

## Peça 280 — Stone Texture

![Stone Texture](../../scenery-review/PART280.png)

**Categoria:** Scenery  
**Fases em que aparece:** 4 fases  
**Quantidade de Estados:** 0 estado(s)  

> Wood panel backdrop (72x64)

---



# 9. Catálogo Detalhado de Fases e Dependências

Este documento cataloga exaustivamente todas as fases do jogo. Para cada fase, detalhamos o objetivo, dicas, **setup exato das peças** (inventário + cenário), e um **Mapa de Dependências** que estipula quais sistemas (`Solvers`), áudios e volumes de frames visuais (`.ANM`) o `LevelLoader` da Godot precisará puxar para a memória.

## ELEV1.yaml - Under the Sea
**Objetivo:** Get Mel home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Mel could walk through this pipe... if there were one here.
- This looks like a good place for an anti-gravity pad.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 9 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **257 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 6 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 6 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 4 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 4 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 2 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 1 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 2 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 1 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 2 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 2 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 2 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 2 peça(s)
- ![Green Cliff](../../scenery-review/PART217.png) **Green Cliff**: 1 peça(s)
- ![Shipwreck](../../scenery-review/PART218.png) **Shipwreck**: 1 peça(s)
- ![Ancient Ruins](../../scenery-review/PART220.png) **Ancient Ruins**: 2 peça(s)
- ![Stone Temple](../../scenery-review/PART221.png) **Stone Temple**: 2 peça(s)
- ![Bamboo Fence](../../scenery-review/PART223.png) **Bamboo Fence**: 1 peça(s)
- ![Stone Block](../../scenery-review/PART225.png) **Stone Block**: 1 peça(s)
- ![Anchor](../../scenery-review/PART228.png) **Anchor**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Shell Spiral](../../scenery-review/PART234.png) **Shell Spiral**: 1 peça(s)
- ![Starfish](../../scenery-review/PART236.png) **Starfish**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 1 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 4 peça(s)
- ![Coral Branch](../../scenery-review/PART239.png) **Coral Branch**: 3 peça(s)
- ![Green Coral](../../scenery-review/PART240.png) **Green Coral**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 2 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 3 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 1 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 12 peça(s)
- ![Octopus](../../scenery-review/PART251.png) **Octopus**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 2 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 4 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 3 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)
- ![Dolphin](../../scenery-review/PART261.png) **Dolphin**: 1 peça(s)

---

## ELEV2.yaml - Yellow Brick Path
**Objetivo:** Get Newton Mouse into his hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
-  Holes in the floor are a blast.
- Newton is just crazy about cheese.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **420 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 2 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 4 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 10 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 5 peça(s)

---

## ELEV3.yaml - Space Hoops
**Objetivo:** Put the basketball into the basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Jack has been known to be a good shot.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **128 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 3 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 4 peça(s)
- ![Snow Peaks](../../scenery-review/PART159.png) **Snow Peaks**: 2 peça(s)
- ![Planet Rings](../../scenery-review/PART168.png) **Planet Rings**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Stalactites](../../scenery-review/PART180.png) **Stalactites**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![City Buildings](../../scenery-review/PART187.png) **City Buildings**: 1 peça(s)
- ![Ice Castle](../../scenery-review/PART188.png) **Ice Castle**: 1 peça(s)
- ![Crystal Tower](../../scenery-review/PART189.png) **Crystal Tower**: 1 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Dish Antenna](../../scenery-review/PART194.png) **Dish Antenna**: 1 peça(s)

---

## ELEV4.yaml - Bump and Roll
**Objetivo:** Get the tennis ball into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- This ball needs a little punch to get going.
- Bowling ball in the side pocket!  Get it?
- A little time management maybe...

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **309 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## ELEV5.yaml - Midnight Blast
**Objetivo:** Fire the cannon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- This ball needs a little extra help to get going.
- Is it conveyor or conveyer? Something to be pondered I suppose.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **254 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 3 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![desert mesa](../../build/phase-3/bitmaps/BLANK.png) **desert mesa**: 2 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/BLANK.png) **small mesa**: 3 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/BLANK.png) **medium mesa**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 3 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 4 peça(s)
- ![Sphinx Pyramid](../../scenery-review/PART182.png) **Sphinx Pyramid**: 1 peça(s)

---

## ELEV6.yaml - Bill's Aquarium
**Objetivo:** Break Bill's aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Use a corner pipe to turn the ball in the proper direction.
- In some situations, one just isn't enough.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **343 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 8 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 17 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## ELEV7.yaml - Caged Balloons
**Objetivo:** Pop both of the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Sometimes you have to really atTACK a puzzle.
- There is a way to pull this balloon down with the parts available.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **286 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 8 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 6 peça(s)
- ![Archway](../../build/phase-3/bitmaps/BLANK.png) **Archway**: 4 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/BLANK.png) **Glass Building**: 4 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 1 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 2 peça(s)

---

## ELEV8.yaml - Air Time
**Objetivo:** Put all of the blimps in the hangar on the right.  They all need to be there at the same time.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- There must be a way to turn these three blimps around without disturbing the others.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **65 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 3 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 8 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 6 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/BLANK.png) **Elm Tree**: 7 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 9 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 7 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 3 peça(s)

---

## ELEV9.yaml - Pulley Popper
**Objetivo:** Pop the silver balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- This ball needs to make its way into the beach bucket.
- There must be a way to get this bucket through the wall below.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **311 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 9 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)

---

## ELEV10.yaml - Separation
**Objetivo:** Put the baseball in the aquarium and the pinball in the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- A light ball will roll over a trap door, but a heavy ball will fall through.
- Bombs away!
- Room for a Kaboom!
- What to do with this gap? Something should SPRING to mind.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **109 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 4 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 22 peça(s)

---

## ELEV11.yaml - Beach Blast
**Objetivo:** Shoot off all the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- There is a way to light these five rockets at the same time. But it can only be done at the speed of light.
- Leave the lighting of this last one up to Mel.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **566 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 8 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 6 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 6 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![tile](../../build/phase-3/bitmaps/BLANK.png) **tile**: 4 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 2 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/BLANK.png) **Glass Building**: 1 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/BLANK.png) **apartment building**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Sand Hill](../../scenery-review/PART162.png) **Sand Hill**: 1 peça(s)
- ![Tropical Island](../../scenery-review/PART163.png) **Tropical Island**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 1 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 2 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Breaking Wave](../../scenery-review/PART207.png) **Breaking Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 1 peça(s)
- ![Comet Streak](../../scenery-review/PART231.png) **Comet Streak**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 4 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 1 peça(s)
- ![Fish School](../../scenery-review/PART257.png) **Fish School**: 1 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 1 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)

---

## ELEV12.yaml - The Dream
**Objetivo:** Put the balls into the boxes. The green ball goes in the aquarium, the blue one in the crate, the yellow one in the basket, and the red one in the cardboard box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- An incline might be helpful here.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **94 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 8 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 4 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 5 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 3 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 15 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 9 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 4 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 2 peça(s)

---

## ELEV13.yaml - Late for the World Cup
**Objetivo:** Put the soccer ball into the basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- This all looks a little off-balance.
- A large curved pipe will help get the ball around the corner.
- Anti-gravity will move the basketball into the air, but it will still need help to get over the wall.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **114 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 9 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 5 peça(s)
- ![tile](../../build/phase-3/bitmaps/BLANK.png) **tile**: 8 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 9 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 1 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 1 peça(s)
- ![Snow Peaks](../../scenery-review/PART159.png) **Snow Peaks**: 2 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Breaking Wave](../../scenery-review/PART207.png) **Breaking Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 6 peça(s)

---

## ELEV14.yaml - Trap Newton
**Objetivo:** Trap Newton Mouse with the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Get Newton to fall on the plunger of the remote bomb.
- Use the remote bomb to blow up this wall and allow the pinball through.
- Hmm....What would cut this rope?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **133 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/BLANK.png) **Glass Building**: 3 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/BLANK.png) **apartment building**: 2 peça(s)
- ![office building](../../build/phase-3/bitmaps/BLANK.png) **office building**: 1 peça(s)
- ![car](../../build/phase-3/bitmaps/BLANK.png) **car**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/BLANK.png) **lamp post**: 4 peça(s)

---

## ELEV15.yaml - Balloon Traveler
**Objetivo:** Use the tack on the left side of the screen to pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Anti-gravity pads have an interesting effect on balloons. Place one here and see what happens!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **73 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 9 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 12 peça(s)

---

## ELEV16.yaml - Kitty in a Cage
**Objetivo:** Lure Curie Cat into the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- There must be something that will work with this plug.
- Here is some rotational energy waiting to be tapped.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **402 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 8 peça(s)

---

## ELEV17.yaml - The Food Machine.
**Objetivo:** Open the can, start the mixer, and heat up some coffee.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **212 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 8 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## ELEV18.yaml - Night in the Mountains
**Objetivo:** Help Mel get back to his cabin.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- On occasion, parts will be used in unusual ways. This accelerator tube for instance...

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **375 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 8 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/BLANK.png) **Elm Tree**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 7 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/BLANK.png) **Little Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 2 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 12 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 1 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 3 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 8 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 2 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 2 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 3 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## ELEV19.yaml - Double Whammy
**Objetivo:** Blow up both missiles.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Here's a nice spot for something tipsy.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **187 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## ELEV20.yaml - Deep Sea Explosion
**Objetivo:** Make the soccer ball float off the top of the screen.

**Ambiente:**
- Gravidade: 238
- Pressão do Ar: 128

**Dicas Ativas (2):**
- This basketball may be the key to the whole thing.
- Use a rope to pull down on the remote bomb's plunger. A teeter-totter might help.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **191 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 7 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 7 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Treasure Chest](../../scenery-review/PART229.png) **Treasure Chest**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Shell Spiral](../../scenery-review/PART234.png) **Shell Spiral**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 7 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 1 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Octopus](../../scenery-review/PART251.png) **Octopus**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 1 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 1 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 1 peça(s)
- ![Fish School](../../scenery-review/PART257.png) **Fish School**: 2 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 1 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 2 peça(s)

---

## ELEV21.yaml - Newton Drops a Message
**Objetivo:** Reveal Newton's message and get Curie Cat off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Who needs gravity in a spot like this?
- What if this ball were to get blown to the left?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **537 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 3 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 13 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 4 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 7 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## ELEV22.yaml - Home Sweet Home
**Objetivo:** Help Newton Mouse get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Some explosives might help remodel this wall.
- Newton looks small enough to go through these pipes.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **163 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 7 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 3 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 8 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 4 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)

---

## ELEV23.yaml - Feeding Curie
**Objetivo:** Open a can of cat food for Curie Cat.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Getting this bucket to fall may take some explosive thinking.
- Some extra GEAR may be needed to get the power from this motor to the generator.
- This generator needs to turn to get power flowing through the outlet.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **419 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 4 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Lattice Archway](../../build/phase-3/bitmaps/BLANK.png) **Lattice Archway**: 9 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 3 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)

---

## ELEV24.yaml - Fishtank Target
**Objetivo:** Blow up the fish tank with the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Find a source of rotational energy to drive this machine.
- Use the inclines to adjust the missile's trajectory.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **328 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 6 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 8 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 6 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 2 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 2 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 1 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 1 peça(s)

---

## ELEV25.yaml - Ghost Dynamite
**Objetivo:** Light the dynamite with the candle.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Try connecting a rope from the match to a balloon.
- Some anti-gravity will keep the candle floating.
- Try putting a balloon in here.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **198 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 10 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 9 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 7 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## ELEV26.yaml - The Merry Mixer
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Use hedge trimmers to cut the balloon loose.
- A springboard can bounce the ball up, over, and into the pipe.
- Anti-gravity pads have a funny effect on balloons.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **153 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 10 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 15 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)

---

## HH1.yaml - Shootin' Hoops
**Objetivo:** Put the basketball into the box on the right.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **175 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 5 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 4 peça(s)

---

## HH2.yaml - Pool Shark
**Objetivo:** Put the eight ball in the corner pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **239 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 6 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 4 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 2 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 3 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 3 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 3 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH3.yaml - High Impact Fishing
**Objetivo:** Break all of the fish tanks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **242 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 4 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 4 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)

---

## HH4.yaml - Plunk it in the Pocket
**Objetivo:** Put each pool ball into the nearest pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **484 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 4 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 4 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 6 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 5 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## HH5.yaml - Lawn Bowling
**Objetivo:** Put the bowling ball into the small glass aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **166 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 3 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 2 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 8 peça(s)

---

## HH6.yaml - Crazy Cannon
**Objetivo:** Fire the cannon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **300 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 4 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)

---

## HH7.yaml - The Balloon Buster's Ball
**Objetivo:** Pop all of the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **111 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 11 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 10 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 5 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 4 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 6 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 11 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 4 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 6 peça(s)

---

## HH8.yaml - Setting Sail
**Objetivo:** Make some toast.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **294 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 4 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 8 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH9.yaml - Score!
**Objetivo:** Put the bowling ball into the basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **202 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 6 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)

---

## HH10.yaml - Fire One
**Objetivo:** Launch the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **348 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 3 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## HH11.yaml - The Rocketeer's Revenge
**Objetivo:** Launch the rocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **451 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 4 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## HH12.yaml - Pool Trick
**Objetivo:** Shoot each of the numbered balls into the nearest pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **164 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 4 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 8 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 9 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)

---

## HH13.yaml - Big Red Head to Head
**Objetivo:** Launch the rocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **406 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 8 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 3 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH14.yaml - Blimp Blaster
**Objetivo:** Shoot down the blimp with a missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **208 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HH15.yaml - Mouse Race
**Objetivo:** Help Newton Mouse get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **210 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 12 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 19 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 12 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## HH16.yaml - Coffee Cage
**Objetivo:** Put the pot in the cage and brew some coffee.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **225 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH17.yaml - Rocket Rivalry
**Objetivo:** See who can launch the rocket!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 35 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **681 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HH18.yaml - Too Many Mice
**Objetivo:** Help Newton and his pals each find a mouse hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **224 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 6 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 16 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 27 peça(s)

---

## HH19.yaml - See-Saw Asylum
**Objetivo:** Pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **226 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 8 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH20.yaml - Bill's Bad Day
**Objetivo:** Break Bill's aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **342 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 8 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## HH21.yaml - Zap Trap.
**Objetivo:** Hit the sensor with the red laser.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **317 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## HH22.yaml - Laser Lighter
**Objetivo:** Light the hot air balloon at the bottom left and make it float off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **145 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 5 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 10 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH23.yaml - Balloons or Bust
**Objetivo:** Pop both balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **135 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH24.yaml - Punch Mel
**Objetivo:** Knock Mel off the screen. 

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **282 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH25.yaml - Pass to the Glass
**Objetivo:** Get the soccer ball into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **134 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 6 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH26.yaml - Slam Dunk
**Objetivo:** Get the basketball into the cardboard box at the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **232 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 3 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH27.yaml - Sharpshooter
**Objetivo:** Light the candle with the laser.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **156 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HH28.yaml - Ragtime Rollers
**Objetivo:** Put the bowling ball into the aquarium and the silver ball into the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **170 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 5 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/BLANK.png) **T-Connector**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 13 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH29.yaml - Loony Lamp
**Objetivo:** Light the oil lamp.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **201 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 4 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH30.yaml - Little Hindenburg
**Objetivo:** Destroy the blimp with the remote bomb.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **297 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 4 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH31.yaml - Puppy Popper
**Objetivo:** Pop the doggy balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **120 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## HH32.yaml - Mixer Moxie
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **497 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 6 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HH33.yaml - Shootin' Newton
**Objetivo:** Get Newton Mouse into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **612 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 5 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 6 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 7 peça(s)

---

## HH34.yaml - Blimp Buster
**Objetivo:** Destroy the blimp!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **210 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HH35.yaml - The Pop Shop
**Objetivo:** Pop the silver balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **226 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HH36.yaml - Pop the Purple Puppy
**Objetivo:** Pop the balloon before it escapes!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **128 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH37.yaml - 'Gator on Guard
**Objetivo:** Put Curie Cat in the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **645 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 7 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 8 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH38.yaml - The Age of Aquarium
**Objetivo:** Break both fish tanks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1008_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **507 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 2 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 7 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH39.yaml - Rootin' Tootin' Newton
**Objetivo:** Get Newton Mouse into the caution box at the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **207 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 10 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 3 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/BLANK.png) **T-Connector**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH40.yaml - The Perky Percolator
**Objetivo:** Make coffee by placing a flame under it.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **275 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 4 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH41.yaml - Blimp Exodus
**Objetivo:** Get the blimp off the screen any way you can.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **410 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 7 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 6 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH42.yaml - Omega Launch
**Objetivo:** Launch the rocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 29 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **397 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH43.yaml - 'Gator in the Garden
**Objetivo:** Help Mel Schlemming get back to his cozy home in the Everglades.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **473 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH44.yaml - Skyrockets in Flight
**Objetivo:** Launch the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **308 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 3 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH45.yaml - Log Hangar
**Objetivo:** Get the balloon into the log box at the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **285 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 7 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH46.yaml - Bye-Bye Bucket
**Objetivo:** Knock the bucket off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 25 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **400 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 7 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH47.yaml - Bucket Battle
**Objetivo:** Put the bucket on top of the caution wall.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **122 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 8 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH48.yaml - Hot Air Heroics
**Objetivo:** Light the balloon so that it floats off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **485 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH49.yaml - Bigshot
**Objetivo:** Fire the cannon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **580 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HH50.yaml - Last Launch
**Objetivo:** Launch all three fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **417 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 7 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 3 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV1.yaml - Things That Go Boom!!!
**Objetivo:** Set off the fireworks on the left side of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 25 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **628 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 21 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV2.yaml - Curie and the Fish Squish
**Objetivo:** Break all six fish tanks and help Curie Cat exit the right side of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **508 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 6 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 12 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 4 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HLEV3.yaml - Newton's Cafe
**Objetivo:** Help Newton Mouse treat all his pals to a cheese dinner.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **174 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 6 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 11 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)

---

## HLEV4.yaml - Curious Curie
**Objetivo:** Help Curie Cat get out of the basement. Make her exit the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **658 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 27 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 5 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)

---

## HLEV5.yaml - Cage the Kitty
**Objetivo:** Put Curie Cat in the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Can you think of anything that might "phaze" this dynamite?
- Pipes. Newton Mouse. Does that GENERATE any ideas?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **563 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 4 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)

---

## HLEV6.yaml - Target Practice
**Objetivo:** Use the boxing glove to pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The cannon ball would roll a lot better if there wasn't a wall in the way.
- Place the cannon here to give you the push you need.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **310 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 6 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Sand Dune](../../scenery-review/PART160.png) **Sand Dune**: 2 peça(s)
- ![Desert Dune](../../scenery-review/PART161.png) **Desert Dune**: 2 peça(s)
- ![Sand Hill](../../scenery-review/PART162.png) **Sand Hill**: 3 peça(s)
- ![Tropical Island](../../scenery-review/PART163.png) **Tropical Island**: 2 peça(s)

---

## HLEV7.yaml - Plural Pop
**Objetivo:** Pop both of the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Anti-gravity will move the ball in the right direction.
- Once you get the ball up here, you'll need to "accelerate" it over to the right.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **199 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 11 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 8 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 3 peça(s)

---

## HLEV8.yaml - Laser Coffee.
**Objetivo:** Get the coffee pot off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Did you know three colored laser beams mix to make a single white one?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **357 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 13 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 2 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 4 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 1 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 3 peça(s)

---

## HLEV9.yaml - Newton Goes Bowling
**Objetivo:** Put the bowling ball into the cardboard box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- You'll need help to turn on the generator as you push down the plunger. (A bucket-load of help!)

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **273 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 9 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 12 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/BLANK.png) **Elm Tree**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 12 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 3 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 10 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 3 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 3 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 3 peça(s)

---

## HLEV10.yaml - Toast Roast
**Objetivo:** It's breakfast time. Let's roast some toast.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Even a mouse could pop open the Jack-in-the-box.
- Use mouse power to get the ball over to the toaster.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **461 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 2 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 3 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 2 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 3 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 1 peça(s)
- ![Green Cliff](../../scenery-review/PART217.png) **Green Cliff**: 1 peça(s)
- ![Shipwreck](../../scenery-review/PART218.png) **Shipwreck**: 1 peça(s)
- ![Submarine](../../scenery-review/PART219.png) **Submarine**: 1 peça(s)
- ![Ancient Ruins](../../scenery-review/PART220.png) **Ancient Ruins**: 1 peça(s)
- ![Stone Temple](../../scenery-review/PART221.png) **Stone Temple**: 1 peça(s)

---

## HLEV11.yaml - Clash of the Critters
**Objetivo:** Help Curie Cat and Newton Mouse blow each other off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Carefully placed explosives could do a double duty.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **488 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 14 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## HLEV12.yaml - Cheese Please!
**Objetivo:** Put Newton Mouse into the cage at the bottom. Put the center piece of cheese in with him.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Whatever is placed here should help the ball get to the timer, and clear the way for Newton.
- What happens when cheese chunks collide?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **406 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 5 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 9 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 7 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## HLEV13.yaml - Danger Blimp
**Objetivo:** Get the blimp into the hangar on the left.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **262 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 6 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 3 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 5 peça(s)

---

## HLEV14.yaml - Pompeian Rhapsody
**Objetivo:** Light the candle and turn on the lava lamp.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- There must be some trick to a match-on-a-stick!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **120 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 13 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 11 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 7 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## HLEV15.yaml - Blimp-Be-Gone
**Objetivo:** Blow up the blimp before it can get off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Something as small as a mouse can start off this whole puzzle.
- Something you See (or Saw) in the parts bin might be a tip-off.
- The blimp's starting point is also the missile's launching point.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **299 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 8 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV16.yaml - Newton's Special Brew
**Objetivo:** Get the coffee to start brewing.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- A perfect place to catch some wind.
- A grand place for Newton's favorite dairy product.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **300 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 9 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 19 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/BLANK.png) **Glass Building**: 9 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/BLANK.png) **apartment building**: 1 peça(s)
- ![office building](../../build/phase-3/bitmaps/BLANK.png) **office building**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/BLANK.png) **lamp post**: 1 peça(s)
- ![fire hydrant](../../build/phase-3/bitmaps/BLANK.png) **fire hydrant**: 1 peça(s)

---

## HLEV17.yaml - Mel on the Move
**Objetivo:** Help Mel get safely home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Something just isn't connecting. What Mel needs is a "phazer-totter."
- Think Jericho, 800 B.C. Think "boom!"

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **383 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 17 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 4 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 3 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 11 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/BLANK.png) **Wooden Barrier**: 3 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)

---

## HLEV18.yaml - Edison's Breakfast
**Objetivo:** Turn on the can opener.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Reach deep down into your evil side. What would you really like to do to this happy face balloon?
- Some toast would go nicely with that delicious can of kitty food.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **560 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 6 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 4 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/BLANK.png) **Wooden Barrier**: 13 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)

---

## HLEV19.yaml - Mel's Mine Field
**Objetivo:** Get Mel or any of his friends to the house.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **363 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 10 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 14 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/BLANK.png) **Elm Tree**: 5 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 6 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)

---

## HLEV20.yaml - Mel Takes a Hike
**Objetivo:** Set off the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- If Mel could only get over to those flint rocks, I'll bet he could spark some interesting events.
- This wall needs to go.
- Gravity, in this case, is working against us in two ways.
- Color is important when it comes to switches.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **639 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 9 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Spiral Galaxy](../../scenery-review/PART172.png) **Spiral Galaxy**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 2 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 2 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## HLEV21.yaml - The Big Balloon Bummer
**Objetivo:** Pop all the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **286 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 10 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 1 peça(s)
- ![desert mesa](../../build/phase-3/bitmaps/BLANK.png) **desert mesa**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 3 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 4 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/BLANK.png) **small mesa**: 2 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/BLANK.png) **medium mesa**: 1 peça(s)
- ![Erupting Volcano](../../scenery-review/PART199.png) **Erupting Volcano**: 1 peça(s)
- ![Red Coral Branch](../../scenery-review/PART200.png) **Red Coral Branch**: 1 peça(s)
- ![Red Coral](../../scenery-review/PART202.png) **Red Coral**: 2 peça(s)

---

## HLEV22.yaml - Jolly Jolly Jumpin' Jack
**Objetivo:** Make Jack pop out of his box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **468 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 20 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 4 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/BLANK.png) **small mesa**: 2 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/BLANK.png) **medium mesa**: 2 peça(s)
- ![Red Canyon](../../scenery-review/PART164.png) **Red Canyon**: 3 peça(s)
- ![Red Rock](../../scenery-review/PART165.png) **Red Rock**: 3 peça(s)
- ![Red Formation](../../scenery-review/PART166.png) **Red Formation**: 2 peça(s)
- ![Volcano](../../scenery-review/PART198.png) **Volcano**: 2 peça(s)
- ![Erupting Volcano](../../scenery-review/PART199.png) **Erupting Volcano**: 1 peça(s)
- ![Red Coral Branch](../../scenery-review/PART200.png) **Red Coral Branch**: 3 peça(s)
- ![Red Seaweed](../../scenery-review/PART201.png) **Red Seaweed**: 2 peça(s)
- ![Red Coral](../../scenery-review/PART202.png) **Red Coral**: 3 peça(s)

---

## HLEV23.yaml - Rocket Racket
**Objetivo:** Make the rocket fly off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **453 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 5 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 4 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 18 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 3 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 3 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 3 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 8 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV24.yaml - Trick Shot
**Objetivo:** Put the 2 ball into the middle pocket at the bottom of the screen, and put the 3 ball into the top left corner pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **123 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 9 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)

---

## HLEV25.yaml - Fire Show Shenanigans
**Objetivo:** Set off all the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **406 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 7 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 9 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 11 peça(s)
- ![tile](../../build/phase-3/bitmaps/BLANK.png) **tile**: 3 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 2 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## HLEV26.yaml - Late for Breakfast
**Objetivo:** Make some toast and launch the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 35 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **625 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 4 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Archway](../../build/phase-3/bitmaps/BLANK.png) **Archway**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/BLANK.png) **Wooden Barrier**: 3 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 5 peça(s)
- ![Sand Dune](../../scenery-review/PART160.png) **Sand Dune**: 3 peça(s)
- ![Desert Dune](../../scenery-review/PART161.png) **Desert Dune**: 2 peça(s)
- ![Sand Hill](../../scenery-review/PART162.png) **Sand Hill**: 1 peça(s)
- ![Tropical Island](../../scenery-review/PART163.png) **Tropical Island**: 2 peça(s)

---

## HLEV27.yaml - Curie and the Cannon
**Objetivo:** Fire the cannon and put the laundry basket over Curie Cat.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **683 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 4 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Archway](../../build/phase-3/bitmaps/BLANK.png) **Archway**: 8 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 3 peça(s)
- ![Ship Logo](../../scenery-review/PART230.png) **Ship Logo**: 1 peça(s)

---

## HLEV28.yaml - Patriotic Pop-A-Thon
**Objetivo:** Pop the balloon in the top right corner of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **671 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 5 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 4 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 8 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 9 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 3 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 50 peça(s)

---

## HLEV29.yaml - Immobilized Mel
**Objetivo:** Help Mel get to the floor at the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **331 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 6 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 12 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 17 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 5 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Blue Space](../../scenery-review/PART205.png) **Blue Space**: 3 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 1 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 3 peça(s)
- ![Coral Arch](../../scenery-review/PART212.png) **Coral Arch**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Coral Formation](../../scenery-review/PART214.png) **Coral Formation**: 1 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 2 peça(s)
- ![Sea Urchin](../../scenery-review/PART248.png) **Sea Urchin**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 2 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 1 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 4 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 2 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 2 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 1 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 2 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 8 peça(s)

---

## HLEV30.yaml - Free Smiley
**Objetivo:** Make the smiley face balloon fly off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **364 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 8 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/BLANK.png) **Little Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 1 peça(s)
- ![Trees on Rocks](../../scenery-review/PART155.png) **Trees on Rocks**: 1 peça(s)
- ![Einstein Bust](../../scenery-review/PART274.png) **Einstein Bust**: 1 peça(s)
- ![Wooden Door](../../scenery-review/PART279.png) **Wooden Door**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 1 peça(s)

---

## HLEV31.yaml - Rocketropolis
**Objetivo:** Launch the rocket off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **454 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 11 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 3 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 18 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/BLANK.png) **Glass Building**: 3 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/BLANK.png) **apartment building**: 1 peça(s)
- ![office building](../../build/phase-3/bitmaps/BLANK.png) **office building**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 1 peça(s)
- ![Sphinx Pyramid](../../scenery-review/PART182.png) **Sphinx Pyramid**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![Cityscape](../../scenery-review/PART185.png) **Cityscape**: 1 peça(s)
- ![Metropolis](../../scenery-review/PART186.png) **Metropolis**: 1 peça(s)
- ![City Buildings](../../scenery-review/PART187.png) **City Buildings**: 3 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 2 peça(s)

---

## MLEV1.yaml - Mountain Man Mel
**Objetivo:** Get Mel to his cabin.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- What a lovely spot for a balloon!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **689 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 5 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 3 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/BLANK.png) **Elm Tree**: 2 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 3 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/BLANK.png) **Little Cloud**: 8 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 2 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Maple Tree**: 3 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 4 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 1 peça(s)

---

## MLEV2.yaml - Mondrian's Toy Box
**Objetivo:** Make all five Jack-in-the-boxes pop open.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Find a way to turn these gears. They all appear to be connected.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **144 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 14 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 5 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 7 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 18 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 15 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 7 peça(s)

---

## MLEV3.yaml - Gimpy Blimpy
**Objetivo:** Get the balloon off the top of the screen without popping any blimps.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- I wonder if a little tube of something explosive might fit between the blimps?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **282 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 15 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)

---

## MLEV4.yaml - Pipe Gripe
**Objetivo:** Get the Pinball off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- A little acceleration might be in order right about here.
- This looks like the only place on the screen the ball can get out.
- The shortest route is a straight line... but sometimes that just isn't an option.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **45 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 6 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 11 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 10 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 6 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/BLANK.png) **T-Connector**: 2 peça(s)

---

## MLEV5.yaml - Up and Away!
**Objetivo:** Launch the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Try some negative gravity on this pinball.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **175 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 8 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 5 peça(s)
- ![Rocky Mountain](../../scenery-review/PART154.png) **Rocky Mountain**: 2 peça(s)
- ![Trees on Rocks](../../scenery-review/PART155.png) **Trees on Rocks**: 2 peça(s)
- ![Trees on Terrain](../../scenery-review/PART156.png) **Trees on Terrain**: 3 peça(s)
- ![Moon Crater](../../scenery-review/PART170.png) **Moon Crater**: 1 peça(s)
- ![Owl](../../scenery-review/PART171.png) **Owl**: 1 peça(s)
- ![Red Coral Branch](../../scenery-review/PART200.png) **Red Coral Branch**: 4 peça(s)
- ![Red Seaweed](../../scenery-review/PART201.png) **Red Seaweed**: 3 peça(s)
- ![Red Coral](../../scenery-review/PART202.png) **Red Coral**: 3 peça(s)

---

## MLEV6.yaml - Mouse House Munchies
**Objetivo:** Feed Newton Mouse the cheese.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- The balloon tied to this rope is dying to "cut loose."

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **323 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 3 peça(s)
- ![tile](../../build/phase-3/bitmaps/BLANK.png) **tile**: 1 peça(s)
- ![Computer Monitor](../../scenery-review/PART272.png) **Computer Monitor**: 1 peça(s)
- ![Metal Vent](../../scenery-review/PART273.png) **Metal Vent**: 2 peça(s)
- ![Cliff Edge](../../scenery-review/PART276.png) **Cliff Edge**: 1 peça(s)
- ![Periodic Table](../../scenery-review/PART278.png) **Periodic Table**: 1 peça(s)

---

## MLEV7.yaml - Laser Launch
**Objetivo:** Launch the rocket off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Use a conveyor belt to move the rocket into the pit on the right.
- Use some pipes to get the ball going in the right direction.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **350 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 3 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 15 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## MLEV8.yaml - Fire Ball
**Objetivo:** Launch the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The right combination of parts will force the trap door to open.
- A plumber's nightmare--a soccer ball in the pipes.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **331 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 3 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 10 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 16 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)

---

## MLEV9.yaml - Fourth of July
**Objetivo:** Launch all the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- If there was just a little more time, you could light the candle.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **369 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 6 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 4 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 7 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## MLEV10.yaml - Beach Ball Bonanza
**Objetivo:** Put the striped ball into the bucket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The mouse motor can power the generator.
- It would be FANtastic to turn this pinwheel, which could then turn the conveyor belt.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **363 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 9 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 12 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/BLANK.png) **small mesa**: 1 peça(s)

---

## MLEV11.yaml - Cat Bounce
**Objetivo:** Pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Use some mouse power to generate electricity.
- Curie Cat comes running whenever she hears the can opener.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **462 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 10 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Archway](../../build/phase-3/bitmaps/BLANK.png) **Archway**: 3 peça(s)

---

## MLEV12.yaml - Laser Target
**Objetivo:** Shoot the sensor at the bottom right with the laser.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Pull down on the chain.
- This is a dual-purpose pinball.
- It's done with mirrors.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **317 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 8 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 4 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 3 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 9 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## MLEV13.yaml - Breakfast Buffet
**Objetivo:** Make coffee and toast.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Place the mouse motor here so the tennis ball can roll over it.
- With a little luck, a timer will push the tennis ball to the toaster.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **236 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 10 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 27 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 5 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 4 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 2 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 5 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 8 peça(s)

---

## MLEV14.yaml - Pipe Mixer
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- There's too much gravity here!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **165 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 7 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 7 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)

---

## MLEV15.yaml - Fishing in Rome
**Objetivo:** Break the fish tank.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- What goes up doesn't always come down.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **357 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 12 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)

---

## MLEV16.yaml - Bomb Baffle
**Objetivo:** Set off both bombs.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- See what happens if you pull down and push up at the same time.
- This appears to be the only object with enough potential energy to do anything.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **247 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 6 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## MLEV17.yaml - Bowl Me Over
**Objetivo:** Put the bowling ball into the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- You could get some real mouse power going here.
- Keep it moving...

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1008_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **202 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 11 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## MLEV18.yaml - Mel in a Muddle
**Objetivo:** Get Mel home in one piece!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- A timer here would not only help Mel across, but also get the pinball moving.
- Mel is a little off-balance in this one.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **380 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 14 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 10 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## MLEV19.yaml - Mel's Amazing Maze
**Objetivo:** Get Mel home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- A remote bomb plunger goes here. Set the bomb itself to the left so it can blow a hole in the floor.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **394 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 8 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 12 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## MLEV20.yaml - Illuminate the Lab
**Objetivo:** Turn on the lava lamp on top of Mel's underwater laboratory.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 128

**Dicas Ativas (2):**
- This pinball needs to float.
- Push down on this teeter-totter.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **364 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 6 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 8 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 1 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Ship Logo](../../scenery-review/PART230.png) **Ship Logo**: 1 peça(s)
- ![Starfish](../../scenery-review/PART236.png) **Starfish**: 1 peça(s)
- ![Green Coral](../../scenery-review/PART240.png) **Green Coral**: 1 peça(s)
- ![Coral Tree](../../scenery-review/PART241.png) **Coral Tree**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 4 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Sea Urchin](../../scenery-review/PART248.png) **Sea Urchin**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 1 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 2 peça(s)
- ![Fish School](../../scenery-review/PART257.png) **Fish School**: 2 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 6 peça(s)
- ![Dolphin](../../scenery-review/PART261.png) **Dolphin**: 3 peça(s)
- ![Orca Whale](../../scenery-review/PART262.png) **Orca Whale**: 1 peça(s)

---

## MLEV21.yaml - Blow Up
**Objetivo:** Make the balloon fly off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Don't forget to cut the rope, or the balloon will never take off!
- Give the baseball some help over to the remote plunger.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **211 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)

---

## MLEV22.yaml - Gravity Cavity
**Objetivo:** Put the soccer ball in the caution box with the 1-ball.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- How can one CONVEY the marvels of soccer?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **177 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 4 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 12 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## MLEV23.yaml - The Sky is Falling!
**Objetivo:** Mel is in trouble. Help him get to his house in the upper right.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Find a way to stop these buckets from falling.
- Unless he can find a way to float, Mel will fall through this hole.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **360 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 4 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 4 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 4 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/BLANK.png) **Elm Tree**: 4 peça(s)
- ![tile](../../build/phase-3/bitmaps/BLANK.png) **tile**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/BLANK.png) **Glass Building**: 1 peça(s)
- ![office building](../../build/phase-3/bitmaps/BLANK.png) **office building**: 1 peça(s)
- ![car](../../build/phase-3/bitmaps/BLANK.png) **car**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/BLANK.png) **lamp post**: 4 peça(s)
- ![fire hydrant](../../build/phase-3/bitmaps/BLANK.png) **fire hydrant**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Maple Tree**: 3 peça(s)

---

## MLEV24.yaml - Stop the Invasion
**Objetivo:** Blow up all of the blimps.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- This blimp will help in the destruction of the others.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **207 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 5 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 8 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 3 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 17 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 36 peça(s)
- ![Stalactites](../../scenery-review/PART180.png) **Stalactites**: 1 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 1 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Satellite Tower](../../scenery-review/PART192.png) **Satellite Tower**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Dish Antenna](../../scenery-review/PART194.png) **Dish Antenna**: 1 peça(s)
- ![Glass Dome](../../scenery-review/PART195.png) **Glass Dome**: 2 peça(s)
- ![Crystal Formation](../../scenery-review/PART196.png) **Crystal Formation**: 1 peça(s)

---

## MLEV25.yaml - Mel-O-Drama
**Objetivo:** Help Mel make it home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Mel could use a little help from his mouse friends.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **556 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 9 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/BLANK.png) **Little Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![desert mesa](../../build/phase-3/bitmaps/BLANK.png) **desert mesa**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/BLANK.png) **small mesa**: 1 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/BLANK.png) **medium mesa**: 1 peça(s)
- ![Red Canyon](../../scenery-review/PART164.png) **Red Canyon**: 1 peça(s)
- ![Red Rock](../../scenery-review/PART165.png) **Red Rock**: 2 peça(s)
- ![Red Formation](../../scenery-review/PART166.png) **Red Formation**: 1 peça(s)
- ![Castle Fortress](../../scenery-review/PART167.png) **Castle Fortress**: 1 peça(s)

---

## MLEV26.yaml - Lunar Base Take-off
**Objetivo:** Launch the rocket off the top of the screen.

**Ambiente:**
- Gravidade: 0
- Pressão do Ar: 0

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 25 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **517 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 19 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 1 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 6 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![Sci-Fi City](../../scenery-review/PART184.png) **Sci-Fi City**: 3 peça(s)
- ![Cityscape](../../scenery-review/PART185.png) **Cityscape**: 3 peça(s)
- ![Metropolis](../../scenery-review/PART186.png) **Metropolis**: 3 peça(s)
- ![City Buildings](../../scenery-review/PART187.png) **City Buildings**: 3 peça(s)
- ![Ice Castle](../../scenery-review/PART188.png) **Ice Castle**: 2 peça(s)
- ![Crystal Tower](../../scenery-review/PART189.png) **Crystal Tower**: 1 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Glass Dome](../../scenery-review/PART195.png) **Glass Dome**: 1 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## MLEV27.yaml - Flight through the Alps
**Objetivo:** Launch the balloon off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 29 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **338 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 10 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 10 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 4 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 3 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 5 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 5 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 6 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)

---

## MLEV28.yaml - Soccer Shocker
**Objetivo:** Put the soccer ball into the wooden crate.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 31 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **381 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 14 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 11 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![Mountain Range](../../scenery-review/PART197.png) **Mountain Range**: 1 peça(s)
- ![Volcano](../../scenery-review/PART198.png) **Volcano**: 1 peça(s)
- ![Blue Space](../../scenery-review/PART205.png) **Blue Space**: 1 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Breaking Wave](../../scenery-review/PART207.png) **Breaking Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 2 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)

---

## MLEV29.yaml - Pinball Puzzler
**Objetivo:** Make the pinball in the upper left corner fall off the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **94 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 18 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 11 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 3 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/BLANK.png) **T-Connector**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![tile](../../build/phase-3/bitmaps/BLANK.png) **tile**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## MLEV30.yaml - All Terrain Pinball
**Objetivo:** Put the pinball into the wicker basket and activate the computer terminal.

**Ambiente:**
- Gravidade: 143
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **232 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 13 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 3 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 7 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 8 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/BLANK.png) **Spruce Tree**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 2 peça(s)
- ![tile](../../build/phase-3/bitmaps/BLANK.png) **tile**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 3 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 2 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 3 peça(s)
- ![Coral Arch](../../scenery-review/PART212.png) **Coral Arch**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Hot Rod Car](../../scenery-review/PART226.png) **Hot Rod Car**: 1 peça(s)
- ![Clown Fish](../../scenery-review/PART227.png) **Clown Fish**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 5 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 2 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 6 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 2 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 1 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Sea Urchin](../../scenery-review/PART248.png) **Sea Urchin**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Octopus](../../scenery-review/PART251.png) **Octopus**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 3 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 1 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 2 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)
- ![Dolphin](../../scenery-review/PART261.png) **Dolphin**: 1 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)

---

## RLEV1.yaml - Exit Laughing
**Objetivo:** Make the happy face balloon exit the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **354 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 4 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 2 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 18 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 1 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Treasure Chest](../../scenery-review/PART229.png) **Treasure Chest**: 1 peça(s)
- ![Ship Logo](../../scenery-review/PART230.png) **Ship Logo**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Shell Spiral](../../scenery-review/PART234.png) **Shell Spiral**: 2 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 4 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 2 peça(s)
- ![Coral Branch](../../scenery-review/PART239.png) **Coral Branch**: 2 peça(s)
- ![Green Coral](../../scenery-review/PART240.png) **Green Coral**: 2 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 2 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 4 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 3 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 2 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 1 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 4 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)
- ![Orca Whale](../../scenery-review/PART262.png) **Orca Whale**: 1 peça(s)
- ![Gray Whale](../../scenery-review/PART263.png) **Gray Whale**: 1 peça(s)

---

## RLEV2.yaml - The Critter-Gitter Cat Trap
**Objetivo:** Trap Curie Cat in the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **448 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 14 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Stained Glass](../../scenery-review/PART268.png) **Stained Glass**: 1 peça(s)
- ![Abstract Art](../../scenery-review/PART269.png) **Abstract Art**: 1 peça(s)
- ![Landscape Painting](../../scenery-review/PART270.png) **Landscape Painting**: 1 peça(s)
- ![Einstein Bust](../../scenery-review/PART274.png) **Einstein Bust**: 1 peça(s)

---

## RLEV3.yaml - Lil' Mel's Jail Break
**Objetivo:** Assist Mel in his daring escape and journey home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **602 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 17 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 5 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 5 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/BLANK.png) **apartment building**: 2 peça(s)
- ![office building](../../build/phase-3/bitmaps/BLANK.png) **office building**: 3 peça(s)

---

## RLEV4.yaml - Laser Balloon Blitz
**Objetivo:** Pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **530 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 9 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 4 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 3 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 1 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 3 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 1 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)
- ![Trees on Terrain](../../scenery-review/PART156.png) **Trees on Terrain**: 1 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 1 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 1 peça(s)
- ![Castle Fortress](../../scenery-review/PART167.png) **Castle Fortress**: 1 peça(s)

---

## RLEV5.yaml - Balloon Over Manhattan
**Objetivo:** Make the balloon fly off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **184 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 6 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 6 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 4 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 6 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 2 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/BLANK.png) **Glass Building**: 3 peça(s)
- ![office building](../../build/phase-3/bitmaps/BLANK.png) **office building**: 1 peça(s)
- ![Stalactites](../../scenery-review/PART180.png) **Stalactites**: 1 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![Sphinx Pyramid](../../scenery-review/PART182.png) **Sphinx Pyramid**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![Sci-Fi City](../../scenery-review/PART184.png) **Sci-Fi City**: 1 peça(s)
- ![Cityscape](../../scenery-review/PART185.png) **Cityscape**: 1 peça(s)
- ![Crystal Tower](../../scenery-review/PART189.png) **Crystal Tower**: 1 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 4 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Satellite Tower](../../scenery-review/PART192.png) **Satellite Tower**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Glass Dome](../../scenery-review/PART195.png) **Glass Dome**: 1 peça(s)

---

## RLEV6.yaml - Pool Ball Sinker
**Objetivo:** Sink the eight ball.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **310 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 2 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 1 peça(s)

---

## RLEV7.yaml - Mega-Launch
**Objetivo:** Launch the missile, the rocket, and the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **585 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 8 peça(s)

---

## RLEV8.yaml - Newton's Dilemma
**Objetivo:** Get Newton safely home to his mouse hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **430 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 9 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 15 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 6 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV9.yaml - Brain Teaser Breakout
**Objetivo:** Lift the basket off of Newton so he can eat the cheese.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **349 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 15 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 10 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## RLEV10.yaml - Jack's Big Fan
**Objetivo:** Make the Jack-in-the-box pop out.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **441 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 14 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 13 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV11.yaml - Illuminated Schlemming
**Objetivo:** Light both candles and get Mel home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **629 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 4 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 14 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 2 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## RLEV12.yaml - Schlemming in Dreamland
**Objetivo:** Mel is sleep walking. Help him get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **393 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 5 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 10 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 3 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/BLANK.png) **small mountain**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 3 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 16 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 9 peça(s)

---

## RLEV13.yaml - Lasermania
**Objetivo:** Use the lasers to power the electric can-opener.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **448 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 4 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 5 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 5 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 16 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 5 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## RLEV14.yaml - Ballistic Balloon
**Objetivo:** Put the balloon inside the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **613 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 6 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 10 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 2 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/BLANK.png) **Wooden Barrier**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 3 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV15.yaml - Missile vs. Blimp
**Objetivo:** Remove the green blimp from the skies.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 31 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **651 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 4 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 3 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 3 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 12 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 2 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)

---

## RLEV16.yaml - Rodent Restaurant
**Objetivo:** Newton Mouse is ready for breakfast. Brew up some coffee and start the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 41 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **814 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## RLEV17.yaml - Fireworks Berserk
**Objetivo:** Set off the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 45 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **1422 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 7 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 4 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/BLANK.png) **lamp post**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/BLANK.png) **medium mesa**: 1 peça(s)

---

## RLEV18.yaml - Big Job, Little Mouse
**Objetivo:** Newton Mouse has some major painting to do. Help him lift the leaky paint bucket on the right up above his scaffold.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **676 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 6 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 5 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 2 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 8 peça(s)
- ![Archway](../../build/phase-3/bitmaps/BLANK.png) **Archway**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 1 peça(s)
- ![Bamboo Fence](../../scenery-review/PART223.png) **Bamboo Fence**: 1 peça(s)
- ![Wooden Door](../../scenery-review/PART279.png) **Wooden Door**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 13 peça(s)

---

## RLEV19.yaml - Fandango
**Objetivo:** Help Newton Mouse cool off by turning on the fan.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 40 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **886 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 9 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 4 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 5 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/BLANK.png) **Scaffold Barrier**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)

---

## RLEV20.yaml - It's Hip to Drip
**Objetivo:** Put the bowling ball into the steel cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **251 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 13 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV21.yaml - Mind-Mixer
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 30 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **524 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 12 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 4 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![Blue Space](../../scenery-review/PART205.png) **Blue Space**: 10 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 1 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 3 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Coral Arch](../../scenery-review/PART212.png) **Coral Arch**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 1 peça(s)
- ![Green Cliff](../../scenery-review/PART217.png) **Green Cliff**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 2 peça(s)

---

## RLEV22.yaml - The Ultimate Schlemming
**Objetivo:** Get Mel home.  Don't allow the red light to blink on the laser-detector.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 29 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **650 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 7 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 12 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 2 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 6 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## RLEV23.yaml - Blast-A-Blimp
**Objetivo:** Blow up the blimp with the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 30 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **478 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/BLANK.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/BLANK.png) **Big Cloud**: 2 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 4 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/BLANK.png) **Small Cloud**: 2 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Submarine](../../scenery-review/PART219.png) **Submarine**: 1 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 2 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 3 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)

---

## RLEV24.yaml - Enchanted Kingdom
**Objetivo:** Help Mel exit the right side of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **400 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 4 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 4 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 3 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/BLANK.png) **Elm Tree**: 2 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/BLANK.png) **Little Cloud**: 5 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/BLANK.png) **Color Block**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/BLANK.png) **Small Pine Tree**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 6 peça(s)
- ![Rocky Mountain](../../scenery-review/PART154.png) **Rocky Mountain**: 7 peça(s)
- ![Trees on Terrain](../../scenery-review/PART156.png) **Trees on Terrain**: 1 peça(s)
- ![Red Canyon](../../scenery-review/PART164.png) **Red Canyon**: 1 peça(s)
- ![Castle Fortress](../../scenery-review/PART167.png) **Castle Fortress**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Wooden Door](../../scenery-review/PART279.png) **Wooden Door**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 4 peça(s)

---

## RLEV25.yaml - Poolin' Around
**Objetivo:** Sink one ball into each hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **123 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 16 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 5 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)

---

## RLEV26.yaml - Beam Scream
**Objetivo:** Break the laser beam.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **354 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 3 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 18 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 2 peça(s)
- ![Archway](../../build/phase-3/bitmaps/BLANK.png) **Archway**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/BLANK.png) **purple mountain**: 1 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/BLANK.png) **medium mountain**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 2 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 2 peça(s)
- ![Snow Peaks](../../scenery-review/PART159.png) **Snow Peaks**: 1 peça(s)

---

## RLEV27.yaml - Basketball Brain-Buster
**Objetivo:** Send the basketball off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **239 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 4 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 17 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## RLEV28.yaml - Kitty Catcher
**Objetivo:** Put Curie Cat in the hole on the left. Then trap her with the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **470 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 4 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 5 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 8 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 6 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 3 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 3 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 7 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 10 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## RLEV29.yaml - TIM2 Contest Champion!
**Objetivo:** Congratulations to Richard and William Smith for creating this First Prize Puzzle in the TIM2 Puzzle Contest! Check out their work, and see if you can help Mel get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **657 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 8 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 7 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 7 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 14 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 11 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 5 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 2 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 7 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## TLEV1.yaml - Balls
**Objetivo:** Knock the eight ball off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Note how the super ball on the left bounces.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **113 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 2 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 2 peça(s)

---

## TLEV2.yaml - Walls and Inclines
**Objetivo:** Put both bowling balls into the large column box in the center.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- A wall can be stretched to fit correctly.
- Inclines could help get things rolling in the right direction.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **292 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 3 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 3 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 3 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 3 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 2 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 6 peça(s)

---

## TLEV3.yaml - Gears and Belts
**Objetivo:** Get all of the basketballs into the piped area.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- Notice that this conveyor belt moves faster than the one above. This is because it is attached to the small gear.
- This conveyor belt moves slower because it is connected to a large gear.
- The small gear will spin two times faster than the large gear.
- Look at the machine on the left side and try to duplicate what you see.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **97 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 8 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 3 peça(s)

---

## TLEV4.yaml - Teeter-Totters & Ropes
**Objetivo:** Put the three bowling balls into the wicker baskets.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Notice how this steel cable goes through the pulleys. This allows the teeter-totter to pull up on an object placed at a higher level.
- Look at the right side of the screen and try to duplicate what you see.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **75 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 3 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 4 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## TLEV5.yaml - Switches and Plugs
**Objetivo:** Start both of the electric mixers.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (6):**
- Notice that these electric plugs do not have a switch. They are always on.
- A ball bumping this switch turns on the power.
- This electric switch has been flipped upside-down. In this position, it must be bumped from below to flip it on.
- A switch that has been turned on may also be turned off by flipping it back to its original position.
- Notice that both plugs and switches have two outlets.
- This ball will turn on a switch placed beneath it. A switch or plug must be set in position before the electric part you wish to plug into it.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **359 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 5 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 3 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## TLEV6.yaml - Motors & Generators
**Objetivo:** Put both bowling balls between the logs.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Connect a belt to this wheel from any rotating power source. The generator will make electricity.
- Plug this motor into any powered outlet and it will run.
- If this conveyor belt is rotating the wrong direction, flip the motor.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 9 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **175 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)

---

## TLEV7.yaml - Lights and Solar Panels
**Objetivo:** Turn on all of the lights.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Pull down on this chain to turn on a lava lamp. Rope or steel cable can be attached to the chain.
- Bump the button on top of a flashlight to turn it on.
- The solar panel works like a generator. Get any light to shine on the panel to power the plug.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **156 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 2 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV8.yaml - Fire
**Objetivo:** Light both candles, both lamps, both flint-rocks, and the match-on-a-spring.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (7):**
- Any light shone through a magnifying glass will start a flame or light a fuse.
- You may need to flip a magnifying glass to make it work.
- To light the match, pull out this pin. A rope or steel cable can be attached to the eye hook.
- Hit the flint rocks with a falling object to light a fire.
- Check out how the other lamp is lit when you run the puzzle.
- Notice how the other candle is lit when you run the puzzle.
- Check out how the other flint rock is lit when you run the puzzle.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **127 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 4 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 4 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/BLANK.png) **Aladdin's Lamp**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 6 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV9.yaml - Explosives
**Objetivo:** Blow up both remote bombs.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (6):**
- The nitroglycerine will explode if dropped or hit with enough force.
- A light source and magnifying glass will light fuses.
- Push or pull down on the plunger to set off the bomb. A rope or steel cable can be tied to the plunger.
- Notice that not all walls can be blown up.
- Notice that some walls can be destroyed.
- This side is a mirror image of the other.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **144 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 5 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 8 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)

---

## TLEV10.yaml - Things That Launch
**Objetivo:** Launch all the rockets, missiles, and fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- A fuse can be lit with fire or by shining light through a magnifying glass.
- When a missile collides with something, it will explode.
- When lit, this part will explode into fireworks before leaving the screen. It's a programmable part.
- Missiles and rockets can be launched horizontally, fireworks can't.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **520 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 3 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 3 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 4 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 2 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)

---

## TLEV11.yaml - Cannons
**Objetivo:** Fire all of the cannons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Direct flame may be used to light fuses.
- Magnified light may be used to light fuses.
- Cannons can be flipped in six directions.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **174 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/BLANK.png) **Cannon**: 6 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 4 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 5 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 4 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)

---

## TLEV12.yaml - Fan, Pinwheel, Bike Pump
**Objetivo:** Put a bowling ball into each steel cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Plug a fan into any electric power source to make it run.
- Use wind from the fan or bike pump to turn the pinwheel. The pinwheel may be flipped if you want to change the direction it rotates.
- Push down on the bike pump and air will come out the front.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **153 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 2 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 4 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 4 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## TLEV13.yaml - Balloons
**Objetivo:** Pop the happy face balloon, but none of the others.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Hedge trimmers, tin snips, and tacks will pop balloons.
- Fire and explosions will pop balloons.
- Balloons can pull some objects upward.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **85 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 6 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)

---

## TLEV14.yaml - Blimps
**Objetivo:** Pop all of the blimps.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- A burning blimp can light fuses, candles, and oil lamps.
- A blimp will explode if it comes in contact with any fire.
- If a blimp bumps into hedge trimmers, tin snips, or a tack it will pop.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **103 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 4 peça(s)
- ![Candle](../../build/phase-3/bitmaps/BLANK.png) **Candle**: 1 peça(s)

---

## TLEV15.yaml - Hot Air Balloons
**Objetivo:** Launch all of the hot air balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Light the candle in the balloon to make it rise.
- Ropes and cables can be tied to balloons.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **116 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/BLANK.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 3 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV16.yaml - Anti-Gravity Pad
**Objetivo:** Put one balloon into each yellow brick box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- These anti-gravity pads will reverse the gravitational pull on an object.
- Notice how the bowling ball rises instead of dropping.
- The anti-gravity pad makes this balloon sink instead of rising.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **198 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 9 peça(s)

---

## TLEV17.yaml - Things That Bounce
**Objetivo:** Put all of the pinballs into a cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- Attach a belt from a motor to the Jack-in-the-box to pop it open. Anything on top will be thrown off when it pops open.
- An object bouncing on the springboard will get higher with each bounce.
- The pinball bumper will bounce an object off at any angle desired.
- Drop something on top of this and it will be flipped into the air.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **111 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 6 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 3 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 5 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 2 peça(s)

---

## TLEV18.yaml - Boxing Glove
**Objetivo:** Get both balloons off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Hit the button on the back of this glove to make it punch. Flip it to punch in the other direction.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **77 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)

---

## TLEV19.yaml - Electric Mixer, Can Opener
**Objetivo:** Turn on both electric mixers and open both cans.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Plug the mixer into an electric outlet to turn it on.
- Plug the can opener into an electric outlet to make it open the can.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 4 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **41 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 4 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 4 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 2 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 2 peça(s)

---

## TLEV20.yaml - Toasters
**Objetivo:** Make toast in each of the toasters.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- A toaster must be plugged into an outlet to work.
- After a toaster is plugged into an outlet, the handle must be pushed down.
- When the toast pops up, it can push up on objects.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **87 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)

---

## TLEV21.yaml - Large Pipes
**Objetivo:** Put one bowling ball into each steel cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- This accelerator can be flipped to force objects up, down, left, or right. The arrows indicate the direction of acceleration.
- Drop something into this curved pipe and it will come out the other side.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **61 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)

---

## TLEV22.yaml - Egg Timer
**Objetivo:** Get all of the pinballs off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- This timer can be programmed so that the little arm will pop out after a set amount of time. Push the button on top to turn it on.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **106 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 4 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 4 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/BLANK.png) **Remote Control Explosives**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 4 peça(s)

---

## TLEV23.yaml - Message Machine
**Objetivo:** Turn on all of the computers to read the message.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Drop something on the keyboard to turn on the computer.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **66 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 6 peça(s)

---

## TLEV24.yaml - Pool Balls, Walls, Cues
**Objetivo:** Put the 6-ball into the bottom right corner pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (6):**
- Bump this button on the back of the pool cue to make it spring forward.
- Change the angle at which the pool ball is hit to create a different trajectory.
- These pockets can be rotated to fit any angle on a pool table. If you get a ball close enough to the hole, it will go in.
- This wall can be stretched just like any other. It can also be flipped to a vertical position.
- The pool cue can be rotated to 8 different angles.
- The number on the pool ball can be programmed from 1 to 15. All of the pool balls react the same way.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **151 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 2 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 4 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 8 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 8 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)

---

## TLEV25.yaml - Coffee Pot
**Objetivo:** Blow both hot air balloons off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Make a fire under the coffee pot and it will blow steam out of its spout.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **106 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 2 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 5 peça(s)

---

## TLEV26.yaml - Lasers
**Objetivo:** Turn on all of the lasers.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Plug lasers into a power plug to make them work.
- Lasers can be flipped up, down, left, or right.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **80 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 2 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 2 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## TLEV27.yaml - Laser-Activated Plugs
**Objetivo:** Start the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- When a laser of the correct color hits this sensor the power will be turned on.
- Use a blue laser to turn on this switch.
- These plugs are programmable by color. Program the switch to match the laser color.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **97 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 3 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## TLEV28.yaml - Laser Mixers
**Objetivo:** Open all of the cans.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Combine two or more laser beams through this mixer to create new laser colors.
- Mix the colors to make a new color that will match each switch.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **227 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 3 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 2 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 2 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 2 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 3 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)

---

## TLEV29.yaml - Laser Mirrors
**Objetivo:** Start the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Flip the mirrors to angle the lasers in the correct direction.
- Try placing the mirror here. Small adjustments may be needed to get the correct angle on the laser.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **216 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 5 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## TLEV30.yaml - Laser Detector
**Objetivo:** Turn on the green light in each of the laser detectors.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- When a laser hits the eye of this detector, the green light will blink. If the beam is shut off, the red light will blink. If the beam then returns, both lights will blink.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **71 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 3 peça(s)

---

## TLEV31.yaml - Translation & Rotation
**Objetivo:** Put the pinballs into the aquariums.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (5):**
- Pull on this arm with a rope to rotate the center gear.
- The rotation of this gear can be used to power another part.
- Connect a belt from a motor to this wheel to move the arm up and down.
- A rope connected to this arm will pull on the object attached to the other end.
- Push on this end to turn the center gear.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **86 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 2 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 2 peça(s)

---

## TLEV32.yaml - Buckets
**Objetivo:** Put the two beach buckets up inside the yellow bricks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- The amount of liquid that drips out of the bucket can be programmed. The faster the bucket drips, the more quickly it becomes lighter.
- Ropes and cables can be tied to buckets.
- Many objects can be dropped into buckets.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **94 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 3 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 6 peça(s)

---

## TLEV33.yaml - Snips & Trimmers
**Objetivo:** Put one bucket into each basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The hedge trimmers can only cut rope. They won't work on steel cable.
- Tin snips can cut rope or steel cable.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **93 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 3 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/BLANK.png) **Boat Cleat**: 5 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 5 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/BLANK.png) **Steel Cable**: 2 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 3 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)

---

## TLEV34.yaml - Cats and Aquariums
**Objetivo:** Put all five cats between the pipes.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Fish aquariums will attract cats. Once they are broken they will attract cats from a greater distance.
- Bump the cat to make her take a few steps forward.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **362 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 5 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 6 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV35.yaml - Mice and Cheese
**Objetivo:** Get all of the mice to a piece of cheese.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Cheese will attract mice if they can see it. They can't see it from a long distance.
- Curie Cat will chase any mouse she sees. A caught mouse is instant cat food.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 4 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **272 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 5 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 3 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 5 peça(s)

---

## TLEV36.yaml - Mouse Hole
**Objetivo:** Get a mouse into each mouse hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- If a mouse encounters a mouse hole as it is running along it will go inside.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 4 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **82 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 2 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 2 peça(s)

---

## TLEV37.yaml - Mandrill Motor
**Objetivo:** Put a bowling ball inside each crate.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Release this shade and Pavlov Mandrill will walk on the treadmill, trying to get the bananas.
- Connect a belt to this wheel to turn another part.
- Pull down on this lever to flip up the shade.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **113 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/BLANK.png) **Rope**: 2 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 2 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)

---

## TLEV38.yaml - Mel Schlemming
**Objetivo:** Get one Schlemming into each house.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Mel can be programmed to walk, run, or stand still.
- If Mel bumps into something solid he will turn around.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 3 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **207 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 5 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 5 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 4 peça(s)

---

## TLEV39.yaml - Edison Alligator
**Objetivo:** Put the pinball into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Edison Alligator will happily eat mice or Mel Schlemming for dinner.
- Edison will toss any object that lands on his nose.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 9 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **260 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/BLANK.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 4 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 6 peça(s)

---

## TLEV40.yaml - Vacuum
**Objetivo:** Vacuum up both mice.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Plug the vacuum into an electric outlet and it will vacuum up anything within range.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **165 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/BLANK.png) **Cheese**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---



# 10. Catálogo de User Journeys (Fluxos de UX)

Este documento especifica os 14 diagramas de interação e fluxo de usuário ponta-a-ponta, extraídos do motor original. Ele estabelece as regras exatas das máquinas de estado da Interface Gráfica (UI) que a versão da Godot deve implementar.


Complete specification for all 14 user journeys in The Incredible Machine 2.
Cross-referenced with the original game manual (SierraChest walkthrough),
the Python reference editor (`tim2_editor/`), and reverse-engineered ANM/BMP assets.

## Journey Overview

| ID | Journey | Original Game | Python Editor | Standalone Script |
|----|---------|:---:|:---:|:---:|
| J01 | Sign-In Window | Yes | ❌ | `j01_signin.py` |
| J02 | Main Menu | Yes | ❌ | `j02_mainmenu.py` |
| J03 | Puzzle Select | Yes | ❌ | `j03_puzzle_select.py` |
| J04 | Parts Bin — Browse & Place | Yes | ✅ | `j04_parts_bin.py` |
| J05 | Part Handles — Flip/Stretch/Program/Delete | Yes | ❌ | `j05_part_handles.py` |
| J06 | Connections — Rope/Belt/Electrical | Yes | ✅ | `j06_connections.py` |
| J07 | Programmable Parts — 14 dialogs | Yes | ❌ | `j07_programmable.py` |
| J08 | Simulation — Start/Observe/Pause/Reset | Yes | ✅ | `j08_simulation.py` |
| J09 | Simulation — Solve Conditions | Yes | ✅ | `j09_solve.py` |
| J10 | Save & Load | Yes | ✅ | `j10_save_load.py` |
| J11 | Player Preferences | Yes | ❌ | `j11_preferences.py` |
| J12 | Music & Sound | Yes | ❌ | `j12_music_sound.py` |
| J13 | Hints & Info Dialogs | Yes | ❌ | `j13_hints_info.py` |
| J14 | Head-to-Head | Yes | ❌ | `j14_head_to_head.py` |

---

## J01 — Sign-In Window

![J01 UI](../../build/phase-3/bitmaps/SIGN_IN_f000.png)


### Screen Spec
- ANM: `SIGN_IN.ANM` (279×125 canvas)
- BMP: `SIGN_IN.BMP`
- Original features per manual:
  - Dark blue player name input field
  - Light blue player registry (all signed-in names)
  - Green help question mark button
  - Done button

### Interaction Flow
```
Window opens → type name → Enter/Add → name in registry
→ click name to select → Done → proceed to Main Menu
```

### States
| State | ANM State | Visual |
|-------|-----------|--------|
| Idle | 1 | Window visible, empty input |
| Editing | 2 | Cursor in name field |
| Selected | 3 | Name highlighted in registry |
| Done | 4 | Window closing |

### Test Script
- Asset checks: SIGN_IN.ANM exists, has valid Section C/B/D
- Behavioral: input parsing, registry management, selection
- Manual: `python3 scripts/phase-20/journeys/j01_signin.py --interactive`

---

## J02 — Main Menu

![J02 UI](../../build/phase-3/bitmaps/MAINMENU_f000.png)


### Screen Spec
- ANM: `MAINMENU.ANM` (672×377 canvas, 11 states, 116 frames)
- BMP: `MAINMENU.BMP`, `MAINBUTN.BMP`

### Button Layout (per manual)
| Row | Left | Center | Right |
|-----|------|--------|-------|
| Upper | Puzzle Play | Professor Tim's Workshop | Head-to-Head |
| Lower | Guided Tour | Sign-In | Tutorial |
| Right icons | Computer (preferences) | Stop (quit) | Question mark (help) |

### Interaction Flow
```
Main Menu → hover button → click → navigate to target screen
Computer icon → J11 Preferences
Stop icon → Quit dialog → Exit
```

### States
| State | Description |
|-------|-------------|
| idle | Menu visible, all buttons ready |
| hover_X | Button X highlighted |
| click_X | Navigate to target screen |
| quit | Exit game |

---

## J03 — Puzzle Select

![J03 UI](../../build/phase-3/bitmaps/MAINPUZL_f000.png)


### Screen Spec
- BMP: `PUZDISP.BMP`, `PUZTYPE1.BMP` through `PUZTYPE8.BMP`
- 206 levels across 7 categories

### Categories (per manual)
| Category | Level Prefix | Count |
|----------|-------------|-------|
| Tutorial | TLEV* | ~40 |
| Easy | ELEV* | 26 |
| Medium | MLEV* | 30 |
| Hard | HLEV* | 31 |
| Really Hard | RLEV* | 29 |
| Head-to-Head | HH* | 50 |
| Workshop (custom) | user-saved | varies |

### Interaction Flow
```
Select category → scroll puzzle list → click puzzle → LOAD
Light bulb icon: solved (on) / unsolved (off)
Double-click = quick load
```

---

## J04 — Parts Bin → Browse & Place

![J04 UI](../../build/phase-3/bitmaps/BINSOLVE_f000.png)


### Screen Spec
- ANM: `BINSOLVE.ANM` (8 states, 9 frames)
- BMP: `ICONS1-10.BMP`, `PARTSBIN.BMP`
- Data: `build/phase-9/part-name-catalog.json` (149 parts × 19 categories)

### Hotkeys (per manual)
| Key | Category |
|-----|----------|
| B | Balls |
| W | Walls |
| P | Pipes |
| I | Inclines |
| A | Arches |
| O | Pool Stuff |
| G | Gears & Belts |
| R | Ropes |
| F | Flames |
| E | Electrical |
| L | Lasers |
| M | Mouse Cage |
| C | Critters |

### Interaction Flow
```
Parts Bin visible → scroll categories → hover part → part name tooltip
→ click part → part attached to cursor → click canvas → part placed at grid snap
→ right-click existing part → duplicate copy
```

### In-Editor Status
- Catalog panel: ✅ Implemented (`tim2_editor/main.py:draw_catalog()`)
- Grid snap: ✅ (`16px grid`, `place_part()`)
- Hotkeys: 🟡 Not implemented
- Duplicate: 🟡 Not implemented
- Tooltips: 🟡 Not implemented

---

## J05 — Part Handles

![J05 UI](../../build/phase-3/bitmaps/BUTTONS_f000.png)


### Handle Types (per manual)
| Handle | Icon | Action |
|--------|------|--------|
| Recycle | Trash can | Remove part back to Parts Bin |
| Flip | Curved arrows | Rotate/flip part orientation |
| Size/Stretch | Double arrow | Click-drag to resize |
| Program | Computer | Open programming dialog (J07) |
| Info | Magnifying glass | Open info dialog (J13) |
| Solve | Checkered flag | Program solution condition (Workshop only) |
| Lock | Padlock | Lock part in position (Workshop only) |

### ANM Reference
- `HANDLES.ANM` (16 states, 108 frames, animated)
- `BUTTONS.ANM` (21 states, 49 frames)

### Interaction Flow
```
Part placed on canvas → cursor over part → handles appear as overlay
→ click handle → execute action
→ flip: rotate clockwise 90°/flip horizontal/flip vertical
→ stretch: click-drag to resize, click to set
→ recycle: remove part
→ program: open dialog window
→ info: open description window
```

---

## J06 — Connections

### Connection Types (per manual)
**Rope** (part type 10, steel cable type 76):
- Attaches to 16 part types: Teeter-Totter, Leaky Bucket, Lava Lamp, Pulley, Boat Cleat,
  Phazer, Mandrill Motor, Trans-Roto-Matic, Laundry Basket, Balloon, Tipsy Trailer,
  Roto-Trans-Converter, Bucket, Hot Air Balloon, Match-on-a-spring, Remote Control Bomb

**Belt** (part type 8):
- Attaches to 11 rotating part types: Large Gears, Small Gears, Pinwheel, Conveyor Belt,
  Mouse Motor, Generator, Electric Motor, Trans-Roto-Matic, Roto-Trans-Converter,
  Jack-in-the-Box, Mandrill Motor

**Electrical** (outlet connections):
- 5 power sources: Generator, Electric Switch & Outlet, Electrical Outlet,
  Solar Panel, Laser-Activated Plug

### Interaction Flow
```
Select Rope/Belt from Parts Bin → cursor shows line
→ click first part (anchor turns red) → drag to second part
→ line turns green when valid connection → click to attach
→ connection line drawn between parts (center-to-center)
```

### Part Struct Fields
- `connected_1`, `connected_2`: Part indices for rope/belt connections
- `outlet_plugged_1`, `outlet_plugged_2`: Part indices for electrical
- `belt_anchor_x/y`, `rope_1_anchor_x/y`, `rope_2_anchor_x/y`: Anchor positions

### In-Editor Status
- Connection line rendering: ✅ (`main.py:draw_part()` lines 330-337)
- Click-and-drag connection tool: ❌ Not implemented
- Red/green line color feedback: ❌ Not implemented

---

## J08 — Simulation → Run/Pause/Reset

![J08 UI](../../build/phase-3/bitmaps/MAINPIEC_f000.png)


### Game Loop (per godot-specification.md §1)
```
60 Hz tick rate
  Pass 0: advance state machines
  Pass 1: apply gravity
  Pass 2-3: AABB collision detection + response
  Pass 4-5: proximity interactions
  Pass 6-7: constraint enforcement (3 passes)
```

### Controls (per manual)
| Action | Trigger |
|--------|---------|
| Start | Click green flag (Parts Bin) |
| Stop/Pause | Click checkered flag |
| Reset | Click broom icon (remove unlocked parts) |
| Timeout | Auto-stop after ~10,000 ticks (if unsolved) |

### Visual Feedback
- Parts animate via ANM state machine (Section C → Section D bytecode)
- Moving parts update position each tick
- Collisions trigger state transitions + sound effects
- Goal Bar shows progress

### In-Editor Status
- Simulation loop: ✅ (`world.py:step()` 5 passes)
- Green flag / play toggle: ✅ (space bar, `toggle_preview()`)
- Reset on stop: ✅ (`world.reset()`)
- ANM rendering during sim: 🟡 (gray rectangles placeholder)
- Sound on collision: ❌ Not implemented

---

## J09 — Simulation → Solve Conditions

![J09 UI](../../build/phase-3/bitmaps/SOLVE_f000.png)


### Condition Types
| Type | Rect | Check |
|------|------|-------|
| Position | (x, y, w, h) | Part bbox overlaps target rect |
| Off-screen | (-1, -1, -1, -1) | Part outside viewport |
| Off-top | (-500, -2000, 1640, 2000) | Part above screen |
| Off-bottom | (-500, 400, 1640, 3000) | Part below screen |
| State-only | (0, 0, 0, 0) | part.state_counter == target_state |

### Solution Struct (per level file)
```
conditions_count: N
delay: ticks_before_end
conditions:
  - part_index: INT16LE
    part_state_1: UINT16LE
    part_state_2: UINT16LE
    part_count: UINT16LE
    rect: { x, y, width, height }
```

### Interaction Flow
```
Simulation runs → each tick: check all conditions
→ all met → delay_ticks → puzzle solved overlay
→ SOLVE.ANM victory animation
→ menu: Replay / Next Puzzle / Back to Select
```

### In-Editor Status
- Solution checker: ✅ (`solver.py`)
- Green target rects: ✅ (`main.py:draw()` lines 242-252)
- Victory overlay: ❌ SOLVE.ANM not integrated
- Victory menu: ❌ Not implemented

---

## J10 — Save & Load

![J10 UI](../../build/phase-3/bitmaps/LOADSAVE_f000.png)


### Actions (per manual)
| Action | Shortcut | Description |
|--------|----------|-------------|
| Save | Ctrl+S | Serialize level to YAML file |
| Load | Ctrl+L | Load YAML file, populate editor |
| New | N key | Clear editor, start empty level |

### Serialization Format
```
level_info: magic, title, goal, bg_color
environment: pressure, gravity, music_track
hints: count, entries
parts: fixed_count, moving_count, part_entries
solution: conditions_count, delay, conditions
```

### Fidelity Requirements
- All 48-byte part struct fields preserved
- Hex flags (`0xNNNN`) preserved
- Connections (connected_1/2, outlet_plugged_1/2) preserved
- Solution conditions preserved
- Float/int round-trip tolerance

### In-Editor Status
- Save: ✅ (`save_yaml()` → 269 lines of YAML output)
- Load: ✅ (`load_yaml()` → regex parser, all 206 levels)
- New: ✅ (`new_level()`)
- Shortcuts: ✅ (`Ctrl+S`, `Ctrl+L`, `N`)

---

## J11 — Player Preferences

### Toggles (per manual)
| Preference | Default | Effect |
|------------|---------|--------|
| Ambient Animation | ON | Parts wiggle/twinkle when idle |
| Scenery Displayed | ON | Background scenery visible |
| Background | ON | Wallpaper/tiles/color blocks |
| Info Handles | ON | Magnifying glass on part hover |
| Sound Effects | ON | Play sounds on collisions/actions |

### Storage
- JSON file in user data directory
- Keyed by player name (from J01 sign-in)
- Loaded on game start, saved on preference change

---

## J12 — Music & Sound

### Music System
- Tracks: IDs 1000–1023 (24 tracks)
- Format: FM synthesis via ADL.DRV (OPL2)
- Access: Click guitar icon on control panel

### Sound Effects
- FM synthesis: 14 patches in TIM2.SX (IDs < 300)
- Digital audio: 113 RAW files at 11025 Hz (IDs 3001–3754)
- Access via ANM Section D bytecode: `PLAY_SFX sound_id`

### Controls
| Control | Action |
|---------|--------|
| Music list | Scroll, click to select |
| Note button | Restart current track |
| Switch | Turn music on/off |
| POW button | Preview selected sound effect |
| Volume arrows | Increase/decrease volume |
| Done | Close panel |

---

## J13 — Hints & Info Dialogs

### Info Dialogs
- ANM: `INFO0.ANM` through `INFO148.ANM` (one per part type)
- Each displays: part name, description, usage tips
- Access: click magnifying glass handle on part OR click ? then click part
- Text source: `build/phase-9/part-name-catalog.json` description field

### Hints System
- ANM: `HINTLOCK.ANM` (4 states, 43 frames)
- Each level can have 0–5 hints
- Hint data: position (x, y), icon flip, text
- Access: click Hand icon on control panel → pointing hands appear → click to read

### Professor Help
- ANM: `PROFESOR.ANM` (329×138 canvas)
- Professor Tim provides contextual tips
- Triggered by tutorial and guided tour modes

---

## J14 — Head-to-Head Mode

![J14 UI](../../build/phase-3/bitmaps/MAINH2H_f000.png)


### Screen Spec
- ANM: `HEDTOHED.ANM` (639×399, 5 states, 21 frames)
- 50 head-to-head puzzles

### Gameplay
- Two players alternate turns placing parts
- Turn indicator shows current player
- Each player builds toward completing the puzzle
- First player to trigger solution wins
- Score tracking per puzzle

### In-Editor Status
- Not implemented in Python editor
- Standalone test script only

---

## Validation

- **Master runner**: `scripts/phase-20/01-validate-user-journeys.py`
- **Per-journey scripts**: `scripts/phase-20/journeys/j{NN}_{name}.py`
- **Logs**: `build/phase-20/logs/J{NN}_{timestamp}.log`
- **Report**: `build/phase-20/user-journey-report.json`

### Running Tests
```bash
# List all journeys
python3 scripts/phase-20/01-validate-user-journeys.py --list

# Run all headless
python3 scripts/phase-20/01-validate-user-journeys.py

# Run one interactively (with pygame window)
python3 scripts/phase-20/01-validate-user-journeys.py --interactive J04

# Run specific journey headless
python3 scripts/phase-20/01-validate-user-journeys.py --journey J08
```

---

## Sound & Animation Integration

Every user journey references specific sound effects and animation states.
The following table shows which journeys trigger audio and ANM playback:

### Sound References by Journey

| Journey | Sound Type | Sound IDs | Source |
|---------|-----------|-----------|--------|
| J01 Sign-In | — | — | No sounds in original |
| J02 Main Menu | UI click | 3000 (menu select) | MAINMENU ANM PLAY_SFX |
| J03 Puzzle Select | UI click, solved jingle | 3000, custom | PUZLTYPE BMP |
| J04 Parts Bin | Part pickup/place | 5, 3005 (generic pickup) | BINSOLVE ANM |
| J05 Part Handles | Flip, stretch click | per-part sounds | BUTTONS/HANDLES ANM |
| J06 Connections | Rope snap, belt attach | 3006 (click) | Connection validation |
| J07 Programmable | Open/close dialog | 3000 (UI) | INFO ANMs |
| J08 Simulation | Collision sounds | per-part sounds (61 unique IDs) | PLAY_SFX in ANM bytecode |
| J09 Solve | Victory fanfare | 3000, SOLVE sequence | SOLVE ANM |
| J10 Save/Load | Disk write | — | OS-level |
| J11 Preferences | Toggle click | 3000 | UI feedback |
| J12 Music & Sound | Track playback, SFX preview | 1000–1023 (music), 3001–3754 (SFX) | ADL.DRV + RAW files |
| J13 Hints | Hint reveal | 3000 | HINTLOCK ANM |
| J14 Head-to-Head | Turn change, victory | 3000, custom | HEDTOHED ANM |

### Animation States by Journey

| Journey | ANM | States Used | Frame Range |
|---------|-----|-------------|-------------|
| J01 Sign-In | SIGN_IN | 2 (editing), 3 (selected), 5 (idle) | 0–7 |
| J02 Main Menu | MAINMENU | 1–11 (11 states) | 0–460 (animated) |
| J03 Puzzle Select | — | (static BMPs) | PUZDISP, PUZTYPE1-8 |
| J04 Parts Bin | BINSOLVE | 1–8 | 0–8 |
| J05 Part Handles | HANDLES, BUTTONS | 1–16 (HANDLES), 1–21 (BUTTONS) | 0–107, 0–48 |
| J06 Connections | — | Dynamic (line drawing) | Draw via DRAW_LINE opcode |
| J07 Programmable | INFO0–INFO148 | 1 (info display) | 1–72 (varies per part) |
| J08 Simulation | PART0–PART261 | All part states (89 unique IDs) | 0–189 (varies) |
| J09 Solve | SOLVE | 1 (solved overlay) | 0–N |
| J10 Save/Load | LOADSAVE | 1,3,5 | 0–10 |
| J11 Preferences | — | (button highlights) | — |
| J12 Music & Sound | — | Track list, volume bar | Draw via DRAW_RECT |
| J13 Hints | HINTLOCK | 1–4 | 0–216 (animated) |
| J14 Head-to-Head | HEDTOHED | 1–5 | 0–20 |

### Validation Requirements for Sounds

Every journey test script that references sounds must:
1. Check that the sound ID exists in `behaviors.json` per-part `sounds[]`
2. Verify WAV file exists: `build/phase-6/raw-wav/SX_{ID}_11025.wav`
3. In interactive mode: play the sound when the associated action occurs
4. Log every sound triggered with sound_id and WAV path

### Validation Requirements for Animations

Every journey test script that references ANM states must:
1. Check that the ANM JSON exists in `build/phase-4/anm/`
2. Verify that the state ID exists in ANM Section C
3. Verify frame metadata exists in Section B
4. Verify PNG files exist for each DRAW_BMP sprite reference
5. Log state→frame→sprite resolutions

### Animation Frame Timing (Standard 60 Hz)

| Timing Type | Description |
|-------------|-------------|
| Static ANM | Section A empty — frame changes only on state transition |
| Animated ANM | Section A has durations — frames advance per tick |
| Idle animation | Parts wiggle/twinkle when ambient animation is ON (preference) |
| State transition | Instant frame change when state_counter changes |
| Sub-state countdown | Temporary state with timed reversion (offsets 0xAE–0xB0) |

## See Also

- `docs/game-architecture-specification.md` §1 — Screen flow map
- `docs/godot-specification.md` §1 — Game loop
- `docs/state-machine-specification.md` — Full state machine reference
- `docs/validation-directives.md` — Validation architecture and patterns
- `tim2_editor/main.py` — Python editor reference implementation
- `tim2_editor/game.py` — Game mode
- `tim2_editor/sandbox.py` — Interactive part viewer
- `scripts/phase-20/journeys/` — Per-journey test scripts


# 11. Editor de Níveis Standalone (Godot 4.6+)

O Editor de Fases é o pilar da versão "Clean Room". O objetivo principal desta arquitetura é portar a flexibilidade do protótipo em Python (`tim2_editor`) para a engine da Godot 4.6+, permitindo aos jogadores construir, salvar, carregar e testar as engenhocas *sem depender do jogo base compilado*.

## Visão Geral do Layout

A UI do editor não deve sobrepor o viewport principal para manter a legibilidade. Ela é dividida nos seguintes containers de controle:

![Editor UI Original Reference](../../build/phase-3/bitmaps/MAINEDIT_f000.png)

1. **Toolbar Superior (`MarginContainer > HBoxContainer`):**
   - Botões globais de ação (Salvar, Carregar, Limpar, Testar).
2. **Viewport Central (`SubViewportContainer > SubViewport > Node2D`):**
   - A área "canvas" de jogo. Suporta resolução base de 560x377 escalada.
   - Possui lógica isolada para zoom (`Mouse Wheel`) e translação da câmera (`Middle Mouse Drag`).
3. **Painel de Catálogo Direito (`PanelContainer > ScrollContainer > VBoxContainer`):**
   - Apresenta as 149 peças + cenário, agrupadas por Categoria.
   - Ícones extraídos dos primeiros frames (`PART{N}_f000.png`).
4. **Overlay Dinâmico (Handles Overlay):**
   - Renderiza alças de manipulação contextuais quando o jogador clica numa peça na viewport.

---

## Estrutura da Árvore de Nós (Scene Tree)

O `LevelEditor.tscn` deve ser instanciado como uma hierarquia desacoplada:

```text
LevelEditor (Control)
│
├── UI_CanvasLayer (CanvasLayer)
│   ├── TopMenu (HBoxContainer)
│   │   ├── BtnLoad (Button)
│   │   ├── BtnSave (Button)
│   │   ├── BtnPlay (Button)
│   │   └── EnvSettingsDialog (PopupPanel)
│   │
│   ├── SideCatalog (PanelContainer)
│   │   └── Scroll (ScrollContainer)
│   │       └── PartGrid (GridContainer)
│   │           ├── PartBtn0 (TextureButton)
│   │           └── PartBtnN (TextureButton)
│   │
│   └── ModeIndicator (Label)
│
└── GameSpace (SubViewportContainer)
    └── LevelViewport (SubViewport)
        ├── Camera2D (Handles Zoom/Pan)
        ├── Background (ColorRect/TextureRect)
        ├── GridOverlay (Node2D - custom _draw)
        └── PartContainer (Node2D)
            ├── PlacedPartA (Area2D + Sprite2D)
            └── PlacedPartB (Area2D + Sprite2D)
```

---

## Máquina de Estados da Ferramenta (Tool Modes)

A classe `EditorController.gd` intercepta a entrada de mouse e teclado em `_unhandled_input(event)`. Apenas um modo fica ativo por vez.

### 1. `MODE_PLACE` (Atalho: P)
- **Ação:** Instancia uma nova peça na cena.
- **Fluxo:** O jogador clica no `PartBtn0` do catálogo. O editor entra em `MODE_PLACE`. O cursor exibe uma versão transparente/fantasma do ícone (`modulate = Color(1, 1, 1, 0.5)`). Ao clicar no *GameSpace*, o script instancia a cena respectiva atrelada à grade (*Snap-to-Grid* em 16px).

### 2. `MODE_SELECT` (Atalho: S)
- **Ação:** Manipular uma peça existente.
- **Fluxo:** Clicar num nó Area2D dentro do `PartContainer` ativa seu destaque.
- **Handles (Alças):**
  - ![Flip Handle](../../build/phase-3/bitmaps/BUTTONS_f000.png) **Girar/Inverter (Flip):** Rotaciona a peça ou espelha o eixo X/Y (alterando os `flags`).
  - ![Delete Handle](../../build/phase-3/bitmaps/BUTTONS_f001.png) **Deletar:** Remove o nó da memória com `queue_free()`.
  - **Programar:** Abre o pop-up modal para definir comportamentos avançados.

### 3. `MODE_CONNECT` (Atalho: C)
- **Ação:** Cria lógicas físicas entre duas peças.
- **Fluxo:** Essencial para Cordas, Correias e Eletricidade.
  - Clique inicial no "Nó de Ancoragem" da Peça A.
  - A Engine traça uma `Line2D` elástica seguindo a posição global do cursor do Mouse.
  - O cursor brilha "Verde" se passar por cima de uma âncora válida (ex: engrenagem se for correia), ou "Vermelho" caso seja inválido.
  - Clique secundário na Peça B finaliza o vínculo e registra os IDs matemáticos (`connected_1`, `connected_2`).

### 4. `MODE_PREVIEW` (Atalho: Espaço)
- **Ação:** Testa o código de física real da fase.
- **Fluxo:** Ao clicar em Play, o editor serializa toda a fase atual e desativa a UI. O sistema instancia o `PhysicsSolver` de 60Hz. Se o usuário clicar em "Stop", a fase é destruída e reconstruída com os dados de antes do Play para garantir estado imutável.

---

## Fluxos e Jornadas Restritas de Edição (User Journeys)

### J07 - Peças Programáveis (Program Dialogs)
Algumas peças não são estáticas. O editor precisa injetar caixas de diálogo modais exclusivas quando o botão "Programar" é acionado na UI.
- **Laser:** Definir o canal RGB de emissão.
- **Balão de Fala:** Configurar a String que aparecerá quando disparado.
- **Interruptores:** Definir qual o valor elétrico que propaga na ativação.

### J10 - Save & Load Serializado (YAML)
O motor nativo da Godot possui `ResourceSaver`, porém, a especificação dita que os dados do puzzle devem estar totalmente dissociados da Engine (para possibilitar modding aberto e validação limpa via Python).
- O editor processa um parser YAML nativo (`LevelSerializer.gd`).
- Ao acionar "Save", o construtor formata os dicionários, as condições de vitória (`SolutionCondition`), as matrizes de `fixed_parts` e joga um arquivo `nome.yaml` usando o `FileAccess`.

---

## Funcionalidades QoL (Quality of Life)

O editor moderno ultrapassa o limite clássico de 1994, oferecendo:
1. **Histórico de Ações (Undo/Redo):** Usa a classe embutida `UndoRedo` da Godot, mapeando o instanciamento/destruição de peças na memória.
2. **Seleção em Massa (Box Select):** O botão esquerdo arrastado em área neutra cria um Box. Múltiplas peças podem ser arrastadas e apagadas de uma só vez.
3. **Menu "Goal & Hints":** Modal (`PopupPanel`) focado para o Level Designer escrever a dica de vitória ("Goal") e preencher os nós esféricos vermelhos que o jogador poderá clicar no futuro para obter a tradução livre da dica.

## Mapeamento Avançado de Casos de Uso e Resolução de Ambiguidades

Durante a arquitetura do editor, diversas ambiguidades (*edge cases*) emergem na interação do usuário. Abaixo, detalhamos cada Caso de Uso com suas respectivas resoluções de ambiguidade (User Journeys expandidas).

### UC01: Iniciar Novo Nível (New Level)
- **Ambiguidade:** O que acontece se o jogador tiver trabalho não salvo ao clicar em "Novo"?
- **Resolução (User Journey):** 
  1. O usuário clica em "Novo" (ou pressiona `N`).
  2. A engine verifica o sinalizador interno `is_dirty`. Se verdadeiro, um modal de aviso surge no meio da tela: *"Você tem alterações não salvas. Deseja descartá-las?"*
  3. Ao confirmar, a `SceneTree` do `PartContainer` é purgada (`queue_free` em todos os nós) e as configurações globais (gravidade, pressão) retornam aos valores *default*. O sinalizador `is_dirty` volta a `false`.

### UC02: Adicionar e Posicionar Peça (Place Part)
- **Ambiguidade:** Como o usuário sabe se o local de drop é válido antes de clicar? O que acontece se o mouse sair do GameSpace?
- **Resolução (User Journey):**
  1. O usuário clica na peça desejada no Catálogo Lateral. O cursor do mouse passa a exibir um "fantasma" transparente da peça.
  2. Ao mover o mouse pela viewport, a peça fantasma segue a ancoragem do *snap-to-grid* (16x16 pixels).
  3. Um shader/código de colisão roda em tempo real: se a *Bounding Box* da peça fantasma sobrepor qualquer outra peça existente, o fantasma fica destacado na cor **Vermelha** (inválido). Se estiver livre, fica em sua cor normal.
  4. Tentar clicar com o fantasma vermelho gera um feedback sonoro de erro.
  5. Clicar fora dos limites do `SubViewport` (ex: em cima do menu) ou clicar com o Botão Direito cancela a ação `MODE_PLACE` e devolve o cursor ao estado normal.

### UC03: Estabelecer Vínculo Físico (Connect Parts)
- **Ambiguidade:** O que acontece se o usuário tentar ligar uma Corda a um pino Elétrico? E como cancelar um traçado pela metade?
- **Resolução (User Journey):**
  1. O usuário ativa `MODE_CONNECT` e clica numa âncora mecânica (Peça A). Uma `Line2D` elástica começa a seguir a posição do mouse.
  2. O sistema filtra imediatamente os alvos válidos em tela: como a Peça A é mecânica (Motor), apenas as âncoras mecânicas (Engrenagens/Polias) ganham um leve brilho. 
  3. Se o cursor passar por cima de um pino elétrico, a linha fica **Vermelha** e um "X" aparece, bloqueando o clique.
  4. Se o usuário pressionar `ESC` ou clicar com o **Botão Direito**, o vínculo em andamento é destruído sumariamente e a ferramenta reseta.
  5. Um clique válido numa âncora verde finaliza a linha geométrica e consolida o ID matemático.

### UC04: Programar Comportamento Específico (Program Part)
- **Ambiguidade:** Como o usuário descobre visualmente que uma peça *é* programável sem ter que sair testando todas? E se ele cancelar a edição?
- **Resolução (User Journey):**
  1. No modo `MODE_SELECT`, ao passar o mouse (*hover*) sobre uma peça programável (ex: *Laser* ou *Interruptor*), um pequeno ícone de "Computador" (Handle de Programação) aparece flutuando anexado a ela.
  2. Ao clicar nesse ícone (ou com o Botão Direito > Programar), a simulação é pausada e um Modal pop-up de configuração se abre sobrepondo o editor.
  3. O usuário altera os parâmetros (ex: troca o laser para Vermelho).
  4. Se clicar em **Cancelar** ou no **[X]**, nenhuma modificação é feita nos *Flags* da peça. Apenas clicar em **Confirmar/Aplicar** salva as máscaras de bits (`flags_1`, `flags_2`) no banco de dados da peça na `SceneTree`.

### UC05: Definir Condições de Vitória (Set Win Condition)
- **Ambiguidade:** É possível ter múltiplas condições de vitória? Como visualizá-las e deletá-las no canvas?
- **Resolução (User Journey):**
  1. O usuário clica no menu superior "Goal/Win Setup".
  2. O catálogo lateral é temporariamente substituído pela aba de *Goals*.
  3. O usuário pode adicionar múltiplas condições clicando em "Add Target Rect". 
  4. No *GameSpace*, polígonos semi-transparentes verdes aparecem. Eles possuem *Handles* de arrastar as bordas (stretch) para definir a zona exata de alvo.
  5. Cada polígono possui um botão flutuante **[X]** no seu canto superior direito. Ao clicar, a condição é excluída, resolvendo de forma elegante a gestão visual de requisitos de vitória.

### UC06 & UC07: Testar Nível e Retornar (Preview / Play / Stop)
- **Ambiguidade:** Quando o teste rola, bombas explodem e cordas partem. Como o jogo retorna ao estado perfeitamente inicial após parar o teste?
- **Resolução (User Journey):**
  1. O usuário clica em "Play" (Espaço). Imediatamente, a engine *serializa* a cena inteira em um buffer temporário em memória RAM (`temp_state.yaml`).
  2. O `PhysicsSolver` assume o controle. O jogo simula a 60Hz. Objetos são consumidos e posições são alteradas agressivamente.
  3. Ao detectar falha no plano ou concluir o teste, o usuário clica em "Stop" (ou aperta Espaço).
  4. O editor purga e deleta 100% da simulação atual da memória RAM.
  5. Ele executa um `Load` silencioso e instantâneo a partir do `temp_state.yaml`. Resultado: a tela pisca e tudo volta exatamente ao estado pixel-perfect de antes do "Play".

### UC08: Manipulação em Massa (Box Select & Mover Cluster)
- **Ambiguidade:** O *Box Select* serve apenas para deletar, ou posso mover um grupo inteiro de engrenagens montadas sem quebrar as conexões delas?
- **Resolução (User Journey):**
  1. O usuário arrasta o clique esquerdo em uma área vazia criando um retângulo de seleção.
  2. Todas as peças capturadas ficam com um contorno em realce (Seleção Ativa). As linhas de correia/corda interconectando este grupo ficam visíveis.
  3. **Mover:** Ao clicar e segurar qualquer peça dentro dessa área, o usuário arrasta *todo o cluster* em uníssono. A engine verifica se *nenhuma* das peças vai colidir na nova posição de *snap-to-grid*. Se o local couber todas, o cluster é movido e as coordenadas de tudo se atualizam. Se alguma peça colidir com uma externa ao cluster, a silhueta inteira do cluster fica Vermelha e impede o drop.
  4. **Deletar:** Apertar `Delete` apaga todas as peças do cluster de uma vez e gera **apenas 1 passo** no sistema de *UndoRedo*.

---

## Questões em Aberto e Definições Futuras

Algumas dúvidas de arquitetura não cobertas pelas User Journeys básicas foram levantadas e respondidas diretamente cruzando os dados da engenharia reversa do formato original:

### Q1. Diferenciação de Inventário (Parts Bin) vs Cenário Fixo
- **A Dúvida:** Quando estou criando um nível novo, como eu digo para a engine que a "Corda" que acabei de colocar deve ir para o inventário do jogador (Parts Bin) ao invés de aparecer travada no cenário?
- **Resposta Baseada no Clean Room (YAML):** A extração do *timgres* e os YAMLs de fase (`docs/user-journey-specification.md`) revelam que o comportamento da peça depende da sua máscara de bits. O `flag_1` contendo `0x0040` dita que a peça está *Locked* (travada).
- **Diretriz para a Godot:** O Editor deve possuir um botão de "Cadeado" no painel de propriedades ou um Handle de *Lock/Unlock* na peça. Se destrancada (sem o `0x0040`), a peça não aparece na tela na hora de jogar, mas sim contabilizada dentro do Parts Bin do jogador.

### Q2. Ordem de Renderização (Z-Indexing Overlap)
- **A Dúvida:** Se o Level Designer colocar uma parede de cenário (ID 150) exatamente na mesma coordenada de uma Bola de Boliche (ID 4), quem renderiza na frente? A engine original dependia da ordem de *draw* (array order).
- **Diretriz para a Godot:** Para resolver definitivamente essa ambiguidade e evitar o *z-fighting*, o `PartContainer` deve atribuir ordens rigorosas via `CanvasItem.z_index`:
  - `z_index = -1` para Cenários/Scenery (IDs >= 150).
  - `z_index = 0` para peças estruturais fixas (Paredes, Canos).
  - `z_index = 1` para peças ativas, molas e correias.
  - `z_index = 2` para partículas, explosões e *overlays* de laser.

### Q3. Limite de Vínculos Geométricos
- **A Dúvida:** O usuário pode puxar 3 ou 4 cordas a partir de uma mesma roldana usando o UC03?
- **Resposta Baseada no Clean Room:** **Não.** O struct binário original possui apenas 2 ponteiros para conexões mecânicas (`connected_1` e `connected_2`). A interface da Godot deve bloquear a tentativa de criar um 3º vínculo mecânico numa mesma peça, exibindo o cursor vermelho de erro.

### Q4. Loop Infinito na Simulação
- **A Dúvida:** Se o Level Designer configurar uma máquina de moto-contínuo perfeita e apertar *Play* (UC06), a simulação rodará para sempre sem atingir o objetivo. O editor corre o risco de travar ou estourar memória se deixado ali?
- **Resposta Baseada no Clean Room:** Conforme catalogado no `user-journey-specification.md` (J08), o motor tem um limiar.
- **Diretriz para a Godot:** O `PhysicsSolver` do editor deve manter um contador global de *ticks*. Ao atingir `10.000 ticks` lógicos (~2.7 minutos de simulação) sem acionar o Win Condition, a engine deve disparar um Auto-Stop informando o *Timeout* da fase.

---

## Roadmap Ágil de Implementação (14 Dias)

Para orientar a equipe de Engenharia (Track B) a desenvolver este editor partindo da "Baixa Interdependência" até a complexidade máxima, a implementação foi dividida em um Sprint de 6 Fases (14 dias):

### Phase 1: Fundação & Câmera (Dias 1-2)
**Objetivo:** Ter um ambiente 2D funcional para testes de navegação.
- **Entregáveis:** Setup do `LevelEditor.tscn`, `CanvasLayer` (UI), `SubViewport` (GameSpace), Controle de Câmera (Zoom/Pan) e Grid de 16x16.
- **Leitura Obrigatória:** *Seção Estrutura da Árvore de Nós*.

### Phase 2: Interface e Dicionários (Dias 3-4)
**Objetivo:** UI conectada a dados dinâmicos.
- **Entregáveis:** Painel Lateral (Catálogo) fazendo parse do `part-name-catalog.json`. Geração de 149 `TextureButton`s iterativos.
- **Leitura Obrigatória:** `build/phase-9/part-name-catalog.json` e `08_detailed_parts_catalog.md`.

### Phase 3: Ferramentas Básicas (Dias 5-7)
**Objetivo:** O usuário pode colocar fantasmas das peças no grid, selecioná-las e apagá-las.
- **Entregáveis:** Ferramenta `MODE_PLACE` (UC02) com validação visual de AABB overlap. Ferramenta `MODE_SELECT` (UC08) com Box Select e Delete.
- **Leitura Obrigatória:** *Resoluções de Ambiguidades de Overlap para UC02 e UC08*.

### Phase 4: Memória & Serialização (Dias 8-10)
**Objetivo:** Exportar/Importar as edições voláteis da tela para um `.YAML`.
- **Entregáveis:** Módulo `LevelSerializer.gd`. Salvar (Export) e Carregar (Import) nativo usando `FileAccess`.
- **Leitura Obrigatória:** `build/phase-5/yaml/ELEV1.yaml`.

### Phase 5: Conexões Físicas e Win States (Dias 11-12)
**Objetivo:** Interações geométricas e Lógica de Vitória.
- **Entregáveis:** Ferramenta `MODE_CONNECT` (UC03) com nós `Line2D` elásticos bloqueando ligações inválidas. Painel de Goal (UC05) com Target Rects verdes arrastáveis.
- **Leitura Obrigatória:** *Questões Abertas Q3: Limites geómetricos* e Jornada J06.

### Phase 6: Integração Backend & Play (Dias 13-14)
**Objetivo:** Handover hermético para o motor de jogo.
- **Entregáveis:** Botão **Play** (UC06) que salva um `temp_state.yaml` e despacha o `PhysicsSolver` de 60Hz. Botão **Stop** (UC07) que restaura silenciosamente o estado. Temporizador de *Timeout* de 10.000 ticks.
- **Leitura Obrigatória:** `04_physics_engine.md` e *Q4. Loop infinito e regras de reset*.


# 12. Guia de Produção de Assets (Arte e Áudio)

Este documento é o manual definitivo para os Artistas (Pixel Art/2D) e Sound Designers responsáveis por criar a identidade visual e sonora da versão "Remake" do motor. 

Como a arquitetura "Clean Room" dita que o código de simulação (`backend`) é **matematicamente idêntico ao jogo de 1994**, os novos assets de arte e áudio operam como uma "skin" sobre a física. Eles não podem alterar o comportamento do jogo.

---

## 1. A Regra de Ouro: A Arte Serve à Física

> [!WARNING]
> Nunca modifique o *hitbox* (área de colisão matemática) de uma peça para acomodar um novo desenho. O seu desenho deve se acomodar ao hitbox!

Se a "Bola de Boliche" original possuía um raio de colisão rígido de 16px, a sua nova e ultra-detalhada bola de boliche pode ser renderizada com um sprite de 32x32px, mas a física continuará tratando-a como tendo raio de 16px. Se você desenhar uma bola gigantesca de 64x64px num arquivo `.PNG` com centro 16, ela vai "atravessar" as paredes visualmente.

**Onde consultar as medidas exatas:**
- A base de dados principal é `docs/parts/`. 
- Toda peça possui uma tabela informando a dimensão em *pixels* (`sprite_w`, `sprite_h`). Use essas dimensões como o limite máximo do seu canvas.

---

## 2. Guia de Estilo (Pixel Art Moderna)

Para afastar o visual da paleta de 256-cores de 1994 sem perder o carisma, o guia estético dita:

### 2.1. Direção Estética
- **Slapstick Comedy & Steampunk:** As engenhocas devem parecer saídas de um desenho animado do *Pica-Pau* ou *Tom & Jerry*, cruzado com máquinas a vapor extravagantes.
- **Formas e Silhuetas:** A legibilidade imediata é mais importante do que a textura. O jogador não pode confundir um dínamo com uma torradeira.

### 2.2. Restrições Técnicas de Imagem
- **Formato:** `.PNG` (fundo estritamente transparente via Alpha Channel).
- **Cor:** 32-bits (RGBA). Não há restrição de paleta, mas recomenda-se limitar as cores e focar no contraste (cel-shading ou iluminação direcional unificada) para evitar poluição visual nas fases mais caóticas.
- **Sombras Padrão:** Não crie sombras diretas (drop shadows) projetadas nos sprites de peças móveis! A engine da Godot aplicará shaders de oclusão e drop-shadow dinâmicos dependendo da iluminação da fase.

### 2.3. Alinhamento de Grade (Grid Snap)
A engine opera numa **grade base de 16x16 pixels**. 
Elementos que se encaixam na estrutura (como paredes, canos e esteiras) precisam ter *tiles* com arestas limpas (seamless tiles) que se alinhem perfeitamente nesses múltiplos (ex: 16x16, 32x32, 64x16).

---

## 3. Guia de Animação (Frame Sync)

> [!IMPORTANT]
> A quantidade de *frames* (quadros) por animação **não é flexível**.

O antigo motor controlava as animações via máquinas de estado finitas (`.ANM`). O `state_counter` do backend roda a 60Hz.

- Se a tabela `docs/parts/part-004-balloon.md` diz que a transição de estado de explosão ("Burst") da bexiga dura **8 frames**, a sua nova animação precisa ser entregue em um *Sprite Sheet* contendo **exatamente 8 quadros**.
- Se você criar 12 quadros para deixar mais fluído, os 4 últimos quadros nunca serão tocados, e a peça já estará morta na engine física.

**Formato de Entrega de Sprites:**
Recomendado usar *Sprite Sheets* de linha única (eixo horizontal) ordenados por estado.
O *pivot/anchor* das imagens deve ser especificado no centro lógico.

---

## 4. Guia de Engenharia de Áudio (SFX e Música)

### 4.1. Música de Fundo
- **Formato e Qualidade:** `.OGG` ou `.WAV` (44.1kHz / 48kHz, 16-bit, Stereo). Substituindo o antigo sistema MIDI/OPL2 FM (11kHz).
- **Tonalidade:** As músicas precisam ter loops ininterruptos (*seamless looping*). Estilos recomendados vão do "Jazz Sintético" ao "Reggae Eletrônico". Devem ficar no fundo e não irritar, visto que os jogadores passarão horas na mesma tela pensando num quebra-cabeça.

### 4.2. Efeitos Sonoros (SFX) Reativos
- **Sem bloqueios (Non-blocking):** A física rege o jogo. Um som não pode ditar o atraso de uma colisão.
- O *AudioDispatcher* despacha eventos sonoros baseados em colisões. 
- **Sobreposição (Concurrency):** Você precisa criar áudios curtos, secos e de forte "ataque". Se 15 bolas de boliche quicarem simultaneamente, os ecos longos se acumularão e estourarão as caixas de som do jogador. Se um som exigir decaimento (ex: sino grande), certifique-se de que a Godot utilize pools de áudio rotativos ou reduza os decaimentos do arquivo `.WAV`.

---

## 5. Diretrizes do Design de Níveis (UGC e YAML)

Se novos Level Designers forem contratados para adicionar desafios além dos 206 originais:
1. Trabalhem primeiramente no **Godot Sandbox Editor**. 
2. As peças devem ser restritas àquelas já catalogadas em `build/phase-9/part-name-catalog.json`.
3. Evitem cenários que dependem de saltos milimétricos interconectados em redes de 20 peças; o hardware dos anos 90 permitia saltos por arredondamento impreciso que nós evitamos no remake (devido ao fix-point moderno). Confiem mais na lógica e em conectores de eletricidade/cordas do que em rebotes absurdos.


