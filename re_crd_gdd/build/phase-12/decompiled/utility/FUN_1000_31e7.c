// TIM2.EXE: FUN_1000_31e7 @ file 0x0183E7 Ghidra 0x131E7
// Subsystem: utility | Size: 28 bytes


void __cdecl16near FUN_1000_31e7(void)

{
  int iVar1;
  int iVar2;
  int in_BX;
  
  iVar1 = *(int *)(in_BX + 6);
  if (in_BX != iVar1) {
    iVar2 = *(int *)(in_BX + 4);
    DAT_554c_5b54 = iVar1;
    *(int *)(iVar1 + 4) = iVar2;
    *(int *)(iVar2 + 6) = iVar1;
    return;
  }
  DAT_554c_5b54 = 0;
  return;
}

