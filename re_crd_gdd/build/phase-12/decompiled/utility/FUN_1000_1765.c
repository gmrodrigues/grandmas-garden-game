// TIM2.EXE: FUN_1000_1765 @ file 0x016965 Ghidra 0x11765
// Subsystem: utility | Size: 90 bytes


void FUN_1000_1765(undefined2 param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  
  if (param_3 == 0) {
    while (DAT_554c_57c6 != 0) {
      DAT_554c_57c6 = DAT_554c_57c6 + -1;
      puVar1 = (undefined2 *)(DAT_554c_57c6 * 4 + -0x782c);
      (*(code *)*puVar1)(0x1000);
    }
    FUN_1000_0152();
    (*DAT_554c_57c8)(0x1000);
  }
  FUN_1000_01ed();
  FUN_1000_0165();
  if (param_2 == 0) {
    if (param_3 == 0) {
      (*DAT_554c_57cc)(0x1000);
      (*DAT_554c_57d0)(0x1000);
    }
    FUN_1000_018e(0x1000,param_1);
  }
  return;
}

