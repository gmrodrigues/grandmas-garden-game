// TIM2.EXE: FUN_1000_1a88 @ file 0x016C88 Ghidra 0x11A88
// Subsystem: utility | Size: 74 bytes


byte __cdecl16far FUN_1000_1a88(void)

{
  char in_AL;
  int in_CX;
  byte in_BL;
  
  if (in_CX < 0) {
    return in_AL - (~in_BL + 1) & 0xf;
  }
  return in_AL + in_BL & 0xf;
}

