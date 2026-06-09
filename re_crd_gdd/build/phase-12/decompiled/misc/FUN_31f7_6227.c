// TIM2.EXE: FUN_31f7_6227 @ file 0x03D397 Ghidra 0x38197
// Subsystem: misc | Size: 128 bytes


void __cdecl16far FUN_31f7_6227(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = DAT_5b41_1a16;
  if (DAT_5b41_1a16 == 0) {
    iVar3 = 2;
    do {
      iVar3 = iVar3 + 1;
      if (iVar3 == 0) break;
      iVar2 = FUN_4551_0308(DAT_5b41_0a12,iVar3);
    } while (iVar2 == 0);
  }
  DAT_5b41_1a16 = iVar3;
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  *(undefined2 *)(iVar3 + 0x98) =
       *(undefined2 *)
        ((uint)((*(byte *)(iVar3 + 0xc) & 0x10) != 0) * 2 + *(int *)(iRam00055826 + 0x46));
  if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
    uVar1 = 9;
  }
  else {
    uVar1 = 0x38;
  }
  *(undefined1 *)(iVar3 + 0x5a) = uVar1;
  *(undefined1 *)(iVar3 + 0x5b) = 0x1d;
  *(undefined2 *)(iVar3 + 0x5c) = 8;
  FUN_28eb_3670(iVar3,uVar4);
  return;
}

