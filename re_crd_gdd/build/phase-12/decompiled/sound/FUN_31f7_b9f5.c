// TIM2.EXE: FUN_31f7_b9f5 @ file 0x042B65 Ghidra 0x3D965
// Subsystem: sound | Size: 85 bytes


void __cdecl16far
FUN_31f7_b9f5(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6)

{
  int iVar1;
  
  FUN_31f7_b9c5((int)param_1,param_1._2_2_,param_3,param_4,param_5,param_6);
  while( true ) {
    iVar1 = *(int *)((int)param_1 + 0x8e);
    param_1._0_2_ = *(int *)((int)param_1 + 0x8c);
    if ((int)param_1 == 0 && iVar1 == 0) break;
    FUN_31f7_ba4a((int)param_1,iVar1,param_2);
    param_1._2_2_ = iVar1;
  }
  return;
}

