// TIM2.EXE: FUN_42da_0610 @ file 0x0485B0 Ghidra 0x433B0
// Subsystem: misc | Size: 86 bytes


int __cdecl16far FUN_42da_0610(int param_1,char *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 != 0) {
    if ((char *)param_2 != (char *)0x0 || param_2._2_2_ != 0) {
      if (param_3 == 0) {
        param_3 = -1;
      }
      while (pcVar1 = param_2, param_3 != 0) {
        iVar3 = iVar3 + 1;
        iVar2 = FUN_1000_1135(*param_2,param_1);
        if (iVar2 == 0) {
          return iVar3;
        }
        param_2 = (char *)CONCAT22(param_2._2_2_,(char *)param_2 + 1);
        param_3 = param_3 + -1;
        if (*pcVar1 == '\0') {
          return iVar3;
        }
      }
    }
  }
  return iVar3;
}

