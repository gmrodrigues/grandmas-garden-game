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
