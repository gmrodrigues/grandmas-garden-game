// TIM2.EXE: FUN_1a9e_4d00 @ file 0x0248E0 Ghidra 0x1F6E0
// Subsystem: level | Size: 31 bytes


byte __cdecl16far FUN_1a9e_4d00(int param_1)

{
  byte bVar1;
  
  bVar1 = DAT_554c_5011;
  if (param_1 != 0xe0) {
    bVar1 = *(byte *)(param_1 + 0x50c4);
  }
  return bVar1 & 1;
}

