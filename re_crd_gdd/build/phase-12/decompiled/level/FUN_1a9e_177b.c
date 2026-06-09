// TIM2.EXE: FUN_1a9e_177b @ file 0x02135B Ghidra 0x1C15B
// Subsystem: level | Size: 76 bytes


bool __cdecl16near FUN_1a9e_177b(void)

{
  uint uVar1;
  byte bVar2;
  
  if (DAT_554c_402e < 9) {
    bVar2 = FUN_1a9e_0131();
    DAT_554c_402c = DAT_554c_402c | (uint)bVar2 << (8 - DAT_554c_402e & 0x1f);
    DAT_554c_402e = DAT_554c_402e + 8;
  }
  uVar1 = DAT_554c_402c;
  DAT_554c_402c = DAT_554c_402c << 1;
  DAT_554c_402e = DAT_554c_402e - 1;
  return (int)uVar1 < 0;
}

