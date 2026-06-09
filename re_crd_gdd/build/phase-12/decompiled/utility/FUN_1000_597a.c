// TIM2.EXE: FUN_1000_597a @ file 0x01AB7A Ghidra 0x1597A
// Subsystem: utility | Size: 69 bytes


int __cdecl16far FUN_1000_597a(int param_1,undefined2 param_2,undefined2 param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined2 unaff_SS;
  
  if (param_1 == 0) {
    param_1 = FUN_1000_1dd2(4);
    if (param_1 == 0) goto LAB_1000_59ac;
  }
  FUN_1000_5bc7(param_1,param_2);
  *(undefined2 *)(param_1 + 2) = param_3;
LAB_1000_59ac:
  puVar1 = (uint *)0x10;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar2);
  return param_1;
}

