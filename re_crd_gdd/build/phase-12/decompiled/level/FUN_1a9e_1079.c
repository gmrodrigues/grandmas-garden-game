// TIM2.EXE: FUN_1a9e_1079 @ file 0x020C59 Ghidra 0x1BA59
// Subsystem: level | Size: 36 bytes


undefined2 __cdecl16far FUN_1a9e_1079(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_1a9e_03bd(param_1);
  if (iVar1 == 0) {
    return 0xffff;
  }
  return *(undefined2 *)(DAT_5b41_0042 + 0x12);
}

