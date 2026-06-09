// TIM2.EXE: FUN_460e_0aa3 @ file 0x04BD83 Ghidra 0x46B83
// Subsystem: misc | Size: 161 bytes


int * __cdecl16far FUN_460e_0aa3(undefined2 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  
  piVar1 = (int *)FUN_460e_0a42(param_1);
  if (piVar1 == (int *)0x0 && in_DX == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    do {
      iVar3 = piVar1[1];
      piVar1 = (int *)*piVar1;
      if (piVar1 == (int *)0x0 && iVar3 == 0) {
        return (int *)(int)piVar1;
      }
      if ((piVar1[2] == param_2) && (param_3 == 0 && param_4 == 0)) {
        return (int *)(int)piVar1;
      }
      iVar2 = FUN_4340_0b8a((int)piVar1 + 7,iVar3,param_3,param_4);
      if ((iVar2 == 0) && (param_2 == 0)) {
        return (int *)(int)piVar1;
      }
      in_DX = iVar3;
    } while ((piVar1[2] != param_2) ||
            (iVar3 = FUN_4340_0b8a((int)piVar1 + 7,iVar3,param_3,param_4), iVar3 != 0));
  }
  return piVar1;
}

