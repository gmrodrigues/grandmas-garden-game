// TIM2.EXE: FUN_1a9e_2bbf @ file 0x02279F Ghidra 0x1D59F
// Subsystem: level | Size: 187 bytes


void __cdecl16near FUN_1a9e_2bbf(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_CX;
  int iVar4;
  int in_BX;
  int unaff_BP;
  int iVar5;
  int iVar6;
  int unaff_SI;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined2 unaff_ES;
  bool bVar10;
  
  iVar5 = in_CX;
  iVar2 = in_BX;
  if (in_BX <= unaff_BP) {
    iVar5 = unaff_SI;
    iVar2 = unaff_BP;
    unaff_BP = in_BX;
    unaff_SI = in_CX;
  }
  piVar9 = (int *)((iVar5 * 2 + 1) * 2);
  iVar4 = 2;
  iVar7 = unaff_SI - iVar5;
  if (unaff_SI < iVar5) {
    iVar7 = -iVar7;
    iVar4 = -6;
  }
  iVar5 = unaff_BP - iVar2;
  if (iVar5 != 0 && iVar2 <= unaff_BP) {
    iVar5 = -iVar5;
  }
  iVar6 = (iVar5 + iVar7) * 2;
  iVar8 = iVar7 * 2;
  iVar5 = iVar5 + iVar8;
  *piVar9 = iVar2;
  piVar9 = (int *)((int)piVar9 + iVar4 + 2);
  iVar2 = iVar2 + -1;
  iVar3 = iVar2;
  iVar1 = iVar7;
  if (iVar5 < 0) goto LAB_1a9e_2bf8;
LAB_1a9e_2c26:
  *piVar9 = iVar2;
  piVar9 = (int *)((int)piVar9 + iVar4 + 2);
  if (iVar7 + -1 != 0) {
    bVar10 = SCARRY2(iVar5,iVar6);
    iVar5 = iVar5 + iVar6;
    iVar3 = iVar2 + -1;
    iVar1 = iVar7 + -1;
    if (bVar10 != iVar5 < 0) goto LAB_1a9e_2bf8;
    *piVar9 = iVar2 + -1;
    piVar9 = (int *)((int)piVar9 + iVar4 + 2);
    if (iVar7 + -2 != 0) {
      bVar10 = SCARRY2(iVar5,iVar6);
      iVar5 = iVar5 + iVar6;
      iVar3 = iVar2 + -2;
      iVar1 = iVar7 + -2;
      if (bVar10 != iVar5 < 0) goto LAB_1a9e_2bf8;
      *piVar9 = iVar2 + -2;
      piVar9 = (int *)((int)piVar9 + iVar4 + 2);
      if (iVar7 + -3 != 0) {
        bVar10 = SCARRY2(iVar5,iVar6);
        iVar5 = iVar5 + iVar6;
        iVar3 = iVar2 + -3;
        iVar1 = iVar7 + -3;
        if (bVar10 != iVar5 < 0) goto LAB_1a9e_2bf8;
        *piVar9 = iVar2 + -3;
        piVar9 = (int *)((int)piVar9 + iVar4 + 2);
        if (iVar7 + -4 != 0) {
          bVar10 = SCARRY2(iVar5,iVar6);
          iVar5 = iVar5 + iVar6;
          iVar3 = iVar2 + -4;
          iVar1 = iVar7 + -4;
          if (bVar10 != iVar5 < 0) goto LAB_1a9e_2bf8;
          *piVar9 = iVar2 + -4;
          piVar9 = (int *)((int)piVar9 + iVar4 + 2);
          if (iVar7 + -5 != 0) {
            bVar10 = SCARRY2(iVar5,iVar6);
            iVar5 = iVar5 + iVar6;
            iVar3 = iVar2 + -5;
            iVar1 = iVar7 + -5;
            if (bVar10 != iVar5 < 0) goto LAB_1a9e_2bf8;
            *piVar9 = iVar2 + -5;
            piVar9 = (int *)((int)piVar9 + iVar4 + 2);
            if (iVar7 + -6 != 0) {
              bVar10 = SCARRY2(iVar5,iVar6);
              iVar5 = iVar5 + iVar6;
              iVar3 = iVar2 + -6;
              iVar1 = iVar7 + -6;
              if (bVar10 != iVar5 < 0) goto LAB_1a9e_2bf8;
              *piVar9 = iVar2 + -6;
              piVar9 = (int *)((int)piVar9 + iVar4 + 2);
              if (iVar7 + -7 != 0) {
                bVar10 = SCARRY2(iVar5,iVar6);
                iVar5 = iVar5 + iVar6;
                iVar3 = iVar2 + -7;
                iVar1 = iVar7 + -7;
                if (bVar10 != iVar5 < 0) goto LAB_1a9e_2bf8;
                *piVar9 = iVar2 + -7;
                piVar9 = (int *)((int)piVar9 + iVar4 + 2);
                iVar2 = iVar2 + -8;
                iVar7 = iVar7 + -8;
                if (iVar7 != 0) goto LAB_1a9e_2c22;
              }
            }
          }
        }
      }
    }
  }
  return;
LAB_1a9e_2c22:
  bVar10 = SCARRY2(iVar5,iVar6);
  iVar5 = iVar5 + iVar6;
  iVar3 = iVar2;
  iVar1 = iVar7;
  if (bVar10 != iVar5 < 0) {
LAB_1a9e_2bf8:
    do {
      iVar7 = iVar1;
      iVar2 = iVar3 + -1;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      if (bVar10 == iVar5 < 0) break;
      iVar2 = iVar3 + -2;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      if (bVar10 == iVar5 < 0) break;
      iVar2 = iVar3 + -3;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      if (bVar10 == iVar5 < 0) break;
      iVar2 = iVar3 + -4;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      if (bVar10 == iVar5 < 0) break;
      iVar2 = iVar3 + -5;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      if (bVar10 == iVar5 < 0) break;
      iVar2 = iVar3 + -6;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      if (bVar10 == iVar5 < 0) break;
      iVar2 = iVar3 + -7;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      if (bVar10 == iVar5 < 0) break;
      iVar2 = iVar3 + -8;
      bVar10 = SCARRY2(iVar5,iVar8);
      iVar5 = iVar5 + iVar8;
      iVar3 = iVar2;
      iVar1 = iVar7;
    } while (bVar10 != iVar5 < 0);
  }
  goto LAB_1a9e_2c26;
}

