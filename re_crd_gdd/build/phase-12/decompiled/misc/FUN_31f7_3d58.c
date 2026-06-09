// TIM2.EXE: FUN_31f7_3d58 @ file 0x03AEC8 Ghidra 0x35CC8
// Subsystem: misc | Size: 82 bytes


void __cdecl16far FUN_31f7_3d58(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) ^ 0x10;
  }
  FUN_31f7_3aab((int)param_1,param_1._2_2_);
  FUN_28eb_3328((int)param_1,param_1._2_2_);
  FUN_2424_0915((int)param_1,param_1._2_2_,3);
  FUN_2424_0f94((int)param_1,param_1._2_2_,3);
  FUN_28eb_2d82((int)param_1,param_1._2_2_,2);
  return;
}

