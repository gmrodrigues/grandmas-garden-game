// TIM2.EXE: FUN_4876_083e @ file 0x04E19E Ghidra 0x48F9E
// Subsystem: misc | Size: 281 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far FUN_4876_083e(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0xe);
  if (iVar1 == 1) {
    *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + 1;
    *(undefined2 *)((int)param_1 + 0x26) = 2;
    if (*(uint *)((int)param_1 + 0x2e) < *(uint *)((int)param_1 + 0x2c)) {
LAB_4876_0937:
      DAT_5b41_1ae4 = param_1._2_2_;
      DAT_5b41_1ae2 = (int)param_1;
      goto LAB_4876_0944;
    }
  }
  else {
    if (iVar1 == 2) {
      if (param_2 != 0) {
        *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + 1;
        if (*(uint *)((int)param_1 + 0x2c) <= *(uint *)((int)param_1 + 0x2e)) {
          *(undefined2 *)((int)param_1 + 0x2e) = 1;
        }
        *(undefined2 *)((int)param_1 + 0x26) = 2;
        if ((_DAT_5b41_1b88 & 2) != 0) {
          return 2;
        }
      }
      if ((param_2 == 0) && (*(int *)((int)param_1 + 0x2e) != 0)) {
        *(undefined2 *)((int)param_1 + 0x2e) = 0;
        *(undefined2 *)((int)param_1 + 0x26) = 2;
      }
      return 0;
    }
    if (iVar1 != 5) goto LAB_4876_0944;
    *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + 1;
    *(undefined2 *)((int)param_1 + 0x26) = 2;
    if (*(uint *)((int)param_1 + 0x2e) < *(uint *)((int)param_1 + 0x2c)) goto LAB_4876_0937;
    if ((_DAT_5b41_1b88 & 8) != 0) {
      *(undefined2 *)((int)param_1 + 0x2e) = 1;
      return 2;
    }
    if (_DAT_5b41_1b88 != 0) {
      *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + -1;
      goto LAB_4876_0944;
    }
  }
  DAT_5b41_1ae4 = 0;
  DAT_5b41_1ae2 = 0;
  *(undefined2 *)((int)param_1 + 0x2e) = 0;
LAB_4876_0944:
  if (DAT_5b41_1ae2 == 0 && DAT_5b41_1ae4 == 0) {
    return 2;
  }
  return 1;
}

