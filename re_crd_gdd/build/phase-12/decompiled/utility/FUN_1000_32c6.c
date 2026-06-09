// TIM2.EXE: FUN_1000_32c6 @ file 0x0184C6 Ghidra 0x132C6
// Subsystem: utility | Size: 41 bytes


int * __cdecl16near FUN_1000_32c6(void)

{
  int in_AX;
  int *piVar1;
  
  piVar1 = (int *)FUN_1000_2a9d();
  if (piVar1 != (int *)0xffff) {
    piVar1[1] = (int)DAT_554c_5b52;
    DAT_554c_5b52 = piVar1;
    *piVar1 = in_AX + 1;
    return piVar1 + 2;
  }
  return (int *)0x0;
}

