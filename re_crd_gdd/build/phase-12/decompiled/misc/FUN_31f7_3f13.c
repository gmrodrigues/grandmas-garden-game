// TIM2.EXE: FUN_31f7_3f13 @ file 0x03B083 Ghidra 0x35E83
// Subsystem: misc | Size: 61 bytes


void __cdecl16far FUN_31f7_3f13(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = (uint)((*(byte *)(iVar2 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(iRam00055804 + 0x46));
  FUN_28eb_3670(iVar2,uVar3,uVar1);
  return;
}

