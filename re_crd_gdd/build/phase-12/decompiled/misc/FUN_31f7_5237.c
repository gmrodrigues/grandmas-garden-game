// TIM2.EXE: FUN_31f7_5237 @ file 0x03C3A7 Ghidra 0x371A7
// Subsystem: misc | Size: 185 bytes


undefined2 __cdecl16far FUN_31f7_5237(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar7 + 0x9c);
  iVar2 = *(int *)(iVar7 + 0x9a);
  if ((*(int *)(iVar7 + 0xa2) == 0) && ((*(byte *)(iVar7 + 0xd) & 0x10) == 0)) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
    *(undefined2 *)(iVar2 + 0x10) = 0;
    *(undefined2 *)(iVar7 + 0x9c) = 0;
    *(undefined2 *)(iVar7 + 0x9a) = 0;
    *(uint *)(iVar7 + 10) = *(uint *)(iVar7 + 10) & 0xfffe;
    iVar3 = *(int *)(iVar7 + 0x24);
    *(int *)(iVar7 + 0x20) = iVar3 >> 0xf;
    *(int *)(iVar7 + 0x1e) = iVar3;
    uVar5 = *(undefined2 *)(iVar7 + 0x20);
    uVar4 = FUN_1000_199e();
    *(undefined2 *)(iVar7 + 0x20) = uVar5;
    *(undefined2 *)(iVar7 + 0x1e) = uVar4;
    if (*(int *)(iVar2 + 0x10) < 4) {
      uVar6 = (int)*(uint *)(iVar7 + 0x3c) >> 0xf;
      *(int *)(iVar7 + 0x3c) = -((*(uint *)(iVar7 + 0x3c) ^ uVar6) - uVar6);
      *(int *)(iVar7 + 0x3c) = *(int *)(iVar7 + 0x3c) + -0x800;
      FUN_549b_007a(0x1000,iVar7,uVar8);
    }
    return 0;
  }
  return 1;
}

