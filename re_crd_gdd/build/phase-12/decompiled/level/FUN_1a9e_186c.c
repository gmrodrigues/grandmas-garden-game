// TIM2.EXE: FUN_1a9e_186c @ file 0x02144C Ghidra 0x1C24C
// Subsystem: level | Size: 254 bytes


void __cdecl16near FUN_1a9e_186c(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = *(undefined2 *)(DAT_5b41_0042 + 4);
  uVar1 = FUN_1000_1a88();
  DAT_5b41_1d4a = CONCAT22(uVar2,uVar1);
  uVar2 = *(undefined2 *)(DAT_5b41_0042 + 4);
  uVar1 = FUN_1000_1a88();
  DAT_5b41_1d46 = CONCAT22(uVar2,uVar1);
  uVar2 = *(undefined2 *)(DAT_5b41_0042 + 4);
  DAT_5b41_1d42._0_2_ = FUN_1000_1a88();
  DAT_5b41_1d42._2_2_ = uVar2;
  for (iVar5 = 0; iVar5 < 0x13a; iVar5 = iVar5 + 1) {
    *(undefined2 *)((int)DAT_5b41_1d4a + iVar5 * 2) = 1;
    *(int *)((int)DAT_5b41_1d42 + iVar5 * 2) = iVar5 + 0x273;
    *(int *)(iVar5 * 2 + (int)DAT_5b41_1d46 + 0x4e6) = iVar5;
  }
  iVar5 = 0;
  for (iVar6 = 0x13a; iVar4 = (int)DAT_5b41_1d4a, uVar2 = (undefined2)((ulong)DAT_5b41_1d4a >> 0x10)
      , iVar6 < 0x273; iVar6 = iVar6 + 1) {
    piVar3 = (int *)(iVar4 + iVar5 * 2);
    *(int *)(iVar4 + iVar6 * 2) = *piVar3 + piVar3[1];
    *(int *)((int)DAT_5b41_1d42 + iVar6 * 2) = iVar5;
    uVar2 = DAT_5b41_1d46._2_2_;
    piVar3 = (int *)(iVar5 * 2 + (int)DAT_5b41_1d46);
    piVar3[1] = iVar6;
    *piVar3 = iVar6;
    iVar5 = iVar5 + 2;
  }
  *(undefined2 *)(iVar4 + 0x4e6) = 0xffff;
  *(undefined2 *)((int)DAT_5b41_1d46 + 0x4e4) = 0;
  return;
}

