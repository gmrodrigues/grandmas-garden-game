// TIM2.EXE: FUN_28eb_2440 @ file 0x0304F0 Ghidra 0x2B2F0
// Subsystem: misc | Size: 272 bytes


void __cdecl16far FUN_28eb_2440(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(byte *)(iVar3 + 0xe) & 2) == 0) {
    iVar6 = *(int *)(iVar3 + 0x70);
    iVar1 = *(int *)(iVar3 + 0x6e);
    if (iVar1 != 0 || iVar6 != 0) {
      iVar5 = iVar1 + (uint)*(byte *)(iVar3 + 0x94) * 4;
      *(undefined2 *)(iVar5 + 0x70) = 0;
      *(undefined2 *)(iVar5 + 0x6e) = 0;
      *(undefined2 *)(iVar3 + 0x70) = 0;
      *(undefined2 *)(iVar3 + 0x6e) = 0;
      puVar2 = (undefined2 *)(*(int *)(*(int *)(iVar3 + 8) * 2 + 0x302) + 8);
      (*(code *)*puVar2)(0x28eb,iVar3,uVar7);
      puVar2 = (undefined2 *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 8);
      (*(code *)*puVar2)(0x28eb,iVar1,iVar6);
      *(undefined2 *)(iVar1 + 0xa8) = *(undefined2 *)(iVar1 + 0x10);
      FUN_2424_0f94(iVar1,iVar6,3);
    }
  }
  else {
    for (iVar6 = 4; iVar6 < 6; iVar6 = iVar6 + 1) {
      iVar4 = iVar3 + iVar6 * 4;
      iVar1 = *(int *)(iVar4 + 0x60);
      iVar5 = *(int *)(iVar4 + 0x5e);
      if (iVar5 != 0 || iVar1 != 0) {
        *(undefined2 *)(iVar4 + 0x60) = 0;
        *(undefined2 *)(iVar4 + 0x5e) = 0;
        *(undefined2 *)(iVar5 + 0x70) = 0;
        *(undefined2 *)(iVar5 + 0x6e) = 0;
        puVar2 = (undefined2 *)(*(int *)(*(int *)(iVar5 + 8) * 2 + 0x302) + 8);
        (*(code *)*puVar2)(0x28eb,iVar5,iVar1);
      }
    }
    puVar2 = (undefined2 *)(*(int *)(*(int *)(iVar3 + 8) * 2 + 0x302) + 8);
    (*(code *)*puVar2)(0x28eb,iVar3,uVar7);
    *(undefined2 *)(iVar3 + 0xa8) = *(undefined2 *)(iVar3 + 0x10);
  }
  return;
}

