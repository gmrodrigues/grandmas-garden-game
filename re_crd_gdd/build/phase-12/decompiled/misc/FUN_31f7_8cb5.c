// TIM2.EXE: FUN_31f7_8cb5 @ file 0x03FE25 Ghidra 0x3AC25
// Subsystem: misc | Size: 58 bytes


undefined2 __cdecl16far FUN_31f7_8cb5(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(int *)(iVar1 + 0xa2) == 0) || (*(int *)(iVar1 + 0xa2) == 3)) {
    *(undefined2 *)(*(int *)(iVar1 + 0x9a) + 0x16) = 1;
  }
  return 1;
}

