// TIM2.EXE: FUN_1000_2dd2 @ file 0x017FD2 Ghidra 0x12DD2
// Subsystem: utility | Size: 35 bytes


undefined2 __cdecl16near FUN_1000_2dd2(void)

{
  int in_AX;
  int in_DX;
  int iVar1;
  
  iRam000554c0 = iRam000554c0 - in_AX;
  iVar1 = in_DX + iRam000554c0;
  *(int *)0x0 = in_AX;
  *(int *)0x2 = in_DX;
  *(int *)0x2 = iVar1;
  return 4;
}

