// TIM2.EXE: FUN_553b_00cf @ file 0x05A67F Ghidra 0x5547F
// Subsystem: misc | Size: 50 bytes


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

void FUN_553b_00cf(void)

{
  byte *pbVar1;
  uint *puVar2;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined2 *puVar7;
  undefined2 uVar8;
  long lVar9;
  code *pcVar10;
  undefined4 uVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  char cVar15;
  uint uVar16;
  uint uVar17;
  undefined2 uVar18;
  undefined1 *puVar19;
  uint uVar20;
  undefined2 in_CX;
  char cVar22;
  int iVar21;
  int extraout_DX;
  uint uVar23;
  undefined2 uVar24;
  byte *in_BX;
  int iVar25;
  undefined1 *puVar26;
  undefined2 *puVar27;
  undefined2 *puVar28;
  int iVar29;
  undefined2 *puVar30;
  undefined2 *puVar31;
  undefined1 *puVar32;
  uint *puVar33;
  int *piVar34;
  uint *puVar35;
  uint *puVar36;
  uint *puVar37;
  int iVar38;
  undefined1 *puVar39;
  undefined2 *in_ESP;
  ulong uVar40;
  int unaff_BP;
  int iVar41;
  int iVar42;
  int iVar43;
  uint uVar44;
  undefined1 *puVar45;
  undefined1 *puVar46;
  char *pcVar47;
  char *pcVar48;
  uint *puVar49;
  char *pcVar50;
  int unaff_DI;
  uint uVar51;
  undefined2 *puVar52;
  undefined2 *puVar53;
  byte *pbVar54;
  undefined2 uVar55;
  undefined2 unaff_SS;
  undefined2 uVar56;
  undefined2 in_FS;
  long in_GS_OFFSET;
  byte in_AF;
  bool bVar57;
  char cVar58;
  byte in_TF;
  byte in_IF;
  char cVar59;
  byte in_NT;
  
  pcVar10 = (code *)swi(0x3f);
  bVar12 = (*pcVar10)();
  cVar15 = (char)in_CX;
  cVar22 = (char)((uint)in_CX >> 8) + cVar15;
  in_AF = 9 < (bVar12 & 0xf) | in_AF;
  uVar55 = *(undefined2 *)in_ESP;
  uVar56 = (undefined2)((ulong)in_ESP >> 0x10);
  puVar27 = (undefined2 *)in_ESP + 1;
  cVar59 = SCARRY1(cVar22,cVar15);
  cVar22 = cVar22 + cVar15;
  cVar58 = cVar22 < '\0';
  bVar57 = cVar22 == '\0';
  in_AF = 9 < (bVar12 + in_AF * -6 & 0xf) | in_AF;
  puVar52 = (undefined2 *)0x7;
  pcVar10 = (code *)swi(0x3f);
  bVar12 = (*pcVar10)();
  if (!bVar57 && cVar59 == cVar58) {
    in_AF = 9 < (bVar12 & 0xf) | in_AF;
    bVar12 = bVar12 + in_AF * -6 & 0xf;
    uVar55 = *(undefined2 *)((int)puVar27 + 1);
    puVar27 = (undefined2 *)((int)puVar27 + 3);
  }
  in_AF = 9 < (bVar12 & 0xf) | in_AF;
  bVar12 = bVar12 + in_AF * -6 & 0xf;
  in_AF = 9 < (bVar12 | *in_BX & 0xf) | in_AF;
  bVar13 = (bVar12 | *in_BX) + in_AF * -6 & 0xf;
  bVar12 = DAT_6000_21c0 << 7 | DAT_6000_21c0 >> 1;
  bVar57 = (DAT_6000_21c0 >> 1 & 1) != 0;
  cVar22 = bVar12 + bVar13;
  DAT_6000_21c0 = cVar22 + bVar57;
  in_AF = 9 < bVar13 | in_AF;
  bVar14 = bVar13 + in_AF * -6 & 0xf;
  if (SCARRY1(bVar12,bVar13) == SCARRY1(cVar22,bVar57)) {
    in_AF = 9 < bVar14 | in_AF;
    bVar14 = bVar14 + in_AF * -6 & 0xf;
  }
  in_AF = 9 < bVar14 | in_AF;
  cVar58 = '\0';
  pcVar10 = (code *)swi(0x3f);
  cVar22 = (*pcVar10)();
  bVar13 = cVar22 + '\x04' + cVar58;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  *(char *)(unaff_BP + 0x55) = *(char *)(unaff_BP + 0x55) + cVar15;
  pbVar1 = (byte *)(unaff_BP + unaff_DI + 0x48);
  *pbVar1 = *pbVar1 & bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  in_BX[(int)puVar52] = in_BX[(int)puVar52] + bVar13;
  pbVar1 = in_BX + (int)puVar52;
  bVar12 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar13;
  puVar53 = puVar52 + 1;
  out(*puVar52,extraout_DX + 1);
  if (CARRY1(bVar12,bVar13)) {
    in_BX[(int)puVar53] = in_BX[(int)puVar53] + bVar13;
    in_BX[(int)puVar53] = in_BX[(int)puVar53] + bVar13;
    in_BX[(int)puVar53] = in_BX[(int)puVar53] + bVar13;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar51 = puVar27[-1];
  puVar45 = (undefined1 *)*puVar27;
  iVar41 = puVar27[1];
  iVar25 = puVar27[3];
  uVar23 = puVar27[4];
  iVar21 = puVar27[5];
  uVar16 = puVar27[6];
  out(*puVar45,uVar23);
  pbVar1 = (byte *)(iVar41 + uVar51 + 0x2b);
  *pbVar1 = *pbVar1 & (byte)uVar16;
  iVar42 = -*(int *)(iVar25 + (int)(puVar45 + 1));
  uVar40 = CONCAT22(uVar56,(int)puVar27 + iVar42 + 0xe);
  uVar17 = uVar16 + 0xbce0;
  puVar26 = puVar45 + 3;
  out(*(undefined2 *)(puVar45 + 1),uVar23);
  if (SBORROW2(uVar16,0x4320)) {
LAB_554c_00a5:
    puVar45 = (undefined1 *)(uVar51 - 1);
    iVar29 = (int)uVar40;
    *(int *)(iVar29 + -2) = iVar41;
    puVar30 = (undefined2 *)(iVar29 + -4);
    *(uint *)(iVar29 + -4) = uVar23;
    iVar25 = iVar25 + 1;
    iVar41 = iVar41 + 1;
    puVar26[iVar25] = puVar26[iVar25] ^ (byte)(uVar23 >> 8);
    *(uint *)(puVar26 + iVar25) = *(uint *)(puVar26 + iVar25) ^ uVar17;
LAB_554c_00af:
    *(uint *)((int)puVar30 + -2) = uVar23;
    *(int *)((int)puVar30 + -4) = iVar25;
    *(int *)((int)puVar30 + -6) = iVar41 + 1;
    *(uint *)((int)puVar30 + -8) = uVar23;
    iVar42 = iVar41 + 2;
    iVar25 = iVar25 + 2;
    puVar26 = puVar26 + 1;
    puVar26[iVar41 + 0x47] = puVar26[iVar41 + 0x47] + (char)uVar23;
    puVar31 = (undefined2 *)((int)puVar30 + -10);
    *(int *)((int)puVar30 + -10) = iVar25;
  }
  else {
    bVar12 = (byte)uVar17;
    if (uVar16 < 0x4320) {
      puVar26[iVar25] = puVar26[iVar25] + bVar12;
      puVar26[iVar25] = puVar26[iVar25] + bVar12;
      puVar26[iVar25] = puVar26[iVar25] + bVar12;
      puVar26[iVar25] = puVar26[iVar25] + bVar12;
      puVar26[iVar25] = puVar26[iVar25] + bVar12;
      puVar26[iVar41 + 0x45] = puVar26[iVar41 + 0x45] + (char)uVar23;
      uVar40 = (ulong)(uint)((int)puVar27 + iVar42 + 0xc);
      *(int *)((int)puVar27 + iVar42 + 0xc) = iVar25;
      goto LAB_554c_00a5;
    }
    *(undefined2 *)(uVar40 - 2) = 0x2074;
    *(uint *)(iVar25 + uVar51) = *(uint *)(iVar25 + uVar51) ^ uVar51;
    puVar26[iVar41 + 0x6f] = puVar26[iVar41 + 0x6f] & bVar12;
    puVar28 = (undefined2 *)(undefined2 *)(uVar40 - 2);
    puVar45 = (undefined1 *)*puVar28;
    iVar41 = puVar28[2];
    iVar25 = puVar28[4];
    uVar23 = puVar28[5];
    iVar21 = puVar28[6];
    uVar17 = puVar28[7];
    puVar30 = puVar28 + 8;
    puVar31 = puVar28 + 8;
    puVar26 = (undefined1 *)puVar28[1] + 1;
    out(*(undefined1 *)puVar28[1],uVar23);
    pbVar1 = puVar45 + iVar25 + 0x6e;
    *pbVar1 = *pbVar1 & (byte)iVar21;
    if (*pbVar1 == 0) goto LAB_554c_00af;
    *(char *)(iVar41 + 0x75) = *(char *)(iVar41 + 0x75) + (byte)iVar21;
    puVar46 = puVar45 + 1;
    uVar6 = in(uVar23);
    *puVar45 = uVar6;
    puVar45 = puVar45 + 2;
    uVar6 = in(uVar23);
    *puVar46 = uVar6;
    puVar26[iVar25 + 0x6f] = puVar26[iVar25 + 0x6f] & (byte)(uVar23 >> 8);
    iVar42 = *(int *)(iVar41 + 0x74) * 0x7265;
    puVar45[iVar25 + 0x73] = puVar45[iVar25 + 0x73] & (byte)(uVar17 >> 8);
  }
  *(int *)((int)puVar31 + -2) = iVar42;
  *(uint *)((int)puVar31 + -4) = uVar23;
  iVar41 = iVar25 + 1;
  *(undefined2 *)((int)puVar31 + -6) = puVar45 + -1;
  pcVar3 = puVar45 + -1 + iVar42 + 0x5b;
  *pcVar3 = *pcVar3 + (char)uVar23;
  *(int *)((int)puVar31 + -8) = iVar41;
  *(undefined1 **)(undefined1 *)((int)puVar31 + -10) = (undefined1 *)((int)puVar31 + -8);
  *(uint *)((int)puVar31 + -0xc) = uVar23;
  *(int *)((int)puVar31 + -0xe) = iVar41;
  cVar15 = (char)(uVar23 >> 8);
  puVar26[iVar42 + 0x76] = puVar26[iVar42 + 0x76] + cVar15;
  puVar26[0x40] = puVar26[0x40] + (char)iVar21;
  puVar46 = puVar26 + -2;
  puVar32 = (undefined1 *)((int)puVar31 + -0x10);
  *(int *)((int)puVar31 + -0x10) = iVar42 + 3;
  iVar21 = iVar21 + 1;
  puVar52 = (undefined2 *)(puVar45 + 1);
  iVar43 = iVar42 + 4;
  bVar12 = (byte)((uint)iVar21 >> 8);
  bVar57 = CARRY1(DAT_5b41_0214,bVar12);
  DAT_5b41_0214 = DAT_5b41_0214 + bVar12;
  if (bVar57) {
LAB_554c_0149:
    *(undefined1 **)(puVar32 + -1) = puVar32 + 1;
    puVar46[0x41] = puVar46[0x41] + (char)iVar21 + '\x01';
    pcVar47 = puVar46 + -1;
    *(int *)(puVar32 + -3) = iVar43;
    iVar21 = iVar21 + 2;
    puVar52 = puVar52 + 1;
    *(uint *)(puVar32 + -5) = uVar23;
    iVar42 = iVar43 + 2;
    piVar34 = (int *)(puVar32 + -7);
    *(int *)(puVar32 + -7) = iVar41;
    cVar15 = (char)(uVar23 >> 8);
    *(char *)(iVar41 + 0x74) = *(char *)(iVar41 + 0x74) + cVar15;
    pcVar47[iVar43 + 100] = pcVar47[iVar43 + 100] + cVar15;
    cVar15 = (char)uVar17;
    pcVar47[iVar41] = pcVar47[iVar41] + cVar15;
    pcVar47[iVar41] = pcVar47[iVar41] + cVar15;
    pcVar47[iVar41] = pcVar47[iVar41] + cVar15;
    pcVar47[iVar41] = pcVar47[iVar41];
    pcVar47[iVar41] = pcVar47[iVar41] + cVar15;
    *pcVar47 = *pcVar47 + (char)iVar21;
    *(char *)(iVar42 + (int)puVar52) = *(char *)(iVar42 + (int)puVar52) + cVar15;
    pcVar47[iVar41] = pcVar47[iVar41] + cVar15;
    pcVar47[iVar41] = pcVar47[iVar41] + cVar15;
  }
  else {
    puVar45[0x4f] = puVar45[0x4f] + (char)uVar17;
    *(int *)((int)puVar31 + -0x13) = iVar41;
    *(undefined1 **)(undefined1 *)((int)puVar31 + -0x14) = (undefined1 *)((int)puVar31 + -0x12);
    puVar46[iVar42 + 0x66] = puVar46[iVar42 + 0x66] + cVar15;
    puVar46[iVar42 + 0x78] = puVar46[iVar42 + 0x78] + cVar15;
    *(char *)(iVar25 + 0x75) = *(char *)(iVar25 + 0x75) + cVar15;
    puVar26[0x3f] = puVar26[0x3f] + (char)iVar21;
    *(int *)((int)puVar31 + -0x16) = iVar43;
    puVar26[0x3e] = puVar26[0x3e] + (char)iVar21 + '\x01';
    *(int *)((int)puVar31 + -0x18) = iVar42 + 5;
    pcVar3 = puVar26 + iVar25 + -3;
    *pcVar3 = *pcVar3 + (char)(uVar17 - 1 >> 8);
    cVar15 = *pcVar3;
    uVar6 = in(uVar23);
    puVar45[6] = uVar6;
    puVar52 = (undefined2 *)*(undefined2 *)((int)puVar31 + -0x18);
    puVar46 = (undefined1 *)*(undefined2 *)((int)puVar31 + -0x16);
    iVar42 = *(int *)((int)puVar31 + -0x14);
    iVar41 = *(int *)((int)puVar31 + -0x10);
    uVar23 = *(uint *)((int)puVar31 + -0xe);
    iVar21 = *(int *)((int)puVar31 + -0xc);
    uVar17 = *(uint *)((int)puVar31 + -10);
    piVar34 = (int *)((int)puVar31 + -8);
    pcVar47 = puVar46 + 1;
    out(*puVar46,uVar23);
    if (cVar15 == '\0') {
      *(byte *)(in_GS_OFFSET + 0xa732520) =
           *(byte *)(in_GS_OFFSET + 0xa732520) & (byte)((uint)iVar41 >> 8);
      DAT_5b41_0214 = DAT_5b41_0214 + (char)((uint)iVar21 >> 8);
      iVar41 = iVar41 + -1;
      iVar43 = iVar42 + 1;
      iVar21 = *(int *)((int)puVar31 + -8);
      uVar23 = uVar23 + 1;
      *(uint *)((int)puVar31 + -8) = uVar23;
      iVar21 = iVar21 + 2;
      *(uint *)((int)puVar31 + -9) = uVar17;
      pcVar3 = (char *)((int)puVar52 + iVar42 + 0x54);
      *pcVar3 = *pcVar3 + (char)uVar17;
      *(uint *)((int)puVar31 + -0xb) = uVar23;
      *(int *)((int)puVar31 + -0xd) = iVar41;
      puVar52 = puVar52 + -1;
      *(uint *)((int)puVar31 + -0xf) = uVar23;
      *(uint *)((int)puVar31 + -0x11) = uVar23;
      puVar32 = (undefined1 *)((int)puVar31 + -0x13);
      *(int *)((int)puVar31 + -0x13) = iVar41;
      pbVar1 = (byte *)((int)puVar52 + iVar42 + 0x76);
      bVar12 = *pbVar1;
      bVar13 = (byte)(uVar17 >> 8);
      *pbVar1 = *pbVar1 + bVar13;
      if (!CARRY1(bVar12,bVar13)) {
        puVar46 = puVar46 + 3;
        out(*(undefined2 *)pcVar47,uVar23);
        puVar46[iVar43] = puVar46[iVar43] + (char)((uint)iVar21 >> 8);
        goto LAB_554c_0149;
      }
      puVar52 = (undefined2 *)*(undefined2 *)((int)puVar31 + -0x13);
      pcVar47 = (char *)*(undefined2 *)((int)puVar31 + -0x11);
      iVar42 = *(int *)((int)puVar31 + -0xf);
      iVar41 = *(int *)((int)puVar31 + -0xb);
      uVar23 = *(uint *)((int)puVar31 + -9);
      iVar21 = *(int *)((int)puVar31 + -7);
      uVar17 = *(uint *)((int)puVar31 + -5);
      piVar34 = (int *)((int)puVar31 + -3);
    }
  }
  bVar13 = (byte)uVar17;
  pcVar47[iVar41] = pcVar47[iVar41] + bVar13;
  *(char *)(iVar42 + (int)puVar52) = *(char *)(iVar42 + (int)puVar52) + (char)(uVar23 >> 8);
  pcVar47[iVar41] = pcVar47[iVar41] + bVar13;
  pcVar47[iVar41] = pcVar47[iVar41] + bVar13;
  pcVar47[iVar41] = pcVar47[iVar41] + bVar13;
  pcVar47[iVar41 + -0x4d00] = pcVar47[iVar41 + -0x4d00] + bVar13;
  pcVar47[8] = pcVar47[8] + (char)iVar21;
  pcVar47[iVar41] = pcVar47[iVar41] + bVar13;
  *(char *)(iVar42 + -0x7ff9) = *(char *)(iVar42 + -0x7ff9) + (char)iVar41;
  pcVar3 = (char *)((int)puVar52 + iVar42 + 0x21);
  *pcVar3 = *pcVar3 + (char)(uVar17 >> 8);
  pcVar47[iVar41] = pcVar47[iVar41] + bVar13;
  uVar56 = *piVar34;
  pcVar47[iVar41] = pcVar47[iVar41] + bVar13;
  pbVar1 = (byte *)(pcVar47 + iVar41);
  bVar12 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar13;
  iVar25 = *(int *)((int)puVar52 + iVar41 + 0x4e);
  *piVar34 = iVar41;
  piVar34[-1] = (int)piVar34;
  uVar17 = iVar21 + iVar25 + (uint)CARRY1(bVar12,bVar13) + 1;
  uVar16 = piVar34[-2];
  uVar51 = iVar42 + 2;
  pcVar47[iVar41] = pcVar47[iVar41] + (char)uVar16;
  piVar4 = (int *)0x5207;
  *piVar4 = *piVar4 + uVar16;
  puVar33 = (uint *)(*(int *)((int)puVar52 + iVar42 + 0x6a) * 0x6152);
  if (*piVar4 < 0) {
    iVar21 = uVar16 + 1;
    uVar23 = uVar23 - 1;
    puVar33[-1] = (uint)puVar33;
    puVar33[-2] = iVar21;
    pcVar47[iVar42 + 0x47] = pcVar47[iVar42 + 0x47] + (char)uVar23;
    puVar33[-3] = iVar41;
    puVar33[-4] = uVar51;
    puVar33[-5] = uVar23;
    puVar33[-6] = iVar21;
    bVar12 = (byte)(uVar23 >> 8);
    pcVar47[iVar42 + 100] = pcVar47[iVar42 + 100] + bVar12;
    pcVar47[iVar42 + 100] = pcVar47[iVar42 + 100] + bVar12;
    pcVar47[iVar42 + 100] = pcVar47[iVar42 + 100] + bVar12;
    pcVar47[iVar42 + 100] = pcVar47[iVar42 + 100] + bVar12;
    pcVar47[iVar42 + 100] = pcVar47[iVar42 + 100] + bVar12;
    pcVar47[iVar42 + 100] = pcVar47[iVar42 + 100] + bVar12;
    pcVar47[iVar41 + 1] = pcVar47[iVar41 + 1] + (char)iVar21;
    uVar16 = uVar16 + 0x202;
    piVar4 = (int *)((int)puVar52 + iVar42 + 1);
    *piVar4 = *piVar4 + uVar16;
    puVar33[-7] = uVar23;
    puVar33[-8] = iVar41 + 1;
    puVar33[-9] = iVar42 + 3;
    puVar33[-10] = uVar23;
    pcVar47[iVar42 + 0x67] = pcVar47[iVar42 + 0x67] + bVar12;
    pcVar47[iVar42 + 0x4a] = pcVar47[iVar42 + 0x4a] + (char)uVar23;
    puVar33[-0xb] = iVar41 + 3;
    puVar33[-0xc] = iVar42 + 4;
    puVar36 = puVar33 + -0xd;
    puVar33[-0xd] = uVar23;
    puVar26 = (undefined1 *)(iVar41 + 5);
    puVar53 = (undefined2 *)((int)puVar52 + -1);
    pbVar1 = (byte *)(iVar42 + 0x72);
    bVar57 = CARRY1(*pbVar1,bVar12);
    *pbVar1 = *pbVar1 + bVar12;
    pcVar50 = pcVar47 + 4;
    out(*(undefined2 *)(pcVar47 + 2),uVar23);
    if (bVar57 || *pbVar1 == 0) {
      uVar6 = in(uVar23);
      *(undefined1 *)puVar53 = uVar6;
code_r0x0005572e:
      uVar6 = in(uVar23);
      *(undefined1 *)puVar52 = uVar6;
      pcVar47 = pcVar50;
      puVar53 = puVar36;
      if (!bVar57) goto LAB_554c_02a1;
      puVar45 = (undefined1 *)puVar36[1];
      uVar51 = puVar36[2];
      puVar26 = (undefined1 *)puVar36[4];
      uVar23 = puVar36[5];
      uVar17 = puVar36[6];
      uVar16 = puVar36[7];
      pcVar47 = puVar45 + 1;
      out(*puVar45,uVar23);
      puVar52 = (undefined2 *)*puVar36 + 1;
      uVar8 = in(uVar23);
      *(undefined2 *)*puVar36 = uVar8;
      pbVar1 = puVar26 + 0x76;
      bVar12 = *pbVar1;
      bVar13 = (byte)(uVar17 >> 8);
      *pbVar1 = *pbVar1 + bVar13;
      if (CARRY1(bVar12,bVar13)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      puVar37 = (uint *)(*(int *)(puVar45 + 0x66) * 0x6e00);
    }
    else {
      pbVar1 = (byte *)(pcVar47 + 0x6d);
      bVar57 = CARRY1(*pbVar1,bVar12);
      bVar13 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar12;
      puVar52 = (undefined2 *)((int)puVar52 + 1);
      uVar8 = in(uVar23);
      *puVar53 = uVar8;
      if (SCARRY1(bVar13,bVar12)) {
        puVar36 = puVar33 + -0xe;
        puVar33[-0xe] = 0x6e61;
        goto code_r0x0005572e;
      }
      uVar6 = in(uVar23);
      *(undefined1 *)puVar52 = uVar6;
      pcVar47[0x7d] = pcVar47[0x7d] + (char)(uVar16 >> 8);
      out(*pcVar50,uVar23);
      iVar25 = puVar33[-0xc];
      iVar42 = puVar33[-0xb];
      iVar21 = puVar33[-9];
      uVar24 = puVar33[-8];
      uVar18 = puVar33[-6];
      uVar8 = in(uVar24);
      *(undefined2 *)puVar33[-0xd] = uVar8;
      uVar6 = in(uVar24);
      *(undefined1 *)(*(int *)(iVar21 + iVar25 + 0x2e) * 0x6170) = uVar6;
      pbVar1 = (byte *)(iVar42 + iVar25 + 0x6c);
      bVar12 = *pbVar1;
      bVar14 = (byte)((uint)uVar18 >> 8);
      bVar13 = *pbVar1;
      *pbVar1 = *pbVar1 + bVar14;
      puVar52 = (undefined2 *)puVar33[-5];
      pcVar47 = (char *)puVar33[-4];
      uVar51 = puVar33[-3];
      puVar26 = (undefined1 *)puVar33[-1];
      uVar23 = *puVar33;
      uVar17 = puVar33[1];
      uVar16 = puVar33[2];
      puVar35 = puVar33 + 3;
      puVar37 = puVar33 + 3;
      puVar2 = (uint *)((int)puVar52 + uVar51 + 0x2e);
      *puVar2 = *puVar2 + (uint)CARRY1(bVar12,bVar14) * ((uVar51 & 3) - (*puVar2 & 3));
      if (!SCARRY1(bVar13,bVar14)) goto code_r0x000556e0;
    }
    puVar49 = (uint *)(pcVar47 + 2);
    out(*(undefined2 *)pcVar47,uVar23);
    pbVar54 = (byte *)(puVar52 + 1);
    uVar8 = in(uVar23);
    *puVar52 = uVar8;
    uVar44 = uVar51;
  }
  else {
    puVar26 = (undefined1 *)(iVar41 + 1);
    puVar35 = puVar33 + -1;
    puVar33[-1] = uVar51;
code_r0x000556e0:
    uVar6 = in(uVar23);
    *(undefined1 *)puVar52 = uVar6;
    pcVar3 = (char *)((int)puVar52 + uVar51 + 0x56);
    *pcVar3 = *pcVar3 + (char)uVar16;
    *(uint *)((int)puVar35 + -2) = uVar23;
    *(undefined2 *)((int)puVar35 + -4) = puVar26;
    *(uint *)((int)puVar35 + -6) = uVar23;
    *(uint *)((int)puVar35 + -8) = uVar23;
    uVar44 = uVar51 + 1;
    puVar37 = (uint *)((int)puVar35 + -10);
    puVar39 = (undefined1 *)((int)puVar35 + -10);
    *(undefined2 *)((int)puVar35 + -10) = puVar26;
    pbVar1 = (byte *)((int)puVar52 + uVar51 + 0x76);
    bVar12 = *pbVar1;
    bVar13 = (byte)(uVar16 >> 8);
    *pbVar1 = *pbVar1 + bVar13;
    if (CARRY1(bVar12,bVar13)) {
      puVar53 = (undefined2 *)((int)puVar35 + -0xc);
      *(uint *)((int)puVar35 + -0xc) = uVar16;
      bVar57 = true;
LAB_554c_02a1:
      uVar16 = CONCAT11((char)(uVar16 >> 8),(char)uVar16 + '\x15' + bVar57);
      *(uint *)(puVar26 + (int)pcVar47 + 0x41) = *(uint *)(puVar26 + (int)pcVar47 + 0x41) & uVar23;
      *(uint *)((int)puVar53 + -2) = uVar23;
      *(undefined1 **)(undefined1 *)((int)puVar53 + -4) = (undefined1 *)((int)puVar53 + -2);
      puVar39 = (undefined1 *)((int)puVar53 + -6);
      *(undefined2 *)((int)puVar53 + -6) = puVar26;
      pcVar50 = pcVar47;
LAB_554c_02ab:
      *(uint *)(puVar39 + -2) = uVar16;
      puVar26[(int)(pcVar50 + -1)] = puVar26[(int)(pcVar50 + -1)] + (char)uVar16;
      puVar26[(int)(pcVar50 + -1)] = puVar26[(int)(pcVar50 + -1)] + (char)uVar16;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    out(*(undefined2 *)pcVar47,uVar23);
    pbVar1 = (byte *)((int)puVar52 + uVar51 + 0x79);
    bVar12 = *pbVar1;
    bVar13 = (byte)(uVar23 >> 8);
    *pbVar1 = *pbVar1 + bVar13;
    out(*(undefined2 *)(pcVar47 + 2),uVar23);
    pcVar50 = pcVar47 + 4;
    if (CARRY1(bVar12,bVar13) || *pbVar1 == 0) goto LAB_554c_02ab;
    pcVar47[0x6d] = pcVar47[0x6d] + bVar13;
    uVar8 = in(uVar23);
    *puVar52 = uVar8;
    bVar12 = (byte)(uVar17 >> 8) ^ *(byte *)0x7873;
    uVar17 = CONCAT11(bVar12,(char)uVar17);
    pcVar3 = (char *)((int)puVar52 + 0x67);
    *pcVar3 = *pcVar3 + bVar12;
    cVar15 = *pcVar3;
    puVar7 = puVar52 + 2;
    uVar8 = in(uVar23);
    puVar52[1] = uVar8;
    out(*(undefined2 *)(pcVar47 + 4),uVar23);
    puVar49 = (uint *)(pcVar47 + 7);
    out(pcVar47[6],uVar23);
    if (cVar15 != '\0') {
      out((byte)*puVar49,uVar23);
      *(undefined2 *)((int)puVar35 + -0xc) = puVar26;
      uVar8 = *(undefined2 *)((int)puVar35 + -0xc);
      *(undefined2 *)((int)puVar35 + -0xc) = puVar26;
      puVar2 = (uint *)(pcVar47 + 8 + uVar44);
      *puVar2 = *puVar2 ^ (uint)(pcVar47 + 8);
      pcVar48 = pcVar47 + 9;
      puVar36 = (uint *)((int)puVar35 + -0xe);
      puVar53 = (undefined2 *)((int)puVar35 + -0xe);
      *(undefined1 **)(undefined1 *)((int)puVar35 + -0xe) = (undefined1 *)((int)puVar35 + -0xc);
      pbVar1 = puVar26 + (int)(pcVar47 + 8) + 0x61;
      bVar12 = *pbVar1;
      bVar14 = (byte)((uint)uVar8 >> 8);
      *pbVar1 = *pbVar1 + bVar14;
      out(pcVar47[8],uVar23);
      puVar52 = (undefined2 *)((int)puVar52 + 5);
      uVar6 = in(uVar23);
      *(undefined1 *)puVar7 = uVar6;
      if (CARRY1(bVar12,bVar14)) {
        pbVar1 = puVar26 + (int)pcVar48 + 0x61;
        bVar57 = CARRY1(*pbVar1,bVar14);
        *pbVar1 = *pbVar1 + bVar14;
        pcVar50 = pcVar47 + 10;
        out(*pcVar48,uVar23);
        goto code_r0x0005572e;
      }
      puVar26[(int)pcVar48] = puVar26[(int)pcVar48] ^ bVar13;
      *(uint *)(puVar26 + (int)pcVar48) = *(uint *)(puVar26 + (int)pcVar48) ^ uVar16;
      puVar26[(int)pcVar48] = puVar26[(int)pcVar48] + (char)uVar16;
      pbVar1 = (byte *)(uVar44 + (int)puVar52);
      bVar57 = CARRY1(*pbVar1,(byte)uVar23);
      *pbVar1 = *pbVar1 + (byte)uVar23;
      pcVar47 = pcVar48;
      goto LAB_554c_02a1;
    }
    pbVar54 = (byte *)((int)puVar52 + 5);
    uVar6 = in(uVar23);
    *(undefined1 *)puVar7 = uVar6;
  }
  *(undefined2 *)((int)puVar37 + -2) = 0x6c6f;
  lVar9 = (long)*(int *)(byte *)((int)puVar49 + 0x61) * 0x79;
  iVar38 = (int)lVar9;
  if (iVar38 != lVar9) {
    *(byte *)(puVar49 + -0x39fb) = (byte)puVar49[-0x39fb] + (byte)uVar17;
    bVar12 = (byte)uVar16 | *pbVar54;
    puVar26[(int)puVar49] = puVar26[(int)puVar49] + bVar12;
    puVar26[(int)pbVar54] = puVar26[(int)pbVar54] + bVar12;
    puVar26[(int)puVar49] = puVar26[(int)puVar49] + bVar12;
  }
  *(byte *)puVar49 = (byte)*puVar49 + (char)(uVar23 >> 8);
  uVar11 = *(undefined4 *)pbVar54;
  uVar55 = (undefined2)((ulong)uVar11 >> 0x10);
  bVar12 = (byte)uVar11 | 6;
  *(int *)(iVar38 + -2) = iVar38;
  *(undefined2 *)(iVar38 + -4) = uVar55;
  *(uint *)(iVar38 + -6) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
       (uint)((char)bVar12 < '\0') * 0x80 | (uint)(bVar12 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
       (uint)((POPCOUNT(bVar12) & 1U) == 0) * 4;
  *(undefined2 *)(iVar38 + -8) = uVar55;
  cVar15 = in(6);
  puVar19 = (undefined1 *)CONCAT11((char)((ulong)uVar11 >> 8),cVar15 + -7);
  puVar45 = puVar19;
  puVar46 = (undefined1 *)(iVar38 + -8);
  if ((char)(cVar15 + -7) != '\0') {
    *(byte *)(puVar49 + 4) = (byte)puVar49[4] | (byte)uVar17;
    puVar45 = (undefined1 *)0x407;
    puVar46 = puVar19;
  }
  bVar12 = (byte)puVar45;
  *(byte *)puVar49 = (byte)*puVar49 | (byte)((uint)puVar45 >> 8) | (byte)puVar26;
  *(uint *)((int)puVar49 + 9) = *(uint *)((int)puVar49 + 9) | uVar44;
  puVar49[5] = puVar49[5] | CONCAT11(9,bVar12);
  ((byte *)(uVar44 + (int)puVar49))[0] = 0;
  ((byte *)(uVar44 + (int)puVar49))[1] = 0x50;
  uVar16 = *(uint *)((int)puVar49 + -0xbf5);
  uVar23 = *puVar49;
  *(byte *)((uint)pbVar54 | uVar23) = (byte)*puVar49;
  uVar51 = CONCAT11(bVar12 / 10,bVar12 % 10 - 0xb) | 0xdfc;
  bVar57 = false;
  uVar20 = uVar51 ^ 0xe;
  if (-1 < (char)((byte)uVar51 ^ 0xe)) {
    uVar17 = (uint)*(undefined4 *)0xf0c;
    *(undefined1 **)(puVar46 + -2) = puVar46;
    *puVar26 = 0;
    bVar12 = in(0xf);
    bVar57 = bVar12 < 0x10;
    uVar20 = CONCAT11((char)(uVar51 >> 8),bVar12 - 0x10);
    if ((byte)(bVar12 - 0x10) == '\0') goto LAB_554c_0364;
  }
  puVar2 = puVar49 + 9;
  uVar51 = *puVar2;
  uVar5 = *puVar2;
  *puVar2 = uVar5 + uVar17 + (uint)bVar57;
  uVar17 = (uint)(CARRY2(uVar51,uVar17) || CARRY2(uVar5 + uVar17,(uint)bVar57));
  *(undefined1 **)(byte *)((int)puVar49 + 1) =
       puVar26 + uVar20 +
       (uint)(CARRY2(uVar20,(uint)puVar26) || CARRY2((uint)(puVar26 + uVar20),uVar17)) +
       *(int *)(byte *)((int)puVar49 + 1) + uVar17;
LAB_554c_0364:
  *(undefined2 *)((byte *)((uint)pbVar54 | uVar23) + (uVar44 | uVar16) + 1) = unaff_SS;
  pcVar10 = (code *)swi(3);
  (*pcVar10)();
  return;
}

