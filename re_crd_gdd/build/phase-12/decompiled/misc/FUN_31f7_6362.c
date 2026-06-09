// TIM2.EXE: FUN_31f7_6362 @ file 0x03D4D2 Ghidra 0x382D2
// Subsystem: misc | Size: 61 bytes


void __cdecl16far FUN_31f7_6362(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = (uint)((*(byte *)(iVar2 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(iRam00055828 + 0x46));
  FUN_28eb_3670(iVar2,uVar3,uVar1);
  return;
}

