// TIM2.EXE: FUN_31f7_093d @ file 0x037AAD Ghidra 0x328AD
// Subsystem: misc | Size: 46 bytes


undefined2 __cdecl16far FUN_31f7_093d(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 8) == 0x14) {
    *(undefined2 *)(*(int *)(iVar1 + 0x9a) + 0x16) = 1;
  }
  return 1;
}

