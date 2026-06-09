// TIM2.EXE: FUN_4bdc_2104 @ file 0x0530C4 Ghidra 0x4DEC4
// Subsystem: physics | Size: 61 bytes


void __cdecl16near FUN_4bdc_2104(void)

{
  int *piVar1;
  char cVar2;
  char in_AH;
  int in_BX;
  char *unaff_BP;
  uint unaff_SI;
  undefined2 unaff_ES;
  
  if (in_AH == -0x10) {
    do {
      cVar2 = *unaff_BP;
      unaff_BP = unaff_BP + 1;
      piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
      *piVar1 = *piVar1 + 1;
      unaff_SI = unaff_SI & 0x7fff;
    } while (cVar2 != -9);
    return;
  }
  if ((in_AH != -0x40) && (in_AH != -0x30)) {
    piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
    *piVar1 = *piVar1 + 1;
    unaff_SI = unaff_SI & 0x7fff;
  }
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  return;
}

