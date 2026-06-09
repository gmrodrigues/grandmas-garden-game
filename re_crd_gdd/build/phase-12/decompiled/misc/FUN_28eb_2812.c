// TIM2.EXE: FUN_28eb_2812 @ file 0x0308C2 Ghidra 0x2B6C2
// Subsystem: misc | Size: 456 bytes


void __cdecl16far FUN_28eb_2812(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  
  if (((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0) &&
     ((*(byte *)((int)DAT_5b41_0567 + 0xb) & 8) != 0)) {
    if ((*(byte *)((int)DAT_5b41_0567 + 0xe) & 3) != 0) {
      FUN_28eb_2440((int)DAT_5b41_0567,DAT_5b41_0567._2_2_);
    }
    uVar8 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
    iVar4 = *(int *)((int)DAT_5b41_0567 + 0x58);
    if ((*(int *)((int)DAT_5b41_0567 + 8) != 8) && (iVar4 != 0)) {
      uVar8 = *(undefined2 *)(iVar4 + 4);
      uVar9 = *(undefined2 *)(iVar4 + 2);
      FUN_28eb_2550(uVar9,uVar8);
      FUN_28eb_27be(uVar9,uVar8);
    }
    uVar8 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
    iVar4 = (int)DAT_5b41_0567;
    if (*(int *)(iVar4 + 8) == 7) {
      iVar7 = *(int *)(iVar4 + 0x60);
      iVar1 = *(int *)(iVar4 + 0x5e);
      if (iVar1 != 0 || iVar7 != 0) {
        iVar3 = FUN_28eb_3930(iVar4,uVar8,iVar1,iVar7);
        uVar9 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
        iVar5 = (int)DAT_5b41_0567;
        uVar8 = *(undefined2 *)(iVar5 + 100);
        iVar4 = *(int *)(iVar5 + 0x62);
        iVar5 = FUN_28eb_3930(iVar5,uVar9,iVar4,uVar8);
        iVar6 = iVar1 + iVar3 * 4;
        *(undefined2 *)(iVar6 + 0x68) = uVar8;
        *(int *)(iVar6 + 0x66) = iVar4;
        iVar3 = iVar1 + iVar3 * 4;
        *(undefined2 *)(iVar3 + 0x60) = uVar8;
        *(int *)(iVar3 + 0x5e) = iVar4;
        iVar3 = iVar4 + iVar5 * 4;
        *(int *)(iVar3 + 0x68) = iVar7;
        *(int *)(iVar3 + 0x66) = iVar1;
        iVar3 = iVar4 + iVar5 * 4;
        *(int *)(iVar3 + 0x60) = iVar7;
        *(int *)(iVar3 + 0x5e) = iVar1;
        if (*(int *)(iVar1 + 8) == 7) {
          FUN_28eb_1e42(iVar1,iVar7);
          FUN_2424_0f94(iVar1,iVar7,3);
        }
        if (*(int *)(iVar4 + 8) == 7) {
          FUN_28eb_1e42(iVar4,uVar8);
          FUN_2424_0f94(iVar4,uVar8,3);
        }
        puVar2 = (undefined2 *)*(int *)((int)DAT_5b41_0567 + 0x78);
        FUN_28eb_2d82(*puVar2,puVar2[1],2);
        iVar4 = 0;
        while( true ) {
          uVar8 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
          if (3 < iVar4) break;
          iVar7 = (int)DAT_5b41_0567 + iVar4 * 4;
          *(undefined2 *)(iVar7 + 0x60) = 0;
          *(undefined2 *)(iVar7 + 0x5e) = 0;
          iVar4 = iVar4 + 1;
        }
        *(undefined2 *)((int)DAT_5b41_0567 + 0x78) = 0;
      }
    }
    else if ((*(int *)(iVar4 + 8) != 10) && (*(int *)(iVar4 + 8) != 0x4c)) {
      for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
        puVar2 = (undefined2 *)*(int *)((int)DAT_5b41_0567 + iVar4 * 2 + 0x76);
        if (puVar2 != (undefined2 *)0x0) {
          uVar8 = puVar2[1];
          uVar9 = *puVar2;
          FUN_28eb_25df(uVar9,uVar8,1);
          FUN_28eb_27be(uVar9,uVar8);
        }
      }
    }
    FUN_28eb_27be((int)DAT_5b41_0567,DAT_5b41_0567._2_2_);
  }
  return;
}

