// TIM2.EXE: FUN_1a9e_6e73 @ file 0x026A53 Ghidra 0x21853
// Subsystem: misc | Size: 52 bytes


undefined2 __cdecl16far FUN_1a9e_6e73(int param_1)

{
  undefined2 *puVar1;
  
  if (param_1 != 0) {
    puVar1 = (undefined2 *)FUN_1a9e_6886(param_1);
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = 0;
      FUN_1000_0c9d(param_1);
      return 1;
    }
  }
  return 0;
}

