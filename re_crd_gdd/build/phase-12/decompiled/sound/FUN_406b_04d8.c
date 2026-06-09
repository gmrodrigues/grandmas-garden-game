// TIM2.EXE: FUN_406b_04d8 @ file 0x045D88 Ghidra 0x40B88
// Subsystem: sound | Size: 98 bytes


bool __cdecl16far FUN_406b_04d8(int param_1)

{
  if (param_1 == -1) {
    DAT_53bd_0044 = 0;
  }
  if (DAT_53bd_0044 != 0) {
    DAT_53bd_0044 = DAT_53bd_0044 + -1;
  }
  if (DAT_53bd_0044 == 0) {
    DAT_53bd_0004 = DAT_53bd_0042;
    FUN_406b_111b(0);
  }
  return DAT_53bd_0044 == 0;
}

