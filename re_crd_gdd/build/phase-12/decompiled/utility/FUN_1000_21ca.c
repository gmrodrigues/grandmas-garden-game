// TIM2.EXE: FUN_1000_21ca @ file 0x0173CA Ghidra 0x121CA
// Subsystem: utility | Size: 48 bytes


uint __cdecl16far FUN_1000_21ca(uint param_1)

{
  if (param_1 == 0xffff) {
    param_1 = 0xffff;
  }
  else if ((*(byte *)((param_1 & 0xff) + 0x59c1) & 4) == 0) {
    param_1 = param_1 & 0xff;
  }
  else {
    param_1 = (param_1 & 0xff) + 0x20;
  }
  return param_1;
}

