// TIM2.EXE: FUN_3e34_013c @ file 0x04367C Ghidra 0x3E47C
// Subsystem: sound | Size: 36 bytes


int __cdecl16far FUN_3e34_013c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined2 uVar4;
  
  iVar2 = 0;
  if ((int *)param_1 != (int *)0x0 || param_1._2_2_ != 0) {
    while (piVar1 = param_1, uVar4 = (undefined2)((ulong)param_1 >> 0x10), piVar3 = (int *)param_1,
          param_1 = (int *)CONCAT22(uVar4,piVar3 + 2), *piVar1 != 0 || piVar3[1] != 0) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

