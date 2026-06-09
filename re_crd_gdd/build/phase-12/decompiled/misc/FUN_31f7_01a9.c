// TIM2.EXE: FUN_31f7_01a9 @ file 0x037319 Ghidra 0x32119
// Subsystem: misc | Size: 111 bytes


void __cdecl16far FUN_31f7_01a9(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 != 0) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      *(undefined2 *)(iVar1 + 0x10) = 2;
    }
    else {
      *(undefined2 *)(iVar1 + 0x10) = 0;
    }
  }
  *(undefined2 *)(iVar1 + 0xa8) = *(undefined2 *)(iVar1 + 0x10);
  FUN_31f7_0125(iVar1,param_1._2_2_);
  FUN_28eb_3328(iVar1,param_1._2_2_);
  FUN_2424_0915(iVar1,param_1._2_2_,3);
  FUN_2424_0f94(iVar1,param_1._2_2_,3);
  FUN_28eb_2d82(iVar1,param_1._2_2_,2);
  return;
}

