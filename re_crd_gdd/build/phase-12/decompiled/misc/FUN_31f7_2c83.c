// TIM2.EXE: FUN_31f7_2c83 @ file 0x039DF3 Ghidra 0x34BF3
// Subsystem: misc | Size: 442 bytes


void __cdecl16far FUN_31f7_2c83(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 local_4;
  
  iVar8 = (int)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  if (*(int *)(iVar7 + 0x16) == 0) {
    *(undefined2 *)(iVar7 + 0x10) = 0;
    goto LAB_31f7_2e2b;
  }
  if ((DAT_5b41_051f & 1) == 0) {
    if (*(int *)(iVar7 + 0x10) == 2) {
LAB_31f7_2ce1:
      *(undefined2 *)(iVar7 + 0x10) = 1;
    }
    else {
      *(undefined2 *)(iVar7 + 0x10) = 2;
    }
  }
  else {
    if (*(int *)(iVar7 + 0x10) == 0) {
      *(undefined2 *)(iVar7 + 0x10) = 2;
    }
    else {
      *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + 1;
    }
    iVar2 = FUN_4551_0308(DAT_5b41_09de,*(undefined2 *)(iVar7 + 0x10));
    if (iVar2 != 0) goto LAB_31f7_2ce1;
  }
  iVar2 = iVar7;
  iVar9 = iVar8;
  if ((*(byte *)(iVar7 + 0xc) & 0x10) == 0) {
    FUN_28eb_51b3(iVar7,iVar8,0x3000,0xff00,0,0,*(undefined2 *)(iVar7 + 0x4a));
    local_4 = 0xf000;
  }
  else {
    FUN_28eb_51b3(iVar7,iVar8,0x3000,*(undefined2 *)(iVar7 + 0x48),*(int *)(iVar7 + 0x48) + 0x100,0,
                  *(undefined2 *)(iVar7 + 0x4a));
    local_4 = 0x1000;
  }
  while( true ) {
    iVar1 = *(int *)(iVar2 + 0x8e);
    iVar2 = *(int *)(iVar2 + 0x8c);
    if (iVar2 == 0 && iVar1 == 0) break;
    iVar9 = iVar1;
    if ((*(byte *)(iVar2 + 0xb) & 0x20) == 0) {
      uVar4 = (int)*(uint *)(iVar2 + 0x90) >> 0xf;
      iVar5 = 0x100 - ((*(uint *)(iVar2 + 0x90) ^ uVar4) - uVar4);
      FUN_2fc8_152f(local_4,iVar5);
      uVar3 = FUN_1000_19bf();
      iVar6 = *(int *)(iVar2 + 0x3e) >> 0xf;
      iVar5 = FUN_1000_18f0(0x1000,uVar3,iVar5,*(int *)(iVar2 + 0x3e));
      *(int *)(iVar2 + 0x3a) = *(int *)(iVar2 + 0x3a) + iVar5;
      FUN_549b_007a(0x1000,iVar2,iVar1,iVar6);
      if (((*(int *)(iVar2 + 8) == 0x2d) || (*(int *)(iVar2 + 8) == 0x4e)) ||
         (*(int *)(iVar2 + 8) == 0x8a)) {
        *(undefined2 *)(iVar2 + 0xb4) = 0;
        *(undefined2 *)(iVar2 + 0x16) = 0;
        *(undefined2 *)(iVar2 + 0x10) = 0;
      }
    }
    else if ((*(int *)(iVar2 + 8) == 0x28) &&
            (uVar4 = (int)*(uint *)(iVar2 + 0x90) >> 0xf,
            (int)((*(uint *)(iVar2 + 0x90) ^ uVar4) - uVar4) < 200)) {
      *(undefined2 *)(iVar2 + 0x16) = 1;
      *(undefined2 *)(iVar2 + 0xb4) = 0x14;
    }
  }
LAB_31f7_2e2b:
  FUN_28eb_3328(iVar7,iVar8);
  return;
}

