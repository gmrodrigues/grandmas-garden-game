# 4. UI/UX e Controles

A interface de usuário de um simulador puzzle-sandbox é o elemento que determina se o jogador se sentirá no controle de uma máquina complexa ou frustrado brigando com caixas.

A implementação da UI em Godot tem o luxo de ser livre de amarras de motor antigo, desde que mantenha a coerência mecânica descrita no `tim2_specs/user-journey-specification.md`.

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
