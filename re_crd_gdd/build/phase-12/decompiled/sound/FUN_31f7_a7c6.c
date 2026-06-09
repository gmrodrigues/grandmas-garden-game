// TIM2.EXE: FUN_31f7_a7c6 @ file 0x041936 Ghidra 0x3C736
// Subsystem: sound | Size: 82 bytes


undefined2 __cdecl16far FUN_31f7_a7c6(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 8) == 0x6d) {
    if ((*(byte *)(iVar1 + 0xc) & 0x10) == 0) {
      *(undefined2 *)(iVar1 + 0x16) = 4;
    }
    else {
      *(undefined2 *)(iVar1 + 0x16) = 3;
    }
  }
  else if (*(int *)(iVar1 + 8) == 0x14) {
    *(undefined2 *)(*(int *)(iVar1 + 0x9a) + 0x16) = 2;
  }
  return 1;
}

