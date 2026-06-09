// TIM2.EXE: FUN_460e_2412 @ file 0x04D6F2 Ghidra 0x484F2
// Subsystem: misc | Size: 48 bytes


void __cdecl16far FUN_460e_2412(void)

{
  bool bVar1;
  
  if ((DAT_5b41_1cea != '\0') && (DAT_554c_5744 != 0 || DAT_554c_5746 != 0)) {
    FUN_1000_1364();
    return;
  }
  if (DAT_5b41_1ce6 != 0 || DAT_5b41_1ce8 != 0) {
    bVar1 = 0xff46 < DAT_5b41_1ce6;
    DAT_5b41_1ce6 = DAT_5b41_1ce6 + 0xb9;
    DAT_5b41_1ce8 = DAT_5b41_1ce8 + (uint)bVar1;
  }
  return;
}

