// TIM2.EXE: FUN_2424_2165 @ file 0x02B5A5 Ghidra 0x263A5
// Subsystem: misc | Size: 278 bytes


void __cdecl16far FUN_2424_2165(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  FUN_28eb_1599((int)param_1,param_1._2_2_,&local_a);
  if (param_2 == 2) {
    FUN_2424_02ca();
    DAT_554c_42ce = 0;
    FUN_1a9e_5722(local_a,local_8 + 1,local_a + local_6 + -1,local_8 + local_4 + -1);
    FUN_1a9e_5722(local_a,local_8 + local_4 + -1,local_a + local_6 + -1,local_8 + 1);
    DAT_554c_42ce = 0xc;
    FUN_1a9e_5722(local_a,local_8,local_a + local_6 + -1,local_8 + local_4 + -2);
    FUN_1a9e_5722(local_a,local_8 + local_4 + -2,local_a + local_6 + -1,local_8);
  }
  FUN_2424_2fbd(&local_a);
  if (((param_3 != 0) && (DAT_5b41_0939 != 9)) && ((DAT_5b41_0939 & 0x8000) == 0)) {
    uVar1 = FUN_28eb_12a3((int)param_1,param_1._2_2_);
    FUN_2424_31e8(uVar1,&local_a);
  }
  if ((*(byte *)((int)param_1 + 0xf) & 0x20) != 0) {
    FUN_2424_36c1((int)param_1,param_1._2_2_);
  }
  FUN_2424_1e00(&local_a);
  return;
}

