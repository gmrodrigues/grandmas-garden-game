// TIM2.EXE: FUN_1a9e_834a @ file 0x027F2A Ghidra 0x22D2A
// Subsystem: physics | Size: 32 bytes


int __cdecl16far FUN_1a9e_834a(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    while (*(int *)(param_1 + iVar1 * 2) != 0) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

