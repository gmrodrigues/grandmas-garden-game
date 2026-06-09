// TIM2.EXE: FUN_406b_1e45 @ file 0x0476F5 Ghidra 0x424F5
// Subsystem: misc | Size: 45 bytes


void __cdecl16far FUN_406b_1e45(undefined2 param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  
  while (puVar1 = param_2, param_3 != 0) {
    param_2 = (undefined1 *)CONCAT22(param_2._2_2_,(undefined1 *)param_2 + 1);
    FUN_1000_1135(*puVar1,param_1);
    param_3 = param_3 + -1;
  }
  return;
}

