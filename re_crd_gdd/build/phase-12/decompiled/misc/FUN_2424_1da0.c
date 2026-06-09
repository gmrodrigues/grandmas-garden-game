// TIM2.EXE: FUN_2424_1da0 @ file 0x02B1E0 Ghidra 0x25FE0
// Subsystem: misc | Size: 96 bytes


void __cdecl16far FUN_2424_1da0(int *param_1,int *param_2)

{
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  local_a = *param_1;
  local_8 = param_1[1];
  local_6 = (*param_2 + local_a) - local_a;
  local_4 = (param_2[1] + local_8) - local_8;
  FUN_2424_1e00(&local_a);
  return;
}

