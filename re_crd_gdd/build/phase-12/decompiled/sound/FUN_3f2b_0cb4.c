// TIM2.EXE: FUN_3f2b_0cb4 @ file 0x045164 Ghidra 0x3FF64
// Subsystem: sound | Size: 99 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far FUN_3f2b_0cb4(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  if ((0 < param_1) && (param_1 < 5)) {
    if (DAT_5b41_1b54 == (int *)0x0 && DAT_5b41_1b56 == 0) {
      iVar3 = param_1 >> 0xf;
      uVar2 = FUN_1000_199e(0,0);
      iVar3 = iVar3 + (uint)(0xffdf < uVar2);
      DAT_5b41_1b58 = FUN_22de_01ec(uVar2 + 0x20,iVar3);
      if (DAT_5b41_1b58 == 0 && iVar3 == 0) {
        DAT_5b41_1b5a = iVar3;
        return 0;
      }
      _DAT_5b41_1b54 = (int *)((ulong)(iVar3 + 1) << 0x10);
      DAT_5b41_1b5a = iVar3;
      *_DAT_5b41_1b54 = param_1;
    }
  }
  uVar1 = DAT_5b41_1b56;
  return uVar1;
}

