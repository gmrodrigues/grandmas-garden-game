// TIM2.EXE: FUN_1000_208d @ file 0x01728D Ghidra 0x1208D
// Subsystem: utility | Size: 21 bytes


void __cdecl16far FUN_1000_208d(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}

