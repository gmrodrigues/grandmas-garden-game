// TIM2.EXE: FUN_28eb_1d98 @ file 0x02FE48 Ghidra 0x2AC48
// Subsystem: misc | Size: 170 bytes


void __cdecl16far FUN_28eb_1d98(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  iVar1 = *(int *)(iVar5 + 0x60);
  iVar2 = *(int *)(iVar5 + 0x5e);
  iVar3 = *(int *)(iVar5 + 100);
  iVar4 = *(int *)(iVar5 + 0x62);
  if (*(int *)(iVar5 + 8) == 7) {
    FUN_28eb_1e42(iVar5,uVar6);
  }
  if ((iVar2 != 0 || iVar1 != 0) && (*(int *)(iVar2 + 8) == 7)) {
    FUN_28eb_1e42(iVar2,iVar1);
    FUN_2424_0f94(iVar2,iVar1,3);
    FUN_28eb_2d82(iVar2,iVar1,2);
  }
  if ((iVar4 != 0 || iVar3 != 0) && (*(int *)(iVar4 + 8) == 7)) {
    FUN_28eb_1e42(iVar4,iVar3);
    FUN_2424_0f94(iVar4,iVar3,3);
    FUN_28eb_2d82(iVar4,iVar3,2);
  }
  return;
}

