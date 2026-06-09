// TIM2.EXE: FUN_31f7_6f0f @ file 0x03E07F Ghidra 0x38E7F
// Subsystem: misc | Size: 58 bytes


void __cdecl16far FUN_31f7_6f0f(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) ^ 0x10;
  }
  FUN_31f7_6a10((int)param_1,param_1._2_2_);
  FUN_2424_0f94((int)param_1,param_1._2_2_,3);
  FUN_28eb_2d82((int)param_1,param_1._2_2_,2);
  return;
}

