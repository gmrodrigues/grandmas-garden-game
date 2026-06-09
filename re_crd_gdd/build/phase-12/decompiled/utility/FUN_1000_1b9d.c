// TIM2.EXE: FUN_1000_1b9d @ file 0x016D9D Ghidra 0x11B9D
// Subsystem: utility | Size: 21 bytes


uint __cdecl16far FUN_1000_1b9d(void)

{
  code *pcVar1;
  uint extraout_DX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return extraout_DX & 0x80;
}

