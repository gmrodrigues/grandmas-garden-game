// TIM2.EXE: FUN_4340_0d3f @ file 0x04933F Ghidra 0x4413F
// Subsystem: misc | Size: 85 bytes


char * __cdecl16far FUN_4340_0d3f(char *param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 local_6;
  
  iVar1 = FUN_4340_0a09(param_1,param_2);
  local_6 = (char *)CONCAT22(param_2,param_1 + iVar1);
  if (param_1 + iVar1 != (char *)0x0 || param_2 != 0) {
    while ((param_1 < (char *)local_6 && (*local_6 != param_3))) {
      local_6 = (char *)CONCAT22(local_6._2_2_,(char *)local_6 + -1);
    }
    if (*local_6 == param_3) {
      return (char *)local_6;
    }
  }
  return (char *)0x0;
}

