// TIM2.EXE: FUN_1000_3e17 @ file 0x019017 Ghidra 0x13E17
// Subsystem: utility | Size: 149 bytes


undefined2 __cdecl16far FUN_1000_3e17(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_1000_3f88();
  }
  else {
    if ((int *)param_1[7] != param_1) {
      return 0xffff;
    }
    if (*param_1 < 0) {
      iVar1 = param_1[3] + *param_1 + 1;
      *param_1 = *param_1 - iVar1;
      iVar2 = param_1[4];
      param_1[5] = iVar2;
      iVar2 = FUN_1000_57f7((int)(char)param_1[2],iVar2,iVar1);
      if ((iVar2 != iVar1) && ((*(byte *)((int)param_1 + 3) & 2) == 0)) {
        param_1[1] = param_1[1] | 0x10;
        return 0xffff;
      }
    }
    else if ((((*(byte *)(param_1 + 1) & 8) != 0) || (param_1[5] == (int)param_1 + 5)) &&
            (*param_1 = 0, param_1[5] == (int)param_1 + 5)) {
      param_1[5] = param_1[4];
    }
  }
  return 0;
}

