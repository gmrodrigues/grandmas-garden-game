// TIM2.EXE: FUN_31f7_1e64 @ file 0x038FD4 Ghidra 0x33DD4
// Subsystem: misc | Size: 84 bytes


undefined2 __cdecl16far FUN_31f7_1e64(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0xa2);
  if ((*(byte *)(*(int *)(iVar2 + 0x9a) + 0xc) & 0x10) != 0) {
    iVar1 = (*(int *)(iRam000557e2 + 0x22) - iVar1) + -2;
    if (iVar1 < 0) {
      iVar1 = iVar1 + *(int *)(iRam000557e2 + 0x22);
    }
  }
  if ((iVar1 == 0) || (iVar1 == 2)) {
    *(undefined2 *)(*(int *)(iVar2 + 0x9a) + 0x16) = 1;
  }
  return 1;
}

