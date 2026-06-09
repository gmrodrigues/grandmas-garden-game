// TIM2.EXE: FUN_1000_5395 @ file 0x01A595 Ghidra 0x15395
// Subsystem: utility | Size: 43 bytes


void FUN_1000_5395(int *param_1,int param_2,undefined2 param_3)

{
  FUN_1000_49eb(*param_1,param_3,param_2);
  *param_1 = *param_1 + param_2;
  *(undefined1 *)*param_1 = 0;
  return;
}

