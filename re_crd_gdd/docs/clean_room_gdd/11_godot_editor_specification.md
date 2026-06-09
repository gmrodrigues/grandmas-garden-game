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
- **Resposta Baseada no Clean Room (YAML):** A extração do *timgres* e os YAMLs de fase (`tim2_specs/user-journey-specification.md`) revelam que o comportamento da peça depende da sua máscara de bits. O `flag_1` contendo `0x0040` dita que a peça está *Locked* (travada).
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
