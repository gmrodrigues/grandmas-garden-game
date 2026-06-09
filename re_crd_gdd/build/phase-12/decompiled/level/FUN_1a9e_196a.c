// TIM2.EXE: FUN_1a9e_196a @ file 0x02154A Ghidra 0x1C34A
// Subsystem: level | Size: 381 bytes


void __cdecl16near FUN_1a9e_196a(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar7;
  int local_4;
  
  local_4 = 0;
  for (iVar6 = 0; iVar6 < 0x273; iVar6 = iVar6 + 1) {
    if (0x272 < *(int *)((int)DAT_5b41_1d42 + iVar6 * 2)) {
      uVar7 = (undefined2)((ulong)DAT_5b41_1d4a >> 0x10);
      *(uint *)((int)DAT_5b41_1d4a + local_4 * 2) =
           *(int *)((int)DAT_5b41_1d4a + iVar6 * 2) + 1U >> 1;
      uVar7 = (undefined2)((ulong)DAT_5b41_1d42 >> 0x10);
      *(undefined2 *)((int)DAT_5b41_1d42 + local_4 * 2) =
           *(undefined2 *)((int)DAT_5b41_1d42 + iVar6 * 2);
      local_4 = local_4 + 1;
    }
  }
  iVar6 = 0;
  for (local_4 = 0x13a; local_4 < 0x273; local_4 = local_4 + 1) {
    uVar7 = (undefined2)((ulong)DAT_5b41_1d4a >> 0x10);
    iVar3 = (int)DAT_5b41_1d4a;
    uVar2 = *(int *)(iVar3 + iVar6 * 2) + *(int *)(iVar3 + (iVar6 + 1) * 2);
    *(uint *)(iVar3 + local_4 * 2) = uVar2;
    iVar3 = local_4;
    do {
      iVar1 = iVar3;
      iVar3 = iVar1 + -1;
    } while (uVar2 < *(uint *)((int)DAT_5b41_1d4a + (iVar1 + -1) * 2));
    iVar3 = (local_4 - iVar1) * 2;
    while( true ) {
      iVar3 = iVar3 + -1;
      iVar4 = (int)DAT_5b41_1d4a;
      uVar7 = (undefined2)((ulong)DAT_5b41_1d4a >> 0x10);
      if (iVar3 < 0) break;
      *(undefined2 *)((iVar1 + iVar3) * 2 + iVar4 + 2) =
           *(undefined2 *)(iVar4 + (iVar1 + iVar3) * 2);
      uVar7 = (undefined2)((ulong)DAT_5b41_1d42 >> 0x10);
      *(undefined2 *)((iVar1 + iVar3) * 2 + (int)DAT_5b41_1d42 + 2) =
           *(undefined2 *)((int)DAT_5b41_1d42 + (iVar1 + iVar3) * 2);
    }
    *(uint *)(iVar4 + iVar1 * 2) = uVar2;
    *(int *)((int)DAT_5b41_1d42 + iVar1 * 2) = iVar6;
    iVar6 = iVar6 + 2;
  }
  for (iVar6 = 0; iVar6 < 0x273; iVar6 = iVar6 + 1) {
    iVar3 = *(int *)((int)DAT_5b41_1d42 + iVar6 * 2);
    uVar7 = DAT_5b41_1d46._2_2_;
    if (iVar3 < 0x273) {
      piVar5 = (int *)(iVar3 * 2 + (int)DAT_5b41_1d46);
      piVar5[1] = iVar6;
      *piVar5 = iVar6;
    }
    else {
      *(int *)((int)DAT_5b41_1d46 + iVar3 * 2) = iVar6;
    }
  }
  return;
}

