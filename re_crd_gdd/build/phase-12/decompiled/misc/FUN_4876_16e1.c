// TIM2.EXE: FUN_4876_16e1 @ file 0x04F041 Ghidra 0x49E41
// Subsystem: misc | Size: 148 bytes


void __cdecl16far FUN_4876_16e1(undefined2 param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  int in_DX;
  
  iVar2 = FUN_460e_0f42(param_1);
  if (iVar2 != 0 || in_DX != 0) {
    uVar3 = FUN_460e_0f42(0,*(undefined2 *)(iVar2 + 0x10),0);
    iVar2 = FUN_460e_141e(uVar3,in_DX);
    while( true ) {
      if ((iVar2 == 0 && in_DX == 0) || ((param_2 == 0 && (param_3 == 0)))) break;
      *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + param_2;
      *(int *)(iVar2 + 0x16) = *(int *)(iVar2 + 0x16) + param_3;
      if (*(int *)(iVar2 + 0xe) == 4) {
        *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + param_2;
        *(int *)(iVar2 + 0x3a) = *(int *)(iVar2 + 0x3a) + param_3;
      }
      piVar1 = (int *)(iVar2 + 10);
      iVar2 = *(int *)(iVar2 + 8);
      in_DX = *piVar1;
    }
  }
  return;
}

