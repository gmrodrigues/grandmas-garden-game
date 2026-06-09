// TIM2.EXE: FUN_31f7_352a @ file 0x03A69A Ghidra 0x3549A
// Subsystem: misc | Size: 74 bytes


void __cdecl16far FUN_31f7_352a(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x16) != 0) {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_09e8,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 == -1) {
      *(undefined2 *)(iVar2 + 0x10) = DAT_5b41_19c8;
    }
    FUN_31f7_34cb(iVar2,uVar3);
    FUN_28eb_3328(iVar2,uVar3);
  }
  return;
}

