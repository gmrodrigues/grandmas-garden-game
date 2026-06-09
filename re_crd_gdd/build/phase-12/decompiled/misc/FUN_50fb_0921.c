// TIM2.EXE: FUN_50fb_0921 @ file 0x056AD1 Ghidra 0x518D1
// Subsystem: misc | Size: 42 bytes


undefined2 __cdecl16far FUN_50fb_0921(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = DAT_554c_5eb0;
  DAT_554c_5eb0 = param_1;
  if (param_1 == 0) {
    DAT_554c_5eb0 = 1;
  }
  return uVar1;
}

