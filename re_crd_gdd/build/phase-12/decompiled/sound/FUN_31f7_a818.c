// TIM2.EXE: FUN_31f7_a818 @ file 0x041988 Ghidra 0x3C788
// Subsystem: sound | Size: 189 bytes


void __cdecl16far FUN_31f7_a818(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int in_DX;
  undefined2 uVar4;
  int iVar5;
  undefined2 uVar6;
  
  iVar2 = FUN_2321_0ff6(0x29);
  iVar5 = (int)param_1;
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  if (iVar2 != 0 || in_DX != 0) {
    FUN_28eb_2a59(iVar2,in_DX,(undefined2 *)&DAT_5b41_054f,0);
    *(uint *)(iVar2 + 10) = *(uint *)(iVar2 + 10) | 0x10;
    *(int *)(iVar2 + 0x22) = *(int *)(iVar5 + 0x22) + -10;
    *(int *)(iVar2 + 0x24) = *(int *)(iVar5 + 0x24) + -0xc;
    iVar1 = *(int *)(iVar2 + 0x22);
    *(int *)(iVar2 + 0x1c) = iVar1 >> 0xf;
    *(int *)(iVar2 + 0x1a) = iVar1;
    uVar4 = *(undefined2 *)(iVar2 + 0x1c);
    uVar3 = FUN_1000_199e();
    *(undefined2 *)(iVar2 + 0x1c) = uVar4;
    *(undefined2 *)(iVar2 + 0x1a) = uVar3;
    iVar1 = *(int *)(iVar2 + 0x24);
    *(int *)(iVar2 + 0x20) = iVar1 >> 0xf;
    *(int *)(iVar2 + 0x1e) = iVar1;
    uVar4 = *(undefined2 *)(iVar2 + 0x20);
    uVar3 = FUN_1000_199e();
    *(undefined2 *)(iVar2 + 0x20) = uVar4;
    *(undefined2 *)(iVar2 + 0x1e) = uVar3;
    FUN_28eb_3328(iVar2,in_DX);
  }
  *(undefined2 *)(iVar5 + 0x10) = DAT_5b41_09a9;
  return;
}

