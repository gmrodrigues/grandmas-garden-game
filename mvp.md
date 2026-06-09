Para validar a arquitetura isolada, a ponte GDExtension e o rigor matemático do loop de 60Hz, o MVP (Minimum Viable Product) não exige a implementação das 278 peças descritas no GDD. O objetivo desta etapa é construir o **"Hello World" de Rube Goldberg**: um único tabuleiro fechado que force a execução simultânea dos 7 passes da simulação.

Trabalhando no Antigravity para o código em Zig e no Godot para o frontend, o escopo desse MVP deve ser cirurgicamente contido às seguintes entregas:

### Marcos (Milestones)

| Fase | Descrição | Estado |
|------|-----------|--------|
| A | Levels JSON + PartFactory + SolutionCondition | ✅ Concluído |
| B | UI minimal (SimUI.gd, botões, speed slider) | ✅ Concluído |
| C | Split monolith Main.gd → Part + Board + PhysicsEngine + ChainManager | ✅ Concluído |
| D | 60Hz fixed tick + determinism test (--determinism-test, 50-run PASS) | ✅ Concluído |
| E | chain_script data-driven (7 rules, 0 hardcoded part refs) | ✅ Concluído |
| F | Áudio (AudioManager FM/PCM dispatch) | ⏳ Pendente |
| G | Level editor com overlay de simulação isolado (SubViewport) | 🔄 Em progresso |

### 1. O Cenário de Teste Mínimo (A Reação em Cadeia)

O mapa de teste precisa de uma sequência de eventos que encadeie todas as regras do motor físico de forma sequencial e dependente. A falha em um passe quebra toda a cadeia, facilitando o *debug* visual.

**A Máquina do MVP:**

1. Um **Temporizador** (ex: um rato numa gaiola que corre após 2 segundos) aciona uma engrenagem. *(Testa o Passe 1: Contadores e Passe 3: Comportamentos)*.
2. A engrenagem puxa uma **Corda** que liberta uma **Bola de Boliche**. *(Testa o Passe 7: Constraint Solver para cabos)*.
3. A Bola de Boliche cai livremente. *(Testa o Passe 2: Gravidade)*.
4. A bola atinge uma **Plataforma Inclinada** e rola. *(Testa o Passe 5: Colisões AABB e repulsão vetorial)*.
5. A bola cai da plataforma, quica no limite inferior da tela e atinge um **Interruptor Laser**. *(Testa o Passe 4: Clamping de borda de tela e Passe 6: Ótica/Proximidade)*.
6. O Laser energiza uma **Tomada** que liga um **Ventilador**, soprando um balão contra espinhos. *(Testa o Passe 6: Elétrica e o Sistema de Efeitos Colaterais/Áudio)*.

### 2. O Subconjunto de Peças (Os Arquétipos)

Em vez de programar peças individuais, você implementará **Arquétipos de Memória** no Zig. O MVP precisa apenas destas entidades no `BoardState`:

* **Estática/Passiva:** Uma parede ou plataforma (ignora gravidade, fornece colisão rígida).
* **Cinética Simples:** A bola de boliche (sofre gravidade, possui inércia, colide).
* **Constraint Driver:** Um motor contínuo (ignora gravidade, injeta velocidade angular em outras peças).
* **Constraint Link:** Uma correia e uma corda (não possuem X/Y próprio, apenas ligam IDs de peças e equalizam forças).
* **Gatilho de Energia/Sinal:** Um laser emissor e um painel receptor (atualizam máscaras de bits de `IS_POWERED`).
* **Consumidor de Sinal:** O ventilador ou uma lâmpada (lê o bit `IS_POWERED` e altera seu próprio bit de animação).

### 3. A Infraestrutura do MVP

O pipeline completo pode ser reduzido a três componentes essenciais:

* **O "Compilador" de Fase (Godot `@tool`):** Um script simples no editor que lê um Node2D com 10 Sprites organizados na tela e exporta um arquivo `.bin` ou `.json` cru, contendo apenas IDs, Posição X/Y em pixels e conexões.
* **O Motor Núcleo (Zig via GDExtension):** Uma *Struct of Arrays* (SoA) pré-alocada para suportar um limite rígido de, digamos, 32 peças. O loop de 60Hz roda em *hardcode*, executando as funções matemáticas de ponto fixo. No final de cada *tick*, ele preenche um `PackedFloat32Array` ou `PackedByteArray`.
* **A Renderização ("Puppet Master" no Godot):** Um único script em um nó principal que puxa esse `PackedArray` e faz um *for-loop*, atualizando a posição `x` e `y` de 10 *sprites* genéricos instanciados na tela, usando interpolação simples.

### O Critério de Sucesso do MVP

A validação técnica deste MVP resume-se a dois testes cruciais:

1. **O Teste de Estresse do Determinismo:** Você deixa a simulação rodar. Se, após 1.000 reinícios do cenário, a bola de boliche atingir o laser exatamente no mesmo *frame* e com a mesma representação de sub-pixel no log de ponto fixo, a arquitetura está validada e imune a *floating-point drift*.
2. **O Teste de Profiling:** Usando o *profiler* do Godot, o tempo de execução do núcleo em Zig (`tick_simulation()`) deve registrar algo na ordem dos microssegundos (µs), confirmando que a separação da carga via DOD e a transferência de memória em bloco libertam completamente a *engine* para escalar a UI e os gráficos.

Alcançando esta estabilidade no MVP, escalar o jogo de 10 para 278 peças torna-se estritamente um trabalho de inserção de dados (Data Entry) no catálogo YAML e expansão da matriz de colisões, sem necessidade de reescrever a fundação do motor.

### 4. Simulação Isolada em Overlay

Quando o jogador pressiona **Play**, o tabuleiro de edição desaparece e um SubViewport sobreposto à interface mostra a simulação a correr. Este overlay é completamente isolado do editor.

#### Controles e Estado da Simulação

Durante o playback, o overlay expõe:
- **Controles**: Play / Pause, Stop, Reset
- **Estado atual**: `idle`, `running`, `paused`, `success`, `fail`
- **Tick atual**: contador de ticks decorridos

#### Objetivos como Checkboxes

Os objetivos do nível são apresentados como checkboxes de leitura (não interativos durante o playback):

- **Objetivo Primário**: checkbox que é **automaticamente marcado** (`✓`) quando a condição de vitória é atingida
- **Objetivo Secundário**: checkbox separado, marcado quando condições opcionais são cumpridas

```
┌─────────────────────────────────────┐
│  Simulação          [▶][⏸][⏹][↺]  │
│  Estado: running    Tick: 127/500  │
├─────────────────────────────────────┤
│  ☐ Objetivo Primário: Atingir laser│
│  ☐ Objetivo Secundário: Não falhar │
└─────────────────────────────────────┘
```

#### Ciclo Sucesso/Falha

Quando a simulação atinge **sucesso** ou **falha**:

1. O estado da simulação é definido para `success` ou `fail`
2. O checkbox do objetivo correspondente é **automaticamente marcado** conforme o resultado
3. O playback para
4. É mostrada uma mensagem visual (ex: "Vitória!" ou "Falhou!")
5. O jogador pode pressionar **Reset** para rever ou **Stop** para voltar ao editor

#### Fluxo

```
[Editor] ──init(level_data)──> [Simulation Overlay]
                                       │
                                  [Play] → estado: running
                                       │
                                  [tick 0..N]
                                       │
                          ┌────────────┴────────────┐
                     [sucesso?]                [falha?]
                          │                        │
                    estado: success          estado: fail
                    checkbox prim: ✓          checkbox prim: ✗
                          │                        │
                     [mensagem]               [mensagem]
                          │                        │
                     [Reset / Stop]           [Reset / Stop]
```

#### Princípios de Arquitetura

1. **Contexto Exclusivo**: Editor ou simulação — nunca os dois em interação simultânea.
2. **Editor: OOP**: O editor é uma aplicação orientada a objetos — tem classes (`PartData`, `BehaviorRegistry`, `ChainBuilder`), interfaces, e ferramentas interativas (arrastar, editar propriedades, adicionar/remover peças).
3. **Simulação: Data-Driven**: A simulação recebe apenas dados (`parts[]`, `chain_script`, `solution`) e executa lógica pura e determinística. Os objetos da simulação não têm comportamento próprio — apenas dados e physics.
4. **Dados only**: `parts[]`, `chain_script`, `solution` fluem do editor para a simulação — nenhum estado de runtime volta ao editor.
5. **Comunicação por Sinais**: `simulation_finished(success, tick_count, events)` é o único canal de retorno.