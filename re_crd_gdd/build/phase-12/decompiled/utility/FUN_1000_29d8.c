// TIM2.EXE: FUN_1000_29d8 @ file 0x017BD8 Ghidra 0x129D8
// Subsystem: utility | Size: 102 bytes


undefined2 __cdecl16far FUN_1000_29d8(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  
  if (((int)param_1 == 0 && param_1._2_2_ == 0) ||
     ((param_1._2_2_ == 0x554c && ((int)param_1 == 0)))) {
    uVar2 = 0;
  }
  else {
    iVar1 = ((int *)((int)param_1 + param_2))[1];
    iVar3 = *(int *)((int)param_1 + param_2);
    iVar3 = iVar3 - *(int *)(iVar3 + -2);
    uVar2 = *(undefined2 *)(*(int *)(iVar3 + -8) + 0x1a);
  }
  return uVar2;
}

