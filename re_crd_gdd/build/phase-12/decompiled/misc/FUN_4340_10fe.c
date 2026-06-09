// TIM2.EXE: FUN_4340_10fe @ file 0x0496FE Ghidra 0x444FE
// Subsystem: misc | Size: 1104 bytes


undefined2 __cdecl16far FUN_4340_10fe(int *param_1,undefined2 *param_2,int param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  bool bVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  uint local_22;
  int local_1e;
  int local_18;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  byte *local_e;
  int local_c;
  undefined4 local_a;
  undefined4 local_6;
  
  if (((int *)param_1 == (int *)0x0 && param_1._2_2_ == 0) ||
     (((int *)param_1)[8] == 0 && ((int *)param_1)[9] == 0)) {
    uVar5 = 0;
  }
  else if ((((((param_3 == 0) && (DAT_53c6_00f2 == param_1._2_2_)) &&
             (DAT_53c6_00f0 == (int *)param_1)) &&
            ((((int *)DAT_53c6_00fa)[1] == ((int *)param_1)[9] &&
             (*DAT_53c6_00fa == ((int *)param_1)[8])))) && (DAT_53c6_00d8 == *param_1)) &&
          ((((((int *)param_1)[1] == DAT_53c6_00da && (((int *)param_1)[4] == DAT_53c6_00e0)) &&
            ((((int *)param_1)[5] == DAT_53c6_00e2 &&
             (((((int *)param_1)[6] == DAT_53c6_00e4 && (((int *)param_1)[7] == DAT_53c6_00e6)) &&
              (((int *)param_1)[9] == DAT_53c6_00ea)))))) &&
           ((((int *)param_1)[8] == DAT_53c6_00e8 && (((int *)param_1)[0xb] == DAT_53c6_00ee)))))) {
    if ((undefined2 *)param_2 != (undefined2 *)0x0 || param_2._2_2_ != 0) {
      puVar9 = (undefined2 *)0xf0;
      for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
        puVar2 = (undefined2 *)param_2;
        param_2._0_2_ = (undefined2 *)param_2 + 1;
        puVar1 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = *puVar1;
      }
    }
    uVar5 = 1;
  }
  else {
    FUN_1000_1842(0x4340,(int *)param_1,param_1._2_2_,0xd8,0x53c6);
    DAT_53c6_00f0 = (int *)param_1;
    DAT_53c6_00f4 = 0;
    DAT_53c6_00f6 = 0;
    DAT_53c6_00f8 = 0;
    DAT_53c6_00fa = &DAT_53c6_0010;
    local_12 = 0;
    local_10 = 0;
    local_22 = 0;
    local_6 = &DAT_53c6_0010;
    local_1e = ((int *)param_1)[0xb];
    local_c = ((int *)param_1)[9];
    local_e = (byte *)((int *)param_1)[8];
    local_a = (byte *)CONCAT22(local_c,local_e);
    DAT_53c6_00f2 = param_1._2_2_;
    iVar6 = FUN_4340_1602((int *)param_1,param_1._2_2_,0xfe,0x53c6);
    iVar7 = FUN_4340_1640((int *)param_1,param_1._2_2_,0xfe,0x53c6);
    bVar3 = false;
    local_18 = iVar7;
LAB_4340_14a7:
    if (((*local_a != 0) && (local_22 < 0x32)) && (!bVar3)) {
      iVar8 = FUN_4340_154e((int *)param_1,param_1._2_2_,(byte *)local_a,local_a._2_2_,&local_14,
                            &local_16);
      if ((local_12 + local_18 <= ((int *)param_1)[5]) &&
         (local_12 + local_16 <= ((int *)param_1)[5])) {
        uVar4 = local_22;
        if (((local_10 != 0) || (local_12 != 0)) && (((int *)param_1)[4] <= local_10 + local_14)) {
          if (local_1e == 0) {
            uVar5 = (undefined2)((ulong)local_6 >> 0x10);
            ((undefined2 *)local_6)[1] = local_c;
            *local_6 = local_e;
            local_6 = (undefined2 *)CONCAT22(uVar5,(undefined2 *)local_6 + 2);
            local_c = local_a._2_2_;
            local_e = (byte *)local_a;
            local_10 = 0;
            local_12 = local_12 + local_18;
            local_18 = iVar7;
            if ((((*(byte *)((int *)param_1 + 6) & 2) == 0) ||
                (((int *)param_1)[5] < local_12 + iVar7)) ||
               (uVar4 = local_22 + 1, ((int *)param_1)[5] < local_12 + local_16))
            goto LAB_4340_14bf;
          }
          else {
            local_1e = local_1e + -1;
            local_c = local_a._2_2_;
            local_e = (byte *)local_a;
            local_10 = 0;
            local_18 = iVar7;
          }
        }
        local_22 = uVar4;
        if (local_18 < local_16) {
          local_18 = local_16;
        }
        local_a = (byte *)CONCAT22(local_a._2_2_,(byte *)local_a + iVar8);
        local_10 = local_10 + local_14;
        iVar8 = local_10;
        if (local_10 <= DAT_53c6_00f4) {
          iVar8 = DAT_53c6_00f4;
        }
        do {
          DAT_53c6_00f4 = iVar8;
          if (((*local_a == 0) || (0x20 < *local_a)) || (((int *)param_1)[5] < local_12 + local_18))
          goto LAB_4340_14a7;
          uVar4 = local_22;
          if (*local_a == 10) {
            if (local_1e == 0) {
              uVar5 = (undefined2)((ulong)local_6 >> 0x10);
              ((undefined2 *)local_6)[1] = local_c;
              *local_6 = local_e;
              local_6 = (undefined2 *)CONCAT22(uVar5,(undefined2 *)local_6 + 2);
              local_e = (byte *)local_a + 1;
              local_c = local_a._2_2_;
              local_10 = 0;
              local_12 = local_12 + local_18;
              uVar4 = local_22 + 1;
              local_18 = iVar7;
              if ((*(byte *)((int *)param_1 + 6) & 2) == 0) {
                bVar3 = true;
                goto LAB_4340_14a7;
              }
            }
            else {
              local_1e = local_1e + -1;
              local_e = (byte *)local_a + 1;
              local_c = local_a._2_2_;
              local_10 = 0;
              local_18 = iVar7;
            }
          }
          else if (*local_a == 0x20) {
            local_10 = local_10 + iVar6;
          }
          local_22 = uVar4;
          local_a = (byte *)CONCAT22(local_a._2_2_,(byte *)local_a + 1);
          iVar8 = DAT_53c6_00f4;
        } while( true );
      }
      local_22 = local_22 - 1;
    }
LAB_4340_14bf:
    if (((*local_a == 0) && ((byte *)((int *)param_1)[8] < (byte *)local_a)) &&
       (((byte *)local_a)[-1] != 10)) {
      local_12 = local_12 + local_18;
    }
    uVar5 = (undefined2)((ulong)local_6 >> 0x10);
    puVar9 = (undefined2 *)local_6;
    puVar9[1] = local_c;
    *local_6 = local_e;
    local_6 = (undefined2 *)CONCAT22(uVar5,puVar9 + 2);
    puVar9[3] = 0;
    *local_6 = 0;
    DAT_53c6_00f8 = local_22 + 1;
    if (local_12 != 0) {
      iVar7 = local_12;
    }
    DAT_53c6_00f6 = iVar7;
    if ((undefined2 *)param_2 != (undefined2 *)0x0 || param_2._2_2_ != 0) {
      puVar9 = (undefined2 *)0xf0;
      for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
        puVar2 = (undefined2 *)param_2;
        param_2._0_2_ = (undefined2 *)param_2 + 1;
        puVar1 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = *puVar1;
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}

