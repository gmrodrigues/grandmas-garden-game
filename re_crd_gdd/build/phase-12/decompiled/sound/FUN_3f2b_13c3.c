// TIM2.EXE: FUN_3f2b_13c3 @ file 0x045873 Ghidra 0x40673
// Subsystem: sound | Size: 43 bytes


int * __cdecl16near FUN_3f2b_13c3(void)

{
  int in_AX;
  int *piVar1;
  undefined2 unaff_ES;
  
  piVar1 = (int *)FUN_3f2b_11ba();
  if (piVar1 != (int *)0xffff) {
    piVar1[1] = *(int *)0x6;
    *(int *)0x6 = (int)piVar1;
    *piVar1 = in_AX + 1;
    return piVar1 + 2;
  }
  return (int *)0x0;
}

