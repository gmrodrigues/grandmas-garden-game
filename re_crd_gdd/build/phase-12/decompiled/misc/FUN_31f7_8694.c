// TIM2.EXE: FUN_31f7_8694 @ file 0x03F804 Ghidra 0x3A604
// Subsystem: misc | Size: 69 bytes


void __cdecl16far FUN_31f7_8694(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) ^ 0x10;
  }
  FUN_31f7_8634((int)param_1,param_1._2_2_);
  FUN_28eb_3328((int)param_1,param_1._2_2_);
  FUN_2424_0f94((int)param_1,param_1._2_2_,3);
  FUN_28eb_2d82((int)param_1,param_1._2_2_,2);
  return;
}

