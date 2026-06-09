// TIM2.EXE: FUN_31f7_26af @ file 0x03981F Ghidra 0x3461F
// Subsystem: misc | Size: 131 bytes


undefined2 __cdecl16far FUN_31f7_26af(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = *(int *)(iVar3 + 8);
  if (iVar2 == 0x37) {
    FUN_31f7_706a(iVar3,uVar4);
  }
  else if (iVar2 < 0x38) {
    if (iVar2 == 4) {
      *(undefined2 *)(iVar3 + 0x16) = 1;
    }
    else if (iVar2 == 0x13) {
      FUN_31f7_25cf(iVar3,uVar4);
    }
    else if (iVar2 == 0x15) {
      piVar1 = (int *)(*(int *)(iVar3 + 0x9a) + 0x3a);
      *piVar1 = *piVar1 + -1;
    }
  }
  else if ((iVar2 == 0x4f) || (iVar2 == 0x6d)) {
    *(undefined2 *)(iVar3 + 0x16) = 2;
  }
  return 1;
}

