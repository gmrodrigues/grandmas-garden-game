// TIM2.EXE: FUN_460e_06a6 @ file 0x04B986 Ghidra 0x46786
// Subsystem: misc | Size: 52 bytes


int __cdecl16far FUN_460e_06a6(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_460e_0aa3(param_1,param_2,0,0);
  if (iVar1 == 0 && in_DX == 0) {
    return 0;
  }
  return iVar1 + 7;
}

