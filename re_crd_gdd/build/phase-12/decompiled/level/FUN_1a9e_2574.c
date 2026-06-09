// TIM2.EXE: FUN_1a9e_2574 @ file 0x022154 Ghidra 0x1CF54
// Subsystem: level | Size: 35 bytes


void __cdecl16far FUN_1a9e_2574(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  while (param_3 != 0) {
    *param_2 = *param_1;
    param_1 = (undefined1 *)CONCAT22(param_1._2_2_,(undefined1 *)param_1 + 1);
    param_2 = (undefined1 *)CONCAT22(param_2._2_2_,(undefined1 *)param_2 + 1);
    param_3 = param_3 + -1;
  }
  return;
}

