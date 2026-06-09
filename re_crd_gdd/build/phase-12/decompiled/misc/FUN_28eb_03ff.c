// TIM2.EXE: FUN_28eb_03ff @ file 0x02E4AF Ghidra 0x292AF
// Subsystem: misc | Size: 809 bytes


undefined2 __cdecl16far FUN_28eb_03ff(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined2 uVar14;
  int in_DX;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  undefined4 uVar19;
  int local_16;
  uint local_8;
  uint local_6;
  int *local_4;
  
  uVar14 = 0x28eb;
  if (((((int)param_1 == 0 && param_1._2_2_ == 0) && ((int)param_2 != 0 || param_2._2_2_ != 0)) &&
      ((*(int *)((int)param_2 + 0x98) == 0 || (*(int *)((int)param_2 + 8) == 0x15)))) &&
     ((((*(int *)((int)param_2 + 0x22) - DAT_5b41_0925 <= DAT_5b41_1b84 &&
        (DAT_5b41_1b84 <
         (*(int *)((int)param_2 + 0x22) + *(int *)((int)param_2 + 0x44)) - DAT_5b41_0925)) &&
       (*(int *)((int)param_2 + 0x24) - DAT_5b41_0927 <= DAT_5b41_1b86)) &&
      (DAT_5b41_1b86 <
       (*(int *)((int)param_2 + 0x24) + *(int *)((int)param_2 + 0x46)) - DAT_5b41_0927)))) {
    iVar9 = FUN_28eb_0728((int)param_2,param_2._2_2_,DAT_5b41_04ec,DAT_5b41_04ee);
    if ((in_DX == param_2._2_2_) && (iVar9 == (int)param_2)) {
      uVar14 = 1;
    }
    else {
      uVar14 = 0;
    }
  }
  else if ((((int)param_1 == 0 && param_1._2_2_ == 0) ||
           ((*(int *)((int)param_1 + 0x98) != 0 && (*(int *)((int)param_1 + 0x96) != 0)))) &&
          (((int)param_2 != 0 || param_2._2_2_ != 0 &&
           ((*(int *)((int)param_2 + 0x98) != 0 && (*(int *)((int)param_2 + 0x96) != 0)))))) {
    if ((int)param_1 == 0 && param_1._2_2_ == 0) {
      uVar15 = DAT_5b41_1b84 + DAT_5b41_0925;
      uVar16 = DAT_5b41_1b86 + DAT_5b41_0927;
    }
    else {
      uVar15 = *(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x44) / 2;
      uVar16 = *(int *)((int)param_1 + 0x24) + *(int *)((int)param_1 + 0x46) / 2;
    }
    bVar6 = false;
    bVar8 = false;
    bVar5 = false;
    bVar7 = false;
    iVar9 = *(int *)((int)param_2 + 0x22);
    iVar2 = *(int *)((int)param_2 + 0x24);
    local_4 = (int *)*(int *)((int)param_2 + 0x98);
    local_16 = *(int *)((int)param_2 + 0x96);
    local_8 = local_4[local_16 * 3 + -3] + iVar9;
    local_6 = local_4[local_16 * 3 + -2] + iVar2;
    do {
      iVar1 = local_16 + -1;
      if (local_16 == 0) goto LAB_28eb_0722;
      uVar10 = *local_4 + iVar9;
      uVar11 = local_4[1] + iVar2;
      local_4 = local_4 + 3;
      if ((((int)uVar15 < (int)local_8) || ((int)uVar10 < (int)uVar15)) &&
         (((int)uVar15 < (int)uVar10 || ((int)local_8 < (int)uVar15)))) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if ((((int)uVar16 < (int)local_6) || ((int)uVar11 < (int)uVar16)) &&
         (((int)uVar16 < (int)uVar11 || ((int)local_6 < (int)uVar16)))) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if ((bVar3) || (bVar4)) {
        if ((bVar4) && (!bVar3)) {
          if ((int)uVar16 < (int)local_6) {
            bVar8 = true;
          }
          else {
            bVar7 = true;
          }
        }
        if ((bVar3) && (!bVar4)) {
          if ((int)uVar15 < (int)local_8) {
            bVar6 = true;
          }
          else {
            bVar5 = true;
          }
        }
        if ((bVar3) && (bVar4)) {
          iVar12 = local_8 - uVar10;
          iVar13 = local_6 - uVar11;
          if (iVar12 != 0) {
            iVar17 = iVar12 >> 0xf;
            uVar19 = FUN_1000_18f0(uVar14,iVar13 * uVar15,(int)(iVar13 * uVar15) >> 0xf,iVar12);
            uVar18 = (int)((ulong)uVar19 >> 0x10) + ((int)local_6 >> 0xf) +
                     (uint)CARRY2((uint)uVar19,local_6);
            uVar14 = 0x1000;
            uVar19 = FUN_1000_18f0(0x1000,iVar13 * local_8,(int)(iVar13 * local_8) >> 0xf,iVar12);
            iVar17 = (iVar17 - (int)((ulong)uVar19 >> 0x10)) - (uint)(uVar18 < (uint)uVar19);
            if (((int)uVar16 >> 0xf < iVar17) ||
               (((int)uVar16 >> 0xf <= iVar17 && (uVar16 <= uVar18 - (uint)uVar19)))) {
              bVar8 = true;
            }
            else {
              bVar7 = true;
            }
          }
          if (iVar13 != 0) {
            iVar17 = iVar13 >> 0xf;
            uVar19 = FUN_1000_18f0(uVar14,iVar12 * uVar16,(int)(iVar12 * uVar16) >> 0xf,iVar13);
            uVar18 = (int)((ulong)uVar19 >> 0x10) + ((int)local_8 >> 0xf) +
                     (uint)CARRY2((uint)uVar19,local_8);
            uVar14 = 0x1000;
            uVar19 = FUN_1000_18f0(0x1000,iVar12 * local_6,(int)(iVar12 * local_6) >> 0xf,iVar13);
            iVar12 = (iVar17 - (int)((ulong)uVar19 >> 0x10)) - (uint)(uVar18 < (uint)uVar19);
            if (((int)uVar15 >> 0xf < iVar12) ||
               (((int)uVar15 >> 0xf <= iVar12 && (uVar15 <= uVar18 - (uint)uVar19)))) {
              bVar6 = true;
            }
            else {
              bVar5 = true;
            }
          }
        }
      }
      local_16 = iVar1;
      local_8 = uVar10;
      local_6 = uVar11;
    } while ((((!bVar5) || (!bVar6)) || (!bVar7)) || (!bVar8));
    uVar14 = 1;
  }
  else {
LAB_28eb_0722:
    uVar14 = 0;
  }
  return uVar14;
}

