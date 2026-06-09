// TIM2.EXE: FUN_1a9e_0eab @ file 0x020A8B Ghidra 0x1B88B
// Subsystem: level | Size: 210 bytes


undefined2 __cdecl16far FUN_1a9e_0eab(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  iVar1 = FUN_1a9e_03bd(param_1);
  if (iVar1 != 0) {
    DAT_5b41_02e5 = 0;
    if ((DAT_5b41_02ea & 0x40) == 0) {
      (*(code *)*(undefined2 *)((uint)DAT_5b41_0046 * 0xe + 0x16e))(1);
      if ((DAT_5b41_02ea & 0x20) == 0) {
        uVar3 = *(undefined2 *)(DAT_5b41_0042 + 8);
        uVar2 = FUN_1000_1a88(DAT_5b41_0042 + 0x12,0x554c,4);
        FUN_1000_05ea(uVar2,uVar3);
      }
      else {
        FUN_1000_0e6d(DAT_5b41_0047,*(uint *)(DAT_5b41_0042 + 0x1c) + 1,
                      *(int *)(DAT_5b41_0042 + 0x1e) +
                      (uint)(0xfffe < *(uint *)(DAT_5b41_0042 + 0x1c)),0);
        FUN_1000_10d5(DAT_5b41_0042 + 0x12,4,1,DAT_5b41_0047);
        FUN_1000_0e6d(DAT_5b41_0047,0,0,2);
      }
    }
    FUN_1a9e_047d(param_1);
    return DAT_5b41_02e5;
  }
  return 0xffff;
}

