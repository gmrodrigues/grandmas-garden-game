// TIM2.EXE: FUN_1000_1853 @ file 0x016A53 Ghidra 0x11853
// Subsystem: utility | Size: 11 bytes


void __stdcall16far FUN_1000_1853(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int in_CX;
  int iVar3;
  undefined1 *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  byte in_CF;
  
  for (iVar3 = in_CX * 2 + (uint)in_CF; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    puVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *puVar2 = *puVar1;
  }
  return;
}

