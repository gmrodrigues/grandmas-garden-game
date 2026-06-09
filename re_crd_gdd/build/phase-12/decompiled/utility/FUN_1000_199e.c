// TIM2.EXE: FUN_1000_199e @ file 0x016B9E Ghidra 0x1199E
// Subsystem: utility | Size: 30 bytes


int __cdecl16far FUN_1000_199e(void)

{
  int in_AX;
  byte in_CL;
  
  if (in_CL < 0x10) {
    return in_AX << (in_CL & 0x1f);
  }
  return 0;
}

