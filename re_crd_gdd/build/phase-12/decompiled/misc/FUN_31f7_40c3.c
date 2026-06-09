// TIM2.EXE: FUN_31f7_40c3 @ file 0x03B233 Ghidra 0x36033
// Subsystem: misc | Size: 75 bytes


undefined2 __cdecl16far FUN_31f7_40c3(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(byte *)(*(int *)(iVar1 + 0x9a) + 0xc) & 0x10) == 0) {
    if (*(int *)(iVar1 + 0xa0) != -0x4000) {
      return 1;
    }
  }
  else if (*(int *)(iVar1 + 0xa0) != 0x4000) {
    return 1;
  }
  *(undefined2 *)(*(int *)(iVar1 + 0x9a) + 0x16) = 1;
  return 1;
}

