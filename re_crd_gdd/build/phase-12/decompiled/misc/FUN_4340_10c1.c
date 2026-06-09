// TIM2.EXE: FUN_4340_10c1 @ file 0x0496C1 Ghidra 0x444C1
// Subsystem: misc | Size: 61 bytes


void __cdecl16far FUN_4340_10c1(undefined2 *param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  
  if (((undefined2 *)param_1 != (undefined2 *)0x0 || param_1._2_2_ != 0) &&
     (param_2 != 0 || param_3 != 0)) {
    iVar1 = FUN_4340_1eea(*param_1,(undefined2 *)param_1,param_1._2_2_,param_2,param_3,param_4);
    (*(code *)*(undefined2 *)(iVar1 + 4))(0x4340);
  }
  return;
}

