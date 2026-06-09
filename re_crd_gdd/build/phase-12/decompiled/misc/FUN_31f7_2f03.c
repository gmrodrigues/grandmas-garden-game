// TIM2.EXE: FUN_31f7_2f03 @ file 0x03A073 Ghidra 0x34E73
// Subsystem: misc | Size: 38 bytes


void __cdecl16far FUN_31f7_2f03(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(int *)(iVar1 + 0x16) != 0) && (*(int *)(iVar1 + 0x10) != 2)) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    FUN_28eb_3328(iVar1,uVar2);
  }
  return;
}

