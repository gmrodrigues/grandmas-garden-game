// TIM2.EXE: FUN_28eb_33c7 @ file 0x031477 Ghidra 0x2C277
// Subsystem: misc | Size: 700 bytes


/* WARNING: Instruction at (ram,0x0002ff71) overlaps instruction at (ram,0x0002ff6d)
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __cdecl16far FUN_28eb_33c7(void)

{
  uint *puVar1;
  int *piVar2;
  char *pcVar3;
  undefined1 uVar4;
  byte bVar5;
  code *pcVar6;
  char cVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  undefined2 *puVar16;
  int in_CX;
  uint in_DX;
  int iVar17;
  int *piVar18;
  undefined2 *puVar20;
  undefined2 *puVar21;
  undefined2 *puVar22;
  undefined2 *puVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  undefined2 *puVar26;
  undefined2 *puVar27;
  undefined2 *puVar28;
  undefined2 *puVar29;
  undefined2 *puVar30;
  undefined2 *puVar31;
  undefined2 *puVar32;
  undefined2 *puVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  undefined2 *puVar36;
  undefined2 *puVar37;
  undefined2 *puVar38;
  undefined1 *puVar39;
  undefined1 *puVar40;
  undefined2 *puVar41;
  undefined2 *puVar42;
  undefined1 *puVar43;
  undefined1 *puVar44;
  undefined2 *puVar46;
  undefined2 *puVar47;
  undefined2 *puVar48;
  undefined2 *puVar49;
  undefined2 *puVar50;
  undefined2 *puVar51;
  undefined1 *puVar52;
  undefined2 *puVar53;
  undefined2 *puVar54;
  undefined2 *puVar55;
  undefined1 *puVar56;
  undefined1 *puVar57;
  undefined1 *puVar58;
  undefined2 *puVar59;
  undefined2 *puVar60;
  undefined2 *puVar61;
  undefined2 *puVar62;
  undefined2 *puVar63;
  undefined2 *puVar64;
  undefined2 *puVar65;
  undefined1 *puVar66;
  undefined1 *puVar67;
  undefined2 *puVar68;
  undefined1 *puVar69;
  undefined2 *puVar70;
  undefined1 *puVar71;
  undefined1 *puVar72;
  undefined1 *puVar73;
  int *piVar75;
  int *piVar76;
  int *piVar77;
  int *piVar78;
  int *piVar79;
  int *piVar80;
  int *piVar81;
  int *piVar82;
  undefined2 *puVar83;
  undefined2 *puVar84;
  undefined2 *puVar85;
  undefined2 *puVar86;
  undefined2 *puVar87;
  undefined2 *puVar88;
  undefined2 *puVar89;
  undefined1 *puVar90;
  undefined1 *puVar91;
  undefined1 *puVar92;
  undefined1 *puVar93;
  undefined2 *puVar94;
  int iVar95;
  undefined1 *puVar96;
  undefined1 *puVar97;
  undefined2 *puVar98;
  int *piVar99;
  int *piVar100;
  undefined2 *puVar101;
  int *piVar102;
  int *piVar103;
  undefined2 *puVar104;
  undefined2 *puVar105;
  undefined2 *puVar106;
  undefined2 *puVar107;
  int *piVar108;
  undefined4 in_ESP;
  undefined2 unaff_BP;
  int *unaff_SI;
  char *pcVar109;
  int *unaff_DI;
  undefined2 uVar110;
  undefined2 uVar111;
  undefined2 uVar112;
  undefined2 unaff_SS;
  byte in_AF;
  bool bVar113;
  undefined4 uVar114;
  long lVar115;
  int *piVar19;
  undefined1 *puVar45;
  undefined1 *puVar74;
  
  iVar95 = (int)in_ESP;
  puVar16 = (undefined2 *)(iVar95 + -2);
  *(undefined2 *)(iVar95 + -2) = unaff_BP;
  puVar96 = (undefined1 *)(iVar95 + -10);
  puVar48 = (undefined2 *)(iVar95 + -0xc);
  puVar34 = (undefined1 *)(iVar95 + -0xc);
  puVar90 = (undefined1 *)(iVar95 + -0xc);
  *(undefined2 *)(iVar95 + -0xc) = unaff_SI;
  uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
  piVar14 = (int *)*(int *)((int)*(undefined4 *)(iVar95 + 4) + 8);
  if (piVar14 == (int *)0x55) {
LAB_28eb_34f4:
    uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
    iVar17 = (int)*(undefined4 *)(iVar95 + 4);
    *(undefined2 *)(iVar17 + 0x48) = *(undefined2 *)(iVar17 + 0x54);
    *(undefined2 *)(iVar17 + 0x4a) = *(undefined2 *)(iVar17 + 0x56);
LAB_28eb_3507:
    uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
    iVar17 = (int)*(undefined4 *)(iVar95 + 4);
    piVar14 = (int *)*(undefined2 *)(iVar17 + 0x48);
    *(undefined2 *)(iVar17 + 0x46) = *(undefined2 *)(iVar17 + 0x4a);
    *(undefined2 *)(iVar17 + 0x44) = piVar14;
    return piVar14;
  }
  if ((int)piVar14 < 0x56) {
    if (piVar14 != (int *)0x38) {
      if ((int)piVar14 < 0x39) {
        if (piVar14 == (int *)0x7) goto LAB_28eb_351d;
        if ((int)piVar14 < 8) {
          piVar14 = (int *)((int)piVar14 - 1);
          if (piVar14 < (int *)0x5) {
            iVar17 = (int)piVar14 * 2;
            uVar112 = 0x2000;
            puVar96 = (undefined1 *)(iVar95 + -0xc);
            switch(piVar14) {
            case (int *)0x0:
              if (*(int *)(iVar17 + 8) == 7) {
                piVar14 = (int *)(*(int *)(iVar17 + 0x76) + 0x26);
              }
              else {
                piVar14 = unaff_DI + 0x15;
              }
              *(undefined2 *)(iVar95 + -0x10) = piVar14;
              *(undefined2 *)(iVar95 + -0xe) = 2;
              *(undefined2 *)(iVar95 + -0x10) = unaff_DI;
              *(undefined2 *)(iVar95 + -0x12) = *(undefined2 *)(iVar95 + -0x12);
              *(undefined2 *)(iVar95 + -0x14) = *(undefined2 *)(iVar95 + -0x14);
              *(undefined2 *)(iVar95 + -0x16) = 0x2000;
              puVar65 = (undefined2 *)(iVar95 + -0x18);
              *(undefined2 *)(iVar95 + -0x18) = 0x4d5c;
              uVar110 = FUN_28eb_3b36();
              *(undefined2 *)(iVar95 + -4) = uVar110;
              puVar65[5] = uVar110;
              puVar65[4] = 2;
              puVar65[3] = *(undefined2 *)(iVar95 + -0x10);
              puVar65[2] = unaff_DI + 0x13;
              puVar65[1] = 0x28eb;
              *puVar65 = 0x4d71;
              FUN_2424_1b66();
              puVar66 = (undefined1 *)((int)puVar65 + 0xc);
              for (iVar17 = 0; iVar17 < 2; iVar17 = iVar17 + 1) {
                *(int *)(iVar95 + -8) = unaff_DI[iVar17 * 2 + 0x17] + -8;
                *(int *)(iVar95 + -6) = unaff_DI[iVar17 * 2 + 0x18] + -8;
                *(undefined2 *)(puVar66 + -2) = 2;
                *(int *)(puVar66 + -4) = iVar95 + -0xc;
                *(int *)(puVar66 + -6) = iVar95 + -8;
                *(undefined2 *)(puVar66 + -8) = 0x28eb;
                puVar67 = puVar66 + -10;
                *(undefined2 *)(puVar66 + -10) = 0x4da3;
                FUN_2424_1da0();
                puVar66 = puVar67 + 10;
              }
              piVar14 = (int *)unaff_DI[4];
              if ((unaff_DI[5] != *(int *)(iVar95 + -0x16)) ||
                 (piVar14 != (int *)*(int *)(iVar95 + -0x18))) {
                iVar17 = unaff_DI[4];
                *(int *)(iVar95 + -0x16) = unaff_DI[5];
                *(int *)(iVar95 + -0x18) = iVar17;
                uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + -0x18) >> 0x10);
                iVar17 = (int)*(undefined4 *)(iVar95 + -0x18) +
                         (uint)*(byte *)((int)unaff_DI + 0x15) * 4;
                piVar14 = (int *)*(int *)(iVar17 + 0x5e);
                *(undefined2 *)(iVar95 + -0x12) = *(undefined2 *)(iVar17 + 0x60);
                *(int *)(iVar95 + -0x14) = (int)piVar14;
                if ((*(byte *)(iVar95 + 8) & 1) != 0) {
                  uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + -0x14) >> 0x10);
                  iVar17 = (int)*(undefined4 *)(iVar95 + -0x14);
                  if (*(int *)(iVar17 + 8) == 7) {
                    piVar14 = (int *)(*(int *)(iVar17 + 0x76) + 0x32);
                  }
                  else {
                    piVar14 = unaff_DI + 0x17;
                  }
                  *(undefined2 *)(iVar95 + -0xe) = piVar14;
                  *(undefined2 *)(puVar66 + -2) = 1;
                  *(int **)(puVar66 + -4) = unaff_DI;
                  *(undefined2 *)(puVar66 + -6) = *(undefined2 *)(iVar95 + -0x12);
                  *(undefined2 *)(puVar66 + -8) = *(undefined2 *)(iVar95 + -0x14);
                  *(undefined2 *)(puVar66 + -10) = 0x28eb;
                  puVar68 = (undefined2 *)(puVar66 + -0xc);
                  *(undefined2 *)(puVar66 + -0xc) = 0x4e15;
                  uVar110 = FUN_28eb_3b36();
                  *(undefined2 *)(iVar95 + -4) = uVar110;
                  puVar68[5] = uVar110;
                  puVar68[4] = 1;
                  puVar68[3] = unaff_DI + 0x19;
                  puVar68[2] = *(undefined2 *)(iVar95 + -0xe);
                  puVar68[1] = 0x28eb;
                  *puVar68 = 0x4e2a;
                  piVar14 = (int *)FUN_2424_1b66();
                  puVar66 = (undefined1 *)((int)puVar68 + 0xc);
                  for (iVar17 = 0; iVar17 < 2; iVar17 = iVar17 + 1) {
                    *(int *)(iVar95 + -8) = unaff_DI[iVar17 * 2 + 0x17] + -8;
                    *(int *)(iVar95 + -6) = unaff_DI[iVar17 * 2 + 0x18] + -8;
                    *(undefined2 *)(puVar66 + -2) = 1;
                    *(int *)(puVar66 + -4) = iVar95 + -0xc;
                    *(int *)(puVar66 + -6) = iVar95 + -8;
                    *(undefined2 *)(puVar66 + -8) = 0x28eb;
                    puVar69 = puVar66 + -10;
                    *(undefined2 *)(puVar66 + -10) = 0x4e5c;
                    piVar14 = (int *)FUN_2424_1da0();
                    puVar66 = puVar69 + 10;
                  }
                }
                if ((*(byte *)(iVar95 + 8) & 2) != 0) {
                  if (*(int *)((int)*(undefined4 *)(iVar95 + -0x18) + 8) == 7) {
                    piVar14 = (int *)(*(int *)((int)*(undefined4 *)(iVar95 + -0x14) + 0x76) + 0x2a);
                  }
                  else {
                    piVar14 = unaff_DI + 0x13;
                  }
                  *(undefined2 *)(iVar95 + -0xe) = piVar14;
                  *(undefined2 *)(puVar66 + -2) = 2;
                  *(int **)(puVar66 + -4) = unaff_DI;
                  *(undefined2 *)(puVar66 + -6) = *(undefined2 *)(iVar95 + -0x12);
                  *(undefined2 *)(puVar66 + -8) = *(undefined2 *)(iVar95 + -0x14);
                  *(undefined2 *)(puVar66 + -10) = 0x28eb;
                  puVar70 = (undefined2 *)(puVar66 + -0xc);
                  *(undefined2 *)(puVar66 + -0xc) = 0x4e9a;
                  uVar110 = FUN_28eb_3b36();
                  *(undefined2 *)(iVar95 + -4) = uVar110;
                  puVar70[5] = uVar110;
                  puVar70[4] = 2;
                  puVar70[3] = unaff_DI + 0x15;
                  puVar70[2] = *(undefined2 *)(iVar95 + -0xe);
                  puVar70[1] = 0x28eb;
                  *puVar70 = 0x4eaf;
                  piVar14 = (int *)FUN_2424_1b66();
                  puVar71 = (undefined1 *)((int)puVar70 + 0xc);
                  for (iVar17 = 0; iVar17 < 2; iVar17 = iVar17 + 1) {
                    *(int *)(iVar95 + -8) = unaff_DI[iVar17 * 2 + 0x17] + -8;
                    *(int *)(iVar95 + -6) = unaff_DI[iVar17 * 2 + 0x18] + -8;
                    *(undefined2 *)(puVar71 + -2) = 2;
                    *(int *)(puVar71 + -4) = iVar95 + -0xc;
                    *(int *)(puVar71 + -6) = iVar95 + -8;
                    *(undefined2 *)(puVar71 + -8) = 0x28eb;
                    puVar72 = puVar71 + -10;
                    *(undefined2 *)(puVar71 + -10) = 0x4ee1;
                    piVar14 = (int *)FUN_2424_1da0();
                    puVar71 = puVar72 + 10;
                  }
                }
              }
              return piVar14;
            case (int *)0x1:
              do {
                puVar16 = (undefined2 *)puVar96;
                *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) - *(int *)(iVar95 + -6);
LAB_1a9e_62c7:
                while( true ) {
                  bVar5 = *(byte *)*(undefined4 *)(iVar95 + -0xc);
                  *(uint *)(iVar95 + -4) = (uint)bVar5;
                  *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + 1;
                  if ((*(uint *)(iVar95 + -4) & 0x80) == 0) break;
                  if ((*(uint *)(iVar95 + -4) & 0x40) == 0) {
                    *(uint *)(iVar95 + -4) = *(uint *)(iVar95 + -4) & 0x3f;
                    *(undefined2 *)((int)puVar16 + -2) = *(undefined2 *)(iVar95 + -4);
                    *(undefined2 *)((int)puVar16 + -4) = 0x2000;
                    puVar23 = (undefined2 *)((int)puVar16 + -6);
                    *(undefined2 *)((int)puVar16 + -6) = 0xea0;
                    uVar110 = FUN_1a9e_60f0();
                    puVar16 = puVar23 + 3;
                    *(undefined2 *)(iVar95 + -6) = uVar110;
                    DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc + *(int *)(iVar95 + -4));
                    *(undefined1 *)(iVar95 + -0x24) = *(undefined1 *)*(undefined4 *)(iVar95 + -0xc);
                    *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + 1;
                    if ((*(byte *)(iVar95 + 10) & 2) != 0) {
                      *(int *)(iVar95 + -0x16) = *(int *)(iVar95 + 6) - *(int *)(iVar95 + -6);
                      if (*(char *)(iVar95 + -0x1c) != '\0') {
                        puVar16 = puVar23 + 3;
                        if (*(char *)(iVar95 + -0x1b) == '\0') goto LAB_1a9e_65ea;
                        if ((*(int *)(iVar95 + -0x16) < DAT_554c_42c4) ||
                           (DAT_554c_42c6 <= *(int *)(iVar95 + 6))) {
                          if (*(int *)(iVar95 + -0x16) < DAT_554c_42c4) {
                            iVar11 = DAT_554c_42c4 - *(int *)(iVar95 + -0x16);
                            *(int *)(iVar95 + -0x18) = iVar11;
                            piVar108 = (int *)(iVar95 + -6);
                            iVar17 = *piVar108;
                            *piVar108 = *piVar108 - iVar11;
                            puVar16 = puVar23 + 3;
                            if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0)
                            goto LAB_1a9e_650e;
                          }
                          else {
                            iVar11 = *(int *)(iVar95 + 6) - DAT_554c_42c6;
                            *(int *)(iVar95 + -0x18) = iVar11;
                            piVar108 = (int *)(iVar95 + -6);
                            iVar17 = *piVar108;
                            *piVar108 = *piVar108 - iVar11;
                            puVar16 = puVar23 + 3;
                            if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0) {
                              *(int *)(iVar95 + 6) = DAT_554c_42c6;
                              goto LAB_1a9e_650e;
                            }
                          }
                          goto LAB_1a9e_65ea;
                        }
                      }
LAB_1a9e_650e:
                      puVar23[2] = unaff_DI;
                      pcVar6 = DAT_554c_4d9e;
                      puVar23[1] = 0x2000;
                      *puVar23 = 0xf0f;
                      (*pcVar6)();
                      unaff_DI = (int *)*puVar23;
                      puVar16 = puVar23 + 1;
                      goto LAB_1a9e_65ea;
                    }
                    *(int *)(iVar95 + -0x16) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -6);
                    if (*(char *)(iVar95 + -0x1c) == '\0') {
LAB_1a9e_659b:
                      puVar23[2] = unaff_DI;
                      pcVar6 = DAT_554c_4d9e;
                      puVar23[1] = 0x2000;
                      *puVar23 = 0xf99;
                      (*pcVar6)();
                      unaff_DI = (int *)*puVar23;
                      puVar16 = puVar23 + 1;
                    }
                    else {
                      if (*(char *)(iVar95 + -0x1b) == '\0') goto LAB_1a9e_65ea;
                      if ((DAT_554c_42c4 <= *(int *)(iVar95 + 6)) &&
                         (*(int *)(iVar95 + -0x16) <= DAT_554c_42c6)) goto LAB_1a9e_659b;
                      if (*(int *)(iVar95 + 6) < DAT_554c_42c4) {
                        iVar11 = DAT_554c_42c4 - *(int *)(iVar95 + 6);
                        *(int *)(iVar95 + -0x18) = iVar11;
                        piVar108 = (int *)(iVar95 + -6);
                        iVar17 = *piVar108;
                        *piVar108 = *piVar108 - iVar11;
                        puVar16 = puVar23 + 3;
                        if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0) {
                          *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + iVar11;
                          goto LAB_1a9e_659b;
                        }
                      }
                      else {
                        iVar11 = (*(int *)(iVar95 + -0x16) - DAT_554c_42c6) + -1;
                        *(int *)(iVar95 + -0x18) = iVar11;
                        piVar108 = (int *)(iVar95 + -6);
                        iVar17 = *piVar108;
                        *piVar108 = *piVar108 - iVar11;
                        puVar16 = puVar23 + 3;
                        if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0)
                        goto LAB_1a9e_659b;
                      }
                    }
LAB_1a9e_65ea:
                    *(undefined2 *)(iVar95 + 6) = *(undefined2 *)(iVar95 + -0x16);
                  }
                  else {
                    *(uint *)(iVar95 + -4) = *(uint *)(iVar95 + -4) & 0x3f;
                    uVar110 = *(undefined2 *)(iVar95 + -4);
                    *(undefined2 *)(iVar95 + -6) = uVar110;
                    *(undefined2 *)((int)puVar16 + -2) = uVar110;
                    *(undefined2 *)((int)puVar16 + -4) = 0x2000;
                    puVar20 = (undefined2 *)((int)puVar16 + -6);
                    *(undefined2 *)((int)puVar16 + -6) = 0xcd8;
                    uVar110 = FUN_1a9e_60f0();
                    puVar16 = puVar20 + 3;
                    *(undefined2 *)(iVar95 + -6) = uVar110;
                    if (*(int *)(iVar95 + -4) != 0) {
                      *(undefined2 *)(iVar95 + -0x22) =
                           ((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
                      *(undefined2 *)(iVar95 + -0x12) =
                           *(undefined2 *)(*(int *)(iVar95 + -0x22) * 2 + 0x7cf2);
                      puVar20[2] = unaff_DI;
                      puVar20[1] = unaff_SI;
                      pcVar109 = (char *)(iVar95 + -0x174);
                      iVar11 = *(int *)(iVar95 + -0x22) << 1;
                      iVar17 = *(int *)(iVar95 + -6);
                      if (0 < iVar17) {
                        cVar7 = *(char *)(iVar95 + -0x23);
                        do {
                          while( true ) {
                            uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + -0xc) >> 0x10);
                            iVar12 = (int)*(undefined4 *)(iVar95 + -0xc);
                            uVar15 = *(int *)(iVar11 + 0x7cf2) - *(int *)(iVar95 + -0x12);
                            uVar13 = uVar15 >> 1;
                            if ((uVar15 & 1) == 0) break;
                            pcVar3 = pcVar109;
                            pcVar109 = pcVar109 + 1;
                            *pcVar3 = (*(byte *)(iVar12 + uVar13) & 0xf) + cVar7;
                            iVar11 = iVar11 + 2;
                            iVar17 = iVar17 + -1;
                            if (iVar17 == 0) goto LAB_1a9e_6371;
                          }
                          pcVar3 = pcVar109;
                          pcVar109 = pcVar109 + 1;
                          *pcVar3 = (*(byte *)(iVar12 + uVar13) >> 4) + cVar7;
                          iVar11 = iVar11 + 2;
                          iVar17 = iVar17 + -1;
                        } while (iVar17 != 0);
                      }
LAB_1a9e_6371:
                      unaff_SI = (int *)puVar20[1];
                      unaff_DI = (int *)puVar20[2];
                      *(int *)(iVar95 + -0xc) =
                           *(int *)(iVar95 + -0xc) + (*(int *)(iVar95 + -4) + 1 >> 1);
                    }
                    DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc + *(int *)(iVar95 + -4));
                    if (*(int *)(iVar95 + -6) != 0) {
                      *(int *)(iVar95 + -0x1a) = iVar95 + -0x174;
                      if ((*(byte *)(iVar95 + 10) & 2) != 0) {
                        *(int *)(iVar95 + -0x16) = *(int *)(iVar95 + 6) - *(int *)(iVar95 + -6);
                        if (*(char *)(iVar95 + -0x1c) != '\0') {
                          puVar16 = puVar20 + 3;
                          if (*(char *)(iVar95 + -0x1b) == '\0') goto LAB_1a9e_64ac;
                          if ((*(int *)(iVar95 + -0x16) < DAT_554c_42c4) ||
                             (DAT_554c_42c6 <= *(int *)(iVar95 + 6))) {
                            if (*(int *)(iVar95 + -0x16) < DAT_554c_42c4) {
                              iVar11 = DAT_554c_42c4 - *(int *)(iVar95 + -0x16);
                              *(int *)(iVar95 + -0x18) = iVar11;
                              piVar108 = (int *)(iVar95 + -6);
                              iVar17 = *piVar108;
                              *piVar108 = *piVar108 - iVar11;
                              puVar16 = puVar20 + 3;
                              if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0)
                              goto LAB_1a9e_63c8;
                            }
                            else {
                              iVar11 = *(int *)(iVar95 + 6) + DAT_554c_42c6;
                              *(int *)(iVar95 + -0x18) = iVar11;
                              piVar108 = (int *)(iVar95 + -6);
                              iVar17 = *piVar108;
                              *piVar108 = *piVar108 - iVar11;
                              puVar16 = puVar20 + 3;
                              if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0) {
                                *(int *)(iVar95 + -0x1a) = *(int *)(iVar95 + -0x1a) + iVar11;
                                *(int *)(iVar95 + 6) = DAT_554c_42c6;
                                goto LAB_1a9e_63c8;
                              }
                            }
                            goto LAB_1a9e_64ac;
                          }
                        }
LAB_1a9e_63c8:
                        puVar20[2] = unaff_SI;
                        puVar20[1] = unaff_DI;
                        pcVar6 = DAT_554c_4e0e;
                        *puVar20 = 0x2000;
                        puVar21 = puVar20 + -1;
                        puVar20[-1] = 0xdc5;
                        (*pcVar6)();
                        unaff_DI = (int *)*puVar21;
                        unaff_SI = (int *)puVar21[1];
                        puVar16 = puVar21 + 2;
                        goto LAB_1a9e_64ac;
                      }
                      *(int *)(iVar95 + -0x16) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -6);
                      if (*(char *)(iVar95 + -0x1c) == '\0') {
LAB_1a9e_6455:
                        puVar20[2] = unaff_SI;
                        puVar20[1] = unaff_DI;
                        pcVar6 = DAT_554c_4e0e;
                        *puVar20 = 0x2000;
                        puVar22 = puVar20 + -1;
                        puVar20[-1] = 0xe52;
                        (*pcVar6)();
                        unaff_DI = (int *)*puVar22;
                        unaff_SI = (int *)puVar22[1];
                        puVar16 = puVar22 + 2;
                      }
                      else {
                        puVar16 = puVar20 + 3;
                        if (*(char *)(iVar95 + -0x1b) == '\0') goto LAB_1a9e_64ac;
                        if ((DAT_554c_42c4 <= *(int *)(iVar95 + 6)) &&
                           (*(int *)(iVar95 + -0x16) <= DAT_554c_42c6)) goto LAB_1a9e_6455;
                        if (*(int *)(iVar95 + 6) < DAT_554c_42c4) {
                          iVar11 = DAT_554c_42c4 - *(int *)(iVar95 + 6);
                          *(int *)(iVar95 + -0x18) = iVar11;
                          piVar108 = (int *)(iVar95 + -6);
                          iVar17 = *piVar108;
                          *piVar108 = *piVar108 - iVar11;
                          puVar16 = puVar20 + 3;
                          if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0) {
                            *(int *)(iVar95 + -0x1a) = *(int *)(iVar95 + -0x1a) + iVar11;
                            *(int *)(iVar95 + 6) = DAT_554c_42c4;
                            goto LAB_1a9e_6455;
                          }
                        }
                        else {
                          iVar11 = (*(int *)(iVar95 + -0x16) - DAT_554c_42c6) + -1;
                          *(int *)(iVar95 + -0x18) = iVar11;
                          piVar108 = (int *)(iVar95 + -6);
                          iVar17 = *piVar108;
                          *piVar108 = *piVar108 - iVar11;
                          puVar16 = puVar20 + 3;
                          if (*piVar108 != 0 && SBORROW2(iVar17,iVar11) == *piVar108 < 0)
                          goto LAB_1a9e_6455;
                        }
                      }
LAB_1a9e_64ac:
                      *(undefined2 *)(iVar95 + 6) = *(undefined2 *)(iVar95 + -0x16);
                    }
                  }
                }
                if ((*(uint *)(iVar95 + -4) & 0x40) == 0) {
                  *(uint *)(iVar95 + -4) = *(uint *)(iVar95 + -4) & 0x3f;
                  *(int *)((int)puVar16 + -2) = -*(int *)(iVar95 + -4);
                  *(undefined2 *)((int)puVar16 + -4) = 0x2000;
                  puVar25 = (undefined2 *)((int)puVar16 + -6);
                  *(undefined2 *)((int)puVar16 + -6) = 0x102c;
                  uVar15 = FUN_1a9e_60f0();
                  *(int *)(iVar95 + -6) = (uVar15 ^ (int)uVar15 >> 0xf) - ((int)uVar15 >> 0xf);
                  DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc - *(int *)(iVar95 + -4));
                  if ((*(byte *)(iVar95 + 10) & 2) == 0) {
                    *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) - *(int *)(iVar95 + -6);
                  }
                  else {
                    *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -6);
                  }
                  bVar5 = *(byte *)*(undefined4 *)(iVar95 + -0xc);
                  *(uint *)(iVar95 + -4) = (uint)bVar5;
                  puVar16 = puVar25 + 3;
                  if (((bVar5 & 0xc0) == 0) &&
                     (*(uint *)(iVar95 + -0x12) = bVar5 & 0x3f, puVar16 = puVar25 + 3,
                     (bVar5 & 0x3f) != 0)) {
                    *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + 1;
                    *(int *)(iVar95 + -0x12) = *(int *)(iVar95 + -0x12) << 6;
                    puVar25[2] = *(undefined2 *)(iVar95 + -0x12);
                    puVar25[1] = 0x2000;
                    *puVar25 = 0x107b;
                    uVar110 = FUN_1a9e_60f0();
                    puVar16 = (undefined2 *)((int)puVar25 + 6);
                    *(undefined2 *)(iVar95 + -6) = uVar110;
                    DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc - *(int *)(iVar95 + -0x12));
                    if ((*(byte *)(iVar95 + 10) & 2) == 0) {
                      *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) - *(int *)(iVar95 + -6);
                    }
                    else {
                      *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -6);
                      puVar16 = (undefined2 *)((int)puVar25 + 6);
                    }
                  }
                  iVar17 = *(int *)(iVar95 + -0x26);
                  uVar13 = *(uint *)(iVar95 + -0x28);
                  puVar1 = (uint *)(iVar95 + -0x2c);
                  uVar15 = *puVar1;
                  *puVar1 = *puVar1 + uVar13;
                  *(int *)(iVar95 + -0x2a) =
                       *(int *)(iVar95 + -0x2a) + iVar17 + (uint)CARRY2(uVar15,uVar13);
                  *(undefined2 *)(iVar95 + -0x22) = *(undefined2 *)(iVar95 + -0x2a);
                  if (*(int *)(iVar95 + -0x2e) == *(int *)(iVar95 + -0x22)) {
                    uVar110 = *(undefined2 *)(iVar95 + -0x10);
                    *(undefined2 *)(iVar95 + -10) = *(undefined2 *)(iVar95 + -0xe);
                    *(undefined2 *)(iVar95 + -0xc) = uVar110;
                    *(undefined2 *)(iVar95 + 6) = *(undefined2 *)(iVar95 + -0x30);
                    DAT_5b41_26dc = (int *)*(int *)(iVar95 + -0x34);
                  }
                  else {
                    uVar15 = *(int *)(iVar95 + -0x22) - *(int *)(iVar95 + -0x2e) >> 0xf;
                    iVar17 = ((*(int *)(iVar95 + -0x22) - *(int *)(iVar95 + -0x2e) ^ uVar15) -
                             uVar15) + -1;
                    *(int *)(iVar95 + -0x18) = iVar17;
                    if (iVar17 != 0) {
                      while (*(int *)(iVar95 + -0x18) != 0) {
                        bVar5 = *(byte *)*(undefined4 *)(iVar95 + -0xc);
                        *(uint *)(iVar95 + -4) = (uint)bVar5;
                        *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + 1;
                        uVar15 = bVar5 & 0x3f;
                        *(uint *)(iVar95 + -6) = uVar15;
                        *(uint *)((int)puVar16 + -2) = uVar15;
                        *(undefined2 *)((int)puVar16 + -4) = 0x2000;
                        puVar26 = (undefined2 *)((int)puVar16 + -6);
                        *(undefined2 *)((int)puVar16 + -6) = 0x1106;
                        piVar14 = (int *)FUN_1a9e_60f0();
                        puVar16 = puVar26 + 3;
                        *(int *)(iVar95 + -8) = (int)piVar14;
                        if ((*(byte *)(iVar95 + 10) & 2) != 0) {
                          piVar14 = (int *)-(int)piVar14;
                          *(int *)(iVar95 + -8) = (int)piVar14;
                        }
                        if ((*(uint *)(iVar95 + -4) & 0x80) == 0) {
                          if ((*(uint *)(iVar95 + -4) & 0x40) == 0) {
                            DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc - *(int *)(iVar95 + -6));
                            *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) - *(int *)(iVar95 + -8);
                            bVar5 = *(byte *)*(undefined4 *)(iVar95 + -0xc);
                            *(uint *)(iVar95 + -4) = (uint)bVar5;
                            puVar16 = puVar26 + 3;
                            if (((bVar5 & 0xc0) == 0) &&
                               (*(uint *)(iVar95 + -0x12) = bVar5 & 0x3f, puVar16 = puVar26 + 3,
                               (bVar5 & 0x3f) != 0)) {
                              *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + 1;
                              *(int *)(iVar95 + -0x12) = *(int *)(iVar95 + -0x12) << 6;
                              puVar26[2] = *(undefined2 *)(iVar95 + -0x12);
                              puVar26[1] = 0x2000;
                              *puVar26 = 0x11aa;
                              uVar110 = FUN_1a9e_60f0();
                              puVar16 = (undefined2 *)((int)puVar26 + 6);
                              *(undefined2 *)(iVar95 + -6) = uVar110;
                              DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc - *(int *)(iVar95 + -0x12))
                              ;
                              if ((*(byte *)(iVar95 + 10) & 2) == 0) {
                                *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) - *(int *)(iVar95 + -6);
                              }
                              else {
                                *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -6);
                                puVar16 = (undefined2 *)((int)puVar26 + 6);
                              }
                            }
                            *(int *)(iVar95 + -0x18) = *(int *)(iVar95 + -0x18) + -1;
                          }
                          else {
                            if (*(int *)(iVar95 + -6) == 0) {
                              return piVar14;
                            }
                            DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc + *(int *)(iVar95 + -6));
                            *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -8);
                          }
                        }
                        else {
                          DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc + *(int *)(iVar95 + -6));
                          if ((*(uint *)(iVar95 + -4) & 0x40) == 0) {
                            *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -8);
                            *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + 1;
                            puVar16 = puVar26 + 3;
                          }
                          else {
                            *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -8);
                            *(int *)(iVar95 + -0xc) =
                                 *(int *)(iVar95 + -0xc) + (*(int *)(iVar95 + -6) + 1 >> 1);
                            puVar16 = puVar26 + 3;
                          }
                        }
                      }
                    }
                  }
                  uVar110 = *(undefined2 *)(iVar95 + -0xc);
                  *(undefined2 *)(iVar95 + -0xe) = *(undefined2 *)(iVar95 + -10);
                  *(undefined2 *)(iVar95 + -0x10) = uVar110;
                  *(undefined2 *)(iVar95 + -0x2e) = *(undefined2 *)(iVar95 + -0x22);
                  *(undefined2 *)(iVar95 + -0x30) = *(undefined2 *)(iVar95 + 6);
                  piVar14 = DAT_5b41_26dc;
                  *(int *)(iVar95 + -0x34) = (int)DAT_5b41_26dc;
                  piVar108 = (int *)(iVar95 + 0xe);
                  *piVar108 = *piVar108 + -1;
                  if (*piVar108 == 0) {
                    return piVar14;
                  }
                  if ((*(byte *)(iVar95 + 10) & 2) == 0) {
                    iVar17 = ((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
                  }
                  else {
                    iVar17 = -((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
                  }
                  *(int *)(iVar95 + 6) = *(int *)(iVar95 + -0x32) + iVar17;
                  *(int *)(iVar95 + 8) = *(int *)(iVar95 + 8) + *(int *)(iVar95 + -0x14);
                  if (*(char *)(iVar95 + -0x1c) != '\0') goto code_r0x0002122e;
                  goto LAB_1a9e_686e;
                }
                puVar1 = (uint *)(iVar95 + -4);
                *puVar1 = *puVar1 & 0x3f;
                if (*puVar1 == 0) {
                  return (int *)(uint)bVar5;
                }
                *(undefined2 *)((int)puVar16 + -2) = *(undefined2 *)(iVar95 + -4);
                *(undefined2 *)((int)puVar16 + -4) = 0x2000;
                puVar24 = (undefined1 *)((int)puVar16 + -6);
                *(undefined2 *)((int)puVar16 + -6) = 0xfed;
                uVar110 = FUN_1a9e_60f0();
                puVar16 = (undefined2 *)(puVar24 + 6);
                *(undefined2 *)(iVar95 + -6) = uVar110;
                DAT_5b41_26dc = (int *)((int)DAT_5b41_26dc + *(int *)(iVar95 + -4));
                puVar96 = puVar24 + 6;
                if ((*(byte *)(iVar95 + 10) & 2) == 0) {
                  *(int *)(iVar95 + 6) = *(int *)(iVar95 + 6) + *(int *)(iVar95 + -6);
                  goto LAB_1a9e_62c7;
                }
              } while( true );
            case (int *)0x3:
              if ((*(int *)(iVar17 + 8) == 0x16) ||
                 (puVar96 = (undefined1 *)(iVar95 + -0xc), *(int *)(iVar17 + 8) == 0x37)) {
                uVar110 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
                iVar17 = (int)DAT_5b41_0567;
                puVar96 = (undefined1 *)(iVar95 + -0xc);
                if (*(int *)(iVar17 + 0x62) != 0 || *(int *)(iVar17 + 100) != 0) {
                  *(undefined2 *)(iVar95 + -0xe) = 0;
                  *(undefined2 *)(iVar95 + -0x10) = 0;
                  *(undefined2 *)(iVar95 + -0x12) = *(undefined2 *)(iVar17 + 100);
                  *(undefined2 *)(iVar95 + -0x14) = *(undefined2 *)(iVar17 + 0x62);
                  *(undefined2 *)(iVar95 + -0x16) = 0x2000;
                  puVar58 = (undefined1 *)(iVar95 + -0x18);
                  *(undefined2 *)(iVar95 + -0x18) = 0x46c6;
                  FUN_2424_2165();
                  puVar96 = puVar58 + 0xc;
                }
              }
              if (DAT_554c_02f0 != -1) {
                DAT_554c_42ce = (undefined1)DAT_554c_02f0;
                *(undefined2 *)(puVar96 + -2) = 0;
                *(int *)(puVar96 + -4) = DAT_5b41_054d - DAT_5b41_0927;
                *(int *)(puVar96 + -6) = DAT_5b41_054b - DAT_5b41_0925;
                *(int *)(puVar96 + -8) = DAT_5b41_0549 - DAT_5b41_0927;
                *(int *)(puVar96 + -10) = DAT_5b41_0547 - DAT_5b41_0925;
                *(undefined2 *)(puVar96 + -0xc) = 0x2000;
                puVar59 = (undefined2 *)(puVar96 + -0xe);
                *(undefined2 *)(puVar96 + -0xe) = 0x4704;
                FUN_2424_276e();
                puVar59[1] = 2;
                *puVar59 = (undefined2 *)&DAT_5b41_054b;
                puVar59[-1] = (undefined2 *)&DAT_5b41_0547;
                puVar59[-2] = 0x2000;
                puVar60 = puVar59 + -3;
                puVar59[-3] = 0x4711;
                FUN_2424_1a04();
                puVar96 = (undefined1 *)((int)puVar60 + 0x14);
              }
              if (5000 < DAT_554c_2f1c) {
                *(undefined2 *)(puVar96 + -2) = 0x2000;
                puVar61 = (undefined2 *)(puVar96 + -4);
                *(undefined2 *)(puVar96 + -4) = 0x4721;
                FUN_2424_196d();
                puVar61[1] = 1;
                *puVar61 = 0x2000;
                puVar62 = puVar61 + -1;
                puVar61[-1] = 0x4728;
                FUN_2424_184a();
                puVar96 = (undefined1 *)((int)puVar62 + 6);
              }
              *(undefined2 *)(puVar96 + -2) = 0x2000;
              puVar63 = (undefined2 *)(puVar96 + -4);
              *(undefined2 *)(puVar96 + -4) = 0x472f;
              FUN_2424_0304();
              puVar63[1] = 0;
              *puVar63 = 0x2000;
              puVar64 = puVar63 + -1;
              puVar63[-1] = 0x4736;
              FUN_460e_1314();
              *(undefined2 *)((int)puVar64 + 4) = 0x460e;
              *(undefined2 *)((int)puVar64 + 2) = 0x473e;
              FUN_2424_1650();
              DAT_5b41_0567 =
                   (int *)CONCAT22(*(undefined2 *)(iVar95 + -4),(int *)*(undefined2 *)(iVar95 + -6))
              ;
              return (int *)*(undefined2 *)(iVar95 + -6);
            case (int *)0x4:
              if (DAT_554c_42df != '\0') {
                *(undefined2 *)(iVar95 + -0xe) = 0;
                *(undefined2 *)(iVar95 + -0x10) = 0x5654;
                *(undefined2 *)(iVar95 + -0x12) = unaff_SI;
                *(undefined2 *)(iVar95 + -0x14) = 0x2000;
                puVar36 = (undefined2 *)(iVar95 + -0x16);
                *(undefined2 *)(iVar95 + -0x16) = 0x2b26;
                iVar17 = FUN_1a9e_6a85();
                if ((in_DX == 0xffff) && (iVar17 == -1)) {
                  puVar36[4] = 0;
                  puVar36[3] = 0x565d;
                  puVar36[2] = unaff_SI;
                  puVar36[1] = 0x2000;
                  *puVar36 = 0x2b47;
                  iVar17 = FUN_1a9e_6a85();
                  if ((in_DX != 0xffff) ||
                     (puVar48 = (undefined2 *)((int)puVar36 + 10), iVar17 != -1)) {
                    *(undefined2 *)(iVar95 + -0x1c) = 6;
                    puVar48 = (undefined2 *)((int)puVar36 + 10);
                  }
                }
                else {
                  *(undefined2 *)(iVar95 + -0x1c) = 5;
                  puVar48 = puVar36 + 5;
                }
                if (4 < *(int *)(iVar95 + -0x1c)) {
                  *(undefined2 *)((int)puVar48 + -2) = unaff_SI;
                  *(undefined2 *)((int)puVar48 + -4) = 0x2000;
                  puVar37 = (undefined2 *)((int)puVar48 + -6);
                  *(undefined2 *)((int)puVar48 + -6) = 0x2b68;
                  uVar110 = FUN_1a9e_6e3d();
                  puVar37[2] = in_DX;
                  puVar37[1] = uVar110;
                  *puVar37 = 0x5666;
                  puVar37[-1] = unaff_SI;
                  puVar37[-2] = 0;
                  puVar37[-3] = 0x2000;
                  puVar38 = puVar37 + -4;
                  puVar37[-4] = 0x2b7a;
                  unaff_DI = (int *)FUN_28eb_2779();
                  puVar39 = (undefined1 *)((int)puVar38 + 0xe);
                  puVar48 = (undefined2 *)((int)puVar38 + 0xe);
                  if (-1 < (int)unaff_DI) {
                    *(undefined2 *)(iVar95 + -0x1e) = 0;
                    *(undefined2 *)(iVar95 + -0x20) = 0x7fff;
                    while( true ) {
                      *(undefined2 *)(puVar39 + -2) = 0;
                      *(undefined2 *)(puVar39 + -4) = 0;
                      *(undefined2 *)(puVar39 + -6) = *(undefined2 *)(iVar95 + -0x1e);
                      *(undefined2 *)(puVar39 + -8) = *(undefined2 *)(iVar95 + -0x20);
                      *(undefined2 *)(puVar39 + -10) = 0x2000;
                      puVar40 = puVar39 + -0xc;
                      *(undefined2 *)(puVar39 + -0xc) = 0x2bb1;
                      lVar115 = FUN_2fc8_00fc();
                      puVar44 = puVar40 + 8;
                      puVar39 = puVar40 + 8;
                      *(undefined2 *)(iVar95 + -0xe) = (int)((ulong)lVar115 >> 0x10);
                      *(undefined2 *)(iVar95 + -0x10) = (int)lVar115;
                      if (lVar115 != 0) break;
                      uVar15 = *(uint *)(iVar95 + -0x1e);
                      uVar13 = *(uint *)(iVar95 + -0x20);
                      *(int *)(iVar95 + -0x1e) = (int)uVar15 >> 1;
                      *(uint *)(iVar95 + -0x20) = uVar13 >> 1 | (uint)((uVar15 & 1) != 0) << 0xf;
                    }
                    uVar110 = *(undefined2 *)(iVar95 + -8);
                    *(undefined2 *)(iVar95 + -10) = *(undefined2 *)(iVar95 + -6);
                    *(undefined2 *)(iVar95 + -0xc) = uVar110;
                    while( true ) {
                      *(undefined2 *)(puVar44 + -2) = *(undefined2 *)(iVar95 + -0x20);
                      *(undefined2 *)(puVar44 + -4) = *(undefined2 *)(iVar95 + -0xe);
                      *(undefined2 *)(puVar44 + -6) = *(undefined2 *)(iVar95 + -0x10);
                      *(int **)(puVar44 + -8) = unaff_DI;
                      *(undefined2 *)(puVar44 + -10) = uVar112;
                      puVar46 = (undefined2 *)(puVar44 + -0xc);
                      *(undefined2 *)(puVar44 + -0xc) = 0x2c2c;
                      iVar17 = FUN_28eb_2aad();
                      puVar42 = puVar46 + 6;
                      *(int *)(iVar95 + -0x16) = iVar17;
                      if (iVar17 < 1) break;
                      if (*(int *)(iVar95 + -0x1c) == 6) {
                        puVar46[5] = *(undefined2 *)(iVar95 + -0x16);
                        puVar46[4] = *(undefined2 *)(iVar95 + -0xe);
                        puVar46[3] = *(undefined2 *)(iVar95 + -0x10);
                        puVar46[2] = *(undefined2 *)(iVar95 + -0xe);
                        puVar46[1] = *(undefined2 *)(iVar95 + -0x10);
                        *puVar46 = uVar112;
                        puVar41 = puVar46 + -1;
                        puVar46[-1] = 0x2be6;
                        FUN_1a9e_836a();
                        puVar42 = (undefined2 *)((int)puVar41 + 0xe);
                        *(int *)(iVar95 + -0x16) = *(int *)(iVar95 + -0x16) << 1;
                        *(int *)(iVar95 + -0x16) = *(int *)(iVar95 + -0x16) << 1;
                      }
                      *(undefined2 *)((int)puVar42 + -2) = *(undefined2 *)(iVar95 + -0x16);
                      *(undefined2 *)((int)puVar42 + -4) = *(undefined2 *)(iVar95 + -10);
                      *(undefined2 *)((int)puVar42 + -6) = *(undefined2 *)(iVar95 + -0xc);
                      *(undefined2 *)((int)puVar42 + -8) = *(undefined2 *)(iVar95 + -0xe);
                      *(undefined2 *)((int)puVar42 + -10) = *(undefined2 *)(iVar95 + -0x10);
                      pcVar6 = DAT_554c_4db2;
                      *(undefined2 *)((int)puVar42 + -0xc) = uVar112;
                      puVar43 = (undefined1 *)((int)puVar42 + -0xe);
                      *(undefined2 *)((int)puVar42 + -0xe) = (undefined2 *)&DAT_554c_2c02;
                      (*pcVar6)();
                      iVar17 = *(int *)(iVar95 + -0x1e);
                      iVar11 = *(int *)(iVar95 + -0x20);
                      *(int *)(puVar43 + 8) = iVar11 << 1;
                      *(uint *)(puVar43 + 6) = iVar17 << 1 | (uint)(iVar11 < 0);
                      *(undefined2 *)(puVar43 + 8) = uVar112;
                      uVar112 = 0x1000;
                      puVar45 = puVar43 + 6;
                      *(undefined2 *)(puVar43 + 6) = 0x2c1d;
                      FUN_1000_1a00();
                      puVar44 = puVar45 + 2;
                    }
                    puVar46[5] = unaff_DI;
                    puVar46[4] = uVar112;
                    puVar47 = puVar46 + 3;
                    puVar46[3] = 0x2c3c;
                    FUN_28eb_29db();
                    puVar48 = (undefined2 *)((int)puVar47 + 6);
                  }
                }
              }
              bVar113 = true;
              *(undefined2 *)((int)puVar48 + -2) = uVar112;
              puVar49 = (undefined2 *)((int)puVar48 + -4);
              *(undefined2 *)((int)puVar48 + -4) = 0x2c4e;
              FUN_1000_1821();
              puVar51 = puVar49 + 2;
              if (!bVar113) {
                puVar49[1] = *(undefined2 *)(iVar95 + -0xe);
                *puVar49 = *(undefined2 *)(iVar95 + -0x10);
                puVar49[-1] = 0x1000;
                puVar50 = puVar49 + -2;
                puVar49[-2] = 0x2c5b;
                func_0x0002fdf5();
                puVar51 = (undefined2 *)((int)puVar50 + 4);
              }
              if (*(int *)(iVar95 + -0x12) != 0) {
                *(undefined2 *)((int)puVar51 + -2) = *(undefined2 *)(iVar95 + -0x12);
                *(undefined2 *)((int)puVar51 + -4) = 0x1000;
                puVar52 = (undefined1 *)((int)puVar51 + -6);
                *(undefined2 *)((int)puVar51 + -6) = 0x2c6c;
                FUN_1000_130c();
                puVar51 = (undefined2 *)(puVar52 + 6);
                uRam00055624 = 0;
                uRam00055622 = 0;
              }
              if (*(int *)(iVar95 + -0x1c) == 0) {
                bVar113 = true;
                *(undefined2 *)((int)puVar51 + -2) = 0x1000;
                puVar53 = (undefined2 *)((int)puVar51 + -4);
                *(undefined2 *)((int)puVar51 + -4) = 0x2c90;
                FUN_1000_1821();
                puVar55 = puVar53 + 2;
                if (!bVar113) {
                  puVar53[1] = *(undefined2 *)(iVar95 + -6);
                  *puVar53 = *(undefined2 *)(iVar95 + -8);
                  puVar53[-1] = 0x1000;
                  puVar54 = puVar53 + -2;
                  puVar53[-2] = 0x2c9d;
                  func_0x0002fdf5();
                  puVar55 = (undefined2 *)((int)puVar54 + 4);
                }
                if (unaff_DI != (int *)0x0) {
                  *(undefined2 *)((int)puVar55 + -2) = unaff_DI;
                  *(undefined2 *)((int)puVar55 + -4) = 0x1000;
                  puVar56 = (undefined1 *)((int)puVar55 + -6);
                  *(undefined2 *)((int)puVar55 + -6) = 0x2caa;
                  FUN_28eb_29db();
                  puVar55 = (undefined2 *)(puVar56 + 6);
                }
                *(undefined2 *)((int)puVar55 + -2) = *(undefined2 *)(iVar95 + -4);
                *(undefined2 *)((int)puVar55 + -4) = 0x1000;
                puVar57 = (undefined1 *)((int)puVar55 + -6);
                *(undefined2 *)((int)puVar55 + -6) = 0x2cb5;
                FUN_1a9e_82f5();
                puVar51 = (undefined2 *)(puVar57 + 6);
                *(undefined2 *)(iVar95 + -4) = 0;
              }
              if (*(int *)(iVar95 + -0x1a) != 0) {
                *(undefined2 *)((int)puVar51 + -2) = unaff_SI;
                *(undefined2 *)((int)puVar51 + -4) = 0x1000;
                *(undefined2 *)((int)puVar51 + -6) = 0x2cc9;
                FUN_1a9e_6e73();
              }
              return (int *)*(undefined2 *)(iVar95 + -4);
            }
switchD_2000_7d1e_caseD_1:
            if ((char)piVar14 != '\0') {
              *(undefined2 *)(iVar95 + -0xe) = (undefined2 *)&DAT_554c_5175;
              *(undefined2 *)(iVar95 + -0x10) = (undefined2 *)&DAT_554c_5173;
              *(undefined2 *)(iVar95 + -0x12) = *(undefined2 *)(iVar95 + 4);
              *(undefined2 *)(iVar95 + -0x14) = 0x2000;
              *(undefined2 *)(iVar95 + -0x16) = 0x84;
              FUN_2fc8_0364();
              piVar14 = (int *)0x0;
              if (DAT_554c_5173 < -0x1e) {
                piVar14 = (int *)0x4;
              }
              else if (0x1d < DAT_554c_5173) {
                piVar14 = (int *)0x8;
              }
              if (DAT_554c_5175 < -0x1e) {
                piVar14 = (int *)((uint)piVar14 | 1);
              }
              else if (0x1d < DAT_554c_5175) {
                piVar14 = (int *)((uint)piVar14 | 2);
              }
            }
            return piVar14;
          }
        }
        else {
          if (piVar14 == (int *)0x2e) goto LAB_28eb_34f4;
          if ((int)piVar14 < 0x2f) {
            if ((piVar14 == (int *)0x8) || (piVar14 == (int *)0xa)) goto LAB_28eb_34e5;
          }
          else if (piVar14 == (int *)0x30) goto LAB_28eb_34f4;
        }
        goto LAB_28eb_356a;
      }
      if (piVar14 == (int *)0x4c) {
LAB_28eb_34e5:
        uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
        iVar17 = (int)*(undefined4 *)(iVar95 + 4);
        *(undefined2 *)(iVar17 + 0x4a) = 0;
        *(undefined2 *)(iVar17 + 0x48) = 0;
        goto LAB_28eb_3507;
      }
      if ((int)piVar14 < 0x4d) {
        if (piVar14 != (int *)0x3c) {
          if ((int)piVar14 < 0x3d) {
            if ((piVar14 == (int *)0x39) || (piVar14 == (int *)0x3a)) {
LAB_28eb_351d:
              uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
              iVar17 = *(int *)(*(int *)((int)*(undefined4 *)(iVar95 + 4) + 8) * 2 + 0x68fe);
              if (iVar17 == 0) {
                return piVar14;
              }
              *(undefined2 *)(iVar95 + -0xe) = unaff_SS;
              *(int *)(iVar95 + -0x10) = iVar95 + -10;
              *(undefined2 *)(iVar95 + -0x12) = *(undefined2 *)(*(int *)(iVar95 + 4) + 0x10);
              *(int *)(iVar95 + -0x14) = iVar17;
              *(undefined2 *)(iVar95 + -0x16) = 0x28eb;
              *(undefined2 *)(iVar95 + -0x18) = 0xc3f3;
              FUN_4551_03eb();
              uVar112 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
              iVar17 = (int)*(undefined4 *)(iVar95 + 4);
              *(undefined2 *)(iVar17 + 0x48) = *(undefined2 *)(iVar95 + -6);
              *(undefined2 *)(iVar17 + 0x4a) = *(undefined2 *)(iVar95 + -4);
              uVar110 = *(undefined2 *)(iVar17 + 0x4a);
              piVar14 = (int *)*(undefined2 *)(iVar17 + 0x48);
              *(undefined2 *)(iVar17 + 0x46) = uVar110;
              *(undefined2 *)(iVar17 + 0x44) = piVar14;
              goto LAB_28eb_3636;
            }
          }
          else if (piVar14 == (int *)0x47) goto LAB_28eb_351d;
          goto LAB_28eb_356a;
        }
      }
      else if (((piVar14 != (int *)0x52) && (piVar14 != (int *)0x53)) && (piVar14 != (int *)0x54))
      goto LAB_28eb_356a;
    }
    goto LAB_28eb_34f4;
  }
  if (piVar14 == (int *)0x7b) goto LAB_28eb_34f4;
  if (0x7b < (int)piVar14) {
    if (piVar14 != (int *)0xcb) {
      if ((int)piVar14 < 0xcc) {
        piVar14 = piVar14 + -0x3e;
        if (piVar14 < (int *)0x4) {
          iVar17 = (int)piVar14 * 2;
          uVar112 = 0x2000;
          switch(piVar14) {
          case (int *)0x0:
            *(int *)(iVar17 + 0x3c) = (int)piVar14 - *(int *)(iVar17 + 0x28);
            *(int *)(iVar17 + 0x3c) =
                 *(int *)(iVar17 + 0x3c) << (9U - *(char *)(iVar95 + 10) & 0x1f);
            *(undefined2 *)(iVar95 + -0xe) = *(undefined2 *)(iVar95 + 6);
            *(undefined2 *)(iVar95 + -0x10) = *(undefined2 *)(iVar95 + 4);
            *(undefined2 *)(iVar95 + -0x12) = 0x2000;
            *(undefined2 *)(iVar95 + -0x14) = 0xcb79;
            piVar14 = (int *)FUN_549b_007a();
            return piVar14;
          case (int *)0x1:
            goto switchD_2000_7d1e_caseD_1;
          case (int *)0x2:
            uVar15 = *(int *)(iVar95 + -0xc) + *(int *)(iVar17 + 0x44) / 2;
            *(undefined2 *)(iVar95 + -0xc) = *(undefined2 *)(iVar17 + 0x24);
            uVar13 = *(int *)(iVar95 + -0xc) + *(int *)(iVar17 + 0x46) / 2;
            *(undefined2 *)(iVar95 + -0x14) = 0;
            *(undefined2 *)(iVar95 + -0x12) = 0;
            *(undefined2 *)(iVar95 + -0x10) = 0;
            *(undefined2 *)(iVar95 + -0xe) = 0;
            uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 8) >> 0x10);
            iVar17 = (int)*(undefined4 *)(iVar95 + 8);
            *(undefined2 *)(iVar95 + -0x18) = *(undefined2 *)(iVar17 + 0x22);
            *(undefined2 *)(iVar95 + -0x1a) = *(undefined2 *)(iVar17 + 0x24);
            *(undefined2 *)(iVar95 + -4) = *(undefined2 *)(iVar17 + 0x98);
            *(undefined2 *)(iVar95 + -0x16) = *(undefined2 *)(iVar17 + 0x96);
            *(int *)(iVar95 + -8) =
                 *(int *)(*(int *)(iVar95 + -0x16) * 6 + *(int *)(iVar95 + -4) + -6) +
                 *(int *)(iVar95 + -0x18);
            *(int *)(iVar95 + -6) =
                 *(int *)(*(int *)(iVar95 + -0x16) * 6 + *(int *)(iVar95 + -4) + -4) +
                 *(int *)(iVar95 + -0x1a);
            do {
              iVar17 = *(int *)(iVar95 + -0x16);
              *(int *)(iVar95 + -0x16) = *(int *)(iVar95 + -0x16) + -1;
              if (iVar17 == 0) {
                return (int *)0x0;
              }
              *(undefined2 *)(iVar95 + -0xc) = *(undefined2 *)(iVar95 + -8);
              *(undefined2 *)(iVar95 + -10) = *(undefined2 *)(iVar95 + -6);
              piVar14 = (int *)*(int *)(iVar95 + -4);
              *(int *)(iVar95 + -8) = *piVar14 + *(int *)(iVar95 + -0x18);
              *(int *)(iVar95 + -6) = piVar14[1] + *(int *)(iVar95 + -0x1a);
              *(int *)(iVar95 + -4) = *(int *)(iVar95 + -4) + 6;
              if ((((int)uVar15 < *(int *)(iVar95 + -0xc)) || (*(int *)(iVar95 + -8) < (int)uVar15))
                 && (((int)uVar15 < *(int *)(iVar95 + -8) || (*(int *)(iVar95 + -0xc) < (int)uVar15)
                     ))) {
                uVar110 = 0;
              }
              else {
                uVar110 = 1;
              }
              *(undefined2 *)(iVar95 + -0x20) = uVar110;
              if ((((int)uVar13 < *(int *)(iVar95 + -10)) || (*(int *)(iVar95 + -6) < (int)uVar13))
                 && (((int)uVar13 < *(int *)(iVar95 + -6) || (*(int *)(iVar95 + -10) < (int)uVar13))
                    )) {
                uVar110 = 0;
              }
              else {
                uVar110 = 1;
              }
              *(undefined2 *)(iVar95 + -0x22) = uVar110;
              if ((*(int *)(iVar95 + -0x22) != 0) || (*(int *)(iVar95 + -0x20) != 0)) {
                if ((*(int *)(iVar95 + -0x20) != 0) && (*(int *)(iVar95 + -0x22) == 0)) {
                  if ((int)uVar13 < *(int *)(iVar95 + -10)) {
                    *(undefined2 *)(iVar95 + -0x12) = 1;
                  }
                  else {
                    *(undefined2 *)(iVar95 + -0xe) = 1;
                  }
                }
                if ((*(int *)(iVar95 + -0x22) != 0) && (*(int *)(iVar95 + -0x20) == 0)) {
                  if ((int)uVar15 < *(int *)(iVar95 + -0xc)) {
                    *(undefined2 *)(iVar95 + -0x14) = 1;
                  }
                  else {
                    *(undefined2 *)(iVar95 + -0x10) = 1;
                  }
                }
                if ((*(int *)(iVar95 + -0x22) != 0) && (*(int *)(iVar95 + -0x20) != 0)) {
                  *(int *)(iVar95 + -0x1c) = *(int *)(iVar95 + -0xc) - *(int *)(iVar95 + -8);
                  *(int *)(iVar95 + -0x1e) = *(int *)(iVar95 + -10) - *(int *)(iVar95 + -6);
                  if (*(int *)(iVar95 + -0x1c) != 0) {
                    iVar17 = *(int *)(iVar95 + -0x1c);
                    *(int *)(puVar96 + -2) = iVar17 >> 0xf;
                    *(int *)(puVar96 + -4) = iVar17;
                    iVar17 = *(int *)(iVar95 + -0x1e);
                    *(int *)(puVar96 + -6) = (int)(iVar17 * uVar15) >> 0xf;
                    *(uint *)(puVar96 + -8) = iVar17 * uVar15;
                    *(undefined2 *)(puVar96 + -10) = uVar112;
                    piVar79 = (int *)(puVar96 + -0xc);
                    *(undefined2 *)(puVar96 + -0xc) = 0x950d;
                    uVar114 = FUN_1000_18f0();
                    piVar79[4] = (int)uVar114;
                    uVar9 = *(uint *)(iVar95 + -10);
                    piVar79[3] = (int)((ulong)uVar114 >> 0x10);
                    iVar17 = piVar79[3];
                    uVar10 = piVar79[4];
                    piVar79[4] = uVar10 + uVar9;
                    piVar79[3] = iVar17 + ((int)uVar9 >> 0xf) + (uint)CARRY2(uVar10,uVar9);
                    iVar17 = *(int *)(iVar95 + -0x1c);
                    piVar79[2] = iVar17 >> 0xf;
                    piVar79[1] = iVar17;
                    iVar17 = *(int *)(iVar95 + -0x1e);
                    iVar11 = *(int *)(iVar95 + -0xc);
                    *piVar79 = iVar17 * iVar11 >> 0xf;
                    piVar79[-1] = iVar17 * iVar11;
                    piVar79[-2] = 0x1000;
                    uVar112 = 0x1000;
                    piVar80 = piVar79 + -3;
                    piVar79[-3] = 0x952f;
                    uVar114 = FUN_1000_18f0();
                    puVar96 = (undefined1 *)((int)piVar80 + 0xe);
                    iVar17 = (*(int *)((int)piVar80 + 10) - (int)((ulong)uVar114 >> 0x10)) -
                             (uint)(*(uint *)((int)piVar80 + 0xc) < (uint)uVar114);
                    if (((int)uVar13 >> 0xf < iVar17) ||
                       (((int)uVar13 >> 0xf <= iVar17 &&
                        (uVar13 <= *(uint *)((int)piVar80 + 0xc) - (uint)uVar114)))) {
                      *(undefined2 *)(iVar95 + -0x12) = 1;
                    }
                    else {
                      *(undefined2 *)(iVar95 + -0xe) = 1;
                      puVar96 = (undefined1 *)((int)piVar80 + 0xe);
                    }
                  }
                  if (*(int *)(iVar95 + -0x1e) != 0) {
                    iVar17 = *(int *)(iVar95 + -0x1e);
                    *(int *)(puVar96 + -2) = iVar17 >> 0xf;
                    *(int *)(puVar96 + -4) = iVar17;
                    iVar17 = *(int *)(iVar95 + -0x1c);
                    *(int *)(puVar96 + -6) = (int)(iVar17 * uVar13) >> 0xf;
                    *(uint *)(puVar96 + -8) = iVar17 * uVar13;
                    *(undefined2 *)(puVar96 + -10) = uVar112;
                    piVar81 = (int *)(puVar96 + -0xc);
                    *(undefined2 *)(puVar96 + -0xc) = 0x9567;
                    uVar114 = FUN_1000_18f0();
                    piVar81[4] = (int)uVar114;
                    uVar9 = *(uint *)(iVar95 + -0xc);
                    piVar81[3] = (int)((ulong)uVar114 >> 0x10);
                    iVar17 = piVar81[3];
                    uVar10 = piVar81[4];
                    piVar81[4] = uVar10 + uVar9;
                    piVar81[3] = iVar17 + ((int)uVar9 >> 0xf) + (uint)CARRY2(uVar10,uVar9);
                    iVar17 = *(int *)(iVar95 + -0x1e);
                    piVar81[2] = iVar17 >> 0xf;
                    piVar81[1] = iVar17;
                    iVar17 = *(int *)(iVar95 + -0x1c);
                    iVar11 = *(int *)(iVar95 + -10);
                    *piVar81 = iVar17 * iVar11 >> 0xf;
                    piVar81[-1] = iVar17 * iVar11;
                    piVar81[-2] = 0x1000;
                    uVar112 = 0x1000;
                    piVar82 = piVar81 + -3;
                    piVar81[-3] = 0x9589;
                    uVar114 = FUN_1000_18f0();
                    puVar96 = (undefined1 *)((int)piVar82 + 0xe);
                    iVar17 = (*(int *)((int)piVar82 + 10) - (int)((ulong)uVar114 >> 0x10)) -
                             (uint)(*(uint *)((int)piVar82 + 0xc) < (uint)uVar114);
                    if (((int)uVar15 >> 0xf < iVar17) ||
                       (((int)uVar15 >> 0xf <= iVar17 &&
                        (uVar15 <= *(uint *)((int)piVar82 + 0xc) - (uint)uVar114)))) {
                      *(undefined2 *)(iVar95 + -0x14) = 1;
                    }
                    else {
                      *(undefined2 *)(iVar95 + -0x10) = 1;
                      puVar96 = (undefined1 *)((int)piVar82 + 0xe);
                    }
                  }
                }
              }
            } while ((((*(int *)(iVar95 + -0x10) == 0) || (*(int *)(iVar95 + -0x14) == 0)) ||
                     (*(int *)(iVar95 + -0xe) == 0)) || (*(int *)(iVar95 + -0x12) == 0));
            return (int *)0x1;
          }
          piVar2 = (int *)*(undefined2 *)(iVar95 + -0xc);
          *(uint *)(iVar95 + -0xc) = (uint)piVar14;
          *(uint *)(iVar95 + -0xe) = in_DX;
          iVar17 = *(int *)(iVar95 + -0x14);
          *(undefined2 *)(iVar95 + -0x10) = 0x2000;
          puVar97 = (undefined1 *)(iVar95 + -0x12);
          *(undefined2 *)(iVar95 + -0x12) = 0xfb0f;
          uVar13 = FUN_1000_180a();
          uVar15 = *(uint *)(puVar97 + 6);
          *(int *)(iVar95 + -0x1c) = (*(int *)(puVar97 + 4) - iVar17) - (uint)(uVar15 < uVar13);
          *(int *)(iVar95 + -0x1e) = uVar15 - uVar13;
          if (*(int *)(iVar95 + -0x1e) == 0 && *(int *)(iVar95 + -0x1c) == 0) {
            iVar17 = *piVar2;
            *(int *)(puVar97 + 6) = iVar17;
            *(int *)(puVar97 + 4) = iVar17 >> 0xf;
            uVar110 = *(undefined2 *)(iVar95 + -0x10);
            *(undefined2 *)(puVar97 + 6) = 0x1000;
            puVar104 = (undefined2 *)(puVar97 + 4);
            *(undefined2 *)(puVar97 + 4) = 0xfbb7;
            uVar112 = FUN_1000_180a();
            puVar104[1] = uVar112;
            iVar17 = piVar2[1];
            *puVar104 = uVar110;
            puVar104[-1] = iVar17;
            puVar104[-2] = iVar17 >> 0xf;
            iVar17 = *(int *)(iVar95 + -0x14);
            puVar104[-1] = 0x1000;
            puVar105 = puVar104 + -2;
            puVar104[-2] = 0xfbcc;
            uVar15 = FUN_1000_180a();
            puVar96 = (undefined1 *)((int)puVar105 + 8);
            if (*(uint *)((int)puVar105 + 6) + uVar15 != 0 ||
                *(int *)((int)puVar105 + 4) + iVar17 +
                (uint)CARRY2(*(uint *)((int)puVar105 + 6),uVar15) != 0) {
              *(undefined2 *)(iVar95 + -0x20) = 0;
              *(undefined2 *)(iVar95 + -0x22) = 0;
              puVar96 = (undefined1 *)((int)puVar105 + 8);
              goto LAB_2e67_157e;
            }
            *(int *)(iVar95 + -0x20) = piVar2[2];
            iVar17 = piVar2[3];
          }
          else {
            uVar110 = *(undefined2 *)(iVar95 + -8);
            *(undefined2 *)(puVar97 + 6) = 0x1000;
            puVar98 = (undefined2 *)(puVar97 + 4);
            *(undefined2 *)(puVar97 + 4) = 0xfb37;
            uVar112 = FUN_1000_180a();
            puVar98[1] = uVar112;
            *puVar98 = uVar110;
            iVar17 = *(int *)(iVar95 + -0x14);
            puVar98[-1] = 0x1000;
            piVar99 = puVar98 + -2;
            puVar98[-2] = 0xfb4a;
            uVar15 = FUN_1000_180a();
            iVar11 = piVar99[3] - uVar15;
            iVar17 = (piVar99[2] - iVar17) - (uint)((uint)piVar99[3] < uVar15);
            *(int *)(iVar95 + -0x24) = iVar17;
            *(int *)(iVar95 + -0x26) = iVar11;
            piVar99[3] = *(undefined2 *)(iVar95 + -0x1c);
            piVar99[2] = *(undefined2 *)(iVar95 + -0x1e);
            piVar99[1] = iVar17;
            *piVar99 = iVar11;
            piVar99[-1] = 0x1000;
            piVar100 = piVar99 + -2;
            piVar99[-2] = 0xfb63;
            uVar110 = FUN_1000_18f0();
            *(undefined2 *)(iVar95 + -0x20) = uVar110;
            uVar110 = *(undefined2 *)(iVar95 + -0x18);
            *(undefined2 *)((int)piVar100 + 8) = 0x1000;
            puVar101 = (undefined2 *)((int)piVar100 + 6);
            *(undefined2 *)((int)piVar100 + 6) = 0xfb77;
            uVar112 = FUN_1000_180a();
            puVar101[1] = uVar112;
            *puVar101 = uVar110;
            iVar17 = *(int *)(iVar95 + -0xc);
            puVar101[-1] = 0x1000;
            piVar102 = puVar101 + -2;
            puVar101[-2] = 0xfb8a;
            uVar15 = FUN_1000_180a();
            iVar11 = piVar102[3] - uVar15;
            iVar17 = (piVar102[2] - iVar17) - (uint)((uint)piVar102[3] < uVar15);
            *(int *)(iVar95 + -0x24) = iVar17;
            *(int *)(iVar95 + -0x26) = iVar11;
            piVar102[3] = *(undefined2 *)(iVar95 + -0x1c);
            piVar102[2] = *(undefined2 *)(iVar95 + -0x1e);
            piVar102[1] = iVar17;
            *piVar102 = iVar11;
            piVar102[-1] = 0x1000;
            piVar103 = piVar102 + -2;
            piVar102[-2] = 0xfba3;
            iVar17 = FUN_1000_18f0();
            puVar96 = (undefined1 *)((int)piVar103 + 10);
          }
          *(int *)(iVar95 + -0x22) = iVar17;
LAB_2e67_157e:
          puVar16 = (undefined2 *)*(int *)(iVar95 + 8);
          *puVar16 = *(undefined2 *)(iVar95 + -0x20);
          puVar16[1] = *(undefined2 *)(iVar95 + -0x22);
          *(int *)(puVar96 + -2) = piVar2[2];
          *(int *)(puVar96 + -4) = *piVar2;
          *(undefined2 *)(puVar96 + -6) = *(undefined2 *)(iVar95 + -0x20);
          *(undefined2 *)(puVar96 + -8) = 0x1000;
          puVar106 = (undefined2 *)(puVar96 + -10);
          *(undefined2 *)(puVar96 + -10) = 0xfc08;
          iVar17 = FUN_2e67_1398();
          if (iVar17 != 0) {
            puVar106[4] = unaff_DI[2];
            puVar106[3] = *unaff_DI;
            puVar106[2] = *(undefined2 *)(iVar95 + -0x20);
            puVar106[1] = 0x1000;
            *puVar106 = 0xfc1b;
            iVar17 = FUN_2e67_1398();
            if (iVar17 != 0) {
              puVar106[4] = piVar2[3];
              puVar106[3] = piVar2[1];
              puVar106[2] = *(undefined2 *)(iVar95 + -0x22);
              puVar106[1] = 0x1000;
              *puVar106 = 0xfc2f;
              iVar17 = FUN_2e67_1398();
              if (iVar17 != 0) {
                puVar106[4] = unaff_DI[3];
                puVar106[3] = unaff_DI[1];
                puVar106[2] = *(undefined2 *)(iVar95 + -0x22);
                puVar106[1] = 0x1000;
                *puVar106 = 0xfc43;
                iVar17 = FUN_2e67_1398();
                if (iVar17 != 0) {
                  return (int *)0x1;
                }
              }
            }
          }
          return (int *)0x0;
        }
      }
      else if (((piVar14 == (int *)0xcd) || (piVar14 == (int *)0x10f)) || (piVar14 == (int *)0x118))
      goto LAB_28eb_34f4;
LAB_28eb_356a:
      uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
      iVar17 = *(int *)(*(int *)((int)*(undefined4 *)(iVar95 + 4) + 8) * 2 + 0x68fe);
      if (iVar17 == 0) {
        uVar112 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
        iVar17 = (int)*(undefined4 *)(iVar95 + 4);
        *(undefined2 *)(iVar17 + 0x4a) = 0;
        *(undefined2 *)(iVar17 + 0x48) = 0;
        uVar110 = *(undefined2 *)(iVar17 + 0x48);
        *(undefined2 *)(iVar17 + 0x46) = *(undefined2 *)(iVar17 + 0x4a);
        *(undefined2 *)(iVar17 + 0x44) = uVar110;
      }
      else {
        *(undefined2 *)(iVar95 + -0xe) = unaff_SS;
        *(int *)(iVar95 + -0x10) = iVar95 + -10;
        *(undefined2 *)(iVar95 + -0x12) = *(undefined2 *)(*(int *)(iVar95 + 4) + 0x10);
        *(int *)(iVar95 + -0x14) = iVar17;
        *(undefined2 *)(iVar95 + -0x16) = 0x28eb;
        *(undefined2 *)(iVar95 + -0x18) = 0xc440;
        FUN_4551_03eb();
        uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
        iVar17 = (int)*(undefined4 *)(iVar95 + 4);
        *(undefined2 *)(iVar17 + 0x48) = *(undefined2 *)(iVar95 + -6);
        *(undefined2 *)(iVar17 + 0x4a) = *(undefined2 *)(iVar95 + -4);
        if ((*(byte *)(iVar17 + 0xf) & 0x10) == 0) {
          iVar17 = *(int *)(*(int *)((int)*(undefined4 *)(iVar95 + 4) + 8) * 2 + 0x302);
          uVar112 = *(undefined2 *)(iVar17 + 0x44);
          uVar110 = *(undefined2 *)(iVar17 + 0x42);
        }
        else {
          uVar112 = *(undefined2 *)(iVar17 + 0x4a);
          uVar110 = *(undefined2 *)(iVar17 + 0x48);
        }
        uVar111 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
        iVar17 = (int)*(undefined4 *)(iVar95 + 4);
        *(undefined2 *)(iVar17 + 0x46) = uVar112;
        *(undefined2 *)(iVar17 + 0x44) = uVar110;
        uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
        if ((*(int *)(*(int *)(*(int *)((int)*(undefined4 *)(iVar95 + 4) + 8) * 2 + 0x302) + 0x2a)
             != 0) ||
           (*(int *)(*(int *)(*(int *)(*(int *)(iVar95 + 4) + 8) * 2 + 0x302) + 0x2c) != 0)) {
          iVar17 = *(int *)(*(int *)((int)*(undefined4 *)(iVar95 + 4) + 8) * 2 + 0x302);
          uVar110 = *(undefined2 *)(iVar17 + 0x2c);
          piVar14 = (int *)*(undefined2 *)(iVar17 + 0x2a);
          goto LAB_28eb_3636;
        }
      }
      uVar112 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
      iVar17 = (int)*(undefined4 *)(iVar95 + 4);
      uVar110 = *(undefined2 *)(iVar17 + 0x46);
      piVar14 = (int *)*(undefined2 *)(iVar17 + 0x44);
LAB_28eb_3636:
      uVar112 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
      iVar17 = (int)*(undefined4 *)(iVar95 + 4);
      *(undefined2 *)(iVar17 + 0x56) = uVar110;
      *(undefined2 *)(iVar17 + 0x54) = piVar14;
      return piVar14;
    }
    goto LAB_28eb_34f4;
  }
  if (piVar14 == (int *)0x65) goto LAB_28eb_34f4;
  if (0x65 < (int)piVar14) {
    if (piVar14 != (int *)0x79) {
      if ((int)piVar14 < 0x7a) {
        if ((piVar14 == (int *)0x66) || (piVar14 == (int *)0x76)) goto LAB_28eb_34f4;
      }
      else if (piVar14 == (int *)0x7a) goto LAB_28eb_34f4;
      goto LAB_28eb_356a;
    }
    goto LAB_28eb_34f4;
  }
  piVar14 = piVar14 + -0x2c;
  if ((int *)0xc < piVar14) goto LAB_28eb_356a;
  puVar48 = (undefined2 *)((int)piVar14 * 2);
  switch(piVar14) {
  case (int *)0x0:
    *(byte *)((int)unaff_DI + iVar95 + 0x644) =
         *(byte *)((int)unaff_DI + iVar95 + 0x644) | (byte)in_CX;
code_r0x00029a58:
    if ((in_DX == *(uint *)(iVar95 + -0x26)) && (piVar14 == (int *)*(uint *)(iVar95 + -0x28))) {
LAB_28eb_0bb2:
      unaff_DI = (int *)((int)unaff_DI + -0x23);
      *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + -0x23;
      *(int *)(iVar95 + -0xe) = *(int *)(iVar95 + -0xe) + 0x23;
      *(int *)(iVar95 + -0x10) = *(int *)(iVar95 + -0x10) + 0x23;
    }
    break;
  case (int *)0x1:
    pcVar6 = DAT_554c_4d7e;
    *(undefined2 *)(iVar95 + -0xe) = 0x2000;
    *(undefined2 *)(iVar95 + -0x10) = 0x1ea;
    piVar14 = (int *)(*pcVar6)();
    return piVar14;
  case (int *)0x2:
    do {
    } while( true );
  case (int *)0x3:
    do {
      *(undefined1 *)((int)puVar48 + 0x95) = (char)piVar14;
      do {
        do {
          in_CX = in_CX + 1;
          if (1 < in_CX) {
            return piVar14;
          }
          bVar5 = *(byte *)(*(int *)((int)unaff_DI * 2 + 0x302) + in_CX + 0x20);
          piVar14 = (int *)CONCAT11((char)((uint)piVar14 >> 8),bVar5);
          *(byte *)(iVar95 + -3) = bVar5;
        } while (bVar5 == 0xff);
        uVar112 = *(undefined2 *)((uint)bVar5 * 4 + 0x64bb);
        uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 4) >> 0x10);
        iVar17 = (int)*(undefined4 *)(iVar95 + 4) + in_CX * 4;
        *(undefined2 *)(iVar17 + 0x86) = *(undefined2 *)((uint)bVar5 * 4 + 0x64bd);
        *(undefined2 *)(iVar17 + 0x84) = uVar112;
        piVar14 = (int *)((uint)*(byte *)(iVar95 + -3) * 4);
        puVar48 = (undefined2 *)*(undefined2 *)(iVar95 + 4);
        *(undefined2 *)((int)piVar14 + 0x64bd) = *(undefined2 *)(iVar95 + 6);
        *(undefined2 *)((int)piVar14 + 0x64bb) = puVar48;
      } while (in_CX != 0);
      piVar14 = (int *)CONCAT11((char)((uint)piVar14 >> 8),*(undefined1 *)(iVar95 + -3));
    } while( true );
  case (int *)0x4:
    *(undefined2 *)(iVar95 + -0xe) = 0x2000;
    piVar108 = (int *)(CONCAT22((int)((ulong)in_ESP >> 0x10),iVar95 + -0xe) + -2);
    *piVar108 = in_CX;
    piVar18 = (int *)piVar108;
    piVar19 = piVar18 + -1;
    piVar18[-1] = 0xd;
    DAT_554c_516f = (int *)FUN_2fc8_01f3();
    *(undefined2 *)((int)piVar19 + -2) = 0x1d;
    uVar110 = FUN_2fc8_01f3();
    puVar16 = (undefined2 *)*(undefined2 *)(iVar95 + 6);
    *(undefined2 *)*(undefined2 *)(iVar95 + 8) = uVar110;
    piVar14 = DAT_554c_516f;
    *puVar16 = DAT_554c_516f;
    return piVar14;
  case (int *)0x5:
    *(undefined2 *)(iVar95 + -0x26) = 0;
    *(undefined2 *)(iVar95 + -0x28) = 0;
    if (*(int *)(iVar95 + 4) != 0 || *(int *)(iVar95 + 6) != 0) {
      if ((((*(int *)(iVar95 + 6) != *(int *)(iVar95 + 10)) ||
           (*(int *)(iVar95 + 4) != *(int *)(iVar95 + 8))) &&
          ((*(int *)(iVar95 + 6) != *(int *)(iVar95 + -0x1e) ||
           (*(int *)(iVar95 + 4) != *(int *)(iVar95 + -0x20))))) &&
         ((*(int *)(iVar95 + 6) != *(int *)(iVar95 + -0x22) ||
          (*(int *)(iVar95 + 4) != *(int *)(iVar95 + -0x24))))) {
        in_DX = *(uint *)(iVar95 + 6);
        piVar14 = (int *)*(uint *)(iVar95 + 4);
        goto code_r0x00029a58;
      }
      goto LAB_28eb_0bb2;
    }
    break;
  case (int *)0x6:
    *(undefined2 *)(iVar95 + -0xe) = 0x2000;
    puVar74 = (undefined1 *)(iVar95 + -0x10);
    *(undefined2 *)(iVar95 + -0x10) = 0x5f06;
    uVar110 = FUN_1000_19bf();
    puVar73 = puVar74 + 4;
    *(undefined2 *)(iVar95 + -4) = uVar110;
    *(undefined2 *)(iVar95 + -0x3e) = 0;
    *(undefined2 *)(iVar95 + -0x40) = 0;
    while( true ) {
      if ((*(int *)(iVar95 + -0x42) <= *(int *)(iVar95 + -0x3e)) &&
         ((*(int *)(iVar95 + -0x42) < *(int *)(iVar95 + -0x3e) ||
          ((int *)*(uint *)(iVar95 + -0x44) < (int *)*(uint *)(iVar95 + -0x40))))) break;
      *(undefined2 *)(puVar73 + -2) = 0x1000;
      piVar75 = (int *)(puVar73 + -4);
      *(undefined2 *)(puVar73 + -4) = 0x5f24;
      uVar110 = FUN_1000_19bf();
      *(undefined2 *)(iVar95 + -10) = uVar110;
      piVar75[1] = 0x1000;
      *piVar75 = 0x5f35;
      uVar110 = FUN_1000_19bf();
      piVar77 = piVar75 + 2;
      *(undefined2 *)(iVar95 + -8) = uVar110;
      if ((*(int *)(iVar95 + -6) != *(int *)(iVar95 + -10)) ||
         (*(int *)(iVar95 + -4) != *(int *)(iVar95 + -8))) {
        piVar75[1] = *(undefined2 *)(iVar95 + 8);
        *piVar75 = iVar95 + -10;
        piVar75[-1] = iVar95 + -6;
        piVar75[-2] = 0x1000;
        piVar76 = piVar75 + -3;
        piVar75[-3] = 0x5f57;
        FUN_2424_1a04();
        piVar77 = (int *)((int)piVar76 + 10);
        *(undefined2 *)(iVar95 + -6) = *(undefined2 *)(iVar95 + -10);
        *(undefined2 *)(iVar95 + -4) = *(undefined2 *)(iVar95 + -8);
      }
      iVar17 = *(int *)(iVar95 + -0x3e);
      uVar15 = *(uint *)(iVar95 + -0x40);
      *(int *)((int)piVar77 + -2) = uVar15 * 2 + 1;
      *(int *)((int)piVar77 + -4) =
           (iVar17 << 1 | (uint)CARRY2(uVar15,uVar15)) + (uint)(0xfffe < uVar15 * 2);
      iVar17 = *(int *)(iVar95 + -0xe);
      *(undefined2 *)((int)piVar77 + -2) = 0x1000;
      piVar78 = (int *)((int)piVar77 + -4);
      *(undefined2 *)((int)piVar77 + -4) = 0x5f85;
      uVar9 = FUN_1000_180a();
      uVar13 = *(uint *)(iVar95 + -0x18);
      uVar10 = uVar9 + *(uint *)(iVar95 + -0x18);
      iVar11 = *(int *)(iVar95 + -0x16);
      puVar1 = (uint *)(iVar95 + -0x20);
      uVar15 = *puVar1;
      *puVar1 = *puVar1 + uVar10;
      *(int *)(iVar95 + -0x1e) =
           *(int *)(iVar95 + -0x1e) + iVar17 + iVar11 + (uint)CARRY2(uVar9,uVar13) +
           (uint)CARRY2(uVar15,uVar10);
      iVar17 = *(int *)(iVar95 + -0x3e);
      uVar15 = *(uint *)(iVar95 + -0x40);
      piVar78[1] = uVar15 * 2 + 1;
      *piVar78 = (iVar17 << 1 | (uint)CARRY2(uVar15,uVar15)) + (uint)(0xfffe < uVar15 * 2);
      iVar17 = *(int *)(iVar95 + -0x12);
      piVar78[1] = 0x1000;
      *piVar78 = 0x5fb0;
      uVar9 = FUN_1000_180a();
      puVar73 = (undefined1 *)((int)piVar78 + 4);
      uVar13 = *(uint *)(iVar95 + -0x1c);
      uVar10 = uVar9 + *(uint *)(iVar95 + -0x1c);
      iVar11 = *(int *)(iVar95 + -0x1a);
      puVar1 = (uint *)(iVar95 + -0x24);
      uVar15 = *puVar1;
      *puVar1 = *puVar1 + uVar10;
      *(int *)(iVar95 + -0x22) =
           *(int *)(iVar95 + -0x22) + iVar17 + iVar11 + (uint)CARRY2(uVar9,uVar13) +
           (uint)CARRY2(uVar15,uVar10);
      puVar1 = (uint *)(iVar95 + -0x40);
      uVar15 = *puVar1;
      *puVar1 = *puVar1 + 1;
      *(int *)(iVar95 + -0x3e) = *(int *)(iVar95 + -0x3e) + (uint)(0xfffe < uVar15);
    }
    return (int *)*(uint *)(iVar95 + -0x40);
  case (int *)0x7:
    uVar110 = *(undefined2 *)(iVar95 + -0xe);
    ((undefined2 *)&DAT_5b41_25d8)[(int)piVar14 * 2] = *(undefined2 *)(iVar95 + -0xc);
    ((undefined2 *)&DAT_5b41_25d6)[(int)piVar14 * 2] = uVar110;
    *(undefined2 *)(iVar95 + -0xe) = *(undefined2 *)(iVar95 + -8);
    *(undefined2 *)(iVar95 + -0x10) = 0x2000;
    puVar27 = (undefined2 *)(iVar95 + -0x12);
    *(undefined2 *)(iVar95 + -0x12) = 0x1ab6;
    FUN_28eb_29db();
    puVar29 = puVar27 + 3;
    puVar16 = puVar27 + 3;
    if (*(int *)(iVar95 + -10) != 0) {
      if (*(int *)(iVar95 + -0xe) != 0 || *(int *)(iVar95 + -0xc) != 0) {
        puVar27[2] = *(undefined2 *)(iVar95 + -0xc);
        puVar27[1] = *(undefined2 *)(iVar95 + -0xe);
        *puVar27 = 0x2000;
        puVar28 = puVar27 + -1;
        puVar27[-1] = 0x1ad5;
        func_0x0002fdf5();
        puVar29 = (undefined2 *)((int)puVar28 + 4);
      }
      unaff_SI = (int *)0x0;
      puVar16 = puVar29;
    }
    if (*(int *)(iVar95 + -4) != 0) {
      *(undefined2 *)((int)puVar16 + -2) = unaff_DI;
      *(undefined2 *)((int)puVar16 + -4) = 0x2000;
      *(undefined2 *)((int)puVar16 + -6) = 0x1c0f;
      FUN_1a9e_6e73();
    }
    return unaff_SI;
  case (int *)0x8:
    in(in_DX);
    *(undefined2 *)(iVar95 + -0xe) = uVar110;
    *(undefined2 *)(iVar95 + -0x10) = unaff_SI;
    *(undefined2 *)(iVar95 + -0x12) = unaff_DI;
    puVar96 = (undefined1 *)*(undefined2 *)(iVar95 + 4);
    puVar16 = (undefined2 *)*(int *)(iVar95 + 4);
    *(undefined2 *)(iVar95 + -4) = *puVar16;
    uVar110 = *(undefined2 *)((int)puVar16 + 0x1b);
    *(undefined2 *)(iVar95 + -6) = *(undefined2 *)((int)puVar16 + 0x1d);
    *(undefined2 *)(iVar95 + -8) = uVar110;
    iVar17 = 0x43;
    while (0 < iVar17) {
      *puVar96 = 0;
      puVar96 = puVar96 + 1;
      iVar17 = iVar17 + -1;
    }
    puVar16 = (undefined2 *)*(int *)(iVar95 + 4);
    uVar110 = *(undefined2 *)(iVar95 + -8);
    *(undefined2 *)((int)puVar16 + 0x1d) = *(undefined2 *)(iVar95 + -6);
    *(undefined2 *)((int)puVar16 + 0x1b) = uVar110;
    uVar110 = *(undefined2 *)(iVar95 + -4);
    *puVar16 = uVar110;
    *(undefined2 *)(iVar95 + -0x14) = uVar110;
    *(undefined2 *)(iVar95 + -0x16) = 0x2000;
    *(undefined2 *)(iVar95 + -0x18) = 0x12db;
    piVar14 = (int *)FUN_1000_0fc7();
    return piVar14;
  case (int *)0x9:
    do {
      *(undefined2 *)(puVar90 + -2) = *(undefined2 *)(iVar95 + -8);
      *(undefined2 *)(puVar90 + -4) = *(undefined2 *)(iVar95 + -10);
      *(uint *)(puVar90 + -6) = DAT_5b41_04ee;
      *(undefined2 *)(puVar90 + -8) = DAT_5b41_04ec;
      *(undefined2 *)(puVar90 + -10) = 0x2000;
      puVar91 = puVar90 + -0xc;
      *(undefined2 *)(puVar90 + -0xc) = 0x9e71;
      DAT_5b41_04ec = FUN_28eb_0728();
      DAT_5b41_04ee = in_DX;
      puVar16 = (undefined2 *)(puVar91 + 0xc);
LAB_28eb_10f9:
      do {
        *(undefined2 *)((int)puVar16 + -2) = 0x1000;
        *(undefined2 *)((int)puVar16 + -4) = *(undefined2 *)(iVar95 + -4);
        *(undefined2 *)((int)puVar16 + -6) = *(undefined2 *)(iVar95 + -6);
        *(undefined2 *)((int)puVar16 + -8) = 0x2000;
        puVar94 = (undefined2 *)((int)puVar16 + -10);
        *(undefined2 *)((int)puVar16 + -10) = 0x9fb7;
        uVar110 = FUN_28eb_32d8();
        *(uint *)(iVar95 + -4) = in_DX;
        *(undefined2 *)(iVar95 + -6) = uVar110;
        if (*(int *)(iVar95 + -6) == 0 && *(int *)(iVar95 + -4) == 0) {
          if (*(int *)(iVar95 + -0xe) != 0 || *(int *)(iVar95 + -0xc) != 0) {
            return (int *)*(undefined2 *)(iVar95 + -0xe);
          }
          return (int *)0x0;
        }
        puVar94[4] = *(undefined2 *)(iVar95 + -4);
        puVar94[3] = *(undefined2 *)(iVar95 + -6);
        puVar94[2] = *(undefined2 *)(iVar95 + 6);
        puVar94[1] = *(undefined2 *)(iVar95 + 4);
        *puVar94 = 0x2000;
        puVar83 = puVar94 + -1;
        puVar94[-1] = 0x9cc5;
        iVar17 = FUN_28eb_0a36();
        puVar16 = puVar83 + 6;
        *(uint *)(iVar95 + -8) = in_DX;
        *(int *)(iVar95 + -10) = iVar17;
        if ((((iVar17 != 0 || *(int *)(iVar95 + -8) != 0) &&
             ((*(byte *)((int)*(undefined4 *)(iVar95 + -10) + 0xb) & 0x80) != 0)) &&
            (iRam000557bc != 3)) && (*(int *)(iVar95 + 4) != 0 || *(int *)(iVar95 + 6) != 0)) {
          in_DX = *(uint *)(iVar95 + 6);
          if ((in_DX != *(uint *)(iVar95 + -8)) || (*(int *)(iVar95 + 4) != *(int *)(iVar95 + -10)))
          {
            *(undefined2 *)(iVar95 + -8) = 0;
            *(undefined2 *)(iVar95 + -10) = 0;
          }
        }
        if (((*(int *)(iVar95 + -10) != 0 || *(int *)(iVar95 + -8) != 0) &&
            (*(int *)((int)*(undefined4 *)(iVar95 + -10) + 0x98) == 0)) &&
           ((*(int *)(iVar95 + -0xe) != 0 || *(int *)(iVar95 + -0xc) != 0 &&
            (*(int *)((int)*(undefined4 *)(iVar95 + -0xe) + 0x98) == 0)))) {
          uVar15 = in_DX;
          if (*(int *)(iVar95 + -0xe) != 0 || *(int *)(iVar95 + -0xc) != 0) {
            uVar15 = *(uint *)(iVar95 + -0xc);
            if ((uVar15 == DAT_5b41_0567._2_2_) && (*(int *)(iVar95 + -0xe) == (int)DAT_5b41_0567))
            {
              puVar83[5] = *(undefined2 *)(iVar95 + -8);
              puVar83[4] = *(undefined2 *)(iVar95 + -10);
              puVar83[3] = 0x2000;
              puVar84 = puVar83 + 2;
              puVar83[2] = 0x9d5c;
              uVar110 = FUN_28eb_0d77();
              puVar84[3] = uVar110;
              puVar84[2] = uVar15;
              puVar84[1] = *(undefined2 *)(iVar95 + -0xc);
              *puVar84 = *(undefined2 *)(iVar95 + -0xe);
              puVar84[-1] = 0x2000;
              puVar85 = puVar84 + -2;
              puVar84[-2] = 0x9d6b;
              uVar13 = FUN_28eb_0d77();
              in_DX = *(uint *)((int)puVar85 + 10);
              puVar16 = (undefined2 *)((int)puVar85 + 0xc);
              if ((*(int *)((int)puVar85 + 8) <= (int)uVar15) &&
                 ((*(int *)((int)puVar85 + 8) < (int)uVar15 ||
                  (puVar16 = (undefined2 *)((int)puVar85 + 0xc), in_DX < uVar13)))) {
                in_DX = *(uint *)(iVar95 + -8);
                DAT_5b41_04ec = *(undefined2 *)(iVar95 + -10);
                DAT_5b41_04ee = in_DX;
                puVar16 = (undefined2 *)((int)puVar85 + 0xc);
              }
              goto LAB_28eb_10f9;
            }
          }
          if (*(int *)(iVar95 + -10) == 0 && *(int *)(iVar95 + -8) == 0) {
LAB_28eb_0f34:
            puVar83[5] = *(undefined2 *)(iVar95 + -8);
            puVar83[4] = *(undefined2 *)(iVar95 + -10);
            puVar83[3] = 0x2000;
            puVar88 = puVar83 + 2;
            puVar83[2] = 0x9dee;
            uVar110 = FUN_28eb_0d77();
            puVar88[3] = uVar110;
            puVar88[2] = uVar15;
            puVar88[1] = *(undefined2 *)(iVar95 + -0xc);
            *puVar88 = *(undefined2 *)(iVar95 + -0xe);
            puVar88[-1] = 0x2000;
            puVar89 = puVar88 + -2;
            puVar88[-2] = 0x9dfd;
            uVar13 = FUN_28eb_0d77();
            in_DX = *(uint *)((int)puVar89 + 10);
            puVar92 = (undefined1 *)((int)puVar89 + 0xc);
            puVar16 = (undefined2 *)((int)puVar89 + 0xc);
            if (((int)uVar15 < *(int *)((int)puVar89 + 8)) ||
               (((int)uVar15 <= *(int *)((int)puVar89 + 8) &&
                (puVar16 = (undefined2 *)((int)puVar89 + 0xc), uVar13 <= in_DX))))
            goto LAB_28eb_10f9;
            in_DX = *(uint *)(iVar95 + -8);
            uVar110 = *(undefined2 *)(iVar95 + -10);
            DAT_5b41_04ec = uVar110;
            DAT_5b41_04ee = in_DX;
          }
          else {
            uVar15 = *(uint *)(iVar95 + -8);
            iVar17 = *(int *)(iVar95 + -10);
            if ((uVar15 != DAT_5b41_0567._2_2_) || (iVar17 != (int)DAT_5b41_0567))
            goto LAB_28eb_0f34;
            puVar83[5] = uVar15;
            puVar83[4] = iVar17;
            puVar83[3] = 0x2000;
            puVar86 = puVar83 + 2;
            puVar83[2] = 0x9db0;
            uVar110 = FUN_28eb_0d77();
            puVar86[3] = uVar110;
            puVar86[2] = uVar15;
            puVar86[1] = *(undefined2 *)(iVar95 + -0xc);
            *puVar86 = *(undefined2 *)(iVar95 + -0xe);
            puVar86[-1] = 0x2000;
            puVar87 = puVar86 + -2;
            puVar86[-2] = 0x9dbf;
            uVar13 = FUN_28eb_0d77();
            puVar92 = (undefined1 *)((int)puVar87 + 0xc);
            if ((*(int *)((int)puVar87 + 8) <= (int)uVar15) &&
               ((*(int *)((int)puVar87 + 8) < (int)uVar15 || (*(uint *)((int)puVar87 + 10) < uVar13)
                ))) {
              DAT_5b41_04ee = *(uint *)(iVar95 + -8);
              DAT_5b41_04ec = *(undefined2 *)(iVar95 + -10);
            }
            in_DX = *(uint *)(iVar95 + -8);
            uVar110 = *(undefined2 *)(iVar95 + -10);
          }
LAB_28eb_10f3:
          *(uint *)(iVar95 + -0xc) = in_DX;
          *(undefined2 *)(iVar95 + -0xe) = uVar110;
          puVar16 = (undefined2 *)puVar92;
          goto LAB_28eb_10f9;
        }
        if (*(int *)(iVar95 + -10) == 0 && *(int *)(iVar95 + -8) == 0) goto LAB_28eb_10f9;
        if (*(int *)(iVar95 + -0xe) == 0 && *(int *)(iVar95 + -0xc) == 0) {
LAB_28eb_0fce:
          in_DX = *(uint *)(iVar95 + -8);
          if ((in_DX == DAT_5b41_0567._2_2_) && (*(int *)(iVar95 + -10) == (int)DAT_5b41_0567)) {
            puVar83[5] = *(undefined2 *)(iVar95 + -0xc);
            puVar83[4] = *(undefined2 *)(iVar95 + -0xe);
            puVar83[3] = 0;
            puVar83[2] = 0;
            puVar83[1] = 0x2000;
            *puVar83 = 0x9e9e;
            iVar17 = FUN_28eb_03ff();
            puVar92 = (undefined1 *)((int)puVar83 + 0xc);
            if (iVar17 == 0) {
              DAT_5b41_04ee = *(uint *)(iVar95 + -8);
              DAT_5b41_04ec = *(undefined2 *)(iVar95 + -10);
            }
            in_DX = *(uint *)(iVar95 + -8);
            uVar110 = *(undefined2 *)(iVar95 + -10);
            goto LAB_28eb_10f3;
          }
          if (*(int *)(iVar95 + -0xe) != 0 || *(int *)(iVar95 + -0xc) != 0) {
            uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + -10) >> 0x10);
            iVar17 = (int)*(undefined4 *)(iVar95 + -10);
            if ((*(byte *)(iVar17 + 0xb) & 0x80) == 0) {
              if (*(int *)(iVar17 + 0x98) == 0) {
LAB_28eb_1038:
                puVar93 = (undefined1 *)((int)puVar83 + 0xc);
                in_DX = *(uint *)(iVar95 + -8);
                DAT_5b41_04ec = *(undefined2 *)(iVar95 + -10);
              }
              else {
                puVar83[5] = *(undefined2 *)(iVar95 + -8);
                puVar83[4] = iVar17;
                puVar83[3] = 0;
                puVar83[2] = 0;
                puVar83[1] = 0x2000;
                *puVar83 = 0x9ee1;
                iVar17 = FUN_28eb_03ff();
                puVar16 = puVar83 + 6;
                if (iVar17 != 0) goto LAB_28eb_1038;
                iVar17 = (int)*(undefined4 *)(iVar95 + -0xe);
                if (*(int *)(iVar17 + 0x98) == 0) goto LAB_28eb_10f9;
                puVar83[5] = *(undefined2 *)(iVar95 + -0xc);
                puVar83[4] = iVar17;
                puVar83[3] = 0;
                puVar83[2] = 0;
                puVar83[1] = 0x2000;
                *puVar83 = 0x9f0a;
                iVar17 = FUN_28eb_03ff();
                puVar16 = puVar83 + 6;
                if (iVar17 != 0) goto LAB_28eb_10f9;
                puVar83[5] = *(undefined2 *)(iVar95 + -8);
                puVar83[4] = *(undefined2 *)(iVar95 + -10);
                puVar83[3] = *(undefined2 *)(iVar95 + -0xc);
                puVar83[2] = *(undefined2 *)(iVar95 + -0xe);
                puVar83[1] = 0x2000;
                *puVar83 = 0x9f24;
                DAT_5b41_04ec = FUN_28eb_0728();
                puVar93 = (undefined1 *)((int)puVar83 + 0xc);
              }
              *(uint *)(iVar95 + -0xc) = in_DX;
              *(undefined2 *)(iVar95 + -0xe) = DAT_5b41_04ec;
              DAT_5b41_04ee = in_DX;
              puVar16 = (undefined2 *)puVar93;
              goto LAB_28eb_10f9;
            }
          }
          in_DX = *(uint *)(iVar95 + -8);
          DAT_5b41_04ec = *(undefined2 *)(iVar95 + -10);
          DAT_5b41_04ee = in_DX;
          if ((((((*(byte *)((int)*(undefined4 *)(iVar95 + -10) + 0xb) & 0x80) == 0) ||
                (iRam000557bc == 3)) ||
               (((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0 &&
                (*(int *)((int)DAT_5b41_0567 + 8) == 10)))) ||
              (((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0 &&
               (*(int *)((int)DAT_5b41_0567 + 8) == 0x4c)))) ||
             ((puVar16 = puVar83 + 6, (int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0 &&
              (puVar16 = puVar83 + 6, *(int *)((int)DAT_5b41_0567 + 8) == 8)))) {
            puVar83[5] = *(undefined2 *)(iVar95 + -8);
            puVar83[4] = *(undefined2 *)(iVar95 + -10);
            puVar83[3] = *(undefined2 *)(iVar95 + -0xc);
            puVar83[2] = *(undefined2 *)(iVar95 + -0xe);
            puVar83[1] = 0x2000;
            *puVar83 = 0x9fa0;
            uVar110 = FUN_28eb_0728();
            puVar92 = (undefined1 *)((int)puVar83 + 0xc);
            goto LAB_28eb_10f3;
          }
          goto LAB_28eb_10f9;
        }
        in_DX = *(uint *)(iVar95 + -0xc);
        if ((in_DX != DAT_5b41_0567._2_2_) || (*(int *)(iVar95 + -0xe) != (int)DAT_5b41_0567))
        goto LAB_28eb_0fce;
        puVar83[5] = *(undefined2 *)(iVar95 + -8);
        puVar83[4] = *(undefined2 *)(iVar95 + -10);
        puVar83[3] = 0;
        puVar83[2] = 0;
        puVar83[1] = 0x2000;
        *puVar83 = 0x9e55;
        iVar17 = FUN_28eb_03ff();
        puVar90 = (undefined1 *)((int)puVar83 + 0xc);
        puVar16 = (undefined2 *)((int)puVar83 + 0xc);
      } while (iVar17 == 0);
    } while( true );
  case (int *)0xa:
    puVar1 = (uint *)((int)puVar48 + (int)unaff_SI);
    piVar2 = (int *)*puVar1;
    *puVar1 = *puVar1 - (int)unaff_DI;
    uVar112 = in(in_DX);
    bVar5 = 9 < ((byte)uVar112 & 0xf) |
            9 < (((char)piVar14 + -0x38) - (piVar2 < unaff_DI) & 0xfU) | in_AF;
    if (in_CX == 1 || (byte)in_CX == (byte)((uint)puVar48 >> 8)) {
      bVar8 = ((byte)uVar112 + bVar5 * '\x06' & 0xf) % 0x37;
      puVar107 = (undefined2 *)(iVar95 + -0xe);
      *(int *)(iVar95 + -0xe) = iVar95 + -2;
      cVar7 = '\x16';
      do {
        puVar16 = puVar16 + -1;
        puVar107 = puVar107 + -1;
        *puVar107 = *puVar16;
        cVar7 = cVar7 + -1;
      } while ('\0' < cVar7);
      *(int *)(iVar95 + -0x3c) = iVar95 + -0xe;
      bVar5 = 9 < (bVar8 & 0xf) | bVar5;
      _DAT_5000_eaf7 = CONCAT11(bVar5,bVar8 + bVar5 * '\x06') & 0xff0f;
      uVar4 = *(undefined1 *)puVar48;
      if (((int)(uint)bVar8 < *unaff_DI) && (SBORROW2((uint)bVar8,*unaff_DI))) {
        *(undefined2 *)(iVar95 + 0x448b) = unaff_DI + 1;
        *(uint *)((int)puVar48 + -1) = *(uint *)((int)puVar48 + -1) ^ (uint)unaff_SI;
        DAT_554c_36f1 = DAT_554c_36f1 + '\x01';
        puVar16 = (undefined2 *)in(0x36);
        *(undefined1 *)(unaff_DI + 1) = *(undefined1 *)0xb136;
        *(undefined2 *)0x367c = puVar16;
        out(*puVar16,CONCAT11(uVar4,(char)in_DX));
      }
    }
    else {
      out(*unaff_SI,in_DX);
    }
    piVar14 = (int *)FUN_28eb_4cfc();
    return piVar14;
  case (int *)0xb:
    while( true ) {
      puVar48[1] = piVar14;
      puVar48[2] = 0xfffe;
      unaff_SI = unaff_SI + 1;
      if (*unaff_SI == 0) break;
      *(int *)(iVar95 + -8) = DAT_5b41_2839;
      *(int *)(puVar34 + -2) = (int)DAT_5b41_2837 >> 4;
      DAT_5b41_2839 = *(int *)(iVar95 + -8) + *(int *)(puVar34 + -2);
      *(uint *)(puVar34 + -2) = DAT_5b41_2837 & 0xf;
      uVar15 = *(uint *)(puVar34 + -2);
      DAT_5b41_2837 = uVar15;
      *(int *)(iVar95 + -4) = DAT_5b41_2839;
      *(uint *)(iVar95 + -6) = uVar15;
      if (DAT_554c_42df == '\0') {
        *(int *)(iVar95 + -0xc) = *(int *)(*unaff_SI + 6) * *(int *)(*unaff_SI + 8);
        *(undefined2 *)(puVar34 + -2) = 0;
        *(undefined2 *)(puVar34 + -4) = 0;
        *(undefined2 *)(puVar34 + -6) = 0;
        *(undefined2 *)(puVar34 + -8) = *(undefined2 *)(iVar95 + -0xc);
        *(undefined2 *)(puVar34 + -10) = 0x2000;
        puVar30 = (undefined2 *)(puVar34 + -0xc);
        *(undefined2 *)(puVar34 + -0xc) = 0x1fcc;
        uVar114 = FUN_2fc8_00fc();
        *(undefined2 *)(iVar95 + -0xe) = (int)((ulong)uVar114 >> 0x10);
        *(undefined2 *)(iVar95 + -0x10) = (int)uVar114;
        *(uint *)(iVar95 + -0xc) = *(uint *)(iVar95 + -0xc) >> 1;
        *(uint *)(iVar95 + -0xc) = *(uint *)(iVar95 + -0xc) >> 1;
        *(uint *)(iVar95 + -0xc) = *(uint *)(iVar95 + -0xc) >> 1;
        puVar30[3] = *(undefined2 *)(iVar95 + -0xc);
        uVar110 = *(undefined2 *)*unaff_SI;
        puVar30[2] = ((undefined2 *)*unaff_SI)[1];
        puVar30[1] = uVar110;
        puVar30[1] = puVar30[1];
        *puVar30 = *(undefined2 *)(iVar95 + -0xe);
        puVar30[-1] = *(undefined2 *)(iVar95 + -0x10);
        puVar30[-2] = 0x2000;
        puVar31 = puVar30 + -3;
        puVar30[-3] = 0x1ff9;
        FUN_1a9e_74bc();
        puVar16 = (undefined2 *)*unaff_SI;
        *puVar16 = *(undefined2 *)(iVar95 + -0xe);
        puVar16[1] = *(undefined2 *)(iVar95 + -0x10);
        *(int *)((int)puVar31 + 0xc) = (int)puVar16;
        *(undefined2 *)((int)puVar31 + 10) = 0x2000;
        puVar32 = (undefined2 *)((int)puVar31 + 8);
        *(undefined2 *)((int)puVar31 + 8) = 0x200f;
        FUN_1a9e_7911();
        puVar32[2] = *(undefined2 *)(iVar95 + -0xe);
        puVar32[1] = *(undefined2 *)(iVar95 + -0x10);
        *puVar32 = 0x2000;
        puVar33 = puVar32 + -1;
        puVar32[-1] = 0x201d;
        func_0x0002fdf5();
        puVar34 = (undefined1 *)((int)puVar33 + 4);
      }
      else {
        *(int *)(puVar34 + -2) = *unaff_SI;
        *(undefined2 *)(puVar34 + -4) = 0x2000;
        puVar35 = puVar34 + -6;
        *(undefined2 *)(puVar34 + -6) = 0x2029;
        FUN_1a9e_7911();
        puVar34 = puVar35 + 6;
      }
      puVar48 = (undefined2 *)*unaff_SI;
      *puVar48 = *(undefined2 *)(iVar95 + -4);
      piVar14 = (int *)*(uint *)(iVar95 + -6);
    }
    *(int *)(iVar95 + -8) = DAT_5b41_2839 - DAT_5b41_2835;
    iVar17 = DAT_5b41_2837 - DAT_5b41_2833;
    DAT_5b41_282f = *(int *)(iVar95 + -8) + (iVar17 + 0xf >> 4);
    *(undefined2 *)(iVar95 + -10) = *(undefined2 *)*(undefined2 *)*(undefined2 *)(iVar95 + 4);
    pcVar6 = (code *)swi(0x21);
    (*pcVar6)();
    *(undefined2 *)(puVar34 + -2) = DAT_5b41_283f;
    *(undefined2 *)(puVar34 + -4) = 0x2000;
    *(undefined2 *)(puVar34 + -6) = 0x208c;
    FUN_1000_130c();
    return (int *)(*(int *)(iVar95 + -8) * 0x10 + iVar17);
  case (int *)0xc:
    goto switchD_2000_c347_caseD_c;
  }
  if ((int)unaff_DI <= *(int *)(iVar95 + -8)) {
    piVar14 = (int *)*(uint *)(iVar95 + -4);
switchD_2000_c347_caseD_c:
    *(int *)((int)unaff_DI + iVar95 + -0x1bb) = *(int *)((int)unaff_DI + iVar95 + -0x1bb) + in_CX;
    if ((((int)piVar14 < *(int *)(iVar95 + -0xe)) &&
        (*(int *)(iVar95 + -0xc) <= *(int *)(iVar95 + -10))) &&
       (*(int *)(iVar95 + -6) < *(int *)(iVar95 + -0x10))) {
      if ((*(int *)(iVar95 + -0x18) != 0) && (DAT_5b41_0939 != 9)) {
        uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 8) >> 0x10);
        iVar11 = (int)*(undefined4 *)(iVar95 + 8);
        iVar17 = ((uint)*(byte *)(iVar11 + 0x5a) + *(int *)(iVar95 + -0x16)) -
                 *(int *)(iVar11 + 0x5c);
        *(int *)(iVar95 + -0xc) =
             ((uint)*(byte *)(iVar11 + 0x5b) + *(int *)(iVar95 + -0x14)) - *(int *)(iVar11 + 0x5c);
        *(int *)(iVar95 + -0xe) = *(int *)(iVar11 + 0x5c) * 2 + iVar17;
        *(int *)(iVar95 + -0x10) = *(int *)(iVar11 + 0x5c) * 2 + *(int *)(iVar95 + -0xc);
        if ((*(int *)(*(int *)(iVar95 + -0x18) + 4) == *(int *)(iVar95 + 6)) &&
           (*(int *)(*(int *)(iVar95 + -0x18) + 2) == *(int *)(iVar95 + 4))) {
          iVar17 = iVar17 + -0x23;
          *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + -0x23;
          *(int *)(iVar95 + -0xe) = *(int *)(iVar95 + -0xe) + 0x23;
        }
        if (((iVar17 <= *(int *)(iVar95 + -8)) && (*(int *)(iVar95 + -4) < *(int *)(iVar95 + -0xe)))
           && ((*(int *)(iVar95 + -0xc) <= *(int *)(iVar95 + -10) &&
               (*(int *)(iVar95 + -6) < *(int *)(iVar95 + -0x10))))) {
          iVar17 = *(int *)(iVar95 + -0x18);
          if ((*(int *)(iVar17 + 8) == *(int *)(iVar95 + 10)) &&
             (*(int *)(iVar17 + 6) == *(int *)(iVar95 + 8))) {
            uVar110 = *(undefined2 *)(iVar17 + 10);
            *(undefined2 *)(iVar17 + 8) = *(undefined2 *)(iVar17 + 0xc);
            *(undefined2 *)(iVar17 + 6) = uVar110;
            uVar110 = *(undefined2 *)(iVar95 + 8);
            *(undefined2 *)(iVar17 + 0xc) = *(undefined2 *)(iVar95 + 10);
            *(undefined2 *)(iVar17 + 10) = uVar110;
          }
          return (int *)*(undefined2 *)(*(int *)(iVar95 + -0x18) + 2);
        }
      }
      piVar14 = (int *)*(undefined2 *)(iVar95 + -0x1a);
      *(undefined2 *)(iVar95 + -0x12) = 0;
      do {
        if (1 < *(int *)(iVar95 + -0x12)) {
          return (int *)*(undefined2 *)(iVar95 + 8);
        }
        if ((piVar14 != (int *)0x0) && (DAT_5b41_0939 != 9)) {
          uVar110 = (undefined2)((ulong)*(undefined4 *)(iVar95 + 8) >> 0x10);
          iVar17 = (int)*(undefined4 *)(iVar95 + 8);
          if (*(int *)(iVar17 + 8) != 7) {
            iVar17 = iVar17 + *(int *)(iVar95 + -0x12) * 2;
            iVar11 = (int)*(char *)(iVar17 + 0x7a) + *(int *)(iVar95 + -0x16);
            iVar12 = iVar11 + -8;
            *(int *)(iVar95 + -0xc) = (int)*(char *)(iVar17 + 0x7b) + *(int *)(iVar95 + -0x14) + -4;
            *(int *)(iVar95 + -0xe) = iVar11 + 8;
            *(int *)(iVar95 + -0x10) = *(int *)(iVar95 + -0xc) + 8;
            if ((piVar14[1] == *(int *)(iVar95 + 6)) && (*piVar14 == *(int *)(iVar95 + 4))) {
              iVar12 = iVar11 + -0x2b;
              *(int *)(iVar95 + -0xc) = *(int *)(iVar95 + -0xc) + -0x23;
              *(int *)(iVar95 + -0xe) = *(int *)(iVar95 + -0xe) + 0x23;
            }
            if ((((iVar12 <= *(int *)(iVar95 + -8)) &&
                 (*(int *)(iVar95 + -4) < *(int *)(iVar95 + -0xe))) &&
                (*(int *)(iVar95 + -0xc) <= *(int *)(iVar95 + -10))) &&
               (*(int *)(iVar95 + -6) < *(int *)(iVar95 + -0x10))) {
              if ((piVar14[3] == *(int *)(iVar95 + 10)) && (piVar14[2] == *(int *)(iVar95 + 8))) {
                *(undefined2 *)(iVar95 + -0xe) = piVar14;
                *(undefined2 *)(iVar95 + -0x10) = 0x2000;
                *(undefined2 *)(iVar95 + -0x12) = 0x9bfe;
                FUN_28eb_08be();
              }
              return (int *)*piVar14;
            }
          }
        }
        piVar14 = (int *)*(undefined2 *)(iVar95 + -0x1c);
        *(int *)(iVar95 + -0x12) = *(int *)(iVar95 + -0x12) + 1;
      } while( true );
    }
  }
  return (int *)0x0;
code_r0x0002122e:
  if ((DAT_554c_42ca < *(int *)(iVar95 + 8)) || (*(int *)(iVar95 + 8) < DAT_554c_42c8)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  *(char *)(iVar95 + -0x1b) = cVar7;
  if (cVar7 != '\0') {
LAB_1a9e_686e:
    *(undefined2 *)(iVar95 + -0x1e) = *(undefined2 *)(*(int *)(iVar95 + 8) * 2 + 0x49b2);
  }
  goto LAB_1a9e_62c7;
}

