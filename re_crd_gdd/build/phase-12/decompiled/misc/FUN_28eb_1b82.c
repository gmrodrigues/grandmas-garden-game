// TIM2.EXE: FUN_28eb_1b82 @ file 0x02FC32 Ghidra 0x2AA32
// Subsystem: misc | Size: 134 bytes


undefined2 __cdecl16far FUN_28eb_1b82(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  
  uVar9 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  uVar10 = (undefined2)((ulong)param_2 >> 0x10);
  iVar8 = (int)param_2;
  iVar6 = *(int *)(iVar7 + 0x24);
  bVar1 = *(byte *)(iVar7 + 0x5b);
  iVar3 = *(int *)(iVar8 + 0x24);
  bVar2 = *(byte *)(iVar8 + 0x5b);
  iVar7 = (int)((*(int *)(iVar7 + 0x22) + (uint)*(byte *)(iVar7 + 0x5a)) -
               (*(int *)(iVar8 + 0x22) + (uint)*(byte *)(iVar8 + 0x5a))) >> 0xf;
  uVar4 = FUN_1000_180a();
  iVar6 = (int)((iVar6 + (uint)bVar1) - (iVar3 + (uint)bVar2)) >> 0xf;
  uVar5 = FUN_1000_180a();
  iVar6 = iVar7 + iVar6 + (uint)CARRY2(uVar4,uVar5);
  if ((iVar6 < 1) && ((iVar6 < 0 || (uVar4 + uVar5 < 0x4c90)))) {
    uVar9 = 1;
  }
  else {
    uVar9 = 0;
  }
  return uVar9;
}

