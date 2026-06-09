// TIM2.EXE: FUN_28eb_3ccf @ file 0x031D7F Ghidra 0x2CB7F
// Subsystem: misc | Size: 1744 bytes


undefined2 __cdecl16far FUN_28eb_3ccf(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint extraout_DX;
  uint extraout_DX_00;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int local_2c;
  undefined2 local_28;
  int local_24;
  undefined2 local_1e;
  undefined1 local_1c [2];
  undefined1 local_1a [2];
  int local_18;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  uint local_c;
  uint local_a;
  uint local_8;
  int local_6;
  int local_4;
  
  uVar18 = (uint)((ulong)param_1 >> 0x10);
  iVar15 = (int)param_1;
  iVar11 = *(int *)((int)*(undefined4 *)(iVar15 + 0x5e) + 8);
  if (*(int *)(iVar15 + 0x24) < *(int *)(iVar15 + 0x28)) {
    local_24 = 0;
  }
  else if (*(int *)(iVar15 + 0x28) < *(int *)(iVar15 + 0x24)) {
    local_24 = 1;
  }
  else {
    local_24 = -1;
  }
  piVar2 = (int *)*(int *)(iVar15 + 0x76);
  iVar14 = piVar2[1];
  iVar3 = *piVar2;
  iVar17 = iVar14;
  iVar6 = FUN_28eb_396b(iVar15,uVar18,piVar2);
  uVar10 = piVar2[3];
  if ((uVar10 == uVar18) && (piVar2[2] == iVar15)) {
    local_1e = 0;
    cVar1 = *(char *)((int)piVar2 + 0x15);
    local_4 = *(int *)(iVar3 + 0xae);
    local_c = *(uint *)(iVar3 + 0xb4);
  }
  else {
    local_1e = 1;
    cVar1 = (char)piVar2[10];
    local_4 = *(int *)(iVar3 + 0xb4);
    local_c = *(uint *)(iVar3 + 0xae);
  }
  local_e = FUN_28eb_443a(piVar2,iVar6,iVar17,local_1a,local_1c);
  local_6 = FUN_28eb_443a(piVar2,iVar15,uVar18,&local_12,&local_14);
  local_8 = local_6 - local_4;
  if (((*(int *)(iVar15 + 8) != 0x31) && (local_a = local_e - local_c, 0 < (int)local_8)) &&
     ((int)local_a < 0)) {
    uVar10 = local_8 + local_a;
    if ((int)uVar10 < 1) {
      local_8 = 0;
      local_a = uVar10;
    }
    else {
      local_a = 0;
      local_8 = uVar10;
    }
    uVar10 = piVar2[3];
    if ((uVar10 == uVar18) && (piVar2[2] == iVar15)) {
      local_4 = local_6 - local_8;
      *(int *)(iVar3 + 0xae) = local_4;
      local_c = local_e - local_a;
      *(uint *)(iVar3 + 0xb4) = local_c;
    }
    else {
      local_4 = local_6 - local_8;
      *(int *)(iVar3 + 0xb4) = local_4;
      local_c = local_e - local_a;
      *(uint *)(iVar3 + 0xae) = local_c;
    }
  }
  if (((0 < (int)local_8) && ((*(byte *)(iVar6 + 0xb) & 0x10) != 0)) &&
     ((*(int *)(iVar6 + 8) != 0x31 &&
      ((*(int *)(iVar15 + 8) != 0x31 && (*(int *)(iVar6 + 0x3e) < *(int *)(iVar15 + 0x3e))))))) {
    uVar12 = (int)local_8 >> 0xf;
    uVar7 = FUN_2fc8_152f((local_8 ^ uVar12) - uVar12,
                          *(int *)(iVar15 + 0x3e) - *(int *)(iVar6 + 0x3e));
    iVar13 = *(int *)(iVar15 + 0x3e) >> 0xf;
    uVar10 = *(uint *)(iVar15 + 0x3e);
    local_2c = FUN_1000_18f0((undefined2 *)&DAT_554c_2fc8,uVar10 + uVar7,
                             ((int)uVar10 >> 0xf) + uVar12 + (uint)CARRY2(uVar10,uVar7),
                             *(int *)(iVar15 + 0x3e));
    uVar7 = (int)local_c >> 0xf;
    uVar10 = (local_c ^ uVar7) - uVar7;
    iVar16 = local_2c;
    if (local_2c < 2) {
      iVar16 = 1;
    }
    if (iVar16 < (int)uVar10) {
      if (local_2c < 2) {
        local_2c = 1;
      }
    }
    else {
      local_2c = (local_c ^ uVar7) - uVar7;
      uVar10 = uVar7;
    }
    if (local_2c != 0) {
      if ((piVar2[3] == uVar18) && (piVar2[2] == iVar15)) {
        *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) - local_2c;
        local_c = *(uint *)(iVar3 + 0xb4);
        FUN_28eb_3ccf(iVar6,iVar17,iVar13);
        *(uint *)(iVar6 + 10) = *(uint *)(iVar6 + 10) & 0xfff0;
        FUN_549b_005c(0x1000,iVar6,iVar17);
        uVar10 = extraout_DX;
        local_e = FUN_28eb_443a(piVar2,iVar6,iVar17,local_1a,local_1c);
        local_a = local_e - local_c;
        if (local_a != 0) {
          *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + local_a;
          local_2c = local_2c - local_a;
        }
        if (local_2c != 0) {
          *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) + local_2c;
          local_4 = *(int *)(iVar3 + 0xae);
LAB_28eb_4023:
          local_8 = local_6 - local_4;
        }
      }
      else {
        *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) - local_2c;
        local_c = *(uint *)(iVar3 + 0xae);
        FUN_28eb_3ccf(iVar6,iVar17,iVar13);
        *(uint *)(iVar6 + 10) = *(uint *)(iVar6 + 10) & 0xfff0;
        FUN_549b_005c(0x1000,iVar6,iVar17);
        uVar10 = extraout_DX_00;
        local_e = FUN_28eb_443a(piVar2,iVar6,iVar17,local_1a,local_1c);
        local_a = local_e - local_c;
        if (local_a != 0) {
          *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) + local_a;
          local_2c = local_2c - local_a;
        }
        if (local_2c != 0) {
          *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + local_2c;
          local_4 = *(int *)(iVar3 + 0xb4);
          goto LAB_28eb_4023;
        }
      }
    }
  }
  if ((int)local_8 < 1) {
    return 0;
  }
  if ((*(int *)(iVar6 + 8) == 0x31) && (*(int *)(iVar15 + 8) != 0x31)) {
    if (iVar11 != 7) {
      return 0;
    }
    if ((piVar2[3] == iVar17) && (piVar2[2] == iVar6)) {
      *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) - local_8;
      uVar8 = DAT_5b41_0937;
      if (*(int *)(iVar3 + 0xae) < 0) {
        local_8 = local_8 + *(int *)(iVar3 + 0xae);
        DAT_5b41_0937 = 0x1000;
        FUN_2424_0a23(iVar3,iVar14,3);
        iVar11 = iVar6 + (uint)*(byte *)(piVar2 + 10) * 4;
        uVar9 = *(undefined2 *)(iVar11 + 0x60);
        iVar11 = *(int *)(iVar11 + 0x5e);
        uVar4 = *(undefined2 *)(iVar11 + 0x60);
        iVar15 = *(int *)(iVar11 + 0x5e);
        DAT_5b41_0937 = uVar8;
        local_10 = FUN_28eb_3930(iVar11,uVar9,iVar15,uVar4);
        iVar16 = iVar6 + (uint)*(byte *)(piVar2 + 10) * 4;
        *(undefined2 *)(iVar16 + 0x60) = uVar4;
        *(int *)(iVar16 + 0x5e) = iVar15;
        iVar15 = iVar15 + local_10 * 4;
        *(int *)(iVar15 + 0x60) = iVar17;
        *(int *)(iVar15 + 0x5e) = iVar6;
        for (iVar15 = 0; iVar15 < 2; iVar15 = iVar15 + 1) {
          iVar17 = iVar11 + iVar15 * 4;
          *(undefined2 *)(iVar17 + 0x60) = 0;
          *(undefined2 *)(iVar17 + 0x5e) = 0;
        }
        uVar8 = FUN_28eb_399d(piVar2,3,0);
        *(undefined2 *)((int)*(undefined4 *)piVar2 + 0xae) = uVar8;
      }
      *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + local_8;
      return 0;
    }
    *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) - local_8;
    uVar8 = DAT_5b41_0937;
    if (*(int *)(iVar3 + 0xb4) < 0) {
      local_8 = local_8 + *(int *)(iVar3 + 0xb4);
      DAT_5b41_0937 = 0x1000;
      FUN_2424_0a23(iVar3,iVar14,3);
      iVar11 = iVar6 + (uint)*(byte *)((int)piVar2 + 0x15) * 4;
      uVar9 = *(undefined2 *)(iVar11 + 0x60);
      iVar11 = *(int *)(iVar11 + 0x5e);
      uVar4 = *(undefined2 *)(iVar11 + 100);
      iVar15 = *(int *)(iVar11 + 0x62);
      DAT_5b41_0937 = uVar8;
      local_10 = FUN_28eb_3930(iVar11,uVar9,iVar15,uVar4);
      iVar16 = iVar6 + (uint)*(byte *)((int)piVar2 + 0x15) * 4;
      *(undefined2 *)(iVar16 + 0x60) = uVar4;
      *(int *)(iVar16 + 0x5e) = iVar15;
      iVar15 = iVar15 + local_10 * 4;
      *(int *)(iVar15 + 0x60) = iVar17;
      *(int *)(iVar15 + 0x5e) = iVar6;
      for (iVar15 = 0; iVar15 < 2; iVar15 = iVar15 + 1) {
        iVar17 = iVar11 + iVar15 * 4;
        *(undefined2 *)(iVar17 + 0x60) = 0;
        *(undefined2 *)(iVar17 + 0x5e) = 0;
      }
      uVar8 = FUN_28eb_399d(piVar2,3,1);
      *(undefined2 *)((int)*(undefined4 *)piVar2 + 0xb4) = uVar8;
    }
    *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) + local_8;
    return 0;
  }
  uVar8 = FUN_2fc8_152f(local_12,local_4);
  iVar14 = local_6 >> 0xf;
  local_16 = FUN_1000_18f0((undefined2 *)&DAT_554c_2fc8,uVar8,uVar10,local_6);
  *(int *)(iVar15 + 0x22) = *(int *)(iVar15 + 0x22) + (local_16 - local_12);
  iVar11 = *(int *)(iVar15 + 0x22);
  *(int *)(iVar15 + 0x1c) = iVar11 >> 0xf;
  *(int *)(iVar15 + 0x1a) = iVar11;
  uVar8 = *(undefined2 *)(iVar15 + 0x1c);
  uVar9 = FUN_1000_199e(iVar14);
  *(undefined2 *)(iVar15 + 0x1c) = uVar8;
  *(undefined2 *)(iVar15 + 0x1a) = uVar9;
  uVar9 = FUN_2fc8_152f(local_14,local_4);
  iVar14 = local_6 >> 0xf;
  local_18 = FUN_1000_18f0((undefined2 *)&DAT_554c_2fc8,uVar9,uVar8,local_6);
  *(int *)(iVar15 + 0x24) = *(int *)(iVar15 + 0x24) + (local_18 - local_14);
  iVar11 = *(int *)(iVar15 + 0x24);
  *(int *)(iVar15 + 0x20) = iVar11 >> 0xf;
  *(int *)(iVar15 + 0x1e) = iVar11;
  uVar8 = *(undefined2 *)(iVar15 + 0x20);
  uVar9 = FUN_1000_199e(iVar14);
  *(undefined2 *)(iVar15 + 0x20) = uVar8;
  *(undefined2 *)(iVar15 + 0x1e) = uVar9;
  FUN_28eb_3328(iVar15,uVar18);
  FUN_28eb_3c7b(iVar15,uVar18,0,0,1);
  if (*(int *)(iVar15 + 0x22) == *(int *)(iVar15 + 0x26)) {
    *(undefined2 *)(iVar15 + 0x3c) = 0;
  }
  if (*(int *)(iVar15 + 8) == 0x31) {
    return 1;
  }
  if (local_24 == -1) {
    return 1;
  }
  uVar10 = FUN_28eb_37bb(piVar2,local_1e,local_24 != 0);
  if ((*(int *)(iVar6 + 8) != 3) && (*(int *)(iVar6 + 8) != 0x8b)) {
    puVar5 = (undefined2 *)(*(int *)(*(int *)(iVar6 + 8) * 2 + 0x302) + 0x14);
    (*(code *)*puVar5)(0x1000,iVar15,uVar18,iVar6,iVar17,0,uVar10,*(undefined2 *)(iVar15 + 0x3e),
                       *(undefined2 *)(iVar15 + 0x40),*(undefined2 *)(iVar15 + 0x42));
    return 1;
  }
  local_28 = 0;
  if ((uVar10 & 4) == 0) {
    if (cVar1 != '\0') {
      iVar11 = *(int *)(iVar6 + 0x10);
      goto joined_r0x0002d271;
    }
    iVar11 = *(int *)(iVar6 + 0x10);
  }
  else {
    if (cVar1 == '\0') {
      iVar11 = *(int *)(iVar6 + 0x10);
joined_r0x0002d271:
      if (0 < iVar11) {
        local_28 = 0xffff;
      }
      goto LAB_28eb_43c8;
    }
    iVar11 = *(int *)(iVar6 + 0x10);
  }
  if (iVar11 < 2) {
    local_28 = 1;
  }
LAB_28eb_43c8:
  iVar11 = FUN_28eb_46b0(iVar15,uVar18,iVar6,iVar17);
  if (iVar11 != 0) {
    *(undefined2 *)(iVar6 + 0x16) = local_28;
    uVar8 = *(undefined2 *)(iVar15 + 0x40);
    *(undefined2 *)(iVar6 + 0x42) = *(undefined2 *)(iVar15 + 0x42);
    *(undefined2 *)(iVar6 + 0x40) = uVar8;
  }
  return 1;
}

