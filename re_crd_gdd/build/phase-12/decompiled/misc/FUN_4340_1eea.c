// TIM2.EXE: FUN_4340_1eea @ file 0x04A4EA Ghidra 0x452EA
// Subsystem: misc | Size: 60 bytes


int __cdecl16far FUN_4340_1eea(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    for (iVar1 = 0; iVar1 < 0x19; iVar1 = iVar1 + 1) {
      if (*(int *)(iVar1 * 0x1e + 0x100) == param_1) {
        return iVar1 * 0x1e + 0x102;
      }
    }
  }
  return 0x3f0;
}

