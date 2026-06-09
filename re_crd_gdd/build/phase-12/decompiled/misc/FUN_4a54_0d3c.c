// TIM2.EXE: FUN_4a54_0d3c @ file 0x05047C Ghidra 0x4B27C
// Subsystem: misc | Size: 786 bytes


void __cdecl16near FUN_4a54_0d3c(undefined2 param_1,int *param_2)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  ulong uVar7;
  undefined2 local_1cc;
  undefined2 local_1ca;
  int local_1c8;
  int local_1c6;
  uint local_24;
  uint local_22;
  undefined4 local_20;
  uint local_1c;
  uint local_1a;
  uint local_18;
  uint local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  undefined2 local_c;
  int local_a;
  uint local_8;
  int local_6;
  int *local_4;
  
  uVar7 = CONCAT22(local_20._2_2_,(uint)local_20);
  local_14 = 0;
  local_22 = 0;
  uVar3 = 0x4a54;
  for (local_4 = param_2; local_20 = uVar7, *local_4 != 0; local_4 = local_4 + 1) {
    uVar7 = FUN_1a9e_5398(uVar3,*(undefined2 *)(*local_4 + 6),*(undefined2 *)(*local_4 + 8));
    if ((uVar7 < 0x80000000) && ((0xffff < (long)uVar7 || (local_22 < (uint)uVar7)))) {
      local_22 = (uint)uVar7;
    }
    uVar3 = 0x1a9e;
  }
  uVar4 = 0xffff;
  local_1c = FUN_1a9e_539c(0xffff,0xffff,0,0);
  local_1a = uVar4;
  local_18 = FUN_1a9e_6e3d(param_1);
  if (((int)uVar4 <= (int)local_1a) && ((uVar4 != local_1a || (local_18 <= local_1c)))) {
    local_22 = 0;
    local_1c = local_18;
    local_1a = uVar4;
  }
  iVar5 = 0;
  local_16 = uVar4;
  if ((local_1a < 0x8000) && ((local_1a != 0 || (local_22 <= local_1c)))) {
    local_10 = FUN_1a9e_539c(local_1c,local_1a,0,0);
    local_e = iVar5;
    if (local_10 != 0 || iVar5 != 0) goto LAB_4a54_0e48;
  }
  if (iRam00055622 == 0 && iRam00055624 == 0) {
    return;
  }
  if (0x3ab4 < local_22) {
    return;
  }
  local_e = iRam00055624;
  local_10 = iRam00055622;
  local_1a = 0;
  local_1c = 0x3ab4;
LAB_4a54_0e48:
  DAT_5b41_2858 = &local_1cc;
  local_1ca = 0;
  local_1cc = 0;
  local_1c6 = local_e;
  local_1c8 = local_10;
  FUN_4a54_0c1d(local_10,local_e,local_1c,local_1a,param_1);
  bVar6 = local_18 < local_1c;
  local_18 = local_18 - local_1c;
  local_16 = (local_16 - local_1a) - (uint)bVar6;
  for (local_4 = param_2; piVar1 = (int *)*local_4, piVar1 != (int *)0x0; local_4 = local_4 + 1) {
    local_6 = *piVar1 + ((uint)piVar1[1] >> 4);
    local_8 = piVar1[1] & 0xf;
    local_24 = piVar1[3] * piVar1[4] >> 2;
    for (iVar5 = 0; puVar2 = DAT_5b41_2858, iVar5 < 4; iVar5 = iVar5 + 1) {
      DAT_5b41_2858[iVar5 * 2 + 5] = local_6;
      puVar2[iVar5 * 2 + 4] = local_8;
      local_8 = local_8 + local_24;
    }
    local_12 = 0;
    for (iVar5 = 0; iVar5 < piVar1[4]; iVar5 = iVar5 + 1) {
      DAT_5b41_2858[iVar5 + 0xc] = local_12;
      local_12 = local_12 + piVar1[3];
    }
    FUN_4a54_14ad(0,0,piVar1[3],piVar1[4]);
    local_24 = FUN_1000_19bf();
    puVar2 = DAT_5b41_2858;
    DAT_5b41_2858[1] = 0;
    *puVar2 = 0;
    iVar5 = puVar2[3];
    local_c = puVar2[2];
    local_a = iVar5;
    if (local_18 == 0 && local_16 == 0) {
      uVar3 = FUN_1000_1a88();
      puVar2 = DAT_5b41_2858;
      DAT_5b41_2858[3] = iVar5;
      puVar2[2] = uVar3;
    }
    else {
      local_8 = FUN_1000_1a88();
      local_6 = iVar5;
      FUN_4a54_148b(local_c,local_a,local_8,iVar5,local_1c - local_24);
      FUN_1000_1a00(0x1000);
      local_20._0_2_ = local_18;
      local_20._2_2_ = local_16;
      if ((local_16 < 0x8000) && ((0 < (int)local_16 || (local_24 < local_18)))) {
        local_20._0_2_ = local_24;
        local_20._2_2_ = 0;
      }
      if (((int)local_1a <= (int)local_20._2_2_) &&
         (((int)local_1a < (int)local_20._2_2_ || (local_1c < (uint)local_20)))) {
        local_20._2_2_ = local_1a;
        local_20._0_2_ = local_1c;
      }
      FUN_4a54_0c1d(local_c,local_a,(uint)local_20,local_20._2_2_,param_1);
      bVar6 = local_18 < (uint)local_20;
      local_18 = local_18 - (uint)local_20;
      local_16 = (local_16 - local_20._2_2_) - (uint)bVar6;
    }
    local_14 = local_14 + 1;
  }
  if ((local_e != iRam00055624) || (local_10 != iRam00055622)) {
    FUN_1a9e_5415(local_10,local_e);
  }
  return;
}

