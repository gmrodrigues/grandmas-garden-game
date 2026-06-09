// TIM2.EXE: FUN_1000_19df @ file 0x016BDF Ghidra 0x119DF
// Subsystem: utility | Size: 30 bytes


uint __cdecl16far FUN_1000_19df(void)

{
  uint in_AX;
  byte in_CL;
  uint in_DX;
  
  if (in_CL < 0x10) {
    return in_AX >> (in_CL & 0x1f) | in_DX << (0x10 - in_CL & 0x1f);
  }
  return in_DX >> (in_CL - 0x10 & 0x1f);
}

