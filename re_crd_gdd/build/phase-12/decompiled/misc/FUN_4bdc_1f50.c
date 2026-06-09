// TIM2.EXE: FUN_4bdc_1f50 @ file 0x052F10 Ghidra 0x4DD10
// Subsystem: misc | Size: 36 bytes


void __cdecl16near FUN_4bdc_1f50(void)

{
  int *piVar1;
  char in_AL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_ES;
  
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  if ((in_AL != -1) && (cRam0004020f == '\0')) {
    (*pcRam000556ad)(0x4000,unaff_BP + 1);
  }
  return;
}

