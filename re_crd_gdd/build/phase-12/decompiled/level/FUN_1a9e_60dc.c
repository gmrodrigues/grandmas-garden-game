// TIM2.EXE: FUN_1a9e_60dc @ file 0x025CBC Ghidra 0x20ABC
// Subsystem: level | Size: 20 bytes


void __cdecl16near FUN_1a9e_60dc(void)

{
  code *pcVar1;
  undefined2 unaff_ES;
  
  *(byte *)0x10 = *(byte *)0x10 & 0xcf;
  *(byte *)0x10 = *(byte *)0x10 | 0x20;
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}

