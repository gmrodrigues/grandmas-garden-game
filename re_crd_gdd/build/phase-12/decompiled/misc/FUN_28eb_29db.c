// TIM2.EXE: FUN_28eb_29db @ file 0x030A8B Ghidra 0x2B88B
// Subsystem: misc | Size: 72 bytes


/* WARNING: Instruction at (ram,0x0002b88c) overlaps instruction at (ram,0x0002b88b)
    */

void __cdecl16far FUN_28eb_29db(void)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  int iVar3;
  int unaff_DI;
  undefined2 uVar4;
  undefined2 unaff_SS;
  bool in_CF;
  bool in_ZF;
  bool bVar5;
  
  if (in_CF || in_ZF) {
    FUN_2424_0f94(*(undefined2 *)(unaff_BP + -0x14),*(undefined2 *)(unaff_BP + -0x12));
    FUN_28eb_2d82();
    for (iVar3 = 0; uVar4 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10), iVar3 < 4; iVar3 = iVar3 + 1
        ) {
      iVar2 = (int)DAT_5b41_0567 + iVar3 * 4;
      *(undefined2 *)(iVar2 + 0x60) = 0;
      *(undefined2 *)(iVar2 + 0x5e) = 0;
    }
    *(undefined2 *)((int)DAT_5b41_0567 + 0x78) = 0;
  }
  else {
    while( true ) {
      unaff_SI = unaff_SI + 1;
      bVar5 = unaff_SI == 0;
      FUN_2424_3660();
      if (!bVar5) {
        uVar4 = ((undefined2 *)*(int *)(unaff_BP + -0x18))[1];
        uVar1 = *(undefined2 *)*(int *)(unaff_BP + -0x18);
        *(undefined2 *)(unaff_BP + -10) = uVar4;
        *(undefined2 *)(unaff_BP + -0xc) = uVar1;
        FUN_28eb_25df(uVar1,uVar4);
        FUN_28eb_27be(*(undefined2 *)(unaff_BP + -0xc),*(undefined2 *)(unaff_BP + -10));
      }
      unaff_DI = unaff_DI + 1;
      if (1 < unaff_DI) break;
      *(undefined2 *)(unaff_BP + -0x18) = *(undefined2 *)((int)DAT_5b41_0567 + unaff_DI * 2 + 0x76);
    }
  }
  FUN_28eb_27be((undefined2)DAT_5b41_0567,DAT_5b41_0567._2_2_);
  return;
}

