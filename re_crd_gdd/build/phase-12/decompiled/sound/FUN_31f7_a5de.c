// TIM2.EXE: FUN_31f7_a5de @ file 0x04174E Ghidra 0x3C54E
// Subsystem: sound | Size: 488 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_31f7_a5de(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (DAT_5b41_1ab2 <= *(int *)(iVar1 + 0x10)) {
    *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x3c) + 0x200;
    if (0x1000 < *(int *)(iVar1 + 0x3c)) {
      *(undefined2 *)(iVar1 + 0x3c) = 0x1000;
    }
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    if (*(int *)(iVar1 + 0x10) == DAT_5b41_09a9) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
    }
    else if (*(int *)(iVar1 + 0x10) == DAT_5b41_1ab6) {
      *(int *)(iVar1 + 0x10) = DAT_5b41_1ab4;
    }
    if (DAT_5b41_1ab4 <= *(int *)(iVar1 + 0x10)) {
      FUN_553b_00b6(0x31f7,iVar1,uVar2,0,*(undefined2 *)(iVar1 + 0x48),0);
    }
    if (400 < *(int *)(iVar1 + 0x24)) {
      param_1 = 0x30003;
      FUN_2424_0f94();
      _DAT_0000_003f = _DAT_0000_003f | 0x2000;
    }
    goto LAB_31f7_a7ab;
  }
  if (*(int *)(iVar1 + 0x16) != 0) {
    if (*(int *)(iVar1 + 0x16) == 1) {
      *(int *)(iVar1 + 0x10) = DAT_5b41_1ab2;
      *(undefined2 *)(iVar1 + 0x98) = 0;
      goto LAB_31f7_a7ab;
    }
    if (*(int *)(iVar1 + 0x16) == 2) {
      FUN_31f7_a818(iVar1,uVar2);
      *(undefined2 *)(iVar1 + 0x98) = 0;
      goto LAB_31f7_a7ab;
    }
    if (*(int *)(iVar1 + 0x16) == 3) {
      *(int *)(iVar1 + 0x10) = DAT_5b41_1ab0;
      if (0 < *(int *)(iVar1 + 0x3a)) {
LAB_31f7_a70d:
        *(undefined2 *)(iVar1 + 0x3a) = 0;
      }
    }
    else {
      *(int *)(iVar1 + 0x10) = DAT_5b41_1aae;
      if (*(int *)(iVar1 + 0x3a) < 0) goto LAB_31f7_a70d;
    }
    *(undefined2 *)(iVar1 + 0x16) = 0;
    goto LAB_31f7_a7ab;
  }
  if (*(int *)(iVar1 + 0x10) < DAT_5b41_1aae) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    if (*(int *)(iVar1 + 0x10) == DAT_5b41_1aae) {
      *(undefined2 *)(iVar1 + 0x10) = 0;
    }
    if ((*(byte *)(iVar1 + 0xc) & 0x10) == 0) {
      if (-0x200 < *(int *)(iVar1 + 0x3a)) {
        *(int *)(iVar1 + 0x3a) = *(int *)(iVar1 + 0x3a) + -0x40;
      }
    }
    else if (*(int *)(iVar1 + 0x3a) < 0x200) {
      *(int *)(iVar1 + 0x3a) = *(int *)(iVar1 + 0x3a) + 0x40;
    }
    goto LAB_31f7_a7ab;
  }
  if ((*(byte *)(iVar1 + 0xc) & 0x10) == 0) {
    if (*(int *)(iVar1 + 0x3a) < 0) goto LAB_31f7_a665;
  }
  else if (0 < *(int *)(iVar1 + 0x3a)) {
LAB_31f7_a665:
    *(undefined2 *)(iVar1 + 0x3a) = 0;
  }
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
  if ((*(int *)(iVar1 + 0x10) == DAT_5b41_1ab0) || (*(int *)(iVar1 + 0x10) == DAT_5b41_1ab2)) {
    *(undefined2 *)(iVar1 + 0x10) = 0;
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) ^ 0x10;
    FUN_31f7_a534(iVar1,uVar2);
  }
LAB_31f7_a7ab:
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  if (*(int *)((int)param_1 + 0x10) != *(int *)((int)param_1 + 0x12)) {
    FUN_28eb_3328();
  }
  return;
}

