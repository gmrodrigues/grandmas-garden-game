// TIM2.EXE: FUN_460e_15eb @ file 0x04C8CB Ghidra 0x476CB
// Subsystem: misc | Size: 167 bytes


undefined2 __cdecl16far FUN_460e_15eb(int param_1,undefined2 param_2,int *param_3)

{
  int iVar1;
  int local_a [2];
  int *local_6;
  
  FUN_460e_0f98(param_1,0x10);
  FUN_460e_0f98(param_2,0x20);
  if (param_1 != 0) {
    local_a[0] = param_1;
    local_a[1] = 0;
    FUN_460e_15eb(0,0,local_a);
  }
  if ((int *)param_3 != (int *)0x0 || param_3._2_2_ != 0) {
    FUN_460e_1692((int *)param_3,param_3._2_2_);
    iVar1 = 0x200;
    local_6 = &DAT_5408_0000;
    while ((iVar1 != 0 && (*local_6 != 0))) {
      iVar1 = iVar1 + -1;
      local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 1);
    }
    if (1 < iVar1) {
      while ((*param_3 != 0 && (iVar1 != 0))) {
        *local_6 = *param_3;
        param_3 = (int *)CONCAT22(param_3._2_2_,(int *)param_3 + 1);
        local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 1);
        iVar1 = iVar1 + -1;
      }
      return 1;
    }
  }
  return 0;
}

