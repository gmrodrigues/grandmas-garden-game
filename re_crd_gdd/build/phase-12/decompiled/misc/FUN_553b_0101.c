// TIM2.EXE: FUN_553b_0101 @ file 0x05A6B1 Ghidra 0x554B1
// Subsystem: misc | Size: 832 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00055539) overlaps instruction at (ram,0x00055538)
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: Removing unreachable block (ram,0x00055516) */
/* WARNING: Removing unreachable block (ram,0x0005551d) */
/* WARNING: Removing unreachable block (ram,0x0005552a) */
/* WARNING: Removing unreachable block (ram,0x0005552c) */
/* WARNING: Removing unreachable block (ram,0x00055539) */
/* WARNING: Removing unreachable block (ram,0x00055752) */
/* WARNING: Removing unreachable block (ram,0x00055754) */

void FUN_553b_0101(void)

{
  byte *pbVar1;
  uint *puVar2;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined2 *puVar7;
  long lVar8;
  code *pcVar9;
  undefined4 uVar10;
  char cVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  undefined2 uVar15;
  byte bVar18;
  undefined1 *puVar16;
  uint uVar17;
  char in_CL;
  int iVar19;
  byte bVar20;
  int extraout_DX;
  uint uVar21;
  undefined2 uVar22;
  int in_BX;
  int iVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  undefined2 *puVar26;
  int iVar27;
  undefined2 *puVar28;
  undefined2 *puVar29;
  undefined1 *puVar30;
  uint *puVar31;
  int *piVar32;
  uint *puVar33;
  uint *puVar34;
  uint *puVar35;
  int iVar36;
  undefined1 *puVar37;
  undefined2 *in_ESP;
  ulong uVar38;
  int unaff_BP;
  int iVar39;
  int iVar40;
  int iVar41;
  uint uVar42;
  undefined2 *unaff_SI;
  undefined1 *puVar43;
  undefined1 *puVar44;
  char *pcVar45;
  char *pcVar46;
  uint *puVar47;
  char *pcVar48;
  int unaff_DI;
  uint uVar49;
  undefined2 *puVar50;
  undefined2 *puVar51;
  byte *pbVar52;
  undefined2 unaff_ES;
  undefined2 uVar53;
  undefined2 unaff_SS;
  undefined2 uVar54;
  undefined2 in_FS;
  long in_GS_OFFSET;
  char in_CF;
  bool bVar55;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  
  pcVar9 = (code *)swi(0x3f);
  cVar11 = (*pcVar9)();
  bVar12 = cVar11 + '\x04' + in_CF;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(unaff_BP + 0x55) = *(char *)(unaff_BP + 0x55) + in_CL;
  puVar25 = (undefined2 *)in_ESP;
  pbVar1 = (byte *)(unaff_BP + unaff_DI + 0x48);
  *pbVar1 = *pbVar1 & bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar12;
  pbVar1 = (byte *)(in_BX + (int)unaff_SI);
  bVar20 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar12;
  out(*unaff_SI,extraout_DX + 1);
  if (CARRY1(bVar20,bVar12)) {
    pcVar3 = (char *)((int)unaff_SI + in_BX + 2);
    *pcVar3 = *pcVar3 + bVar12;
    pcVar3 = (char *)((int)unaff_SI + in_BX + 2);
    *pcVar3 = *pcVar3 + bVar12;
    pcVar3 = (char *)((int)unaff_SI + in_BX + 2);
    *pcVar3 = *pcVar3 + bVar12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar49 = puVar25[-1];
  puVar43 = (undefined1 *)*puVar25;
  iVar39 = puVar25[1];
  iVar23 = puVar25[3];
  uVar21 = puVar25[4];
  iVar19 = puVar25[5];
  uVar13 = puVar25[6];
  out(*puVar43,uVar21);
  pbVar1 = (byte *)(iVar39 + uVar49 + 0x2b);
  *pbVar1 = *pbVar1 & (byte)uVar13;
  iVar40 = -*(int *)(iVar23 + (int)(puVar43 + 1));
  uVar38 = CONCAT22((int)((ulong)in_ESP >> 0x10),(int)puVar25 + iVar40 + 0xe);
  uVar14 = uVar13 + 0xbce0;
  puVar24 = puVar43 + 3;
  out(*(undefined2 *)(puVar43 + 1),uVar21);
  if (SBORROW2(uVar13,0x4320)) {
LAB_554c_00a5:
    puVar43 = (undefined1 *)(uVar49 - 1);
    iVar27 = (int)uVar38;
    *(int *)(iVar27 + -2) = iVar39;
    puVar28 = (undefined2 *)(iVar27 + -4);
    *(uint *)(iVar27 + -4) = uVar21;
    iVar23 = iVar23 + 1;
    iVar39 = iVar39 + 1;
    puVar24[iVar23] = puVar24[iVar23] ^ (byte)(uVar21 >> 8);
    *(uint *)(puVar24 + iVar23) = *(uint *)(puVar24 + iVar23) ^ uVar14;
LAB_554c_00af:
    *(uint *)((int)puVar28 + -2) = uVar21;
    *(int *)((int)puVar28 + -4) = iVar23;
    *(int *)((int)puVar28 + -6) = iVar39 + 1;
    *(uint *)((int)puVar28 + -8) = uVar21;
    iVar40 = iVar39 + 2;
    iVar23 = iVar23 + 2;
    puVar24 = puVar24 + 1;
    puVar24[iVar39 + 0x47] = puVar24[iVar39 + 0x47] + (char)uVar21;
    puVar29 = (undefined2 *)((int)puVar28 + -10);
    *(int *)((int)puVar28 + -10) = iVar23;
  }
  else {
    bVar20 = (byte)uVar14;
    if (uVar13 < 0x4320) {
      puVar24[iVar23] = puVar24[iVar23] + bVar20;
      puVar24[iVar23] = puVar24[iVar23] + bVar20;
      puVar24[iVar23] = puVar24[iVar23] + bVar20;
      puVar24[iVar23] = puVar24[iVar23] + bVar20;
      puVar24[iVar23] = puVar24[iVar23] + bVar20;
      puVar24[iVar39 + 0x45] = puVar24[iVar39 + 0x45] + (char)uVar21;
      uVar38 = (ulong)(uint)((int)puVar25 + iVar40 + 0xc);
      *(int *)((int)puVar25 + iVar40 + 0xc) = iVar23;
      goto LAB_554c_00a5;
    }
    *(undefined2 *)(uVar38 - 2) = 0x2074;
    *(uint *)(iVar23 + uVar49) = *(uint *)(iVar23 + uVar49) ^ uVar49;
    puVar24[iVar39 + 0x6f] = puVar24[iVar39 + 0x6f] & bVar20;
    puVar26 = (undefined2 *)(undefined2 *)(uVar38 - 2);
    puVar43 = (undefined1 *)*puVar26;
    iVar39 = puVar26[2];
    iVar23 = puVar26[4];
    uVar21 = puVar26[5];
    iVar19 = puVar26[6];
    uVar14 = puVar26[7];
    puVar28 = puVar26 + 8;
    puVar29 = puVar26 + 8;
    puVar24 = (undefined1 *)puVar26[1] + 1;
    out(*(undefined1 *)puVar26[1],uVar21);
    pbVar1 = puVar43 + iVar23 + 0x6e;
    *pbVar1 = *pbVar1 & (byte)iVar19;
    if (*pbVar1 == 0) goto LAB_554c_00af;
    *(char *)(iVar39 + 0x75) = *(char *)(iVar39 + 0x75) + (byte)iVar19;
    puVar44 = puVar43 + 1;
    uVar6 = in(uVar21);
    *puVar43 = uVar6;
    puVar43 = puVar43 + 2;
    uVar6 = in(uVar21);
    *puVar44 = uVar6;
    puVar24[iVar23 + 0x6f] = puVar24[iVar23 + 0x6f] & (byte)(uVar21 >> 8);
    iVar40 = *(int *)(iVar39 + 0x74) * 0x7265;
    puVar43[iVar23 + 0x73] = puVar43[iVar23 + 0x73] & (byte)(uVar14 >> 8);
  }
  *(int *)((int)puVar29 + -2) = iVar40;
  *(uint *)((int)puVar29 + -4) = uVar21;
  iVar39 = iVar23 + 1;
  *(undefined2 *)((int)puVar29 + -6) = puVar43 + -1;
  pcVar3 = puVar43 + -1 + iVar40 + 0x5b;
  *pcVar3 = *pcVar3 + (char)uVar21;
  *(int *)((int)puVar29 + -8) = iVar39;
  *(undefined1 **)(undefined1 *)((int)puVar29 + -10) = (undefined1 *)((int)puVar29 + -8);
  *(uint *)((int)puVar29 + -0xc) = uVar21;
  *(int *)((int)puVar29 + -0xe) = iVar39;
  cVar11 = (char)(uVar21 >> 8);
  puVar24[iVar40 + 0x76] = puVar24[iVar40 + 0x76] + cVar11;
  puVar24[0x40] = puVar24[0x40] + (char)iVar19;
  puVar44 = puVar24 + -2;
  puVar30 = (undefined1 *)((int)puVar29 + -0x10);
  *(int *)((int)puVar29 + -0x10) = iVar40 + 3;
  iVar19 = iVar19 + 1;
  puVar50 = (undefined2 *)(puVar43 + 1);
  iVar41 = iVar40 + 4;
  bVar20 = (byte)((uint)iVar19 >> 8);
  bVar55 = CARRY1(DAT_5b41_0214,bVar20);
  DAT_5b41_0214 = DAT_5b41_0214 + bVar20;
  if (bVar55) {
LAB_554c_0149:
    *(undefined1 **)(puVar30 + -1) = puVar30 + 1;
    puVar44[0x41] = puVar44[0x41] + (char)iVar19 + '\x01';
    pcVar45 = puVar44 + -1;
    *(int *)(puVar30 + -3) = iVar41;
    iVar19 = iVar19 + 2;
    puVar50 = puVar50 + 1;
    *(uint *)(puVar30 + -5) = uVar21;
    iVar40 = iVar41 + 2;
    piVar32 = (int *)(puVar30 + -7);
    *(int *)(puVar30 + -7) = iVar39;
    cVar11 = (char)(uVar21 >> 8);
    *(char *)(iVar39 + 0x74) = *(char *)(iVar39 + 0x74) + cVar11;
    pcVar45[iVar41 + 100] = pcVar45[iVar41 + 100] + cVar11;
    cVar11 = (char)uVar14;
    pcVar45[iVar39] = pcVar45[iVar39] + cVar11;
    pcVar45[iVar39] = pcVar45[iVar39] + cVar11;
    pcVar45[iVar39] = pcVar45[iVar39] + cVar11;
    pcVar45[iVar39] = pcVar45[iVar39];
    pcVar45[iVar39] = pcVar45[iVar39] + cVar11;
    *pcVar45 = *pcVar45 + (char)iVar19;
    *(char *)(iVar40 + (int)puVar50) = *(char *)(iVar40 + (int)puVar50) + cVar11;
    pcVar45[iVar39] = pcVar45[iVar39] + cVar11;
    pcVar45[iVar39] = pcVar45[iVar39] + cVar11;
  }
  else {
    puVar43[0x4f] = puVar43[0x4f] + (char)uVar14;
    *(int *)((int)puVar29 + -0x13) = iVar39;
    *(undefined1 **)(undefined1 *)((int)puVar29 + -0x14) = (undefined1 *)((int)puVar29 + -0x12);
    puVar44[iVar40 + 0x66] = puVar44[iVar40 + 0x66] + cVar11;
    puVar44[iVar40 + 0x78] = puVar44[iVar40 + 0x78] + cVar11;
    *(char *)(iVar23 + 0x75) = *(char *)(iVar23 + 0x75) + cVar11;
    puVar24[0x3f] = puVar24[0x3f] + (char)iVar19;
    *(int *)((int)puVar29 + -0x16) = iVar41;
    puVar24[0x3e] = puVar24[0x3e] + (char)iVar19 + '\x01';
    *(int *)((int)puVar29 + -0x18) = iVar40 + 5;
    pcVar3 = puVar24 + iVar23 + -3;
    *pcVar3 = *pcVar3 + (char)(uVar14 - 1 >> 8);
    cVar11 = *pcVar3;
    uVar6 = in(uVar21);
    puVar43[6] = uVar6;
    puVar50 = (undefined2 *)*(undefined2 *)((int)puVar29 + -0x18);
    puVar44 = (undefined1 *)*(undefined2 *)((int)puVar29 + -0x16);
    iVar40 = *(int *)((int)puVar29 + -0x14);
    iVar39 = *(int *)((int)puVar29 + -0x10);
    uVar21 = *(uint *)((int)puVar29 + -0xe);
    iVar19 = *(int *)((int)puVar29 + -0xc);
    uVar14 = *(uint *)((int)puVar29 + -10);
    piVar32 = (int *)((int)puVar29 + -8);
    pcVar45 = puVar44 + 1;
    out(*puVar44,uVar21);
    if (cVar11 == '\0') {
      *(byte *)(in_GS_OFFSET + 0xa732520) =
           *(byte *)(in_GS_OFFSET + 0xa732520) & (byte)((uint)iVar39 >> 8);
      DAT_5b41_0214 = DAT_5b41_0214 + (char)((uint)iVar19 >> 8);
      iVar39 = iVar39 + -1;
      iVar41 = iVar40 + 1;
      iVar19 = *(int *)((int)puVar29 + -8);
      uVar21 = uVar21 + 1;
      *(uint *)((int)puVar29 + -8) = uVar21;
      iVar19 = iVar19 + 2;
      *(uint *)((int)puVar29 + -9) = uVar14;
      pcVar3 = (char *)((int)puVar50 + iVar40 + 0x54);
      *pcVar3 = *pcVar3 + (char)uVar14;
      *(uint *)((int)puVar29 + -0xb) = uVar21;
      *(int *)((int)puVar29 + -0xd) = iVar39;
      puVar50 = puVar50 + -1;
      *(uint *)((int)puVar29 + -0xf) = uVar21;
      *(uint *)((int)puVar29 + -0x11) = uVar21;
      puVar30 = (undefined1 *)((int)puVar29 + -0x13);
      *(int *)((int)puVar29 + -0x13) = iVar39;
      pbVar1 = (byte *)((int)puVar50 + iVar40 + 0x76);
      bVar20 = *pbVar1;
      bVar12 = (byte)(uVar14 >> 8);
      *pbVar1 = *pbVar1 + bVar12;
      if (!CARRY1(bVar20,bVar12)) {
        puVar44 = puVar44 + 3;
        out(*(undefined2 *)pcVar45,uVar21);
        puVar44[iVar41] = puVar44[iVar41] + (char)((uint)iVar19 >> 8);
        goto LAB_554c_0149;
      }
      puVar50 = (undefined2 *)*(undefined2 *)((int)puVar29 + -0x13);
      pcVar45 = (char *)*(undefined2 *)((int)puVar29 + -0x11);
      iVar40 = *(int *)((int)puVar29 + -0xf);
      iVar39 = *(int *)((int)puVar29 + -0xb);
      uVar21 = *(uint *)((int)puVar29 + -9);
      iVar19 = *(int *)((int)puVar29 + -7);
      uVar14 = *(uint *)((int)puVar29 + -5);
      piVar32 = (int *)((int)puVar29 + -3);
    }
  }
  bVar12 = (byte)uVar14;
  pcVar45[iVar39] = pcVar45[iVar39] + bVar12;
  *(char *)(iVar40 + (int)puVar50) = *(char *)(iVar40 + (int)puVar50) + (char)(uVar21 >> 8);
  pcVar45[iVar39] = pcVar45[iVar39] + bVar12;
  pcVar45[iVar39] = pcVar45[iVar39] + bVar12;
  pcVar45[iVar39] = pcVar45[iVar39] + bVar12;
  pcVar45[iVar39 + -0x4d00] = pcVar45[iVar39 + -0x4d00] + bVar12;
  pcVar45[8] = pcVar45[8] + (char)iVar19;
  pcVar45[iVar39] = pcVar45[iVar39] + bVar12;
  *(char *)(iVar40 + -0x7ff9) = *(char *)(iVar40 + -0x7ff9) + (char)iVar39;
  pcVar3 = (char *)((int)puVar50 + iVar40 + 0x21);
  *pcVar3 = *pcVar3 + (char)(uVar14 >> 8);
  pcVar45[iVar39] = pcVar45[iVar39] + bVar12;
  uVar54 = *piVar32;
  pcVar45[iVar39] = pcVar45[iVar39] + bVar12;
  pbVar1 = (byte *)(pcVar45 + iVar39);
  bVar20 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar12;
  iVar23 = *(int *)((int)puVar50 + iVar39 + 0x4e);
  *piVar32 = iVar39;
  piVar32[-1] = (int)piVar32;
  uVar14 = iVar19 + iVar23 + (uint)CARRY1(bVar20,bVar12) + 1;
  uVar13 = piVar32[-2];
  uVar49 = iVar40 + 2;
  pcVar45[iVar39] = pcVar45[iVar39] + (char)uVar13;
  piVar4 = (int *)0x5207;
  *piVar4 = *piVar4 + uVar13;
  puVar31 = (uint *)(*(int *)((int)puVar50 + iVar40 + 0x6a) * 0x6152);
  if (*piVar4 < 0) {
    iVar19 = uVar13 + 1;
    uVar21 = uVar21 - 1;
    puVar31[-1] = (uint)puVar31;
    puVar31[-2] = iVar19;
    pcVar45[iVar40 + 0x47] = pcVar45[iVar40 + 0x47] + (char)uVar21;
    puVar31[-3] = iVar39;
    puVar31[-4] = uVar49;
    puVar31[-5] = uVar21;
    puVar31[-6] = iVar19;
    bVar20 = (byte)(uVar21 >> 8);
    pcVar45[iVar40 + 100] = pcVar45[iVar40 + 100] + bVar20;
    pcVar45[iVar40 + 100] = pcVar45[iVar40 + 100] + bVar20;
    pcVar45[iVar40 + 100] = pcVar45[iVar40 + 100] + bVar20;
    pcVar45[iVar40 + 100] = pcVar45[iVar40 + 100] + bVar20;
    pcVar45[iVar40 + 100] = pcVar45[iVar40 + 100] + bVar20;
    pcVar45[iVar40 + 100] = pcVar45[iVar40 + 100] + bVar20;
    pcVar45[iVar39 + 1] = pcVar45[iVar39 + 1] + (char)iVar19;
    uVar13 = uVar13 + 0x202;
    piVar4 = (int *)((int)puVar50 + iVar40 + 1);
    *piVar4 = *piVar4 + uVar13;
    puVar31[-7] = uVar21;
    puVar31[-8] = iVar39 + 1;
    puVar31[-9] = iVar40 + 3;
    puVar31[-10] = uVar21;
    pcVar45[iVar40 + 0x67] = pcVar45[iVar40 + 0x67] + bVar20;
    pcVar45[iVar40 + 0x4a] = pcVar45[iVar40 + 0x4a] + (char)uVar21;
    puVar31[-0xb] = iVar39 + 3;
    puVar31[-0xc] = iVar40 + 4;
    puVar34 = puVar31 + -0xd;
    puVar31[-0xd] = uVar21;
    puVar24 = (undefined1 *)(iVar39 + 5);
    puVar51 = (undefined2 *)((int)puVar50 + -1);
    pbVar1 = (byte *)(iVar40 + 0x72);
    bVar55 = CARRY1(*pbVar1,bVar20);
    *pbVar1 = *pbVar1 + bVar20;
    pcVar48 = pcVar45 + 4;
    out(*(undefined2 *)(pcVar45 + 2),uVar21);
    if (bVar55 || *pbVar1 == 0) {
      uVar6 = in(uVar21);
      *(undefined1 *)puVar51 = uVar6;
code_r0x0005572e:
      uVar6 = in(uVar21);
      *(undefined1 *)puVar50 = uVar6;
      pcVar45 = pcVar48;
      puVar51 = puVar34;
      if (!bVar55) goto LAB_554c_02a1;
      puVar43 = (undefined1 *)puVar34[1];
      uVar49 = puVar34[2];
      puVar24 = (undefined1 *)puVar34[4];
      uVar21 = puVar34[5];
      uVar14 = puVar34[6];
      uVar13 = puVar34[7];
      pcVar45 = puVar43 + 1;
      out(*puVar43,uVar21);
      puVar50 = (undefined2 *)*puVar34 + 1;
      uVar53 = in(uVar21);
      *(undefined2 *)*puVar34 = uVar53;
      pbVar1 = puVar24 + 0x76;
      bVar20 = *pbVar1;
      bVar12 = (byte)(uVar14 >> 8);
      *pbVar1 = *pbVar1 + bVar12;
      if (CARRY1(bVar20,bVar12)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      puVar35 = (uint *)(*(int *)(puVar43 + 0x66) * 0x6e00);
    }
    else {
      pbVar1 = (byte *)(pcVar45 + 0x6d);
      bVar55 = CARRY1(*pbVar1,bVar20);
      bVar12 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar20;
      puVar50 = (undefined2 *)((int)puVar50 + 1);
      uVar53 = in(uVar21);
      *puVar51 = uVar53;
      if (SCARRY1(bVar12,bVar20)) {
        puVar34 = puVar31 + -0xe;
        puVar31[-0xe] = 0x6e61;
        goto code_r0x0005572e;
      }
      uVar6 = in(uVar21);
      *(undefined1 *)puVar50 = uVar6;
      pcVar45[0x7d] = pcVar45[0x7d] + (char)(uVar13 >> 8);
      out(*pcVar48,uVar21);
      iVar23 = puVar31[-0xc];
      iVar40 = puVar31[-0xb];
      iVar19 = puVar31[-9];
      uVar22 = puVar31[-8];
      uVar15 = puVar31[-6];
      uVar53 = in(uVar22);
      *(undefined2 *)puVar31[-0xd] = uVar53;
      uVar6 = in(uVar22);
      *(undefined1 *)(*(int *)(iVar19 + iVar23 + 0x2e) * 0x6170) = uVar6;
      pbVar1 = (byte *)(iVar40 + iVar23 + 0x6c);
      bVar12 = *pbVar1;
      bVar18 = (byte)((uint)uVar15 >> 8);
      bVar20 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar18;
      puVar50 = (undefined2 *)puVar31[-5];
      pcVar45 = (char *)puVar31[-4];
      uVar49 = puVar31[-3];
      puVar24 = (undefined1 *)puVar31[-1];
      uVar21 = *puVar31;
      uVar14 = puVar31[1];
      uVar13 = puVar31[2];
      puVar33 = puVar31 + 3;
      puVar35 = puVar31 + 3;
      puVar2 = (uint *)((int)puVar50 + uVar49 + 0x2e);
      *puVar2 = *puVar2 + (uint)CARRY1(bVar12,bVar18) * ((uVar49 & 3) - (*puVar2 & 3));
      if (!SCARRY1(bVar20,bVar18)) goto code_r0x000556e0;
    }
    puVar47 = (uint *)(pcVar45 + 2);
    out(*(undefined2 *)pcVar45,uVar21);
    pbVar52 = (byte *)(puVar50 + 1);
    uVar53 = in(uVar21);
    *puVar50 = uVar53;
    uVar42 = uVar49;
  }
  else {
    puVar24 = (undefined1 *)(iVar39 + 1);
    puVar33 = puVar31 + -1;
    puVar31[-1] = uVar49;
code_r0x000556e0:
    uVar6 = in(uVar21);
    *(undefined1 *)puVar50 = uVar6;
    pcVar3 = (char *)((int)puVar50 + uVar49 + 0x56);
    *pcVar3 = *pcVar3 + (char)uVar13;
    *(uint *)((int)puVar33 + -2) = uVar21;
    *(undefined2 *)((int)puVar33 + -4) = puVar24;
    *(uint *)((int)puVar33 + -6) = uVar21;
    *(uint *)((int)puVar33 + -8) = uVar21;
    uVar42 = uVar49 + 1;
    puVar35 = (uint *)((int)puVar33 + -10);
    puVar37 = (undefined1 *)((int)puVar33 + -10);
    *(undefined2 *)((int)puVar33 + -10) = puVar24;
    pbVar1 = (byte *)((int)puVar50 + uVar49 + 0x76);
    bVar20 = *pbVar1;
    bVar12 = (byte)(uVar13 >> 8);
    *pbVar1 = *pbVar1 + bVar12;
    if (CARRY1(bVar20,bVar12)) {
      puVar51 = (undefined2 *)((int)puVar33 + -0xc);
      *(uint *)((int)puVar33 + -0xc) = uVar13;
      bVar55 = true;
LAB_554c_02a1:
      uVar13 = CONCAT11((char)(uVar13 >> 8),(char)uVar13 + '\x15' + bVar55);
      *(uint *)(puVar24 + (int)pcVar45 + 0x41) = *(uint *)(puVar24 + (int)pcVar45 + 0x41) & uVar21;
      *(uint *)((int)puVar51 + -2) = uVar21;
      *(undefined1 **)(undefined1 *)((int)puVar51 + -4) = (undefined1 *)((int)puVar51 + -2);
      puVar37 = (undefined1 *)((int)puVar51 + -6);
      *(undefined2 *)((int)puVar51 + -6) = puVar24;
      pcVar48 = pcVar45;
LAB_554c_02ab:
      *(uint *)(puVar37 + -2) = uVar13;
      puVar24[(int)(pcVar48 + -1)] = puVar24[(int)(pcVar48 + -1)] + (char)uVar13;
      puVar24[(int)(pcVar48 + -1)] = puVar24[(int)(pcVar48 + -1)] + (char)uVar13;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    out(*(undefined2 *)pcVar45,uVar21);
    pbVar1 = (byte *)((int)puVar50 + uVar49 + 0x79);
    bVar20 = *pbVar1;
    bVar12 = (byte)(uVar21 >> 8);
    *pbVar1 = *pbVar1 + bVar12;
    out(*(undefined2 *)(pcVar45 + 2),uVar21);
    pcVar48 = pcVar45 + 4;
    if (CARRY1(bVar20,bVar12) || *pbVar1 == 0) goto LAB_554c_02ab;
    pcVar45[0x6d] = pcVar45[0x6d] + bVar12;
    uVar53 = in(uVar21);
    *puVar50 = uVar53;
    bVar20 = (byte)(uVar14 >> 8) ^ *(byte *)0x7873;
    uVar14 = CONCAT11(bVar20,(char)uVar14);
    pcVar3 = (char *)((int)puVar50 + 0x67);
    *pcVar3 = *pcVar3 + bVar20;
    cVar11 = *pcVar3;
    puVar7 = puVar50 + 2;
    uVar53 = in(uVar21);
    puVar50[1] = uVar53;
    out(*(undefined2 *)(pcVar45 + 4),uVar21);
    puVar47 = (uint *)(pcVar45 + 7);
    out(pcVar45[6],uVar21);
    if (cVar11 != '\0') {
      out((byte)*puVar47,uVar21);
      *(undefined2 *)((int)puVar33 + -0xc) = puVar24;
      uVar53 = *(undefined2 *)((int)puVar33 + -0xc);
      *(undefined2 *)((int)puVar33 + -0xc) = puVar24;
      puVar2 = (uint *)(pcVar45 + 8 + uVar42);
      *puVar2 = *puVar2 ^ (uint)(pcVar45 + 8);
      pcVar46 = pcVar45 + 9;
      puVar34 = (uint *)((int)puVar33 + -0xe);
      puVar51 = (undefined2 *)((int)puVar33 + -0xe);
      *(undefined1 **)(undefined1 *)((int)puVar33 + -0xe) = (undefined1 *)((int)puVar33 + -0xc);
      pbVar1 = puVar24 + (int)(pcVar45 + 8) + 0x61;
      bVar20 = *pbVar1;
      bVar18 = (byte)((uint)uVar53 >> 8);
      *pbVar1 = *pbVar1 + bVar18;
      out(pcVar45[8],uVar21);
      puVar50 = (undefined2 *)((int)puVar50 + 5);
      uVar6 = in(uVar21);
      *(undefined1 *)puVar7 = uVar6;
      if (CARRY1(bVar20,bVar18)) {
        pbVar1 = puVar24 + (int)pcVar46 + 0x61;
        bVar55 = CARRY1(*pbVar1,bVar18);
        *pbVar1 = *pbVar1 + bVar18;
        pcVar48 = pcVar45 + 10;
        out(*pcVar46,uVar21);
        goto code_r0x0005572e;
      }
      puVar24[(int)pcVar46] = puVar24[(int)pcVar46] ^ bVar12;
      *(uint *)(puVar24 + (int)pcVar46) = *(uint *)(puVar24 + (int)pcVar46) ^ uVar13;
      puVar24[(int)pcVar46] = puVar24[(int)pcVar46] + (char)uVar13;
      pbVar1 = (byte *)(uVar42 + (int)puVar50);
      bVar55 = CARRY1(*pbVar1,(byte)uVar21);
      *pbVar1 = *pbVar1 + (byte)uVar21;
      pcVar45 = pcVar46;
      goto LAB_554c_02a1;
    }
    pbVar52 = (byte *)((int)puVar50 + 5);
    uVar6 = in(uVar21);
    *(undefined1 *)puVar7 = uVar6;
  }
  *(undefined2 *)((int)puVar35 + -2) = 0x6c6f;
  lVar8 = (long)*(int *)(byte *)((int)puVar47 + 0x61) * 0x79;
  iVar36 = (int)lVar8;
  if (iVar36 != lVar8) {
    *(byte *)(puVar47 + -0x39fb) = (byte)puVar47[-0x39fb] + (byte)uVar14;
    bVar20 = (byte)uVar13 | *pbVar52;
    puVar24[(int)puVar47] = puVar24[(int)puVar47] + bVar20;
    puVar24[(int)pbVar52] = puVar24[(int)pbVar52] + bVar20;
    puVar24[(int)puVar47] = puVar24[(int)puVar47] + bVar20;
  }
  *(byte *)puVar47 = (byte)*puVar47 + (char)(uVar21 >> 8);
  uVar10 = *(undefined4 *)pbVar52;
  uVar53 = (undefined2)((ulong)uVar10 >> 0x10);
  bVar20 = (byte)uVar10 | 6;
  *(int *)(iVar36 + -2) = iVar36;
  *(undefined2 *)(iVar36 + -4) = uVar53;
  *(uint *)(iVar36 + -6) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
       (uint)((char)bVar20 < '\0') * 0x80 | (uint)(bVar20 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT(bVar20) & 1U) == 0) * 4;
  *(undefined2 *)(iVar36 + -8) = uVar53;
  cVar11 = in(6);
  puVar16 = (undefined1 *)CONCAT11((char)((ulong)uVar10 >> 8),cVar11 + -7);
  puVar43 = puVar16;
  puVar44 = (undefined1 *)(iVar36 + -8);
  if ((char)(cVar11 + -7) != '\0') {
    *(byte *)(puVar47 + 4) = (byte)puVar47[4] | (byte)uVar14;
    puVar43 = (undefined1 *)0x407;
    puVar44 = puVar16;
  }
  bVar20 = (byte)puVar43;
  *(byte *)puVar47 = (byte)*puVar47 | (byte)((uint)puVar43 >> 8) | (byte)puVar24;
  *(uint *)((int)puVar47 + 9) = *(uint *)((int)puVar47 + 9) | uVar42;
  puVar47[5] = puVar47[5] | CONCAT11(9,bVar20);
  ((byte *)(uVar42 + (int)puVar47))[0] = 0;
  ((byte *)(uVar42 + (int)puVar47))[1] = 0x50;
  uVar13 = *(uint *)((int)puVar47 + -0xbf5);
  uVar21 = *puVar47;
  *(byte *)((uint)pbVar52 | uVar21) = (byte)*puVar47;
  uVar49 = CONCAT11(bVar20 / 10,bVar20 % 10 - 0xb) | 0xdfc;
  bVar55 = false;
  uVar17 = uVar49 ^ 0xe;
  if (-1 < (char)((byte)uVar49 ^ 0xe)) {
    uVar14 = (uint)*(undefined4 *)0xf0c;
    *(undefined1 **)(puVar44 + -2) = puVar44;
    *puVar24 = 0;
    bVar20 = in(0xf);
    bVar55 = bVar20 < 0x10;
    uVar17 = CONCAT11((char)(uVar49 >> 8),bVar20 - 0x10);
    if ((byte)(bVar20 - 0x10) == '\0') goto LAB_554c_0364;
  }
  puVar2 = puVar47 + 9;
  uVar49 = *puVar2;
  uVar5 = *puVar2;
  *puVar2 = uVar5 + uVar14 + (uint)bVar55;
  uVar14 = (uint)(CARRY2(uVar49,uVar14) || CARRY2(uVar5 + uVar14,(uint)bVar55));
  *(undefined1 **)(byte *)((int)puVar47 + 1) =
       puVar24 + uVar17 +
       (uint)(CARRY2(uVar17,(uint)puVar24) || CARRY2((uint)(puVar24 + uVar17),uVar14)) +
       *(int *)(byte *)((int)puVar47 + 1) + uVar14;
LAB_554c_0364:
  *(undefined2 *)((byte *)((uint)pbVar52 | uVar21) + (uVar42 | uVar13) + 1) = unaff_SS;
  pcVar9 = (code *)swi(3);
  (*pcVar9)();
  return;
}

