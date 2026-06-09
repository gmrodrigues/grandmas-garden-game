// TIM2.EXE: FUN_28eb_08be @ file 0x02E96E Ghidra 0x2976E
// Subsystem: misc | Size: 376 bytes


void __cdecl16far FUN_28eb_08be(undefined2 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  
  uVar10 = (undefined2)((ulong)*(undefined4 *)(param_1 + 2) >> 0x10);
  iVar9 = (int)*(undefined4 *)(param_1 + 2) + (uint)*(byte *)(param_1 + 10) * 4;
  iVar8 = *(int *)(iVar9 + 0x5e);
  iVar9 = *(int *)(iVar9 + 0x60);
  while( true ) {
    if ((iVar8 == 0 && iVar9 == 0) || (*(int *)(iVar8 + 8) != 7)) break;
    uVar10 = *(undefined2 *)(iVar8 + 0x60);
    uVar3 = *(undefined2 *)(iVar8 + 0x5e);
    uVar4 = *(undefined2 *)(iVar8 + 0x62);
    *(undefined2 *)(iVar8 + 0x60) = *(undefined2 *)(iVar8 + 100);
    *(undefined2 *)(iVar8 + 0x5e) = uVar4;
    *(undefined2 *)(iVar8 + 100) = uVar10;
    *(undefined2 *)(iVar8 + 0x62) = uVar3;
    uVar10 = *(undefined2 *)(iVar8 + 0x5e);
    *(undefined2 *)(iVar8 + 0x68) = *(undefined2 *)(iVar8 + 0x60);
    *(undefined2 *)(iVar8 + 0x66) = uVar10;
    iVar5 = *(int *)(iVar8 + 100);
    uVar10 = *(undefined2 *)(iVar8 + 0x62);
    *(int *)(iVar8 + 0x6c) = iVar5;
    *(undefined2 *)(iVar8 + 0x6a) = uVar10;
    uVar10 = *(undefined2 *)(iVar8 + 0x7a);
    *(undefined2 *)(iVar8 + 0x7a) = *(undefined2 *)(iVar8 + 0x7c);
    *(undefined2 *)(iVar8 + 0x7c) = uVar10;
    iVar6 = *(int *)(iVar8 + 0x76);
    uVar10 = *(undefined2 *)(iVar6 + 0x1e);
    *(undefined2 *)(iVar6 + 0x1e) = *(undefined2 *)(iVar6 + 0x22);
    *(undefined2 *)(iVar6 + 0x22) = uVar10;
    uVar10 = *(undefined2 *)(iVar6 + 0x20);
    *(undefined2 *)(iVar6 + 0x20) = *(undefined2 *)(iVar6 + 0x24);
    *(undefined2 *)(iVar6 + 0x24) = uVar10;
    uVar10 = *(undefined2 *)(iVar6 + 0x26);
    *(undefined2 *)(iVar6 + 0x26) = *(undefined2 *)(iVar6 + 0x2a);
    *(undefined2 *)(iVar6 + 0x2a) = uVar10;
    uVar10 = *(undefined2 *)(iVar6 + 0x28);
    *(undefined2 *)(iVar6 + 0x28) = *(undefined2 *)(iVar6 + 0x2c);
    *(undefined2 *)(iVar6 + 0x2c) = uVar10;
    uVar10 = *(undefined2 *)(iVar6 + 0x2e);
    *(undefined2 *)(iVar6 + 0x2e) = *(undefined2 *)(iVar6 + 0x32);
    *(undefined2 *)(iVar6 + 0x32) = uVar10;
    uVar10 = *(undefined2 *)(iVar6 + 0x30);
    *(undefined2 *)(iVar6 + 0x30) = *(undefined2 *)(iVar6 + 0x34);
    *(undefined2 *)(iVar6 + 0x34) = uVar10;
    iVar8 = *(int *)(iVar8 + 0x62);
    iVar9 = iVar5;
  }
  uVar10 = param_1[3];
  uVar3 = param_1[2];
  uVar4 = param_1[5];
  uVar7 = param_1[4];
  param_1[3] = uVar4;
  param_1[2] = uVar7;
  param_1[7] = uVar4;
  param_1[6] = uVar7;
  param_1[5] = uVar10;
  param_1[4] = uVar3;
  param_1[9] = uVar10;
  param_1[8] = uVar3;
  uVar1 = *(undefined1 *)(param_1 + 10);
  uVar2 = *(undefined1 *)((int)param_1 + 0x15);
  *(undefined1 *)(param_1 + 10) = uVar2;
  *(undefined1 *)(param_1 + 0xb) = uVar2;
  *(undefined1 *)((int)param_1 + 0x15) = uVar1;
  *(undefined1 *)((int)param_1 + 0x17) = uVar1;
  FUN_2424_0f94(*param_1,param_1[1],3);
  return;
}

