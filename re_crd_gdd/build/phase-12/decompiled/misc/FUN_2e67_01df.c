// TIM2.EXE: FUN_2e67_01df @ file 0x033A4F Ghidra 0x2E84F
// Subsystem: misc | Size: 82 bytes


void __cdecl16far FUN_2e67_01df(void)

{
  if (DAT_5b41_0bec != 0) {
    FUN_4bdc_3427(0xfffe);
    FUN_4bdc_32e9(0xfffe);
    FUN_460e_20cf();
    FUN_4bdc_3ce2();
    if (DAT_5b41_0bea != 0) {
      FUN_1a9e_6e73(DAT_5b41_0bea);
    }
    DAT_5b41_0bea = 0;
    DAT_5b41_0bec = 0;
    DAT_5b41_0c40 = 0;
    DAT_5b41_0c42 = 0;
  }
  return;
}

