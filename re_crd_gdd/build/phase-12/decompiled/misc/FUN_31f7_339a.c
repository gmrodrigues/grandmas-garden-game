// TIM2.EXE: FUN_31f7_339a @ file 0x03A50A Ghidra 0x3530A
// Subsystem: misc | Size: 85 bytes


void __cdecl16far FUN_31f7_339a(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *(undefined2 *)(iVar2 + 0xb4) = *(undefined2 *)(iVar2 + 0xae);
  FUN_31f7_3192(iVar2,uVar3);
  uVar1 = (uint)((*(byte *)(iVar2 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(iRam000557f8 + 0x46));
  FUN_28eb_3670(iVar2,uVar3,uVar1);
  return;
}

