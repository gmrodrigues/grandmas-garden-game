// TIM2.EXE: FUN_4876_0b75 @ file 0x04E4D5 Ghidra 0x492D5
// Subsystem: misc | Size: 2153 bytes


/* WARNING: Restarted to delay deadcode elimination for space: stack */

byte * __cdecl16far FUN_4876_0b75(undefined4 param_1,int param_2)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  byte bVar4;
  uint *puVar5;
  byte bVar6;
  undefined2 *puVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int unaff_SI;
  byte *unaff_DI;
  int iVar14;
  undefined2 uVar15;
  undefined2 unaff_SS;
  byte in_AF;
  undefined1 auStackY_10c [208];
  uint local_2a;
  uint uStack_28;
  int local_26;
  uint local_22;
  int local_1c;
  int local_1a;
  byte *pbStack_18;
  int local_16;
  int local_14;
  uint local_12;
  int local_10;
  undefined4 local_e;
  undefined4 local_a;
  int local_6;
  byte *pbStack_4;
  
  local_6 = (int)param_1 + 0x28;
  pbStack_4 = param_1._2_2_;
  puVar7 = (undefined2 *)((int)param_1 + 0x34);
  local_a = (undefined2 *)CONCAT22(param_1._2_2_,puVar7);
  if (*(int *)((int)param_1 + 0x44) == 0 && *(int *)((int)param_1 + 0x46) == 0) {
    return (byte *)0x0;
  }
  if (param_2 == 2) {
    *(undefined2 *)((int)param_1 + 0x26) = 2;
    DAT_5b41_1ae4 = (byte *)0x0;
    DAT_5b41_1ae2 = 0;
    *(undefined2 *)((int)param_1 + 0x36) = DAT_5450_0000;
    *(undefined2 *)((int)param_1 + 0x42) = DAT_5450_0004;
    *puVar7 = DAT_5450_0002;
    return (byte *)0x2;
  }
  iVar10 = unaff_SI;
  if (((DAT_5b41_1b88 & 6) != 0) || (param_2 == 3)) {
    if (param_2 == 0) {
      pbVar9 = (byte *)FUN_4876_0b75((int)param_1,param_1._2_2_,2);
      return pbVar9;
    }
    if ((DAT_5b41_1ae4 != param_1._2_2_) || (DAT_5b41_1ae2 != (int)param_1)) {
      DAT_5450_0000 = *(undefined2 *)((int)param_1 + 0x36);
      DAT_5450_0004 = *(undefined2 *)((int)param_1 + 0x42);
      DAT_5450_0002 = *puVar7;
      *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)((int)param_1 + 0x50);
      *(undefined2 *)((int)param_1 + 0x42) = *(undefined2 *)((int)param_1 + 0x4e);
      *local_a = *(undefined2 *)((int)param_1 + 0x4c);
      DAT_5450_0008 = 0;
      DAT_5450_0006 = (byte *)0x0;
      DAT_5450_000e = 2;
      FUN_4340_10fe(puVar7,param_1._2_2_,0,0,1);
      DAT_5b41_1ae4 = param_1._2_2_;
      DAT_5b41_1ae2 = (int)param_1;
    }
    DAT_5450_000c = DAT_5450_0008;
    DAT_5450_000a = DAT_5450_0006;
    if (param_2 == 3) {
      DAT_5450_0008 = *(int *)((int)param_1 + 0x46);
      DAT_5450_0006 = (byte *)*(undefined2 *)((int)param_1 + 0x44);
      local_e = (byte *)CONCAT22(DAT_5450_0008,DAT_5450_0006);
      uVar12 = FUN_4340_0a09(DAT_5450_0006,DAT_5450_0008);
      if (uVar12 < DAT_5b41_1ae6) {
        iVar8 = FUN_4340_0a09((byte *)local_e,local_e._2_2_);
        DAT_5450_0006 = DAT_5450_0006 + iVar8;
      }
      else {
        DAT_5450_0006 = DAT_5450_0006 + DAT_5b41_1ae6;
      }
    }
    else {
      DAT_5450_0006 =
           (byte *)FUN_4340_1a32((undefined2 *)local_a,local_a._2_2_,DAT_5b41_1b84,DAT_5b41_1b86);
    }
    FUN_4340_167e((undefined2 *)local_a,local_a._2_2_,DAT_5450_0006,DAT_5450_0008,&local_1c);
    DAT_5450_0014 = local_1c;
    DAT_5450_0016 = local_1a;
    DAT_5450_0018 = local_16;
    DAT_5450_0012 = 2;
    *(undefined2 *)((int)param_1 + 0x26) = 2;
  }
  if (DAT_5b41_1ae4 != param_1._2_2_) {
    return (byte *)0x0;
  }
  if (DAT_5b41_1ae2 != (int)param_1) {
    return (byte *)0x0;
  }
  if (3 < *(uint *)((int)param_1 + 0x2c)) {
    *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + 1;
    if (*(uint *)((int)param_1 + 0x2c) <= *(uint *)((int)param_1 + 0x2e)) {
      *(undefined2 *)((int)param_1 + 0x2e) = 3;
    }
    *(undefined2 *)((int)param_1 + 0x26) = 2;
  }
  iVar8 = DAT_5450_0008;
  local_10 = 0;
  iVar14 = 1;
  local_e = (byte *)CONCAT22(DAT_5450_0008,DAT_5450_0006);
  local_14 = 0;
  puVar7 = (undefined2 *)local_a;
  if (DAT_5b41_1b90 == 0x4b) {
    if ((DAT_5b41_1b94 & 1) == 0) {
      if ((byte *)puVar7[8] < DAT_5450_0006) {
        local_e = (byte *)CONCAT22(DAT_5450_0008,DAT_5450_0006 + -1);
        local_14 = -1;
      }
    }
    else {
      iVar10 = DAT_5450_0008;
      pbVar9 = (byte *)FUN_4340_0ef6(puVar7[8],puVar7[9],DAT_5450_0006,DAT_5450_0008);
      local_e = (byte *)CONCAT22(iVar10,pbVar9);
    }
    goto LAB_4876_130e;
  }
  if (DAT_5b41_1b90 < 0x4c) {
    if (DAT_5b41_1b90 == 0x47) {
LAB_4876_0eb0:
      local_e = (byte *)CONCAT22(puVar7[9],(byte *)puVar7[8]);
      goto LAB_4876_130e;
    }
    if (DAT_5b41_1b90 < 0x48) {
      if (DAT_5b41_1b90 == 0xe) {
        if ((DAT_5b41_1b94 & 1) == 0) {
          if (DAT_5450_0006 <= (byte *)puVar7[8]) goto LAB_4876_130e;
          DAT_5450_0006 = DAT_5450_0006 + -1;
          local_e = (byte *)CONCAT22(DAT_5450_0008,DAT_5450_0006);
          FUN_4340_0e53(DAT_5450_0006,DAT_5450_0008);
        }
        else {
          do {
            uVar15 = (undefined2)((ulong)local_a >> 0x10);
            iVar10 = FUN_4340_0e53(((undefined2 *)local_a)[8],((undefined2 *)local_a)[9]);
          } while (iVar10 != 0);
          uVar15 = (undefined2)((ulong)local_a >> 0x10);
          DAT_5450_0008 = ((undefined2 *)local_a)[9];
          DAT_5450_0006 = (byte *)((undefined2 *)local_a)[8];
          local_e = (byte *)CONCAT22(DAT_5450_0008,DAT_5450_0006);
        }
        FUN_4340_10fe((undefined2 *)local_a,local_a._2_2_,0,0,1);
        DAT_5450_0010 = 2;
        *(undefined2 *)((int)param_1 + 0x26) = 2;
        local_10 = 1;
        goto LAB_4876_130e;
      }
      if ((DAT_5b41_1b90 == 0xf) || (DAT_5b41_1b90 == 0x1c)) {
        *(undefined2 *)((int)param_1 + 0x26) = 2;
        puVar7[1] = DAT_5450_0000;
        puVar7[7] = DAT_5450_0004;
        *local_a = DAT_5450_0002;
        DAT_5b41_1ae2 = 0;
        DAT_5b41_1ae4 = (byte *)0x0;
        return (byte *)0x2;
      }
    }
    else {
      if (DAT_5b41_1b90 == 0x48) {
        DAT_5450_0016 = DAT_5450_0016 + -1;
        iVar10 = DAT_5450_0008;
        pbVar9 = (byte *)FUN_4340_1a32(puVar7,local_a._2_2_,DAT_5450_0014,DAT_5450_0016);
        local_e = (byte *)CONCAT22(iVar10,pbVar9);
        iVar14 = -1;
        goto LAB_4876_130e;
      }
      if (DAT_5b41_1b90 == 0x49) goto LAB_4876_0eb0;
    }
  }
  else {
    uVar12 = DAT_5b41_1b90 - 0x4d;
    if (uVar12 < 7) {
      switch(uVar12) {
      case 0:
        bVar4 = 9 < ((byte)DAT_5450_0006 & 0xf) | in_AF;
        bVar6 = (byte)DAT_5450_0006 + bVar4 * -6;
        return (byte *)CONCAT11((char)((uint)DAT_5450_0006 >> 8),
                                bVar6 + (0x9f < bVar6 | CARRY2(uVar12,uVar12) | bVar4 * (bVar6 < 6))
                                        * -0x60);
      case 1:
        return DAT_5450_0006;
      case 2:
        iVar10 = 0;
        while ((*(int *)(iVar10 + 0x4e) != uVar12 * 2 || (*(int *)(iVar10 + 0x50) != 0x5450))) {
          iVar10 = iVar10 + 4;
          if (iVar10 == 0x40) {
            FUN_4bdc_0cf1();
            uRam0004020a = 1;
            return unaff_DI;
          }
        }
        return unaff_DI;
      case 4:
        pbVar9 = DAT_5450_0006;
        iVar10 = unaff_SI;
        if (CARRY2(uVar12,uVar12) || uVar12 * 2 == 0) goto LAB_4a54_1807;
        while (iVar14 = iVar14 + 1, iVar10 = unaff_SI, iVar14 < (int)puVar7) {
LAB_4a54_1807:
          do {
            puVar5 = DAT_5b41_2858;
            bVar4 = (byte)((ulong)param_1 >> 0x10) & 0xf;
            uVar11 = *DAT_5b41_2858;
            uVar13 = DAT_5b41_2858[1];
            puVar1 = DAT_5b41_2858;
            uVar12 = *puVar1;
            *puVar1 = (uint)(param_1._2_2_ + *puVar1);
            puVar5[1] = puVar5[1] + (uint)CARRY2(uVar12,(uint)param_1._2_2_);
            pbVar9 = (byte *)CONCAT11((char)((uint)iVar14 >> 8),
                                      auStackY_10c
                                      [*(uint *)(puVar5[2] +
                                                (((uVar11 >> 1 | (uint)((uVar13 & 1) != 0) << 0xf)
                                                  >> 1 | (uint)((uVar13 >> 1 & 1) != 0) << 0xf) >> 1
                                                | (uint)((uVar13 >> 2 & 1) != 0) << 0xf)) >>
                                       ((byte)uVar11 & 7) &
                                       (uint)(byte)((byte)(-0x100 << bVar4) |
                                                   (byte)(0xff00 >> 0x10 - bVar4))]);
            *(undefined1 *)
             ((int)*(undefined4 *)(DAT_5b41_2858 + 4) + DAT_5b41_2858[iVar10 + 0xc] + iVar14) =
                 auStackY_10c
                 [*(uint *)(puVar5[2] +
                           (((uVar11 >> 1 | (uint)((uVar13 & 1) != 0) << 0xf) >> 1 |
                            (uint)((uVar13 >> 1 & 1) != 0) << 0xf) >> 1 |
                           (uint)((uVar13 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar11 & 7) &
                  (uint)(byte)((byte)(-0x100 << bVar4) | (byte)(0xff00 >> 0x10 - bVar4))];
            iVar10 = iVar10 + 1;
            unaff_SI = (int)param_1;
          } while (iVar10 < iVar8);
        }
        return pbVar9;
      case 5:
        pbVar9 = (byte *)FUN_4551_01dc();
        return pbVar9;
      case 6:
        if (DAT_5450_0008 == 0x100) {
          pbVar9 = (byte *)((int)(param_1._2_2_ + unaff_SI) * 2);
        }
        else {
          pbVar9 = param_1._2_2_ + unaff_SI;
        }
        FUN_406b_20eb(pbVar9 + -1);
        DAT_5b41_1ae0 = param_1._2_2_;
        DAT_554c_42d4 = 0xa001;
        DAT_554c_42d2 = local_a._2_2_ + -0x5fff;
        DAT_554c_42d0 = DAT_554c_42d2 + local_a._2_2_;
        if (0xafff < (uint)(DAT_554c_42d0 + local_a._2_2_)) {
          DAT_554c_42d0 = 0;
        }
        if (unaff_SI <= DAT_554c_42ca) {
          DAT_554c_42ca = unaff_SI + -1;
        }
        DAT_554c_49ac = unaff_SI;
        FUN_1a9e_4d29(0x4000,0);
        FUN_1a9e_4d29(0x1a9e,1);
        return param_1._2_2_;
      }
switchD_4000_95bd_caseD_3:
      iVar8 = (*pcRam000556ad)(0x4000,unaff_DI);
      *(undefined1 *)(iVar8 + 0x1ce) = 0xff;
      FUN_4bdc_2141();
      (*pcRam000556ad)(0x4000);
      (*pcRam000556ad)(0x4000);
      (*pcRam000556ad)(0x4000);
      (*pcRam000556ad)(0x4000);
      (*pcRam000556ad)(0x4000);
      (*pcRam000556ad)(0x4000);
LAB_4bdc_1557:
      do {
        do {
          iVar8 = iVar10;
          iVar10 = iVar8 + 1;
          if (iVar10 == 0x10) {
            uVar13 = (uint)(byte)(cRam00040201 + 1);
            uStack_28 = 0;
            uVar12 = 0;
            uVar11 = local_2a;
            do {
              local_2a = uVar12;
              if (*(char *)(uStack_28 + 0x16e) != -1) {
                do {
                  uVar12 = uVar13;
                  uVar13 = uVar12 - 1;
                } while (*(char *)(uVar12 + 0x12d) != -1);
                uVar2 = *(undefined1 *)(uStack_28 + 0x16e);
                *(undefined1 *)(uVar12 + 0x12d) = uVar2;
                local_2a = CONCAT11((char)(local_2a >> 8),uVar2) & 0xff0f;
                (*pcRam000556ad)(0x4000,unaff_DI,uVar13,uVar11);
                (*pcRam000556ad)(0x4000);
                iVar10 = (*pcRam000556ad)(0x4000);
                *(undefined1 *)(iVar10 + 0x1ce) = 0xff;
                FUN_4bdc_2141();
                (*pcRam000556ad)(0x4000);
                (*pcRam000556ad)(0x4000);
                (*pcRam000556ad)(0x4000);
                (*pcRam000556ad)(0x4000);
                (*pcRam000556ad)(0x4000);
                (*pcRam000556ad)(0x4000);
              }
              uStack_28 = uStack_28 + 1;
              uVar12 = local_2a;
            } while (uStack_28 != 0x10);
            iVar10 = 0xf;
            do {
              if ((*(char *)(iVar10 + 0x1be) != '\x0f') && (*(char *)(iVar10 + 0x12e) == -1)) {
                local_2a = 0x4000;
                (*pcRam000556ad)();
                local_2a = 0x4000;
                (*pcRam000556ad)();
                local_2a = 0x4000;
                (*pcRam000556ad)();
              }
              iVar10 = iVar10 + -1;
            } while (-1 < iVar10);
            uRam000401be = uRam0004012e & 0xf0f;
            uRam000401c0 = uRam00040130 & 0xf0f;
            uRam000401c2 = uRam00040132 & 0xf0f;
            uRam000401c4 = uRam00040134 & 0xf0f;
            uRam000401c6 = uRam00040136 & 0xf0f;
            uRam000401c8 = uRam00040138 & 0xf0f;
            uRam000401ca = uRam0004013a & 0xf0f;
            uRam000401cc = uRam0004013c & 0xf0f;
            iVar10 = 0;
            iVar8 = 0;
            do {
              if (*(byte *)(iVar10 + 0x12e) == 0xff) {
                *(undefined2 *)(iVar8 + 0x8e) = 0;
                *(undefined2 *)(iVar8 + 0x90) = 0;
              }
              else {
                uVar12 = (*(byte *)(iVar10 + 0x12e) & 0xf0) >> 2;
                *(undefined2 *)(iVar8 + 0x8e) = *(undefined2 *)(uVar12 + 0xe);
                *(undefined2 *)(iVar8 + 0x90) = *(undefined2 *)(uVar12 + 0x10);
              }
              iVar8 = iVar8 + 4;
              iVar10 = iVar10 + 1;
            } while (iVar10 != 0x10);
            cRam000401ff = cRam000401ff + -1;
            return pbStack_18;
          }
        } while (*(char *)(iVar8 + 0x16f) == -1);
        if (*(char *)(iVar8 + 0x13f) == '\0') {
          uVar3 = *(undefined4 *)(((*(byte *)(iVar8 + 0x16f) & 0xf0) >> 2) + 0xe);
          uVar12 = (uint)bRam00040200 << 2;
          do {
            if ((*(int *)(uVar12 + 0x8e) == (int)uVar3) &&
               (*(int *)(uVar12 + 0x90) == (int)((ulong)uVar3 >> 0x10))) {
              uVar12 = uVar12 >> 2;
              if (*(byte *)(uVar12 + 0x1be) == (*(byte *)(iVar8 + 0x16f) & 0xf)) {
                if (*(char *)(uVar12 + 0x13e) == '\0') {
                  *(undefined1 *)(uVar12 + 0x12e) = *(undefined1 *)(iVar8 + 0x16f);
                  *(undefined1 *)(iVar8 + 0x16f) = 0xff;
                }
                break;
              }
              uVar12 = uVar12 << 2;
            }
            uVar12 = uVar12 + 4;
          } while (cRam00040201 != (byte)(((byte)uVar12 >> 2) - 1));
          goto LAB_4bdc_1557;
        }
        bVar4 = *(byte *)(iVar8 + 0x16f);
        *(undefined1 *)(iVar8 + 0x16f) = 0xff;
        *(byte *)(iVar8 + 0x12f) = bVar4;
        uVar3 = *(undefined4 *)(((bVar4 & 0xf0) >> 2) + 0xe);
        uStack_28 = bVar4 & 0xff0f;
        if (((*(char *)(iVar8 + 0x1bf) != (char)uStack_28) ||
            (*(int *)(iVar10 * 4 + 0x8e) != (int)uVar3)) ||
           (*(int *)(iVar10 * 4 + 0x90) != (int)((ulong)uVar3 >> 0x10))) goto LAB_4bdc_141d;
      } while( true );
    }
  }
  iVar14 = 0;
  if (0x1f < DAT_5b41_1b8e) {
    iVar10 = FUN_4340_0a09(puVar7[8],puVar7[9]);
    uVar15 = (undefined2)((ulong)local_a >> 0x10);
    puVar7 = (undefined2 *)local_a;
    if (iVar10 + 1U < (uint)puVar7[10]) {
      uVar12 = puVar7[6];
      if ((uVar12 & 4) == 0) {
        if ((((uVar12 & 8) != 0) && (0x40 < DAT_5b41_1b8e)) && (DAT_5b41_1b8e < 0x5b)) {
          DAT_5b41_1b8e = DAT_5b41_1b8e + 0x20;
        }
      }
      else if ((0x60 < DAT_5b41_1b8e) && (DAT_5b41_1b8e < 0x7b)) {
        DAT_5b41_1b8e = DAT_5b41_1b8e - 0x20;
      }
      if ((((((uVar12 & 0xf0) != 0) &&
            (((uVar12 & 0x10) == 0 ||
             (((DAT_5b41_1b8e < 0x30 || (0x39 < DAT_5b41_1b8e)) && (DAT_5b41_1b8e != 0x2d)))))) &&
           (((uVar12 & 0x20) == 0 ||
            (((DAT_5b41_1b8e < 0x41 || (0x5a < DAT_5b41_1b8e)) &&
             ((DAT_5b41_1b8e < 0x61 || (0x7a < DAT_5b41_1b8e)))))))) &&
          (((uVar12 & 0x40) == 0 ||
           ((((((DAT_5b41_1b8e < 0x30 || (0x39 < DAT_5b41_1b8e)) && (DAT_5b41_1b8e != 0x2d)) &&
              ((DAT_5b41_1b8e < 0x41 || (0x5a < DAT_5b41_1b8e)))) &&
             ((DAT_5b41_1b8e < 0x61 || (0x7a < DAT_5b41_1b8e)))) &&
            ((DAT_5b41_1b8e != 0x2e && (DAT_5b41_1b8e != 0x5f)))))))) &&
         (((uVar12 & 0x80) == 0 ||
          ((((((DAT_5b41_1b8e < 0x30 || (0x39 < DAT_5b41_1b8e)) && (DAT_5b41_1b8e != 0x2d)) &&
             (((DAT_5b41_1b8e < 0x41 || (0x5a < DAT_5b41_1b8e)) &&
              ((DAT_5b41_1b8e < 0x61 || (0x7a < DAT_5b41_1b8e)))))) &&
            ((DAT_5b41_1b8e != 0x2e && (DAT_5b41_1b8e != 0x5f)))) &&
           ((DAT_5b41_1b8e != 0x5c && (DAT_5b41_1b8e != 0x3a)))))))) {
        DAT_5b41_1b8e = 0;
      }
      if (((DAT_5b41_1b8e == 0x2d) && ((uVar12 & 0x10) != 0)) &&
         ((puVar7[9] != local_e._2_2_ ||
          (((byte *)puVar7[8] != (byte *)local_e || (**(char **)(puVar7 + 8) == '-')))))) {
        DAT_5b41_1b8e = 0;
      }
      if (DAT_5b41_1b8e != 0) {
        FUN_4340_0df6((byte *)local_e,local_e._2_2_,DAT_5b41_1b8e);
        local_e = (byte *)CONCAT22(local_e._2_2_,(byte *)local_e + 1);
        DAT_5450_0010 = 2;
        *(undefined2 *)((int)param_1 + 0x26) = 2;
        iVar14 = 1;
        local_10 = 1;
        local_12 = FUN_4340_1c51((undefined2 *)local_a,local_a._2_2_);
        FUN_4340_10fe((undefined2 *)local_a,local_a._2_2_,&local_2a);
        uVar15 = (undefined2)((ulong)local_a >> 0x10);
        if ((local_26 <= (int)((undefined2 *)local_a)[4]) && (local_12 <= local_22)) {
          iVar10 = FUN_4340_167e((undefined2 *)local_a,uVar15,(byte *)local_e,local_e._2_2_,
                                 &local_1c);
          if (iVar10 != 2) {
            uVar15 = (undefined2)((ulong)local_a >> 0x10);
            puVar7 = (undefined2 *)local_a;
            if ((((puVar7[2] != local_1c) || (DAT_5b41_1b8e != 0x20)) &&
                (local_1c < (int)(puVar7[2] + puVar7[4]))) &&
               (local_1a < (int)(puVar7[3] + puVar7[5]))) goto LAB_4876_130e;
          }
        }
        if (local_12 <= local_22) {
          uVar15 = (undefined2)((ulong)local_a >> 0x10);
          puVar7 = (undefined2 *)local_a;
          if ((((byte *)(puVar7[8] + 1) < (byte *)local_e) && (((byte *)local_e)[-1] == 0x20)) &&
             ((((byte *)local_e)[-2] != 0x20 &&
              (local_1a + local_16 <= (int)(puVar7[3] + puVar7[5]))))) {
            local_14 = 1;
            goto LAB_4876_130e;
          }
        }
        local_e._0_2_ = (byte *)local_e + -1;
        FUN_4340_0e53((byte *)local_e,local_e._2_2_);
        FUN_4340_10fe((undefined2 *)local_a,local_a._2_2_,0,0,1);
      }
    }
  }
LAB_4876_130e:
  if (iVar14 != 0) {
    iVar10 = FUN_4340_167e((undefined2 *)local_a,local_a._2_2_,(byte *)local_e,local_e._2_2_,
                           &local_1c);
    if (iVar10 != 2) goto LAB_4876_1386;
    if (local_14 == -1) {
      while (((byte *)((undefined2 *)local_a)[8] < (byte *)local_e &&
             (uVar15 = (undefined2)((ulong)local_e >> 0x10), ((byte *)local_e)[-1] < 0x21))) {
        local_e = (byte *)CONCAT22(uVar15,(byte *)local_e + -1);
      }
    }
    else {
      while ((*local_e != 0 && (*local_e < 0x21))) {
        local_e = (byte *)CONCAT22(local_e._2_2_,(byte *)local_e + 1);
      }
    }
    while( true ) {
      FUN_4340_167e((undefined2 *)local_a,local_a._2_2_,(byte *)local_e,local_e._2_2_,&local_1c);
LAB_4876_1386:
      uVar15 = (undefined2)((ulong)local_a >> 0x10);
      puVar7 = (undefined2 *)local_a;
      if (((byte *)local_e <= (byte *)puVar7[8]) ||
         ((local_1c < (int)(puVar7[2] + puVar7[4]) &&
          (local_1a + local_16 <= (int)(puVar7[3] + puVar7[5]))))) break;
      local_e = (byte *)CONCAT22(local_e._2_2_,(byte *)local_e + -1);
    }
    DAT_5450_0016 = local_1a;
    DAT_5450_0018 = local_16;
    if (0 < iVar14) {
      DAT_5450_0014 = local_1c;
    }
  }
  if ((DAT_5450_0008 != local_e._2_2_) || (DAT_5450_0006 != (byte *)local_e)) {
    DAT_5450_000c = DAT_5450_0008;
    DAT_5450_000a = DAT_5450_0006;
    DAT_5450_0008 = local_e._2_2_;
    DAT_5450_0006 = (byte *)local_e;
    DAT_5450_0012 = 2;
    *(undefined2 *)((int)param_1 + 0x26) = 2;
  }
  if ((local_10 != 0) && ((*(byte *)((undefined2 *)local_a + 6) & 1) != 0)) {
    return (byte *)0x2;
  }
  return (byte *)0x1;
LAB_4bdc_141d:
  (*pcRam000556ad)(0x4000);
  (*pcRam000556ad)(0x4000);
  goto switchD_4000_95bd_caseD_3;
}

