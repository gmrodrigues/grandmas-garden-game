// TIM2.EXE: FUN_1000_976b @ file 0x01E96B Ghidra 0x1976B
// Subsystem: utility | Size: 98 bytes


undefined2 __cdecl16far FUN_1000_976b(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int local_4;
  
  iVar1 = FUN_1000_9cb9(param_4,param_3,param_2,param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (param_3 - param_1) + 1;
    for (local_4 = param_2; local_4 <= param_4; local_4 = local_4 + 1) {
      uVar3 = FUN_1000_270f(local_4,param_1);
      FUN_1000_9c7b(iVar1,param_5,0x554c,uVar3);
      param_5 = param_5 + iVar1 * 2;
    }
    uVar2 = 1;
  }
  return uVar2;
}

