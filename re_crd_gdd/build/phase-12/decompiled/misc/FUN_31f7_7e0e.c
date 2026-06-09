// TIM2.EXE: FUN_31f7_7e0e @ file 0x03EF7E Ghidra 0x39D7E
// Subsystem: misc | Size: 78 bytes


void __cdecl16far FUN_31f7_7e0e(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_09a1 == 0) {
    DAT_5b41_1a5c = FUN_4551_0370(DAT_5b41_0a34,2);
    iVar1 = FUN_4551_0370(DAT_5b41_0a34,0xffff);
    DAT_5b41_09a1 = iVar1 + -1;
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined2 *)((int)param_1 + 0x98) = *(undefined2 *)*(undefined2 *)(DAT_554c_0388 + 0x46);
  FUN_28eb_3670((int)param_1,uVar2);
  return;
}

