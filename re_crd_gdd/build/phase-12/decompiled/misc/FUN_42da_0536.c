// TIM2.EXE: FUN_42da_0536 @ file 0x0484D6 Ghidra 0x432D6
// Subsystem: misc | Size: 74 bytes


int __cdecl16far FUN_42da_0536(int param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 != 0) {
    if ((char *)param_2 != (char *)0x0 || param_2._2_2_ != 0) {
      if (param_3 == 0) {
        param_3 = -1;
      }
      do {
        pcVar1 = param_2;
        if (param_3 == 0) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
        cVar2 = FUN_1000_0fdc(param_1);
        param_2 = (char *)CONCAT22(param_2._2_2_,(char *)param_2 + 1);
        *pcVar1 = cVar2;
        param_3 = param_3 + -1;
      } while (cVar2 != '\0');
    }
  }
  return iVar3;
}

