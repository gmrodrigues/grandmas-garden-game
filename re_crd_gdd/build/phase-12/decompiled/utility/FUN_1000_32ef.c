// TIM2.EXE: FUN_1000_32ef @ file 0x0184EF Ghidra 0x132EF
// Subsystem: utility | Size: 25 bytes


int * __cdecl16near FUN_1000_32ef(void)

{
  int in_AX;
  int *in_BX;
  int *piVar1;
  
  *in_BX = *in_BX - in_AX;
  piVar1 = (int *)((int)in_BX + *in_BX);
  *piVar1 = in_AX + 1;
  piVar1[1] = (int)in_BX;
  *(undefined2 *)((int)piVar1 + in_AX + 2) = piVar1;
  return piVar1 + 2;
}

