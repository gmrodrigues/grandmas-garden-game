// TIM2.EXE: FUN_4bdc_2159 @ file 0x053119 Ghidra 0x4DF19
// Subsystem: physics | Size: 34 bytes


void __cdecl16near FUN_4bdc_2159(void)

{
  int in_BX;
  int iVar1;
  int unaff_ES;
  
  iVar1 = 0;
  while ((*(int *)(iVar1 + 0xe) != in_BX || (*(int *)(iVar1 + 0x10) != unaff_ES))) {
    iVar1 = iVar1 + 4;
    if (iVar1 == 0x40) {
      return;
    }
  }
  return;
}

