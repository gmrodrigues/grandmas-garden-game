// TIM2.EXE: FUN_3f2b_0d17 @ file 0x0451C7 Ghidra 0x3FFC7
// Subsystem: sound | Size: 48 bytes


void __cdecl16far FUN_3f2b_0d17(void)

{
  if (DAT_5b41_1b54 != 0 || DAT_5b41_1b56 != 0) {
    DAT_5b41_1b56 = 0;
    DAT_5b41_1b54 = 0;
    FUN_22de_0351(DAT_5b41_1b58,DAT_5b41_1b5a);
    DAT_5b41_1b5a = 0;
    DAT_5b41_1b58 = 0;
  }
  return;
}

