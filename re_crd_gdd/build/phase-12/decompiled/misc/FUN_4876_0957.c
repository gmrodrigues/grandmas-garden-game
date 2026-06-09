// TIM2.EXE: FUN_4876_0957 @ file 0x04E2B7 Ghidra 0x490B7
// Subsystem: misc | Size: 146 bytes


undefined2 __cdecl16far FUN_4876_0957(undefined4 param_1)

{
  uint uVar1;
  
  if ((DAT_5b41_1b88 & 6) != 0) {
    *(uint *)((int)param_1 + 0x34) = (uint)(*(int *)((int)param_1 + 0x34) == 0);
  }
  if (*(int *)((int)param_1 + 0x34) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)((int)param_1 + 0x2c) - 1;
  }
  if (*(uint *)((int)param_1 + 0x2e) < uVar1) {
    *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + 1;
  }
  else {
    if (*(uint *)((int)param_1 + 0x2e) <= uVar1) goto LAB_4876_09bd;
    *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + -1;
  }
  *(undefined2 *)((int)param_1 + 0x26) = 2;
LAB_4876_09bd:
  if (*(uint *)((int)param_1 + 0x2e) == uVar1) {
    DAT_5b41_1ae4 = 0;
    DAT_5b41_1ae2 = 0;
    return 3;
  }
  DAT_5b41_1ae4 = param_1._2_2_;
  DAT_5b41_1ae2 = (int)param_1;
  return 1;
}

