// TIM2.EXE: FUN_2424_08e8 @ file 0x029D28 Ghidra 0x24B28
// Subsystem: misc | Size: 45 bytes


void __cdecl16far FUN_2424_08e8(void)

{
  int *piVar1;
  
  for (piVar1 = DAT_5b41_04ac; (piVar1 != (int *)0x0 && (*piVar1 != 0)); piVar1 = (int *)*piVar1) {
  }
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)DAT_5b41_04ae;
    DAT_5b41_04ae = DAT_5b41_04ac;
    DAT_5b41_04ac = (int *)0x0;
  }
  return;
}

