// TIM2.EXE: FUN_31f7_3357 @ file 0x03A4C7 Ghidra 0x352C7
// Subsystem: misc | Size: 67 bytes


undefined2 __cdecl16far FUN_31f7_3357(undefined4 param_1)

{
  if (DAT_5b41_19c4 == 0) {
    DAT_5b41_19c4 = FUN_4551_0370(DAT_5b41_09e4,5);
    DAT_5b41_19c6 = FUN_4551_0370(DAT_5b41_09e4,4);
  }
  if ((int)param_1 != 0 || param_1._2_2_ != 0) {
    *(undefined2 *)((int)param_1 + 0xae) = 1;
  }
  return 1;
}

