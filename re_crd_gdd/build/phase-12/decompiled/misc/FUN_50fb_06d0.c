// TIM2.EXE: FUN_50fb_06d0 @ file 0x056880 Ghidra 0x51680
// Subsystem: misc | Size: 78 bytes


void __cdecl16far FUN_50fb_06d0(int param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  *(undefined2 *)(param_1 + 6) = param_2;
  uVar1 = FUN_1000_337f(*(undefined2 *)(param_1 + 2),*(int *)(param_1 + 6) + 1);
  *(undefined2 *)(param_1 + 2) = uVar1;
  if (*(int *)(param_1 + 2) == 0) {
    FUN_1000_59e3(0x59aa);
  }
  *(undefined2 *)0x14 = local_20;
  return;
}

