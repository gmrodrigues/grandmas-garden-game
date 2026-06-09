// TIM2.EXE: FUN_1000_22bc @ file 0x0174BC Ghidra 0x122BC
// Subsystem: utility | Size: 1059 bytes


/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined2 FUN_1000_22bc(void)

{
  char *pcVar1;
  uint *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined2 *puVar5;
  uint uVar6;
  int *piVar7;
  char cVar8;
  char cVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  uint uVar12;
  byte bVar15;
  int iVar13;
  int iVar14;
  int extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int iVar16;
  int unaff_BP;
  char *pcVar17;
  char *pcVar18;
  char *pcVar19;
  int *piVar20;
  undefined1 *puVar21;
  uint *puVar22;
  int *piVar23;
  int iVar24;
  int unaff_SS;
  bool bVar25;
  
  *(int *)(unaff_BP + -4) = unaff_BP + -0x96;
LAB_1000_22c5:
  pcVar19 = (char *)*(undefined2 *)(unaff_BP + -4);
LAB_1000_22c8:
  pcVar17 = (char *)*(undefined2 *)(unaff_BP + 6);
LAB_1000_22cb:
  pcVar18 = pcVar17 + 1;
  cVar9 = *pcVar17;
  if (cVar9 == '\0') goto LAB_1000_26bf;
  if (cVar9 == '%') {
    *(int *)(unaff_BP + -0x10) = (int)pcVar18;
    pcVar1 = pcVar18;
    pcVar18 = pcVar17 + 2;
    cVar9 = *pcVar1;
    if (cVar9 != '%') goto code_r0x000122ed;
  }
  *pcVar19 = cVar9;
  pcVar19 = pcVar19 + 1;
  pcVar1 = (char *)(unaff_BP + -0x14);
  cVar9 = *pcVar1;
  *pcVar1 = *pcVar1 + -1;
  pcVar17 = pcVar18;
  if (*pcVar1 == '\0' || SBORROW1(cVar9,'\x01') != *pcVar1 < '\0') {
    FUN_1000_228c();
  }
  goto LAB_1000_22cb;
code_r0x000122ed:
  *(undefined2 *)(unaff_BP + -4) = pcVar19;
  uVar12 = 0;
  *(undefined2 *)(unaff_BP + -0xe) = 0;
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined1 *)(unaff_BP + -0xb) = 0;
  *(undefined2 *)(unaff_BP + -8) = 0xffff;
  *(undefined2 *)(unaff_BP + -10) = 0xffff;
  do {
    if (0x5f < (byte)(cVar9 - 0x20U)) goto switchD_1000_2324_caseD_13;
    cVar4 = *(char *)((byte)(cVar9 - 0x20U) + 0x5ac9);
    cVar8 = cVar4 * '\x02';
    bVar15 = (byte)(uVar12 >> 8);
    iVar24 = unaff_SS;
    switch(cVar4) {
    case '\0':
      if (bVar15 != 0) goto switchD_1000_2324_caseD_13;
      if (*(char *)(unaff_BP + -0xb) != '+') {
        *(char *)(unaff_BP + -0xb) = cVar9;
      }
      break;
    case '\x01':
      if (bVar15 != 0) goto switchD_1000_2324_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 1;
      break;
    case '\x02':
      iVar24 = *(int *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      if (bVar15 < 2) {
        if (iVar24 < 0) {
          iVar24 = -iVar24;
          *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
        }
        *(int *)(unaff_BP + -8) = iVar24;
        uVar12 = 0x300;
      }
      else {
        if (bVar15 != 4) goto switchD_1000_2324_caseD_13;
        *(int *)(unaff_BP + -10) = iVar24;
        uVar12 = 0x500;
      }
      break;
    case '\x03':
      if (bVar15 != 0) goto switchD_1000_2324_caseD_13;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 2;
      break;
    case '\x04':
      if (3 < bVar15) goto switchD_1000_2324_caseD_13;
      uVar12 = 0x400;
      *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + 1;
      break;
    case '\x05':
switchD_1000_2324_caseD_5:
      if (bVar15 < 3) {
        uVar12 = 0x200;
        LOCK();
        iVar24 = *(int *)(unaff_BP + -8);
        *(int *)(unaff_BP + -8) = (int)(char)(cVar9 + -0x30);
        UNLOCK();
        if (-1 < iVar24) {
          *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + iVar24 * 10;
        }
      }
      else {
        if (bVar15 != 4) {
switchD_1000_2324_caseD_13:
          pcVar19 = (char *)*(undefined2 *)(unaff_BP + -0x10);
          do {
            FUN_1000_2283();
            pcVar1 = pcVar19;
            pcVar19 = pcVar19 + 1;
          } while (*pcVar1 != '\0');
LAB_1000_26bf:
          if (*(char *)(unaff_BP + -0x14) < 'P') {
            FUN_1000_228c();
          }
          if (*(int *)(unaff_BP + -0x16) == 0) {
            uVar11 = *(undefined2 *)(unaff_BP + -0x12);
          }
          else {
            uVar11 = 0xffff;
          }
          return uVar11;
        }
        LOCK();
        iVar24 = *(int *)(unaff_BP + -10);
        *(int *)(unaff_BP + -10) = (int)(char)(cVar9 + -0x30);
        UNLOCK();
        if (iVar24 != 0) {
          *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + iVar24 * 10;
        }
      }
      break;
    case '\x06':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x10;
      goto LAB_1000_235c;
    case '\a':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x100;
    case '\b':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffef;
      goto LAB_1000_235c;
    case '\t':
      if (bVar15 != 0) goto switchD_1000_2324_caseD_5;
      if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
        *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 8;
        uVar12 = 0x100;
      }
      break;
    case '\n':
      goto switchD_1000_2324_caseD_a;
    case '\v':
      uVar11 = CONCAT11(8,cVar8);
      goto LAB_1000_2411;
    case '\f':
      uVar11 = CONCAT11(10,cVar8);
      goto LAB_1000_2411;
    case '\r':
      uVar11 = CONCAT11(0x10,cVar9 + -0x17);
LAB_1000_2411:
      *(undefined1 *)(unaff_BP + -0xb) = 0;
      *(char *)(unaff_BP + -5) = cVar9;
      iVar13 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      piVar23 = (int *)*(undefined2 *)(unaff_BP + 4);
      iVar16 = *piVar23;
      goto LAB_1000_2435;
    case '\x0e':
      *(char *)(unaff_BP + -5) = cVar9;
      *(undefined2 *)(unaff_BP + 6) = pcVar18;
      puVar21 = (undefined1 *)(unaff_BP + -0x46);
      puVar5 = (undefined2 *)*(int *)(unaff_BP + 4);
      uVar11 = *puVar5;
      *(undefined2 *)(unaff_BP + 4) = puVar5 + 1;
      if ((*(uint *)(unaff_BP + -2) & 0x20) != 0) {
        *(undefined2 *)(unaff_BP + 4) = puVar5 + 2;
        FUN_1000_2244(uVar11);
        puVar3 = puVar21;
        puVar21 = (undefined1 *)(unaff_BP + -0x45);
        *puVar3 = 0x3a;
      }
      FUN_1000_2244();
      *puVar21 = 0;
      *(undefined1 *)(unaff_BP + -6) = 0;
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xfffb;
      puVar22 = (uint *)(unaff_BP + -0x46);
      uVar12 = (int)puVar21 - (int)puVar22;
      goto LAB_1000_2573;
    case '\x0f':
      *(undefined2 *)(unaff_BP + 6) = pcVar18;
      *(char *)(unaff_BP + -5) = cVar9;
      uVar11 = *(undefined2 *)(unaff_BP + 4);
      uVar12 = *(uint *)(unaff_BP + -10);
      if ((int)uVar12 < 0) {
        uVar12 = 6;
      }
      uVar6 = *(uint *)(unaff_BP + -2);
      if ((*(uint *)(unaff_BP + -2) & 0x100) == 0) {
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 8;
        uVar10 = 6;
      }
      else {
        uVar10 = 8;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 10;
      }
      thunk_FUN_1000_92b3(uVar10,uVar6 & 1,cVar9,unaff_BP + -0x45,uVar12,uVar11);
      puVar22 = (uint *)(unaff_BP + -0x45);
      goto LAB_1000_2573;
    case '\x10':
      *(undefined2 *)(unaff_BP + 6) = pcVar18;
      *(char *)(unaff_BP + -5) = cVar9;
      uVar12 = *(uint *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
      puVar22 = (uint *)(unaff_BP + -0x45);
      *puVar22 = uVar12 & 0xff;
      uVar12 = 1;
      goto LAB_1000_25b6;
    case '\x11':
      *(undefined2 *)(unaff_BP + 6) = pcVar18;
      *(char *)(unaff_BP + -5) = cVar9;
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        puVar22 = *(uint **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        iVar24 = 0x554c;
        bVar25 = puVar22 == (uint *)0x0;
      }
      else {
        puVar2 = (uint *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        iVar24 = (int)((ulong)puVar2 >> 0x10);
        puVar22 = (uint *)puVar2;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
        bVar25 = iVar24 == 0 && puVar22 == (uint *)0x0;
      }
      if (bVar25) {
        iVar24 = 0x554c;
        puVar22 = (uint *)&DAT_554c_5ac2;
      }
      FUN_1000_2276();
      if (*(uint *)(unaff_BP + -10) < uVar12) {
        uVar12 = *(uint *)(unaff_BP + -10);
      }
      goto LAB_1000_25b6;
    case '\x12':
      *(undefined2 *)(unaff_BP + 6) = pcVar18;
      if ((*(uint *)(unaff_BP + -2) & 0x20) == 0) {
        piVar23 = *(int **)(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
        uVar11 = 0x554c;
      }
      else {
        piVar7 = (int *)*(undefined4 *)*(undefined2 *)(unaff_BP + 4);
        uVar11 = (undefined2)((ulong)piVar7 >> 0x10);
        piVar23 = (int *)piVar7;
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
      }
      *piVar23 = (uint)(byte)(0x50 - *(char *)(unaff_BP + -0x14)) + *(int *)(unaff_BP + -0x12);
      if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
        piVar23[1] = 0;
      }
      goto LAB_1000_22c5;
    default:
      goto switchD_1000_2324_caseD_13;
    case '\x16':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) & 0xffdf;
      goto LAB_1000_235c;
    case '\x17':
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x20;
LAB_1000_235c:
      uVar12 = 0x500;
    }
    pcVar1 = pcVar18;
    pcVar18 = pcVar18 + 1;
    cVar9 = *pcVar1;
  } while( true );
switchD_1000_2324_caseD_a:
  uVar11 = CONCAT11(10,cVar8);
  *(undefined1 *)(unaff_BP + -6) = 1;
  *(char *)(unaff_BP + -5) = cVar9;
  piVar23 = (int *)*(undefined2 *)(unaff_BP + 4);
  iVar16 = *piVar23;
  iVar13 = iVar16 >> 0xf;
LAB_1000_2435:
  piVar20 = piVar23 + 1;
  *(undefined2 *)(unaff_BP + 6) = pcVar18;
  if ((*(uint *)(unaff_BP + -2) & 0x10) != 0) {
    iVar13 = *piVar20;
    piVar20 = piVar23 + 2;
  }
  *(undefined2 *)(unaff_BP + 4) = piVar20;
  puVar22 = (uint *)(unaff_BP + -0x45);
  if ((iVar16 == 0) && (iVar13 == 0)) {
    if (*(int *)(unaff_BP + -10) != 0) goto LAB_1000_2466;
    *(char *)puVar22 = '\0';
  }
  else {
    *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 4;
LAB_1000_2466:
    FUN_1000_1bb2(uVar11,*(undefined1 *)(unaff_BP + -6),(char)((uint)uVar11 >> 8),puVar22,iVar16,
                  iVar13);
  }
  if (*(int *)(unaff_BP + -10) < 0) {
LAB_1000_2573:
    if (((*(uint *)(unaff_BP + -2) & 8) != 0) && (0 < *(int *)(unaff_BP + -8))) goto LAB_1000_2581;
  }
  else {
LAB_1000_2581:
    FUN_1000_2276();
    if ((char)*puVar22 == '-') {
      uVar12 = uVar12 - 1;
    }
    if (extraout_DX - uVar12 != 0 && (int)uVar12 <= extraout_DX) {
      *(int *)(unaff_BP + -0xe) = extraout_DX - uVar12;
    }
  }
  if ((char)*puVar22 != '-') {
    if (*(char *)(unaff_BP + -0xb) == '\0') goto LAB_1000_25b3;
    puVar22 = (uint *)((int)puVar22 + -1);
    *(char *)puVar22 = *(char *)(unaff_BP + -0xb);
  }
  if ((0 < *(int *)(unaff_BP + -0xe)) && (uVar12 = *(uint *)(unaff_BP + -10), (int)uVar12 < 0)) {
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + -1;
  }
LAB_1000_25b3:
  FUN_1000_2276();
LAB_1000_25b6:
  pcVar19 = (char *)*(undefined2 *)(unaff_BP + -4);
  iVar16 = *(int *)(unaff_BP + -8);
  if ((*(uint *)(unaff_BP + -2) & 5) == 5) {
    cVar9 = *(char *)(unaff_BP + -5);
    if (cVar9 == 'o') {
      if (*(int *)(unaff_BP + -0xe) < 1) {
        *(undefined2 *)(unaff_BP + -0xe) = 1;
      }
    }
    else if ((cVar9 == 'x') || (cVar9 == 'X')) {
      *(uint *)(unaff_BP + -2) = *(uint *)(unaff_BP + -2) | 0x40;
      iVar16 = iVar16 + -2;
      piVar7 = (int *)(unaff_BP + -0xe);
      iVar13 = *piVar7;
      *piVar7 = *piVar7 + -2;
      if (SBORROW2(iVar13,2) != *piVar7 < 0) {
        *(undefined2 *)(unaff_BP + -0xe) = 0;
      }
    }
  }
  iVar13 = uVar12 + *(int *)(unaff_BP + -0xe);
  if ((*(uint *)(unaff_BP + -2) & 2) == 0) {
    for (; iVar13 < iVar16; iVar16 = iVar16 + -1) {
      FUN_1000_2283();
    }
  }
  if ((*(uint *)(unaff_BP + -2) & 0x40) != 0) {
    FUN_1000_2283();
    FUN_1000_2283();
  }
  iVar14 = *(int *)(unaff_BP + -0xe);
  if (0 < iVar14) {
    iVar13 = iVar13 - iVar14;
    iVar16 = iVar16 - iVar14;
    cVar9 = (char)*puVar22;
    if (((cVar9 == '-') || (cVar9 == ' ')) || (cVar9 == '+')) {
      puVar22 = (uint *)((int)puVar22 + 1);
      FUN_1000_2283();
      iVar13 = iVar13 + -1;
      iVar16 = iVar16 + -1;
      iVar14 = extraout_DX_00;
    }
    for (; iVar14 != 0; iVar14 = iVar14 + -1) {
      FUN_1000_2283();
      iVar13 = extraout_DX_01;
    }
  }
  if (iVar13 != 0) {
    iVar16 = iVar16 - iVar13;
    do {
      puVar2 = puVar22;
      puVar22 = (uint *)((int)puVar22 + 1);
      *pcVar19 = (char)*puVar2;
      pcVar19 = pcVar19 + 1;
      pcVar1 = (char *)(unaff_BP + -0x14);
      cVar9 = *pcVar1;
      *pcVar1 = *pcVar1 + -1;
      if (*pcVar1 == '\0' || SBORROW1(cVar9,'\x01') != *pcVar1 < '\0') {
        FUN_1000_228c();
      }
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  if (0 < iVar16) {
    do {
      FUN_1000_2283();
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
  }
  goto LAB_1000_22c8;
}

