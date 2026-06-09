// TIM2.EXE: FUN_1a9e_7768 @ file 0x027348 Ghidra 0x22148
// Subsystem: physics | Size: 132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_1a9e_7768(byte param_1,int param_2)

{
  int iVar1;
  
  *_DAT_5b41_2837 = param_1 | 0xc0;
  _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
  if ((param_1 & 1) != 0) {
    *(undefined1 *)((uint)param_1 + param_2) = 0;
    param_1 = param_1 + 1;
  }
  if (DAT_5b41_282e == '\x0f') {
    for (iVar1 = 0; iVar1 < (int)(uint)param_1; iVar1 = iVar1 + 2) {
      *_DAT_5b41_2837 = *(char *)(iVar1 + param_2) << 4 | *(byte *)(iVar1 + param_2 + 1);
      _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
    }
    return;
  }
  for (iVar1 = 0; iVar1 < (int)(uint)param_1; iVar1 = iVar1 + 1) {
    *_DAT_5b41_2837 = *(byte *)(iVar1 + param_2);
    _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
  }
  return;
}

