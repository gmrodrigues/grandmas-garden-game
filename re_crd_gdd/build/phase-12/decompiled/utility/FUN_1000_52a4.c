// TIM2.EXE: FUN_1000_52a4 @ file 0x01A4A4 Ghidra 0x152A4
// Subsystem: utility | Size: 241 bytes


undefined2 __cdecl16far FUN_1000_52a4(int *param_1,int param_2,int param_3,uint param_4)

{
  undefined2 uVar1;
  
  if ((((int *)param_1[7] == param_1) && (param_3 < 3)) && (param_4 < 0x8000)) {
    if ((DAT_554c_5e08 == 0) && (param_1 == (int *)0x57e4)) {
      DAT_554c_5e08 = 1;
    }
    else if ((DAT_554c_5e06 == 0) && (param_1 == (int *)0x57d4)) {
      DAT_554c_5e06 = 1;
    }
    if (*param_1 != 0) {
      FUN_1000_43c4(param_1,0,0,1);
    }
    if ((*(byte *)(param_1 + 1) & 4) != 0) {
      FUN_1000_3157(param_1[4]);
    }
    param_1[1] = param_1[1] & 0xfff3;
    param_1[3] = 0;
    param_1[4] = (int)param_1 + 5;
    param_1[5] = (int)param_1 + 5;
    if ((param_3 != 2) && (param_4 != 0)) {
      DAT_554c_57ca = 0x1000;
      DAT_554c_57c8 = 0x5b6c;
      if (param_2 == 0) {
        param_2 = FUN_1000_3226(param_4);
        if (param_2 == 0) goto LAB_1000_536e;
        param_1[1] = param_1[1] | 4;
      }
      param_1[5] = param_2;
      param_1[4] = param_2;
      param_1[3] = param_4;
      if (param_3 == 1) {
        param_1[1] = param_1[1] | 8;
      }
    }
    uVar1 = 0;
  }
  else {
LAB_1000_536e:
    uVar1 = 0xffff;
  }
  return uVar1;
}

