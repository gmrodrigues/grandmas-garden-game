// TIM2.EXE: FUN_1000_1b4b @ file 0x016D4B Ghidra 0x11B4B
// Subsystem: utility | Size: 62 bytes


undefined2 FUN_1000_1b4b(int param_1)

{
  if (param_1 < 0) {
    if (-DAT_554c_5bf0 == param_1 || -param_1 < DAT_554c_5bf0) {
      iRam0005554e = -param_1;
      DAT_554c_5944 = 0xffff;
      return 0xffff;
    }
  }
  else if (param_1 < 0x59) goto LAB_1000_1b5f;
  param_1 = 0x57;
LAB_1000_1b5f:
  DAT_554c_5944 = param_1;
  iRam0005554e = (int)*(char *)(param_1 + 0x5946);
  return 0xffff;
}

