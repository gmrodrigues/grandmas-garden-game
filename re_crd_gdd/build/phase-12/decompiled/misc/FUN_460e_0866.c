// TIM2.EXE: FUN_460e_0866 @ file 0x04BB46 Ghidra 0x46946
// Subsystem: misc | Size: 276 bytes


int __cdecl16far FUN_460e_0866(undefined2 param_1,undefined2 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_DX;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = (int *)FUN_460e_0a42(param_1);
  if (piVar1 != (int *)0x0 || in_DX != 0) {
    iVar5 = 0;
    piVar4 = piVar1;
    iVar2 = in_DX;
    while( true ) {
      iVar6 = piVar4[1];
      piVar4 = (int *)*piVar4;
      if (piVar4 == (int *)0x0 && iVar6 == 0) break;
      iVar2 = iVar6;
      if (((*(byte *)(piVar4 + 3) & 8) == 0) ||
         (uVar3 = FUN_4340_0a09((int)piVar4 + 7,iVar6), uVar3 < 0x200)) {
        iVar5 = iVar5 + 1;
      }
    }
    if (iVar5 != 0) {
      if (param_3 != 0) {
        FUN_42da_0007(param_2,param_3);
      }
      iVar2 = FUN_42da_05c8(param_2,iVar5);
      while (iVar6 = in_DX, iVar2 != 0) {
        do {
          in_DX = piVar1[1];
          piVar1 = (int *)*piVar1;
          if (piVar1 == (int *)0x0 && in_DX == 0) {
            if (param_3 != 0) {
              FUN_42da_0108(param_2);
              return iVar5;
            }
            return iVar5;
          }
        } while (((*(byte *)(piVar1 + 3) & 8) != 0) &&
                (uVar3 = FUN_4340_0a09((int)piVar1 + 7,in_DX), iVar6 = in_DX, 0x1ff < uVar3));
        iVar2 = FUN_42da_05c8(param_2,piVar1[2]);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = FUN_42da_0610(param_2,(int)piVar1 + 7,in_DX,0x200);
      }
    }
  }
  return 0;
}

