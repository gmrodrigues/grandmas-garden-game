// TIM2.EXE: FUN_1000_8074 @ file 0x01D274 Ghidra 0x18074
// Subsystem: utility | Size: 715 bytes


void __cdecl16far
FUN_1000_8074(int param_1,undefined2 param_2,undefined4 param_3,uint param_4,int param_5,int param_6
             ,undefined2 param_7)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  bool bVar13;
  int local_24;
  int iStack_22;
  uint uStack_20;
  uint local_1e;
  int local_1c;
  undefined4 local_1a;
  undefined4 local_12;
  undefined4 local_a;
  
  iVar7 = (int)param_3;
  uVar10 = (undefined2)((ulong)param_3 >> 0x10);
  if (param_6 == 0) {
    uVar6 = *(uint *)(iVar7 + 0x1c);
  }
  else {
    uVar6 = *(uint *)(iVar7 + 0x1a);
  }
  if (((param_4 == 0 && param_5 == 0) || (param_5 != 0)) || (uVar6 <= param_4)) {
    FUN_1000_7f88(param_1,param_2,iVar7,uVar10,param_6);
  }
  else {
    local_1c = param_5;
    local_1e = param_4;
    piVar3 = (int *)(iVar7 + *(int *)(iVar7 + 0xc));
    local_12 = (int *)CONCAT22(uVar10,piVar3);
    if (param_6 != 0) {
      while( true ) {
        uVar11 = (undefined2)((ulong)local_12 >> 0x10);
        iVar1 = ((int *)local_12)[1];
        iVar2 = *local_12;
        if (iVar2 == 0 && iVar1 == 0) break;
        if ((*(byte *)(iVar2 + 8) & 2) != 0) {
          uVar6 = *(uint *)(iVar2 + 0x1c);
          if ((local_1c == 0) && (local_1e <= uVar6)) {
            local_12._0_2_ = (int *)local_12 + 4;
            local_12._2_2_ = uVar11;
            goto LAB_1000_8149;
          }
          bVar13 = local_1e < uVar6;
          local_1e = local_1e - uVar6;
          local_1c = local_1c - (uint)bVar13;
        }
        local_12 = (int *)CONCAT22(uVar11,(int *)local_12 + 4);
      }
    }
    piVar4 = (int *)(iVar7 + *(int *)(iVar7 + 10));
    local_a = (int *)CONCAT22(uVar10,piVar4);
    while( true ) {
      uVar11 = (undefined2)((ulong)local_a >> 0x10);
      piVar8 = (int *)local_a;
      iVar1 = piVar8[1];
      iVar2 = *local_a;
      if (iVar2 == 0 && iVar1 == 0) break;
      if ((*(byte *)(iVar2 + 8) & 2) != 0) {
        uVar6 = *(uint *)(iVar2 + 0x1c);
        if ((local_1c == 0) && (local_1e <= uVar6)) {
          FUN_1000_7ff3(param_1,param_2,piVar8 + 4,uVar11,piVar4,uVar10,local_1e,0,param_7);
          goto joined_r0x00018317;
        }
        bVar13 = local_1e < uVar6;
        local_1e = local_1e - uVar6;
        local_1c = local_1c - (uint)bVar13;
      }
      local_a = (int *)CONCAT22(uVar11,piVar8 + 4);
    }
    piVar5 = (int *)(iVar7 + *(int *)(iVar7 + 0x24));
    local_1a = (int *)CONCAT22(uVar10,piVar5);
    while( true ) {
      uVar12 = (undefined2)((ulong)local_1a >> 0x10);
      iVar7 = ((int *)local_1a)[1];
      local_24 = *local_1a;
      uStack_20 = 1;
      iStack_22 = iVar7;
      if ((*(byte *)(local_24 + 3) & 4) != 0) {
        uStack_20 = *(uint *)(local_24 + 10);
        iStack_22 = *(int *)(local_24 + 8);
        local_24 = *(int *)(local_24 + 6);
      }
      uVar6 = *(int *)(local_24 + 0x1a) * uStack_20;
      if ((local_1c == 0) && (local_1e <= uVar6)) break;
      bVar13 = local_1e < uVar6;
      local_1e = local_1e - uVar6;
      local_1c = local_1c - (uint)bVar13;
      local_1a = (int *)CONCAT22(uVar12,(int *)local_1a + 3);
    }
    do {
      uVar12 = (undefined2)((ulong)local_1a >> 0x10);
      piVar9 = (int *)local_1a;
      if (uStack_20 < 2) {
        FUN_1000_8074(param_1 + piVar9[2],param_2,*local_1a,piVar9[1],local_1e,local_1c,1,param_7);
      }
      else {
        FUN_1000_833f(param_1 + piVar9[2],param_2,*local_1a,piVar9[1],local_1e,local_1c,param_7);
      }
      local_1c = 0;
      local_1e = 0;
      local_1a = (int *)CONCAT22(uVar12,piVar9 + -3);
    } while (piVar5 <= piVar9 + -3);
    FUN_1000_7ff3(param_1,param_2,piVar8,uVar11,piVar4,uVar10,0,0,param_7);
joined_r0x00018317:
    if (param_6 != 0) {
      local_1e = 0;
LAB_1000_8149:
      FUN_1000_7ff3(param_1,param_2,(int *)local_12,local_12._2_2_,piVar3,uVar10,local_1e,1,param_7)
      ;
    }
  }
  return;
}

