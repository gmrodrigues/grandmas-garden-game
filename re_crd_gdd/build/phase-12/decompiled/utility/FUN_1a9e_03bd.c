// TIM2.EXE: FUN_1a9e_03bd @ file 0x01FF9D Ghidra 0x1AD9D
// Subsystem: utility | Size: 137 bytes


undefined2 __cdecl16near FUN_1a9e_03bd(int param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if (((param_1 < 0) || (3 < param_1)) ||
     (DAT_5b41_0042 = (undefined2 *)((undefined2 *)&DAT_5b41_0051)[param_1],
     DAT_5b41_0042 == (undefined2 *)0x0)) {
    uVar2 = 0;
    uVar1 = DAT_5b41_02eb;
  }
  else {
    DAT_5b41_004f = DAT_5b41_0042[2];
    DAT_5b41_004d = DAT_5b41_0042[1];
    DAT_5b41_0044 = *DAT_5b41_0042;
    DAT_5b41_02ea = *(byte *)(DAT_5b41_0042 + 0x10);
    DAT_5b41_0046 = DAT_5b41_02ea & 0x1f;
    if ((DAT_5b41_02ea & 0x20) == 0) {
      DAT_5b41_02e9 = 0;
      uVar2 = DAT_5b41_0042[4];
      uVar3 = FUN_1000_1a88();
      DAT_5b41_02eb = func_0x000106aa(0x1000,uVar3,uVar2);
    }
    else {
      DAT_5b41_0047 = DAT_5b41_0042[3];
      DAT_5b41_02e9 = 0x20;
    }
    uVar2 = 1;
    uVar1 = DAT_5b41_02eb;
  }
  DAT_5b41_02eb._2_2_ = (undefined2)((ulong)uVar1 >> 0x10);
  DAT_5b41_02eb._0_2_ = (undefined2)uVar1;
  return uVar2;
}

