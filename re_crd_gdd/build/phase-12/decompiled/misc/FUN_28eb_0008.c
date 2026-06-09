// TIM2.EXE: FUN_28eb_0008 @ file 0x02E0B8 Ghidra 0x28EB8
// Subsystem: misc | Size: 195 bytes


void __cdecl16far FUN_28eb_0008(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 8) == 0x4f) {
    iVar1 = *(int *)(iVar3 + 0x24) + 0x13;
  }
  else if (*(int *)(iVar3 + 8) == 0xb) {
    iVar1 = *(int *)(iVar3 + 0x24) + 0x10;
  }
  else {
    iVar1 = *(int *)(iVar3 + 0x24) + (*(int *)(iVar3 + 0x56) >> 1);
  }
  uVar6 = (undefined2)((ulong)param_2 >> 0x10);
  iVar4 = (int)param_2;
  if (*(int *)(iVar4 + 8) == 0x4f) {
    iVar2 = *(int *)(iVar4 + 0x24) + 0x13;
  }
  else if (*(int *)(iVar4 + 8) == 0xb) {
    iVar2 = *(int *)(iVar4 + 0x24) + 0x10;
  }
  else {
    iVar2 = *(int *)(iVar4 + 0x24) + (*(int *)(iVar4 + 0x56) >> 1);
  }
  iVar3 = (*(int *)(iVar3 + 0x22) + (*(int *)(iVar3 + 0x54) >> 1)) -
          (*(int *)(iVar4 + 0x22) + (*(int *)(iVar4 + 0x54) >> 1));
  FUN_2e67_1277(iVar3,iVar3 >> 0xf,iVar2 - iVar1,iVar2 - iVar1 >> 0xf);
  return;
}

