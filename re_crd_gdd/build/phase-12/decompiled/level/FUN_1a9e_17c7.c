// TIM2.EXE: FUN_1a9e_17c7 @ file 0x0213A7 Ghidra 0x1C1A7
// Subsystem: level | Size: 63 bytes


uint __cdecl16near FUN_1a9e_17c7(void)

{
  uint uVar1;
  byte bVar2;
  
  for (; uVar1 = DAT_554c_402c, DAT_554c_402e < 9; DAT_554c_402e = DAT_554c_402e + 8) {
    bVar2 = FUN_1a9e_0131();
    DAT_554c_402c = DAT_554c_402c | (uint)bVar2 << (8 - DAT_554c_402e & 0x1f);
  }
  DAT_554c_402c = DAT_554c_402c << 8;
  DAT_554c_402e = DAT_554c_402e - 8;
  return uVar1 >> 8;
}

