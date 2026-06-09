// TIM2.EXE: FUN_1a9e_5897 @ file 0x025477 Ghidra 0x20277
// Subsystem: level | Size: 49 bytes


void __cdecl16far FUN_1a9e_5897(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x33);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x33);
  (*pcVar1)();
  return;
}

