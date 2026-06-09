// TIM2.EXE: FUN_31f7_ac1b @ file 0x041D8B Ghidra 0x3CB8B
// Subsystem: sound | Size: 118 bytes


undefined2 __cdecl16far FUN_31f7_ac1b(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar3 + 0x9c);
  iVar2 = *(int *)(iVar3 + 0x9a);
  if (((*(int *)(iVar2 + 0x10) % 7 == 0) || (*(int *)(iVar2 + 0x10) % 7 == 6)) &&
     ((*(int *)(iVar3 + 0xa0) + *(int *)((*(int *)(iVar2 + 0x10) / 7) * 2 + 0x3cdc) & 0x8000U) == 0)
     ) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0xa8) + 1;
  }
  return 1;
}

