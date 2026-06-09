// TIM2.EXE: FUN_4340_0a09 @ file 0x049009 Ghidra 0x43E09
// Subsystem: misc | Size: 32 bytes


int __cdecl16far FUN_4340_0a09(char *param_1)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((char *)param_1 != (char *)0x0 || param_1._2_2_ != 0) {
    while( true ) {
      pcVar1 = param_1;
      param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
      if (*pcVar1 == '\0') break;
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}

