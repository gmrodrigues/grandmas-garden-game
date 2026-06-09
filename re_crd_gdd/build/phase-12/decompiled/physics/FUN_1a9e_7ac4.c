// TIM2.EXE: FUN_1a9e_7ac4 @ file 0x0276A4 Ghidra 0x224A4
// Subsystem: physics | Size: 270 bytes


int __cdecl16far FUN_1a9e_7ac4(undefined2 param_1)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  int extraout_DX;
  undefined2 extraout_DX_00;
  int iVar6;
  uint local_14;
  int local_12;
  int iStack_10;
  undefined2 local_e;
  uint uStack_c;
  uint local_a;
  int local_8;
  int local_6;
  int local_4;
  
  local_12 = 0x140;
  local_14 = 200;
  func_0x0002cb02(0x1a9e);
  local_8 = 0;
  iVar6 = extraout_DX;
  iVar2 = FUN_1a9e_6ea7(param_1);
  if (iVar2 == 0) {
    local_6 = 1;
    param_1 = FUN_1a9e_69e9(param_1);
  }
  else {
    local_6 = 0;
  }
  iVar2 = FUN_1a9e_6a85(param_1,0x5618,0);
  if ((iVar6 != -1) || (iVar2 != -1)) {
    FUN_1000_0d10(&local_12,1,2,param_1);
    FUN_1000_0d10(&local_14,1,2,param_1);
  }
  iVar2 = FUN_1a9e_6a85(param_1,0x5621,0);
  if ((iVar6 != -1) || (iVar2 != -1)) {
    uVar3 = FUN_1a9e_6e3d(param_1);
    local_4 = FUN_28eb_2779(0,param_1,0x562a,uVar3,iVar6);
    if (-1 < local_4) {
      uVar4 = local_12 >> 1;
      local_a = uVar4 << 7;
      iVar6 = iStack_10;
      do {
        iStack_10 = iVar6;
        iStack_10 = FUN_1000_127a(local_a);
        local_e = 0x554c;
        if (iStack_10 != 0) break;
        local_a = local_a >> 1;
        iVar6 = 0;
      } while (uVar4 <= local_a);
      if (iStack_10 != 0) {
        iVar6 = 0;
        uVar5 = local_a / uVar4;
        lVar1 = CONCAT22(local_a % uVar4,local_a);
        if ((int)local_14 < (int)(local_a / uVar4)) {
          uVar5 = local_14;
          lVar1 = CONCAT22(local_a % uVar4,local_a);
        }
        while( true ) {
          iVar2 = (int)((ulong)lVar1 >> 0x10);
          uStack_c = (uint)lVar1;
          if ((int)local_14 <= iVar6) break;
          FUN_28eb_2aad(local_4,iStack_10,local_e,uStack_c);
          func_0x0002ea8b(0x1000,iStack_10,local_e,0,iVar6,uVar4 << 1,uVar5);
          lVar1 = CONCAT22(extraout_DX_00,uStack_c);
          iVar6 = iVar6 + uVar5;
          if ((int)local_14 < (int)(iVar6 + uVar5)) {
            uVar5 = local_14 - iVar6;
            lVar1 = (long)(int)uVar5 * (long)(int)uVar4;
          }
        }
        local_8 = 1;
        if (DAT_554c_42df != '\0') {
          FUN_28eb_29db(local_4);
          iVar6 = FUN_1a9e_6a85(param_1,0x562c,0);
          if ((iVar2 == -1) && (iVar6 == -1)) {
            iVar6 = FUN_1a9e_6a85(param_1,0x5635,0);
            if ((iVar2 != -1) || (iVar6 != -1)) {
              local_8 = 6;
            }
          }
          else {
            local_8 = 5;
          }
          if (4 < local_8) {
            uVar3 = FUN_1a9e_6e3d(param_1);
            local_4 = FUN_28eb_2779(0,param_1,0x563e,uVar3,iVar2);
            if (-1 < local_4) {
              iVar6 = 0;
              uVar5 = local_a / uVar4;
              if (local_8 == 6) {
                local_a = local_a >> 2;
              }
              uStack_c = local_a;
              if ((int)local_14 < (int)uVar5) {
                uVar5 = local_14;
              }
              while (iVar6 < (int)local_14) {
                FUN_28eb_2aad(local_4,iStack_10,local_e,uStack_c);
                if (local_8 == 6) {
                  FUN_1a9e_836a(iStack_10,local_e,iStack_10,local_e,uStack_c);
                }
                func_0x0002ea8f(0x1000,iStack_10,local_e,0,iVar6,uVar4 << 1,uVar5);
                iVar6 = iVar6 + uVar5;
                if ((int)local_14 < (int)(iVar6 + uVar5)) {
                  uVar5 = local_14 - iVar6;
                  uStack_c = uVar5 * uVar4;
                  if (local_8 == 6) {
                    uStack_c = uStack_c >> 2;
                  }
                }
              }
            }
          }
        }
        FUN_1000_130c(iStack_10);
      }
      FUN_28eb_29db(local_4);
    }
  }
  if (local_6 != 0) {
    FUN_1a9e_6e73(param_1);
  }
  return local_8;
}

