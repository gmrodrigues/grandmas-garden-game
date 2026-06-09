// TIM2.EXE: FUN_2e67_15e5 @ file 0x034E55 Ghidra 0x2FC55
// Subsystem: misc | Size: 57 bytes


void __cdecl16far FUN_2e67_15e5(int *param_1)

{
  if (param_1[2] - *param_1 < 1) {
    if (param_1[2] - *param_1 < 0) {
      param_1[2] = param_1[2] + -1;
    }
  }
  else {
    param_1[2] = param_1[2] + 1;
  }
  if (param_1[3] - param_1[1] < 1) {
    if (param_1[3] - param_1[1] < 0) {
      param_1[3] = param_1[3] + -1;
    }
  }
  else {
    param_1[3] = param_1[3] + 1;
  }
  return;
}

