// TIM2.EXE: FUN_2424_4007 @ file 0x02D447 Ghidra 0x28247
// Subsystem: misc | Size: 128 bytes


undefined2 __cdecl16far FUN_2424_4007(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  piVar5 = (int *)param_1;
  if (piVar5[2] < 1) {
    iVar2 = piVar5[2] + *param_1;
    iVar1 = *param_1;
  }
  else {
    iVar2 = *param_1;
    iVar1 = piVar5[2] + *param_1;
  }
  if (piVar5[3] < 1) {
    iVar4 = piVar5[1] + piVar5[3];
    iVar3 = piVar5[1];
  }
  else {
    iVar4 = piVar5[1];
    iVar3 = piVar5[1] + piVar5[3];
  }
  if ((((*(int *)(param_2 + 2) < iVar1) && (iVar2 <= *(int *)(param_2 + 6))) &&
      (*(int *)(param_2 + 4) < iVar3)) && (iVar4 <= *(int *)(param_2 + 8))) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

