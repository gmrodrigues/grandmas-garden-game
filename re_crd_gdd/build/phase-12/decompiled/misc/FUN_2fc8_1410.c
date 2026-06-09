// TIM2.EXE: FUN_2fc8_1410 @ file 0x036290 Ghidra 0x31090
// Subsystem: misc | Size: 40 bytes


undefined2 __cdecl16far FUN_2fc8_1410(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 + 0xc000U >> 4;
  if ((uVar1 & 0x800) != 0) {
    uVar1 = 0x1000 - uVar1;
  }
  return *(undefined2 *)(uVar1 * 2 + 0xe);
}

