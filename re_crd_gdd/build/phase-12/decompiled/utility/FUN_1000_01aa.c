// TIM2.EXE: FUN_1000_01aa @ file 0x0153AA Ghidra 0x101AA
// Subsystem: utility | Size: 67 bytes


void __cdecl16near FUN_1000_01aa(void)

{
  code *pcVar1;
  undefined2 in_BX;
  undefined2 unaff_ES;
  
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

