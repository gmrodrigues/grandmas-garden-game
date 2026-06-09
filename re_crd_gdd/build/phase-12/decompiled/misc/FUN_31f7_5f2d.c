// TIM2.EXE: FUN_31f7_5f2d @ file 0x03D09D Ghidra 0x37E9D
// Subsystem: misc | Size: 112 bytes


void __cdecl16far FUN_31f7_5f2d(undefined4 param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  if (DAT_5b41_1a14 == 0) {
    DAT_5b41_1a14 = FUN_4551_0370(DAT_5b41_0a08,2);
  }
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
    uVar1 = 0x30;
  }
  else {
    uVar1 = 4;
  }
  *(undefined1 *)(iVar3 + 0x82) = uVar1;
  *(undefined1 *)(iVar3 + 0x83) = 3;
  uVar2 = (uint)((*(byte *)(iVar3 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar3 + 0x98) = *(undefined2 *)(uVar2 * 2 + *(int *)(iRam0005581c + 0x46));
  FUN_28eb_3670(iVar3,uVar4,uVar2);
  return;
}

