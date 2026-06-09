// TIM2.EXE: FUN_31f7_891e @ file 0x03FA8E Ghidra 0x3A88E
// Subsystem: misc | Size: 121 bytes


void __cdecl16far FUN_31f7_891e(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  if (DAT_5b41_1a6e == 0) {
    DAT_5b41_1a6e = FUN_4551_0370(DAT_5b41_0a44,3);
    DAT_5b41_09a5 = FUN_4551_0370(DAT_5b41_0a44,2);
    DAT_5b41_1a70 = FUN_4551_0370(DAT_5b41_0a44,0xffff);
  }
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = *(int *)(iVar3 + 0x10) >> 1;
  if (4 < iVar2) {
    iVar2 = 4;
  }
  if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
    uVar1 = *(undefined1 *)(iVar2 + 0x3c54);
  }
  else {
    uVar1 = *(undefined1 *)(iVar2 + 0x3c59);
  }
  *(undefined1 *)(iVar3 + 0x7a) = uVar1;
  *(undefined1 *)(iVar3 + 0x7b) = 7;
  return;
}

