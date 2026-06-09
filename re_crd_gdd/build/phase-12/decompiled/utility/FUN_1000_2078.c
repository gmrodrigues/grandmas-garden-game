// TIM2.EXE: FUN_1000_2078 @ file 0x017278 Ghidra 0x12078
// Subsystem: utility | Size: 21 bytes


void __cdecl16far FUN_1000_2078(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}

