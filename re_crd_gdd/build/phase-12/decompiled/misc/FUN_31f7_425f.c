// TIM2.EXE: FUN_31f7_425f @ file 0x03B3CF Ghidra 0x361CF
// Subsystem: misc | Size: 111 bytes


void __cdecl16far FUN_31f7_425f(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar2 = DAT_5b41_19d8;
  if (DAT_5b41_19d8 == 0) {
    iVar2 = 2;
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 == 0) break;
      iVar1 = FUN_4551_0308(DAT_5b41_09f4,iVar2);
    } while (iVar1 == 0);
  }
  DAT_5b41_19d8 = iVar2;
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 2;
  }
  if (*(int *)(iVar2 + 0x10) == DAT_5b41_19d8) {
    iVar1 = iVar1 + 1;
  }
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(iVar1 * 2 + *(int *)(iRam00055808 + 0x46));
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

