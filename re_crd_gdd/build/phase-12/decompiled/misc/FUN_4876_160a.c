// TIM2.EXE: FUN_4876_160a @ file 0x04EF6A Ghidra 0x49D6A
// Subsystem: misc | Size: 57 bytes


undefined2 __cdecl16far FUN_4876_160a(undefined2 param_1)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_460e_0f42(param_1);
  if ((iVar1 != 0 || in_DX != 0) && (*(int *)(iVar1 + 0xe) == 4)) {
    return *(undefined2 *)(iVar1 + 0x44);
  }
  return 0;
}

