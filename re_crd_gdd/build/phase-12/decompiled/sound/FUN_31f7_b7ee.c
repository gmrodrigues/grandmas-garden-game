// TIM2.EXE: FUN_31f7_b7ee @ file 0x04295E Ghidra 0x3D75E
// Subsystem: sound | Size: 117 bytes


void __cdecl16far FUN_31f7_b7ee(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_1ac2 == 0) {
    DAT_5b41_1ac2 = FUN_4551_0370(DAT_5b41_0ad6,3);
    DAT_5b41_1ac4 = FUN_4551_0370(DAT_5b41_0ad6,4);
    DAT_5b41_1ac6 = FUN_4551_0370(DAT_5b41_0ad6,5);
    DAT_5b41_1ac8 = FUN_4551_0370(DAT_5b41_0ad6,0xffff);
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x16) = 0;
  *(undefined2 *)(iVar1 + 0x98) = *(undefined2 *)*(undefined2 *)(DAT_554c_042a + 0x46);
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

