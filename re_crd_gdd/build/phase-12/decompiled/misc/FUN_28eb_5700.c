// TIM2.EXE: FUN_28eb_5700 @ file 0x0337B0 Ghidra 0x2E5B0
// Subsystem: misc | Size: 199 bytes


void __cdecl16far FUN_28eb_5700(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = (int)((ulong)param_1 >> 0x10);
  iVar6 = (int)param_1;
  if ((*(int *)(iVar6 + 8) == 0x11) || (*(int *)(iVar6 + 8) == 0x6c)) {
    iVar2 = *(int *)(iVar6 + 0x22) - *(int *)(iVar6 + 0x26);
    iVar3 = *(int *)(iVar6 + 0x24) - *(int *)(iVar6 + 0x28);
    if ((iVar2 != 0) || (iVar3 != 0)) {
      while( true ) {
        iVar1 = *(int *)(iVar6 + 0x8e);
        iVar6 = *(int *)(iVar6 + 0x8c);
        if (iVar6 == 0 && iVar1 == 0) break;
        *(int *)(iVar6 + 0x22) = *(int *)(iVar6 + 0x22) + iVar2;
        *(int *)(iVar6 + 0x24) = *(int *)(iVar6 + 0x24) + iVar3;
        FUN_28eb_3328(iVar6,iVar1);
        iVar7 = *(int *)(iVar6 + 0x22);
        *(int *)(iVar6 + 0x1c) = iVar7 >> 0xf;
        *(int *)(iVar6 + 0x1a) = iVar7;
        uVar5 = *(undefined2 *)(iVar6 + 0x1c);
        uVar4 = FUN_1000_199e();
        *(undefined2 *)(iVar6 + 0x1c) = uVar5;
        *(undefined2 *)(iVar6 + 0x1a) = uVar4;
        iVar7 = *(int *)(iVar6 + 0x24);
        *(int *)(iVar6 + 0x20) = iVar7 >> 0xf;
        *(int *)(iVar6 + 0x1e) = iVar7;
        uVar5 = *(undefined2 *)(iVar6 + 0x20);
        uVar4 = FUN_1000_199e();
        *(undefined2 *)(iVar6 + 0x20) = uVar5;
        *(undefined2 *)(iVar6 + 0x1e) = uVar4;
        iVar7 = iVar1;
      }
    }
  }
  return;
}

