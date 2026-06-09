// TIM2.EXE: FUN_31f7_677c @ file 0x03D8EC Ghidra 0x386EC
// Subsystem: misc | Size: 133 bytes


void __cdecl16far FUN_31f7_677c(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_5b41_1a1a == 0) {
    DAT_5b41_1a18 = FUN_4551_0370(DAT_5b41_0a18,6);
    DAT_5b41_1a1a = FUN_4551_0370(DAT_5b41_0a18,8);
    DAT_5b41_1a1c = FUN_4551_0370(DAT_5b41_0a18,0xb);
    DAT_5b41_1a1e = FUN_4551_0370(DAT_5b41_0a18,0xd);
  }
  iVar1 = FUN_31f7_688a((int)param_1,param_1._2_2_);
  *(undefined2 *)((int)param_1 + 0x98) = *(undefined2 *)(iVar1 * 2 + *(int *)(iRam0005582c + 0x46));
  FUN_28eb_3670((int)param_1,param_1._2_2_,iVar1);
  return;
}

