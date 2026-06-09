// TIM2.EXE: FUN_4551_06cf @ file 0x04ADDF Ghidra 0x45BDF
// Subsystem: misc | Size: 1075 bytes


undefined2 * __cdecl16far FUN_4551_06cf(undefined2 param_1)

{
  char cVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  int in_DX;
  uint uVar9;
  undefined2 uVar10;
  int local_b0 [64];
  int *local_30;
  int local_2e;
  int local_2c;
  uint local_2a;
  uint local_28;
  int local_26;
  int local_24;
  int local_22;
  uint local_20;
  undefined2 local_1e;
  int local_1c;
  undefined4 local_1a;
  int *local_16;
  int local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  puVar2 = (undefined2 *)FUN_3f2b_07a3(param_1);
  local_6 = (undefined2 *)CONCAT22(in_DX,puVar2);
  if (puVar2 == (undefined2 *)0x0 && in_DX == 0) {
    uVar3 = FUN_3f2b_0718(param_1);
    iVar4 = FUN_1a9e_69e9(uVar3);
    if (iVar4 == 0) {
      DAT_5b41_1ad2 = 2;
      return (undefined2 *)0x0;
    }
    iVar5 = FUN_1a9e_6a85(iVar4,0x3fbb,0);
    if ((((in_DX == -1) && (iVar5 == -1)) || (cVar1 = FUN_42da_0498(iVar4), cVar1 != 'T')) ||
       (cVar1 = FUN_42da_0498(iVar4), cVar1 != 'B')) {
      FUN_1a9e_6e73(iVar4);
      DAT_5b41_1ad2 = 4;
      return (undefined2 *)0x0;
    }
    local_20 = FUN_42da_04d6(iVar4);
    local_22 = FUN_42da_04d6(iVar4);
    local_24 = FUN_42da_04d6(iVar4);
    local_26 = FUN_42da_04d6(iVar4);
    local_28 = FUN_42da_04d6(iVar4);
    if (0x3e9 < local_20) {
      FUN_1a9e_6e73(iVar4);
      DAT_5b41_1ad2 = 4;
      return (undefined2 *)0x0;
    }
    iVar5 = local_26 * 4;
    local_2a = local_22 * 2 + local_24 * 0xc + iVar5 + local_28 + 0x16;
    puVar2 = (undefined2 *)FUN_22de_01ec(local_2a,0,2,1);
    local_6 = (undefined2 *)CONCAT22(iVar5,puVar2);
    if (puVar2 == (undefined2 *)0x0 && iVar5 == 0) {
      FUN_1a9e_6e73(iVar4);
      return (undefined2 *)0x0;
    }
    puVar6 = puVar2 + 9;
    puVar7 = puVar6;
    iVar8 = iVar5;
    if (local_22 == 0) {
      puVar7 = (undefined2 *)0x0;
      iVar8 = 0;
    }
    puVar2[1] = iVar8;
    *local_6 = puVar7;
    puVar6 = puVar6 + local_22;
    puVar7 = puVar6;
    iVar8 = iVar5;
    if (local_24 == 0) {
      puVar7 = (undefined2 *)0x0;
      iVar8 = 0;
    }
    puVar2[3] = iVar8;
    puVar2[2] = puVar7;
    puVar7 = puVar6 + local_24 * 6;
    iVar8 = iVar5;
    if (local_26 == 0) {
      puVar7 = (undefined2 *)0x0;
      iVar8 = 0;
    }
    puVar2[5] = iVar8;
    puVar2[4] = puVar7;
    local_30 = puVar6 + local_24 * 6 + local_26 * 2 + 2;
    iVar8 = local_24;
    if (local_22 != 0) {
      iVar8 = local_22;
    }
    puVar2[6] = iVar8;
    local_2e = iVar5;
    uVar3 = FUN_42da_04d6(iVar4);
    ((undefined2 *)local_6)[7] = uVar3;
    uVar3 = FUN_42da_04d6(iVar4);
    uVar10 = (undefined2)((ulong)local_6 >> 0x10);
    ((undefined2 *)local_6)[8] = uVar3;
    local_14 = local_2e;
    local_16 = local_30;
    local_a = (undefined2 *)CONCAT22(((undefined2 *)local_6)[1],(undefined2 *)*local_6);
    for (iVar5 = local_22; iVar5 != 0; iVar5 = iVar5 + -1) {
      uVar3 = FUN_42da_04d6(iVar4);
      *local_a = uVar3;
      local_a = (undefined2 *)CONCAT22(local_a._2_2_,(undefined2 *)local_a + 1);
    }
    uVar3 = (undefined2)((ulong)local_6 >> 0x10);
    local_1a = (undefined2 *)
               CONCAT22(((undefined2 *)local_6)[3],(undefined2 *)((undefined2 *)local_6)[2]);
    for (iVar5 = local_24; iVar5 != 0; iVar5 = iVar5 + -1) {
      uVar3 = FUN_42da_04b8(iVar4);
      *local_1a = uVar3;
      uVar3 = FUN_42da_04b8(iVar4);
      ((undefined2 *)local_1a)[1] = uVar3;
      uVar3 = FUN_42da_04b8(iVar4);
      ((undefined2 *)local_1a)[2] = uVar3;
      uVar3 = FUN_42da_04b8(iVar4);
      ((undefined2 *)local_1a)[3] = uVar3;
      iVar8 = FUN_42da_04d6(iVar4);
      uVar3 = (undefined2)((ulong)local_1a >> 0x10);
      puVar2 = (undefined2 *)local_1a;
      puVar2[5] = local_14;
      puVar2[4] = local_16 + iVar8;
      local_1a = (undefined2 *)CONCAT22(uVar3,puVar2 + 6);
    }
    uVar3 = (undefined2)((ulong)local_6 >> 0x10);
    local_e = (undefined2 *)
              CONCAT22(((undefined2 *)local_6)[5],(undefined2 *)((undefined2 *)local_6)[4]);
    for (iVar5 = local_26; iVar5 != 0; iVar5 = iVar5 + -1) {
      uVar3 = FUN_42da_04d6(iVar4);
      *local_e = uVar3;
      uVar3 = FUN_42da_04d6(iVar4);
      uVar10 = (undefined2)((ulong)local_e >> 0x10);
      ((undefined2 *)local_e)[1] = uVar3;
      local_e = (undefined2 *)CONCAT22(uVar10,(undefined2 *)local_e + 2);
    }
    local_12 = (int *)CONCAT22(local_14,local_16);
    for (local_2a = local_28 >> 1; local_2a != 0; local_2a = local_2a - *(int *)(local_1c * 2)) {
      local_1c = FUN_42da_04b8(iVar4);
      *local_12 = local_1c;
      local_12 = (int *)CONCAT22(local_12._2_2_,(int *)local_12 + 1);
      iVar5 = *(int *)(local_1c * 2);
      while (iVar5 = iVar5 + -1, iVar5 != 0) {
        iVar8 = FUN_42da_04b8(iVar4);
        *local_12 = iVar8;
        local_12 = (int *)CONCAT22(local_12._2_2_,(int *)local_12 + 1);
      }
    }
    FUN_460e_074f(0x5fc1);
    FUN_460e_07ca(0x5fc1,iVar4,0x3fc0);
    for (uVar9 = 0; uVar9 < 0x40; uVar9 = uVar9 + 1) {
      local_b0[uVar9] = 0;
    }
    local_12 = (int *)CONCAT22(local_14,local_16);
    while( true ) {
      local_1c = *local_12;
      if (local_1c == 1) break;
      if (local_1c == 2) {
        local_2c = ((int *)local_12)[1];
        if (local_2c != 0) {
          if (local_b0[local_2c] == 0) {
            local_1e = FUN_460e_06da(0x5fc1,local_2c);
            iVar5 = FUN_3e34_0836(local_1e,DAT_554c_3d4e);
            local_b0[local_2c] = iVar5;
          }
          ((int *)local_12)[1] = local_b0[local_2c];
        }
      }
      local_12 = (int *)CONCAT22(local_12._2_2_,(int *)local_12 + *(int *)(local_1c * 2));
    }
    FUN_460e_074f(0x5fc1);
    FUN_3f2b_08e1(param_1,(undefined2 *)local_6,local_6._2_2_);
    FUN_1a9e_6e73(iVar4);
  }
  return (undefined2 *)local_6;
}

