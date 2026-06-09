// TIM2.EXE: FUN_460e_071e @ file 0x04B9FE Ghidra 0x467FE
// Subsystem: misc | Size: 49 bytes


undefined2 __cdecl16far FUN_460e_071e(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_460e_0aa3(param_1,0,param_2,param_3);
  if (iVar1 == 0 && in_DX == 0) {
    return 0;
  }
  return *(undefined2 *)(iVar1 + 4);
}

