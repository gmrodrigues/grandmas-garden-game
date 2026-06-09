// TIM2.EXE: FUN_1a9e_1357 @ file 0x020F37 Ghidra 0x1BD37
// Subsystem: level | Size: 58 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near FUN_1a9e_1357(void)

{
  int iVar1;
  
  for (iVar1 = 0x1001; iVar1 < 0x1101; iVar1 = iVar1 + 1) {
    *(undefined2 *)((int)_DAT_5b41_1d56 + iVar1 * 2) = 0x1000;
  }
  for (iVar1 = 0; iVar1 < 0x1000; iVar1 = iVar1 + 1) {
    *(undefined2 *)((int)DAT_5b41_1d52 + iVar1 * 2) = 0x1000;
  }
  return;
}

