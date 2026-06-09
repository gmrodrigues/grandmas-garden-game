// TIM2.EXE: FUN_4bdc_19c8 @ file 0x052988 Ghidra 0x4D788
// Subsystem: misc | Size: 44 bytes


undefined2 __cdecl16near FUN_4bdc_19c8(void)

{
  undefined2 in_AX;
  int in_BX;
  int iVar1;
  int unaff_ES;
  
  iVar1 = 0;
  while ((*(int *)(iVar1 + 0x4e) != in_BX || (*(int *)(iVar1 + 0x50) != unaff_ES))) {
    iVar1 = iVar1 + 4;
    if (iVar1 == 0x40) {
      FUN_4bdc_0cf1();
      uRam0004020a = 1;
      return in_AX;
    }
  }
  return in_AX;
}

