// TIM2.EXE: FUN_31f7_3e8a @ file 0x03AFFA Ghidra 0x35DFA
// Subsystem: misc | Size: 137 bytes


void __cdecl16far FUN_31f7_3e8a(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 0x16) != 0) {
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_09ee,*(undefined2 *)(iVar3 + 0x10));
    if (iVar1 == -1) {
      *(undefined2 *)(iVar3 + 0x10) = 1;
    }
    *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) + -1;
    if (*(int *)(iVar3 + 0xae) < 1) {
      uVar2 = FUN_460e_1a42();
      *(int *)(iVar3 + 0xae) = uVar2 % 200 + 0x14;
      uVar2 = FUN_460e_1a42();
      *(int *)(iVar3 + 0x3a) = (uVar2 & 0x3ff) - 0x200;
      uVar2 = FUN_460e_1a42();
      *(int *)(iVar3 + 0x3c) = (uVar2 & 0x3ff) - 0x200;
    }
    FUN_31f7_3e34(iVar3,uVar4);
  }
  return;
}

