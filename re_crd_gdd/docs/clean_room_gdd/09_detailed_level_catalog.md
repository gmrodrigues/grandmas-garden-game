# 9. Catálogo Detalhado de Fases e Dependências

Este documento cataloga exaustivamente todas as fases do jogo. Para cada fase, detalhamos o objetivo, dicas, **setup exato das peças** (inventário + cenário), e um **Mapa de Dependências** que estipula quais sistemas (`Solvers`), áudios e volumes de frames visuais (`.ANM`) o `LevelLoader` da Godot precisará puxar para a memória.

## ELEV1.yaml - Under the Sea
**Objetivo:** Get Mel home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Mel could walk through this pipe... if there were one here.
- This looks like a good place for an anti-gravity pad.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 9 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **257 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 6 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 6 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 4 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 4 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 2 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 1 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 2 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 1 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 2 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 2 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 2 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 2 peça(s)
- ![Green Cliff](../../scenery-review/PART217.png) **Green Cliff**: 1 peça(s)
- ![Shipwreck](../../scenery-review/PART218.png) **Shipwreck**: 1 peça(s)
- ![Ancient Ruins](../../scenery-review/PART220.png) **Ancient Ruins**: 2 peça(s)
- ![Stone Temple](../../scenery-review/PART221.png) **Stone Temple**: 2 peça(s)
- ![Bamboo Fence](../../scenery-review/PART223.png) **Bamboo Fence**: 1 peça(s)
- ![Stone Block](../../scenery-review/PART225.png) **Stone Block**: 1 peça(s)
- ![Anchor](../../scenery-review/PART228.png) **Anchor**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Shell Spiral](../../scenery-review/PART234.png) **Shell Spiral**: 1 peça(s)
- ![Starfish](../../scenery-review/PART236.png) **Starfish**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 1 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 4 peça(s)
- ![Coral Branch](../../scenery-review/PART239.png) **Coral Branch**: 3 peça(s)
- ![Green Coral](../../scenery-review/PART240.png) **Green Coral**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 2 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 3 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 1 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 12 peça(s)
- ![Octopus](../../scenery-review/PART251.png) **Octopus**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 2 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 4 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 3 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)
- ![Dolphin](../../scenery-review/PART261.png) **Dolphin**: 1 peça(s)

---

## ELEV2.yaml - Yellow Brick Path
**Objetivo:** Get Newton Mouse into his hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
-  Holes in the floor are a blast.
- Newton is just crazy about cheese.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **420 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 2 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 4 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 10 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 5 peça(s)

---

## ELEV3.yaml - Space Hoops
**Objetivo:** Put the basketball into the basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Jack has been known to be a good shot.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **128 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 3 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 4 peça(s)
- ![Snow Peaks](../../scenery-review/PART159.png) **Snow Peaks**: 2 peça(s)
- ![Planet Rings](../../scenery-review/PART168.png) **Planet Rings**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Stalactites](../../scenery-review/PART180.png) **Stalactites**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![City Buildings](../../scenery-review/PART187.png) **City Buildings**: 1 peça(s)
- ![Ice Castle](../../scenery-review/PART188.png) **Ice Castle**: 1 peça(s)
- ![Crystal Tower](../../scenery-review/PART189.png) **Crystal Tower**: 1 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Dish Antenna](../../scenery-review/PART194.png) **Dish Antenna**: 1 peça(s)

---

## ELEV4.yaml - Bump and Roll
**Objetivo:** Get the tennis ball into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- This ball needs a little punch to get going.
- Bowling ball in the side pocket!  Get it?
- A little time management maybe...

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **309 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## ELEV5.yaml - Midnight Blast
**Objetivo:** Fire the cannon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- This ball needs a little extra help to get going.
- Is it conveyor or conveyer? Something to be pondered I suppose.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **254 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 3 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![desert mesa](../../build/phase-3/bitmaps/PART129_f000.png) **desert mesa**: 2 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/PART146_f000.png) **small mesa**: 3 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/PART147_f000.png) **medium mesa**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 3 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 4 peça(s)
- ![Sphinx Pyramid](../../scenery-review/PART182.png) **Sphinx Pyramid**: 1 peça(s)

---

## ELEV6.yaml - Bill's Aquarium
**Objetivo:** Break Bill's aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Use a corner pipe to turn the ball in the proper direction.
- In some situations, one just isn't enough.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **343 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 8 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 17 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## ELEV7.yaml - Caged Balloons
**Objetivo:** Pop both of the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Sometimes you have to really atTACK a puzzle.
- There is a way to pull this balloon down with the parts available.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **286 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 8 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 6 peça(s)
- ![Archway](../../build/phase-3/bitmaps/PART103_f000.png) **Archway**: 4 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/PART130_f000.png) **Glass Building**: 4 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/PART141_f000.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 1 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 2 peça(s)

---

## ELEV8.yaml - Air Time
**Objetivo:** Put all of the blimps in the hangar on the right.  They all need to be there at the same time.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- There must be a way to turn these three blimps around without disturbing the others.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **65 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 3 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 8 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 6 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/PART110_f000.png) **Elm Tree**: 7 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 9 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 7 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 3 peça(s)

---

## ELEV9.yaml - Pulley Popper
**Objetivo:** Pop the silver balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- This ball needs to make its way into the beach bucket.
- There must be a way to get this bucket through the wall below.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **311 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 9 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)

---

## ELEV10.yaml - Separation
**Objetivo:** Put the baseball in the aquarium and the pinball in the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- A light ball will roll over a trap door, but a heavy ball will fall through.
- Bombs away!
- Room for a Kaboom!
- What to do with this gap? Something should SPRING to mind.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **109 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 4 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 22 peça(s)

---

## ELEV11.yaml - Beach Blast
**Objetivo:** Shoot off all the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- There is a way to light these five rockets at the same time. But it can only be done at the speed of light.
- Leave the lighting of this last one up to Mel.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **566 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 8 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 6 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 6 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![tile](../../build/phase-3/bitmaps/PART123_f000.png) **tile**: 4 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 2 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/PART130_f000.png) **Glass Building**: 1 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/PART131_f000.png) **apartment building**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Sand Hill](../../scenery-review/PART162.png) **Sand Hill**: 1 peça(s)
- ![Tropical Island](../../scenery-review/PART163.png) **Tropical Island**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 1 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 2 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Breaking Wave](../../scenery-review/PART207.png) **Breaking Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 1 peça(s)
- ![Comet Streak](../../scenery-review/PART231.png) **Comet Streak**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 4 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 1 peça(s)
- ![Fish School](../../scenery-review/PART257.png) **Fish School**: 1 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 1 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)

---

## ELEV12.yaml - The Dream
**Objetivo:** Put the balls into the boxes. The green ball goes in the aquarium, the blue one in the crate, the yellow one in the basket, and the red one in the cardboard box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- An incline might be helpful here.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **94 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 8 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 4 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 5 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 3 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 15 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 9 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 4 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 2 peça(s)

---

## ELEV13.yaml - Late for the World Cup
**Objetivo:** Put the soccer ball into the basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- This all looks a little off-balance.
- A large curved pipe will help get the ball around the corner.
- Anti-gravity will move the basketball into the air, but it will still need help to get over the wall.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **114 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 9 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 5 peça(s)
- ![tile](../../build/phase-3/bitmaps/PART123_f000.png) **tile**: 8 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 9 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 1 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 1 peça(s)
- ![Snow Peaks](../../scenery-review/PART159.png) **Snow Peaks**: 2 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Breaking Wave](../../scenery-review/PART207.png) **Breaking Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 6 peça(s)

---

## ELEV14.yaml - Trap Newton
**Objetivo:** Trap Newton Mouse with the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Get Newton to fall on the plunger of the remote bomb.
- Use the remote bomb to blow up this wall and allow the pinball through.
- Hmm....What would cut this rope?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **133 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/PART130_f000.png) **Glass Building**: 3 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/PART131_f000.png) **apartment building**: 2 peça(s)
- ![office building](../../build/phase-3/bitmaps/PART132_f000.png) **office building**: 1 peça(s)
- ![car](../../build/phase-3/bitmaps/PART133_f000.png) **car**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/PART134_f000.png) **lamp post**: 4 peça(s)

---

## ELEV15.yaml - Balloon Traveler
**Objetivo:** Use the tack on the left side of the screen to pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Anti-gravity pads have an interesting effect on balloons. Place one here and see what happens!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **73 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 9 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 12 peça(s)

---

## ELEV16.yaml - Kitty in a Cage
**Objetivo:** Lure Curie Cat into the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- There must be something that will work with this plug.
- Here is some rotational energy waiting to be tapped.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **402 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 8 peça(s)

---

## ELEV17.yaml - The Food Machine.
**Objetivo:** Open the can, start the mixer, and heat up some coffee.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **212 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 8 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## ELEV18.yaml - Night in the Mountains
**Objetivo:** Help Mel get back to his cabin.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- On occasion, parts will be used in unusual ways. This accelerator tube for instance...

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **375 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 8 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/PART110_f000.png) **Elm Tree**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 7 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/PART115_f000.png) **Little Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 2 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/PART141_f000.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 12 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 1 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 3 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 8 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 2 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 2 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 3 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## ELEV19.yaml - Double Whammy
**Objetivo:** Blow up both missiles.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Here's a nice spot for something tipsy.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **187 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## ELEV20.yaml - Deep Sea Explosion
**Objetivo:** Make the soccer ball float off the top of the screen.

**Ambiente:**
- Gravidade: 238
- Pressão do Ar: 128

**Dicas Ativas (2):**
- This basketball may be the key to the whole thing.
- Use a rope to pull down on the remote bomb's plunger. A teeter-totter might help.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **191 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 7 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 7 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Treasure Chest](../../scenery-review/PART229.png) **Treasure Chest**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Shell Spiral](../../scenery-review/PART234.png) **Shell Spiral**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 7 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 1 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Octopus](../../scenery-review/PART251.png) **Octopus**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 1 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 1 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 1 peça(s)
- ![Fish School](../../scenery-review/PART257.png) **Fish School**: 2 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 1 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 2 peça(s)

---

## ELEV21.yaml - Newton Drops a Message
**Objetivo:** Reveal Newton's message and get Curie Cat off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Who needs gravity in a spot like this?
- What if this ball were to get blown to the left?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **537 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 3 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 13 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 4 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 7 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## ELEV22.yaml - Home Sweet Home
**Objetivo:** Help Newton Mouse get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Some explosives might help remodel this wall.
- Newton looks small enough to go through these pipes.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **163 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 7 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 3 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 8 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 4 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)

---

## ELEV23.yaml - Feeding Curie
**Objetivo:** Open a can of cat food for Curie Cat.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Getting this bucket to fall may take some explosive thinking.
- Some extra GEAR may be needed to get the power from this motor to the generator.
- This generator needs to turn to get power flowing through the outlet.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **419 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 4 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Lattice Archway](../../build/phase-3/bitmaps/PART106_f000.png) **Lattice Archway**: 9 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 3 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)

---

## ELEV24.yaml - Fishtank Target
**Objetivo:** Blow up the fish tank with the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Find a source of rotational energy to drive this machine.
- Use the inclines to adjust the missile's trajectory.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **328 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 6 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 8 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 6 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 2 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 2 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 1 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 1 peça(s)

---

## ELEV25.yaml - Ghost Dynamite
**Objetivo:** Light the dynamite with the candle.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Try connecting a rope from the match to a balloon.
- Some anti-gravity will keep the candle floating.
- Try putting a balloon in here.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **198 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 10 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 9 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 7 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## ELEV26.yaml - The Merry Mixer
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Use hedge trimmers to cut the balloon loose.
- A springboard can bounce the ball up, over, and into the pipe.
- Anti-gravity pads have a funny effect on balloons.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **153 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 10 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 15 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)

---

## HH1.yaml - Shootin' Hoops
**Objetivo:** Put the basketball into the box on the right.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **175 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 5 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 4 peça(s)

---

## HH2.yaml - Pool Shark
**Objetivo:** Put the eight ball in the corner pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **239 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 6 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 4 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 2 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 3 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 3 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 3 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH3.yaml - High Impact Fishing
**Objetivo:** Break all of the fish tanks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **242 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 4 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 4 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)

---

## HH4.yaml - Plunk it in the Pocket
**Objetivo:** Put each pool ball into the nearest pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **484 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 4 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 4 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 6 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 5 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## HH5.yaml - Lawn Bowling
**Objetivo:** Put the bowling ball into the small glass aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **166 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 3 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 2 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 8 peça(s)

---

## HH6.yaml - Crazy Cannon
**Objetivo:** Fire the cannon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **300 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 4 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)

---

## HH7.yaml - The Balloon Buster's Ball
**Objetivo:** Pop all of the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **111 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 11 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 10 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 5 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 4 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 6 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 11 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 4 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 6 peça(s)

---

## HH8.yaml - Setting Sail
**Objetivo:** Make some toast.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **294 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 4 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 8 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH9.yaml - Score!
**Objetivo:** Put the bowling ball into the basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **202 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 6 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)

---

## HH10.yaml - Fire One
**Objetivo:** Launch the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **348 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 3 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## HH11.yaml - The Rocketeer's Revenge
**Objetivo:** Launch the rocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **451 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 4 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## HH12.yaml - Pool Trick
**Objetivo:** Shoot each of the numbered balls into the nearest pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **164 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 4 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 8 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 9 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)

---

## HH13.yaml - Big Red Head to Head
**Objetivo:** Launch the rocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **406 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 8 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 3 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH14.yaml - Blimp Blaster
**Objetivo:** Shoot down the blimp with a missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **208 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HH15.yaml - Mouse Race
**Objetivo:** Help Newton Mouse get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **210 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 12 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 19 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 12 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## HH16.yaml - Coffee Cage
**Objetivo:** Put the pot in the cage and brew some coffee.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **225 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH17.yaml - Rocket Rivalry
**Objetivo:** See who can launch the rocket!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 35 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **681 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HH18.yaml - Too Many Mice
**Objetivo:** Help Newton and his pals each find a mouse hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **224 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 6 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 16 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 27 peça(s)

---

## HH19.yaml - See-Saw Asylum
**Objetivo:** Pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **226 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 8 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH20.yaml - Bill's Bad Day
**Objetivo:** Break Bill's aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **342 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 8 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## HH21.yaml - Zap Trap.
**Objetivo:** Hit the sensor with the red laser.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **317 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## HH22.yaml - Laser Lighter
**Objetivo:** Light the hot air balloon at the bottom left and make it float off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **145 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 5 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 10 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH23.yaml - Balloons or Bust
**Objetivo:** Pop both balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **135 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH24.yaml - Punch Mel
**Objetivo:** Knock Mel off the screen. 

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **282 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH25.yaml - Pass to the Glass
**Objetivo:** Get the soccer ball into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **134 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 6 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH26.yaml - Slam Dunk
**Objetivo:** Get the basketball into the cardboard box at the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **232 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 3 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH27.yaml - Sharpshooter
**Objetivo:** Light the candle with the laser.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **156 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HH28.yaml - Ragtime Rollers
**Objetivo:** Put the bowling ball into the aquarium and the silver ball into the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **170 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 5 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/PART98_f000.png) **T-Connector**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 13 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH29.yaml - Loony Lamp
**Objetivo:** Light the oil lamp.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **201 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 4 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH30.yaml - Little Hindenburg
**Objetivo:** Destroy the blimp with the remote bomb.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **297 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 4 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH31.yaml - Puppy Popper
**Objetivo:** Pop the doggy balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **120 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## HH32.yaml - Mixer Moxie
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **497 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 6 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HH33.yaml - Shootin' Newton
**Objetivo:** Get Newton Mouse into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **612 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 5 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 6 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 7 peça(s)

---

## HH34.yaml - Blimp Buster
**Objetivo:** Destroy the blimp!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **210 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HH35.yaml - The Pop Shop
**Objetivo:** Pop the silver balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **226 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HH36.yaml - Pop the Purple Puppy
**Objetivo:** Pop the balloon before it escapes!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **128 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH37.yaml - 'Gator on Guard
**Objetivo:** Put Curie Cat in the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **645 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 7 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 8 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## HH38.yaml - The Age of Aquarium
**Objetivo:** Break both fish tanks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1008_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **507 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 2 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 7 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH39.yaml - Rootin' Tootin' Newton
**Objetivo:** Get Newton Mouse into the caution box at the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **207 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 10 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 3 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/PART98_f000.png) **T-Connector**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH40.yaml - The Perky Percolator
**Objetivo:** Make coffee by placing a flame under it.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **275 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 4 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH41.yaml - Blimp Exodus
**Objetivo:** Get the blimp off the screen any way you can.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **410 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 7 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 6 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH42.yaml - Omega Launch
**Objetivo:** Launch the rocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 29 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **397 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH43.yaml - 'Gator in the Garden
**Objetivo:** Help Mel Schlemming get back to his cozy home in the Everglades.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **473 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH44.yaml - Skyrockets in Flight
**Objetivo:** Launch the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **308 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 3 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH45.yaml - Log Hangar
**Objetivo:** Get the balloon into the log box at the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **285 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 7 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH46.yaml - Bye-Bye Bucket
**Objetivo:** Knock the bucket off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 25 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **400 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 7 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH47.yaml - Bucket Battle
**Objetivo:** Put the bucket on top of the caution wall.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **122 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 8 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH48.yaml - Hot Air Heroics
**Objetivo:** Light the balloon so that it floats off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **485 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HH49.yaml - Bigshot
**Objetivo:** Fire the cannon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **580 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HH50.yaml - Last Launch
**Objetivo:** Launch all three fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **417 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 7 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 3 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV1.yaml - Things That Go Boom!!!
**Objetivo:** Set off the fireworks on the left side of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 25 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **628 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 21 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV2.yaml - Curie and the Fish Squish
**Objetivo:** Break all six fish tanks and help Curie Cat exit the right side of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **508 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 6 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 12 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 4 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HLEV3.yaml - Newton's Cafe
**Objetivo:** Help Newton Mouse treat all his pals to a cheese dinner.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **174 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 6 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 11 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)

---

## HLEV4.yaml - Curious Curie
**Objetivo:** Help Curie Cat get out of the basement. Make her exit the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **658 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 27 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 5 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)

---

## HLEV5.yaml - Cage the Kitty
**Objetivo:** Put Curie Cat in the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Can you think of anything that might "phaze" this dynamite?
- Pipes. Newton Mouse. Does that GENERATE any ideas?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **563 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 4 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)

---

## HLEV6.yaml - Target Practice
**Objetivo:** Use the boxing glove to pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The cannon ball would roll a lot better if there wasn't a wall in the way.
- Place the cannon here to give you the push you need.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **310 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 6 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Sand Dune](../../scenery-review/PART160.png) **Sand Dune**: 2 peça(s)
- ![Desert Dune](../../scenery-review/PART161.png) **Desert Dune**: 2 peça(s)
- ![Sand Hill](../../scenery-review/PART162.png) **Sand Hill**: 3 peça(s)
- ![Tropical Island](../../scenery-review/PART163.png) **Tropical Island**: 2 peça(s)

---

## HLEV7.yaml - Plural Pop
**Objetivo:** Pop both of the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Anti-gravity will move the ball in the right direction.
- Once you get the ball up here, you'll need to "accelerate" it over to the right.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **199 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 11 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 8 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 3 peça(s)

---

## HLEV8.yaml - Laser Coffee.
**Objetivo:** Get the coffee pot off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Did you know three colored laser beams mix to make a single white one?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **357 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 13 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 2 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 4 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 1 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 3 peça(s)

---

## HLEV9.yaml - Newton Goes Bowling
**Objetivo:** Put the bowling ball into the cardboard box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- You'll need help to turn on the generator as you push down the plunger. (A bucket-load of help!)

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **273 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 9 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 12 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/PART110_f000.png) **Elm Tree**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 12 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 3 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 10 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 3 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 3 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 3 peça(s)

---

## HLEV10.yaml - Toast Roast
**Objetivo:** It's breakfast time. Let's roast some toast.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Even a mouse could pop open the Jack-in-the-box.
- Use mouse power to get the ball over to the toaster.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **461 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 2 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 3 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 2 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 3 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 1 peça(s)
- ![Green Cliff](../../scenery-review/PART217.png) **Green Cliff**: 1 peça(s)
- ![Shipwreck](../../scenery-review/PART218.png) **Shipwreck**: 1 peça(s)
- ![Submarine](../../scenery-review/PART219.png) **Submarine**: 1 peça(s)
- ![Ancient Ruins](../../scenery-review/PART220.png) **Ancient Ruins**: 1 peça(s)
- ![Stone Temple](../../scenery-review/PART221.png) **Stone Temple**: 1 peça(s)

---

## HLEV11.yaml - Clash of the Critters
**Objetivo:** Help Curie Cat and Newton Mouse blow each other off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Carefully placed explosives could do a double duty.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **488 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 14 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## HLEV12.yaml - Cheese Please!
**Objetivo:** Put Newton Mouse into the cage at the bottom. Put the center piece of cheese in with him.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Whatever is placed here should help the ball get to the timer, and clear the way for Newton.
- What happens when cheese chunks collide?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **406 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 5 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 9 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 7 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## HLEV13.yaml - Danger Blimp
**Objetivo:** Get the blimp into the hangar on the left.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **262 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 6 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 3 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 5 peça(s)

---

## HLEV14.yaml - Pompeian Rhapsody
**Objetivo:** Light the candle and turn on the lava lamp.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- There must be some trick to a match-on-a-stick!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **120 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 13 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 11 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 7 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## HLEV15.yaml - Blimp-Be-Gone
**Objetivo:** Blow up the blimp before it can get off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Something as small as a mouse can start off this whole puzzle.
- Something you See (or Saw) in the parts bin might be a tip-off.
- The blimp's starting point is also the missile's launching point.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **299 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 8 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV16.yaml - Newton's Special Brew
**Objetivo:** Get the coffee to start brewing.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- A perfect place to catch some wind.
- A grand place for Newton's favorite dairy product.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **300 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 9 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 19 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/PART130_f000.png) **Glass Building**: 9 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/PART131_f000.png) **apartment building**: 1 peça(s)
- ![office building](../../build/phase-3/bitmaps/PART132_f000.png) **office building**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/PART134_f000.png) **lamp post**: 1 peça(s)
- ![fire hydrant](../../build/phase-3/bitmaps/PART135_f000.png) **fire hydrant**: 1 peça(s)

---

## HLEV17.yaml - Mel on the Move
**Objetivo:** Help Mel get safely home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Something just isn't connecting. What Mel needs is a "phazer-totter."
- Think Jericho, 800 B.C. Think "boom!"

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **383 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 17 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 4 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 3 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 11 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/PART104_f000.png) **Wooden Barrier**: 3 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)

---

## HLEV18.yaml - Edison's Breakfast
**Objetivo:** Turn on the can opener.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Reach deep down into your evil side. What would you really like to do to this happy face balloon?
- Some toast would go nicely with that delicious can of kitty food.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **560 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 6 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 4 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/PART104_f000.png) **Wooden Barrier**: 13 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)

---

## HLEV19.yaml - Mel's Mine Field
**Objetivo:** Get Mel or any of his friends to the house.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **363 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 10 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 14 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 3 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/PART110_f000.png) **Elm Tree**: 5 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 6 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)

---

## HLEV20.yaml - Mel Takes a Hike
**Objetivo:** Set off the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- If Mel could only get over to those flint rocks, I'll bet he could spark some interesting events.
- This wall needs to go.
- Gravity, in this case, is working against us in two ways.
- Color is important when it comes to switches.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **639 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 9 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Spiral Galaxy](../../scenery-review/PART172.png) **Spiral Galaxy**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 2 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 2 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## HLEV21.yaml - The Big Balloon Bummer
**Objetivo:** Pop all the balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **286 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 10 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 1 peça(s)
- ![desert mesa](../../build/phase-3/bitmaps/PART129_f000.png) **desert mesa**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 3 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 4 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/PART146_f000.png) **small mesa**: 2 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/PART147_f000.png) **medium mesa**: 1 peça(s)
- ![Erupting Volcano](../../scenery-review/PART199.png) **Erupting Volcano**: 1 peça(s)
- ![Red Coral Branch](../../scenery-review/PART200.png) **Red Coral Branch**: 1 peça(s)
- ![Red Coral](../../scenery-review/PART202.png) **Red Coral**: 2 peça(s)

---

## HLEV22.yaml - Jolly Jolly Jumpin' Jack
**Objetivo:** Make Jack pop out of his box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **468 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 20 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 4 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/PART146_f000.png) **small mesa**: 2 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/PART147_f000.png) **medium mesa**: 2 peça(s)
- ![Red Canyon](../../scenery-review/PART164.png) **Red Canyon**: 3 peça(s)
- ![Red Rock](../../scenery-review/PART165.png) **Red Rock**: 3 peça(s)
- ![Red Formation](../../scenery-review/PART166.png) **Red Formation**: 2 peça(s)
- ![Volcano](../../scenery-review/PART198.png) **Volcano**: 2 peça(s)
- ![Erupting Volcano](../../scenery-review/PART199.png) **Erupting Volcano**: 1 peça(s)
- ![Red Coral Branch](../../scenery-review/PART200.png) **Red Coral Branch**: 3 peça(s)
- ![Red Seaweed](../../scenery-review/PART201.png) **Red Seaweed**: 2 peça(s)
- ![Red Coral](../../scenery-review/PART202.png) **Red Coral**: 3 peça(s)

---

## HLEV23.yaml - Rocket Racket
**Objetivo:** Make the rocket fly off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **453 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 5 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 4 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 18 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 3 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 3 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 3 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 8 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## HLEV24.yaml - Trick Shot
**Objetivo:** Put the 2 ball into the middle pocket at the bottom of the screen, and put the 3 ball into the top left corner pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **123 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 9 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)

---

## HLEV25.yaml - Fire Show Shenanigans
**Objetivo:** Set off all the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **406 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 7 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 9 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 11 peça(s)
- ![tile](../../build/phase-3/bitmaps/PART123_f000.png) **tile**: 3 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 2 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## HLEV26.yaml - Late for Breakfast
**Objetivo:** Make some toast and launch the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 35 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **625 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 4 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Archway](../../build/phase-3/bitmaps/PART103_f000.png) **Archway**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/PART104_f000.png) **Wooden Barrier**: 3 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 5 peça(s)
- ![Sand Dune](../../scenery-review/PART160.png) **Sand Dune**: 3 peça(s)
- ![Desert Dune](../../scenery-review/PART161.png) **Desert Dune**: 2 peça(s)
- ![Sand Hill](../../scenery-review/PART162.png) **Sand Hill**: 1 peça(s)
- ![Tropical Island](../../scenery-review/PART163.png) **Tropical Island**: 2 peça(s)

---

## HLEV27.yaml - Curie and the Cannon
**Objetivo:** Fire the cannon and put the laundry basket over Curie Cat.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **683 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 4 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Archway](../../build/phase-3/bitmaps/PART103_f000.png) **Archway**: 8 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 3 peça(s)
- ![Ship Logo](../../scenery-review/PART230.png) **Ship Logo**: 1 peça(s)

---

## HLEV28.yaml - Patriotic Pop-A-Thon
**Objetivo:** Pop the balloon in the top right corner of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **671 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 5 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 4 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 8 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 9 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 3 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 50 peça(s)

---

## HLEV29.yaml - Immobilized Mel
**Objetivo:** Help Mel get to the floor at the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **331 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 6 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 12 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 17 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 5 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Blue Space](../../scenery-review/PART205.png) **Blue Space**: 3 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 1 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 3 peça(s)
- ![Coral Arch](../../scenery-review/PART212.png) **Coral Arch**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Coral Formation](../../scenery-review/PART214.png) **Coral Formation**: 1 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 2 peça(s)
- ![Sea Urchin](../../scenery-review/PART248.png) **Sea Urchin**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 2 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 1 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 4 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 2 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 2 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 1 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 2 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 8 peça(s)

---

## HLEV30.yaml - Free Smiley
**Objetivo:** Make the smiley face balloon fly off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **364 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 8 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/PART115_f000.png) **Little Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 1 peça(s)
- ![Trees on Rocks](../../scenery-review/PART155.png) **Trees on Rocks**: 1 peça(s)
- ![Einstein Bust](../../scenery-review/PART274.png) **Einstein Bust**: 1 peça(s)
- ![Wooden Door](../../scenery-review/PART279.png) **Wooden Door**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 1 peça(s)

---

## HLEV31.yaml - Rocketropolis
**Objetivo:** Launch the rocket off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **454 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 11 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 3 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 18 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/PART130_f000.png) **Glass Building**: 3 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/PART131_f000.png) **apartment building**: 1 peça(s)
- ![office building](../../build/phase-3/bitmaps/PART132_f000.png) **office building**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 1 peça(s)
- ![Sphinx Pyramid](../../scenery-review/PART182.png) **Sphinx Pyramid**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![Cityscape](../../scenery-review/PART185.png) **Cityscape**: 1 peça(s)
- ![Metropolis](../../scenery-review/PART186.png) **Metropolis**: 1 peça(s)
- ![City Buildings](../../scenery-review/PART187.png) **City Buildings**: 3 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 2 peça(s)

---

## MLEV1.yaml - Mountain Man Mel
**Objetivo:** Get Mel to his cabin.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- What a lovely spot for a balloon!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **689 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 5 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 3 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/PART110_f000.png) **Elm Tree**: 2 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 3 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/PART115_f000.png) **Little Cloud**: 8 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 2 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/PART141_f000.png) **Small Maple Tree**: 3 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 4 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 1 peça(s)

---

## MLEV2.yaml - Mondrian's Toy Box
**Objetivo:** Make all five Jack-in-the-boxes pop open.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Find a way to turn these gears. They all appear to be connected.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **144 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 14 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 5 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 7 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 18 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 15 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 7 peça(s)

---

## MLEV3.yaml - Gimpy Blimpy
**Objetivo:** Get the balloon off the top of the screen without popping any blimps.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- I wonder if a little tube of something explosive might fit between the blimps?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **282 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 15 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)

---

## MLEV4.yaml - Pipe Gripe
**Objetivo:** Get the Pinball off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- A little acceleration might be in order right about here.
- This looks like the only place on the screen the ball can get out.
- The shortest route is a straight line... but sometimes that just isn't an option.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **45 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 6 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 11 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 10 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 6 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/PART98_f000.png) **T-Connector**: 2 peça(s)

---

## MLEV5.yaml - Up and Away!
**Objetivo:** Launch the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Try some negative gravity on this pinball.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **175 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 8 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 5 peça(s)
- ![Rocky Mountain](../../scenery-review/PART154.png) **Rocky Mountain**: 2 peça(s)
- ![Trees on Rocks](../../scenery-review/PART155.png) **Trees on Rocks**: 2 peça(s)
- ![Trees on Terrain](../../scenery-review/PART156.png) **Trees on Terrain**: 3 peça(s)
- ![Moon Crater](../../scenery-review/PART170.png) **Moon Crater**: 1 peça(s)
- ![Owl](../../scenery-review/PART171.png) **Owl**: 1 peça(s)
- ![Red Coral Branch](../../scenery-review/PART200.png) **Red Coral Branch**: 4 peça(s)
- ![Red Seaweed](../../scenery-review/PART201.png) **Red Seaweed**: 3 peça(s)
- ![Red Coral](../../scenery-review/PART202.png) **Red Coral**: 3 peça(s)

---

## MLEV6.yaml - Mouse House Munchies
**Objetivo:** Feed Newton Mouse the cheese.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- The balloon tied to this rope is dying to "cut loose."

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **323 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 3 peça(s)
- ![tile](../../build/phase-3/bitmaps/PART122_f000.png) **tile**: 1 peça(s)
- ![Computer Monitor](../../scenery-review/PART272.png) **Computer Monitor**: 1 peça(s)
- ![Metal Vent](../../scenery-review/PART273.png) **Metal Vent**: 2 peça(s)
- ![Cliff Edge](../../scenery-review/PART276.png) **Cliff Edge**: 1 peça(s)
- ![Periodic Table](../../scenery-review/PART278.png) **Periodic Table**: 1 peça(s)

---

## MLEV7.yaml - Laser Launch
**Objetivo:** Launch the rocket off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Use a conveyor belt to move the rocket into the pit on the right.
- Use some pipes to get the ball going in the right direction.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **350 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 3 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 15 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## MLEV8.yaml - Fire Ball
**Objetivo:** Launch the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The right combination of parts will force the trap door to open.
- A plumber's nightmare--a soccer ball in the pipes.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **331 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 3 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 10 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 16 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)

---

## MLEV9.yaml - Fourth of July
**Objetivo:** Launch all the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- If there was just a little more time, you could light the candle.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **369 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 6 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 4 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 2 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 7 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## MLEV10.yaml - Beach Ball Bonanza
**Objetivo:** Put the striped ball into the bucket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The mouse motor can power the generator.
- It would be FANtastic to turn this pinwheel, which could then turn the conveyor belt.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **363 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 9 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 12 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/PART146_f000.png) **small mesa**: 1 peça(s)

---

## MLEV11.yaml - Cat Bounce
**Objetivo:** Pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Use some mouse power to generate electricity.
- Curie Cat comes running whenever she hears the can opener.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **462 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 10 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Archway](../../build/phase-3/bitmaps/PART103_f000.png) **Archway**: 3 peça(s)

---

## MLEV12.yaml - Laser Target
**Objetivo:** Shoot the sensor at the bottom right with the laser.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Pull down on the chain.
- This is a dual-purpose pinball.
- It's done with mirrors.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **317 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 8 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 4 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 3 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 9 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## MLEV13.yaml - Breakfast Buffet
**Objetivo:** Make coffee and toast.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Place the mouse motor here so the tennis ball can roll over it.
- With a little luck, a timer will push the tennis ball to the toaster.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **236 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 10 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 27 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 5 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 4 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 2 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 5 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 8 peça(s)

---

## MLEV14.yaml - Pipe Mixer
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- There's too much gravity here!

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **165 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 7 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 7 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)

---

## MLEV15.yaml - Fishing in Rome
**Objetivo:** Break the fish tank.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- What goes up doesn't always come down.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 16 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **357 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 2 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 12 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)

---

## MLEV16.yaml - Bomb Baffle
**Objetivo:** Set off both bombs.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- See what happens if you pull down and push up at the same time.
- This appears to be the only object with enough potential energy to do anything.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **247 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 6 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## MLEV17.yaml - Bowl Me Over
**Objetivo:** Put the bowling ball into the cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- You could get some real mouse power going here.
- Keep it moving...

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1008_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **202 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 11 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## MLEV18.yaml - Mel in a Muddle
**Objetivo:** Get Mel home in one piece!

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- A timer here would not only help Mel across, but also get the pinball moving.
- Mel is a little off-balance in this one.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 22 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **380 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 14 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 10 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## MLEV19.yaml - Mel's Amazing Maze
**Objetivo:** Get Mel home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- A remote bomb plunger goes here. Set the bomb itself to the left so it can blow a hole in the floor.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_0_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **394 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 8 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 12 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## MLEV20.yaml - Illuminate the Lab
**Objetivo:** Turn on the lava lamp on top of Mel's underwater laboratory.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 128

**Dicas Ativas (2):**
- This pinball needs to float.
- Push down on this teeter-totter.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **364 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 1 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 6 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 8 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 1 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Ship Logo](../../scenery-review/PART230.png) **Ship Logo**: 1 peça(s)
- ![Starfish](../../scenery-review/PART236.png) **Starfish**: 1 peça(s)
- ![Green Coral](../../scenery-review/PART240.png) **Green Coral**: 1 peça(s)
- ![Coral Tree](../../scenery-review/PART241.png) **Coral Tree**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 4 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Sea Urchin](../../scenery-review/PART248.png) **Sea Urchin**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 1 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 2 peça(s)
- ![Fish School](../../scenery-review/PART257.png) **Fish School**: 2 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 6 peça(s)
- ![Dolphin](../../scenery-review/PART261.png) **Dolphin**: 3 peça(s)
- ![Orca Whale](../../scenery-review/PART262.png) **Orca Whale**: 1 peça(s)

---

## MLEV21.yaml - Blow Up
**Objetivo:** Make the balloon fly off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Don't forget to cut the rope, or the balloon will never take off!
- Give the baseball some help over to the remote plunger.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **211 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)

---

## MLEV22.yaml - Gravity Cavity
**Objetivo:** Put the soccer ball in the caution box with the 1-ball.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- How can one CONVEY the marvels of soccer?

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **177 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 4 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 12 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## MLEV23.yaml - The Sky is Falling!
**Objetivo:** Mel is in trouble. Help him get to his house in the upper right.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Find a way to stop these buckets from falling.
- Unless he can find a way to float, Mel will fall through this hole.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **360 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 4 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 4 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 4 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/PART110_f000.png) **Elm Tree**: 4 peça(s)
- ![tile](../../build/phase-3/bitmaps/PART123_f000.png) **tile**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/PART130_f000.png) **Glass Building**: 1 peça(s)
- ![office building](../../build/phase-3/bitmaps/PART132_f000.png) **office building**: 1 peça(s)
- ![car](../../build/phase-3/bitmaps/PART133_f000.png) **car**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/PART134_f000.png) **lamp post**: 4 peça(s)
- ![fire hydrant](../../build/phase-3/bitmaps/PART135_f000.png) **fire hydrant**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/PART141_f000.png) **Small Maple Tree**: 3 peça(s)

---

## MLEV24.yaml - Stop the Invasion
**Objetivo:** Blow up all of the blimps.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- This blimp will help in the destruction of the others.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **207 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 5 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 8 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 3 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 17 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 36 peça(s)
- ![Stalactites](../../scenery-review/PART180.png) **Stalactites**: 1 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 1 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Satellite Tower](../../scenery-review/PART192.png) **Satellite Tower**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Dish Antenna](../../scenery-review/PART194.png) **Dish Antenna**: 1 peça(s)
- ![Glass Dome](../../scenery-review/PART195.png) **Glass Dome**: 2 peça(s)
- ![Crystal Formation](../../scenery-review/PART196.png) **Crystal Formation**: 1 peça(s)

---

## MLEV25.yaml - Mel-O-Drama
**Objetivo:** Help Mel make it home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Mel could use a little help from his mouse friends.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 23 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **556 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 9 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/PART115_f000.png) **Little Cloud**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![desert mesa](../../build/phase-3/bitmaps/PART129_f000.png) **desert mesa**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![small mesa](../../build/phase-3/bitmaps/PART146_f000.png) **small mesa**: 1 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/PART147_f000.png) **medium mesa**: 1 peça(s)
- ![Red Canyon](../../scenery-review/PART164.png) **Red Canyon**: 1 peça(s)
- ![Red Rock](../../scenery-review/PART165.png) **Red Rock**: 2 peça(s)
- ![Red Formation](../../scenery-review/PART166.png) **Red Formation**: 1 peça(s)
- ![Castle Fortress](../../scenery-review/PART167.png) **Castle Fortress**: 1 peça(s)

---

## MLEV26.yaml - Lunar Base Take-off
**Objetivo:** Launch the rocket off the top of the screen.

**Ambiente:**
- Gravidade: 0
- Pressão do Ar: 0

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1023_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 25 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **517 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 19 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 1 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 1 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 6 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![Sci-Fi City](../../scenery-review/PART184.png) **Sci-Fi City**: 3 peça(s)
- ![Cityscape](../../scenery-review/PART185.png) **Cityscape**: 3 peça(s)
- ![Metropolis](../../scenery-review/PART186.png) **Metropolis**: 3 peça(s)
- ![City Buildings](../../scenery-review/PART187.png) **City Buildings**: 3 peça(s)
- ![Ice Castle](../../scenery-review/PART188.png) **Ice Castle**: 2 peça(s)
- ![Crystal Tower](../../scenery-review/PART189.png) **Crystal Tower**: 1 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Glass Dome](../../scenery-review/PART195.png) **Glass Dome**: 1 peça(s)
- ![Dark Space](../../scenery-review/PART203.png) **Dark Space**: 1 peça(s)

---

## MLEV27.yaml - Flight through the Alps
**Objetivo:** Launch the balloon off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 29 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **338 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 10 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 10 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 4 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 3 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 5 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 5 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 6 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)

---

## MLEV28.yaml - Soccer Shocker
**Objetivo:** Put the soccer ball into the wooden crate.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 31 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **381 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 14 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 11 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![Mountain Range](../../scenery-review/PART197.png) **Mountain Range**: 1 peça(s)
- ![Volcano](../../scenery-review/PART198.png) **Volcano**: 1 peça(s)
- ![Blue Space](../../scenery-review/PART205.png) **Blue Space**: 1 peça(s)
- ![Ocean Wave](../../scenery-review/PART206.png) **Ocean Wave**: 1 peça(s)
- ![Breaking Wave](../../scenery-review/PART207.png) **Breaking Wave**: 1 peça(s)
- ![Surf Wave](../../scenery-review/PART208.png) **Surf Wave**: 2 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)

---

## MLEV29.yaml - Pinball Puzzler
**Objetivo:** Make the pinball in the upper left corner fall off the bottom of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **94 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 3 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 18 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 11 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 3 peça(s)
- ![T-Connector](../../build/phase-3/bitmaps/PART98_f000.png) **T-Connector**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![tile](../../build/phase-3/bitmaps/PART122_f000.png) **tile**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## MLEV30.yaml - All Terrain Pinball
**Objetivo:** Put the pinball into the wicker basket and activate the computer terminal.

**Ambiente:**
- Gravidade: 143
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **232 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 13 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 3 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 7 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 8 peça(s)
- ![Spruce Tree](../../build/phase-3/bitmaps/PART111_f000.png) **Spruce Tree**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 2 peça(s)
- ![tile](../../build/phase-3/bitmaps/PART123_f000.png) **tile**: 2 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 3 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/PART141_f000.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 2 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 3 peça(s)
- ![Coral Arch](../../scenery-review/PART212.png) **Coral Arch**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Hot Rod Car](../../scenery-review/PART226.png) **Hot Rod Car**: 1 peça(s)
- ![Clown Fish](../../scenery-review/PART227.png) **Clown Fish**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 5 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 2 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 6 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 2 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 1 peça(s)
- ![Seaweed Long](../../scenery-review/PART246.png) **Seaweed Long**: 1 peça(s)
- ![Plant Stem](../../scenery-review/PART247.png) **Plant Stem**: 1 peça(s)
- ![Sea Urchin](../../scenery-review/PART248.png) **Sea Urchin**: 1 peça(s)
- ![Red Crab](../../scenery-review/PART249.png) **Red Crab**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Octopus](../../scenery-review/PART251.png) **Octopus**: 1 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 3 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 1 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 2 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)
- ![Dolphin](../../scenery-review/PART261.png) **Dolphin**: 1 peça(s)
- ![Tree Trunk](../../scenery-review/PART267.png) **Tree Trunk**: 1 peça(s)

---

## RLEV1.yaml - Exit Laughing
**Objetivo:** Make the happy face balloon exit the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **354 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 4 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 2 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 18 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 1 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Treasure Chest](../../scenery-review/PART229.png) **Treasure Chest**: 1 peça(s)
- ![Ship Logo](../../scenery-review/PART230.png) **Ship Logo**: 1 peça(s)
- ![Shell](../../scenery-review/PART233.png) **Shell**: 1 peça(s)
- ![Shell Spiral](../../scenery-review/PART234.png) **Shell Spiral**: 2 peça(s)
- ![Metal Gears](../../scenery-review/PART237.png) **Metal Gears**: 4 peça(s)
- ![Orange Coral](../../scenery-review/PART238.png) **Orange Coral**: 2 peça(s)
- ![Coral Branch](../../scenery-review/PART239.png) **Coral Branch**: 2 peça(s)
- ![Green Coral](../../scenery-review/PART240.png) **Green Coral**: 2 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 2 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 4 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 3 peça(s)
- ![Striped Fish](../../scenery-review/PART252.png) **Striped Fish**: 2 peça(s)
- ![Goldfish](../../scenery-review/PART254.png) **Goldfish**: 1 peça(s)
- ![Seahorse](../../scenery-review/PART255.png) **Seahorse**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 4 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)
- ![Orca Whale](../../scenery-review/PART262.png) **Orca Whale**: 1 peça(s)
- ![Gray Whale](../../scenery-review/PART263.png) **Gray Whale**: 1 peça(s)

---

## RLEV2.yaml - The Critter-Gitter Cat Trap
**Objetivo:** Trap Curie Cat in the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **448 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 14 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Stained Glass](../../scenery-review/PART268.png) **Stained Glass**: 1 peça(s)
- ![Abstract Art](../../scenery-review/PART269.png) **Abstract Art**: 1 peça(s)
- ![Landscape Painting](../../scenery-review/PART270.png) **Landscape Painting**: 1 peça(s)
- ![Einstein Bust](../../scenery-review/PART274.png) **Einstein Bust**: 1 peça(s)

---

## RLEV3.yaml - Lil' Mel's Jail Break
**Objetivo:** Assist Mel in his daring escape and journey home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **602 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 17 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 5 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 5 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![apartment building](../../build/phase-3/bitmaps/PART131_f000.png) **apartment building**: 2 peça(s)
- ![office building](../../build/phase-3/bitmaps/PART132_f000.png) **office building**: 3 peça(s)

---

## RLEV4.yaml - Laser Balloon Blitz
**Objetivo:** Pop the balloon.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **530 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 9 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 4 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 3 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 1 peça(s)
- ![Pine Forest](../../scenery-review/PART150.png) **Pine Forest**: 3 peça(s)
- ![Cave Opening](../../scenery-review/PART151.png) **Cave Opening**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 1 peça(s)
- ![Rocky Terrain](../../scenery-review/PART153.png) **Rocky Terrain**: 2 peça(s)
- ![Trees on Terrain](../../scenery-review/PART156.png) **Trees on Terrain**: 1 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 1 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 1 peça(s)
- ![Castle Fortress](../../scenery-review/PART167.png) **Castle Fortress**: 1 peça(s)

---

## RLEV5.yaml - Balloon Over Manhattan
**Objetivo:** Make the balloon fly off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **184 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 6 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 6 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 4 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 6 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 2 peça(s)
- ![Glass Building](../../build/phase-3/bitmaps/PART130_f000.png) **Glass Building**: 3 peça(s)
- ![office building](../../build/phase-3/bitmaps/PART132_f000.png) **office building**: 1 peça(s)
- ![Stalactites](../../scenery-review/PART180.png) **Stalactites**: 1 peça(s)
- ![Greenhouse Dome](../../scenery-review/PART181.png) **Greenhouse Dome**: 1 peça(s)
- ![Sphinx Pyramid](../../scenery-review/PART182.png) **Sphinx Pyramid**: 1 peça(s)
- ![Futuristic Tower](../../scenery-review/PART183.png) **Futuristic Tower**: 1 peça(s)
- ![Sci-Fi City](../../scenery-review/PART184.png) **Sci-Fi City**: 1 peça(s)
- ![Cityscape](../../scenery-review/PART185.png) **Cityscape**: 1 peça(s)
- ![Crystal Tower](../../scenery-review/PART189.png) **Crystal Tower**: 1 peça(s)
- ![City Skyline](../../scenery-review/PART190.png) **City Skyline**: 4 peça(s)
- ![Totem Pole](../../scenery-review/PART191.png) **Totem Pole**: 1 peça(s)
- ![Satellite Tower](../../scenery-review/PART192.png) **Satellite Tower**: 1 peça(s)
- ![Radio Tower](../../scenery-review/PART193.png) **Radio Tower**: 1 peça(s)
- ![Glass Dome](../../scenery-review/PART195.png) **Glass Dome**: 1 peça(s)

---

## RLEV6.yaml - Pool Ball Sinker
**Objetivo:** Sink the eight ball.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1010_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 20 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **310 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 2 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 1 peça(s)

---

## RLEV7.yaml - Mega-Launch
**Objetivo:** Launch the missile, the rocket, and the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 27 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **585 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 9 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 8 peça(s)

---

## RLEV8.yaml - Newton's Dilemma
**Objetivo:** Get Newton safely home to his mouse hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **430 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 9 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 2 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 15 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 6 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 1 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV9.yaml - Brain Teaser Breakout
**Objetivo:** Lift the basket off of Newton so he can eat the cheese.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **349 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 4 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 15 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 10 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## RLEV10.yaml - Jack's Big Fan
**Objetivo:** Make the Jack-in-the-box pop out.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **441 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 14 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 13 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV11.yaml - Illuminated Schlemming
**Objetivo:** Light both candles and get Mel home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **629 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 4 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 14 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 3 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 2 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## RLEV12.yaml - Schlemming in Dreamland
**Objetivo:** Mel is sleep walking. Help him get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 19 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **393 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 5 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 5 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 10 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 3 peça(s)
- ![small mountain](../../build/phase-3/bitmaps/PART144_f000.png) **small mountain**: 2 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Star Glow](../../scenery-review/PART177.png) **Star Glow**: 3 peça(s)
- ![Star Burst](../../scenery-review/PART178.png) **Star Burst**: 16 peça(s)
- ![Star Sparkle](../../scenery-review/PART179.png) **Star Sparkle**: 9 peça(s)

---

## RLEV13.yaml - Lasermania
**Objetivo:** Use the lasers to power the electric can-opener.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **448 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 4 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 4 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 5 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 5 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 16 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 5 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 6 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## RLEV14.yaml - Ballistic Balloon
**Objetivo:** Put the balloon inside the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 32 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **613 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 6 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 10 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 4 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 2 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Wooden Barrier](../../build/phase-3/bitmaps/PART104_f000.png) **Wooden Barrier**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 3 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV15.yaml - Missile vs. Blimp
**Objetivo:** Remove the green blimp from the skies.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 31 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **651 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 4 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 3 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 3 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 12 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 2 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)

---

## RLEV16.yaml - Rodent Restaurant
**Objetivo:** Newton Mouse is ready for breakfast. Brew up some coffee and start the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 41 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **814 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 3 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 5 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 3 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## RLEV17.yaml - Fireworks Berserk
**Objetivo:** Set off the fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 45 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **1422 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 5 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 7 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 4 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![lamp post](../../build/phase-3/bitmaps/PART134_f000.png) **lamp post**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)
- ![medium mesa](../../build/phase-3/bitmaps/PART147_f000.png) **medium mesa**: 1 peça(s)

---

## RLEV18.yaml - Big Job, Little Mouse
**Objetivo:** Newton Mouse has some major painting to do. Help him lift the leaky paint bucket on the right up above his scaffold.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 28 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **676 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 7 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 6 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 5 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 2 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 4 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 8 peça(s)
- ![Archway](../../build/phase-3/bitmaps/PART103_f000.png) **Archway**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 1 peça(s)
- ![Bamboo Fence](../../scenery-review/PART223.png) **Bamboo Fence**: 1 peça(s)
- ![Wooden Door](../../scenery-review/PART279.png) **Wooden Door**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 13 peça(s)

---

## RLEV19.yaml - Fandango
**Objetivo:** Help Newton Mouse cool off by turning on the fan.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 40 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **886 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 9 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 4 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 2 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 1 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 5 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Scaffold Barrier](../../build/phase-3/bitmaps/PART105_f000.png) **Scaffold Barrier**: 2 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 3 peça(s)

---

## RLEV20.yaml - It's Hip to Drip
**Objetivo:** Put the bowling ball into the steel cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **251 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 8 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 13 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)

---

## RLEV21.yaml - Mind-Mixer
**Objetivo:** Turn on the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 30 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **524 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 12 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 4 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![Blue Space](../../scenery-review/PART205.png) **Blue Space**: 10 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 1 peça(s)
- ![Bubble Stream](../../scenery-review/PART210.png) **Bubble Stream**: 3 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Coral Arch](../../scenery-review/PART212.png) **Coral Arch**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Green Mountain](../../scenery-review/PART215.png) **Green Mountain**: 1 peça(s)
- ![Mossy Rock](../../scenery-review/PART216.png) **Mossy Rock**: 1 peça(s)
- ![Green Cliff](../../scenery-review/PART217.png) **Green Cliff**: 1 peça(s)
- ![Seaweed Tall](../../scenery-review/PART242.png) **Seaweed Tall**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 1 peça(s)
- ![Seaweed Vine](../../scenery-review/PART245.png) **Seaweed Vine**: 1 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Fish Scatter](../../scenery-review/PART258.png) **Fish Scatter**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 2 peça(s)

---

## RLEV22.yaml - The Ultimate Schlemming
**Objetivo:** Get Mel home.  Don't allow the red light to blink on the laser-detector.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 29 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **650 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 1 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 7 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 12 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 2 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 1 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 6 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)

---

## RLEV23.yaml - Blast-A-Blimp
**Objetivo:** Blow up the blimp with the missile.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 30 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **478 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Captain Z Super Phazer](../../build/phase-3/bitmaps/PART27_f000.png) **Captain Z Super Phazer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Sun](../../build/phase-3/bitmaps/PART113_f000.png) **Sun**: 1 peça(s)
- ![Big Cloud](../../build/phase-3/bitmaps/PART114_f000.png) **Big Cloud**: 2 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 4 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 9 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 1 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)
- ![Small Cloud](../../build/phase-3/bitmaps/PART143_f000.png) **Small Cloud**: 2 peça(s)
- ![Rising Bubbles](../../scenery-review/PART209.png) **Rising Bubbles**: 2 peça(s)
- ![Floating Bubbles](../../scenery-review/PART211.png) **Floating Bubbles**: 1 peça(s)
- ![Coral Branch](../../scenery-review/PART213.png) **Coral Branch**: 1 peça(s)
- ![Submarine](../../scenery-review/PART219.png) **Submarine**: 1 peça(s)
- ![Kelp Forest](../../scenery-review/PART243.png) **Kelp Forest**: 1 peça(s)
- ![Kelp Plant](../../scenery-review/PART244.png) **Kelp Plant**: 2 peça(s)
- ![Jellyfish](../../scenery-review/PART250.png) **Jellyfish**: 1 peça(s)
- ![Angelfish](../../scenery-review/PART253.png) **Angelfish**: 1 peça(s)
- ![Shark](../../scenery-review/PART256.png) **Shark**: 1 peça(s)
- ![Fish Group](../../scenery-review/PART259.png) **Fish Group**: 3 peça(s)
- ![Great White Shark](../../scenery-review/PART260.png) **Great White Shark**: 1 peça(s)

---

## RLEV24.yaml - Enchanted Kingdom
**Objetivo:** Help Mel exit the right side of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **400 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 3 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 5 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 4 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 1 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 4 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 4 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 3 peça(s)
- ![Elm Tree](../../build/phase-3/bitmaps/PART110_f000.png) **Elm Tree**: 2 peça(s)
- ![Little Cloud](../../build/phase-3/bitmaps/PART115_f000.png) **Little Cloud**: 5 peça(s)
- ![Color Block](../../build/phase-3/bitmaps/PART127_f000.png) **Color Block**: 1 peça(s)
- ![Small Maple Tree](../../build/phase-3/bitmaps/PART141_f000.png) **Small Maple Tree**: 1 peça(s)
- ![Small Pine Tree](../../build/phase-3/bitmaps/PART142_f000.png) **Small Pine Tree**: 1 peça(s)
- ![Forest Trees](../../scenery-review/PART152.png) **Forest Trees**: 6 peça(s)
- ![Rocky Mountain](../../scenery-review/PART154.png) **Rocky Mountain**: 7 peça(s)
- ![Trees on Terrain](../../scenery-review/PART156.png) **Trees on Terrain**: 1 peça(s)
- ![Red Canyon](../../scenery-review/PART164.png) **Red Canyon**: 1 peça(s)
- ![Castle Fortress](../../scenery-review/PART167.png) **Castle Fortress**: 1 peça(s)
- ![Moon](../../scenery-review/PART169.png) **Moon**: 1 peça(s)
- ![Wooden Door](../../scenery-review/PART279.png) **Wooden Door**: 1 peça(s)
- ![Stone Texture](../../scenery-review/PART280.png) **Stone Texture**: 4 peça(s)

---

## RLEV25.yaml - Poolin' Around
**Objetivo:** Sink one ball into each hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **123 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 16 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 5 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 6 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 6 peça(s)

---

## RLEV26.yaml - Beam Scream
**Objetivo:** Break the laser beam.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 26 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **354 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Trap Door](../../build/phase-3/bitmaps/PART73_f000.png) **Trap Door**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 3 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 18 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 2 peça(s)
- ![Archway](../../build/phase-3/bitmaps/PART103_f000.png) **Archway**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)
- ![purple mountain](../../build/phase-3/bitmaps/PART128_f000.png) **purple mountain**: 1 peça(s)
- ![medium mountain](../../build/phase-3/bitmaps/PART145_f000.png) **medium mountain**: 1 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 1 peça(s)
- ![Snow Mountains](../../scenery-review/PART157.png) **Snow Mountains**: 2 peça(s)
- ![Iceberg](../../scenery-review/PART158.png) **Iceberg**: 2 peça(s)
- ![Snow Peaks](../../scenery-review/PART159.png) **Snow Peaks**: 1 peça(s)

---

## RLEV27.yaml - Basketball Brain-Buster
**Objetivo:** Send the basketball off the top of the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **239 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 1 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 4 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 1 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 3 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 17 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## RLEV28.yaml - Kitty Catcher
**Objetivo:** Put Curie Cat in the hole on the left. Then trap her with the laundry basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 21 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **470 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 4 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 5 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 8 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 1 peça(s)
- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 1 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 6 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 3 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 3 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 7 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 10 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)

---

## RLEV29.yaml - TIM2 Contest Champion!
**Objetivo:** Congratulations to Richard and William Smith for creating this First Prize Puzzle in the TIM2 Puzzle Contest! Check out their work, and see if you can help Mel get home.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 24 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **657 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 8 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 7 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 7 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 14 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 1 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 11 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 1 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 5 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 1 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 1 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 2 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 7 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## TLEV1.yaml - Balls
**Objetivo:** Knock the eight ball off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Note how the super ball on the left bounces.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1000_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **113 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 2 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 2 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 2 peça(s)

---

## TLEV2.yaml - Walls and Inclines
**Objetivo:** Put both bowling balls into the large column box in the center.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- A wall can be stretched to fit correctly.
- Inclines could help get things rolling in the right direction.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 18 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **292 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 2 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Curved Pipe Wall](../../build/phase-3/bitmaps/PART47_f000.png) **Curved Pipe Wall**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 3 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 3 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 3 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 3 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 2 peça(s)
- ![Log Incline](../../build/phase-3/bitmaps/PART100_f000.png) **Log Incline**: 2 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 6 peça(s)

---

## TLEV3.yaml - Gears and Belts
**Objetivo:** Get all of the basketballs into the piped area.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- Notice that this conveyor belt moves faster than the one above. This is because it is attached to the small gear.
- This conveyor belt moves slower because it is connected to a large gear.
- The small gear will spin two times faster than the large gear.
- Look at the machine on the left side and try to duplicate what you see.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **97 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 3 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 5 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 3 peça(s)
- ![Gear](../../build/phase-3/bitmaps/PART14_f000.png) **Gear**: 8 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Tiny Gear](../../build/phase-3/bitmaps/PART86_f000.png) **Tiny Gear**: 3 peça(s)

---

## TLEV4.yaml - Teeter-Totters & Ropes
**Objetivo:** Put the three bowling balls into the wicker baskets.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Notice how this steel cable goes through the pulleys. This allows the teeter-totter to pull up on an object placed at a higher level.
- Look at the right side of the screen and try to duplicate what you see.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **75 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 3 peça(s)
- ![Wood incline](../../build/phase-3/bitmaps/PART2_f000.png) **Wood incline**: 3 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 3 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 3 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 4 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 2 peça(s)

---

## TLEV5.yaml - Switches and Plugs
**Objetivo:** Start both of the electric mixers.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (6):**
- Notice that these electric plugs do not have a switch. They are always on.
- A ball bumping this switch turns on the power.
- This electric switch has been flipped upside-down. In this position, it must be bumped from below to flip it on.
- A switch that has been turned on may also be turned off by flipping it back to its original position.
- Notice that both plugs and switches have two outlets.
- This ball will turn on a switch placed beneath it. A switch or plug must be set in position before the electric part you wish to plug into it.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 17 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **359 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 5 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 1 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 3 peça(s)
- ![Super Ball](../../build/phase-3/bitmaps/PART59_f000.png) **Super Ball**: 1 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 1 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Brick Incline](../../build/phase-3/bitmaps/PART102_f000.png) **Brick Incline**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## TLEV6.yaml - Motors & Generators
**Objetivo:** Put both bowling balls between the logs.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Connect a belt to this wheel from any rotating power source. The generator will make electricity.
- Plug this motor into any powered outlet and it will run.
- If this conveyor belt is rotating the wrong direction, flip the motor.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 9 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **175 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Generator](../../build/phase-3/bitmaps/PART26_f000.png) **Generator**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 3 peça(s)

---

## TLEV7.yaml - Lights and Solar Panels
**Objetivo:** Turn on all of the lights.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Pull down on this chain to turn on a lava lamp. Rope or steel cable can be attached to the chain.
- Bump the button on top of a flashlight to turn it on.
- The solar panel works like a generator. Get any light to shine on the panel to power the plug.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 15 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **156 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Lava Lamp](../../build/phase-3/bitmaps/PART29_f000.png) **Lava Lamp**: 2 peça(s)
- ![Solar Panel](../../build/phase-3/bitmaps/PART38_f000.png) **Solar Panel**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Electric Motor](../../build/phase-3/bitmaps/PART50_f000.png) **Electric Motor**: 2 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 1 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV8.yaml - Fire
**Objetivo:** Light both candles, both lamps, both flint-rocks, and the match-on-a-spring.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (7):**
- Any light shone through a magnifying glass will start a flame or light a fuse.
- You may need to flip a magnifying glass to make it work.
- To light the match, pull out this pin. A rope or steel cable can be attached to the eye hook.
- Hit the flint rocks with a falling object to light a fire.
- Check out how the other lamp is lit when you run the puzzle.
- Notice how the other candle is lit when you run the puzzle.
- Check out how the other flint rock is lit when you run the puzzle.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **127 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 4 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 4 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Aladdin's Lamp](../../build/phase-3/bitmaps/PART45_f000.png) **Aladdin's Lamp**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 6 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 2 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV9.yaml - Explosives
**Objetivo:** Blow up both remote bombs.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (6):**
- The nitroglycerine will explode if dropped or hit with enough force.
- A light source and magnifying glass will light fuses.
- Push or pull down on the plunger to set off the bomb. A rope or steel cable can be tied to the plunger.
- Notice that not all walls can be blown up.
- Notice that some walls can be destroyed.
- This side is a mirror image of the other.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 13 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **144 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Dynamite](../../build/phase-3/bitmaps/PART19_f000.png) **Dynamite**: 2 peça(s)
- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 2 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 5 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 2 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 8 peça(s)
- ![Programmable Ball](../../build/phase-3/bitmaps/PART87_f000.png) **Programmable Ball**: 1 peça(s)

---

## TLEV10.yaml - Things That Launch
**Objetivo:** Launch all the rockets, missiles, and fireworks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- A fuse can be lit with fire or by shining light through a magnifying glass.
- When a missile collides with something, it will explode.
- When lit, this part will explode into fireworks before leaving the screen. It's a programmable part.
- Missiles and rockets can be launched horizontally, fireworks can't.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 14 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **520 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 3 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 3 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 4 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Missile](../../build/phase-3/bitmaps/PART70_f000.png) **Missile**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Fireworks](../../build/phase-3/bitmaps/PART80_f000.png) **Fireworks**: 2 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 2 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)

---

## TLEV11.yaml - Cannons
**Objetivo:** Fire all of the cannons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Direct flame may be used to light fuses.
- Magnified light may be used to light fuses.
- Cannons can be flipped in six directions.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1009_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **174 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 1 peça(s)
- ![Cannon](../../build/phase-3/bitmaps/PART18_f000.png) **Cannon**: 6 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 4 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 5 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 4 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)

---

## TLEV12.yaml - Fan, Pinwheel, Bike Pump
**Objetivo:** Put a bowling ball into each steel cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Plug a fan into any electric power source to make it run.
- Use wind from the fan or bike pump to turn the pinwheel. The pinwheel may be flipped if you want to change the direction it rotates.
- Push down on the bike pump and air will come out the front.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **153 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 4 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 4 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Bike Pump](../../build/phase-3/bitmaps/PART16_f000.png) **Bike Pump**: 2 peça(s)
- ![Electric Fan](../../build/phase-3/bitmaps/PART24_f000.png) **Electric Fan**: 2 peça(s)
- ![Pinwheel](../../build/phase-3/bitmaps/PART40_f000.png) **Pinwheel**: 4 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 4 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## TLEV13.yaml - Balloons
**Objetivo:** Pop the happy face balloon, but none of the others.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Hedge trimmers, tin snips, and tacks will pop balloons.
- Fire and explosions will pop balloons.
- Balloons can pull some objects upward.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1011_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **85 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Brick Wall](../../build/phase-3/bitmaps/PART1_f000.png) **Brick Wall**: 1 peça(s)
- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 6 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 1 peça(s)
- ![Nitroglycerine](../../build/phase-3/bitmaps/PART74_f000.png) **Nitroglycerine**: 1 peça(s)

---

## TLEV14.yaml - Blimps
**Objetivo:** Pop all of the blimps.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- A burning blimp can light fuses, candles, and oil lamps.
- A blimp will explode if it comes in contact with any fire.
- If a blimp bumps into hedge trimmers, tin snips, or a tack it will pop.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **103 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Thumb Tack](../../build/phase-3/bitmaps/PART53_f000.png) **Thumb Tack**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 1 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 4 peça(s)
- ![Candle](../../build/phase-3/bitmaps/PART138_f000.png) **Candle**: 1 peça(s)

---

## TLEV15.yaml - Hot Air Balloons
**Objetivo:** Launch all of the hot air balloons.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Light the candle in the balloon to make it rise.
- Ropes and cables can be tied to balloons.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 12 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **116 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 1 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 1 peça(s)
- ![Flashlight](../../build/phase-3/bitmaps/PART25_f000.png) **Flashlight**: 1 peça(s)
- ![Magnifying Glass](../../build/phase-3/bitmaps/PART30_f000.png) **Magnifying Glass**: 1 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 3 peça(s)
- ![Match-on-a-Spring](../../build/phase-3/bitmaps/PART75_f000.png) **Match-on-a-Spring**: 1 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 1 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 3 peça(s)
- ![Blimp](../../build/phase-3/bitmaps/PART109_f000.png) **Blimp**: 1 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV16.yaml - Anti-Gravity Pad
**Objetivo:** Put one balloon into each yellow brick box.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- These anti-gravity pads will reverse the gravitational pull on an object.
- Notice how the bowling ball rises instead of dropping.
- The anti-gravity pad makes this balloon sink instead of rising.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1012_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **198 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 3 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Rocket](../../build/phase-3/bitmaps/PART36_f000.png) **Rocket**: 1 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 3 peça(s)
- ![Anti-Gravity Pad](../../build/phase-3/bitmaps/PART69_f000.png) **Anti-Gravity Pad**: 6 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 9 peça(s)

---

## TLEV17.yaml - Things That Bounce
**Objetivo:** Put all of the pinballs into a cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (4):**
- Attach a belt from a motor to the Jack-in-the-box to pop it open. Anything on top will be thrown off when it pops open.
- An object bouncing on the springboard will get higher with each bounce.
- The pinball bumper will bounce an object off at any angle desired.
- Drop something on top of this and it will be flipped into the air.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **111 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Jack-in-the-box](../../build/phase-3/bitmaps/PART13_f000.png) **Jack-in-the-box**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Springboard](../../build/phase-3/bitmaps/PART39_f000.png) **Springboard**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 6 peça(s)
- ![Pinball Bumper](../../build/phase-3/bitmaps/PART64_f000.png) **Pinball Bumper**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 3 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 5 peça(s)
- ![Pinball Flipper](../../build/phase-3/bitmaps/PART116_f000.png) **Pinball Flipper**: 2 peça(s)

---

## TLEV18.yaml - Boxing Glove
**Objetivo:** Get both balloons off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Hit the button on the back of this glove to make it punch. Flip it to punch in the other direction.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **77 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Balloon](../../build/phase-3/bitmaps/PART4_f000.png) **Balloon**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Boxing Glove](../../build/phase-3/bitmaps/PART35_f000.png) **Boxing Glove**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)

---

## TLEV19.yaml - Electric Mixer, Can Opener
**Objetivo:** Turn on both electric mixers and open both cans.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Plug the mixer into an electric outlet to turn it on.
- Plug the can opener into an electric outlet to make it open the can.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1014_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 4 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **41 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 4 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 4 peça(s)
- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 2 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 2 peça(s)

---

## TLEV20.yaml - Toasters
**Objetivo:** Make toast in each of the toasters.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- A toaster must be plugged into an outlet to work.
- After a toaster is plugged into an outlet, the handle must be pushed down.
- When the toast pops up, it can push up on objects.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **87 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Tipsy Trailer](../../build/phase-3/bitmaps/PART3_f000.png) **Tipsy Trailer**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 1 peça(s)
- ![Toaster](../../build/phase-3/bitmaps/PART81_f000.png) **Toaster**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)

---

## TLEV21.yaml - Large Pipes
**Objetivo:** Put one bowling ball into each steel cage.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- This accelerator can be flipped to force objects up, down, left, or right. The arrows indicate the direction of acceleration.
- Drop something into this curved pipe and it will come out the other side.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
  - `PipeNetwork (BFS Teleport)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1013_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **61 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 2 peça(s)
- ![Large Curved Pipe](../../build/phase-3/bitmaps/PART57_f000.png) **Large Curved Pipe**: 4 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Accelerator Tube](../../build/phase-3/bitmaps/PART88_f000.png) **Accelerator Tube**: 2 peça(s)
- ![Large Pipes](../../build/phase-3/bitmaps/PART97_f000.png) **Large Pipes**: 2 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 2 peça(s)

---

## TLEV22.yaml - Egg Timer
**Objetivo:** Get all of the pinballs off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- This timer can be programmed so that the little arm will pop out after a set amount of time. Push the button on top to turn it on.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **106 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Remote Control](../../build/phase-3/bitmaps/PART22_f000.png) **Remote Control**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 4 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 4 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 6 peça(s)
- ![Remote Control Explosives](../../build/phase-3/bitmaps/PART55_f000.png) **Remote Control Explosives**: 2 peça(s)
- ![Egg Timer](../../build/phase-3/bitmaps/PART137_f000.png) **Egg Timer**: 4 peça(s)

---

## TLEV23.yaml - Message Machine
**Objetivo:** Turn on all of the computers to read the message.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Drop something on the keyboard to turn on the computer.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **66 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Basketball](../../build/phase-3/bitmaps/PART9_f000.png) **Basketball**: 1 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Soccer Ball](../../build/phase-3/bitmaps/PART68_f000.png) **Soccer Ball**: 1 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 1 peça(s)
- ![Message Computer](../../build/phase-3/bitmaps/PART136_f000.png) **Message Computer**: 6 peça(s)

---

## TLEV24.yaml - Pool Balls, Walls, Cues
**Objetivo:** Put the 6-ball into the bottom right corner pocket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (6):**
- Bump this button on the back of the pool cue to make it spring forward.
- Change the angle at which the pool ball is hit to create a different trajectory.
- These pockets can be rotated to fit any angle on a pool table. If you get a ball close enough to the hole, it will go in.
- This wall can be stretched just like any other. It can also be flipped to a vertical position.
- The pool cue can be rotated to 8 different angles.
- The number on the pool ball can be programmed from 1 to 15. All of the pool balls react the same way.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **151 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Pool Ball](../../build/phase-3/bitmaps/PART63_f000.png) **Pool Ball**: 2 peça(s)
- ![Pool Cue](../../build/phase-3/bitmaps/PART117_f000.png) **Pool Cue**: 4 peça(s)
- ![Pool Table Wall](../../build/phase-3/bitmaps/PART118_f000.png) **Pool Table Wall**: 8 peça(s)
- ![Pool Table Pocket](../../build/phase-3/bitmaps/PART119_f000.png) **Pool Table Pocket**: 8 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 3 peça(s)
- ![Yellow Brick Incline](../../build/phase-3/bitmaps/PART126_f000.png) **Yellow Brick Incline**: 5 peça(s)

---

## TLEV25.yaml - Coffee Pot
**Objetivo:** Blow both hot air balloons off the screen.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Make a fire under the coffee pot and it will blow steam out of its spout.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **106 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Coffee Pot](../../build/phase-3/bitmaps/PART62_f000.png) **Coffee Pot**: 2 peça(s)
- ![Flint & Tinder](../../build/phase-3/bitmaps/PART78_f000.png) **Flint & Tinder**: 2 peça(s)
- ![Hot Air Balloon](../../build/phase-3/bitmaps/PART79_f000.png) **Hot Air Balloon**: 2 peça(s)
- ![Sand Wall](../../build/phase-3/bitmaps/PART82_f000.png) **Sand Wall**: 5 peça(s)

---

## TLEV26.yaml - Lasers
**Objetivo:** Turn on all of the lasers.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Plug lasers into a power plug to make them work.
- Lasers can be flipped up, down, left, or right.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1001_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **80 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 2 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 2 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## TLEV27.yaml - Laser-Activated Plugs
**Objetivo:** Start the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- When a laser of the correct color hits this sensor the power will be turned on.
- Use a blue laser to turn on this switch.
- These plugs are programmable by color. Program the switch to match the laser color.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1015_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **97 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 3 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

## TLEV28.yaml - Laser Mixers
**Objetivo:** Open all of the cans.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Combine two or more laser beams through this mixer to create new laser colors.
- Mix the colors to make a new color that will match each switch.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **227 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Can Opener](../../build/phase-3/bitmaps/PART67_f000.png) **Can Opener**: 3 peça(s)
- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 2 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 2 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 2 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 3 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 3 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)

---

## TLEV29.yaml - Laser Mirrors
**Objetivo:** Start the electric mixer.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Flip the mirrors to angle the lasers in the correct direction.
- Try placing the mirror here. Small adjustments may be needed to get the correct angle on the laser.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1016_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **216 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Angled Mirror](../../build/phase-3/bitmaps/PART94_f000.png) **Angled Mirror**: 5 peça(s)
- ![Laser Mixer](../../build/phase-3/bitmaps/PART95_f000.png) **Laser Mixer**: 1 peça(s)
- ![Laser-Activated Plug](../../build/phase-3/bitmaps/PART96_f000.png) **Laser-Activated Plug**: 1 peça(s)
- ![Electric Mixer](../../build/phase-3/bitmaps/PART107_f000.png) **Electric Mixer**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 2 peça(s)

---

## TLEV30.yaml - Laser Detector
**Objetivo:** Turn on the green light in each of the laser detectors.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- When a laser hits the eye of this detector, the green light will blink. If the beam is shut off, the red light will blink. If the beam then returns, both lights will blink.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
  - `LaserRaycastSystem`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1017_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 5 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **71 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Red Laser](../../build/phase-3/bitmaps/PART91_f000.png) **Red Laser**: 1 peça(s)
- ![Green Laser](../../build/phase-3/bitmaps/PART92_f000.png) **Green Laser**: 1 peça(s)
- ![Blue Laser](../../build/phase-3/bitmaps/PART93_f000.png) **Blue Laser**: 1 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 3 peça(s)
- ![Laser Detector](../../build/phase-3/bitmaps/PART148_f000.png) **Laser Detector**: 3 peça(s)

---

## TLEV31.yaml - Translation & Rotation
**Objetivo:** Put the pinballs into the aquariums.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (5):**
- Pull on this arm with a rope to rotate the center gear.
- The rotation of this gear can be used to power another part.
- Connect a belt from a motor to this wheel to move the arm up and down.
- A rope connected to this arm will pull on the object attached to the other end.
- Push on this end to turn the center gear.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1019_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 10 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **86 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Mouse Motor](../../build/phase-3/bitmaps/PART6_f000.png) **Mouse Motor**: 2 peça(s)
- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)
- ![Trans-Roto-Matic](../../build/phase-3/bitmaps/PART89_f000.png) **Trans-Roto-Matic**: 2 peça(s)
- ![Roto-Trans Converter](../../build/phase-3/bitmaps/PART90_f000.png) **Roto-Trans Converter**: 2 peça(s)

---

## TLEV32.yaml - Buckets
**Objetivo:** Put the two beach buckets up inside the yellow bricks.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- The amount of liquid that drips out of the bucket can be programmed. The faster the bucket drips, the more quickly it becomes lighter.
- Ropes and cables can be tied to buckets.
- Many objects can be dropped into buckets.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1020_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **94 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Pulley](../../build/phase-3/bitmaps/PART7_f000.png) **Pulley**: 4 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 2 peça(s)
- ![Greco-Roman Wall](../../build/phase-3/bitmaps/PART84_f000.png) **Greco-Roman Wall**: 3 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 6 peça(s)

---

## TLEV33.yaml - Snips & Trimmers
**Objetivo:** Put one bucket into each basket.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- The hedge trimmers can only cut rope. They won't work on steel cable.
- Tin snips can cut rope or steel cable.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1021_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 11 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **93 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 3 peça(s)
- ![Bucket](../../build/phase-3/bitmaps/PART17_f000.png) **Bucket**: 3 peça(s)
- ![Boat Cleat](../../build/phase-3/bitmaps/PART23_f000.png) **Boat Cleat**: 5 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Hedge Trimmers](../../build/phase-3/bitmaps/PART37_f000.png) **Hedge Trimmers**: 2 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 5 peça(s)
- ![Steel Cable](../../build/phase-3/bitmaps/PART76_f000.png) **Steel Cable**: 2 peça(s)
- ![Tin Snips](../../build/phase-3/bitmaps/PART77_f000.png) **Tin Snips**: 3 peça(s)
- ![Leaky Bucket](../../build/phase-3/bitmaps/PART108_f000.png) **Leaky Bucket**: 2 peça(s)

---

## TLEV34.yaml - Cats and Aquariums
**Objetivo:** Put all five cats between the pipes.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Fish aquariums will attract cats. Once they are broken they will attract cats from a greater distance.
- Bump the cat to make her take a few steps forward.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1018_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 8 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **362 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 5 peça(s)
- ![Fish Tank](../../build/phase-3/bitmaps/PART15_f000.png) **Fish Tank**: 2 peça(s)
- ![Baseball](../../build/phase-3/bitmaps/PART28_f000.png) **Baseball**: 2 peça(s)
- ![Tennis Ball](../../build/phase-3/bitmaps/PART44_f000.png) **Tennis Ball**: 1 peça(s)
- ![Pipe Wall](../../build/phase-3/bitmaps/PART46_f000.png) **Pipe Wall**: 3 peça(s)
- ![Cinder Block Wall](../../build/phase-3/bitmaps/PART83_f000.png) **Cinder Block Wall**: 6 peça(s)
- ![Granite Incline](../../build/phase-3/bitmaps/PART101_f000.png) **Granite Incline**: 9 peça(s)
- ![Teeter-Totter](../../build/phase-3/bitmaps/PART139_f000.png) **Teeter-Totter**: 1 peça(s)

---

## TLEV35.yaml - Mice and Cheese
**Objetivo:** Get all of the mice to a piece of cheese.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Cheese will attract mice if they can see it. They can't see it from a long distance.
- Curie Cat will chase any mouse she sees. A caught mouse is instant cat food.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1003_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 4 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **272 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Curie Cat](../../build/phase-3/bitmaps/PART12_f000.png) **Curie Cat**: 2 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 5 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 3 peça(s)
- ![Log Wall](../../build/phase-3/bitmaps/PART85_f000.png) **Log Wall**: 5 peça(s)

---

## TLEV36.yaml - Mouse Hole
**Objetivo:** Get a mouse into each mouse hole.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- If a mouse encounters a mouse hole as it is running along it will go inside.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1002_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 4 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **82 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 2 peça(s)
- ![Mouse Hole](../../build/phase-3/bitmaps/PART66_f000.png) **Mouse Hole**: 2 peça(s)
- ![Yellow Brick Wall](../../build/phase-3/bitmaps/PART125_f000.png) **Yellow Brick Wall**: 2 peça(s)

---

## TLEV37.yaml - Mandrill Motor
**Objetivo:** Put a bowling ball inside each crate.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (3):**
- Release this shade and Pavlov Mandrill will walk on the treadmill, trying to get the bananas.
- Connect a belt to this wheel to turn another part.
- Pull down on this lever to flip up the shade.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ConstraintSolver (Ropes & Belts)`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1007_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 7 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **113 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 2 peça(s)
- ![Conveyor Belt](../../build/phase-3/bitmaps/PART5_f000.png) **Conveyor Belt**: 2 peça(s)
- ![Belt](../../build/phase-3/bitmaps/BLANK.png) **Belt**: 2 peça(s)
- ![Rope](../../build/phase-3/bitmaps/PART10_f000.png) **Rope**: 2 peça(s)
- ![Laundry Basket](../../build/phase-3/bitmaps/PART11_f000.png) **Laundry Basket**: 2 peça(s)
- ![Mandrill Motor](../../build/phase-3/bitmaps/PART31_f000.png) **Mandrill Motor**: 2 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 2 peça(s)

---

## TLEV38.yaml - Mel Schlemming
**Objetivo:** Get one Schlemming into each house.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Mel can be programmed to walk, run, or stand still.
- If Mel bumps into something solid he will turn around.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1004_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 3 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **207 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 5 peça(s)
- ![Caution Wall](../../build/phase-3/bitmaps/PART56_f000.png) **Caution Wall**: 5 peça(s)
- ![Mel's House](../../build/phase-3/bitmaps/PART58_f000.png) **Mel's House**: 4 peça(s)

---

## TLEV39.yaml - Edison Alligator
**Objetivo:** Put the pinball into the aquarium.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (2):**
- Edison Alligator will happily eat mice or Mel Schlemming for dinner.
- Edison will toss any object that lands on his nose.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1005_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 9 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **260 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Bowling Ball](../../build/phase-3/bitmaps/PART0_f000.png) **Bowling Ball**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 1 peça(s)
- ![Pinball](../../build/phase-3/bitmaps/PART43_f000.png) **Pinball**: 1 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 1 peça(s)
- ![Mel Schlemming](../../build/phase-3/bitmaps/PART54_f000.png) **Mel Schlemming**: 1 peça(s)
- ![Grass Floor](../../build/phase-3/bitmaps/PART60_f000.png) **Grass Floor**: 4 peça(s)
- ![Alligator](../../build/phase-3/bitmaps/PART61_f000.png) **Alligator**: 3 peça(s)
- ![Boxes](../../build/phase-3/bitmaps/PART71_f000.png) **Boxes**: 1 peça(s)
- ![Grass Incline](../../build/phase-3/bitmaps/PART99_f000.png) **Grass Incline**: 6 peça(s)

---

## TLEV40.yaml - Vacuum
**Objetivo:** Vacuum up both mice.

**Ambiente:**
- Gravidade: 272
- Pressão do Ar: 67

**Dicas Ativas (1):**
- Plug the vacuum into an electric outlet and it will vacuum up anything within range.

**Mapa de Dependências:**
- **Sistemas Físicos Necessários:**
  - `ElectricalPropagationSystem`
  - `GravitySolver (Standard)`
- **Recursos de Áudio:**
  - Música de Fundo: `SX_1006_11025.wav`
  - *Efeitos Sonoros (SFX): Despachados dinamicamente via `AudioDispatcher` pelos comportamentos das peças.*
- **Recursos Visuais (ANM & PNG):**
  - Requer 6 arquivos `.ANM` carregados.
  - Totaliza aproximadamente **165 frames** de sprite PNG na memória de vídeo.

**Setup de Peças (Agrupadas por Tipo):**

- ![Electric Switch & Outlet](../../build/phase-3/bitmaps/PART21_f000.png) **Electric Switch & Outlet**: 1 peça(s)
- ![Newton Mouse](../../build/phase-3/bitmaps/PART42_f000.png) **Newton Mouse**: 2 peça(s)
- ![Wood Wall](../../build/phase-3/bitmaps/PART48_f000.png) **Wood Wall**: 2 peça(s)
- ![Vacuum](../../build/phase-3/bitmaps/PART51_f000.png) **Vacuum**: 2 peça(s)
- ![Cheese](../../build/phase-3/bitmaps/PART52_f000.png) **Cheese**: 2 peça(s)
- ![Electrical Outlet](../../build/phase-3/bitmaps/PART120_f000.png) **Electrical Outlet**: 1 peça(s)

---

