// TIM2.EXE: FUN_31f7_3aab @ file 0x03AC1B Ghidra 0x35A1B
// Subsystem: misc | Size: 295 bytes


void __cdecl16far FUN_31f7_3aab(undefined4 param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  if (DAT_5b41_19ca == 0) {
    DAT_5b41_19ca = FUN_4551_0370(DAT_5b41_09ec,3);
    DAT_5b41_19cc = FUN_4551_0370(DAT_5b41_09ec,4);
    DAT_5b41_19ce = FUN_4551_0370(DAT_5b41_09ec,9);
    DAT_5b41_19d0 = FUN_4551_0370(DAT_5b41_09ec,5);
    DAT_5b41_19d2 = FUN_4551_0370(DAT_5b41_09ec,7);
    DAT_5b41_19d4 = FUN_4551_0370(DAT_5b41_09ec,8);
    DAT_5b41_19d6 = FUN_4551_0370(DAT_5b41_09ec,0xffff);
  }
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar2 = (uint)((*(byte *)(iVar3 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar3 + 0x98) = *(undefined2 *)(uVar2 * 2 + *(int *)(iRam00055800 + 0x46));
  if ((*(int *)(iVar3 + 0x10) < DAT_5b41_19cc) || (*(int *)(iVar3 + 0x10) == DAT_5b41_19d4)) {
    if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
      uVar1 = 0x62;
    }
    else {
      uVar1 = 3;
    }
    *(undefined1 *)(iVar3 + 0x7a) = uVar1;
    *(undefined1 *)(iVar3 + 0x7b) = 0x42;
  }
  else {
    if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
      uVar1 = 0x5c;
    }
    else {
      uVar1 = 9;
    }
    *(undefined1 *)(iVar3 + 0x7a) = uVar1;
    *(undefined1 *)(iVar3 + 0x7b) = 0x47;
  }
  if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
    uVar1 = 0x22;
  }
  else {
    uVar1 = 0x47;
  }
  *(undefined1 *)(iVar3 + 0x5a) = uVar1;
  *(undefined1 *)(iVar3 + 0x5b) = 0x42;
  *(undefined2 *)(iVar3 + 0x5c) = 7;
  FUN_28eb_3670(iVar3,uVar4,uVar2);
  return;
}

