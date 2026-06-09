// TIM2.EXE: FUN_460e_0562 @ file 0x04B842 Ghidra 0x46642
// Subsystem: misc | Size: 324 bytes


undefined2 __cdecl16far FUN_460e_0562(undefined2 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int in_DX;
  undefined4 local_6;
  
  piVar3 = (int *)FUN_460e_0a42(param_1);
  if (piVar3 != (int *)0x0 || in_DX != 0) {
    piVar2 = (int *)CONCAT22(in_DX,piVar3);
    while( true ) {
      iVar1 = piVar3[1];
      piVar3 = (int *)*piVar3;
      local_6 = (int *)CONCAT22(iVar1,piVar3);
      if ((((piVar3 == (int *)0x0 && iVar1 == 0) ||
           ((piVar3[2] == param_2 && (param_3 == 0 && param_4 == 0)))) ||
          ((iVar4 = FUN_4340_0b8a((int)piVar3 + 7,iVar1,param_3,param_4), iVar4 == 0 &&
           (param_2 == 0)))) ||
         ((piVar3[2] == param_2 &&
          (iVar4 = FUN_4340_0b8a((int)piVar3 + 7,iVar1,param_3,param_4), iVar4 == 0)))) break;
      piVar2 = (int *)CONCAT22(iVar1,piVar3);
      in_DX = iVar1;
    }
    if (piVar3 != (int *)0x0 || iVar1 != 0) {
      iVar4 = *local_6;
      ((int *)piVar2)[1] = piVar3[1];
      *piVar2 = iVar4;
      if (((*(byte *)(piVar3 + 3) & 8) == 0) || ((*(byte *)(piVar3 + 3) & 1) == 0)) {
        if ((*(byte *)(piVar3 + 3) & 2) == 0) {
          if ((*(byte *)(piVar3 + 3) & 4) == 0) {
            return 0;
          }
          piVar3[1] = DAT_5b41_1c09;
          *local_6 = (int)DAT_5b41_1c07;
          DAT_5b41_1c07 = piVar3;
          DAT_5b41_1c09 = iVar1;
        }
        else {
          piVar3[1] = DAT_5b41_1c05;
          *local_6 = (int)DAT_5b41_1c03;
          DAT_5b41_1c03 = piVar3;
          DAT_5b41_1c05 = iVar1;
        }
      }
      else {
        FUN_22de_0351(piVar3,iVar1);
      }
      return 1;
    }
  }
  return 0;
}

