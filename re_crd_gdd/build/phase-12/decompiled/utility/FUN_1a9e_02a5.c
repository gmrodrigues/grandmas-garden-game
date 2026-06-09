// TIM2.EXE: FUN_1a9e_02a5 @ file 0x01FE85 Ghidra 0x1AC85
// Subsystem: utility | Size: 120 bytes


undefined2 __cdecl16near FUN_1a9e_02a5(undefined2 param_1,uint param_2)

{
  undefined2 uVar1;
  
  if (DAT_5b41_02e7 < param_2) {
    FUN_1000_0624((uint)*(byte *)(DAT_5b41_0042 + 0x1a) + DAT_5b41_0044,0x554c,param_1,param_2,
                  (int)param_2 >> 0xf);
    *(char *)(DAT_5b41_0042 + 0x1a) = *(char *)(DAT_5b41_0042 + 0x1a) + (char)param_2;
    uVar1 = 0;
  }
  else {
    if ((DAT_5b41_02e9 & 0x40) != 0) {
      FUN_1000_0624((undefined2)DAT_5b41_0049,DAT_5b41_0049._2_2_,param_1,param_2,
                    (int)param_2 >> 0xf);
    }
    DAT_5b41_02e7 = DAT_5b41_02e7 - param_2;
    FUN_1000_1a00(0x1a9e);
    uVar1 = 1;
  }
  return uVar1;
}

