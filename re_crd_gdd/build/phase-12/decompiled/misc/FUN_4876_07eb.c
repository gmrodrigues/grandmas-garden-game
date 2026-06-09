// TIM2.EXE: FUN_4876_07eb @ file 0x04E14B Ghidra 0x48F4B
// Subsystem: misc | Size: 63 bytes


void __cdecl16far FUN_4876_07eb(int param_1,undefined2 param_2)

{
  if (*(int *)(param_1 + 0x34) != 0 || *(int *)(param_1 + 0x36) != 0) {
    (*(code *)*(undefined2 *)(param_1 + 0x34))(0x4876,param_1,param_2);
    return;
  }
  FUN_4876_06b2(param_1,param_2);
  return;
}

