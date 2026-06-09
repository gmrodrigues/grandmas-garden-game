# 14. Comportamento das Peças: Edição, Simulação e Gizmos

A arquitetura da Godot deve tratar as peças de forma bidimensional quanto ao seu ciclo de vida. Uma mesma peça possui **dois modos distintos de existência**: o Modo de Edição (`MODE_PLACE` / `MODE_SELECT`) e o Modo de Simulação (`MODE_PREVIEW`). 

Este documento mapeia o comportamento das peças em cada um desses estados e categoriza todos os manipuladores visuais (*Gizmos*) exigidos pela ferramenta.

---

## 1. Modos de Vida da Peça

### Modo de Edição (Edit Mode)
Enquanto a simulação está pausada e o usuário está arquitetando a engenhoca, o motor de física não atua.
- **`state_counter`:** Fixo no estado inicial (geralmente `0`, a não ser que alterado pelo usuário via Gizmo de Programação).
- **Colisões Físicas:** Desativadas. A *hitbox* serve puramente para o evento de clique do Mouse (`input_event`) e validação estática de *overlap* na hora de instanciar a peça.
- **Renderização de Gizmos:** A peça desenha *Overlays* ou instancia Nódulos Filhos (ex: botões de arrastar, âncoras de conexão elétricas piscando).
- **Hover/Highlight:** O Mouse-over pinta a peça com um *outline* amarelo/branco e exibe o nome da peça (Tooltip).

### Modo de Simulação (Simulation Mode)
Ativado assim que o usuário aperta *Play*.
- **Obliteração de Gizmos:** Todas as alças, nós visuais de conexão, setas e highlights são destruídos ou ocultos (`hide()`). O jogador deve ver a tela limpa como em 1993.
- **Loop de Física (60Hz):** O `state_counter` é liberado para avançar. Temporizadores internos disparam.
- **Colisões Resolvidas:** As máscaras de colisão passam a agir diretamente via `SOLVE.RES`. A sobreposição não é mais bloqueada pelo *mouse*, mas passa a gerar trancos, empurrões, destruição ou transições de estado.

---

## 2. Comportamento de Posicionamento (Placing Behavior)

O Godot lidará com a instância de peças através de uma matriz de restrições geométricas.

* **Snap-to-Grid:** Todo clique arredonda a posição global para o múltiplo mais próximo de 16 pixels.
* **Validação de Sobreposição (Overlap):** Antes da peça ser de fato fixada (`add_child`), uma consulta de shape (`PhysicsDirectSpaceState2D.intersect_shape`) testa a área. Se detectar uma peça da camada Ativa, o fantasma da peça sob o mouse fica **Vermelho** e a colocação é rejeitada.
* **Exceções de Sobreposição (Scenery & Backgrounds):** Peças do tipo Cenário (IDs >= 150) e Paredes de Tijolo têm máscaras ignoradas por esse teste e recebem `z_index = -1`, permitindo que o jogador crie fundos murados onde motores e ratos operam fisicamente por cima sem acusar erro de intercessão no editor.

---

## 3. Arquétipos de Gizmos (Manipuladores Visuais)

Ao clicar numa peça no Modo de Edição, ela revela *Handles* (alças) ao seu redor. Abaixo, catalogamos os arquétipos e as peças que as utilizam.

### 3.1 Gizmos de Extensão (Stretch)
Peças que não têm tamanho fixo. Possuem handles circulares nas extremidades. Clicar e arrastar esses handles expande ou contrai a peça em blocos (geralmente repetindo o segmento do meio do sprite).
* **Uso (Godot):** Redimensiona o `.region_rect` do Sprite2D e recalcula o polígono de colisão para abranger o novo tamanho.
* **Peças Aplicáveis:**
  * Paredes (Brick Wall, Caution Wall)
  * Rampas de Madeira (Wood Incline)
  * Correias de Transmissão (Belts) e Cordas (Ropes) - *O Stretch aqui não repete blocos, mas estica uma Line2D entre as polias.*

### 3.2 Gizmos de Orientação (Flip)
Peças direcionais. Ao ser selecionada, a peça revela ícones interativos flutuantes (`BUTTONS_f000.png` originais) que rodam ou espelham a mecânica da peça.
* **Uso (Godot):** Altera a rotação visual, inverte as normais de colisão (eixo X ou Y) e salva a orientação desejada nos `flags` da peça.
* **Peças Aplicáveis:**
  * Canhões (Cannons) - *Apontam para 6 direções diferentes.*
  * Lasers e Detectores - *Apontam para 4 direções ordinais.*
  * Luvas de Boxe (Boxing Gloves) e Aceleradores (Accelerators) - *Golpeiam na direção girada.*
  * Lupa (Magnifying Glass), Moinho de Vento (Pinwheel) e Espelhos.
  * Rampas inclinadas e Esteiras rolantes (Conveyor Belts) - *Muda a direção da força da esteira.*

### 3.3 Gizmos de Conexão (Anchors / Plugs)
Não são handles para serem arrastados isoladamente, mas "Tomadas" visuais. Durante o uso da ferramenta Corda (`MODE_CONNECT`), passar o mouse por cima ativa um brilho de atração (Snap Magnético).
* **Uso (Godot):** São meros marcadores (`Marker2D` ou `Area2D` restritos). Quando o usuário arrasta uma linha até ele, o ID da peça é gravado em `connected_1` ou `connected_2`.
* **Peças Aplicáveis:**
  * **Mecânicas:** Engrenagens, Motores, Polias.
  * **Elétricas:** Geradores, Tomadas (Outlets), Painéis Solares, Ventiladores.
  * **Tubulações:** Canos retos e curvos.

### 3.4 Gizmos de Programação (Program / Dialog)
Peças que operam logicamente ou têm atrasos customizados. Exibem um ícone de Computador. Ao clicar no gizmo, abre-se uma tela flutuante Modal.
* **Uso (Godot):** Abre um painel GUI em `CanvasLayer` com botões e caixas de texto.
* **Peças Aplicáveis:**
  * **Balões de Fala/Computador de Mensagem:** Campo de texto livre para *Strings*.
  * **Laser:** Rádio *Buttons* para selecionar a cor/comprimento de onda da luz.
  * **Timers (Egg Timer):** *Slider* ou número definindo o atraso em *ticks* da física.
  * **Interruptores de Parede:** Opção para já iniciar a simulação no estado Ligado (estado pré-setado ao invés do default).

### 3.5 Condições de Vitória (Goal Regions)
Não pertencem a uma peça específica, mas à arquitetura geométrica do nível.
* **Uso (Godot):** Usam a ferramenta *Add Target Rect*. Elas funcionam exatamente como Gizmos de Extensão, gerando zonas (`Area2D`) flutuantes na tela que testam a presença de peças específicas quando a simulação entra em curso.
