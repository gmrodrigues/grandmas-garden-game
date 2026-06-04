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

## Matriz de Interação (SOLVE.RES)

O jogo raramente programa eventos específicos "na unha". A interação ocorre através de uma tabela de decisão baseada em estado (`build/phase-16/solve-decoded.json`), que opera pelo esquema de "Pares de Gatilho":

`{Minha_Peça, Meu_Estado} + {Outra_Peça, Estado_Dela} => {Ação}`

Exemplos clássicos de interação:
* **Fogo vs Explosivo:** Se a Chama (Peça A) encostar na Dinamite (Peça B), Peça B avança para seu estado de ignição. A partir daí, o *timer* interno (*state_counter*) da Dinamite cuida do atraso até a explosão, que então gera uma força radial (*push/destroy*).
* **Laser vs Balão:** O laser projeta o raio. Se a linha de colisão do raio intercepta o balão de festa, aciona o gatilho de *burst* no balão, reproduzindo a animação de destruição.
* **Gato vs Rato:** A peça Gato executa uma rotina de varredura direcional em seu *pass* de *behavior*. Se "ver" a peça Rato no mesmo eixo, altera sua própria velocidade (`vel_x`) para perseguir o rato.

## O Papel do Design Limpo (Clean Room)

Ao implementar cada peça, desenvolvedores da Godot devem consultar **exclusivamente** os dados da pasta `docs/parts/`. 
Nós não portamos código de C para GDScript; nós olhamos os parâmetros de atrito e massa, as dimensões da Hitbox (AABB offset) e programamos a lógica no Node da peça. O número do estado (`state_id`) dita qual quadro de sprite desenhar e qual som emitir (baseado em `R-016-sound-param-table.md`).
