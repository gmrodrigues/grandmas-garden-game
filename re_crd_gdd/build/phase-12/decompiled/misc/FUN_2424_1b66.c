// TIM2.EXE: FUN_2424_1b66 @ file 0x02AFA6 Ghidra 0x25DA6
// Subsystem: misc | Size: 570 bytes


void __cdecl16far
FUN_2424_1b66(undefined2 param_1,undefined2 param_2,undefined2 param_3,int param_4)

{
  uint local_40;
  int local_3e;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  if (param_4 < 5) {
    FUN_2424_1a04(param_1,param_2,param_3);
  }
  else {
    FUN_1000_199e();
    FUN_1000_199e();
    FUN_1000_199e();
    FUN_1000_199e();
    local_6 = FUN_1000_19bf();
    local_4 = FUN_1000_19bf();
    local_3e = 0;
    for (local_40 = 0; (local_3e < 0 || ((local_3e < 1 && (local_40 < 0x11))));
        local_40 = local_40 + 1) {
      local_a = FUN_1000_19bf();
      local_8 = FUN_1000_19bf();
      if ((local_6 != local_a) || (local_4 != local_8)) {
        FUN_2424_1a04(&local_6,&local_a,param_3);
        local_6 = local_a;
        local_4 = local_8;
      }
      FUN_1000_180a();
      FUN_1000_180a();
      local_3e = local_3e + (uint)(0xfffe < local_40);
    }
  }
  return;
}

