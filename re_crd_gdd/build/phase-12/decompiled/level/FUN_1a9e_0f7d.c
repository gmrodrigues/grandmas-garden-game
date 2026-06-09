// TIM2.EXE: FUN_1a9e_0f7d @ file 0x020B5D Ghidra 0x1B95D
// Subsystem: level | Size: 63 bytes


undefined2 __cdecl16far
FUN_1a9e_0f7d(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = FUN_1a9e_03bd(param_1);
  if (iVar1 == 0) {
    return 0xffff;
  }
  DAT_5b41_0049 = func_0x000106aa(0x1a9e,param_2,param_3);
  DAT_5b41_02e9 = DAT_5b41_02e9 | 0x40;
  uVar2 = FUN_1a9e_075d(param_1,param_4);
  return uVar2;
}

