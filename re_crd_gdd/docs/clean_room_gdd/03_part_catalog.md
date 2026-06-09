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

## Sistema de Máquina de Estados e Interação (SOLVE.RES)

Diferente de engines modernas onde cada peça tem scripts de colisão customizados, no TIM2 as interações ocorrem através de uma arquitetura estrita de Máquina de Estados. De acordo com a engenharia reversa do formato ANM e do motor de física, existem quatro conceitos interligados que regem isso:

1. **`state_counter` (Física Interna):** Um contador numérico incrementado automaticamente a cada *tick* (60 Hz) pelo motor do jogo. Ele rege timers, atrasos (como o pavio de uma dinamite) e ciclos de animação.
2. **`current_state` (Validação):** Uma cópia ou espelho do `state_counter`, utilizada para checar condições de vitória da fase ("Solution") e buscar os estados no ANM.
3. **`state_id` (Renderização ANM):** Encontrado na "Seção C" do formato `.ANM` (timgres). Ele correlaciona o estado lógico de uma peça a um `first_frame_id`, que aponta qual quadro exato de sprite desenhar na tela e se a peça é ou não animada nesse estado.
4. **Pares de Gatilho (SOLVE.RES):** A tabela de colisão global (`build/phase-16/solve-decoded.json`). Quando duas peças se encostam, o jogo cruza os dados:
   `{self: state_counter_A, other: state_counter_B} => anm_state_override`

### A Resolução de Colisão
Ao colidir, a *engine* lê os `state_counter`s de ambas as peças e busca um gatilho válido no SOLVE.RES:
* Se der *match*, o `state_counter` da peça sofre um *override* instantâneo para o valor de `anm_state` definido na tabela. Isso força a peça a pular visualmente para um novo `state_id` no ANM e começar uma nova física.
* Em alguns casos (`anm_state` nulo na tabela), a peça assume que o estado de animação atual flui diretamente do gatilho (`self`).
* Por fim, existem dezenas de "Estados Órfãos" no arquivo ANM que o SOLVE.RES nunca chama; eles atuam puramente como frames de transição em animações contínuas impulsionadas pelo avanço livre do `state_counter`.

### Dinâmica do Ciclo de Vida: Início, Transições e Sprites

Para que uma peça ganhe vida de forma determinística, seu comportamento depende do seu estágio na simulação:

1. **Estado Inicial:** 
   Quando o nível é carregado (ou a simulação inicia ao apertar *Play*), cada peça recebe um `state_counter` inicial. Na grande maioria das peças, o valor é cravado em **0** (o estado "Padrão/Desligado"). Algumas peças específicas herdam estados iniciais predefinidos gravados no cabeçalho do arquivo `.LEV` ou definidos pelo jogador no editor (ex: interruptores pré-ligados, canhões invertidos, gravidade do balão).

2. **O Que Ocasiona Cada Transição?**
   O `state_counter` avança por três gatilhos motores distintos:
   * **Colisões Físicas (SOLVE.RES):** O gatilho mestre. A sobreposição exata de duas caixas delimitadoras (*hitboxes*) faz a engine buscar as regras na tabela (ex: Laser toca no Balão $\Rightarrow$ estado transita para "Estourando").
   * **Avanço Temporal (Tick Loop):** O motor a 60 Hz possui um loop incondicional que auto-incrementa o `state_counter` se a peça tiver limites superiores definidos. Isso causa ciclos de animações contínuas (ex: moinhos girando infinitamente) ou atuam como *timers* de atraso (ex: a chama sobe pelo pavio da dinamite tick a tick até o limite de explosão).
   * **Estímulos Lógicos/Mecânicos:** Peças ligadas a redes elétricas (fios) ou mecânicas (cordas, correias, engrenagens) sofrem transições de estado remotamente quando o torque ou a energia do sistema muda (ex: a correia transmite força e altera o estado das polias atreladas).

3. **Os Sprites de Cada Estado:**
   No motor original, um sprite nunca é chamado "manualmente"; ele é um reflexo submisso do estado através das Seções do arquivo `.ANM`:
   * A **Seção C** do formato cruza a variável global com o design visual: ela diz "O estado `2` corresponde ao conjunto de frames X".
   * A **Seção B** define o tamanho, largura, altura e o deslocamento de tela desses frames.
   * A **Seção D** contém as cores em pixel art puras.
   * **No Clean Room (Godot):** A equipe de desenvolvimento traduzirá essa cadeia complexa para um modelo limpo. Cada peça utilizará um `AnimatedSprite2D` (ou `AnimationPlayer`) que conterá animações nomeadas exatamente como os IDs lógicos (ex: `"state_0"`, `"state_1"`, `"state_2"`). O único papel do script de renderização da Godot será escutar as alterações da variável física `state_counter` e dar um simples `.play("state_" + str(state_counter))`.

## O Papel do Design Limpo (Clean Room)

Ao implementar cada peça, desenvolvedores da Godot devem consultar **exclusivamente** os dados da pasta `docs/parts/`, cruzando sempre a lógica com a especificação canônica em `tim2_specs/state-machine-specification.md`.
Nós não portamos código de C sujo para GDScript. O correto é traduzir a semântica: programamos o loop de 60 Hz avançando o `state_counter` e deixamos as reações de colisão buscarem o novo estado através de uma cópia da tabela SOLVE.RES estática, mantendo o determinismo 100% idêntico ao jogo de 1993.
