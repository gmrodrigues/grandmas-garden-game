// TIM2.EXE: FUN_28eb_3287 @ file 0x031337 Ghidra 0x2C137
// Subsystem: misc | Size: 81 bytes


int __cdecl16far FUN_28eb_3287(uint param_1)

{
  if ((DAT_5b41_054f != 0 || DAT_5b41_0551 != 0) && ((param_1 & 0x2000) != 0)) {
    return DAT_5b41_054f;
  }
  if ((DAT_5b41_0557 != 0 || DAT_5b41_0559 != 0) && ((param_1 & 0x1000) != 0)) {
    return DAT_5b41_0557;
  }
  if ((DAT_5b41_055f != 0 || DAT_5b41_0561 != 0) && ((param_1 & 0x800) != 0)) {
    return DAT_5b41_055f;
  }
  return 0;
}

