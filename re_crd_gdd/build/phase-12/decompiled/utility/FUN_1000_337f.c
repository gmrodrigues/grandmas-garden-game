// TIM2.EXE: FUN_1000_337f @ file 0x01857F Ghidra 0x1337F
// Subsystem: utility | Size: 83 bytes


int * __cdecl16far FUN_1000_337f(int *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    FUN_1000_3157(param_1);
    param_1 = (int *)0x0;
  }
  else if (param_1 == (int *)0x0) {
    param_1 = (int *)FUN_1000_3226(param_2);
  }
  else {
    piVar2 = param_1 + -2;
    uVar1 = param_2 + 5U & 0xfffe;
    if (uVar1 < 8) {
      uVar1 = 8;
    }
    if (*piVar2 - 1U < uVar1) {
      param_1 = piVar2;
      FUN_1000_3308();
    }
    else if (uVar1 < *piVar2 - 1U) {
      param_1 = piVar2;
      FUN_1000_333d();
    }
  }
  return param_1;
}

