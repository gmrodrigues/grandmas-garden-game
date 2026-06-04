# Capítulo 13: Especificações Técnicas e Formatos de Dados

Este capítulo condensa os detalhes de baixo nível extraídos durante o processo de engenharia reversa (Clean Room), servindo como guia definitivo para a reimplementação do motor físico, da máquina de estados e do decodificador de arquivos na Godot.

---

## 1. Máquinas de Estado (State Machines)

O The Incredible Machine 2 utiliza um sistema de estados composto por quatro conceitos interligados. Estas regras regem as 52 peças interativas e gerenciam animações e transições lógicas.

### Conceitos Fundamentais
1. **`state_counter`**: Variável interna de física (INT16). Incrementada pelo motor a cada tick. Pode ser sobrescrita por colisões, gatilhos de proximidade ou eventos de som.
2. **`current_state`**: Cópia em runtime do `state_counter`, utilizada para checagem de resolução do puzzle e para buscar a animação correta no arquivo ANM.
3. **`ANM state_id`**: Identificador presente na Seção C dos arquivos de animação, que mapeia para o primeiro frame visual de um determinado estado. Existem 89 IDs de estado únicos no jogo.
4. **Gatilhos `SOLVE.RES` (`self` / `other`)**: Pares lógicos que determinam reações em cadeia. Quando a peça atual está no estado `self` e a peça colidida está no estado `other`, ocorre uma transição de estado.

### Motor de Execução (Tick = 60Hz)
O motor avança os estados das peças móveis a cada tick físico. Para a maioria das peças:
- O estado avança de um limite inferior (geralmente `0`) até um limite superior (`8`).
- Quando atinge o topo, sofre wrap-around (reseta para `0`).
- Estados iguais a zero (estado de repouso) muitas vezes possuem um delay randômico antes de começar a avançar, garantindo assincronicidade visual em peças repetidas (ex: velas piscando).

### Mapeamento de Colisões
Quando duas peças (A e B) colidem, a engine lê ambos os `state_counter` e verifica o catálogo `SOLVE.RES`. 
Se a combinação satisfizer a regra de transição de uma das peças (ou de ambas), o `state_counter` é atualizado para o estado de destino (ex: Vela acesa encosta no pavio da Dinamite -> Dinamite passa para o estado "Acesa").

---

## 2. Formatos de Arquivo (Arquitetura de Dados)

Os arquivos originais extraídos (Levels e ANMs) possuem formatos binários Little-Endian específicos.

### Formato de Fases (.LEV / .TIM)
Os arquivos de puzzle na versão TIM2/TIM3 geralmente usam o **Magic Number `EF AC 13 01`** (ou `14 01`).
A estrutura de um arquivo de fase segue a ordem:
1. **Cabeçalho**: Magic Number + cor de fundo da paleta.
2. **Strings**: Título (null-terminated) e Descrição do Objetivo (null-terminated).
3. **Dicas (Hints)**: Array opcional contendo coordenadas e o texto da dica associada à Lupa.
4. **Header Físico**: Valores de Gravidade, Pressão de ar e ID da música.
5. **Blocos de Peças**:
   - Lista de peças fixas (não afetadas pela gravidade/mouse).
   - Lista de peças móveis (podem interagir livremente).
6. **Bloco de Solução**: As condições de vitória (qual peça deve estar em qual posição ou em qual estado).

### Estrutura de Peça (Part Entry)
Cada instância de peça gravada na fase ocupa, via de regra, **48 bytes**. 
(Peças compostas como Correias e Cordas possuem tamanhos estendidos: 52 e 54 bytes, respectivamente).
- **ID da Peça (INT16)**: Define o tipo.
- **Flags_1**: Bitfield que define atributos. Ex: `0x40` (Locked/Inventário), `0x200` (Pode virar verticalmente), `0x400` (Horizontalmente), `0x1000` (Móvel).
- **Flags_2**: Controle de conexões. Ex: `0x1` (Aceita correia), `0x4` (Aceita corda), `0x10/0x20` (Sprite invertido).
- **Flags_3**: Atributos TIM2 específicos. Ex: `0x1` (Elétrico), `0x4` (Inflamável), `0x40` (Trancado no nível).
- **Posição X/Y**: Coordenadas da peça em pixels, relativas ao grid de colisão.
- **Ligações e Conexões**: Índices apontando para as IDs de outras peças com as quais estão conectadas por cabos ou correias (`belt_connected_part`, `rope_connected_part`).

### Formato de Animação e Sprites (.ANM)
O jogo não guarda imagens soltas. Tudo fica dentro dos `.ANM`, que usam o padrão "Dynamix Chunk".
A estrutura é dividida em blocos lógicos, onde os mais vitais para a renderização são:
- **Sec B (Frames)**: Contém o tamanho (Width/Height) do sprite e o offset de textura.
- **Sec C (State Map)**: Mapeia o `state_id` da lógica do jogo (ex: 4 = "Estourado") para a ID do frame visual na Seção B.
- **Sec D (Draw Commands)**: Comandos de baixo nível (0 a 5) instruindo a paleta de cores, cópia em bloco ou transparência para compor a imagem em tela. O script de extração (Track A) transformou isso em `.png`. Na Godot, usaremos os PNGs extraídos mapeados pelos arquivos JSON gerados pelo extrator.

---

## 3. Detalhes Técnicos e Limitações

### Determinismo Físico
O motor de The Incredible Machine opera estritamente de maneira **determinística a 60 FPS**. Qualquer variação de ponto flutuante ou frame-rate destrói a solução dos puzzles.
- **Track B Requirement**: Na engine moderna (Godot), a física **deve** usar Inteiros (Ponto Fixo) ou `_physics_process` cravado a 60 Hz utilizando os mesmos multiplicadores do MS-DOS originais para Massa, Inércia, Gravidade (default: 272) e Pressão do ar (default: 67).

### Z-Indexing Categórico
A ordem de renderização (Z-Index) das peças originais obedece implicitamente a categoria de flag delas:
1. Fundo (Background / Paredes)
2. Correias e Cordas
3. Peças do Cenário (Scenery)
4. Peças Móveis Interativas
5. Efeitos Especiais de Sobreposição (Explosões / Faíscas)
6. Cursor e UI.

### Compatibilidade e Clean Room
Todo o mapeamento das reações (SOLVE.RES), propriedades de massa e centro de cintos (`belt_connect_pos_x/y`) já foram descompilados e serializados na pasta `build/phase-16/godot/`. A porta da Godot não precisa ler os arquivos binários diretamente em runtime, mas consumirá os JSONs limpos que agem como as tabelas de verdade.
