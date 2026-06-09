// TIM2.EXE: FUN_1a9e_5d60 @ file 0x025940 Ghidra 0x20740
// Subsystem: level | Size: 50 bytes


undefined2 __cdecl16far FUN_1a9e_5d60(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((DAT_554c_42c3 != '\0') &&
     ((((param_1 < DAT_554c_42c4 || (DAT_554c_42c6 < param_1)) || (param_2 < DAT_554c_42c8)) ||
      (DAT_554c_42ca < param_2)))) {
    return 0xffff;
  }
                    /* WARNING: Could not recover jumptable at 0x00020769. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(ulong)DAT_554c_4dca)();
  return uVar1;
}

