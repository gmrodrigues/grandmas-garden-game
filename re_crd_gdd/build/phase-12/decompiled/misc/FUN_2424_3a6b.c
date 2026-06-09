// TIM2.EXE: FUN_2424_3a6b @ file 0x02CEAB Ghidra 0x27CAB
// Subsystem: misc | Size: 347 bytes


/* WARNING: Instruction at (ram,0x00029f40) overlaps instruction at (ram,0x00029f3e)
    */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl16far FUN_2424_3a6b(uint *param_1,uint *param_2,uint param_3,int param_4)

{
  int *piVar1;
  uint *puVar2;
  char *pcVar3;
  undefined2 *puVar4;
  int iVar5;
  uint *puVar6;
  undefined3 uVar7;
  byte bVar8;
  char cVar9;
  uint uVar10;
  undefined1 uVar15;
  int iVar11;
  uint *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined2 in_CX;
  uint *in_DX;
  uint *puVar16;
  char *pcVar17;
  undefined2 *puVar18;
  int unaff_SI;
  uint *puVar19;
  undefined1 *unaff_DI;
  uint *puVar20;
  undefined2 uVar21;
  undefined2 uVar22;
  uint *puVar23;
  uint *puVar24;
  uint *unaff_SS;
  undefined2 in_FS;
  bool bVar25;
  undefined2 in_stack_00000016;
  uint auStack_150 [143];
  undefined2 uStack_32;
  undefined2 uStack_30;
  uint *puStack_2e;
  uint *puStack_2c;
  uint *puStack_2a;
  uint **ppuStack_28;
  uint *puStack_26;
  uint **ppuStack_24;
  undefined4 uStack_22;
  undefined4 uStack_1e;
  uint *puStack_1a;
  uint *in_stack_0000ffe8;
  int local_12;
  uint *local_10;
  uint *local_e;
  uint *local_c;
  undefined4 local_a;
  undefined4 local_6;
  
  puVar24 = (uint *)0x2424;
  puVar20 = (uint *)((ulong)param_1 >> 0x10);
  puVar16 = (uint *)param_1;
  puVar12 = (uint *)*(int *)(puVar16[4] * 2 + 0x68fe);
  local_e = puVar12;
  puVar19 = (uint *)0x0;
  for (local_12 = 2; puVar23 = puVar24, local_12 != 0; local_12 = local_12 + -1) {
    do {
      puVar19 = (uint *)((int)puVar19 + 1);
      puStack_1a = local_e;
      puVar24 = (uint *)0x4551;
      uStack_1e = (uint *)CONCAT22(puVar23,(uint *)0x7cd8);
      puVar12 = (uint *)FUN_4551_0308();
      puVar23 = puVar24;
    } while (puVar12 == (uint *)0x0);
    in_stack_0000ffe8 = puVar19;
  }
  if (puVar16[0x57] != 0) {
    local_c = (uint *)puVar16[0x57];
    iVar11 = puVar16[0x11] - DAT_5b41_0925;
    local_10 = (uint *)(puVar16[0x12] - DAT_5b41_0927);
    pcVar17 = (char *)((int)local_c + -1);
    if (pcVar17 < "CHECK") {
      iVar5 = (int)pcVar17 * 2;
      unaff_DI = &stack0xfffe;
      switch(pcVar17) {
      case (char *)0x0:
        puVar16[0x4b] = *(uint *)(iVar5 + 0x22);
        puVar16[0x1f] = *(uint *)(*(int *)((int)puVar19 * 2 + 0x302) + 0x38);
        puVar16[0x52] = 0xffff;
        puVar16[0x53] = 0xffff;
        uVar10 = *(uint *)(*(int *)((int)puVar19 * 2 + 0x302) + 0x2a);
        puVar16[0x25] = (uint)in_DX;
        puVar16[0x24] = uVar10;
        iVar11 = *(int *)((int)puVar19 * 2 + 0x302);
        if (*(int *)(iVar11 + 0x1c) != 0 || *(int *)(iVar11 + 0x1e) != 0) {
          puVar4 = (undefined2 *)(*(int *)((int)puVar19 * 2 + 0x302) + 0x1c);
          uStack_1e = (uint *)0x200040cd;
          puStack_1a = puVar16;
          iVar11 = (*(code *)*puVar4)();
          if (iVar11 == 0) {
            return (uint *)0x0;
          }
        }
        puVar4 = (undefined2 *)(*(int *)((int)puVar19 * 2 + 0x302) + 8);
        uStack_1e = (uint *)0x200040e9;
        puStack_1a = puVar16;
        (*(code *)*puVar4)();
        puVar16[0x56] = puVar16[6];
        uStack_1e = param_1;
        uStack_22 = (uint *)0x200040fe;
        FUN_28eb_3328();
        return (uint *)0x1;
      case "":
        do {
          uVar21 = (undefined2)((ulong)local_6 >> 0x10);
          puVar12 = (uint *)local_6;
          if (((puVar12[4] == 0x76) && (puVar12[0x25] == 0x20)) &&
             (puVar12[0x12] == puVar16[0x12] - 0x20)) {
            bVar25 = (puVar12[6] & 0x30) != 0;
            if (((local_c != (uint *)0x0) || (bVar25)) || (puVar12[0x11] != puVar16[0x11])) {
              if (((local_c != (uint *)0x0) && (!bVar25)) &&
                 (puVar12[0x11] + puVar12[0x24] == puVar16[0x11] + puVar16[0x24])) {
                local_a = (uint *)CONCAT22(9,(uint *)local_a);
              }
            }
            else {
              local_a = (uint *)CONCAT22(7,(uint *)local_a);
            }
          }
          local_6 = (uint *)CONCAT22(puVar12[0x47],(uint *)puVar12[0x46]);
        } while (((uint *)puVar12[0x46] != (uint *)0x0 || puVar12[0x47] != 0) &&
                (local_a._2_2_ == (uint *)0x0));
        puStack_1a = (uint *)puVar16[0x25];
        uStack_1e = (uint *)0x100000;
        uStack_22 = (uint *)CONCAT22(0x2000,puVar20);
        puStack_26 = (uint *)0x2000;
        ppuStack_28 = (uint **)0x842b;
        ppuStack_24 = (uint **)puVar16;
        FUN_2424_4ae2();
        puVar12 = puVar16;
        puVar19 = puVar20;
        while( true ) {
          puVar24 = (uint *)puVar12[0x47];
          puVar12 = (uint *)puVar12[0x46];
          local_6 = (uint *)CONCAT22(puVar24,puVar12);
          if ((puVar12 == (uint *)0x0 && puVar24 == (uint *)0x0) || ((uint *)local_a != (uint *)0x0)
             ) break;
          puVar19 = puVar24;
          if (((puVar12[4] == 0x76) && (puVar12[0x25] == 0x20)) &&
             (puVar16[0x12] + puVar16[0x25] == puVar12[0x12])) {
            bVar25 = (puVar12[6] & 0x30) == 0;
            if (((local_c != (uint *)0x0) || (bVar25)) || (puVar12[0x11] != puVar16[0x11])) {
              if (((local_c != (uint *)0x0) && (!bVar25)) &&
                 (puVar12[0x11] + puVar12[0x24] == puVar16[0x11] + puVar16[0x24])) {
                local_a = (uint *)CONCAT22(local_a._2_2_,(uint *)0xc);
              }
            }
            else {
              local_a = (uint *)CONCAT22(local_a._2_2_,(uint *)0xa);
            }
          }
        }
        if (((uint *)puVar16[0x57] != local_a._2_2_) || ((uint *)puVar16[0x5a] != (uint *)local_a))
        {
          uStack_1e._0_2_ = (uint *)0x2000;
          uStack_22 = (uint *)CONCAT22(0x8699,(uint *)uStack_22);
          puStack_1a = puVar20;
          uStack_1e._2_2_ = puVar16;
          FUN_2424_3746();
          uStack_1e = (uint *)CONCAT22(uStack_1e._2_2_,2);
          uStack_22 = param_1;
          ppuStack_24 = (uint **)0x2000;
          puStack_26 = (uint *)0x86a5;
          FUN_2424_3746();
          puVar16[0x57] = (uint)local_a._2_2_;
          puVar16[0x5a] = (uint)(uint *)local_a;
          ppuStack_24 = (uint **)0x1;
          puStack_2a = (uint *)0x2000;
          puStack_2c = (uint *)0x86c2;
          ppuStack_28 = (uint **)puVar16;
          puStack_26 = puVar20;
          FUN_2424_3746();
          puStack_2a = (uint *)0x2;
          uStack_30 = 0x2000;
          uStack_32 = 0x86ce;
          puStack_2e = puVar16;
          puStack_2c = puVar20;
          FUN_2424_3746();
        }
        puVar16[0x57] = (uint)local_a._2_2_;
        puVar16[0x5a] = (uint)(uint *)local_a;
        if ((local_a._2_2_ == (uint *)0x0) && ((uint *)local_a == (uint *)0x0)) {
          puVar12 = (uint *)0x0;
        }
        else {
          puVar12 = (uint *)0x1;
        }
        return puVar12;
      case "NULL CHECK":
        puVar2 = puVar19 + (int)pcVar17;
        puVar12 = (uint *)*puVar2;
        uVar10 = *puVar2;
        *puVar2 = (uVar10 - (int)local_10) - (uint)CARRY2((uint)pcVar17,(uint)pcVar17);
        pcVar3 = (char *)(iVar5 + iVar11 + -0x11aa);
        *pcVar3 = *pcVar3 + (char)in_CX +
                  (puVar12 < local_10 ||
                  uVar10 - (int)local_10 < (uint)CARRY2((uint)pcVar17,(uint)pcVar17));
        puStack_2a = (uint *)((int)puVar20 * 2);
        ppuStack_28 = (uint **)((int)puStack_2a >> 0xf);
        puStack_1a = (uint *)0x689c;
        FUN_1000_199e();
        puStack_1a = (uint *)0x68b0;
        pcVar17 = (char *)FUN_1000_199e();
        uStack_1e = (uint *)CONCAT22(in_stack_00000016,pcVar17);
        puStack_26 = (uint *)(1 << (param_1._2_1_ & 0x1f));
        ppuStack_24 = (uint **)((int)puStack_26 >> 0xf);
        puStack_1a = (uint *)&DAT_5b41_0983;
        local_6._2_2_ = (uint *)FUN_1000_19bf();
        puStack_1a = (uint *)0x68e4;
        local_6._0_2_ = (uint *)FUN_1000_19bf();
        uStack_22._2_2_ = (uint *)0x0;
        for (uStack_22._0_2_ = (uint *)0x0;
            ((int)uStack_22._2_2_ < (int)ppuStack_24 ||
            (((int)uStack_22._2_2_ <= (int)ppuStack_24 && ((uint *)uStack_22 <= puStack_26))));
            uStack_22._0_2_ = (uint *)((int)(uint *)uStack_22 + 1)) {
          puStack_1a = (uint *)0x6902;
          pcVar17 = (char *)FUN_1000_19bf();
          puStack_1a = (uint *)0x6912;
          iVar11 = FUN_1000_19bf();
          if ((local_6._2_2_ != (uint *)pcVar17) || ((uint *)local_6 != (uint *)iVar11)) {
            uStack_1e = (uint *)CONCAT22((uint *)local_6,local_6._2_2_);
            uStack_22._2_2_ = (uint *)0x1000;
            uStack_22._0_2_ = (uint *)((int)(undefined2 *)&DAT_5b41_09da + 1);
            puStack_1a = (uint *)pcVar17;
            FUN_2424_27e0();
            local_6._0_2_ = (uint *)iVar11;
            local_6._2_2_ = (uint *)pcVar17;
          }
          puStack_1a = (uint *)0x6953;
          FUN_1000_180a();
          puStack_1a = (uint *)0x697e;
          puVar12 = local_c;
          uVar10 = FUN_1000_180a();
          uStack_1e = (uint *)CONCAT22((char *)((int)puVar12 +
                                               (uint)CARRY2((uint)(uint *)uStack_1e,
                                                            uVar10 + (int)local_10) +
                                               (int)uStack_1e._2_2_ +
                                               (uint)CARRY2(uVar10,(uint)local_10) + unaff_SI),
                                       (char *)((int)(uint *)uStack_1e +
                                               (int)(uVar10 + (int)local_10)));
          uStack_22._2_2_ =
               (uint *)((int)uStack_22._2_2_ + (uint)((uint *)0xfffe < (uint *)uStack_22));
        }
        return (uint *)uStack_22;
      case "ULL CHECK":
        if ((char)((uint)iVar5 >> 8) != '\0') {
          puStack_1a = (uint *)0x2000;
          uStack_1e = (uint *)CONCAT22((undefined2 *)&DAT_5b41_1a48,(uint *)uStack_1e);
          local_10 = (uint *)FUN_2424_4087();
        }
        if (local_10 == (uint *)0x0) {
          puVar12 = (uint *)0x0;
          if (puVar16[4] == 0x76) {
            puStack_1a = (uint *)0x2000;
            uStack_1e = (uint *)CONCAT22((undefined2 *)&DAT_5b41_1a74,(uint *)uStack_1e);
            puVar12 = (uint *)FUN_2424_48ce();
          }
        }
        else {
          puStack_1a = (uint *)0x2000;
          uStack_1e = (uint *)CONCAT22(0x79ab,(uint *)uStack_1e);
          puVar12 = (uint *)FUN_2424_3ebc();
        }
        return puVar12;
      case "L CHECK":
        puStack_1a = (uint *)0x3e8;
        uStack_1e = (uint *)0x200043a8;
        puVar12 = (uint *)FUN_2e67_072c();
        if (puVar12 == (uint *)0x0) {
          puStack_1a = (uint *)0x0;
          uStack_1e = (uint *)(ulong)DAT_5b41_0755;
          uStack_22 = (uint *)0x2e6743be;
          puVar12 = (uint *)FUN_2e67_045f();
          return puVar12;
        }
        return puVar12;
      case " CHECK":
        *(uint *)(iVar5 + 0xac) = (uint)local_10 | 0x26;
        DAT_5b41_050f = 0;
        if (((*(byte *)((int)puVar16 + 0xf) & 4) != 0) && (((uint)puVar19 & 1) == 0)) {
          puVar19 = (uint *)((uint)puVar19 | 0x80);
        }
        return puVar19;
      }
      goto switchD_2000_7d1e_caseD_1;
    }
    uStack_1e = (uint *)CONCAT22(iVar11,(char *)((int)puVar19 + (int)local_c) + -1);
    uStack_22 = (uint *)CONCAT22(local_e,puVar24);
    ppuStack_24 = (uint **)0x7d41;
    puStack_1a = local_10;
    puVar12 = (uint *)FUN_2424_49f1();
    in_stack_0000ffe8 = (uint *)0x0;
    if (5000 < DAT_554c_2f1c) {
      puStack_1a = (uint *)&local_a;
      uStack_1e = (uint *)CONCAT22((char *)((int)puVar19 + (int)local_c) + -1,local_e);
      uStack_22 = (uint *)CONCAT22(puVar24,0x7d60);
      FUN_4551_03eb();
      uStack_22 = (uint *)((ulong)local_6 >> 0x10);
      ppuStack_24 = (uint **)(uint *)local_6;
      puStack_26 = (uint *)((int)local_10 + (int)local_a._2_2_);
      ppuStack_28 = (uint **)(iVar11 + (int)(uint *)local_a);
      puStack_2a = (uint *)0x4551;
      puVar24 = (uint *)0x406b;
      puStack_2c = (uint *)0x7d7a;
      puVar12 = (uint *)FUN_406b_000c();
      in_stack_0000ffe8 = unaff_SS;
    }
  }
  if (puVar16[0x5a] == 0) {
    return puVar12;
  }
  local_c = (uint *)puVar16[0x5a];
  puVar12 = (uint *)(puVar16[0x11] - DAT_5b41_0925);
  local_10 = (uint *)(puVar16[0x12] - DAT_5b41_0927);
  puVar23 = local_c + -1;
  if ((uint *)0xa < puVar23) {
    uStack_1e = (uint *)CONCAT22(puVar12,(char *)((int)puVar19 + (int)local_c) + -1);
    uStack_22 = (uint *)CONCAT22(local_e,puVar24);
    ppuStack_24 = (uint **)0x7de2;
    puStack_1a = local_10;
    puVar20 = (uint *)FUN_2424_49f1();
    if (DAT_554c_2f1c < 0x1389) {
      return puVar20;
    }
    puStack_1a = (uint *)&local_a;
    uStack_1e = (uint *)CONCAT22((char *)((int)puVar19 + (int)local_c) + -1,local_e);
    uStack_22 = (uint *)CONCAT22(puVar24,0x7e01);
    FUN_4551_03eb();
    uStack_22 = (uint *)((ulong)local_6 >> 0x10);
    ppuStack_24 = (uint **)(uint *)local_6;
    puStack_26 = (uint *)((int)local_10 + (int)local_a._2_2_);
    ppuStack_28 = (uint **)((int)puVar12 + (int)(uint *)local_a);
    puStack_2a = (uint *)0x4551;
    puStack_2c = (uint *)0x7e1b;
    puVar12 = (uint *)FUN_406b_000c();
    return puVar12;
  }
  iVar11 = (int)puVar23 * 2;
  bVar25 = iVar11 == 0;
  switch(puVar23) {
  case (uint *)0x0:
    do {
      *(undefined2 *)&DAT_5b41_04ec = local_10;
      puStack_1a = (uint *)local_a;
      if (((*(byte *)((int)puStack_1a + 0xb) & 0x80) == 0) || (iRam000557bc == 3)) {
LAB_28eb_10e0:
        uStack_1e = (uint *)CONCAT22(local_c,local_e);
        uStack_22 = (uint *)0x20009fa0;
        local_e = (uint *)FUN_28eb_0728();
        local_c = in_DX;
      }
      else if (((((uint *)DAT_5b41_0567 != (uint *)0x0 || DAT_5b41_0567._2_2_ != (uint *)0x0) &&
                (((uint *)DAT_5b41_0567)[4] == 10)) ||
               (((uint *)DAT_5b41_0567 != (uint *)0x0 || DAT_5b41_0567._2_2_ != (uint *)0x0 &&
                (((uint *)DAT_5b41_0567)[4] == 0x4c)))) ||
              (((uint *)DAT_5b41_0567 != (uint *)0x0 || DAT_5b41_0567._2_2_ != (uint *)0x0 &&
               (((uint *)DAT_5b41_0567)[4] == 8)))) goto LAB_28eb_10e0;
      while( true ) {
        while( true ) {
          while( true ) {
            do {
              while( true ) {
                puStack_1a = local_6._2_2_;
                uStack_1e = (uint *)CONCAT22((uint *)local_6,0x2000);
                uStack_22 = (uint *)CONCAT22(0x9fb7,(uint *)uStack_22);
                puStack_1a = (uint *)FUN_28eb_32d8();
                local_6 = (uint *)CONCAT22(in_DX,puStack_1a);
                if (puStack_1a == (uint *)0x0 && in_DX == (uint *)0x0) {
                  if (local_e != (uint *)0x0 || local_c != (uint *)0x0) {
                    return local_e;
                  }
                  return (uint *)0x0;
                }
                uStack_1e = param_1;
                uStack_22 = (uint *)0x20009cc5;
                puVar12 = (uint *)FUN_28eb_0a36();
                local_a = (uint *)CONCAT22(in_DX,puVar12);
                if (((((puVar12 != (uint *)0x0 || in_DX != (uint *)0x0) &&
                      ((*(byte *)((int)puVar12 + 0xb) & 0x80) != 0)) && (iRam000557bc != 3)) &&
                    (puVar16 != (uint *)0x0 || puVar20 != (uint *)0x0)) &&
                   ((puVar20 != in_DX || (in_DX = puVar20, puVar16 != puVar12)))) {
                  local_a = (uint *)0x0;
                  in_DX = puVar20;
                }
                if ((((uint *)local_a == (uint *)0x0 && local_a._2_2_ == (uint *)0x0) ||
                    (((uint *)local_a)[0x4c] != 0)) ||
                   ((local_e == (uint *)0x0 && local_c == (uint *)0x0 || (local_e[0x4c] != 0))))
                break;
                if (((local_e == (uint *)0x0 && local_c == (uint *)0x0) ||
                    (in_DX = local_c, local_c != DAT_5b41_0567._2_2_)) ||
                   (local_e != (uint *)DAT_5b41_0567)) {
                  puVar12 = in_DX;
                  if ((((uint *)local_a == (uint *)0x0 && local_a._2_2_ == (uint *)0x0) ||
                      (puVar12 = local_a._2_2_, local_a._2_2_ != DAT_5b41_0567._2_2_)) ||
                     ((uint *)local_a != (uint *)DAT_5b41_0567)) {
                    puStack_1a = (uint *)local_a;
                    uStack_1e = (uint *)0x20009dee;
                    in_DX = (uint *)FUN_28eb_0d77();
                    uStack_1e = (uint *)CONCAT22(local_c,local_e);
                    uStack_22 = (uint *)0x20009dfd;
                    puStack_1a = puVar12;
                    puVar19 = (uint *)FUN_28eb_0d77();
                    if (((int)puStack_1a <= (int)puVar12) &&
                       (((int)puStack_1a < (int)puVar12 || (in_DX < puVar19)))) {
                      DAT_5b41_04ee = local_a._2_2_;
                      DAT_5b41_04ec = (uint *)local_a;
                      in_DX = local_a._2_2_;
                      local_e = (uint *)local_a;
                      local_c = local_a._2_2_;
                    }
                  }
                  else {
                    puStack_1a = (uint *)local_a;
                    uStack_1e = (uint *)0x20009db0;
                    uVar10 = FUN_28eb_0d77();
                    uStack_1e = (uint *)CONCAT22(local_c,local_e);
                    uStack_22 = (uint *)0x20009dbf;
                    puStack_1a = puVar12;
                    uVar14 = FUN_28eb_0d77();
                    in_DX = local_a._2_2_;
                    local_e = (uint *)local_a;
                    local_c = local_a._2_2_;
                    if (((int)puStack_1a <= (int)puVar12) &&
                       (((int)puStack_1a < (int)puVar12 || (uVar10 < uVar14)))) {
                      DAT_5b41_04ee = local_a._2_2_;
                      DAT_5b41_04ec = (uint *)local_a;
                    }
                  }
                }
                else {
                  puStack_1a = (uint *)local_a;
                  uStack_1e = (uint *)0x20009d5c;
                  puVar12 = local_c;
                  in_DX = (uint *)FUN_28eb_0d77();
                  uStack_1e = (uint *)CONCAT22(local_c,local_e);
                  uStack_22 = (uint *)0x20009d6b;
                  puStack_1a = puVar12;
                  puVar19 = (uint *)FUN_28eb_0d77();
                  if (((int)puStack_1a <= (int)puVar12) &&
                     (((int)puStack_1a < (int)puVar12 || (in_DX < puVar19)))) {
                    DAT_5b41_04ee = local_a._2_2_;
                    DAT_5b41_04ec = (uint *)local_a;
                    in_DX = local_a._2_2_;
                  }
                }
              }
            } while ((uint *)local_a == (uint *)0x0 && local_a._2_2_ == (uint *)0x0);
            if (((local_e == (uint *)0x0 && local_c == (uint *)0x0) ||
                (local_c != DAT_5b41_0567._2_2_)) || (local_e != (uint *)DAT_5b41_0567)) break;
            puStack_1a = (uint *)local_a;
            uStack_1e = (uint *)0x0;
            uStack_22 = (uint *)0x20009e55;
            in_DX = local_c;
            iVar11 = FUN_28eb_03ff();
            if (iVar11 != 0) {
              puStack_1a = (uint *)local_a;
              uStack_1e = (uint *)CONCAT22(DAT_5b41_04ee,DAT_5b41_04ec);
              uStack_22 = (uint *)0x20009e71;
              DAT_5b41_04ec = (uint *)FUN_28eb_0728();
              DAT_5b41_04ee = in_DX;
            }
          }
          if ((local_a._2_2_ != DAT_5b41_0567._2_2_) || ((uint *)local_a != (uint *)DAT_5b41_0567))
          break;
          puStack_1a = local_e;
          uStack_1e = (uint *)0x0;
          uStack_22 = (uint *)0x20009e9e;
          iVar11 = FUN_28eb_03ff();
          in_DX = local_a._2_2_;
          local_e = (uint *)local_a;
          local_c = local_a._2_2_;
          if (iVar11 == 0) {
            DAT_5b41_04ee = local_a._2_2_;
            DAT_5b41_04ec = (uint *)local_a;
            local_c = local_a._2_2_;
          }
        }
        in_DX = local_a._2_2_;
        if ((local_e == (uint *)0x0 && local_c == (uint *)0x0) ||
           ((*(byte *)((int)(uint *)local_a + 0xb) & 0x80) != 0)) break;
        if (((uint *)local_a)[0x4c] == 0) {
LAB_28eb_1038:
          in_DX = local_a._2_2_;
          DAT_5b41_04ec = (uint *)local_a;
          DAT_5b41_04ee = local_a._2_2_;
          local_e = (uint *)local_a;
          local_c = local_a._2_2_;
        }
        else {
          uStack_1e = (uint *)0x0;
          uStack_22 = (uint *)0x20009ee1;
          puStack_1a = (uint *)local_a;
          iVar11 = FUN_28eb_03ff();
          if (iVar11 != 0) goto LAB_28eb_1038;
          if (local_e[0x4c] != 0) {
            puStack_1a = local_e;
            uStack_1e = (uint *)0x0;
            uStack_22 = (uint *)0x20009f0a;
            iVar11 = FUN_28eb_03ff();
            if (iVar11 == 0) {
              puStack_1a = (uint *)local_a;
              uStack_1e = (uint *)CONCAT22(local_c,local_e);
              uStack_22 = (uint *)0x20009f24;
              DAT_5b41_04ec = (uint *)FUN_28eb_0728();
              DAT_5b41_04ee = in_DX;
              local_e = DAT_5b41_04ec;
              local_c = in_DX;
            }
          }
        }
      }
      DAT_5b41_04ec = (uint *)local_a;
      DAT_5b41_04ee = local_a._2_2_;
      local_10 = (uint *)local_a;
    } while( true );
  case (uint *)0x1:
switchD_2000_7d1e_caseD_1:
    if ((char)local_10 != '\0') {
      puStack_1a = (uint *)&DAT_554c_5173;
      uStack_1e = (uint *)CONCAT22(*(undefined2 *)(unaff_DI + 6),0x2000);
      uStack_22 = (uint *)CONCAT22(0x84,(uint *)uStack_22);
      FUN_2fc8_0364();
      local_10 = (uint *)0x0;
      if (DAT_554c_5173 < -0x1e) {
        local_10 = (uint *)0x4;
      }
      else if (0x1d < DAT_554c_5173) {
        local_10 = (uint *)0x8;
      }
      if (DAT_554c_5175 < -0x1e) {
        local_10 = (uint *)((uint)local_10 | 1);
      }
      else if (0x1d < DAT_554c_5175) {
        local_10 = (uint *)((uint)local_10 | 2);
      }
    }
    return local_10;
  case (uint *)0x2:
    piVar1 = (int *)(&stack0x00d7 + (int)puVar12);
    *piVar1 = (int)(*piVar1 + (int)local_10);
    if (-1 < *piVar1) {
      uStack_1e = (uint *)CONCAT22(0x57f,(uint *)uStack_1e);
      puStack_1a = (uint *)iVar11;
      FUN_1a9e_5ad4();
      FUN_1a9e_5ad4();
      do {
        uVar10 = 32000;
        if (param_4 == 0) {
          if (param_3 == 0) break;
          if ((int)param_3 < 0x7d01) {
            uVar10 = param_3;
          }
        }
        (*pcRam00025b2d)();
        (*pcRam00025b2d)();
        (*pcRam00025b2f)();
        bVar25 = param_3 < uVar10;
        param_3 = param_3 - uVar10;
        param_4 = param_4 - (uint)bVar25;
      } while( true );
    }
    return (uint *)local_6;
  case (uint *)0x3:
    while( true ) {
      DAT_5b41_283b = DAT_5b41_283b + puVar19[3];
      local_6 = (uint *)((ulong)local_6 & 0xffff);
      while (puVar2 = local_a, local_e = puVar12, (int)local_6._2_2_ < (int)puVar19[3]) {
        cVar9 = (char)*local_c;
        uVar7 = local_a._1_3_;
        local_a = (uint *)CONCAT31(local_a._1_3_,cVar9);
        local_c = (uint *)((int)local_c + 1);
        if (cVar9 == '\0') {
          if (puVar12 != (uint *)0x0) {
            FUN_1a9e_77ec();
            puVar12 = (uint *)0x0;
          }
          local_a = (uint *)CONCAT22((int)local_a._2_2_ + 1,(uint *)local_a);
        }
        else {
          local_a._1_1_ = SUB41(puVar2,1);
          bVar8 = cVar9 - local_a._1_1_ & DAT_5b41_282e;
          local_a = (uint *)CONCAT31(uVar7,bVar8);
          puVar6 = local_a;
          *(byte *)(DAT_5b41_283f + (int)puVar12) = bVar8;
          puVar12 = (uint *)((int)puVar12 + 1);
          local_a._2_2_ = SUB42(puVar2,2);
          local_a = puVar6;
          if (local_a._2_2_ == (uint *)0x0) {
            if (DAT_5b41_2831 != 0) {
              while (DAT_5b41_2831 != 0) {
                DAT_5b41_2831 = DAT_5b41_2831 + -1;
                *_DAT_5b41_2837 = 0;
                _DAT_5b41_2837 = (undefined1 *)CONCAT22(DAT_5b41_2839,DAT_5b41_2837 + 1);
              }
              DAT_5b41_2831 = 0;
            }
          }
          else {
            local_e = local_a._2_2_;
            FUN_1a9e_76bf();
            local_a = (uint *)((ulong)local_a & 0xffff);
          }
        }
        local_6 = (uint *)CONCAT22((int)local_6._2_2_ + 1,(uint *)local_6);
      }
      if (puVar12 != (uint *)0x0) {
        FUN_1a9e_77ec();
        puVar12 = (uint *)0x0;
      }
      local_a = (uint *)CONCAT22((int)local_a._2_2_ - puVar19[3],(uint *)local_a);
      DAT_5b41_2831 = DAT_5b41_2831 + 1;
      puVar20 = (uint *)((int)(uint *)local_6 + 1);
      local_6 = (uint *)CONCAT22(local_6._2_2_,puVar20);
      if ((int)puVar19[4] <= (int)puVar20) break;
      local_c = auStack_150;
      local_e = (uint *)puVar19[3];
      puStack_1a = (uint *)0x23ba;
      FUN_1a9e_5c0a();
    }
    if (puVar12 != (uint *)0x0) {
      local_e = puVar12;
      FUN_1a9e_77ec();
    }
    local_e = (uint *)0x0;
    FUN_1a9e_76bf();
    *(byte *)CONCAT22(local_e,(byte *)0x2000) = local_a._1_1_;
    return (uint *)(uint)local_a._1_1_;
  case (uint *)0x5:
    if (*(int *)(unaff_DI + 8) == 7) {
      FUN_28eb_1e42();
      puStack_1a = (uint *)0xb825;
      FUN_2424_0f94();
    }
    local_e = (uint *)0x2;
    FUN_28eb_2d82();
    iVar11 = 0;
    while( true ) {
      puVar12 = (uint *)DAT_5b41_0567;
      uVar21 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
      if (3 < iVar11) break;
      puVar12[iVar11 * 2 + 0x30] = 0;
      puVar12[iVar11 * 2 + 0x2f] = 0;
      iVar11 = iVar11 + 1;
    }
    puVar12[0x3c] = 0;
    local_e = DAT_5b41_0567._2_2_;
    puVar12 = (uint *)FUN_28eb_27be();
    return puVar12;
  case (uint *)0x6:
    puVar12 = (uint *)(uint)DAT_554c_515d;
    if (DAT_554c_515d != 0) {
      func_0x0002fe0c();
      DAT_554c_516f = (uint *)FUN_2fc8_01f3();
      uVar10 = FUN_2fc8_01f3();
      *(uint *)param_2 = uVar10;
      puVar12 = DAT_554c_516f;
      *puVar20 = (uint)DAT_554c_516f;
    }
    return puVar12;
  case (uint *)0x7:
    return local_10;
  case (uint *)0x8:
    if (bVar25 || SCARRY2((int)puVar23,(int)puVar23) != iVar11 < 0) {
      return (uint *)0x1;
    }
    return (uint *)0x0;
  case (uint *)0x9:
    if ((bVar25) || ((puVar20 == puStack_26 && ((uint **)puVar16 == ppuStack_28)))) {
      puVar12 = (uint *)((int)puVar12 + -0x23);
      local_c = (uint *)((int)local_c + -0x23);
      local_e = (uint *)((int)local_e + 0x23);
      local_10 = (uint *)((int)local_10 + 0x23);
    }
    if (((((int)local_a._2_2_ < (int)puVar12) || ((int)local_e <= (int)local_6._2_2_)) ||
        ((int)(uint *)local_a < (int)local_c)) || ((int)local_10 <= (int)(uint *)local_6)) {
      param_2._0_2_ = (uint *)0x0;
    }
    else {
      if ((in_stack_0000ffe8 != (uint *)0x0) && (DAT_5b41_0939 != 9)) {
        puVar13 = unaff_DI + ((uint)(byte)((uint *)param_2)[0x2d] - ((uint *)param_2)[0x2e]);
        local_c = (uint *)(((uint)*(byte *)((int)(uint *)param_2 + 0x5b) + unaff_SI) -
                          ((uint *)param_2)[0x2e]);
        local_e = (uint *)(puVar13 + ((uint *)param_2)[0x2e] * 2);
        iVar11 = ((uint *)param_2)[0x2e] * 2 + (int)local_c;
        if (((uint *)in_stack_0000ffe8[2] == puVar20) && ((uint *)in_stack_0000ffe8[1] == puVar16))
        {
          puVar13 = puVar13 + -0x23;
          local_c = (uint *)((int)local_c + -0x23);
          local_e = (uint *)((int)local_e + 0x23);
        }
        if ((((int)puVar13 <= (int)local_a._2_2_) && ((int)local_6._2_2_ < (int)local_e)) &&
           (((int)local_c <= (int)(uint *)local_a && ((int)(uint *)local_6 < iVar11)))) {
          if ((in_stack_0000ffe8[4] == param_2._2_2_) &&
             ((uint *)in_stack_0000ffe8[3] == (uint *)param_2)) {
            uVar10 = in_stack_0000ffe8[5];
            in_stack_0000ffe8[4] = in_stack_0000ffe8[6];
            in_stack_0000ffe8[3] = uVar10;
            in_stack_0000ffe8[6] = param_2._2_2_;
            in_stack_0000ffe8[5] = (uint)(uint *)param_2;
          }
          return (uint *)in_stack_0000ffe8[1];
        }
      }
      puVar12 = puStack_1a;
      for (local_12 = 0; local_12 < 2; local_12 = local_12 + 1) {
        if (((puVar12 != (uint *)0x0) && (DAT_5b41_0939 != 9)) && (((uint *)param_2)[4] != 7)) {
          cVar9 = (char)((uint *)param_2)[local_12 + 0x3d];
          puVar13 = unaff_DI + cVar9 + -8;
          iVar11 = *(char *)((int)(uint *)param_2 + local_12 * 2 + 0x7b) + unaff_SI;
          local_c = (uint *)(iVar11 + -4);
          local_e = (uint *)(unaff_DI + cVar9 + 8);
          if (((uint *)puVar12[1] == puVar20) && ((uint *)*puVar12 == puVar16)) {
            puVar13 = unaff_DI + cVar9 + -0x2b;
            local_c = (uint *)(iVar11 + -0x27);
            local_e = (uint *)(unaff_DI + cVar9 + 0x2b);
          }
          if ((((int)puVar13 <= (int)local_a._2_2_) && ((int)local_6._2_2_ < (int)local_e)) &&
             (((int)local_c <= (int)(uint *)local_a && ((int)(uint *)local_6 < iVar11 + 4)))) {
            if ((puVar12[3] == param_2._2_2_) && ((uint *)puVar12[2] == (uint *)param_2)) {
              puStack_1a = (uint *)0x2000;
              uStack_1e = (uint *)CONCAT22(0x9bfe,(uint *)uStack_1e);
              FUN_28eb_08be();
            }
            return (uint *)*puVar12;
          }
        }
        puVar12 = uStack_1e._2_2_;
      }
    }
    return (uint *)param_2;
  case (uint *)0xa:
    out(in_DX,0);
    out((char *)((int)in_DX + 1),(char)DAT_554c_5582);
    uVar15 = (undefined1)((uint)DAT_554c_5582 >> 8);
    out(in_DX,uVar15);
    return (uint *)CONCAT11(uVar15,uVar15);
  }
  if ((!bVar25) && (puVar19 < (uint *)0x7d0)) {
    for (puVar12 = (uint *)0x0; (int)puVar12 < 9; puVar12 = (uint *)((int)puVar12 + 1)) {
      if ((uint *)((undefined2 *)&DAT_554c_2f24)[(int)puVar12] == puVar19) {
        puVar19 = (uint *)((undefined2 *)&DAT_554c_2f36)[(int)puVar12];
      }
    }
  }
  puStack_1a = (uint *)0x2000;
  uStack_1e._2_2_ = (uint *)0xeb2a;
  puVar24 = (uint *)FUN_2e67_0c9b();
  if (DAT_5b41_0bee != 0) {
    uStack_1e = (uint *)CONCAT22(puVar24,puVar19);
    uStack_22 = (uint *)0x2000eb43;
    puStack_1a = (uint *)param_2;
    puVar12 = (uint *)FUN_2e67_08ed();
    return puVar12;
  }
  if ((puVar19 < (uint *)0xfa0) && (*(char *)((uint)puVar19 / 1000 + 0x6b94) != '\0')) {
    return (uint *)0x0;
  }
  uVar10 = (uint)puVar19 / 1000;
  if (4 < uVar10) {
    return local_6._2_2_;
  }
  iVar11 = uVar10 * 2;
  uVar21 = 0x2000;
  switch(uVar10) {
  case 1:
    *(int *)(iVar11 + 0x3c) = uVar10 - *(int *)(iVar11 + 0x28);
    *(int *)(iVar11 + 0x3c) = *(int *)(iVar11 + 0x3c) << (9U - param_2._2_1_ & 0x1f);
    uStack_1e = (uint *)0x2000cb79;
    puStack_1a = puVar16;
    puVar12 = (uint *)FUN_549b_007a();
    return puVar12;
  case 2:
    puStack_1a = (uint *)0x1ea;
    puVar12 = (uint *)(*DAT_554c_4d7e)();
    return puVar12;
  case 3:
    *(char *)(puVar12 + (uVar10 - 0x1dd)) = (char)puVar12[uVar10 - 0x1dd] + -1;
    local_a._2_2_ = (uint *)puVar12[1];
    local_a._0_2_ = (uint *)*puVar12;
    local_e = (uint *)(((int)(uint *)local_a - (int)(uint *)local_6) / 2 + (int)(uint *)local_6);
    local_c = (uint *)(((int)local_a._2_2_ - (int)local_6._2_2_) / 2 + (int)local_6._2_2_);
    uStack_1e = (uint *)CONCAT22(&local_e,&local_6);
    uStack_22 = (uint *)0x20005d3e;
    puStack_1a = (uint *)param_2;
    FUN_2424_1a04();
    uStack_22 = (uint *)CONCAT22((uint *)param_2,&local_a);
    ppuStack_24 = &local_e;
    puStack_26 = (uint *)0x2000;
    ppuStack_28 = (uint **)s_Invalid_argument_554c_5d4d;
    FUN_2424_1a04();
    local_6 = (uint *)CONCAT22(((int)local_6._2_2_ - (int)local_c) / 4 + (int)local_c,
                               (char *)((int)local_e + ((int)(uint *)local_6 - (int)local_e) / 4));
    local_e = (uint *)((int)local_e + ((int)(uint *)local_a - (int)local_e) / 4);
    local_c = (uint *)(((int)local_a._2_2_ - (int)local_c) / 4 + (int)local_c);
    puStack_26 = (uint *)param_2;
    ppuStack_28 = &local_e;
    puStack_2a = (uint *)&local_6;
    puStack_2c = (uint *)0x2000;
    puStack_2e = (uint *)0x5d9b;
    puVar12 = (uint *)FUN_2424_1a04();
    DAT_5b41_04aa = DAT_5b41_04aa + -1;
    return puVar12;
  case 4:
    cVar9 = *(char *)(iVar11 + 0x7a);
    do {
      puVar12 = puStack_2c;
      local_6._2_2_ = (uint *)(unaff_DI + cVar9);
      local_6._0_2_ =
           (uint *)(((uint *)uStack_1e)[0x18] +
                   (int)*(char *)((int)(uint *)uStack_1e + (int)puVar19 * 2 + 0x7b));
      uVar22 = uVar21;
      if (((uint **)uStack_22._2_2_ == ppuStack_28) && ((uint *)uStack_22 == puStack_2a)) {
        puStack_1a = uStack_1e._2_2_;
        uStack_1e = (uint *)CONCAT22((uint *)uStack_1e,uVar21);
        uVar22 = 0x28eb;
        uStack_22 = (uint *)CONCAT22(0x561b,(uint *)uStack_22);
        FUN_28eb_3b36();
        puVar19 = puVar12;
      }
      uVar21 = (undefined2)((ulong)uStack_22 >> 0x10);
      puVar12 = (uint *)uStack_22;
      puVar13 = (undefined1 *)(puVar12[0x17] + (int)(char)puVar12[(int)((int)puStack_1a + 0x3d)]);
      uVar10 = puVar12[0x18];
      puVar12 = (uint *)(uVar10 + (int)*(char *)((int)puVar12 + (int)puStack_1a * 2 + 0x7b));
      local_a = (uint *)CONCAT22(puVar13,puVar12);
      if ((int)local_6._2_2_ < (int)puVar13) {
        local_c = (uint *)((int)local_6._2_2_ - DAT_5b41_0925);
      }
      else {
        local_c = (uint *)((int)puVar13 - DAT_5b41_0925);
        puVar13 = (undefined1 *)local_6._2_2_;
      }
      if ((int)(uint *)local_6 < (int)puVar12) {
        local_e = (uint *)((int)(uint *)local_6 - DAT_5b41_0927);
      }
      else {
        local_e = (uint *)((int)puVar12 - DAT_5b41_0927);
        puVar12 = (uint *)local_6;
      }
      iVar11 = (int)puVar12 - DAT_5b41_0927;
      if (0 < (int)uVar10) {
        iVar11 = iVar11 + ((int)uVar10 >> 1);
      }
      uVar10 = (uint)((int)(puVar13 + (-(int)local_c - DAT_5b41_0925)) < iVar11 - (int)local_e);
      local_c = (uint *)((int)local_c - uVar10);
      local_e = (uint *)((int)local_e - (uint)(uVar10 == 0));
      for (puVar18 = DAT_5b41_04ac; uVar21 = uVar22, puVar18 != (undefined2 *)0x0;
          puVar18 = (undefined2 *)*puVar18) {
        if ((((puVar18[6] == 1) && ((int)puVar18[1] <= (int)(puVar13 + (uVar10 - DAT_5b41_0925))))
            && ((int)local_c <= (int)puVar18[3])) &&
           (((int)puVar18[2] <= (int)(iVar11 + (uint)(uVar10 == 0)) &&
            ((int)local_e <= (int)puVar18[4])))) {
          uVar21 = 0x28eb;
          uStack_1e = (uint *)CONCAT22(uVar22,0x571b);
          puStack_1a = puVar16;
          FUN_28eb_2d82();
          uStack_22 = (uint *)CONCAT22(ppuStack_28,puStack_2a);
          puVar19 = puVar24;
          break;
        }
      }
      if (((uint **)uStack_22._2_2_ == ppuStack_28) && ((uint *)uStack_22 == puStack_2a)) {
        uStack_22 = (uint *)0x0;
        uStack_1e._2_2_ = (uint *)0x0;
        uStack_1e._0_2_ = (uint *)0x0;
      }
      else {
        uStack_1e._0_2_ = (uint *)uStack_22;
        uStack_1e._2_2_ = uStack_22._2_2_;
        uStack_22 = (uint *)CONCAT22(((uint *)uStack_22)[0x30],(uint *)((uint *)uStack_22)[0x2f]);
      }
      if ((uint *)uStack_1e == (uint *)0x0 && uStack_1e._2_2_ == (uint *)0x0) {
        return (uint *)0x0;
      }
      if ((uint *)uStack_22 == (uint *)0x0 && uStack_22._2_2_ == (uint *)0x0) {
        return (uint *)0x0;
      }
      if (((uint **)uStack_1e._2_2_ != ppuStack_24) || ((uint *)uStack_1e != puStack_26)) {
        puVar19 = (uint *)0x1;
      }
      unaff_DI = (undefined1 *)((uint *)uStack_1e)[0x17];
      cVar9 = (char)((uint *)uStack_1e)[(int)puVar19 + 0x3d];
      puVar20 = uStack_1e._2_2_;
    } while( true );
  }
  *(uint *)(iVar11 + 0x7c) = uVar10;
  uVar22 = (undefined2)((ulong)local_a >> 0x10);
  ((uint *)local_a)[0x4c] = puVar16[0x4c];
  uVar10 = *(uint *)(*(int *)(puVar16[4] * 2 + 0x302) + 0x22);
  ((uint *)local_a)[0x4b] = uVar10;
  if ((uVar10 != 0) && (*(int *)(*(int *)(puVar16[4] * 2 + 0x302) + 0x46) == 0)) {
    local_c = (uint *)puVar16[0x4c];
    puStack_1a = (uint *)0x2000;
    uVar21 = 0x1000;
    uStack_1e._2_2_ = (uint *)0xc07a;
    puVar12 = (uint *)FUN_1000_12bf();
    uVar22 = (undefined2)((ulong)local_a >> 0x10);
    ((uint *)local_a)[0x4c] = (uint)puVar12;
    if (puVar12 == (uint *)0x0) {
      local_6 = (uint *)CONCAT22(local_6._2_2_,(uint *)0x1);
      goto LAB_28eb_3257;
    }
    local_6 = (uint *)((ulong)local_6 & 0xffff);
    while ((int)local_6._2_2_ < (int)((uint *)local_a)[0x4b]) {
      *puVar12 = *local_c;
      puVar12[1] = local_c[1];
      puVar12[2] = local_c[2];
      puVar12 = puVar12 + 3;
      local_c = local_c + 3;
      local_6 = (uint *)CONCAT22((int)local_6._2_2_ + 1,(uint *)local_6);
    }
  }
  uVar22 = (undefined2)((ulong)local_a >> 0x10);
  puVar12 = (uint *)local_a;
  puVar12[0x54] = puVar16[0x54];
  puVar12[0x55] = puVar16[0x55];
  puVar12[0x56] = puVar16[0x56];
  puVar4 = (undefined2 *)(*(int *)(puVar12[4] * 2 + 0x302) + 8);
  uStack_1e._2_2_ = (uint *)0xc104;
  puStack_1a = (uint *)uVar21;
  (*(code *)*puVar4)();
LAB_28eb_3257:
  if ((uint *)local_6 != (uint *)0x0) {
    if ((uint *)local_a != (uint *)0x0 || local_a._2_2_ != (uint *)0x0) {
      uStack_1e = (uint *)CONCAT22(0xc120,(uint *)uStack_1e);
      puStack_1a = (uint *)uVar21;
      FUN_2321_0c23();
      local_a = (uint *)0x0;
    }
  }
  return (uint *)local_a;
}

