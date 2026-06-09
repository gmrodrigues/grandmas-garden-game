// TIM2.EXE: FUN_31f7_29e0 @ file 0x039B50 Ghidra 0x34950
// Subsystem: misc | Size: 99 bytes


undefined2 __cdecl16far FUN_31f7_29e0(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(int *)(*(int *)(iVar1 + 0x9a) + 0x16) == 0) && (*(int *)(iVar1 + 0xa0) == 0)) {
    *(undefined2 *)(*(int *)(iVar1 + 0x9a) + 0x16) = 1;
  }
  return 1;
}

