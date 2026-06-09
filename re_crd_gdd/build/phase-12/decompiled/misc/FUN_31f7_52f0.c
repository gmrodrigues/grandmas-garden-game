// TIM2.EXE: FUN_31f7_52f0 @ file 0x03C460 Ghidra 0x37260
// Subsystem: misc | Size: 60 bytes


void __cdecl16far FUN_31f7_52f0(undefined4 param_1)

{
  undefined2 uVar1;
  
  if (DAT_5b41_19fc == 0) {
    DAT_5b41_19fc = FUN_4551_0370(DAT_5b41_09fc,4);
  }
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined2 *)((int)param_1 + 0x98) = *(undefined2 *)*(undefined2 *)(iRam00055810 + 0x46);
  FUN_28eb_3670((int)param_1,uVar1);
  return;
}

