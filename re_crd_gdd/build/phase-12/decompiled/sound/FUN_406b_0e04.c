// TIM2.EXE: FUN_406b_0e04 @ file 0x0466B4 Ghidra 0x414B4
// Subsystem: sound | Size: 27 bytes


void __cdecl16far FUN_406b_0e04(int param_1)

{
  code *pcVar1;
  
  if ((0 < param_1) && (param_1 < 0x20)) {
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
  }
  return;
}

