// TIM2.EXE: FUN_4bdc_1dca @ file 0x052D8A Ghidra 0x4DB8A
// Subsystem: misc | Size: 49 bytes


void __cdecl16near FUN_4bdc_1dca(void)

{
  int *piVar1;
  char in_AL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_ES;
  
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  if ((in_AL != -1) && (cRam0004020f == '\0')) {
    (*pcRam000556ad)(0x4000,unaff_BP + 2);
  }
  return;
}

