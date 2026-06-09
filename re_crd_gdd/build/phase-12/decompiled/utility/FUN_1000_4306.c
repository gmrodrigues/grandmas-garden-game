// TIM2.EXE: FUN_1000_4306 @ file 0x019506 Ghidra 0x14306
// Subsystem: utility | Size: 78 bytes


uint __cdecl16far
FUN_1000_4306(undefined2 param_1,uint param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  ulong uVar2;
  
  if (param_2 != 0) {
    uVar2 = FUN_1000_1fce();
    if ((uVar2 < 0x20000) && ((int)(uVar2 >> 0x10) == 0)) {
      iVar1 = FUN_1000_4213(param_4,(int)uVar2,param_1);
      return (uint)((int)uVar2 - iVar1) / param_2;
    }
  }
  return 0;
}

