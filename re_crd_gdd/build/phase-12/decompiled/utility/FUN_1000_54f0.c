// TIM2.EXE: FUN_1000_54f0 @ file 0x01A6F0 Ghidra 0x154F0
// Subsystem: utility | Size: 44 bytes


char * __cdecl16far FUN_1000_54f0(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = param_3;
  pcVar4 = param_2;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  pcVar4 = param_1;
  for (param_3 = param_3 - iVar3; param_3 != 0; param_3 = param_3 + -1) {
    pcVar2 = pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    *pcVar2 = *pcVar1;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar1 = '\0';
  }
  return param_1;
}

