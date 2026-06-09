// TIM2.EXE: FUN_406b_111b @ file 0x0469CB Ghidra 0x417CB
// Subsystem: sound | Size: 1037 bytes


void __cdecl16far FUN_406b_111b(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  uVar8 = 0x406b;
  if ((param_1 != 0) && (param_1 != 1)) {
    return;
  }
  if (DAT_5b41_1b6c != 0) {
    return;
  }
  DAT_5b41_1b6c = 1;
  if (*(int *)(param_1 * 0x12 + 0x12) == 0 && *(int *)(param_1 * 0x12 + 0x14) == 0) {
    DAT_5b41_1b6c = 1;
    return;
  }
  if (DAT_53bd_0038 == 0) {
    *(undefined2 *)(param_1 * 0x12 + 4) = 0xfffe;
  }
  if (DAT_554c_5594 == '\0') {
    local_4 = DAT_5b41_1b7c;
    local_6 = DAT_5b41_1b7e;
  }
  else {
    FUN_406b_0b9d(&local_4,&local_6);
  }
  DAT_5b41_1b7c = local_4;
  DAT_5b41_1b7e = local_6;
  iVar1 = *(int *)(param_1 * 0x12 + 4);
  if (iVar1 == -2) {
    local_c = 0;
    local_a = 0;
    iVar7 = 0;
    local_8 = 0;
  }
  else {
    local_8 = local_4;
    iVar7 = local_6;
    if ((int)DAT_53bd_003c != 0 || DAT_53bd_003c._2_2_ != 0) {
      local_8 = local_4 - *(int *)((int)DAT_53bd_003c + iVar1 * 4);
      iVar7 = local_6 - *(int *)((int)DAT_53bd_003c + iVar1 * 4 + 2);
    }
    local_a = *(int *)(*(int *)(iVar1 * 2 + DAT_53bd_0038) + 6);
    local_c = *(int *)(*(int *)(iVar1 * 2 + DAT_53bd_0038) + 8);
  }
  iVar2 = local_8;
  if (local_8 < 0) {
    iVar2 = 0;
  }
  iVar3 = iVar7;
  if (iVar7 < 0) {
    iVar3 = 0;
  }
  iVar4 = DAT_554c_49aa;
  if (local_8 + local_a < DAT_554c_49aa) {
    iVar4 = local_8 + local_a;
  }
  iVar4 = iVar4 - iVar2;
  if ((DAT_554c_3e4a == 0) || (DAT_5b41_1b96 == 0)) {
    iVar5 = DAT_554c_49ac;
    if (DAT_554c_49ac <= iVar7 + local_c) goto LAB_406b_12b0;
  }
  else {
    iVar5 = DAT_554c_3e4a;
    if (DAT_554c_3e4a <= iVar7 + local_c) goto LAB_406b_12b0;
  }
  iVar5 = iVar7 + local_c;
LAB_406b_12b0:
  iVar5 = iVar5 - iVar3;
  if ((((*(int *)(param_1 * 0x12 + 6) != iVar1) || (*(int *)(param_1 * 0x12 + 8) != iVar2)) ||
      (*(int *)(param_1 * 0x12 + 10) != iVar3)) ||
     (((*(int *)(param_1 * 0x12 + 0xc) != iVar4 || (*(int *)(param_1 * 0x12 + 0xe) != iVar5)) ||
      (DAT_53bd_0056 != 0)))) {
    FUN_406b_1528(0);
    DAT_554c_42c8 = 0;
    DAT_554c_42c4 = 0;
    DAT_554c_42c6 = DAT_554c_49aa + -1;
    iVar6 = DAT_554c_3e4a;
    if (DAT_53bd_0010 == 0) {
      iVar6 = DAT_554c_49ac;
    }
    DAT_554c_42ca = iVar6 + -1;
    DAT_554c_42c3 = 1;
    DAT_554c_42d6 = DAT_554c_42d2;
    if ((param_1 == 0) && (DAT_554c_42d6 = DAT_554c_42d4, DAT_53bd_0010 != 0)) {
      DAT_554c_42d6 = 0xa000;
    }
    DAT_554c_42d8 = DAT_554c_42d6;
    if (DAT_53bd_0056 == 0) {
      if (*(int *)(param_1 * 0x12 + 6) != -2) {
        uVar8 = 0x1a9e;
        FUN_1a9e_5dc4(0x406b,*(undefined2 *)(param_1 * 0x12 + 0x12),
                      *(undefined2 *)(param_1 * 0x12 + 0x14),*(undefined2 *)(param_1 * 0x12 + 8),
                      *(undefined2 *)(param_1 * 0x12 + 10),*(undefined2 *)(param_1 * 0x12 + 0xc),
                      *(undefined2 *)(param_1 * 0x12 + 0xe));
      }
      *(int *)(param_1 * 0x12 + 6) = iVar1;
      *(int *)(param_1 * 0x12 + 8) = iVar2;
      *(int *)(param_1 * 0x12 + 10) = iVar3;
      *(int *)(param_1 * 0x12 + 0xc) = iVar4;
      *(int *)(param_1 * 0x12 + 0xe) = iVar5;
      *(int *)(param_1 * 0x12 + 0x10) = DAT_5b41_1b96;
      iVar6 = DAT_554c_3e4a;
      if (DAT_53bd_0010 == 0) {
        iVar6 = DAT_554c_49ac;
      }
      DAT_554c_42ca = iVar6 + -1;
      DAT_554c_42d6 = DAT_554c_42d2;
      if ((param_1 == 0) && (DAT_554c_42d6 = DAT_554c_42d4, DAT_53bd_0010 != 0)) {
        DAT_554c_42d6 = 0xa000;
      }
      DAT_554c_42d8 = DAT_554c_42d6;
      if (((iVar1 != -2) && (0 < iVar4)) && (0 < iVar5)) {
        FUN_1a9e_5394(uVar8,*(undefined2 *)(param_1 * 0x12 + 0x12),
                      *(undefined2 *)(param_1 * 0x12 + 0x14),iVar2,iVar3,iVar4,iVar5);
      }
    }
    if (iVar1 != -2) {
      FUN_4a54_09f2(*(undefined2 *)(iVar1 * 2 + DAT_53bd_0038),local_8,iVar7,0);
    }
    FUN_406b_1528(1);
  }
  DAT_5b41_1b6c = 0;
  return;
}

