// TIM2.EXE: FUN_4876_16a2 @ file 0x04F002 Ghidra 0x49E02
// Subsystem: misc | Size: 63 bytes


undefined2 __cdecl16far FUN_4876_16a2(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  
  iVar1 = FUN_460e_0f42(param_1);
  if ((iVar1 == 0 && in_DX == 0) || (*(int *)(iVar1 + 0xe) != 4)) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 0x50) = param_2;
    *(undefined2 *)(iVar1 + 0x36) = param_2;
    uVar2 = 1;
  }
  return uVar2;
}

