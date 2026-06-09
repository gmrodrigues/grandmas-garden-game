// TIM2.EXE: FUN_1000_570b @ file 0x01A90B Ghidra 0x1570B
// Subsystem: utility | Size: 236 bytes


undefined2 FUN_1000_570b(int param_1,uint param_2,uint param_3,byte param_4)

{
  int iVar1;
  uint uVar2;
  uint local_4;
  
  if (param_2 == 0) {
    local_4 = param_3;
    if ((0x3a < param_3) && ((param_1 + 0x46U & 3) == 0)) {
      local_4 = param_3 - 1;
    }
    param_2 = 0;
    while (*(uint *)(param_2 * 2 + 0x5e0a) <= local_4) {
      param_2 = param_2 + 1;
    }
  }
  else {
    param_3 = param_3 + *(int *)((param_2 - 1) * 2 + 0x5e0a);
    if ((3 < param_2) && ((param_1 + 0x46U & 3) == 0)) {
      param_3 = param_3 + 1;
    }
  }
  if (3 < param_2) {
    if (param_2 != 4) {
      if (10 < param_2) {
        return 0;
      }
      if (param_2 != 10) {
        return 1;
      }
    }
    if ((param_1 < 0x11) || (param_2 != 4)) {
      iVar1 = *(int *)(param_2 * 2 + 0x5e0a);
    }
    else {
      iVar1 = iRam0005b2d0 + 7;
    }
    if ((param_1 + 0x7b2U & 3) != 0) {
      iVar1 = iVar1 + -1;
    }
    uVar2 = iVar1 - (param_1 * 0x16d + (param_1 + 1 >> 2) + iVar1 + 4U) % 7;
    if (param_2 == 4) {
      if ((uVar2 < param_3) || ((param_3 == uVar2 && (1 < param_4)))) {
        return 1;
      }
    }
    else {
      if (param_3 < uVar2) {
        return 1;
      }
      if ((param_3 == uVar2) && (param_4 < 2)) {
        return 1;
      }
    }
  }
  return 0;
}

