// TIM2.EXE: FUN_1a9e_76bf @ file 0x02729F Ghidra 0x2209F
// Subsystem: physics | Size: 161 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_1a9e_76bf(int param_1)

{
  int iVar1;
  
  if (DAT_5b41_2831 != 0) {
    if (param_1 < 0) {
      *_DAT_5b41_2837 = (byte)-param_1 & 0x3f;
      _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
      iVar1 = (int)(-param_1 & 0x1c0U) >> 6;
      if (iVar1 != 0) {
        *_DAT_5b41_2837 = (byte)iVar1;
        _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
      }
      while( true ) {
        DAT_5b41_2831 = DAT_5b41_2831 + -1;
        if (DAT_5b41_2831 == 0) break;
        *_DAT_5b41_2837 = 0;
        _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
      }
      return;
    }
    while (DAT_5b41_2831 != 0) {
      DAT_5b41_2831 = DAT_5b41_2831 + -1;
      *_DAT_5b41_2837 = 0;
      _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
    }
    DAT_5b41_2831 = 0;
  }
  for (; 0x3f < param_1; param_1 = param_1 + -0x3f) {
    *_DAT_5b41_2837 = 0x7f;
    _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
  }
  *_DAT_5b41_2837 = (byte)param_1 | 0x40;
  _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
  return;
}

