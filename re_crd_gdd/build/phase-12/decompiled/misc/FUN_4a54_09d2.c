// TIM2.EXE: FUN_4a54_09d2 @ file 0x050112 Ghidra 0x4AF12
// Subsystem: misc | Size: 32 bytes


int __cdecl16far FUN_4a54_09d2(int param_1)

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

