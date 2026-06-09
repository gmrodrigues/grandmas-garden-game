// TIM2.EXE: FUN_1a9e_610c @ file 0x025CEC Ghidra 0x20AEC
// Subsystem: level | Size: 1866 bytes


void __cdecl16far
FUN_1a9e_610c(undefined2 *param_1,int param_2,int param_3,uint param_4,uint param_5,uint param_6)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  char *pcVar8;
  undefined2 uVar9;
  bool bVar10;
  char local_174 [320];
  int local_34;
  int local_32;
  int local_30;
  uint local_2e;
  uint local_2c;
  uint local_2a;
  uint local_28;
  uint local_26;
  byte local_24;
  char local_23;
  uint local_22;
  undefined2 local_20;
  undefined2 local_1e;
  char local_1c;
  char local_1b;
  char *local_1a;
  int local_18;
  int local_16;
  int local_14;
  uint local_12;
  byte *local_10;
  undefined2 local_e;
  undefined4 local_c;
  int local_8;
  uint local_6;
  uint local_4;
  
  if ((param_5 == 0) || (param_6 == 0)) {
    return;
  }
  if ((int)param_5 < 0) {
    param_5 = (param_5 ^ (int)param_5 >> 0xf) - ((int)param_5 >> 0xf);
    param_2 = param_2 - param_5;
    param_4 = param_4 ^ 2;
  }
  if ((int)param_6 < 0) {
    param_6 = (param_6 ^ (int)param_6 >> 0xf) - ((int)param_6 >> 0xf);
    param_3 = param_3 - param_6;
    param_4 = param_4 ^ 1;
  }
  local_20 = DAT_554c_42d8;
  local_1c = DAT_554c_42c3;
  if ((((DAT_554c_42c3 != '\0') && (DAT_554c_42c4 <= param_2)) &&
      ((int)(param_2 + param_5) <= DAT_554c_42c6)) &&
     ((DAT_554c_42c8 <= param_3 && ((int)(param_3 + param_6) <= DAT_554c_42ca)))) {
    local_1c = '\0';
  }
  if ((param_4 & 2) != 0) {
    param_2 = param_2 + (param_5 - 1);
  }
  local_2a = 0;
  local_26 = param_5;
  FUN_2e67_0423(&local_2c,param_1[3]);
  local_12 = 0;
  for (local_16 = 0; local_16 <= (int)param_1[3]; local_16 = local_16 + 1) {
    local_22 = param_5;
    if ((int)local_2a < (int)param_5) {
      local_22 = local_2a;
    }
    ((undefined2 *)&DAT_5b41_20c2)[local_16] = local_22;
    bVar10 = CARRY2(local_2c,local_28);
    local_2c = local_2c + local_28;
    local_2a = local_2a + local_26 + (uint)bVar10;
    for (; local_12 < local_22; local_12 = local_12 + 1) {
      *(int *)(local_12 * 2 + 0x7cf2) = local_16 + -1;
    }
  }
  local_2e = 0;
  if ((param_4 & 1) == 0) {
    local_14 = 1;
  }
  else {
    local_14 = -1;
    param_3 = param_3 + (param_6 - 1);
  }
  if (local_1c != '\0') {
    if ((DAT_554c_42ca < param_3) || (param_3 < DAT_554c_42c8)) {
      local_1b = '\0';
    }
    else {
      local_1b = '\x01';
    }
    if (local_1b == '\0') goto LAB_1a9e_625e;
  }
  local_1e = *(undefined2 *)(param_3 * 2 + 0x49b2);
LAB_1a9e_625e:
  local_e = *param_1;
  local_c = (byte *)CONCAT22(local_e,(char *)param_1[1]);
  local_23 = *local_c;
  local_10 = (byte *)((char *)param_1[1] + 1);
  local_c = (byte *)CONCAT22(local_e,local_10);
  local_32 = param_2;
  local_30 = param_2;
  DAT_5b41_26dc = 0;
  local_34 = 0;
  DAT_5b41_26da = DAT_5b41_20c2;
  local_2a = 0;
  local_26 = param_1[4] + -1;
  FUN_2e67_0423(&local_2c,param_6 - 1);
LAB_1a9e_62c7:
  do {
    while( true ) {
      bVar2 = *local_c;
      local_4 = (uint)bVar2;
      local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
      if ((bVar2 & 0x80) == 0) break;
      if ((bVar2 & 0x40) == 0) {
        local_4 = local_4 & 0x3f;
        local_6 = FUN_1a9e_60f0(local_4);
        DAT_5b41_26dc = DAT_5b41_26dc + local_4;
        local_24 = *local_c;
        local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
        if ((param_4 & 2) != 0) {
          local_16 = param_2 - local_6;
          if (local_1c != '\0') {
            if (local_1b == '\0') goto LAB_1a9e_65ea;
            if ((local_16 < DAT_554c_42c4) || (DAT_554c_42c6 <= param_2)) {
              if (local_16 < DAT_554c_42c4) {
                local_18 = DAT_554c_42c4 - local_16;
                uVar6 = local_6 - local_18;
                bVar10 = local_18 <= (int)local_6;
                local_6 = uVar6;
                if (uVar6 != 0 && bVar10) goto LAB_1a9e_650e;
              }
              else {
                local_18 = param_2 - DAT_554c_42c6;
                uVar6 = local_6 - local_18;
                bVar10 = local_18 <= (int)local_6;
                local_6 = uVar6;
                if (uVar6 != 0 && bVar10) goto LAB_1a9e_650e;
              }
              goto LAB_1a9e_65ea;
            }
          }
LAB_1a9e_650e:
          (*DAT_554c_4d9e)(0x1a9e);
          goto LAB_1a9e_65ea;
        }
        local_16 = param_2 + local_6;
        if (local_1c == '\0') {
LAB_1a9e_659b:
          (*DAT_554c_4d9e)(0x1a9e);
        }
        else {
          if (local_1b == '\0') goto LAB_1a9e_65ea;
          if ((DAT_554c_42c4 <= param_2) && (local_16 <= DAT_554c_42c6)) goto LAB_1a9e_659b;
          if (param_2 < DAT_554c_42c4) {
            local_18 = DAT_554c_42c4 - param_2;
            uVar6 = local_6 - local_18;
            bVar10 = local_18 <= (int)local_6;
            local_6 = uVar6;
            if (uVar6 != 0 && bVar10) goto LAB_1a9e_659b;
          }
          else {
            local_18 = (local_16 - DAT_554c_42c6) + -1;
            uVar6 = local_6 - local_18;
            bVar10 = local_18 <= (int)local_6;
            local_6 = uVar6;
            if (uVar6 != 0 && bVar10) goto LAB_1a9e_659b;
          }
        }
LAB_1a9e_65ea:
        param_2 = local_16;
      }
      else {
        local_6 = local_4 & 0x3f;
        local_4 = local_6;
        uVar6 = FUN_1a9e_60f0(local_6);
        cVar3 = local_23;
        local_6 = uVar6;
        if (local_4 != 0) {
          local_22 = ((undefined2 *)&DAT_5b41_20c2)[DAT_5b41_26dc];
          local_12 = *(uint *)(local_22 * 2 + 0x7cf2);
          pcVar8 = local_174;
          iVar7 = local_22 << 1;
          if (0 < (int)uVar6) {
            do {
              while( true ) {
                uVar9 = (undefined2)((ulong)local_c >> 0x10);
                uVar4 = *(int *)(iVar7 + 0x7cf2) - local_12;
                uVar5 = uVar4 >> 1;
                if ((uVar4 & 1) == 0) break;
                pcVar1 = pcVar8;
                pcVar8 = pcVar8 + 1;
                *pcVar1 = (((byte *)local_c)[uVar5] & 0xf) + cVar3;
                iVar7 = iVar7 + 2;
                uVar6 = uVar6 - 1;
                if (uVar6 == 0) goto LAB_1a9e_6371;
              }
              pcVar1 = pcVar8;
              pcVar8 = pcVar8 + 1;
              *pcVar1 = (((byte *)local_c)[uVar5] >> 4) + cVar3;
              iVar7 = iVar7 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
LAB_1a9e_6371:
          local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + ((int)(local_4 + 1) >> 1));
        }
        DAT_5b41_26dc = DAT_5b41_26dc + local_4;
        if (local_6 != 0) {
          local_1a = local_174;
          if ((param_4 & 2) != 0) {
            local_16 = param_2 - local_6;
            if (local_1c != '\0') {
              if (local_1b == '\0') goto LAB_1a9e_64ac;
              if ((local_16 < DAT_554c_42c4) || (DAT_554c_42c6 <= param_2)) {
                if (local_16 < DAT_554c_42c4) {
                  local_18 = DAT_554c_42c4 - local_16;
                  uVar6 = local_6 - local_18;
                  bVar10 = local_18 <= (int)local_6;
                  local_6 = uVar6;
                  if (uVar6 != 0 && bVar10) goto LAB_1a9e_63c8;
                }
                else {
                  local_18 = param_2 + DAT_554c_42c6;
                  uVar6 = local_6 - local_18;
                  bVar10 = local_18 <= (int)local_6;
                  local_6 = uVar6;
                  if (uVar6 != 0 && bVar10) {
                    local_1a = local_1a + local_18;
                    goto LAB_1a9e_63c8;
                  }
                }
                goto LAB_1a9e_64ac;
              }
            }
LAB_1a9e_63c8:
            (*DAT_554c_4e0e)(0x1a9e,unaff_DI,unaff_SI);
            goto LAB_1a9e_64ac;
          }
          local_16 = param_2 + local_6;
          if (local_1c == '\0') {
LAB_1a9e_6455:
            (*DAT_554c_4e0e)(0x1a9e);
          }
          else {
            if (local_1b == '\0') goto LAB_1a9e_64ac;
            if ((DAT_554c_42c4 <= param_2) && (local_16 <= DAT_554c_42c6)) goto LAB_1a9e_6455;
            if (param_2 < DAT_554c_42c4) {
              local_18 = DAT_554c_42c4 - param_2;
              uVar6 = local_6 - local_18;
              bVar10 = local_18 <= (int)local_6;
              local_6 = uVar6;
              if (uVar6 != 0 && bVar10) {
                local_1a = local_1a + local_18;
                goto LAB_1a9e_6455;
              }
            }
            else {
              local_18 = (local_16 - DAT_554c_42c6) + -1;
              uVar6 = local_6 - local_18;
              bVar10 = local_18 <= (int)local_6;
              local_6 = uVar6;
              if (uVar6 != 0 && bVar10) goto LAB_1a9e_6455;
            }
          }
LAB_1a9e_64ac:
          param_2 = local_16;
        }
      }
    }
    if ((bVar2 & 0x40) == 0) {
      local_4 = local_4 & 0x3f;
      uVar6 = FUN_1a9e_60f0(-local_4);
      local_6 = (uVar6 ^ (int)uVar6 >> 0xf) - ((int)uVar6 >> 0xf);
      DAT_5b41_26dc = DAT_5b41_26dc - local_4;
      uVar6 = local_6;
      if ((param_4 & 2) == 0) {
        uVar6 = -local_6;
      }
      param_2 = param_2 + uVar6;
      bVar2 = *local_c;
      local_4 = (uint)bVar2;
      if (((bVar2 & 0xc0) == 0) && (local_12 = local_4 & 0x3f, (bVar2 & 0x3f) != 0)) {
        local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
        local_12 = local_12 << 6;
        local_6 = FUN_1a9e_60f0(local_12);
        DAT_5b41_26dc = DAT_5b41_26dc - local_12;
        if ((param_4 & 2) == 0) {
          param_2 = param_2 - local_6;
        }
        else {
          param_2 = param_2 + local_6;
        }
      }
      bVar10 = CARRY2(local_2c,local_28);
      local_2c = local_2c + local_28;
      local_2a = local_2a + local_26 + (uint)bVar10;
      local_22 = local_2a;
      if (local_2e == local_2a) {
        local_c = (byte *)CONCAT22(local_e,local_10);
        param_2 = local_30;
        DAT_5b41_26dc = local_34;
      }
      else {
        uVar6 = (int)(local_2a - local_2e) >> 0xf;
        local_18 = ((local_2a - local_2e ^ uVar6) - uVar6) + -1;
        if (local_18 != 0) {
          while (local_18 != 0) {
            local_4 = (uint)*local_c;
            local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
            local_6 = local_4 & 0x3f;
            local_8 = FUN_1a9e_60f0(local_6);
            if ((param_4 & 2) != 0) {
              local_8 = -local_8;
            }
            if ((local_4 & 0x80) == 0) {
              if ((local_4 & 0x40) == 0) {
                DAT_5b41_26dc = DAT_5b41_26dc - local_6;
                param_2 = param_2 - local_8;
                bVar2 = *local_c;
                local_4 = (uint)bVar2;
                if (((bVar2 & 0xc0) == 0) && (local_12 = local_4 & 0x3f, (bVar2 & 0x3f) != 0)) {
                  local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
                  local_12 = local_12 << 6;
                  local_6 = FUN_1a9e_60f0(local_12);
                  DAT_5b41_26dc = DAT_5b41_26dc - local_12;
                  if ((param_4 & 2) == 0) {
                    param_2 = param_2 - local_6;
                  }
                  else {
                    param_2 = param_2 + local_6;
                  }
                }
                local_18 = local_18 + -1;
              }
              else {
                if (local_6 == 0) {
                  return;
                }
                DAT_5b41_26dc = DAT_5b41_26dc + local_6;
                param_2 = param_2 + local_8;
              }
            }
            else {
              DAT_5b41_26dc = DAT_5b41_26dc + local_6;
              if ((local_4 & 0x40) == 0) {
                param_2 = param_2 + local_8;
                local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
              }
              else {
                param_2 = param_2 + local_8;
                local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + ((int)(local_6 + 1) >> 1)
                                          );
              }
            }
          }
        }
      }
      local_e = local_c._2_2_;
      local_10 = (byte *)local_c;
      local_2e = local_22;
      local_30 = param_2;
      local_34 = DAT_5b41_26dc;
      param_6 = param_6 - 1;
      if (param_6 == 0) {
        return;
      }
      if ((param_4 & 2) == 0) {
        param_2 = ((undefined2 *)&DAT_5b41_20c2)[DAT_5b41_26dc];
      }
      else {
        param_2 = -((undefined2 *)&DAT_5b41_20c2)[DAT_5b41_26dc];
      }
      param_2 = local_32 + param_2;
      param_3 = param_3 + local_14;
      if (local_1c != '\0') break;
      goto LAB_1a9e_686e;
    }
    local_4 = local_4 & 0x3f;
    if ((bVar2 & 0x3f) == 0) {
      return;
    }
    local_6 = FUN_1a9e_60f0(local_4);
    DAT_5b41_26dc = DAT_5b41_26dc + local_4;
    if ((param_4 & 2) == 0) {
      param_2 = param_2 + local_6;
    }
    else {
      param_2 = param_2 - local_6;
    }
  } while( true );
  if ((DAT_554c_42ca < param_3) || (param_3 < DAT_554c_42c8)) {
    local_1b = '\0';
  }
  else {
    local_1b = '\x01';
  }
  if (local_1b != '\0') {
LAB_1a9e_686e:
    local_1e = *(undefined2 *)(param_3 * 2 + 0x49b2);
  }
  goto LAB_1a9e_62c7;
}

