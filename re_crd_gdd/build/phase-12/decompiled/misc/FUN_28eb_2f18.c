// TIM2.EXE: FUN_28eb_2f18 @ file 0x030FC8 Ghidra 0x2BDC8
// Subsystem: misc | Size: 642 bytes


int __cdecl16far FUN_28eb_2f18(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  bool bVar5;
  undefined2 uVar6;
  undefined2 *puVar7;
  int in_DX;
  int iVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 *puStack_c;
  int local_a;
  int iStack_4;
  
  bVar5 = false;
  uVar10 = 0x2321;
  local_a = FUN_2321_0bd2();
  if (local_a == 0 && in_DX == 0) {
    bVar5 = true;
    goto LAB_28eb_3257;
  }
  uVar9 = (undefined2)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  *(undefined2 *)(local_a + 8) = *(undefined2 *)(iVar8 + 8);
  *(undefined2 *)(local_a + 10) = *(undefined2 *)(iVar8 + 10);
  *(undefined2 *)(local_a + 0xc) = *(undefined2 *)(iVar8 + 0xc);
  *(undefined2 *)(local_a + 0xe) = *(undefined2 *)(iVar8 + 0xe);
  *(undefined2 *)(local_a + 0x10) = *(undefined2 *)(iVar8 + 0x10);
  *(undefined2 *)(local_a + 0x12) = *(undefined2 *)(iVar8 + 0x12);
  *(undefined2 *)(local_a + 0x14) = *(undefined2 *)(iVar8 + 0x14);
  *(undefined2 *)(local_a + 0x16) = *(undefined2 *)(iVar8 + 0x16);
  uVar6 = *(undefined2 *)(iVar8 + 0x44);
  *(undefined2 *)(local_a + 0x46) = *(undefined2 *)(iVar8 + 0x46);
  *(undefined2 *)(local_a + 0x44) = uVar6;
  uVar6 = *(undefined2 *)(iVar8 + 0x48);
  *(undefined2 *)(local_a + 0x4a) = *(undefined2 *)(iVar8 + 0x4a);
  *(undefined2 *)(local_a + 0x48) = uVar6;
  uVar6 = *(undefined2 *)(iVar8 + 0x54);
  *(undefined2 *)(local_a + 0x56) = *(undefined2 *)(iVar8 + 0x56);
  *(undefined2 *)(local_a + 0x54) = uVar6;
  if (*(int *)(local_a + 8) == 8) {
    uVar10 = 0x1000;
    uVar6 = FUN_1000_12bf(1,0x3e);
    *(undefined2 *)(local_a + 0x58) = uVar6;
    if (*(int *)(local_a + 0x58) == 0) {
      bVar5 = true;
      goto LAB_28eb_3257;
    }
    iVar1 = *(int *)(local_a + 0x58);
    *(int *)(iVar1 + 4) = in_DX;
    *(int *)(iVar1 + 2) = local_a;
  }
  *(undefined2 *)(local_a + 0x5a) = *(undefined2 *)(iVar8 + 0x5a);
  *(undefined2 *)(local_a + 0x5c) = *(undefined2 *)(iVar8 + 0x5c);
  if (((*(int *)(local_a + 8) == 10) || (*(int *)(local_a + 8) == 7)) ||
     (*(int *)(local_a + 8) == 0x4c)) {
    uVar10 = 0x1000;
    uVar6 = FUN_1000_12bf(1,0x36);
    *(undefined2 *)(local_a + 0x76) = uVar6;
    if (*(int *)(local_a + 0x76) != 0) {
      piVar2 = (int *)*(int *)(local_a + 0x76);
      piVar2[1] = in_DX;
      *piVar2 = local_a;
      goto LAB_28eb_3088;
    }
LAB_28eb_30c0:
    bVar5 = true;
  }
  else {
LAB_28eb_3088:
    if (*(int *)(local_a + 8) == 0x57) {
      uVar10 = 0x1000;
      puVar7 = (undefined2 *)FUN_1000_12bf(1,8);
      *(undefined2 *)(local_a + 0x68) = 0x554c;
      *(undefined2 *)(local_a + 0x66) = puVar7;
      *(undefined2 *)(local_a + 0x60) = 0x554c;
      *(undefined2 *)(local_a + 0x5e) = puVar7;
      if (*(int *)(local_a + 0x5e) == 0 && *(int *)(local_a + 0x60) == 0) goto LAB_28eb_30c0;
      puVar3 = (undefined2 *)*(int *)(iVar8 + 0x5e);
      *puVar7 = *puVar3;
      puVar7[1] = puVar3[1];
      puVar7[2] = puVar3[2];
      puVar7[3] = puVar3[3];
    }
    if (((*(int *)(local_a + 8) == 0x5b) || (*(int *)(local_a + 8) == 0x5c)) ||
       ((*(int *)(local_a + 8) == 0x5d || (*(int *)(local_a + 8) == 0x5f)))) {
      uVar10 = 0x1000;
      uVar6 = FUN_1000_12bf(0x10,4);
      *(undefined2 *)(local_a + 0x68) = 0x554c;
      *(undefined2 *)(local_a + 0x66) = uVar6;
      *(undefined2 *)(local_a + 0x60) = 0x554c;
      *(undefined2 *)(local_a + 0x5e) = uVar6;
      if (*(int *)(local_a + 0x5e) == 0 && *(int *)(local_a + 0x60) == 0) {
        bVar5 = true;
        goto LAB_28eb_3257;
      }
    }
    *(undefined2 *)(local_a + 0x7a) = *(undefined2 *)(iVar8 + 0x7a);
    *(undefined2 *)(local_a + 0x7c) = *(undefined2 *)(iVar8 + 0x7c);
    *(undefined2 *)(local_a + 0x98) = *(undefined2 *)(iVar8 + 0x98);
    iVar1 = *(int *)(*(int *)(*(int *)(iVar8 + 8) * 2 + 0x302) + 0x22);
    *(int *)(local_a + 0x96) = iVar1;
    if ((iVar1 != 0) && (*(int *)(*(int *)(*(int *)(iVar8 + 8) * 2 + 0x302) + 0x46) == 0)) {
      puStack_c = (undefined2 *)*(undefined2 *)(iVar8 + 0x98);
      uVar10 = 0x1000;
      puVar7 = (undefined2 *)FUN_1000_12bf(*(undefined2 *)(local_a + 0x96),6);
      *(undefined2 *)(local_a + 0x98) = puVar7;
      if (puVar7 == (undefined2 *)0x0) {
        bVar5 = true;
        goto LAB_28eb_3257;
      }
      for (iStack_4 = 0; iStack_4 < *(int *)(local_a + 0x96); iStack_4 = iStack_4 + 1) {
        *puVar7 = *puStack_c;
        puVar7[1] = puStack_c[1];
        puVar7[2] = puStack_c[2];
        puVar7 = puVar7 + 3;
        puStack_c = puStack_c + 3;
      }
    }
    *(undefined2 *)(local_a + 0xa8) = *(undefined2 *)(iVar8 + 0xa8);
    *(undefined2 *)(local_a + 0xaa) = *(undefined2 *)(iVar8 + 0xaa);
    *(undefined2 *)(local_a + 0xac) = *(undefined2 *)(iVar8 + 0xac);
    puVar4 = (undefined2 *)(*(int *)(*(int *)(local_a + 8) * 2 + 0x302) + 8);
    (*(code *)*puVar4)(uVar10,local_a,in_DX);
  }
LAB_28eb_3257:
  if ((bVar5) && (local_a != 0 || in_DX != 0)) {
    FUN_2321_0c23(local_a,in_DX);
    local_a = 0;
  }
  return local_a;
}

