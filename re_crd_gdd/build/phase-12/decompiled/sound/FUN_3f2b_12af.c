// TIM2.EXE: FUN_3f2b_12af @ file 0x04575F Ghidra 0x4055F
// Subsystem: sound | Size: 44 bytes


void __cdecl16near FUN_3f2b_12af(void)

{
  int iVar1;
  int iVar2;
  int in_BX;
  undefined2 unaff_ES;
  
  iVar1 = *(int *)0x8;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 6);
    *(int *)(iVar1 + 6) = in_BX;
    *(int *)(iVar2 + 4) = in_BX;
    *(int *)(in_BX + 6) = iVar2;
    *(int *)(in_BX + 4) = iVar1;
    return;
  }
  *(int *)0x8 = in_BX;
  *(int *)(in_BX + 4) = in_BX;
  *(int *)(in_BX + 6) = in_BX;
  return;
}

