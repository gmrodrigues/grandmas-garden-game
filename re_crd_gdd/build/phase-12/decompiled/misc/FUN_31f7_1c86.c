// TIM2.EXE: FUN_31f7_1c86 @ file 0x038DF6 Ghidra 0x33BF6
// Subsystem: misc | Size: 71 bytes


void __cdecl16far FUN_31f7_1c86(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) ^ 0x10;
  }
  FUN_31f7_1a17((int)param_1,param_1._2_2_);
  FUN_2424_0915((int)param_1,param_1._2_2_,3);
  FUN_2424_0f94((int)param_1,param_1._2_2_,3);
  FUN_28eb_2d82((int)param_1,param_1._2_2_,2);
  return;
}

