// TIM2.EXE: FUN_4bdc_302e @ file 0x053FEE Ghidra 0x4EDEE
// Subsystem: physics | Size: 76 bytes


undefined2 __cdecl16far FUN_4bdc_302e(void)

{
  int iVar1;
  
  if (DAT_5b41_2860 != 0 || DAT_5b41_2862 != 0) {
    for (iVar1 = 0; iVar1 < 7; iVar1 = iVar1 + 1) {
      if (((undefined2 *)&DAT_5b41_2860)[iVar1 * 2] != 0 ||
          ((undefined2 *)&DAT_5b41_2862)[iVar1 * 2] != 0) {
        FUN_2e67_10e9(((undefined2 *)&DAT_5b41_2860)[iVar1 * 2],
                      ((undefined2 *)&DAT_5b41_2862)[iVar1 * 2],2);
      }
    }
    return 1;
  }
  return 0;
}

