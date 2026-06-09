// TIM2.EXE: FUN_50fb_0516 @ file 0x0566C6 Ghidra 0x514C6
// Subsystem: misc | Size: 181 bytes


undefined2 * __cdecl16far
FUN_50fb_0516(undefined2 *param_1,undefined2 param_2,int param_3,undefined2 param_4,int param_5,
             int param_6)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  if ((param_1 != (undefined2 *)0x0) ||
     (param_1 = (undefined2 *)FUN_1000_1dd2(10), param_1 != (undefined2 *)0x0)) {
    *param_1 = 1;
    param_1[4] = 0;
    param_1[2] = param_3 + param_5;
    uVar3 = FUN_50fb_071e(param_1[2] + param_6);
    param_1[3] = uVar3;
    uVar3 = FUN_1000_3226(param_1[3] + 1);
    param_1[1] = uVar3;
    if (param_1[1] == 0) {
      FUN_1000_59e3(0x59aa);
    }
    FUN_1000_49eb(param_1[1],param_2,param_3);
    FUN_1000_49eb(param_1[1] + param_3,param_4,param_5);
    *(undefined1 *)(param_3 + param_5 + param_1[1]) = 0;
  }
  puVar1 = (uint *)0x10;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar2);
  return param_1;
}

