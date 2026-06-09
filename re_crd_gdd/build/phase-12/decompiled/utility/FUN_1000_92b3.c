// TIM2.EXE: FUN_1000_92b3 @ file 0x01E4B3 Ghidra 0x192B3
// Subsystem: utility | Size: 28 bytes


void FUN_1000_92b3(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  FUN_1000_143a();
  return;
}

