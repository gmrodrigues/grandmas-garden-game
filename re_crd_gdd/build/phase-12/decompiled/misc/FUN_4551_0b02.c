// TIM2.EXE: FUN_4551_0b02 @ file 0x04B212 Ghidra 0x46012
// Subsystem: misc | Size: 212 bytes


undefined2 __cdecl16far FUN_4551_0b02(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int in_DX;
  uint uVar4;
  undefined4 local_a;
  
  iVar2 = FUN_4551_06cf(param_1);
  if (iVar2 == 0 && in_DX == 0) {
    uVar3 = 0;
  }
  else {
    for (uVar4 = 0; uVar4 < 0x40; uVar4 = uVar4 + 1) {
      *(undefined2 *)(uVar4 * 2 + param_2) = 0;
    }
    if (*(int *)(iVar2 + 4) != 0 || *(int *)(iVar2 + 6) != 0) {
      uVar3 = (undefined2)((ulong)*(undefined4 *)(iVar2 + 4) >> 0x10);
      iVar2 = (int)*(undefined4 *)(iVar2 + 4);
      if (*(int *)(iVar2 + 8) != 0 || *(int *)(iVar2 + 10) != 0) {
        local_a = (int *)CONCAT22(*(undefined2 *)(iVar2 + 10),(int *)*(undefined2 *)(iVar2 + 8));
        while (iVar2 = *local_a, iVar2 != 1) {
          if ((iVar2 == 2) && (iVar1 = ((int *)local_a)[1], iVar1 != 0)) {
            uVar4 = 0;
            while (((uVar4 < 0x40 && (*(int *)(uVar4 * 2 + param_2) != 0)) &&
                   (*(int *)(uVar4 * 2 + param_2) != iVar1))) {
              uVar4 = uVar4 + 1;
            }
            if (*(int *)(uVar4 * 2 + param_2) == 0) {
              *(int *)(uVar4 * 2 + param_2) = iVar1;
            }
          }
          local_a = (int *)CONCAT22(local_a._2_2_,(int *)local_a + *(int *)(iVar2 * 2));
        }
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

