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
