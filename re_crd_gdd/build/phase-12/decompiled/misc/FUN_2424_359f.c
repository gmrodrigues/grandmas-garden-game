// TIM2.EXE: FUN_2424_359f @ file 0x02C9DF Ghidra 0x277DF
// Subsystem: misc | Size: 90 bytes


void __cdecl16far FUN_2424_359f(int param_1)

{
  DAT_554c_42d8 = DAT_554c_42d2;
  FUN_2424_0304();
  FUN_406b_000c(0,0,DAT_554c_49aa,DAT_554c_49ac,0);
  if (DAT_554c_3e4a != 0) {
    DAT_554c_42d8 = 0xa000;
    FUN_406b_000c(0,0,DAT_554c_49aa,DAT_554c_3e4a,0);
    DAT_554c_42d8 = DAT_554c_42d2;
  }
  if (param_1 != 0) {
    FUN_2424_028d();
  }
  return;
}

