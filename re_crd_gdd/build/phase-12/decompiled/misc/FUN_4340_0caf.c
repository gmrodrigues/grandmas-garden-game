// TIM2.EXE: FUN_4340_0caf @ file 0x0492AF Ghidra 0x440AF
// Subsystem: misc | Size: 56 bytes


char * __cdecl16far FUN_4340_0caf(char *param_1,char param_2)

{
  if ((char *)param_1 != (char *)0x0 || param_1._2_2_ != 0) {
    while ((*param_1 != '\0' && (*param_1 != param_2))) {
      param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
    }
    if (*param_1 != '\0') {
      return (char *)param_1;
    }
  }
  return (char *)0x0;
}

