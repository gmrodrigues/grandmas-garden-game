// TIM2.EXE: FUN_4876_04b6 @ file 0x04DE16 Ghidra 0x48C16
// Subsystem: misc | Size: 453 bytes


undefined2 __cdecl16far FUN_4876_04b6(undefined2 param_1,int param_2,int *param_3)

{
  int in_DX;
  undefined2 uVar1;
  undefined2 uVar2;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int *local_a;
  int local_6;
  int iStack_4;
  
  if ((int *)param_3 != (int *)0x0 || param_3._2_2_ != 0) {
    if (param_2 != -1) {
      ((int *)param_3)[1] = 0;
      *param_3 = 0;
      ((int *)param_3)[3] = 0;
      ((int *)param_3)[2] = 0;
    }
    local_6 = FUN_460e_0f42(param_1);
    if (local_6 != 0 || in_DX != 0) {
      if (param_2 == 0) {
        uVar1 = *(undefined2 *)(local_6 + 0x10);
        uVar2 = 0;
        while (local_6 = FUN_460e_13ae(uVar2,uVar1), local_6 != 0 || in_DX != 0) {
          iStack_4 = in_DX;
          FUN_4876_04b6(*(undefined2 *)(local_6 + 0xc),0xffff,(int *)param_3,param_3._2_2_);
          uVar1 = *(undefined2 *)(local_6 + 0x10);
          uVar2 = *(undefined2 *)(local_6 + 0xc);
        }
      }
      else {
        local_a = (int *)CONCAT22(in_DX,(int *)(local_6 + 0x28));
        local_c = *local_a;
        if (local_c == 0) {
          return 0;
        }
        local_e = 0;
        local_10 = 0;
        local_12 = 0;
        local_14 = 0;
        iStack_4 = in_DX;
        FUN_4551_03eb(local_c,*(int *)(local_6 + 0x2a) + *(int *)(local_6 + 0x2e),&local_14);
        if ((local_10 != 0) && (local_e != 0)) {
          uVar1 = (undefined2)((ulong)local_a >> 0x10);
          local_14 = local_14 + *(int *)(local_6 + 0x14) + ((int *)local_a)[4];
          local_12 = local_12 + *(int *)(local_6 + 0x16) + ((int *)local_a)[5];
          if ((((int *)param_3)[2] == 0) || (((int *)param_3)[3] == 0)) {
            *param_3 = local_14;
            ((int *)param_3)[1] = local_12;
            ((int *)param_3)[2] = local_10;
            ((int *)param_3)[3] = local_e;
          }
          if (local_14 < *param_3) {
            ((int *)param_3)[2] = ((int *)param_3)[2] + (*param_3 - local_14);
            *param_3 = local_14;
          }
          if (local_12 < ((int *)param_3)[1]) {
            ((int *)param_3)[3] = ((int *)param_3)[3] + (((int *)param_3)[1] - local_12);
            ((int *)param_3)[1] = local_12;
          }
          if (((int *)param_3)[2] + *param_3 < local_14 + local_10) {
            ((int *)param_3)[2] = (local_14 + local_10) - *param_3;
          }
          if (((int *)param_3)[1] + ((int *)param_3)[3] < local_12 + local_e) {
            ((int *)param_3)[3] = (local_12 + local_e) - ((int *)param_3)[1];
          }
        }
      }
      return 1;
    }
  }
  return 0;
}

