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
