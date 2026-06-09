// TIM2.EXE: FUN_2e67_08ed @ file 0x03415D Ghidra 0x2EF5D
// Subsystem: misc | Size: 237 bytes


undefined2 __cdecl16far FUN_2e67_08ed(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 local_a;
  undefined4 local_6;
  
  if (DAT_5b41_0bec != 0) {
    local_a = (uint *)0x0;
    local_6 = &DAT_5b41_0c48;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      if (((((param_4 != 0) && (((uint *)local_6)[3] == param_4)) && (1999 < *local_6)) &&
          ((*local_6 < 4000 && (1999 < param_1)))) && (param_1 < 4000)) {
        if (param_2 < ((uint *)local_6)[1]) {
          return 0;
        }
LAB_2e67_096a:
        local_a = local_6;
        break;
      }
      if ((*local_6 == param_1) && ((uint)(param_4 == 0) == ((uint *)local_6)[3]))
      goto LAB_2e67_096a;
      if (*local_6 == 0) {
        if ((uint *)local_a == (uint *)0x0 && local_a._2_2_ == 0) {
          local_a = local_6;
        }
      }
      local_6 = (uint *)CONCAT22(local_6._2_2_,(uint *)local_6 + 4);
    }
    if ((uint *)local_a != (uint *)0x0 || local_a._2_2_ != 0) {
      *local_a = param_1;
      ((uint *)local_a)[1] = param_2;
      ((uint *)local_a)[2] = param_3;
      ((uint *)local_a)[3] = (uint)(param_4 == 0);
      return 1;
    }
  }
  return 0;
}

