// TIM2.EXE: FUN_31f7_b757 @ file 0x0428C7 Ghidra 0x3D6C7
// Subsystem: sound | Size: 151 bytes


void __cdecl16far FUN_31f7_b757(void)

{
  int *piVar1;
  int in_BX;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_ES;
  undefined2 uVar4;
  undefined2 unaff_SS;
  
  if (*(int *)(in_BX + 0x16) == 0) {
    uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
    iVar3 = (int)*(undefined4 *)(unaff_BP + 6);
    if (*(int *)(iVar3 + 0x10) == 0) goto LAB_31f7_b7e3;
    iVar3 = *(int *)(iVar3 + 0x10);
    if ((iVar3 < DAT_5b41_1ac4) || (DAT_5b41_1ac6 <= iVar3)) {
      *(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0x10) = DAT_5b41_1ac4;
    }
    else {
      piVar1 = (int *)((int)*(undefined4 *)(unaff_BP + 6) + 0x10);
      *piVar1 = *piVar1 + 1;
    }
    uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
    iVar2 = (int)*(undefined4 *)(unaff_BP + 6);
    iVar3 = DAT_5b41_1ac4;
    if (*(int *)(iVar2 + 0x10) != DAT_5b41_1ac6) goto LAB_31f7_b7e3;
  }
  else {
    if ((*(int *)(in_BX + 0x10) < DAT_5b41_1ac4) || (DAT_5b41_1ac6 <= *(int *)(in_BX + 0x10))) {
      piVar1 = (int *)((int)*(undefined4 *)(unaff_BP + 6) + 0x10);
      *piVar1 = *piVar1 + 1;
    }
    else {
      *(int *)(in_BX + 0x10) = DAT_5b41_1ac6;
    }
    uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
    iVar2 = (int)*(undefined4 *)(unaff_BP + 6);
    iVar3 = DAT_5b41_1ac2;
    if (*(int *)(iVar2 + 0x10) != DAT_5b41_1ac4) {
      uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
      iVar2 = (int)*(undefined4 *)(unaff_BP + 6);
      iVar3 = DAT_5b41_1ac6;
      if (*(int *)(iVar2 + 0x10) != DAT_5b41_1ac8) goto LAB_31f7_b7e3;
    }
  }
  *(int *)(iVar2 + 0x10) = iVar3;
LAB_31f7_b7e3:
  *(undefined2 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x16) = 0;
  return;
}

