// TIM2.EXE: FUN_4a54_09a6 @ file 0x0500E6 Ghidra 0x4AEE6
// Subsystem: misc | Size: 28 bytes


void __cdecl16near FUN_4a54_09a6(undefined2 param_1,int *param_2)

{
  for (; *param_2 != 0; param_2 = param_2 + 1) {
    *(undefined2 *)(*param_2 + 4) = param_1;
  }
  return;
}

