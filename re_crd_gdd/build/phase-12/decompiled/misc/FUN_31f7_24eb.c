// TIM2.EXE: FUN_31f7_24eb @ file 0x03965B Ghidra 0x3445B
// Subsystem: misc | Size: 75 bytes


void __cdecl16far FUN_31f7_24eb(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = (uint)((*(byte *)(iVar2 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(iRam000557e8 + 0x46));
  *(undefined2 *)(iVar2 + 0x82) = ((undefined2 *)&DAT_554c_3ad0)[uVar1];
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

