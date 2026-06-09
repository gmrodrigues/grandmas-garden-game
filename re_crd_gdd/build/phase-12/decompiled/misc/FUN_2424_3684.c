// TIM2.EXE: FUN_2424_3684 @ file 0x02CAC4 Ghidra 0x278C4
// Subsystem: misc | Size: 61 bytes


void __cdecl16far FUN_2424_3684(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_2424_4087((int)param_1,param_1._2_2_);
  if (iVar1 != 0) {
    FUN_2424_3a6b((int)param_1,param_1._2_2_);
    return;
  }
  if (*(int *)((int)param_1 + 8) == 0x76) {
    FUN_2424_44bb((int)param_1,param_1._2_2_);
  }
  return;
}

