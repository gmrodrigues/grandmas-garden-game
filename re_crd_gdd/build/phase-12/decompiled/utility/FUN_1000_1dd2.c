// TIM2.EXE: FUN_1000_1dd2 @ file 0x016FD2 Ghidra 0x11DD2
// Subsystem: utility | Size: 65 bytes


int __cdecl16far FUN_1000_1dd2(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while ((iVar1 = FUN_1000_3226(param_1), iVar1 == 0 &&
         (DAT_554c_59ae != (code *)0x0 || DAT_554c_59b0 != 0))) {
    (*DAT_554c_59ae)(0x1000);
  }
  return iVar1;
}

