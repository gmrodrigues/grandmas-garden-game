// TIM2.EXE: FUN_1a9e_77ec @ file 0x0273CC Ghidra 0x221CC
// Subsystem: physics | Size: 293 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_1a9e_77ec(byte *param_1,int param_2)

{
  byte *pbVar1;
  byte local_106 [257];
  byte local_5;
  byte local_4;
  byte local_3;
  
  local_4 = 0;
  local_5 = 0;
  while (0 < param_2) {
    local_4 = 1;
    local_3 = *param_1;
    pbVar1 = param_1;
    while (pbVar1 = pbVar1 + 1, *pbVar1 == local_3) {
      local_4 = local_4 + 1;
    }
    if ((int)(uint)local_4 < DAT_554c_5616) {
      param_2 = param_2 + -1;
      local_106[local_5] = local_3;
      local_5 = local_5 + 1;
      param_1 = param_1 + 1;
    }
    else {
      if (param_2 < (int)(uint)local_4) {
        local_4 = (byte)param_2;
      }
      if (local_5 != 0) {
        FUN_1a9e_7768(CONCAT11((char)((uint)local_106 >> 8),local_5),local_106);
        local_5 = 0;
      }
      param_2 = param_2 - (uint)local_4;
      param_1 = param_1 + local_4;
      while (0x3f < local_4) {
        local_4 = local_4 - 0x3f;
        *_DAT_5b41_2837 = 0xbf;
        _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
        *_DAT_5b41_2837 = local_3;
        _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
      }
      if (local_4 != 0) {
        *_DAT_5b41_2837 = local_4 | 0x80;
        _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
        *_DAT_5b41_2837 = local_3;
        _DAT_5b41_2837 = (byte *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
      }
      local_4 = 0;
    }
    if (local_5 == 0x3f) {
      FUN_1a9e_7768(CONCAT11((char)((uint)local_106 >> 8),0x3f),local_106);
      local_5 = 0;
    }
  }
  if (local_5 != 0) {
    FUN_1a9e_7768(CONCAT11((char)((uint)local_106 >> 8),local_5),local_106);
  }
  return;
}

