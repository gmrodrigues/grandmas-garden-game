// TIM2.EXE: FUN_1000_1c97 @ file 0x016E97 Ghidra 0x11C97
// Subsystem: utility | Size: 71 bytes


int FUN_1000_1c97(undefined2 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if (param_3 == 0) {
    param_3 = -0x77ac;
  }
  if (param_2 == 0) {
    param_2 = 0x59a0;
  }
  uVar1 = FUN_1000_140a(param_3,param_2,param_1);
  FUN_1000_1c2f(uVar1,param_1);
  FUN_1000_5401(param_3,0x59a4);
  return param_3;
}

