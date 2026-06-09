// TIM2.EXE: FUN_31f7_6b14 @ file 0x03DC84 Ghidra 0x38A84
// Subsystem: misc | Size: 1019 bytes


void __cdecl16far FUN_31f7_6b14(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined4 local_6;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  if (DAT_5b41_09a3 <= *(int *)(iVar7 + 0x10)) {
    if (DAT_5b41_1a2a <= *(int *)(iVar7 + 0x10)) {
      *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
      if (*(int *)(iVar7 + 0x10) == DAT_5b41_1a2c) {
        if (*(int *)(iVar7 + 0xb4) != 0) goto LAB_31f7_6ee5;
        if (*(int *)(iVar7 + 0x10) == 0) {
          iVar4 = DAT_5b41_1a22;
          if (*(int *)(iVar7 + 0xae) == 0) {
            *(undefined2 *)(iVar7 + 0x10) = 0;
            goto LAB_31f7_6ee5;
          }
        }
        else {
          iVar4 = *(int *)(iVar7 + 0xa8) + 1;
        }
      }
      else {
        iVar4 = DAT_5b41_1a2e;
        if (*(int *)(iVar7 + 0x10) != DAT_5b41_1a30) goto LAB_31f7_6ee5;
      }
      *(int *)(iVar7 + 0x10) = iVar4;
LAB_31f7_6ee5:
      FUN_28eb_3328(iVar7,uVar8);
      if (*(int *)(iVar7 + 0x10) != DAT_5b41_1a30) {
        return;
      }
      FUN_31f7_6a10(iVar7,uVar8);
      return;
    }
    *(undefined2 *)(iVar7 + 0xae) = 1;
    *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
    if (*(int *)(iVar7 + 0x10) == DAT_5b41_1a2a) {
      *(int *)(iVar7 + 0x10) = DAT_5b41_09a3 + 1;
    }
    goto LAB_31f7_6e7e;
  }
  local_6 = (int *)CONCAT22(uVar8,(int *)(iVar7 + 0x9a));
  uVar3 = *(uint *)(iVar7 + 0xe) & 0x800;
  if (uVar3 == 0) {
    uVar6 = (int)*(uint *)(iVar7 + 0x3c) >> 0xf;
    if ((0x600 < (int)((*(uint *)(iVar7 + 0x3c) ^ uVar6) - uVar6)) &&
       (*local_6 == 0 && *(int *)(iVar7 + 0x9c) == 0)) {
      if (*(int *)(iVar7 + 0x16) < 3) {
        *(int *)(iVar7 + 0x16) = *(int *)(iVar7 + 0x16) + 1;
        goto LAB_31f7_6baa;
      }
      *(int *)(iVar7 + 0x10) = DAT_5b41_09a3;
    }
LAB_31f7_6ba1:
    *(undefined2 *)(iVar7 + 0x16) = 0;
  }
  else {
    if (*(int *)(iVar7 + 0x16) != 0) {
      *(int *)(iVar7 + 0x10) = DAT_5b41_09a3;
      *(int *)(iVar7 + 0x3a) = *(int *)(iVar7 + 0x3a) >> 2;
      goto LAB_31f7_6ba1;
    }
    *(undefined2 *)(iVar7 + 0x16) = 1;
  }
LAB_31f7_6baa:
  if ((*(int *)(iVar7 + 0x10) == DAT_5b41_1a26) || (*(int *)(iVar7 + 0x10) == DAT_5b41_1a22)) {
    *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + 4;
    iVar4 = FUN_28eb_0119(iVar7,uVar8);
    if (iVar4 == 0) {
      *(int *)(iVar7 + 0x10) = DAT_5b41_09a3;
      *(undefined2 *)(iVar7 + 0x16) = 0;
    }
    *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + -4;
  }
  if (*(int *)(iVar7 + 0x10) == DAT_5b41_09a3) goto LAB_31f7_6e7e;
  if (*(int *)(iVar7 + 0xae) == 0) {
    if ((DAT_5b41_051f & 1) == 0) goto LAB_31f7_6e7e;
    *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
    if ((*(int *)(iVar7 + 0x10) == DAT_5b41_1a20) && (uVar3 = FUN_460e_1a42(), (uVar3 & 1) != 0)) {
      *(undefined2 *)(iVar7 + 0x10) = 0;
    }
    if (*(int *)(iVar7 + 0x10) != DAT_5b41_1a22) goto LAB_31f7_6e7e;
    uVar3 = FUN_460e_1a42();
    iVar4 = DAT_5b41_1a20;
    if ((uVar3 & 1) == 0) {
      *(undefined2 *)(iVar7 + 0x10) = 0;
      goto LAB_31f7_6e7e;
    }
  }
  else {
    bVar2 = DAT_5b41_1a26 <= *(int *)(iVar7 + 0x10);
    *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
    if (*(int *)(iVar7 + 0x10) <= DAT_5b41_1a22) {
      *(int *)(iVar7 + 0x10) = DAT_5b41_1a22 + 1;
    }
    if (*local_6 == 0 && *(int *)(iVar7 + 0x9c) == 0) {
LAB_31f7_6caa:
      if (bVar2) {
        if ((*(byte *)(iVar7 + 0xc) & 0x10) == 0) {
          *(int *)(iVar7 + 0x22) =
               *(int *)(iVar7 + 0x22) +
               *(int *)((*(int *)(iVar7 + 0x10) - DAT_5b41_1a28) * 2 + 0x3b94);
          if (*local_6 != 0 || *(int *)(iVar7 + 0x9c) != 0) {
            bVar1 = *(byte *)(iVar7 + 0xa1);
            goto joined_r0x00038caa;
          }
        }
        else {
          *(int *)(iVar7 + 0x22) =
               *(int *)(iVar7 + 0x22) -
               *(int *)((*(int *)(iVar7 + 0x10) - DAT_5b41_1a28) * 2 + 0x3b94);
          if ((((*local_6 != 0 || *(int *)(iVar7 + 0x9c) != 0) && (*(int *)(iVar7 + 0xa0) != 0)) &&
              ((*(byte *)(iVar7 + 0xa1) & 0x80) == 0)) && (uVar3 == 0)) {
            iVar4 = *(int *)((*(int *)(iVar7 + 0x10) - DAT_5b41_1a24) * 2 + 0x3b94);
LAB_31f7_6dca:
            *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + iVar4;
            iVar4 = *(int *)(iVar7 + 0x24);
            *(int *)(iVar7 + 0x20) = iVar4 >> 0xf;
            *(int *)(iVar7 + 0x1e) = iVar4;
            uVar9 = *(undefined2 *)(iVar7 + 0x20);
            uVar5 = FUN_1000_199e();
            *(undefined2 *)(iVar7 + 0x20) = uVar9;
            *(undefined2 *)(iVar7 + 0x1e) = uVar5;
          }
        }
      }
      else if ((*(byte *)(iVar7 + 0xc) & 0x10) == 0) {
        *(int *)(iVar7 + 0x22) =
             *(int *)(iVar7 + 0x22) +
             *(int *)((*(int *)(iVar7 + 0x10) - DAT_5b41_1a24) * 2 + 0x3b72);
        if (*local_6 != 0 || *(int *)(iVar7 + 0x9c) != 0) {
          bVar1 = *(byte *)(iVar7 + 0xa1);
joined_r0x00038caa:
          if ((bVar1 & 0x80) != 0) goto joined_r0x00038cb1;
        }
      }
      else {
        *(int *)(iVar7 + 0x22) =
             *(int *)(iVar7 + 0x22) -
             *(int *)((*(int *)(iVar7 + 0x10) - DAT_5b41_1a24) * 2 + 0x3b72);
        if (((*local_6 != 0 || *(int *)(iVar7 + 0x9c) != 0) && (*(int *)(iVar7 + 0xa0) != 0)) &&
           ((*(byte *)(iVar7 + 0xa1) & 0x80) == 0)) {
joined_r0x00038cb1:
          if (uVar3 == 0) {
            iVar4 = *(int *)((*(int *)(iVar7 + 0x10) - DAT_5b41_1a24) * 2 + 0x3b72);
            goto LAB_31f7_6dca;
          }
        }
      }
      iVar4 = *(int *)(iVar7 + 0x22);
      *(int *)(iVar7 + 0x1c) = iVar4 >> 0xf;
      *(int *)(iVar7 + 0x1a) = iVar4;
      uVar9 = *(undefined2 *)(iVar7 + 0x1c);
      uVar5 = FUN_1000_199e();
      *(undefined2 *)(iVar7 + 0x1c) = uVar9;
      *(undefined2 *)(iVar7 + 0x1a) = uVar5;
      *(undefined2 *)(iVar7 + 0x3a) = 0;
    }
    else {
      uVar9 = (undefined2)((ulong)*(undefined4 *)local_6 >> 0x10);
      iVar4 = (int)*(undefined4 *)local_6;
      if ((*(int *)(iVar4 + 0x16) == 0) || (*(int *)(iVar4 + 8) != 5)) goto LAB_31f7_6caa;
    }
    if (bVar2) {
      iVar4 = DAT_5b41_1a28;
      if (*(int *)(iVar7 + 0x10) != DAT_5b41_09a3) goto LAB_31f7_6e7e;
    }
    else {
      iVar4 = DAT_5b41_1a24;
      if (*(int *)(iVar7 + 0x10) != DAT_5b41_1a26) goto LAB_31f7_6e7e;
    }
  }
  *(int *)(iVar7 + 0x10) = iVar4;
LAB_31f7_6e7e:
  FUN_28eb_3328(iVar7,uVar8);
  return;
}

