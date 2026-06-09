// TIM2.EXE: FUN_2424_3d5f @ file 0x02D19F Ghidra 0x27F9F
// Subsystem: misc | Size: 277 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00023d1a) overlaps instruction at (ram,0x00023d19)
    */
/* WARNING: Removing unreachable block (ram,0x00021c09) */
/* WARNING: Removing unreachable block (ram,0x00020f66) */
/* WARNING: Removing unreachable block (ram,0x00020ed9) */
/* WARNING: Removing unreachable block (ram,0x00020e20) */
/* WARNING: Removing unreachable block (ram,0x00020d93) */
/* WARNING: Removing unreachable block (ram,0x0002eb76) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * __cdecl16far
FUN_2424_3d5f(long param_1,int *param_2,byte param_3,undefined2 param_4,int param_5)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint in_DX;
  char cVar9;
  int iVar7;
  uint uVar8;
  undefined2 *puVar10;
  byte *unaff_SI;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  undefined2 uVar14;
  int *piVar15;
  byte *pbVar16;
  undefined2 unaff_SS;
  bool bVar17;
  undefined1 auStack_1f6 [130];
  char acStack_174 [294];
  byte abStack_4e [26];
  byte *pbStack_34;
  int iStack_32;
  byte *pbStack_30;
  byte *pbStack_2e;
  uint uStack_2c;
  byte *pbStack_2a;
  uint uStack_28;
  byte *pbStack_26;
  undefined2 uStack_24;
  undefined4 uStack_22;
  int iStack_1c;
  byte *pbStack_1a;
  byte *pbStack_18;
  int *piVar18;
  int local_e;
  undefined4 local_c;
  byte *pbStack_8;
  undefined4 local_6;
  
  piVar15 = (int *)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  uVar13 = 0;
  local_6._0_2_ = (byte *)*(uint *)(*(int *)(iVar7 + 8) * 2 + 0x68fe);
  for (iVar11 = 2; iVar11 != 0; iVar11 = iVar11 + -1) {
    do {
      uVar13 = uVar13 + 1;
      iVar4 = FUN_4551_0308();
    } while (iVar4 == 0);
  }
  if (*(int *)(iVar7 + 0xae) == 0) {
LAB_2424_3e0a:
    if (*(int *)(iVar7 + 0xb4) != 0) {
      local_6._2_2_ = (byte *)*(int *)(iVar7 + 0xb4);
      FUN_4551_03eb();
      local_e = local_e + (*(int *)(iVar7 + 0x22) - DAT_5b41_0925);
      pbVar6 = (byte *)(*(int *)(iVar7 + 0x24) - DAT_5b41_0927);
      pbVar5 = (byte *)local_c + (int)pbVar6;
      local_c = (byte *)CONCAT22(local_c._2_2_,pbVar5);
      uVar8 = (int)local_6._2_2_ - 2;
      if (uVar8 < 0xb) {
        bVar17 = SCARRY2(uVar8,uVar8);
        iVar11 = uVar8 * 2;
        iVar4 = 0;
        switch(uVar8) {
        case 0:
          local_c._2_2_ = (byte *)((int)local_c._2_2_ + *(int *)(iVar11 + 0x4a));
          local_c._0_2_ = pbVar5;
          FUN_4551_03eb();
          uStack_22 = (byte *)CONCAT22(&stack0xffee,0x4551);
          uStack_24 = 0x7f70;
          pbVar5 = (byte *)FUN_2424_1e00();
          return pbVar5;
        case 1:
          while (bVar17 != iVar11 < 0) {
            pbVar6 = (byte *)switchD_2000:809a::caseD_7();
            iVar11 = iVar4 + -0x118;
            bVar17 = SBORROW2(iVar4 + 1,0x119);
            iVar4 = iVar4 + 1;
          }
          return pbVar6;
        case 3:
          if (iVar11 != 0) {
            pbStack_8 = (byte *)0x6;
          }
          if (4 < (int)pbStack_8) {
            uVar13 = FUN_1a9e_6e3d();
            uStack_22 = (byte *)CONCAT22(0x26a0,(byte *)uStack_22);
            local_6._2_2_ = (byte *)FUN_28eb_2779();
            if (-1 < (int)local_6._2_2_) {
              iVar7 = 0;
              uVar13 = (uint)local_c._2_2_ / uVar13;
              if (pbStack_8 == (byte *)0x6) {
                local_c = (byte *)((ulong)((uint)local_c._2_2_ >> 2) << 0x10);
              }
              local_c = (byte *)CONCAT22(local_c._2_2_,local_c._2_2_);
              if ((int)in_DX < (int)uVar13) {
                uVar13 = in_DX;
              }
              while (iVar11 = local_e, iVar7 < (int)in_DX) {
                FUN_28eb_2aad();
                iVar4 = local_e;
                if (pbStack_8 == (byte *)0x6) {
                  uStack_22 = (byte *)CONCAT22(0x2705,(byte *)uStack_22);
                  FUN_1a9e_836a();
                  iVar11 = iVar4;
                }
                uStack_22 = (byte *)0x2000271e;
                func_0x0002ea8f();
                iVar7 = iVar7 + uVar13;
                in_DX = uVar13;
                if ((int)uVar13 < (int)(iVar7 + uVar13)) {
                  uVar13 = uVar13 - iVar7;
                  pbVar5 = (byte *)(uVar13 * iVar11 * 2);
                  local_c = (byte *)CONCAT22(local_c._2_2_,pbVar5);
                  if (pbStack_8 == (byte *)0x6) {
                    local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)((uint)pbVar5 >> 2));
                  }
                }
              }
            }
          }
          FUN_1000_130c();
          FUN_28eb_29db();
          if ((byte *)local_6 != (byte *)0x0) {
            FUN_1a9e_6e73();
          }
          return pbStack_8;
        case 4:
          pbStack_2a = (byte *)0x0;
          pbStack_26 = (byte *)(*(int *)(iVar7 + 8) + -1);
          FUN_2e67_0423();
LAB_1a9e_62c7:
          do {
            while( true ) {
              bVar2 = *local_c;
              local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
              if ((bVar2 & 0x80) == 0) break;
              local_6._2_2_ = (byte *)(uint)bVar2;
              if ((bVar2 & 0x40) == 0) {
                local_6 = (ulong)CONCAT12(bVar2,(byte *)local_6) & 0x3fffff;
                pbVar5 = (byte *)FUN_1a9e_60f0();
                DAT_5b41_26dc = DAT_5b41_26dc + (int)local_6._2_2_;
                uStack_24 = CONCAT11(uStack_24._1_1_,*local_c);
                local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
                local_6._0_2_ = pbVar5;
                if ((param_3 & 2) != 0) {
                  pbVar6 = (byte *)((int)param_1._2_2_ - (int)pbVar5);
                  if (((int)pbVar6 < DAT_554c_42c4) || (DAT_554c_42c6 <= (int)param_1._2_2_)) {
                    if ((int)pbVar6 < DAT_554c_42c4) {
                      local_6._0_2_ = pbVar5 + -(DAT_554c_42c4 - (int)pbVar6);
                      if ((byte *)local_6 != (byte *)0x0 &&
                          DAT_554c_42c4 - (int)pbVar6 <= (int)pbVar5) goto LAB_1a9e_650e;
                    }
                    else {
                      local_6._0_2_ = pbVar5 + -((int)param_1._2_2_ - DAT_554c_42c6);
                      if ((byte *)local_6 != (byte *)0x0 &&
                          (int)param_1._2_2_ - DAT_554c_42c6 <= (int)pbVar5) goto LAB_1a9e_650e;
                    }
                  }
                  else {
LAB_1a9e_650e:
                    (*DAT_554c_4d9e)();
                  }
                  goto LAB_1a9e_65ea;
                }
                pbVar6 = pbVar5 + (int)param_1._2_2_;
                if (((int)param_1._2_2_ < DAT_554c_42c4) || (DAT_554c_42c6 < (int)pbVar6)) {
                  if ((int)param_1._2_2_ < DAT_554c_42c4) {
                    local_6._0_2_ = pbVar5 + -(DAT_554c_42c4 - (int)param_1._2_2_);
                    if ((byte *)local_6 != (byte *)0x0 &&
                        DAT_554c_42c4 - (int)param_1._2_2_ <= (int)pbVar5) goto LAB_1a9e_659b;
                  }
                  else {
                    local_6._0_2_ = pbVar5 + -(int)(pbVar6 + (-1 - DAT_554c_42c6));
                    if ((byte *)local_6 != (byte *)0x0 &&
                        (int)(pbVar6 + (-1 - DAT_554c_42c6)) <= (int)pbVar5) goto LAB_1a9e_659b;
                  }
                }
                else {
LAB_1a9e_659b:
                  (*DAT_554c_4d9e)();
                }
LAB_1a9e_65ea:
                param_1 = ZEXT24(pbVar6) << 0x10;
              }
              else {
                local_6._0_2_ = (byte *)((uint)local_6._2_2_ & 0x3f);
                local_6._2_2_ = (byte *)local_6;
                pbVar5 = (byte *)FUN_1a9e_60f0();
                local_6._0_2_ = pbVar5;
                if (local_6._2_2_ != (byte *)0x0) {
                  pbVar6 = (byte *)((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
                  uStack_22 = (byte *)CONCAT22(uStack_22._2_2_,pbVar6);
                  iVar7 = *(int *)((int)pbVar6 * 2 + 0x7cf2);
                  pcVar12 = acStack_174;
                  iVar11 = (int)pbVar6 << 1;
                  if (0 < (int)pbVar5) {
                    cVar9 = uStack_24._1_1_;
                    do {
                      while( true ) {
                        uVar14 = (undefined2)((ulong)local_c >> 0x10);
                        uVar13 = *(int *)(iVar11 + 0x7cf2) - iVar7;
                        uVar8 = uVar13 >> 1;
                        if ((uVar13 & 1) == 0) break;
                        pcVar1 = pcVar12;
                        pcVar12 = pcVar12 + 1;
                        *pcVar1 = (((byte *)local_c)[uVar8] & 0xf) + cVar9;
                        iVar11 = iVar11 + 2;
                        pbVar5 = pbVar5 + -1;
                        if (pbVar5 == (byte *)0x0) goto LAB_1a9e_6371;
                      }
                      pcVar1 = pcVar12;
                      pcVar12 = pcVar12 + 1;
                      *pcVar1 = (((byte *)local_c)[uVar8] >> 4) + cVar9;
                      iVar11 = iVar11 + 2;
                      pbVar5 = pbVar5 + -1;
                    } while (pbVar5 != (byte *)0x0);
                  }
LAB_1a9e_6371:
                  local_c = (byte *)CONCAT22(local_c._2_2_,
                                             (byte *)local_c + ((int)((int)local_6._2_2_ + 1U) >> 1)
                                            );
                }
                DAT_5b41_26dc = DAT_5b41_26dc + (int)local_6._2_2_;
                if ((byte *)local_6 != (byte *)0x0) {
                  if ((param_3 & 2) != 0) {
                    pbVar5 = (byte *)((int)param_1._2_2_ - (int)(byte *)local_6);
                    if (((int)pbVar5 < DAT_554c_42c4) || (DAT_554c_42c6 <= (int)param_1._2_2_)) {
                      if ((int)pbVar5 < DAT_554c_42c4) {
                        pbVar6 = (byte *)local_6 + -(DAT_554c_42c4 - (int)pbVar5);
                        bVar17 = DAT_554c_42c4 - (int)pbVar5 <= (int)(byte *)local_6;
                        local_6._0_2_ = pbVar6;
                        if (pbVar6 != (byte *)0x0 && bVar17) goto LAB_1a9e_63c8;
                      }
                      else {
                        pbVar6 = (byte *)local_6 + -((int)param_1._2_2_ + DAT_554c_42c6);
                        bVar17 = (int)param_1._2_2_ + DAT_554c_42c6 <= (int)(byte *)local_6;
                        local_6._0_2_ = pbVar6;
                        if (pbVar6 != (byte *)0x0 && bVar17) goto LAB_1a9e_63c8;
                      }
                    }
                    else {
LAB_1a9e_63c8:
                      (*DAT_554c_4e0e)();
                    }
                    goto LAB_1a9e_64ac;
                  }
                  pbVar5 = (byte *)local_6 + (int)param_1._2_2_;
                  if (((int)param_1._2_2_ < DAT_554c_42c4) || (DAT_554c_42c6 < (int)pbVar5)) {
                    if ((int)param_1._2_2_ < DAT_554c_42c4) {
                      pbVar6 = (byte *)local_6 + -(DAT_554c_42c4 - (int)param_1._2_2_);
                      bVar17 = DAT_554c_42c4 - (int)param_1._2_2_ <= (int)(byte *)local_6;
                      local_6._0_2_ = pbVar6;
                      if (pbVar6 != (byte *)0x0 && bVar17) goto LAB_1a9e_6455;
                    }
                    else {
                      pbVar6 = (byte *)local_6 + -(int)(pbVar5 + (-1 - DAT_554c_42c6));
                      bVar17 = (int)(pbVar5 + (-1 - DAT_554c_42c6)) <= (int)(byte *)local_6;
                      local_6._0_2_ = pbVar6;
                      if (pbVar6 != (byte *)0x0 && bVar17) goto LAB_1a9e_6455;
                    }
                  }
                  else {
LAB_1a9e_6455:
                    (*DAT_554c_4e0e)();
                  }
LAB_1a9e_64ac:
                  param_1 = ZEXT24(pbVar5) << 0x10;
                }
              }
            }
            if ((bVar2 & 0x40) == 0) {
              local_6 = (ulong)CONCAT12(bVar2,(byte *)local_6) & 0x3fffff;
              iStack_1c._0_1_ = ',';
              uVar13 = FUN_1a9e_60f0();
              pbVar6 = (byte *)((uVar13 ^ (int)uVar13 >> 0xf) - ((int)uVar13 >> 0xf));
              DAT_5b41_26dc = DAT_5b41_26dc + -(int)local_6._2_2_;
              pbVar5 = pbVar6;
              if ((param_3 & 2) == 0) {
                pbVar5 = (byte *)-(int)pbVar6;
              }
              param_1._2_2_ = pbVar5 + (int)param_1._2_2_;
              bVar2 = *local_c;
              local_6._2_2_ = (byte *)(uint)bVar2;
              local_6._0_2_ = pbVar6;
              if (((bVar2 & 0xc0) == 0) &&
                 (uVar13 = (uint)local_6._2_2_ & 0x3f, (bVar2 & 0x3f) != 0)) {
                local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
                iStack_1c._0_1_ = '{';
                local_6._0_2_ = (byte *)FUN_1a9e_60f0();
                DAT_5b41_26dc = DAT_5b41_26dc + uVar13 * -0x40;
                if ((param_3 & 2) == 0) {
                  param_1._2_2_ = param_1._2_2_ + -(int)(byte *)local_6;
                }
                else {
                  param_1._2_2_ = param_1._2_2_ + (int)(byte *)local_6;
                }
              }
              bVar17 = CARRY2(uStack_2c,uStack_28);
              uStack_2c = uStack_2c + uStack_28;
              pbStack_2a = pbStack_2a + (uint)bVar17 + (int)pbStack_26;
              uStack_22 = (byte *)CONCAT22(uStack_22._2_2_,pbStack_2a);
              if (pbStack_2e == pbStack_2a) {
                local_c = (byte *)CONCAT22(local_e,unaff_SI);
                param_1._2_2_ = pbStack_30;
                DAT_5b41_26dc = pbStack_34;
              }
              else {
                uVar13 = (int)pbStack_2a - (int)pbStack_2e >> 0xf;
                pbStack_18 = (byte *)((((int)pbStack_2a - (int)pbStack_2e ^ uVar13) - uVar13) - 1);
                if (pbStack_18 != (byte *)0x0) {
                  while (pbStack_18 != (byte *)0x0) {
                    local_6._2_2_ = (byte *)(uint)*local_c;
                    local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
                    pbStack_18 = (byte *)((uint)local_6._2_2_ & 0x3f);
                    iStack_1c._0_1_ = '\x06';
                    local_6._0_2_ = pbStack_18;
                    pbStack_8 = (byte *)FUN_1a9e_60f0();
                    if ((param_3 & 2) != 0) {
                      pbStack_8 = (byte *)-(int)pbStack_8;
                    }
                    if (((uint)local_6._2_2_ & 0x80) == 0) {
                      if (((uint)local_6._2_2_ & 0x40) == 0) {
                        DAT_5b41_26dc = DAT_5b41_26dc + -(int)(byte *)local_6;
                        param_1._2_2_ = param_1._2_2_ + -(int)pbStack_8;
                        bVar2 = *local_c;
                        local_6._2_2_ = (byte *)(uint)bVar2;
                        if (((bVar2 & 0xc0) == 0) &&
                           (uVar13 = (uint)local_6._2_2_ & 0x3f, (bVar2 & 0x3f) != 0)) {
                          local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
                          pbStack_18 = (byte *)(uVar13 * 0x40);
                          iStack_1c._0_1_ = -0x56;
                          local_6._0_2_ = (byte *)FUN_1a9e_60f0();
                          DAT_5b41_26dc = DAT_5b41_26dc + uVar13 * -0x40;
                          if ((param_3 & 2) == 0) {
                            param_1._2_2_ = param_1._2_2_ + -(int)(byte *)local_6;
                          }
                          else {
                            param_1._2_2_ = param_1._2_2_ + (int)(byte *)local_6;
                          }
                        }
                        pbStack_18 = pbStack_18 + -1;
                      }
                      else {
                        if ((byte *)local_6 == (byte *)0x0) {
                          return pbStack_8;
                        }
                        DAT_5b41_26dc = DAT_5b41_26dc + (int)(byte *)local_6;
                        param_1._2_2_ = param_1._2_2_ + (int)pbStack_8;
                      }
                    }
                    else {
                      DAT_5b41_26dc = DAT_5b41_26dc + (int)(byte *)local_6;
                      if (((uint)local_6._2_2_ & 0x40) == 0) {
                        param_1._2_2_ = param_1._2_2_ + (int)pbStack_8;
                        local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + 1);
                      }
                      else {
                        param_1._2_2_ = param_1._2_2_ + (int)pbStack_8;
                        local_c = (byte *)CONCAT22(local_c._2_2_,
                                                   (byte *)local_c +
                                                   ((int)((byte *)local_6 + 1) >> 1));
                      }
                    }
                  }
                }
              }
              local_e = (int)local_c._2_2_;
              pbStack_2e = (byte *)uStack_22;
              pbStack_30 = param_1._2_2_;
              pbStack_34 = DAT_5b41_26dc;
              param_5 = param_5 + -1;
              if (param_5 == 0) {
                return DAT_5b41_26dc;
              }
              if ((param_3 & 2) == 0) {
                iVar7 = ((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
              }
              else {
                iVar7 = -((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
              }
              param_1 = (ulong)(uint)(iStack_32 + iVar7) << 0x10;
              unaff_SI = (byte *)local_c;
              if ((char)iStack_1c != '\0') goto code_r0x0002122e;
              goto LAB_1a9e_686e;
            }
            local_6 = (ulong)CONCAT12(bVar2,(byte *)local_6) & 0x3fffff;
            if ((bVar2 & 0x3f) == 0) {
              return (byte *)(uint)bVar2;
            }
            pbVar5 = (byte *)FUN_1a9e_60f0();
            DAT_5b41_26dc = DAT_5b41_26dc + (int)local_6._2_2_;
            local_6._0_2_ = pbVar5;
            if ((param_3 & 2) == 0) {
              param_1 = ZEXT24(pbVar5 + (int)param_1._2_2_) << 0x10;
            }
            else {
              param_1 = (ulong)(uint)((int)param_1._2_2_ - (int)pbVar5) << 0x10;
            }
          } while( true );
        case 5:
          return unaff_SI;
        case 6:
switchD_2000_6a47_caseD_1:
          iVar7 = 0;
          uVar14 = 0x2000;
          do {
            uStack_22 = (byte *)CONCAT22(uVar14,0x7410);
            FUN_3e34_0ec9();
            iVar7 = iVar7 + *(int *)((byte *)local_6 + 6);
            uVar14 = 0x3e34;
          } while (iVar7 < local_e);
          pbVar5 = (byte *)FUN_2424_02ca();
          return pbVar5;
        case 7:
          FUN_2321_0b43();
          pbVar5 = (byte *)FUN_5506_002a();
          return pbVar5;
        case 8:
          DAT_554c_516f = (byte *)FUN_2fc8_01f3();
          pbVar6 = (byte *)FUN_2fc8_01f3();
        case 2:
          *param_2 = (int)pbVar6;
          pbVar5 = DAT_554c_516f;
          *piVar15 = (int)DAT_554c_516f;
          break;
        case 9:
          abStack_4e[uVar13] = abStack_4e[uVar13] ^ (byte)pbVar6;
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        case 10:
          do {
            FUN_1000_3d77();
            do {
              for (uVar8 = 0; uVar8 < 500; uVar8 = uVar8 + 1) {
                auStack_1f6[uVar8] = *(undefined1 *)((int)&local_6 + (3 - uVar8));
              }
              uVar13 = uVar13 + 1;
              if (9999 < uVar13) {
                DAT_5b41_0953 = 0;
                return DAT_5b41_0951;
              }
            } while (uVar13 % 0x1e != 0);
            FUN_1000_418e();
          } while( true );
        }
switchD_2000_8024_caseD_5:
        return pbVar5;
      }
      iVar7 = FUN_2424_4007();
      if (iVar7 != 0) goto LAB_2424_3e89;
    }
    pbVar5 = (byte *)0x0;
  }
  else {
    local_6._2_2_ = (byte *)*(int *)(iVar7 + 0xae);
    piVar18 = &local_e;
    pbStack_18 = (byte *)(uVar13 + (int)local_6._2_2_ + -1);
    pbStack_1a = (byte *)local_6;
    FUN_4551_03eb();
    local_e = local_e + (*(int *)(iVar7 + 0x22) - DAT_5b41_0925);
    pbVar5 = (byte *)(*(int *)(iVar7 + 0x24) - DAT_5b41_0927);
    local_c = (byte *)CONCAT22(local_c._2_2_,(byte *)local_c + (int)pbVar5);
    if ((int)local_6._2_2_ - 1U < 9) {
      iVar11 = ((int)local_6._2_2_ - 1U) * 2;
      pbVar6 = (byte *)0x2000;
      switch(local_6._2_2_) {
      case (byte *)0x1:
switchD_2000_8024_caseD_1:
        if (pbVar5 != pbStack_2a) goto LAB_2424_1514;
        uStack_22 = (byte *)0x0;
        iStack_1c = 0;
        pbVar5 = (byte *)0x0;
        pbVar16 = pbVar6;
        do {
          if (pbVar5 == (byte *)0x0 && iStack_1c == 0) {
            return (byte *)0x0;
          }
          if ((byte *)uStack_22 == (byte *)0x0 && uStack_22._2_2_ == 0) {
            return (byte *)0x0;
          }
          if ((iStack_1c != uStack_24) || (pbVar5 != pbStack_26)) {
            pbStack_18 = (byte *)0x1;
            piVar18 = (int *)0x0;
          }
          local_6._2_2_ =
               (byte *)(*(int *)(pbVar5 + 0x2e) + (int)(char)pbVar5[(int)pbStack_18 * 2 + 0x7a]);
          local_6._0_2_ =
               (byte *)(*(int *)(pbVar5 + 0x30) + (int)(char)pbVar5[(int)pbStack_18 * 2 + 0x7b]);
          if ((uStack_22._2_2_ == uStack_28) && ((byte *)uStack_22 == pbStack_2a)) {
            pbStack_18 = (byte *)iStack_1c;
            pbVar16 = (byte *)0x28eb;
            piVar18 = (int *)FUN_28eb_3b36();
            pbStack_1a = pbVar5;
          }
          uVar14 = (undefined2)((ulong)uStack_22 >> 0x10);
          pbVar5 = (byte *)uStack_22;
          pbStack_8 = (byte *)(*(int *)(pbVar5 + 0x2e) +
                              (int)(char)pbVar5[(int)pbStack_1a * 2 + 0x7a]);
          iVar11 = *(int *)(pbVar5 + 0x30) + (int)(char)pbVar5[(int)pbStack_1a * 2 + 0x7b];
          if ((int)local_6._2_2_ < (int)pbStack_8) {
            iVar4 = (int)local_6._2_2_ - DAT_5b41_0925;
            pbVar5 = pbStack_8;
          }
          else {
            iVar4 = (int)pbStack_8 - DAT_5b41_0925;
            pbVar5 = local_6._2_2_;
          }
          if ((int)(byte *)local_6 < iVar11) {
            local_e = (int)(byte *)local_6 - DAT_5b41_0927;
            iVar3 = iVar11;
          }
          else {
            local_e = iVar11 - DAT_5b41_0927;
            iVar3 = (int)(byte *)local_6;
          }
          iVar3 = iVar3 - DAT_5b41_0927;
          if (0 < (int)piVar18) {
            iVar3 = iVar3 + ((int)piVar18 >> 1);
          }
          uVar13 = (uint)((int)(pbVar5 + (-iVar4 - DAT_5b41_0925)) < iVar3 - local_e);
          local_c = (byte *)CONCAT22(iVar11,(byte *)(iVar4 - uVar13));
          local_e = local_e - (uint)(uVar13 == 0);
          for (puVar10 = DAT_5b41_04ac; pbVar6 = pbVar16, puVar10 != (undefined2 *)0x0;
              puVar10 = (undefined2 *)*puVar10) {
            if ((((puVar10[6] == 1) && ((int)puVar10[1] <= (int)(pbVar5 + (uVar13 - DAT_5b41_0925)))
                 ) && ((int)(iVar4 - uVar13) <= (int)puVar10[3])) &&
               (((int)puVar10[2] <= (int)(iVar3 + (uint)(uVar13 == 0)) &&
                (local_e <= (int)puVar10[4])))) {
              pbVar6 = (byte *)0x28eb;
              FUN_28eb_2d82();
              uStack_22 = (byte *)CONCAT22(uStack_28,pbStack_2a);
              pbStack_1a = pbVar16;
              pbStack_18 = (byte *)iVar7;
              piVar18 = piVar15;
              break;
            }
          }
          pbVar5 = (byte *)uStack_22;
          if (uStack_22._2_2_ == uStack_28) goto switchD_2000_8024_caseD_1;
LAB_2424_1514:
          pbVar5 = (byte *)uStack_22;
          iStack_1c = uStack_22._2_2_;
          uStack_22 = (byte *)CONCAT22(*(undefined2 *)((byte *)uStack_22 + 0x60),
                                       *(byte **)((byte *)uStack_22 + 0x5e));
          pbVar16 = pbVar6;
        } while( true );
      default:
        goto switchD_2000_6a47_caseD_1;
      case (byte *)0x3:
        func_0x00027b7c();
        FUN_2e67_0c9b();
        if (DAT_5b41_0bee == 0) {
          if (cRam0005c054 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0002eb7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            pbVar5 = (byte *)(*(code *)switchD_2000:eb7b::switchdataD_2000_06a1)();
            return pbVar5;
          }
          pbVar5 = (byte *)0x0;
        }
        else {
          pbVar5 = (byte *)FUN_2e67_08ed();
        }
        return pbVar5;
      case (byte *)0x4:
        return pbVar5;
      case (byte *)0x5:
        goto switchD_2000_8024_caseD_5;
      case (byte *)0x6:
        cVar9 = (char)((uint)iVar11 >> 8) + (char)pbVar5;
        if (cVar9 < '\0') {
          return (byte *)0x0;
        }
        pcVar1 = (char *)CONCAT11(cVar9,(char)iVar11);
        *pcVar1 = *pcVar1 + (char)pbVar5;
        DAT_5b41_2626 = 0;
        DAT_5b41_25d8 = 0;
        DAT_5b41_25d6 = 0;
        if (DAT_5b41_2676 == 0 && DAT_5b41_2678 == 0) {
          pbVar5 = (byte *)FUN_1000_130c();
        }
        else {
          pbVar5 = (byte *)func_0x0002fdf5();
        }
        DAT_5b41_25c2 = 0;
        DAT_5b41_25d8 = 0;
        DAT_5b41_25d6 = 0;
        DAT_5b41_2678 = 0;
        DAT_5b41_2676 = 0;
        _DAT_5b41_2628 = 0;
        DAT_5b41_2626 = 0;
        return pbVar5;
      case (byte *)0x7:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (byte *)0x9:
        *(char *)(iVar11 + uVar13) = *(char *)(iVar11 + uVar13) + '\x01';
        iRam000654b0 = iRam000654b0 + uVar13;
        return pbVar5;
      }
    }
    iVar11 = FUN_2424_4007();
    if (iVar11 == 0) goto LAB_2424_3e0a;
LAB_2424_3e89:
    pbVar5 = (byte *)0x1;
  }
  return pbVar5;
code_r0x0002122e:
  if ((DAT_554c_42ca < (int)param_2) || ((int)param_2 < DAT_554c_42c8)) {
    bVar17 = false;
  }
  else {
    bVar17 = true;
  }
  if (bVar17) {
LAB_1a9e_686e:
  }
  goto LAB_1a9e_62c7;
}

