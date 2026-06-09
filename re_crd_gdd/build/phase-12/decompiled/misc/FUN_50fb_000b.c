// TIM2.EXE: FUN_50fb_000b @ file 0x0561BB Ghidra 0x50FBB
// Subsystem: misc | Size: 84 bytes


undefined2 * __cdecl16far FUN_50fb_000b(undefined2 *param_1,undefined2 *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  if (param_1 == (undefined2 *)0x0) {
    param_1 = (undefined2 *)FUN_1000_1dd2(2);
    if (param_1 == (undefined2 *)0x0) goto LAB_50fb_0043;
  }
  *param_1 = *param_2;
  *(int *)*param_1 = *(int *)*param_1 + 1;
LAB_50fb_0043:
  puVar1 = (uint *)0x10;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar2);
  *(undefined2 *)0x14 = local_20;
  return param_1;
}

