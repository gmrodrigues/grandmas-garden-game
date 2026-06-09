// TIM2.EXE: FUN_1000_1710 @ file 0x016910 Ghidra 0x11710
// Subsystem: utility | Size: 21 bytes


void __cdecl16far FUN_1000_1710(int *param_1)

{
  code *pcVar1;
  byte bVar2;
  
  pcVar1 = (code *)swi(0x21);
  bVar2 = (*pcVar1)();
  *param_1 = bVar2 + 1;
  return;
}

