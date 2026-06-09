// TIM2.EXE: FUN_22de_0351 @ file 0x028331 Ghidra 0x23131
// Subsystem: misc | Size: 136 bytes


void __cdecl16far FUN_22de_0351(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2;
  if (param_1 != 0 || param_2 != 0) {
    DAT_5b41_02f0 = &param_1;
    iVar2 = FUN_3f2b_0e3a(0);
    if ((iVar2 == 0) || (iVar1 != DAT_554c_3d5a)) {
      if ((DAT_5b41_1b54 == 0 && DAT_5b41_1b56 == 0) || (iVar1 != DAT_5b41_1b56)) {
        if (iVar1 == 0x554c) {
          FUN_1000_130c(param_1);
        }
        else {
          FUN_1a9e_5415(param_1,param_2);
        }
      }
      else {
        FUN_3f2b_0da4(param_1,param_2);
      }
    }
    else {
      FUN_3f2b_0ffb(param_1,param_2);
    }
  }
  return;
}

