// TIM2.EXE: FUN_2e67_0c9b @ file 0x03450B Ghidra 0x2F30B
// Subsystem: misc | Size: 63 bytes


int __cdecl16far FUN_2e67_0c9b(uint param_1)

{
  int iVar1;
  
  if ((3999 < param_1) && (param_1 < 5000)) {
    return 1000;
  }
  if ((2999 < param_1) && (param_1 < 4000)) {
    iVar1 = 0x3f;
    while ((iVar1 != 0 && (*(uint *)(iVar1 * 2 + 0x2f48) != param_1))) {
      iVar1 = iVar1 + -1;
    }
    return iVar1;
  }
  return 0;
}

