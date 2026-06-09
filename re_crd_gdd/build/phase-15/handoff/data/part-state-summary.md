# Part State Machine Reference

Generated from 433 ANM files (433 entries)

## State ID Legend (from cross-file analysis)

| State ID | Frequency | Parts Using It | Likely Meaning |
|----------|-----------|----------------|----------------|
|   1 | 253 files | BINSOLVE, BUTTONS, CNTRLPNL, CREDITS, GOALBAR | Idle / Default / Ready |
|   2 | 181 files | BINSOLVE, BUTTONS, HANDLES, HEDTOHED, HINTLOCK | Active / Running / Moving |
|   3 |  77 files | BINSOLVE, GOALBAR, HEDTOHED, HINTLOCK, INFO104 | Triggered / Touched / On |
|   4 |  64 files | BINSOLVE, BUTTONS, GOALBAR, HEDTOHED, HINTLOCK | Broken / Destroyed / Off |
|   5 |  40 files | BINSOLVE, BUTTONS, CNTRLPNL, GOALBAR, HEDTOHED | Intermediate state A |
|   6 |  36 files | BINSOLVE, CNTRLPNL, GOALBAR, MAINMENU, PART108 |  |
|   7 |  30 files | BINSOLVE, CNTRLPNL, MAINMENU, PART108, PART109 |  |
|   8 |  30 files | BINSOLVE, CNTRLPNL, HANDLES, MAINMENU, PART108 |  |
|   9 |  30 files | MAINMENU, PART108, PART117, PART119, PART12 |  |
|  10 |  20 files | HANDLES, MAINMENU, PART108, PART12, PART21 |  |
|  11 |  21 files | CNTRLPNL, GOALBAR, MAINMENU, PART119, PART12 |  |
|  12 |  19 files | CNTRLPNL, PART117, PART119, PART12, PART21 |  |
|  13 |  17 files | HANDLES, PART117, PART119, PART12, PART13 |  |
|  14 |  15 files | BUTTONS, HANDLES, PART117, PART119, PART12 |  |
|  15 |  17 files | BUTTONS, CNTRLPNL, PART117, PART119, PART15 |  |
|  16 |  15 files | BUTTONS, CNTRLPNL, HANDLES, MAINMENU, PART119 |  |
|  17 |  11 files | BUTTONS, CNTRLPNL, PART117, PART119, PART36 |  |
|  18 |   9 files | HANDLES, PART117, PART119, PART36, PART54 |  |
|  19 |  11 files | CNTRLPNL, PART117, PART137, PART18, PART54 |  |
|  20 |  13 files | CNTRLPNL, HANDLES, PART117, PART137, PART18 |  |
|  21 |  11 files | HANDLES, PART117, PART137, PART36, PART54 |  |
|  22 |  10 files | BUTTONS, HANDLES, PART117, PART137, PART18 |  |
|  23 |  10 files | BUTTONS, HANDLES, PART117, PART137, PART18 |  |
|  24 |   9 files | BUTTONS, HANDLES, PART117, PART137, PART18 |  |
|  25 |  10 files | BUTTONS, HANDLES, PART117, PART137, PART18 |  |
|  26 |   7 files | HANDLES, PART117, PART137, PART18, PART95 |  |
|  27 |   8 files | HANDLES, INFO4, PART117, PART137, PART18 |  |
|  28 |   7 files | PART117, PART137, PART18, PART95, PROFESOR |  |
|  29 |   7 files | PART117, PART137, PART18, PART95, PROFESOR |  |
|  30 |   7 files | BUTTONS, PART117, PART137, PART18, PART95 |  |
|  31 |   5 files | BUTTONS, PART117, PART137, PART18, PART95 |  |
|  32 |   5 files | BUTTONS, PART117, PART137, PART95, PROGPART |  |
|  33 |   4 files | PART117, PART137, PART95, PROGPART |  |
|  34 |   3 files | PART137, PART18, PROGPART |  |
|  35 |   4 files | BUTTONS, PART137, PART18, PROGPART |  |
|  36 |   4 files | BUTTONS, PART137, PART18, PROGPART |  |
|  37 |   2 files | PART137, PROGPART |  |
|  38 |   2 files | PART137, PART18 |  |
|  39 |   3 files | BUTTONS, PART137, PART18 |  |
|  40 |   2 files | PART137, PART18 |  |
|  41 |   3 files | PART137, PART18, PROGPART |  |
|  42 |   3 files | PART137, PART18, PROGPART |  |
|  43 |   4 files | BUTTONS, PART137, PART18, SOLVE |  |
|  44 |   4 files | BUTTONS, PART137, PART18, SOLVE |  |
|  45 |   4 files | BUTTONS, PART18, PROGPART, SOLVE |  |
|  46 |   1 files | PART18 |  |
|  47 |   2 files | PART18, PROGPART |  |
|  48 |   1 files | PART18 |  |
|  49 |   2 files | PART18, PROGPART |  |
|  50 |   1 files | PART18 |  |
|  51 |   3 files | PART18, PART54, PROGPART |  |
|  52 |   2 files | PART18, PROGPART |  |
|  53 |   1 files | PROGPART |  |
|  54 |   1 files | PROGPART |  |
|  55 |   1 files | PROGPART |  |
|  56 |   1 files | PROGPART |  |
|  57 |   1 files | PROGPART |  |
|  59 |   1 files | PROGPART |  |
|  60 |   1 files | PROGPART |  |
|  61 |   1 files | PROGPART |  |
|  62 |   1 files | PROGPART |  |
|  63 |   1 files | PROGPART |  |
|  64 |   1 files | PROGPART |  |
|  66 |   1 files | PROGPART |  |
|  75 |   1 files | PROGPART |  |
|  76 |   1 files | PROGPART |  |
|  77 |   1 files | PROGPART |  |
|  78 |   1 files | PROGPART |  |
|  79 |   1 files | PROGPART |  |
|  80 |   1 files | PROGPART |  |
|  81 |   1 files | PROGPART |  |
|  82 |   1 files | PROGPART |  |
|  83 |   1 files | PROGPART |  |
|  84 |   1 files | PROGPART |  |
|  90 |   1 files | PROGPART |  |
|  91 |   1 files | PROGPART |  |
|  92 |   1 files | PROGPART |  |
|  93 |   1 files | PROGPART |  |
|  94 |   1 files | PROGPART |  |
|  95 |   1 files | PROGPART |  |
|  96 |   1 files | PROGPART |  |
|  97 |   1 files | PROGPART |  |
|  98 |   1 files | PROGPART |  |
|  99 |   1 files | PROGPART |  |
| 100 |   1 files | PROGPART |  |
| 101 |   1 files | PROGPART |  |
| 102 |   1 files | PROGPART |  |
| 103 |   1 files | PROGPART |  |
| 104 |   1 files | PROGPART |  |

## Per-Part State Machines

### BINSOLVE
- 9 frames, 8 states, 19 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(64×38 @ 0,0)
  - state_id=2 → first_frame_id=2 frame=(56×53 @ 0,0)
  - state_id=3 → first_frame_id=3 frame=(56×56 @ 0,0)
  - state_id=4 → first_frame_id=4 frame=(64×80 @ 0,0)
  - state_id=5 → first_frame_id=5 frame=(72×85 @ 0,0)
  - state_id=6 → first_frame_id=6 frame=(72×82 @ 0,0)
  - state_id=7 → first_frame_id=7 frame=(104×100 @ 0,0)
  - state_id=8 → first_frame_id=8 frame=(96×97 @ 0,0)
  - Commands: DRAW_BMP=8, DRAW_RECT=1, END_ANM=1, END_FRAME=9

### BUTTONS
- 49 frames, 21 states, 133 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(639×399 @ 0,0)
  - state_id=1 → first_frame_id=1 frame=(32×28 @ 259,148)
  - state_id=2 → first_frame_id=4 frame=(32×27 @ 259,180)
  - state_id=31 → first_frame_id=7 frame=(48×49 @ 317,151)
  - state_id=5 → first_frame_id=10 frame=(24×14 @ 362,119)
  - state_id=14 → first_frame_id=11 frame=(32×32 @ 469,270)
  - state_id=15 → first_frame_id=13 frame=(24×26 @ 434,118)
  - state_id=16 → first_frame_id=20 frame=(26×26 @ 470,230)
  - state_id=17 → first_frame_id=23 frame=(51×36 @ 456,315)
  - state_id=45 → first_frame_id=25 frame=(67×41 @ 136,99)
  - state_id=22 → first_frame_id=27 frame=(51×32 @ 358,83)
  - state_id=23 → first_frame_id=31 frame=(72×202 @ 6,16)
  - state_id=24 → first_frame_id=32 frame=(72×202 @ 78,16)
  - state_id=25 → first_frame_id=33 frame=(32×20 @ 157,20)
  - state_id=35 → first_frame_id=34 frame=(24×15 @ 590,17)
  - state_id=36 → first_frame_id=35 frame=(24×15 @ 590,17)
  - state_id=30 → first_frame_id=36 frame=(64×53 @ 233,28)
  - state_id=32 → first_frame_id=39 frame=(56×50 @ 242,89)
  - state_id=39 → first_frame_id=42 frame=(24×30 @ 339,34)
  - state_id=43 → first_frame_id=45 frame=(24×24 @ 556,345)
  - state_id=44 → first_frame_id=47 frame=(24×24 @ 580,345)
  - Commands: DRAW_BMP=74, DRAW_RECT=1, END_ANM=1, END_FRAME=49, PLAY_SFX=8

### CNTRLPNL
- 25 frames, 12 states, 113 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=11 → first_frame_id=0 frame=(640×400 @ 0,0)
  - state_id=1 → first_frame_id=1 frame=(48×377 @ 0,0)
  - state_id=5 → first_frame_id=2 frame=(33×27 @ 10,9)
  - state_id=6 → first_frame_id=4 frame=(34×61 @ 9,40)
  - state_id=7 → first_frame_id=6 frame=(34×40 @ 10,105)
  - state_id=8 → first_frame_id=8 frame=(33×44 @ 10,152)
  - state_id=16 → first_frame_id=10 frame=(34×47 @ 9,201)
  - state_id=15 → first_frame_id=12 frame=(50×49 @ 0,249)
  - state_id=12 → first_frame_id=14 frame=(43×54 @ 1,249)
  - state_id=17 → first_frame_id=16 frame=(42×45 @ 3,249)
  - state_id=19 → first_frame_id=18 frame=(40×47 @ 3,314)
  - state_id=20 → first_frame_id=21 frame=(32×38 @ 11,323)
  - Commands: DRAW_BMP=76, DRAW_RECT=2, END_ANM=1, END_FRAME=25, PLAY_SFX=9

### CREDITS
- 4 frames, 1 states, 16 commands
- Dimensions: 0×0
- Animated: True (10 ticks in 6 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(83×71 @ 153,69)
  - Commands: DRAW_BMP=6, DRAW_RECT=4, END_ANM=1, END_FRAME=4, PLAY_SFX=1

### GOALBAR
- 34 frames, 6 states, 176 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(645×64 @ 0,0)
  - state_id=3 → first_frame_id=2 frame=(317×52 @ 7,6)
  - state_id=4 → first_frame_id=3 frame=(317×58 @ 7,0)
  - state_id=6 → first_frame_id=4 frame=(16×19 @ 68,32)
  - state_id=5 → first_frame_id=14 frame=(16×27 @ 136,17)
  - state_id=11 → first_frame_id=24 frame=(16×19 @ 68,32)
  - Commands: DRAW_BMP=94, DRAW_LINE=15, DRAW_RECT=32, END_ANM=1, END_FRAME=34

### HANDLES
- 108 frames, 16 states, 292 commands
- Dimensions: 0×0
- Animated: True (9786 ticks in 156 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(36×36 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(24×25 @ 15,10)
  - state_id=25 → first_frame_id=6 frame=(24×15 @ 11,10)
  - state_id=24 → first_frame_id=12 frame=(24×15 @ 1,10)
  - state_id=23 → first_frame_id=18 frame=(16×24 @ 10,11)
  - state_id=22 → first_frame_id=24 frame=(16×24 @ 10,1)
  - state_id=8 → first_frame_id=30 frame=(24×28 @ 8,1)
  - state_id=10 → first_frame_id=31 frame=(40×24 @ 1,5)
  - state_id=20 → first_frame_id=32 frame=(24×28 @ 8,1)
  - state_id=13 → first_frame_id=40 frame=(24×24 @ 1,11)
  - state_id=14 → first_frame_id=54 frame=(24×27 @ 1,8)
  - state_id=16 → first_frame_id=55 frame=(32×27 @ 1,8)
  - state_id=18 → first_frame_id=60 frame=(32×26 @ 1,2)
  - state_id=21 → first_frame_id=78 frame=(40×22 @ 1,13)
  - state_id=26 → first_frame_id=86 frame=(35×22 @ 1,13)
  - state_id=27 → first_frame_id=116
  - Commands: DRAW_BMP=182, DRAW_RECT=1, END_ANM=1, END_FRAME=108

### HEDTOHED
- 21 frames, 5 states, 121 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(285×337 @ 154,16)
  - state_id=3 → first_frame_id=2 frame=(32×28 @ 300,145)
  - state_id=2 → first_frame_id=5 frame=(32×27 @ 299,174)
  - state_id=4 → first_frame_id=8 frame=(16×27 @ 278,157)
  - state_id=5 → first_frame_id=18 frame=(26×30 @ 276,307)
  - Commands: DRAW_BMP=78, DRAW_RECT=18, END_ANM=1, END_FRAME=21, PLAY_SFX=3

### HINTLOCK
- 43 frames, 4 states, 160 commands
- Dimensions: 0×0
- Animated: True (6314 ticks in 217 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(15×14 @ 134,88)
  - state_id=1 → first_frame_id=1 frame=(72×76 @ 67,27)
  - state_id=3 → first_frame_id=53
  - state_id=2 → first_frame_id=165
  - Commands: DRAW_BMP=100, DRAW_RECT=13, END_ANM=1, END_FRAME=43, PLAY_SFX=3

### INFO0 (part_type=0)
- 5 frames, 1 states, 20 commands
- Dimensions: 0×0
- Animated: True (10 ticks in 84 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(98×105 @ 0,0)
  - Commands: DRAW_BMP=9, DRAW_RECT=5, END_ANM=1, END_FRAME=5

### INFO1 (part_type=1)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×99 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO10 (part_type=10)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(160×98 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO100 (part_type=100)
- 1 frames, 1 states, 4 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(263×100 @ 0,0)
  - Commands: DRAW_BMP=2, END_ANM=1, END_FRAME=1

### INFO101 (part_type=101)
- 1 frames, 1 states, 5 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(288×166 @ 0,0)
  - Commands: DRAW_BMP=3, END_ANM=1, END_FRAME=1

### INFO102 (part_type=102)
- 1 frames, 1 states, 4 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(192×134 @ 0,0)
  - Commands: DRAW_BMP=2, END_ANM=1, END_FRAME=1

### INFO103 (part_type=103)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×98 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO104 (part_type=104)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(104×98 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO105 (part_type=105)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×99 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO106 (part_type=106)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×111 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO107 (part_type=107)
- 13 frames, 1 states, 90 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(176×111 @ 0,0)
  - Commands: DRAW_BMP=50, DRAW_RECT=13, END_ANM=1, END_FRAME=13, PLAY_SFX=13

### INFO108 (part_type=108)
- 9 frames, 1 states, 34 commands
- Dimensions: 0×0
- Animated: True (102 ticks in 35 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(72×98 @ 0,0)
  - Commands: DRAW_BMP=15, DRAW_RECT=8, END_ANM=1, END_FRAME=9, PLAY_SFX=1

### INFO109 (part_type=109)
- 5 frames, 2 states, 26 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(152×100 @ 0,0)
  - state_id=3 → first_frame_id=0 frame=(152×100 @ 0,0)
  - Commands: DRAW_BMP=10, DRAW_RECT=5, END_ANM=1, END_FRAME=5, PLAY_SFX=5

### INFO11 (part_type=11)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×94 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO116 (part_type=116)
- 3 frames, 1 states, 11 commands
- Dimensions: 0×0
- Animated: True (21 ticks in 27 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(109×77 @ 0,0)
  - Commands: DRAW_BMP=3, DRAW_RECT=3, END_ANM=1, END_FRAME=3, PLAY_SFX=1

### INFO117 (part_type=117)
- 10 frames, 1 states, 26 commands
- Dimensions: 0×0
- Animated: True (428 ticks in 95 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×89 @ 0,0)
  - Commands: DRAW_BMP=11, DRAW_RECT=3, END_ANM=1, END_FRAME=10, PLAY_SFX=1

### INFO118 (part_type=118)
- 1 frames, 1 states, 7 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(320×64 @ 0,0)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=1

### INFO119 (part_type=119)
- 1 frames, 1 states, 7 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(410×167 @ 0,0)
  - Commands: DRAW_BMP=3, DRAW_RECT=2, END_ANM=1, END_FRAME=1

### INFO12 (part_type=12)
- 17 frames, 1 states, 69 commands
- Dimensions: 0×0
- Animated: True (672 ticks in 97 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(116×99 @ 0,0)
  - Commands: DRAW_BMP=34, DRAW_RECT=17, END_ANM=1, END_FRAME=17

### INFO120 (part_type=120)
- 13 frames, 1 states, 43 commands
- Dimensions: 0×0
- Animated: True (314 ticks in 50 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(169×90 @ 0,0)
  - Commands: DRAW_BMP=16, DRAW_RECT=10, END_ANM=1, END_FRAME=13, PLAY_SFX=3

### INFO125 (part_type=125)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(160×92 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO126 (part_type=126)
- 1 frames, 1 states, 4 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(192×134 @ 0,0)
  - Commands: DRAW_BMP=2, END_ANM=1, END_FRAME=1

### INFO13 (part_type=13)
- 7 frames, 1 states, 55 commands
- Dimensions: 0×0
- Animated: True (63 ticks in 21 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(172×111 @ 0,0)
  - Commands: DRAW_BMP=39, DRAW_RECT=7, END_ANM=1, END_FRAME=7, PLAY_SFX=1

### INFO136 (part_type=136)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(112×100 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO137 (part_type=137)
- 16 frames, 1 states, 57 commands
- Dimensions: 0×0
- Animated: True (400 ticks in 56 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×90 @ 0,0)
  - Commands: DRAW_BMP=32, END_ANM=1, END_FRAME=16, PLAY_SFX=8

### INFO138 (part_type=138)
- 5 frames, 1 states, 21 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(80×108 @ 0,0)
  - Commands: DRAW_BMP=10, DRAW_RECT=5, END_ANM=1, END_FRAME=5

### INFO139 (part_type=139)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(160×76 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO14 (part_type=14)
- 18 frames, 1 states, 62 commands
- Dimensions: 0×0
- Animated: True (684 ticks in 116 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×98 @ 0,0)
  - Commands: DRAW_BMP=34, DRAW_RECT=7, END_ANM=1, END_FRAME=18, PLAY_SFX=2

### INFO148 (part_type=148)
- 6 frames, 1 states, 19 commands
- Dimensions: 0×0
- Animated: True (65 ticks in 26 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(104×87 @ 0,0)
  - Commands: DRAW_BMP=10, END_ANM=1, END_FRAME=6, PLAY_SFX=2

### INFO15 (part_type=15)
- 72 frames, 1 states, 1132 commands
- Dimensions: 0×0
- Animated: True (7668 ticks in 216 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(172×111 @ 0,0)
  - Commands: DRAW_BMP=550, DRAW_LINE=223, DRAW_RECT=214, END_ANM=1, END_FRAME=72, PLAY_SFX=72

### INFO16 (part_type=16)
- 12 frames, 1 states, 37 commands
- Dimensions: 0×0
- Animated: True (727 ticks in 155 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(120×97 @ 0,0)
  - Commands: DRAW_BMP=24, END_ANM=1, END_FRAME=12

### INFO17 (part_type=17)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(80×98 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO18 (part_type=18)
- 31 frames, 1 states, 125 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(172×111 @ 0,0)
  - Commands: DRAW_BMP=62, DRAW_RECT=30, END_ANM=1, END_FRAME=31, PLAY_SFX=1

### INFO19 (part_type=19)
- 26 frames, 1 states, 131 commands
- Dimensions: 0×0
- Animated: True (650 ticks in 51 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(172×76 @ 0,0)
  - Commands: DRAW_BMP=78, DRAW_RECT=25, END_ANM=1, END_FRAME=26, PLAY_SFX=1

### INFO2 (part_type=2)
- 1 frames, 1 states, 6 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(212×145 @ 0,0)
  - Commands: DRAW_BMP=2, DRAW_RECT=2, END_ANM=1, END_FRAME=1

### INFO20 (part_type=20)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×60 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO21 (part_type=21)
- 9 frames, 1 states, 44 commands
- Dimensions: 0×0
- Animated: True (468 ticks in 130 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×88 @ 0,0)
  - Commands: DRAW_BMP=21, DRAW_RECT=10, END_ANM=1, END_FRAME=9, PLAY_SFX=3

### INFO22 (part_type=22)
- 6 frames, 1 states, 31 commands
- Dimensions: 0×0
- Animated: True (27 ticks in 49 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(172×111 @ 0,0)
  - Commands: DRAW_BMP=17, DRAW_RECT=6, END_ANM=1, END_FRAME=6, PLAY_SFX=1

### INFO23 (part_type=23)
- 13 frames, 1 states, 35 commands
- Dimensions: 0×0
- Animated: True (893 ticks in 124 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(88×39 @ 0,0)
  - Commands: DRAW_BMP=15, DRAW_RECT=5, END_ANM=1, END_FRAME=13, PLAY_SFX=1

### INFO24 (part_type=24)
- 2 frames, 1 states, 13 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(61×106 @ 0,0)
  - Commands: DRAW_BMP=6, DRAW_RECT=2, END_ANM=1, END_FRAME=2, PLAY_SFX=2

### INFO25 (part_type=25)
- 6 frames, 1 states, 31 commands
- Dimensions: 0×0
- Animated: True (442 ticks in 137 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(148×72 @ 0,0)
  - Commands: DRAW_BMP=16, DRAW_RECT=6, END_ANM=1, END_FRAME=6, PLAY_SFX=2

### INFO26 (part_type=26)
- 4 frames, 1 states, 24 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(160×64 @ 0,0)
  - Commands: DRAW_BMP=15, END_ANM=1, END_FRAME=4, PLAY_SFX=4

### INFO27 (part_type=27)
- 48 frames, 1 states, 250 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(136×88 @ 0,0)
  - Commands: DRAW_BMP=154, DRAW_RECT=46, END_ANM=1, END_FRAME=48, PLAY_SFX=1

### INFO28 (part_type=28)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(80×73 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO29 (part_type=29)
- 5 frames, 1 states, 31 commands
- Dimensions: 0×0
- Animated: True (50 ticks in 25 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(74×104 @ 0,0)
  - Commands: DRAW_BMP=15, DRAW_RECT=5, END_ANM=1, END_FRAME=5, PLAY_SFX=5

### INFO3 (part_type=3)
- 1 frames, 1 states, 4 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(112×60 @ 0,0)
  - Commands: DRAW_BMP=2, END_ANM=1, END_FRAME=1

### INFO30 (part_type=30)
- 12 frames, 1 states, 34 commands
- Dimensions: 0×0
- Animated: True (781 ticks in 116 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(48×101 @ 0,0)
  - Commands: DRAW_BMP=14, DRAW_RECT=6, END_ANM=1, END_FRAME=12, PLAY_SFX=1

### INFO31 (part_type=31)
- 3 frames, 1 states, 10 commands
- Dimensions: 0×0
- Animated: True (7 ticks in 64 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(144×110 @ 0,0)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=3, PLAY_SFX=1

### INFO32 (part_type=32)
- 3 frames, 1 states, 10 commands
- Dimensions: 0×0
- Animated: True (7 ticks in 64 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(160×64 @ 0,0)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=3, PLAY_SFX=1

### INFO33 (part_type=33)
- 11 frames, 1 states, 32 commands
- Dimensions: 0×0
- Animated: True (771 ticks in 149 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(120×89 @ 0,0)
  - Commands: DRAW_BMP=14, DRAW_RECT=4, END_ANM=1, END_FRAME=11, PLAY_SFX=2

### INFO34 (part_type=34)
- 8 frames, 1 states, 20 commands
- Dimensions: 0×0
- Animated: True (537 ticks in 121 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(88×105 @ 0,0)
  - Commands: DRAW_BMP=9, END_ANM=1, END_FRAME=8, PLAY_SFX=2

### INFO35 (part_type=35)
- 8 frames, 1 states, 22 commands
- Dimensions: 0×0
- Animated: True (483 ticks in 82 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(144×99 @ 0,0)
  - Commands: DRAW_BMP=9, DRAW_RECT=3, END_ANM=1, END_FRAME=8, PLAY_SFX=1

### INFO36 (part_type=36)
- 54 frames, 1 states, 313 commands
- Dimensions: 0×0
- Animated: True (1584 ticks in 72 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(192×111 @ 0,0)
  - Commands: DRAW_BMP=149, DRAW_RECT=54, END_ANM=1, END_FRAME=54, PLAY_SFX=55

### INFO37 (part_type=37)
- 10 frames, 1 states, 40 commands
- Dimensions: 0×0
- Animated: True (486 ticks in 98 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(128×87 @ 0,0)
  - Commands: DRAW_BMP=19, DRAW_RECT=9, END_ANM=1, END_FRAME=10, PLAY_SFX=1

### INFO38 (part_type=38)
- 17 frames, 1 states, 54 commands
- Dimensions: 0×0
- Animated: True (862 ticks in 109 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(144×64 @ 0,0)
  - Commands: DRAW_BMP=25, DRAW_RECT=8, END_ANM=1, END_FRAME=17, PLAY_SFX=3

### INFO39 (part_type=39)
- 7 frames, 1 states, 50 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×83 @ 0,0)
  - Commands: DRAW_BMP=35, DRAW_RECT=7, END_ANM=1, END_FRAME=7

### INFO4 (part_type=4)
- 56 frames, 1 states, 583 commands
- Dimensions: 0×0
- Animated: True (4490 ticks in 164 sub-frames)
  - state_id=27 → first_frame_id=0 frame=(208×165 @ 0,0)
  - Commands: DRAW_BMP=242, DRAW_LINE=224, DRAW_RECT=58, END_ANM=1, END_FRAME=56, PLAY_SFX=2

### INFO40 (part_type=40)
- 11 frames, 1 states, 27 commands
- Dimensions: 0×0
- Animated: True (429 ticks in 71 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×99 @ 0,0)
  - Commands: DRAW_BMP=12, DRAW_RECT=2, END_ANM=1, END_FRAME=11, PLAY_SFX=1

### INFO42 (part_type=42)
- 30 frames, 1 states, 100 commands
- Dimensions: 0×0
- Animated: True (1754 ticks in 149 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(121×106 @ 0,0)
  - Commands: DRAW_BMP=30, DRAW_RECT=30, END_ANM=1, END_FRAME=30, PLAY_SFX=9

### INFO43 (part_type=43)
- 23 frames, 1 states, 94 commands
- Dimensions: 0×0
- Animated: True (877 ticks in 106 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(88×85 @ 0,0)
  - Commands: DRAW_BMP=44, DRAW_RECT=22, END_ANM=1, END_FRAME=23, PLAY_SFX=4

### INFO44 (part_type=44)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(88×81 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO45 (part_type=45)
- 61 frames, 1 states, 265 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(154×90 @ 0,0)
  - Commands: DRAW_BMP=133, DRAW_RECT=69, END_ANM=1, END_FRAME=61, PLAY_SFX=1

### INFO46 (part_type=46)
- 8 frames, 1 states, 30 commands
- Dimensions: 0×0
- Animated: True (483 ticks in 112 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×100 @ 0,0)
  - Commands: DRAW_BMP=15, DRAW_RECT=5, END_ANM=1, END_FRAME=8, PLAY_SFX=1

### INFO47 (part_type=47)
- 16 frames, 1 states, 78 commands
- Dimensions: 0×0
- Animated: True (215 ticks in 100 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×93 @ 0,0)
  - Commands: DRAW_BMP=29, DRAW_RECT=30, END_ANM=1, END_FRAME=16, PLAY_SFX=2

### INFO48 (part_type=48)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×103 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO5 (part_type=5)
- 11 frames, 1 states, 93 commands
- Dimensions: 0×0
- Animated: True (165 ticks in 31 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(160×32 @ 0,0)
  - Commands: DRAW_BMP=70, END_ANM=1, END_FRAME=11, PLAY_SFX=11

### INFO50 (part_type=50)
- 10 frames, 1 states, 41 commands
- Dimensions: 0×0
- Animated: True (415 ticks in 98 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×108 @ 0,0)
  - Commands: DRAW_BMP=10, DRAW_LINE=10, END_ANM=1, END_FRAME=10, PLAY_SFX=10

### INFO51 (part_type=51)
- 4 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: True (259 ticks in 119 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(160×83 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=4, PLAY_SFX=4

### INFO52 (part_type=52)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(136×75 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO53 (part_type=53)
- 10 frames, 1 states, 38 commands
- Dimensions: 0×0
- Animated: True (1192 ticks in 160 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(73×146 @ 0,0)
  - Commands: DRAW_BMP=16, DRAW_RECT=10, END_ANM=1, END_FRAME=10, PLAY_SFX=1

### INFO54 (part_type=54)
- 38 frames, 1 states, 290 commands
- Dimensions: 0×0
- Animated: True (3984 ticks in 287 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(64×97 @ 0,0)
  - Commands: DRAW_BMP=169, DRAW_LINE=25, DRAW_RECT=49, END_ANM=1, END_FRAME=38, PLAY_SFX=8

### INFO55 (part_type=55)
- 6 frames, 1 states, 31 commands
- Dimensions: 0×0
- Animated: True (15 ticks in 38 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(172×111 @ 0,0)
  - Commands: DRAW_BMP=11, DRAW_RECT=12, END_ANM=1, END_FRAME=6, PLAY_SFX=1

### INFO56 (part_type=56)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×96 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO57 (part_type=57)
- 17 frames, 1 states, 45 commands
- Dimensions: 0×0
- Animated: True (526 ticks in 95 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×99 @ 0,0)
  - Commands: DRAW_BMP=20, DRAW_RECT=6, END_ANM=1, END_FRAME=17, PLAY_SFX=1

### INFO58 (part_type=58)
- 3 frames, 1 states, 23 commands
- Dimensions: 0×0
- Animated: True (6 ticks in 6 sub-frames)
  - state_id=5 → first_frame_id=0 frame=(172×149 @ 0,0)
  - Commands: DRAW_BMP=12, DRAW_RECT=7, END_ANM=1, END_FRAME=3

### INFO59 (part_type=59)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×93 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO6 (part_type=6)
- 28 frames, 1 states, 97 commands
- Dimensions: 0×0
- Animated: True (1438 ticks in 143 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(144×90 @ 0,0)
  - Commands: DRAW_BMP=62, END_ANM=1, END_FRAME=28, PLAY_SFX=6

### INFO60 (part_type=60)
- 12 frames, 1 states, 52 commands
- Dimensions: 0×0
- Animated: True (285 ticks in 60 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(197×128 @ 0,0)
  - Commands: DRAW_BMP=27, DRAW_RECT=12, END_ANM=1, END_FRAME=12

### INFO61 (part_type=61)
- 7 frames, 1 states, 30 commands
- Dimensions: 0×0
- Animated: True (149 ticks in 63 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(174×111 @ 0,0)
  - Commands: DRAW_BMP=14, DRAW_RECT=7, END_ANM=1, END_FRAME=7, PLAY_SFX=1

### INFO62 (part_type=62)
- 7 frames, 1 states, 28 commands
- Dimensions: 0×0
- Animated: True (42 ticks in 14 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(88×90 @ 0,0)
  - Commands: DRAW_BMP=13, END_ANM=1, END_FRAME=7, PLAY_SFX=7

### INFO63 (part_type=63)
- 20 frames, 1 states, 65 commands
- Dimensions: 0×0
- Animated: True (2747 ticks in 185 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(176×113 @ 0,0)
  - Commands: DRAW_BMP=20, DRAW_LINE=4, DRAW_RECT=20, END_ANM=1, END_FRAME=20

### INFO64 (part_type=64)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(88×99 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO65 (part_type=65)
- 31 frames, 1 states, 297 commands
- Dimensions: 0×0
- Animated: True (916 ticks in 56 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(79×105 @ 0,0)
  - Commands: DRAW_BMP=173, DRAW_RECT=31, END_ANM=1, END_FRAME=31, PLAY_SFX=61

### INFO66 (part_type=66)
- 9 frames, 1 states, 85 commands
- Dimensions: 0×0
- Animated: True (46 ticks in 32 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(172×111 @ 0,0)
  - Commands: DRAW_BMP=36, DRAW_LINE=18, DRAW_RECT=18, END_ANM=1, END_FRAME=9, PLAY_SFX=3

### INFO67 (part_type=67)
- 6 frames, 1 states, 34 commands
- Dimensions: 0×0
- Animated: True (30 ticks in 12 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(83×104 @ 0,0)
  - Commands: DRAW_BMP=15, DRAW_RECT=6, END_ANM=1, END_FRAME=6, PLAY_SFX=6

### INFO68 (part_type=68)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(72×73 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO69 (part_type=69)
- 4 frames, 1 states, 13 commands
- Dimensions: 0×0
- Animated: True (30 ticks in 20 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(144×48 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4, PLAY_SFX=4

### INFO7 (part_type=7)
- 11 frames, 1 states, 33 commands
- Dimensions: 0×0
- Animated: True (1045 ticks in 149 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(80×87 @ 0,0)
  - Commands: DRAW_BMP=14, DRAW_RECT=6, END_ANM=1, END_FRAME=11, PLAY_SFX=1

### INFO70 (part_type=70)
- 54 frames, 1 states, 310 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(192×111 @ 0,0)
  - Commands: DRAW_BMP=145, DRAW_RECT=54, END_ANM=1, END_FRAME=54, PLAY_SFX=56

### INFO71 (part_type=71)
- 1 frames, 1 states, 5 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(172×111 @ 0,0)
  - Commands: DRAW_BMP=1, DRAW_LINE=1, DRAW_RECT=1, END_ANM=1, END_FRAME=1

### INFO73 (part_type=73)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×106 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO74 (part_type=74)
- 6 frames, 1 states, 25 commands
- Dimensions: 0×0
- Animated: True (45 ticks in 18 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×95 @ 0,0)
  - Commands: DRAW_BMP=12, END_ANM=1, END_FRAME=6, PLAY_SFX=6

### INFO75 (part_type=75)
- 13 frames, 1 states, 79 commands
- Dimensions: 0×0
- Animated: True (360 ticks in 70 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(125×69 @ 0,0)
  - Commands: DRAW_BMP=52, DRAW_RECT=13, END_ANM=1, END_FRAME=13

### INFO76 (part_type=76)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(120×106 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO77 (part_type=77)
- 16 frames, 1 states, 53 commands
- Dimensions: 0×0
- Animated: True (705 ticks in 74 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(144×80 @ 0,0)
  - Commands: DRAW_BMP=26, DRAW_RECT=9, END_ANM=1, END_FRAME=16, PLAY_SFX=1

### INFO78 (part_type=78)
- 54 frames, 1 states, 333 commands
- Dimensions: 0×0
- Animated: True (1431 ticks in 73 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(140×100 @ 0,0)
  - Commands: DRAW_BMP=223, DRAW_RECT=54, END_ANM=1, END_FRAME=54, PLAY_SFX=1

### INFO79 (part_type=79)
- 15 frames, 1 states, 78 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(172×112 @ 0,0)
  - Commands: DRAW_BMP=30, DRAW_LINE=17, DRAW_RECT=15, END_ANM=1, END_FRAME=15

### INFO8 (part_type=8)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(152×73 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO80 (part_type=80)
- 13 frames, 1 states, 71 commands
- Dimensions: 0×0
- Animated: True (234 ticks in 37 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(68×153 @ 0,0)
  - Commands: DRAW_BMP=39, DRAW_RECT=17, END_ANM=1, END_FRAME=13, PLAY_SFX=1

### INFO81 (part_type=81)
- 5 frames, 1 states, 56 commands
- Dimensions: 0×0
- Animated: True (40 ticks in 20 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×131 @ 0,0)
  - Commands: DRAW_BMP=45, DRAW_RECT=5, END_ANM=1, END_FRAME=5

### INFO82 (part_type=82)
- 1 frames, 1 states, 8 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(187×108 @ 0,0)
  - Commands: DRAW_BMP=5, DRAW_RECT=1, END_ANM=1, END_FRAME=1

### INFO83 (part_type=83)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×96 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO84 (part_type=84)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(144×97 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO85 (part_type=85)
- 1 frames, 1 states, 4 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(176×111 @ 0,0)
  - Commands: DRAW_BMP=2, END_ANM=1, END_FRAME=1

### INFO86 (part_type=86)
- 18 frames, 1 states, 67 commands
- Dimensions: 0×0
- Animated: True (324 ticks in 96 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×95 @ 0,0)
  - Commands: DRAW_BMP=34, DRAW_RECT=12, END_ANM=1, END_FRAME=18, PLAY_SFX=2

### INFO87 (part_type=87)
- 8 frames, 1 states, 26 commands
- Dimensions: 0×0
- Animated: True (161 ticks in 46 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(176×111 @ 0,0)
  - Commands: DRAW_BMP=9, DRAW_RECT=7, END_ANM=1, END_FRAME=8, PLAY_SFX=1

### INFO88 (part_type=88)
- 12 frames, 1 states, 56 commands
- Dimensions: 0×0
- Animated: True (168 ticks in 30 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(120×77 @ 0,0)
  - Commands: DRAW_BMP=40, END_ANM=1, END_FRAME=12, PLAY_SFX=3

### INFO89 (part_type=89)
- 4 frames, 1 states, 26 commands
- Dimensions: 0×0
- Animated: True (16 ticks in 10 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(168×106 @ 0,0)
  - Commands: DRAW_BMP=12, DRAW_RECT=8, END_ANM=1, END_FRAME=4, PLAY_SFX=1

### INFO9 (part_type=9)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×90 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO90 (part_type=90)
- 9 frames, 1 states, 58 commands
- Dimensions: 0×0
- Animated: True (71 ticks in 17 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(40×128 @ 0,0)
  - Commands: DRAW_BMP=37, DRAW_RECT=10, END_ANM=1, END_FRAME=9, PLAY_SFX=1

### INFO91 (part_type=91)
- 4 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: True (18 ticks in 12 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(120×50 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=4, PLAY_SFX=4

### INFO92 (part_type=92)
- 4 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: True (12 ticks in 8 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(120×50 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=4, PLAY_SFX=4

### INFO93 (part_type=93)
- 4 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: True (12 ticks in 8 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(120×50 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=4, PLAY_SFX=4

### INFO94 (part_type=94)
- 19 frames, 1 states, 56 commands
- Dimensions: 0×0
- Animated: True (535 ticks in 79 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(102×95 @ 0,0)
  - Commands: DRAW_BMP=25, DRAW_RECT=10, END_ANM=1, END_FRAME=19, PLAY_SFX=1

### INFO95 (part_type=95)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×92 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### INFO96 (part_type=96)
- 6 frames, 1 states, 21 commands
- Dimensions: 0×0
- Animated: True (85 ticks in 29 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×88 @ 0,0)
  - Commands: DRAW_BMP=7, DRAW_RECT=5, END_ANM=1, END_FRAME=6, PLAY_SFX=2

### INFO97 (part_type=97)
- 12 frames, 1 states, 33 commands
- Dimensions: 0×0
- Animated: True (165 ticks in 50 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×76 @ 0,0)
  - Commands: DRAW_BMP=17, DRAW_RECT=2, END_ANM=1, END_FRAME=12, PLAY_SFX=1

### INFO98 (part_type=98)
- 16 frames, 1 states, 48 commands
- Dimensions: 0×0
- Animated: True (405 ticks in 54 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(104×103 @ 0,0)
  - Commands: DRAW_BMP=23, DRAW_RECT=7, END_ANM=1, END_FRAME=16, PLAY_SFX=1

### INFO99 (part_type=99)
- 86 frames, 1 states, 512 commands
- Dimensions: 0×0
- Animated: True (10237 ticks in 226 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(266×109 @ 0,0)
  - Commands: DRAW_BMP=338, DRAW_RECT=87, END_ANM=1, END_FRAME=86

### LOADSAVE
- 11 frames, 3 states, 71 commands
- Dimensions: 0×0
- Animated: True (162 ticks in 30 sub-frames)
  - state_id=5 → first_frame_id=0 frame=(12×11 @ 16,3)
  - state_id=1 → first_frame_id=1 frame=(100×88 @ 123,129)
  - state_id=3 → first_frame_id=14
  - Commands: DRAW_BMP=42, DRAW_RECT=9, END_ANM=1, END_FRAME=11, PLAY_SFX=8

### MAINMENU
- 116 frames, 11 states, 812 commands
- Dimensions: 0×0
- Animated: True (24198 ticks in 461 sub-frames)
  - state_id=10 → first_frame_id=0 frame=(110×121 @ 65,55)
  - state_id=2 → first_frame_id=0 frame=(110×121 @ 65,55)
  - state_id=3 → first_frame_id=75 frame=(154×116 @ 189,198)
  - state_id=4 → first_frame_id=210
  - state_id=11 → first_frame_id=276
  - state_id=6 → first_frame_id=291
  - state_id=7 → first_frame_id=348
  - state_id=1 → first_frame_id=452
  - state_id=8 → first_frame_id=454
  - state_id=16 → first_frame_id=457
  - state_id=9 → first_frame_id=460
  - Commands: DRAW_BMP=473, DRAW_LINE=47, DRAW_RECT=152, END_ANM=1, END_FRAME=116, PLAY_SFX=23

### PART0 (part_type=0)
- 8 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=8

### PART1 (part_type=1)
- 20 frames, 2 states, 41 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=4 frame=(16×16 @ 0,0)
  - state_id=1 → first_frame_id=8 frame=(40×16 @ 0,0)
  - Commands: DRAW_BMP=20, END_ANM=1, END_FRAME=20

### PART10 (part_type=10)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×5 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART100 (part_type=100)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×32 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART101 (part_type=101)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×32 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART102 (part_type=102)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×32 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART103 (part_type=103)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART104 (part_type=104)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(64×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART105 (part_type=105)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART106 (part_type=106)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(64×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART107 (part_type=107)
- 5 frames, 2 states, 15 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(56×55 @ 0,0)
  - state_id=1 → first_frame_id=1 frame=(56×59 @ 0,-4)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=5, PLAY_SFX=4

### PART108 (part_type=108)
- 42 frames, 8 states, 119 commands
- Dimensions: 0×0
- Animated: True (2490 ticks in 91 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×50 @ 0,0)
  - state_id=9 → first_frame_id=1 frame=(40×50 @ 0,0)
  - state_id=8 → first_frame_id=8 frame=(40×50 @ 0,0)
  - state_id=7 → first_frame_id=18 frame=(40×50 @ 0,0)
  - state_id=6 → first_frame_id=30 frame=(40×60 @ 0,0)
  - state_id=5 → first_frame_id=51
  - state_id=4 → first_frame_id=80
  - state_id=10 → first_frame_id=90
  - Commands: DRAW_BMP=71, END_ANM=1, END_FRAME=42, PLAY_SFX=5

### PART109 (part_type=109)
- 24 frames, 7 states, 93 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×36 @ 0,0)
  - state_id=3 → first_frame_id=5 frame=(48×41 @ 3,-4)
  - state_id=4 → first_frame_id=8 frame=(48×41 @ -1,-4)
  - state_id=2 → first_frame_id=11 frame=(56×35 @ 0,0)
  - state_id=7 → first_frame_id=16 frame=(32×68 @ 14,-22)
  - state_id=5 → first_frame_id=17 frame=(56×35 @ 0,0)
  - state_id=6 → first_frame_id=22 frame=(32×68 @ 14,-22)
  - Commands: DRAW_BMP=56, END_ANM=1, END_FRAME=24, PLAY_SFX=12

### PART11 (part_type=11)
- 2 frames, 2 states, 6 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=6 → first_frame_id=0 frame=(64×62 @ 0,0)
  - state_id=5 → first_frame_id=1 frame=(64×62 @ 0,0)
  - Commands: DRAW_BMP=3, END_ANM=1, END_FRAME=2

### PART115 (part_type=115)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×40 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART116 (part_type=116)
- 2 frames, 2 states, 6 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(48×41 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(64×17 @ -13,0)
  - Commands: DRAW_BMP=2, END_ANM=1, END_FRAME=2, PLAY_SFX=1

### PART117 (part_type=117)
- 56 frames, 24 states, 121 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(48×9 @ 35,34)
  - state_id=4 → first_frame_id=1 frame=(32×9 @ 36,34)
  - state_id=9 → first_frame_id=6 frame=(48×9 @ 35,34)
  - state_id=12 → first_frame_id=7 frame=(40×33 @ 35,34)
  - state_id=13 → first_frame_id=8 frame=(32×26 @ 35,34)
  - state_id=14 → first_frame_id=13 frame=(40×33 @ 35,34)
  - state_id=15 → first_frame_id=14 frame=(16×43 @ 35,34)
  - state_id=17 → first_frame_id=15 frame=(16×32 @ 35,35)
  - state_id=18 → first_frame_id=20 frame=(16×43 @ 35,34)
  - state_id=19 → first_frame_id=21 frame=(40×33 @ 5,34)
  - state_id=20 → first_frame_id=22 frame=(32×26 @ 13,34)
  - state_id=21 → first_frame_id=27 frame=(40×33 @ 5,34)
  - state_id=22 → first_frame_id=28 frame=(48×9 @ -5,34)
  - state_id=23 → first_frame_id=29 frame=(32×9 @ 10,34)
  - state_id=24 → first_frame_id=34 frame=(48×9 @ -5,34)
  - state_id=25 → first_frame_id=35 frame=(40×33 @ 5,10)
  - state_id=26 → first_frame_id=36 frame=(32×26 @ 13,17)
  - state_id=27 → first_frame_id=41 frame=(40×33 @ 5,10)
  - state_id=28 → first_frame_id=42 frame=(16×43 @ 35,0)
  - state_id=29 → first_frame_id=43 frame=(16×32 @ 35,10)
  - state_id=30 → first_frame_id=48 frame=(16×43 @ 35,0)
  - state_id=31 → first_frame_id=49 frame=(40×33 @ 35,10)
  - state_id=32 → first_frame_id=50 frame=(32×26 @ 35,17)
  - state_id=33 → first_frame_id=55 frame=(40×33 @ 35,10)
  - Commands: DRAW_BMP=56, END_ANM=1, END_FRAME=56, PLAY_SFX=8

### PART118 (part_type=118)
- 23 frames, 3 states, 47 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×32 @ 0,0)
  - state_id=2 → first_frame_id=11 frame=(32×16 @ 0,0)
  - state_id=3 → first_frame_id=22 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=23, END_ANM=1, END_FRAME=23

### PART119 (part_type=119)
- 16 frames, 16 states, 33 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×64 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(32×48 @ 0,0)
  - state_id=4 → first_frame_id=2 frame=(64×64 @ 0,0)
  - state_id=5 → first_frame_id=3 frame=(48×32 @ 0,0)
  - state_id=6 → first_frame_id=4 frame=(64×64 @ 0,0)
  - state_id=7 → first_frame_id=5 frame=(32×48 @ 0,0)
  - state_id=8 → first_frame_id=6 frame=(64×64 @ 0,0)
  - state_id=9 → first_frame_id=7 frame=(48×32 @ 0,0)
  - state_id=11 → first_frame_id=8 frame=(64×64 @ 0,0)
  - state_id=12 → first_frame_id=9 frame=(32×48 @ 0,0)
  - state_id=13 → first_frame_id=10 frame=(64×64 @ 0,0)
  - state_id=14 → first_frame_id=11 frame=(48×32 @ 0,0)
  - state_id=15 → first_frame_id=12 frame=(64×64 @ 0,0)
  - state_id=16 → first_frame_id=13 frame=(32×48 @ 0,0)
  - state_id=17 → first_frame_id=14 frame=(64×64 @ 0,0)
  - state_id=18 → first_frame_id=15 frame=(48×32 @ 0,0)
  - Commands: DRAW_BMP=16, END_ANM=1, END_FRAME=16

### PART12 (part_type=12)
- 182 frames, 12 states, 598 commands
- Dimensions: 0×0
- Animated: True (28127 ticks in 334 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(45×42 @ 0,0)
  - state_id=8 → first_frame_id=1 frame=(45×42 @ 0,0)
  - state_id=7 → first_frame_id=75 frame=(72×57 @ -18,-16)
  - state_id=6 → first_frame_id=97 frame=(45×42 @ 0,0)
  - state_id=4 → first_frame_id=149 frame=(48×33 @ 0,9)
  - state_id=5 → first_frame_id=160 frame=(48×33 @ 0,9)
  - state_id=9 → first_frame_id=170 frame=(72×57 @ -18,-15)
  - state_id=11 → first_frame_id=171 frame=(72×57 @ -18,-16)
  - state_id=12 → first_frame_id=245
  - state_id=13 → first_frame_id=262
  - state_id=14 → first_frame_id=314
  - state_id=10 → first_frame_id=324
  - Commands: DRAW_BMP=412, END_ANM=1, END_FRAME=182, PLAY_SFX=3

### PART120 (part_type=120)
- 4 frames, 4 states, 13 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×32 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(32×32 @ 0,0)
  - state_id=3 → first_frame_id=2 frame=(32×32 @ 0,0)
  - state_id=4 → first_frame_id=3 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=4

### PART121 (part_type=121)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(64×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART122 (part_type=122)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(96×80 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART123 (part_type=123)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(64×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART124 (part_type=124)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×48 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART125 (part_type=125)
- 20 frames, 2 states, 41 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=4 frame=(16×16 @ 0,0)
  - state_id=1 → first_frame_id=8 frame=(40×16 @ 0,0)
  - Commands: DRAW_BMP=20, END_ANM=1, END_FRAME=20

### PART126 (part_type=126)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×32 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART128 (part_type=128)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(192×71 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART129 (part_type=129)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=6 → first_frame_id=0 frame=(88×72 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART13 (part_type=13)
- 30 frames, 4 states, 176 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(33×32 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(33×32 @ 0,0)
  - state_id=5 → first_frame_id=12 frame=(33×49 @ 0,-17)
  - state_id=13 → first_frame_id=29 frame=(61×52 @ -3,-20)
  - Commands: DRAW_BMP=144, END_ANM=1, END_FRAME=30, PLAY_SFX=1

### PART130 (part_type=130)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×111 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART131 (part_type=131)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×81 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART132 (part_type=132)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×44 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART133 (part_type=133)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×35 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART134 (part_type=134)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×109 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART135 (part_type=135)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×38 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART136 (part_type=136)
- 9 frames, 3 states, 27 commands
- Dimensions: 0×0
- Animated: True (71 ticks in 16 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(48×43 @ 0,0)
  - state_id=5 → first_frame_id=1 frame=(48×43 @ 0,0)
  - state_id=6 → first_frame_id=2 frame=(48×43 @ 0,0)
  - Commands: DRAW_BMP=17, END_ANM=1, END_FRAME=9

### PART137 (part_type=137)
- 33 frames, 26 states, 232 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=22 → first_frame_id=0 frame=(50×40 @ 0,0)
  - state_id=37 → first_frame_id=1 frame=(50×36 @ 0,4)
  - state_id=21 → first_frame_id=2 frame=(50×33 @ 0,7)
  - state_id=23 → first_frame_id=3 frame=(50×40 @ 0,0)
  - state_id=38 → first_frame_id=4 frame=(50×36 @ 0,4)
  - state_id=24 → first_frame_id=5 frame=(50×33 @ 0,7)
  - state_id=26 → first_frame_id=6 frame=(50×40 @ 0,0)
  - state_id=39 → first_frame_id=7 frame=(50×36 @ 0,4)
  - state_id=25 → first_frame_id=8 frame=(50×33 @ 0,7)
  - state_id=28 → first_frame_id=9 frame=(50×40 @ 0,0)
  - state_id=40 → first_frame_id=10 frame=(50×36 @ 0,4)
  - state_id=27 → first_frame_id=11 frame=(50×33 @ 0,7)
  - state_id=30 → first_frame_id=12 frame=(50×40 @ 0,0)
  - state_id=41 → first_frame_id=13 frame=(50×36 @ 0,4)
  - state_id=29 → first_frame_id=14 frame=(50×33 @ 0,7)
  - state_id=36 → first_frame_id=15 frame=(50×40 @ 0,0)
  - state_id=42 → first_frame_id=16 frame=(50×36 @ 0,4)
  - state_id=31 → first_frame_id=17 frame=(50×33 @ 0,7)
  - state_id=33 → first_frame_id=18 frame=(50×40 @ 0,0)
  - state_id=43 → first_frame_id=19 frame=(50×36 @ 0,4)
  - state_id=32 → first_frame_id=20 frame=(50×33 @ 0,7)
  - state_id=34 → first_frame_id=21 frame=(50×40 @ 0,0)
  - state_id=44 → first_frame_id=22 frame=(50×36 @ 0,4)
  - state_id=35 → first_frame_id=23 frame=(50×33 @ 0,7)
  - state_id=19 → first_frame_id=24 frame=(50×33 @ 0,7)
  - state_id=20 → first_frame_id=32 frame=(50×33 @ 0,7)
  - Commands: DRAW_BMP=197, END_ANM=1, END_FRAME=33, PLAY_SFX=1

### PART138 (part_type=138)
- 6 frames, 2 states, 18 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×33 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(24×39 @ 0,-6)
  - Commands: DRAW_BMP=11, END_ANM=1, END_FRAME=6

### PART139 (part_type=139)
- 3 frames, 1 states, 10 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=5 → first_frame_id=0 frame=(88×40 @ 0,0)
  - Commands: DRAW_BMP=6, END_ANM=1, END_FRAME=3

### PART14 (part_type=14)
- 5 frames, 2 states, 11 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×35 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(40×35 @ 0,0)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=5

### PART140 (part_type=140)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×65 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART141 (part_type=141)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(48×50 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART142 (part_type=142)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×62 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART143 (part_type=143)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(56×27 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART144 (part_type=144)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(128×63 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART145 (part_type=145)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(160×59 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART146 (part_type=146)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(72×24 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART147 (part_type=147)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(80×67 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART148 (part_type=148)
- 7 frames, 4 states, 19 commands
- Dimensions: 0×0
- Animated: True (210 ticks in 58 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(40×32 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(40×32 @ 0,0)
  - state_id=4 → first_frame_id=20
  - state_id=5 → first_frame_id=39
  - Commands: DRAW_BMP=11, END_ANM=1, END_FRAME=7

### PART149 (part_type=149)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(104×44 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART15 (part_type=15)
- 117 frames, 3 states, 869 commands
- Dimensions: 0×0
- Animated: True (15358 ticks in 300 sub-frames)
  - state_id=15 → first_frame_id=0 frame=(67×51 @ 0,0)
  - state_id=9 → first_frame_id=255
  - state_id=14 → first_frame_id=299
  - Commands: DRAW_BMP=726, DRAW_LINE=24, END_ANM=1, END_FRAME=117, PLAY_SFX=1

### PART150 (part_type=150)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(104×45 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART151 (part_type=151)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×47 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART152 (part_type=152)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×36 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART153 (part_type=153)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×33 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART154 (part_type=154)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×34 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART155 (part_type=155)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(104×26 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART156 (part_type=156)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×19 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART157 (part_type=157)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(120×32 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART158 (part_type=158)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×42 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART159 (part_type=159)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×31 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART16 (part_type=16)
- 3 frames, 3 states, 8 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(48×51 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(48×41 @ 1,4)
  - state_id=5 → first_frame_id=2 frame=(56×24 @ -1,13)
  - Commands: DRAW_BMP=3, END_ANM=1, END_FRAME=3, PLAY_SFX=1

### PART160 (part_type=160)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×21 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART161 (part_type=161)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×19 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART162 (part_type=162)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×13 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART164 (part_type=164)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×22 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART165 (part_type=165)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(96×16 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART166 (part_type=166)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×26 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART167 (part_type=167)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(96×124 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART168 (part_type=168)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(160×92 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART169 (part_type=169)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×61 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART17 (part_type=17)
- 2 frames, 2 states, 5 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×49 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(40×49 @ 0,0)
  - Commands: DRAW_BMP=2, END_ANM=1, END_FRAME=2

### PART170 (part_type=170)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×66 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART171 (part_type=171)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×45 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART172 (part_type=172)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×84 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART173 (part_type=173)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×83 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART174 (part_type=174)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×51 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART175 (part_type=175)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×41 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART176 (part_type=176)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×48 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART177 (part_type=177)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×57 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART178 (part_type=178)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×23 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART179 (part_type=179)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×17 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART18 (part_type=18)
- 136 frames, 37 states, 693 commands
- Dimensions: 0×0
- Animated: True (12108 ticks in 178 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×61 @ 18,17)
  - state_id=23 → first_frame_id=1 frame=(91×82 @ 7,-4)
  - state_id=24 → first_frame_id=12 frame=(80×59 @ 18,19)
  - state_id=19 → first_frame_id=22 frame=(80×59 @ 18,19)
  - state_id=29 → first_frame_id=27 frame=(90×80 @ 16,-2)
  - state_id=3 → first_frame_id=29 frame=(88×93 @ 18,-15)
  - state_id=4 → first_frame_id=30 frame=(98×96 @ 8,-18)
  - state_id=25 → first_frame_id=31 frame=(99×78 @ 7,0)
  - state_id=26 → first_frame_id=42 frame=(107×43 @ 14,35)
  - state_id=20 → first_frame_id=52 frame=(86×78 @ -7,0)
  - state_id=30 → first_frame_id=57 frame=(79×78 @ 0,0)
  - state_id=6 → first_frame_id=59 frame=(56×69 @ 20,9)
  - state_id=7 → first_frame_id=60 frame=(64×63 @ 5,15)
  - state_id=27 → first_frame_id=61 frame=(132×170 @ 22,-88)
  - state_id=28 → first_frame_id=72 frame=(94×80 @ 3,-2)
  - state_id=22 → first_frame_id=82 frame=(72×58 @ 12,20)
  - state_id=31 → first_frame_id=86 frame=(194×129 @ -110,-51)
  - state_id=15 → first_frame_id=87 frame=(184×129 @ -100,-51)
  - state_id=9 → first_frame_id=90 frame=(88×61 @ -5,17)
  - state_id=34 → first_frame_id=91 frame=(80×59 @ 3,19)
  - state_id=35 → first_frame_id=92 frame=(88×65 @ -5,13)
  - state_id=36 → first_frame_id=102 frame=(98×67 @ -5,11)
  - state_id=38 → first_frame_id=112 frame=(96×46 @ -12,32)
  - state_id=39 → first_frame_id=117 frame=(91×78 @ 22,0)
  - state_id=40 → first_frame_id=119 frame=(100×78 @ 22,0)
  - state_id=41 → first_frame_id=120 frame=(103×78 @ 22,0)
  - state_id=42 → first_frame_id=121 frame=(90×82 @ 22,0)
  - state_id=43 → first_frame_id=131 frame=(128×176 @ -57,-98)
  - state_id=45 → first_frame_id=141
  - state_id=44 → first_frame_id=146
  - state_id=46 → first_frame_id=148
  - state_id=47 → first_frame_id=149
  - state_id=48 → first_frame_id=150
  - state_id=49 → first_frame_id=160
  - state_id=50 → first_frame_id=170
  - state_id=51 → first_frame_id=175
  - state_id=52 → first_frame_id=177
  - Commands: DRAW_BMP=544, END_ANM=1, END_FRAME=136, PLAY_SFX=12

### PART180 (part_type=180)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(96×54 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART181 (part_type=181)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×30 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART182 (part_type=182)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×44 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART183 (part_type=183)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×57 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART184 (part_type=184)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×47 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART185 (part_type=185)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×40 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART186 (part_type=186)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×44 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART187 (part_type=187)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×33 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART188 (part_type=188)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×33 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART189 (part_type=189)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×50 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART19 (part_type=19)
- 18 frames, 3 states, 71 commands
- Dimensions: 0×0
- Animated: True (238 ticks in 23 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(53×15 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(92×45 @ -39,-11)
  - state_id=4 → first_frame_id=17 frame=(40×15 @ 13,0)
  - Commands: DRAW_BMP=51, END_ANM=1, END_FRAME=18, PLAY_SFX=1

### PART190 (part_type=190)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×53 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART191 (part_type=191)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×83 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART192 (part_type=192)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×103 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART193 (part_type=193)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×56 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART194 (part_type=194)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×45 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART195 (part_type=195)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×30 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART196 (part_type=196)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×54 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART197 (part_type=197)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(136×16 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART198 (part_type=198)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×57 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART199 (part_type=199)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(128×73 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART2 (part_type=2)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×32 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART20 (part_type=20)
- 7 frames, 1 states, 15 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×12 @ 0,0)
  - Commands: DRAW_BMP=7, END_ANM=1, END_FRAME=7

### PART200 (part_type=200)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×11 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART201 (part_type=201)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(128×24 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART202 (part_type=202)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(168×18 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART203 (part_type=203)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×72 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART204 (part_type=204)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×79 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART205 (part_type=205)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×72 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART206 (part_type=206)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(112×32 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART207 (part_type=207)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×18 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART208 (part_type=208)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×14 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART209 (part_type=209)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×81 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART21 (part_type=21)
- 8 frames, 8 states, 33 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=6 → first_frame_id=0 frame=(32×32 @ 0,0)
  - state_id=7 → first_frame_id=1 frame=(32×32 @ 0,0)
  - state_id=8 → first_frame_id=2 frame=(32×32 @ 0,0)
  - state_id=9 → first_frame_id=3 frame=(32×32 @ 0,0)
  - state_id=10 → first_frame_id=4 frame=(32×32 @ 0,0)
  - state_id=11 → first_frame_id=5 frame=(32×32 @ 0,0)
  - state_id=12 → first_frame_id=6 frame=(32×32 @ 0,0)
  - state_id=13 → first_frame_id=7 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=24, END_ANM=1, END_FRAME=8

### PART210 (part_type=210)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×74 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART211 (part_type=211)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×40 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART212 (part_type=212)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×49 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART213 (part_type=213)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×44 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART214 (part_type=214)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×28 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART215 (part_type=215)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×54 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART216 (part_type=216)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×36 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART217 (part_type=217)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(96×45 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART218 (part_type=218)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×91 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART219 (part_type=219)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(144×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART22 (part_type=22)
- 14 frames, 2 states, 68 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(35×37 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(35×37 @ 0,0)
  - Commands: DRAW_BMP=52, END_ANM=1, END_FRAME=14, PLAY_SFX=1

### PART220 (part_type=220)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×71 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART221 (part_type=221)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×58 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART222 (part_type=222)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×16 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART223 (part_type=223)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×31 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART224 (part_type=224)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×27 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART225 (part_type=225)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×35 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART226 (part_type=226)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(136×61 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART227 (part_type=227)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×25 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART228 (part_type=228)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×42 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART229 (part_type=229)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×42 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART23 (part_type=23)
- 4 frames, 2 states, 12 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×15 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(32×18 @ 0,-3)
  - Commands: DRAW_BMP=7, END_ANM=1, END_FRAME=4

### PART230 (part_type=230)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×16 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART231 (part_type=231)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×12 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART232 (part_type=232)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×16 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART233 (part_type=233)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×21 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART234 (part_type=234)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×18 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART235 (part_type=235)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×13 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART236 (part_type=236)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×19 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART237 (part_type=237)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×18 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART238 (part_type=238)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×35 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART239 (part_type=239)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×25 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART24 (part_type=24)
- 69 frames, 2 states, 414 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×46 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(32×46 @ 0,0)
  - Commands: DRAW_BMP=276, END_ANM=1, END_FRAME=69, PLAY_SFX=68

### PART240 (part_type=240)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×35 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART241 (part_type=241)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×25 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART242 (part_type=242)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×52 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART243 (part_type=243)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×31 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART244 (part_type=244)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×68 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART245 (part_type=245)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×81 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART246 (part_type=246)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×66 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART247 (part_type=247)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×46 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART248 (part_type=248)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×21 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART249 (part_type=249)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×22 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART25 (part_type=25)
- 3 frames, 3 states, 14 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(48×21 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(69×34 @ 0,-8)
  - state_id=2 → first_frame_id=2 frame=(69×34 @ 0,-8)
  - Commands: DRAW_BMP=9, END_ANM=1, END_FRAME=3, PLAY_SFX=1

### PART250 (part_type=250)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×27 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART251 (part_type=251)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×33 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART252 (part_type=252)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×19 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART254 (part_type=254)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×14 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART255 (part_type=255)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×35 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART256 (part_type=256)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×15 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART257 (part_type=257)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×9 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART258 (part_type=258)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×11 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART259 (part_type=259)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×21 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART26 (part_type=26)
- 36 frames, 8 states, 209 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=9 → first_frame_id=0 frame=(81×34 @ 0,0)
  - state_id=10 → first_frame_id=1 frame=(81×34 @ 0,0)
  - state_id=11 → first_frame_id=2 frame=(81×34 @ 0,0)
  - state_id=12 → first_frame_id=3 frame=(81×34 @ 0,0)
  - state_id=2 → first_frame_id=4 frame=(81×34 @ 0,0)
  - state_id=3 → first_frame_id=12 frame=(81×34 @ 0,0)
  - state_id=4 → first_frame_id=20 frame=(81×34 @ 0,0)
  - state_id=5 → first_frame_id=28 frame=(81×34 @ 0,0)
  - Commands: DRAW_BMP=140, END_ANM=1, END_FRAME=36, PLAY_SFX=32

### PART260 (part_type=260)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(120×35 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART261 (part_type=261)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(104×35 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART262 (part_type=262)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(176×91 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART263 (part_type=263)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(216×88 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART264 (part_type=264)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×53 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART265 (part_type=265)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×20 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART266 (part_type=266)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×25 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART267 (part_type=267)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×26 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART268 (part_type=268)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×111 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART269 (part_type=269)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×101 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART27 (part_type=27)
- 10 frames, 4 states, 51 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(70×44 @ 0,0)
  - state_id=6 → first_frame_id=1 frame=(70×44 @ 0,0)
  - state_id=5 → first_frame_id=8 frame=(70×44 @ 0,0)
  - state_id=4 → first_frame_id=9 frame=(70×44 @ 0,0)
  - Commands: DRAW_BMP=39, END_ANM=1, END_FRAME=10, PLAY_SFX=1

### PART270 (part_type=270)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(104×76 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART271 (part_type=271)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×64 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART272 (part_type=272)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×62 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART273 (part_type=273)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×60 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART274 (part_type=274)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×46 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART277 (part_type=277)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(120×113 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART278 (part_type=278)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(112×66 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART279 (part_type=279)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(64×80 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART28 (part_type=28)
- 8 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×18 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=8

### PART281 (part_type=281)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART282 (part_type=282)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART283 (part_type=283)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART284 (part_type=284)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART285 (part_type=285)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART286 (part_type=286)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART287 (part_type=287)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART288 (part_type=288)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART289 (part_type=289)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART29 (part_type=29)
- 8 frames, 3 states, 57 commands
- Dimensions: 0×0
- Animated: True (84 ticks in 22 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(28×65 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(27×79 @ 0,0)
  - state_id=3 → first_frame_id=7 frame=(28×65 @ 0,0)
  - Commands: DRAW_BMP=48, END_ANM=1, END_FRAME=8

### PART290 (part_type=290)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART291 (part_type=291)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART292 (part_type=292)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART293 (part_type=293)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART294 (part_type=294)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(8×1 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART3 (part_type=3)
- 3 frames, 1 states, 10 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=6 → first_frame_id=0 frame=(80×39 @ 0,0)
  - Commands: DRAW_BMP=6, END_ANM=1, END_FRAME=3

### PART30 (part_type=30)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×40 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART31 (part_type=31)
- 68 frames, 7 states, 654 commands
- Dimensions: 0×0
- Animated: True (4558 ticks in 185 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(106×79 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(106×79 @ 0,0)
  - state_id=4 → first_frame_id=128
  - state_id=9 → first_frame_id=137
  - state_id=5 → first_frame_id=159
  - state_id=7 → first_frame_id=173
  - state_id=8 → first_frame_id=179
  - Commands: DRAW_BMP=579, END_ANM=1, END_FRAME=68, PLAY_SFX=6

### PART32 (part_type=32)
- 4 frames, 2 states, 14 commands
- Dimensions: 0×0
- Animated: True (10 ticks in 6 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×54 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(106×40 @ -42,10)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=4, PLAY_SFX=1

### PART33 (part_type=33)
- 5 frames, 2 states, 21 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×50 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(72×50 @ 0,0)
  - Commands: DRAW_BMP=15, END_ANM=1, END_FRAME=5

### PART34 (part_type=34)
- 13 frames, 2 states, 27 commands
- Dimensions: 0×0
- Animated: True (251 ticks in 56 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×62 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(56×62 @ 0,0)
  - Commands: DRAW_BMP=13, END_ANM=1, END_FRAME=13

### PART35 (part_type=35)
- 14 frames, 3 states, 30 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(56×39 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(56×39 @ 0,0)
  - state_id=4 → first_frame_id=13 frame=(88×79 @ -30,-1)
  - Commands: DRAW_BMP=14, END_ANM=1, END_FRAME=14, PLAY_SFX=1

### PART36 (part_type=36)
- 107 frames, 15 states, 407 commands
- Dimensions: 0×0
- Animated: True (5864 ticks in 117 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×85 @ 28,0)
  - state_id=10 → first_frame_id=1 frame=(32×87 @ 28,-2)
  - state_id=17 → first_frame_id=4 frame=(64×110 @ 13,0)
  - state_id=9 → first_frame_id=31 frame=(86×29 @ 0,28)
  - state_id=8 → first_frame_id=35 frame=(114×62 @ -28,11)
  - state_id=12 → first_frame_id=41 frame=(111×50 @ -25,15)
  - state_id=16 → first_frame_id=42 frame=(105×62 @ -19,13)
  - state_id=18 → first_frame_id=45 frame=(102×62 @ -16,12)
  - state_id=14 → first_frame_id=66 frame=(88×29 @ -2,28)
  - state_id=15 → first_frame_id=72 frame=(86×51 @ -1,11)
  - state_id=25 → first_frame_id=78 frame=(110×49 @ -1,21)
  - state_id=20 → first_frame_id=79 frame=(112×50 @ -1,21)
  - state_id=21 → first_frame_id=83 frame=(102×62 @ -1,15)
  - state_id=23 → first_frame_id=104 frame=(84×29 @ -1,28)
  - state_id=24 → first_frame_id=111
  - Commands: DRAW_BMP=293, END_ANM=1, END_FRAME=107, PLAY_SFX=6

### PART37 (part_type=37)
- 10 frames, 6 states, 38 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=7 → first_frame_id=0 frame=(61×36 @ 0,0)
  - state_id=8 → first_frame_id=1 frame=(61×36 @ 0,0)
  - state_id=11 → first_frame_id=4 frame=(32×8 @ 29,11)
  - state_id=3 → first_frame_id=5 frame=(65×36 @ -5,-2)
  - state_id=4 → first_frame_id=6 frame=(64×17 @ -5,13)
  - state_id=9 → first_frame_id=7 frame=(70×17 @ -5,13)
  - Commands: DRAW_BMP=20, DRAW_LINE=6, END_ANM=1, END_FRAME=10, PLAY_SFX=1

### PART38 (part_type=38)
- 8 frames, 2 states, 25 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(72×32 @ 0,0)
  - state_id=2 → first_frame_id=4 frame=(72×32 @ 0,0)
  - Commands: DRAW_BMP=16, END_ANM=1, END_FRAME=8

### PART39 (part_type=39)
- 9 frames, 3 states, 29 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×27 @ 0,0)
  - state_id=5 → first_frame_id=2 frame=(56×43 @ 0,-16)
  - state_id=4 → first_frame_id=8 frame=(56×27 @ 0,0)
  - Commands: DRAW_BMP=18, END_ANM=1, END_FRAME=9, PLAY_SFX=1

### PART4 (part_type=4)
- 23 frames, 8 states, 51 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(40×51 @ 0,0)
  - state_id=7 → first_frame_id=1 frame=(40×51 @ 0,0)
  - state_id=2 → first_frame_id=6 frame=(48×51 @ 0,0)
  - state_id=6 → first_frame_id=7 frame=(48×51 @ 0,0)
  - state_id=4 → first_frame_id=13 frame=(56×51 @ 0,0)
  - state_id=8 → first_frame_id=14 frame=(56×51 @ 0,0)
  - state_id=5 → first_frame_id=18 frame=(40×42 @ 0,0)
  - state_id=9 → first_frame_id=19 frame=(40×42 @ 0,0)
  - Commands: DRAW_BMP=23, END_ANM=1, END_FRAME=23, PLAY_SFX=4

### PART40 (part_type=40)
- 11 frames, 2 states, 34 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×55 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(56×55 @ 0,0)
  - Commands: DRAW_BMP=22, END_ANM=1, END_FRAME=11

### PART41 (part_type=41)
- 3 frames, 1 states, 10 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(72×66 @ 0,0)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=3, PLAY_SFX=1

### PART42 (part_type=42)
- 54 frames, 9 states, 111 commands
- Dimensions: 0×0
- Animated: True (2008 ticks in 80 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×20 @ 0,0)
  - state_id=9 → first_frame_id=1 frame=(32×26 @ -1,-4)
  - state_id=7 → first_frame_id=23 frame=(32×24 @ -2,-4)
  - state_id=8 → first_frame_id=27 frame=(32×24 @ -2,-4)
  - state_id=10 → first_frame_id=30 frame=(32×23 @ -2,-3)
  - state_id=11 → first_frame_id=50 frame=(48×14 @ -24,3)
  - state_id=14 → first_frame_id=51 frame=(32×13 @ 0,4)
  - state_id=12 → first_frame_id=73
  - state_id=13 → first_frame_id=77
  - Commands: DRAW_BMP=54, END_ANM=1, END_FRAME=54, PLAY_SFX=2

### PART43 (part_type=43)
- 4 frames, 2 states, 12 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×23 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(26×24 @ 0,-1)
  - Commands: DRAW_BMP=7, END_ANM=1, END_FRAME=4

### PART44 (part_type=44)
- 8 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×15 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=8

### PART45 (part_type=45)
- 9 frames, 3 states, 27 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(56×29 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(57×29 @ 0,0)
  - state_id=2 → first_frame_id=4 frame=(57×46 @ 0,-17)
  - Commands: DRAW_BMP=17, END_ANM=1, END_FRAME=9

### PART46 (part_type=46)
- 20 frames, 2 states, 41 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=4 frame=(16×16 @ 0,0)
  - state_id=1 → first_frame_id=8 frame=(32×25 @ 0,0)
  - Commands: DRAW_BMP=20, END_ANM=1, END_FRAME=20

### PART47 (part_type=47)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART48 (part_type=48)
- 38 frames, 3 states, 77 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(16×16 @ 0,0)
  - state_id=3 → first_frame_id=13 frame=(16×16 @ 0,0)
  - state_id=4 → first_frame_id=26 frame=(16×16 @ 0,0)
  - Commands: DRAW_BMP=38, END_ANM=1, END_FRAME=38

### PART5 (part_type=5)
- 25 frames, 10 states, 71 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×16 @ 0,0)
  - state_id=11 → first_frame_id=1 frame=(32×16 @ 0,0)
  - state_id=4 → first_frame_id=5 frame=(48×16 @ 0,0)
  - state_id=12 → first_frame_id=6 frame=(48×16 @ 0,0)
  - state_id=6 → first_frame_id=10 frame=(64×16 @ 0,0)
  - state_id=13 → first_frame_id=11 frame=(64×16 @ 0,0)
  - state_id=8 → first_frame_id=15 frame=(80×16 @ 0,0)
  - state_id=14 → first_frame_id=16 frame=(80×16 @ 0,0)
  - state_id=10 → first_frame_id=20 frame=(96×16 @ 0,0)
  - state_id=15 → first_frame_id=21 frame=(96×16 @ 0,0)
  - Commands: DRAW_BMP=25, END_ANM=1, END_FRAME=25, PLAY_SFX=20

### PART50 (part_type=50)
- 38 frames, 3 states, 219 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(70×54 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(70×54 @ 0,0)
  - state_id=3 → first_frame_id=10 frame=(70×50 @ 0,0)
  - Commands: DRAW_BMP=152, END_ANM=1, END_FRAME=38, PLAY_SFX=28

### PART51 (part_type=51)
- 60 frames, 2 states, 297 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=9 → first_frame_id=0 frame=(65×33 @ 0,0)
  - state_id=10 → first_frame_id=1 frame=(65×33 @ 0,0)
  - Commands: DRAW_BMP=177, END_ANM=1, END_FRAME=60, PLAY_SFX=59

### PART52 (part_type=52)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×18 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART53 (part_type=53)
- 16 frames, 8 states, 46 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=6 → first_frame_id=0 frame=(24×24 @ 4,0)
  - state_id=7 → first_frame_id=1 frame=(24×25 @ 4,-1)
  - state_id=8 → first_frame_id=4 frame=(24×24 @ 4,0)
  - state_id=9 → first_frame_id=5 frame=(24×25 @ 4,0)
  - state_id=11 → first_frame_id=8 frame=(24×17 @ 0,4)
  - state_id=10 → first_frame_id=9 frame=(25×17 @ -1,4)
  - state_id=13 → first_frame_id=12 frame=(24×17 @ 0,4)
  - state_id=12 → first_frame_id=13 frame=(78×30 @ -48,4)
  - Commands: DRAW_BMP=29, END_ANM=1, END_FRAME=16

### PART54 (part_type=54)
- 103 frames, 14 states, 294 commands
- Dimensions: 0×0
- Animated: True (12376 ticks in 276 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×26 @ 0,0)
  - state_id=18 → first_frame_id=1 frame=(16×28 @ 4,-2)
  - state_id=19 → first_frame_id=24 frame=(16×28 @ 4,-2)
  - state_id=20 → first_frame_id=47 frame=(24×26 @ 0,0)
  - state_id=21 → first_frame_id=70 frame=(24×26 @ 3,0)
  - state_id=23 → first_frame_id=95 frame=(40×11 @ -1,16)
  - state_id=25 → first_frame_id=134
  - state_id=3 → first_frame_id=135
  - state_id=15 → first_frame_id=151
  - state_id=16 → first_frame_id=152
  - state_id=8 → first_frame_id=160
  - state_id=9 → first_frame_id=168
  - state_id=11 → first_frame_id=198
  - state_id=51 → first_frame_id=235
  - Commands: DRAW_BMP=176, END_ANM=1, END_FRAME=103, PLAY_SFX=14

### PART55 (part_type=55)
- 9 frames, 2 states, 35 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(62×48 @ 0,0)
  - state_id=5 → first_frame_id=1 frame=(62×48 @ 0,0)
  - Commands: DRAW_BMP=24, END_ANM=1, END_FRAME=9, PLAY_SFX=1

### PART56 (part_type=56)
- 18 frames, 3 states, 37 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×16 @ 0,0)
  - state_id=2 → first_frame_id=3 frame=(16×16 @ 0,0)
  - state_id=3 → first_frame_id=6 frame=(24×9 @ 5,3)
  - Commands: DRAW_BMP=18, END_ANM=1, END_FRAME=18

### PART57 (part_type=57)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(72×64 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART58 (part_type=58)
- 86 frames, 8 states, 524 commands
- Dimensions: 0×0
- Animated: True (5190 ticks in 141 sub-frames)
  - state_id=5 → first_frame_id=0 frame=(48×64 @ 0,0)
  - state_id=6 → first_frame_id=1 frame=(48×64 @ 0,0)
  - state_id=9 → first_frame_id=70 frame=(72×97 @ 0,-33)
  - state_id=8 → first_frame_id=108
  - state_id=4 → first_frame_id=111
  - state_id=15 → first_frame_id=112
  - state_id=13 → first_frame_id=122
  - state_id=14 → first_frame_id=131
  - Commands: DRAW_BMP=434, END_ANM=1, END_FRAME=86, PLAY_SFX=3

### PART59 (part_type=59)
- 3 frames, 3 states, 7 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×23 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(24×27 @ 1,-2)
  - state_id=4 → first_frame_id=2 frame=(32×22 @ -1,0)
  - Commands: DRAW_BMP=3, END_ANM=1, END_FRAME=3

### PART6 (part_type=6)
- 17 frames, 2 states, 85 commands
- Dimensions: 0×0
- Animated: True (269 ticks in 36 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(48×32 @ 0,0)
  - state_id=6 → first_frame_id=31
  - Commands: DRAW_BMP=66, END_ANM=1, END_FRAME=17, PLAY_SFX=1

### PART60 (part_type=60)
- 30 frames, 3 states, 61 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×16 @ 0,0)
  - state_id=2 → first_frame_id=8 frame=(16×16 @ 0,0)
  - state_id=3 → first_frame_id=18 frame=(40×20 @ 0,0)
  - Commands: DRAW_BMP=30, END_ANM=1, END_FRAME=30

### PART61 (part_type=61)
- 47 frames, 11 states, 191 commands
- Dimensions: 0×0
- Animated: True (1830 ticks in 86 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(100×16 @ 0,0)
  - state_id=7 → first_frame_id=1 frame=(95×18 @ 0,-2)
  - state_id=8 → first_frame_id=11 frame=(100×26 @ 0,-10)
  - state_id=4 → first_frame_id=21 frame=(96×16 @ 4,0)
  - state_id=12 → first_frame_id=24 frame=(96×17 @ 4,-1)
  - state_id=5 → first_frame_id=26 frame=(96×17 @ 4,-1)
  - state_id=6 → first_frame_id=65
  - state_id=9 → first_frame_id=67
  - state_id=10 → first_frame_id=77
  - state_id=11 → first_frame_id=82
  - state_id=13 → first_frame_id=84
  - Commands: DRAW_BMP=141, END_ANM=1, END_FRAME=47, PLAY_SFX=2

### PART62 (part_type=62)
- 24 frames, 3 states, 96 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×41 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(40×41 @ 0,-1)
  - state_id=4 → first_frame_id=18 frame=(73×69 @ -33,-28)
  - Commands: DRAW_BMP=45, DRAW_LINE=23, DRAW_RECT=3, END_ANM=1, END_FRAME=24

### PART63 (part_type=63)
- 16 frames, 16 states, 33 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(24×23 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(24×23 @ 0,0)
  - state_id=4 → first_frame_id=2 frame=(24×23 @ 0,0)
  - state_id=5 → first_frame_id=3 frame=(24×23 @ 0,0)
  - state_id=6 → first_frame_id=4 frame=(24×23 @ 0,0)
  - state_id=7 → first_frame_id=5 frame=(24×23 @ 0,0)
  - state_id=8 → first_frame_id=6 frame=(24×23 @ 0,0)
  - state_id=9 → first_frame_id=7 frame=(24×23 @ 0,0)
  - state_id=10 → first_frame_id=8 frame=(24×23 @ 0,0)
  - state_id=11 → first_frame_id=9 frame=(24×23 @ 0,0)
  - state_id=12 → first_frame_id=10 frame=(24×23 @ 0,0)
  - state_id=13 → first_frame_id=11 frame=(24×23 @ 0,0)
  - state_id=14 → first_frame_id=12 frame=(24×23 @ 0,0)
  - state_id=15 → first_frame_id=13 frame=(24×23 @ 0,0)
  - state_id=16 → first_frame_id=14 frame=(24×23 @ 0,0)
  - state_id=17 → first_frame_id=15 frame=(24×23 @ 0,0)
  - Commands: DRAW_BMP=16, END_ANM=1, END_FRAME=16

### PART64 (part_type=64)
- 3 frames, 2 states, 8 commands
- Dimensions: 0×0
- Animated: True (7 ticks in 5 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(48×41 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(48×41 @ 0,0)
  - Commands: DRAW_BMP=3, END_ANM=1, END_FRAME=3, PLAY_SFX=1

### PART65 (part_type=65)
- 18 frames, 3 states, 72 commands
- Dimensions: 0×0
- Animated: True (173 ticks in 20 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×62 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(40×62 @ 0,0)
  - state_id=3 → first_frame_id=8 frame=(48×65 @ -1,-3)
  - Commands: DRAW_BMP=36, END_ANM=1, END_FRAME=18, PLAY_SFX=17

### PART66 (part_type=66)
- 7 frames, 3 states, 22 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×21 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(24×21 @ 0,0)
  - state_id=2 → first_frame_id=6 frame=(24×21 @ 0,0)
  - Commands: DRAW_BMP=13, END_ANM=1, END_FRAME=7, PLAY_SFX=1

### PART67 (part_type=67)
- 20 frames, 3 states, 139 commands
- Dimensions: 0×0
- Animated: True (338 ticks in 36 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(43×51 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(43×49 @ 0,2)
  - state_id=2 → first_frame_id=25
  - Commands: DRAW_BMP=105, END_ANM=1, END_FRAME=20, PLAY_SFX=13

### PART68 (part_type=68)
- 8 frames, 1 states, 17 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=8

### PART69 (part_type=69)
- 5 frames, 2 states, 15 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×16 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(48×16 @ 0,0)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=5, PLAY_SFX=4

### PART7 (part_type=7)
- 4 frames, 2 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(24×22 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(24×19 @ 0,3)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART70 (part_type=70)
- 93 frames, 15 states, 355 commands
- Dimensions: 0×0
- Animated: True (4441 ticks in 103 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×95 @ 35,0)
  - state_id=8 → first_frame_id=1 frame=(64×120 @ 19,0)
  - state_id=4 → first_frame_id=28 frame=(8×2 @ 34,0)
  - state_id=3 → first_frame_id=32 frame=(124×49 @ -24,22)
  - state_id=12 → first_frame_id=38 frame=(114×49 @ -14,28)
  - state_id=13 → first_frame_id=39 frame=(115×50 @ -15,26)
  - state_id=14 → first_frame_id=40 frame=(109×62 @ -9,22)
  - state_id=15 → first_frame_id=56 frame=(109×25 @ -9,35)
  - state_id=16 → first_frame_id=64 frame=(121×49 @ -4,22)
  - state_id=17 → first_frame_id=70 frame=(116×49 @ -4,27)
  - state_id=18 → first_frame_id=71 frame=(119×50 @ -4,28)
  - state_id=19 → first_frame_id=72 frame=(116×62 @ -4,20)
  - state_id=20 → first_frame_id=88 frame=(109×25 @ 14,35)
  - state_id=21 → first_frame_id=96
  - state_id=22 → first_frame_id=102
  - Commands: DRAW_BMP=255, END_ANM=1, END_FRAME=93, PLAY_SFX=6

### PART71 (part_type=71)
- 9 frames, 9 states, 23 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(50×32 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(64×32 @ 0,0)
  - state_id=4 → first_frame_id=2 frame=(48×48 @ 0,0)
  - state_id=5 → first_frame_id=3 frame=(64×48 @ 0,0)
  - state_id=6 → first_frame_id=4 frame=(80×64 @ 0,0)
  - state_id=7 → first_frame_id=5 frame=(48×32 @ 0,0)
  - state_id=8 → first_frame_id=6 frame=(64×32 @ 0,0)
  - state_id=9 → first_frame_id=7 frame=(48×48 @ 0,0)
  - state_id=10 → first_frame_id=8 frame=(64×48 @ 0,0)
  - Commands: DRAW_BMP=13, END_ANM=1, END_FRAME=9

### PART72 (part_type=72)
- 12 frames, 1 states, 25 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(24×7 @ -2,3)
  - Commands: DRAW_BMP=12, END_ANM=1, END_FRAME=12

### PART73 (part_type=73)
- 9 frames, 3 states, 37 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(53×49 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(61×52 @ 0,0)
  - state_id=4 → first_frame_id=8 frame=(22×49 @ 0,0)
  - Commands: DRAW_BMP=26, END_ANM=1, END_FRAME=9, PLAY_SFX=1

### PART74 (part_type=74)
- 8 frames, 2 states, 23 commands
- Dimensions: 0×0
- Animated: True (49 ticks in 14 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×29 @ 0,0)
  - state_id=3 → first_frame_id=13
  - Commands: DRAW_BMP=8, END_ANM=1, END_FRAME=8, PLAY_SFX=6

### PART75 (part_type=75)
- 18 frames, 4 states, 80 commands
- Dimensions: 0×0
- Animated: True (299 ticks in 35 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(43×23 @ 0,0)
  - state_id=4 → first_frame_id=2 frame=(46×23 @ 0,0)
  - state_id=3 → first_frame_id=10 frame=(33×38 @ -1,-15)
  - state_id=2 → first_frame_id=27
  - Commands: DRAW_BMP=60, END_ANM=1, END_FRAME=18, PLAY_SFX=1

### PART76 (part_type=76)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×15 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART77 (part_type=77)
- 4 frames, 4 states, 11 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(61×33 @ 0,0)
  - state_id=5 → first_frame_id=1 frame=(16×8 @ 45,9)
  - state_id=6 → first_frame_id=2 frame=(64×21 @ 1,6)
  - state_id=3 → first_frame_id=3 frame=(64×21 @ 1,6)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=4, PLAY_SFX=1

### PART78 (part_type=78)
- 32 frames, 4 states, 174 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×34 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(48×34 @ 0,0)
  - state_id=5 → first_frame_id=12 frame=(48×41 @ 0,-7)
  - state_id=7 → first_frame_id=27 frame=(48×36 @ 0,-2)
  - Commands: DRAW_BMP=140, END_ANM=1, END_FRAME=32, PLAY_SFX=1

### PART79 (part_type=79)
- 12 frames, 5 states, 44 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×83 @ 0,0)
  - state_id=5 → first_frame_id=1 frame=(40×83 @ 0,0)
  - state_id=4 → first_frame_id=6 frame=(40×83 @ 0,0)
  - state_id=2 → first_frame_id=8 frame=(80×118 @ -17,-34)
  - state_id=3 → first_frame_id=10 frame=(17×65 @ 10,19)
  - Commands: DRAW_BMP=30, END_ANM=1, END_FRAME=12, PLAY_SFX=1

### PART8 (part_type=8)
- 0 frames, 1 states, 1 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0
  - Commands: END_ANM=1

### PART80 (part_type=80)
- 135 frames, 15 states, 424 commands
- Dimensions: 0×0
- Animated: True (9764 ticks in 147 sub-frames)
  - state_id=9 → first_frame_id=0 frame=(26×86 @ 0,0)
  - state_id=19 → first_frame_id=1 frame=(64×106 @ -16,0)
  - state_id=10 → first_frame_id=22 frame=(24×87 @ 0,0)
  - state_id=11 → first_frame_id=25 frame=(24×86 @ 0,0)
  - state_id=6 → first_frame_id=31 frame=(56×57 @ -18,-11)
  - state_id=12 → first_frame_id=48 frame=(56×105 @ -14,0)
  - state_id=20 → first_frame_id=49 frame=(56×106 @ -17,0)
  - state_id=14 → first_frame_id=70 frame=(24×86 @ 0,0)
  - state_id=15 → first_frame_id=73 frame=(40×37 @ -10,-3)
  - state_id=7 → first_frame_id=79 frame=(40×37 @ -10,-3)
  - state_id=16 → first_frame_id=95 frame=(56×100 @ -15,0)
  - state_id=21 → first_frame_id=96 frame=(56×97 @ -10,0)
  - state_id=17 → first_frame_id=117 frame=(96×111 @ -37,-28)
  - state_id=18 → first_frame_id=120 frame=(96×111 @ -37,-28)
  - state_id=8 → first_frame_id=126 frame=(96×111 @ -37,-28)
  - Commands: DRAW_BMP=282, END_ANM=1, END_FRAME=135, PLAY_SFX=6

### PART81 (part_type=81)
- 48 frames, 9 states, 211 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×35 @ 0,0)
  - state_id=8 → first_frame_id=1 frame=(48×31 @ 0,4)
  - state_id=2 → first_frame_id=5 frame=(40×49 @ 4,-21)
  - state_id=6 → first_frame_id=16 frame=(48×35 @ 0,0)
  - state_id=9 → first_frame_id=17 frame=(48×31 @ 0,4)
  - state_id=3 → first_frame_id=21 frame=(40×49 @ 4,-21)
  - state_id=7 → first_frame_id=32 frame=(48×35 @ 0,0)
  - state_id=10 → first_frame_id=33 frame=(48×31 @ 0,4)
  - state_id=4 → first_frame_id=37 frame=(40×49 @ 4,-21)
  - Commands: DRAW_BMP=159, END_ANM=1, END_FRAME=48, PLAY_SFX=3

### PART82 (part_type=82)
- 30 frames, 3 states, 61 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×16 @ 0,0)
  - state_id=2 → first_frame_id=12 frame=(16×16 @ 0,0)
  - state_id=3 → first_frame_id=18 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=30, END_ANM=1, END_FRAME=30

### PART83 (part_type=83)
- 20 frames, 3 states, 41 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(16×16 @ 0,0)
  - state_id=1 → first_frame_id=4 frame=(16×16 @ 0,0)
  - state_id=3 → first_frame_id=8 frame=(16×16 @ 0,0)
  - Commands: DRAW_BMP=20, END_ANM=1, END_FRAME=20

### PART84 (part_type=84)
- 25 frames, 3 states, 51 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×16 @ 0,0)
  - state_id=3 → first_frame_id=4 frame=(16×16 @ 0,0)
  - state_id=2 → first_frame_id=13 frame=(24×32 @ 0,0)
  - Commands: DRAW_BMP=25, END_ANM=1, END_FRAME=25

### PART85 (part_type=85)
- 35 frames, 3 states, 71 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×16 @ 0,0)
  - state_id=2 → first_frame_id=13 frame=(16×16 @ 0,0)
  - state_id=3 → first_frame_id=23 frame=(24×27 @ 0,0)
  - Commands: DRAW_BMP=35, END_ANM=1, END_FRAME=35

### PART86 (part_type=86)
- 5 frames, 2 states, 11 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×17 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(24×17 @ 0,0)
  - Commands: DRAW_BMP=5, END_ANM=1, END_FRAME=5

### PART87 (part_type=87)
- 21 frames, 7 states, 43 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×27 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(32×27 @ 0,0)
  - state_id=7 → first_frame_id=2 frame=(32×27 @ 0,0)
  - state_id=8 → first_frame_id=3 frame=(32×27 @ 0,0)
  - state_id=9 → first_frame_id=4 frame=(32×27 @ 0,0)
  - state_id=5 → first_frame_id=5 frame=(32×27 @ 0,0)
  - state_id=4 → first_frame_id=13 frame=(32×27 @ 0,0)
  - Commands: DRAW_BMP=21, END_ANM=1, END_FRAME=21

### PART88 (part_type=88)
- 10 frames, 4 states, 41 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=20 → first_frame_id=0 frame=(40×48 @ 0,0)
  - state_id=16 → first_frame_id=1 frame=(40×48 @ 0,0)
  - state_id=21 → first_frame_id=5 frame=(48×38 @ 0,0)
  - state_id=22 → first_frame_id=6 frame=(48×38 @ 0,0)
  - Commands: DRAW_BMP=30, END_ANM=1, END_FRAME=10

### PART89 (part_type=89)
- 9 frames, 2 states, 56 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(88×49 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(88×49 @ 0,0)
  - Commands: DRAW_BMP=45, END_ANM=1, END_FRAME=9, PLAY_SFX=1

### PART9 (part_type=9)
- 17 frames, 2 states, 35 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=3 → first_frame_id=0 frame=(32×32 @ 0,0)
  - state_id=4 → first_frame_id=1 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=17, END_ANM=1, END_FRAME=17

### PART90 (part_type=90)
- 9 frames, 2 states, 47 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×69 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(24×69 @ 0,0)
  - Commands: DRAW_BMP=36, END_ANM=1, END_FRAME=9, PLAY_SFX=1

### PART91 (part_type=91)
- 20 frames, 8 states, 74 commands
- Dimensions: 0×0
- Animated: True (558 ticks in 52 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×18 @ 9,17)
  - state_id=6 → first_frame_id=1 frame=(24×42 @ 17,9)
  - state_id=7 → first_frame_id=2 frame=(48×18 @ -6,17)
  - state_id=8 → first_frame_id=3 frame=(24×42 @ 17,0)
  - state_id=9 → first_frame_id=4 frame=(48×18 @ 9,17)
  - state_id=4 → first_frame_id=16 frame=(24×42 @ 17,0)
  - state_id=3 → first_frame_id=28
  - state_id=2 → first_frame_id=40
  - Commands: DRAW_BMP=40, END_ANM=1, END_FRAME=20, PLAY_SFX=13

### PART92 (part_type=92)
- 20 frames, 8 states, 74 commands
- Dimensions: 0×0
- Animated: True (558 ticks in 52 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×18 @ 9,17)
  - state_id=6 → first_frame_id=1 frame=(24×42 @ 17,9)
  - state_id=7 → first_frame_id=2 frame=(48×18 @ -6,17)
  - state_id=8 → first_frame_id=3 frame=(24×42 @ 17,0)
  - state_id=9 → first_frame_id=4 frame=(48×18 @ 9,17)
  - state_id=4 → first_frame_id=16 frame=(24×42 @ 17,0)
  - state_id=3 → first_frame_id=28
  - state_id=2 → first_frame_id=40
  - Commands: DRAW_BMP=42, END_ANM=1, END_FRAME=20, PLAY_SFX=11

### PART93 (part_type=93)
- 20 frames, 8 states, 74 commands
- Dimensions: 0×0
- Animated: True (558 ticks in 52 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(48×18 @ 9,17)
  - state_id=5 → first_frame_id=1 frame=(24×42 @ 17,9)
  - state_id=6 → first_frame_id=2 frame=(48×18 @ -6,17)
  - state_id=7 → first_frame_id=3 frame=(24×42 @ 17,0)
  - state_id=9 → first_frame_id=4 frame=(48×18 @ 9,17)
  - state_id=4 → first_frame_id=16 frame=(24×42 @ 17,0)
  - state_id=3 → first_frame_id=28
  - state_id=2 → first_frame_id=40
  - Commands: DRAW_BMP=40, END_ANM=1, END_FRAME=20, PLAY_SFX=13

### PART94 (part_type=94)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(24×23 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PART95 (part_type=95)
- 115 frames, 32 states, 452 commands
- Dimensions: 0×0
- Animated: True (19665 ticks in 343 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(40×40 @ 0,0)
  - state_id=2 → first_frame_id=1 frame=(40×40 @ 0,0)
  - state_id=3 → first_frame_id=13 frame=(40×40 @ 0,0)
  - state_id=4 → first_frame_id=25 frame=(40×40 @ 0,0)
  - state_id=5 → first_frame_id=37 frame=(40×40 @ 0,0)
  - state_id=6 → first_frame_id=49 frame=(40×40 @ 0,0)
  - state_id=7 → first_frame_id=61 frame=(40×40 @ 0,0)
  - state_id=8 → first_frame_id=73 frame=(40×40 @ 0,0)
  - state_id=16 → first_frame_id=85 frame=(40×40 @ 0,0)
  - state_id=17 → first_frame_id=88 frame=(40×40 @ 0,0)
  - state_id=19 → first_frame_id=100 frame=(40×40 @ 0,0)
  - state_id=20 → first_frame_id=109 frame=(40×40 @ 0,0)
  - state_id=21 → first_frame_id=121
  - state_id=22 → first_frame_id=133
  - state_id=23 → first_frame_id=145
  - state_id=24 → first_frame_id=157
  - state_id=25 → first_frame_id=169
  - state_id=26 → first_frame_id=172
  - state_id=27 → first_frame_id=184
  - state_id=28 → first_frame_id=196
  - state_id=29 → first_frame_id=208
  - state_id=30 → first_frame_id=220
  - state_id=31 → first_frame_id=232
  - state_id=32 → first_frame_id=244
  - state_id=33 → first_frame_id=256
  - state_id=9 → first_frame_id=259
  - state_id=10 → first_frame_id=271
  - state_id=11 → first_frame_id=283
  - state_id=12 → first_frame_id=295
  - state_id=13 → first_frame_id=307
  - state_id=14 → first_frame_id=319
  - state_id=15 → first_frame_id=331
  - Commands: DRAW_BMP=336, END_ANM=1, END_FRAME=115

### PART96 (part_type=96)
- 28 frames, 10 states, 85 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=2 → first_frame_id=0 frame=(32×32 @ 0,0)
  - state_id=3 → first_frame_id=1 frame=(32×32 @ 0,0)
  - state_id=4 → first_frame_id=2 frame=(32×32 @ 0,0)
  - state_id=5 → first_frame_id=3 frame=(32×32 @ 0,0)
  - state_id=6 → first_frame_id=4 frame=(32×32 @ 0,0)
  - state_id=7 → first_frame_id=5 frame=(32×32 @ 0,0)
  - state_id=8 → first_frame_id=6 frame=(32×32 @ 0,0)
  - state_id=10 → first_frame_id=7 frame=(32×32 @ 0,0)
  - state_id=11 → first_frame_id=14 frame=(32×32 @ 0,0)
  - state_id=12 → first_frame_id=21 frame=(32×32 @ 0,0)
  - Commands: DRAW_BMP=56, END_ANM=1, END_FRAME=28

### PART97 (part_type=97)
- 6 frames, 2 states, 13 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×38 @ 0,0)
  - state_id=2 → first_frame_id=3 frame=(40×16 @ 0,0)
  - Commands: DRAW_BMP=6, END_ANM=1, END_FRAME=6

### PART98 (part_type=98)
- 1 frames, 1 states, 3 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(80×80 @ 0,0)
  - Commands: DRAW_BMP=1, END_ANM=1, END_FRAME=1

### PART99 (part_type=99)
- 4 frames, 1 states, 9 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(16×32 @ 0,0)
  - Commands: DRAW_BMP=4, END_ANM=1, END_FRAME=4

### PARTSBIN
- 38 frames, 15 states, 146 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=8 → first_frame_id=0 frame=(640×400 @ 0,0)
  - state_id=1 → first_frame_id=1 frame=(80×377 @ 560,0)
  - state_id=2 → first_frame_id=2 frame=(34×30 @ 566,6)
  - state_id=3 → first_frame_id=4 frame=(34×35 @ 602,4)
  - state_id=4 → first_frame_id=6 frame=(50×27 @ 577,40)
  - state_id=7 → first_frame_id=8 frame=(57×30 @ 568,38)
  - state_id=5 → first_frame_id=10 frame=(24×24 @ 566,336)
  - state_id=6 → first_frame_id=13 frame=(24×24 @ 589,337)
  - state_id=12 → first_frame_id=16 frame=(24×31 @ 611,334)
  - state_id=13 → first_frame_id=19 frame=(58×29 @ 562,42)
  - state_id=14 → first_frame_id=22 frame=(56×29 @ 571,304)
  - state_id=15 → first_frame_id=25 frame=(25×29 @ 610,334)
  - state_id=16 → first_frame_id=28 frame=(51×26 @ 568,42)
  - state_id=17 → first_frame_id=31 frame=(43×29 @ 579,39)
  - state_id=19 → first_frame_id=34 frame=(32×30 @ 563,6)
  - Commands: DRAW_BMP=92, DRAW_RECT=3, END_ANM=1, END_FRAME=38, PLAY_SFX=12

### PROFESOR
- 15 frames, 7 states, 52 commands
- Dimensions: 0×0
- Animated: True (144 ticks in 54 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(34×29 @ 71,32)
  - state_id=5 → first_frame_id=1 frame=(127×111 @ 58,27)
  - state_id=3 → first_frame_id=41
  - state_id=4 → first_frame_id=44
  - state_id=11 → first_frame_id=47
  - state_id=28 → first_frame_id=50
  - state_id=29 → first_frame_id=52
  - Commands: DRAW_BMP=30, DRAW_RECT=1, END_ANM=1, END_FRAME=15, PLAY_SFX=5

### PROFESR2
- 181 frames, 25 states, 2579 commands
- Dimensions: 0×0
- Animated: True (41484 ticks in 486 sub-frames)
  - state_id=1 → first_frame_id=0 frame=(34×29 @ 71,32)
  - state_id=5 → first_frame_id=1 frame=(120×111 @ 58,27)
  - state_id=6 → first_frame_id=41 frame=(120×114 @ 58,27)
  - state_id=7 → first_frame_id=51 frame=(135×123 @ 58,27)
  - state_id=9 → first_frame_id=55 frame=(135×123 @ 58,27)
  - state_id=10 → first_frame_id=89 frame=(129×141 @ 58,27)
  - state_id=12 → first_frame_id=99 frame=(121×112 @ 58,27)
  - state_id=13 → first_frame_id=126 frame=(120×114 @ 58,27)
  - state_id=15 → first_frame_id=160 frame=(160×78 @ 14,60)
  - state_id=18 → first_frame_id=211
  - state_id=19 → first_frame_id=252
  - state_id=30 → first_frame_id=257
  - state_id=20 → first_frame_id=269
  - state_id=21 → first_frame_id=293
  - state_id=22 → first_frame_id=315
  - state_id=23 → first_frame_id=363
  - state_id=24 → first_frame_id=376
  - state_id=25 → first_frame_id=396
  - state_id=26 → first_frame_id=433
  - state_id=27 → first_frame_id=443
  - state_id=3 → first_frame_id=473
  - state_id=4 → first_frame_id=476
  - state_id=11 → first_frame_id=479
  - state_id=28 → first_frame_id=482
  - state_id=29 → first_frame_id=484
  - Commands: DRAW_BMP=2372, DRAW_LINE=1, DRAW_RECT=3, END_ANM=1, END_FRAME=181, PLAY_SFX=21

### PROGPART
- 243 frames, 72 states, 770 commands
- Dimensions: 0×0
- Animated: True (38877 ticks in 378 sub-frames)
  - state_id=6 → first_frame_id=0 frame=(32×28 @ 172,73)
  - state_id=8 → first_frame_id=3 frame=(32×27 @ 172,73)
  - state_id=82 → first_frame_id=6 frame=(24×24 @ 130,34)
  - state_id=83 → first_frame_id=9 frame=(24×24 @ 158,35)
  - state_id=2 → first_frame_id=12 frame=(24×14 @ 174,81)
  - state_id=84 → first_frame_id=13 frame=(16×23 @ 188,37)
  - state_id=104 → first_frame_id=14 frame=(24×30 @ 70,28)
  - state_id=12 → first_frame_id=16 frame=(56×42 @ 124,70)
  - state_id=11 → first_frame_id=17 frame=(56×42 @ 125,70)
  - state_id=10 → first_frame_id=18 frame=(56×44 @ 123,69)
  - state_id=95 → first_frame_id=19 frame=(40×50 @ 131,66)
  - state_id=90 → first_frame_id=20 frame=(40×50 @ 131,66)
  - state_id=91 → first_frame_id=49 frame=(40×52 @ 131,66)
  - state_id=92 → first_frame_id=70 frame=(24×23 @ 137,83)
  - state_id=93 → first_frame_id=83 frame=(24×27 @ 139,79)
  - state_id=94 → first_frame_id=93 frame=(24×26 @ 143,80)
  - state_id=15 → first_frame_id=100 frame=(32×27 @ 137,82)
  - state_id=16 → first_frame_id=101 frame=(32×27 @ 137,82)
  - state_id=17 → first_frame_id=102 frame=(32×27 @ 137,82)
  - state_id=18 → first_frame_id=103 frame=(32×27 @ 137,82)
  - state_id=19 → first_frame_id=104 frame=(32×27 @ 137,82)
  - state_id=20 → first_frame_id=105 frame=(32×27 @ 137,82)
  - state_id=21 → first_frame_id=106 frame=(32×27 @ 137,82)
  - state_id=22 → first_frame_id=107 frame=(32×27 @ 137,82)
  - state_id=23 → first_frame_id=108 frame=(32×27 @ 137,82)
  - state_id=24 → first_frame_id=109 frame=(32×27 @ 137,82)
  - state_id=25 → first_frame_id=110 frame=(32×27 @ 137,82)
  - state_id=26 → first_frame_id=111 frame=(32×27 @ 137,82)
  - state_id=27 → first_frame_id=112 frame=(32×27 @ 137,82)
  - state_id=28 → first_frame_id=113 frame=(32×27 @ 137,82)
  - state_id=29 → first_frame_id=114 frame=(32×27 @ 137,82)
  - state_id=30 → first_frame_id=115 frame=(32×27 @ 137,82)
  - state_id=32 → first_frame_id=116 frame=(32×27 @ 137,82)
  - state_id=33 → first_frame_id=117 frame=(32×27 @ 137,82)
  - state_id=34 → first_frame_id=118 frame=(32×27 @ 137,82)
  - state_id=35 → first_frame_id=119 frame=(32×27 @ 137,82)
  - state_id=64 → first_frame_id=120 frame=(56×57 @ 122,70)
  - state_id=103 → first_frame_id=121 frame=(56×57 @ 122,70)
  - state_id=36 → first_frame_id=207 frame=(60×92 @ 125,34)
  - state_id=37 → first_frame_id=223 frame=(67×94 @ 125,32)
  - state_id=98 → first_frame_id=231 frame=(60×92 @ 125,34)
  - state_id=99 → first_frame_id=232 frame=(67×94 @ 125,32)
  - state_id=41 → first_frame_id=233 frame=(72×97 @ 125,29)
  - state_id=42 → first_frame_id=241 frame=(52×89 @ 125,37)
  - state_id=100 → first_frame_id=249
  - state_id=101 → first_frame_id=250
  - state_id=102 → first_frame_id=251
  - state_id=45 → first_frame_id=252
  - state_id=47 → first_frame_id=268
  - state_id=49 → first_frame_id=282
  - state_id=51 → first_frame_id=302
  - state_id=52 → first_frame_id=303
  - state_id=53 → first_frame_id=304
  - state_id=54 → first_frame_id=305
  - state_id=55 → first_frame_id=306
  - state_id=56 → first_frame_id=307
  - state_id=57 → first_frame_id=308
  - state_id=59 → first_frame_id=309
  - state_id=60 → first_frame_id=310
  - state_id=61 → first_frame_id=311
  - state_id=62 → first_frame_id=312
  - state_id=63 → first_frame_id=313
  - state_id=66 → first_frame_id=314
  - state_id=75 → first_frame_id=316
  - state_id=76 → first_frame_id=318
  - state_id=77 → first_frame_id=320
  - state_id=78 → first_frame_id=322
  - state_id=79 → first_frame_id=324
  - state_id=80 → first_frame_id=326
  - state_id=81 → first_frame_id=328
  - state_id=96 → first_frame_id=330
  - state_id=97 → first_frame_id=372
  - Commands: DRAW_BMP=505, END_ANM=1, END_FRAME=243, PLAY_SFX=21

### PUZDISP
- 8 frames, 7 states, 17 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(40×39 @ 0,0)
  - state_id=2 → first_frame_id=2 frame=(48×35 @ 0,0)
  - state_id=3 → first_frame_id=3 frame=(32×48 @ 0,0)
  - state_id=4 → first_frame_id=4 frame=(40×47 @ 0,0)
  - state_id=5 → first_frame_id=5 frame=(56×33 @ 0,0)
  - state_id=6 → first_frame_id=6 frame=(64×31 @ 0,0)
  - state_id=7 → first_frame_id=7 frame=(56×43 @ 0,0)
  - Commands: DRAW_BMP=7, DRAW_RECT=1, END_ANM=1, END_FRAME=8

### PUZLTYPE
- 162 frames, 8 states, 1124 commands
- Dimensions: 0×0
- Animated: True (40254 ticks in 521 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(104×101 @ 46,30)
  - state_id=2 → first_frame_id=85 frame=(88×67 @ 55,50)
  - state_id=4 → first_frame_id=136 frame=(96×57 @ 53,59)
  - state_id=7 → first_frame_id=193
  - state_id=9 → first_frame_id=255
  - state_id=11 → first_frame_id=317
  - state_id=13 → first_frame_id=508
  - state_id=16 → first_frame_id=519
  - Commands: DRAW_BMP=786, DRAW_LINE=25, DRAW_RECT=137, END_ANM=1, END_FRAME=162, PLAY_SFX=13

### SIERRA
- 43 frames, 1 states, 190 commands
- Dimensions: 0×0
- Animated: True (2074 ticks in 74 sub-frames)
  - state_id=1 → first_frame_id=1 frame=(317×80 @ 352,0)
  - Commands: DRAW_BMP=94, DRAW_RECT=43, END_ANM=1, END_FRAME=43, PLAY_SFX=9

### SIGN_IN
- 8 frames, 5 states, 21 commands
- Dimensions: 0×0
- Animated: False (0 ticks in 0 sub-frames)
  - state_id=5 → first_frame_id=0 frame=(9×11 @ 207,114)
  - state_id=2 → first_frame_id=1 frame=(66×30 @ 213,38)
  - state_id=3 → first_frame_id=2 frame=(32×28 @ 129,40)
  - state_id=4 → first_frame_id=4 frame=(32×27 @ 128,75)
  - state_id=6 → first_frame_id=6 frame=(24×30 @ 83,72)
  - Commands: DRAW_BMP=8, DRAW_RECT=1, END_ANM=1, END_FRAME=8, PLAY_SFX=3

### SOLVE
- 16 frames, 6 states, 38 commands
- Dimensions: 0×0
- Animated: True (161 ticks in 20 sub-frames)
  - state_id=4 → first_frame_id=0 frame=(639×399 @ 0,0)
  - state_id=1 → first_frame_id=1 frame=(32×28 @ 259,148)
  - state_id=2 → first_frame_id=4 frame=(32×27 @ 259,180)
  - state_id=43 → first_frame_id=7 frame=(32×23 @ 97,76)
  - state_id=44 → first_frame_id=15 frame=(59×35 @ 162,57)
  - state_id=45 → first_frame_id=19
  - Commands: DRAW_BMP=16, DRAW_RECT=1, END_ANM=1, END_FRAME=16, PLAY_SFX=4

### TITLE
- 204 frames, 5 states, 2264 commands
- Dimensions: 0×0
- Animated: True (37437 ticks in 359 sub-frames)
  - state_id=1 → first_frame_id=127 frame=(342×84 @ 266,0)
  - state_id=2 → first_frame_id=128 frame=(172×84 @ 436,0)
  - state_id=3 → first_frame_id=130 frame=(101×42 @ 436,0)
  - state_id=4 → first_frame_id=131 frame=(588×273 @ 20,20)
  - state_id=5 → first_frame_id=211
  - Commands: DRAW_BMP=1655, DRAW_LINE=23, DRAW_RECT=360, END_ANM=1, END_FRAME=204, PLAY_SFX=21
