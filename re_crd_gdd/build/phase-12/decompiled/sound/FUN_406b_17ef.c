// TIM2.EXE: FUN_406b_17ef @ file 0x04709F Ghidra 0x41E9F
// Subsystem: sound | Size: 367 bytes


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl16far
FUN_406b_17ef(uint *param_1,undefined2 param_2,byte *param_3,undefined2 param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  param_5 = param_5 >> 3;
  uVar5 = param_5;
  do {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    *param_3 = ((((((((uVar1 & 1) != 0) << 1 | (uVar1 >> 8 & 1) != 0) << 1 | (uVar2 & 1) != 0) << 1
                  | (uVar2 >> 8 & 1) != 0) << 1 | (uVar3 & 1) != 0) << 1 | (uVar3 >> 8 & 1) != 0) <<
                1 | (uVar4 & 1) != 0) << 1 | (uVar4 >> 8 & 1) != 0;
    pbVar6 = param_3 + param_5;
    *pbVar6 = ((((((((uVar1 >> 1 & 1) != 0) << 1 | (uVar1 >> 9 & 1) != 0) << 1 |
                  (uVar2 >> 1 & 1) != 0) << 1 | (uVar2 >> 9 & 1) != 0) << 1 | (uVar3 >> 1 & 1) != 0)
                << 1 | (uVar3 >> 9 & 1) != 0) << 1 | (uVar4 >> 1 & 1) != 0) << 1 |
              (uVar4 >> 9 & 1) != 0;
    pbVar6 = pbVar6 + param_5;
    *pbVar6 = ((((((((uVar1 >> 2 & 1) != 0) << 1 | (uVar1 >> 10 & 1) != 0) << 1 |
                  (uVar2 >> 2 & 1) != 0) << 1 | (uVar2 >> 10 & 1) != 0) << 1 | (uVar3 >> 2 & 1) != 0
                ) << 1 | (uVar3 >> 10 & 1) != 0) << 1 | (uVar4 >> 2 & 1) != 0) << 1 |
              (uVar4 >> 10 & 1) != 0;
    pbVar6 = pbVar6 + param_5;
    *pbVar6 = ((((((((uVar1 >> 3 & 1) != 0) << 1 | (uVar1 >> 0xb & 1) != 0) << 1 |
                  (uVar2 >> 3 & 1) != 0) << 1 | (uVar2 >> 0xb & 1) != 0) << 1 |
                (uVar3 >> 3 & 1) != 0) << 1 | (uVar3 >> 0xb & 1) != 0) << 1 | (uVar4 >> 3 & 1) != 0)
              << 1 | (uVar4 >> 0xb & 1) != 0;
    pbVar6 = pbVar6 + param_5;
    *pbVar6 = ((((((((uVar1 >> 4 & 1) != 0) << 1 | (uVar1 >> 0xc & 1) != 0) << 1 |
                  (uVar2 >> 4 & 1) != 0) << 1 | (uVar2 >> 0xc & 1) != 0) << 1 |
                (uVar3 >> 4 & 1) != 0) << 1 | (uVar3 >> 0xc & 1) != 0) << 1 | (uVar4 >> 4 & 1) != 0)
              << 1 | (uVar4 >> 0xc & 1) != 0;
    pbVar6 = pbVar6 + param_5;
    *pbVar6 = ((((((((uVar1 >> 5 & 1) != 0) << 1 | (uVar1 >> 0xd & 1) != 0) << 1 |
                  (uVar2 >> 5 & 1) != 0) << 1 | (uVar2 >> 0xd & 1) != 0) << 1 |
                (uVar3 >> 5 & 1) != 0) << 1 | (uVar3 >> 0xd & 1) != 0) << 1 | (uVar4 >> 5 & 1) != 0)
              << 1 | (uVar4 >> 0xd & 1) != 0;
    pbVar6[param_5] =
         ((((((((uVar1 >> 6 & 1) != 0) << 1 | (uVar1 >> 0xe & 1) != 0) << 1 | (uVar2 >> 6 & 1) != 0)
             << 1 | (uVar2 >> 0xe & 1) != 0) << 1 | (uVar3 >> 6 & 1) != 0) << 1 |
          (uVar3 >> 0xe & 1) != 0) << 1 | (uVar4 >> 6 & 1) != 0) << 1 | (uVar4 >> 0xe & 1) != 0;
    (pbVar6 + param_5)[param_5] =
         ((((((((uVar1 >> 7 & 1) != 0) << 1 | (int)uVar1 < 0) << 1 | (uVar2 >> 7 & 1) != 0) << 1 |
            (int)uVar2 < 0) << 1 | (uVar3 >> 7 & 1) != 0) << 1 | (int)uVar3 < 0) << 1 |
         (uVar4 >> 7 & 1) != 0) << 1 | (int)uVar4 < 0;
    param_3 = param_3 + 1;
    param_1 = param_1 + 4;
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  return;
}

