// TIM2.EXE: FUN_31f7_2b6a @ file 0x039CDA Ghidra 0x34ADA
// Subsystem: misc | Size: 35 bytes


void __cdecl16far FUN_31f7_2b6a(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x7a) = 0xe;
  if ((*(byte *)(iVar1 + 0xc) & 0x20) != 0) {
    *(undefined1 *)(iVar1 + 0x7b) = 8;
    return;
  }
  *(undefined1 *)(iVar1 + 0x7b) = 7;
  return;
}

