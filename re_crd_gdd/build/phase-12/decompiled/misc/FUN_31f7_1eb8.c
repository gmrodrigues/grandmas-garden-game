// TIM2.EXE: FUN_31f7_1eb8 @ file 0x039028 Ghidra 0x33E28
// Subsystem: misc | Size: 68 bytes


void __cdecl16far FUN_31f7_1eb8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 3;
  }
  iVar1 = iVar1 + *(int *)(iVar2 + 0x10);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(iVar1 * 2 + *(int *)(iRam000557e2 + 0x46));
  FUN_28eb_3670(iVar2,uVar3,iVar1);
  return;
}

