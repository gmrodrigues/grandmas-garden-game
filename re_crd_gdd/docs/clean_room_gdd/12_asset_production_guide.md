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
