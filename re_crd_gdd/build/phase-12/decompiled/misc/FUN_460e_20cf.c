// TIM2.EXE: FUN_460e_20cf @ file 0x04D3AF Ghidra 0x481AF
// Subsystem: misc | Size: 113 bytes


void __cdecl16far FUN_460e_20cf(void)

{
  if (DAT_5b41_1cf1 != 0) {
    FUN_1a9e_3f10(DAT_5b41_1cf1);
    DAT_5b41_1cf1 = 0;
  }
  if (DAT_5b41_1cea != '\0') {
    FUN_460e_2140();
    FUN_1000_1364();
    DAT_554c_575e = 0x2b11;
    FUN_1000_135d(0x2b11);
    if (DAT_554c_3fd0 != 0 || DAT_554c_3fd2 != 0) {
      FUN_1a9e_5415(DAT_554c_3fd0,DAT_554c_3fd2);
      DAT_554c_3fd2 = 0;
      DAT_554c_3fd0 = 0;
      DAT_5b41_1ced = 0;
    }
    DAT_5b41_1cea = '\0';
  }
  return;
}

