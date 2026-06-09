// TIM2.EXE: FUN_4876_1643 @ file 0x04EFA3 Ghidra 0x49DA3
// Subsystem: misc | Size: 95 bytes


undefined2 __cdecl16far
FUN_4876_1643(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_460e_0f42(param_1);
  if ((iVar1 != 0 || in_DX != 0) && (*(int *)(iVar1 + 0xe) == 4)) {
    *(undefined2 *)(iVar1 + 0x46) = param_3;
    *(undefined2 *)(iVar1 + 0x44) = param_2;
    *(undefined2 *)(iVar1 + 0x48) = param_4;
    *(undefined2 *)(iVar1 + 0x26) = 2;
    return 1;
  }
  return 0;
}

