// TIM2.EXE: FUN_50fb_0618 @ file 0x0567C8 Ghidra 0x515C8
// Subsystem: misc | Size: 95 bytes


void __cdecl16far FUN_50fb_0618(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 1;
  iVar1 = FUN_50fb_071e(param_2 + 1);
  if (DAT_554c_5eb2 < (uint)(*(int *)(param_1 + 6) - iVar1)) {
    uVar2 = FUN_1000_337f(*(undefined2 *)(param_1 + 2),iVar1 + 1);
    *(undefined2 *)(param_1 + 2) = uVar2;
    *(int *)(param_1 + 6) = iVar1;
  }
  *(undefined2 *)0x14 = local_20;
  return;
}

