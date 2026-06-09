// TIM2.EXE: FUN_1a9e_1806 @ file 0x0213E6 Ghidra 0x1C1E6
// Subsystem: level | Size: 102 bytes


void __cdecl16near FUN_1a9e_1806(char param_1,uint param_2)

{
  DAT_554c_402f = DAT_554c_402f | param_2 >> (DAT_554c_4031 & 0x1f);
  DAT_554c_4031 = DAT_554c_4031 + param_1;
  if (7 < DAT_554c_4031) {
    FUN_1a9e_036b(DAT_554c_402f >> 8);
    DAT_554c_4031 = DAT_554c_4031 - 8;
    if (7 < DAT_554c_4031) {
      FUN_1a9e_036b(DAT_554c_402f);
      DAT_554c_4031 = DAT_554c_4031 - 8;
      DAT_554c_402f = param_2 << (param_1 - DAT_554c_4031 & 0x1f);
      return;
    }
    DAT_554c_402f = DAT_554c_402f << 8;
  }
  return;
}

