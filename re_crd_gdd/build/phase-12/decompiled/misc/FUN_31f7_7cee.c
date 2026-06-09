// TIM2.EXE: FUN_31f7_7cee @ file 0x03EE5E Ghidra 0x39C5E
// Subsystem: misc | Size: 82 bytes


void __cdecl16far FUN_31f7_7cee(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x16) != 0) {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_0a30,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 == -1) {
      *(undefined2 *)(iVar2 + 0x10) = 0;
      *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + -1;
      if (*(int *)(iVar2 + 0xb4) == 0) {
        *(undefined2 *)(iVar2 + 0x16) = 0;
      }
    }
    FUN_28eb_3328(iVar2,uVar3);
  }
  return;
}

