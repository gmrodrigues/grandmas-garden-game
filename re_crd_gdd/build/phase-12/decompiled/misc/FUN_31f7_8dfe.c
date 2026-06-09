// TIM2.EXE: FUN_31f7_8dfe @ file 0x03FF6E Ghidra 0x3AD6E
// Subsystem: misc | Size: 46 bytes


undefined2 __cdecl16far FUN_31f7_8dfe(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 8) == 0x14) {
    *(undefined2 *)(*(int *)(iVar1 + 0x9a) + 0x16) = 2;
  }
  return 1;
}

