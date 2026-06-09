// TIM2.EXE: FUN_3f2b_06d5 @ file 0x044B85 Ghidra 0x3F985
// Subsystem: sound | Size: 67 bytes


undefined2 __cdecl16far FUN_3f2b_06d5(undefined2 param_1)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_3f2b_0b8e(param_1,0);
  if ((iVar1 != 0 || in_DX != 0) && (*(int *)(iVar1 + 2) != 0)) {
    if (*(int *)(iVar1 + 0xc) != 0) {
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -1;
    }
    return *(undefined2 *)(iVar1 + 0xc);
  }
  return 0;
}

