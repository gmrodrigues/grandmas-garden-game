// TIM2.EXE: FUN_28eb_4789 @ file 0x032839 Ghidra 0x2D639
// Subsystem: misc | Size: 106 bytes


void __cdecl16far FUN_28eb_4789(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar4 = iVar3;
  iVar6 = iVar5;
  while( true ) {
    iVar1 = *(int *)(iVar4 + 0x8e);
    iVar4 = *(int *)(iVar4 + 0x8c);
    if (iVar4 == 0 && iVar1 == 0) break;
    uVar2 = FUN_28eb_47f3(*(undefined2 *)(iVar3 + 0x3e),*(undefined2 *)(iVar4 + 0x3e));
    *(undefined2 *)(iVar3 + 0x3e) = uVar2;
    iVar6 = iVar1;
  }
  if (*(int *)(iVar3 + 8) == 0x6c) {
    uVar2 = FUN_28eb_47f3(*(undefined2 *)(iVar3 + 0x3e),*(int *)(iVar3 + 0xb4) >> 1);
    *(undefined2 *)(iVar3 + 0x3e) = uVar2;
  }
  return;
}

