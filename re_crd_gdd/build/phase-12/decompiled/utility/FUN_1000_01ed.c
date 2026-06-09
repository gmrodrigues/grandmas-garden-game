// TIM2.EXE: FUN_1000_01ed @ file 0x0153ED Ghidra 0x101ED
// Subsystem: utility | Size: 45 bytes


void __cdecl16far FUN_1000_01ed(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}

