// TIM2.EXE: FUN_31f7_549b @ file 0x03C60B Ghidra 0x3740B
// Subsystem: misc | Size: 535 bytes


void __cdecl16far FUN_31f7_549b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = (int)((ulong)param_1 >> 0x10);
  iVar6 = (int)param_1;
  *(undefined2 *)(iVar6 + 0x16) = 1;
  *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
  iVar3 = FUN_4551_0308(*(undefined2 *)(*(int *)(iVar6 + 8) * 2 + 0x68fe),
                        *(undefined2 *)(iVar6 + 0x10));
  if (iVar3 == -1) {
    *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + -1;
    FUN_2424_0f94(iVar6,iVar7,3);
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x2000;
  }
  else {
    FUN_28eb_3328(iVar6,iVar7);
  }
  if (*(int *)(iVar6 + 0x10) != 1) {
    return;
  }
  *(undefined2 *)(iVar6 + 0x10) = 0;
  FUN_28eb_3328(iVar6,iVar7);
  FUN_28eb_4f3d(iVar6,iVar7,0x3000,0xffd8,0x14,0xffe8,8);
  *(undefined2 *)(iVar6 + 0x10) = 1;
  FUN_28eb_3328(iVar6,iVar7);
  iVar3 = iVar6;
  iVar8 = iVar7;
LAB_31f7_5687:
  iVar2 = *(int *)(iVar3 + 0x8e);
  iVar3 = *(int *)(iVar3 + 0x8c);
  if (iVar3 == 0 && iVar2 == 0) {
    FUN_2424_35f9(0,0);
    return;
  }
  iVar8 = iVar2;
  if ((*(byte *)(iVar3 + 0xb) & 0x10) != 0) {
    iVar1 = *(int *)(iVar3 + 8);
    if (iVar1 == 0x4a) {
      FUN_31f7_883d(iVar3,iVar2);
      goto LAB_31f7_5687;
    }
    if (iVar1 < 0x4b) {
      if (iVar1 == 4) {
        *(undefined2 *)(iVar3 + 0x16) = 1;
        goto LAB_31f7_5687;
      }
      if (iVar1 == 0x13) {
        FUN_31f7_25cf(iVar3,iVar2);
        goto LAB_31f7_5687;
      }
    }
    else if ((iVar1 == 0x4f) || (iVar1 == 0x6d)) {
      *(undefined2 *)(iVar3 + 0x16) = 2;
      goto LAB_31f7_5687;
    }
    uVar4 = FUN_31f7_56b2(iVar3,iVar2);
    uVar5 = FUN_28eb_0008(iVar6,iVar7,iVar3,iVar2);
    FUN_28eb_3c0f(0x28eb,iVar3,iVar2,uVar5,uVar4);
    if ((*(int *)(iVar3 + 8) == 0x36) && (*(int *)(iVar3 + 0x10) < DAT_5b41_09a3)) {
      *(int *)(iVar3 + 0x10) = DAT_5b41_09a3;
    }
    goto LAB_31f7_5687;
  }
  iVar1 = *(int *)(iVar3 + 8);
  if (iVar1 == 0x37) {
    FUN_31f7_706a(iVar3,iVar2);
    goto LAB_31f7_5687;
  }
  if (0x37 < iVar1) {
    if (iVar1 == 0x55) goto LAB_31f7_5660;
    if (0x55 < iVar1) goto LAB_31f7_563f;
    if ((iVar1 == 0x3c) || (iVar1 == 0x53)) goto LAB_31f7_5660;
    goto LAB_31f7_5687;
  }
  if (iVar1 == 0xf) {
    FUN_31f7_1e38(iVar3,iVar2);
    goto LAB_31f7_5687;
  }
  if (iVar1 < 0x10) {
    if (iVar1 == 1) goto LAB_31f7_5660;
    if (iVar1 == 6) {
      FUN_31f7_111e(iVar3,iVar2);
    }
    goto LAB_31f7_5687;
  }
  if (iVar1 != 0x30) goto LAB_31f7_5687;
LAB_31f7_5660:
  FUN_31f7_5716(iVar3,iVar2,iVar6,iVar7);
  goto LAB_31f7_5687;
LAB_31f7_563f:
  if (iVar1 != 0x7d) goto LAB_31f7_5687;
  goto LAB_31f7_5660;
}

