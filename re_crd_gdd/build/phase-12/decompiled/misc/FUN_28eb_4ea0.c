// TIM2.EXE: FUN_28eb_4ea0 @ file 0x032F50 Ghidra 0x2DD50
// Subsystem: misc | Size: 145 bytes


void __cdecl16far FUN_28eb_4ea0(undefined4 param_1,int param_2)

{
  undefined2 *puVar1;
  
  if (param_2 == 1) goto LAB_28eb_4edc;
  if (param_2 == 2) goto LAB_28eb_4ed2;
  if (param_2 != 0xf) goto LAB_28eb_4ee4;
  if ((*(byte *)((int)param_1 + 0xc) & 0x10) == 0) {
    if ((*(byte *)((int)param_1 + 0xc) & 0x20) != 0) goto LAB_28eb_4ed2;
  }
  else if ((*(byte *)((int)param_1 + 0xc) & 0x20) == 0) {
LAB_28eb_4ed2:
    *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) ^ 0x20;
    goto LAB_28eb_4ee4;
  }
LAB_28eb_4edc:
  *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) ^ 0x10;
LAB_28eb_4ee4:
  puVar1 = (undefined2 *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 8);
  (*(code *)*puVar1)(0x28eb,(int)param_1,param_1._2_2_);
  FUN_28eb_3328((int)param_1,param_1._2_2_);
  FUN_2424_0915((int)param_1,param_1._2_2_,3);
  FUN_2424_0f94((int)param_1,param_1._2_2_,3);
  FUN_28eb_2d82((int)param_1,param_1._2_2_,2);
  return;
}

