// TIM2.EXE: FUN_1a9e_0225 @ file 0x01FE05 Ghidra 0x1AC05
// Subsystem: utility | Size: 128 bytes


undefined2 __cdecl16near FUN_1a9e_0225(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = DAT_5b41_0042;
  uVar4 = 0x1a9e;
  puVar1 = (uint *)(DAT_5b41_0042 + 10);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_1;
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + (uint)CARRY2(uVar2,param_1);
  if (param_1 <= DAT_5b41_02e7) {
    if ((DAT_5b41_02e9 & 0x40) == 0) {
      uVar4 = 0x1000;
      FUN_1000_0e6d(DAT_5b41_0047,param_1,0,1);
    }
    else {
      FUN_1a9e_00ca((undefined2)DAT_5b41_0049,DAT_5b41_0049._2_2_,param_1);
    }
    DAT_5b41_02e7 = DAT_5b41_02e7 - param_1;
    FUN_1000_1a00(uVar4);
    return 1;
  }
  *(char *)(DAT_5b41_0042 + 0x1a) = *(char *)(DAT_5b41_0042 + 0x1a) + (char)param_1;
  FUN_1a9e_00ca(DAT_5b41_0044,0x554c,param_1);
  return 0;
}

