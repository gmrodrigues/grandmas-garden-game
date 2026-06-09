// TIM2.EXE: FUN_50fb_071e @ file 0x0568CE Ghidra 0x516CE
// Subsystem: misc | Size: 61 bytes


int __cdecl16far FUN_50fb_071e(int param_1)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  iVar1 = ((((param_1 - DAT_554c_5eae) + DAT_554c_5eb0) - 1) / DAT_554c_5eb0) * DAT_554c_5eb0 +
          DAT_554c_5eae;
  *(undefined2 *)0x14 = local_20;
  return iVar1;
}

