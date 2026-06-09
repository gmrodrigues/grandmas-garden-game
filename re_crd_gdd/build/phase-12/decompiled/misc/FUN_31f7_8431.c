// TIM2.EXE: FUN_31f7_8431 @ file 0x03F5A1 Ghidra 0x3A3A1
// Subsystem: misc | Size: 38 bytes


void __cdecl16far FUN_31f7_8431(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x16) != 0) {
    *(undefined2 *)(iVar1 + 0x16) = 4;
  }
  *(undefined2 *)(iVar1 + 0x9c) = 0;
  *(undefined2 *)(iVar1 + 0x9a) = 0;
  return;
}

