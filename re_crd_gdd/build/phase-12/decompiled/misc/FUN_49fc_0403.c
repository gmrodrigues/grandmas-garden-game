// TIM2.EXE: FUN_49fc_0403 @ file 0x04F5C3 Ghidra 0x4A3C3
// Subsystem: misc | Size: 71 bytes


void __cdecl16far FUN_49fc_0403(void)

{
  if (DAT_5452_0000 != 0 || DAT_5452_0002 != 0) {
    FUN_460e_074f(0x5fc2);
    FUN_22de_0351(DAT_5452_0000,DAT_5452_0002);
    DAT_5452_0002 = 0;
    DAT_5452_0000 = 0;
  }
  return;
}

