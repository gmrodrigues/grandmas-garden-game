// TIM2.EXE: FUN_1000_3203 @ file 0x018403 Ghidra 0x13203
// Subsystem: utility | Size: 35 bytes


void __cdecl16near FUN_1000_3203(void)

{
  int iVar1;
  int iVar2;
  int in_BX;
  
  iVar2 = DAT_554c_5b54;
  if (DAT_554c_5b54 != 0) {
    iVar1 = *(int *)(DAT_554c_5b54 + 6);
    *(int *)(DAT_554c_5b54 + 6) = in_BX;
    *(int *)(iVar1 + 4) = in_BX;
    *(int *)(in_BX + 6) = iVar1;
    *(int *)(in_BX + 4) = iVar2;
    return;
  }
  DAT_554c_5b54 = in_BX;
  *(int *)(in_BX + 4) = in_BX;
  *(int *)(in_BX + 6) = in_BX;
  return;
}

