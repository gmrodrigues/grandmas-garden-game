// TIM2.EXE: FUN_2424_36fe @ file 0x02CB3E Ghidra 0x2793E
// Subsystem: misc | Size: 72 bytes


undefined2 __cdecl16far FUN_2424_36fe(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = FUN_2424_4087((int)param_1,param_1._2_2_);
  if (iVar1 == 0) {
    if (*(int *)((int)param_1 + 8) == 0x76) {
      uVar2 = FUN_2424_479c((int)param_1,param_1._2_2_,param_2);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = FUN_2424_3d5f((int)param_1,param_1._2_2_,param_2);
  }
  return uVar2;
}

