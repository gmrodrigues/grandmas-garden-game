// TIM2.EXE: FUN_31f7_b6b5 @ file 0x042825 Ghidra 0x3D625
// Subsystem: sound | Size: 156 bytes


void __cdecl16far FUN_31f7_b6b5(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(int *)(iVar2 + 0x16) == 0) && (0x14 < *(int *)(iVar2 + 0xb4))) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
  }
  if (*(int *)(iVar2 + 0x16) == 0) {
    return;
  }
  if ((DAT_5b41_051f & 1) == 0) {
    if (*(int *)(iVar2 + 0x10) == 3) {
      *(undefined2 *)(iVar2 + 0x10) = 5;
    }
    else {
      *(undefined2 *)(iVar2 + 0x10) = 3;
    }
  }
  else {
    if (DAT_5b41_1ac0 <= *(int *)(iVar2 + 0x10)) {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
      iVar1 = FUN_4551_0308(DAT_5b41_0ac2,*(undefined2 *)(iVar2 + 0x10));
      if (iVar1 != -1) goto LAB_31f7_b72e;
    }
    *(int *)(iVar2 + 0x10) = DAT_5b41_1ac0;
  }
LAB_31f7_b72e:
  FUN_28eb_3328(iVar2,uVar3);
  FUN_553b_00b6(0x28eb,iVar2,uVar3,6,0x11,0xfff0);
  return;
}

