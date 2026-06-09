// TIM2.EXE: FUN_2424_44bb @ file 0x02D8FB Ghidra 0x286FB
// Subsystem: misc | Size: 302 bytes


/* WARNING: Instruction at (ram,0x0002ff71) overlaps instruction at (ram,0x0002ff6d)
    */
/* WARNING: Removing unreachable block (ram,0x00020615) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * __cdecl16far FUN_2424_44bb(byte *param_1)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined2 *puVar7;
  char cVar8;
  byte bVar9;
  undefined2 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  uint in_CX;
  int in_DX;
  byte *pbVar15;
  uint uVar16;
  undefined1 *puVar17;
  undefined2 *puVar18;
  int unaff_SI;
  undefined2 uVar19;
  int iVar20;
  undefined2 unaff_SS;
  byte in_AF;
  bool bVar21;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  undefined4 local_6;
  
  iVar20 = (int)((ulong)param_1 >> 0x10);
  pbVar15 = (byte *)param_1;
  local_e = *(int *)(*(int *)(pbVar15 + 8) * 2 + 0x68fe);
  pbVar11 = (byte *)FUN_4551_0370();
  if (*(int *)(pbVar15 + 0xae) != 0) {
    pbVar11 = (byte *)(*(int *)(pbVar15 + 0x22) - DAT_5b41_0925);
    pbVar12 = (byte *)(*(int *)(pbVar15 + 0x24) - DAT_5b41_0927);
    uVar16 = *(int *)(pbVar15 + 0xae) - 1;
    if (uVar16 < 9) {
      puVar10 = (undefined2 *)(uVar16 * 2);
      bVar21 = puVar10 == (undefined2 *)0x0;
      switch(*(int *)(pbVar15 + 0xae)) {
      case 1:
        *(byte **)(pbVar11 + 0x1b) = pbVar12;
        FUN_1a9e_68b6();
        return *(byte **)pbVar11;
      case 3:
        puVar17 = (undefined1 *)CONCAT11(0x38,(char)puVar10);
        puVar10 = (undefined2 *)((int)&local_6 + 3);
        uVar19 = in(in_DX);
        bVar6 = 9 < ((byte)uVar19 & 0xf) | 9 < ((*pbVar11 ^ 0x38) & 0xf) | in_AF;
        if (in_CX == 1 || (char)in_CX == '8') {
          bVar9 = ((byte)uVar19 + bVar6 * '\x06' & 0xf) % 0x37;
          puVar18 = (undefined2 *)&stack0xffe8;
          cVar8 = '\x16';
          do {
            puVar10 = puVar10 + -1;
            puVar18 = puVar18 + -1;
            *puVar18 = *puVar10;
            cVar8 = cVar8 + -1;
          } while ('\0' < cVar8);
          bVar6 = 9 < (bVar9 & 0xf) | bVar6;
          _DAT_5000_eaf7 = CONCAT11(bVar6,bVar9 + bVar6 * '\x06') & 0xff0f;
          uVar5 = *puVar17;
          if (((int)(uint)bVar9 < *(int *)pbVar12) && (SBORROW2((uint)bVar9,*(int *)pbVar12))) {
            puVar1 = (uint *)(puVar17 + -1);
            *puVar1 = *puVar1 ^ (uint)(pbVar11 + 1);
            DAT_554c_36f1 = DAT_554c_36f1 + '\x01';
            puVar10 = (undefined2 *)in(0x36);
            pbVar12[2] = *(byte *)0xb136;
            *(undefined2 *)0x367c = puVar10;
            out(*puVar10,CONCAT11(uVar5,(char)in_DX));
          }
        }
        else {
          out(*(undefined2 *)(pbVar11 + 1),in_DX);
        }
        pbVar11 = (byte *)FUN_28eb_4cfc();
        return pbVar11;
      case 4:
switchD_2000_8756_caseD_4:
LAB_2424_12ce:
        do {
          while( true ) {
            do {
              while( true ) {
                while( true ) {
                  iVar20 = ((undefined2 *)local_6)[1];
                  puVar10 = (undefined2 *)*local_6;
                  local_6 = (undefined2 *)CONCAT22(iVar20,puVar10);
                  if (puVar10 != (undefined2 *)0x0 || iVar20 != 0) break;
                  unaff_SI = unaff_SI + 1;
                  if (1 < unaff_SI) {
                    return (byte *)0x0;
                  }
                  if (unaff_SI == 0) {
                    puVar10 = (undefined2 *)&DAT_5b41_054f;
                  }
                  else {
                    puVar10 = (undefined2 *)&DAT_5b41_0557;
                  }
                  local_6 = (undefined2 *)CONCAT22(0x554c,puVar10);
                }
                if (DAT_5b41_04b4 == 0) break;
                DAT_5b41_04b4 = 0;
                unaff_SI = 0;
                local_6 = &DAT_5b41_054f;
              }
              if (*(char *)(puVar10 + 0xc) == -0x80) {
                *(undefined1 *)(puVar10 + 0xc) = 0;
              }
              if ((*(byte *)((int)puVar10 + 0xf) & 0x20) == 0) {
                local_8 = 0;
                local_a = 0;
              }
              else {
                local_a = puVar10[0x57];
                local_8 = puVar10[0x5a];
              }
              bVar21 = *(char *)(puVar10 + 0xc) == '\0';
switchD_2000_8756_caseD_9:
            } while (((!bVar21) || ((*(byte *)((int)puVar10 + 0xd) & 0x20) != 0)) ||
                    ((*(byte *)((int)puVar10 + 0xf) & 0x40) != 0));
            if ((puVar10[4] != 10) && (puVar10[4] != 0x4c)) break;
            FUN_2424_12f5();
          }
          uVar19 = (undefined2)((ulong)local_6 >> 0x10);
          puVar10 = (undefined2 *)local_6;
        } while (puVar10[4] == 0x31);
        if (puVar10[4] == 8) goto LAB_2424_1186;
        local_c = puVar10[0x17] - DAT_5b41_0925;
        local_e = puVar10[0x18] - DAT_5b41_0927;
        local_10 = puVar10[0x24] + local_c;
        local_12 = puVar10[0x25] + local_e;
        puVar10 = DAT_5b41_04ac;
        goto LAB_2424_12ca;
      case 5:
        if ((iRam000557bc == 6) && ((pbVar15[0xf] & 0x10) == 0)) {
          if ((pbVar15[0xe] & 0x40) == 0) {
            pbVar11 = (byte *)((uint)pbVar11 | 0x10);
          }
          else {
            pbVar11 = (byte *)((uint)pbVar11 | 0x400);
          }
        }
        if (((pbVar15[0xf] & 0x10) == 0) && ((DAT_5b41_051f & 0x10) == 0)) {
          pbVar11 = (byte *)((uint)pbVar11 | 0x20);
        }
        if ((pbVar15[0xf] & 0x10) != 0) {
          pbVar11 = (byte *)((uint)pbVar11 | 0x3000);
        }
        if ((pbVar15[0xe] & 0x40) != 0) {
          return pbVar11;
        }
        pbVar12 = (byte *)((uint)pbVar11 | 0x140);
        if (*(int *)(pbVar15 + 8) == 8) {
          return pbVar12;
        }
        if (*(int *)(pbVar15 + 8) == 10) {
          return pbVar12;
        }
        if (*(int *)(pbVar15 + 8) == 0x4c) {
          return pbVar12;
        }
        if ((pbVar15[0xc] & 0x80) != 0) {
          pbVar12 = (byte *)((uint)pbVar11 | 0x141);
        }
        if ((pbVar15[0xd] & 1) != 0) {
          pbVar12 = (byte *)((uint)pbVar12 | 2);
        }
        if (((pbVar15[0xb] & 4) == 0) || ((pbVar15[0xb] & 2) == 0)) {
          if ((pbVar15[0xb] & 4) != 0) {
            if (DAT_5b41_0939 == 9) {
              pbVar12 = (byte *)((uint)pbVar12 | 4);
            }
            else {
              DAT_5b41_050f = 1;
              puVar7 = (undefined2 *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0xc);
              (*(code *)*puVar7)();
              *(undefined2 *)(pbVar15 + 0xac) = *(undefined2 *)(pbVar15 + 0xc);
              iVar13 = FUN_28eb_0119();
              if ((iVar13 == 0) &&
                 ((*(int *)(pbVar15 + 0x58) == 0 || (iVar13 = FUN_28eb_1c08(), iVar13 != 0)))) {
                pbVar12 = (byte *)((uint)pbVar12 | 4);
              }
              puVar7 = (undefined2 *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0xc);
              (*(code *)*puVar7)();
              *(undefined2 *)(pbVar15 + 0xac) = *(undefined2 *)(pbVar15 + 0xc);
              DAT_5b41_050f = 0;
            }
          }
          if ((pbVar15[0xb] & 2) == 0) goto LAB_28eb_155d;
          if (DAT_5b41_0939 == 9) {
            pbVar12 = (byte *)((uint)pbVar12 | 8);
            goto LAB_28eb_155d;
          }
          DAT_5b41_050f = 1;
          puVar7 = (undefined2 *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0xc);
          (*(code *)*puVar7)();
          *(undefined2 *)(pbVar15 + 0xac) = *(undefined2 *)(pbVar15 + 0xc);
          iVar13 = FUN_28eb_0119();
          if ((iVar13 == 0) &&
             ((*(int *)(pbVar15 + 0x58) == 0 || (iVar13 = FUN_28eb_1c08(), iVar13 != 0)))) {
            pbVar12 = (byte *)((uint)pbVar12 | 8);
          }
          puVar7 = (undefined2 *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0xc);
          (*(code *)*puVar7)();
          *(undefined2 *)(pbVar15 + 0xac) = *(undefined2 *)(pbVar15 + 0xc);
        }
        else {
          if (DAT_5b41_0939 == 9) {
            pbVar12 = (byte *)((uint)pbVar12 | 0xc);
            goto LAB_28eb_155d;
          }
          local_6._2_2_ = *(int *)(pbVar15 + 0x10);
          local_6._0_2_ = *(undefined2 **)(pbVar15 + 0xc);
          DAT_5b41_050f = 1;
          bVar21 = false;
          do {
            puVar7 = (undefined2 *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0xc);
            (*(code *)*puVar7)();
            *(undefined2 *)(pbVar15 + 0xac) = *(undefined2 *)(pbVar15 + 0xc);
            if ((*(int *)(pbVar15 + 0x10) == local_6._2_2_) &&
               ((undefined2 *)*(int *)(pbVar15 + 0xc) == (undefined2 *)local_6)) {
LAB_28eb_13e7:
              bVar21 = true;
            }
            else {
              iVar13 = FUN_28eb_0119();
              if ((iVar13 == 0) &&
                 ((*(int *)(pbVar15 + 0x58) == 0 || (iVar13 = FUN_28eb_1c08(), iVar13 != 0)))) {
                pbVar12 = (byte *)((uint)pbVar12 | 0xc);
                goto LAB_28eb_13e7;
              }
            }
          } while (!bVar21);
          *(int *)(pbVar15 + 0x10) = local_6._2_2_;
          *(undefined2 **)(pbVar15 + 0xc) = (undefined2 *)local_6;
          *(undefined2 **)(pbVar15 + 0xac) = (undefined2 *)local_6;
          puVar7 = (undefined2 *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0xc);
          (*(code *)*puVar7)();
        }
        DAT_5b41_050f = 0;
LAB_28eb_155d:
        if ((pbVar15[0xf] & 4) != 0) {
          if (((uint)pbVar12 & 1) == 0) {
            pbVar12 = (byte *)((uint)pbVar12 | 0x80);
          }
          else {
            pbVar12 = (byte *)((uint)pbVar12 | 0x800);
          }
        }
        if (((iRam000557bc == 1) || (iRam000557bc == 6)) && ((pbVar15[0xf] & 0x80) != 0)) {
          pbVar12 = (byte *)((uint)pbVar12 | 0x200);
        }
        return pbVar12;
      case 6:
        return pbVar12;
      case 7:
        pbVar15 = pbVar12;
        for (uVar16 = in_CX >> 1; uVar16 != 0; uVar16 = uVar16 - 1) {
          pbVar4 = pbVar15;
          pbVar15 = pbVar15 + 2;
          pbVar3 = pbVar11;
          pbVar11 = pbVar11 + 2;
          *(undefined2 *)pbVar4 = *(undefined2 *)pbVar3;
        }
        for (uVar16 = (uint)((in_CX & 1) != 0); uVar16 != 0; uVar16 = uVar16 - 1) {
          pbVar4 = pbVar15;
          pbVar15 = pbVar15 + 1;
          pbVar3 = pbVar11;
          pbVar11 = pbVar11 + 1;
          *pbVar4 = *pbVar3;
        }
        return pbVar12;
      case 8:
        return pbVar12;
      case 9:
        goto switchD_2000_8756_caseD_9;
      }
      goto switchD_2000_8802_caseD_7;
    }
    pbVar11 = (byte *)FUN_2424_49f1();
    if (5000 < DAT_554c_2f1c) {
      FUN_4551_03eb();
      pbVar11 = (byte *)FUN_406b_000c();
    }
  }
  if (*(int *)(pbVar15 + 0xb4) != 0) {
    iVar13 = *(int *)(pbVar15 + 0x22) - DAT_5b41_0925;
    pbVar11 = (byte *)(*(int *)(pbVar15 + 0x24) - DAT_5b41_0927);
    uVar16 = *(int *)(pbVar15 + 0xb4) - 2;
    if (uVar16 < 0xb) {
      switch(uVar16) {
      case 0:
        goto switchD_2000_8802_caseD_0;
      case 1:
        (*DAT_554c_517c)();
        pbVar11 = (byte *)FUN_1a9e_599d();
        DAT_554c_5596 = DAT_554c_5596 + -1;
        return pbVar11;
      case 2:
        while( true ) {
          FUN_3e34_0ec9();
          uVar19 = (undefined2)((ulong)local_6 >> 0x10);
          iVar13 = iVar13 + ((undefined2 *)local_6)[3];
          if (local_e <= iVar13) break;
          local_e = ((undefined2 *)local_6)[4];
        }
        pbVar11 = (byte *)FUN_2424_02ca();
        return pbVar11;
      case 3:
        return pbVar11;
      default:
        pbVar12 = (byte *)FUN_28eb_3287();
        do {
          if (pbVar12 == (byte *)0x0 && in_DX == 0) {
            return (byte *)0x0;
          }
          iVar13 = in_DX;
          iVar14 = FUN_28eb_00cb();
          if (((iVar14 == 0) &&
              (((in_DX != iVar20 || (iVar13 = in_DX, pbVar12 != pbVar15)) &&
               (iVar13 = in_DX, (pbVar12[0xd] & 0x20) == 0)))) && ((pbVar12[0xf] & 0x50) == 0)) {
            if ((((*(int *)(pbVar12 + 0x22) < local_8) &&
                 (local_6._2_2_ < *(int *)(pbVar12 + 0x54) + *(int *)(pbVar12 + 0x22))) &&
                ((*(int *)(pbVar12 + 0x24) < (int)pbVar11 &&
                 ((int)(undefined2 *)local_6 < *(int *)(pbVar12 + 0x56) + *(int *)(pbVar12 + 0x24)))
                )) && (((iVar13 = FUN_28eb_024e(), iVar13 != 0 ||
                        (iVar13 = FUN_28eb_03ff(), iVar13 != 0)) ||
                       (iVar14 = FUN_28eb_03ff(), iVar13 = in_DX, iVar14 != 0)))) {
              return (byte *)0x1;
            }
          }
          pbVar12 = (byte *)FUN_28eb_32d8();
          in_DX = iVar13;
        } while( true );
      case 5:
      case 10:
        piVar2 = (int *)(uVar16 * 2 + iVar13);
        *piVar2 = (int)(pbVar11 + *piVar2);
        if ((pbVar11 == (byte *)0x0) || (DAT_554c_5740 == 0 && DAT_554c_5742 == 0)) {
          DAT_5b41_0c40 = 0;
        }
        else {
          DAT_5b41_0c40 = 1;
        }
        DAT_5b41_0c42 = (uint)(DAT_554c_5744 != 0 || DAT_554c_5746 != 0);
        FUN_2e67_0231();
        return DAT_5b41_0bec;
      case 6:
        if (((undefined2 *)&DAT_5b41_2676)[iVar13 * 2] == 0 &&
            ((undefined2 *)&DAT_5b41_2678)[iVar13 * 2] == 0) {
          pbVar11 = (byte *)FUN_1000_130c();
        }
        else {
          pbVar11 = (byte *)func_0x0002fdf5();
        }
        ((undefined1 *)&DAT_5b41_25c2)[iVar13] = 0;
        ((undefined2 *)&DAT_5b41_25d8)[iVar13 * 2] = 0;
        ((undefined2 *)&DAT_5b41_25d6)[iVar13 * 2] = 0;
        ((undefined2 *)&DAT_5b41_2678)[iVar13 * 2] = 0;
        ((undefined2 *)&DAT_5b41_2676)[iVar13 * 2] = 0;
        *(undefined2 *)((undefined *)&DAT_5b41_2628 + iVar13 * 4) = 0;
        ((undefined2 *)&DAT_5b41_2626)[iVar13 * 2] = 0;
        return pbVar11;
      case 7:
switchD_2000_8802_caseD_7:
        if ((*(int *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0x2a) == 0) &&
           (*(int *)(*(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302) + 0x2c) == 0)) {
          uVar19 = *(undefined2 *)(pbVar15 + 0x46);
          pbVar11 = *(byte **)(pbVar15 + 0x44);
        }
        else {
          iVar13 = *(int *)(*(int *)(pbVar15 + 8) * 2 + 0x302);
          uVar19 = *(undefined2 *)(iVar13 + 0x2c);
          pbVar11 = (byte *)*(undefined2 *)(iVar13 + 0x2a);
        }
        *(undefined2 *)(pbVar15 + 0x56) = uVar19;
        *(byte **)(pbVar15 + 0x54) = pbVar11;
        return pbVar11;
      case 8:
        pbVar11 = (byte *)FUN_2424_25bc();
        return pbVar11;
      }
    }
    pbVar11 = (byte *)FUN_2424_49f1();
    if (5000 < DAT_554c_2f1c) {
      FUN_4551_03eb();
      pbVar11 = (byte *)FUN_406b_000c();
    }
  }
  return pbVar11;
LAB_2424_1186:
  iVar20 = puVar10[0x2c];
  if (((iVar20 != 0) && (iVar13 = FUN_28eb_1c08(), iVar13 != 0)) &&
     (((DAT_5b41_0939 != 9 ||
       (((*(int *)(iVar20 + 8) != DAT_5b41_0567._2_2_ ||
         (*(int *)(iVar20 + 6) != (int)DAT_5b41_0567)) &&
        ((*(int *)(iVar20 + 0xc) != DAT_5b41_0567._2_2_ ||
         (*(int *)(iVar20 + 10) != (int)DAT_5b41_0567)))))) ||
      (iVar13 = FUN_28eb_4d94(), iVar13 != 0)))) {
    if (*(int *)(iVar20 + 0xe) < *(int *)(iVar20 + 0x12)) {
      local_c = *(int *)(iVar20 + 0xe) - DAT_5b41_0925;
      local_10 = *(int *)(iVar20 + 0x1a) - *(int *)(iVar20 + 0xe);
    }
    else {
      local_c = *(int *)(iVar20 + 0x12) - DAT_5b41_0925;
      local_10 = *(int *)(iVar20 + 0x16) - *(int *)(iVar20 + 0x12);
    }
    local_10 = local_c + local_10;
    puVar10 = DAT_5b41_04ac;
    if (*(int *)(iVar20 + 0x10) < *(int *)(iVar20 + 0x14)) {
      local_e = *(int *)(iVar20 + 0x10) - DAT_5b41_0927;
      local_12 = local_e + (*(int *)(iVar20 + 0x1c) - *(int *)(iVar20 + 0x10));
    }
    else {
      local_e = *(int *)(iVar20 + 0x14) - DAT_5b41_0927;
      local_12 = local_e + (*(int *)(iVar20 + 0x18) - *(int *)(iVar20 + 0x14));
    }
LAB_2424_12ca:
    for (; puVar10 != (undefined2 *)0x0; puVar10 = (undefined2 *)*puVar10) {
      if ((puVar10[6] == 1) &&
         ((((((int)puVar10[1] < local_10 && (local_c <= (int)puVar10[3])) &&
            ((int)puVar10[2] < local_12)) && (local_e <= (int)puVar10[4])) ||
          (((local_8 != 0 || (local_a != 0)) && (iVar20 = FUN_2424_36fe(), iVar20 != 0)))))) {
        FUN_28eb_2d82();
        goto switchD_2000_8756_caseD_4;
      }
    }
  }
  goto LAB_2424_12ce;
switchD_2000_8802_caseD_0:
  puVar1 = (uint *)(uVar16 * 2 + iVar13);
  (&stack0x02c2)[(int)pbVar11] =
       (&stack0x02c2)[(int)pbVar11] + (char)(pbVar11 + *puVar1) + CARRY2(uVar16,uVar16) +
       (CARRY2((uint)pbVar11,*puVar1) ||
       CARRY2((uint)(pbVar11 + *puVar1),(uint)CARRY2(uVar16,uVar16)));
  iVar13 = *(int *)(pbVar15 + 8);
  if (iVar13 != 0x5b) {
    if (iVar13 < 0x5c) {
      if (iVar13 != 0x4c) {
        if (0x4c < iVar13) {
          if (iVar13 != 0x57) goto LAB_2321_0cd1;
          goto LAB_2321_0cc9;
        }
        if ((iVar13 != 7) && (iVar13 != 10)) goto LAB_2321_0cd1;
      }
      if (*(int *)(pbVar15 + 0x76) == 0) goto LAB_2321_0cd1;
    }
    else if (((iVar13 != 0x5c) && (iVar13 != 0x5d)) && (iVar13 != 0x5f)) goto LAB_2321_0cd1;
  }
LAB_2321_0cc9:
  FUN_1000_130c();
LAB_2321_0cd1:
  *(int *)(pbVar15 + 2) = DAT_5b41_04ff;
  *(byte **)param_1 = DAT_5b41_04fd;
  DAT_5b41_04ff = iVar20;
  DAT_5b41_04fd = pbVar15;
  return pbVar15;
}

