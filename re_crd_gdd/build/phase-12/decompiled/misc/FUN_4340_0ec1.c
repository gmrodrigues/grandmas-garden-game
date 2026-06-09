// TIM2.EXE: FUN_4340_0ec1 @ file 0x0494C1 Ghidra 0x442C1
// Subsystem: misc | Size: 53 bytes


byte * __cdecl16far FUN_4340_0ec1(byte *param_1)

{
  if ((byte *)param_1 != (byte *)0x0 || param_1._2_2_ != 0) {
    while (0x20 < *param_1) {
      param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
    }
    while ((*param_1 != 0 && (*param_1 < 0x21))) {
      param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
    }
  }
  return (byte *)param_1;
}

