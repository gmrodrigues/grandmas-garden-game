// TIM2.EXE: FUN_1a9e_5a82 @ file 0x025662 Ghidra 0x20462
// Subsystem: level | Size: 35 bytes


byte __cdecl16far FUN_1a9e_5a82(int param_1)

{
  byte bVar1;
  
  bVar1 = -DAT_554c_5594;
  if (DAT_554c_5594 != '\0') {
    bVar1 = DAT_554c_5595;
    if (param_1 != 0) {
      bVar1 = DAT_554c_5595 >> 1;
    }
  }
  return bVar1 & 1;
}

