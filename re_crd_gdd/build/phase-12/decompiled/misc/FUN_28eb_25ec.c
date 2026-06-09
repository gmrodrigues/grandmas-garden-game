// TIM2.EXE: FUN_28eb_25ec @ file 0x03069C Ghidra 0x2B49C
// Subsystem: misc | Size: 395 bytes


void __cdecl16far FUN_28eb_25ec(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_BP;
  int unaff_DI;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  
  iVar4 = *(int *)((int)*(undefined4 *)(unaff_BP + 6) + unaff_DI * 2 + 0x76);
  *(int *)(unaff_BP + -0x14) = iVar4;
  if (iVar4 != 0) {
    if (*(int *)(unaff_BP + 10) != 0) {
      iVar4 = *(int *)(unaff_BP + -0x14);
      iVar2 = *(int *)(iVar4 + 6);
      iVar3 = *(int *)(iVar4 + 4);
      *(int *)(unaff_BP + -4) = iVar2;
      *(int *)(unaff_BP + -6) = iVar3;
      if (iVar3 != 0 || iVar2 != 0) {
        *(undefined2 *)(iVar4 + 6) = 0;
        *(undefined2 *)(iVar4 + 4) = 0;
        *(undefined2 *)(iVar4 + 0xe) = 0;
        *(undefined2 *)(iVar4 + 0xc) = 0;
        bVar1 = *(byte *)(iVar4 + 0x14);
        *(uint *)(unaff_BP + -2) = (uint)bVar1;
        uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -6) >> 0x10);
        *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -6) + (uint)bVar1 * 2 + 0x76) = 0;
        iVar4 = *(int *)(unaff_BP + -6) + *(int *)(unaff_BP + -2) * 4;
        uVar6 = *(undefined2 *)(iVar4 + 0x5e);
        *(undefined2 *)(unaff_BP + -0xc) = *(undefined2 *)(iVar4 + 0x60);
        *(undefined2 *)(unaff_BP + -0xe) = uVar6;
        *(undefined2 *)(iVar4 + 0x68) = 0;
        *(undefined2 *)(iVar4 + 0x66) = 0;
        iVar4 = *(int *)(unaff_BP + -6) + *(int *)(unaff_BP + -2) * 4;
        *(undefined2 *)(iVar4 + 0x60) = 0;
        *(undefined2 *)(iVar4 + 0x5e) = 0;
        while ((*(int *)(unaff_BP + -0xe) != 0 || *(int *)(unaff_BP + -0xc) != 0 &&
               (*(int *)((int)*(undefined4 *)(unaff_BP + -0xe) + 8) == 7))) {
          uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0xe) >> 0x10);
          iVar4 = (int)*(undefined4 *)(unaff_BP + -0xe);
          uVar6 = *(undefined2 *)(iVar4 + 0x5e);
          *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)(iVar4 + 0x60);
          *(undefined2 *)(unaff_BP + -0x12) = uVar6;
          for (unaff_DI = 0; unaff_DI < 4; unaff_DI = unaff_DI + 1) {
            uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0xe) >> 0x10);
            iVar4 = (int)*(undefined4 *)(unaff_BP + -0xe) + unaff_DI * 4;
            *(undefined2 *)(iVar4 + 0x60) = 0;
            *(undefined2 *)(iVar4 + 0x5e) = 0;
          }
          *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -0xe) + 0x78) = 0;
          uVar6 = *(undefined2 *)(unaff_BP + -0x12);
          *(undefined2 *)(unaff_BP + -0xc) = *(undefined2 *)(unaff_BP + -0x10);
          *(undefined2 *)(unaff_BP + -0xe) = uVar6;
        }
      }
    }
    iVar4 = *(int *)(unaff_BP + -0x14);
    iVar2 = *(int *)(iVar4 + 10);
    iVar3 = *(int *)(iVar4 + 8);
    *(int *)(unaff_BP + -8) = iVar2;
    *(int *)(unaff_BP + -10) = iVar3;
    if (iVar3 != 0 || iVar2 != 0) {
      bVar1 = *(byte *)(iVar4 + 0x15);
      *(uint *)(unaff_BP + -2) = (uint)bVar1;
      uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -10) >> 0x10);
      *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -10) + (uint)bVar1 * 2 + 0x76) = 0;
      iVar4 = *(int *)(unaff_BP + -0x14);
      *(undefined2 *)(iVar4 + 10) = 0;
      *(undefined2 *)(iVar4 + 8) = 0;
      *(undefined2 *)(iVar4 + 0x12) = 0;
      *(undefined2 *)(iVar4 + 0x10) = 0;
      iVar4 = *(int *)(unaff_BP + -10) + *(int *)(unaff_BP + -2) * 4;
      uVar6 = *(undefined2 *)(iVar4 + 0x5e);
      *(undefined2 *)(unaff_BP + -0xc) = *(undefined2 *)(iVar4 + 0x60);
      *(undefined2 *)(unaff_BP + -0xe) = uVar6;
      *(undefined2 *)(iVar4 + 0x68) = 0;
      *(undefined2 *)(iVar4 + 0x66) = 0;
      iVar4 = *(int *)(unaff_BP + -10) + *(int *)(unaff_BP + -2) * 4;
      *(undefined2 *)(iVar4 + 0x60) = 0;
      *(undefined2 *)(iVar4 + 0x5e) = 0;
      if ((*(int *)(unaff_BP + -0xe) != 0 || *(int *)(unaff_BP + -0xc) != 0) &&
         (*(int *)(unaff_BP + 10) == 0)) {
        iVar4 = FUN_28eb_3930(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                              *(undefined2 *)(unaff_BP + -0xe),*(undefined2 *)(unaff_BP + -0xc));
        *(int *)(unaff_BP + -2) = iVar4;
        uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0xe) >> 0x10);
        iVar4 = (int)*(undefined4 *)(unaff_BP + -0xe) + iVar4 * 4;
        *(undefined2 *)(iVar4 + 0x68) = 0;
        *(undefined2 *)(iVar4 + 0x66) = 0;
        iVar4 = *(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -2) * 4;
        *(undefined2 *)(iVar4 + 0x60) = 0;
        *(undefined2 *)(iVar4 + 0x5e) = 0;
      }
    }
    iVar4 = (int)*(undefined4 *)(unaff_BP + 6);
    if ((*(byte *)(iVar4 + 0xb) & 8) == 0) {
      FUN_28eb_2ca2(iVar4,*(undefined2 *)(unaff_BP + 8));
    }
  }
  if (1 < unaff_DI + 1) {
    return;
  }
  FUN_28eb_25ec();
  return;
}

