// TIM2.EXE: FUN_31f7_ab62 @ file 0x041CD2 Ghidra 0x3CAD2
// Subsystem: sound | Size: 185 bytes


void __cdecl16far FUN_31f7_ab62(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  iVar2 = *(int *)(iVar5 + 0x22) + (*(int *)(iVar5 + 0x48) >> 1);
  uVar8 = (undefined2)((ulong)param_2 >> 0x10);
  iVar6 = (int)param_2;
  iVar3 = *(int *)(iVar6 + 0x22) + (*(int *)(iVar6 + 0x48) >> 1);
  if ((*(byte *)(iVar5 + 0xc) & 0x10) == 0) {
    iVar3 = iVar2 - iVar3;
  }
  else {
    iVar3 = iVar3 - iVar2;
  }
  iVar2 = (iVar3 >> 1) + -3;
  if (iVar2 < 9) {
    if (iVar2 < -7) {
      iVar2 = -7;
    }
  }
  else {
    iVar2 = 8;
  }
  iVar3 = (iVar2 + 8) * 0x200;
  uVar1 = iVar3 - 0x1000;
  uVar4 = (int)uVar1 >> 0xf;
  *(int *)(iVar6 + 0x3c) = ((uVar1 ^ uVar4) - uVar4) + -0x2800;
  if ((*(byte *)(iVar5 + 0xc) & 0x10) == 0) {
    *(int *)(iVar6 + 0x3a) = (iVar2 + 8) * -0x200;
  }
  else {
    *(int *)(iVar6 + 0x3a) = iVar3;
  }
  if ((*(int *)(iVar6 + 8) == 0x36) && (*(int *)(iVar6 + 0x10) < DAT_5b41_09a3)) {
    *(int *)(iVar6 + 0x10) = DAT_5b41_09a3;
    FUN_28eb_3328(iVar6,uVar8);
  }
  return;
}

