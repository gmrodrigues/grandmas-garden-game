// TIM2.EXE: FUN_31f7_7862 @ file 0x03E9D2 Ghidra 0x397D2
// Subsystem: misc | Size: 119 bytes


void __cdecl16far FUN_31f7_7862(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1a56 == 0) {
    DAT_5b41_1a56 = FUN_4551_0370(DAT_5b41_0a2a,3);
    DAT_5b41_1a58 = FUN_4551_0370(DAT_5b41_0a2a,4);
    DAT_5b41_1a5a = FUN_4551_0370(DAT_5b41_0a2a,0xffff);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = (uint)((*(byte *)(iVar2 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(DAT_554c_037e + 0x46));
  FUN_28eb_3670(iVar2,uVar3,uVar1);
  return;
}

