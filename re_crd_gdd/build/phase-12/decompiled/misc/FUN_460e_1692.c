// TIM2.EXE: FUN_460e_1692 @ file 0x04C972 Ghidra 0x47772
// Subsystem: misc | Size: 186 bytes


void __cdecl16far FUN_460e_1692(int *param_1)

{
  int iVar1;
  int iVar2;
  int *local_a;
  int *local_6;
  
  if ((int *)param_1 != (int *)0x0 || param_1._2_2_ != 0) {
    iVar1 = 0;
    while (*param_1 != 0) {
      local_6 = &DAT_5408_0000;
      while ((*local_6 != 0 && (*local_6 != *param_1))) {
        local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 1);
      }
      if (*local_6 != 0) {
        if (*local_6 == DAT_5b41_1c1e) {
          DAT_5b41_1c1e = 0;
        }
        *local_6 = 0;
        iVar1 = iVar1 + 1;
      }
      param_1 = (int *)CONCAT22(param_1._2_2_,(int *)param_1 + 1);
    }
    if (iVar1 != 0) {
      local_a = &DAT_5408_0000;
      local_6 = &DAT_5408_0000;
      for (iVar2 = 0x200; iVar2 != 0; iVar2 = iVar2 + -1) {
        if (*local_6 != 0) {
          *local_a = *local_6;
          local_a = (int *)CONCAT22(local_a._2_2_,(int *)local_a + 1);
        }
        local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 1);
      }
      while (iVar1 != 0) {
        *local_a = 0;
        local_a = (int *)CONCAT22(local_a._2_2_,(int *)local_a + 1);
        iVar1 = iVar1 + -1;
      }
    }
  }
  return;
}

