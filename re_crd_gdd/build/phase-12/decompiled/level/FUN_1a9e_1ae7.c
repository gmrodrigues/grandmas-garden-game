// TIM2.EXE: FUN_1a9e_1ae7 @ file 0x0216C7 Ghidra 0x1C4C7
// Subsystem: level | Size: 284 bytes


void __cdecl16near FUN_1a9e_1ae7(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  int iVar7;
  undefined2 uVar8;
  
  if (*(int *)((int)DAT_5b41_1d4a + 0x4e4) == -0x8000) {
    FUN_1a9e_196a();
  }
  param_1 = *(int *)(param_1 * 2 + (int)DAT_5b41_1d46 + 0x4e6);
  do {
    uVar8 = (undefined2)((ulong)DAT_5b41_1d4a >> 0x10);
    puVar5 = (uint *)((int)DAT_5b41_1d4a + param_1 * 2);
    puVar1 = puVar5;
    *puVar1 = *puVar1 + 1;
    uVar2 = *puVar5;
    iVar3 = param_1 + 1;
    if (*(uint *)((int)DAT_5b41_1d4a + (param_1 + 1) * 2) < uVar2) {
      do {
        iVar7 = iVar3;
        uVar8 = (undefined2)((ulong)DAT_5b41_1d4a >> 0x10);
        iVar3 = iVar7 + 1;
      } while (*(uint *)((int)DAT_5b41_1d4a + (iVar7 + 1) * 2) < uVar2);
      *(undefined2 *)((int)DAT_5b41_1d4a + param_1 * 2) =
           *(undefined2 *)((int)DAT_5b41_1d4a + iVar7 * 2);
      *(uint *)((int)DAT_5b41_1d4a + iVar7 * 2) = uVar2;
      iVar3 = *(int *)((int)DAT_5b41_1d42 + param_1 * 2);
      uVar8 = (undefined2)((ulong)DAT_5b41_1d46 >> 0x10);
      piVar6 = (int *)((int)DAT_5b41_1d46 + iVar3 * 2);
      *piVar6 = iVar7;
      if (iVar3 < 0x273) {
        piVar6[1] = iVar7;
      }
      uVar8 = (undefined2)((ulong)DAT_5b41_1d42 >> 0x10);
      piVar6 = (int *)((int)DAT_5b41_1d42 + iVar7 * 2);
      iVar4 = *piVar6;
      *piVar6 = iVar3;
      uVar8 = (undefined2)((ulong)DAT_5b41_1d46 >> 0x10);
      piVar6 = (int *)((int)DAT_5b41_1d46 + iVar4 * 2);
      *piVar6 = param_1;
      if (iVar4 < 0x273) {
        piVar6[1] = param_1;
      }
      *(int *)((int)DAT_5b41_1d42 + param_1 * 2) = iVar4;
      param_1 = iVar7;
    }
    param_1 = *(int *)((int)DAT_5b41_1d46 + param_1 * 2);
  } while (param_1 != 0);
  return;
}

