// TIM2.EXE: FUN_3f2b_13ee @ file 0x04589E Ghidra 0x4069E
// Subsystem: sound | Size: 30 bytes


int * __cdecl16near FUN_3f2b_13ee(void)

{
  int in_AX;
  int *in_BX;
  int *piVar1;
  undefined2 unaff_ES;
  
  *in_BX = *in_BX - in_AX;
  piVar1 = (int *)((int)in_BX + *in_BX);
  *piVar1 = in_AX + 1;
  piVar1[1] = (int)in_BX;
  *(undefined2 *)((int)piVar1 + in_AX + 2) = piVar1;
  return piVar1 + 2;
}

