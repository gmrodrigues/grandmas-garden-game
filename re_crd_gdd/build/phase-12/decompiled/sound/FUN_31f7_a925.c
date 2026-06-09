// TIM2.EXE: FUN_31f7_a925 @ file 0x041A95 Ghidra 0x3C895
// Subsystem: sound | Size: 384 bytes


undefined2 __cdecl16far FUN_31f7_a925(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar11;
  int local_4;
  
  iVar9 = (int)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  iVar1 = *(int *)(iVar7 + 0x9c);
  iVar2 = *(int *)(iVar7 + 0x9a);
  local_4 = *(int *)(iVar7 + 0xa2);
  if (((*(byte *)(iVar2 + 0xc) & 0x10) != 0) &&
     (local_4 = (*(int *)(DAT_554c_03ea + 0x22) - local_4) + -2, local_4 < 0)) {
    local_4 = local_4 + *(int *)(DAT_554c_03ea + 0x22);
  }
  if (local_4 == 0) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
    FUN_31f7_ab62(iVar2,iVar1,iVar7,iVar9);
    if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
      FUN_28eb_51b3(iVar2,iVar1,0x3000,0,0x21,0,0x21);
      uVar11 = 0x21;
      uVar6 = 0;
    }
    else {
      FUN_28eb_51b3(iVar2,iVar1,0x3000,0xb,0x2c,0,0x21);
      uVar11 = 0x2c;
      uVar6 = 0xb;
    }
    FUN_31f7_b9c5(iVar2,iVar1,uVar6,uVar11,0,0x21);
    iVar8 = iVar2;
    iVar10 = iVar1;
    while( true ) {
      iVar3 = *(int *)(iVar8 + 0x8e);
      iVar8 = *(int *)(iVar8 + 0x8c);
      if (iVar8 == 0 && iVar3 == 0) break;
      if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
        iVar4 = (*(int *)(iVar2 + 0x22) - *(int *)(iVar8 + 0x22)) + 0x21;
      }
      else {
        iVar4 = (*(int *)(iVar8 + 0x22) - *(int *)(iVar2 + 0x22)) + -0xb;
      }
      iVar5 = *(int *)(iVar8 + 0x24) - *(int *)(iVar2 + 0x24);
      iVar10 = iVar3;
      if ((iVar5 < 1) || ((-1 < iVar4 && (iVar5 < iVar4)))) {
        if (((*(byte *)(iVar8 + 0xb) & 0x10) == 0) || ((iVar3 == iVar9 && (iVar8 == iVar7)))) {
          FUN_31f7_ba4a(iVar8,iVar3,0);
        }
        else {
          FUN_31f7_ab62(iVar2,iVar1,iVar8,iVar3);
        }
      }
    }
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
  }
  return uVar6;
}

