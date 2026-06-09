// TIM2.EXE: FUN_4bdc_35e5 @ file 0x0545A5 Ghidra 0x4F3A5
// Subsystem: physics | Size: 47 bytes


int __cdecl16far FUN_4bdc_35e5(undefined2 param_1)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_4bdc_270f(param_1);
  if (iVar1 != 0 || in_DX != 0) {
    return (int)*(char *)(iVar1 + 0x158);
  }
  return -1;
}

