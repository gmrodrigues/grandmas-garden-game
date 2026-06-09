// TIM2.EXE: FUN_406b_158a @ file 0x046E3A Ghidra 0x41C3A
// Subsystem: sound | Size: 475 bytes


int __cdecl16far FUN_406b_158a(int param_1,int param_2)

{
  undefined4 local_6;
  
  param_1 = param_1 * 8;
  local_6 = (int *)CONCAT22(0x53bd,(int *)(param_1 + 0x28));
  if ((DAT_53bd_0052 & 2) == 0) {
    if ((DAT_53bd_0052 & 2) == 0) {
      *local_6 = 0;
      if (*(int *)(param_1 + 0x2a) != param_2) {
        *(int *)(param_1 + 0x2a) = param_2;
        if (param_2 != 0) {
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
          if ((*(int *)(param_1 + 0x2c) == 2) && ((DAT_53bd_0052 & 4) == 0)) {
            *local_6 = 4;
          }
          else {
            *local_6 = 2;
          }
        }
        if (DAT_554c_5594 == '\0') {
          DAT_5b41_1b80 = DAT_5b41_1b7c;
          DAT_5b41_1b82 = DAT_5b41_1b7e;
        }
        else {
          FUN_406b_0b9d((undefined2 *)&DAT_5b41_1b80,(undefined2 *)&DAT_5b41_1b82);
        }
        *(undefined2 *)(param_1 + 0x2e) = DAT_53bd_0000;
      }
      if ((DAT_53bd_004c == 0) && (*(int *)(param_1 + 0x2e) != 0)) {
        *(int *)(param_1 + 0x2e) = *(int *)(param_1 + 0x2e) + -1;
      }
      if (*(int *)(param_1 + 0x2e) == 0) {
        if (param_2 != 0) {
          *local_6 = 8;
        }
        *(undefined2 *)(param_1 + 0x2c) = 0;
        *(undefined2 *)(param_1 + 0x2e) = 0;
      }
      param_2 = *local_6;
    }
    else {
      param_2 = 0;
    }
  }
  else {
    if (*(int *)(param_1 + 0x2a) != param_2) {
      *(int *)(param_1 + 0x2a) = param_2;
      if (param_2 == 0) {
        if (*local_6 == 8) {
          *local_6 = 0;
        }
        else {
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
          if (((*(int *)(param_1 + 0x2c) == 1) && (*local_6 != 2)) || ((DAT_53bd_0052 & 4) != 0)) {
            *local_6 = 2;
          }
          else {
            *local_6 = 4;
          }
        }
      }
      if (DAT_554c_5594 == '\0') {
        DAT_5b41_1b80 = DAT_5b41_1b7c;
        DAT_5b41_1b82 = DAT_5b41_1b7e;
      }
      else {
        FUN_406b_0b9d((undefined2 *)&DAT_5b41_1b80,(undefined2 *)&DAT_5b41_1b82);
      }
      *(undefined2 *)(param_1 + 0x2e) = DAT_53bd_0000;
    }
    if ((DAT_53bd_004c == 0) && (*(int *)(param_1 + 0x2e) != 0)) {
      *(int *)(param_1 + 0x2e) = *(int *)(param_1 + 0x2e) + -1;
    }
    if ((*(int *)(param_1 + 0x2e) == 0) || (0 < *(int *)(param_1 + 0x2c))) {
      if (param_2 == 0) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          *local_6 = 0;
        }
      }
      else {
        *local_6 = 8;
      }
      *(undefined2 *)(param_1 + 0x2c) = 0;
      param_2 = *local_6;
    }
  }
  return param_2;
}

