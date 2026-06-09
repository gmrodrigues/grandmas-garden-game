// TIM2.EXE: FUN_1000_1a5f @ file 0x016C5F Ghidra 0x11A5F
// Subsystem: utility | Size: 38 bytes


void __cdecl16far FUN_1000_1a5f(void)

{
  uint in_AX;
  char in_CL;
  int in_DX;
  uint in_BX;
  undefined2 unaff_ES;
  uint *in_stack_00000000;
  
  if (in_BX < in_AX) {
    in_DX = in_DX + -0x1000;
  }
  *in_stack_00000000 = in_BX - in_AX & 0xf;
  in_stack_00000000[1] = in_DX + (uint)(byte)(in_CL << 4) * -0x100 + (in_BX - in_AX >> 4);
  return;
}

