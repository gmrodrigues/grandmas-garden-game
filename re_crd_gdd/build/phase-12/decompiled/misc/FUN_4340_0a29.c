// TIM2.EXE: FUN_4340_0a29 @ file 0x049029 Ghidra 0x43E29
// Subsystem: misc | Size: 69 bytes


char * __cdecl16far FUN_4340_0a29(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (((char *)param_2 == (char *)0x0 && param_2._2_2_ == 0) ||
     ((char *)param_1 == (char *)0x0 && param_1._2_2_ == 0)) {
    if ((char *)param_1 != (char *)0x0 || param_1._2_2_ != 0) {
      *param_1 = '\0';
    }
  }
  else {
    do {
      pcVar3 = param_2;
      pcVar2 = param_1;
      param_2 = (char *)CONCAT22(param_2._2_2_,(char *)param_2 + 1);
      cVar1 = *pcVar3;
      param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
    param_1 = (char *)((ulong)pcVar2 & 0xffff);
  }
  return (char *)param_1;
}

