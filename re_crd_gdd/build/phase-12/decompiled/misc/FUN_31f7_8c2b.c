// TIM2.EXE: FUN_31f7_8c2b @ file 0x03FD9B Ghidra 0x3AB9B
// Subsystem: misc | Size: 138 bytes


undefined2 __cdecl16far
FUN_31f7_8c2b(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
             uint param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_3 >> 0x10);
  iVar4 = (int)param_3;
  if (param_5 == 1) {
    piVar1 = (int *)(*(int *)(iVar4 + 0x76) + 0x18);
    *piVar1 = *piVar1 + 1;
    return 0;
  }
  uVar3 = param_5 & 0x18;
  if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
    if ((uVar3 == 8) || ((uVar3 == 0x10 && (*(int *)(iVar4 + 0x16) != 0)))) {
      return 1;
    }
    if ((param_5 & 0x8018) != 0x10) {
      return 0;
    }
    iVar2 = *(int *)(iVar4 + 0x16);
  }
  else {
    if (uVar3 == 0x10) {
      return 1;
    }
    if ((uVar3 == 8) && (*(int *)(iVar4 + 0x16) != 0)) {
      return 1;
    }
    if ((param_5 & 0x8018) != 8) {
      return 0;
    }
    iVar2 = *(int *)(iVar4 + 0x16);
  }
  if (iVar2 == 0) {
    *(undefined2 *)(iVar4 + 0x16) = 1;
  }
  return 0;
}

