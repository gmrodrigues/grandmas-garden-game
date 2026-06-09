// TIM2.EXE: FUN_31f7_639f @ file 0x03D50F Ghidra 0x3830F
// Subsystem: misc | Size: 637 bytes


void __cdecl16far FUN_31f7_639f(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int unaff_DI;
  int iVar9;
  
  iVar9 = (int)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  if (*(int *)(iVar7 + 0x16) == 0) {
    *(undefined2 *)(iVar7 + 0x10) = 0;
    goto LAB_31f7_65ff;
  }
  if ((DAT_5b41_051f & 1) == 0) {
    if (*(int *)(iVar7 + 0x10) == 2) {
LAB_31f7_63e9:
      *(undefined2 *)(iVar7 + 0x10) = 1;
    }
    else {
      *(undefined2 *)(iVar7 + 0x10) = 2;
    }
  }
  else {
    *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
    iVar2 = FUN_4551_0308(DAT_5b41_0a14,*(undefined2 *)(iVar7 + 0x10));
    if (iVar2 == -1) goto LAB_31f7_63e9;
  }
  FUN_28eb_4f3d(iVar7,iVar9,0x1000,0,0,0,0x40);
  if ((*(byte *)(iVar7 + 0xc) & 0x10) == 0) {
    iVar2 = 0x10;
  }
  else {
    iVar2 = 0x2c;
  }
  iVar2 = iVar2 + *(int *)(iVar7 + 0x22);
  iVar8 = iVar7;
  iVar3 = iVar9;
  while( true ) {
    iVar1 = *(int *)(iVar8 + 0x8e);
    iVar8 = *(int *)(iVar8 + 0x8c);
    if (iVar8 == 0 && iVar1 == 0) break;
    iVar3 = *(int *)(iVar8 + 0x22) + (*(int *)(iVar8 + 0x48) >> 1);
    if (*(int *)(iVar7 + 0x24) + 0x1f < *(int *)(iVar8 + 0x24)) {
      *(uint *)(iVar8 + 10) = *(uint *)(iVar8 + 10) & 0xfffe;
      if (((iVar2 + -0x10 <= iVar3) && (iVar3 <= iVar2 + 0x10)) &&
         (*(int *)(iVar8 + 0x24) < *(int *)(iVar7 + 0x24) + 0x21)) {
        FUN_31f7_66af(iVar8,iVar1);
      }
      if (-0x400 < *(int *)(iVar8 + 0x3c)) {
        uVar4 = FUN_31f7_6656(iVar8,iVar1);
        uVar6 = (int)*(uint *)(iVar8 + 0x92) >> 0xf;
        FUN_2fc8_152f(uVar4,0x50 - ((*(uint *)(iVar8 + 0x92) ^ uVar6) - uVar6));
        unaff_DI = FUN_1000_19bf();
        *(int *)(iVar8 + 0x3c) = *(int *)(iVar8 + 0x3c) - unaff_DI;
        FUN_549b_007a(0x1000,iVar8,iVar1);
        if (*(int *)(iVar8 + 0x3c) < -0x400) {
          *(undefined2 *)(iVar8 + 0x3c) = 0xfc00;
        }
      }
      if (*(int *)(iVar8 + 0x24) != *(int *)(iVar8 + 0x2c)) {
        if ((*(int *)(iVar8 + 8) == 0x36) && (*(int *)(iVar8 + 0x10) < 6)) {
          *(undefined2 *)(iVar8 + 0x10) = 6;
          FUN_28eb_3328(iVar8,iVar1);
        }
        iVar5 = unaff_DI >> 1;
        if (iVar3 < iVar2 + -4) {
          if ((*(int *)(iVar8 + 0x3a) < 0x200) &&
             (*(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) + iVar5,
             0x200 < *(int *)(iVar8 + 0x3a))) {
            *(undefined2 *)(iVar8 + 0x3a) = 0x200;
          }
        }
        else if (iVar2 + 4 < iVar3) {
          if ((-0x200 < *(int *)(iVar8 + 0x3a)) &&
             (*(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) - iVar5,
             *(int *)(iVar8 + 0x3a) < -0x200)) {
            *(undefined2 *)(iVar8 + 0x3a) = 0xfe00;
          }
        }
        else if (*(int *)(iVar8 + 0x3a) < 1) {
          *(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) + iVar5;
          if (0 < *(int *)(iVar8 + 0x3a)) goto LAB_31f7_65b4;
        }
        else {
          *(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) - iVar5;
          if (*(int *)(iVar8 + 0x3a) < 0) {
LAB_31f7_65b4:
            *(undefined2 *)(iVar8 + 0x3a) = 0;
          }
        }
      }
    }
    iVar3 = iVar1;
    if (*(int *)(iVar8 + 8) == 0x2d) {
      *(undefined2 *)(iVar8 + 0xb4) = 0;
      *(undefined2 *)(iVar8 + 0x16) = 0;
      *(undefined2 *)(iVar8 + 0x10) = 0;
    }
  }
LAB_31f7_65ff:
  if (*(int *)(iVar7 + 0x10) != *(int *)(iVar7 + 0x12)) {
    FUN_28eb_3328(iVar7,iVar9);
  }
  return;
}

