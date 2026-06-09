// TIM2.EXE: FUN_460e_1a42 @ file 0x04CD22 Ghidra 0x47B22
// Subsystem: misc | Size: 125 bytes


undefined2 __cdecl16far FUN_460e_1a42(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_5408_0402 * 2;
  piVar1 = (int *)(iVar2 + 0x404);
  *piVar1 = *piVar1 + *(int *)(DAT_5408_0400 * 2 + 0x404);
  DAT_5408_0402 = DAT_5408_0402 + 1;
  if (DAT_5408_0402 == 0x38) {
    DAT_5408_0402 = 0;
  }
  DAT_5408_0400 = DAT_5408_0400 + 1;
  if (DAT_5408_0400 == 0x38) {
    DAT_5408_0400 = 0;
  }
  return *(undefined2 *)(iVar2 + 0x404);
}

