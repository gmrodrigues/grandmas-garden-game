// TIM2.EXE: FUN_31f7_791e @ file 0x03EA8E Ghidra 0x3988E
// Subsystem: misc | Size: 604 bytes


void __cdecl16far FUN_31f7_791e(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if (*(int *)(iVar4 + 0x16) == 0) {
    if (*(int *)(iVar4 + 0xb4) != 0) {
      *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + -1;
    }
    if (*(int *)(iVar4 + 0xb4) == 0) {
      *(undefined2 *)(iVar4 + 0x10) = 0;
    }
    if (*(int *)(iVar4 + 0x10) < DAT_5b41_1a58) {
      if ((*(int *)(iVar4 + 0xb4) != 0) &&
         (*(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1,
         *(int *)(iVar4 + 0x10) == DAT_5b41_1a58)) {
        *(int *)(iVar4 + 0x10) = DAT_5b41_1a56;
      }
    }
    else if ((*(int *)(iVar4 + 0xb4) != 0) &&
            (*(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1,
            *(int *)(iVar4 + 0x10) == DAT_5b41_1a5a)) {
      *(int *)(iVar4 + 0x10) = DAT_5b41_1a58;
    }
    FUN_28eb_3328(iVar4,iVar5);
    goto LAB_31f7_7a3e;
  }
  if ((*(int *)(iVar4 + 0xb4) < 0x28) && (*(int *)(iVar4 + 0x10) < DAT_5b41_1a58)) {
    *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + 2;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
    iVar2 = DAT_5b41_1a56;
    if (*(int *)(iVar4 + 0x10) == DAT_5b41_1a58) {
LAB_31f7_7975:
      *(int *)(iVar4 + 0x10) = iVar2;
    }
  }
  else {
    *(undefined2 *)(iVar4 + 0xb4) = 0x28;
    if (*(int *)(iVar4 + 0x10) < DAT_5b41_1a58) {
      iVar2 = DAT_5b41_1a58 + -1;
      goto LAB_31f7_7975;
    }
  }
  if (*(int *)(iVar4 + 0xb4) == 0x28) {
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
    if (*(int *)(iVar4 + 0x10) == DAT_5b41_1a5a) {
      if ((DAT_5b41_051f & 1) == 0) {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + -2;
      }
      else {
        *(int *)(iVar4 + 0x10) = DAT_5b41_1a58;
      }
    }
    FUN_28eb_3328(iVar4,iVar5);
  }
  *(undefined2 *)(iVar4 + 0x16) = 0;
LAB_31f7_7a3e:
  if (DAT_5b41_1a58 <= *(int *)(iVar4 + 0x10)) {
    if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
      if (*(int *)(iVar4 + 0x3a) < 0x100) {
        *(int *)(iVar4 + 0x3a) = *(int *)(iVar4 + 0x3a) + 0x20;
      }
      uVar8 = 0;
      uVar7 = 0xffd3;
    }
    else {
      if (-0x100 < *(int *)(iVar4 + 0x3a)) {
        *(int *)(iVar4 + 0x3a) = *(int *)(iVar4 + 0x3a) + -0x20;
      }
      uVar8 = 0x4b;
      uVar7 = 0x1e;
    }
    FUN_28eb_51b3(iVar4,iVar5,0x3000,uVar7,uVar8,0xffdd,0);
    iVar2 = iVar4;
    iVar6 = iVar5;
    uVar7 = 0x28eb;
    while( true ) {
      iVar1 = *(int *)(iVar2 + 0x8e);
      iVar2 = *(int *)(iVar2 + 0x8c);
      if (iVar2 == 0 && iVar1 == 0) break;
      iVar6 = iVar1;
      if ((*(byte *)(iVar2 + 0xb) & 0x10) == 0) {
        if (*(int *)(iVar2 + 8) == 0x28) {
          *(undefined2 *)(iVar2 + 0x16) = 1;
          *(undefined2 *)(iVar2 + 0xb4) = 0x14;
        }
        else if (*(int *)(iVar2 + 8) == 6) {
          FUN_31f7_111e(iVar2,iVar1);
        }
      }
      else {
        iVar3 = FUN_31f7_7b7a(iVar2,iVar1);
        if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
          if (-0x600 < *(int *)(iVar2 + 0x3a)) {
            *(int *)(iVar2 + 0x3a) = *(int *)(iVar2 + 0x3a) - iVar3;
          }
        }
        else if (*(int *)(iVar2 + 0x3a) < 0x600) {
          *(int *)(iVar2 + 0x3a) = *(int *)(iVar2 + 0x3a) + iVar3;
        }
        if (-0x600 < *(int *)(iVar2 + 0x3c)) {
          *(int *)(iVar2 + 0x3c) = *(int *)(iVar2 + 0x3c) - iVar3;
        }
        FUN_549b_007a(uVar7,iVar2,iVar1);
        uVar7 = 0x549b;
        if (((*(int *)(iVar2 + 8) == 0x2d) || (*(int *)(iVar2 + 8) == 0x4e)) ||
           (*(int *)(iVar2 + 8) == 0x8a)) {
          *(undefined2 *)(iVar2 + 0xb4) = 0;
          *(undefined2 *)(iVar2 + 0x16) = 0;
          *(undefined2 *)(iVar2 + 0x10) = 0;
        }
      }
    }
  }
  return;
}

