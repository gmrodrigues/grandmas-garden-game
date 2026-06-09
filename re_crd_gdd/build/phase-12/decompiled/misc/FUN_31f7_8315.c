// TIM2.EXE: FUN_31f7_8315 @ file 0x03F485 Ghidra 0x3A285
// Subsystem: misc | Size: 284 bytes


void __cdecl16far FUN_31f7_8315(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  
  uVar9 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  iVar4 = (uint)(DAT_5b41_0989 <= *(int *)(iVar7 + 0xa8)) +
          (uint)(DAT_5b41_098b <= *(int *)(iVar7 + 0xa8));
  iVar8 = 0;
  iVar5 = iVar4;
  while ((iVar8 < 4 && (iVar1 = FUN_2321_0f22(0x29), iVar1 != 0 || iVar5 != 0))) {
    FUN_28eb_2a59(iVar1,iVar5,(undefined2 *)&DAT_5b41_054f,0);
    *(uint *)(iVar1 + 10) = *(uint *)(iVar1 + 10) | 0x10;
    *(int *)(iVar1 + 0x22) = *(int *)(iVar8 * 6 + iVar4 * 2 + 0x3c10) + *(int *)(iVar7 + 0x22);
    *(int *)(iVar1 + 0x24) = *(int *)(iVar8 * 6 + iVar4 * 2 + 0x3c28) + *(int *)(iVar7 + 0x24);
    iVar6 = *(int *)(iVar1 + 0x22);
    *(int *)(iVar1 + 0x1c) = iVar6 >> 0xf;
    *(int *)(iVar1 + 0x1a) = iVar6;
    uVar3 = *(undefined2 *)(iVar1 + 0x1c);
    uVar2 = FUN_1000_199e();
    *(undefined2 *)(iVar1 + 0x1c) = uVar3;
    *(undefined2 *)(iVar1 + 0x1a) = uVar2;
    iVar6 = *(int *)(iVar1 + 0x24);
    *(int *)(iVar1 + 0x20) = iVar6 >> 0xf;
    *(int *)(iVar1 + 0x1e) = iVar6;
    iVar6 = *(int *)(iVar1 + 0x20);
    uVar3 = FUN_1000_199e();
    *(int *)(iVar1 + 0x20) = iVar6;
    *(undefined2 *)(iVar1 + 0x1e) = uVar3;
    FUN_28eb_3328(iVar1,iVar5);
    iVar8 = iVar8 + 1;
    iVar5 = iVar6;
  }
  *(undefined2 *)(iVar7 + 0x10) = ((undefined2 *)&DAT_5b41_1a64)[iVar4];
  return;
}

