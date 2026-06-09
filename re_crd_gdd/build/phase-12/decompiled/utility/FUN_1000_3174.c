// TIM2.EXE: FUN_1000_3174 @ file 0x018374 Ghidra 0x13174
// Subsystem: utility | Size: 58 bytes


void __cdecl16near FUN_1000_3174(void)

{
  byte *in_BX;
  byte *pbVar1;
  
  pbVar1 = in_BX;
  if (DAT_554c_5b50 != in_BX) {
    pbVar1 = *(byte **)(in_BX + 2);
    if ((*pbVar1 & 1) != 0) goto LAB_1000_31a8;
    if (pbVar1 != DAT_554c_5b50) {
      FUN_1000_31e7();
      in_BX = pbVar1;
      pbVar1 = *(byte **)(pbVar1 + 2);
      goto LAB_1000_31a8;
    }
  }
  DAT_554c_5b50 = (byte *)0x0;
  DAT_554c_5b52 = (byte *)0x0;
  DAT_554c_5b54 = 0;
  in_BX = pbVar1;
  pbVar1 = DAT_554c_5b52;
LAB_1000_31a8:
  DAT_554c_5b52 = pbVar1;
  FUN_1000_2a77(in_BX);
  return;
}

