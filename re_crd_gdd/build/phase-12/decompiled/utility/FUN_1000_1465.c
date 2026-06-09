// TIM2.EXE: FUN_1000_1465 @ file 0x016665 Ghidra 0x11465
// Subsystem: utility | Size: 26 bytes


undefined2 __cdecl16far FUN_1000_1465(void)

{
  undefined2 uVar1;
  byte in_CL;
  int in_BX;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  iVar2 = in_BX << (in_CL & 0x1f);
  uVar1 = *(undefined2 *)(unaff_BP + 6);
  *(undefined2 *)(iVar2 + -0x782a) = *(undefined2 *)(unaff_BP + 8);
  *(undefined2 *)(iVar2 + -0x782c) = uVar1;
  DAT_554c_57c6 = DAT_554c_57c6 + 1;
  return 0;
}

