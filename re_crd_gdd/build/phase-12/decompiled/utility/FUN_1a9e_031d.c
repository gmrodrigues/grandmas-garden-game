// TIM2.EXE: FUN_1a9e_031d @ file 0x01FEFD Ghidra 0x1ACFD
// Subsystem: utility | Size: 78 bytes


undefined2 __cdecl16near FUN_1a9e_031d(undefined1 param_1)

{
  byte bVar1;
  
  if (DAT_5b41_02e7 != 0) {
    if ((DAT_5b41_02e9 & 0x40) != 0) {
      *DAT_5b41_0049 = param_1;
    }
    FUN_1000_1a00(0x1a9e);
    DAT_5b41_02e7 = DAT_5b41_02e7 + -1;
    return 1;
  }
  bVar1 = *(byte *)(DAT_5b41_0042 + 0x1a);
  *(char *)(DAT_5b41_0042 + 0x1a) = *(char *)(DAT_5b41_0042 + 0x1a) + '\x01';
  *(undefined1 *)((uint)bVar1 + DAT_5b41_0044) = param_1;
  return 0;
}

