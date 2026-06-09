// TIM2.EXE: FUN_1000_1a44 @ file 0x016C44 Ghidra 0x11A44
// Subsystem: utility | Size: 27 bytes


void FUN_1000_1a44(void)

{
  uint *in_AX;
  int in_CX;
  undefined2 in_DX;
  uint uVar1;
  uint in_BX;
  uint uVar2;
  
  uVar1 = in_AX[1];
  if (in_CX < 0) {
    FUN_1000_1a1b();
    return;
  }
  uVar2 = *in_AX - in_BX;
  if (*in_AX < in_BX) {
    uVar1 = uVar1 - 0x1000;
  }
  *in_AX = uVar2 & 0xf;
  in_AX[1] = uVar1 + (uint)(byte)((char)in_CX << 4) * -0x100 + (uVar2 >> 4);
  return;
}

