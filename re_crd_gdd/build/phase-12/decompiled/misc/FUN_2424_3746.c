// TIM2.EXE: FUN_2424_3746 @ file 0x02CB86 Ghidra 0x27986
// Subsystem: misc | Size: 68 bytes


void __cdecl16far FUN_2424_3746(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_2424_4087((int)param_1,param_1._2_2_);
  if (iVar1 == 0) {
    if (*(int *)((int)param_1 + 8) == 0x76) {
      FUN_2424_48ce((int)param_1,param_1._2_2_,param_2);
    }
  }
  else {
    FUN_2424_3ebc((int)param_1,param_1._2_2_,param_2);
  }
  return;
}

