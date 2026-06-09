// TIM2.EXE: FUN_1a9e_7911 @ file 0x0274F1 Ghidra 0x222F1
// Subsystem: physics | Size: 435 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_1a9e_7911(undefined2 *param_1)

{
  int iVar1;
  byte local_150 [320];
  byte *local_10;
  byte *local_c;
  byte local_a;
  byte local_9;
  int local_8;
  int local_6;
  int local_4;
  
  iVar1 = 0;
  local_8 = 0;
  local_9 = 0xff;
  DAT_5b41_2831 = 0;
  DAT_5b41_282f = 0;
  _DAT_5b41_283b = (byte *)CONCAT22(*param_1,(byte *)param_1[1]);
  if ((DAT_5b41_282e == 0xf) && (DAT_554c_42df != '\0')) {
    for (local_6 = 0; local_6 < (int)param_1[4]; local_6 = local_6 + 1) {
      for (local_4 = 0; local_4 < (int)param_1[3]; local_4 = local_4 + 1) {
        local_a = *_DAT_5b41_283b;
        _DAT_5b41_283b = (byte *)CONCAT22(DAT_5b41_283d,DAT_5b41_283b + 1);
        if ((local_a != 0) && (local_a < local_9)) {
          local_9 = local_a;
        }
      }
    }
  }
  else {
    local_9 = 1;
  }
  DAT_5b41_283d = *param_1;
  DAT_5b41_283b = (byte *)param_1[1];
  local_10 = _DAT_5b41_2837;
  _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
  for (local_6 = 0; local_6 < (int)param_1[4]; local_6 = local_6 + 1) {
    local_c = local_150;
    FUN_1a9e_5c0a(local_c);
    DAT_5b41_283b = (byte *)((int)DAT_5b41_283b + param_1[3]);
    for (local_4 = 0; local_4 < (int)param_1[3]; local_4 = local_4 + 1) {
      local_a = *local_c;
      local_c = local_c + 1;
      if (local_a == 0) {
        if (iVar1 != 0) {
          FUN_1a9e_77ec(DAT_5b41_283f,iVar1);
          iVar1 = 0;
        }
        local_8 = local_8 + 1;
      }
      else {
        local_a = local_a - local_9 & DAT_5b41_282e;
        *(byte *)(DAT_5b41_283f + iVar1) = local_a;
        iVar1 = iVar1 + 1;
        if (local_8 == 0) {
          if (DAT_5b41_2831 != 0) {
            while (DAT_5b41_2831 != 0) {
              DAT_5b41_2831 = DAT_5b41_2831 + -1;
              *_DAT_5b41_2837 = 0;
              _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
            }
            DAT_5b41_2831 = 0;
          }
        }
        else {
          FUN_1a9e_76bf(local_8);
          local_8 = 0;
        }
      }
    }
    if (iVar1 != 0) {
      FUN_1a9e_77ec(DAT_5b41_283f,iVar1);
      iVar1 = 0;
    }
    local_8 = local_8 - param_1[3];
    DAT_5b41_2831 = DAT_5b41_2831 + 1;
  }
  if (iVar1 != 0) {
    FUN_1a9e_77ec(DAT_5b41_283f,iVar1);
  }
  FUN_1a9e_76bf(0);
  *local_10 = local_9;
  return;
}

