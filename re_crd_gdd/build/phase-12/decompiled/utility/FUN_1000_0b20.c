// TIM2.EXE: FUN_1000_0b20 @ file 0x015D20 Ghidra 0x10B20
// Subsystem: utility | Size: 381 bytes


undefined2 * __cdecl16far FUN_1000_0b20(char *param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_12 [14];
  int local_4;
  
  if (DAT_5b41_045f != '\0') {
    FUN_1000_09ba(0);
  }
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    FUN_1000_02a3();
    DAT_5b41_02f6 = 0;
    if (DAT_5b41_0469 == 0) {
      puVar1 = (undefined2 *)FUN_1000_418e(param_1,param_2);
      return puVar1;
    }
    DAT_5b41_045a = 0;
    DAT_5b41_0458 = 0;
    iVar4 = 10;
    for (puVar1 = (undefined2 *)&DAT_5b41_02fc; (iVar4 != 0 && (puVar1[7] != 0));
        puVar1 = puVar1 + 9) {
      iVar4 = iVar4 + -1;
    }
    if (iVar4 != 0) {
      FUN_1000_05f4(param_1);
      DAT_5b41_045d = 1;
      DAT_5b41_045e = 0;
      local_4 = FUN_1000_418e(param_1,param_2);
      DAT_5b41_045d = 0;
      if (local_4 != 0) {
        *puVar1 = 0;
        puVar1[6] = 0;
        puVar1[5] = 0;
        puVar1[4] = 0;
        puVar1[3] = 0;
        puVar1[2] = 0;
        puVar1[1] = 0;
        puVar1[7] = 1;
        puVar1[8] = local_4;
        DAT_5b41_0460 = DAT_5b41_0460 + '\x01';
        return puVar1;
      }
      iVar4 = FUN_1000_07db(puVar1);
      if (iVar4 != 0) {
        FUN_1000_09ba(*puVar1);
        iVar4 = puVar1[2] + puVar1[6] + (uint)CARRY2(puVar1[1],puVar1[5]);
        FUN_1000_0a7c(puVar1[1] + puVar1[5],iVar4);
        local_4 = *(undefined2 *)(DAT_5b41_0465 * 0x1c + 0x6310);
        FUN_1000_4306(local_12,0xd,1,local_4);
        FUN_1000_4306(puVar1 + 3,4,1,local_4);
        uVar2 = FUN_1000_4431(local_4);
        puVar1[2] = iVar4;
        puVar1[1] = uVar2;
        iVar3 = DAT_5b41_0465 * 0x1c;
        *(int *)(iVar3 + 0x6314) = iVar4;
        *(undefined2 *)(iVar3 + 0x6312) = uVar2;
        iVar4 = FUN_1000_5494(local_12,param_1);
        if (iVar4 == 0) {
          puVar1[6] = 0;
          puVar1[5] = 0;
          puVar1[8] = 0;
          puVar1[7] = 1;
          DAT_5b41_0460 = DAT_5b41_0460 + '\x01';
          return puVar1;
        }
      }
    }
  }
  return (undefined2 *)0x0;
}

