// TIM2.EXE: FUN_2424_31e8 @ file 0x02C628 Ghidra 0x27428
// Subsystem: misc | Size: 951 bytes


void __cdecl16far FUN_2424_31e8(uint param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined2 uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  
  if (DAT_5b41_04b8 == 0) {
    for (iVar10 = 0; iVar10 < 0xd; iVar10 = iVar10 + 1) {
      uVar11 = FUN_4551_0370(DAT_5b41_050d,*(undefined2 *)(iVar10 * 2 + 0x2c8));
      ((undefined2 *)&DAT_5b41_04d2)[iVar10] = uVar11;
      ((undefined2 *)&DAT_5b41_04b8)[iVar10] = uVar11;
    }
  }
  if (DAT_5b41_050b != DAT_5b41_04b6) {
    if (DAT_5b41_04b6 != 0xe) {
      ((undefined2 *)&DAT_5b41_04d2)[DAT_5b41_04b6] = ((undefined2 *)&DAT_5b41_04b8)[DAT_5b41_04b6];
    }
    if (DAT_5b41_050b != 0xe) {
      ((undefined2 *)&DAT_5b41_04d2)[DAT_5b41_050b] = ((undefined2 *)&DAT_5b41_04b8)[DAT_5b41_050b];
    }
    DAT_5b41_04b6 = DAT_5b41_050b;
  }
  FUN_2424_02ca();
  if (DAT_5b41_050b != 0xe) {
    ((undefined2 *)&DAT_5b41_04d2)[DAT_5b41_050b] =
         ((undefined2 *)&DAT_5b41_04d2)[DAT_5b41_050b] + 1;
    iVar10 = FUN_4551_0308(DAT_5b41_050d,((undefined2 *)&DAT_5b41_04d2)[DAT_5b41_050b]);
    if (iVar10 != 0) {
      ((undefined2 *)&DAT_5b41_04d2)[DAT_5b41_050b] = ((undefined2 *)&DAT_5b41_04b8)[DAT_5b41_050b];
    }
  }
  uVar11 = (undefined2)((ulong)param_2 >> 0x10);
  piVar9 = (int *)param_2;
  iVar10 = *param_2;
  iVar2 = iVar10 + -0x24;
  iVar3 = piVar9[1] + -0x24;
  iVar4 = (piVar9[2] + -0x24) / 2 + *param_2;
  iVar8 = piVar9[1] + (piVar9[3] + -0x24) / 2;
  iVar5 = piVar9[2] + *param_2;
  iVar6 = piVar9[1] + piVar9[3];
  bVar12 = (param_1 & 0x40) != 0;
  if (bVar12) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e0,iVar2,iVar3,0);
  }
  bVar13 = (param_1 & 0x3000) != 0;
  if (bVar13) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e8,iVar5,iVar3,0);
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04ea,iVar5,iVar6,0);
  }
  bVar14 = (param_1 & 1) != 0;
  if (bVar14) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04d2,iVar2,iVar8,0);
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04d4,iVar5,iVar8,0);
  }
  bVar15 = (param_1 & 2) != 0;
  if (bVar15) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04d6,iVar4,iVar3,0);
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04d8,iVar4,iVar6,0);
  }
  bVar16 = (param_1 & 0xc) != 0;
  if (bVar16) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04da,iVar2,iVar6,0);
  }
  bVar17 = (param_1 & 0x20) != 0;
  if (bVar17) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e4,iVar5,iVar6,0);
  }
  bVar18 = (param_1 & 0x200) != 0;
  if (bVar18) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e6,iVar4,iVar3,0);
  }
  bVar18 = bVar18 || (bVar15 || (bVar13 || bVar12));
  bVar19 = (param_1 & 0x80) != 0;
  if (bVar19) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e2,iVar5,iVar8,0);
  }
  bVar1 = bVar19 || (bVar17 || (bVar14 || bVar13));
  bVar20 = (param_1 & 0x800) != 0;
  if (bVar20) {
    FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e2,iVar10 + -0x14,iVar6 + -8,0);
  }
  bVar13 = bVar20 || (bVar19 || (bVar17 || (bVar16 || (bVar15 || bVar13))));
  bVar20 = bVar20 || (bVar16 || (bVar14 || bVar12));
  if ((param_1 & 0x410) != 0) {
    bVar12 = (param_1 & 0x400) == 0;
    if ((bVar12) || (iVar5 < DAT_5b41_051d + -0x12)) {
      bVar1 = true;
      DAT_5b41_0513 = iVar5;
    }
    else {
      DAT_5b41_0513 = iVar10 + -0x12;
      bVar20 = true;
    }
    if ((bVar12) || (-0x13 < iVar3)) {
      bVar18 = true;
      DAT_5b41_0515 = iVar3;
    }
    else {
      DAT_5b41_0515 = iVar6 + -0x12;
      DAT_5b41_0513 = iVar10 + -0x12;
      bVar20 = true;
      bVar13 = true;
    }
    uVar7 = DAT_5b41_04dc;
    if (!bVar12) {
      uVar7 = DAT_5b41_04de;
    }
    FUN_4551_01dc(DAT_5b41_050d,uVar7,DAT_5b41_0513,DAT_5b41_0515,0);
  }
  if (bVar20) {
    *param_2 = *param_2 + -0x24;
    piVar9[2] = piVar9[2] + 0x24;
  }
  if (bVar18) {
    piVar9[1] = piVar9[1] + -0x24;
    piVar9[3] = piVar9[3] + 0x24;
  }
  if (bVar1) {
    piVar9[2] = piVar9[2] + 0x24;
  }
  if (bVar13) {
    piVar9[3] = piVar9[3] + 0x24;
  }
  return;
}

