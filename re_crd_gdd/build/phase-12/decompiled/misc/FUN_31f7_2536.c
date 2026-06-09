// TIM2.EXE: FUN_31f7_2536 @ file 0x0396A6 Ghidra 0x344A6
// Subsystem: misc | Size: 95 bytes


void __cdecl16far FUN_31f7_2536(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(int *)(iVar2 + 0x16) == 0) && (0x14 < *(int *)(iVar2 + 0xb4))) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
  }
  if (*(int *)(iVar2 + 0x16) != 0) {
    iVar1 = FUN_4551_0308(DAT_5b41_09d4,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 == -1) {
      FUN_31f7_25cf(iVar2,uVar3);
      return;
    }
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    FUN_28eb_3328(iVar2,uVar3);
  }
  return;
}

