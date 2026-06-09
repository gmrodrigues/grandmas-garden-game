// TIM2.EXE: FUN_3f2b_0da4 @ file 0x045254 Ghidra 0x40054
// Subsystem: sound | Size: 46 bytes


void __cdecl16far FUN_3f2b_0da4(int param_1,int param_2)

{
  if ((DAT_5b41_1b54 != 0 || DAT_5b41_1b56 != 0) && (param_1 != 0 || param_2 != 0)) {
    FUN_3f2b_0dd2();
    FUN_3f2b_0ffb(param_1,param_2);
    FUN_3f2b_0e15();
  }
  return;
}

