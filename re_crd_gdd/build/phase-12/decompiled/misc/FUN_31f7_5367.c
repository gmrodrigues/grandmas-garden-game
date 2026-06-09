// TIM2.EXE: FUN_31f7_5367 @ file 0x03C4D7 Ghidra 0x372D7
// Subsystem: misc | Size: 24 bytes


void __cdecl16far FUN_31f7_5367(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x5a) = 0x1a;
  *(undefined1 *)(iVar1 + 0x5b) = 0x1a;
  *(undefined2 *)(iVar1 + 0x5c) = 3;
  return;
}

