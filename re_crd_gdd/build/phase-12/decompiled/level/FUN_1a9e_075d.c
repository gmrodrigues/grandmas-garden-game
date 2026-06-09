// TIM2.EXE: FUN_1a9e_075d @ file 0x02033D Ghidra 0x1B13D
// Subsystem: level | Size: 65 bytes


uint __cdecl16near FUN_1a9e_075d(undefined2 param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  DAT_5b41_02e7 = param_2;
  FUN_1a9e_06e8();
  if (DAT_5b41_02e7 != 0) {
    (*(code *)*(undefined2 *)((uint)DAT_5b41_0046 * 0xe + 0x16c))();
    if (DAT_5b41_02e7 != 0) {
      FUN_1a9e_06e8();
    }
  }
  iVar3 = DAT_5b41_0042;
  uVar4 = param_2 - DAT_5b41_02e7;
  puVar1 = (uint *)(DAT_5b41_0042 + 0x16);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar4;
  *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + (uint)CARRY2(uVar2,uVar4);
  return uVar4;
}

