// TIM2.EXE: FUN_4876_0720 @ file 0x04E080 Ghidra 0x48E80
// Subsystem: misc | Size: 93 bytes


undefined2 __cdecl16far
FUN_4876_0720(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_460e_0f42(param_1);
  if ((iVar1 != 0 || in_DX != 0) && (*(int *)(iVar1 + 0xe) == 0)) {
    *(undefined2 *)(iVar1 + 0x3a) = param_3;
    *(undefined2 *)(iVar1 + 0x38) = param_2;
    *(undefined2 *)(iVar1 + 0x36) = param_5;
    *(undefined2 *)(iVar1 + 0x34) = param_4;
    return 1;
  }
  return 0;
}

