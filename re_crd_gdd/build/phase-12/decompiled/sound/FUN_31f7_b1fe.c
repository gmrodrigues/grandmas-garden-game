// TIM2.EXE: FUN_31f7_b1fe @ file 0x04236E Ghidra 0x3D16E
// Subsystem: sound | Size: 49 bytes


undefined2 __cdecl16far FUN_31f7_b1fe(undefined4 param_1)

{
  if ((int)param_1 == 0 && param_1._2_2_ == 0) {
    if (DAT_5b41_1ab8 == 0) {
      DAT_5b41_1ab8 = FUN_4340_0849(0x3d3c);
    }
  }
  else {
    *(undefined2 *)((int)param_1 + 0xae) = 0x41;
  }
  return 1;
}

