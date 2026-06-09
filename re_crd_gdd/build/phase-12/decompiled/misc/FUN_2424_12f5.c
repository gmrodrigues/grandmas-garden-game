// TIM2.EXE: FUN_2424_12f5 @ file 0x02A735 Ghidra 0x25535
// Subsystem: misc | Size: 595 bytes


void __cdecl16far FUN_2424_12f5(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined2 *puVar12;
  undefined2 uVar13;
  int local_22;
  int iStack_20;
  int local_1e;
  int iStack_1c;
  uint local_1a;
  uint local_18;
  int local_16;
  int local_e;
  int local_c;
  
  uVar13 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = *(int *)((int)param_1 + 0x76);
  iVar3 = *(int *)(iVar2 + 6);
  iVar4 = *(int *)(iVar2 + 4);
  iVar5 = *(int *)(iVar2 + 10);
  iVar6 = *(int *)(iVar2 + 8);
  local_18 = (uint)*(byte *)(iVar2 + 0x14);
  local_1a = 0;
  iVar11 = iVar4 + local_18 * 4;
  iStack_20 = *(int *)(iVar11 + 0x60);
  local_22 = *(int *)(iVar11 + 0x5e);
  local_16 = FUN_28eb_3b36(iVar4,iVar3,iVar2,3);
  local_1e = iVar4;
  iStack_1c = iVar3;
  do {
    if ((local_1e == 0 && iStack_1c == 0) || (local_22 == 0 && iStack_20 == 0)) {
      return;
    }
    if ((iStack_1c != iVar3) || (local_1e != iVar4)) {
      local_18 = 1;
      local_16 = 0;
    }
    iVar8 = *(int *)(local_1e + 0x2e) + (int)*(char *)(local_1e + local_18 * 2 + 0x7a);
    iVar11 = *(int *)(local_1e + 0x30) + (int)*(char *)(local_1e + local_18 * 2 + 0x7b);
    if ((iStack_20 == iVar5) && (local_22 == iVar6)) {
      local_1a = (uint)*(byte *)(iVar2 + 0x15);
      local_16 = FUN_28eb_3b36(local_1e,iStack_1c,iVar2,3);
    }
    iVar9 = *(int *)(local_22 + 0x2e) + (int)*(char *)(local_22 + local_1a * 2 + 0x7a);
    iVar10 = *(int *)(local_22 + 0x30) + (int)*(char *)(local_22 + local_1a * 2 + 0x7b);
    if (iVar8 < iVar9) {
      local_c = iVar8 - DAT_5b41_0925;
      iVar8 = iVar9;
    }
    else {
      local_c = iVar9 - DAT_5b41_0925;
    }
    if (iVar11 < iVar10) {
      local_e = iVar11 - DAT_5b41_0927;
      iVar11 = iVar10;
    }
    else {
      local_e = iVar10 - DAT_5b41_0927;
    }
    iVar11 = iVar11 - DAT_5b41_0927;
    if (0 < local_16) {
      iVar11 = iVar11 + (local_16 >> 1);
    }
    uVar7 = (uint)((iVar8 - DAT_5b41_0925) - local_c < iVar11 - local_e);
    for (puVar12 = DAT_5b41_04ac; puVar12 != (undefined2 *)0x0; puVar12 = (undefined2 *)*puVar12) {
      if ((((puVar12[6] == 1) && ((int)puVar12[1] <= (int)((iVar8 - DAT_5b41_0925) + uVar7))) &&
          ((int)(local_c - uVar7) <= (int)puVar12[3])) &&
         (((int)puVar12[2] <= (int)(iVar11 + (uint)(uVar7 == 0)) &&
          ((int)(local_e - (uint)(uVar7 == 0)) <= (int)puVar12[4])))) {
        FUN_28eb_2d82((int)param_1,uVar13,0x81);
        local_22 = iVar6;
        iStack_20 = iVar5;
        break;
      }
    }
    if ((iStack_20 == iVar5) && (local_22 == iVar6)) {
      local_22 = 0;
      iStack_20 = 0;
      local_1e = 0;
      iStack_1c = 0;
    }
    else {
      local_1e = local_22;
      iStack_1c = iStack_20;
      piVar1 = (int *)(local_22 + 0x60);
      local_22 = *(int *)(local_22 + 0x5e);
      iStack_20 = *piVar1;
    }
  } while( true );
}

