// TIM2.EXE: FUN_31f7_7024 @ file 0x03E194 Ghidra 0x38F94
// Subsystem: misc | Size: 70 bytes


void __cdecl16far FUN_31f7_7024(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x16) != 0) {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_0a1c,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 == -1) {
      FUN_31f7_706a(iVar2,uVar3);
      return;
    }
    FUN_28eb_3328(iVar2,uVar3);
  }
  return;
}

