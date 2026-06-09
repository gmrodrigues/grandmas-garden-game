// TIM2.EXE: FUN_31f7_4087 @ file 0x03B1F7 Ghidra 0x35FF7
// Subsystem: misc | Size: 60 bytes


void __cdecl16far FUN_31f7_4087(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x16) == 0) {
    *(undefined2 *)(iVar2 + 0x10) = 0;
  }
  else {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_09f2,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 == -1) {
      *(undefined2 *)(iVar2 + 0x10) = 1;
      return;
    }
  }
  return;
}

