// TIM2.EXE: FUN_1a9e_2422 @ file 0x022002 Ghidra 0x1CE02
// Subsystem: level | Size: 124 bytes


int __cdecl16far FUN_1a9e_2422(int param_1,int param_2,int param_3)

{
  if (param_1 < 0) {
    param_2 = 0;
    DAT_554c_4e8e = 0;
  }
  if (((DAT_554c_42df != '\0') && (DAT_554c_4e8e < 9)) && (1 < param_2)) {
    ((undefined2 *)&DAT_5b41_1d8e)[DAT_554c_4e8e] = param_1 * 3;
    ((undefined2 *)&DAT_5b41_1d7a)[DAT_554c_4e8e] = (param_1 + param_2) * 3;
    if (param_3 < 0) {
      param_3 = param_2 + param_3;
    }
    ((undefined2 *)&DAT_5b41_1d66)[DAT_554c_4e8e] = param_3 * 3;
    DAT_554c_4e8e = DAT_554c_4e8e + 1;
    return DAT_554c_4e8e;
  }
  return 0;
}

