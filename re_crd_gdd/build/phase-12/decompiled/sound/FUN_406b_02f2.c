// TIM2.EXE: FUN_406b_02f2 @ file 0x045BA2 Ghidra 0x409A2
// Subsystem: sound | Size: 217 bytes


undefined2 __cdecl16far FUN_406b_02f2(int param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  FUN_406b_03cb(0xfffe,0xffff);
  if (DAT_53bd_0038 != 0) {
    FUN_4a54_09c2(DAT_53bd_0038);
    DAT_53bd_0038 = 0;
  }
  if (param_1 == 0) {
    DAT_53bd_003a = 0;
    DAT_53bd_003c._2_2_ = 0;
    DAT_53bd_003c._0_2_ = 0;
    uVar1 = 0;
  }
  else {
    iVar2 = param_1;
    if (DAT_53bd_0038 == 0) {
      while ((iVar2 != 0 && (DAT_53bd_0038 = FUN_4a54_0664(param_1), DAT_53bd_0038 == 0))) {
        iVar2 = FUN_3f2b_0aa7();
      }
    }
    DAT_53bd_003a = FUN_4a54_09d2(DAT_53bd_0038);
    DAT_53bd_003c._2_2_ = param_3;
    DAT_53bd_003c._0_2_ = param_2;
    if (DAT_53bd_0038 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

