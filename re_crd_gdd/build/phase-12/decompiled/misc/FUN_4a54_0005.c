// TIM2.EXE: FUN_4a54_0005 @ file 0x04F745 Ghidra 0x4A545
// Subsystem: misc | Size: 50 bytes


undefined2 * __cdecl16far FUN_4a54_0005(undefined2 param_1,undefined2 param_2)

{
  if (DAT_5b41_284c != 0) {
    return (undefined2 *)0x0;
  }
  DAT_5b41_284c = 1;
  DAT_5b41_2854 = param_2;
  DAT_5b41_2852 = param_1;
  DAT_5b41_2850 = 0;
  DAT_5b41_284e = 0;
  return (undefined2 *)&DAT_5b41_284e;
}

