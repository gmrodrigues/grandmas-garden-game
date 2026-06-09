// TIM2.EXE: FUN_31f7_4fa7 @ file 0x03C117 Ghidra 0x36F17
// Subsystem: misc | Size: 47 bytes


void __cdecl16far FUN_31f7_4fa7(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x10) = 0;
  if (*(int *)(iVar1 + 0x6e) != 0 || *(int *)(iVar1 + 0x70) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
  }
  if (*(int *)(iVar1 + 0x72) != 0 || *(int *)(iVar1 + 0x74) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 2;
  }
  return;
}

