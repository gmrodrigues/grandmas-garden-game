// TIM2.EXE: FUN_1a9e_5d02 @ file 0x0258E2 Ghidra 0x206E2
// Subsystem: level | Size: 19 bytes


uint FUN_1a9e_5d02(undefined2 param_1)

{
  uint in_AX;
  uint uVar1;
  uint in_DX;
  uint *in_stack_00000000;
  
  if ((*in_stack_00000000 & 0xfe) != 0xf6) {
    in_stack_00000000 = in_stack_00000000 + -1;
  }
  if ((*in_stack_00000000 & 1) == 0) {
    uVar1 = (int)in_AX >> 1;
  }
  else {
    uVar1 = in_AX >> 1 | (uint)((in_DX & 1) != 0) << 0xf;
  }
  return uVar1;
}

