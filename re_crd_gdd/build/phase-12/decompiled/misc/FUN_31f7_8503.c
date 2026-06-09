// TIM2.EXE: FUN_31f7_8503 @ file 0x03F673 Ghidra 0x3A473
// Subsystem: misc | Size: 95 bytes


void __cdecl16far FUN_31f7_8503(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  iVar4 = DAT_5b41_1a6a;
  if (DAT_5b41_1a6a == 0) {
    iVar3 = 1;
    do {
      iVar4 = iVar3;
      iVar3 = iVar4 + 1;
      if (iVar3 == 0) break;
      iVar1 = FUN_4551_0308(DAT_5b41_0a3e,iVar3);
    } while (iVar1 == 0);
  }
  DAT_5b41_1a6a = iVar4;
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar4 = *(int *)(iVar3 + 0x10);
  if (4 < iVar4) {
    iVar4 = 4;
  }
  if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
    uVar2 = *(undefined2 *)(iVar4 * 2 + 0x3c40);
  }
  else {
    uVar2 = *(undefined2 *)(iVar4 * 2 + 0x3c4a);
  }
  *(undefined2 *)(iVar3 + 0x7a) = uVar2;
  return;
}

