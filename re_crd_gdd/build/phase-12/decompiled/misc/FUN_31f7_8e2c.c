// TIM2.EXE: FUN_31f7_8e2c @ file 0x03FF9C Ghidra 0x3AD9C
// Subsystem: misc | Size: 133 bytes


void __cdecl16far FUN_31f7_8e2c(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x82) = 0x11;
  *(undefined1 *)(iVar1 + 0x83) = 0x3b;
  *(undefined1 *)(iVar1 + 0x7a) = 0x11;
  *(undefined1 *)(iVar1 + 0x7b) = 0x52;
  *(undefined2 *)(iVar1 + 0x98) = *(undefined2 *)*(undefined2 *)(DAT_554c_03a0 + 0x46);
  FUN_28eb_3670(iVar1,uVar2);
  if (DAT_5b41_1a74 == 0) {
    DAT_5b41_1a74 = FUN_4551_0370(DAT_5b41_0a4c,4);
    DAT_5b41_1a76 = FUN_4551_0370(DAT_5b41_0a4c,2);
    DAT_5b41_1a78 = FUN_4551_0370(DAT_5b41_0a4c,3);
    DAT_5b41_1a7a = FUN_4551_0370(DAT_5b41_0a4c,0xffff);
  }
  return;
}

