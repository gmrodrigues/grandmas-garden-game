// TIM2.EXE: FUN_1a9e_0083 @ file 0x01FC63 Ghidra 0x1AA63
// Subsystem: utility | Size: 71 bytes


undefined2 __cdecl16near FUN_1a9e_0083(void)

{
  int iVar1;
  undefined2 local_4;
  
  iVar1 = DAT_5b41_0044;
  for (local_4 = (uint)*(byte *)(DAT_5b41_0042 + 0x1b); *(byte *)(DAT_5b41_0042 + 0x1a) != local_4;
      local_4 = local_4 + 1 & 0x7f) {
    FUN_1a9e_036b(*(undefined1 *)(local_4 + iVar1));
  }
  *(undefined1 *)(DAT_5b41_0042 + 0x1b) = (undefined1)local_4;
  return 0;
}

