// TIM2.EXE: FUN_4340_1ea6 @ file 0x04A4A6 Ghidra 0x452A6
// Subsystem: misc | Size: 68 bytes


undefined2 __cdecl16far FUN_4340_1ea6(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = 0;
    while ((uVar1 < 0x19 && (*(int *)(uVar1 * 0x1e + 0x100) != param_1))) {
      uVar1 = uVar1 + 1;
    }
    if (uVar1 < 0x19) {
      *(undefined2 *)(uVar1 * 0x1e + 0x100) = 0;
      return 1;
    }
  }
  return 0;
}

