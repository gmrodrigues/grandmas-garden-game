// TIM2.EXE: FUN_1a9e_1202 @ file 0x020DE2 Ghidra 0x1BBE2
// Subsystem: level | Size: 178 bytes


undefined2 __cdecl16far FUN_1a9e_1202(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  iVar1 = FUN_1a9e_03bd(param_1);
  if ((iVar1 != 0) && ((DAT_5b41_02ea & 0x40) != 0)) {
    if (*(int *)((uint)DAT_5b41_0046 * 0xe + 0x172) != 0) {
      (*(code *)*(undefined2 *)((uint)DAT_5b41_0046 * 0xe + 0x172))();
    }
    iVar1 = DAT_5b41_0042;
    *(undefined2 *)(DAT_5b41_0042 + 0xc) = 0;
    *(undefined2 *)(iVar1 + 10) = 5;
    if ((*(byte *)(iVar1 + 0x20) & 0x20) == 0) {
      uVar3 = *(undefined2 *)(DAT_5b41_0042 + 8);
      uVar2 = FUN_1000_1a88();
      DAT_5b41_02eb = func_0x000106aa(0x1000,uVar2,uVar3);
    }
    else {
      FUN_1000_0e6d(DAT_5b41_0047,*(uint *)(iVar1 + 0x1c) + 5,
                    *(int *)(iVar1 + 0x1e) + (uint)(0xfffa < *(uint *)(iVar1 + 0x1c)),0);
    }
    iVar1 = DAT_5b41_0042;
    *(undefined2 *)(DAT_5b41_0042 + 0x18) = 0;
    *(undefined2 *)(iVar1 + 0x16) = 0;
    *(undefined1 *)(iVar1 + 0x1b) = 0;
    *(undefined1 *)(iVar1 + 0x1a) = 0;
    return 0;
  }
  return 0xffff;
}

