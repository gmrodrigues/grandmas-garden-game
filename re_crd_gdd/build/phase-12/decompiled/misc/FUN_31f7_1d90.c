// TIM2.EXE: FUN_31f7_1d90 @ file 0x038F00 Ghidra 0x33D00
// Subsystem: misc | Size: 61 bytes


undefined2 __cdecl16far FUN_31f7_1d90(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  uVar1 = *(undefined2 *)((int)param_1 + 0x9c);
  iVar2 = *(int *)((int)param_1 + 0x9a);
  if (DAT_5b41_099f <= *(int *)(iVar2 + 0x10)) {
    return 1;
  }
  FUN_31f7_1e38(iVar2,uVar1);
  return 0;
}

