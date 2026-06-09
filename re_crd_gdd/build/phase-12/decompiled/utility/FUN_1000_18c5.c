// TIM2.EXE: FUN_1000_18c5 @ file 0x016AC5 Ghidra 0x118C5
// Subsystem: utility | Size: 19 bytes


undefined2 __cdecl16far FUN_1000_18c5(void)

{
  code *pcVar1;
  undefined2 in_BX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return in_BX;
}

