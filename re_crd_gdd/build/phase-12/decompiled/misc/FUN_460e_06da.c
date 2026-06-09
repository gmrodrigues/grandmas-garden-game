// TIM2.EXE: FUN_460e_06da @ file 0x04B9BA Ghidra 0x467BA
// Subsystem: misc | Size: 68 bytes


undefined2 __cdecl16far FUN_460e_06da(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_460e_0aa3(param_1,param_2,0,0);
  if (iVar1 == 0 && in_DX == 0) {
    return 0;
  }
  FUN_4340_0a6e(0x7afa,0x554c,iVar1 + 7,in_DX,0x50);
  return 0x7afa;
}

