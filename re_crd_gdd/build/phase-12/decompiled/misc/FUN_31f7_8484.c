// TIM2.EXE: FUN_31f7_8484 @ file 0x03F5F4 Ghidra 0x3A3F4
// Subsystem: misc | Size: 82 bytes


void __cdecl16far FUN_31f7_8484(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    if (*(int *)((int)param_1 + 0x10) != 4) {
      *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 5;
      FUN_2424_2e7d((int)param_1,param_1._2_2_,0);
      *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + -5;
      return;
    }
  }
  else if (*(int *)((int)param_1 + 0x10) == 4) {
    return;
  }
  FUN_2424_2e7d((int)param_1,param_1._2_2_,param_2);
  return;
}

