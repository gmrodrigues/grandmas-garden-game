// TIM2.EXE: FUN_1000_18d8 @ file 0x016AD8 Ghidra 0x118D8
// Subsystem: utility | Size: 21 bytes


void __cdecl16far FUN_1000_18d8(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}

