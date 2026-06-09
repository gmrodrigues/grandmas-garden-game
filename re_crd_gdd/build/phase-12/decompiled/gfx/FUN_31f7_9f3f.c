// TIM2.EXE: FUN_31f7_9f3f @ file 0x0410AF Ghidra 0x3BEAF
// Subsystem: gfx | Size: 29 bytes


undefined2 __cdecl16far
FUN_31f7_9f3f(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
             int param_5)

{
  int *piVar1;
  
  if (param_5 == 1) {
    piVar1 = (int *)(*(int *)((int)param_3 + 0x76) + 0x18);
    *piVar1 = *piVar1 + 1;
  }
  return 0;
}

