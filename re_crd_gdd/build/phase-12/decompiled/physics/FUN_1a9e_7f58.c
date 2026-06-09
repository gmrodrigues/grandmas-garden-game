// TIM2.EXE: FUN_1a9e_7f58 @ file 0x027B38 Ghidra 0x22938
// Subsystem: physics | Size: 925 bytes


/* WARNING: Removing unreachable block (ram,0x0002298a) */

undefined2 __cdecl16far FUN_1a9e_7f58(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int extraout_DX;
  int extraout_DX_00;
  int iVar5;
  undefined2 uVar6;
  bool bVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  undefined2 uVar11;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_16;
  undefined1 local_14 [2];
  uint local_12;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  undefined2 local_4;
  
  uVar6 = 0x1a9e;
  local_1c = 0;
  local_4 = 0;
  local_8._2_2_ = 0;
  local_8._0_2_ = 0;
  local_10._2_2_ = 0;
  local_10._0_2_ = 0;
  local_12 = 0;
  iVar5 = 0;
  iVar1 = FUN_1a9e_6ea7(param_1);
  if (iVar1 == 0) {
    param_1 = FUN_1a9e_69e9(param_1);
  }
  iVar2 = FUN_1a9e_7d9a(param_1,local_14,&local_4);
  lVar10 = CONCAT22(local_8._2_2_,(undefined2)local_8);
  if (iVar2 != 0) {
    uVar8 = (*DAT_554c_4daa)(0x1a9e,local_4,&local_18);
    lVar9 = FUN_2fc8_00fc(0x1a9e,uVar8,0,0);
    local_8._2_2_ = (undefined2)((ulong)lVar9 >> 0x10);
    lVar10 = lVar9;
    if (lVar9 != 0) {
      if (local_18 != 0) {
        local_8 = lVar9;
        local_10 = FUN_2fc8_00fc(0x1a9e,local_18,local_18 >> 0xf,0,0);
        lVar9 = CONCAT22((int)((ulong)local_10 >> 0x10),(undefined2)local_8);
        lVar10 = local_8;
        if (local_10 == 0) goto LAB_1a9e_825f;
      }
      uVar3 = (undefined2)((ulong)lVar9 >> 0x10);
      local_8._0_2_ = (undefined2)lVar9;
      if (uRam00055622 == 0 && iRam00055624 == 0) {
        uVar6 = 0x1000;
        local_12 = FUN_1000_127a((undefined2 *)&DAT_554c_3cc4);
        lVar9 = CONCAT22(uVar3,(undefined2)local_8);
        if (local_12 != 0) {
          FUN_1000_130c(local_12);
          uVar11 = 0x3ac4;
          uVar6 = 0x1000;
          local_12 = FUN_1000_127a(0x3ac4);
          lVar9 = CONCAT22(uVar3,(undefined2)local_8);
          if (local_12 != 0) {
            iRam00055624 = 0x554c;
            uVar6 = 0x1000;
            uRam00055622 = local_12;
            FUN_1000_1a00(uVar11,0x1000);
            iVar2 = extraout_DX;
            uRam00055622 = FUN_1a9e_5cca(uRam00055622 & 0xfff0,iRam00055624);
            lVar9 = CONCAT22(iVar2,(undefined2)local_8);
            iRam00055624 = iVar2;
          }
        }
      }
      iVar4 = (int)((ulong)lVar9 >> 0x10);
      local_8._0_2_ = (undefined2)lVar9;
      iVar2 = FUN_1a9e_6a85(param_1,0x5649,0);
      if ((iVar4 != -1) || (lVar10 = CONCAT22(local_8._2_2_,(undefined2)local_8), iVar2 != -1)) {
        uVar3 = FUN_1a9e_6e3d(param_1);
        iVar5 = FUN_28eb_2779(0,param_1,0x5652,uVar3,iVar4);
        lVar10 = CONCAT22(local_8._2_2_,(undefined2)local_8);
        if (-1 < iVar5) {
          local_a = local_8._2_2_;
          local_c = (undefined2)local_8;
          while( true ) {
            uVar3 = 0x7fff;
            iVar2 = FUN_28eb_2aad(iVar5,local_c,local_a,0x7fff);
            if (iVar2 != 0x7fff) break;
            FUN_1000_1a00(uVar3,uVar6);
            uVar6 = 0x1000;
          }
          uVar8 = FUN_28eb_2ba9(uVar6,iVar5,local_10,uVar8);
          (*DAT_554c_4dae)(uVar6,local_4,(undefined2)local_8,local_8._2_2_,uVar8);
          iVar2 = extraout_DX_00;
          FUN_28eb_29db(iVar5);
          local_1c = 1;
          lVar10 = CONCAT22(local_8._2_2_,(undefined2)local_8);
          if (DAT_554c_42df != '\0') {
            iVar4 = FUN_1a9e_6a85(param_1,0x5654,0);
            if ((iVar2 == -1) && (iVar4 == -1)) {
              iVar4 = FUN_1a9e_6a85(param_1,0x565d,0);
              if ((iVar2 != -1) || (iVar4 != -1)) {
                local_1c = 6;
              }
            }
            else {
              local_1c = 5;
            }
            lVar10 = CONCAT22(local_8._2_2_,(undefined2)local_8);
            if (4 < local_1c) {
              uVar3 = FUN_1a9e_6e3d(param_1);
              iVar5 = FUN_28eb_2779(0,param_1,0x5666,uVar3,iVar2);
              lVar10 = CONCAT22(local_8._2_2_,(undefined2)local_8);
              if (-1 < iVar5) {
                local_20 = 0x7fff;
                while( true ) {
                  lVar10 = FUN_2fc8_00fc(uVar6,local_20,0,0,0);
                  if (lVar10 != 0) break;
                  local_20 = local_20 >> 1;
                  local_10 = 0;
                }
                local_a = local_8._2_2_;
                local_c = (undefined2)local_8;
                local_10 = lVar10;
                while( true ) {
                  local_16 = FUN_28eb_2aad(iVar5,local_10,local_20);
                  if (local_16 < 1) break;
                  if (local_1c == 6) {
                    FUN_1a9e_836a(local_10,local_10,local_16);
                    local_16 = local_16 << 2;
                  }
                  (*DAT_554c_4db2)(uVar6,local_10,local_c,local_a,local_16);
                  FUN_1000_1a00(uVar6);
                  uVar6 = 0x1000;
                }
                FUN_28eb_29db(iVar5);
                lVar10 = CONCAT22(local_8._2_2_,(undefined2)local_8);
              }
            }
          }
        }
      }
    }
  }
LAB_1a9e_825f:
  bVar7 = true;
  local_8 = lVar10;
  FUN_1000_1821();
  if (!bVar7) {
    func_0x0002fdf5(0x1000,local_10);
  }
  if (local_12 != 0) {
    FUN_1000_130c(local_12);
    iRam00055624 = 0;
    uRam00055622 = 0;
  }
  if (local_1c == 0) {
    bVar7 = true;
    FUN_1000_1821();
    if (!bVar7) {
      func_0x0002fdf5(0x1000,local_8);
    }
    if (iVar5 != 0) {
      FUN_28eb_29db(iVar5);
    }
    FUN_1a9e_82f5(local_4);
    local_4 = 0;
  }
  if (iVar1 == 0) {
    FUN_1a9e_6e73(param_1);
  }
  return local_4;
}

