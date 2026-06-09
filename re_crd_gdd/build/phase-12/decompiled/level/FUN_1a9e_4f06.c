// TIM2.EXE: FUN_1a9e_4f06 @ file 0x024AE6 Ghidra 0x1F8E6
// Subsystem: level | Size: 658 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far FUN_1a9e_4f06(byte param_1,int param_2,int param_3)

{
  int iVar1;
  code *local_1a;
  code *local_18;
  int local_16;
  uint local_14;
  uint local_12;
  byte local_f;
  char local_e;
  byte local_d;
  uint local_c;
  uint local_a;
  byte local_7;
  undefined4 local_6;
  
  local_7 = DAT_554c_42c0;
  local_16 = (uint)param_1 - (uint)(byte)DAT_554c_431c;
  if ((-1 < local_16) && (local_16 < (int)(uint)(byte)DAT_554c_4330)) {
    if ((DAT_5b41_25c2 & 1) == 0) {
      if (DAT_5b41_25c2 == 2) {
        local_12 = (uint)(byte)DAT_554c_42f4;
        local_6 = (byte *)CONCAT22(DAT_5b41_25d8,
                                   (byte *)(DAT_5b41_25d6 +
                                           local_16 * local_12 * (uint)(byte)DAT_554c_4308));
      }
      else {
        local_12 = (uint)(byte)DAT_554c_42f4;
        local_6 = (byte *)CONCAT22(DAT_5b41_25d8,
                                   (byte *)(DAT_5b41_25d6 +
                                           (local_12 + 7 >> 3) * local_16 *
                                           (uint)(byte)DAT_554c_4308));
      }
    }
    else {
      local_12 = (uint)*(byte *)((int)_DAT_5b41_2626 + local_16);
      local_6 = (byte *)CONCAT22(DAT_5b41_25d8,
                                 (byte *)(DAT_5b41_25d6 +
                                         *(int *)((int)_DAT_5b41_2676 + local_16 * 2)));
    }
    local_14 = (uint)(byte)DAT_554c_4308;
    if ((((param_2 < DAT_554c_42c4) || (param_3 < DAT_554c_42c8)) ||
        (DAT_554c_42c6 < param_2 + local_12)) || (DAT_554c_42ca < param_3 + local_14)) {
      local_18 = (code *)0x1a9e;
      local_1a = (code *)((char *)s_Cross_device_link_554c_5d81 + 0x11);
    }
    else {
      local_18 = (code *)DAT_554c_4dd0;
      local_1a = DAT_554c_4dce;
    }
    local_e = DAT_5b41_25c2 < 2;
    if ((DAT_554c_42c2 & 4) != 0) {
      param_2 = param_2 + (uint)((byte)DAT_554c_4308 >> 1);
    }
    for (local_c = 0; local_c < local_14; local_c = local_c + 1) {
      if ((DAT_554c_42c2 & 1) == 0) {
        DAT_554c_42ce = DAT_554c_42c1;
        func_0x00010102(0x1a9e,param_2,param_3,param_2 + local_12,param_3);
      }
      local_d = 0x80;
      local_a = 0;
      while( true ) {
        if (local_12 <= local_a) break;
        if (local_e == '\0') {
          local_f = *local_6;
          if ((local_f != 0) && (DAT_554c_42c0 = local_f, local_f < 5)) {
            DAT_554c_42c0 = *(byte *)(local_f + 0x5156);
          }
          if (local_a < local_12 - 1) {
            local_6 = (byte *)CONCAT22(local_6._2_2_,(byte *)local_6 + 1);
          }
        }
        else {
          if (local_d == 0) {
            local_d = 0x80;
            local_6 = (byte *)CONCAT22(local_6._2_2_,(byte *)local_6 + 1);
          }
          local_f = *local_6 & local_d;
          local_d = local_d >> 1;
        }
        iVar1 = param_2 + local_a;
        if (local_f == 0) {
          if (((DAT_554c_42c2 & 8) != 0) && (DAT_5b41_26c6 == local_c)) {
            (*local_1a)(0x1a9e,iVar1,param_3,local_7);
          }
        }
        else if ((DAT_554c_42c2 & 0x10) == 0) {
          (*local_1a)(0x1a9e,iVar1,param_3,(int)(char)DAT_554c_42c0);
          if ((DAT_554c_42c2 & 2) != 0) {
            (*local_1a)(0x1a9e,iVar1 + 1,param_3,(int)(char)DAT_554c_42c0);
          }
        }
        else if ((iVar1 + param_3 & 1U) == 0) {
          if ((DAT_554c_42c2 & 2) != 0) {
            (*local_1a)(0x1a9e,iVar1 + 1,param_3,(int)(char)DAT_554c_42c0);
          }
        }
        else {
          (*local_1a)(0x1a9e,iVar1,param_3,(int)(char)DAT_554c_42c0);
        }
        local_a = local_a + 1;
      }
      if (((DAT_554c_42c2 & 4) != 0) && ((local_c & 1) != 0)) {
        param_2 = param_2 + -1;
      }
      param_3 = param_3 + 1;
      local_6 = (byte *)CONCAT22(local_6._2_2_,(byte *)local_6 + 1);
    }
    DAT_554c_42c0 = local_7;
    return local_12;
  }
  return 0;
}

