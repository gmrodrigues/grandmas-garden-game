// TIM2.EXE: FUN_3f2b_128d @ file 0x04573D Ghidra 0x4053D
// Subsystem: sound | Size: 34 bytes


void __cdecl16near FUN_3f2b_128d(void)

{
  int iVar1;
  int iVar2;
  int in_BX;
  undefined2 unaff_ES;
  
  iVar1 = *(int *)(in_BX + 6);
  if (in_BX != iVar1) {
    *(int *)0x8 = iVar1;
    iVar2 = *(int *)(in_BX + 4);
    *(int *)(iVar1 + 4) = iVar2;
    *(int *)(iVar2 + 6) = iVar1;
    return;
  }
  *(undefined2 *)0x8 = 0;
  return;
}

