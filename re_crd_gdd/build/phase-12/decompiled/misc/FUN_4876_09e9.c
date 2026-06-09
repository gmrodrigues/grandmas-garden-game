// TIM2.EXE: FUN_4876_09e9 @ file 0x04E349 Ghidra 0x49149
// Subsystem: misc | Size: 85 bytes


undefined2 __cdecl16far FUN_4876_09e9(undefined2 param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int in_DX;
  
  iVar1 = FUN_460e_0f42(param_1);
  if ((iVar1 == 0 && in_DX == 0) || (*(int *)(iVar1 + 0xe) != 3)) {
    uVar2 = 0;
  }
  else {
    *(int *)(iVar1 + 0x34) = param_2;
    if (param_2 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x2c) + -1;
    }
    *(int *)(iVar1 + 0x2e) = iVar3;
    *(undefined2 *)(iVar1 + 0x26) = 2;
    uVar2 = 1;
  }
  return uVar2;
}

