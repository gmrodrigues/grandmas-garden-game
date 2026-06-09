// TIM2.EXE: FUN_460e_2381 @ file 0x04D661 Ghidra 0x48461
// Subsystem: misc | Size: 43 bytes


int __cdecl16far FUN_460e_2381(void)

{
  int iVar1;
  
  if (DAT_5b41_1cea != '\0') {
    iVar1 = FUN_1000_13a4();
    return iVar1;
  }
  iVar1 = DAT_5b41_1ce6;
  if (DAT_5b41_1ce6 == 0 && DAT_5b41_1ce8 == 0) {
    iVar1 = -1;
  }
  return iVar1;
}

