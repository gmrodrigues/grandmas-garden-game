// TIM2.EXE: FUN_28eb_2a23 @ file 0x030AD3 Ghidra 0x2B8D3
// Subsystem: misc | Size: 54 bytes


void __cdecl16far FUN_28eb_2a23(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  piVar3 = (int *)param_1;
  iVar1 = *param_1;
  piVar2 = *(int **)(piVar3 + 2);
  ((int *)piVar2)[1] = piVar3[1];
  *piVar2 = iVar1;
  if (iVar1 != 0 || piVar3[1] != 0) {
    iVar1 = piVar3[2];
    uVar6 = (undefined2)((ulong)*(undefined4 *)param_1 >> 0x10);
    iVar4 = (int)*(undefined4 *)param_1;
    *(int *)(iVar4 + 6) = piVar3[3];
    *(int *)(iVar4 + 4) = iVar1;
  }
  return;
}

