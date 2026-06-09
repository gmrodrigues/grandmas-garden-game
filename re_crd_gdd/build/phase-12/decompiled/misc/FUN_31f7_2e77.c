// TIM2.EXE: FUN_31f7_2e77 @ file 0x039FE7 Ghidra 0x34DE7
// Subsystem: misc | Size: 79 bytes


undefined2 __cdecl16far FUN_31f7_2e77(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0xa2);
  if ((*(byte *)(*(int *)(iVar2 + 0x9a) + 0xc) & 0x10) != 0) {
    iVar1 = (*(int *)(iRam000557f4 + 0x22) - iVar1) + -2;
    if (iVar1 < 0) {
      iVar1 = iVar1 + *(int *)(iRam000557f4 + 0x22);
    }
  }
  if (iVar1 == 0) {
    *(undefined2 *)(*(int *)(iVar2 + 0x9a) + 0x16) = 1;
  }
  return 1;
}

