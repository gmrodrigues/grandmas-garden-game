// TIM2.EXE: FUN_1000_0566 @ file 0x015766 Ghidra 0x10566
// Subsystem: utility | Size: 122 bytes


void __cdecl16far FUN_1000_0566(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    if (((undefined2 *)&DAT_5b41_03c8)[iVar1 * 0xe] != 0 ||
        ((undefined2 *)&DAT_5b41_03ca)[iVar1 * 0xe] != 0) {
      FUN_22de_0351(((undefined2 *)&DAT_5b41_03c8)[iVar1 * 0xe],
                    ((undefined2 *)&DAT_5b41_03ca)[iVar1 * 0xe]);
      ((undefined2 *)&DAT_5b41_03ca)[iVar1 * 0xe] = 0;
      ((undefined2 *)&DAT_5b41_03c8)[iVar1 * 0xe] = 0;
    }
  }
  if (DAT_5b41_046b != 0 || DAT_5b41_046d != 0) {
    FUN_1000_18d8(0x24,DAT_5b41_046b,DAT_5b41_046d);
    DAT_5b41_046d = 0;
    DAT_5b41_046b = 0;
  }
  DAT_5b41_0467 = 0;
  DAT_5b41_0465 = 0;
  DAT_5b41_045c = 0;
  return;
}

