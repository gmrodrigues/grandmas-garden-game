// TIM2.EXE: FUN_3f2b_069c @ file 0x044B4C Ghidra 0x3F94C
// Subsystem: sound | Size: 57 bytes


undefined2 __cdecl16far FUN_3f2b_069c(undefined2 param_1)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_3f2b_0b8e(param_1,0);
  if ((iVar1 != 0 || in_DX != 0) && (*(int *)(iVar1 + 2) != 0)) {
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
    return *(undefined2 *)(iVar1 + 0xc);
  }
  return 0;
}

