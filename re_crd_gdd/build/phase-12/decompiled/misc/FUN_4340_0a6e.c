// TIM2.EXE: FUN_4340_0a6e @ file 0x04906E Ghidra 0x43E6E
// Subsystem: misc | Size: 77 bytes


char * __cdecl16far FUN_4340_0a6e(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  
  if ((char *)param_2 != (char *)0x0 || param_2._2_2_ != 0) {
    if ((char *)param_1 != (char *)0x0 || param_1._2_2_ != 0) {
      while ((iVar1 = param_3, *param_2 != '\0' && (iVar1 = param_3 + -1, param_3 != 0))) {
        *param_1 = *param_2;
        param_2 = (char *)CONCAT22(param_2._2_2_,(char *)param_2 + 1);
        param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
        param_3 = iVar1;
      }
      if (iVar1 != 0) {
        *param_1 = '\0';
      }
    }
  }
  return (char *)param_1;
}

