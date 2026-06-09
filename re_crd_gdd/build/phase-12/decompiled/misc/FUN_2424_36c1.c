// TIM2.EXE: FUN_2424_36c1 @ file 0x02CB01 Ghidra 0x27901
// Subsystem: misc | Size: 61 bytes


void __cdecl16far FUN_2424_36c1(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_2424_4087((int)param_1,param_1._2_2_);
  if (iVar1 != 0) {
    FUN_2424_3c0a(0x2424,(int)param_1,param_1._2_2_);
    return;
  }
  if (*(int *)((int)param_1 + 8) == 0x76) {
    FUN_2424_4678((int)param_1,param_1._2_2_);
  }
  return;
}

