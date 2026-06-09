// TIM2.EXE: FUN_4bdc_2fa3 @ file 0x053F63 Ghidra 0x4ED63
// Subsystem: physics | Size: 48 bytes


int __cdecl16far FUN_4bdc_2fa3(undefined4 param_1,int param_2)

{
  for (; ((int)param_1 != 0 || param_1._2_2_ != 0 && (param_2 != 0)); param_2 = param_2 + -1) {
    param_1 = CONCAT22(*(undefined2 *)((int)param_1 + 0x174),*(undefined2 *)((int)param_1 + 0x172));
  }
  return (int)param_1;
}

