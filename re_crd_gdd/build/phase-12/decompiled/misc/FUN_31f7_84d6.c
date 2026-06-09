// TIM2.EXE: FUN_31f7_84d6 @ file 0x03F646 Ghidra 0x3A446
// Subsystem: misc | Size: 45 bytes


void __cdecl16far FUN_31f7_84d6(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) != DAT_5b41_1a6a) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    FUN_28eb_3328(iVar1,uVar2);
    FUN_31f7_8503(iVar1,uVar2);
  }
  return;
}

