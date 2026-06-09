// TIM2.EXE: FUN_1000_2976 @ file 0x017B76 Ghidra 0x12976
// Subsystem: utility | Size: 98 bytes


undefined2 __cdecl16far FUN_1000_2976(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  if (((int)param_1 == 0 && param_1._2_2_ == 0) ||
     ((param_1._2_2_ == 0x554c && ((int)param_1 == 0)))) {
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)((int)param_1 + param_2) - *(int *)(*(int *)((int)param_1 + param_2) + -2);
    uVar1 = *(undefined2 *)(*(int *)(iVar2 + -8) + 0x1a);
  }
  return uVar1;
}

