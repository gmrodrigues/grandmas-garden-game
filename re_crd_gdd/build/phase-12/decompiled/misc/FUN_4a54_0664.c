// TIM2.EXE: FUN_4a54_0664 @ file 0x04FDA4 Ghidra 0x4ABA4
// Subsystem: misc | Size: 830 bytes


int __cdecl16far FUN_4a54_0664(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  int extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int extraout_DX_02;
  undefined2 uVar4;
  undefined1 local_a4 [68];
  undefined1 local_60 [68];
  int local_1c;
  undefined4 local_1a;
  undefined1 local_16 [4];
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  local_4 = 0;
  local_c = 0;
  local_e = 0;
  local_a = 0;
  iVar2 = FUN_1a9e_6ea7(param_1);
  if (iVar2 == 0) {
    local_a = 1;
    param_1 = FUN_1a9e_69e9(param_1);
    if (param_1 != 0) goto LAB_4a54_06a8;
  }
  else {
LAB_4a54_06a8:
    FUN_1a9e_693e(local_60,param_1);
    iVar2 = FUN_1a9e_6a85(param_1,0x5672,0);
    if ((in_DX == -1) && (iVar2 == -1)) {
      iVar2 = FUN_1a9e_6a85(param_1,0x567b,0);
      if ((in_DX == -1) && (iVar2 == -1)) {
        local_4 = FUN_1a9e_7f58(param_1);
        goto LAB_4a54_091d;
      }
      FUN_1000_0d10(&local_1c,2,1,param_1);
      FUN_1a9e_6988(local_60);
      iVar2 = FUN_1a9e_7d9a(param_1,&local_6,&local_4);
      if (iVar2 != 0) {
        FUN_4a54_09a6(0xffff,local_4);
        iVar2 = extraout_DX_00;
        iVar3 = FUN_1a9e_6a85(param_1,0x5684,0);
        if ((iVar2 != -1) || (iVar3 != -1)) goto LAB_4a54_07a3;
      }
    }
    else {
      FUN_1a9e_693e(local_a4,param_1);
      FUN_1a9e_6988(local_60);
      iVar2 = FUN_1a9e_7d9a(param_1,&local_6,&local_4);
      if (iVar2 != 0) {
        FUN_4a54_09a6(0xfffe,local_4);
        iVar2 = extraout_DX;
        FUN_1a9e_6988(local_a4);
        local_1c = 0;
LAB_4a54_07a3:
        if (local_1c == 0) {
          local_1a._0_2_ = FUN_1a9e_6e3d(param_1);
          local_1a._2_2_ = iVar2;
          local_e = FUN_1a9e_539c((undefined2)local_1a,iVar2,0,0);
          local_c = iVar2;
          if (local_e != 0 || iVar2 != 0) {
            FUN_4a54_0c1d(local_e,iVar2,(undefined2)local_1a,local_1a._2_2_,param_1);
            in_DX = extraout_DX_01;
            iVar2 = FUN_1a9e_6a85(param_1,0x568d,0);
            if ((in_DX != -1) || (iVar2 != -1)) {
              for (local_8 = 0; local_8 < local_6; local_8 = local_8 + 1) {
                iVar2 = FUN_1000_0d10(local_16,4,1,param_1);
                if (iVar2 != 1) {
                  FUN_1a9e_5415(local_e,local_c);
                  goto LAB_4a54_097e;
                }
                in_DX = local_c;
                local_12 = FUN_1000_1a88();
                piVar1 = (int *)*(int *)(local_4 + local_8 * 2);
                *piVar1 = in_DX;
                piVar1[1] = local_12;
                local_10 = in_DX;
              }
              goto LAB_4a54_091d;
            }
            FUN_1a9e_5415(local_e,local_c);
          }
        }
        else {
          local_1a = (*DAT_554c_4daa)(0x1a9e,local_4,&local_8);
          iVar2 = (int)((ulong)local_1a >> 0x10);
          local_e = FUN_1a9e_539c(local_1a,0,0);
          local_c = iVar2;
          if (local_e != 0 || iVar2 != 0) {
            FUN_4a54_09a6(0xfffc,local_4);
            uVar4 = 0x1a9e;
            for (local_8 = 0; local_8 < local_6; local_8 = local_8 + 1) {
              piVar1 = (int *)*(int *)(local_4 + local_8 * 2);
              *piVar1 = local_c;
              piVar1[1] = local_e;
              FUN_1000_1a00(piVar1[3] * piVar1[4],uVar4);
              uVar4 = 0x1000;
            }
            FUN_4a54_0d3c(param_1,local_4);
            in_DX = extraout_DX_02;
LAB_4a54_091d:
            local_6 = FUN_4a54_09d2(local_4);
            iVar2 = FUN_1a9e_6a85(param_1,0x5696,0);
            if ((in_DX != -1) || (iVar2 != -1)) {
              FUN_1a9e_7559(local_4,0x10);
            }
            iVar2 = FUN_1a9e_6a85(param_1,0x569f,0);
            if ((in_DX != -1) || (iVar2 != -1)) {
              FUN_4a54_09a6(0xfffd,local_4);
            }
            goto LAB_4a54_098e;
          }
        }
      }
    }
  }
LAB_4a54_097e:
  FUN_4a54_09c2(local_4);
  local_4 = 0;
LAB_4a54_098e:
  if (local_a != 0) {
    FUN_1a9e_6e73(param_1);
  }
  return local_4;
}

