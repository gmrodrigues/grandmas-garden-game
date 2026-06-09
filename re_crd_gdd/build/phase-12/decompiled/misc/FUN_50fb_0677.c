// TIM2.EXE: FUN_50fb_0677 @ file 0x056827 Ghidra 0x51627
// Subsystem: misc | Size: 89 bytes


void __cdecl16far FUN_50fb_0677(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  iVar1 = FUN_50fb_071e(*(undefined2 *)(param_1 + 4));
  if (DAT_554c_5eb2 < (uint)(*(int *)(param_1 + 6) - iVar1)) {
    uVar2 = FUN_1000_337f(*(undefined2 *)(param_1 + 2),iVar1 + 1);
    *(undefined2 *)(param_1 + 2) = uVar2;
    *(int *)(param_1 + 6) = iVar1;
  }
  *(undefined2 *)0x14 = local_20;
  return;
}

