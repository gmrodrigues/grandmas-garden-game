// TIM2.EXE: FUN_1000_8a46 @ file 0x01DC46 Ghidra 0x18A46
// Subsystem: utility | Size: 99 bytes


undefined2 __cdecl16far FUN_1000_8a46(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0 && *(int *)(param_1 + 6) == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(param_2 + 4) == 0 && *(int *)(param_2 + 6) == 0) {
    uVar1 = 1;
  }
  else {
    iVar2 = FUN_1000_a3c1(*(int *)(param_1 + 4) + *(int *)((int)*(undefined4 *)(param_1 + 4) + 4),
                          *(undefined2 *)(param_1 + 6),
                          *(int *)(param_2 + 4) + *(int *)((int)*(undefined4 *)(param_2 + 4) + 4),
                          *(undefined2 *)(param_2 + 6));
    if (iVar2 < 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

