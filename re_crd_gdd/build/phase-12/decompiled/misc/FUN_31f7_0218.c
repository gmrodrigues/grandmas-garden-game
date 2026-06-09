// TIM2.EXE: FUN_31f7_0218 @ file 0x037388 Ghidra 0x32188
// Subsystem: misc | Size: 905 bytes


void __cdecl16far FUN_31f7_0218(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  
  iVar9 = (int)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  if (*(int *)(iVar8 + 0x16) == 0) goto LAB_31f7_04ca;
  *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | 0x40;
  if ((*(byte *)(iVar8 + 0xd) & 4) == 0) {
    iVar3 = FUN_31f7_06c7(0,0,iVar8,iVar9,0x8000,1000,*(undefined2 *)(iVar8 + 0x40),
                          *(undefined2 *)(iVar8 + 0x42));
    if (iVar3 == 0) {
      FUN_31f7_06c7(0,0,iVar8,iVar9,0,1000,*(undefined2 *)(iVar8 + 0x40),
                    *(undefined2 *)(iVar8 + 0x42));
      goto LAB_31f7_0289;
    }
    *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | 0x200;
  }
  else {
LAB_31f7_0289:
    *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + *(int *)(iVar8 + 0x16);
  }
  if (*(int *)(iVar8 + 0x10) != *(int *)(iVar8 + 0x12)) {
    FUN_31f7_0125(iVar8,iVar9);
    if ((*(int *)(iVar8 + 0x12) == 0) || (*(int *)(iVar8 + 0x12) == 2)) {
      FUN_2e67_045f(0xc43,0,1,1);
    }
    FUN_28eb_3328(iVar8,iVar9);
    iVar4 = *(int *)(iVar8 + 0x22) + (*(int *)(iVar8 + 0x48) >> 1);
    FUN_28eb_529d(iVar8,iVar9,0x1000,*(int *)(iVar8 + 0x10) * 8 + 0x39f0);
    iVar3 = iVar8;
    iVar5 = iVar9;
    while( true ) {
      iVar2 = *(int *)(iVar3 + 0x8e);
      iVar3 = *(int *)(iVar3 + 0x8c);
      if (iVar3 == 0 && iVar2 == 0) break;
      iVar5 = *(int *)(iVar3 + 0x22) + (*(int *)(iVar3 + 0x48) >> 1);
      iVar6 = FUN_31f7_07db(iVar3,iVar2);
      if (*(int *)(iVar8 + 0x16) == -1) {
        if (iVar5 < iVar4) {
          *(int *)(iVar3 + 0x3c) = iVar6;
          goto LAB_31f7_036b;
        }
        *(int *)(iVar3 + 0x3c) = -iVar6;
LAB_31f7_0384:
        *(int *)(iVar3 + 0x3a) = iVar6 >> 2;
      }
      else if (*(int *)(iVar8 + 0x16) == 1) {
        if (iVar4 <= iVar5) {
          *(int *)(iVar3 + 0x3c) = iVar6;
          goto LAB_31f7_0384;
        }
        *(int *)(iVar3 + 0x3c) = -iVar6;
LAB_31f7_036b:
        *(int *)(iVar3 + 0x3a) = -(iVar6 >> 2);
      }
      FUN_2424_0f94(iVar3,iVar2,3);
      if (*(int *)(iVar3 + 0x3c) < 0) {
        *(int *)(iVar3 + 0x28) = *(int *)(iVar3 + 0x24) + -0x10;
        FUN_549b_005c(0x2424,iVar3,iVar2);
        *(int *)(iVar3 + 0x28) = *(int *)(iVar3 + 0x24) + 0x10;
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | 0x2000;
        FUN_549b_005c(0x549b,iVar3,iVar2);
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xdfff;
        iVar5 = *(int *)(iVar3 + 0x24);
        *(int *)(iVar3 + 0x28) = iVar5;
        iVar5 = iVar5 >> 0xf;
        iVar6 = FUN_1000_199e();
      }
      else {
        *(int *)(iVar3 + 0x28) = *(int *)(iVar3 + 0x24) + 0x10;
        FUN_549b_005c(0x2424,iVar3,iVar2);
        *(int *)(iVar3 + 0x28) = *(int *)(iVar3 + 0x24) + -0x10;
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | 0x2000;
        FUN_549b_005c(0x549b,iVar3,iVar2);
        *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xdfff;
        uVar1 = *(uint *)(iVar3 + 0x24);
        *(uint *)(iVar3 + 0x28) = uVar1;
        iVar7 = ((int)uVar1 >> 0xf) + (uint)(0xfffe < uVar1);
        iVar5 = FUN_1000_199e();
        iVar6 = iVar5 + -1;
        iVar5 = iVar7 + -1 + (uint)(iVar5 != 0);
      }
      *(int *)(iVar3 + 0x20) = iVar5;
      *(int *)(iVar3 + 0x1e) = iVar6;
      iVar5 = iVar2;
      if ((*(int *)(iVar3 + 8) == 0x36) && (*(int *)(iVar3 + 0x10) < DAT_5b41_09a3)) {
        *(int *)(iVar3 + 0x10) = DAT_5b41_09a3;
      }
    }
  }
  *(undefined2 *)(iVar8 + 0x16) = 0;
  *(undefined2 *)(iVar8 + 0x42) = 0;
  *(undefined2 *)(iVar8 + 0x40) = 0;
LAB_31f7_04ca:
  if ((*(int *)(iVar8 + 0x10) == 1) && (*(int *)(iVar8 + 0x12) == 0)) {
    FUN_31f7_0829(iVar8,iVar9,0,0,0x20,0x10,0x1f);
    uVar12 = 0x18;
    uVar11 = 0xc;
    uVar10 = 1;
  }
  else if ((*(int *)(iVar8 + 0x10) == 2) && (*(int *)(iVar8 + 0x12) == 1)) {
    FUN_31f7_0829(iVar8,iVar9,0,0,0x20,0,0x10);
    uVar12 = 0x26;
    uVar11 = 0x18;
    uVar10 = 1;
  }
  else {
    if ((*(int *)(iVar8 + 0x10) == 1) && (*(int *)(iVar8 + 0x12) == 2)) {
      FUN_31f7_0829(iVar8,iVar9,1,0,0x16,10,0x10);
      uVar12 = 0x20;
      uVar11 = 0x10;
    }
    else {
      if (*(int *)(iVar8 + 0x10) != 0) {
        return;
      }
      if (*(int *)(iVar8 + 0x12) != 1) {
        return;
      }
      FUN_31f7_0829(iVar8,iVar9,1,0,0x16,0x15,0x26);
      uVar12 = 0x10;
      uVar11 = 0;
    }
    uVar10 = 0;
  }
  FUN_31f7_0829(iVar8,iVar9,uVar10,0x34,0x4f,uVar11,uVar12);
  return;
}

