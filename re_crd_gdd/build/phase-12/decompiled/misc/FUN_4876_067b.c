// TIM2.EXE: FUN_4876_067b @ file 0x04DFDB Ghidra 0x48DDB
// Subsystem: misc | Size: 55 bytes


bool __cdecl16far FUN_4876_067b(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_460e_0f42(param_1);
  if (iVar1 != 0 || in_DX != 0) {
    *(undefined2 *)(iVar1 + 0x2a) = param_2;
  }
  return iVar1 != 0 || in_DX != 0;
}

