// TIM2.EXE: FUN_31f7_706a @ file 0x03E1DA Ghidra 0x38FDA
// Subsystem: misc | Size: 244 bytes


void __cdecl16far FUN_31f7_706a(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int in_DX;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  while( true ) {
    iVar4 = (int)param_1;
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    if ((1 < iVar5) || (iVar1 = FUN_2321_0f22(0x29), iVar1 == 0 && in_DX == 0)) break;
    FUN_28eb_2a59(iVar1,in_DX,(undefined2 *)&DAT_5b41_054f,0);
    *(uint *)(iVar1 + 10) = *(uint *)(iVar1 + 10) | 0x10;
    *(undefined2 *)(iVar1 + 0x22) = *(undefined2 *)(iVar4 + 0x22);
    *(int *)(iVar1 + 0x24) = *(int *)(iVar4 + 0x24) - ((undefined2 *)&DAT_554c_3ba6)[iVar5];
    iVar4 = *(int *)(iVar1 + 0x22);
    *(int *)(iVar1 + 0x1c) = iVar4 >> 0xf;
    *(int *)(iVar1 + 0x1a) = iVar4;
    uVar3 = *(undefined2 *)(iVar1 + 0x1c);
    uVar2 = FUN_1000_199e();
    *(undefined2 *)(iVar1 + 0x1c) = uVar3;
    *(undefined2 *)(iVar1 + 0x1a) = uVar2;
    iVar4 = *(int *)(iVar1 + 0x24);
    *(int *)(iVar1 + 0x20) = iVar4 >> 0xf;
    *(int *)(iVar1 + 0x1e) = iVar4;
    iVar4 = *(int *)(iVar1 + 0x20);
    uVar3 = FUN_1000_199e();
    *(int *)(iVar1 + 0x20) = iVar4;
    *(undefined2 *)(iVar1 + 0x1e) = uVar3;
    FUN_28eb_3328(iVar1,in_DX);
    iVar5 = iVar5 + 1;
    in_DX = iVar4;
  }
  FUN_2424_0f94(iVar4,uVar3,3);
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 0x2000;
  iVar5 = FUN_4551_0370(DAT_5b41_0a1c,0xffff);
  *(int *)(iVar4 + 0x10) = iVar5 + -1;
  return;
}

