// TIM2.EXE: FUN_2424_276e @ file 0x02BBAE Ghidra 0x269AE
// Subsystem: misc | Size: 114 bytes


void __cdecl16far FUN_2424_276e(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_5 < 5) {
    FUN_2424_27e0(param_1,param_2,param_3,param_4);
  }
  else {
    param_5 = (param_2 + param_4 >> 1) + param_5;
    FUN_2424_25bc(DAT_554c_42ce,4,param_1,param_1 >> 0xf,param_1 + param_3 >> 1,
                  param_1 + param_3 >> 0xf,param_3,param_3 >> 0xf,param_2,param_2 >> 0xf,param_5,
                  param_5 >> 0xf,param_4,param_4 >> 0xf);
  }
  return;
}

