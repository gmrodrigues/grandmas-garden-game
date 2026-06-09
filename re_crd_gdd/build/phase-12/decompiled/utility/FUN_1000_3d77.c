// TIM2.EXE: FUN_1000_3d77 @ file 0x018F77 Ghidra 0x13D77
// Subsystem: utility | Size: 160 bytes


undefined2 __cdecl16far FUN_1000_3d77(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 local_4;
  
  local_4 = 0xffff;
  if ((param_1 != (int *)0x0) && ((int *)param_1[7] == param_1)) {
    if (param_1[3] != 0) {
      if ((*param_1 < 0) && (iVar1 = FUN_1000_3e17(param_1), iVar1 != 0)) {
        return 0xffff;
      }
      if ((*(byte *)(param_1 + 1) & 4) != 0) {
        FUN_1000_3157(param_1[4]);
      }
    }
    if (-1 < (char)param_1[2]) {
      local_4 = FUN_1000_3c9b((int)(char)param_1[2]);
    }
    param_1[1] = 0;
    param_1[3] = 0;
    *param_1 = 0;
    *(undefined1 *)(param_1 + 2) = 0xff;
    if (param_1[6] != 0) {
      uVar2 = FUN_1000_1c97(param_1[6],0,0);
      FUN_1000_222a(uVar2);
      param_1[6] = 0;
    }
  }
  return local_4;
}

