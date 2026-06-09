// TIM2.EXE: FUN_1000_2cb4 @ file 0x017EB4 Ghidra 0x12CB4
// Subsystem: utility | Size: 55 bytes


void __cdecl16near FUN_1000_2cb4(void)

{
  iRam000554c4 = DAT_1000_2baf;
  if (DAT_1000_2baf != 0) {
    uRam000554c6 = *(undefined2 *)0x6;
    *(undefined2 *)0x6 = 0x554c;
    *(undefined2 *)0x4 = 0x554c;
    return;
  }
  DAT_1000_2baf = 0x554c;
  iRam000554c4 = 0x554c;
  uRam000554c6 = 0x554c;
  return;
}

