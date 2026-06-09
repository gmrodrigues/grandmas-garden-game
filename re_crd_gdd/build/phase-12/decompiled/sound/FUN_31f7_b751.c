// TIM2.EXE: FUN_31f7_b751 @ file 0x0428C1 Ghidra 0x3D6C1
// Subsystem: sound | Size: 6 bytes


void FUN_31f7_b751(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_2 >> 0x10);
  iVar2 = (int)param_2;
  if (*(int *)(iVar2 + 0x16) == 0) {
    if (*(int *)(iVar2 + 0x10) == 0) goto LAB_31f7_b7e3;
    if ((*(int *)(iVar2 + 0x10) < DAT_5b41_1ac4) || (DAT_5b41_1ac6 <= *(int *)(iVar2 + 0x10))) {
      *(int *)(iVar2 + 0x10) = DAT_5b41_1ac4;
    }
    else {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    }
    iVar1 = DAT_5b41_1ac4;
    if (*(int *)(iVar2 + 0x10) != DAT_5b41_1ac6) goto LAB_31f7_b7e3;
  }
  else {
    if ((*(int *)(iVar2 + 0x10) < DAT_5b41_1ac4) || (DAT_5b41_1ac6 <= *(int *)(iVar2 + 0x10))) {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    }
    else {
      *(int *)(iVar2 + 0x10) = DAT_5b41_1ac6;
    }
    iVar1 = DAT_5b41_1ac2;
    if ((*(int *)(iVar2 + 0x10) != DAT_5b41_1ac4) &&
       (iVar1 = DAT_5b41_1ac6, *(int *)(iVar2 + 0x10) != DAT_5b41_1ac8)) goto LAB_31f7_b7e3;
  }
  *(int *)(iVar2 + 0x10) = iVar1;
LAB_31f7_b7e3:
  *(undefined2 *)(iVar2 + 0x16) = 0;
  return;
}

