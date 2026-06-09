// TIM2.EXE: FUN_1a9e_25bd @ file 0x02219D Ghidra 0x1CF9D
// Subsystem: level | Size: 1074 bytes


int __cdecl16far FUN_1a9e_25bd(uint param_1,undefined2 *param_2,undefined2 *param_3)

{
  undefined2 *puVar1;
  int *piVar2;
  undefined2 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  undefined2 *puVar19;
  int *piVar20;
  uint uVar21;
  undefined2 *puVar22;
  bool bVar23;
  
  DAT_554c_4f16 = 0;
  DAT_554c_4f1d = '\0';
  if (-1 < (int)param_1) {
    DAT_554c_445c = param_1;
    puVar19 = (undefined2 *)&DAT_554c_436c;
    for (uVar9 = param_1; uVar9 != 0; uVar9 = uVar9 - 1) {
      puVar3 = puVar19;
      puVar19 = puVar19 + 1;
      puVar1 = param_2;
      param_2 = param_2 + 1;
      *puVar3 = *puVar1;
    }
    puVar19 = (undefined2 *)&DAT_554c_4394;
    for (uVar9 = param_1; uVar9 != 0; uVar9 = uVar9 - 1) {
      puVar3 = puVar19;
      puVar19 = puVar19 + 1;
      puVar1 = param_3;
      param_3 = param_3 + 1;
      *puVar3 = *puVar1;
    }
  }
  uVar9 = DAT_554c_445c;
  iVar11 = DAT_554c_436c;
  if ((int)param_1 < 3) {
    if ((int)param_1 < 2) goto LAB_1a9e_29b9;
LAB_1a9e_25f4:
    FUN_1a9e_29f2();
LAB_1a9e_29b9:
    while (uVar9 = DAT_554c_4f1a, DAT_554c_4f1d != '\0') {
      DAT_554c_4f1d = '\0';
      puVar19 = (undefined2 *)&DAT_554c_440c;
      puVar22 = (undefined2 *)&DAT_554c_43bc;
      for (uVar12 = DAT_554c_4f1a >> 1; uVar12 != 0; uVar12 = uVar12 - 1) {
        puVar3 = puVar22;
        puVar22 = puVar22 + 1;
        puVar1 = puVar19;
        puVar19 = puVar19 + 1;
        *puVar3 = *puVar1;
      }
      puVar19 = (undefined2 *)&DAT_554c_4434;
      puVar22 = (undefined2 *)&DAT_554c_43e4;
      for (uVar12 = uVar9 >> 1; uVar12 != 0; uVar12 = uVar12 - 1) {
        puVar3 = puVar22;
        puVar22 = puVar22 + 1;
        puVar1 = puVar19;
        puVar19 = puVar19 + 1;
        *puVar3 = *puVar1;
      }
LAB_1a9e_2810:
      puVar19 = (undefined2 *)&DAT_554c_43bc;
      puVar22 = (undefined2 *)((int)(undefined2 *)&DAT_554c_436c + uVar9);
      uVar12 = uVar9 >> 1;
      do {
        puVar1 = puVar19;
        puVar19 = puVar19 + 1;
        puVar22 = puVar22 + -1;
        *puVar22 = *puVar1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
      puVar19 = (undefined2 *)&DAT_554c_43e4;
      puVar22 = (undefined2 *)((int)(undefined2 *)&DAT_554c_4394 + uVar9);
      uVar12 = uVar9 >> 1;
      do {
        puVar1 = puVar19;
        puVar19 = puVar19 + 1;
        puVar22 = puVar22 + -1;
        *puVar22 = *puVar1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
      DAT_554c_4f04 = (uVar9 - 2) - DAT_554c_4f04;
      DAT_554c_4f06 = (uVar9 - 2) - DAT_554c_4f06;
LAB_1a9e_284d:
      iVar11 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + DAT_554c_4f06);
      uVar21 = 0;
      uVar12 = DAT_554c_4f04;
      while( true ) {
        *(undefined2 *)((int)(undefined2 *)&DAT_554c_43bc + uVar21) =
             *(undefined2 *)((int)(undefined2 *)&DAT_554c_436c + uVar12);
        iVar10 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar12);
        *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar21) = iVar10;
        uVar21 = uVar21 + 2;
        if (iVar11 <= iVar10) break;
        uVar12 = uVar12 + 2 & -(uint)(uVar12 + 2 < uVar9);
      }
      DAT_554c_4f08 = uVar21 >> 1;
      iVar11 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + DAT_554c_4f04);
      uVar12 = DAT_554c_4f06;
      while( true ) {
        *(undefined2 *)((int)(undefined2 *)&DAT_554c_43bc + uVar21) =
             *(undefined2 *)((int)(undefined2 *)&DAT_554c_436c + uVar12);
        iVar10 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar12);
        *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar21) = iVar10;
        iVar14 = DAT_554c_4d74;
        uVar21 = uVar21 + 2;
        if (iVar10 <= iVar11) break;
        uVar12 = uVar12 + 2 & -(uint)(uVar12 + 2 < uVar9);
      }
      DAT_554c_4f0a = (uVar21 >> 1) - DAT_554c_4f08;
      DAT_554c_4f10 = 2;
      DAT_554c_4f0e = 0;
      uVar9 = DAT_554c_4f08;
      while( true ) {
        while (uVar9 = uVar9 - 1, uVar9 != 0) {
          iVar6 = DAT_554c_4f0e + 2;
          iVar11 = *(int *)((int)(undefined2 *)&DAT_554c_43bc + DAT_554c_4f0e);
          iVar10 = *(int *)((int)(undefined2 *)&DAT_554c_43be + DAT_554c_4f0e);
          iVar15 = *(int *)((int)(undefined2 *)&DAT_554c_43e4 + DAT_554c_4f0e);
          uVar21 = iVar11 - iVar10 >> 0xf;
          uVar12 = iVar11 - iVar10 ^ uVar21;
          iVar7 = uVar12 - uVar21;
          DAT_554c_4f0c = uVar9;
          if (uVar12 == uVar21) {
            DAT_554c_4f0e = iVar6;
            FUN_1a9e_2a3e();
            uVar9 = DAT_554c_4f0c;
          }
          else {
            uVar9 = iVar15 - *(int *)((int)(undefined2 *)&DAT_554c_43e6 + DAT_554c_4f0e);
            uVar12 = (int)uVar9 >> 0xf;
            uVar9 = uVar9 ^ uVar12;
            iVar8 = uVar9 - uVar12;
            if (uVar9 == uVar12) {
              iVar7 = iVar11;
              if (iVar10 <= iVar11) {
                iVar7 = iVar10;
                iVar10 = iVar11;
              }
              if (DAT_554c_4f10 != 0) {
                iVar7 = iVar10;
              }
              DAT_554c_4f0e = iVar6;
              *(int *)(iVar15 * 4 + DAT_554c_4f10) = iVar7;
              uVar9 = DAT_554c_4f0c;
            }
            else if (iVar7 < iVar8) {
              DAT_554c_4f0e = iVar6;
              FUN_1a9e_2a5a();
              uVar9 = DAT_554c_4f0c;
            }
            else if (iVar8 < iVar7) {
              if (DAT_554c_4f10 == 0) {
                DAT_554c_4f0e = iVar6;
                FUN_1a9e_2c7b();
                uVar9 = DAT_554c_4f0c;
              }
              else {
                DAT_554c_4f0e = iVar6;
                FUN_1a9e_2bbf();
                uVar9 = DAT_554c_4f0c;
              }
            }
            else {
              DAT_554c_4f0e = iVar6;
              FUN_1a9e_2b98();
              uVar9 = DAT_554c_4f0c;
            }
          }
        }
        if (DAT_554c_4f10 == 0) break;
        DAT_554c_4f0e = DAT_554c_4f0e + 2;
        DAT_554c_4f10 = 0;
        uVar9 = DAT_554c_4f0a;
      }
      iVar11 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + DAT_554c_4f04);
      DAT_554c_4f16 = iVar14;
      iVar10 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + DAT_554c_4f06);
      *(int *)(iVar11 * 4 + 0xc) = iVar11;
      *(int *)(iVar11 * 4 + 0xe) = (iVar10 - iVar11) + 1;
      (*DAT_554c_4de2)(0x1a9e);
      if (DAT_554c_42ce != DAT_554c_42cd) {
        FUN_1a9e_29f2();
      }
    }
    return DAT_554c_4f16;
  }
  if (DAT_554c_42cc == '\0') {
    ((undefined2 *)&DAT_554c_436c)[DAT_554c_445c] = DAT_554c_436c;
    ((undefined2 *)&DAT_554c_4394)[uVar9] = DAT_554c_4394;
    FUN_1a9e_29f2();
    goto LAB_1a9e_29b9;
  }
  if (DAT_554c_42ce != DAT_554c_42cd) {
    DAT_554c_4f18 = DAT_554c_445c;
    piVar18 = (int *)&DAT_554c_436e;
    piVar20 = (int *)&DAT_554c_440e;
    DAT_554c_440c = DAT_554c_436c;
    iVar14 = DAT_554c_445c - 1;
    for (iVar10 = iVar14; iVar10 != 0; iVar10 = iVar10 + -1) {
      piVar4 = piVar20;
      piVar20 = piVar20 + 1;
      piVar2 = piVar18;
      piVar18 = piVar18 + 1;
      *piVar4 = *piVar2;
    }
    *piVar20 = iVar11;
    iVar11 = DAT_554c_4394;
    piVar18 = (int *)&DAT_554c_4396;
    piVar20 = (int *)&DAT_554c_4436;
    DAT_554c_4434 = DAT_554c_4394;
    for (; iVar14 != 0; iVar14 = iVar14 + -1) {
      piVar4 = piVar20;
      piVar20 = piVar20 + 1;
      piVar2 = piVar18;
      piVar18 = piVar18 + 1;
      *piVar4 = *piVar2;
    }
    *piVar20 = iVar11;
  }
  if (DAT_554c_42c3 != '\0') {
    FUN_1a9e_4464();
  }
  if (DAT_554c_445c == 2) goto LAB_1a9e_25f4;
  if ((int)DAT_554c_445c < 2) goto LAB_1a9e_29b9;
  DAT_554c_4f14 = DAT_554c_4394;
  iVar14 = 0x7fff;
  iVar15 = -0x7fff;
  DAT_554c_4f12 = DAT_554c_436c;
  iVar10 = 0x7fff;
  iVar11 = -0x7fff;
  uVar9 = 0;
  DAT_554c_4f04 = 0;
  DAT_554c_4f06 = 0;
  iVar6 = (DAT_554c_445c - 1) * 2;
  do {
    iVar7 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + iVar6);
    if (iVar7 == DAT_554c_4f14) {
      if (*(int *)((int)(undefined2 *)&DAT_554c_436c + iVar6) != DAT_554c_4f12) {
        iVar7 = *(int *)((int)(undefined2 *)&DAT_554c_4394 + iVar6);
        goto LAB_1a9e_26a6;
      }
    }
    else {
LAB_1a9e_26a6:
      DAT_554c_4f14 = iVar7;
      *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar9) = iVar7;
      if ((iVar7 <= iVar14) &&
         ((iVar7 < iVar14 || (iVar11 < *(int *)((int)(undefined2 *)&DAT_554c_436c + iVar6))))) {
        iVar11 = *(int *)((int)(undefined2 *)&DAT_554c_436c + iVar6);
        iVar14 = iVar7;
        DAT_554c_4f04 = uVar9;
      }
      if ((iVar15 <= iVar7) &&
         ((iVar15 < iVar7 || (*(int *)((int)(undefined2 *)&DAT_554c_436c + iVar6) <= iVar10)))) {
        iVar10 = *(int *)((int)(undefined2 *)&DAT_554c_436c + iVar6);
        iVar15 = iVar7;
        DAT_554c_4f06 = uVar9;
      }
      DAT_554c_4f12 = *(int *)((int)(undefined2 *)&DAT_554c_436c + iVar6);
      *(int *)((int)(undefined2 *)&DAT_554c_43bc + uVar9) = DAT_554c_4f12;
      uVar9 = uVar9 + 2;
    }
    iVar7 = DAT_554c_4d74;
    bVar23 = 1 < iVar6;
    iVar6 = iVar6 + -2;
  } while (bVar23);
  if ((iVar14 == iVar15) || (uVar12 = uVar9 >> 1, uVar12 == 2)) {
    if ((DAT_554c_42cd == DAT_554c_42ce) && (iVar15 == iVar14)) {
      *(int *)0x0 = iVar14;
      *(undefined2 *)0x2 = 1;
      iVar14 = iVar11;
      if (iVar11 < iVar10) {
        iVar14 = iVar10;
        iVar10 = iVar11;
      }
      *(int *)0x4 = iVar10;
      *(int *)0x6 = iVar14;
      (*DAT_554c_4de2)(0x1a9e);
    }
    else {
      func_0x00010102(0x1a9e,iVar10,iVar15,iVar11,iVar14);
    }
    goto LAB_1a9e_29b9;
  }
  if (uVar12 < 2) goto LAB_1a9e_29b9;
  uVar21 = DAT_554c_4f04 + 2 & -(uint)(DAT_554c_4f04 + 2 < uVar9);
  uVar13 = *(int *)((int)(undefined2 *)&DAT_554c_43bc + uVar21) -
           *(int *)((int)(undefined2 *)&DAT_554c_43bc + DAT_554c_4f04);
  uVar21 = *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar21) -
           *(int *)((int)(undefined2 *)&DAT_554c_43e4 + DAT_554c_4f04);
  if (uVar21 == 0) {
    uVar21 = 1;
    bVar23 = (int)uVar13 < 0;
    uVar13 = 0x7fff;
    if (bVar23) {
      uVar13 = 0x8001;
    }
  }
  iVar11 = DAT_554c_4f04 - 2;
  if ((int)DAT_554c_4f04 < 2) {
    iVar11 = iVar11 + uVar9;
  }
  uVar5 = *(int *)((int)(undefined2 *)&DAT_554c_43bc + iVar11) -
          *(int *)((int)(undefined2 *)&DAT_554c_43bc + DAT_554c_4f04);
  uVar16 = *(int *)((int)(undefined2 *)&DAT_554c_43e4 + iVar11) -
           *(int *)((int)(undefined2 *)&DAT_554c_43e4 + DAT_554c_4f04);
  DAT_554c_445c = uVar12;
  if (uVar16 == 0) {
    uVar16 = 1;
    uVar12 = 0x8001;
    uVar17 = uVar16;
    if (-1 < (int)uVar5) {
      uVar5 = 0x7fff;
      goto LAB_1a9e_2794;
    }
LAB_1a9e_279e:
    if (-1 < (int)uVar13) goto LAB_1a9e_27f3;
    uVar5 = -uVar13;
    uVar13 = -uVar12;
    uVar16 = uVar21;
    uVar21 = uVar17;
  }
  else {
LAB_1a9e_2794:
    uVar12 = uVar5;
    uVar17 = uVar16;
    if ((int)uVar5 < 0) goto LAB_1a9e_279e;
    if ((int)uVar13 < 1) goto LAB_1a9e_2810;
  }
  if (uVar13 / uVar21 <= uVar5 / uVar16) {
    if (uVar13 / uVar21 < uVar5 / uVar16) goto LAB_1a9e_2810;
    uVar12 = (uint)(((ulong)uVar13 % (ulong)uVar21 << 0x10) / (ulong)uVar21);
    uVar21 = (uint)(((ulong)uVar5 % (ulong)uVar16 << 0x10) / (ulong)uVar16);
    if (uVar12 < uVar21) goto LAB_1a9e_2810;
    if (uVar12 == uVar21) {
      DAT_554c_4f1d = '\x01';
      puVar19 = (undefined2 *)&DAT_554c_43bc;
      puVar22 = (undefined2 *)&DAT_554c_440c;
      DAT_554c_4f1a = uVar9;
      for (uVar12 = uVar9 >> 1; uVar12 != 0; uVar12 = uVar12 - 1) {
        puVar3 = puVar22;
        puVar22 = puVar22 + 1;
        puVar1 = puVar19;
        puVar19 = puVar19 + 1;
        *puVar3 = *puVar1;
      }
      puVar19 = (undefined2 *)&DAT_554c_43e4;
      puVar22 = (undefined2 *)&DAT_554c_4434;
      for (uVar12 = uVar9 >> 1; uVar12 != 0; uVar12 = uVar12 - 1) {
        puVar3 = puVar22;
        puVar22 = puVar22 + 1;
        puVar1 = puVar19;
        puVar19 = puVar19 + 1;
        *puVar3 = *puVar1;
      }
    }
  }
LAB_1a9e_27f3:
  puVar19 = (undefined2 *)&DAT_554c_43bc;
  puVar22 = (undefined2 *)&DAT_554c_436c;
  for (uVar12 = uVar9 >> 1; uVar12 != 0; uVar12 = uVar12 - 1) {
    puVar3 = puVar22;
    puVar22 = puVar22 + 1;
    puVar1 = puVar19;
    puVar19 = puVar19 + 1;
    *puVar3 = *puVar1;
  }
  puVar19 = (undefined2 *)&DAT_554c_43e4;
  puVar22 = (undefined2 *)&DAT_554c_4394;
  uVar12 = uVar9 >> 1;
  do {
    if (uVar12 == 0) goto LAB_1a9e_284d;
    uVar12 = uVar12 - 1;
    puVar3 = puVar22;
    puVar22 = puVar22 + 1;
    puVar1 = puVar19;
    puVar19 = puVar19 + 1;
    *puVar3 = *puVar1;
  } while( true );
}

