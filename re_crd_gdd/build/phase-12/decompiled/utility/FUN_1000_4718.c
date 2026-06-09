// TIM2.EXE: FUN_1000_4718 @ file 0x019918 Ghidra 0x14718
// Subsystem: utility | Size: 76 bytes


uint __cdecl16far FUN_1000_4718(undefined2 param_1,uint param_2,uint param_3,undefined2 param_4)

{
  ulong uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_1000_1fce();
    if ((uVar1 < 0x20000) && ((int)(uVar1 >> 0x10) == 0)) {
      param_3 = FUN_1000_4ed6(param_4,(int)uVar1,param_1);
      param_3 = param_3 / param_2;
    }
    else {
      param_3 = 0;
    }
  }
  return param_3;
}

