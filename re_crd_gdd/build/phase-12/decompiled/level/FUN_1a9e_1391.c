// TIM2.EXE: FUN_1a9e_1391 @ file 0x020F71 Ghidra 0x1BD71
// Subsystem: level | Size: 547 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near FUN_1a9e_1391(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined4 local_6;
  
  uVar8 = _DAT_5b41_1d64;
  iVar6 = 1;
  pbVar4 = (byte *)(DAT_5b41_1d62 + param_1);
  local_6 = (byte *)CONCAT22(_DAT_5b41_1d64,pbVar4);
  iVar1 = *local_6 + 0x1001;
  *(undefined2 *)((int)DAT_5b41_1d5a + param_1 * 2) = 0x1000;
  *(undefined2 *)((int)_DAT_5b41_1d56 + param_1 * 2) = 0x1000;
  DAT_5b41_1d5e = 0;
  uVar2 = DAT_5b41_1d60;
  while( true ) {
    do {
      DAT_5b41_1d60 = uVar2;
      if (iVar6 < 0) {
        uVar7 = (undefined2)((ulong)DAT_5b41_1d5a >> 0x10);
        piVar5 = (int *)((int)DAT_5b41_1d5a + iVar1 * 2);
        if (*piVar5 == 0x1000) {
          *(int *)((int)DAT_5b41_1d5a + iVar1 * 2) = param_1;
          *(int *)((int)DAT_5b41_1d52 + param_1 * 2) = iVar1;
          return;
        }
        iVar1 = *piVar5;
      }
      else {
        uVar7 = (undefined2)((ulong)_DAT_5b41_1d56 >> 0x10);
        piVar5 = (int *)((int)_DAT_5b41_1d56 + iVar1 * 2);
        if (*piVar5 == 0x1000) {
          *(int *)((int)_DAT_5b41_1d56 + iVar1 * 2) = param_1;
          *(int *)((int)DAT_5b41_1d52 + param_1 * 2) = iVar1;
          return;
        }
        iVar1 = *piVar5;
      }
      iVar3 = 1;
      while ((iVar3 < 0x3c &&
             (iVar6 = (uint)pbVar4[iVar3] - (uint)*(byte *)(iVar1 + iVar3 + DAT_5b41_1d62),
             iVar6 == 0))) {
        iVar3 = iVar3 + 1;
      }
      uVar2 = DAT_5b41_1d60;
    } while (iVar3 < 3);
    if ((DAT_5b41_1d5e < iVar3) &&
       (DAT_5b41_1d60 = (param_1 - iVar1 & 0xfffU) - 1, DAT_5b41_1d5e = iVar3, 0x3b < iVar3)) break;
    uVar2 = DAT_5b41_1d60;
    if ((iVar3 == DAT_5b41_1d5e) && (uVar2 = (param_1 - iVar1 & 0xfffU) - 1, DAT_5b41_1d60 <= uVar2)
       ) {
      uVar2 = DAT_5b41_1d60;
    }
  }
  uVar8 = (undefined2)((ulong)DAT_5b41_1d52 >> 0x10);
  *(undefined2 *)((int)DAT_5b41_1d52 + param_1 * 2) =
       *(undefined2 *)((int)DAT_5b41_1d52 + iVar1 * 2);
  uVar8 = (undefined2)((ulong)DAT_5b41_1d5a >> 0x10);
  *(undefined2 *)((int)DAT_5b41_1d5a + param_1 * 2) =
       *(undefined2 *)((int)DAT_5b41_1d5a + iVar1 * 2);
  uVar8 = (undefined2)((ulong)_DAT_5b41_1d56 >> 0x10);
  *(undefined2 *)((int)_DAT_5b41_1d56 + param_1 * 2) =
       *(undefined2 *)((int)_DAT_5b41_1d56 + iVar1 * 2);
  *(int *)((int)DAT_5b41_1d52 + *(int *)((int)DAT_5b41_1d5a + iVar1 * 2) * 2) = param_1;
  uVar8 = (undefined2)((ulong)DAT_5b41_1d52 >> 0x10);
  *(int *)((int)DAT_5b41_1d52 + *(int *)((int)_DAT_5b41_1d56 + iVar1 * 2) * 2) = param_1;
  uVar7 = (undefined2)((ulong)_DAT_5b41_1d56 >> 0x10);
  uVar9 = (undefined2)((ulong)DAT_5b41_1d52 >> 0x10);
  if (*(int *)((int)_DAT_5b41_1d56 + *(int *)((int)DAT_5b41_1d52 + iVar1 * 2) * 2) == iVar1) {
    *(int *)((int)_DAT_5b41_1d56 + *(int *)((int)DAT_5b41_1d52 + iVar1 * 2) * 2) = param_1;
  }
  else {
    *(int *)((int)DAT_5b41_1d5a + *(int *)((int)DAT_5b41_1d52 + iVar1 * 2) * 2) = param_1;
  }
  *(undefined2 *)((int)DAT_5b41_1d52 + iVar1 * 2) = 0x1000;
  return;
}

