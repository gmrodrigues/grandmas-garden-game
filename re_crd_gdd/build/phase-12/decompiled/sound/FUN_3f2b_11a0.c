// TIM2.EXE: FUN_3f2b_11a0 @ file 0x045650 Ghidra 0x40450
// Subsystem: sound | Size: 26 bytes


undefined2 __cdecl16near FUN_3f2b_11a0(uint param_1)

{
  undefined2 unaff_ES;
  
  if (param_1 < *(uint *)0x0) {
    *(uint *)0x2 = param_1;
    return 0;
  }
  return 0xffff;
}

