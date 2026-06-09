// TIM2.EXE: FUN_1000_3286 @ file 0x018486 Ghidra 0x13286
// Subsystem: utility | Size: 64 bytes


int * __cdecl16near FUN_1000_3286(void)

{
  int in_AX;
  uint uVar1;
  int *piVar2;
  
  uVar1 = FUN_1000_2a9d(0,0);
  if ((uVar1 & 1) != 0) {
    FUN_1000_2a9d(uVar1 & 1,0);
  }
  piVar2 = (int *)FUN_1000_2a9d(in_AX,0);
  if (piVar2 != (int *)0xffff) {
    DAT_554c_5b50 = piVar2;
    DAT_554c_5b52 = piVar2;
    *piVar2 = in_AX + 1;
    return piVar2 + 2;
  }
  return (int *)0x0;
}

