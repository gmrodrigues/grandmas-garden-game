// TIM2.EXE: FUN_2424_1650 @ file 0x02AA90 Ghidra 0x25890
// Subsystem: misc | Size: 45 bytes


void __cdecl16far FUN_2424_1650(void)

{
  int *piVar1;
  
  for (piVar1 = DAT_5b41_04b0; (piVar1 != (int *)0x0 && (*piVar1 != 0)); piVar1 = (int *)*piVar1) {
  }
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)DAT_5b41_04ae;
    DAT_5b41_04ae = DAT_5b41_04b0;
    DAT_5b41_04b0 = (int *)0x0;
  }
  return;
}

