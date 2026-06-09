// TIM2.EXE: FUN_4bdc_2914 @ file 0x0538D4 Ghidra 0x4E6D4
// Subsystem: physics | Size: 435 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far FUN_4bdc_2914(undefined2 param_1,undefined2 param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int in_AX;
  int iVar4;
  int iVar5;
  uint *in_DX;
  int iVar6;
  undefined2 *puVar7;
  uint unaff_SI;
  uint uVar8;
  uint unaff_DI;
  undefined2 uVar9;
  bool bVar10;
  bool bVar11;
  char *pcVar12;
  int local_10;
  undefined4 local_e;
  int local_a;
  undefined2 uStack_8;
  undefined4 local_6;
  
  local_e = (uint *)((ulong)local_e & 0xffff0000);
  local_10 = 0;
  if (DAT_554c_575a == 5) {
    uStack_8._1_1_ = 0x13;
  }
  else {
    if ((int)DAT_554c_575a < 6) {
      if (3 < DAT_554c_575a) {
        return 0;
      }
      bVar10 = (int)DAT_554c_575a < 0;
      switch(DAT_554c_575a) {
      case 0:
        out(in_DX,(char)in_AX);
        *(char *)(unaff_DI + 0x20) = *(char *)(unaff_DI + 0x20) + (char)((uint)in_DX >> 8);
        if ((undefined2 *)param_3 != (undefined2 *)0x0 || param_3._2_2_ != (uint *)0x0) {
          puVar7 = (undefined2 *)0xf0;
          for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
            puVar3 = (undefined2 *)param_3;
            param_3._0_2_ = (undefined2 *)param_3 + 1;
            puVar2 = puVar7;
            puVar7 = puVar7 + 1;
            *puVar3 = *puVar2;
          }
        }
        return 1;
      case 1:
        return in_AX;
      case 2:
        _DAT_53bd_004a = 0;
        return 0x53bd;
      case 3:
        iVar4 = unaff_SI + 1;
        bVar11 = iVar4 == 0;
        in(in_DX);
        while (pcVar12 = (char *)(ulong)unaff_SI, !bVar10 && !bVar11) {
          unaff_SI = unaff_SI + 1;
          if (*pcVar12 == '\0') {
            uVar9 = (undefined2)((ulong)local_e >> 0x10);
            ((uint *)local_e)[1] = 0;
            *local_e = unaff_SI;
            local_e = (uint *)CONCAT22(uVar9,(uint *)local_e + 2);
          }
          bVar11 = unaff_DI == unaff_SI;
          bVar10 = unaff_DI < unaff_SI;
        }
        uVar9 = (undefined2)((ulong)local_6 >> 0x10);
        puVar7 = (undefined2 *)local_6;
        puVar7[1] = 0;
        *local_6 = 0;
        puVar7[3] = uStack_8;
        puVar7[2] = local_a;
        puVar7[6] = iVar4;
        return 1;
      }
    }
    if (DAT_554c_575a == 6) {
      uStack_8._1_1_ = 0;
    }
    else if (DAT_554c_575a == 7) {
      uStack_8._1_1_ = 7;
    }
    else {
      if (DAT_554c_575a != 0x7e) {
        return 0;
      }
      uStack_8._1_1_ = DAT_554c_574a;
    }
  }
  iVar4 = FUN_1a9e_0c49(0,param_1,0x572a,param_2,(undefined2 *)param_3);
  if (iVar4 < 0) goto LAB_4bdc_2abd;
  iVar5 = FUN_4bdc_2b20(iVar4,uStack_8._1_1_);
  if (iVar5 == 0) {
LAB_4bdc_2aae:
    DAT_554c_5748 = 2;
  }
  else {
    local_10 = FUN_4bdc_2c25(iVar4);
    local_e = (uint *)ZEXT24(in_DX);
    if (local_10 == 0 && in_DX == (uint *)0x0) goto LAB_4bdc_2aae;
    local_a = 0;
    local_e._2_2_ = 0;
    uVar8 = 5;
    local_6._0_2_ = local_10;
    local_6._2_2_ = in_DX;
    while ((int)local_6 != 0 || local_6._2_2_ != (uint *)0x0) {
      bVar10 = CARRY2(local_e._2_2_,*(uint *)((int)local_6 + 2));
      local_e._2_2_ = local_e._2_2_ + *(uint *)((int)local_6 + 2);
      local_a = local_a + (uint)bVar10;
      uVar8 = uVar8 + 6;
      puVar7 = (undefined2 *)((int)local_6 + 6);
      local_6._0_2_ = *(int *)((int)local_6 + 4);
      local_6._2_2_ = (uint *)*puVar7;
    }
    if ((uVar8 & 1) != 0) {
      uVar8 = uVar8 + 1;
    }
    if (uVar8 < 0x26) {
      uVar8 = 0x26;
    }
    bVar10 = CARRY2(local_e._2_2_,uVar8);
    local_e._2_2_ = local_e._2_2_ + uVar8;
    local_e = (uint *)CONCAT22(local_e._2_2_,in_DX);
    uVar1 = local_a + (uint)bVar10;
    iVar6 = local_e._2_2_ + 1;
    iVar5 = FUN_2e67_0edd(iVar6,uVar1 + (0xfffe < local_e._2_2_),4);
    if ((iVar5 != 0 || iVar6 != 0) &&
       (iVar6 = FUN_4bdc_2db5(iVar4,local_10,in_DX,iVar5,iVar6,uVar8,uStack_8._1_1_), iVar6 != 0)) {
      FUN_4bdc_2add(local_10,in_DX);
      if (param_3._2_2_ != (uint *)0x0) {
        param_3._2_2_[1] = uVar1;
        *param_3._2_2_ = local_e._2_2_;
      }
      FUN_1a9e_0eab(iVar4);
      return iVar5;
    }
  }
  FUN_1a9e_0eab(iVar4);
LAB_4bdc_2abd:
  FUN_4bdc_2add(local_10,(uint *)local_e);
  return 0;
}

