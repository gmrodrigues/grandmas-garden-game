// TIM2.EXE: FUN_1a9e_5ad4 @ file 0x0256B4 Ghidra 0x204B4
// Subsystem: level | Size: 20 bytes


undefined4 __cdecl16near FUN_1a9e_5ad4(void)

{
  uint in_AX;
  uint in_CX;
  int in_DX;
  uint in_BX;
  
  return CONCAT22(in_DX + (-(uint)CARRY2(in_AX,in_BX) & 0x1000) + (in_CX >> 5 | in_CX << 0xc),
                  in_AX + in_BX);
}

