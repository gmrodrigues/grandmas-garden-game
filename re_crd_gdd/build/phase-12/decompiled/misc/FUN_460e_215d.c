// TIM2.EXE: FUN_460e_215d @ file 0x04D43D Ghidra 0x4823D
// Subsystem: misc | Size: 109 bytes


int __cdecl16far FUN_460e_215d(int param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_5b41_1cea != '\0') {
    DAT_554c_3fd7 = (char)(param_1 / 1000) + '0';
    DAT_554c_3fd8 = (char)((param_1 % 1000) / 100) + '0';
    DAT_554c_3fd9 = (char)((param_1 % 100) / 10) + '0';
    s_0_RAW_554c_3fda[0] = (char)(param_1 % 10) + '0';
    iVar1 = FUN_460e_21ca(0x3fd4,0x554c,param_2);
    if (iVar1 != 0) {
      DAT_5b41_1ceb = param_1;
    }
  }
  return iVar1;
}

