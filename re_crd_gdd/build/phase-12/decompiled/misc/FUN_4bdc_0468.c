// TIM2.EXE: FUN_4bdc_0468 @ file 0x051428 Ghidra 0x4C228
// Subsystem: misc | Size: 55 bytes


void __cdecl16far FUN_4bdc_0468(void)

{
  undefined2 in_AX;
  byte extraout_AH;
  undefined1 in_CL;
  undefined1 in_CH;
  undefined2 unaff_ES;
  
  uRam000401ed = in_AX;
  uRam000401ef = unaff_ES;
  (*pcRam000556ad)(0x4000);
  uRam00040205 = in_CL;
  uRam00040202 = in_CH;
  bRam00040206 = extraout_AH >> 4;
  if (DAT_554c_5756 != 0) {
    bRam00040206 = bRam00040206 | 1;
  }
  return;
}

