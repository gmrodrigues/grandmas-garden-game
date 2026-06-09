// TIM2.EXE: FUN_3e34_01ec @ file 0x04372C Ghidra 0x3E52C
// Subsystem: sound | Size: 75 bytes


void __cdecl16far FUN_3e34_01ec(void)

{
  int iVar1;
  
  for (iVar1 = 1; iVar1 < 0x32; iVar1 = iVar1 + 1) {
    if (*(int *)(iVar1 * 2) != 0) {
      FUN_3f2b_0f46(*(undefined2 *)(iVar1 * 2));
      *(undefined2 *)(iVar1 * 2) = 0;
    }
  }
  FUN_3f2b_118f();
  return;
}

