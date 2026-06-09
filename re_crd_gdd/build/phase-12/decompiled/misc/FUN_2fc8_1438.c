// TIM2.EXE: FUN_2fc8_1438 @ file 0x0362B8 Ghidra 0x310B8
// Subsystem: misc | Size: 37 bytes


undefined2 __cdecl16far FUN_2fc8_1438(uint param_1)

{
  param_1 = param_1 >> 4;
  if ((param_1 & 0x800) != 0) {
    param_1 = 0x1000 - param_1;
  }
  return *(undefined2 *)(param_1 * 2 + 0xe);
}

