// TIM2.EXE: FUN_460e_1a18 @ file 0x04CCF8 Ghidra 0x47AF8
// Subsystem: misc | Size: 42 bytes


undefined2 __cdecl16far FUN_460e_1a18(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (0x1ff < iVar1) {
      return 0;
    }
    if (*(int *)(iVar1 * 2) == param_1) break;
    iVar1 = iVar1 + 1;
  }
  return 1;
}

