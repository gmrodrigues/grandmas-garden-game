// TIM2.EXE: FUN_2424_479c @ file 0x02DBDC Ghidra 0x289DC
// Subsystem: misc | Size: 234 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000226fc) overlaps instruction at (ram,0x000226fa)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl16far
FUN_2424_479c(uint *param_1,undefined2 param_2,uint *param_3,uint param_4,uint param_5,int param_6,
             uint param_7,int param_8,uint param_9,int param_10,uint param_11,int param_12,
             uint param_13,int param_14)

{
  byte *pbVar1;
  char *pcVar2;
  uint uVar3;
  undefined2 *puVar4;
  code *pcVar5;
  undefined2 *puVar6;
  code *pcVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  byte bVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  int iVar18;
  uint *puVar19;
  uint *puVar20;
  char cVar21;
  int in_CX;
  int extraout_DX;
  char cVar22;
  byte bVar23;
  uint in_DX;
  undefined2 *puVar24;
  char cVar25;
  undefined2 *puVar26;
  int iVar27;
  int *piVar28;
  int *piVar29;
  uint *puVar30;
  int *piVar31;
  undefined4 in_ESI;
  uint *unaff_DI;
  undefined2 uVar32;
  uint uVar33;
  undefined2 uVar34;
  uint *unaff_SS;
  byte in_AF;
  bool bVar35;
  undefined1 in_XMM4 [16];
  undefined4 uVar36;
  long lVar37;
  uint *puStack_40;
  int iStack_3e;
  int iStack_2a;
  uint *puStack_28;
  uint uStack_26;
  uint *puStack_24;
  undefined4 uStack_22;
  undefined1 *puStack_1e;
  uint *puStack_1a;
  uint *puStack_18;
  uint *puVar38;
  uint *puVar39;
  undefined1 auStack_e [2];
  undefined1 local_c [2];
  undefined2 local_a;
  uint *local_8;
  undefined4 uStack_6;
  
  auStack_e[0] = (undefined1)in_ESI;
  auStack_e[1] = (byte)((ulong)in_ESI >> 8);
  puVar19 = (uint *)*(undefined2 *)(param_1[4] * 2 + 0x68fe);
  puVar16 = (uint *)FUN_4551_0370();
  uVar34 = (undefined2)((ulong)in_ESI >> 0x10);
  local_c[0] = (byte)puVar16;
  local_c[1] = (byte)((uint)puVar16 >> 8);
  uVar32 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
  if (param_1[0x57] == 0) {
LAB_2424_4827:
    uVar32 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
    if (param_1[0x5a] != 0) {
      puVar30 = (uint *)CONCAT22(uVar34,(uint *)param_1[0x5a]);
      puVar16 = (uint *)0x8a85;
      FUN_4551_03eb();
      uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
      local_a = (uint *)((int)local_a + (param_1[0x11] - DAT_5b41_0925));
      puVar17 = (uint *)(param_1[0x12] - DAT_5b41_0927);
      local_8 = (uint *)((int)local_8 + (int)puVar17);
      puVar39 = (uint *)puVar30;
      if (puVar39 + -1 < (uint *)0xb) {
        iVar18 = 0x2000;
        puVar38 = puVar19;
        switch(puVar39) {
        case (uint *)0x2:
          if ((in_DX == 0xffff) && (puVar17 == (uint *)0xffff)) {
            local_c[0] = 0;
            local_c[1] = 0;
            auStack_e[0] = 0x5d;
            auStack_e[1] = 0x56;
            unaff_SS = (uint *)0x2000;
            iVar13 = FUN_1a9e_6a85();
            if ((in_DX != 0xffff) || (iVar13 != -1)) {
              puVar16 = (uint *)0x6;
            }
          }
          else {
            puVar16 = (uint *)0x5;
            puVar39 = unaff_DI;
          }
          puVar17 = (uint *)puVar30;
          if (4 < (int)puVar16) {
            local_c[0] = (byte)puVar30;
            local_c[1] = (byte)((ulong)puVar30 >> 8);
            auStack_e[0] = 0;
            auStack_e[1] = 0x20;
            uVar34 = FUN_1a9e_6e3d();
            local_c[0] = (byte)in_DX;
            local_c[1] = (byte)(in_DX >> 8);
            auStack_e[0] = (undefined1)uVar34;
            auStack_e[1] = (byte)((uint)uVar34 >> 8);
            puVar39 = (uint *)0x5666;
            unaff_SS = (uint *)puVar30;
            puVar19 = (uint *)FUN_28eb_2779();
            puVar17 = (uint *)puVar30;
            if (-1 < (int)puVar19) {
              uStack_22 = 0x7fff0000;
              while( true ) {
                local_c[0] = 0;
                local_c[1] = 0;
                auStack_e[0] = 0;
                auStack_e[1] = 0;
                lVar37 = FUN_2fc8_00fc();
                auStack_e[0] = (undefined1)((ulong)lVar37 >> 0x10);
                auStack_e[1] = (byte)((ulong)lVar37 >> 0x18);
                if (lVar37 != 0) break;
                uStack_22 = (uStack_22 >> 0x11) << 0x10;
              }
              local_a._0_1_ = SUB41(uStack_6,0);
              local_a._1_1_ = (byte)((ulong)uStack_6 >> 8);
              while( true ) {
                local_c[0] = (byte)(uStack_22 >> 0x10);
                local_c[1] = (byte)(uStack_22 >> 0x18);
                iVar13 = FUN_28eb_2aad();
                uVar11 = local_a._1_1_;
                puVar17 = (uint *)puVar30;
                local_a._1_1_ = (byte)((uint)iVar18 >> 8);
                uVar10 = local_a._1_1_;
                if (iVar13 < 1) break;
                local_a._1_1_ = uVar11;
                if (puVar16 == (uint *)0x6) {
                  local_c[0] = (byte)iVar13;
                  local_c[1] = (byte)((uint)iVar13 >> 8);
                  FUN_1a9e_836a();
                  iVar13 = iVar18 << 2;
                }
                local_c[0] = (byte)iVar13;
                local_c[1] = (byte)((uint)iVar13 >> 8);
                auStack_e[0] = (undefined1)local_a;
                auStack_e[1] = local_a._1_1_;
                (*DAT_554c_4db2)();
                iVar18 = 0x1000;
                local_c[0] = 0x1d;
                local_c[1] = 0x2c;
                local_a._0_1_ = 0;
                local_a._1_1_ = uVar10;
                FUN_1000_1a00();
              }
              local_c[0] = (byte)puVar19;
              local_c[1] = (byte)((uint)puVar19 >> 8);
              puVar39 = (uint *)0x2c3c;
              auStack_e[1] = local_a._1_1_;
              auStack_e[0] = 0;
              local_a._1_1_ = uVar11;
              FUN_28eb_29db();
              unaff_SS = puVar19;
            }
          }
          bVar35 = true;
          local_c[0] = 0;
          local_c[1] = (byte)((uint)iVar18 >> 8);
          auStack_e[0] = 0x4e;
          auStack_e[1] = 0x2c;
          FUN_1000_1821();
          if (!bVar35) {
            local_c[0] = auStack_e[0];
            local_c[1] = auStack_e[1];
            auStack_e[0] = SUB21(puVar39,0);
            auStack_e[1] = (byte)((uint)puVar39 >> 8);
            unaff_SS = (uint *)0x2c5b;
            func_0x0002fdf5();
          }
          if (unaff_SS != (uint *)0x0) {
            local_c[0] = (byte)unaff_SS;
            local_c[1] = (byte)((uint)unaff_SS >> 8);
            auStack_e[0] = 0;
            auStack_e[1] = 0x10;
            FUN_1000_130c();
            uRam00055624 = 0;
            uRam00055622 = 0;
          }
          if (puVar16 == (uint *)0x0) {
            bVar35 = true;
            local_c[0] = 0;
            local_c[1] = 0x10;
            auStack_e[0] = 0x90;
            auStack_e[1] = 0x2c;
            FUN_1000_1821();
            if (!bVar35) {
              local_c[0] = (byte)uStack_6;
              local_c[1] = (byte)((ulong)uStack_6 >> 8);
              auStack_e[0] = SUB21(local_8,0);
              auStack_e[1] = (byte)((uint)local_8 >> 8);
              func_0x0002fdf5();
            }
            if (puVar19 != (uint *)0x0) {
              local_c[0] = (byte)puVar19;
              local_c[1] = (byte)((uint)puVar19 >> 8);
              auStack_e[0] = 0;
              auStack_e[1] = 0x10;
              FUN_28eb_29db();
            }
            local_c[0] = (byte)((ulong)uStack_6 >> 0x10);
            local_c[1] = (byte)((ulong)uStack_6 >> 0x18);
            auStack_e[0] = 0;
            auStack_e[1] = 0x10;
            FUN_1a9e_82f5();
            uStack_6 = (uint *)((ulong)uStack_6 & 0xffff);
          }
          local_c[0] = (byte)puVar17;
          local_c[1] = (byte)((uint)puVar17 >> 8);
          auStack_e[0] = 0;
          auStack_e[1] = 0x10;
          FUN_1a9e_6e73();
          return uStack_6._2_2_;
        case (uint *)0x3:
          iVar18 = (int)(puVar39 + -1) * 2;
          do {
            iVar18 = iVar18 + (int)puVar17 * 4;
            if (((*(uint *)(iVar18 + 0x1d) & 0x7fff) == *(uint *)((int)uStack_6._2_2_ + 0x3d)) &&
               (*(int *)(iVar18 + 0x1b) == *(int *)((int)uStack_6._2_2_ + 0x3b))) {
              if (*(int *)((int)uStack_6._2_2_ + 0x37) == 0) {
                puVar19 = (uint *)FUN_1a9e_6a52();
                return puVar19;
              }
              *(int *)((int)uStack_6._2_2_ + 0x37) = *(int *)((int)uStack_6._2_2_ + 0x37) + -4;
            }
            else if ((*(uint *)((int)uStack_6._2_2_ +
                                (*(int *)((int)uStack_6._2_2_ + 0x37) >> 2) * 4 + 0x1d) & 0x8000) ==
                     0) {
              iVar18 = *(int *)((int)uStack_6._2_2_ + 0x41);
              uVar3 = *(uint *)((int)uStack_6._2_2_ + 0x3f);
              puVar30 = (uint *)((int)uStack_6._2_2_ + 0x3b);
              uVar33 = *puVar30;
              *puVar30 = *puVar30 + uVar3;
              *(int *)((int)uStack_6._2_2_ + 0x3d) =
                   *(int *)((int)uStack_6._2_2_ + 0x3d) + iVar18 + (uint)CARRY2(uVar33,uVar3);
              FUN_1000_0e6d();
            }
            else {
              iVar18 = FUN_1000_0d10();
              if (iVar18 != 4) {
                puVar19 = (uint *)FUN_1a9e_6a52();
                return puVar19;
              }
              *(int *)((int)uStack_6._2_2_ + 0x37) = *(int *)((int)uStack_6._2_2_ + 0x37) + 4;
              if (0x17 < *(int *)((int)uStack_6._2_2_ + 0x37)) {
                puVar19 = (uint *)FUN_1a9e_6a52();
                return puVar19;
              }
              *(undefined1 *)((int)uStack_6._2_2_ + *(int *)((int)uStack_6._2_2_ + 0x37) + 2) = 0;
              puVar30 = (uint *)((int)uStack_6._2_2_ + 0x3b);
              uVar33 = *puVar30;
              *puVar30 = *puVar30 + 8;
              *(int *)((int)uStack_6._2_2_ + 0x3d) =
                   *(int *)((int)uStack_6._2_2_ + 0x3d) + (uint)(0xfff7 < uVar33);
              iVar18 = FUN_1000_0d10();
              if (iVar18 != 1) {
                puVar19 = (uint *)FUN_1a9e_6a52();
                return puVar19;
              }
              uVar33 = *(uint *)((int)uStack_6._2_2_ + 0x3b);
              uVar3 = *(uint *)((int)uStack_6._2_2_ + 0x3f);
              iVar18 = (int)uStack_6._2_2_ + (*(int *)((int)uStack_6._2_2_ + 0x37) >> 2) * 4;
              *(int *)(iVar18 + 0x1d) =
                   *(int *)((int)uStack_6._2_2_ + 0x3d) + *(int *)((int)uStack_6._2_2_ + 0x41) +
                   (uint)CARRY2(uVar33,*(uint *)((int)uStack_6._2_2_ + 0x3f));
              *(int *)(iVar18 + 0x1b) = uVar33 + uVar3;
              *(undefined2 *)((int)uStack_6._2_2_ + 0x3f) =
                   *(undefined2 *)((int)uStack_6._2_2_ + 0x3f);
              *(uint *)((int)uStack_6._2_2_ + 0x41) = *(uint *)((int)uStack_6._2_2_ + 0x41) & 0x7fff
              ;
              if (*(int *)((int)uStack_6._2_2_ + 0x41) < 0) {
LAB_1a9e_6ddd:
                puVar19 = (uint *)FUN_1a9e_6a52();
                return puVar19;
              }
              uVar33 = *(uint *)((int)uStack_6._2_2_ + 0x1d) & 0x7fff;
              if ((uVar33 <= *(uint *)((int)uStack_6._2_2_ + 0x41)) &&
                 ((*(uint *)((int)uStack_6._2_2_ + 0x41) != uVar33 ||
                  (*(uint *)((int)uStack_6._2_2_ + 0x1b) <= *(uint *)((int)uStack_6._2_2_ + 0x3f))))
                 ) goto LAB_1a9e_6ddd;
              if ((uint *)*(undefined2 *)((int)uStack_6._2_2_ + 0x37) == (uint *)uStack_6) {
                iVar18 = FUN_1a9e_6904();
                if ((iVar18 != 0) &&
                   (bVar35 = param_3 == (uint *)0x0, param_3 = (uint *)((int)param_3 + -1), bVar35))
                {
                  *(int *)((int)uStack_6._2_2_ + 0x39) = (int)local_8;
                  return (uint *)*(undefined2 *)((int)uStack_6._2_2_ + 0x3b);
                }
              }
            }
            puVar17 = (uint *)(*(int *)((int)uStack_6._2_2_ + 0x37) >> 2);
            iVar18 = (int)uStack_6._2_2_;
          } while( true );
        case (uint *)0x4:
          return puVar17;
        case (uint *)0x5:
          do {
            iVar13 = 0x2000;
            FUN_1a9e_836a();
            do {
              local_c[0] = (byte)puVar30;
              local_c[1] = (byte)((ulong)puVar30 >> 8);
              iVar13 = iVar13 * 2;
              auStack_e = (undefined1  [2])iVar13;
              func_0x0002ea8f();
              puVar16 = (uint *)CONCAT11(local_c[1],local_c[0]);
              puVar19 = (uint *)((int)puVar38 + (int)(uint *)puVar30);
              if (iVar13 < (int)puVar19 + (int)(uint *)puVar30) {
                puVar30 = (uint *)(ulong)(uint)(iVar13 - (int)puVar19);
                puVar16 = (uint *)((iVar13 - (int)puVar19) * (int)puVar38);
                if (local_8 == (uint *)0x6) {
                  local_c[0] = (byte)((uint)puVar16 >> 1);
                  bVar23 = (byte)((uint)puVar16 >> 8);
                  local_c[1] = bVar23 >> 1;
                  local_c[0] = (byte)(CONCAT11(local_c[1],local_c[0]) >> 1);
                  local_c[1] = bVar23 >> 2;
                  puVar16 = (uint *)CONCAT11(local_c[1],local_c[0]);
                }
              }
LAB_1a9e_7d65:
              if (iVar13 <= (int)puVar19) {
LAB_1a9e_7d6a:
                local_c[0] = (byte)puVar38;
                local_c[1] = (byte)((uint)puVar38 >> 8);
                auStack_e[0] = 0;
                auStack_e[1] = 0x20;
                FUN_1000_130c();
                local_c[0] = (byte)((ulong)uStack_6 >> 0x10);
                local_c[1] = (byte)((ulong)uStack_6 >> 0x18);
                auStack_e[0] = 0;
                auStack_e[1] = 0x10;
                FUN_28eb_29db();
                if ((uint *)uStack_6 != (uint *)0x0) {
                  local_c[0] = (byte)param_1;
                  local_c[1] = (byte)((uint)param_1 >> 8);
                  auStack_e[0] = 0;
                  auStack_e[1] = 0x10;
                  FUN_1a9e_6e73();
                }
                return local_8;
              }
              iVar13 = 0x26e8;
              local_c = (undefined1  [2])puVar16;
              FUN_28eb_2aad();
              puVar38 = puVar19;
            } while (local_8 != (uint *)0x6);
          } while( true );
        case (uint *)0x7:
          do {
            out(in_DX,(char)puVar17);
            puStack_18 = (uint *)uStack_6;
            FUN_4551_03eb();
            unaff_DI = (uint *)((int)unaff_DI + (int)(uint *)puVar30);
            auStack_e = (undefined1  [2])((int)auStack_e + (int)puVar19);
            puStack_1a = (uint *)0x2;
            _puStack_1e = (undefined1 *)CONCAT22(unaff_SS,&stack0xfff0);
            uStack_22 = 0x4551893f;
            puVar19 = (uint *)FUN_2424_1e00();
            puVar6 = (undefined2 *)CONCAT11(local_c[0],auStack_e[1]);
            uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
            if (param_1[0x5a] == 0) {
              return puVar19;
            }
            uStack_6 = (uint *)CONCAT22(param_1[0x5a],(uint *)uStack_6);
            puVar19 = (uint *)(param_1[0x11] - DAT_5b41_0925);
            puVar30 = (uint *)CONCAT22((int)((ulong)puVar30 >> 0x10),puVar19);
            puVar17 = (uint *)(param_1[0x12] - DAT_5b41_0927);
            uVar33 = param_1[0x5a] - 2;
            if (10 < uVar33) {
              FUN_4551_03eb();
              auStack_e = (undefined1  [2])((int)auStack_e + (int)puVar17);
              puVar19 = (uint *)FUN_2424_1e00();
              return puVar19;
            }
            puVar24 = (undefined2 *)(uVar33 * 2);
            bVar23 = (byte)puVar17;
            switch(uVar33) {
            case 0:
              *(byte *)(uint *)((int)puVar24 + (int)puVar19) =
                   (char)*(uint *)((int)puVar24 + (int)puVar19) + bVar23;
              puVar19 = puVar17;
              break;
            case 1:
              puVar30 = puVar19;
              *puVar30 = *puVar30 +
                         (uint)CARRY2(uVar33,uVar33) * (((uint)puVar17 & 3) - (*puVar30 & 3));
              uVar11 = in(in_DX);
              *(undefined1 *)puVar17 = uVar11;
              puVar30 = (uint *)(&stack0xfffe + (int)puVar19);
              *puVar30 = *puVar30 +
                         (uint)(auStack_e[1] < (byte)puVar17[0x1e]) *
                         (((uint)(puVar17 + 1) & 3) - (*puVar30 & 3));
              iVar18 = CONCAT11(local_c[1],local_c[0]);
              puVar16 = puVar17 + 2;
              uVar33 = in(in_DX);
              puVar17[1] = uVar33;
              local_c[1] = (byte)puVar16;
              local_a._0_1_ = (undefined1)((uint)puVar16 >> 8);
              iVar18 = iVar18 + 1;
              puVar24 = (undefined2 *)((int)&uStack_6 + 3);
              uVar32 = in(in_DX);
              bVar23 = 9 < ((byte)uVar32 & 0xf) | 9 < ((bVar23 ^ 0x38) & 0xf) | in_AF;
              if (iVar18 == 1 || (char)iVar18 == (char)((uint)unaff_DI >> 8)) {
                bVar12 = ((byte)uVar32 + bVar23 * '\x06' & 0xf) % 0x37;
                puVar6 = (undefined2 *)((int)auStack_e + 1);
                auStack_e[1] = (byte)puVar24;
                local_c[0] = (byte)((uint)puVar24 >> 8);
                cVar21 = '\x16';
                unique0x100019dc = puVar16;
                unique0x100019de = puVar24;
                do {
                  puVar24 = puVar24 + -1;
                  puVar6 = puVar6 + -1;
                  *puVar6 = *puVar24;
                  cVar21 = cVar21 + -1;
                } while ('\0' < cVar21);
                puVar30 = puVar16;
                bVar23 = 9 < (bVar12 & 0xf) | bVar23;
                _DAT_5000_eaf7 = CONCAT11(bVar23,bVar12 + bVar23 * '\x06') & 0xff0f;
                uVar33 = *unaff_DI;
                puVar6 = stack0xfff3;
                puVar16 = stack0xfff5;
                if (((int)(uint)bVar12 < (int)*puVar30) && (SBORROW2((uint)bVar12,*puVar30))) {
                  *(uint *)((int)unaff_DI + -1) = *(uint *)((int)unaff_DI + -1) ^ (uint)puVar19;
                  DAT_554c_36f1 = DAT_554c_36f1 + '\x01';
                  puVar24 = (undefined2 *)in(0x36);
                  *(undefined1 *)(puVar17 + 3) = *(undefined1 *)0xb136;
                  *(undefined2 *)0x367c = puVar24;
                  out(*puVar24,CONCAT11((char)uVar33,(char)in_DX));
                }
              }
              else {
                out(*puVar19,in_DX);
              }
              unique0x100019f8 = puVar6;
              unique0x100019fa = puVar16;
              puVar19 = (uint *)FUN_28eb_4cfc();
              return puVar19;
            case 2:
              out(in_DX,bVar23);
              puVar16 = (uint *)(in_CX + (int)(((long)((int)puVar17 - in_CX) *
                                               (long)(int)(puVar17 + -uVar33)) /
                                              (long)(int)(&stack0xfffe + uVar33 * -2)));
              if (DAT_554c_42ca < puVar16) {
                puVar39 = puVar16;
                puVar19 = DAT_554c_42c4;
                if (DAT_554c_42ca < puVar17) {
                  return DAT_554c_42ca;
                }
              }
              else {
                puVar39 = DAT_554c_42c4;
                if (puVar17 <= DAT_554c_42ca) goto LAB_1a9e_57cd;
                puVar30 = (uint *)ZEXT24(DAT_554c_42c4);
                puVar39 = puVar17;
                puVar17 = puVar16;
              }
              puVar39 = (uint *)((int)puVar19 +
                                (int)(((long)((int)(uint *)puVar30 - (int)puVar19) *
                                      (long)((int)DAT_554c_42ca - (int)puVar39)) /
                                     (long)((int)puVar17 - (int)puVar39)));
LAB_1a9e_57cd:
              if ((puVar39 <= DAT_554c_42c6) ||
                 (puVar19 = DAT_554c_42c6, (uint *)puVar30 <= DAT_554c_42c6)) {
                puVar19 = (uint *)(*DAT_554c_4d7e)();
              }
              return puVar19;
            case 3:
              goto LAB_2424_4a1f;
            case 4:
              return (uint *)*(uint **)puVar19;
            case 5:
              movmskps(puVar30,in_XMM4);
              do {
                iVar18 = puVar24[0x11];
                iVar13 = puVar24[0x12];
                *(int *)(local_c + in_CX) = puVar24[0x2a] + iVar18;
                *(int *)(auStack_e + in_CX) = puVar24[0x2b] + iVar13;
                if ((((iVar18 < *(int *)((int)&local_8 + in_CX)) &&
                     (*(int *)((int)&uStack_6 + in_CX + 2) < *(int *)(local_c + in_CX))) &&
                    (iVar13 < *(int *)((int)&local_a + in_CX))) &&
                   (*(int *)((int)&uStack_6 + in_CX) < *(int *)(auStack_e + in_CX))) {
                  iVar18 = FUN_28eb_024e();
                  if (iVar18 != 0) {
                    return (uint *)0x1;
                  }
                  iVar18 = FUN_28eb_03ff();
                  if (iVar18 != 0) {
                    return (uint *)0x1;
                  }
                  iVar18 = FUN_28eb_03ff();
                  if (iVar18 != 0) {
                    return (uint *)0x1;
                  }
                }
                do {
                  do {
                    do {
                      uVar34 = FUN_28eb_32d8();
                      *(uint *)(&stack0xfff0 + in_CX) = in_DX;
                      *(undefined2 *)(&stack0xffee + in_CX) = uVar34;
                      if (*(int *)(&stack0xffee + in_CX) == 0 && *(int *)(&stack0xfff0 + in_CX) == 0
                         ) {
                        return (uint *)0x0;
                      }
                      iVar18 = FUN_28eb_00cb();
                    } while (iVar18 != 0);
                    in_DX = *(uint *)(&stack0xfff0 + in_CX);
                  } while ((in_DX == *(uint *)((int)&param_2 + in_CX)) &&
                          (*(int *)(&stack0xffee + in_CX) == *(int *)((int)&param_1 + in_CX)));
                  uVar34 = (undefined2)((ulong)*(undefined2 **)(&stack0xffee + in_CX) >> 0x10);
                  puVar24 = (undefined2 *)*(undefined2 **)(&stack0xffee + in_CX);
                } while (((*(byte *)((int)puVar24 + 0xd) & 0x20) != 0) ||
                        ((*(byte *)((int)puVar24 + 0xf) & 0x50) != 0));
              } while( true );
            case 6:
              *(uint *)((int)puVar24 + (int)puVar19) =
                   *(uint *)((int)puVar24 + (int)puVar19) + (int)puVar17;
              if ((puVar17 == (uint *)0x0) || (DAT_554c_5740 == 0 && DAT_554c_5742 == 0)) {
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
              DAT_554c_516f = (uint *)FUN_2fc8_01f3();
              auStack_e[0] = 0x4c;
              auStack_e[1] = 0;
              uVar33 = FUN_2fc8_01f3();
              *param_3 = uVar33;
              puVar19 = DAT_554c_516f;
              *(undefined2 *)CONCAT11(param_2._1_1_,(byte)param_2) = DAT_554c_516f;
              return puVar19;
            }
          } while( true );
        case (uint *)0x8:
          if (((((puVar19 == (uint *)0x4) && (999 < DAT_5b41_0c98)) &&
               (in_DX = DAT_554c_2fce,
               (int)CONCAT11(param_2._1_1_,(byte)param_2) <= (int)DAT_554c_2fce)) &&
              ((DAT_554c_2fce != CONCAT11(param_2._1_1_,(byte)param_2) || (param_1 <= DAT_554c_2fcc)
               ))) && (DAT_5b41_0cb9 == 0)) {
            uStack_6 = (uint *)CONCAT22(DAT_5b41_0ca2,DAT_5b41_0ca0);
            DAT_5b41_0cb9 = DAT_5b41_0c98;
            in_DX = DAT_5b41_0ca2;
            FUN_1a9e_5c44();
          }
          if (((DAT_5b41_0c9c != (uint *)0x0 || DAT_5b41_0c9e != 0) && (puVar19 == (uint *)0x4)) &&
             (DAT_5b41_0c98 < 1000)) {
            in_DX = (int)DAT_554c_2fd0 >> 0xf;
            if (((int)CONCAT11(param_2._1_1_,(byte)param_2) <= (int)in_DX) &&
               ((piVar28 = _DAT_554c_2fd2, in_DX != CONCAT11(param_2._1_1_,(byte)param_2) ||
                (param_1 <= DAT_554c_2fd0)))) {
              for (; (piVar28 != (int *)0x0 && ((*piVar28 != -1 && (*piVar28 != DAT_5b41_0c98))));
                  piVar28 = piVar28 + 1) {
              }
              if ((piVar28 == (int *)0x0) || (*piVar28 == DAT_5b41_0c98)) {
                uStack_6 = (uint *)CONCAT22(DAT_5b41_0c9e,DAT_5b41_0c9c);
                in_DX = DAT_5b41_0c9e;
                if (DAT_5b41_0cbb != 0) {
                  FUN_4bdc_32e9();
                }
                DAT_5b41_0cbb = DAT_5b41_0c98;
                FUN_1a9e_5c44();
              }
            }
          }
          if ((uint *)uStack_6 == (uint *)0x0 && uStack_6._2_2_ == (uint *)0x0) {
            puVar16 = (uint *)FUN_22de_01ec();
            uStack_6 = (uint *)CONCAT22(in_DX,puVar16);
            if ((puVar16 != (uint *)0x0 || in_DX != 0) && (puVar19 == (uint *)0x4)) {
              DAT_5b41_0c9a = 1;
            }
          }
          return (uint *)uStack_6;
        case (uint *)0x9:
          FUN_1000_199e();
          puVar19 = (uint *)(1 << (local_c[0] & 0x1f));
          iVar18 = (int)puVar19 >> 0xf;
          uVar34 = FUN_1000_19bf();
          uStack_6 = (uint *)CONCAT22(uStack_6._2_2_,uVar34);
          puVar16 = (uint *)FUN_1000_19bf();
          iStack_3e = 0;
          uStack_6._2_2_ = puVar16;
          for (puStack_40 = (uint *)0x0;
              (iStack_3e < iVar18 || ((iStack_3e <= iVar18 && (puStack_40 <= puVar19))));
              puStack_40 = (uint *)((int)puStack_40 + 1)) {
            uVar34 = FUN_1000_19bf();
            local_a._0_1_ = (undefined1)uVar34;
            local_a._1_1_ = (byte)((uint)uVar34 >> 8);
            local_8 = (uint *)FUN_1000_19bf();
            if (((uint *)uStack_6 != (uint *)CONCAT11(local_a._1_1_,(undefined1)local_a)) ||
               (uStack_6._2_2_ != local_8)) {
              FUN_2424_1a04();
              uStack_6._0_2_ = (uint *)CONCAT11(local_a._1_1_,(undefined1)local_a);
              uStack_6._2_2_ = local_8;
            }
            FUN_1000_180a();
            FUN_1000_180a();
            iStack_3e = iStack_3e + (uint)((uint *)0xfffe < puStack_40);
          }
          return puStack_40;
        case (uint *)0xa:
          do {
          } while( true );
        case (uint *)0xc:
switchD_2000_8a43_caseD_9:
          uVar11 = in(in_DX);
          lVar37 = CONCAT22(in_DX,CONCAT11((char)((uint)puVar17 >> 8),uVar11));
          puVar17 = &local_a;
          do {
            iVar18 = (int)((ulong)lVar37 >> 0x10);
            local_c[0] = (byte)lVar37;
            local_c[1] = (byte)((ulong)lVar37 >> 8);
            puVar38 = unaff_DI;
            do {
              puVar16 = puVar19;
              if ((int)puVar17 <= (int)puVar16) {
                local_8 = (uint *)0x1;
                if (DAT_554c_42df != '\0') {
                  local_c[0] = (byte)((ulong)uStack_6 >> 0x10);
                  local_c[1] = (byte)((ulong)uStack_6 >> 0x18);
                  auStack_e[0] = 0;
                  auStack_e[1] = 0x20;
                  FUN_28eb_29db();
                  puVar19 = param_1;
                  local_c[0] = 0;
                  local_c[1] = 0;
                  auStack_e[0] = 0x2c;
                  auStack_e[1] = 0x56;
                  iVar13 = FUN_1a9e_6a85();
                  puVar38 = param_1;
                  if ((iVar18 == -1) && (iVar13 == -1)) {
                    local_c[0] = 0;
                    local_c[1] = 0;
                    auStack_e[0] = 0x35;
                    auStack_e[1] = 0x56;
                    iVar13 = FUN_1a9e_6a85();
                    if ((iVar18 != -1) || (iVar13 != -1)) {
                      local_8 = (uint *)0x6;
                    }
                  }
                  else {
                    local_8 = (uint *)0x5;
                    puVar38 = puVar19;
                  }
                  if (4 < (int)local_8) {
                    local_c[0] = (byte)param_1;
                    local_c[1] = (byte)((uint)param_1 >> 8);
                    auStack_e[0] = 0;
                    auStack_e[1] = 0x20;
                    uVar34 = FUN_1a9e_6e3d();
                    local_c[0] = (byte)iVar18;
                    local_c[1] = (byte)((uint)iVar18 >> 8);
                    auStack_e[0] = (undefined1)uVar34;
                    auStack_e[1] = (byte)((uint)uVar34 >> 8);
                    puVar38 = (uint *)0x563e;
                    iVar13 = 0;
                    iVar18 = FUN_28eb_2779();
                    bVar23 = local_a._1_1_;
                    uStack_6 = (uint *)CONCAT22(iVar18,(uint *)uStack_6);
                    if (-1 < iVar18) {
                      puVar19 = (uint *)0x0;
                      puVar30 = (uint *)(ZEXT24(local_a) / 0x2000);
                      if (local_8 == (uint *)0x6) {
                        local_a._0_1_ = (undefined1)((uint)local_a >> 1);
                        local_a._1_1_ = local_a._1_1_ >> 1;
                        local_a._0_1_ =
                             (undefined1)(CONCAT11(local_a._1_1_,(undefined1)local_a) >> 1);
                        local_a._1_1_ = bVar23 >> 2;
                      }
                      puVar16 = local_a;
                      auStack_e = (undefined1  [2])CONCAT11(auStack_e[1],auStack_e[0]);
                      if ((uint *)puVar30 == (uint *)0x0) goto LAB_1a9e_7d65;
                      puVar30 = (uint *)0x0;
                      auStack_e = (undefined1  [2])CONCAT11(auStack_e[1],auStack_e[0]);
                      goto LAB_1a9e_7d65;
                    }
                  }
                }
                goto LAB_1a9e_7d6a;
              }
              FUN_28eb_2aad();
              local_c[0] = (byte)puVar30;
              local_c[1] = (byte)((ulong)puVar30 >> 8);
              auStack_e[0] = 200;
              auStack_e[1] = 0x4b;
              puVar17 = (uint *)0x4bc8;
              func_0x0002ea8b();
              puVar19 = (uint *)((int)puVar16 + (int)(uint *)puVar30);
              iVar18 = extraout_DX;
              puVar20 = puVar17;
              puVar38 = puVar16;
              unaff_DI = puVar16;
            } while ((int)puVar19 + (int)(uint *)puVar30 < 0x4bc9);
switchD_2000_8a43_caseD_7:
            puVar30 = (uint *)(ulong)(uint)((int)puVar17 - (int)puVar19);
            lVar37 = (long)((int)puVar17 - (int)puVar19) * (long)(int)puVar16;
            puVar17 = puVar20;
          } while( true );
        }
switchD_2000_8a43_caseD_8:
        puVar19 = (uint *)puVar30;
        if (DAT_554c_02e6 != 0) {
          func_0x00054bdf();
        }
        func_0x00054ab0();
        if ((puVar19 != (uint *)0x0) && (5000 < DAT_554c_2f1c)) {
          FUN_460e_101b();
        }
        FUN_2424_03c5();
        FUN_2424_028d();
        FUN_460e_18af();
        FUN_2e67_0a1f();
        FUN_2424_08e8();
        FUN_311b_06b8();
        FUN_406b_03cb();
        puVar19 = (uint *)FUN_2424_01b2();
        return puVar19;
      }
      iVar18 = FUN_2424_4007();
      if (iVar18 != 0) goto LAB_2424_489b;
    }
    puVar19 = (uint *)0x0;
  }
  else {
    puVar30 = (uint *)CONCAT22(uVar34,(uint *)param_1[0x57]);
    FUN_4551_03eb();
    uVar33 = (uint)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
    local_a = (uint *)(CONCAT11(local_a._1_1_,(undefined1)local_a) + (param_1[0x11] - DAT_5b41_0925)
                      );
    puVar17 = (uint *)(param_1[0x12] - DAT_5b41_0927);
    local_8 = (uint *)((int)local_8 + (int)puVar17);
    puVar39 = (uint *)puVar30;
    if ((int)puVar39 - 1U < 9) {
      pbVar8 = (byte *)(((int)puVar39 - 1U) * 2);
      iVar18 = 0x2000;
      puVar20 = &local_a;
      switch(puVar39) {
      case (uint *)0x1:
        FUN_2424_1a04();
        if (5000 < DAT_554c_2f1c) {
          uStack_6._0_2_ = (uint *)0x2000;
          local_8 = (uint *)0x4721;
          FUN_2424_196d();
          uStack_6 = (uint *)CONCAT22(uStack_6._2_2_,(uint *)0x1);
          local_8 = (uint *)0x2000;
          local_a._0_1_ = 0x28;
          local_a._1_1_ = 0x47;
          FUN_2424_184a();
        }
        uStack_6._0_2_ = (uint *)0x2000;
        local_8 = (uint *)0x472f;
        FUN_2424_0304();
        uStack_6._0_2_ = (uint *)0x0;
        local_8 = (uint *)0x2000;
        local_a._0_1_ = 0x36;
        local_a._1_1_ = 0x47;
        FUN_460e_1314();
        uStack_6._0_2_ = (uint *)0x460e;
        local_8 = (uint *)0x473e;
        FUN_2424_1650();
        DAT_5b41_0567._2_2_ = uStack_6._2_2_;
        DAT_5b41_0567._0_2_ = (uint *)uStack_6;
        return (uint *)uStack_6;
      case (uint *)0x2:
        puVar17 = (uint *)*(undefined2 *)(*(int *)(pbVar8 + 8) * 2 + 0x68fe);
        puStack_18 = (uint *)FUN_4551_0370();
        local_c[0] = (byte)puStack_18;
        local_c[1] = (byte)((uint)puStack_18 >> 8);
        uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        if (param_1[0x57] != 0) {
          puVar30 = (uint *)(ulong)param_1[0x57];
          puVar19 = &local_a;
          _puStack_1e = (undefined1 *)0x45518b4f;
          FUN_4551_03eb();
          uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
          puVar39 = (uint *)((int)local_a + (param_1[0x11] - DAT_5b41_0925));
          local_a._0_1_ = SUB21(puVar39,0);
          local_a._1_1_ = (byte)((uint)puVar39 >> 8);
          puVar20 = (uint *)(param_1[0x12] - DAT_5b41_0927);
          local_8 = (uint *)((int)local_8 + (int)puVar20);
          puVar38 = (uint *)puVar30;
          local_a = puVar39;
          if ((int)puVar38 - 1U < 9) {
            puVar24 = (undefined2 *)(((int)puVar38 - 1U) * 2);
            puStack_1a = puVar17;
            switch(puVar38) {
            case (uint *)0x1:
              if ((char)puVar20 != '\0') {
                FUN_2fc8_0364();
                puVar20 = (uint *)0x0;
                if (DAT_554c_5173 < -0x1e) {
                  puVar20 = (uint *)0x4;
                }
                else if (0x1d < DAT_554c_5173) {
                  puVar20 = (uint *)0x8;
                }
                if (DAT_554c_5175 < -0x1e) {
                  puVar20 = (uint *)((uint)puVar20 | 1);
                }
                else if (0x1d < DAT_554c_5175) {
                  puVar20 = (uint *)((uint)puVar20 | 2);
                }
              }
              return puVar20;
            case (uint *)0x2:
              cVar22 = (char)((int)puVar20 >> 0xf);
              cVar25 = (char)((uint)puVar24 >> 8) + cVar22;
              *(undefined2 *)(CONCAT11(cVar25,(char)puVar24) + (int)puVar38) = 0x7404;
              puVar20 = puVar20 + 0xdc;
              cVar21 = (&stack0xfffe)[(int)puVar17];
              bVar23 = cVar22 + (&stack0xfffe)[(int)puVar17];
              pbVar1 = (byte *)((int)puVar17 +
                               CONCAT11(cVar25,(char)puVar24 + (char)((uint)in_CX >> 8)) + -0x15ba);
              *pbVar1 = *pbVar1 >> 3 | *pbVar1 << 5;
              if (bVar23 != 0 && SCARRY1(cVar22,cVar21) == (int)((uint)bVar23 << 8) < 0) {
                *(char *)((int)puVar38 + 0xb) = *(char *)((int)puVar38 + 0xb) + bVar23;
                DAT_5b41_0513 = local_8;
                if (DAT_5b41_051d + -0x12 <= (int)local_8) {
                  uVar33 = 1;
                  DAT_5b41_0513 = (uint *)((int)uStack_6._2_2_ + 0x12);
                }
                if ((puStack_18 == (uint *)0x0) || (-0x13 < (int)puVar39)) {
                  unaff_DI = (uint *)0x1;
                  DAT_5b41_0515 = puVar39;
                }
                else {
                  DAT_5b41_0515 = (uint *)(CONCAT11(auStack_e[1],auStack_e[0]) + -0x12);
                  DAT_5b41_0513 = (uint *)((int)uStack_6._2_2_ + 0x12);
                  uVar33 = 1;
                }
                puVar19 = DAT_5b41_0515;
                unaff_SS = (uint *)0x0;
                puVar20 = (uint *)FUN_4551_01dc();
              }
              if (uVar33 != 0) {
                piVar31 = (int *)CONCAT22(param_3,(int *)CONCAT11(param_2._1_1_,(byte)param_2));
                *piVar31 = *piVar31 + -0x24;
                piVar31 = (int *)CONCAT11(param_2._1_1_,(byte)param_2) + 2;
                *piVar31 = *piVar31 + 0x24;
              }
              if (unaff_DI != (uint *)0x0) {
                piVar31 = (int *)(CONCAT11(param_2._1_1_,(byte)param_2) + 2);
                *piVar31 = *piVar31 + -0x24;
                piVar31 = (int *)(CONCAT11(param_2._1_1_,(byte)param_2) + 6);
                *piVar31 = *piVar31 + 0x24;
              }
              if (unaff_SS != (uint *)0x0) {
                piVar31 = (int *)(CONCAT11(param_2._1_1_,(byte)param_2) + 4);
                *piVar31 = *piVar31 + 0x24;
              }
              if (puVar19 != (uint *)0x0) {
                piVar31 = (int *)(CONCAT11(param_2._1_1_,(byte)param_2) + 6);
                *piVar31 = *piVar31 + 0x24;
              }
              return puVar20;
            case (uint *)0x4:
              uVar36 = FUN_1a9e_5ad4();
              param_1 = (uint *)uVar36;
              param_2._0_1_ = (byte)((ulong)uVar36 >> 0x10);
              param_2._1_1_ = (undefined1)((ulong)uVar36 >> 0x18);
              FUN_1a9e_5ad4();
              do {
                uVar33 = 32000;
                if (param_6 == 0) {
                  if (param_5 == 0) {
                    return (uint *)uStack_6;
                  }
                  if ((int)param_5 < 0x7d01) {
                    uVar33 = param_5;
                  }
                }
                (*pcRam00025b2d)();
                auStack_e[0] = 0xc9;
                auStack_e[1] = 5;
                (*pcRam00025b2d)();
                local_c[0] = 0xd2;
                local_c[1] = 5;
                (*pcRam00025b2f)();
                bVar35 = param_5 < uVar33;
                param_5 = param_5 - uVar33;
                param_6 = param_6 - (uint)bVar35;
              } while( true );
            case (uint *)0x5:
              param_1[0x4b] = puVar24[0x11];
              param_1[0x1f] = *(uint *)(*(int *)((int)puVar38 * 2 + 0x302) + 0x38);
              param_1[0x52] = 0xffff;
              param_1[0x53] = 0xffff;
              uVar33 = *(uint *)(*(int *)((int)puVar38 * 2 + 0x302) + 0x2a);
              param_1[0x25] = in_DX;
              param_1[0x24] = uVar33;
              iVar18 = *(int *)((int)puVar38 * 2 + 0x302);
              if (*(int *)(iVar18 + 0x1c) != 0 || *(int *)(iVar18 + 0x1e) != 0) {
                puVar4 = (undefined2 *)(*(int *)((int)puVar38 * 2 + 0x302) + 0x1c);
                iVar18 = (*(code *)*puVar4)();
                if (iVar18 == 0) {
                  return (uint *)0x0;
                }
              }
              puVar4 = (undefined2 *)(*(int *)((int)puVar38 * 2 + 0x302) + 8);
              (*(code *)*puVar4)();
              uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10)
              ;
              param_1[0x56] = param_1[6];
              FUN_28eb_3328();
              return (uint *)0x1;
            case (uint *)0x6:
switchD_2000_8802_caseD_7:
              uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10)
              ;
              if ((*(int *)(*(int *)(param_1[4] * 2 + 0x302) + 0x2a) == 0) &&
                 (*(int *)(*(int *)(param_1[4] * 2 + 0x302) + 0x2c) == 0)) {
                uVar34 = (undefined2)
                         (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
                uVar33 = param_1[0x23];
                puVar19 = (uint *)param_1[0x22];
              }
              else {
                iVar18 = *(int *)(param_1[4] * 2 + 0x302);
                uVar33 = *(uint *)(iVar18 + 0x2c);
                puVar19 = (uint *)*(uint *)(iVar18 + 0x2a);
              }
              uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10)
              ;
              param_1[0x2b] = uVar33;
              param_1[0x2a] = (uint)puVar19;
              return puVar19;
            case (uint *)0x7:
switchD_2000_8b75_caseD_7:
              puVar9 = _puStack_1e;
              puVar19 = puVar17;
              iVar18 = CONCAT11(local_c[1],local_c[0]);
              if ((param_1 != (uint *)0x0 || CONCAT11(param_2._1_1_,(byte)param_2) != 0) &&
                 (((((CONCAT11(param_2._1_1_,(byte)param_2) == param_4 && (param_1 == param_3)) ||
                    (((undefined1 *)CONCAT11(param_2._1_1_,(byte)param_2) == puStack_1e &&
                     (param_1 == uStack_22._2_2_)))) ||
                   (((uint *)CONCAT11(param_2._1_1_,(byte)param_2) == (uint *)uStack_22 &&
                    (param_1 == puStack_24)))) ||
                  ((iVar18 = CONCAT11(local_c[1],local_c[0]),
                   CONCAT11(param_2._1_1_,(byte)param_2) == uStack_26 &&
                   (iVar18 = CONCAT11(local_c[1],local_c[0]), param_1 == puStack_28)))))) {
                puVar19 = (uint *)((int)puVar17 + -0x23);
                iVar18 = CONCAT11(local_c[1],local_c[0]) + -0x23;
                auStack_e = (undefined1  [2])((int)auStack_e + 0x23);
                unaff_DI = (uint *)((int)unaff_DI + 0x23);
              }
              if (((((int)local_8 < (int)puVar19) || ((int)auStack_e <= (int)uStack_6._2_2_)) ||
                  ((int)local_a < iVar18)) || ((int)unaff_DI <= (int)(uint *)uStack_6)) {
                param_3 = (uint *)0x0;
              }
              else {
                if ((puStack_18 != (uint *)0x0) && (DAT_5b41_0939 != 9)) {
                  iVar14 = (int)puVar38 + ((uint)(byte)param_3[0x2d] - param_3[0x2e]);
                  iVar18 = (int)puVar17 + ((uint)*(byte *)((int)param_3 + 0x5b) - param_3[0x2e]);
                  iVar13 = param_3[0x2e] * 2 + iVar14;
                  iVar15 = param_3[0x2e] * 2 + iVar18;
                  if ((puStack_18[2] == CONCAT11(param_2._1_1_,(byte)param_2)) &&
                     ((uint *)puStack_18[1] == param_1)) {
                    iVar14 = iVar14 + -0x23;
                    iVar18 = iVar18 + -0x23;
                    iVar13 = iVar13 + 0x23;
                  }
                  if (((iVar14 <= (int)local_8) && ((int)uStack_6._2_2_ < iVar13)) &&
                     ((iVar18 <= (int)local_a && ((int)(uint *)uStack_6 < iVar15)))) {
                    if ((puStack_18[4] == param_4) && ((uint *)puStack_18[3] == param_3)) {
                      uVar33 = puStack_18[5];
                      puStack_18[4] = puStack_18[6];
                      puStack_18[3] = uVar33;
                      puStack_18[6] = param_4;
                      puStack_18[5] = (uint)param_3;
                    }
                    return (uint *)puStack_18[1];
                  }
                }
                puVar16 = puStack_1a;
                for (iVar18 = 0; iVar18 < 2; iVar18 = iVar18 + 1) {
                  if (((puVar16 != (uint *)0x0) && (DAT_5b41_0939 != 9)) && (param_3[4] != 7)) {
                    cVar21 = (char)param_3[iVar18 + 0x3d];
                    iVar13 = (int)puVar38 + cVar21 + -8;
                    cVar22 = *(char *)((int)param_3 + iVar18 * 2 + 0x7b);
                    local_c = (undefined1  [2])((int)puVar17 + cVar22 + -4);
                    auStack_e = (undefined1  [2])((int)puVar38 + cVar21 + 8);
                    if ((puVar16[1] == CONCAT11(param_2._1_1_,(byte)param_2)) &&
                       ((uint *)*puVar16 == param_1)) {
                      iVar13 = (int)puVar38 + cVar21 + -0x2b;
                      local_c = (undefined1  [2])((int)puVar17 + cVar22 + -0x27);
                      auStack_e = (undefined1  [2])((int)puVar38 + cVar21 + 0x2b);
                    }
                    if (((iVar13 <= (int)local_8) && ((int)uStack_6._2_2_ < (int)auStack_e)) &&
                       (((int)local_c <= (int)local_a &&
                        ((int)(uint *)uStack_6 < (int)puVar17 + cVar22 + 4)))) {
                      if ((puVar16[3] == param_4) && ((uint *)puVar16[2] == param_3)) {
                        FUN_28eb_08be();
                      }
                      return (uint *)*puVar16;
                    }
                  }
                  puVar16 = (uint *)((ulong)puVar9 >> 0x10);
                }
              }
              return param_3;
            case (uint *)0x8:
              if ((puVar24 == (undefined2 *)0x0) || ((char)puVar20 == '\0')) {
                if (DAT_554c_559f == '\x03') {
                  puVar19 = (uint *)0x0;
                }
                else {
                  puVar19 = (uint *)0x1;
                }
              }
              else {
                puVar19 = (uint *)0x3;
              }
              return puVar19;
            case (uint *)0x9:
              do {
              } while( true );
            }
switchD_2000_8b75_caseD_3:
            puVar38 = (uint *)puVar30;
            puStack_28 = (uint *)*puVar24;
            uStack_26 = in_DX;
            goto switchD_2000_8b75_caseD_7;
          }
          puStack_18 = (uint *)FUN_2424_1e00();
        }
        uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        if (param_1[0x5a] != 0) {
          piVar31 = (int *)(ulong)param_1[0x5a];
          FUN_4551_03eb();
          uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
          uVar3 = (int)local_a + (param_1[0x11] - DAT_5b41_0925);
          local_a._0_1_ = (undefined1)uVar3;
          local_a._1_1_ = (byte)(uVar3 >> 8);
          puVar19 = (uint *)(param_1[0x12] - DAT_5b41_0927);
          local_8 = (uint *)((int)local_8 + (int)puVar19);
          piVar29 = (int *)piVar31;
          piVar28 = piVar29 + -1;
          local_a = (uint *)uVar3;
          if (piVar28 < (int *)0xb) {
            puVar16 = (uint *)((int)piVar28 * 2);
            cVar21 = (char)((uint)puVar19 >> 8);
            switch(piVar28) {
            case (int *)0x0:
              do {
                LOCK();
                local_8 = (uint *)*(uint *)((int)puVar16 + -0x3e17);
                *(uint *)((int)puVar16 + -0x3e17) = (uint)puVar19;
                UNLOCK();
                pcVar2 = (char *)((int)(undefined2 *)&DAT_5b41_2839 + (int)puVar16 + (int)puVar17);
                *pcVar2 = *pcVar2 + (char)((uint)local_8 >> 8);
                puVar17 = DAT_5b41_2837;
                DAT_5b41_2839 = (uint *)((int)local_8 + ((int)DAT_5b41_2837 >> 4));
                uStack_6 = (uint *)((ulong)CONCAT22(DAT_5b41_2839,DAT_5b41_2837) & 0xffff000f);
                piVar28 = (int *)piVar31;
                local_a = (uint *)uVar3;
                if (DAT_554c_42df == '\0') {
                  local_c = (undefined1  [2])(*(int *)(*piVar28 + 6) * *(int *)(*piVar28 + 8));
                  DAT_5b41_2837 = (uint *)((uint)DAT_5b41_2837 & 0xf);
                  uVar36 = FUN_2fc8_00fc();
                  bVar23 = local_c[1];
                  auStack_e[0] = (undefined1)((ulong)uVar36 >> 0x10);
                  auStack_e[1] = (byte)((ulong)uVar36 >> 0x18);
                  local_c[0] = (byte)((uint)local_c >> 1);
                  local_c[1] = local_c[1] >> 1;
                  local_c[0] = (byte)(CONCAT11(local_c[1],local_c[0]) >> 1);
                  local_c[1] = bVar23 >> 2;
                  local_c[0] = (byte)(CONCAT11(local_c[1],local_c[0]) >> 1);
                  local_c[1] = bVar23 >> 3;
                  FUN_1a9e_74bc();
                  puVar24 = (undefined2 *)*piVar28;
                  *puVar24 = CONCAT11(auStack_e[1],auStack_e[0]);
                  puVar24[1] = (int)uVar36;
                  FUN_1a9e_7911();
                  func_0x0002fdf5();
                  uVar3 = (uint)local_a;
                }
                else {
                  DAT_5b41_2837 = (uint *)((uint)DAT_5b41_2837 & 0xf);
                  FUN_1a9e_7911();
                  uVar3 = (uint)local_a;
                }
                puVar16 = (uint *)*piVar28;
                *puVar16 = (uint)uStack_6._2_2_;
                puVar16[1] = (uint)(uint *)uStack_6;
                puVar16[2] = 0xfffe;
                puVar39 = DAT_5b41_2837;
                iVar18 = DAT_5b41_2833;
                piVar31 = (int *)ZEXT24(piVar28 + 1);
                puVar19 = DAT_5b41_2839;
              } while (piVar28[1] != 0);
              local_8 = (uint *)((int)DAT_5b41_2839 - DAT_5b41_2835);
              DAT_5b41_282f = (int)local_8 + ((int)DAT_5b41_2837 + (0xf - DAT_5b41_2833) >> 4);
              local_a._0_1_ = (undefined1)*(undefined2 *)*param_1;
              local_a._1_1_ = (byte)((uint)*(undefined2 *)*param_1 >> 8);
              pcVar7 = (code *)swi(0x21);
              (*pcVar7)();
              FUN_1000_130c();
              return (uint *)((int)puVar39 + ((int)local_8 * 0x10 - iVar18));
            case (int *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (int *)0x2:
              *(char *)(int *)((int)puVar16 + (int)piVar29) =
                   (char)*(int *)((int)puVar16 + (int)piVar29) + '\x01';
              if (puVar19 != (uint *)0xf6) {
                puVar16 = puVar16 + -1;
              }
              if ((*puVar16 & 1) == 0) {
                puVar19 = (uint *)((int)uVar33 >> 1);
              }
              else {
                puVar19 = (uint *)(uVar33 >> 1 | (uint)((in_DX & 1) != 0) << 0xf);
              }
              return puVar19;
            case (int *)0x3:
              goto switchD_2000_8bda_caseD_3;
            case (int *)0x4:
              do {
                piVar28 = (int *)piVar31;
                FUN_3e34_0ec9();
                uVar33 = (int)piVar28 + ((uint *)uStack_6)[3];
                piVar31 = (int *)(ulong)uVar33;
              } while ((int)uVar33 < CONCAT11(auStack_e[1],auStack_e[0]));
              puVar19 = (uint *)FUN_2424_02ca();
              return puVar19;
            case (int *)0x5:
              (&stack0x0e44)[(int)puVar17] =
                   (&stack0x0e44)[(int)puVar17] + (char)in_CX + CARRY2((uint)piVar28,(uint)piVar28);
              local_a = (uint *)(param_7 + (int)param_3 + (int)puVar19 * -2);
              local_8 = (uint *)(((param_8 + param_4 + (uint)CARRY2(param_7,(uint)param_3)) -
                                 (in_DX << 1 | (uint)CARRY2((uint)puVar19,(uint)puVar19))) -
                                (uint)(param_7 + (int)param_3 < (uint)((int)puVar19 * 2)));
              auStack_e = (undefined1  [2])(param_13 + param_9 + param_11 * -2);
              local_c = (undefined1  [2])
                        (((param_14 + param_10 + (uint)CARRY2(param_13,param_9)) -
                         (param_12 << 1 | (uint)CARRY2(param_11,param_11))) -
                        (uint)(param_13 + param_9 < param_11 * 2));
              FUN_1000_199e();
              FUN_1000_199e();
              FUN_1000_199e();
              FUN_1000_199e();
              puVar19 = (uint *)(1 << ((byte)param_2 & 0x1f));
              iVar18 = (int)puVar19 >> 0xf;
              uStack_6._2_2_ = (uint *)FUN_1000_19bf();
              uStack_6._0_2_ = (uint *)FUN_1000_19bf();
              uStack_22._2_2_ = (uint *)0x0;
              for (uStack_22._0_2_ = (uint *)0x0;
                  ((int)uStack_22._2_2_ < iVar18 ||
                  (((int)uStack_22._2_2_ <= iVar18 && ((uint *)uStack_22 <= puVar19))));
                  uStack_22._0_2_ = (uint *)((int)(uint *)uStack_22 + 1)) {
                iVar13 = FUN_1000_19bf();
                iVar14 = FUN_1000_19bf();
                if ((uStack_6._2_2_ != (uint *)iVar13) || ((uint *)uStack_6 != (uint *)iVar14)) {
                  uStack_22._2_2_ = (uint *)0x692b;
                  FUN_2424_27e0();
                  uStack_6._0_2_ = (uint *)iVar14;
                  uStack_6._2_2_ = (uint *)iVar13;
                }
                FUN_1000_180a();
                FUN_1000_180a();
                uStack_22._2_2_ =
                     (uint *)((int)uStack_22._2_2_ + (uint)((uint *)0xfffe < (uint *)uStack_22));
              }
              return (uint *)uStack_22;
            default:
              puVar17 = (uint *)CONCAT11(cVar21,*(char *)&DAT_554c_5596);
              if (*(char *)&DAT_554c_5596 == '\0') {
                *(undefined1 *)&DAT_554c_5595 = (char)puVar16;
                *(int *)&DAT_554c_5178 = in_CX;
                *(uint *)&DAT_554c_517a = in_DX;
                puVar17 = (uint *)CONCAT11(cVar21,*(char *)&DAT_554c_5596);
                if ((*(char *)&DAT_554c_5596 == '\0') &&
                   (puVar17 = (uint *)0x0,
                   *(int *)&DAT_554c_517c != 0 || *(int *)&DAT_554c_517e != 0)) {
                  *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + '\x01';
                  *(undefined2 *)&DAT_554c_557e = 0x2000;
                  *(undefined2 *)&DAT_554c_557c = 0x2fe;
                  FUN_1a9e_5938();
                  uVar34 = ((undefined2 *)&DAT_554c_517c)[1];
                  pcVar5 = (code *)*(undefined2 *)&DAT_554c_517c;
                  *(undefined2 *)&DAT_554c_557e = 0x2000;
                  puVar26 = (undefined2 *)&DAT_554c_557c;
                  *(undefined2 *)&DAT_554c_557c = 0x303;
                  (*pcVar5)();
                  *(undefined2 *)((int)puVar26 + -2) = 0x2000;
                  *(undefined2 *)((int)puVar26 + -4) = 0x307;
                  puVar17 = (uint *)FUN_1a9e_599d();
                  *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + -1;
                }
              }
              return puVar17;
            case (int *)0x7:
              return puVar19;
            case (int *)0x8:
              iVar27 = *(int *)(&stack0x6bf6 + (int)puVar17) * -0x15;
              if ((CONCAT11(param_2._1_1_,(byte)param_2) == DAT_5b41_0ca2) &&
                 (param_1 == DAT_5b41_0ca0)) {
                DAT_5b41_0cb9 = 0;
              }
              else if ((CONCAT11(param_2._1_1_,(byte)param_2) == DAT_5b41_0c9e) &&
                      (param_1 == DAT_5b41_0c9c)) {
                DAT_5b41_0cbb = 0;
              }
              else {
                *(undefined2 *)(iVar27 + -2) = CONCAT11(param_2._1_1_,(byte)param_2);
                *(undefined2 *)(iVar27 + -4) = param_1;
                *(undefined2 *)(iVar27 + -6) = 0x2000;
                *(undefined2 *)(iVar27 + -8) = 0xf845;
                param_1 = (uint *)FUN_22de_0351();
              }
              return param_1;
            case (int *)0x9:
              *(char *)(int *)((int)puVar16 + (int)piVar29) =
                   (char)*(int *)((int)puVar16 + (int)piVar29) + cVar21;
              FUN_2424_4ae2();
              puVar19 = param_1;
              uVar33 = (uint)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
              while( true ) {
                uVar3 = puVar19[0x47];
                puVar19 = (uint *)puVar19[0x46];
                uStack_6 = (uint *)CONCAT22(uVar3,puVar19);
                if ((puVar19 == (uint *)0x0 && uVar3 == 0) || (local_8 != (uint *)0x0)) break;
                uVar33 = uVar3;
                if (((puVar19[4] == 0x76) && (puVar19[0x25] == 0x20)) &&
                   (puVar19[0x12] == param_1[0x12] - 0x20)) {
                  bVar35 = (puVar19[6] & 0x30) != 0;
                  if (((CONCAT11(local_c[1],local_c[0]) != 0) || (bVar35)) ||
                     (puVar19[0x11] != param_1[0x11])) {
                    if (((CONCAT11(local_c[1],local_c[0]) != 0) && (!bVar35)) &&
                       (uVar34 = (undefined2)
                                 (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10),
                       puVar19[0x11] + puVar19[0x24] == param_1[0x11] + param_1[0x24])) {
                      local_8 = (uint *)0x9;
                    }
                  }
                  else {
                    local_8 = (uint *)0x7;
                  }
                }
              }
              uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10)
              ;
              local_a = (uint *)(param_1[0x25] + 0x10);
              local_c[0] = (byte)param_1[0x25];
              local_c[1] = (byte)(param_1[0x25] >> 8);
              auStack_e[0] = 0x10;
              auStack_e[1] = 0;
              FUN_2424_4ae2();
              puVar19 = param_1;
              uVar33 = (uint)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
              while( true ) {
                uVar3 = puVar19[0x47];
                puVar19 = (uint *)puVar19[0x46];
                uStack_6 = (uint *)CONCAT22(uVar3,puVar19);
                if ((puVar19 == (uint *)0x0 && uVar3 == 0) || (local_a != (uint *)0x0)) break;
                uVar33 = uVar3;
                if (((puVar19[4] == 0x76) && (puVar19[0x25] == 0x20)) &&
                   (uVar34 = (undefined2)
                             (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10),
                   param_1[0x12] + param_1[0x25] == puVar19[0x12])) {
                  bVar35 = (puVar19[6] & 0x30) == 0;
                  if (((CONCAT11(local_c[1],local_c[0]) != 0) || (bVar35)) ||
                     (puVar19[0x11] != param_1[0x11])) {
                    if (((CONCAT11(local_c[1],local_c[0]) != 0) && (!bVar35)) &&
                       (uVar34 = (undefined2)
                                 (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10),
                       puVar19[0x11] + puVar19[0x24] == param_1[0x11] + param_1[0x24])) {
                      local_a = (uint *)0xc;
                    }
                  }
                  else {
                    local_a = (uint *)0xa;
                  }
                }
              }
              uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10)
              ;
              if (((uint *)param_1[0x57] != local_8) || ((uint *)param_1[0x5a] != local_a)) {
                local_a._0_1_ = 1;
                local_a._1_1_ = 0;
                local_c[0] = (byte)param_2;
                auStack_e[0] = SUB21(param_1,0);
                auStack_e[1] = (byte)((uint)param_1 >> 8);
                FUN_2424_3746();
                FUN_2424_3746();
                uVar34 = (undefined2)
                         (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
                param_1[0x57] = (uint)local_8;
                param_1[0x5a] = CONCAT11(local_a._1_1_,(undefined1)local_a);
                FUN_2424_3746();
                FUN_2424_3746();
              }
              uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10)
              ;
              param_1[0x57] = (uint)local_8;
              param_1[0x5a] = (uint)local_a;
              if ((local_8 == (uint *)0x0) && (local_a == (uint *)0x0)) {
                puVar19 = (uint *)0x0;
              }
              else {
                puVar19 = (uint *)0x1;
              }
              return puVar19;
            }
          }
          puStack_18 = (uint *)FUN_2424_1e00();
        }
        return puStack_18;
      case (uint *)0x3:
        uVar33 = puVar39[0x18];
        pbVar1 = pbVar8;
        *pbVar1 = *pbVar1 >> 1;
        pcVar2 = (char *)(uVar33 * -0x7d + 9);
        *pcVar2 = *pcVar2 + (char)(in_DX >> 8);
        if (((DAT_5b41_0c9c == (uint *)0x0 && DAT_5b41_0c9e == 0) ||
            (DAT_5b41_0cac == 0 && DAT_5b41_0cae == 0)) ||
           ((DAT_554c_2fca != 0 && (DAT_5b41_0ca4 == 0 && DAT_5b41_0ca6 == 0)))) {
          FUN_2e67_0e27();
        }
        else {
          DAT_5b41_0cb8 = 1;
        }
        return (uint *)(uint)DAT_5b41_0cb8;
      case (uint *)0x4:
        do {
          iVar13 = FUN_28eb_3b36();
          puStack_18 = (uint *)iVar18;
          do {
            uVar34 = (undefined2)(uStack_22 >> 0x10);
            iVar18 = (int)uStack_22;
            local_8 = (uint *)(*(int *)(iVar18 + 0x2e) + (int)*(char *)(iVar18 + -0x5350));
            local_a = (uint *)(*(int *)(iVar18 + 0x30) + (int)*(char *)(iVar18 + -0x534f));
            if ((int)uStack_6._2_2_ < (int)local_8) {
              iVar18 = (int)uStack_6._2_2_ - DAT_5b41_0925;
              puVar19 = local_8;
            }
            else {
              iVar18 = (int)local_8 - DAT_5b41_0925;
              puVar19 = uStack_6._2_2_;
            }
            if ((int)(uint *)uStack_6 < (int)local_a) {
              iVar14 = (int)(uint *)uStack_6 - DAT_5b41_0927;
              puVar16 = local_a;
            }
            else {
              iVar14 = (int)local_a - DAT_5b41_0927;
              puVar16 = (uint *)uStack_6;
            }
            iVar15 = (int)puVar16 - DAT_5b41_0927;
            if (0 < iVar13) {
              iVar15 = iVar15 + (iVar13 >> 1);
            }
            uVar33 = (uint)((int)puVar19 + (-iVar18 - DAT_5b41_0925) < iVar15 - iVar14);
            local_c = (undefined1  [2])(iVar18 - uVar33);
            auStack_e = (undefined1  [2])(iVar14 - (uint)(uVar33 == 0));
            for (puVar24 = DAT_5b41_04ac; puVar24 != (undefined2 *)0x0;
                puVar24 = (undefined2 *)*puVar24) {
              if ((((puVar24[6] == 1) &&
                   ((int)puVar24[1] <= (int)((int)puVar19 + (uVar33 - DAT_5b41_0925)))) &&
                  ((int)local_c <= (int)puVar24[3])) &&
                 (((int)puVar24[2] <= (int)(iVar15 + (uint)(uVar33 == 0)) &&
                  ((int)auStack_e <= (int)puVar24[4])))) {
                iVar13 = 0x28eb;
                puStack_18 = (uint *)0x571b;
                FUN_28eb_2d82();
                uStack_22 = CONCAT22(puStack_28,iStack_2a);
                break;
              }
            }
            iVar18 = 0x28eb;
            if ((uStack_22._2_2_ == puStack_28) && ((uint *)uStack_22 == (uint *)iStack_2a)) {
              uStack_22 = 0;
              _puStack_1e = (undefined1 *)0x0;
            }
            else {
              _puStack_1e = (undefined1 *)uStack_22;
              uStack_22 = CONCAT22(*(undefined2 *)((int)(uint *)uStack_22 + 0x60),
                                   *(undefined2 *)((int)(uint *)uStack_22 + 0x5e));
            }
            puVar16 = (uint *)((ulong)_puStack_1e >> 0x10);
            if (puStack_1e == (undefined1 *)0x0 && puVar16 == (uint *)0x0) {
              return (uint *)0x0;
            }
            if ((uint *)uStack_22 == (uint *)0x0 && uStack_22._2_2_ == (uint *)0x0) {
              return (uint *)0x0;
            }
            if ((puVar16 != puStack_24) || (puStack_1e != (undefined1 *)uStack_26)) {
              puStack_18 = (uint *)0x1;
              iVar13 = 0;
            }
            uStack_6 = (uint *)CONCAT22(*(int *)((int)puStack_1e + 0x2e) +
                                        (int)*(char *)((int)puStack_1e + (int)puStack_18 * 2 + 0x7a)
                                        ,(uint *)(*(int *)((int)puStack_1e + 0x30) +
                                                 (int)*(char *)((int)puStack_1e +
                                                                (int)puStack_18 * 2 + 0x7b)));
          } while ((uStack_22._2_2_ != puStack_28) || ((uint *)uStack_22 != (uint *)iStack_2a));
        } while( true );
      case (uint *)0x5:
        FUN_54a4_0043();
        FUN_2424_050d();
        local_c[0] = 0x24;
        local_c[1] = 0x24;
        auStack_e[0] = 0x1a;
        auStack_e[1] = 0x3c;
        FUN_2424_03c5();
        DAT_5b41_0945 = 0;
        DAT_5b41_0943 = 0;
        DAT_5b41_093d = 0;
        DAT_5b41_093b = 0;
        DAT_5b41_0941 = 0;
        DAT_5b41_093f = 0;
        DAT_5b41_0953 = 1;
        local_c[0] = 0;
        local_c[1] = 0;
        auStack_e[0] = 0xfc;
        auStack_e[1] = 0xff;
        puVar19 = (uint *)FUN_406b_03cb();
        if (puVar19 == (uint *)0x0) {
          if (DAT_5b41_094f == 0) {
            auStack_e[0] = 0x22;
          }
          else {
            auStack_e[0] = 0x23;
          }
          local_c[0] = 0xdc;
          local_c[1] = 0xff;
          auStack_e[1] = 0;
          puVar19 = (uint *)FUN_406b_03cb();
        }
        return puVar19;
      case (uint *)0x6:
        cRam00059b4d = cRam00059b4d + (char)in_DX;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (uint *)0x7:
        goto switchD_2000_8a43_caseD_7;
      case (uint *)0x9:
        goto switchD_2000_8a43_caseD_9;
      }
      goto switchD_2000_8a43_caseD_8;
    }
    iVar18 = FUN_2424_4007();
    uVar34 = (undefined2)((ulong)puVar30 >> 0x10);
    if (iVar18 == 0) goto LAB_2424_4827;
LAB_2424_489b:
    puVar19 = (uint *)0x1;
  }
  return puVar19;
switchD_2000_8bda_caseD_3:
  uVar33 = 0xb;
  while( true ) {
    while( true ) {
      do {
        do {
          piVar28 = (int *)piVar31;
          uVar34 = (undefined2)((ulong)uStack_6 >> 0x10);
          uVar3 = ((uint *)uStack_6)[0x47];
          puVar19 = (uint *)((uint *)uStack_6)[0x46];
          uStack_6 = (uint *)CONCAT22(uVar3,puVar19);
          if ((puVar19 == (uint *)0x0 && uVar3 == 0) || (uVar33 != 0)) {
            uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
            if (((int *)param_1[0x57] != piVar28) || (param_1[0x5a] != uVar33)) {
              FUN_2424_3746();
              FUN_2424_3746();
              uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10)
              ;
              param_1[0x57] = (uint)piVar28;
              param_1[0x5a] = uVar33;
              FUN_2424_3746();
              FUN_2424_3746();
            }
            uVar34 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
            param_1[0x57] = (uint)piVar28;
            param_1[0x5a] = uVar33;
            if ((piVar28 == (int *)0x0) && (uVar33 == 0)) {
              puVar19 = (uint *)0x0;
            }
            else {
              puVar19 = (uint *)0x1;
            }
            return puVar19;
          }
        } while (puVar19[0x25] != 0x10);
        iVar18 = FUN_2424_4087();
      } while (iVar18 == 0);
      uVar34 = (undefined2)((ulong)uStack_6 >> 0x10);
      puVar19 = (uint *)uStack_6;
      if (puVar19[0x11] != param_1[0x11]) break;
      uVar33 = 10;
    }
    uVar32 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
    if (puVar19[0x11] + puVar19[0x24] != param_1[0x11] + param_1[0x24]) break;
    uVar33 = 0xc;
  }
  goto switchD_2000_8bda_caseD_3;
switchD_2000_8976_caseD_7:
  while ((puVar19 = (uint *)puVar30, puVar17 != (uint *)0x0 || puVar24[-0x3d6c] != 0 &&
         ((int)puVar19 < 0x14))) {
    puVar24 = (undefined2 *)(((int)puVar19 + 1U) * 4);
    puVar17 = (uint *)puVar24[-0x3d6d];
    puVar30 = (uint *)(ulong)((int)puVar19 + 1U);
  }
  if ((int)puVar19 < 0x14) {
    iVar18 = FUN_1a9e_6ea7();
    if (iVar18 == 0) {
      uStack_6 = (uint *)CONCAT22(1,(uint *)uStack_6);
      FUN_1a9e_69e9();
    }
    else {
      uStack_6 = (uint *)((ulong)uStack_6 & 0xffff);
    }
    iVar18 = FUN_1a9e_6a85();
    if ((in_DX == 0xffff) && (iVar18 == -1)) {
      puVar19 = (uint *)0x0;
    }
    else {
      FUN_1000_0d10();
      if (((char)puVar19[0x217a] == -3) || ((char)puVar19[0x217a] == -1)) {
        *(char *)(puVar19 + -0x3d77) = -(char)puVar19[0x217a];
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1a9e_6e3d();
        local_8 = (uint *)FUN_28eb_2779();
        local_a._0_1_ = (int)local_8 < 0;
        local_a._1_1_ = 0;
        if (!(bool)(undefined1)local_a) {
          puVar16 = (uint *)FUN_28eb_2ba9();
          local_a._0_1_ = puVar16 != (uint *)uStack_6;
        }
        local_a._1_1_ = 0;
        iVar18 = (int)auStack_e;
        if ((bool)(undefined1)local_a == false) {
          lVar37 = FUN_2fc8_00fc();
          iVar18 = (int)lVar37;
          local_c[0] = (byte)((ulong)lVar37 >> 0x10);
          local_c[1] = (byte)((ulong)lVar37 >> 0x18);
          local_a._0_1_ = lVar37 == 0;
        }
        local_a._1_1_ = 0;
        auStack_e = (undefined1  [2])iVar18;
        if ((bool)(undefined1)local_a == false) {
          puVar16 = (uint *)FUN_28eb_2aad();
          local_a._0_1_ = puVar16 != (uint *)uStack_6;
        }
        local_a._1_1_ = 0;
        if ((bool)(undefined1)local_a == false) {
          ((undefined2 *)&DAT_5b41_2678)[(int)puVar19 * 2] = CONCAT11(local_c[1],local_c[0]);
          ((undefined2 *)&DAT_5b41_2676)[(int)puVar19 * 2] = auStack_e;
          iVar18 = (int)auStack_e + (uint)(byte)puVar19[0x2198] * 2;
          *(uint *)((undefined *)&DAT_5b41_2628 + (int)puVar19 * 4) =
               CONCAT11(local_c[1],local_c[0]);
          ((undefined2 *)&DAT_5b41_2626)[(int)puVar19 * 2] = iVar18;
          auStack_e = (undefined1  [2])(iVar18 + (uint)(byte)puVar19[0x2198]);
          ((undefined2 *)&DAT_5b41_25d8)[(int)puVar19 * 2] = CONCAT11(local_c[1],local_c[0]);
          ((undefined2 *)&DAT_5b41_25d6)[(int)puVar19 * 2] = auStack_e;
        }
        FUN_28eb_29db();
        if (CONCAT11(local_a._1_1_,(undefined1)local_a) == 0) {
          local_a = (uint *)0x0;
        }
        else {
          if (auStack_e != (undefined1  [2])0x0 || CONCAT11(local_c[1],local_c[0]) != 0) {
            func_0x0002fdf5();
          }
          puVar19 = (uint *)0x0;
        }
      }
      else {
        if ((char)puVar19[0x217a] == -2) {
          *(undefined1 *)(puVar19 + -0x3d77) = 2;
          FUN_1000_0d10();
          uStack_6._0_2_ = (uint *)(uint)(byte)puVar19[0x217a];
        }
        else {
          *(undefined1 *)(puVar19 + -0x3d77) = 0;
          uStack_6._0_2_ = (uint *)((int)((byte)puVar19[0x217a] + 7) >> 3);
        }
        FUN_1000_0d10();
        FUN_1000_0d10();
        FUN_1000_0d10();
        uStack_6 = (uint *)CONCAT22(uStack_6._2_2_,
                                    (uint *)((int)(uint *)uStack_6 *
                                            (uint)(byte)puVar19[0x2184] *
                                            (uint)(byte)puVar19[0x2198]));
        iVar18 = FUN_1000_127a();
        local_a._0_1_ = iVar18 == 0;
        local_a._1_1_ = 0;
        if (!(bool)(undefined1)local_a) {
          FUN_1000_0d10();
        }
        if (local_a == (uint *)0x0) {
          ((undefined2 *)&DAT_5b41_25d8)[(int)puVar19 * 2] = 0x554c;
          ((undefined2 *)&DAT_5b41_25d6)[(int)puVar19 * 2] = iVar18;
          ((undefined2 *)&DAT_5b41_2678)[(int)puVar19 * 2] = 0;
          ((undefined2 *)&DAT_5b41_2676)[(int)puVar19 * 2] = 0;
          *(undefined2 *)((undefined *)&DAT_5b41_2628 + (int)puVar19 * 4) = 0;
          ((undefined2 *)&DAT_5b41_2626)[(int)puVar19 * 2] = 0;
        }
        if (CONCAT11(local_a._1_1_,(undefined1)local_a) != 0) {
          if (iVar18 != 0) {
            FUN_1000_130c();
          }
          puVar19 = (uint *)0x0;
        }
      }
    }
    if (uStack_6._2_2_ != (uint *)0x0) {
      FUN_1a9e_6e73();
    }
  }
  else {
    puVar19 = (uint *)0x0;
  }
  return puVar19;
LAB_2424_4a1f:
  do {
    puVar17 = (uint *)puVar30;
    puVar19 = (uint *)puVar17[1];
    uVar33 = puVar17[2];
    puVar16 = (uint *)puVar17[3];
    uStack_6 = (uint *)CONCAT22(uVar33,puVar16);
    local_8 = (uint *)puVar17[4];
    if ((((int)puVar19 <= (int)unaff_DI) &&
        ((int)unaff_DI + CONCAT11(local_c[1],local_c[0]) <= (int)puVar16)) &&
       (((int)uVar33 <= (int)auStack_e && ((int)auStack_e + (int)local_a <= (int)local_8)))) {
      FUN_2424_02ca();
      puVar19 = (uint *)FUN_4551_01dc();
      return puVar19;
    }
    if (((((int)unaff_DI <= (int)puVar16) &&
         ((int)puVar19 <= (int)unaff_DI + CONCAT11(local_c[1],local_c[0]))) &&
        ((int)auStack_e <= (int)local_8)) &&
       ((((int)uVar33 <= (int)auStack_e + (int)local_a && ((int)puVar19 < (int)puVar16)) &&
        ((int)uVar33 <= (int)local_8)))) {
      DAT_554c_42c3 = 1;
      DAT_554c_42c4 = puVar19;
      DAT_554c_42c6 = puVar16;
      DAT_554c_42c8 = uVar33;
      DAT_554c_42ca = local_8;
      FUN_4551_01dc();
    }
    puVar30 = (uint *)(ulong)*puVar17;
  } while (*puVar17 != 0);
  puVar19 = (uint *)FUN_2424_02ca();
  return puVar19;
}

