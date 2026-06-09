// TIM2.EXE: FUN_2e67_0423 @ file 0x033C93 Ghidra 0x2EA93
// Subsystem: misc | Size: 60 bytes


void __cdecl16far FUN_2e67_0423(void)

{
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  FUN_2e67_06ab();
  DAT_5b41_0bee = *(undefined2 *)(unaff_BP + -2);
  if (unaff_SI == DAT_5b41_0be2) {
    DAT_5b41_0be2 = 0;
  }
  if (unaff_SI == DAT_5b41_0be4) {
    DAT_5b41_0be4 = 0;
  }
  if (unaff_SI == DAT_5b41_0be6) {
    DAT_5b41_0be6 = 0;
  }
  FUN_4bdc_32e9();
  return;
}

