// TIM2.EXE: FUN_1000_8441 @ file 0x01D641 Ghidra 0x18441
// Subsystem: utility | Size: 177 bytes


int __cdecl16far FUN_1000_8441(int param_1,undefined2 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined4 local_a;
  
  iVar3 = param_3[1];
  iVar1 = *param_3;
  if (((*(uint *)(iVar1 + 8) & 0x50) == 0x50) && (*(int *)(iVar1 + 6) != -1)) {
    piVar2 = (int *)(param_1 + *(int *)(iVar1 + 6));
    local_a = (int *)CONCAT22(param_2,piVar2);
    if ((*(byte *)(iVar1 + 9) & 0x10) == 0) {
      iVar3 = *local_a;
      local_a._2_2_ = 0x554c;
    }
    else {
      iVar3 = *local_a;
      local_a._2_2_ = piVar2[1];
    }
    param_1 = param_1 - *(int *)(iVar3 + -4);
    iVar3 = iVar3 - *(int *)(iVar3 + -2);
    iVar1 = *(int *)(iVar3 + -8);
    param_3[1] = *(int *)(iVar3 + -6);
    *param_3 = iVar1;
  }
  return param_1;
}

