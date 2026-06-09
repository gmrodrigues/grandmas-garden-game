// TIM2.EXE: FUN_1a9e_6904 @ file 0x0264E4 Ghidra 0x212E4
// Subsystem: misc | Size: 58 bytes


undefined2 __cdecl16far FUN_1a9e_6904(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  while (((*param_1 != '\0' || (*param_2 != '\0')) && (param_3 != 0))) {
    pcVar1 = param_1;
    pcVar2 = param_2;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    if (*pcVar1 != *pcVar2) {
      return 0;
    }
  }
  return 1;
}

