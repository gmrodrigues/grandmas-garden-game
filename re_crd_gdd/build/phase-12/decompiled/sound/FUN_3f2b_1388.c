// TIM2.EXE: FUN_3f2b_1388 @ file 0x045838 Ghidra 0x40638
// Subsystem: sound | Size: 59 bytes


int * __cdecl16near FUN_3f2b_1388(void)

{
  int in_AX;
  uint uVar1;
  int *piVar2;
  undefined2 unaff_ES;
  
  uVar1 = FUN_3f2b_11ba(0);
  if ((uVar1 & 1) != 0) {
    FUN_3f2b_11ba(uVar1 & 1);
  }
  piVar2 = (int *)FUN_3f2b_11ba(in_AX);
  if (piVar2 != (int *)0xffff) {
    *(int *)0x4 = (int)piVar2;
    *(int *)0x6 = (int)piVar2;
    *piVar2 = in_AX + 1;
    return piVar2 + 2;
  }
  return (int *)0x0;
}

