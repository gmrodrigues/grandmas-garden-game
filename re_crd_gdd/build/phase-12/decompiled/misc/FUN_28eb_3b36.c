// TIM2.EXE: FUN_28eb_3b36 @ file 0x031BE6 Ghidra 0x2C9E6
// Subsystem: misc | Size: 217 bytes


int __cdecl16far FUN_28eb_3b36(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar4 = iVar3;
  if (*(int *)(iVar3 + 8) != 7) {
    iVar4 = iVar3 + (uint)*(byte *)(param_2 + 10) * 4;
  }
  iVar1 = param_2[1];
  iVar2 = *param_2;
  if ((param_2[3] == iVar5) && (param_2[2] == iVar3)) {
    if (param_3 == 1) {
      iVar4 = *(int *)(iVar2 + 0xb2);
    }
    else if (param_3 == 2) {
      iVar4 = *(int *)(iVar2 + 0xb0);
    }
    else {
      iVar4 = *(int *)(iVar2 + 0xae);
    }
    uVar6 = 0;
  }
  else {
    if ((*(int *)(iVar4 + 0x5e) == 0 && *(int *)(iVar4 + 0x60) == 0) ||
       ((param_2[5] != *(int *)(iVar4 + 0x60) || (param_2[4] != *(int *)(iVar4 + 0x5e))))) {
      return 0;
    }
    if (param_3 == 1) {
      iVar4 = *(int *)(iVar2 + 0xb8);
    }
    else if (param_3 == 2) {
      iVar4 = *(int *)(iVar2 + 0xb6);
    }
    else {
      iVar4 = *(int *)(iVar2 + 0xb4);
    }
    uVar6 = 1;
  }
  iVar3 = FUN_28eb_399d(param_2,param_3,uVar6);
  return iVar4 - iVar3;
}

