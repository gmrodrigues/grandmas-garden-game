// TIM2.EXE: FUN_2321_0c23 @ file 0x029033 Ghidra 0x23E33
// Subsystem: misc | Size: 206 bytes


void __cdecl16far FUN_2321_0c23(undefined2 *param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((undefined2 *)param_1 == (undefined2 *)0x0 && param_1._2_2_ == 0) {
    return;
  }
  if ((((undefined2 *)param_1)[0x4c] != 0) &&
     (*(int *)(*(int *)(((undefined2 *)param_1)[4] * 2 + 0x302) + 0x46) == 0)) {
    FUN_1000_130c(((undefined2 *)param_1)[0x4c]);
  }
  if ((((undefined2 *)param_1)[0x2c] != 0) && ((*(byte *)((undefined2 *)param_1 + 6) & 1) == 0)) {
    FUN_1000_130c(((undefined2 *)param_1)[0x2c]);
  }
  iVar1 = ((undefined2 *)param_1)[4];
  if (iVar1 == 0x5b) {
LAB_2321_0cc2:
    uVar2 = ((undefined2 *)param_1)[0x2f];
  }
  else {
    if (0x5b < iVar1) {
      if (((iVar1 != 0x5c) && (iVar1 != 0x5d)) && (iVar1 != 0x5f)) goto LAB_2321_0cd1;
      goto LAB_2321_0cc2;
    }
    if (iVar1 != 0x4c) {
      if (0x4c < iVar1) {
        if (iVar1 != 0x57) goto LAB_2321_0cd1;
        goto LAB_2321_0cc2;
      }
      if ((iVar1 != 7) && (iVar1 != 10)) goto LAB_2321_0cd1;
    }
    if (((undefined2 *)param_1)[0x3b] == 0) goto LAB_2321_0cd1;
    uVar2 = ((undefined2 *)param_1)[0x3b];
  }
  FUN_1000_130c(uVar2);
LAB_2321_0cd1:
  ((undefined2 *)param_1)[1] = DAT_5b41_04ff;
  *param_1 = DAT_5b41_04fd;
  DAT_5b41_04ff = param_1._2_2_;
  DAT_5b41_04fd = (undefined2 *)param_1;
  return;
}

