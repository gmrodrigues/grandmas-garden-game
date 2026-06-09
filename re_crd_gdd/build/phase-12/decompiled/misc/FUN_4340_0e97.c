// TIM2.EXE: FUN_4340_0e97 @ file 0x049497 Ghidra 0x44297
// Subsystem: misc | Size: 42 bytes


undefined2 __cdecl16far FUN_4340_0e97(char *param_1,char param_2)

{
  if ((((char *)param_1 != (char *)0x0 || param_1._2_2_ != 0) && (*param_1 != '\0')) &&
     (param_2 != '\0')) {
    *param_1 = param_2;
    return 1;
  }
  return 0;
}

