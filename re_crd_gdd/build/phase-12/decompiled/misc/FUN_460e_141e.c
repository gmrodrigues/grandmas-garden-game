// TIM2.EXE: FUN_460e_141e @ file 0x04C6FE Ghidra 0x474FE
// Subsystem: misc | Size: 166 bytes


undefined2 * __cdecl16far FUN_460e_141e(undefined2 *param_1,int param_2,uint param_3)

{
  undefined4 local_a;
  undefined2 *local_6;
  int local_4;
  
  local_4 = 0;
  local_6 = (undefined2 *)0x0;
  local_a = (undefined2 *)0x0;
  for (; (undefined2 *)param_1 != (undefined2 *)0x0 || param_1._2_2_ != 0;
      param_1 = (undefined2 *)CONCAT22(((undefined2 *)param_1)[1],(undefined2 *)*param_1)) {
    if (((param_2 == 0) || (((undefined2 *)param_1)[8] == param_2)) &&
       ((param_3 == 0 || ((((undefined2 *)param_1)[0x12] & param_3) != 0)))) {
      ((undefined2 *)param_1)[5] = 0;
      ((undefined2 *)param_1)[4] = 0;
      if ((undefined2 *)local_a != (undefined2 *)0x0 || local_a._2_2_ != 0) {
        ((undefined2 *)local_a)[5] = param_1._2_2_;
        ((undefined2 *)local_a)[4] = (undefined2 *)param_1;
      }
      if (local_6 == (undefined2 *)0x0 && local_4 == 0) {
        local_6 = (undefined2 *)param_1;
        local_4 = param_1._2_2_;
      }
      local_a = param_1;
    }
  }
  return local_6;
}

