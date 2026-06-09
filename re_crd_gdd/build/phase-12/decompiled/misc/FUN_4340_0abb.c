// TIM2.EXE: FUN_4340_0abb @ file 0x0490BB Ghidra 0x43EBB
// Subsystem: misc | Size: 77 bytes


char * __cdecl16far FUN_4340_0abb(char *param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == 0 && param_3 == 0) {
    return (char *)0x0;
  }
  if ((char *)param_1 == (char *)0x0 && param_1._2_2_ == 0) {
    iVar1 = FUN_4340_0a09((char *)param_1,param_1._2_2_);
    return (char *)param_1 + iVar1;
  }
  for (; *param_1 != '\0'; param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1)) {
  }
  pcVar2 = (char *)FUN_4340_0a29((char *)param_1,param_1._2_2_,param_2,param_3);
  return pcVar2;
}

