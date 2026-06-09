// TIM2.EXE: FUN_1a9e_6886 @ file 0x026466 Ghidra 0x21266
// Subsystem: misc | Size: 48 bytes


int __cdecl16far FUN_1a9e_6886(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 4;
  do {
    iVar1 = iVar2 + -1;
    if (iVar2 < 1) {
      return 0;
    }
    iVar2 = iVar1;
  } while (*(int *)(iVar1 * 0x43 + -0x798f) != param_1);
  return iVar1 * 0x43 + -0x798f;
}

