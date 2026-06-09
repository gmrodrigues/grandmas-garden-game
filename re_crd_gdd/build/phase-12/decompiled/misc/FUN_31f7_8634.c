// TIM2.EXE: FUN_31f7_8634 @ file 0x03F7A4 Ghidra 0x3A5A4
// Subsystem: misc | Size: 96 bytes


void __cdecl16far FUN_31f7_8634(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1a6c == 0) {
    DAT_5b41_1a6c = FUN_4551_0370(DAT_5b41_0a40,4);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 2;
  }
  if (*(int *)(iVar2 + 0x10) != 0) {
    iVar1 = iVar1 + 1;
  }
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(iVar1 * 2 + *(int *)(DAT_554c_0394 + 0x46));
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

