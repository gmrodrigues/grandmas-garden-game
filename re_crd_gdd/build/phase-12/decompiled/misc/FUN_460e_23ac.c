// TIM2.EXE: FUN_460e_23ac @ file 0x04D68C Ghidra 0x4848C
// Subsystem: misc | Size: 102 bytes


undefined2 __cdecl16far
FUN_460e_23ac(int param_1,int param_2,undefined2 param_3,undefined2 param_4,int param_5,int param_6)

{
  if (((DAT_5b41_1cea != '\0') && (param_1 != 0 || param_2 != 0)) && (param_5 != 0 || param_6 != 0))
  {
    FUN_460e_2140();
    FUN_1000_136f(param_1,param_2,param_3,param_4,param_5,param_6,DAT_554c_3fd0,DAT_554c_3fd2,
                  DAT_5b41_1ced,0);
    FUN_1000_137d();
    DAT_5b41_1ce8 = 0;
    DAT_5b41_1ce6 = 0;
    DAT_5b41_1ceb = 0xffff;
    return 1;
  }
  return 0;
}

