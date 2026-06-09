// TIM2.EXE: FUN_31f7_8cef @ file 0x03FE5F Ghidra 0x3AC5F
// Subsystem: misc | Size: 102 bytes


void __cdecl16far FUN_31f7_8cef(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_09a7 == 0) {
    DAT_5b41_09a7 = FUN_4551_0370(DAT_5b41_0a4a,7);
    DAT_5b41_1a72 = FUN_4551_0370(DAT_5b41_0a4a,0xffff);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = (uint)(*(int *)(iVar2 + 0x10) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(DAT_554c_039e + 0x46));
  FUN_28eb_3670(iVar2,uVar3,uVar1);
  return;
}

