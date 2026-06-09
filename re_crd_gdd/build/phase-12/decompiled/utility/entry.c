// TIM2.EXE: entry @ file 0x015200 Ghidra 0x10000
// Subsystem: utility | Size: 337 bytes


/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */

void entry(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  code *pcVar3;
  byte bVar4;
  undefined2 uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int extraout_DX;
  int iVar10;
  undefined2 extraout_DX_00;
  int iVar11;
  undefined1 *puVar12;
  int *piVar13;
  char *pcVar14;
  char *pcVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined2 unaff_ES;
  bool bVar18;
  undefined4 uVar19;
  
  puVar12 = (undefined1 *)0x80;
  DAT_1000_029f = 0x554c;
  pcVar3 = (code *)swi(0x21);
  uVar19 = (*pcVar3)();
  uVar5 = uRam000554ec;
  iVar8 = iRam000554c2;
  iVar9 = (int)((ulong)uVar19 >> 0x10);
  *(undefined2 *)0x8c = (int)uVar19;
  *(undefined2 *)0x8a = unaff_ES;
  *(undefined2 *)0x86 = uVar5;
  *(int *)0xa0 = iVar8;
  *(undefined2 *)(puVar12 + -2) = 0x28;
  FUN_1000_01aa();
  iVar11 = 0;
  pcVar15 = (char *)0x0;
  uVar7 = 0x7fff;
LAB_1000_0037:
  do {
    if (uVar7 != 0) {
      uVar7 = uVar7 - 1;
      pcVar1 = pcVar15;
      pcVar15 = pcVar15 + 1;
      if (*pcVar1 != '\0') goto LAB_1000_0037;
    }
    iVar10 = extraout_DX;
    bVar4 = 0;
    if (uVar7 == 0) goto code_r0x0001009d;
    iVar11 = iVar11 + 1;
  } while (*pcVar15 != '\0');
  *(int *)0x84 = -(uVar7 | 0x8000);
  *(uint *)0x88 = iVar11 * 2 + 8U & 0xfff8;
  pcVar14 = (char *)(iVar8 - iVar9);
  uVar7 = *(uint *)&DAT_554c_02ea;
  if (uVar7 < 0x200) {
    uVar7 = 0x200;
    *(undefined2 *)&DAT_554c_02ea = 0x200;
  }
  pcVar15 = (char *)(uVar7 + 0x8aec);
  iVar10 = iVar9;
  bVar4 = 1;
  if ((0x7513 < uVar7) ||
     (bVar18 = CARRY2((uint)pcVar15,*(uint *)&DAT_554c_5942),
     pcVar15 = pcVar15 + *(uint *)&DAT_554c_5942, bVar18)) {
code_r0x0001009d:
    bVar6 = bVar4;
    *(undefined2 *)(puVar12 + -2) = 0x1000;
    *(undefined2 *)(puVar12 + -4) = 0xa1;
    FUN_1000_13f1();
  }
  else {
    bVar6 = 4;
    pcVar15 = (char *)(((uint)pcVar15 >> 4) + 1);
    bVar4 = 4;
    if (pcVar14 < pcVar15) goto code_r0x0001009d;
    if (((*(int *)&DAT_554c_02ea == 0) || (*(int *)&DAT_554c_5942 == 0)) &&
       (pcVar15 = (char *)0x1000, pcVar14 < (char *)0x1001)) {
      pcVar15 = pcVar14;
    }
  }
  *(undefined2 *)0x98 = pcVar15 + iVar10;
  *(undefined2 *)0x9c = pcVar15 + iVar10;
  piVar13 = (int *)(puVar12 + -2);
  *(char **)(puVar12 + -2) = pcVar15;
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  uVar5 = DAT_1000_029f;
  puVar16 = (undefined1 *)(*piVar13 << (bVar6 & 0x1f));
  puVar17 = (undefined1 *)&DAT_5b41_0002;
  for (iVar8 = 0x2b9a; iVar8 != 0; iVar8 = iVar8 + -1) {
    puVar2 = puVar17;
    puVar17 = puVar17 + 1;
    *puVar2 = 0;
  }
  if (0x14 < *(uint *)&DAT_554c_5914) {
    bVar18 = *(byte *)0x8c < 3;
    if ((!bVar18) && ((3 < *(byte *)0x8c || (bVar18 = *(byte *)0x8d < 0x1e, !bVar18)))) {
      pcVar3 = (code *)swi(0x21);
      (*pcVar3)();
      if (!bVar18) {
        pcVar3 = (code *)swi(0x21);
        (*pcVar3)();
        if (!bVar18) {
          pcVar3 = (code *)swi(0x21);
          iVar8 = (*pcVar3)();
          if (!bVar18) {
            *(int *)0xa0 = iVar8 + 1;
            pcVar3 = (code *)swi(0x21);
            (*pcVar3)();
            if (!bVar18) {
              pcVar3 = (code *)swi(0x21);
              (*pcVar3)();
              if (!bVar18) goto LAB_1000_0124;
            }
          }
        }
      }
      *(undefined2 *)(puVar16 + -2) = 0x1000;
      *(undefined2 *)(puVar16 + -4) = 0x124;
      FUN_1000_13f1();
    }
  }
LAB_1000_0124:
  *(undefined2 *)(puVar16 + -2) = 0;
  *(undefined2 *)(puVar16 + -4) = 0x1000;
  *(undefined2 *)(puVar16 + -6) = 300;
  FUN_1000_2a3e();
  *(undefined2 *)(puVar16 + -2) = 0x13b;
  FUN_1000_021a();
  *(undefined2 *)(puVar16 + -2) = *(undefined2 *)0x82;
  *(undefined2 *)(puVar16 + -4) = *(undefined2 *)0x80;
  *(undefined2 *)(puVar16 + -6) = *(undefined2 *)0x7e;
  *(undefined2 *)(puVar16 + -8) = 0x1000;
  *(undefined2 *)(puVar16 + -10) = 0x14c;
  uVar5 = FUN_2321_0000();
  *(undefined2 *)(puVar16 + -8) = uVar5;
  *(undefined2 *)(puVar16 + -10) = 0x2321;
  *(undefined2 *)(puVar16 + -0xc) = 0x152;
  FUN_1000_17bf();
  *(undefined2 *)(puVar16 + -10) = 0x5f16;
  *(undefined2 *)(puVar16 + -0xc) = 0x5f46;
  *(undefined2 *)(puVar16 + -0xe) = 0x162;
  FUN_1000_025e();
  return;
}

