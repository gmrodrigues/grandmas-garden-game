// TIM2.EXE: FUN_1000_018e @ file 0x01538E Ghidra 0x1018E
// Subsystem: utility | Size: 28 bytes


void FUN_1000_018e(void)

{
  code *pcVar1;
  undefined2 in_BX;
  undefined2 unaff_ES;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  FUN_1000_173e();
  FUN_1000_17d2();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  uRam0005552e = in_BX;
  uRam00055530 = unaff_ES;
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  uRam00055532 = in_BX;
  uRam00055534 = unaff_ES;
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  uRam00055536 = in_BX;
  uRam00055538 = unaff_ES;
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  uRam0005553a = in_BX;
  uRam0005553c = unaff_ES;
  (*pcVar1)();
  return;
}

