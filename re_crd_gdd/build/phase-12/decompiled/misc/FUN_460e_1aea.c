// TIM2.EXE: FUN_460e_1aea @ file 0x04CDCA Ghidra 0x47BCA
// Subsystem: misc | Size: 139 bytes


undefined2 __cdecl16far FUN_460e_1aea(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (param_1 != 0) {
    FUN_460e_1aea(0,0);
  }
  if (param_2 == 0) {
    if (DAT_5b41_1c80 != 0) {
      FUN_1000_0c9d(DAT_5b41_1c80);
    }
    DAT_5b41_1c80 = 0;
    DAT_5b41_1ba0 = 0;
    DAT_5b41_1b9e = 0;
    uVar1 = 0;
  }
  else {
    if (param_1 != 0) {
      FUN_4340_0a29(0x7b70,0x554c,param_1,0x554c);
    }
    DAT_5b41_1c80 = FUN_1000_0b20(0x7b70,0x3fc6);
    if (DAT_5b41_1c80 == 0) {
      uVar1 = 0;
    }
    else {
      DAT_5b41_1ba0 = 0x460e;
      DAT_5b41_1b9e = 0x1b75;
      DAT_5b41_1b9c = 0;
      uVar1 = 1;
    }
  }
  return uVar1;
}

