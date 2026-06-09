// TIM2.EXE: FUN_2424_229b @ file 0x02B6DB Ghidra 0x264DB
// Subsystem: misc | Size: 320 bytes


void __cdecl16far FUN_2424_229b(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint unaff_DI;
  int local_14;
  int local_10;
  int iStack_e;
  
  iVar4 = DAT_5b41_0567._2_2_;
  iVar3 = (int)DAT_5b41_0567;
  *(uint *)((int)DAT_5b41_0567 + 0xe) = *(uint *)((int)DAT_5b41_0567 + 0xe) | 0x20;
  iVar2 = *(int *)(iVar3 + 8);
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    bVar1 = *(byte *)(*(int *)(iVar2 * 2 + 0x302) + local_14 + 0x20);
    if (bVar1 != 0xff) {
      local_10 = 0;
      iStack_e = 0;
      iVar8 = *(int *)((uint)bVar1 * 4 + 0x64bb);
      iVar6 = *(int *)((uint)bVar1 * 4 + 0x64bd);
      while ((iVar7 = iVar6, iVar5 = iVar8, iVar5 != 0 || iVar7 != 0 &&
             (((*(byte *)(iVar5 + 0xf) & 0x10) != 0 ||
              ((iVar8 = iVar7, iVar6 = FUN_28eb_0728(iVar3,iVar4,iVar5,iVar7), iVar8 == iVar4 &&
               (iVar6 == iVar3))))))) {
        unaff_DI = (uint)(*(byte *)(iVar5 + 0x95) != bVar1);
        iVar6 = iVar5 + unaff_DI * 4;
        iVar8 = *(int *)(iVar6 + 0x84);
        iVar6 = *(int *)(iVar6 + 0x86);
        local_10 = iVar5;
        iStack_e = iVar7;
      }
      if (local_10 == 0 && iStack_e == 0) {
        *(int *)((uint)bVar1 * 4 + 0x64bd) = iVar4;
        *(int *)((uint)bVar1 * 4 + 0x64bb) = iVar3;
      }
      else {
        local_10 = local_10 + unaff_DI * 4;
        *(int *)(local_10 + 0x86) = iVar4;
        *(int *)(local_10 + 0x84) = iVar3;
      }
      iVar8 = iVar3 + local_14 * 4;
      *(int *)(iVar8 + 0x86) = iVar7;
      *(int *)(iVar8 + 0x84) = iVar5;
      if (local_14 == 0) {
        *(byte *)(iVar3 + 0x95) = bVar1;
      }
    }
  }
  return;
}

