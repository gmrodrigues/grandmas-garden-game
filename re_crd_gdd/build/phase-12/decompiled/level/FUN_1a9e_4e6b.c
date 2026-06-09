// TIM2.EXE: FUN_1a9e_4e6b @ file 0x024A4B Ghidra 0x1F84B
// Subsystem: level | Size: 40 bytes


undefined2 __cdecl16far FUN_1a9e_4e6b(int param_1)

{
  undefined2 uVar1;
  
  if (((param_1 < 1) || (0x13 < param_1)) ||
     (((undefined2 *)&DAT_5b41_25d6)[param_1 * 2] == 0 &&
      ((undefined2 *)&DAT_5b41_25d8)[param_1 * 2] == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

