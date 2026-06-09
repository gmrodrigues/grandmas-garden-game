// TIM2.EXE: FUN_1a9e_15b9 @ file 0x021199 Ghidra 0x1BF99
// Subsystem: level | Size: 450 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near FUN_1a9e_15b9(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar4 = (undefined2)((ulong)DAT_5b41_1d52 >> 0x10);
  if (*(int *)((int)DAT_5b41_1d52 + param_1 * 2) != 0x1000) {
    uVar5 = (undefined2)((ulong)_DAT_5b41_1d56 >> 0x10);
    iVar2 = (int)_DAT_5b41_1d56;
    iVar3 = (int)DAT_5b41_1d5a;
    uVar6 = (undefined2)((ulong)DAT_5b41_1d5a >> 0x10);
    if (*(int *)(iVar2 + param_1 * 2) == 0x1000) {
      iVar1 = *(int *)(iVar3 + param_1 * 2);
    }
    else if (*(int *)(iVar3 + param_1 * 2) == 0x1000) {
      iVar1 = *(int *)(iVar2 + param_1 * 2);
    }
    else {
      iVar1 = *(int *)(iVar3 + param_1 * 2);
      if (*(int *)(iVar2 + iVar1 * 2) != 0x1000) {
        do {
          iVar1 = *(int *)(iVar2 + iVar1 * 2);
        } while (*(int *)(iVar2 + iVar1 * 2) != 0x1000);
        *(undefined2 *)(iVar2 + *(int *)((int)DAT_5b41_1d52 + iVar1 * 2) * 2) =
             *(undefined2 *)(iVar3 + iVar1 * 2);
        uVar4 = (undefined2)((ulong)DAT_5b41_1d52 >> 0x10);
        *(undefined2 *)((int)DAT_5b41_1d52 + *(int *)((int)DAT_5b41_1d5a + iVar1 * 2) * 2) =
             *(undefined2 *)((int)DAT_5b41_1d52 + iVar1 * 2);
        uVar4 = (undefined2)((ulong)DAT_5b41_1d5a >> 0x10);
        *(undefined2 *)((int)DAT_5b41_1d5a + iVar1 * 2) =
             *(undefined2 *)((int)DAT_5b41_1d5a + param_1 * 2);
        *(int *)((int)DAT_5b41_1d52 + *(int *)((int)DAT_5b41_1d5a + param_1 * 2) * 2) = iVar1;
      }
      uVar4 = (undefined2)((ulong)_DAT_5b41_1d56 >> 0x10);
      *(undefined2 *)((int)_DAT_5b41_1d56 + iVar1 * 2) =
           *(undefined2 *)((int)_DAT_5b41_1d56 + param_1 * 2);
      *(int *)((int)DAT_5b41_1d52 + *(int *)(DAT_5b41_1d56 + param_1 * 2) * 2) = iVar1;
    }
    uVar4 = (undefined2)((ulong)DAT_5b41_1d52 >> 0x10);
    *(undefined2 *)((int)DAT_5b41_1d52 + iVar1 * 2) =
         *(undefined2 *)((int)DAT_5b41_1d52 + param_1 * 2);
    uVar5 = (undefined2)((ulong)_DAT_5b41_1d56 >> 0x10);
    uVar6 = (undefined2)((ulong)DAT_5b41_1d52 >> 0x10);
    if (*(int *)((int)_DAT_5b41_1d56 + *(int *)((int)DAT_5b41_1d52 + param_1 * 2) * 2) == param_1) {
      *(int *)((int)_DAT_5b41_1d56 + *(int *)((int)DAT_5b41_1d52 + param_1 * 2) * 2) = iVar1;
    }
    else {
      *(int *)((int)DAT_5b41_1d5a + *(int *)((int)DAT_5b41_1d52 + param_1 * 2) * 2) = iVar1;
    }
    *(undefined2 *)((int)DAT_5b41_1d52 + param_1 * 2) = 0x1000;
  }
  return;
}

