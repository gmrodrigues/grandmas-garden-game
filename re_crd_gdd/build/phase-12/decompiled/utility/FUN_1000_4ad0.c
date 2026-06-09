// TIM2.EXE: FUN_1000_4ad0 @ file 0x019CD0 Ghidra 0x14AD0
// Subsystem: utility | Size: 22 bytes


void FUN_1000_4ad0(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}

