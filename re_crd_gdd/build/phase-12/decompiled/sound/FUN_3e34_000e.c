// TIM2.EXE: FUN_3e34_000e @ file 0x04354E Ghidra 0x3E34E
// Subsystem: sound | Size: 119 bytes


undefined2 __cdecl16far FUN_3e34_000e(undefined2 param_1,uint param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  DAT_5b41_1ad2 = 0;
  iVar1 = FUN_4a54_0664(param_1);
  if (iVar1 == 0) {
    if (DAT_5b41_1ad2 == 0) {
      DAT_5b41_1ad2 = 7;
    }
    uVar2 = 0;
  }
  else {
    if ((param_2 & 4) == 0) {
      if ((param_2 & 1) != 0) {
        FUN_3e34_055d(iVar1);
      }
    }
    else if ((param_2 & 1) == 0) {
      FUN_3e34_0237(iVar1);
    }
    else {
      FUN_3e34_03cc(iVar1);
    }
    uVar2 = FUN_3e34_0280(iVar1,param_2);
  }
  return uVar2;
}

