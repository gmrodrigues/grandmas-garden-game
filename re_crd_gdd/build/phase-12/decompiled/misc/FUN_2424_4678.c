// TIM2.EXE: FUN_2424_4678 @ file 0x02DAB8 Ghidra 0x288B8
// Subsystem: misc | Size: 228 bytes


/* WARNING: Instruction at (ram,0x000254bc) overlaps instruction at (ram,0x000254bb)
    */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl16far FUN_2424_4678(uint *param_1,uint *param_2,undefined2 param_3)

{
  uint *puVar1;
  undefined1 auVar2 [2];
  undefined1 uVar3;
  char cVar4;
  uint uVar5;
  undefined2 *puVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined2 uVar15;
  undefined2 *puVar16;
  int in_CX;
  undefined1 *in_DX;
  uint *puVar17;
  uint uVar18;
  uint *in_ESI;
  undefined1 *unaff_DI;
  undefined2 uVar19;
  uint *unaff_SS;
  byte in_AF;
  undefined1 in_XMM4 [16];
  long lVar20;
  uint *puStack_24;
  undefined1 *puStack_22;
  uint *in_stack_0000ffe0;
  undefined1 *puStack_1e;
  uint *puStack_1c;
  uint *puStack_1a;
  uint *puStack_18;
  uint *puVar21;
  undefined1 auStack_12 [2];
  undefined1 local_10 [2];
  undefined4 local_e;
  uint uStack_a;
  uint *local_8;
  undefined4 local_6;
  
  auStack_12[0] = SUB41(in_ESI,0);
  auStack_12[1] = (byte)((ulong)in_ESI >> 8);
  puStack_18 = (uint *)*(undefined2 *)(((uint *)param_1)[4] * 2 + 0x68fe);
  local_6 = (uint *)CONCAT22(local_6._2_2_,puStack_18);
  puVar21 = (uint *)0x3;
  puStack_1a = (uint *)0x2424;
  puStack_1c = (uint *)0x88d8;
  puVar11 = (uint *)FUN_4551_0370();
  local_8 = puVar11;
  uVar19 = (undefined2)((ulong)param_1 >> 0x10);
  puVar17 = (uint *)param_1;
  puVar12 = puVar11;
  auVar2 = local_10;
  iVar10 = (int)local_e;
  if (puVar17[0x57] == 0) {
LAB_2424_4702:
    do {
      local_e._1_1_ = (undefined1)((uint)iVar10 >> 8);
      local_10[1] = (undefined1)((uint)auVar2 >> 8);
      local_10[0] = SUB21(auVar2,0);
      uVar19 = (undefined2)((ulong)param_1 >> 0x10);
      puVar11 = (uint *)param_1;
      if (puVar11[0x5a] == 0) {
        return puVar12;
      }
      local_6 = (uint *)CONCAT22(puVar11[0x5a],(uint *)local_6);
      puVar17 = (uint *)(puVar11[0x11] - DAT_5b41_0925);
      in_ESI = (uint *)CONCAT22((int)((ulong)in_ESI >> 0x10),puVar17);
      puVar12 = (uint *)(puVar11[0x12] - DAT_5b41_0927);
      uVar18 = puVar11[0x5a] - 2;
      local_e._0_2_ = iVar10;
      if (10 < uVar18) {
        local_10 = auVar2;
        FUN_4551_03eb();
        local_10 = (undefined1  [2])((int)local_10 + (int)(uint *)in_ESI);
        local_e._0_2_ = (int)local_e + (int)puVar12;
        puVar12 = (uint *)FUN_2424_1e00();
        return puVar12;
      }
      puVar11 = (uint *)(uVar18 * 2);
      bVar8 = (byte)puVar12;
      switch(uVar18) {
      case 0:
        *(byte *)(uint *)((int)puVar11 + (int)puVar17) =
             (char)*(uint *)((int)puVar11 + (int)puVar17) + bVar8;
        break;
      case 1:
        puVar1 = puVar17;
        *puVar1 = *puVar1 + (uint)CARRY2(uVar18,uVar18) * (((uint)puVar12 & 3) - (*puVar1 & 3));
        uVar3 = in(in_DX);
        *(undefined1 *)puVar12 = uVar3;
        puVar1 = (uint *)(&stack0xfffe + (int)puVar17);
        *puVar1 = *puVar1 + (uint)(auStack_12[1] < (byte)puVar12[0x1e]) *
                            (((uint)(puVar12 + 1) & 3) - (*puVar1 & 3));
        puVar21 = puVar12 + 2;
        uVar18 = in(in_DX);
        puVar12[1] = uVar18;
        local_10[1] = SUB21(puVar21,0);
        local_e._0_1_ = (undefined1)((uint)puVar21 >> 8);
        puVar16 = (undefined2 *)((int)&local_6 + 3);
        uVar15 = in(in_DX);
        bVar8 = 9 < ((byte)uVar15 & 0xf) | 9 < ((bVar8 ^ 0x38) & 0xf) | in_AF;
        if ((int)auVar2 + 1U == 1 || (char)((int)auVar2 + 1U) == (char)((uint)unaff_DI >> 8)) {
          bVar9 = ((byte)uVar15 + bVar8 * '\x06' & 0xf) % 0x37;
          puVar6 = (undefined2 *)((int)auStack_12 + 1);
          auStack_12[1] = (byte)puVar16;
          local_10[0] = (undefined1)((uint)puVar16 >> 8);
          cVar7 = '\x16';
          unique0x10000a7c = puVar16;
          unique0x10000a8a = puVar21;
          do {
            puVar16 = puVar16 + -1;
            puVar6 = puVar6 + -1;
            *puVar6 = *puVar16;
            cVar7 = cVar7 + -1;
          } while ('\0' < cVar7);
          puVar1 = puVar21;
          bVar8 = 9 < (bVar9 & 0xf) | bVar8;
          _DAT_5000_eaf7 = CONCAT11(bVar8,bVar9 + bVar8 * '\x06') & 0xff0f;
          uVar3 = *unaff_DI;
          puVar21 = stack0xfff1;
          if (((int)(uint)bVar9 < (int)*puVar1) && (SBORROW2((uint)bVar9,*puVar1))) {
            *(uint *)(unaff_DI + -1) = *(uint *)(unaff_DI + -1) ^ (uint)puVar17;
            DAT_554c_36f1 = DAT_554c_36f1 + '\x01';
            puVar16 = (undefined2 *)in(0x36);
            *(undefined1 *)(puVar12 + 3) = *(undefined1 *)0xb136;
            *(undefined2 *)0x367c = puVar16;
            out(*puVar16,CONCAT11(uVar3,(char)in_DX));
          }
        }
        else {
          out(*puVar17,in_DX);
        }
        unique0x10000a84 = puVar21;
        puVar12 = (uint *)FUN_28eb_4cfc();
        return puVar12;
      case 2:
        out(in_DX,bVar8);
        puVar21 = (uint *)(in_CX + (int)(((long)((int)puVar12 - in_CX) *
                                         (long)(int)(puVar12 + -uVar18)) /
                                        (long)(int)(&stack0xfffe + uVar18 * -2)));
        if (DAT_554c_42ca < puVar21) {
          puVar11 = puVar21;
          puVar17 = DAT_554c_42c4;
          if (DAT_554c_42ca < puVar12) {
            return DAT_554c_42ca;
          }
        }
        else {
          puVar11 = DAT_554c_42c4;
          if (puVar12 <= DAT_554c_42ca) goto LAB_1a9e_57cd;
          in_ESI = (uint *)ZEXT24(DAT_554c_42c4);
          puVar11 = puVar12;
          puVar12 = puVar21;
        }
        puVar11 = (uint *)((int)puVar17 +
                          (int)(((long)((int)(uint *)in_ESI - (int)puVar17) *
                                (long)((int)DAT_554c_42ca - (int)puVar11)) /
                               (long)((int)puVar12 - (int)puVar11)));
LAB_1a9e_57cd:
        if ((puVar11 <= DAT_554c_42c6) || (puVar12 = DAT_554c_42c6, (uint *)in_ESI <= DAT_554c_42c6)
           ) {
          puVar12 = (uint *)(*DAT_554c_4d7e)();
        }
        return puVar12;
      case 3:
        goto LAB_2424_4a1f;
      case 4:
        return (uint *)*(uint **)puVar17;
      case 5:
        movmskps(in_ESI,in_XMM4);
        do {
          uVar18 = puVar11[0x11];
          uVar5 = puVar11[0x12];
          *(int *)((int)&local_e + in_CX + 2) = puVar11[0x2a] + uVar18;
          *(int *)((int)&local_e + in_CX) = puVar11[0x2b] + uVar5;
          if (((((int)uVar18 < *(int *)((int)&local_8 + in_CX)) &&
               (*(int *)((int)&local_6 + in_CX + 2) < *(int *)((int)&local_e + in_CX + 2))) &&
              ((int)uVar5 < *(int *)((int)&uStack_a + in_CX))) &&
             (*(int *)((int)&local_6 + in_CX) < *(int *)((int)&local_e + in_CX))) {
            iVar10 = FUN_28eb_024e();
            if (iVar10 != 0) {
              return (uint *)0x1;
            }
            iVar10 = FUN_28eb_03ff();
            if (iVar10 != 0) {
              return (uint *)0x1;
            }
            iVar10 = FUN_28eb_03ff();
            if (iVar10 != 0) {
              return (uint *)0x1;
            }
          }
          do {
            do {
              do {
                uVar19 = FUN_28eb_32d8();
                *(undefined1 **)(local_10 + in_CX) = in_DX;
                *(undefined2 *)(auStack_12 + in_CX) = uVar19;
                if (*(int *)(auStack_12 + in_CX) == 0 && *(int *)(local_10 + in_CX) == 0) {
                  return (uint *)0x0;
                }
                iVar10 = FUN_28eb_00cb();
              } while (iVar10 != 0);
              in_DX = *(undefined1 **)(local_10 + in_CX);
            } while ((in_DX == (undefined1 *)*(uint *)((int)&param_1 + in_CX + 2)) &&
                    (*(int *)(auStack_12 + in_CX) == *(int *)((int)&param_1 + in_CX)));
            uVar19 = (undefined2)((ulong)*(uint **)(auStack_12 + in_CX) >> 0x10);
            puVar11 = (uint *)*(uint **)(auStack_12 + in_CX);
          } while (((*(byte *)((int)puVar11 + 0xd) & 0x20) != 0) ||
                  ((*(byte *)((int)puVar11 + 0xf) & 0x50) != 0));
        } while( true );
      case 6:
        *(uint *)((int)puVar11 + (int)puVar17) =
             *(uint *)((int)puVar11 + (int)puVar17) + (int)puVar12;
        if ((puVar12 == (uint *)0x0) || (DAT_554c_5740 == 0 && DAT_554c_5742 == 0)) {
          DAT_5b41_0c40 = 0;
        }
        else {
          DAT_5b41_0c40 = 1;
        }
        DAT_5b41_0c42 = (uint)(DAT_554c_5744 != 0 || DAT_554c_5746 != 0);
        FUN_2e67_0231();
        return DAT_5b41_0bec;
      case 7:
        goto switchD_2000_8976_caseD_7;
      case 8:
        goto switchD_2000_8802_caseD_7;
      case 9:
        goto switchD_2000_8b75_caseD_3;
      case 10:
        func_0x0002fe0c();
        goto switchD_2000_8910_caseD_6;
      }
    } while( true );
  }
  local_6 = (uint *)CONCAT22(puVar17[0x57],(uint *)local_6);
  in_ESI = (uint *)CONCAT22((int)((ulong)in_ESI >> 0x10),(uint *)(puVar17[0x11] - DAT_5b41_0925));
  puVar12 = (uint *)(puVar17[0x12] - DAT_5b41_0927);
  uVar18 = puVar17[0x57] - 1;
  if (8 < uVar18) {
    puStack_18 = (uint *)local_10;
    puStack_1c = (uint *)local_6;
    FUN_4551_03eb();
    local_10 = (undefined1  [2])(CONCAT11(local_10[1],local_10[0]) + (int)(uint *)in_ESI);
    local_e._0_2_ = CONCAT11(local_e._1_1_,(undefined1)local_e) + (int)puVar12;
    puStack_1e = (undefined1 *)0x2;
    puStack_22 = local_10;
    puStack_24 = (uint *)0x4551;
    puVar12 = (uint *)FUN_2424_1e00();
    in_stack_0000ffe0 = unaff_SS;
    puStack_1a = puVar11;
    puVar21 = unaff_SS;
    auVar2 = local_10;
    iVar10 = (int)local_e;
    goto LAB_2424_4702;
  }
  switch(uVar18) {
  case 0:
    do {
      puVar12 = (uint *)in_ESI;
      if (puVar12[6] == 1) {
        if ((int)puVar12[1] < (int)local_10) {
code_r0x000254be:
          puVar12 = (uint *)in_ESI;
          if ((((int)local_e._2_2_ <= (int)puVar12[3]) && ((int)puVar12[2] < (int)auStack_12)) &&
             ((int)local_e <= (int)puVar12[4])) {
LAB_2424_12b5:
            FUN_28eb_2d82();
            goto LAB_2424_12ce;
          }
        }
LAB_2424_1296:
        puVar12 = (uint *)in_ESI;
        if ((local_8 != (uint *)0x0) || (uStack_a != 0)) {
          iVar10 = FUN_2424_36fe();
          if (iVar10 != 0) goto LAB_2424_12b5;
        }
      }
      uVar18 = *puVar12;
LAB_2424_12ca:
      in_ESI = (uint *)(ulong)uVar18;
      if (uVar18 == 0) {
LAB_2424_12ce:
        do {
          do {
            do {
              do {
                while( true ) {
                  do {
                    while( true ) {
                      while( true ) {
                        uVar18 = ((uint *)local_6)[1];
                        puVar12 = (uint *)*local_6;
                        local_6 = (uint *)CONCAT22(uVar18,puVar12);
                        if (puVar12 != (uint *)0x0 || uVar18 != 0) break;
                        unaff_DI = unaff_DI + 1;
                        if (1 < (int)unaff_DI) {
                          return (uint *)0x0;
                        }
                        if (unaff_DI == (undefined1 *)0x0) {
                          puVar12 = (uint *)&DAT_5b41_054f;
                        }
                        else {
                          puVar12 = (uint *)&DAT_5b41_0557;
                        }
                        local_6 = (uint *)CONCAT22(0x554c,puVar12);
                      }
                      if (DAT_5b41_04b4 == 0) break;
                      DAT_5b41_04b4 = 0;
                      unaff_DI = (undefined1 *)0x0;
                      local_6 = &DAT_5b41_054f;
                    }
                    if ((char)puVar12[0xc] == -0x80) {
                      *(undefined1 *)(puVar12 + 0xc) = 0;
                    }
                    if ((*(byte *)((int)puVar12 + 0xf) & 0x20) == 0) {
                      local_8 = (uint *)0x0;
                      uStack_a = 0;
                    }
                    else {
                      uStack_a = puVar12[0x57];
                      local_8 = (uint *)puVar12[0x5a];
                    }
                  } while ((((char)puVar12[0xc] != '\0') ||
                           ((*(byte *)((int)puVar12 + 0xd) & 0x20) != 0)) ||
                          ((*(byte *)((int)puVar12 + 0xf) & 0x40) != 0));
                  if ((puVar12[4] != 10) && (puVar12[4] != 0x4c)) break;
                  FUN_2424_12f5();
                }
              } while (puVar12[4] == 0x31);
              if (puVar12[4] != 8) {
                local_e._2_2_ = (undefined1 *)(puVar12[0x17] - DAT_5b41_0925);
                local_e._0_2_ = puVar12[0x18] - DAT_5b41_0927;
                local_10 = (undefined1  [2])(puVar12[0x24] + (int)local_e._2_2_);
                auStack_12 = (undefined1  [2])(puVar12[0x25] + (int)local_e);
                uVar18 = DAT_5b41_04ac;
                goto LAB_2424_12ca;
              }
              uVar5 = puVar12[0x2c];
            } while (uVar5 == 0);
            iVar10 = FUN_28eb_1c08();
          } while (iVar10 == 0);
          if ((DAT_5b41_0939 != 9) ||
             (((*(int *)(uVar5 + 8) != DAT_5b41_0567._2_2_ ||
               (*(int *)(uVar5 + 6) != (int)DAT_5b41_0567)) &&
              ((*(int *)(uVar5 + 0xc) != DAT_5b41_0567._2_2_ ||
               (*(int *)(uVar5 + 10) != (int)DAT_5b41_0567)))))) break;
          iVar10 = FUN_28eb_4d94();
        } while (iVar10 == 0);
        if (*(int *)(uVar5 + 0xe) < *(int *)(uVar5 + 0x12)) {
          local_e._2_2_ = (undefined1 *)(*(int *)(uVar5 + 0xe) - DAT_5b41_0925);
          iVar10 = *(int *)(uVar5 + 0x1a) - *(int *)(uVar5 + 0xe);
        }
        else {
          local_e._2_2_ = (undefined1 *)(*(int *)(uVar5 + 0x12) - DAT_5b41_0925);
          iVar10 = *(int *)(uVar5 + 0x16) - *(int *)(uVar5 + 0x12);
        }
        local_10 = (undefined1  [2])((int)local_e._2_2_ + iVar10);
        uVar18 = DAT_5b41_04ac;
        if (*(int *)(uVar5 + 0x10) < *(int *)(uVar5 + 0x14)) {
          local_e._0_2_ = *(int *)(uVar5 + 0x10) - DAT_5b41_0927;
          auStack_12 = (undefined1  [2])
                       ((int)local_e + (*(int *)(uVar5 + 0x1c) - *(int *)(uVar5 + 0x10)));
        }
        else {
          local_e._0_2_ = *(int *)(uVar5 + 0x14) - DAT_5b41_0927;
          auStack_12 = (undefined1  [2])
                       ((int)local_e + (*(int *)(uVar5 + 0x18) - *(int *)(uVar5 + 0x14)));
        }
        goto LAB_2424_12ca;
      }
    } while( true );
  case 2:
    puVar12 = (uint *)CONCAT11((char)((uint)puVar12 >> 8),DAT_554c_5596);
    if ((DAT_554c_5596 == '\0') &&
       (puVar12 = (uint *)0x0, DAT_554c_517c != (code *)0x0 || DAT_554c_517e != 0)) {
      DAT_554c_5596 = '\x01';
      FUN_1a9e_5938();
      (*DAT_554c_517c)();
      puVar12 = (uint *)FUN_1a9e_599d();
      DAT_554c_5596 = DAT_554c_5596 + -1;
    }
    return puVar12;
  case 3:
    do {
      puVar12 = (uint *)in_ESI;
      FUN_3e34_0ec9();
      uVar18 = (int)puVar12 + ((uint *)local_6)[3];
      in_ESI = (uint *)(ulong)uVar18;
    } while ((int)uVar18 < CONCAT11(local_e._1_1_,(undefined1)local_e));
    puVar12 = (uint *)FUN_2424_02ca();
    return puVar12;
  case 4:
    return puVar12;
  case 5:
    puVar11 = (uint *)0x88d8;
    in_DX = puRam0005dd9a;
switchD_2000_8b75_caseD_3:
    if (((uint *)param_1 != (uint *)0x0 || param_1._2_2_ != (undefined2 *)0x0) &&
       (((((param_1._2_2_ == (undefined2 *)param_2._2_2_ && ((uint *)param_1 == (uint *)param_2)) ||
          ((param_1._2_2_ == (undefined2 *)puStack_1e && ((uint *)param_1 == in_stack_0000ffe0))))
         || ((param_1._2_2_ == (undefined2 *)puStack_22 && ((uint *)param_1 == puStack_24)))) ||
        ((param_1._2_2_ == (undefined2 *)in_DX && ((uint *)param_1 == (uint *)*puVar11)))))) {
      puVar12 = (uint *)((int)puVar12 + -0x23);
      local_e._2_2_ = (undefined1 *)((int)local_e._2_2_ + -0x23);
      iVar10 = iVar10 + 0x23;
      auVar2 = (undefined1  [2])((int)auVar2 + 0x23);
    }
    if (((((int)local_8 < (int)puVar12) || (iVar10 <= local_6._2_2_)) ||
        ((int)uStack_a < (int)local_e._2_2_)) || ((int)auVar2 <= (int)(uint *)local_6)) {
      param_2._0_2_ = (uint *)0x0;
    }
    else {
      if ((puStack_18 != (uint *)0x0) && (DAT_5b41_0939 != 9)) {
        iVar13 = (int)puVar21 + ((uint)(byte)((uint *)param_2)[0x2d] - ((uint *)param_2)[0x2e]);
        local_e._2_2_ =
             unaff_DI + ((uint)*(byte *)((int)(uint *)param_2 + 0x5b) - ((uint *)param_2)[0x2e]);
        iVar10 = ((uint *)param_2)[0x2e] * 2 + iVar13;
        puVar14 = local_e._2_2_ + ((uint *)param_2)[0x2e] * 2;
        if (((undefined2 *)puStack_18[2] == param_1._2_2_) &&
           ((uint *)puStack_18[1] == (uint *)param_1)) {
          iVar13 = iVar13 + -0x23;
          local_e._2_2_ = local_e._2_2_ + -0x23;
          iVar10 = iVar10 + 0x23;
        }
        if (((iVar13 <= (int)local_8) && (local_6._2_2_ < iVar10)) &&
           (((int)local_e._2_2_ <= (int)uStack_a && ((int)(uint *)local_6 < (int)puVar14)))) {
          if (((undefined1 *)puStack_18[4] == param_2._2_2_) &&
             ((uint *)puStack_18[3] == (uint *)param_2)) {
            uVar18 = puStack_18[5];
            puStack_18[4] = puStack_18[6];
            puStack_18[3] = uVar18;
            puStack_18[6] = (uint)param_2._2_2_;
            puStack_18[5] = (uint)(uint *)param_2;
          }
          return (uint *)puStack_18[1];
        }
      }
      for (auStack_12 = (undefined1  [2])0x0; (int)auStack_12 < 2;
          auStack_12 = (undefined1  [2])((int)auStack_12 + 1)) {
        if (((puStack_1a != (uint *)0x0) && (DAT_5b41_0939 != 9)) && (((uint *)param_2)[4] != 7)) {
          cVar7 = (char)((uint *)param_2)[(int)auStack_12 + 0x3d];
          iVar10 = (int)puVar21 + cVar7 + -8;
          cVar4 = *(char *)((int)(uint *)param_2 + (int)auStack_12 * 2 + 0x7b);
          local_e._2_2_ = unaff_DI + cVar4 + -4;
          local_e._0_2_ = (int)puVar21 + cVar7 + 8;
          local_10 = (undefined1  [2])(unaff_DI + cVar4 + 4);
          if (((undefined2 *)puStack_1a[1] == param_1._2_2_) &&
             ((uint *)*puStack_1a == (uint *)param_1)) {
            iVar10 = (int)puVar21 + cVar7 + -0x2b;
            local_e._2_2_ = unaff_DI + cVar4 + -0x27;
            local_e._0_2_ = (int)puVar21 + cVar7 + 0x2b;
          }
          if (((iVar10 <= (int)local_8) && (local_6._2_2_ < (int)local_e)) &&
             (((int)local_e._2_2_ <= (int)uStack_a && ((int)(uint *)local_6 < (int)local_10)))) {
            if (((undefined1 *)puStack_1a[3] == param_2._2_2_) &&
               ((uint *)puStack_1a[2] == (uint *)param_2)) {
              FUN_28eb_08be();
            }
            return (uint *)*puStack_1a;
          }
        }
        puStack_1a = puStack_1c;
      }
    }
    return (uint *)param_2;
  case 6:
switchD_2000_8910_caseD_6:
    DAT_554c_516f = (uint *)FUN_2fc8_01f3();
    uVar18 = FUN_2fc8_01f3();
    *(uint *)param_2 = uVar18;
    puVar12 = DAT_554c_516f;
    *param_1._2_2_ = DAT_554c_516f;
    return puVar12;
  case 7:
    if (SCARRY2(uVar18,uVar18) == (int)(uVar18 * 2) < 0) goto LAB_2424_1296;
    goto code_r0x000254be;
  case 8:
switchD_2000_8802_caseD_7:
    uVar19 = (undefined2)((ulong)param_1 >> 0x10);
    puVar12 = (uint *)param_1;
    if ((*(int *)(*(int *)(puVar12[4] * 2 + 0x302) + 0x2a) == 0) &&
       (*(int *)(*(int *)(puVar12[4] * 2 + 0x302) + 0x2c) == 0)) {
      uVar18 = puVar12[0x23];
      puVar21 = (uint *)puVar12[0x22];
    }
    else {
      iVar10 = *(int *)(puVar12[4] * 2 + 0x302);
      uVar18 = *(uint *)(iVar10 + 0x2c);
      puVar21 = (uint *)*(undefined2 *)(iVar10 + 0x2a);
    }
    puVar12[0x2b] = uVar18;
    puVar12[0x2a] = (uint)puVar21;
    return puVar21;
  }
  puVar1 = (uint *)(puVar17[0x11] - DAT_5b41_0925) + uVar18;
  uVar5 = (int)puVar12 + *puVar1;
  (&stack0x02c2)[(int)puVar12] =
       (&stack0x02c2)[(int)puVar12] + (char)uVar5 + CARRY2(uVar18,uVar18) +
       (CARRY2((uint)puVar12,*puVar1) || CARRY2(uVar5,(uint)CARRY2(uVar18,uVar18)));
  uVar18 = puVar17[4];
  if (uVar18 != 0x5b) {
    if ((int)uVar18 < 0x5c) {
      if (uVar18 != 0x4c) {
        if (0x4c < (int)uVar18) {
          if (uVar18 != 0x57) goto LAB_2321_0cd1;
          goto LAB_2321_0cc9;
        }
        if ((uVar18 != 7) && (uVar18 != 10)) goto LAB_2321_0cd1;
      }
      if (puVar17[0x3b] == 0) goto LAB_2321_0cd1;
    }
    else if (((uVar18 != 0x5c) && (uVar18 != 0x5d)) && (uVar18 != 0x5f)) goto LAB_2321_0cd1;
  }
LAB_2321_0cc9:
  FUN_1000_130c();
LAB_2321_0cd1:
  uVar19 = (undefined2)((ulong)param_1 >> 0x10);
  puVar12 = (uint *)param_1;
  puVar12[1] = DAT_5b41_04ff;
  *param_1 = (uint)DAT_5b41_04fd;
  DAT_5b41_04ff = uVar19;
  DAT_5b41_04fd = puVar12;
  return puVar12;
switchD_2000_8976_caseD_7:
  while ((puVar21 = (uint *)in_ESI, puVar12 != (uint *)0x0 || puVar11[-0x3d6c] != 0 &&
         ((int)puVar21 < 0x14))) {
    puVar11 = (uint *)(((int)puVar21 + 1U) * 4);
    puVar12 = (uint *)puVar11[-0x3d6d];
    in_ESI = (uint *)(ulong)((int)puVar21 + 1U);
  }
  if ((int)puVar21 < 0x14) {
    iVar10 = FUN_1a9e_6ea7();
    if (iVar10 == 0) {
      local_6 = (uint *)CONCAT22(1,(uint *)local_6);
      FUN_1a9e_69e9();
    }
    else {
      local_6 = (uint *)((ulong)local_6 & 0xffff);
    }
    iVar10 = FUN_1a9e_6a85();
    if ((in_DX == (undefined1 *)0xffff) && (iVar10 == -1)) {
      puVar21 = (uint *)0x0;
    }
    else {
      FUN_1000_0d10();
      if (((char)puVar21[0x217a] == -3) || ((char)puVar21[0x217a] == -1)) {
        *(char *)(puVar21 + -0x3d77) = -(char)puVar21[0x217a];
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1a9e_6e3d();
        local_8 = (uint *)FUN_28eb_2779();
        uStack_a = (uint)((int)local_8 < 0);
        if (uStack_a == 0) {
          puVar12 = (uint *)FUN_28eb_2ba9();
          uStack_a = (uint)(puVar12 != (uint *)local_6);
        }
        lVar20 = CONCAT22(local_e._2_2_,(int)local_e);
        if (uStack_a == 0) {
          lVar20 = FUN_2fc8_00fc();
          uStack_a = (uint)(lVar20 == 0);
        }
        if (uStack_a == 0) {
          local_e = lVar20;
          puVar12 = (uint *)FUN_28eb_2aad();
          uStack_a = (uint)(puVar12 != (uint *)local_6);
          lVar20 = local_e;
        }
        local_e._2_2_ = (undefined1 *)((ulong)lVar20 >> 0x10);
        local_e._0_2_ = (int)lVar20;
        if (uStack_a == 0) {
          ((undefined2 *)&DAT_5b41_2678)[(int)puVar21 * 2] = local_e._2_2_;
          ((undefined2 *)&DAT_5b41_2676)[(int)puVar21 * 2] = (int)local_e;
          local_e._0_2_ = (int)local_e + (uint)(byte)puVar21[0x2198] * 2;
          *(undefined1 **)((undefined *)&DAT_5b41_2628 + (int)puVar21 * 4) = local_e._2_2_;
          ((undefined2 *)&DAT_5b41_2626)[(int)puVar21 * 2] = (int)local_e;
          local_e._0_2_ = (int)local_e + (uint)(byte)puVar21[0x2198];
          ((undefined2 *)&DAT_5b41_25d8)[(int)puVar21 * 2] = local_e._2_2_;
          ((undefined2 *)&DAT_5b41_25d6)[(int)puVar21 * 2] = (int)local_e;
        }
        FUN_28eb_29db();
        if (uStack_a != 0) {
          if ((int)local_e != 0 || local_e._2_2_ != (undefined1 *)0x0) {
            func_0x0002fdf5();
          }
          puVar21 = (uint *)0x0;
        }
      }
      else {
        if ((char)puVar21[0x217a] == -2) {
          *(undefined1 *)(puVar21 + -0x3d77) = 2;
          FUN_1000_0d10();
          local_6._0_2_ = (uint *)(uint)(byte)puVar21[0x217a];
        }
        else {
          *(undefined1 *)(puVar21 + -0x3d77) = 0;
          local_6._0_2_ = (uint *)((int)((byte)puVar21[0x217a] + 7) >> 3);
        }
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        local_6 = (uint *)CONCAT22(local_6._2_2_,
                                   (uint *)((int)(uint *)local_6 *
                                           (uint)(byte)puVar21[0x2184] * (uint)(byte)puVar21[0x2198]
                                           ));
        iVar10 = FUN_1000_127a();
        local_10[0] = (undefined1)iVar10;
        local_10[1] = (undefined1)((uint)iVar10 >> 8);
        uStack_a = (uint)(iVar10 == 0);
        if (uStack_a == 0) {
          FUN_1000_0d10();
        }
        if (uStack_a == 0) {
          ((undefined2 *)&DAT_5b41_25d8)[(int)puVar21 * 2] = 0x554c;
          ((undefined2 *)&DAT_5b41_25d6)[(int)puVar21 * 2] = CONCAT11(local_10[1],local_10[0]);
          ((undefined2 *)&DAT_5b41_2678)[(int)puVar21 * 2] = 0;
          ((undefined2 *)&DAT_5b41_2676)[(int)puVar21 * 2] = 0;
          *(undefined2 *)((undefined *)&DAT_5b41_2628 + (int)puVar21 * 4) = 0;
          ((undefined2 *)&DAT_5b41_2626)[(int)puVar21 * 2] = 0;
        }
        else {
          if (CONCAT11(local_10[1],local_10[0]) != 0) {
            FUN_1000_130c();
          }
          puVar21 = (uint *)0x0;
        }
      }
    }
    if (local_6._2_2_ != 0) {
      FUN_1a9e_6e73();
    }
  }
  else {
    puVar21 = (uint *)0x0;
  }
  return puVar21;
LAB_2424_4a1f:
  do {
    puVar11 = (uint *)in_ESI;
    puVar12 = (uint *)puVar11[1];
    uVar18 = puVar11[2];
    puVar21 = (uint *)puVar11[3];
    local_6 = (uint *)CONCAT22(uVar18,puVar21);
    local_8 = (uint *)puVar11[4];
    local_10 = auVar2;
    local_e._0_2_ = iVar10;
    if ((((int)puVar12 <= (int)auVar2) && ((int)auVar2 + (int)local_e._2_2_ <= (int)puVar21)) &&
       (((int)uVar18 <= iVar10 && ((int)(iVar10 + uStack_a) <= (int)local_8)))) {
      FUN_2424_02ca();
      puVar12 = (uint *)FUN_4551_01dc();
      return puVar12;
    }
    if (((((int)auVar2 <= (int)puVar21) && ((int)puVar12 <= (int)auVar2 + (int)local_e._2_2_)) &&
        (iVar10 <= (int)local_8)) &&
       ((((int)uVar18 <= (int)(iVar10 + uStack_a) && ((int)puVar12 < (int)puVar21)) &&
        ((int)uVar18 <= (int)local_8)))) {
      DAT_554c_42c3 = 1;
      DAT_554c_42c4 = puVar12;
      DAT_554c_42c6 = puVar21;
      DAT_554c_42c8 = uVar18;
      DAT_554c_42ca = local_8;
      FUN_4551_01dc();
      auVar2 = local_10;
      iVar10 = (int)local_e;
    }
    in_ESI = (uint *)(ulong)*puVar11;
  } while (*puVar11 != 0);
  local_10 = auVar2;
  local_e._0_2_ = iVar10;
  puVar12 = (uint *)FUN_2424_02ca();
  return puVar12;
}

