// TIM2.EXE: FUN_4340_08dd @ file 0x048EDD Ghidra 0x43CDD
// Subsystem: misc | Size: 182 bytes


int __cdecl16far FUN_4340_08dd(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  
  iVar2 = DAT_5b41_1ba6;
  if (param_1 == -1) {
    DAT_5b41_1ba6 = 0;
  }
  else {
    iVar1 = FUN_3f2b_0718(param_1);
    if (iVar1 == 0) {
      DAT_5b41_1ad2 = 0x12;
      iVar2 = 0;
    }
    else if (param_1 != 0) {
      iVar1 = FUN_3f2b_0811(param_1);
      if (iVar1 == 0) {
        DAT_5b41_1ba6 = 0;
        DAT_5b41_1ad2 = 0;
        do {
          uVar3 = FUN_3f2b_0718(param_1);
          iVar1 = FUN_1a9e_6ec1(uVar3);
          if ((iVar1 != 0) || (DAT_5b41_1ad2 == 2)) break;
          iVar4 = FUN_3f2b_0aa7();
        } while (iVar4 != 0);
        if (iVar1 == 0) {
          if (iVar2 != 0) {
            FUN_4340_08dd(iVar2);
          }
          DAT_5b41_1ad2 = 0x12;
          return 0;
        }
      }
      FUN_1a9e_4d2d(iVar1);
      FUN_3f2b_0953(param_1,iVar1);
      DAT_5b41_1ba6 = param_1;
    }
  }
  return iVar2;
}

