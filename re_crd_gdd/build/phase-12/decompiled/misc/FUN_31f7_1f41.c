// TIM2.EXE: FUN_31f7_1f41 @ file 0x0390B1 Ghidra 0x33EB1
// Subsystem: misc | Size: 391 bytes


void __cdecl16far FUN_31f7_1f41(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 local_4;
  
  iVar8 = (int)((ulong)param_1 >> 0x10);
  iVar6 = (int)param_1;
  *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x40;
  if ((*(int *)(iVar6 + 0x16) == 1) && (*(int *)(iVar6 + 0x10) != DAT_554c_3a56)) {
    *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
    iVar1 = *(int *)(iVar6 + 0x4a) >> 1;
    iVar7 = iVar6;
    iVar9 = iVar8;
    if ((*(byte *)(iVar6 + 0xc) & 0x10) == 0) {
      FUN_28eb_51b3(iVar6,iVar8,0x3000,*(undefined2 *)(iVar6 + 0x48),*(int *)(iVar6 + 0x48) + 0x80,
                    iVar1 + -6,iVar1 + 10);
      local_4 = 0x1400;
    }
    else {
      FUN_28eb_51b3(iVar6,iVar8,0x3000,0xff80,0,iVar1 + -6,iVar1 + 10);
      local_4 = 0xec00;
    }
    while( true ) {
      iVar1 = *(int *)(iVar7 + 0x8e);
      iVar7 = *(int *)(iVar7 + 0x8c);
      if (iVar7 == 0 && iVar1 == 0) break;
      iVar9 = iVar1;
      if ((*(byte *)(iVar7 + 0xb) & 0x10) == 0) {
        if (*(int *)(iVar7 + 8) == 0x28) {
          *(undefined2 *)(iVar7 + 0x16) = 1;
          *(undefined2 *)(iVar7 + 0xb4) = 0x14;
        }
      }
      else {
        uVar3 = (int)*(uint *)(iVar7 + 0x90) >> 0xf;
        iVar4 = 0x100 - ((*(uint *)(iVar7 + 0x90) ^ uVar3) - uVar3);
        FUN_2fc8_152f(local_4,iVar4);
        uVar2 = FUN_1000_19bf();
        iVar5 = *(int *)(iVar7 + 0x3e) >> 0xf;
        iVar4 = FUN_1000_18f0(0x1000,uVar2,iVar4,*(int *)(iVar7 + 0x3e));
        *(int *)(iVar7 + 0x3a) = *(int *)(iVar7 + 0x3a) + iVar4;
        FUN_549b_007a(0x1000,iVar7,iVar1,iVar5);
        if (((*(int *)(iVar7 + 8) == 0x2d) || (*(int *)(iVar7 + 8) == 0x4e)) ||
           (*(int *)(iVar7 + 8) == 0x8a)) {
          *(undefined2 *)(iVar7 + 0xb4) = 0;
          *(undefined2 *)(iVar7 + 0x16) = 0;
          *(undefined2 *)(iVar7 + 0x10) = 0;
        }
      }
    }
  }
  if (*(int *)(iVar6 + 0x10) != *(int *)(iVar6 + 0x12)) {
    FUN_31f7_1eb8(iVar6,iVar8);
    FUN_28eb_3328(iVar6,iVar8);
  }
  return;
}

