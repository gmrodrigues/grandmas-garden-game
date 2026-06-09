// TIM2.EXE: FUN_1000_4ab3 @ file 0x019CB3 Ghidra 0x14AB3
// Subsystem: utility | Size: 29 bytes


void FUN_1000_4ab3(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    FUN_1000_1b4b(uVar2);
  }
  return;
}

