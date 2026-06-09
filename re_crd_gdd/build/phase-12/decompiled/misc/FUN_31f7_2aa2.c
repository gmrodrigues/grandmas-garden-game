// TIM2.EXE: FUN_31f7_2aa2 @ file 0x039C12 Ghidra 0x34A12
// Subsystem: misc | Size: 112 bytes


void __cdecl16far FUN_31f7_2aa2(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x16) != 0) {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_09da,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 == -1) {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
      if (*(int *)(iVar2 + 0x16) != 2) {
        *(undefined2 *)(iVar2 + 0x16) = 2;
        *(undefined2 *)(*(int *)(iVar2 + 0x62) + 0x16) = 1;
        return;
      }
    }
    else {
      FUN_31f7_2a43(iVar2,uVar3);
      FUN_28eb_3328(iVar2,uVar3);
    }
  }
  return;
}

