// TIM2.EXE: FUN_31f7_a534 @ file 0x0416A4 Ghidra 0x3C4A4
// Subsystem: sound | Size: 170 bytes


void __cdecl16far FUN_31f7_a534(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1aae == 0) {
    DAT_5b41_1aae = FUN_4551_0370(DAT_5b41_0a88,3);
    DAT_5b41_1ab0 = FUN_4551_0370(DAT_5b41_0a88,4);
    DAT_5b41_1ab2 = FUN_4551_0370(DAT_5b41_0a88,2);
    DAT_5b41_09a9 = FUN_4551_0370(DAT_5b41_0a88,5);
    DAT_5b41_1ab4 = FUN_4551_0370(DAT_5b41_0a88,6);
    DAT_5b41_1ab6 = FUN_4551_0370(DAT_5b41_0a88,0xffff);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = (uint)((*(byte *)(iVar2 + 0xc) & 0x10) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(DAT_554c_03dc + 0x46));
  FUN_28eb_3670(iVar2,uVar3,uVar1);
  return;
}

